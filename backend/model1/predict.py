from numpy.random import seed
seed(0)
import tensorflow
tensorflow.random.set_seed(0)



def Vector(f,lang):
    import languages
    if type(f)==str:
        d={}
        exec(f,{},d)
        f=list(d.values())[0]
    if lang=="python":
        obj=languages.python(f)
    else:
        obj=languages.python(max) #default

    ans=obj.generate_vector()

    return ans 

def predict(f,lang):
    vec=Vector(f,lang)
    import model_knn as model 
    obj=model.Model()
    return obj.predict(vec)


if __name__=="__main__":
    #test
    import func
    print(predict(func.MAX,"python"))
    #print(predict("def f(a): return 10*a","python"))








