try:
    from . import predictor
    from . import model_knn as model 
except:
    import predictor
    import model_knn as model


def predict(f,lang="python"):

    mobj=model.Model()
    vobj=predictor.python(f)
    vec =vobj.generate_vector()
    return mobj.predict(vec)


