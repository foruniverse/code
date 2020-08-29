#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int main()
{
    srand(time(NULL));
    cout << "1\n";
    int a = rand() % maxn ;
    cout << a<< endl;
    int b = 1e9;
    for (int i = 0; i < a; ++i) cout << rand()%b << " ";

    return 0;
}
