from . import func
from . import languages
from . import model_knn as model 
import sys


def predict(f,lang):
    vec=languages.Vector(f,lang)
    obj=model.Model()
    return obj.predict(vec)


