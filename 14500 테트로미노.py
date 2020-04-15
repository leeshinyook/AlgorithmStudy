import sys
n,m = map(int,sys.stdin.readline().split())
score = [list(map(int,sys.stdin.readline().split())) for i in range(n)]
block = [
    [(0,1), (1,0), (1,1)],
    [(0,1), (0,2), (0,3)],
    [(1,0), (2,0), (3,0)],
    [(0,1), (0,2), (1,0)],
    [(0,1), (0,2), (-1,2)],
    [(1,0), (1,1), (1,2)],
    [(0,1), (0,2), (1,2)],
    [(1,0), (2,0), (2,1)],
    [(0,1), (1,1), (2,1)],
    [(0,1), (1,0), (2,0)],
    [(1,0), (2,0), (2,-1)],
    [(1,0), (1,1), (2,1)],
    [(0,1), (1,0), (-1,1)],
    [(0,1), (1,0), (1,-1)],
    [(0,1), (1,1), (1,2)],
    [(0,1), (0,2), (1,1)],
    [(1,0), (1,1), (1,-1)],
    [(1,0), (2,0), (1,-1)],
    [(1,0), (1,1), (2,0)]
]
result = 0
for i in range(n):
    for j in range(m):
        for k in range(len(block)):
            sum = score[i][j]
            for l in range(3):
                try:
                    sum += score[i+block[k][l][0]][j+block[k][l][1]]
                except:
                    continue
            result = max(result,sum)
print(result)