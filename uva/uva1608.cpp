#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t； cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], c[n];
        gp_hash_table<int,int> b;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (b[a[i]]) c[i]
        }
        cout 

    }

    return 0;
}



