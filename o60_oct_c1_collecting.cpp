#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
	int N,M,l;
	scanf("%d%d%d",&N,&M,&l);
	int S,T;
	scanf("%d%d",&S,&T);
	int L[N+1];
	int u,v,w,c;
	for(int i=1;i<=N;++i) scanf("%d",&L[i]);
	vector <pii> G[N+1];
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
	}
	int dis[N+1][l+1];
	bool visited[N+1][l+1];
	for(int i=1;i<=N;++i){
		for(int j=0;j<=l;++j){
			dis[i][j]=2e9;
			visited[i][j]=false;
		}
	}
	priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>> PQ;
	dis[S][0]=0;
	PQ.push({{dis[S][0],S} , 0});
	while(!PQ.empty()){
		u=PQ.top().first.second;
		c=PQ.top().second;PQ.pop();
		if(visited[u][c]) continue;
		visited[u][c]=true;
		if(u==T and c==l){
			break;
		}
		for(auto vw:G[u]){
			v=vw.first;
			w=vw.second;
			if(L[v]==c+1){
				if(!visited[v][c+1] and dis[v][c+1]>dis[u][c]+w){
					dis[v][c+1]=dis[u][c]+w;
					PQ.push({{dis[v][c+1],v},c+1});
				}
			}else{
				if(!visited[v][c] and dis[v][c]>dis[u][c]+w){
					dis[v][c]=dis[u][c]+w;
					PQ.push({{dis[v][c],v},c});
				}
			}
		}
	}
	if(dis[T][l]==2e9) dis[T][l]=-1;
	printf("%d",dis[T][l]);
}
