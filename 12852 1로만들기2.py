import sys
num = int(sys.stdin.readline())
dp = [1000001 for i in range(num+1)]
dp[1] = 0
dp[0] = 0
check = [0 for i in range(num+1)]
for i in range(1,num):
    if i*3 <=num and dp[i*3] > dp[i]+1:
        dp[i*3] = dp[i] + 1
        check[i*3] = i
    if i*2 <= num and dp[i*2] > dp[i] +1:
        dp[i*2] = dp[i] + 1
        check[i*2] = i
    if dp[i+1] > dp[i] +1:
        dp[i+1] = dp[i] + 1
        check[i+1] = i
i = num
print(dp[num])
while dp[i] != 0:
    print(i,end= ' ')
    i = check[i]
print(1)