class Solution {
private:
	void ipHelper(string &str, vector<string> &result, string strPre, int start, int num) {
		if (str.length() - start > num * 3 || str.length() - start < 0 || num < 0) return;
		if (num == 0) {
			strPre.pop_back();
			result.push_back(strPre);
		}
		for (int i = 0, count = 0; i < 3 && i + start < str.length(); ++i) {
			count = count * 10 + str[i + start] - '0';
			if (count <= 255)  ipHelper(str, result, strPre + str.substr(start, i + 1) + ".", start + i + 1, num - 1);
			if (count == 0)  return;
		}
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		string help;
		ipHelper(s, ret, help, 0, 4);
		return ret;
	}
}