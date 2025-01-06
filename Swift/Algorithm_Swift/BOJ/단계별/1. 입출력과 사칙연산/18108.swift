//
//  18108.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/18108
//  알고리즘 분류: 수학, 사칙연산

class BOJ18108: Solvable {
    // 메모리: 79504KB, 시간: 8ms, 코드 길이: 123B
    func run() {
        // 입력 받기
        if let input = readLine(), let buddhistYear = Int(input) {
            // 불기 연도를 서기 연도로 변환
            let gregorianYear = buddhistYear - 543
            
            // 결과 출력
            print(gregorianYear)
        }
    }
}
