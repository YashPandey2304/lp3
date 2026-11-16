def  fibnochi_non(n):
    a,b=0,1
    for i in range(n):
        print(a,end="")
        a,b=b,a+b


def  fibo_recur(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    return fibo_recur(n-1)+fibo_recur(n-2)


while True:
    choice=int(input("\n\nEnter the choice "))
    if choice==1:
        n=int(input("ENter the number needed1 :  "))
        fibnochi_non(n)
    elif choice==2:
        n=int(input("ENter the number needed2 :  "))
        for i in range(n):
            
            print(fibo_recur(i),end=" ")
            

    elif choice==3:
        print("existing")
        break
    else:
        print("invlid ans")