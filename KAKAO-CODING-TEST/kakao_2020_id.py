import re
def solution(new_id):    
    answer = re.sub('[^0-9.\-_a-z]', '', new_id.lower())
    answer = re.sub('\.+', '.', answer)
    
    if answer[0] == '.' and answer[-1] == '.':
        answer = answer[1:-1]
    elif answer[0] == '.':
        answer = answer[1:]
    elif answer[-1] == '.':
        answer = answer[:-1]
        
    if len(answer) == 0:
        answer = 'a'
    
    if len(answer) > 15:
        answer = answer[:15]
        if answer[-1] == '.':
            answer = answer[:-1]

    for i in range(2):
        if len(answer) < 3:
            answer = answer + answer[-1]

    return answer
