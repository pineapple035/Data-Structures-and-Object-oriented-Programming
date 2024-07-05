#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s[1005];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int stacks[1005];
    int top=0;
    int cur=1;
    int flag=1;
    for(int i=0;i<n;i++)
    {
        int plate=s[i];

        while(cur<=plate)
        {
            stacks[top++]=cur;
            cur++;
        }
        if(stacks[top-1]!=plate)
        {
            flag=0;
            break;
        }
        else
        {
            top--;
        }
    }
    if(flag==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
