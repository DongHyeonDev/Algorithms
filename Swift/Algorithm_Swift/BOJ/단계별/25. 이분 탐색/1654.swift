//
//  1654.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1654
//  알고리즘 분류: 이분 탐색, 매개 변수 탐색

class BOJ1654: Solvable {
    // 메모리: 79716KB, 시간: 12ms, 코드 길이: 770B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        // K: 이미 가진 랜선 개수, N: 필요한 랜선 개수
        let K = fileIO.readInt()
        let N = fileIO.readInt()

        // 기존 랜선 길이들을 읽어 들이고, 최댓값을 기록
        var lengths = [Int]()
        lengths.reserveCapacity(K)
        var maxLen = 0
        for _ in 0..<K {
            let l = fileIO.readInt()
            lengths.append(l)
            if l > maxLen { maxLen = l }
        }

        // 이분 탐색으로 가능한 최대 랜선 길이 찾기
        var left = 1
        var right = maxLen
        var answer = 0

        while left <= right {
            let mid = (left + right) / 2
            // mid 길이로 자를 때 나오는 랜선 개수 세기
            var count = 0
            for l in lengths {
                count += l / mid
            }
            if count >= N {
                // N개 이상 만들 수 있으면 길이를 늘려본다
                answer = mid
                left = mid + 1
            } else {
                // N개 못 만들면 길이를 줄인다
                right = mid - 1
            }
        }

        // 정답 출력
        print(answer)
    }
}
