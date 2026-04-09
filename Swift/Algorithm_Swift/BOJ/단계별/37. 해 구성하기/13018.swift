//
//  13018.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/9/26.
//

//  문제 링크: https://www.acmicpc.net/problem/13018
//  알고리즘 분류: 수학, 애드 혹, 정수론, 해 구성하기

class BOJ13018: Solvable {
    // 메모리: 82448KB, 시간: 28ms, 코드 길이: 621B
    func run() {
        // 메인 실행
        let io = RhynoFileIO()
        let n = io.readInt(), k = io.readInt()

        if k > n-1 {
            print("Impossible")
        } else {
            var A = Array(1...n)
            var need = (n-1) - k  // 줄여야 할 기여 수

            // (1,2) 교환으로 1 감소 (홀수면 먼저 처리)
            var startPair = 2  // 다음 -2 교환 시작 위치
            if need % 2 == 1 {
                A.swapAt(0, 1)  // 위치 1,2 교환
                need -= 1
                startPair = 4   // (1,2) 교환했으므로 다음은 (4,5)부터
            }

            // -2씩 교환: (startPair, startPair+1), ...
            var pos = startPair
            while need > 0 {
                A.swapAt(pos-1, pos)
                need -= 2
                pos += 2
            }

            print(A.map{String($0)}.joined(separator: " "))
        }
    }
}
