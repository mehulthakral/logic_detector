class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        std::deque<int> qDigits;
        while(x!=0){
           qDigits.push_back(x%10);
            x /= 10;
        }
        
        auto iterBegin = qDigits.begin();
        auto iterEnd = qDigits.end();
        iterEnd--;
        
        while(iterBegin < iterEnd){
            if (*iterBegin != *iterEnd){
                return false;
            }
            iterBegin++;
            iterEnd--;
        }
        
        return true;
    }
};
