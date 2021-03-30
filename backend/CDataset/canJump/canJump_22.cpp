bool canJump(int A[], int n) {
    if(n == 0){
        return true;
    }
    int maxReachPos = A[0];
    for(int i = 0; i <= maxReachPos; i++){
        if(maxReachPos >= n - 1){
            return true;
        }
        maxReachPos = max(maxReachPos, i + A[i]);
    }
    return false;
}
