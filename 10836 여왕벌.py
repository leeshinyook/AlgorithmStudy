import sys
m,n=map(int,sys.stdin.readline().split())
larva = [[1 for i in range(0,m)] for j in range(0,m)]
grow = [0 for i in range(0, 2 * m - 1)]
for i in range(0,n):
    zero,one,two = map(int,sys.stdin.readline().split())
    count = zero
    for j in range(0,one):
        grow[count] += 1
        count +=1
    for j in range(0,two):
        grow[count] += 2
        count +=1
locationY=m-1
locationX=0
for j in grow:
    if locationY != 0:
        larva[locationY][0] += j
        locationY -=1
    else:
        larva[0][locationX] += j
        locationX += 1
for j in range(0,m):
    for k in range(0,m):
        if j==0 or k == 0:
            print(larva[j][k],end=' ')
            continue
        larva[j][k] = larva[j-1][k]
        print(larva[j][k],end=' ')
    print()