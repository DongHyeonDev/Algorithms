//
//  2292.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/13/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2292
//  알고리즘 분류: 수학

class BOJ2292: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 327B
    func run() {
        // N 입력 받기
        if let N = Int(readLine() ?? "0") {
            var layer = 1  // 현재 층(반지름 크기)
            var maxNumber = 1 // 현재 층의 최대 숫자
            
            while maxNumber < N {
                maxNumber += 6 * layer  // 다음 층의 최대 숫자 계산
                layer += 1
            }
            
            print(layer)
        }
    }
}
