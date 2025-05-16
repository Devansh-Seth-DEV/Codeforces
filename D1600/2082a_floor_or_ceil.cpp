#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))

typedef long long ll;

int F(int x, int n) {
	while(n--) {
		if (!x) return x;
		x >>= 1;
	}
	return x;
}

int C(int x, int n) {
	while(n--) {
		if (x<=1) return x;
		x = (x+1)>>1;
	}
	return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int t;
	cin >> t;

	while(t--) {
		int x, n, m;
		cin >> x >> n >> m;
		cout << F(C(x, m), n) << " " << C(F(x, n), m) << "\n";
	}
    
    return 0;
}

