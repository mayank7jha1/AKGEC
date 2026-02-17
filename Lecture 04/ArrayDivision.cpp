#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    if (s % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    s /= 2;
    set<int> st;
    int ls = 0;

    for (int i = 0; i < n; i++) {
        ls += a[i];
        st.insert(a[i]);
        if (ls == s || st.count(ls - s)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    st.clear();
    int rs = 0;

    for (int i = n - 1; i >= 0; i--) {
        rs += a[i];
        st.insert(a[i]);
        if (rs == s || st.count(rs - s)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}