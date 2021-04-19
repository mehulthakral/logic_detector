class Solution {
public:
    
    bool isprime(int num){
        
        if(num==1) return false;
        
        for(int i=2;i*i<=num;i++){
            
            if(num%i==0) return false;
        }
        
        return true;
    }
    int countPrimes(int n) {
        
        
        int ans=0;
        
        for(int i=1;i<n;i++){
           
            if(isprime(i)){
                
                cout<<i<<" ";
                ans++;
            }
        }
        
        return ans;
        
    }
};