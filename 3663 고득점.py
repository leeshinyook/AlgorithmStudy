import sys
n = int(sys.stdin.readline())
for i in range(n):
    str = list(sys.stdin.readline())
    alpa=0
    for i in range(len(str)-1):
        alpa += min((ord(str[i]) - ord("A")),(ord("Z")-ord(str[i])+1))
    Acount = 0
    location = len(str)-1
    for i in range(2):
        for j in range(len(str)-1):
            k = j+1
            while k!=j and str[k] == 'A':
                location = min(location,j+((len(str)-1+j-k)%(len(str)-1)))
                k = (k+1)%(len(str)-1)
        str.reverse()
    if alpa+location ==0:
        print(0)
        continue
    print(location+alpa-1)

