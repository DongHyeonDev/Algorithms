//
//  27866.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/31/24.
//

//  문제 링크: https://www.acmicpc.net/problem/27866
//  알고리즘 분류: 구현, 문자열

class BOJ27866: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 483B
    func run() {
        // 입력 받기
        if let s = readLine(), let iInput = readLine(), let i = Int(iInput) {
            // 조건 확인: 1 ≤ i ≤ |S|
            if i >= 1 && i <= s.count {
                // i번째 글자 출력 (Swift는 0-based index이므로 -1 필요)
                let index = s.index(s.startIndex, offsetBy: i - 1)
                print(s[index])
            } else {
                print("i의 값이 문자열의 범위를 벗어났습니다.")
            }
        } else {
            print("입력이 잘못되었습니다.")
        }
    }
}
