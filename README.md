# Logic Detector and Optimizer
An attempt to detect logic of the program and optimize the program 

Steps to Install:

1. Install docker
2. Install docker-compose
3. Clone the repo
4. `sudo docker-compose up --build`

Steps to Train/Learn new Functions via UI :

1. Type `localhost:8090` in browser to access UI
2. Select language
3. Type code/upload file. The Function name will be taken as label
4. Click on Learn button

Steps to Test/Predict Functions via UI:

1. Type `localhost:8090` in browser to access UI
2. Select language and model
3. Type code/upload file.
4. Click on Test Button

Steps to Optimize Functions via UI:

1. Type `localhost:8090` in browser to access UI
2. Select language
3. Type code/upload file.
4. Modify the weights if necessary by selecting "Add custom weights" checkbox
5. Click on Optimize Button

Steps to Rank Function with respect to functions in Dataset via UI:

1. Type `localhost:8090` in browser to access UI
2. Select language
3. Type code/upload file.
4. Modify the weights if necessary by selecting "Add custom weights" checkbox
5. Click on Rank Button

Steps to Compare 2 or more functions via UI:

1. Type `localhost:8090` in browser to access UI
2. Select language
3. Type the functions
4. Modify the weights if necessary by selecting "Add custom weights" checkbox
5. Click on Compare Button

Steps to Learn new Functions via Library function call:

1. `import model1.dataset as g1`
2. `g1.csv_dataset.add((function_name,function))`
3. `g1.json_dataset.add((function_name,function))`

Steps to Test/Predict Functions via Library function call:

1. `import model1.predict as mp1`
2. `m = mp1.predict(function)`

Steps to Optimize Functions via Library function call:

1. `import model1.optimize as op1`
2. `m = op1.optimize(function)`

Steps to Rank Functions via Library function call:

1. `import model1.optimize as op1`
2. `m = op1.rank(function_arr,"python",[1,0,0,0]) #where function_arr is an array of functions`

Steps to Compare Functions via Library function call:

1. `import model1.optimize as op1`
2. `m = op1.compare(function_arr,"python",[1,0,0,0]) #where function_arr is an array of functions`

Note :

1. function above can be any callable. To call C/C++ functions, use the python module cppyy.

`import model1.predict as mp1`<br>
`import cppyy`<br>
`c_func_str="int test(int a){ return a+1;}"`<br>
`cppyy.cppdef(c_func_str)`<br>
`m = mp1.predict(cppyy.gbl.test)`<br>

2.  giving functions with special pre conditions like strings having only digits or only special characters or functions having types which are not supported by dynamic analysis model, then, will have to specify the pre conditions in dictionary passed as default arg for that parameter.

For example : In case of a function validating IP address string, the string must not contain upper case, lower case and special characters. So in that case, the function signature will be

`def IP_VAL(s:str={'upper_count':0,'lower_count':0, 'special_count':0, 'digits_count': 8}):
  pass`
  
So here by making upper case, lower case and special character count as 0 and digits count as 8, you are specifying the precondition as string having 8 digits with no upper case, lower case and special characters.

3. Default Precondition when no precondition is specified is

`{"start":0,"end":11,"len_list":8,"upper_count":3,"lower_count":3,"digits_count":3,"special_count":3 ,"wspace_count":3,"generator": lambda : random.random}`

So when function signature is like this,

`def IP_VAL(s:str):
  pass`
  
 Then, random strings of length 15 are created which have 3 upper case, 3 lower case, 3 digits and 3 special characters and 3 whitespaces. If s was list, then random list of length 8 is generated.
 
4. start and end specify the range of random numbers to be generated. Ex : if start=1, end=1000, then numbers in the range [1,1000] are generated. 

5. generator specifies a custom random data generator for an argument. It is a callable which takes no arguments. It can also be a string which has a function inside. The function must not take any arguments.

To determine prediction/optimization accuracy label wise for dynamic model for Python and C++:

  1. `cd backend`
  2. Add the labels for which accuracy has to be determined in the labels list in dataset_server.py. Available labels can be reffered from mapping.json 
  3. Run `python dataset_server.py` for Python and the results can be seen in results.txt
  4. Run `python cdataset_server.py` for C++ and the results can be seen in results.txt 
  
6. Optimization, Rank and Compare by default give weightage of 1 to time and 0 for the memory, cyclomatic complexity and halstead's difficulty. Can modifiy the weights to give more/less importance to various parameters
