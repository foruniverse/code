#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
using namespace std;
int count;
int now;
const int maxn = 341 + 9;
string s;

int board[maxn][maxn];

void read(int x, int y,int wide)
{
    char temp = s[now++]; 
    if(temp == 'p')
    {
        read(x,y+wide/2,wide/2);
        read(x,y,wide/2);
        read(x+wide/2,y,wide/2);
        read(x+wide/2,y+wide/2,wide/2);
//        cout<<"\nnmsl_2"<<endl;
    }
    if(temp == 'f')
    {

 //       printf("\nnmsl_1\n");
        for(int i=x;i<wide+x;i++)
            for(int j=y;j<wide+y;j++)
                if(!board[i][j])
                {
                    board[i][j]=1;
  //                  printf("\nnmsl\n");
                    count++;
                }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(board,0,sizeof(board));
        count=0;
        for(int i=1;i<=2;i++)
        {
            cin>> s;
            now = 0;
            read(0,0,32);
        }
        printf("There are %d black pixels.\n",count);
    }
    return 0;
}
