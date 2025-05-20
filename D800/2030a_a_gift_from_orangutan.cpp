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
		int maxi, mini=0;
		cin >> maxi;
		mini = maxi;
		REP(i,1,n) {
			int x; cin >> x;
			if (x > maxi) maxi=x;
			else if (x<mini) mini=x;
		}
		cout << (maxi-mini)*(n-1) << "\n";
	}
    
    return 0;
}
