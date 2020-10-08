from numpy.random import seed
seed(0)
import tensorflow
tensorflow.random.set_seed(0)


def Vector(f,lang):
    import languages
    import func
    d={}
    exec("d['obj']=languages."+lang+"(func."+f+")")


    ans=d["obj"].generate_vector()

    return ans 

def predict(f,lang):
    vec=Vector(f,lang)
    import model_knn as model 
    obj=model.Model()
    return obj.predict(vec)


if __name__=="__main__":
    print(predict("MAX_ARR","python"))






