import model1.Predict as mp
from flask import Flask,jsonify,request
from flask_cors import CORS
app = Flask(__name__)
CORS(app)

@app.route('/predict', methods=['POST'])
def string():
    json = request.get_json(force=True)

    return jsonify(mp.predict(json['f'],json['lang']))


if __name__ == '__main__':
    app.debug=True
    app.run()


    

