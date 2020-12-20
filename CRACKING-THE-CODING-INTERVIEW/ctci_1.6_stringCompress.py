#stringCompress.py
"""
면접문제 1.6 문자열압축
반복되는 문자의 개수를 세는 바식의 기본적인 문자열 압축 메서드를 작성하라.
예를 들어 문자열 aabccccaaa를 압축하면 a2b1c4a3이 된다.
만약 '압축된' 문자열의 길이가 기존 문자열의 길이보다 길다면 기존 문자열을 반환해야 한다.
문자열은 대소문자 알파벳(a~z)으로만 이루어져 있다.
"""

def stringCompress(s):
    answer = ''
    count = 0
    for i in s:
        if not answer:
            answer += i
            count += 1
        elif i == answer[-1]:  #
            count += 1
        else:
            answer += str(count) + i
            count = 1
    answer += str(count)
    if len(answer) > len(s): return s
    return answer
            
print(stringCompress("aabccccaaa"))
