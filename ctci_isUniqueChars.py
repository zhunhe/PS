#isUniqueChars.py
"""
면접문제 1.1 중복이 없는가
문자열이 주어졌을 때, 이 문자열에 같은 문자가 중복되어 등장하는지 확인하는 알고리즘을 작성하라.
"""

def isUniqueChars(string):
    if len(string)>256: return False
    listS = sorted(string)
    for i in range(len(listS)-1):
        if listS[i] == listS[-2:-1]: return False
        elif listS[i] == listS[i+1]: return False
    return True
    
print(isUniqueChars('A Twosome place'))

#예상시간복잡도 O(nlogn), sorted
