#numberOfPrime.py
"""
n까지의 소수개수를 구하기
"""

def numberOfPrime(n):
    #2를 제외한 소수는 모두 홀수 이므로 3,5,7,9...를 추가
    answer = set(range(3, n+1, 2))
    for i in range(3, n+1, 2):
        if i in answer:
            answer -= set(range(i*2, n+1, i))

    return len(answer)+1
    
print(numberOfPrime(10))
