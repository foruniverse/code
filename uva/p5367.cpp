#include<cstdio>
using namespace std;
const int maxn = 1e+6;
const int maxm =  998244353;
int n,used[maxn],jc[maxn];

int main()
{
    jc[0] = 1;
    for(int i = 1;i <= maxn;++i) jc[i] = jc[i - 1] * i % maxm;
    scanf("%d",&n);
    int temp,sum = 1;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&temp);
        used[temp] = 1;
        int now = 0;
        for(int j = 1;j < temp;++j) if(!used[j]) now++;
        sum += now * jc[n - i] % maxm;
    }
    printf("%d",sum);
    return 0;
}
