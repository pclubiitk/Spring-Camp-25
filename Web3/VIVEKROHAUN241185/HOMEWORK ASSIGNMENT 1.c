#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define MAX_LEN 16 // Limit for generated strings
#define SHA256_BLOCK_SIZE 32

// SHA-256 functions and constants
static const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Rotate right macro
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define SIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))
#define EP0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define EP1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))

void sha256_transform(uint32_t state[8], const uint8_t data[64]) {
    uint32_t m[64], w[8], i, t1, t2;
    for (i = 0; i < 16; i++) {
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }
    for (; i < 64; i++) {
        m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
    }
    memcpy(w, state, 8 * sizeof(uint32_t));
    for (i = 0; i < 64; i++) {
        t1 = w[7] + EP1(w[4]) + CH(w[4], w[5], w[6]) + k[i] + m[i];
        t2 = EP0(w[0]) + MAJ(w[0], w[1], w[2]);
        memmove(&w[1], &w[0], 7 * sizeof(uint32_t));
        w[4] += t1;
        w[0] = t1 + t2;
    }
    for (i = 0; i < 8; i++) {
        state[i] += w[i];
    }
}

void sha256(const char *str, char *outputBuffer) {
    uint8_t data[64] = {0};
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    size_t len = strlen(str);
    memcpy(data, str, len);
    data[len] = 0x80;
    uint64_t bit_len = len * 8;
    data[63] = bit_len;
    sha256_transform(state, data);
    for (int i = 0; i < 8; i++) {
        sprintf(outputBuffer + (i * 8), "%08x", state[i]);
    }
}

void generate_random_string(char *prefix, char *output) {
    int prefix_len = strlen(prefix);
    strcpy(output, prefix);
    for (int i = prefix_len; i < MAX_LEN - 1; i++) {
        output[i] = "0123456789abcdef"[rand() % 16];
    }
    output[MAX_LEN - 1] = '\0';
}

int main() {
    char P1[9], P2[9];
    int k;
    printf("Enter P1 (hex, max 8 chars): ");
    scanf("%8s", P1);
    printf("Enter P2 (hex, max 8 chars): ");
    scanf("%8s", P2);
    printf("Enter k (1-10): ");
    scanf("%d", &k);
    
    srand(time(NULL));
    char S1[MAX_LEN], S2[MAX_LEN], hash1[65], hash2[65];
    
    do {
        generate_random_string(P1, S1);
        generate_random_string(P2, S2);
        sha256(S1, hash1);
        sha256(S2, hash2);
    } while (strncmp(hash1, hash2, k) != 0);
    
    printf("Found matching strings:\nS1: %s\nS2: %s\n", S1, S2);
    printf("SHA-256(S1): %.*s...\nSHA-256(S2): %.*s...\n", k, hash1, k, hash2);
    
    return 0;
}
