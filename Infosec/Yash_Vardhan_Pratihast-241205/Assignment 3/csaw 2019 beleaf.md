![Screenshot from 2025-02-13 23-44-00](https://github.com/user-attachments/assets/cea06f02-cdfa-416d-8cd4-6be93cefc7d9)![Screenshot from 2025-02-13 23-44-00](https://github.com/user-attachments/assets/9d7c9cf5-7e8c-43d9-a011-c113461d0fdb)Similar to previous problem asks for an input therefore using ghidra decompiler would be a good idea to look at source code
![Screenshot from 2025-02-13 23-12-28](https://github.com/user-attachments/assets/771368a5-42ed-47cd-8939-89f1ab870744)

Scrolling through the functions we get what looks like the input function 


![image](https://github.com/user-attachments/assets/43719d02-8007-4d49-863a-9ab864d64354)


We observe that the size of the input text must be greater than 16*2 +1=33 bytes .

Also each of the character gets trnasformed using another function


![Screenshot from 2025-02-13 23-44-00](https://github.com/user-attachments/assets/bd1f99f1-252f-415a-97e7-957a26c97f03)





decoding which we get the flag 


flag{we_beleaf_in_your_re_future}
