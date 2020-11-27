# logic_detector
An attempt to detect logic of the program

Steps to Install:

1. Install docker
2. Install docker-compose
3. Clone the repo
4. `sudo docker-compose up --build`

Steps to Train/Learn new Functions via UI :

1. Type `localhost:8090` in browser to access UI
2. Select model
3. Type code/upload file. The Function name will be taken as label
4. Click on Learn button

Steps to Test/Predict Functions via UI:

1. Type `localhost:8090` in browser to access UI
2. Select model
3. Type code/upload file.
4. Click on Test Button

Steps to Learn new Functions via Library function call:

1. `import model1.dataset_gen as g1`
2. `g1.add_to_dataset(function,lang)`

Steps to Test/Predict Functions via Library function call:

1. `import model1.predict as mp1`
2. `m = mp1.predict(function,language)`


Note to add a new logic detection module, 

1. create a directory modelx where x is a number. 
2. add the required python modules in it.
3. create a file called `predict.py` and add a function called `predict(function,language)` which takes 2 args and returns a python dict. `function` is the string argument which contains the function definition and language specifies the language. The return value must be a python dict which gives probabilities of various classes. The keys are the classes and values are probabilities.



