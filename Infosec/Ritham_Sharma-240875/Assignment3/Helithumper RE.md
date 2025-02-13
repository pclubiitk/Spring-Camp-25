We were given an ELF file rev used Ghidra Decompiler to reverse engineer the Assembly code found the main function 

![Screenshot from 2025-02-13 23-07-55](https://github.com/user-attachments/assets/bc8a1025-27df-44f2-b80c-1036739456b7)

So we can see that it is scanning in data , then running the validate function. We can see that the validate function does this The highlighted parts of local_48 array basically stores the flag:

![Screenshot from 2025-02-13 23-09-05](https://github.com/user-attachments/assets/6ed4b025-0b76-4cda-80aa-9425326588fc)

Now executing the file by using the flag obtained from the validate function


![Screenshot from 2025-02-13 23-10-38](https://github.com/user-attachments/assets/eabc0406-0fe5-45bd-9345-c3709c7bd562)
