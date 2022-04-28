n, k = map(int,input().split())
num = int(input())

dp = [[0] * 55] * 10

def calc(num, kRemain):
    if(kRemain == 0):
        return num
    
    res = 0
    for i in range(kRemain, len(str(num))):
        res = max(res, calc(int(str(num)[:i]), kRemain-1) * int(str(num)[i:]))
    return res

ans = 0
for i in range(k, len(str(num))):
    ans = max(ans, int(str(num)[i:]) * calc(int(str(num)[:i]), k-1))

print(ans)
