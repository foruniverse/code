#include<cstdio> #include<list>
using namespace std;

using it= list<int>::iterator;
list<int> buffer;
list<int>::iterator find_list(int value)
{
    for(auto ite=buffer.begin();ite!=buffer.end();ite++)
        if(*ite==value)
            return ite;
}

//int * find_list_2(int value)
//{
//    for(auto x:buffer)
//    {
//        if(x==value)    
//            return &x;
//    }
//    //for循环中auto x 是临时变量，返回地址随着函数栈的消亡而消亡
//    //
//}

void move(it it1,it it2)
{
    if(it1 == it2)
        return;
    int temp=*it1;
    buffer.remove(*it1);
    buffer.insert(it2,temp); 
}
void swap(it it1,it it2)
{
    int temp= *it1;
    *it1= *it2;
    *it2 = temp;
}
void cal(int c,int x, int y)
{
    switch(c)
    {
        case 1:
            move(find_list(x),find_list(y));
            break;
        case 2:
            move(find_list(x),++find_list(y));
            break;
        case 3:
            swap(find_list(x),find_list(y));
            break;
        default:
            buffer.reverse();
    }
//            for(auto temp : buffer)
          //     printf("%d",temp);
}
        int count=0;
int main()
{
    int n,m;
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            buffer.push_back(i);
        }
        int c,x,y;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&c);
            if(c!=4)
                scanf("%d%d",&x,&y);
            cal(c,x,y);
        }
  //      for(auto temp : buffer)
   //         printf("%d",temp);

        long long  sum=0;
        int i=1;
        for(it ite= buffer.begin();ite!=buffer.end();ite++,i++)
        {
            if(i%2!=0)
                sum+=*ite;
        }
        printf("Case %d: %lld",++count,sum);
        buffer.clear();
        putchar('\n');
    }
    return 0;
}
