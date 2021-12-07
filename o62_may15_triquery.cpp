#include <bits/stdc++.h>
using namespace std;

const int NN = 2e3+10;
int seg[2*NN][NN];
int N;

int findx(int r,int c)
{
    return r+c-1;
}
int query(int l,int r,int x)
{
    int ans=0;
    l+=N;
    r+=N;
    while(l <= r)
    {
        if(l % 2 == 1) ans += seg[x][l++];
        if(r % 2 == 0) ans += seg[x][r--];
        l/=2;
        r/=2;
    }
    return ans;
}
void add(int l,int x,int v)
{
    l+=N;
    seg[x][l]=v;
    for(int i=l/2;i>=1;i/=2)
    {
        seg[x][i] = seg[x][i*2] + seg[x][i*2 + 1];
    }
}
int main()
{
    int M;
    scanf("%d%d",&N , &M);
    while(M--)
    {
        int t;
        scanf("%d",&t);
        if(t == 1)
        {
            int r,c,l;
            int ans=0;
            scanf("%d%d%d",&r,&c,&l);
            for(int i=0;i<l-1;++i)
            {
                //cout << query(c - i , c , findx(r , c)-i) << endl;
                ans += query(c - i , c , findx(r , c)-i);
            }
            ans += query(c - l + 1 , c , findx(r , c)-l+1)/2;
            //cout << query(c - l + 1 , c , findx(r , c)-l+1)/2 << endl;
            printf("%d\n",ans);
        }else
        {
            int r,c,v;
            scanf("%d%d%d",&r,&c,&v);
            add(c,findx(r , c) ,v);
        }
    }
}
