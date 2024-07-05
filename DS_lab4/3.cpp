#include <bits/stdc++.h>
using namespace std;

vector<int> change(vector<int>& pre)
{
    if(pre.empty()==1) return {};
    int root=pre[0];
    vector<int> left,right;
    for(int i=1;i<pre.size();i++)
    {
        if(pre[i]<root)
        {
            left.push_back(pre[i]);
        }
        else
        {
            right.push_back(pre[i]);
        }
    }
    vector<int> leftpost=change(left);
    vector<int> rightpost=change(right);

    vector<int> post;
    post.reserve(leftpost.size()+rightpost.size()+1);
    post.insert(post.end(),leftpost.begin(),leftpost.end());
    post.insert(post.end(),rightpost.begin(),rightpost.end());
    post.push_back(root);

    return post;
}

int main()
{
    int n;
    cin>>n;
    vector<int> pre(n);
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }

    vector<int> post=change(pre);

    for(int i=0;i<post.size();i++)
    {
        cout<<post[i];
        if(i!=post.size()-1) cout<<" ";
    }
    cout<<endl;

    return 0;
}
