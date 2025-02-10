import hashlib
import random

strings = input().split()

p1 = strings[0]
p2 = strings[1]
k = int(strings[2])

hash1 = hashlib.sha256(p1.encode()).hexdigest()
hash2 = hashlib.sha256(p2.encode()).hexdigest()

count = 0

while(hash1[:k] != hash2[:k] and count < 10**7):
    p1 = p1 + '1'
    hash1 = hashlib.sha256(p1.encode()).hexdigest()
    count += 1

print(hash1,hash2,p1,p2)