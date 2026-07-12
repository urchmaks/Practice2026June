#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int l = 0, r = n - 1;
        int ans = 0;
        int turn = 0; // 0 - левый, 1 - правый

        while (k > 0 && l <= r) {
            if (l == r) {
                if (k >= a[l]) ans++;
                break;
            }

            long long L = a[l], R = a[r];
            long long d;

            if (turn == 0) {
                if (L <= R) {
                    // умирает левый через 2*L-1 ударов
                    d = 2 * L - 1;
                    if (k < d) break;
                    k -= d;
                    // правый получает L-1 урона
                    a[r] -= (L - 1);
                    l++;
                    ans++;
                } else {
                    // умирает правый через 2*R ударов
                    d = 2 * R;
                    if (k < d) break;
                    k -= d;
                    // левый получает R урона
                    a[l] -= R;
                    r--;
                    ans++;
                }
            } else {
                if (R <= L) {
                    // умирает правый через 2*R-1 ударов
                    d = 2 * R - 1;
                    if (k < d) break;
                    k -= d;
                    // левый получает R-1 урона
                    a[l] -= (R - 1);
                    r--;
                    ans++;
                } else {
                    // умирает левый через 2*L ударов
                    d = 2 * L;
                    if (k < d) break;
                    k -= d;
                    // правый получает L урона
                    a[r] -= L;
                    l++;
                    ans++;
                }
            }
            turn = (turn + d) % 2;
        }

        cout << ans << '\n';
    }
    return 0;
}
