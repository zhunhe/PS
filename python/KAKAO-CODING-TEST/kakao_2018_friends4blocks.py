def friends4blocks(m, n, board):
    answer = 0
    x = board
    x2 = []
    for i in x:
        x1 = []
        for i2 in i:
            x1.append(i2)
        x2.append(x1)

    point = 1
    while point:
        bombList = []
        point = 0
        for i in range(m-1):
            for j in range(n-1):
                if x2[i][j] == x2[i][j+1] == x2[i+1][j] == x2[i+1][j+1]:
                    if x2[i][j] != '팡':
                        bombList.append([i, j])
                        point+=1
        for i2 in bombList:
            i = i2[0]
            j = i2[1]
            x2[i][j], x2[i][j+1], x2[i+1][j], x2[i+1][j+1] = '팡', '팡', '팡', '팡'
        for i3 in range(m):
            for i in range(m-1):
                for j in range(n):
                    if x2[i+1][j] == '팡':
                        x2[i][j], x2[i+1][j] = x2[i+1][j], x2[i][j]
    for i in x2:
        answer += i.count('팡')
    return answer

problem = ["CCBDE", "AAADE", "AAABF", "CCBBF"]
print(friends4blocks(4, 5, problem))
