# pico ctf 2018 strings  
Did ```file strings```  
It was an 64 bit executable  
Tried to run it ```./strings```  it said permision denied.  
Gave it executable permission ```chmod +x strings```  
Then ran it. It said ```Have you ever used the 'strings' function? Check out the man pages!```  
Used ```strings strings | grep pico```  
Flag: ```picoCTF{sTrIngS_sAVeS_Time_3f712a28}```
