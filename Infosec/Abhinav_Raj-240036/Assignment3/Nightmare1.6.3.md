# CSAW'29:Beleaf  
Opened the file  
It asked for a flag. Etered any characters it said Incorrect  

Opened the file in Gidra  
Looked the main function with name ```FUN_001008a1```  
It was checking input with contents of ```DAT_003014e0```.  
It was indicating towards another function ```FUN_001007fa``` .Opened it.   
Saw ```DAT_00301020+ local_10*4``` in it.  
So from the main fn and the next fn we see it is basically checking if the input equals to the character stored at the momory address```DAT_00301020+ local_10*4```.Where local_10 indicates the contents of ```DAT_003014e0```.  
Checked for the entries ,eg 1st element of 3014e0 array is 0x1. So 0x301020+4*0x1 equals to 0x301024 which has element 'f'. next we have 0x9 and then 0x11 calculating this and finding the element we get our flag.  
Flag:```flag{we_beleaf_in_your_re_future}```
