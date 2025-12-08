#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int ab;
    cin >> ab;
    while (ab--) {
        int bc, cd, de;
        cin >> bc >> cd >> de;
 
        vector<ll> fg(bc + 1), gh(bc + 1);
 
        fg[0] = 0;
        for (int i = 1; i <= bc; ++i) fg[i] = i;
        fg[de] = cd - 1;
 
        for (int i = 1; i <= bc; ++i) {
            gh[i] = fg[i] ^ fg[i - 1];
        }
 
        for (int i = 1; i <= bc; ++i) {
            cout << gh[i] << (i == bc ? '\n' : ' ');
        }
    }
    return 0;
}
//nakshatra