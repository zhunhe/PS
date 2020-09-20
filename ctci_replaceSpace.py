# ctci_replaceSpace.py
"""
면접문제 1.3 URL화
문자열에 들어 있는 모든 공백을 '%20'으로 바꿔 주는 메서드를 작성하라.
"""

def replaceSpace(s):
    return ''.join([i.replace(' ', '%s20') if i==' ' else i for i in s])

print(replaceSpace("Mr John Smith"))

#예상시간복잡도 O(n) for loop
