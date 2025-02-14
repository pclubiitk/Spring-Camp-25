# 1.6:Csaw 2018 Tour of x86 pt 1

## Q1-What is the value of dh after line 129 executes?  

line 129: ``` xor dh, dh  ; <- Question 1```  

Here we xor dh register with itself. We know xor of same values will return zero.  
Ans:```0x0```  

## Q2-What is the value of gs after line 145 executes?  
line 149:```  mov gs, dx ; to use them to help me clear     <- Question 2```  

So it moves content of dx reegister to gs. When finding value of dx register in code above we see  
```
mov dx, 0xffff  ; Hexadecimal
not dx
```  
So dx has value 0xffff and then not reverses the bites to 0000  
So value of gs:```0x0```  

## Q3-What is the value of si after line 151 executes?  

Line 151 is:
 ``` mov si, sp ; Source Index       <- Question 3```  
We have to see what is the value of sp.  
We see  line 149:``` mov sp, cx```  
Now line 144:```mov fs, cx ; already zero, I'm just going```  
And line 107:```mov cx, 0```  

So si:```0x0```  

## Q4-What is the value of ax after line 169 executes?  

Lines 168-169 are:
  ```
mov al, 't' 
  mov ah, 0x0e      ; <- question 4
```   
ax is made up of ah(high bite) and al(low bite)  
We see ah is 0x0e.  
al is 't' which in hex is 0x74  
So ax is  ```0x0e74```  

## Q5-What is the value of ax after line 199 executes for the first time?  

Line 199 is:
```mov ah, 0x0e  ; <- Question 5!```  

We have ah 0x0e.  
Line 197 has ``` mov al,[si]```. So al has the content that is pointed by si.  
When looking further we see a ```print_string``` function that is changing the value of ax.  
We have a loop that iterates.  
When it iterates first time it saves ```a``` which has hex ```0x61``` in ```al``` register  
So ax register will be ```0x0e61```.

