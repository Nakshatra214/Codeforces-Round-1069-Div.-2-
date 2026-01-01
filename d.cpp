#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct st {
    long long p;
    int i;
};
 
bool cmp(const st& a, const st& b) {
    if (a.i != b.i) return a.i < b.i;
    return a.p < b.p;
}
 
void slv() {
    int ab, bc;
    if (!(cin >> ab >> bc)) return;
    
    vector<int> cd(ab + 1);
    for (int i = 1; i <= ab; ++i) {
        cin >> cd[i];
    }
 
    vector<vector<int>> de(bc + 1);
    for (int i = 1; i <= ab; ++i) {
        int lm = min(cd[i], bc);
        for (int j = 1; j <= lm; ++j) {
            de[j].push_back(i);
        }
    }
 
    vector<vector<vector<st>>> ef(bc + 1, vector<vector<st>>(bc + 1));
 
    for (int i = 1; i <= bc; ++i) {
        if (!de[i].empty()) {
            int idx = de[i][0];
            ef[i][i].push_back({(long long)i * idx, idx});
        }
    }
 
    long long fg = 0;
 
    for (int gh = 1; gh <= bc; ++gh) {
        for (int hi = 1; hi <= gh; ++hi) {
            if (ef[gh][hi].empty()) continue;
 
            auto& ij = ef[gh][hi];
            
            sort(ij.begin(), ij.end(), cmp);
 
            vector<st> jk;
            long long kl = -1; 
 
            for (const auto& s : ij) {
                if (kl == -1 || s.p < kl) {
                    jk.push_back(s);
                    kl = s.p;
                }
            }
            
            for (const auto& s : jk) {
                long long h = (long long)(ab + 1) * hi - s.p;
                if (h > fg) fg = h;
            }
 
            for (int lm = hi + 1; gh + lm <= bc; ++lm) {
                auto& mn = ef[gh + lm][lm];
                
                if (de[lm].empty()) continue;
 
                for (const auto& s : jk) {
                    auto no = upper_bound(de[lm].begin(), de[lm].end(), s.i);
                    
                    if (no != de[lm].end()) {
                        int pq = *no;
                        long long qr = (long long)(lm - hi) * pq;
                        mn.push_back({s.p + qr, pq});
                    }
                }
            }
        }
    }
 
    cout << fg << "\n";
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
