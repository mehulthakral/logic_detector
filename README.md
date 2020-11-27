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

Note :

While giving functions with special pre conditions like strings having only digits or only special characters or functions having types which are not supported by dynamic analysis model, then, will have to specify the pre conditions in dictionary passed as default arg for that parameter.

For example : In case of a function validating IP address string, the string must not contain upper case, lower case and special characters. So in that case, the function signature will be

`def func(s:str={'upper_count':0,'lower_count':0, 'special_count':0, 'digits_count': 8}):
  pass`
  
So here my making upper case, lower case and special character count as 0 and digits count as 8, you are specifying the precondition as string having 8 digits with no upper case, lower case and special characters

