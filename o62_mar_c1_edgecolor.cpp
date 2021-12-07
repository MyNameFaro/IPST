#include <bits/stdc++.h>
using namespace std;

const int NN = 3e5+10;
bool visited[NN][2];
queue <int> Q[NN];
bool ans=true;
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int t,u,v;
    for(int m=1;m<=M;++m)
    {
        scanf("%d%d%d",&t , &u , &v);
        if(ans)
        {
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    
}