# Wireshark doo dooo do doo...
## Description
Can you find the flag? https://mercury.picoctf.net/static/b44842413a0834f4a3619e5f5e629d05/shark1.pcapng
## Solution
The file given is pcapng so it contains network packet information so we open it in wireshark.
![image](https://github.com/user-attachments/assets/e6c3ad29-3322-41ba-8190-9f5eb11f8b58)

On extracting the http packets, we get:
![image](https://github.com/user-attachments/assets/5e1da4ec-5e80-41bd-8d59-7d658a41c646)

on reading the file:
```
$ cat %2f       
Gur synt vf cvpbPGS{c33xno00_1_f33_h_qrnqorrs}
```
This looks like caesar cipher, so on decoding it, we get ``The flag is picoCTF{p33kab00_1_s33_u_deadbeef}``
