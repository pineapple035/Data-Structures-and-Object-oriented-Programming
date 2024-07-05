#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,c=0;
	cin>>t;
	while(t--)
	{
		c++;
		long long int m[105][105];
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>m[i][j];
			}
		}
		int flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(m[i][j]!=m[j][i]) 
				{
					flag=0;	
					break;
				}
			}
		}
		
		if(flag==1) cout<<"Test #"<<c<<": Symmetric."<<endl;
		else cout<<"Test #"<<c<<": Non-symmetric."<<endl;
	}
	return 0;
}
