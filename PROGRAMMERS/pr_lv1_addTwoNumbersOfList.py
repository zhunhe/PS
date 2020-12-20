#pr_lv1_addTwoNumbersOfList.py

def addTwoNumbersOfList(numbers):
    answer = []
    temp = 0
    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            temp = numbers[i]+numbers[j]
            if temp not in answer:
                answer.append(temp)
    return sorted(answer)

print(addTwoNumbersOfList([2,1,3,4,1]))
