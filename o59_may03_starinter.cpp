#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using lli=long long;

int main(){
	int n,k,t=1;
	lli ans=0;
	scanf("%d%d",&n,&k);
	vector <pii> G[n+1];
	for(int i=1;i<n;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		if(G[u].size()>2){
			t=u;
		}else if(G[v].size()>2){
			t=v;
		}
	}
	stack <int> Q;
	int visited[n+1],dis[n+1];
	for(int i=0;i<=n;++i){
		visited[i]=0;
	}
	vector <int> line[100002];
	visited[t]=1;
	for(int i=1;i<=G[t].size();++i){
		int v=G[t][i-1].first;
		int w=G[t][i-1].second;
		visited[v]=i;
		dis[v]=w;
		Q.push(v);
	}
	while(!Q.empty()){
		int u=Q.top();Q.pop();
		if(dis[u]<=k) ++ans;
		line[visited[u]].push_back(dis[u]);
		for(auto vw:G[u]){
			int v=vw.first;
			int w=vw.second;
			if(!visited[v]){
				visited[v]=visited[u];
				dis[v]=dis[u]+w;
				
				Q.push(v);
			}
		}
	}
	for(int l=1;l<=G[t].size();++l){
		sort(line[l].begin(),line[l].end());
	}
//	printf("(%d)\n",ans);
	for(int l=1;l<=G[t].size();++l){
		for(int i=0;i<line[l].size();++i){
			//printf("%d ",line[l][i]);
			int c=lower_bound(line[l].begin() , line[l].end() , line[l][i]+k+1)-line[l].begin()-1;
			ans+=(c-i);
			//printf("(%d) ",c-i);
			//printf("others ");
			for(int ll=l+1;ll<=G[t].size();++ll){
				int cc=lower_bound(line[ll].begin() , line[ll].end() , k-line[l][i]+1)-line[ll].begin();
				ans+=cc;
				//printf("(%d)",cc);
			}
		}
		//printf("\n");
	}
	printf("%lld",ans);
}
