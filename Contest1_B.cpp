#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(int i=0;i<n;i++){
        vector<ll>arr(7);
        ll g;
        for (int i=0;i<7;i++){
            cin >> g;
            arr[i]=g;
        }
        sort(arr.begin(), arr.end());
        ll sm=0;
        for (int i=0;i<7;i++){
            if (i==6){
                sm+=arr[i];
            }
            else {
                sm-=arr[i];
            }
        }
        cout << sm << '\n';
        //cout << 67 << '\n';
    }
    
    //cout << 9 << '\n';
    return 0;
}
