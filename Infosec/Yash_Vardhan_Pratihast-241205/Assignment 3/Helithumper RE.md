Using Ghidra to decompile the binary we get the source code and main function
![Screenshot from 2025-02-13 23-07-55](https://github.com/user-attachments/assets/bc8a1025-27df-44f2-b80c-1036739456b7)

The main function takes input and then checks it using another vaidate function. We can see that the validate function does highlighted parts of local_48 array basically stores the flag in hexaadecimal

![Screenshot from 2025-02-13 23-09-05](https://github.com/user-attachments/assets/6ed4b025-0b76-4cda-80aa-9425326588fc)

Now executing the file by using the flag obtained from the validate function


![Screenshot from 2025-02-13 23-52-50](https://github.com/user-attachments/assets/bfeaab8a-f328-4794-9e46-5f7589119574)

![Screenshot from 2025-02-13 23-53-52](https://github.com/user-attachments/assets/4b5784b8-fb9b-49d5-a662-266864746424)
