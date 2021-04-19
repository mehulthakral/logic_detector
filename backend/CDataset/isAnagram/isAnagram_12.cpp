class Solution {
public:
static bool isAnagram( const string& s, const string& t ) 
    {
        return is_permutation( begin( s ), end( s ), begin( t ), end( t ) );
    }
};