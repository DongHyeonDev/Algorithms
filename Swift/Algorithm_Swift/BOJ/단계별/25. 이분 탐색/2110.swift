//
//  2110.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2110
//  알고리즘 분류: 이분 탐색, 매개 변수 탐색

class BOJ2110: Solvable {
    // 메모리: 87624KB, 시간: 36ms, 코드 길이: 1097B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        let N = fileIO.readInt() // 집의 개수
        let C = fileIO.readInt() // 공유기의 개수

        var houses = [Int]()
        for _ in 0..<N {
            houses.append(fileIO.readInt())
        }

        // 집들을 좌표 순으로 정렬
        houses.sort()

        // 주어진 거리로 공유기 C개를 설치할 수 있는지 확인하는 함수
        func canInstall(distance: Int) -> Bool {
            var count = 1 // 첫 번째 집에는 항상 공유기 설치
            var lastInstalled = houses[0] // 마지막으로 공유기를 설치한 집의 좌표
            
            for i in 1..<N {
                // 현재 집과 마지막으로 설치한 집 사이의 거리가 distance 이상이면 설치
                if houses[i] - lastInstalled >= distance {
                    count += 1
                    lastInstalled = houses[i]
                    
                    // 이미 C개를 설치했다면 성공
                    if count >= C {
                        return true
                    }
                }
            }
            
            return false
        }

        // 이분 탐색으로 최대 거리 찾기
        var left = 1 // 최소 거리
        var right = houses[N-1] - houses[0] // 최대 가능한 거리
        var answer = 0

        while left <= right {
            let mid = (left + right) / 2
            
            if canInstall(distance: mid) {
                answer = mid
                left = mid + 1 // 더 큰 거리로 시도
            } else {
                right = mid - 1 // 더 작은 거리로 시도
            }
        }

        print(answer)
    }
}
