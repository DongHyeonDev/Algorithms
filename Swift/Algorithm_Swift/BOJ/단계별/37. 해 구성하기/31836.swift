//
//  31836.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/7/26.
//

//  문제 링크: https://www.acmicpc.net/problem/31836
//  알고리즘 분류: 수학, 애드 혹, 해 구성하기

class BOJ31836: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 596B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let N = io.readInt()

        var A: [Int] = []
        var B: [Int] = []

        switch N % 3 {
        case 0:
            for i in 1...N {
                if i % 3 == 0 { B.append(i) }
                else { A.append(i) }
            }

        case 1:
            // N은 사용하지 않음
            for i in 1..<N {
                if i % 3 == 0 { B.append(i) }
                else { A.append(i) }
            }

        default: // N % 3 == 2
            for i in 1...N {
                if i % 3 == 2 { B.append(i) }
                else { A.append(i) }
            }
        }

        print(A.count)
        print(A.map(String.init).joined(separator: " "))
        print(B.count)
        print(B.map(String.init).joined(separator: " "))
    }
}
