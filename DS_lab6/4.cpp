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
    int bropair=0;

    for(int i=0;i<n;i++)
    {
        int val=a[i]-i;
        if(frequency.find(val)!=frequency.end())
        {
            bropair+=frequency[val];
        }
        frequency[val]++;
    }
    cout<<bropair<<endl;

    return 0;
}
