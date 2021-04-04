import os


def save_to_file(func_str):
    #save the code with filename as code.cpp
    pass

def clear():
    os.system(
        "rm ./cpp_logs/code ./cpp_logs/massif.out ./cpp_logs/mem.log ./cpp_logs/massif_print.txt ./cpp_logs/out.txt")
    

def exec_file(): 
    cmd = "g++ ./cpp_logs/code.cpp -o ./cpp_logs/code"
    os.system(cmd)

def valgrind():
    os.system("valgrind --log-file=./cpp_logs/mem.log ./cpp_logs/code > ./cpp_logs/out.txt")
    
   

def massif():
    os.system(
        "valgrind --massif-out-file=./cpp_logs/massif.out --tool=massif ./cpp_logs/code")
    os.system("ms_print ./cpp_logs/massif.out > ./cpp_logs/massif_print.txt")

def c_mem_val():
    # clear()
    exec_file()
    valgrind()
    massif()
    file = open('./cpp_logs/mem.log', 'r')


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

if __name__=="__main__":
    
    c_mem_val()
    

# import subprocess
# output = subprocess.Popen([cmd])
# print(output)
