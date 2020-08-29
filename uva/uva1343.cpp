// uva1343 ida * / bfs 剪枝
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> way;
int buffer[25],maxd,cur;
int pos[8][7] ={
    {1,3,7,12,16,21,23}, //a 0
    {2,4,9,13,18,22,24}, //b 1
    {11,10,9,8,7,6,5},  //c 2 
    {20,19,18,17,16,15,14},//d 3
    {24,22,18,13,9,4,2},//e 4
    {23,21,16,12,7,3,1},//f 5
    {14,15,16,17,18,19,20},//g 6
    {5,6,7,8,9,10,11}//h 7
};
int cut[8]{5,4,7,6,1,0,3,2};
void output(int a[]){
	cout<<"      "<<a[1]<<"     "<<a[2]<<endl;
	cout<<"      "<<a[3]<<"     "<<a[4]<<endl;
	cout<<a[5]<<"  "<<a[6]<<"  "<<a[7]<<"  "<<a[8]<<"  "<<a[9]<<"  "<<a[10]<<"  "<<a[11]<<endl;
	cout<<"      "<<a[12]<<"     "<<a[13]<<endl;
	cout<<a[14]<<"  "<<a[15]<<"  "<<a[16]<<"  "<<a[17]<<"  "<<a[18]<<"  "<<a[19]<<"  "<<a[20]<<endl;
	cout<<"      "<<a[21]<<"     "<<a[22]<<endl;
	cout<<"      "<<a[23]<<"     "<<a[24]; 
    cout<<"\n";
}

int tar[8] = {7,8,9,12,13,16,17,18};
int check()
{
    int ans = 0,ans_1 = 0,ans_2 = 0;
    for(const auto & x : tar) if(buffer[x] == 1) ans++;
    for(const auto & x : tar) if(buffer[x] == 2) ans_1++;
    for(const auto & x : tar) if(buffer[x] == 3) ans_2++;
    if(ans < ans_1)
    {
        if(ans_1 < ans_2) { cur = 3; return ans_2; }
        else { cur = 2;return ans_1; }
    }else{
        if(ans < ans_2) { cur = 3; return ans_2; }
        else { cur = 1; return ans; }
    }
}

bool dfs(int d,int last)
{

    int cont = check();
  //  printf("cont:%d cur:%d D:%d\n",cont,cur,d);
    if(cont == 8) return true;
    if(8 - cont + d > maxd) return false;
    int fake[25];
    memcpy(fake,buffer,sizeof(buffer));
    for(int i = 0; i < 8; ++i)
    {
        if( i == cut[last] ) continue;
        int fir = buffer[pos[i][0]];
        for(int j = 0; j < 6; ++j) buffer[pos[i][j]] = buffer[pos[i][j+1]]; 
        buffer[pos[i][6]] = fir;
        way.push_back(i);
        if(dfs(d + 1,i)) return true;
        way.pop_back();
        memcpy(buffer,fake,sizeof(fake));
    }
    return false;
}

int main(){
    int temp;
    while(scanf("%d",&temp)==1 && temp)
    {
        buffer[1] = temp;
        for(int i = 2; i <= 24; ++i) scanf("%d",&buffer[i]);
        for(maxd = 0;;++maxd,way.clear()) 
        {
        //    之前是这样写的，发现并不需要，因为，无论去探1还是2，枚举过程都是一样的，区别只有最后比对的时候有不同，
        //    而且效率太低
            if(dfs(0,-1)) break;
        }
        if(d != 0) for(const auto & x: way) printf("%c",x + 'A'); 
        else printf("No moves needed");
        printf("\n%d\n",cur);
        way.clear();
    }
    return 0;
}
