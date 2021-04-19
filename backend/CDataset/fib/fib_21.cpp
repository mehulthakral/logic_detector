class Solution {
public:
void matvec_update(const uint32_t* A, uint32_t* s){
    uint32_t s_new[2];
    s_new[0] = A[0]*s[0] + A[1]*s[1];
    s_new[1] = A[2]*s[0] + A[3]*s[1];
    s[0] = s_new[0]; s[1] = s_new[1];
}

void mat_squared(uint32_t* A){
    uint32_t A_sq[4];
    A_sq[0] = A[0]*A[0] + A[1]*A[2];
    A_sq[1] = A[1]*(A[0] + A[3]);
    A_sq[2] = A[2]*(A[0] + A[3]);
    A_sq[3] = A[3]*A[3] + A[1]*A[2];
    A[0] = A_sq[0];
    A[1] = A_sq[1];
    A[2] = A_sq[2];
    A[3] = A_sq[3];
}

    int fib(int N) {
        if( N == 0 ){ return 0; }
        const uint32_t n = N-1;
        uint32_t A[4] = {1, 1, 1, 0}, sn[2] = {1, 0};
        uint32_t bit_idx = 1;
        while( bit_idx <= n ){
            if( n & bit_idx ){
                matvec_update(A, sn);
            }
            mat_squared(A);
            bit_idx = bit_idx << 1;
        }
        
        return sn[0];
    }
};