#include <bits/stdc++.h>
using namespace std;

bool cycle(int node,int parent,unordered_map<int,int*> nodelist,unordered_set<int>& visited)
{
    visited.insert(node);
    for(int i=0;i<101;i++)
    {
        if(nodelist[node][i]==0) continue;
        int neighbor=nodelist[node][i];
        if(neighbor==parent) continue;
        if(visited.count(neighbor) || cycle(neighbor,node,nodelist,visited)) return true;
    }
    return false;
}

bool tree(pair<int,int>* edge)
{
    unordered_map<int,int*> nodelist;
    unordered_set<int> visited;
    for(int i=0;edge[i].first!=0 || edge[i].second!=0;i++)
    {
        int u=edge[i].first;
        int v=edge[i].second;
        if(!nodelist.count(u)) nodelist[u]=new int[101]();
        if(!nodelist.count(v)) nodelist[v]=new int[101]();
        for(int j=0;j<101;j++)
        {
            if(nodelist[u][j]==0)
            {
                nodelist[u][j]=v;
                break;
            }
        }
        for(int j=0;j<101;j++)
        {
            if(nodelist[v][j]==0)
            {
                nodelist[v][j]=u;
                break;
            }
        }
    }

    if(cycle(edge[0].first,-1,nodelist,visited)) return false;
    for(auto it=nodelist.begin();it!=nodelist.end();it++)
    {
        if(!visited.count(it->first)) return false;
    }

    return true;
}

int main()
{
    pair<int,int> edge[101];
    int u,v,edgeindex=0;
    int counts=0;
    while(1)
    {
        counts++;
        cin>>u>>v;
        if(u==0 && v==0) break;
        edge[edgeindex].first=u;
        edge[edgeindex].second=v;
        edgeindex++;
    }

    if(counts==1)
    {
        cout<<"True"<<endl;
    }
    else if(tree(edge))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }

    return 0;
}
