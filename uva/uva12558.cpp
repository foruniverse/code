#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e+5;
using bint = long long;
int maxd,k;
bint forbit[6],ans[maxn],v[maxn];

int get_first(bint a,bint b)
{
    return b / a + 1;
}

bool check(int cur)
{
    for(int i=0;i<k;i++) if( forbit[i] == cur) return false;
    return true;
}
bint gcd(bint a,bint b)
{
  return b ==0? a: gcd(b,a % b);  
}
bool better(int d)
{
    // find the least value of denominator
    for(int i=d;i>=0;i--) if(v[i] != ans[i]) return ans[i] == -1 ||  v[i] < ans[i];
    return false;
}

bool dfs(int d,int from,bint aa,bint bb)
{
    if(d == maxd)
    {
        if(aa != 1 || !check(bb)) return false;
        v[d] = bb ;
        if(better(d)) memcpy(ans,v,sizeof(bint) * (d + 1));
        return true;
    }
    bool ok = false;
    from = max(from,get_first(aa,bb));
    // case 1:  1/fromt <= aa/bb
    // case 2:  1/fromt > aa/bb
    for(int i = from;;i++)
    {
        if(!check(i)) continue;
        if(i * aa >= bb * (maxd + 1 -d)) break;
        bint a2 = aa * i - bb, b2  = bb * i;
        bint g = gcd(a2,b2);
        v[d] = i;// store denominator 
        //cout<<"d:"<<d<< "from:"<<from<<" aa:"<<aa<<" bb:"<<bb<<endl;
        if(dfs(d+1,i+1,a2 / g,b2 / g)) ok = true;
    }
    return ok;
}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<k;i++) scanf("%lld",&forbit[i]); 
        int ok=0;
        for(maxd=1;;++maxd)
        {
            memset(ans,-1,sizeof(ans));
            if(dfs(0,get_first(a,b),a,b)) { ok=1;break; }
        }
        printf("Case %d: ",i);
        if(ok) 
        {
            printf("%d/%d=1/%lld",a,b,ans[0]); 
            for(int i=1;i<=maxd;i++) 
                printf("+1/%lld",ans[i]);
            putchar('\n');
            
        }else printf("No solution\n");
    }
}
