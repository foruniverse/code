//#include<bits/stdc++.h>
//poj 的gcc 是4.4. nm吐了
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
#define lint long long 

//#define __debug true; // c++17

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    stack<int> buffer;
    lint ans[n];
    memset(ans, 0, sizeof(ans));
    lint sum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        while(!buffer.empty() &&  a[i] > a[buffer.top()])
        {
            ans[i] += ans[buffer.top()] + 1;
            buffer.pop();
        }
        sum += ans[i];
        buffer.push(i);
    }
    //for (int i = 0; i < n; ++i) sum += ans[i];
    cout << sum << "\n";
    return 0;
}

