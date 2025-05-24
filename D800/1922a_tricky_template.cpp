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
		string a, b, c;
		cin >> a >> b >> c; cin.ignore();
		bool found=false;
		REP(i,0,n) {
			if (a[i] != c[i] && b[i] != c[i]) {
				found=true;
				break;
			}
		}
		cout << (found ? "YES\n" : "NO\n");
	}
    
    return 0;
}
