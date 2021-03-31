public:
    double myPow(double x, int n) {
        // If the power is zero, then no need to proceed.
		if(n==0){
            return 1;
        }
        double t=1,y=x;
		
		//Keep in mind the limit of int data type. If its exceeding the range, return 0;
        if(n==-2147483648){
            if(x==1){
                return 1;
            }
            else if(x==-1){
                return 1;
            }
            return 0;
        }
		
		//Keep the absolute power stored in the variable
        int ti=abs(n);
        
		/* Now this step is easy. All you have to do is square the y part, and divide the power by half.
		Do this while the power is greater than 1. If the power is even, divide by 2. Else reduce it by one and multiply 
		the remaining integer in any other variable, as Explained above.*/
        while(ti>1){
            if(ti%2==0){
                y*=y;
                ti/=2;
            }
            else{
                t*=y;
                ti-=1;
            }
        }
		
		//Multiply the storing part with the answer.
        y*=t;
		//Check if n is positive or negative. If negative, then we need to divide it by 1.
        if(n < 0){
            return 1/y;
        }
		//Return the Answer
        return y;
    }
};