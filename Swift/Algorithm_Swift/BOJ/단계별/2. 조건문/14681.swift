//
//  14681.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/16/24.
//

//  문제 링크: https://www.acmicpc.net/problem/14681
//  알고리즘 분류: 구현, 기하학

class BOJ14681: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 851B
    func run() {
        // x 좌표 입력 받기
        if let xInput = readLine(), let x = Int(xInput) {
            // y 좌표 입력 받기
            if let yInput = readLine(), let y = Int(yInput) {
                // 조건 확인: x ≠ 0, y ≠ 0
                if x != 0 && y != 0 {
                    // 사분면 판별
                    if x > 0 && y > 0 {
                        print(1) // 제1사분면
                    } else if x < 0 && y > 0 {
                        print(2) // 제2사분면
                    } else if x < 0 && y < 0 {
                        print(3) // 제3사분면
                    } else if x > 0 && y < 0 {
                        print(4) // 제4사분면
                    }
                } else {
                    print("x와 y는 0이 아니어야 합니다.")
                }
            } else {
                print("y 좌표를 올바르게 입력해주세요.")
            }
        } else {
            print("x 좌표를 올바르게 입력해주세요.")
        }
    }
}
