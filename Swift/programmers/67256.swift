/*
** [2020 카카오 인턴쉽] 키패드 누르기
** https://school.programmers.co.kr/learn/courses/30/lessons/67256?language=swift
*/

import Foundation

struct Coor {
    var y: Int
    var x: Int
    
    init(y: Int, x: Int) {
        self.y = y
        self.x = x
    }
}

func distance(next: Coor, cur: Coor) -> Int {
    return abs(next.y - cur.y) + abs(next.x - cur.x)
}

func nextCoor(n: Int) -> Coor {
    if n == 0 {
        return Coor(y: 3, x: 1)
    } else {
        return Coor(y: (n - 1) / 3, x: (n - 1) % 3)
    }
}

func nextIsLeft(n: Int, hand: String, next: Coor, leftCoor: Coor, rightCoor: Coor) -> Bool {
    if n % 3 == 1 {
        return true
    } else if n != 0 && n % 3 == 0 {
        return false
    } else {
        let leftDistance = distance(next: next, cur: leftCoor)
        let rightDistance = distance(next: next, cur: rightCoor)
        if leftDistance < rightDistance {
            return true
        } else if leftDistance > rightDistance {
            return false
        } else if hand == "left" {
            return true
        }
    }
    return false
}

func solution(_ numbers:[Int], _ hand:String) -> String {
    var answer = ""
    var leftCoor: Coor = Coor(y: 3, x: 0)
    var rightCoor: Coor = Coor(y: 3, x: 2)
    for number in numbers {
        let next = nextCoor(n: number)

        if nextIsLeft(n: number, hand: hand, next: next, leftCoor: leftCoor, rightCoor: rightCoor) {
            answer += "L"
            leftCoor = next
        } else {
            answer += "R"
            rightCoor = next
        }
    }
    return answer
}

let numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
let hand = "right"
let result = solution(numbers, hand)
let expected = "LRLLLRLLRRL"
if (result == expected) {
    print("correct!")
} else {
    print("wrong! result:", result, "expected:", expected)
}