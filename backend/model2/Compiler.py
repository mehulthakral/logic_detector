import ast
import dis

"""
with open("fibo_10.py", "r") as source:
        tree = ast.parse(source.read())
code_obj=compile(tree, filename="<ast>", mode="exec")
print(dis.dis(code_obj))
"""

def Bytecode(path):
    with open(path, "r") as source:
        tree = ast.parse(source.read())
    code_obj=compile(tree, filename="<ast>", mode="exec")
    return dis.dis(code_obj)

inp = input()
print(Bytecode(inp))


"""
final = []
with open('dataset.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    #print(reader)
    for r in reader:
        if r !=[]:
            #print(r,"\n\n\n")
            Bytecode(r[1])
            #print(Bytecode(r[1]))
            #final = r + [dis.dis(code_obj)]
            #print(final)
            #print("\n\n\n")
"""