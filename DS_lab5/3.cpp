#include <bits/stdc++.h>
using namespace std;

int ans[15],a[15];

void dfs(int nowtotal,int next,int k)
{
    if(nowtotal==6)
    {
        for(int i=0;i<6;i++)
        {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=next;i<k;i++)
    {
        ans[nowtotal]=a[i];
        dfs(nowtotal+1,i+1,k);
    }
}

int main()
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,k);

    return 0;
}
