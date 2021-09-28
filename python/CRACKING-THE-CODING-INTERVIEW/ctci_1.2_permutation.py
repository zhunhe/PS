#ctci_permutation.py
"""
면접문제 1.2 순열 확인
문자열 두 개가 주어졌을 때 이 둘이 서로 순열 관계에 있는지 확인하는 메서드를 작성하라.
"""

def permutation(s, t):
    if len(s)!=len(t): return False
    for i,j in zip(list(s), list(reversed(t))):
        if i!=j: return False
    return True

print(permutation("banana", "ananab"))

#예상시간복잡도 O(n) reversed(t), for loop
