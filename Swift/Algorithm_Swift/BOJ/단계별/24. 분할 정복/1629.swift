//
//  1629.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/11/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1629
//  알고리즘 분류: 수학, 분할 정복을 이용한 거듭제곱

class BOJ1629: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 534B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        let A = Int64(fileIO.readInt())
        let B = Int64(fileIO.readInt())
        let C = Int64(fileIO.readInt())

        // 이진 지수법으로 (A^B) % C 계산
        func modPow(_ base: Int64, _ exp: Int64, _ mod: Int64) -> Int64 {
            if exp == 0 { return 1 % mod }
            let half = modPow(base, exp / 2, mod)
            let halfSq = (half * half) % mod
            if exp & 1 == 0 {
                return halfSq
            } else {
                return (halfSq * (base % mod)) % mod
            }
        }

        let result = modPow(A, B, C)

        // 결과 출력
        print(result)
    }
}
