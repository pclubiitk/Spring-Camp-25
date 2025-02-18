## Ques 1:-  (Wireshark doo dooo do doo…)
### Flag = ```picoCTF{p33kab00_1_s33_u_deadbeef}```
1. When we export as http, we found a _text/html_ it contains : 
 ```Gur synt vf cvpbPGS{c33xno00_1_f33_h_qrnqorrs}```

2. We decode the flag by passing it through ROT13 (Caesar's cipher) and got our flag.


## Ques 2:- (Trivial Flag Transfer Protocol)
### Flag = ```picoCTF{h1dd3n_1n_pLa1n_51GHT_18375919}```
1. We extract the files with TFTP. There are 2 text files, 3 bmp files and a _.deb_ file.

2. The _.deb_ file contains steghide, this gives us a hint that flag might be hidden in bmp files by steghide.

3. Using a caesar cipher solver, we get these 2 messages from the text files:
 
   Instructions.txt: ```TFTPDOESNTENCRYPTOURTRAFFICSOWEMUSTDISGUISEOURFLAGTRANSFER.FIGUREOUTAWAYTOHIDETHEFLAGANDIWILLCHECKBACKFORTHEPLAN```

   plan.txt: ```IUSEDTHEPROGRAMANDHIDITWITH-DUEDILIGENCE.CHECKOUTTHEPHOTOS```
4. On using steghide with password/passphase **DUEDILIGENCE** on 3 bmp files, we get flag in 3rd bmp file.
``` ──(chi㉿vbox)-[/media/sf_picoctf]
 └─$ steghide extract -sf '/media/sf_picoctf/picture1.bmp' -p DUEDILIGENCE                 
 steghide: could not extract any data with that passphrase!
                                                                                                                          
 ┌──(chi㉿vbox)-[/media/sf_picoctf]
 └─$ steghide extract -sf '/media/sf_picoctf/picture2.bmp' -p DUEDILIGENCE                 
 steghide: could not extract any data with that passphrase!

 ┌──(chi㉿vbox)-[/media/sf_picoctf]
 └─$ steghide extract -sf '/media/sf_picoctf/picture3.bmp' -p DUEDILIGENCE
 the file "flag.txt" does already exist. overwrite ? (y/n) y
 wrote extracted data to "flag.txt".
                                                                                                                          
 ┌──(chi㉿vbox)-[/media/sf_picoctf]
 └─$ cat ./flag.txt                               
 picoCTF{h1dd3n_1n_pLa1n_51GHT_18375919}
 ```
                                         
                                         
                                        
## Ques 3:- (Wireshark twoo twooo two twoo...) <sub>(hardest)</sub>
### Flag = ```picoCTF{dns_3xf1l_ftw_deadbeef}```   
1. Upon initial inspection, there seem to be a lot of requests to a _/flag_ endpoint. Each request shows a different flag so these might be a distraction.

2. After searching through the file We noticed many DNS requests for various subdomains of reddshrimpandherring.com. This looks like the suspicious.

3. A lot of the DNS queries have a destination of **8.8.8.8**. However, a subset have a destination for **18.217.1.57**.

4. We can apply the filter dns and **ip.dst**=```18.217.1.57```. If we take the subdomains of _reddshrimpandherring.com_ and append them in order we get: ```cGljb0NURntkbnNfM3hmMWxfZnR3X2RlYWRiZWVmfQ==```.
5. Its **Base64**. On decoding it gives the flag.

## Ques 4:- (Packets Primer)
### Flag = ```picoCTF{p4ck37_5h4rk_01b0a0d6}```
1. It contains TCP and ARP. A TCP packet contains flag in plain text but with white spaces :
```p i c o C T F { p 4 c k 3 7 _ 5 h 4 r k _ b 9 d 5 3 7 6 5 }```

2. Just remove whitespaces to get flag.
