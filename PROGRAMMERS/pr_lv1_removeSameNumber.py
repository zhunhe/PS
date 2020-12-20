#removeSameNumber.py

def removeSameNumber(arr):
    answer = []
    for i in arr:
        if i in answer[-1:]: continue
        answer.append(i)

    return answer

print(removeSameNumber([1,1,2,2,3,3,4,4,1,1]))
