#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for (int i=(s); i<(e); i++)
#define RI(i) int i; cin >> i

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    RI(t);
    
    while(t--) {
        RI(n); RI(mr);
        int h=0, r=0, l=0;
        REP(i,0,n) {
            RI(m);
            int rc=ceil(m/2.0);
            if(r+rc <= mr) {
                if (m&1 && m>2) {
                    rc--;
                    h += rc<<1; l++; r+=rc;
                } else if (m != 1){
                    h+=m; r+=rc;
                } else l+=m;
            } else l+=m;
        }
        
        while(r<mr && l>0) {
            h++; l--; r++;
        }
        if (l>0) h-=l;
        cout << h << "\n";
    }
    return 0;
}
