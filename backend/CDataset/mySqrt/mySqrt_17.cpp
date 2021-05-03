class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) return x;
		
		uint64_t mult = 0;
		int count = 0;
		
		//have mult start with half the bits of the other, if that's 0 or odd, then +1 bits
		while ((x >> (31 - count) & 1u) == 0) count++;
		count = (32 - count)/2 - ((count+1) % 2);
		
		//set all mult bits to 1 from count to beginning
		mult |= (~(0u) >> (31 - count));

		//while mult is greater, set smaller bits to 0
		while (mult * mult > x && count > 0) {
			count--;
			mult ^= (1u << count);
			
			//mult^2 is less than x but has too large of a difference, reset bit back to 1
			if (mult * mult + (mult * 2) < x) mult |= (1u << count);
		}
		return mult;
	}
};