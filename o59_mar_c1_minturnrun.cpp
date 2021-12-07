#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int,int>;
int di[]={1,0,-1};
int dj[]={0,1,0};
int main(){
	int n,m,r,c,d,dis;
	char ch;
	scanf("%d%d%d",&n,&m,&r);
	bool visited[n+1][m+1];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin >> ch;
			if(ch=='#') visited[i][j]=true;
			else visited[i][j]=false;
		}
	}
	priority_queue <tll,vector<tll>,greater<tll>>PQ;
	PQ.emplace(0,r,1,1);
	int ans=-1;
	while(!PQ.empty()){
		dis=get<0>(PQ.top());
		r=get<1>(PQ.top());
		c=get<2>(PQ.top());
		d=get<3>(PQ.top());PQ.pop();
		if(visited[r][c]) continue;
		visited[r][c]=true;
		if(c==m){
			ans=dis;
			break;
		}
		for(int i=0;i<3;++i){
			int rr=r+di[i];
			int cc=c+dj[i];
			if(rr<=0 or rr>n or cc<=0 or cc>m) continue;
			int dd=0;
			if(d!=i) dd=1;
			if(!visited[rr][cc]){
				PQ.emplace(dis+dd,rr,cc,i);
			}
		}
	}
	printf("%d",ans);
}
