use std::io;
use sha2::{Sha256, Digest};
use hex;

fn take(prompt: &str, max_length: usize) -> String {
    loop {
        println!("{}", prompt);
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let input = input.trim().to_string();
        if input.len() <= max_length {
            return input;
        }
        println!("Error: Input must be {} characters or less.", max_length);
    }
}

fn num() -> usize {
    loop {
        println!("Enter k (1 to 10):");
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        match input.trim().parse() {
            Ok(num) if num >= 1 && num <= 10 => return num,
            _ => println!("Integer only between 1 and 10."),
        }
    }
}

fn hashing(input: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(input);
    hex::encode(hasher.finalize())
}

fn k_identical(p1: &str, p2: &str, k: usize) {
    let mut suffix1 = 0;
    let mut suffix2 = 0;

    loop {
        let s1 = format!("{}{}", p1, suffix1);
        let s2 = format!("{}{}", p2, suffix2);

        let hash1 = hashing(&s1);
        let hash2 = hashing(&s2);

        if hash1[..k] == hash2[..k] {
            let ss1 = format!("{}{}{}", p1, &hash1[..k], hash1);
            let ss2 = format!("{}{}{}", p2, &hash2[..k], hash2);

            println!("{}", ss1);
            println!("{}", ss2);
            return;
        }

        suffix2 += 1;
        if suffix2 > suffix1 {
            suffix1 += 1;
            suffix2 = 0;
        }
    }
}

fn main() {
    let p1 = take("Enter P1 (max 8 characters):", 8);
    let p2 = take("Enter P2 (max 8 characters):", 8);
    let k = num();
    k_identical(&p1, &p2, k);
}
