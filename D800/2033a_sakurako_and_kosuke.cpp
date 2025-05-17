#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    
    while(t--) {
        int n; cin >> n;
        int i=1, x=0;
        while(x>=-n && x<=n) {
            int mov = ((i<<1)-1);
            if (i&1) x += -mov;
            else x += mov;
            i++;
        }
        cout << ((i&1) ? "Kosuke" : "Sakurako") << "\n";
    }
    return 0;
}
