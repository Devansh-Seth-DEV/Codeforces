#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define DARRAY(n,type) (type*) malloc(sizeof(type)*n)

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
	int t;
	cin >> t;

	REP(i,0,t) {
		int n, m, l, r;
		cin >> n >> m >> l >> r;

		int ld=0, rd=0;
		REP(j,0,m) {
			if (rd == r && ld != l) ld--;
			else if (ld == l && rd != r) rd++;
			else if ((j&1) && ld != l) ld--;
			else if (rd != r) rd++;
		}
		cout << ld << " " << rd << "\n";
	}
    
    return 0;
}

