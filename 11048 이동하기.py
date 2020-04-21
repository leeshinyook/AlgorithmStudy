import sys
n,m = map(int,sys.stdin.readline().split())
arr = [list(map(int,sys.stdin.readline().split())) for i in range(n)]
dp = [[0 for i in range(m)] for j in range(n)]
dp[0][0] = arr[0][0]
for i in range(n):
    for j in range(m):
        if i == 0 and j == 0:
            dp[i][j]  = arr[i][j]
        elif i == 0:
            dp[i][j] = dp[i][j-1] + arr[i][j]
        elif j == 0:
            dp[i][j] = dp[i-1][j] + arr[i][j]
        else:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + arr[i][j]
print(dp[n-1][m-1])