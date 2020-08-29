#include<iostream> #include<cstring>
#include<list>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 362880;

int n,vis[maxn + 1],maxd,c[10],jc[10],buffer[15];


int lowbit(int x) { return x & -x; }
void update(int i,int k)
{
    while(i<=n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}
int getsum(int i)
{
    int ans = 0;
    while(i>0)
    {
        ans += c[i];
        i -= lowbit(i);
    }
    return ans;
}


int find_id(int buffer [])
{
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++) update(i,1);
    int ans = 1;
    for(int i = 1;i <= n;i++)
    {
        int cur = buffer[i];
        update(cur,-1);
        ans += jc[n - i] * getsum(cur);
    }
    return ans;
}

int check()
{
    int sum = 0;
    for(int i =1;i < n; ++i) if(buffer[i+1] != 1 + buffer[i]) ++sum;
    return sum;
}


bool dfs(int d)
{
//    cout<<"current depth:"<<d<<"  maxd:"<<maxd<<endl;
    if(find_id(buffer) == 1) return true;
    int fake[12];
    memcpy(fake,buffer,sizeof(buffer));
 //   for(int fuck:buffer) cout<<fuck<<" "; cout<<endl;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;++j)
        {
            int k = 1;
            int len = j - i + 1;// the lenght to be cut;
            while(k<=n)
            {
                if(k==i) k = j + 1;
                if(k > n) break;
                int z = k;

                int len = j - i + 1;
  //              cout<<"before: "<<i<<"-"<<j<<" move to "<<k<<endl;
//                for(int fuck:buffer) cout<<fuck<<" "; cout<<endl;
                if( z < i )
                {
                    for(;z < k + len ;++z)  buffer[z] = fake[z + i - k];
                    for(;z < j + 1;++z) buffer[z] = fake[z - len];
                }else {
                    for(;z > k - len;--z) buffer[z]  = fake[z + j - k];
                    for(;z > i - 1;--z) buffer[z] = fake[z + len];
                }
   //             cout<<"after"<<endl;
    //            for(int fuck:buffer) cout<<fuck<<" "; cout<<endl;
                int id = find_id(buffer);
                if(!vis[id])
                {
                    //cout<<"check:"<<check()<<endl;
                    if(3 * d + check() > 3 * maxd)
                    {
                        ++k;
                        memcpy(buffer,fake,sizeof(fake));
                        continue;
                    }
                    vis[id] = 1;    
                    if(dfs(d+1)) return true;
                    vis[id] = 0;
                } 
                memcpy(buffer,fake,sizeof(fake));
                ++k;
            }
        }
    }
    return false;
}



int main()
{
    jc[0] = 1;
    for(int i = 1;i <= 10;++i) jc[i] = jc[i -1] * i;
    int cont = 0;
    while(scanf("%d",&n)==1 && n)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) 
        {
            int temp;
            scanf("%d",&temp);
            buffer[i] = temp;
        }
//        cout<<find_id(buffer)<<endl;
        vis[find_id(buffer)] = 1;
        for(maxd = 0;maxd <= n - 1;++maxd)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(0)) break;
        }
        cout<<"Case "<<++cont<<": "<<maxd<<endl;
    }
    return 0;
}

