import sys
t = int(sys.stdin.readline())
arr = [[[0,0] for i in range(101)] for i in range(101)];
arr[1][0][0] = 1
arr[1][0][1] = 1

for i in range(2,101):
    for j in range(0,101):
        arr[i][j][0] = arr[i-1][j][0] + arr[i-1][j][1]
        arr[i][j][1] = arr[i-1][j][0] + arr[i-1][j-1][1]
for i in range(t):
    n,k = map(int,sys.stdin.readline().split())
    print(arr[n][k][0]+arr[n][k][1])