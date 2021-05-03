class Solution {
public:
    int countPrimes(int n) {
        if(n<3)return 0;
        vector<bool>ntp(n,false);//ntp::=notPrime,initially assuming all odd numbers are prime so for of them ntp is false
        int lim=sqrt(n),ans=n/2;//assuming all odd numbers are prime,so assumed no of primes=n/2 (half of the numbers are odd)
        for(int i=3;i<=lim;i+=2)//i+=2 for loading only odd numbers.
            if(!ntp[i])//if prime we need to subtract it's odd multiples
                for(int j=i*i;j<n;j+=2*i)//odd multiples only j=i*i+even*i=i*(i+even)=odd multiples as i is odd,so (i+even) is odd.
                {
                    if(!ntp[j]){//wrongly assumed before so we need to update the anwer as it was included in the answer number.
                        ans--;
                        ntp[j]=true;
                    }
                }
        return ans;
    }
};
