#include <bits/stdc++.h>
using namespace std;

vector<int> apple;
vector<vector<int>> leaf;
int step=0;
int root;

void dfs(int v)
{
    int applenum=apple[v];
    for(int i=0;i<leaf[v].size();i++)
    {
        int childleaf=leaf[v][i];
        dfs(childleaf);
        applenum+=apple[childleaf];
        //cout<<childleaf<<" "<<applenum<<endl;
    }
    step+=abs(applenum-1);
    if(v!=root)
    {
        apple[v]=applenum-1;
    }
}

int main()
{
    int n;
    cin>>n;
    apple.resize(n+1);
    leaf.resize(n+1);
    for(int i=0;i<n;i++)
    {
        int v,u,d; //v頂點編號，u是蘋果數量，d是子節點數量
        cin>>v>>u>>d;
        if(i==0) root=v;
        apple[v]=u;
        leaf[v].resize(d);
        for(int j=0;j<d;j++)
        {
            cin>>leaf[v][j];
        }

    }
    dfs(root);

    cout<<step<<endl;

    return 0;
}
