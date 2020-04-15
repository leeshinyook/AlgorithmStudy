import sys
t,w = map(int,sys.stdin.readline().split())
tree = []
dp = [[0 for j in range(w+1)] for i in range(t)]
result = 0
for i in range(0,t):
    tree.append(int(sys.stdin.readline()))
for i in range(w+1):
    if tree[0]%2 != i%2:
        dp[0][i] = 1
for i in range(1,t):
    if tree[i] == 1:
        dp[i][0] = dp[i-1][0] +1
    else:
        dp[i][0] = dp[i-1][0]
    for j in range(1,w+1):
        if tree[i] ==1 and j%2 == 0:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+1
        elif tree[i] == 2 and j%2 ==1:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+1
        else:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])
for i in dp[t-1]:
    result = max(result,i)
print(dp)
print(result)