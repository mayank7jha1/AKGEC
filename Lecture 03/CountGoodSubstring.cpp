#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    ll cnt[2][2] = {0};

    for (int i = 0; i < s.length(); i++) {
        cnt[s[i] - 'a'][i % 2]++;
    }

    ll even = 0, odd = 0;

    for (int i = 0; i < 2; i++) {
        odd += cnt[i][0] * (cnt[i][0] + 1) / 2;
        odd += cnt[i][1] * (cnt[i][1] + 1) / 2;
        even += cnt[i][0] * cnt[i][1];
    }

    cout << even << " " << odd << endl;

    return 0;
}