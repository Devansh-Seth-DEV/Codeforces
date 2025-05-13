#include "cbitmanip.h"

int bitm_popcount(unsigned int x) {
	int n=0;
	while (x) { x &= x-1; n++; }
	return n;
}

long long bitm_popcountll(unsigned long long x) {
	long n=0;
	while(x) { x &= x-1; n++; }
	return n;
}

int bitm_clz(unsigned int x) {
	int n = 0;
	if (x == 0) return 32;
	if ((x >> 16) == 0) { n += 16; x <<= 16; }
	if ((x >> 24) == 0) { n += 8; x <<= 8; }
	if ((x >> 28) == 0) { n += 4; x <<= 4; }
	if ((x >> 30) == 0) { n += 2; x <<= 2; }
	if ((x >> 31) == 0) { n += 1; }
	return n;
}

long long bitm_clzll(unsigned long long x) {
	long n=0;
	if (x==0) return 64;
	if ((x >> 32) == 0) { n += 32; x <<= 32; }
	if ((x >> 48) == 0) { n += 16; x <<= 16; }
	if ((x >> 56) == 0) { n += 8; x <<= 8; }
	if ((x >> 60) == 0) { n += 4; x <<= 4; }
	if ((x >> 62) == 0) { n += 2; x <<= 2; }
	if ((x >> 63) == 0) { n += 1; }
	return n;
}

int bitm_ctz(unsigned int x) {
	int n=0;
	if (x==0) return 32;
	if ((x & 0xffff) == 0) { n += 16; x >>= 16; }
	if ((x & 0xff) == 0) { n += 8; x >>= 8; }
	if ((x & 0xf) == 0) { n += 4; x >>= 4; }
	if ((x & 0x3) == 0) { n += 2; x >>= 2; }
	if ((x & 0x1) == 0) { n += 1; }
	return n;
}

long long bitm_ctzll(unsigned long long x) {
	long long n=0;
	if (x==0) return 64;
	if ((x & 0xffffffff) == 0) { n += 32; x >>= 32; }
	if ((x & 0xffff) == 0) { n += 16; x >>= 16; }
	if ((x & 0xff) == 0) { n += 8; x >>= 8; }
	if ((x & 0xf) == 0) { n += 4; x >>= 4; }
	if ((x & 0x3) == 0) { n += 2; x >>= 2; }
	if ((x & 0x1) == 0) { n += 1; }
	return n;
}

int bitm_parity(unsigned int x) {
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return x & 1;
}

long long bitm_parityll(unsigned long long x) {
	x ^= x >> 32;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return x & 1;
}
