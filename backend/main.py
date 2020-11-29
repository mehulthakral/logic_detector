import model1.predict as mp1
import model2.predict as mp2
import model1.dataset_gen as g1
from flask import Flask,jsonify,request
from flask_cors import CORS
app = Flask(__name__)
CORS(app)

@app.route('/predict', methods=['POST'])
def string():
    json = request.get_json(force=True)
    
    if json['model'] == "model1":
        m = mp1.predict(json['f'],json['lang'])
    elif json['model'] == "model2":
        m = mp2.predict(json['f'],json['lang'])

    return jsonify(m)

@app.route('/add', methods=['POST'])
def add_func():
    json = request.get_json(force=True)
    if json['model'] == "model1":
        choice=g1.add_to_func(json['f'],json['lang'])
        for i in range(5):
            g1.add_to_dataset(choice,json['lang'])
    elif json['model'] == "model2":
        m = mp2.predict(json['f'],json['lang'])
    return "True"

if __name__ == '__main__':
    app.run(host='0.0.0.0',port=80)


    

