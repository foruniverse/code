#include<iostream>
#include<cstdio>
using namespace std;
using lint = long long;

int n,k;
int main(){
    scanf("%d%d",&n,&k);        
    int p[n + 1],c[n + 1];
    for(int i = 1; i <= n; ++i) scanf("%d",&p[i]);
    for(int i = 1; i <= n; ++i) scanf("%d",&c[i]);
    lint ans,best; best = -1e+10;
    for(int i = 1; i <= n; ++i)
    {
        int next = p[i],fake = k;
        ans = 0;
        do{
            ans += c[next]; 
            best = max(ans,best);
            next = p[next];
            --fake;
        }while(fake);
        //printf("%lld\n",ans);
    }
    printf("%lld\n",best);
    return 0;
}
