import sys
global count
def check1(n,num):
    if num>=n:
        return
    global count
    count +=1
    check1(n,num*10+4)
    check1(n,num*10+7)
def check2(n,num):
    if num>n:
        return
    global count
    count +=1
    check2(n,num*10+4)
    check2(n,num*10+7)
count =0
n1,n2 = map(int,sys.stdin.readline().split())
check1(n1,0)
n1c =count-1
count =0
check2(n2,0)
n2c = count-1
print(n2c-n1c)