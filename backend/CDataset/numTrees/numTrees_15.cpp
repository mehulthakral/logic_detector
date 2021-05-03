class Solution {
public:
	vector<int> v;
	int numTressHelper(int n) {
		if (v[n] != 0)
			return v[n];
		for (int i = 1; i <= n; i++) {
			v[n] += numTressHelper(i - 1) * numTressHelper(n - i);
		}
		return v[n];

	}
	int numTrees(int n) {
		v.resize(n + 1);
		v[0] = 1;
		v[1] = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += numTressHelper(i - 1) * numTressHelper(n - i);
		}
		return sum;
	}
};
