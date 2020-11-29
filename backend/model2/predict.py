import pickle
from . import ast_vectors as av


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
    result = model_NB_predict([f])
    return result
