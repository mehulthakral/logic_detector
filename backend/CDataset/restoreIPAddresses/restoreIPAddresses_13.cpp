void helper(string& s, const int sz, int pos, int count, string path, vector<string>& ret)
{
	if (!count)
	{
		if (sz == pos)
		{
			path.erase(path.end() - 1);
			ret.push_back(path);
		}
		return;
	}
	if ('0' == s[pos])
	{
		helper(s, sz, pos + 1, count - 1, path + "0" + ".", ret);
		return;
	}
	int i = 0;
	for (; pos + i < sz && i < 3; ++i)
	{
		string t = s.substr(pos, i + 1);
		if (stoi(t) <= 255)
			helper(s, sz, pos + i + 1, count - 1, path + t + ".", ret);
		else
			break;
	}
	return;
}
vector<string> restoreIpAddresses(string s) 
{
	vector<string> ret;
	if (s.empty() || s.size() < 4)
		return ret;
	int i, k, sz = s.size();
	helper(s, sz, 0, 4, "", ret);
	return ret;
}