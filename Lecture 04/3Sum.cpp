#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 10]++;
    }

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < min(cnt[i], 3); j++) {
            v.push_back(i);
        }
    }

    int len = v.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                if ((v[i] + v[j] + v[k]) % 10 == 3) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}