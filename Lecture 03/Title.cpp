#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    string s;
    cin >> s;

    int n = s.length();
    vector<bool> used(26, false);//Frequency Array

    //This is to check konse konse characters mere original string me use hue hain.
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            used[s[i] - 'a'] = true;
        }
    }

    for (int i = 0; i < (n + 1) / 2; i++) {
        int j = n - 1 - i;
        if (s[i] != '?' && s[j] == '?') {
            s[j] = s[i];
        } else if (s[i] == '?' && s[j] != '?') {
            s[i] = s[j];
        } else if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        if (s[i] != '?') {
            used[s[i] - 'a'] = true;
        }
    }

    int ptr = k - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        int j = n - 1 - i;
        if (s[i] == '?') {
            while (ptr >= 0 && used[ptr]) {
                ptr--;
            }

            char c;
            if (ptr >= 0) {
                c = 'a' + ptr;
                used[ptr] = true;
            } else {
                c = 'a';
            }

            s[i] = s[j] = c;
            used[s[i] - 'a'] = true;
        }
    }

    for (int i = 0; i < k; i++) {
        if (!used[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << s << "\n";

    return 0;
}


