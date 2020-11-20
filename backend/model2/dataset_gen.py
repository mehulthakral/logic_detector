import subprocess
import os
import csv

entries = os.listdir('../dataset')
# print(entries)
tagged_pgm_list=[]
for i in entries:
    pgms=os.listdir('../dataset/'+i)
    # print("pgms \n" ,pgms)
    for j in pgms:
        # print(j)#,end="\t")
        with open('../dataset/'+i+'/'+j, 'r') as f:
            data = f.read()
            # print("file contents are \n",data)
            # print(data)
            path='../dataset/'+i+'/'+j
            # print(path)
            output = subprocess.check_output(["python3", "./Compiler.py"],input=bytes(path,'utf-8'))
            output = output.decode("utf-8")
            t=(i,data,output)
           
            

            tagged_pgm_list.append(t)
print(tagged_pgm_list)


with open('dataset.csv', 'w') as f: 
      
    # using csv.writer method from CSV package 
    write = csv.writer(f) 
      
    # write.writerow(fields) 
    write.writerows(tagged_pgm_list) 


""" ENCODING THE PROGRAMS TO VECTORS USING AST MODULE """


docs = []
labels = []
for p in tagged_pgm_list:
    docs.append(p[1])
    labels.append(p[0])


from ast_vectors import encode_to_ast_vectors
import numpy as np
encoded_ast_count,ast_labels=encode_to_ast_vectors(docs,labels)

rows = []



with open('dataset_encoded.csv', 'w') as f:

    # using csv.writer method from CSV package
    write = csv.writer(f)

    for i in range(len(ast_labels)):
        v = np.array(encoded_ast_count[i])
        row = np.append(v, ast_labels[i])
        # print(row, "\n\n")
        write.writerow(row)




