#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i=s; i<e; i++)
#define REPR(i,s,e) for (int i=s; i>e; i--)

#define SWP(a,l,r)	int temp=a[r]; \
					a[r]=a[l]; \
					a[l]=temp;

#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define RI(i) int i; cin >> i

int minOf3(int a, int b, int c) {
	if (a<=b && a<=c) return 0;
	else if (b<=a && b<=c) return 1;
	else return 2;
}

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(a); RI(b); RI(c);

		REP(i,0,5) {
			int m = minOf3(a, b, c);
			if (m==0) a+=1;
			else if (m==1) b+=1;
			else c+=1;
		}
		cout << a*b*c << "\n";
	}
    
    return 0;
}
