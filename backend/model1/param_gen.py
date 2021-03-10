import random
from typing import List, Set, Dict, Tuple, Optional
import cppyy
from cppyy.gbl.std import vector,pair
import inspect

default_config={"start":0,"end":15,"len_list":15,"upper_count":3,"lower_count":3,"digits_count":3,"special_count":3,"wspace_count":3}

class parameter:
    def __init__(self,annotation,default={}):
        self.annotation=annotation
        self.default=default
        
def signature(f):
    try:
        temp=inspect.signature(f).parameters
        return temp
    except:
        s=f.__doc__
        mappings={  "int":int,
                    "long":int,
                    "float":float,
                    "double":float,
                    "bool":bool,
                    "std::string":str,
                    "char":str,
                    "const int&":int,
                    "const long&":int,
                    "const float&":float,
                    "const double&":float,
                    "const bool&":bool,
                    "const std::string&":str,
                    "const char&":str,
                    "std::vector<int>":List[int],
                    "std::vector<long>":List[int],
                    "std::vector<float>":List[float],
                    "std::vector<double>":List[float],
                    "std::vector<bool>":List[bool],
                    "std::vector<std::string>":List[str],
                    "std::vector<char>":List[str],
                    "const std::vector<int>&":List[int],
                    "const std::vector<long>&":List[int],
                    "const std::vector<float>&":List[float],
                    "const std::vector<double>&":List[float],
                    "const std::vector<bool>&":List[bool],
                    "const std::vector<std::string>&":List[str],
                    "const std::vector<char>&":List[str],
                    "std::vector<std::vector<std::string>>":vector(vector(str)),
                    "std::vector<std::vector<int>>":vector(vector(int)),
                    "std::vector<std::vector<char>>":vector(vector(str)),
                    "std::vector<std::vector<std::string> >":vector(vector(str)),
                    "std::vector<std::vector<char> >":vector(vector(str)),
                    "std::vector<std::vector<int> >":vector(vector(int)),
                    "const std::vector<std::vector<std::string>>&":vector(vector(str)),
                    "const std::vector<std::vector<int>>&":vector(vector(int)),
                    "const std::vector<std::vector<char>>&":vector(vector(str)),
                    "const std::vector<std::vector<std::string> >&":vector(vector(str)),
                    "const std::vector<std::vector<char> >&":vector(vector(str)),
                    "const std::vector<std::vector<int> >&":vector(vector(int)),
                    "std::list<int>":List[int],
                    "std::list<long>":List[int],
                    "std::list<float>":List[float],
                    "std::list<double>":List[float],
                    "std::list<bool>":List[bool],  
                    "std::list<std::string>":List[str], 
                    "std::list<char>":List[str], 
                    "const std::list<int>&":List[int],
                    "const std::list<long>&":List[int],
                    "const std::list<float>&":List[float],
                    "const std::list<double>&":List[float],
                    "const std::list<bool>&":List[bool],  
                    "const std::list<std::string>&":List[str], 
                    "const std::list<char>&":List[str],                         
                    "std::set<int>":Set[int],
                    "std::set<long>":Set[int],
                    "std::set<float>":Set[float],
                    "std::set<double>":Set[float],
                    "std::set<bool>":Set[bool], 
                    "std::set<std::string>":Set[str],  
                    "std::set<char>":Set[str], 
                    "const std::set<int>&":Set[int],
                    "const std::set<long>&":Set[int],
                    "const std::set<float>&":Set[float],
                    "const std::set<double>&":Set[float],
                    "const std::set<bool>&":Set[bool], 
                    "const std::set<std::string>&":Set[str],  
                    "const std::set<char>&":Set[str],                       
        }
        s=s[s.find("(")+1:-1].split(",")
        parameters={}
        for i in s:
            temp=i.strip().split()
            if temp[0]=="const":
                parameters[temp[2]]=parameter(mappings[temp[0]+" "+temp[1]],{})
            else:
                parameters[temp[1]]=parameter(mappings[temp[0]],{})
        return parameters

def param_generator(t,config={}):
    
    if config==inspect._empty:
        config={}
    def get_random_alphanumeric_string(c):
        upper_count=c["upper_count"]
        digits_count=c["digits_count"]
        lower_count=c["lower_count"]
        special_count=c["special_count"]
        wspace_count=c["wspace_count"]
        sample_str = ''.join((random.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ") for i in range(upper_count)))
        sample_str += ''.join((random.choice("abcdefghijklmnopqrstuvwxyz") for i in range(lower_count)))
        sample_str += ''.join((random.choice("0123456789") for i in range(digits_count)))
        sample_str += ''.join((random.choice("*&^%$#@!~`'\",\\|[];:.><?/\t\b\v") for i in range(special_count)))
        sample_str += ''.join((random.choice(" ") for i in range(wspace_count)))
        sample_list = list(sample_str)
        random.shuffle(sample_list)
        final_string = ''.join(sample_list)
        return final_string
    
    def build_missing_config(c):
        if "start" not in c:
            c["start"]=default_config["start"]
        if "end" not in c:
            c["end"]=default_config["end"]
        if "len_list" not in c:
            c["len_list"]=default_config["len_list"]
        if "upper_count" not in c:
            c["upper_count"]=default_config["upper_count"]
        if "lower_count" not in c:
            c["lower_count"]=default_config["lower_count"]
        if "digits_count" not in c:
            c["digits_count"]=default_config["digits_count"]
        if "special_count" not in c:
            c["special_count"]=default_config["special_count"]
        if "wspace_count" not in c:
            c["wspace_count"]=default_config["wspace_count"]
        
    if "generator" in config:
        try:
            temp=config["generator"]()
            return config["generator"]
        except:
            d={}
            exec(config["generator"],globals(),d)
            f=list(d.values())[0]
            return f
    
    build_missing_config(config)
    
    mappings={
        int:lambda :random.randint(config["start"],config["end"]),
        float:lambda : random.randint(config["start"],config["end"])+random.random(),
        bool:lambda : bool(random.randint(0,1)),
        list: lambda : [random.randint(config["start"],config["end"]) for i in range(config["len_list"])],
        tuple: lambda : tuple([random.randint(config["start"],config["end"]) for i in range(config["len_list"])]),
        set: lambda : {random.randint(config["start"],config["end"]) for i in range(config["len_list"])},
        str: lambda : get_random_alphanumeric_string(config),
        List[int]: lambda :[random.randint(config["start"],config["end"]) for i in range(config["len_list"])],
        Tuple[int]: lambda : tuple([random.randint(config["start"],config["end"]) for i in range(config["len_list"])]),
        Set[int]: lambda : {random.randint(config["start"],config["end"]) for i in range(config["len_list"])},
        List[float]: lambda :[random.randint(config["start"],config["end"])+random.random() for i in range(config["len_list"])],
        Tuple[float]: lambda :tuple([random.randint(config["start"],config["end"])+random.random() for i in range(config["len_list"])]),
        Set[float]: lambda :set([random.randint(config["start"],config["end"])+random.random() for i in range(config["len_list"])]),
        List[str]: lambda :[get_random_alphanumeric_string(config) for i in range(config["len_list"])],
        Tuple[str]: lambda :tuple([get_random_alphanumeric_string(config) for i in range(config["len_list"])]),
        Set[str]: lambda :set([get_random_alphanumeric_string(config) for i in range(config["len_list"])]),
        List[List[int]]: lambda : [[random.randint(0,1) for i in range(config["len_list"])] for j in range(config["len_list"])],
        List[List[str]]: lambda : [[str(random.randint(0,1)) for i in range(config["len_list"])] for j in range(config["len_list"])],
        vector(vector(int)):lambda : [[random.randint(0,1) for i in range(config["len_list"])] for j in range(config["len_list"])],
        vector(vector(int)):lambda : [[random.randint(0,1) for i in range(config["len_list"])] for j in range(config["len_list"])],
        inspect.Parameter.empty:lambda : random.randint(config["start"],config["end"])+random.random()
    }
    
    return mappings[t]
