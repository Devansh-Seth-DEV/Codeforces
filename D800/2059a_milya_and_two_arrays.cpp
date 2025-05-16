#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int t;
	cin >> t;

	while(t--) {
        int n;
        cin >> n;

        set<int> a, b;
        int x;
        REP(i,0,n) { cin >> x; a.insert(x); }
        REP(i,0,n) { cin >> x; b.insert(x); }

        if (a.size() + b.size() < 4) cout << "NO\n";
        else cout << "YES\n";
	}
    
    return 0;
}

