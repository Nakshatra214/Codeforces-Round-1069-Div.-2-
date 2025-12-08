#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int ab;
    cin >> ab;
    while (ab--) {
        int bc;
        cin >> bc;
        set<int> cd;
        for (int i = 0; i < bc; ++i) {
            int de;
            cin >> de;
            cd.insert(de);
        }
        int de = (int)cd.size();
        while (!cd.count(de)) {
            cd.insert(de);
            de = (int)cd.size();
        }
        cout << de << '\n';
    }
    return 0;
}