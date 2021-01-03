import model1.predict as mp1
import model2.predict as mp2
import model1.dataset_gen as g1
import model1.parser as p
import model1.optimize as op1
from flask import Flask,jsonify,request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/predict', methods=['POST'])
def PREDICT():
    json = request.get_json(force=True)
    methods=p.parse(json['f'])
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
        methods=p.parse(json['f'])
        for i in methods:
            for j in range(5):
                g1.add_to_csv_dataset((i.__name__,i),json['lang'])
                g1.add_to_json_dataset((i.__name__,i),json['lang'])
        return "True"
    elif json['model'] == "model2":
        return "True"
    else:
        methods=p.parse(json['f'])
        for i in methods:
            for j in range(5):
                g1.add_to_csv_dataset((i.__name__,i),json['lang'])
                g1.add_to_json_dataset((i.__name__,i),json['lang'])
        return "True"


@app.route('/optimize', methods=['POST'])
def OPTIMIZE():
    json = request.get_json(force=True)
    methods=p.parse(json['f'])
    m=[]
    if json['model'] == "model1": #dynamic analysis
        for i in methods:
            func_obj=i[0]
            func_source_code=i[1]
            m.append(op1.optimize(func_obj,json['lang']))
            
    elif json['model'] == "model2": #static analysis
        for i in methods:
            func_obj=i[0]
            func_source_code=i[1]
            m.append(mp2.predict(func_source_code,json['lang']))
            
    else: #default is dynamic analysis
        for i in methods:
            func_obj=i[0]
            func_source_code=i[1]
            m.append(op1.optimize(func_obj,json['lang']))
            
    return jsonify(m)

if __name__ == '__main__':
    app.run(host='0.0.0.0',port=5000)


    

