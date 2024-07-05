#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a;
    int c=1;
    string s;

    int sum=0;
    while(n--)
    {
        vector<int> w;
        vector<string> ss;
        while(1) //讀輸入的字串
        {
            cin>>s;
            sum=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]>='a' && s[i]<='z')
                {
                    sum=sum*32;
                    sum=sum+s[i]-'a'+1;
                }
            }
            w.push_back(sum); //各個單字的和
            ss.push_back(s);
            a=getchar();
            if(a!=' ') break;
        }

        //
        c=1;
        int N=w.size();
        bool flag=true;
        int I,J;
        while(1)
        {
            flag=1;
            for(int i=0;i<w.size()-1;i++)
            {
                for(int j=i+1;j<w.size();j++)
                {
                    if((c/w[i])%N == (c/w[j])%N)
                    {
                        //cout<<ss[i]<<" "<<c<<" "<<v[i]<<" "<<ss[i].size()<<endl;
                        //cout<<ss[j]<<" "<<c<<" "<<v[j]<<" "<<ss[j].size()<<endl;
                        flag=0;
                        I=i;
                        J=j;
                        break;
                    }
                }
                if(flag==0) break;
            }
            if(flag==0)
            {
                c=min((c/w[I]+1)*w[I] , (c/w[J]+1)*w[J]);
                //cout<<c<<endl;
            }
            else
            {
                break;
            }
        }
        for(int i=0;i<ss.size();i++)
        {
            if(i!=0) cout<<" ";
            cout<<ss[i];
        }
        cout<<endl;
        cout<<c<<endl<<endl;

    }

    return 0;
}
