#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,num=1,m[25][25];
	cin>>n;
	int left=0,top=0,right=n-1,bottom=n-1;
	while(num<=n*n)
	{
		for(int i=left;i<=right;i++)
		{
			m[top][i]=num++;
		}
		top++;
		for(int i=top;i<=bottom;i++)
		{
			m[i][right]=num++;
		}
		right--;
		for(int i=right;i>=left;i--)
		{
			m[bottom][i]=num++;
		}
		bottom--;
		for(int i=bottom;i>=top;i--)
		{
			m[i][left]=num++;
		}
		left++;
	}
	cout<<"[";
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"[";
		for(j=0;j<n;j++)
		{
			cout<<m[i][j];
			if(j<n-1) cout<<",";
		}
		cout<<"]";
		if(i<n-1) cout<<",";
	}
	cout<<"]"<<endl;
	return 0;
}
