#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        int k;
        cin >> n >> k;

        vector<long long> a(k);
        int e = 0;
        vector<long long> d;
        d.reserve(k);

        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            if (a[i] == 1) e++;
            else d.push_back(a[i] - 1);
        }

        sort(d.begin(), d.end());
        int m = (int)d.size();

        vector<long long> pref(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            pref[i + 1] = pref[i] + d[i];
        }

        long long ans = LLONG_MAX;

        int b_start = max(0, m - 1);
        for (int b = b_start; b <= m; ++b) {
            long long S_full = pref[b];
            long long s = max({S_full, e + (long long)b + 2 - 2LL * k, 0LL});
            long long extra = s - S_full;
            if (extra < 0) extra = 0;

            long long L = 0;
            if (b < m) {
                L = (pref[m] - pref[b]) - (m - b);
            }

            if (extra <= L) {
                long long cur = 2 * s + k - 1;
                ans = min(ans, cur);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
