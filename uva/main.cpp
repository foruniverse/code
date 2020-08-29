#include<bits/stdc++.h>
using namespace std;
using ulint = unsigned long long;
using lint = long long ;
using ldouble = long double;

void err(istream_iterator<string> _it) {}
template<typename T,typename... Args>
void err(istream_iterator<string> _it, T a,Args... args) {cerr<<"\e[91m"<<*_it<<" is "<<a<<"\e[39m"<<endl;err(++_it,args...);}

//#define __debug true; // c++17
const bool _debug = true;
#define cerr if(_debug)cerr
#define eb emplace_back
#define watch(args...) if(_debug){string _s = #args; replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);cerr<<"\n";istream_iterator<string> _itt(_ss);err(_itt,args);} 

int k, a, b, cont;

void find(int color, int x, int y, int time)
{
    if (x >= a && x <= b) { ++cont; }
    else if (x > b) return;


    if (color == 1) 
    

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        cin >> k >> a >> b;
        find(1, 1, 1, );

    }

    return 0;
}



