//
//  2805.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2805
//  알고리즘 분류: 이분 탐색, 매개 변수 탐색

class BOJ2805: Solvable {
    // 메모리: 114840KB, 시간: 160ms, 코드 길이: 952B
    func run() {
        // 높이 h로 잘랐을 때 얻을 수 있는 나무의 총 길이 계산
        func getCutWood(_ trees: [Int], _ height: Int) -> Int64 {
            var totalWood: Int64 = 0
            for tree in trees {
                if tree > height {
                    totalWood += Int64(tree - height)
                }
            }
            return totalWood
        }

        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        let n = fileIO.readInt() // 나무의 수
        let m = fileIO.readInt() // 필요한 나무의 길이

        var trees: [Int] = []
        var maxHeight = 0

        // N개의 나무 높이 입력
        for _ in 0..<n {
            let height = fileIO.readInt()
            trees.append(height)
            maxHeight = max(maxHeight, height)
        }

        // 이분 탐색으로 최대 높이 찾기
        var left = 0
        var right = maxHeight
        var answer = 0

        while left <= right {
            let mid = (left + right) / 2
            let cutWood = getCutWood(trees, mid)
            
            if cutWood >= m {
                // M 이상의 나무를 얻을 수 있다면, 더 높은 높이도 시도해볼 수 있음
                answer = mid
                left = mid + 1
            } else {
                // M만큼 얻을 수 없다면, 더 낮은 높이로 시도
                right = mid - 1
            }
        }

        print(answer)
    }
}
