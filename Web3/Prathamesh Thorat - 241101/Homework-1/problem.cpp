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

string toHex(int& num)
{
    stringstream ss;
    ss << hex << num;

    return ss.str();
}

int main() {
    string P1, P2;
    int k;

    cout << "Enter prefix P1: ";
    cin >> P1;
    cout << "Enter prefix P2: ";
    cin >> P2;
    cout << "Enter k: ";
    cin >> k;

    if (P1.length() >= 9) {cerr << "Length of P1 must be less than 9" << endl; return 1;}
    if (P2.length() >= 9) {cerr << "Length of P2 must be less than 9" << endl; return 1;}
    if (k < 1 || k > 10) {cerr << "K must be between 1 and 10" << endl; return 1;}
    for(char i : P1) if(!('0' >= i && i <= '9') && !('a' >= i || i <= 'f')) {cerr << "P1 is not an Hex String" << endl; return 1;}
    for(char i : P2) if(!('0' >= i && i <= '9') && !('a' >= i || i <= 'f')) {cerr << "P2 is not an Hex String" << endl; return 1;}

    string S1, S2;

    for (int i = 0; ; ++i) {
        S1 = P1 + toHex(i);
        string hash1 = sha256(S1);

        for (int j = 0; j < 1000000; ++j) {
            S2 = P2 + toHex(j);
            string hash2 = sha256(S2);

            if (hash1.substr(0, k) == hash2.substr(0, k) && S1 != S2) {
                cout << "\nFound S1: " << S1 << endl;
                cout << "Found S2: " << S2 << endl;
                cout << "\nHash1: " << hash1 << endl;
                cout << "Hash2: " << hash2 << endl;
                return 0;
            }
        }
    }

    return 0;
}