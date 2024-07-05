#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    unordered_map<int,int> frequency;
    for(int num:a)
    {
        frequency[num]++;
    }

    int ans=0;
    bool flag=true;

    for(auto number:frequency)
    {
        int times=number.second;
        ans+=(times/6)*2;
        times=times%6;
        if(times==5 || times==4) ans+=2;
        else if(times==3 || times==2) ans+=1;
        else if(times==1)
        {
            flag=false;
            break;
        }
    }
    if(flag==false) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}
