class Solution {
public:
double myPow(double x, int n) {
    double t;
    if(n == 0){
        return 1;
    }
    t = myPow(x, n/2);
    if(n % 2 == 0){
        return t * t; 
    }
    else{
        if(n > 0){
            return x * t * t;
        }
        else {
            return t * t / x;
        }
    }        
}
};
