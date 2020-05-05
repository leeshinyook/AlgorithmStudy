import sys
global large
large = 0
def find_max(energy,sum):
    global large
    for i in range(1,len(energy)-1):
        sum += energy[i-1]*energy[i+1]
        save = energy[i]
        del energy[i]
        find_max(energy,sum)
        energy.insert(i,save)
        sum -= energy[i-1]*energy[i+1]
    if len(energy) == 2:
        large = max(large,sum)

num = int(sys.stdin.readline())
energy = list(map(int,sys.stdin.readline().split()))
find_max(energy,0)
print(large)