import model1.predict as mp1
import model1.dataset as g1
import model1.optimize as op1
import model2.predict as mp2
from flask import Flask,jsonify,request
from flask_cors import CORS
from typing import List, Set, Dict, Tuple, Optional
import inspect
app = Flask(__name__)
CORS(app)

def parse_py(f):
    obj=open("temp.py","w")
    obj.write("from typing import List, Set, Dict, Tuple, Optional"+"\n"+f)
    obj.close()
    temp=__import__("temp")
    methods=[]
    for _,k in inspect.getmembers(temp):
        if inspect.isfunction(k):
            methods.append((k,inspect.getsource(k)))
        elif inspect.isclass(k):
            obj=k()
            methods += [(getattr(obj, m),inspect.getsource(getattr(k, m))) for m in dir(obj) if ((not m.startswith('__')) and (inspect.isfunction(getattr(obj, m)) or (inspect.ismethod(getattr(obj, m)))))]
    return methods

def parse_clike(f):
    cppyy=__import__("cppyy")
    try:
        cppyy.cppdef("using namespace std;")
        cppyy.cppdef(f)
    except:
        pass
    try:
        cppyy.gbl.some_random_member #force load the functions defined earlier
    except:
        cppyy.gbl
    methods=[]
    for _,k in list(inspect.getmembers(cppyy.gbl)):
        if str(type(k))=="<class 'cppyy.CPPOverload'>" and (not _.startswith("__")) :
            methods.append((k,f))
    return methods

@app.route('/predict', methods=['POST'])
def PREDICT():
    json = request.get_json(force=True)
    if json["lang"]=="python":
        methods=parse_py(json['f'])
    else:
        methods=parse_clike(json['f'])
    m=[]
    if json['model'] == "model1": #dynamic analysis
        for i in methods:
            func_obj=i[0]
            original_func_name=func_obj.__name__
            func_source_code=i[1]
            m.append([original_func_name,mp1.predict(func_obj,json['lang'])])
            
    elif json['model'] == "model2": #static analysis
        for i in methods:
            func_obj=i[0]
            original_func_name=func_obj.__name__
            func_source_code=i[1]
            m.append([original_func_name,mp2.predict(func_source_code,json['lang'])])
            
    else: #default is dynamic analysis
        for i in methods:
            func_obj=i[0]
            original_func_name=func_obj.__name__
            func_source_code=i[1]
            m.append([original_func_name,mp1.predict(func_obj,json['lang'])])
            
    return jsonify(m)

@app.route('/learn', methods=['POST'])
def LEARN():
    json = request.get_json(force=True)
    if json['model'] == "model1":
        if json["lang"]=="python":
            methods=parse_py(json['f'])
        else:
            methods=parse_clike(json['f'])
        for i in methods:
            func_obj=i[0]
            func_source_code=i[1]
            for j in range(5):
                g1.csv_dataset.add((func_obj.__name__,func_obj),json['lang'])
            g1.json_dataset.add((func_obj.__name__,func_obj),json['lang'])
        return "True"
    elif json['model'] == "model2": #static analysis
        return "True"
    else:#default is dynamic analysis
        methods=parse_py(json['f'])
        for i in methods:
            func_obj=i[0]
            func_source_code=i[1]
            for j in range(5):
                g1.csv_dataset.add((func_obj.__name__,func_obj),json['lang'])
            g1.json_dataset.add((func_obj.__name__,func_obj),json['lang'])
        return "True"


@app.route('/optimize', methods=['POST'])
def OPTIMIZE():
    json = request.get_json(force=True)
    if json["lang"]=="python":
        methods=parse_py(json['f'])
    else:
        methods=parse_clike(json['f'])
    m=[]
    for i in methods:
        func_obj=i[0]
        func_source_code=i[1]
        m.append(op1.optimize((func_obj,func_source_code),json['lang'],json["weights"]))
            
    return jsonify(m)

@app.route('/rank', methods=['POST'])
def RANK():
    json = request.get_json(force=True)
    if json["lang"]=="python":
        print(json['f'])
        methods=parse_py(json['f'])
    else:
        methods=parse_clike(json['f'])
    print(json['lang'],json['weights'])
    print(methods)
    return jsonify(op1.rank(methods,json['lang'],json["weights"]))

@app.route('/compare', methods=['POST'])
def COMPARE():
    json = request.get_json(force=True)
    if json["lang"]=="python":
        methods=parse_py(json['f'])
    else:
        methods=parse_clike(json['f'])
    
    return jsonify(op1.compare(methods,json['lang'],json["weights"]))

if __name__ == '__main__':
    app.run(host='0.0.0.0',port=5000,threaded=False, processes=3)


    

