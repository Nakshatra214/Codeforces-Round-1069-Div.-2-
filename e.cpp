#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long pw(long long a, long long b, long long c) {
    long long d = 1;
    a %= c;
    while (b > 0) {
        if (b % 2 == 1) d = (d * a) % c;
        a = (a * a) % c;
        b /= 2;
    }
    return d;
}
 
void slv() {
    int ab;
    long long bc, cd;
    if (!(cin >> ab >> bc >> cd)) return;
 
    long long de = pw(bc, cd - 2, cd);
    
    vector<long long> ef(ab + 1);
    ef[0] = 1;
    for (int i = 1; i <= ab; ++i) {
        ef[i] = (ef[i - 1] * de) % cd;
    }
 
    long long fg = 0;
    long long gh = 0;
 
    for (int hi = 1; hi <= ab; ++hi) {
        int ij = min(hi - 1, ab - hi);
        
        long long jk = 0;
        long long kl = 0;
        
        for (int lm = 0; lm <= ij; ++lm) {
            long long mn = ef[lm]; 
            jk = (jk + mn) % cd;
            
            long long no = (2 * lm + 1);
            kl = (kl + mn * no) % cd;
        }
        
        fg = (fg + jk) % cd;
        
        long long pq = (kl - (jk * jk) % cd + cd) % cd;
        gh = (gh + pq) % cd;
    }
 
    for (int hi = 1; hi < ab; ++hi) {
        int ij = min(hi, ab - hi);
        
        long long jk = 0;
        long long kl = 0;
        
        for (int lm = 1; lm <= ij; ++lm) {
            long long mn = ef[lm];
            jk = (jk + mn) % cd;
            
            long long no = (2 * lm - 1);
            kl = (kl + mn * no) % cd;
        }
        
        fg = (fg + jk) % cd;
        long long pq = (kl - (jk * jk) % cd + cd) % cd;
        gh = (gh + pq) % cd;
    }
 
    long long qr = (fg * fg) % cd;
    qr = (qr + gh) % cd;
    
    cout << qr << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            slv();
        }
    }
    return 0;
}
//nakshatra