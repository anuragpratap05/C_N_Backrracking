# C_N_Backrracking
#include<bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    
   
    
    if(n==0)
    {
        return 1;
    }
    
    int sa=x*power(x,n-1);
    return sa;
}

int main()
{
    int x,n;
    cin>>x>>n;
    int ans;
    if(x==0 && n==0)
        ans=1;
    
    else
    {
    ans=power(x,n);
    }
    cout<<ans;
}
