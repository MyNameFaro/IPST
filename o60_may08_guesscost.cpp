#include<bits/stdc++.h>
using namespace std;

int DP[302][302];
int main(){
	int n;
	scanf("%d",&n);
	int arr[n+1];
	//INPUT
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	//DP
	for(int l=n;l>=1;--l){
		DP[l][l]=arr[l];
		for(int r=l+1;r<=n;++r){
			DP[l][r]=2e9;
			for(int k=l+1;k<r;++k){
				DP[l][r]=min(DP[l][r],arr[k]+max(DP[l][k-1],DP[k+1][r]));
			}
			DP[l][r]=min(DP[l][r],arr[l]+DP[l+1][r]);
			DP[l][r]=min(DP[l][r],arr[r]+DP[l][r-1]);
		}
	}

	printf("%d",DP[1][n]);
}
