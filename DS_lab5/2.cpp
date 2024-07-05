#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y,z,t;
};

int bfs(char m[31][31][31],bool visited[31][31][31],int l,int r,int c,point startpoint,point endpoint)
{
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    queue<point> q;
    q.push(startpoint);
    visited[startpoint.z][startpoint.y][startpoint.x]=true;
    while(!q.empty())
    {
        point curr=q.front();
        q.pop();
        if(curr.x==endpoint.x && curr.y==endpoint.y && curr.z==endpoint.z )
        {
            return curr.t;
        }

        for(int i=0;i<6;i++)
        {
            int nextx=curr.x+dx[i];
            int nexty=curr.y+dy[i];
            int nextz=curr.z+dz[i];

            if(nextx>=0 && nextx<c && nexty>=0 && nexty<r && nextz>=0 && nextz<l && visited[nextz][nexty][nextx]==false && m[nextz][nexty][nextx]!='#')
            {
                visited[nextz][nexty][nextx]=true;
                point nextpoint={nextx,nexty,nextz,curr.t+1};
                q.push(nextpoint);
            }
        }
    }

    return -1;
}
int main()
{
    int l,r,c;
    cin>>l>>r>>c;
    char m[31][31][31];
    bool visited[31][31][31]={false};

    point startpoint,endpoint;

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<r;j++)
        {
            for(int k=0;k<c;k++)
            {
                cin>>m[i][j][k];
                if(m[i][j][k]=='S')
                {
                    startpoint.x=k; //寬
                    startpoint.y=j; //長
                    startpoint.z=i; //第幾層
                    startpoint.t=0;
                }
                if(m[i][j][k]=='E')
                {
                    endpoint.x=k; //寬
                    endpoint.y=j; //長
                    endpoint.z=i; //第幾層
                }
            }
        }
    }

    int mintime=bfs(m,visited,l,r,c,startpoint,endpoint);
    if(mintime!=-1)
    {
        cout<<"Escaped in "<<mintime<<" minute(s)."<<endl;
    }
    else
    {
        cout<<"Trapped!"<<endl;
    }

    return 0;
}
