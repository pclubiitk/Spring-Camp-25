import hashlib

def sha256(s: str) -> str:
    return hashlib.sha256(s.encode()).hexdigest()

def to_hex(num: int) -> str:
    return format(num, 'x')

def main():
    P1 = input("Prefix P1: ")
    P2 = input("Prefix P2: ")
    k = int(input("Enter k: "))
    
    if len(P1) >= 9 or len(P2) >= 9:
        print("Length of P1 and P2 must be less than or equal to 8")
        return
    if not (1 <= k <= 10):
        print("K must be between 1 and 10")
        return
    if not all(c in '0123456789abcdef' for c in P1):
        print("P1 is not a Hex String")
        return
    if not all(c in '0123456789abcdef' for c in P2):
        print("P2 is not a Hex String")
        return
    
    i = 0
    while True:
        S1 = P1 + to_hex(i)
        hash1 = sha256(S1)
        
        for j in range(100000000):
            S2 = P2 + to_hex(j)
            hash2 = sha256(S2)
            
            if hash1[:k] == hash2[:k] and S1 != S2:
                print("\nFound S1:", S1)
                print("Found S2:", S2)
                print("\nHash1:", hash1)
                print("Hash2:", hash2)
                return
        
        i += 1

if __name__ == "__main__":
    main()
