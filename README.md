# logic_detector
An attempt to detect logic of the program

Steps:

1. Install docker
2. Install docker-compose
3. clone the repo
4. `sudo docker-compose up --build`
5. type `localhost:8090` in browser to access UI
6. type code/upload file and submit. wait for a minute to get the result

Note to add a new logic detection module, 

1. create a directory modelx where x is a number. 
2. add the required python modules in it.
3. create a file called `predict.py` and add a function called `predict(function,language)` which takes 2 args and returns a python dict. `function` is the string argument which contains the function definition and language specifies the language. The return value must be a python dict which gives probabilities of various classes. The keys are the classes and values are probabilities.



