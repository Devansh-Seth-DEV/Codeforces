#include <bits/stdc++.h>
using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; i++)
#define FOR_REV(i,s,e) for (int i=s; i>e; i--)

#define SWP(A,i,j) \
	int temp=A[j]; \
	A[j]=A[i]; \
	A[i]=temp;

#define INIT_NEW_NUM_ARGS_IMPL(_1, _2, _3, _4, _5, N, ...) N
#define INIT_NEW_NUM_ARGS(...) INIT_NEW_NUM_ARGS_IMPL(__VA_ARGS__, 5, 4, 3, 2)

#define INIT_NEW_ARGS_2(src,n) FOR(i,0,n) src[i] = 0
#define INIT_NEW_ARGS_3(src,n,v) FOR(i,0,n) src[i] = v
#define INIT_NEW_ARGS_4(src,n,v,inc) \
    int temp=v;\
    FOR(i,0,n) {\
        src[i] = temp;\
        temp += inc;\
    }
#define INIT_NEW_ARGS_5(src,n,v,oprnd,op) \
	int temp=v;\
	FOR(i,0,n) {\
		src[i] = temp;\
		temp = temp op oprnd;\
	}

#define INIT_NEW_CHOOSER(...) INIT_NEW_NUM_ARGS(__VA_ARGS__)

#define INIT_NEW_EXPAND_HELPER(count, ...) INIT_NEW_ARGS_##count(__VA_ARGS__)
#define INIT_NEW_EXPAND(count, ...) INIT_NEW_EXPAND_HELPER(count, __VA_ARGS__)


#define NEW(n,type) (type*) malloc(sizeof(type)*(n))
#define INIT_NEW(...) INIT_NEW_EXPAND(INIT_NEW_CHOOSER(__VA_ARGS__), __VA_ARGS__)

#define RI(i) int i; cin >> i

typedef vector<int> vi;

int binaryGCD(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    // Both even
    if ((a & 1) == 0 && (b & 1) == 0)
        return binaryGCD(a >> 1, b >> 1) << 1;

    // a is even, b is odd
    if ((a & 1) == 0)
        return binaryGCD(a >> 1, b);

    // a is odd, b is even
    if ((b & 1) == 0)
        return binaryGCD(a, b >> 1);

    // Both odd, a >= b
    if (a >= b)
        return binaryGCD((a - b) >> 1, b);

    // Both odd, b > a
    return binaryGCD((b - a) >> 1, a);
}

int find_max_index(vi& v, int j) {
	int idx=-1;
	int mx=-1;
	FOR(i,0,v.size()) {
		if(i!=j && v[i]>mx) { mx=v[i]; idx=i; }
	}
	return idx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    
	RI(t);

	while(t--) {
		RI(n);
		vi a(n);

		FOR(i,0,n) cin >> a[i];
		if (n==1) { cout << 0 << "\n"; continue; }

		sort(a.begin(), a.end());

		int k=-1;
		FOR_REV(i,n-2, -1) {
			if (a[i]!=a[n-1]) {k=i;break;}
		}
		if (k<0) { cout << 0 << "\n"; continue; }

		int gcd=binaryGCD(a[n-1], a[k]);
		a[n-1] = gcd;

		int op=1;
		FOR(i,0,n) {
			if(a[i] != gcd) {
				op++;
				gcd = binaryGCD(gcd, a[i]);
				a[i] = gcd;
			}
		}

		cout << op << "\n";
	}
    
    return 0;
}
