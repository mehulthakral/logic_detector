
from model1.predict import predict
from flask import Flask,jsonify,request,Response,render_template
from flask_cors import CORS, cross_origin
import os
import requests
from werkzeug.utils import secure_filename

app = Flask(__name__)

@app.route('/predict', methods=['GET'])
@cross_origin(origin='*')
def string():
    json = request.get_json(force=True)

    return predict(json['f'],json['lang'])





    

