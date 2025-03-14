//
//  10989.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10989
//  알고리즘 분류: 정렬

class BOJ10989: Solvable {
    // 메모리: 214760KB, 시간: 3844ms, 코드 길이: 579B
    func run() {
        // 입력 받기
        if let n = Int(readLine() ?? "0") {
            var countArray = Array(repeating: 0, count: 10_001)

            // 숫자 개수 카운트
            for _ in 0..<n {
                if let num = Int(readLine() ?? "0") {
                    countArray[num] += 1
                }
            }

            // 출력 최적화를 위해 문자열에 결과 저장
            var result = ""

            for i in 0..<countArray.count {
                if countArray[i] > 0 {
                    result += String(repeating: "\(i)\n", count: countArray[i])
                }
            }

            // 한 번에 출력하여 시간 단축
            print(result)
        }
    }
}
