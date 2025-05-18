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
    ios::sync_with_stdio(0); cin.tie(0); 
    
	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		int f0=0;
		REP(i,0,n) {
			char x; cin >> x;
			if (x=='0') f0++;
		}
		int f1=n-f0;
		int res = (f1*(f1-1)) + ((f1*f0)+f0);
		cout << res << "\n";
	}
    
    return 0;
}
