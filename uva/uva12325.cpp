#include<cstdio>
#include<algorithm>
using namespace std;
using int64 = long long;

int main()
{
    int t,n,s1,v1,s2,v2;
    int64 ans;
    scanf("%d",&t);
    for(int i = 1;i <= t;++i)
    {
        scanf("%d%d%d%d%d",&n,&s1,&v1,&s2,&v2);
        ans = -1;
        if(s1 > s2) swap(s1,s2),swap(v1,v2);
        if(n / s2 >= 60000) 
        {
            for(int64 i = 0;i <= s2;++i) ans = max(ans, i * v1 + (n - i * s1)/s2 * v2);
            for(int64 i = 0;i <= s1;++i) ans = max(ans, i * v2 + (n - i * s2)/s1 * v1);
        }
        else 
            for(int64 i = 0; s2 * i <= n; ++i) ans = max(ans, i * v2 + (n -i * s2)/s1 * v1);
        printf("Case #%d: %lld\n",i,ans);
    }
}
