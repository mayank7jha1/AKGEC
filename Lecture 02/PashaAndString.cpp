#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int m;
	cin >> m;

	int n = s.length();
	vector<int> counts(n / 2 + 1, 0);

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		counts[x - 1]++;
	}

	int current_sum = 0;
	for (int i = 0; i < n / 2; i++) {
		current_sum += counts[i];
		if (current_sum % 2 == 1) {
			swap(s[i], s[n - 1 - i]);
		}
	}

	cout << s << "\n";

	return 0;
}