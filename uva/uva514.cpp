#include<cstdio>
#include<stack>

using namespace std;

const int maxn = 1000 + 10;
int n;
int result[maxn];
int main()
{
    while(scanf("%d",&n)==1 && n)
    {
        int temp;
        while(scanf("%d",&temp)==1 && temp)
        {
            stack<int> buffer;
            result[1]=temp;
            for(int i=2;i<=n;i++)
            {
                scanf("%d",result+i);
            }
            int a=1,b=1,ok=1;
            while(b<=n)
            {
                if(a==result[b])
                {
                    a++;
                    b++;
                }
                else if(!buffer.empty() && result[b]==buffer.top())
                {
                    b++;
                    buffer.pop();
                }
                else if(a<n)
                {
                    buffer.push(a);
                    a++;
                }
                else {
                    ok =0;
                    break;
                }
            }
            printf("%s\n",ok?"Yes":"No");
        }
        putchar('\n');
    }
    return 0;
}
