#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    if (cin >> s >> t) {
        int n = s.length();
        if (t.length() != n) {
            cout << -1 << "\n";
            return 0;
        }

        if (s == t) {
            cout << 0 << "\n";
            return 0;
        }

        string double_s = s + s;
        
        vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i-1];
            while (j > 0 && t[i] != t[j])
                j = pi[j-1];
            if (t[i] == t[j])
                ++j;
            pi[i] = j;
        }

        int max_pos = -1;
        int j = 0;
        for (int i = 0; i < double_s.length(); ++i) {
            while (j > 0 && double_s[i] != t[j])
                j = pi[j-1];
            if (double_s[i] == t[j])
                ++j;
            
            if (j == n) {
                int pos = i - n + 1;
                if (pos < n) {
                    if (pos > max_pos) {
                        max_pos = pos;
                    }
                }
                j = pi[j-1];
            }
        }

        if (max_pos != -1) {
            cout << n - max_pos << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
