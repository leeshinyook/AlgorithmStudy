import sys
num = int(sys.stdin.readline())
score = list(map(int,sys.stdin.readline().split()))
dp = [0 for i in range(num+1)]
for i in range(2,num+1):
    large = 0
    small = 10001
    for j in range(i,0,-1):
        large = max(score[j-1],large)
        small = min(score[j-1],small)
        dp[i] = max(dp[i],dp[j-1]+large-small)
print(dp[num])