# import
import pandas as pd
from skcriteria import Data, MIN, MAX
import json
from skcriteria.madm import simple
import inspect
import itertools

import optimize as op1


#Source: https://towardsdatascience.com/ranking-algorithms-know-your-multi-criteria-decision-solving-techniques-20949198f23e


Input_Type = "labelled" #dataset or Model or labelled

def rank_label(df_lab,  wgt):

  criteria_data = Data(
      df_lab.iloc[:, 1:5],          # the pandas dataframe
      [MIN, MIN, MIN, MIN],      # direction of goodness for each column
      anames = df_lab['Index'], # each entity's name, here car name
      cnames = df_lab.columns[1:5], # attribute/column name
      weights=wgt          # weights for each attribute (optional)
      )

  df_lab_copy = df_lab.copy()

  # weighted sum, sumNorm
  dm = simple.WeightedSum(mnorm="sum")
  #print(dm.tolist())
  dec = dm.decide(criteria_data)
  #print(dec)
  df_lab_copy.loc[:, 'rank_weightedSum_sumNorm_inverse'] = dec.rank_

  # weighted sum, maxNorm
  dm = simple.WeightedSum(mnorm="max")
  dec = dm.decide(criteria_data)
  df_lab_copy.loc[:, 'rank_weightedSum_maxNorm_inverse'] = dec.rank_

  # weighted product, sumNorm
  dm = simple.WeightedProduct(mnorm="sum")
  dec = dm.decide(criteria_data)
  df_lab_copy.loc[:, 'rank_weightedProduct_sumNorm_inverse'] = dec.rank_

  # weighted product, sumNorm
  dm = simple.WeightedProduct(mnorm="max")
  dec = dm.decide(criteria_data)
  df_lab_copy.loc[:, 'rank_weightedProduct_maxNorm_inverse'] = dec.rank_

  # sort for better visualization
  df_lab_copy.sort_values(by=['rank_weightedSum_sumNorm_inverse'], inplace=True)

  return df_lab_copy


def Basic_tests(weights):
  strong_dom = []
  #compare=['(df["Time"][i] <= df["Time"][j])','(df["Space"][i] <= df["Space"][j])','(df["Cyclomatic"][i] <= df["Cyclomatic"][j])','(df["Halstead"][i] <= df["Halstead"][j])']
  compare=['(df["Scaled_Time"][i] <= df["Scaled_Time"][j])','(df["Scaled_Space"][i] <= df["Scaled_Space"][j])','(df["Scaled_Cyclomatic"][i] <= df["Scaled_Cyclomatic"][j])','(df["Scaled_Halstead"][i] <= df["Scaled_Halstead"][j])']
  cond=''

  for w in range(len(weights)):
      if weights[w]>0 and cond=='':
          cond = compare[w]
      elif weights[w]>0:
          cond = cond + ' and ' + compare[w]

  for i in range(0,len(df)):
      for j in range(i+1,len(df)):
          if eval(cond):
              strong_dom.append([df["Index"][i],df["Index"][j]])
              if df["Model_Rank"][i] > df["Model_Rank"][j]:
                  print(strong_dom[-1],"Model Error")
              elif df["rank_weightedSum_sumNorm_inverse"][i] > df["rank_weightedSum_sumNorm_inverse"][j] or df["rank_weightedSum_maxNorm_inverse"][i] > df["rank_weightedSum_maxNorm_inverse"][j] or df["rank_weightedProduct_sumNorm_inverse"][i] > df["rank_weightedProduct_sumNorm_inverse"][j] or df["rank_weightedProduct_maxNorm_inverse"][i] > df["rank_weightedProduct_maxNorm_inverse"][j]:
                  print(strong_dom[-1],"Test Error")

  return strong_dom

def Greedy(df, weights):
  n = int(len(df)/5)
  metrics=["Scaled_Time","Scaled_Space","Scaled_Cyclomatic","Scaled_Halstead"]
  wgt=list(zip(weights,metrics))
  wgt.sort(reverse=True)
  for i in wgt:
      df=df.sort_values(i[1])
      df.drop(df.tail(n).index,inplace=True)

  #print(df.iloc[:, 7:12])
  #df.to_csv(r'Greedy.csv', index = False, header=True)
  return df

if Input_Type == "dataset":
  cols=["Label","met1","met2","met3","met4","Code","Index"]
  data=[]
  #Load the file as json. 
  with open("dataset_py.json") as file:
      obj = json.load(file)
      for key, val in obj.items():
          c=0
          for i in val:
              lst=[]
              for j in i:
                  lst.append(j)
              data.append([key]+lst+[c])
              c+=1

  df = pd.DataFrame(data,columns=cols)   

  gb = df.groupby('Label')
  result = pd.DataFrame()

  for name, df_lab  in gb:
    df_lab=df_lab.iloc[1:]
    df_lab.Code = df_lab.Code.apply(lambda x : x.replace('\n', '\\n'))
    rank = rank_label(df_lab)
    result = pd.concat([result,rank])

  #print(result)

  #print(df_lab_copy)
  result.to_csv(r'Ranked.csv', index = False, header=True)

elif Input_Type == "Model":
  df = pd.read_csv('Model_Output.csv')
  df_lab = df
  rank = rank_label(df_lab, [50,100,25,50])
  rank.to_csv(r'Ranked.csv', index = False, header=True)

elif Input_Type == "labelled":
  init_wgt = [0,0,50,100]
  comb = list(itertools.product(init_wgt, repeat=4))
  comb = list(set(comb))

  labels=[]
  with open("dataset_py.json") as file:
    obj = json.load(file)
    for i in obj:
      labels.append(i)
  
  op1.rank_test('SORT','python',init_wgt)
  labelled={}
  for label in labels:
    lab=[]
    print(label)
    for weights in comb:
      temp={}
      weights = list(weights)
      temp["Weights"]=weights
      op1.rank_test(label,'python',weights)
      df = pd.read_csv('Model_Output.csv')
      df_lab = df
      rank = rank_label(df_lab, weights)
      #rank.to_csv(r'Ranked.csv', index = False, header=True)
      greedy_df = Greedy(rank, weights)
      #print(greedy_df.iloc[:, 11:15])
      res=[]
      for key, val in greedy_df.iterrows():
        iters={}
        #iters["Code"]=val[6]
        iters["Index"]=val[11]
        iters["Model_Rank"]=val[12]
        res.append(iters)
      temp["Results"]=res
      lab.append(temp)
    labelled[label]=lab
    #print(labelled)

  with open('Labelled.json', 'w') as outfile:
    json.dump(labelled, outfile, indent="\t")
  print(labelled)