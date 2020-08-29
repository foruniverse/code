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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        set<int> buffer;
        int best = -1,low = 0, high = 0, ans = 0;
        while (high < n)
        {
            if (buffer.insert(a[high]).second == false)
            {
                buffer.erase(a[low++]);
                best = max(best, ans);
                --ans;
            }else{
                ++ans; ++high;
            }
        }
        cout << max(best,ans) << "\n";
    }

    return 0;
}

