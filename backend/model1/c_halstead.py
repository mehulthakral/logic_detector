import subprocess
import decimal
import time
import os

# out = subprocess.Popen(['g++','halstead.cpp'])
def halstead(func_str):
    with open('code.txt', 'w') as f:
        # web_browsers = ['Firefox\n', 'Chrome\n', 'Edge\n']
        f.writelines(func_str)

    os.system("g++ halstead.cpp")
    time.sleep(2)
    out = subprocess.Popen(['./a.out'],  stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    stdout,stderr = out.communicate()
    os.system("rm code.txt ./a.out")
    # print(type(stdout),stdout,"\n",stderr)
    lines = stdout.decode("utf-8")   #stdout is of types bytes, hence the conversion
    lines=lines.split('\n')
    halstead={}
    for i in lines:
        i=i.split(":")
        # print(i)
        if i[0] in ['n1','n2','N1','N2']:
            halstead[i[0]] = int(i[1])
        else:
            halstead[i[0]]=float(i[1])
    return halstead

