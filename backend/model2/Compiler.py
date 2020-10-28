import ast
import dis
with open("anag_10.py", "r") as source:
        tree = ast.parse(source.read())
code_obj=compile(tree, filename="<ast>", mode="exec")
print(dis.dis(code_obj))

"""
#with open("anag_3.py", "r") as source:
#        source_file = source.read()

def isAnagram(s, t):
    h = {}
    for i in s:
        if i not in h:
            h[i] = 0
        h[i] += 1
            
    for j in t:
        if j not in h:
            h[j] = 0
        h[j] -= 1
    
    for key in h.keys():
        if h[key] != 0:
            return False
        
    return True

import pyLLVM

llvm = pyLLVM.pylllvm.compiler(isAnagram)
"""