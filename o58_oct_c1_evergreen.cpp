#include<bits/stdc++.h>
using namespace std;
long long x[1002];
int n;
long long area(int base){
    if(base<=0) return 0;
    if(base%2==0){
        int n=base/2;
        return (long long)(n)*(long long)(n+1);
    }else{
        return (long long)((long long)(base/2)+(long long)1) * (long long)((long long)(base/2)+(long long)1);
    }
}
long long check(int a){
    long long ans=area((2*a)+1);
    ans=ans*n;
    long long minus=0;
    for(int i=1;i<n;++i){
        minus+=area((x[i]+a) - (x[i+1]-a) + 1);
    }
    ans-=minus;
    return ans;
}
int main(){
    long long k;
    scanf("%d %lld",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%lld",&x[i]);
    }
    int l=0,r=4e8;
    int ans=2e9;
    sort(x+1,x+n+1);

    //cout << check(1) << endl;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)>=k){
            ans=min(ans,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%d",ans);
}