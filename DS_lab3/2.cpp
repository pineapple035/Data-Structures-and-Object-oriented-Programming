#include <bits/stdc++.h>
using namespace std;
int main()
{
    string b;
    stack<char> s;
    getline(cin,b);
    int len=b.size();
    int ans=0;
    for(int i=0;i<len;i++)
    {
        //cout<<"ab"<<endl;

        if(b[i]==')')
        {
            //cout<<"cd"<<endl;
            if(!s.empty()&&s.top()=='(')
            {
                s.pop();
                //cout<<"pop"<<endl;
            }
            else
            {
                ans++;
                //cout<<"ans "<<ans<<endl;
            }
        }
        else if(b[i]=='(')
        {
            //cout<<"ef"<<endl;
            s.push(b[i]);
            //cout<<"push "<<endl;
        }
    }

    ans+=s.size();
    cout<<ans<<endl;
    return 0;
}
