class Solution {
public:
	void merge(vector<int>& nums_left, vector<int>& nums_right, vector<int>& nums)
	{
		auto left = nums_left.begin();
		auto const left_end = nums_left.end();

		auto right = nums_right.begin();
		auto const right_end = nums_right.end();

		auto target = nums.begin();
		auto const target_end = nums.end();

		while (target != target_end)
		{
			while (left != left_end && (right == right_end || *left <= *right))
			{
				*target = *left;
				++left;
				++target;
			}
			while (right != right_end && (left == left_end || *right < *left))
			{
				*target = *right;
				++right;
				++target;
			}
		}
	}

	void merge_sort(vector<int>& nums)
	{
		size_t const size = nums.size();
		if (size <= 1)
		{
			return;
		}
		auto const left = nums.begin();
		auto const right = nums.end();
		auto const middle = left + size / 2;

		vector<int> nums_left{ left, middle };
		merge_sort(nums_left);

		vector<int> nums_right{ middle, right };
		merge_sort(nums_right);

		merge(nums_left, nums_right, nums);
	}

	vector<int> sortArray(vector<int>& nums)
	{
		merge_sort(nums);
		return nums;
	}
};