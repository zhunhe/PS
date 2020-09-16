#numberOfPY.py
"""
주어진 문자열에서 p의 갯수, y의 갯수가 같으면 True를 다르면 False를 반환하는 함수를 만들기
단, 대소문자는 구분하지 않는다.
"""

def numberOfPY(string):
    return string.lower().count('p') == string.lower().count('y')

if __name__ == "__main__":
    input1 = ["pPoooyY", "Pyy"]
    input3 = [True, False]
    for i in range(len(input1)):
        result = numberOfPY(input1[i])
        print(result)
        if result == input3[i]: print("정답")
        else:                   print("오답")

