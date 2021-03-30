# import
import pandas as pd
from skcriteria import Data, MIN, MAX
import json
from skcriteria.madm import simple


#Source: https://towardsdatascience.com/ranking-algorithms-know-your-multi-criteria-decision-solving-techniques-20949198f23e

def rank_label(df_lab,  wgt = [1,0,0,0]):

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

Input_Type = "Model_Output" #dataset or Model_Output

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

elif Input_Type == "Model_Output":
  df = pd.read_csv('Model_Output.csv')
  df_lab = df
  rank = rank_label(df_lab, [100,100,0,0])
  rank.to_csv(r'Ranked.csv', index = False, header=True)
