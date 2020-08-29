#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;


bool check(int x,int y)
{
    auto ite = v.begin();

    bool flag = true;
    for(;ite!=v.end();ite++)
        if(*ite == x && flag)
        {
            return true;
        }
        else if(*ite == y)
        {
            flag = false;
        }
    return false;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        v.push_back(i);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(!check(x,y))
        {
            printf("failed: %d",i);
        }
    }
    return 0;

}
