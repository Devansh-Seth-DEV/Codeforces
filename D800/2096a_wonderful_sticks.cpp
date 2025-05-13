#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define DARRAY(n,type) (type*) malloc(sizeof(type)*n)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int t;
	cin >> t;

	REP(i,0,t) {
		int n;
		cin >> n; cin.ignore();

		int *a = DARRAY(n,int);
		REP(k,0,n) a[k] = k+1;

		string s;
		cin >> s; cin.ignore();

		REPR(j,s.size(),0) {
			char c = s[j-1];
			int l=0, r=j;

			if ((c=='<' && a[l] < a[r]) ||
				(c=='>' && a[l] > a[r])) {
				while(l <= r) {
					SWP(a,l,r);
					l++; r--;
				}
			}
		}

		REP(k,0,n) cout << a[k] << " ";
		cout << "\n";

		free(a);
	}
    
    return 0;
}

