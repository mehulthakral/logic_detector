
class Solution {
public:
    void ans(vector<int>& array,int l,int r){
        if(l>=r)
            return;
        int leftidx=l+1;
        int rightidx=r;
        int pivotidx=l;
        while(rightidx>=leftidx){
            if(array[leftidx]>array[pivotidx]&&array[rightidx]<array[pivotidx])
                swap(array[leftidx],array[rightidx]);
            if(array[leftidx]<=array[pivotidx])
                leftidx++;
            if(array[rightidx]>=array[pivotidx])
                rightidx--;
        }
        swap(array[rightidx],array[pivotidx]);
        bool leftsubarraysmall=rightidx-1-l<r-(rightidx+1);
        if(leftsubarraysmall){
            ans(array,l,rightidx-1);
            ans(array,rightidx+1,r);
        }else{
            ans(array,rightidx+1,r);
            ans(array,l,rightidx-1);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        ans(nums,0,nums.size()-1);
        return nums;
 }
};
