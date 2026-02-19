#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string recipe;
    cin >> recipe;

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;

    ll pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll r;
    cin >> r;

    ll cb = 0, cs = 0, cc = 0;
    for (char ch : recipe) {
        if (ch == 'B') cb++;
        else if (ch == 'S') cs++;
        else cc++;
    }

    ll s = 0, e = 2e12;
    ll ans = 0;

    while (s <= e) {
        ll mid = s + (e - s) / 2;

        ll req_b = max(0LL, mid * cb - nb);
        ll req_s = max(0LL, mid * cs - ns);
        ll req_c = max(0LL, mid * cc - nc);

        ll cost = req_b * pb + req_s * ps + req_c * pc;

        if (cost <= r) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}