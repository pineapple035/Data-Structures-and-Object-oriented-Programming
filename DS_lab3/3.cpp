#include <bits/stdc++.h>
using namespace std;
int main()
{
    string k;
    stack<pair<string,int>> s;
    getline(cin,k);
    int len=k.size();
    int num=0;
    string currstr;
    for(int i=0;i<len;i++)
    {
        if(isdigit(k[i]))
        {
            num=num*10+(k[i]-'0');
        }
        else if(k[i]=='[')
        {
            s.push({currstr,num});
            currstr="";
            num=0;
        }
        else if(k[i]==']')
        {
            string prestr=s.top().first;
            int repeat=s.top().second;
            s.pop();
            for(int j=0;j<repeat;j++)
            {
                prestr+=currstr;
            }
            currstr=prestr;
        }
        else
        {
            currstr+=k[i];
        }
    }
    cout<<currstr<<endl;
    return 0;
}
