class Solution {
public:
vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string solution = "";
		backtracking(s,result,solution,0, 0);
		return result;
	}
	void backtracking(string s,vector<string> &result,string solut, int start, int part)
	{
		if (start == s.size() && part == 4){
			result.push_back(solut);
			return;
		}
		else if (part == 4 && start != s.size())
			return;
		else if (part == 3 && (s.size() - start > 3 || s.size() - start < 1))
			return;
		else if (part == 2 && (s.size() - start<2 || s.size() - start>6))
			return;
		else if (part == 1 && (s.size() - start<3 || s.size() - start>9))
			return;
		for (int i = start; i < s.size(); i++)
		{
			if (i - start < 3 && validIP(s, start, i))
			{
				solut.append(s.substr(start, i - start + 1));
				part++;
				if (part < 4) solut.push_back('.');
				backtracking(s, result,solut,i + 1, part);
				if (part < 4) solut.pop_back();
				part--;
				for (int j = 0; j < i - start + 1; j++) solut.pop_back();
			}
			else
				return;
		}
	}
};