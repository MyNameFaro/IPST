#include<bits/stdc++.h>
using namespace std;
int DP[3002][3002],arr[3002];
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int ans=2e9;
	priority_queue <int,vector<int>,greater<int>> pq;
	for(int i=1;i<=N;++i){
		scanf("%d",&arr[i]);
		pq.push(arr[i]);
	}
	if(K>=N){
		ans=0;
		ans+=pq.top();
		pq.pop();
		ans+=pq.top();
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j) DP[i][j]=2e9;
	}
	for(int i=N;i>=1;--i){
		for(int j=i+1;j<=min(i+K-1,N);++j){
			for(int k=i+1;k<=j;++k){
				DP[i][j]=min(DP[i][j],arr[k]+DP[k][min(i+K-1,N)]);
				
			}
		}
	}
	/*for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			printf("%d ",DP[i][j]);
		}
		printf("\n");
	}*/
	printf("%d",ans);
}
