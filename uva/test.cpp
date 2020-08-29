#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n; 
    cin >> n;
    int ik = 1; 
    int a[n];
    while(cin >> a[ik])
    {
        cout << a[ik++];
    }
    return 0;
}
