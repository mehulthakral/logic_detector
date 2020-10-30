import model1.predict as mp1
import model2.predict as mp2
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


if __name__ == '__main__':
    app.debug=True
    app.run()


    

