//
//  1806.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1806
//  알고리즘 분류: 누적 합, 두 포인터

class BOJ1806: Solvable {
    // 메모리: 80772KB, 시간: 20ms, 코드 길이: 603B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 받기
        let N = fileIO.readInt()
        let S = fileIO.readInt()
        var A = [Int](repeating: 0, count: N)
        for i in 0..<N {
            A[i] = fileIO.readInt()
        }

        // 투 포인터(슬라이딩 윈도우)로 최소 길이 탐색
        var minLen = N + 1
        var sum = 0
        var left = 0

        for right in 0..<N {
            sum += A[right]
            // 현재 [left...right] 합이 S 이상인 구간이 되면
            while sum >= S {
                // 길이 갱신
                let len = right - left + 1
                if len < minLen { minLen = len }
                // left 한 칸 옮기며 구간 축소
                sum -= A[left]
                left += 1
            }
        }

        // 출력: 불가능하면 0
        print(minLen == N+1 ? 0 : minLen)
    }
}
