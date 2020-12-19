#pr_lv2_fibo.py

def fibo(n):
    fiboList = [0 for x in range(n+1)]
    fiboList[1] = 1
    for i in range(2, n+1):
        fiboList[i] = (fiboList[i-2] + fiboList[i-1]) % 1234567
    return fiboList[i]

print(fibo(10000))
