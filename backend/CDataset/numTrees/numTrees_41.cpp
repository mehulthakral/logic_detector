class Solution {
public:
    int numTrees(int n) {
        map<int, int> Mymap;
		Mymap[0] = 1;
		for (int i = 1; i <= n; i++){
		    int cont = 0;
			for (int k = 0; k < i; k++)
			cont+= Mymap[k] * Mymap[i - 1 - k];
			Mymap[i] = cont;
		}
		return Mymap[n];
    }
};