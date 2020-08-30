#include <iostream>
using namespace std;

const int maxn = 1e2;
int a[maxn], ans[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	//ans[0] = a[0];
	//for (int j = 1; j < n; ++j) ans[j] = ans[j - 1] + a[j];
	//for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
	return 0;
}