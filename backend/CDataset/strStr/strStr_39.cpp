class Solution {
public:
int strStr(string h, string n) {
    int j;
    if(n.size()==0)
        return 0;
    for(int i=0;i<=(int)(h.length()-n.length());i++)
    {
        for(j=0;j<n.length();j++)
        {
            if(h[i+j]!=n[j])
               break;
        }
        if(j==n.length())
           return i;
    }
    return -1;
   }
 };
