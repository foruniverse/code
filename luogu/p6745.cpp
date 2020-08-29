#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
    int n;
    string m;
    while(cin>>n>>m)
    {
        int cont = m.size();
        if(n <= 18)
        {
            int ad = 1;
            int ok = 0;
            for(int i = cont -1 - n; i >= 0; --i)
            {
                ok = 1;
                int temp  = m[i] - '0';
                temp  += ad;
                if(temp/10) ad = 1;
                else ad = 0;
                m[i] =  temp % 10 + '0';
            }
            if(ad && ok) printf("1");
            else if(ad) { printf("1"); for(int i = 1;i <= n - cont; ++i) printf("0"); }
            cout<<m<<endl;

        }else{
            putchar('1');
            for(int i = 1; i <= n - cont; ++i) putchar('0');
            cout<<m<<endl;    
        }
    }
    return 0;
}
