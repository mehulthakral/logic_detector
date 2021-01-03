from typing import List, Set, Dict, Tuple, Optional
import inspect
import importlib

def parse(f):
    obj=open("temp.py","w")
    obj.write(f)
    obj.close()
    import temp
    temp=importlib.reload(temp)
    methods=[]
    for _,k in inspect.getmembers(temp):
        if inspect.isfunction(k):
            methods.append((k,inspect.getsource(k)))
        elif inspect.isclass(k):
            obj=k()
            methods += [(getattr(obj, m),inspect.getsource(getattr(k, m))) for m in dir(obj) if ((not m.startswith('__')) and (inspect.isfunction(getattr(obj, m)) or (inspect.ismethod(getattr(obj, m)))))]
    return methods
