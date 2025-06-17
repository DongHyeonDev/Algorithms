//
//  1920.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1920
//  알고리즘 분류: 자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵

class BOJ1920: Solvable {
    // 메모리: 84936KB, 시간: 112ms, 코드 길이: 808B
    func run() {
        // 이분 탐색 함수
        func binarySearch(_ arr: [Int], _ target: Int) -> Bool {
            var left = 0
            var right = arr.count - 1
            
            while left <= right {
                let mid = (left + right) / 2
                
                if arr[mid] == target {
                    return true
                } else if arr[mid] < target {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
            }
            
            return false
        }

        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // N개의 정수 입력받기
        let n = fileIO.readInt()
        var numbers: [Int] = []

        for _ in 0..<n {
            numbers.append(fileIO.readInt())
        }

        // 배열 정렬 (이분 탐색을 위해 필수)
        numbers.sort()

        // M개의 쿼리 처리
        let m = fileIO.readInt()

        for _ in 0..<m {
            let query = fileIO.readInt()
            
            if binarySearch(numbers, query) {
                print(1)
            } else {
                print(0)
            }
        }
    }
}
