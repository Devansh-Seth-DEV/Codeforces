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
		RI(a); RI(b);
		if (( a==0 && (b&1)==0 ) ||
			(a>0 && (a&1)==0 && (a==b || b==0 || 1) )
			) cout << "YES\n";
		else cout << "NO\n";
	}
    
    return 0;
}
