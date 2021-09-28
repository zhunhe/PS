#reverseString.py
"""
주어진 문자열을 내림차순 정렬하기. A-Za-z순으로 커진다.
제한사항: 문자열의 길이는 1이상이다.
"""

def reverseString(string):
    return ''.join(sorted(string, reverse=False))

if __name__ == "__main__":
    input1 = ["Zbcdefg"]
    answer = ["gfedcbZ"]
    for i in range(len(input1)):
        result = reverseString(input1)
        print(result)
        if result == answer:    print("정답")
        else:                   print("오답")
