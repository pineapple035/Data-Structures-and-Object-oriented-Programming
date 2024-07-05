#include<bits/stdc++.h>
using namespace std;

const int maxi=INT_MAX;

int shortestpath(vector<vector<pair<int,int>>>& graph,int start,int dest,vector<int>& pre)
{
    int n=graph.size();
    vector<int> dis(n,maxi);
    dis[start]=0;
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq; //priority_queue由小到大
    pq.push({0,start});
    while(pq.empty()==0)
    {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dis[u]) continue;
        for(auto& edge:graph[u])
        {
            int v=edge.first;
            int w=edge.second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
                pre[v]=u;
            }
        }
    }

    return dis[dest];
}

void passpath(vector<int>& pre,int start,int dest)
{
    stack<int> path;
    int curr=dest;
    while(curr!=-1)
    {
        path.push(curr+1);
        curr=pre[curr];
    }

    cout << "Path = ";
    cout<<path.top();
    path.pop();
    while(path.empty()==0)
    {
        cout<<" "<<path.top();
        path.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0;i<n;i++)
    {
        int connectnum;
        cin>>connectnum;
        for(int j=0;j<connectnum;j++)
        {
            int nextblock,wait;
            cin>>nextblock>>wait;
            graph[i].push_back({nextblock-1,wait});
        }
    }
    int start,dest;
    cin>>start>>dest;
    vector<int> pre(n,-1); //N元素，起始為-1
    int shortesttime=shortestpath(graph,start-1,dest-1,pre);
    passpath(pre,start-1,dest-1);
    cout<<"; "<<shortesttime<<" second delay"<<endl;


    return 0;
}
