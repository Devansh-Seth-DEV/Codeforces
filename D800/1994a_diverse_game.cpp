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
		RI(n); RI(m);
		if (n*m == 1) {
			RI(x);
			cout << -1 << "\n"; continue;
		}

		int b[10][10];
		REP(i,0,n) {
			REP(j,0,m) cin >> b[i][j];
		}
		
		REP(i,0,n) {
			REP(j,0,m) {
				cout << b[(i+1)%n][(j+1)%m] << " ";
			}
			cout << "\n";
		}
	}
    
    return 0;
}
