#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 10000;
int cnt[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x + OFFSET]++;
    }

    long long ans = 0;
    int residue = 0;

    for (int i = 0; i <= 20000; i++) {
        if (cnt[i] > 0) {
            int take = (cnt[i] + 1 - residue) / 2;
            ans += (long long)take * (i - OFFSET);
            residue = (residue + cnt[i]) % 2;
        }
    }

    cout << ans << endl;
    return 0;
}