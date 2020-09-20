#ctci_palindrome.py
"""
면접문제 1.4 회문 순열
주어진 문자열이 회문(palindrome)의 순열인지 아닌지 확인하는 함수를 작성하라.
회문이란 앞으로 읽으나 뒤로 읽으나 같은 단어 혹은 구절을 의미하며, 
순열이란 문자열을 재배치하는 것을 뜻한다.
"""

def palindrome(phrase):
    answer = [0]*26
    for i in phrase.lower():
        if i.isalpha():
            answer[ord(i)-ord('a')] ^= 1
    return sum(answer)<=1

print(palindrome("Tact Coa"))

#O(n)
