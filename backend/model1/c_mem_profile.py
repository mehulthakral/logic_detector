import os
import time

def save_to_file(func_str):
    #save the code with filename as code.cpp
    f = open("./model1/cpp_logs/code.cpp","w")
    f.writelines(func_str)

def clear():
    os.system(
        "rm ./model1/cpp_logs/code ./model1/cpp_logs/massif.out ./model1/cpp_logs/mem.log ./model1/cpp_logs/massif_print.txt ./model1/cpp_logs/out.txt")
    

def exec_file(): 
    cmd = "g++ ./model1/cpp_logs/code.cpp -o ./model1/cpp_logs/code"
    os.system(cmd)

def valgrind():
    os.system("valgrind --log-file=./model1/cpp_logs/mem.log ./model1/cpp_logs/code > ./model1/cpp_logs/out.txt")
    
def c_time_val():
    out = subprocess.Popen(['./model1/cpp_logs/code'],  stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    stdout,stderr = out.communicate()
    val = stdout.decode("utf-8")
    return val

def massif():
    os.system(
        "valgrind --massif-out-file=./model1/cpp_logs/massif.out --tool=massif ./model1/cpp_logs/code")
    os.system("ms_print ./model1/cpp_logs/massif.out > ./model1/cpp_logs/massif_print.txt")

def c_mem_val():
    # clear()
    
    file = open('./model1/cpp_logs/mem.log', 'r')

    Lines = file.readlines()
    # count=0
    mem_val=0
    for line in Lines:
        # count += 1
        # print("Line{}: {}".format(count, line.strip()))
        if "bytes allocated" in line:
            mem_val = line.split(" ")[-3].split(",")
            mem_val = int(("").join(mem_val))
            print(mem_val)
    mem_val=mem_val/1024 # convert bytes to Kib
    return mem_val

def c_dynamic_metrics(func_str):
    save_to_file(func_str)
    #time.sleep(2)
    exec_file()
    valgrind()
    massif()

    mem_val = c_mem_val()
    time_val = c_time_val()
    return time_taken,mem_taken
    

# import subprocess
# output = subprocess.Popen([cmd])
# print(output)
