## Assignment1:

Use any programming language of your preference to solve this problem: Given two different prefixes P1 and P2 (each ≤ 8 hexadecimal characters), find two distinct strings S1 and S2 such that their SHA-256 hashes have the same first k characters in hexadecimal.

## Input:
- A string P1 (length ≤ 8) consisting of hexadecimal characters (0-9, a-f).
- A string P2 (length ≤ 8) consisting of hexadecimal characters (0-9, a-f).
- An integer k (1 ≤ k ≤ 10), representing the required matching prefix length in the hash.

## Output:
- Two distinct strings S1 and S2 such that:
- S1 starts with P1 and S2 starts with P2.
- The first k characters of SHA256(S1).hexdigest() and SHA256(S2).hexdigest() are identical.

  SHA256(S1).hexdigest()  is the hexadecimal representation of the SHA-256 hash of S1.

## libraries installed
- install hashlib to use sha256 function