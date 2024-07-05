#include <bits/stdc++.h>
using namespace std;
int main()
{
    int f,i;
    cin>>f>>i;
    int market[105];
    for(int j=0;j<f;j++)
    {
        cin>>market[j];
    }

    int d[505][505];
    for(int j=1;j<=i;j++)
    {
        for(int k=1;k<=i;k++)
        {
            d[j][k]=INT_MAX;
        }
    }
    for(int j=1;j<=i;j++)
    {
        d[j][j]=0;
    }
    int I=i;
    int a,b,len;
    while(cin>>a>>b>>len)
    {
        d[a][b]=d[b][a]=len;
        //if(a>i) I=a;
        //if(b>i) I=b;
    }
    //i=I;

    for(int k=1;k<=i;k++)
    {
        for(int j=1;j<=i;j++)
        {
            for(int l=1;l<=i;l++)
            {
                if(d[j][k]!=INT_MAX && d[k][l]!=INT_MAX)
                {
                    d[j][l]=min(d[j][l],d[j][k]+d[k][l]);
                }
                //cout<<j<<" "<<l<<" "<<k<<" "<<d[j][l]<<" "<<d[j][k]<<" "<<d[k][l]<<endl;
            }
        }
    }

    int minmaxdis=INT_MAX;
    int newmarket=market[0];
    for(int j=1;j<=i;j++)
    {
        market[f]=j;
        //cout<<"新建超市在 "<<j<<endl;
        int currmaxdis=INT_MIN;
        int currnewmarket;

        for(int l=1;l<=i;l++)
        {
            int lmmin=INT_MAX;
            for(int k=0;k<f+1;k++)
            {
                lmmin=min(lmmin,d[l][market[k]]);
                //cout<<l<<" 到超市的距離是 "<<lmmin<<" 現在最大距離 "<<currmaxdis<<endl;

            }
            if(lmmin>currmaxdis)
            {
                    currmaxdis=lmmin;
                    currnewmarket=j;
            }

        }
        if(currmaxdis<minmaxdis)
        {
            minmaxdis=currmaxdis;
            newmarket=currnewmarket;
        }
    }
    //if(newmarket==13) cout<<1<<endl;
    cout<<newmarket<<endl;

    return 0;
}
