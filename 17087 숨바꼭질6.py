import sys
from math import gcd
n,s = map(int,sys.stdin.readline().split())
bro = list(map(int,sys.stdin.readline().split()))
result = abs(bro[0]-s)
for i in bro:
    result = gcd(result,abs(i-s))
print(result)