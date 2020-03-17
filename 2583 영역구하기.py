import sys
import queue
from collections import deque
m,n,k = map(int,sys.stdin.readline().split())
arr=[[0 for col in range(n)] for row in range(m)]
visit = [[0 for col in range(n)]for row in range(m)]
for i in range(k):
    ldx,ldy,rux,ruy = map(int,sys.stdin.readline().split())
    b = ldy
    while b <= ruy-1:
        a=ldx
        while a<= rux-1:
            arr[b][a] = 1
            a+=1
        b+=1
q= deque()
i=0
result =[]
c =0
while i < m:
    j = 0
    while j < n:
        if arr[i][j]==0 and visit[i][j]==0:
            location = [i,j]
            q.append(location)
            count =1
            visit[i][j]=1
            #print(q)
            c+=1
            while len(q)!=0:
                location = q.popleft()
                y=location[0]
                x=location[1]
                if y<m-1 and arr[y+1][x] ==0 and visit[y+1][x]==0:
                    location = [y+1,x]
                    q.appendleft(location)
                    visit[y+1][x]=1
                    count +=1
                if x<n-1 and arr[y][x+1] ==0 and visit[y][x+1]==0:
                    location = [y,x+1]
                    q.appendleft(location)
                    visit[y][x+1]=1
                    count += 1
                if y>0 and arr[y-1][x] ==0 and visit[y-1][x]==0:
                    location = [y-1,x]
                    q.appendleft(location)
                    visit[y-1][x]=1
                    count +=1
                if x>0 and arr[y][x-1] ==0 and visit[y][x-1]==0:
                    location = [y,x-1]
                    q.appendleft(location)
                    visit[y][x-1]=1
                    count +=1
            result.append(count)
        j+=1
    i+=1
result.sort()
print(c)
for i in result:
    print(i,end=' ')