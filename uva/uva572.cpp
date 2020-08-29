#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 100 +10;
int m,n;
char buffer[maxn][maxn];
int flag[maxn][maxn];

void dfs(int x,int y ,int count)
{

    if(flag[x][y] != 0 || buffer[x][y] != '@') 
        return;
    if(!(x>=1 && x<=m  && y>=1 && y<=n))
        return ;
  //  printf("\n%c\n",buffer[x][y]);

    flag[x][y]=count;
 //   cout<<"buffer:\n" ;
//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=n;j++)
//            cout<<buffer[i][j];
//        putchar('\n');
//    }

//    cout<<"flag\n";
//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=n;j++)
//            cout<<flag[i][j]; 
//        putchar('\n');
//    }
//

    for(int i= -1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if( i!=0 || j!= 0 )
                dfs(x+i,y+j,count);
}

int main()
{
    while(scanf("%d%d",&m,&n)==2 && m)
    {

        getchar();
        string line;
        for(int i=1;i<=m;i++)
        {
            //jump '\n'
            getline(cin,line);
            stringstream ss(line);
            char temp;
            int j=1;
            while(ss>>temp)
                buffer[i][j++]=temp;
        } 

        int count = 0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(flag[i][j]==0 && buffer[i][j] == '@')
                    dfs(i,j,++count);
            }
        printf("%d\n",count);

        memset(buffer,0,sizeof(buffer));
        memset(flag,0,sizeof(flag));
    }
    return 0;
}
