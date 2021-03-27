#include<vector>
#include<cmath>
using namespace std;
vector<int> bubbleSort(vector<int> a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
	return a;
}
vector<int> mergeSort(vector<int> bar)
{
    class SORT
    {
        public:
        static void merge(vector<int> &array, vector<int> &L, vector<int> &R) {
            vector<int>::iterator a = array.begin();
            vector<int>::iterator l = L.begin();
            vector<int>::iterator r = R.begin();

            while(l != L.end() && r != R.end()) {
                if (*l <= *r) {
                *a = *l;
                l++;
                }
                else {
                    *a = *r;
                    r++;
                }
                a++;
            }
            while (l != L.end()) {
                *a = *l;
                a++;
                l++;
            }
            while (r != R.end()) {
                *a = *r;
                a++;
                r++;
            }
            
        }
        static void merge_sort(vector<int> &array) {
            if(array.size() == 1) return;
            else {
                const unsigned int len = array.size();
                const int lo = floor((double)len/2);
                const int hi = ceil((double)len/2);

                std::vector<int> L(&array[0], &array[lo]);
                std::vector<int> R(&array[lo], &array[len]);

                merge_sort(L);
                merge_sort(R);
                merge(array, L, R);
            }
        }
    };
	SORT::merge_sort(bar);
    return bar;
}
