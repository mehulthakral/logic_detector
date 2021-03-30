class Solution {
public:
    bool checkprime(int&number){
        int stop = ceil((double)(sqrt(number)));
        for(int div=3;div<=stop;div+=2){
            if(number%div==0){return false;}
        }
        return true;
    }
    int countPrimes(int n) {
        int result=(n>2)?1:0;
        for(int numbers=3;numbers<n;numbers+=2){
            if(checkprime(numbers)){result++;}
        }
        return result;
    }
};
