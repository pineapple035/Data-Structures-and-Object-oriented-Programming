#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i=1;
    bool flag=false;
    long long int num[100005]={0};
    while(cin>>num[i] )
    {
        i++;
    }
    sort(num,num+i);
    for(int j=1;j<i;j++)
    {
        if(num[j]==num[j+1])
        {
            flag=true;
            break;
        }
    }
    if(flag==true) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}
