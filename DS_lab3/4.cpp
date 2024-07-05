#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid,int i,int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
    {
        return;
    }
    grid[i][j]='0';
    dfs(grid,i-1,j);
    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
}

int numisland(vector<vector<char>>& grid)
{
    int num=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]=='1')
            {
                dfs(grid,i,j);
                num++;
            }
        }
    }
    return num;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<char>> grid(m,vector<char>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<numisland(grid)<<endl;
    return 0;
}
