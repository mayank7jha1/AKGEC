#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> right_min(n);
    right_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_min[i] = min(right_min[i + 1], a[i]);
    }

    int partition = 1;
    int current_max = INT_MIN;

    for (int i = 0; i < n - 1; i++) {
        current_max = max(current_max, a[i]);
        if (current_max <= right_min[i + 1]) {
            partition++;
        }
    }

    cout << partition << "\n";

    return 0;
}
