# Wireshark twoo twooo two twoo...
Opened the file in wire shark  
Followed the tcp stream got something written in multipy streams as ```picoCTF{.......}```  
Tried to decode them but they were not the flag  
They had same ip address conection so searched the ip address ```ip.addr==18.217.1.57```  
There were TCP, HTTP, DNS streams with the same adress searched for them seperately  
In the Dns streams(search filter ```ip.dst==18.217.1.57 && DNS```  got something that looked like base64(one stream had info ```fQ==```) and was written in multiple streams.  
Combined them and decoded them to get the flag.  
Got the base64 text:```cGljb0NURntkbnNfM3hmMWxfZnR3X2RlYWRiZWVmfQ==```  
Got the flag:```picoCTF{dns_3xf1l_ftw_deadbeef}```
