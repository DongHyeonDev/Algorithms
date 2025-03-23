//
//  7785.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/23/25.
//

//  문제 링크: https://www.acmicpc.net/problem/7785
//  알고리즘 분류: 자료 구조, 해시를 사용한 집합과 맵

class BOJ7785: Solvable {
    // 메모리: 86008KB, 시간: 200ms, 코드 길이: 685B
    func run() {
        // 출입 기록 수 입력
        if let n = Int(readLine() ?? "0") {
            var employeeSet = Set<String>()

            for _ in 0..<n {
                if let input = readLine()?.split(separator: " "), input.count == 2 {
                    let name = String(input[0])
                    let action = input[1]

                    if action == "enter" {
                        employeeSet.insert(name)
                    } else if action == "leave" {
                        employeeSet.remove(name)
                    }
                }
            }

            // 현재 회사에 있는 사람을 사전 역순으로 정렬하여 출력
            let sortedEmployees = employeeSet.sorted(by: >)
            for employee in sortedEmployees {
                print(employee)
            }
        }
    }
}
