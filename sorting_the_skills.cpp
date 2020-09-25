# C_N_Backrracking
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<n;i++)
    {
        if(a[i+1]==a[i]-1)
        swap(a[i],a[i+1]);
    }
    
    string ans="Yes";
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i)
        {
          ans="No";
          break;
        }
        
    }
    
    cout<<ans<<endl;
    }
}
