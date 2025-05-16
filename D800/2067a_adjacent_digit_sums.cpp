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
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int t;
	cin >> t;

	REP(i,0,t) {
		int x, y;
		cin >> x >> y;

		int k = (x-y+1);
		if (k%9 == 0 && k/9>=0) cout << "YES\n";
		else cout << "NO\n";
	}
    
    return 0;
}

