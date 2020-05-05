import sys
import math
n,m=map(int,sys.stdin.readline().split())
arr = list(map(int,sys.stdin.readline().split()))
low = 0
high = 1000000000
for i in arr:
    low = max(low,i)
while low <= high:
    count = 1
    mid = (low + high) // 2
    sum = arr[0]
    for i in range(1,n):
        if sum+arr[i] > mid:
            count +=1
            sum = 0
        sum += arr[i]
    if count <= m:
        high = mid -1
    else:
        low = mid + 1
print(low)