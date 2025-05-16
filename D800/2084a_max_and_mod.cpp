#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define DARRAY(n,type) (type*) malloc(sizeof(type)*n)

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    int t;
    cin >> t;

    REP(i,0,t) {
        int n;
        cin >> n;

        if (n&1) {
            cout << n << " ";
            REP(j,1,n) cout << j << " ";
        } else cout << -1;

        cout << "\n";
    }
    
    return 0;
}

