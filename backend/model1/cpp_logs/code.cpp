
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #include<algorithm>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    int ans=INT_MIN;
    int solve(TreeNode *trav){
        if(!trav)return 0;
        int sum=trav->val;

        int l_sum=solve(trav->left);
        int r_sum=solve(trav->right);
        
        l_sum=max(l_sum,0);
        r_sum=max(r_sum,0);
        
        ans =max(ans,l_sum+r_sum+sum);
        return max(l_sum,r_sum)+sum;
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};

Solution::TreeNode* newNode(int val, Solution::TreeNode* left, Solution::TreeNode* right)
{
    Solution::TreeNode* newNode = (Solution::TreeNode*) malloc(sizeof(Solution::TreeNode));
    if (!newNode) {
        cout << "Memory error";
        return NULL;
    }
    newNode->val = val;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Solution::TreeNode* makeTree(int i, vector<int>& lt)
{
    if(i>lt.size())
        return NULL;
    Solution::TreeNode* root = newNode(lt[i],makeTree(2*i+1,lt),makeTree(2*i+2,lt));
    return root;
}
        
int main()
{
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    Solution MyObj;
vector<int> vec {0,1,11,6,11,10,10,0,9,7,5,3,11,5,11,1,3,9,3,3,2,8,7,1,1,5,8,7,1,4,8,4};
Solution::TreeNode* inp1 = makeTree(0,vec);
MyObj.maxPathSum(inp1);    
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    cout << fixed 
         << time_taken << setprecision(9);
    return 0;
}
    