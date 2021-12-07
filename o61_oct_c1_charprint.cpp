#include<bits/stdc++.h>
#define NN (int) 3e5+10
using namespace std;
using lli=long long;

vector <int> key[300];
int cnt[300];
lli seg[2*NN];

class Segment
{
private:
    lli seg[2*NN];
public:
    void setzero()
    {
        for(int i=0;i<2*NN;++i)
        {
            seg[i]=0;
        }
    }
    lli query(int a,int b,int N,int m)
    {
        if(m==0) return 0;
        lli ans=0;
        a+= N;
        b+= N;
        while(a <= b)
        {
            if(a % 2==1) ans += seg[a++];
            if(b % 2==0) ans += seg[b--];
            a/=2;
            b/=2;
        }
        return ans;
    }
    void add(int a,int x,int N)
    {
        a+=N;
        seg[a] = x;
        for(int i=a/2;i>=1;i/=2)
        {
            seg[i] = seg[2*i] + seg[2*i + 1];
        }
    }
};

int main()
{
    int m;
    scanf("%d",&m);
    Segment seg;
    seg.setzero();
    lli ans=0;
    string s,t;
    cin >> s;
    for(int i=0;i<s.size();++i)
    {
        key[s[i]].push_back(i+1);
    }
    cin >> t;
    for(int i=0;i<t.size();++i)
    {
        if(cnt[t[i]] >= key[t[i]].size())
        {
            printf("-1");
            return 0;
        }
        int a=key[t[i]][cnt[t[i]]];
        ++cnt[t[i]];
        ans += a - (int) seg.query(1 , a , s.size() , m);
        if(m)
        {
            seg.add(a , 1 , s.size());
        }
    }

    printf("%lld",ans);
}

