#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[30][30]={0};
    int dp[30][30]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }

    int sum=0,ans=-128;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int l=i;l<=n;l++)
            {
                for(int k=j;k<=n;k++)
                {
                    sum=dp[l][k]-dp[l][j-1]-dp[i-1][k]+dp[i-1][j-1];
                    ans=max(sum,ans);
                }
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

const int N = 125;
int a[N][N], s[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = i; k <= n; k++)
                for (int l = j; l <= n; l++) {
                    int sum = s[k][l] - s[i - 1][l] - s[k][j - 1] + s[i - 1][j - 1];
                    ans = max(ans, sum);
                }

    cout << ans << endl;
    return 0;
}
*/
