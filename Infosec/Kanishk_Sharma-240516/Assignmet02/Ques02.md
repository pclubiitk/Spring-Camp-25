# Trivial Flag Transfer Protocol
## Description
Figure out how they moved the [flag](https://mercury.picoctf.net/static/cc6074838ede2edf9f805fd2b58bdc58/tftp.pcapng).
## Solution
### Extracting file
```
└─$ wget https://mercury.picoctf.net/static/cc6074838ede2edf9f805fd2b58bdc58/tftp.pcapng
--2025-02-05 20:25:35--  https://mercury.picoctf.net/static/cc6074838ede2edf9f805fd2b58bdc58/tftp.pcapng
Resolving mercury.picoctf.net (mercury.picoctf.net)... 18.189.209.142
Connecting to mercury.picoctf.net (mercury.picoctf.net)|18.189.209.142|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 52116496 (50M) [application/octet-stream]
Saving to: ‘tftp.pcapng.1’

tftp.pcapng.1   100%[======>]  49.70M  4.25MB/s    in 22s     

2025-02-05 20:25:58 (2.31 MB/s) - ‘tftp.pcapng.1’ saved [52116496/52116496]
```
### Extracting objects
Looking is it a pcapng file, we have to open it in wireshark.
![image](https://github.com/user-attachments/assets/ec209f2d-c602-48c3-b1ed-8f4473564c26)

We extract packets in TFTP to understand the communication between different elements:
![image](https://github.com/user-attachments/assets/62ca7025-dd26-4045-a05d-a2b921cbb1ee)

We extract the necessary objects:
![image](https://github.com/user-attachments/assets/9ff4c9be-bd63-4c6c-b509-1962c398b881)

### Instruction.txt
```
└─$ cat instructions.txt
GSGCQBRFAGRAPELCGBHEGENSSVPFBJRZHFGQVFTHVFRBHESYNTGENAFSRE.SVTHERBHGNJNLGBUVQRGURSYNTNAQVJVYYPURPXONPXSBEGURCYNA
```
There is a chance that it could be in ROT13 so on decoding it, we get:
``TFTP DOESNT ENCRYPT OUR TRAFFIC SO WE MUST DISGUISE OUR FLAG TRANSFER. FIGURE OUT A WAY TO HIDE THE FLAG AND I WILL CHECK BACK FOR THE PLAN``
This also points to the file plan.
### Plan
```
└─$ cat plan            
VHFRQGURCEBTENZNAQUVQVGJVGU-QHRQVYVTRAPR.PURPXBHGGURCUBGBF
```
This also looks like ROT13. So on decoding it, we get:
``I USED THE PROGRAM AND HID IT WITH- DUEDILIGENCE. CHECKOUT THE PHOTOS``
This points to use the program with the photos.
### Program
Installing the program:
```
└─$ sudo apt-get install ./program.deb
[sudo] password for kanishk: 
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
Note, selecting 'steghide' instead of './program.deb'
The following packages were automatically installed and are no longer required:
  apg bolt fwupd fwupd-amd64-signed gir1.2-malcontent-0
  gnome-bluetooth-3-common gnome-bluetooth-sendto
  gnome-control-center-data gnome-online-accounts
  gnome-user-docs gnome-user-share heif-thumbnailer jq
  libapache2-mod-dnssd libarmadillo12 libcolord-gtk4-1t64
  libconfig++9v5 libdisplay-info2 libei1 libeis1 libffado2
  libflatpak0 libfreerdp-server3-3 libfwupd3 libgdal34t64
  libges-1.0-0 libgnome-bluetooth-3.0-13
  libgnome-bluetooth-ui-3.0-13 libgnome-rr-4-2t64
  libgoa-backend-1.0-2 libgsound0t64 libgupnp-av-1.0-3
  libgupnp-dlna-2.0-4 libibus-1.0-5 libjcat1
  libmalcontent-0-0 libmalcontent-ui-1-1 libmutter-15-0
  libnss-myhostname libopenfec1 libostree-1-1 libpoppler134
  librest-1.0-0 libroc0.4 librygel-core-2.8-0
  librygel-db-2.8-0 librygel-renderer-2.8-0
  librygel-server-2.8-0 libsuperlu6 libwireplumber-0.5-0
  libxcb-res0 malcontent malcontent-gui mutter-common-bin
  power-profiles-daemon realmd rygel tecla
Use 'sudo apt autoremove' to remove them.
The following packages will be DOWNGRADED:
  steghide
0 upgraded, 0 newly installed, 1 downgraded, 0 to remove and 1018 not upgraded.
Need to get 0 B/138 kB of archives.
After this operation, 52.2 kB disk space will be freed.
Do you want to continue? [Y/n] y
Get:1 /home/kanishk/picoctf/program.deb steghide amd64 0.5.1-9.1+b1 [138 kB]
dpkg: warning: downgrading steghide from 0.5.1-15 to 0.5.1-9.1+b1
(Reading database ... 464372 files and directories currently installed.)
Preparing to unpack .../kanishk/picoctf/program.deb ...
Unpacking steghide (0.5.1-9.1+b1) over (0.5.1-15) ...
Setting up steghide (0.5.1-9.1+b1) ...
Processing triggers for man-db (2.13.0-1) ...
Processing triggers for kali-menu (2024.4.0) ...
N: Download is performed unsandboxed as root as file '/home/kanishk/picoctf/program.deb' couldn't be accessed by user '_apt'. - pkgAcquire::Run (13: Permission denied)
```
We notice that the program is actually steghide. So, we understand that the there is LSB in the photos and we must access them. The "DUEDILIGENCE" can be the possible password due to its highlighting in the text.
### Extracting flag
Trying steghide with the 3 photos:
```
┌──(kanishk㉿arthur)-[~/picoctf]
└─$ steghide extract -sf picture1.bmp -p "DUEDILIGENCE"
steghide: could not extract any data with that passphrase!
                                                               
┌──(kanishk㉿arthur)-[~/picoctf]
└─$ steghide extract -sf picture2.bmp -p "DUEDILIGENCE"
steghide: could not extract any data with that passphrase!
                                                               
┌──(kanishk㉿arthur)-[~/picoctf]
└─$ steghide extract -sf picture3.bmp -p "DUEDILIGENCE"
wrote extracted data to "flag.txt".
                                                               
┌──(kanishk㉿arthur)-[~/picoctf]
└─$ cat flag.txt   
picoCTF{h1dd3n_1n_pLa1n_51GHT_18375919}
```

                                                  
                                     
                                                        
                        
