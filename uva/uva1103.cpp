#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 10000;
const int max_h = 200 * 4 +10;
const int max_w = 50 * 4 +10;

int total = 0;

const char zimu[7] ={'W','A','K','J','S','D'};
int buffer[max_h][max_w];
int m,n;


vector<int> flag;
//记录是否访问过单元格
int record[max_h][max_w];

int white_position[maxn];

char input[210][max_w];

void print_record()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n*4;j++)
        {
            printf("%d ",record[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void white_dfs(int x, int y, int & count)
{
    if( x<1 || x>m || y<1 || y>n*4 )
    {
        //       printf("(%d,%d) 越界\n",x,y);
        flag.push_back(count);
        return ;
    }
    if( buffer[x][y] == 1 || record[x][y] > 0 )
    {
        //        printf("(%d,%d) 不符合\n",x,y);
        return ;
    }

    record[x][y] = count + 10;
//        printf("(%d,%d)\n ",x,y);
 //      print_record();

    for(int i=-1; i<=1 ;i++)
        for(int j= -1 ;j<=1;j++)
        {
            if( i==0 || j ==0 )
                white_dfs(x+i,y+j,count);
        }
}

void black_dfs(int x,int y,int count)
{
    if( x<1 || x>m || y<1 || y>n*4 )
        return ;

    if(record[x][y] != 0 || buffer[x][y] != 1)
        return;

    record[x][y] = count;

//      print_record();
    for(int i=-1;i<=1;i++)
        for(int j=-1 ; j<=1; j++)
        {
            if( i==0 || j==0 )
            {
                black_dfs(x+i,y+j,count);
            }
        }
}

int main()
{
    while(scanf("%d%d",&m,&n)==2 && m && n)
    {
        for(int i=1;i<=m;i++)
            scanf("%s",input[i]);

        //        for(int i=1;i<=m;i++)
        //        {
        //            for(int j=0;j<strlen(input[i]);j++)
        //            {
        //                printf("%c",input[i][j]);
        //            }
        //            putchar('\n');
        //        }
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<strlen(input[i]);j++)
            {
                int temp =1;
                int now = isdigit(input[i][j])?input[i][j]-48:input[i][j]-97+10;
                //               cout<<"now:"<<now<<endl;
                for(int k=(j+1)*4;k>(j+1)*4-4;temp=temp<<1,k--)
                {
                    buffer[i][k]=( now & temp) != 0  ;
                    //                    cout<<buffer[i][k]<<endl;
                }
            }
        }


  //      for(int i=1;i<=m;i++)
  //      {
  //          for(int j=1;j<=n*4;j++)
  //          {
  //              printf("%d ",buffer[i][j]);
  //          }
  //          putchar('\n');
  //      }

        int count = 0;
        int black_count = 0;

        //     cout<<"98"<<endl;

        flag.clear();

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n*4;j++)
            {
                if( buffer[i][j] == 0 && record[i][j] ==0 )
                {
                    //                cout<<"count:"<<count+1<<endl;
                    white_dfs(i,j,++count);
                    //store initial position of white block
                    white_position[count] =  i* max_h + j;
                }
                else if( buffer[i][j] ==1  &&  record[i][j] ==0 )
                {
                    black_dfs(i,j,++black_count);
                    //               cout<<"black_count"<<black_count<<endl;
                }
            }


        int x,y;
        int alpha[black_count+1]={0};

        //huo qu bai lian tong kuai zuo biao
        
        int beijin = false;
        for(int i=1;i<=count;i++)
        {

            beijin=false;
            for(auto x:flag)
            {
  //              cout<<i<<"=="<<x<<endl;
                if(i==x)
                {
                    beijin = true;
                    break;
                }
            }
            if(beijin)
                continue;
            x=white_position[i] / max_h ;
            y= white_position[i] % max_h;

            while(x>=1)
            {
                if(buffer[--x][y] == 1)
                {
                    alpha[record[x][y]] ++;
                    break;
                }
            }
        }

        //  cout<<"black_liantongkuai:\n";
        char alpha_2[black_count+1];
        for(int i=1;i<=black_count;i++)
        {
            alpha_2 [i]= zimu[alpha[i]]; 
        }

        sort(alpha_2+1,alpha_2+black_count+1);
        printf("Case %d: ",++total );
        for(int i=1;i<=black_count;i++)
            printf("%c",alpha_2[i]);
        putchar('\n');

        //        print_record();        
        memset(white_position,0,sizeof(white_position));
        memset(record,0,sizeof(record));
        memset(input, 0 ,sizeof(input));
        memset(buffer,0,sizeof(buffer));
    }
    return 0;

}
