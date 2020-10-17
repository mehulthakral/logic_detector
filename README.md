# logic_detector
An attempt to detect logic of the program

Steps:

1. Install Docker
2. Install Dockerfile
3. clone the repo
4. `sudo docker-compose up --build`
5. type `localhost:8090` in browser to access UI
6. type code/upload file and submit. wait for a minute to get the result

Note to add a new logic detection module, 

1. create a directory modelx where x is a number. 
2. add the required modules in it.
3. create a file called `predict.py` and add a function called `predict(function,language)` which takes 2 args and returns a python dict. `function` is the string which contains the function definition and language specifies the language. The return value must be a python dict which gives probabilities of various classes. The keys are the classes and values are probabilities.



