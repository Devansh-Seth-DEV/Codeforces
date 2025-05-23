#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define RI(i) int i; cin >> i
#define RS(s) string s; cin >> s; cin.ignore()
#define REVS(s) reverse(s.begin(), s.end())

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n); RS(a);
        string b = a;
        REVS(b);
        cout << min(a, b+a) << "\n";
	}
    
    return 0;
}
