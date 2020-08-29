#include<iostream>
#include<cstdio>
using namespace std;
using lint = long long;

int main(){
    lint x,k,d; 
    while(scanf("%lld%lld%lld",&x,&k,&d) == 3)
    {
        x = abs(x);
        lint time = x / d;
        lint rest = x % d;
        if(rest == 0) {  }
    }
    return 0;
}
