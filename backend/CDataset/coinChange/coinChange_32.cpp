class Solution{
    public:
    int coinChange(vector<int>& coins, int amount) {
    
        if(coins.size()==0 || amount<0)
              return -1;
        if(amount==0)
               return 0;
        sort(coins.begin(), coins.end());
        int i =0;
        for( i=0; i<coins.size() && coins[i]<=amount; i++)
        {
            ;
        }
        int cnt = 0;
        int minCoins = amount+1;
        DFS(coins, i-1, amount, cnt, minCoins);
        
        return minCoins > amount ? -1: minCoins;
        
        
    }
    
    void DFS(vector<int> &coins, int index, int &amount, int &cnt, int &minCoins )
    {
    
        if(index == -1 )
             return ;
        
           
         int max = amount/coins[index];
         for(int i=max; i>=0; i--)
         {
             amount -= i*coins[index];
             cnt += i;
             if(amount > 0 && cnt < minCoins )
             {
                DFS(coins, index-1, amount, cnt, minCoins);   
             }
             else if(amount == 0 )
             {
                minCoins = min(minCoins, cnt);
             }
             else
             {
                 amount += i*coins[index];
                 cnt -= i;
             
                 break;
             }
             
            
             amount += i*coins[index];
             cnt -= i;
             
         }
         
    }
    
};
