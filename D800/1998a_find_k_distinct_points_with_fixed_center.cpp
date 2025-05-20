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
		RI(xc); RI(yc); RI(k);

		REP(i,0,(k>>1)) {
			cout << xc << " " << yc-(i+1) << "\n";
			cout << xc << " " << yc+(i+1) << "\n";
		}
		if(k&1) cout << xc << " " << yc << "\n";
	}
    
    return 0;
}
