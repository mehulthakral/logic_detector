class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string ans;
		dfs(res, s,ans, 0,0);
		return res;
	}
	void dfs(vector<string>& res, string s, string ans,int idx, int depth)
	{
		if (depth > 4) return;
		if ((depth == 4) && (idx == s.size()))
		{
		    ans.erase(ans.end()-1);
			res.push_back(ans);
			return;
		}
		
		for (int i = 1; i < 4; ++i)
		{
	    	if (s[idx] == '0' && i>1) return;
			if (idx + i > s.size()) return;
			auto tmp = s.substr(idx, i);
			if (stoi(tmp) < 256)
			{						
				dfs(res, s, ans+ tmp+".", idx + i, depth + 1);
			}
			else
			{
				return;
			}
		}		
	}
};