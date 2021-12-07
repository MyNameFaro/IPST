#include<bits/stdc++.h>
using namespace std;
int DP[3002][3002],arr[3002];
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int ans=2e9;
	int mn1=2e9,mn2=2e9;
	for(int i=1;i<=N;++i){
		scanf("%d",&arr[i]);
		
	}
	if(K>=N){
		for(int i=1;i<=N;++i){
			if(arr[i]<=mn1){
				mn2=mn1;
				mn1=arr[i];
			}else if(arr[i]<=mn2){
				mn2=arr[i];
			}
		}
		printf("%d",mn1+mn2);
		return 0;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j) DP[i][j]=2e9;
	}
	int mn;
	for(int i=N;i>=N-K+2;--i){
		mn=2e9;
		for(int j=i;j<N+1;++j){
			mn=min(mn,arr[j]);
			DP[i][j]=mn;
		}
	}
	for(int i=N-K+1;i>=2;--i){
		mn=2e9;
		for(int j=i;j<i+K-1;++j){
			mn=min(mn,arr[j]+DP[j+1][i+K-1]);
			DP[i][j]=mn;
		}
	}
	//for(int i=1;i>=1;--i){
		mn=2e9;
		for(int j=1;j<K;++j){
			mn=min(mn,arr[j]+DP[j+1][K]);
			ans=min(ans,mn); 
		}
	//}
	/*for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			printf("%d ",DP[i][j]);
		}
		printf("\n");
	}*/
	printf("%d",ans);
}
