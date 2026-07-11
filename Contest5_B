#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    long long window = 0;

    for (int i = 1; i <= n; ++i) {
        window += dp[i - 1];
        if (i - k - 1 >= 0) {
            window -= dp[i - k - 1];
        }
        window %= MOD;
        if (window < 0) window += MOD;
        dp[i] = (int)window;
    }

    cout << dp[n] << '\n';

    return 0;
}
