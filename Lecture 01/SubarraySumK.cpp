#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<ll, int, chash> mp;
    unordered_map<ll, int, chash> fr;

    ll s = 0, cnt = 0;
    int mx = 0, l = -1, r = -1;
    bool ok = false;

    mp[0] = -1;
    fr[0] = 1;

    for (int i = 0; i < n; i++) {
        s += a[i];
        ll need = s - k;

        if (fr.count(need)) {
            ok = true;
            cnt += fr[need];
            int len = i - mp[need];
            if (len > mx) {
                mx = len;
                l = mp[need] + 1;
                r = i;
            }
        }

        if (mp.find(s) == mp.end()) mp[s] = i;
        fr[s]++;
    }

    cout << (ok ? "Yes" : "No") << "\n";
    if (l != -1) {
        for (int i = l; i <= r; i++) cout << a[i] << " ";
        cout << "\n";
    } else {
        cout << "None\n";
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}