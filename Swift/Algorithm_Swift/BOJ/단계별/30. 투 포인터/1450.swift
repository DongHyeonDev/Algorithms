//
//  1450.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/29/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1450
//  알고리즘 분류: 이분 탐색, 중간에서 만나기

import Foundation

class BOJ1450: Solvable {
    // 메모리: 80808KB, 시간: 20ms, 코드 길이: 1509B
    func run() {
        // 부분집합의 모든 가능한 무게 합을 구하는 함수
        func getSubsetSums(_ weights: [Int]) -> [Int] {
            let n = weights.count
            var sums: [Int] = []
            
            // 2^n 개의 모든 부분집합 생성
            for mask in 0..<(1 << n) {
                var sum = 0
                for i in 0..<n {
                    if (mask & (1 << i)) != 0 {
                        sum += weights[i]
                    }
                }
                sums.append(sum)
            }
            
            return sums.sorted()
        }

        // 이분 탐색으로 target 이하의 원소 개수를 구하는 함수
        func upperBound(_ arr: [Int], _ target: Int) -> Int {
            var left = 0
            var right = arr.count
            
            while left < right {
                let mid = (left + right) / 2
                if arr[mid] <= target {
                    left = mid + 1
                } else {
                    right = mid
                }
            }
            
            return left
        }

        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let c = fileIO.readInt()

        var weights: [Int] = []
        for _ in 0..<n {
            weights.append(fileIO.readInt())
        }

        // 예외 처리: 무게가 0인 경우
        if n == 0 {
            print(1)
            exit(0)
        }

        // 배열을 두 부분으로 나누기
        let mid = n / 2
        let leftWeights = Array(weights[0..<mid])
        let rightWeights = Array(weights[mid..<n])

        // 각 부분의 모든 부분집합 합 구하기
        let leftSums = getSubsetSums(leftWeights)
        let rightSums = getSubsetSums(rightWeights)

        var result = 0

        // 중간에서 만나기: 왼쪽 부분집합과 오른쪽 부분집합을 조합
        for leftSum in leftSums {
            if leftSum > c { break } // 이미 용량 초과
            
            let remaining = c - leftSum
            // rightSums에서 remaining 이하인 원소의 개수를 이분 탐색으로 구함
            let count = upperBound(rightSums, remaining)
            result += count
        }

        print(result)
    }
}
