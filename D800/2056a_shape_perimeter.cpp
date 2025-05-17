#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))

typedef long long ll;

#define F first
#define S second
#define MP(x, y) make_pair((x), (y));

typedef pair<int, int> pi;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    
	    pi base;
	    cin >> base.F >> base.S;
	    pi ub = MP(base.F+m, base.S+m);
	    
	    int sum = 0;
	    
	    REP(i,1,n) {
	        int x, y;
	        cin >> x >> y;
	        base.F += x; base.S += y;
	        pi d = MP(ub.F-base.F, ub.S-base.S);
	        sum += (d.F+d.S)<<1;
	        ub.F = base.F+m; ub.S = base.S+m;
	    }
	    
	    cout << (n*(m<<2))-sum << "\n";
	}
	
	return 0;
}
