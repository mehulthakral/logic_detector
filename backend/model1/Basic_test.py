import pandas as pd

df = pd.read_csv('Ranked.csv')

weights = [75,100,25,50]
strong_dom = []
#compare=['(df["Time"][i] <= df["Time"][j])','(df["Space"][i] <= df["Space"][j])','(df["Cyclomatic"][i] <= df["Cyclomatic"][j])','(df["Halstead"][i] <= df["Halstead"][j])']
compare=['(df["Scaled_Time"][i] <= df["Scaled_Time"][j])','(df["Scaled_Space"][i] <= df["Scaled_Space"][j])','(df["Scaled_Cyclomatic"][i] <= df["Scaled_Cyclomatic"][j])','(df["Scaled_Halstead"][i] <= df["Scaled_Halstead"][j])']
cond=''

for w in range(len(weights)):
    if weights[w]>0 and cond=='':
        cond = compare[w]
    elif weights[w]>0:
        cond = cond + ' and ' + compare[w]
#print(cond)


for i in range(0,len(df)):
    #print(df["Index"][i],df["Scaled_Time"][i])
    for j in range(i+1,len(df)):
        if eval(cond):
            strong_dom.append([df["Index"][i],df["Index"][j]])
            if df["Model_Rank"][i] > df["Model_Rank"][j]:
                print(strong_dom[-1],"Model Error")
            elif df["rank_weightedSum_sumNorm_inverse"][i] > df["rank_weightedSum_sumNorm_inverse"][j] or df["rank_weightedSum_maxNorm_inverse"][i] > df["rank_weightedSum_maxNorm_inverse"][j] or df["rank_weightedProduct_sumNorm_inverse"][i] > df["rank_weightedProduct_sumNorm_inverse"][j] or df["rank_weightedProduct_maxNorm_inverse"][i] > df["rank_weightedProduct_maxNorm_inverse"][j]:
                print(strong_dom[-1],"Test Error")

#print(strong_dom)

n = int(len(df)/5)
metrics=["Scaled_Time","Scaled_Space","Scaled_Cyclomatic","Scaled_Halstead"]
wgt=list(zip(weights,metrics))
wgt.sort(reverse=True)
#print(wgt)
for i in wgt:
    #print(df.iloc[:, 7:12])
    df=df.sort_values(i[1])
    #print(df.iloc[:, 7:12])
    df.drop(df.tail(n).index,inplace=True)

#print(df.iloc[:, 7:12])
df.to_csv(r'Greedy.csv', index = False, header=True)
