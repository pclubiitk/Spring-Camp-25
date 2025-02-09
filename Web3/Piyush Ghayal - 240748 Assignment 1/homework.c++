#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
using namespace std;

string sha256(const string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }

    return ss.str();
}

string Hex(int& num)
{
    stringstream ss;
    ss << hex << num;

    return ss.str();
}

int main() {
    string P1, P2;
    int k;

    
    cin >> P1;
    cin >> P2;
    cin >> k;

    
    string S1, S2;

    for (int i = 0; ; ++i) {
        S1 = P1 + Hex(i);
        string hash1 = sha256(S1);

        for (int j = 0; j < 1000000; ++j) {
            S2 = P2 + Hex(j);
            string hash2 = sha256(S2);

            if (hash1.substr(0, k) == hash2.substr(0, k) && S1 != S2) {
                cout << "Found S1: " << S1 << endl;
                cout << "Found S2: " << S2 << endl;
                cout << "Hash1: " << hash1 << endl;
                cout << "Hash2: " << hash2 << endl;
                return 0;
            }
        }
    }

    return 0;
}