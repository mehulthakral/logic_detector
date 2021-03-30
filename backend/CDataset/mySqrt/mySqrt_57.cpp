int mySqrt(int x) {
		if (x <= 0)
			return 0;
		vector<int> num;
		while (x) {
			num.push_back(x%100);
			x /= 100;
		}

		int result = 0;
		int rd = 0;
		for (int i = num.size() - 1; i >= 0; i--) {    
			int j = 9;
			int temp = ( (rd * 10) + j) * j ;

			while (temp > num[i]) {
				j--;
				temp = ( (rd * 10) + j) * j ;
			}

			result = result * 10 + j;
			rd = (rd * 10 + j) ;

			int reminder = num[i] -  rd * j;

			if (i > 0) {
				num[i-1] = reminder * 100 + num[i-1];
			}

			rd+=j;
		}
		return result;
	}
