#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int h[n+2];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int ans=0;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp=0;
        for(int j=i+1;j<n;j++)
        {
            if(h[i]>=temp)
            {
                if(h[j]>=temp)
                {
                    //cout<<i+1<<" "<<j+1<<endl;
                    ans++;
                }
            }
            temp=max(temp,h[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
