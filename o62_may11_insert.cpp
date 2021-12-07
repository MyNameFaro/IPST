#include <bits/stdc++.h>
using namespace std;
using lli=long long;

lli DP[505][505] ,DP2[505][505];
lli arr[200005];
char s[200005];
int main()
{
	int N;
	scanf("%d",&N);
	cin >> arr[1];
	for(int i=2;i<=N;++i)
	{
		cin >> s[i] >> arr[i];
	}
	for(int l=N;l>=1;--l)
	{
		for(int r=l;r <= N;++r)
		{
			DP2[l][r]=2e9;
			if(l==r)
			{
				DP[l][r]=arr[r];
				DP2[l][r]=arr[r];
				continue;
			}
			for(int k=l+1;k<=r;++k)
			{
				if(s[k]=='+')
				{
					DP[l][r]=max(DP[l][r] , DP[l][k-1] + DP[k][r]);
					DP2[l][r]=min(DP2[l][r] , DP2[l][k-1] + DP2[k][r]);
				}else{
					DP[l][r]=max(DP[l][r] , DP[l][k-1] - DP2[k][r]);
					DP2[l][r]=min(DP2[l][r] , DP2[l][k-1] - DP[k][r]);
				}
				
			}
		}
	}
	printf("%lld",DP[1][N]);
}
