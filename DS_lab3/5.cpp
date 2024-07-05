#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[300000]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int dpmax=a[0];
    int maxsum=a[0];
    for(int i=1;i<n;i++)
    {
        dpmax=max(0,dpmax)+a[i];
        if(dpmax>maxsum) maxsum=dpmax;
    }
    int dpmin=a[0];
    int minsum=a[0];
    for(int i=1;i<n;i++)
    {
        dpmin=min(0,dpmin)+a[i];
        if(dpmin<minsum) minsum=dpmin;
    }
    int all=0;
    for(int i=0;i<n;i++)
    {
        all+=a[i];
    }
    int ans;
    if(maxsum<0) ans=maxsum;
    else ans=max(all-minsum,maxsum);
    cout<<ans<<endl;
    return 0;
}
