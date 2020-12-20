import re
def dart(dartResult):
    answer = []
    bonus = {'S':1, 'D':2, 'T':3}
    option = {'':1, '*':2, '#':-1}
    p = re.compile('(\d+)([SDT])([*#]?)')
    dart = p.findall(dartResult)
    for i in range(len(dart)):
        if dart[i][2] == '*' and i>0:
            answer[i-1] *= 2
        answer.append(int(dart[i][0]) ** bonus[dart[i][1]] * option[dart[i][2]])

    return sum(answer)

print(dart("1S2D*3T"))
