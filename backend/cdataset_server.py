from typing import List
import json
import os
import subprocess
import random
import importlib.machinery
import model1.dataset as g1
import model1.cpp_adaptor as cp


def evaluate():
    # labels = os.listdir('dataset_working')
    # # labels.remove(os.path.basename(__file__))
    # labels.remove('isAnagram')
    # labels.remove('myPow')
    # labels.remove('isPalindrome')
    # labels.remove('fib')
    

    map = json.load(open("mapping.json"))
    #labels = list(map.keys())-['fib','sortArray','isPalindrome','myPow','canFinish','restoreIPAddresses',"canJump",'countPrimes',"coinChange","mySqrt","countPrimes","reverse","rotate","isUgly","numTrees","hasCycle","reverseList","numIslands","canFinish","strStr","isAnagram","inorderTraversal","isValidBST","levelOrder","maxDepth","maxPathSum","solveSudoku",'isAnagram']
    #labels = ["solveSudoku"]
    del map["restoreIPAddresses"]
    labels = list(map.keys())
    #print(labels,len(labels))
    total = 0
    correct = 0
    err={}
    for label in labels:
        prgs = os.listdir('CDataset'+'/'+label)
        prgs.sort()
        if '__pycache__' in prgs:
            prgs.remove('__pycache__')
        ltotal = 0
        lcorrect = 0
        for prg in prgs:
            total += 1
            ltotal += 1
            print("Evaluating " + prg)
            #loader = importlib.machinery.SourceFileLoader('CDataset'+'/'+label, 'CDataset'+'/'+label+'/'+prg)
            loc = 'CDataset'+'/'+label+'/'+prg
            #res = ce.execute(s,label)
            #os.system("cd model1")
            #os.system("python3 model1/cpp_exec.py "+loc+" "+label)
            try:
                res = subprocess.check_output("python3 model1/cpp_exec.py "+loc+" "+label, shell=True)
                #res="isValidBST"
                res = res.splitlines()[-1].decode("utf-8") 
                oplabel = res
                if(oplabel==map[label][0]):
                    correct +=1
                    lcorrect += 1
                print(res,label)
                print("Accuracy till "+ str(total)+" prgs: " + str((float(correct)/total)*100) )
            except Exception as e:
                err[label+prg]=e

        with open("results.txt",'a') as f:
            f.write("Accuracy of "+ label + " " + str(lcorrect)+"/"+str(ltotal)+" prgs: " + str((float(lcorrect)/ltotal)*100)+"\n")
    print(err)
    return  (float(correct)/total)*100

def add_prgs():

    map = json.load(open("mapping.json"))
    labels = ["strStr"]
    # done = ["reverseList","reverse","numTrees","numIslands","mySqrt","myPow"]
    # done = ["rotate","sortArray","canFinish","canJump","coinChange","countPrimes","fib","isPalindrome","inorderTraversal","isUgly","isValidBST","levelOrder","maxDepth","maxPathSum","solveSudoku"]
    # left = ["hasCycle","restoreIPAddresses","isAnagram","strStr"] 
    for label in labels:
        prgs = os.listdir('CDataset'+'/'+label)
        prgs.sort()
        if '__pycache__' in prgs:
            prgs.remove('__pycache__')

        for prg in prgs:
            fobj=open("random.json")
            data=fobj.read()
            obj=json.loads(data)
            fobj.close()
            if(prg in obj):
                continue

            print("Adding " + prg)
            #loader = importlib.machinery.SourceFileLoader('CDataset'+'/'+label, 'CDataset'+'/'+label+'/'+prg)
            #handle = loader.load_module('CDataset'+'/'+label)
            #s = handle.Solution()
            loc = 'CDataset'+'/'+label+'/'+prg
            fol = 'CDataset'+'/'+label
            a = cp.Adaptor()
            #global f
            #f = getattr(s, label)
            s = open(loc)
            fn_src = s.read()
            # f = 0
            #print(fn_src)
            g1.json_dataset.add((map[label][0],getattr(a,label),label,fn_src),"C++")
            fobj=open("random.json","w")
            obj.append(prg)
            data=json.dumps(obj,indent="\t")
            fobj.write(data)
            fobj.close() 

    print("Programs added successfully!")

def optimize_evaluate():
    fobj=open("model1/Labelled.json")
    data=fobj.read()
    obj=json.loads(data)
    fobj.close()

    #del obj["MIN"]
    #del obj["MAX"]
    # print(obj.keys())
    overall_sum = 0.0
    for key in obj.keys():
        print(key, len(obj[key]))
        total, correct = 0,0
        for comb in obj[key]:
            total += 1
            found_value = [dictionary for dictionary in comb["Results"] if dictionary["Model_Rank"] == 1.0]
            if(len(found_value)>0):
                correct += 1
        with open("results.txt",'a') as f:
            f.write("Accuracy of "+ key + " " + str(correct)+"/"+str(total)+" combs: " + str((float(correct)/total)*100)+"\n")
        overall_sum += (float(correct)/total)*100
    with open("results.txt",'a') as f:
            f.write("Overall Accuracy: " + str(float(overall_sum)/len(obj))+"\n")
            
#print(evaluate())
#add_prgs()
optimize_evaluate()
