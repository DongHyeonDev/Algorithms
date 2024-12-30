//
//  5597.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/24/24.
//

//  문제 링크: https://www.acmicpc.net/problem/5597
//  알고리즘 분류: 구현

class BOJ5597: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 696B
    func run() {
        var submittedStudents = Set<Int>()
        
        // 28명의 제출자 출석번호 입력 받기
        for _ in 0..<28 {
            if let input = readLine(), let n = Int(input), n >= 1 && n <= 30 {
                submittedStudents.insert(n)
            } else {
                print("올바른 출석번호를 입력해주세요.")
            }
        }
        
        // 1부터 30까지의 전체 출석번호
        let allStudents = Set(1...30)
        
        // 제출하지 않은 학생 찾기
        let missingStudents = allStudents.subtracting(submittedStudents).sorted()
        
        // 결과 출력
        if missingStudents.count == 2 {
            print(missingStudents[0])
            print(missingStudents[1])
        } else {
            print("제출하지 않은 학생의 수가 올바르지 않습니다.")
        }
    }
}
