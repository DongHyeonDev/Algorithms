//
//  1300.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1300
//  알고리즘 분류: 이분 탐색, 매개 변수 탐색

class BOJ1300: Solvable {
    // 메모리: 79508KB, 시간: 24ms, 코드 길이: 631B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        let N = fileIO.readInt()
        let k = fileIO.readInt()

        // 주어진 값 x보다 작거나 같은 수의 개수를 세는 함수
        func countLessOrEqual(_ x: Int) -> Int {
            var count = 0
            
            for i in 1...N {
                // i행에서 x보다 작거나 같은 수의 개수는 min(x/i, N)개
                count += min(x / i, N)
            }
            
            return count
        }

        // 이분 탐색으로 k번째 수 찾기
        var left = 1
        var right = N * N
        var answer = 0

        while left <= right {
            let mid = (left + right) / 2
            
            let count = countLessOrEqual(mid)
            
            if count >= k {
                answer = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }

        print(answer)
    }
}
