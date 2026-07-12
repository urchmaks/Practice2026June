#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }

    const int INF = 1e9;
    int full = (1 << n) - 1;
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    dp[1][0] = 0;

    for (int mask = 1; mask <= full; ++mask) {
        for (int v = 0; v < n; ++v) {
            if (dp[mask][v] == INF) continue;
            for (int u = 0; u < n; ++u) {
                if (mask & (1 << u)) continue;
                int nmask = mask | (1 << u);
                dp[nmask][u] = min(dp[nmask][u], dp[mask][v] + c[v][u]);
            }
        }
    }

    int ans = INF;
    for (int v = 0; v < n; ++v) {
        ans = min(ans, dp[full][v] + c[v][0]);
    }

    cout << ans << '\n';
    return 0;
}
