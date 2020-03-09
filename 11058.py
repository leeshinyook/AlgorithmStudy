dp = [0, 1, 2, 3, 4, 5, 6]
for x in range(100):
    dp.append(max(dp[-3] * 2, dp[-4] * 3, dp[-5] * 4 ))
n = int(input())
print(dp[n])