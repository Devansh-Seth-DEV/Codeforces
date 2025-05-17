#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    
    while(t--) {
        int n; cin >> n;
        int r=1, mr=1, p;
        REP(i,0,n) {
            if (i==0) cin >> p;
            else {
                int x; cin >> x;
                if (x==p) r++;
                else {
                    mr = max(mr, r);
                    p = x; r=1;
                }
            }
        }
        mr = max(mr, r);
        cout << n-mr << "\n";
    }
    
    return 0;
}
