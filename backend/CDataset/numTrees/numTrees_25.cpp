int numTrees(int n) {

    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        arr[i]=0;
        for(int j=0;j<i;j++)
        {
            arr[i]+=arr[j]*arr[i-j-1];
        }
    }
    return arr[n];
}