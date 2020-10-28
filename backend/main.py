import model1.predict as mp
from flask import Flask,jsonify,request
from flask_cors import CORS
app = Flask(__name__)
CORS(app)

@app.route('/predict', methods=['POST'])
def string():
    json = request.get_json(force=True)
    print(json,json['f'],json['lang'])
    m1 = mp.predict(json['f'],json['lang'])
    return jsonify(m1)


if __name__ == '__main__':
    app.debug=True
    app.run()


    

