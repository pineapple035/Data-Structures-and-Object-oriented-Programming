#include <bits/stdc++.h>
using namespace std;
int main()
{
	const char* rev="A000300HIL0JM0O0002TUVWXY51SE0Z0080";
	char s[30];
	while(scanf("%s",s) == 1)
	{
		int len=strlen(s);
		bool p=1,m=1;
		for(int i=0;i<(len+1)/2;i++)
		{
			if(s[i]!=s[len-i-1])p=0;
			if(isupper(s[len-i-1])&&s[i]!=rev[s[len-i-1]-'A'])m=0;
			if(isdigit(s[len-i-1])&&s[i]!=rev[s[len-i-1]-'1'+26]) m=0;
		}
		if(p==1&&m==1) cout<<s<<" -- is a mirrored palindrome."<<endl;
		else if(p==1) cout<<s<<" -- is a regular palindrome."<<endl;
		else if(m==1) cout<<s<<" -- is a mirrored string."<<endl;
		else cout<<s<<" -- is not a palindrome."<<endl;
	}
	return 0;
 }
