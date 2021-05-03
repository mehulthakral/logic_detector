class Solution
{
public:
    #include<vector>
    class TreeNode{
        public:
        TreeNode* left;
        TreeNode* right;
        int val;
    };
    
    vector< int > inorderTraversal( TreeNode *root )
    {
        vector< int > out;
        stack< pair< int, TreeNode * > > toDo;
        TreeNode * current = root;
        
        for ( ;; )
        {
            if( current )
            {
                if( current->left )
                {
                    pair< int, TreeNode * > temp;
                    temp.first  = current->val;
                    temp.second = current->right;
                    toDo.push( temp );
                    current = current->left;
                }
                else
                {
                    out.push_back( current->val );
                    if( current->right )
                    {
                        current = current->right;
                    }
                    else current = 0;
                }
            }
            else
            {
                if( toDo.size() )
                {
                    out.push_back( toDo.top().first );
                    current = toDo.top().second;
                    toDo.pop();
                }
                else break;
            }
        }
        return out;
    }
};