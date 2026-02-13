#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int N = 100005;

ll a[N];
ll diff[N];
ll op_count[N];

struct Operation {
	int l, r, d;
} ops[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> ops[i].l >> ops[i].r >> ops[i].d;
	}

	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		op_count[x]++;
		op_count[y + 1]--;
	}

	for (int i = 1; i <= m; i++) {
		op_count[i] += op_count[i - 1];
	}

	for (int i = 1; i <= m; i++) {
		if (op_count[i] > 0) {
			ll val = (ll)ops[i].d * op_count[i];
			diff[ops[i].l] += val;
			diff[ops[i].r + 1] -= val;
		}
	}

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
		a[i] += diff[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << (i == n ? "" : " ");
	}
	cout << "\n";

	return 0;
}