#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int s[10000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int d,flag;
    for(int i=0;i<n;i++)
    {
        d=0;
        flag=0;
        for(int j=i+1;j<n;j++)
        {
            d++;
            if(s[i]<s[j])
            {
                flag=d;
                break;
            }
        }
        if(i==n-1) break;
        if(flag==0) cout<<0<<" ";
        else cout<<flag<<" ";
    }
    if(flag==0) cout<<0<<endl;
    else cout<<flag<<endl;

    return 0;
}
