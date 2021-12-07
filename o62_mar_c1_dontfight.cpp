#include <bits/stdc++.h>
using namespace std;
using lli=long long;

const int NN=1e3+10;

lli DP[NN] , rankk[NN] , A[NN];
int P[NN][NN];
lli ans = 3e18;
vector <int> G[NN];

lli solve(int u,int p,int r)
{
    if(DP[u] == 0)
    {
        P[u][0]=p;
        rankk[u]=r;
        DP[u]=A[u];
        for(auto v:G[u])
        {
            if(v == p) continue;
            DP[u] += solve(v , u , r+1);
        }
    }
    return DP[u];
}

bool issub(int u,int v,int N) //NODE V IS PARENT OF U
{
    if(rankk[u] <= rankk[v]) return false;

    for(int j=N;j>=0;--j)
    {
        if(rankk[P[u][j]] >= rankk[v])
        {
            u = P[u][j];
            if(v == u) return true;

        }
    }
    return false;

}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&A[i]);
    }
    for(int i=1;i<N;++i)
    {
        int u,v;
        scanf("%d%d",&u ,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    solve(1 , 0 , 1);
    //BINARY LIFTING
    for(int j=1;j<=N;++j)
    {
        for(int i=1;i<=N;++i)
        {
            P[i][j] = P[P[i][j-1]][j-1];
        }
    }

    for(int u=2;u<=N;++u)
    {
        for(int v= u + 1;v<=N;++v)
        {
            if(issub(u , v , N))
            {
                //cout << u << " " << v << endl;
                lli A = DP[1] - DP[v];
                lli B = DP[v] - DP[u];
                lli C = DP[u];
                ans = min(ans , max({A,B,C}) - min({A,B,C}));
            }
            else if(issub(v , u , N))
            {
                //cout << v << " " << u << endl;
                lli A = DP[1] - DP[u];
                lli B = DP[u] - DP[v];
                lli C = DP[v];
                ans = min(ans , max({A,B,C}) - min({A,B,C}));
            }
            else
            {
                lli A = DP[1] - DP[u] - DP[v];
                lli B = DP[u];
                lli C = DP[v];
                ans = min(ans , max({A,B,C}) - min({A,B,C}));
            }
        }
    }
    printf("%lld",ans);
}
