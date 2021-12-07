#include<bits/stdc++.h>
using namespace std;
int D(int x1 ,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}
int main(){
	int K,M;
	int x1,x2,y1,y2;
	scanf("%d %d",&K,&M);
	K=K*2;
	int hx[K+1],hy[K+1];
	int dis[K+1][K+1];
	for(int i=1;i<=K;++i){
		for(int j=1;j<=K;++j) dis[i][j]=2e9;
	}
	for(int i=1;i<=K;i+=2){
		scanf("%d %d %d %d",&hx[i],&hy[i],&hx[i+1],&hy[i+1]);
		dis[i][i+1]=0;
		dis[i+1][i]=0;
	} 
	for(int k=1;k<=K;++k){
		for(int i=1;i<=K;++i){
			for(int j=1;j<=K;++j){
				dis[i][j] = min(dis[i][j] , D(hx[i],hy[i],hx[j],hy[j]));
				if(dis[i][j]>dis[i][k]+dis[k][j] and dis[i][k]<2e9 and dis[k][j]<2e9) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	while(M--){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int ans=D(x1,y1,x2,y2);
		for(int i=1;i<=K;++i){
			for(int j=1;j<=K;++j){
				ans=min(ans , D(x1,y1,hx[i],hy[i]) + dis[i][j] + D(x2,y2,hx[j],hy[j]));
			}
		}
		printf("%d\n",ans);
	}
}
