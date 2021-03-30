class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i = coins.size()-1;
        int count = 0;
        if(amount == 0){
            return 0;
        }
        if(amount<coins[0]){
            return -1;
        }
        helperFunction(coins, amount, i, count);
        return count;
    }
    
    void helperFunction(vector<int>& coins, int& amount, int& i, int& count){
        if(amount == 0){
            return;
        }
        if(amount - coins[i] >= 0){
            amount = amount - coins[i];
            count++;
            helperFunction(coins, amount, i, count);
        }
        else{
            i--;
            helperFunction(coins, amount, i, count);
        }
    }
};
