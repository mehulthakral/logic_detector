//as for n number of trees possible= ((2n)C(n))/(n+1)
 //(2n)C(n) is equal to ((2n)*(2n-1)*...n terms) / (n*(n-1)*...*1)

 class Solution {
 public:
     int numTrees(int n) {
         double ans=1,i=2*n;
         for(int j=1;j<=n;j++,i--){
             ans*=(i/j);
              }
         return ans/(n+1);
     }
 };