#include <bits/stdc++.h>
using namespace std;
using pa = pair<int,int>;


const int maxn = 5e3 + 5;
pa x[maxn],y[maxn];
int ans1[maxn], ans2[maxn];

int n;

bool solve(pa * a, int * ans)
{
    memset(ans, 0, n * 4);
    for (int i = 1; i <= n; ++i)
    {
        int best = n + 1, record = -1;
        for (int j = 0; j < n; ++j)
        {
            if (a[j].first <= i && a[j].second >= i && !ans[j] && a[j].second < best)
            {
                record = j;
                best = a[j].second;
            }
        }
        if( record < 0 ) return false;
        ans[record] = i;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //fuck freopen fuck fuck fuck fuck fuck
    while(cin >> n && n)
    {
        for (int i = 0; i < n; ++i) cin >> x[i].first >> y[i].first >> x[i].second >> y[i].second; 
        if (solve(x,ans1) && solve(y, ans2))
        {
            for (int i = 0; i < n; ++i) cout << ans1[i] << " "<< ans2[i] << "\n";
        }
        else cout << "IMPOSSIBLE\n"; 
    }
    return 0;
}
