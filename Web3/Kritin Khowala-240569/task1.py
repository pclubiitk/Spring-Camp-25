import hashlib

#s=s.encode("utf-8") 
#print(hashlib.sha256(s).hexdigest())
p1=input("Enter first prefix ")
p2=input("Enter second prefix ")
index=len(p1)
hexa="0123456789ABCDEF"
k=int(input("Enter k"))
def function(s1,s2,k,index,hexa):
    n1=s1.encode("utf-8")
    n2=s2.encode("utf-8")
    n1=hashlib.sha256(n1).hexdigest()
    n2=hashlib.sha256(n2).hexdigest()
    count=int(0)
    for i in range(k):
        if(n1[i]!=n2[i] or count>=k):
            break
        else:
            count+=1
    if(count==k):
        print(n1+" "+n2)
        return
    else:
        temp=list(s1)
        for a in hexa:
            temp[len(s1)-1]=a
            s1="".join(temp)
            return function(s1,s2,k,index+1,hexa)
function(p1,p2,k,index,hexa)    





