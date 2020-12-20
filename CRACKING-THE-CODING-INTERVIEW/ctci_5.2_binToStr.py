#ctci_5.2_binToStr.py

"""
연습문제 5.2 2진수를 문자열로
0.72와 같이 0과 1사이의 실수가 double 타입으로 주어졌을 때,
그 값을 2진수 형태로 출력하는 코드를 작성하라.
길이가 32이하인 문자열로 2진수로 정확하게 표현할 수 없다면
ERROR를 출력하라.
"""

def binToStr(N):
    answer = "0."
    """
    부동소수점연산시 오차를 없애기 위해 소수점아래 길이를 구한다.
    10진수에서 2진수 변환시 N에 x2를 반복하기에 while문 안에서
    Nlen을 넘어가는 경우의수는 없다.
    """
    Nlen = len(str(N))-2
    Ntemp = N
    while True:
        if len(answer) >= 32:
            return "ERROR"
        Ntemp = round(Ntemp*2, Nlen)
        if Ntemp>=1.0:
            answer += '1'
            Ntemp -= 1.0
        else:
            answer += '0'

        if Ntemp == 0.0:    
            return answer
         
print(binToStr(0.72))        
