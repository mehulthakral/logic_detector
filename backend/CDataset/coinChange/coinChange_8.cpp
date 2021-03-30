class Solution {
public:
    unordered_map<int,int> mem;
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        if(amount<0)return -1;
         auto it = mem.find(amount);
        if(it != mem.end()) return it->second;
        int prevcoin=-1;
        
        for(auto x:coins){
            int coin=coinChange(coins,amount-x);
            if(coin>=0) prevcoin=(prevcoin<0) ? coin : min(prevcoin,coin);
        }
        return mem[amount] = (prevcoin < 0) ?  -1 : prevcoin+1;
    }
};
