import sys
import bisect
n,h = map(int,sys.stdin.readline().split())
down =[]
up = []
for i in range(n):
    stuff = int(sys.stdin.readline())
    if i%2 == 0:
        down.append(stuff)
    else:
        up.append(stuff)
down.sort()
up.sort()
count = 1
result =n+1
for i in range(1,h+1):
    d = len(down) - bisect.bisect_left(down,i)
    u = len(up)- bisect.bisect_left(up,h-i+1)
    if result >= d+u:
        if result == d+u:
            count+=1
        else:
            result = d+u
            count =1
print(result,end=' ')
print(count)