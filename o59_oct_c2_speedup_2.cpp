#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int,long long>;
using piii= pair<long long,int>;
using tll = tuple<long long,int ,int>;
int main()
{
    int N,M,L,Q;
    scanf("%d%d%d%d",&N,&M,&L,&Q);
    vector <pii> G[N+10] , H[N+10];
    int l[L + 10];
    while(M--)
    {
        int u,v;
        lli w;
        cin >> u >> v >> w;
        G[u].push_back({v , w});
    }
    for(int i=1;i<=L;++i)
    {
        scanf("%d",&l[i]);
    }
    l[0]=1;
    l[L+1] = N;
    //SECTION1
        lli dis[L+10][N+10];
        bool visited[L+10][N+10];
        for(int i=0;i<L+10;++i)
        {
            for(int j=0;j<N+10;++j)
            {
                dis[i][j]=2e18;
                visited[i][j] = false;
            }
        }
        for(int i=0;i<=L+1;++i)
        {
            priority_queue <piii , vector <piii> , greater<piii>> PQ;
            dis[i][l[i]] = 0;
            PQ.emplace(dis[i][l[i]] , l[i]);
            while(!PQ.empty())
            {
                int u=PQ.top().second;
                PQ.pop();
                if(visited[i][u]) continue;
                visited[i][u] = true;
                for(auto vw:G[u])
                {
                    int v=vw.first;
                    lli w=vw.second;
                    if(dis[i][v] > dis[i][u] + w)
                    {
                        dis[i][v] = dis[i][u] + w;
                        PQ.emplace(dis[i][v] , v);
                    }
                }
            }
        }
     //SECTION2;
        priority_queue <tll , vector <tll> , greater<tll>> PQ;
        for(int i=0;i<=L+1;++i)
        {
            for(int j=0;j<=L+1;++j)
            {
                int u = l[i];
                int v = l[j];
                if(u == v) continue;
                if(dis[i][v] != 2e18)
                {
                    H[u].emplace_back(v , dis[i][v]);
                }
            }
        }
        for(int i=0;i<L+10;++i)
        {
            for(int j=0;j<N+10;++j)
            {
                dis[i][j]=2e18;
                visited[i][j] = false;
            }
        }
       dis[0][1]=0;
       PQ.emplace(dis[0][1] , 0 , 1); //dis stateQ node;
       while(!PQ.empty())
       {
           int q = get<1>(PQ.top());
           int u = get<2>(PQ.top());PQ.pop();
           if(visited[q][u]) continue;
           visited[q][u]=true;
           if(u == N)
           {
               cout << dis[q][u];
               return 0;
           }
           for(auto vw:H[u])
           {
               int v=vw.first;
               lli w=vw.second;
               int qq = min(q + 1,Q);
               if(dis[qq][v] > dis[q][u] + w/((lli)1 << q))
               {
                   dis[qq][v] = dis[q][u] + w/((lli)1 << q);
                   PQ.emplace(dis[qq][v] , qq,v);
               }
           }
       }
    return 0;
}
