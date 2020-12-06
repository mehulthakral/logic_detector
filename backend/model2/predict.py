import pickle
import ast_vectors as av
import json

#X = [""def fib(self, N: int) -> int:\n\tglobal fpp\n\t#base condition\n\tif N <= 0:\n\t\tfpp = 1\n\t\treturn 0\n\t# fib(0)= 0\n\tfp = self.fib(N-1)\n\tf = fp+fpp\n\tfpp = fp\n\treturn f"""
#     ]

# y=["fibonacci"]


#####
####  ``` Refer above for the input format for X , X is list of string of program ,
####       even if its a single string, pass it in a list``` ###
####


def model_NB_predict(X):
  docs, labels = av.encode_to_ast_vectors(X, "unknown")
  #print("Generated vector for given code snippet")
  # print(docs,len(docs))
  filename = 'model2/naivebayes.sav'
  loaded_model = pickle.load(open(filename, 'rb'))
  #print("\n\n", "model loaded")
  # print(loaded_model)
  ypred = loaded_model.predict(docs)
  # print(ypred)

  return {ypred[0]:1}  # the predicted label


def model_KNN_predict(X):
  docs, labels = av.encode_to_ast_vectors(X, "unknown")
  #print("Generated vector for given code snippet")
  # print(docs,len(docs))
  filename = 'model2/knn.sav'
  loaded_model = pickle.load(open(filename, 'rb'))
  #print("\n\n", "model loaded")
  # print(loaded_model)
  ypred = loaded_model.predict(docs)
  # print(ypred)

  return {ypred[0]: 1}  # the predicted label

####
#comment the above function, and uncomment the following code to test the working of the file separately
####

# X = ["""def isAnagram(self, s: str, t: str) -> bool:\n\tchar_count = {}\n\tfor char in s:\n\t\t char_count[char] = char_count.get(char, 0) + 1\n\tfor char in t:\n\t char_count[char] = char_count.get(char, 0) - 1\n\treturn False not in [char_count[char] == 0 for char in char_count]\n""",
#      """def fib(self, N: int) -> int:\n\tglobal fpp\n\t#base condition\n\tif N <= 0:\n\t\tfpp = 1\n\t\treturn 0\n\t# fib(0)= 0\n\tfp = self.fib(N-1)\n\tf = fp+fpp\n\tfpp = fp\n\treturn f"""
#     ]

# y=["anagram","fibonacci"]


# docs,labels=encode_to_ast_vectors(X,"unknown")
# print("Generated vector for given code snippet")
# # print(docs,len(docs))
# filename = 'naivebayes.sav'
# loaded_model = pickle.load(open(filename, 'rb'))
# print("\n\n","model loaded")
# # print(loaded_model)
# ypred=loaded_model.predict(docs)
# print(ypred)

def predict(f,lang):
    result1 = model_NB_predict([f])
    result2 = model_KNN_predict([f])
    #f1=open("NB_Accuracy.json","r")
    #nb_acc = json.load(f1)
    nb_acc = {"canFinish": 1.0, "canJump": 0.8333333333333334, "coinChange": 0.8, "countPrimes": 0.42857142857142855, "fib": 0.7142857142857143, "hasCycle": 0.7142857142857143, "inorderTraversal": 0.7142857142857143, "isAnagram": 0.14285714285714285, "isPalindrome": 0.6666666666666666, "isUgly": 1.0, "isValidBST": 0.7142857142857143, "levelOrder": 1.0, "maxDepth": 0.42857142857142855, "maxPathSum": 0.6666666666666666, "myPow": 0.0, "mySqrt": 0.5714285714285714, "numIslands": 0.5714285714285714, "numTrees": 0.14285714285714285, "restoreIpAddresses": 0.8333333333333334, "reverse": 0.6666666666666666, "reverseList": 0.875, "rotate": 0.2857142857142857, "solveSudoku": 1.0, "sortArray": 1.0, "strStr": 0.2857142857142857}
    knn_acc = {"canFinish": 0.8333333333333334, "canJump": 0.8333333333333334, "coinChange": 0.6, "countPrimes": 1.0, "fib": 0.5714285714285714, "hasCycle": 0.8571428571428571, "inorderTraversal": 0.8571428571428571, "isAnagram": 1.0, "isPalindrome": 0.16666666666666666, "isUgly": 0.8333333333333334, "isValidBST": 0.8571428571428571, "levelOrder": 1.0, "maxDepth": 0.5714285714285714, "maxPathSum": 1.0, "myPow": 0.16666666666666666, "mySqrt": 0.7142857142857143, "numIslands": 0.5714285714285714, "numTrees": 0.7142857142857143, "restoreIpAddresses": 1.0, "reverse": 0.6666666666666666, "reverseList": 1.0, "rotate": 0.0, "solveSudoku": 0.5, "sortArray": 0.4, "strStr": 0.14285714285714285}
    if nb_acc[list(result1.keys())[0]] > knn_acc[list(result2.keys())[0]]:
      return result1
    else:
      return result2
