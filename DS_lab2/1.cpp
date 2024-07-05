#include <bits/stdc++.h>
using namespace std;
int main()
{
    int  n;
    int d[100005]={0};
    int l[100005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        l[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(d[j]<=d[i]) l[i]=max(l[i],l[j]+1);
        }
    }
    int len=0;
    for(int i=0;i<n;i++) len=max(len,l[i]);
    if(len>=n-1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
