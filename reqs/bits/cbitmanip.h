#ifndef CBITMANIP_H
#define CBITMANIP_H

// Returns the number of 1-bits in the binary representation of x.
int bitm_popcount(unsigned int x);
long long bitm_popcountll(unsigned long long x);

// Count leading zeros (number of zeros before the first 1 from the left).
// 32 (Undefined) if x == 0
int bitm_clz(unsigned int x);
long long bitm_clz(unsigned long long x);

// Count trailing zeros (number of zeros after the last 1 from the right).
// 32 (Undefined) if x == 0
int bitm_ctz(unsigned int x);
long long bitm_clz(unsigned long long x);

// Returns 1 if the number of 1-bits is odd, else 0.
int bitm_parity(unsigned int x);
long long bitm_clz(unsigned long long x);

#endif
