#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string initial;
    string mini;
    string s;
    cin>>initial;
    s=initial;
    mini=initial;
    int m=1;
    for(int k=1;k<=n;k++)
    {
        //cout<<k<<endl;
        for(int j=0;j<n-k+1;j++)
        {
            for(int i=0;i<(k+1)/2;i++)
            {
                swap(s[i+j],s[k-i-1+j]);
                //cout<<j<<" ";
                //cout<<i+j<<" "<<k-i-1+j<<" "<<s<<endl;
            }

        }
        if(s<mini)
            {
                mini=s;
                m=k;
            }
        s=initial;
    }
    cout<<mini<<endl<<m<<endl;
    return 0;
}
