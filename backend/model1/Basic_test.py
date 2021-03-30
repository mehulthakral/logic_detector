import pandas as pd

df = pd.read_csv('Ranked.csv')

weights = [100,100,0,0]
strong_dom = []
compare=['(df["Time"][i] <= df["Time"][j])','(df["Space"][i] <= df["Space"][j])','(df["Cyclomatic"][i] <= df["Cyclomatic"][j])','(df["Halstead"][i] <= df["Halstead"][j])']
cond=''

for w in range(len(weights)):
    if weights[w]>0 and cond=='':
        cond = compare[w]
    elif weights[w]>0:
        cond = cond + ' and ' + compare[w]
#print(cond)


for i in range(0,len(df)):
    #print(df["Index"][i],df["Time"][i])
    for j in range(i+1,len(df)):
        if eval(cond):
            strong_dom.append([df["Index"][i],df["Index"][j]])
            if df["Model_Rank"][i] > df["Model_Rank"][j]:
                print(strong_dom[-1],"Model Error")
            elif df["rank_weightedSum_sumNorm_inverse"][i] > df["rank_weightedSum_sumNorm_inverse"][j] or df["rank_weightedSum_maxNorm_inverse"][i] > df["rank_weightedSum_maxNorm_inverse"][j] or df["rank_weightedProduct_sumNorm_inverse"][i] > df["rank_weightedProduct_sumNorm_inverse"][j] or df["rank_weightedProduct_maxNorm_inverse"][i] > df["rank_weightedProduct_maxNorm_inverse"][j]:
                print(strong_dom[-1],"Test Error")
            else:
                print("Passed")

#print(strong_dom)
