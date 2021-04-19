class Solution {
public:
bool isPalindrome(int x) {
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;
	int rx = 0;
	while (x > rx) {
		rx = rx * 10 + x % 10;
		x /= 10;
	}
	return x == rx || x == rx / 10;;
}
};