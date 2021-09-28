#ctci_fibo.py
"""
메모이제이션을 이용한 피보나치 구하기
"""

# 재귀함수 이용
def fibo(n):
    if n<=0:
        return 0
    elif n==1:
        return 1
    return fibo(n-2)+fibo(n-1)

# 재귀함수 및 메모이제이션 이용
memo = {}
def fibo_memoi(n):
    if n<=1:
        memo[n]=n
    elif n not in memo:
        memo[n] = fibo_memoi(n-2) + fibo_memoi(n-1)
    return memo[n]

from timeit import *
t1 = Timer("fibo_memoi(40)", "from __main__ import fibo_memoi")
t2 = Timer("fibo(40)", "from __main__ import fibo")
print("fibo_memoi(40): ", t1.timeit(number=1),"seconds")
print("fibo(40): ", t2.timeit(number=1),"seconds")

#시간비교
#fibo_memoi(40):  3.895699999999919e-05 seconds
#fibo(40):  51.378306183 seconds
