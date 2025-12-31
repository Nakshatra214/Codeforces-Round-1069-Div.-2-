#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int ab;
    cin >> ab;
    while (ab--) {
        string bc, cd;
        cin >> bc >> cd;
 
        int ce[26] = {0}, df[26] = {0};
        for (char x : cd) ce[x - 'a']++;
        for (char x : bc) df[x - 'a']++;
 
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (df[i] > ce[i]) { ok = false; break; }
        }
        if (!ok) {
            cout << "Impossible\n";
            continue;
        }
 
        string de;
        for (int i = 0; i < 26; ++i) {
            int cnt = ce[i] - df[i];
            de.append(cnt, char('a' + i));
        }
 
        string ef;
        int i = 0, j = 0;
        int n = (int)bc.size(), m = (int)de.size();
 
        while (i < n && j < m) {
            if (bc[i] < de[j]) {
                ef.push_back(bc[i]);
                ++i;
            } else if (bc[i] > de[j]) {
                ef.push_back(de[j]);
                ++j;
            } else {
                ef.push_back(bc[i]);
                ++i;
            }
        }
        while (i < n) { ef.push_back(bc[i]); ++i; }
        while (j < m) { ef.push_back(de[j]); ++j; }
 
        cout << ef << '\n';
    }
 
    return 0;
}