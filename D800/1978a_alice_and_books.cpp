#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define AREPV(i,s) for(auto &i: s)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define RI(i) int i; cin >> i
#define PB(x) push_back(x)

typedef vector<int> vi;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n);
		vi v(n);	
		AREPV(i,v) cin >> i;
		int maxi=0;
		REP(i,0,n-1) {
			if (v[i]>maxi) maxi=v[i];
		}
		cout << maxi+v[n-1] << "\n";
	}
    
    return 0;
}
