#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define RI(i) int i; cin >> i

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n);
		if (n&1) {
			int x=n;
			while(x>=1) { cout << x << " "; x-=2; }
			x = 2;
			while(x<=n-1) { cout << x << " "; x+=2; }
			cout << "\n";
		} else cout << -1 << "\n";
	}
    
    return 0;
}
