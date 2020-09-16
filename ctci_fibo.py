#ctci_fibo.py
"""
메모이제이션을 이용한 피보나치 구하기
"""

# 재귀함수의 시간복잡도는 지수시간이 걸리므로
# 효율을 올리기위해 매번 계산하지 않고 저장, 불러오는 방식으로 설계한다
memo = {}
def fibo(n):
    if n<=1:
        memo[n]=n
    elif n not in memo:
        memo[n] = fibo(n-2) + fibo(n-1)
    return memo[n]

# n-1번째 피보나치 수 구하기
print(fibo(5))
