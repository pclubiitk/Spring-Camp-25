#Trivial Flag Transfer Protocol
Opened the network packet file in Wireshark  
Then did Analyse>Follow>UDP stream  
Saw some data return in some of the streams  
Then used filter ```tftp.type``` to get the packets related to data transfer  
Got some packets with name instructions,plan.pictures..  
Did file>export object>Tftp  
Then saved all the files  
The instruction txt has some letters on which i did rot13 to get: TFTP DOESNT ENCRYPT OUR TRAFFIC SO WE MUST DISGUISE OUR FLAG TRANSFER FIGURE OUT A WAY TO HIDE THE FLAG AND I WILL CHECK BACK FOR THE PLAN (gave spaces for better understanding)  
Then opened the plan txt and did rot 13 to get : I USED THE PROGRAM AND HID IT WITH - DUEDILIGENCE . CHECK OUT THE PHOTOS  
Now opened the program file which was basically steghide program.  
Now did ```steghide extract -sf picture1.bmp -p "DUEDILIGENCE"``` on .bmp files  
Got nothing in 1st and 2md picture  
Got the flag.txt file in the 3rd picture  
Flag: ```picoCTF{h1dd3n_1n_pLa1n_51GHT_18375919}``` 

 
