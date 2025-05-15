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
		int n,m;
		cin >> n >> m;

		int order=n*m;
		int *a = NEW(order, int);
		REP(j,0,order) {
			char c;
			cin >> c;
			a[j] = (c=='0') ? 0 : 1;
		}

		int max=0, dup=0;
		REP(j,0,n) {
			int x=0;
			REP(k,0,m) {
				int idx=(j*m)+k;
				x ^= a[idx];
			}
			if (x) max++;
		}

		dup=max;
		REP(j,0,m) {
			int x=0;
			REP(k,0,n) {
				int idx=(k*m)+j;
				x ^= a[idx];
			}
			if (x && dup) dup--;
			else if (x) max++;
		}

		cout << max << "\n";

		free(a);
	}
    
    return 0;
}

