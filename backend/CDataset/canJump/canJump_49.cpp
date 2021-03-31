class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return false;
		if (nums.size() == 1)
			return true;
		if (nums[0] == 0)
			return false;
		bool can_over;
		for (int i = nums.size() - 2; i > 0; --i)
		{
			if (nums[i])
				continue;
			can_over = false;
			int j;
			for (j = i - 1; j >= 0; --j)
			{
				if (nums[j] > i - j)
				{
					can_over = true;
					break;
				}
			}
			if (!can_over)
				return false;
			i = j;
		}
		return true;
	}
};
