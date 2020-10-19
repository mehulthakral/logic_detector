class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        block_size = 1;
        while block_size <= len(nums):
            for l in range(0, len(nums), block_size * 2):
                r = min((l + (2 * block_size)), len(nums));
                mid = l + block_size;
                
                L = nums[l:mid];
                R = nums[mid:r];
                
                srt = [];
                i = j = 0;
                
                while i < len(L) and j < len(R):
                    if L[i] <= R[j]:
                        srt.append(L[i]);
                        i += 1;
                    else:
                        srt.append(R[j]);
                        j += 1;
                while i < len(L):
                    srt.append(L[i]);
                    i += 1;
                while j < len(R):
                    srt.append(R[j]);
                    j += 1;
                nums[l:r] = srt;
            block_size = block_size * 2;
        return nums;
