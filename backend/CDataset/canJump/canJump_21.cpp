bool canJump(int A[], int n) { // Greedy
    
    n==1?({return true;}):({;});  // Return true if already reach the end
    
    int max_index_can_jump = 0; // So far the current max index we can jump to.
    
    for (int i = 0; i <= max_index_can_jump; ++i )
    {
        if( (A[i]+i) > max_index_can_jump ) // check if need to update the current max index we can jump to
        {
            if((A[i]+i) >= (n - 1)) // check if we can jump to the last index (end)
            {
                return true;
            }
            else
            {
                max_index_can_jump = A[i]+i; // Then update
            }
        }
    }
    
    //return max_index_can_jump == (n-1); // First line is only one of the case
    
    return false;
}