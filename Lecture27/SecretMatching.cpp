#include<iostream>
#include<vector>
using namespace std;

class DSU {
public:
    vector<int> par;
    vector<int> rnk;

    DSU(int n) : par(n, -1), rnk(n, 1) {}

    int find(int x) {
        if (par[x] == -1) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rnk[px] < rnk[py]) swap(px, py);
        par[py] = px;
        rnk[px] += rnk[py];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    DSU dsu(26);
    bool used[26] = {};  // track which letters actually appear

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        used[s[0] - 'a'] = true;
        for (int j = 1; j < (int)s.length(); j++) {
            used[s[j] - 'a'] = true;
            dsu.unite(s[j - 1] - 'a', s[j] - 'a');
        }
    }

    // Count distinct components among used letters (at most 26 iterations)
    bool seen[26] = {};
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (used[i]) {
            int root = dsu.find(i);
            if (!seen[root]) {
                seen[root] = true;
                ans++;
            }
        }
    }

    cout << ans << endl;
}
