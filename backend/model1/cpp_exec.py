import cppyy
try :
    import model1.cpp_adaptor as cp
    import model1.predict as mp
except:
    import cpp_adaptor as cp
    import predict as mp

#print(predict(Adaptor))
def execute(func_str, label):
    cppyy.cppdef("using namespace std;")
    cppyy.cppdef(func_str)
    a = cp.Adaptor()
    #print(getattr(a,label))
    res = mp.predict(getattr(a,label),"C++")
    return res


import sys
handle = open(sys.argv[1])
label = sys.argv[2]
func_str = handle.read()
#print(func_str)
print(execute(func_str, label))
"""
f = open("../CDataset/canFinish/canFinish_1.cpp")

s = f.read()
cppyy.cppdef("using namespace std;")
cppyy.cppdef(s)
print(mp.predict(Adaptor.canFinish))
"""