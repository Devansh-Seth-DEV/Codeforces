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
		int maxe; cin >> maxe;
		int maxi=0, f=1;
		REP(i,1,n) {
			int x; cin >> x;
			if (x>maxe) {
				maxi=i; maxe=x;
				f=1;
			} else if(x==maxe) f++;
		}

		if (f==n) { cout << "NO\n"; continue; }

		cout << "YES\n";
		REP(i,0,n) {
			if (i==maxi) cout << 2 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}
    
    return 0;
}

