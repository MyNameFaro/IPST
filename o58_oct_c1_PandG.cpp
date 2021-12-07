#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int>;
int G[102][102] ,P[102][102];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int main(){
	int K;
	scanf("%d",&K);
	while(K--){
		int R,C,n,T,rs,cs;
		scanf("%d%d%d%d%d%d",&R,&C,&n,&T,&rs,&cs);
		bool ans=false;
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				G[i][j]=2e9; //Row ,Column , Ghost i th	
				P[i][j]=2e9;	
			} 
		}
		queue <tll> Q;
		for(int i=1;i<=n;++i){
			int ri,ci,ti;
			scanf("%d%d%d",&ti,&ri,&ci);
			
			if(G[ri][ci]>ti){
				G[ri][ci]=ti;
				Q.emplace(ti , ri , ci);
			}
			
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				char c;
				cin >> c;
				if(c=='#'){
					G[i][j]=-1;
					P[i][j]=-1;
				} 
			}
		}
		while(!Q.empty()){
			int t = get<0>(Q.front());
			int r = get<1>(Q.front());
			int c = get<2>(Q.front());Q.pop();
			for(int i=0;i<4;++i){
				int rr=r+di[i];
				int cc=c+dj[i];
				int tt=t+1;
				if(rr<0 or rr>=R or cc<0 or cc>=C) continue;
				if(G[rr][cc]>tt){
					G[rr][cc]=tt;
					Q.emplace(tt,rr,cc);
				}
			}
		}
		Q.emplace(0 ,rs,cs);
		P[rs][cs]=0;
		int mx_P=-2e9;
		while(!Q.empty()){
			int t = get<0>(Q.front());
			int r = get<1>(Q.front());
			int c = get<2>(Q.front());Q.pop();
			mx_P=max(mx_P,t);
			for(int i=0;i<4;++i){
				int rr=r+di[i];
				int cc=c+dj[i];
				int tt=t+1;
				if(rr<0 or rr>=R or cc<0 or cc>=C) continue;
				if(P[rr][cc]>tt){
					P[rr][cc]=tt;
					Q.emplace(tt,rr,cc);
				}
			}
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(G[i][j]==-1) continue;
				if(P[i][j]<G[i][j] and P[i][j]==min(mx_P,T)){
					//cout << i << " " << j << endl;
					ans=true;
					break;
				}
			}
		}
		if(!ans){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
}
