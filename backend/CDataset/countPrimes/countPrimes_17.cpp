class Solution {
public:
int countPrimes(int n) {
vector prime(n, true);
if(n < 2){
return 0;
}
prime[0] = prime[1] = false;

    for(int i = 2 ; i < sqrt(n) ; i++){
        for(int j = i*i ; j < n ; j += i){
            prime[j] = false;
        }
    }
    
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(prime[i] == true)
            count++;
    }
    return count;
}
};