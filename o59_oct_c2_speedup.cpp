#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii=pair<int,long long>;

lli dis[80005][12]; //dis[v][u] distance from u to v

int Llist[15];
bool visited[15];
lli ans = 2e18;
vector <pii> G[80005];
vector <int> slug;

void solve(int x,int L,int Q,int N)
{
	if(x == Q+1) return;
	if(x > 0)
	{
		lli anss = dis[Llist[slug[0]]][0];
		anss += (dis[N][slug[x-1]])/((lli) 1 << x);
		for(int j = 0;j < x - 1; ++j)
		{
			anss += (dis[Llist[slug[j+1]]][slug[j]])/((lli)1 << (j+1));
		}
		ans=min(anss,ans);
	}
		
	for(int i=1;i<=L;++i)
	{
		
		
		if(visited[i]) continue;
		visited[i]=true;
		
		slug.push_back(i);
		solve(x + 1,L , Q, N);
		slug.pop_back();
		visited[i]=false;
		
	}
	
}

void djk(int st,int N)
{
	priority_queue <pii ,vector <pii> , greater<pii>> PQ;
	set <int> uvt; //Unvisited Set
	for(int u=1;u<=N;++u)
	{
		uvt.insert(u);
	}
	dis[Llist[st]][st]=0;
	PQ.emplace(dis[Llist[st]][st],Llist[st]);
	while(!PQ.empty() and !uvt.empty())
	{
		int u=PQ.top().second;
		PQ.pop();
		if(uvt.find(u)==uvt.end()){ //u is visited;
			continue;
		} 
		uvt.erase(u);
		for(auto vw:G[u])
		{
			int v=vw.first;
			lli w=vw.second;
			if(uvt.find(v) == uvt.end()){ //if v is visited;
				continue;
			}
			if(dis[v][st] > dis[u][st] + w)
			{
				dis[v][st] = dis[u][st] + w;
				PQ.emplace(dis[v][st],v);
			}
		}
	}
	
}

int main()
{
	
	int N,M,L,Q;
	
	scanf("%d%d%d%d",&N,&M,&L,&Q);
	for(int i=1;i<=N;++i)
	{
		for(int j=0;j<12;++j)
		{
			dis[i][j]=2e18;
		}
	}
	int u,v;
	lli w;
	for(int i=1;i<=M;++i)
	{
		
		scanf("%d%d",&u,&v);
		scanf("%lld",&w);
		G[u].push_back({v,w});
	}
	//Dijkstra
	Llist[0]=1;
	djk(0 , N);
	for(int i=1;i<=L;++i)
	{
		scanf("%d",&Llist[i]);
		djk(i , N);
	}
	
	
	for(int i=1;i<=N;++i)
	{
		for(int j=0;j<=L;++j)
		{
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	solve(0,L,Q,N);
	printf("%lld",ans);
	return 0;
}
