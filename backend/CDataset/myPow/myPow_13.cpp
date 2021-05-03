class Solution {
public:
    double myPow(double x, int y)
    {
        double temp;  
    if(y == 0)  
        return 1;  
    temp = myPow(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        if(y > 0)  
            return x * temp * temp;  
        else
            return (temp * temp) / x;  
    }  
    }
};
