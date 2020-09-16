# pr_lv1_stringSortByIndex.py
"""
리스트 안에 있는 문자열을 n번째 인덱스에 있는 문자를 기준으로 오름차순 정렬한다.
n번째 인덱스에 있는 문자가 같을 경우에는 문자열 전체를 기준으로 오름차순 정렬한다.
"""

def stringSortByIndex(strings, n):
    #-x[n]으로 할 시에는 내림차순으로 정렬한다.
    return sorted(sorted(strings), key=lambda x:x[n])

if __name__ == "__main__":
    input1 = [["sun", "bed", "car"], ["abce", "abcd", "cdx"]]
    input2 = [1, 2]
    input3 = [["car", "bed", "sun"], ["abcd", "abce", "cdx"]]

    for i in range(len(input1)):
        a = stringSortByIndex(input1[i], input2[i])
        print(a)    
        if a == input3[i]:  print("정답")
        else:               print("오답")
