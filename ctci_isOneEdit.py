#ctci_isOneEdit.py
"""
면접문제 1.5 하나빼기
문자열을 편집하는 방법에는 세 가지 종류가 있다.
문자 삽입, 문자 삭제, 문자 교체.
문자열 두 개가 주어졌을 때, 문자열을 같게 만들기 위한 편집 횟수가
1회 이내인지 확인하는 함수를 작성하라.
ex)
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false
"""

def isOneEdit(s, t):
    # 주어진 문자열의 길이차이가 1초과면 False
    if abs(len(s)-len(t))>1: return False
    s_set=set(s)
    t_set=set(t)
    gyo = s_set&t_set
    #각 집합과 교집합의 개수차이가 2미만이면 True
    return len(s_set)-len(gyo)<2 and len(t_set)-len(gyo)<2

print(isOneEdit("pale", "ple"))
print(isOneEdit("pales", "pale"))
print(isOneEdit("pale", "bale"))
print(isOneEdit("pale", "bake"))
