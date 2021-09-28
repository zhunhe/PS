#pr_lv1_2016.py

def solution(a, b):
    month = [0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
    day = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"]

    return day[(month[a]+b)%7]

print(solution(5, 24))
