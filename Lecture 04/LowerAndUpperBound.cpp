#include <bits/stdc++.h>
using namespace std;

int lower_bound(const vector<int>& a, int n, int x) {
    int s = 0, e = n - 1;
    int ans = n;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (a[mid] >= x) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int upper_bound(const vector<int>& a, int n, int x) {
    int s = 0, e = n - 1;
    int ans = n;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (a[mid] > x) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

bool binary_search(const vector<int>& a, int n, int x) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (a[mid] == x) return true;
        if (a[mid] > x) e = mid - 1;
        else s = mid + 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int x;
    cin >> x;

    int lb = lower_bound(a, n, x);
    int ub = upper_bound(a, n, x);


    int print_lb = (lb == n) ? -1 : lb;
    int print_ub = (ub == n) ? -1 : ub;

    cout << print_lb << "\n";
    cout << print_ub << "\n";
    cout << binary_search(a, n, x) << "\n";
    cout << ub - lb << "\n";

    return 0;
}