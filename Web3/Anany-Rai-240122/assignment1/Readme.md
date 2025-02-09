
# SPING CAMP WEB3 ASSIGNMENT1

This program finds two distinct strings, S1 and S2, that start with given prefixes P1 and P2, respectively, and have SHA-256 hashes sharing the same first k hexadecimal characters.

## Problem Statement
Given:
- A string `P1` (length ≤ 8) consisting of hexadecimal characters (0-9, a-f).
- A string `P2` (length ≤ 8) consisting of hexadecimal characters (0-9, a-f).
- An integer `k` (1 ≤ k ≤ 10), representing the required matching prefix length in the hash.

Find:
- Two distinct strings `S1` and `S2` such that:
  - `S1` starts with `P1` and `S2` starts with `P2`.
  - The first `k` characters of `SHA256(S1).hexdigest()` and `SHA256(S2).hexdigest()` are identical.

## Prerequisites
This project requires Rust to be installed. If Rust is not installed, follow these steps:

### Installing Rust
Rust can be installed using [Rustup](https://rustup.rs/):

```bash
# On Linux/macOS
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# On Windows (PowerShell)
iwr -useb https://win.rustup.rs | Invoke-Expression
```

After installation, ensure Rust is correctly set up:

```bash
rustc --version  # Check Rust compiler version
cargo --version  # Check Cargo package manager version
```

## How to Run

1. Create/Update the necessary cargo.toml file

  use the given toml file or copy the dependencies 

  ```bash
  
[dependencies]
sha2 = "0.10.8"
hex = "0.4.3"

  ```

3. Build the Rust program:

```bash
cargo build
```

3. Run the Rust program:

```bash
cargo run -- <P1> <P2> <k>
```


This will find two strings `S1` and `S2` that meet the required SHA-256 hash prefix collision criteria.

## License


