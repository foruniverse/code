 /*
  *gnu pb_ds 
  *hash table : gp > cc
  */
#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
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
    int t,cont = 0;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n],b[n],c[n],d[n];
        for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i]; 
        
        //map<int,int> buffer;
        //cc_hash_table<int,int> buffer;
        gp_hash_table<int,int> buffer;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
            {
                //buffer.insert(a[i] + b[j]);
                buffer[a[i] + b[j]] ++;
            }
        lint ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                ans += buffer[-(c[i] + d[j])];
            }
        if (cont++ != 0) cout << "\n";
        cout << ans << "\n";
        //cerr << buffer.size() << "\n";
    }
    return 0;
}

