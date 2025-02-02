//
//  1157.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1157
//  알고리즘 분류: 구현, 문자열

class BOJ1157: Solvable {
    // 메모리: 81516KB, 시간: 100ms, 코드 길이: 688B
    func run() {
        // 입력 받기
        if let input = readLine() {
            let uppercasedInput = input.uppercased() // 대문자로 변환
            var frequency = [Character: Int]() // 빈도수를 저장할 딕셔너리
            
            // 문자별 등장 횟수 계산
            for char in uppercasedInput {
                frequency[char, default: 0] += 1
            }
            
            // 가장 많이 등장한 문자의 개수 찾기
            if let maxCount = frequency.values.max() {
                let maxChars = frequency.filter { $0.value == maxCount }.keys
                
                // 가장 많이 사용된 문자가 여러 개이면 '?', 아니면 그 문자 출력
                print(maxChars.count > 1 ? "?" : String(maxChars.first!))
            }
        }
    }
}
