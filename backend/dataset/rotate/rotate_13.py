class Solution:
    def reverse(self,A,i,j):
        while i<j:
            A[i],A[j] = A[j],A[i]
            i += 1
            j -= 1
    def rotate(self, A:List[int], k:int)->None:
        L  = len(A)
        k %= L
        if k:
            self.reverse( A , 0 , L-1 )
            self.reverse( A , 0 , k-1 )
            self.reverse( A , k , L-1 )
