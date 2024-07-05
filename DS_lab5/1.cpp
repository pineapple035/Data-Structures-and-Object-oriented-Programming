#include <bits/stdc++.h>
using namespace std;
int main()
{
    string maxa;
    cin>>maxa;

    int group[30]={0};
    for(int i=0;i<=maxa[0]-'A';i++)
    {
        group[i]=i;
    }
    string a;
    while(cin>>a)
    {
        if(a.empty()) break;
        int mingroup=min(group[a[0]-'A'],group[a[1]-'A']);
        int maxgroup=max(group[a[0]-'A'],group[a[1]-'A']);

        for(int i=0;i<=maxa[0]-'A';i++)
        {
            if(group[i]==maxgroup) group[i]=mingroup;
        }
    }

    bool visited[30]={false};
    int ans=0;
    for(int i=0;i<=maxa[0]-'A';i++)
    {
        if(visited[group[i]]==false)
        {
            visited[group[i]]=true;
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}
