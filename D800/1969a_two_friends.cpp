#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define RI(i) int i; cin >> i
#define PB(x) push_back(x)

typedef vector<int> vi;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n);
		vi p;
		p.PB(0);
		int f=0;
		REP(i,0,n) {
			RI(x);
			p.PB(x);
		}

		REP(i,1,n+1) {
			if (p[p[i]] == i) { f=1; break; }
		}

		if (f) cout << 2 << "\n";
		else cout << 3 << "\n";
	}
    
    return 0;
}
