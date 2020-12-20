import re

def newsClusttering(str1, str2):
    # 소문자처리, 2자리씩 끊기
    str1_=[str1[i:i+2].lower() for i in range(len(str1)-1)]
    str2_=[str2[i:i+2].lower() for i in range(len(str2)-1)]
    # 알파벳아닌 것 삭제
    str1__=[i for i in str1_ if re.match('[a-z][a-z]', i)]
    str2__=[i for i in str2_ if re.match('[a-z][a-z]', i)]
    # 교집합, 합집합 구하기
    interaction = set(str1__) & set(str2__)
    union = set(str1__) | set(str2__)

    # 합집합이 없을 경우 65536 리턴
    if len(union) == 0:
        return 65536
    # 교집합, 합집합 개수 구하기
    interaction_sum = sum([min(str1__.count(gg), str2__.count(gg)) for gg in interaction])
    union_sum = sum([max(str1__.count(hh), str2__.count(hh)) for hh in union])

    return int(interaction_sum/union_sum*65536)

print(newsClusttering("aa1+aa2", "AAAA12"))
