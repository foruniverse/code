#include<bits/stdc++.h>
using namespace std;
using lint = long long ;
using ldouble = long double;

namespace {
auto fast_io = [] {
#ifndef DEBUG
#  ifndef INTERACTIVE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#  endif // INTERACTIVE
#  ifdef FILES
    freopen(FILES".in", "r", stdin);
    freopen(FILES".out", "w", stdout);
#  endif // FILES
#endif // DEBUG
  return 0;
};
} // namespace

void err(istream_iterator<string> _it) {}
template<typename T,typename... Args>
void err(istream_iterator<string> _it, T a,Args... args) {cerr<<"\n"<<*_it<<" is "<<a<<endl;err(++_it,args...);}

//#define __debug true; // c++17
const bool _debug = true;
#define cerr if(_debug)cerr
#define eb emplace_back
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << "\n";
#define error(args...) if(_debug){string _s = #args; replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s); istream_iterator<string> _itt(_ss);err(_itt,args);} 

int main()
{
    fast_io();
    int n;
    while(cin >> n && n)
    {
        cout << 2 << " " << n  << " " << n << "\n";
        for (int j = 0; j < n; ++j) for (int i = 1; i <=n; ++i) cout << (char)(j + (j < 26 ? 'A' :'a' - 26)) << (i == n ? "\n" : ""); 
        cout << "\n";
        for (int j = 0; j < n; ++j) for (int i = 0; i < n; ++i) cout << (char)(i + (i < 26 ? 'A' :'a' - 26)) << (i == n - 1 ? "\n" : ""); 
        cout << "\n";
    }

    return 0;
}

