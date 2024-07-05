#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    char val;
    treenode* left;
    treenode* right;
    treenode(char i): val(i),left(NULL),right(NULL){}
};

treenode* findnode(string& pre,int& preindex,int prestart,int preend, string& ino,int inostart,int inoend, unordered_map<char,int>& inomap)
{
    if(prestart>preend || inostart>inoend) return NULL;
    char rootval=pre[preindex++]; //第一個pre是根
    treenode* root=new treenode(rootval);
    int inorootmid=inomap[rootval];
    root->left=findnode(pre,preindex,prestart,preend,ino,inostart,inorootmid-1,inomap);
    root->right=findnode(pre,preindex,prestart,preend,ino,inorootmid+1,inoend,inomap);
    return root;
}

treenode* constructtree(string pre,string ino)
{
    unordered_map<char,int> inomap;
    for(int i=0;i<ino.size();i++)
    {
        inomap[ino[i]]=i; //等等可以由pre得到對應的順序
    }
    int preindex=0;
    return findnode(pre,preindex,0,pre.size()-1, ino,0,ino.size()-1,inomap);
}

void post(treenode* root)
{
    if(root==NULL) return;
    post(root->left);
    post(root->right);
    cout<<root->val;
}
int main()
{
    string pre,ino;
    cin>>pre>>ino;
    treenode* root=constructtree(pre,ino);
    post(root);
    cout<<endl;

    return 0;
}
