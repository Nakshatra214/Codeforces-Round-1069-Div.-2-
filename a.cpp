#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while (t--) {
        int ab, bc; 
        cin >> ab >> bc;
        string cd;  
        cin >> cd;
 
        int ef = 0; 
        int gh = 0; 
 
        for (int i = 0; i < ab; ++i) {
            if (cd[i] == '1') {
          
                ef = bc;
            } else {
                if (ef > 0) {
                   
                    ef--;
                } else {
                
                    gh++;
                }
            }
        }
 
        cout << gh << '\n';
    }
    return 0;
}