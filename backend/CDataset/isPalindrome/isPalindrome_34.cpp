class Solution {
public:
bool isPalindrome(int x) {
int a = x;
int b = a;
int c = b;
int len = 0;
long long int sum = 0;

	while (a > 0) {
		a /= 10;
		len++;
	}
	
	for (int i = 0; i < len; i++) {
		int power = len - i - 1;

		sum += (b % 10) * pow(10, power);
		b /= 10;
	}

	if (sum == c) {
		return true;
	}
	else
	{
		return false;
	}
}
};