#ctci_isPrime.py
import math
def isPrime(n):
    # 반복횟수를 줄이기 위해 제곱근 사용하기
    for i in range(2, int(math.sqrt(n))):
        if n%i==0:
            return -1
        return 1

if __name__=="__main__":
    print(isPrime(9))
