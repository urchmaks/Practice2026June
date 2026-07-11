#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<bool> danger(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        danger[x] = true;
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    long long cur = 0;

    for (int i = 1; i <= n; ++i) {
        cur = (cur + dp[i - 1]) % MOD;

        if (i - k - 1 >= 0) {
            cur = (cur - dp[i - k - 1] + MOD) % MOD;
        }

        if (danger[i]) {
            dp[i] = 0;
        } else {
            dp[i] = cur;
        }
    }

    cout << dp[n] % MOD << '\n';

    return 0;
}
