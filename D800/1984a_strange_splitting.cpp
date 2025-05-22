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
		RI(n); RI(a);
		int b;
		REP(i,1,n) {
			if(i==n-1) cin >> b;
			else {RI(x);}
		}
		if (b-a == 0) cout << "NO\n";
		else {
			cout << "YES\n";
			REP(i,0,n) {
				if(i==n>>1) cout << "R";
				else cout << "B";
			}
			cout << "\n";
		}
	}
    
    return 0;
}
