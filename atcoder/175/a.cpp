#include<iostream>
#include<cstdio>
using namespace std;
char s[4];
int main(){

    while(scanf("%s",s) == 1)
    {
        int ans = 0;
        int ok = 0;
        int best = 0;
        for(int i = 0; i < 3; ++i)
        {
            if(s[i] == 'R') {
                ans ++;
            }
            if(s[i] == 'S')
            {
                best = max(best,ans);
                ans = 0;
            }
        }
        best = max(best,ans);
        printf("%d\n",best);
    }
    return 0;
}
