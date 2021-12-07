#include<bits/stdc++.h>
using namespace std;
vector<int> mi(3005,2e9);
int a[3005],dp[3005][3005];
int main(){
    int n,m,i,j,ans=2e9;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        for(j=i-1;j>=max(1,i-m+1);j--){
            if(i<=m)dp[i][j]=a[i]+a[j];
            else dp[i][j]=a[i]+mi[j];
            mi[i]=min(mi[i],dp[i][j]);
        }
    }
    for(j=n-m+1;j<=n;j++)for(i=j+1;i<=n;i++)ans=min(ans,dp[i][j]);
    printf("%d",ans);
    return 0;
}
