#ctci_5.4_nextNumber.py

"""
연습문제 5.4 다음 숫자
양의 정수가 하나 주어졌다.
이 숫자를 2진수로 표기했을 때 1비트의 개수가 같은 숫자 중에서
가장 작은 수와 가장 큰 수를 구하라.
"""

def nextNumber(N):
    lenN = len(bin(N)[2:])
    numOf1 = list(bin(N)[2:]).count('1')
    maxN = '1'*numOf1 + '0'*(lenN-numOf1)
    minN = '0'*(lenN-numOf1) + '1'*numOf1

nextNumber(189)
