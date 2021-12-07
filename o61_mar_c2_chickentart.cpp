#include<bits/stdc++.h>
using namespace std;

int N,M,K;
int arr[100005];

bool check(int x)
{
    vector <int> L (N + 5,0) , R (N+5 ,0);
    int sum = 0 , cnt=1, buf=0;
    int overL=0, overR=0;
    for(int i=1;i<=N;++i)
    {
        if(arr[i] > x){
            overL=i;
            break;
        }
        if(sum + arr[i] > x or buf==M){
            sum = 0;
            ++cnt;
            buf = 0;
        }
        sum += arr[i];
        L[i] = cnt;
        ++buf;
    }
    sum = 0;cnt = 1;buf = 0;
    for(int i=N;i>=1;--i)
    {
        if(arr[i] > x){
            overR=i;
            break;
        }
        if(sum + arr[i] > x or buf==M){
            sum = 0;
            ++cnt;
            buf = 0;
        }
        sum += arr[i];
        R[i] = cnt;
        ++buf;
    }
    if(overR - overL + 1 > M) return false;
    if(!overR)
    {
        for(int i=0;i<=N-M;++i)
        {
            if(R[i + M + 1] + L[i] <= K - 1) return true;
        }
    }else
    {
        for(int i=max(0 , overR - M);i<=min(overL - 1, N-M);++i)
        {
            if(R[i + M + 1] + L[i] <= K - 1) return true;
        }
    }


    return false;
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    int ans=2e9;
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&arr[i]);
    }
    int l=0,r = 1e9;

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            r=mid-1;
            ans =min(ans , mid);
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d",ans);
}
