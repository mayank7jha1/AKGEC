#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        int q;
        cin >> n >> m >> q;
        multiset<int> x, y;
        multiset<int> sx, sy;

        x.insert(0);
        x.insert(n);
        y.insert(0);
        y.insert(m);

        sx.insert(n);
        sy.insert(m);

        for (int i = 0; i < q; i++) {
            int a;
            int b;
            cin >> a >> b;

            if (a == 0) {
                if (x.find(b) != x.end()) {
                    cout << (*sx.rbegin()) * (*sy.rbegin()) << endl;
                    continue;
                }
                auto large = x.lower_bound(b);
                auto small = large;
                small--;
                sx.erase(sx.find(*large - *small));
                sx.insert(*large - b);
                sx.insert(b - *small);
                x.insert(b);
                cout << (*sx.rbegin()) * (*sy.rbegin()) << endl;

            } else {

                if (y.find(b) != y.end()) {
                    cout << (*sx.rbegin()) * (*sy.rbegin()) << endl;
                    continue;
                }

                auto large = y.lower_bound(b);
                auto small = large;
                small--;

                sy.erase(sy.find(*large - *small));

                sy.insert(*large - b);
                sy.insert(b - *small);

                y.insert(b);

                cout << (*sx.rbegin()) * (*sy.rbegin()) << endl;
            }
        }
    }
    return 0;
}
