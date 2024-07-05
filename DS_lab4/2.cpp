#include <bits/stdc++.h>
using namespace std;
int dist(const pair<int,int>& pi, const pair<int,int>& pj)
{
    return (abs(pi.first-pj.first)+abs(pi.second-pj.second));
}
int main()
{
    int n;
    cin>>n;
    pair<int,int> point[1005];
    for(int i=0;i<n;i++)
    {
        cin>>point[i].first>>point[i].second;
    }

    bool visited[1005]={0};
    visited[0]=1;
    int ans=0;
    int connect=1;

    while(connect<n)
    {
        int mincost=INT_MAX;
        int near=-1;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(visited[j]==0)
                    {
                        int cost=dist(point[i],point[j]);
                        if(cost<mincost)
                        {
                            mincost=cost;
                            near=j;
                        }
                    }
                }
            }
        }

        visited[near]=1;
        ans+=mincost;
        connect++;
    }

    cout<<ans<<endl;

    return 0;
}
