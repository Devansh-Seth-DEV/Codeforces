#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))

typedef long long ll;

int mov(int P, int D, int n) {
	int d = (P<D) ? 1 : 0; // 1->R, 0->L
	int pos = d ? P+1 : P-1;
	if (d && pos<=n && pos != D) return pos;
	else if (pos && pos != D) return pos;
	d = !d;
	pos = d ? P+1 : P-1;
	if (d && pos<=n && pos != D) return pos;
	else if (pos && pos != D) return pos;
	return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int t;
	cin >> t;

	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;
		while ((a && b) && (a<=n && b<=n)) {
			a = mov(a, b, n);
			if (a==0) break;
			b = mov(b, a, n);
			if (b==0) break;
		}
		if (a && a<=n) cout << "YES\n";
		else cout << "NO\n";
	}
    
    return 0;
}

