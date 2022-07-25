int f(int n ,vector<int>&h)
{
    if(n==0)
        return 0;
    if(n==1)
        return abs(h[1]-h[0]);
    int left = f(n-1,h)+abs(h[n]-h[n-1]);
    int right = f(n-2,h) +abs(h[n]-h[n-2]);
    return min(left,right);
}
int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    return f(n-1,h);
}