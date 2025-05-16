//
//  1912.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/16/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1912
//  알고리즘 분류: 다이나믹 프로그래밍, 최대 부분 배열 문제

class BOJ1912: Solvable {
    // 메모리: 86520KB, 시간: 32ms, 코드 길이: 1056B
    func run() {
        // 입력 처리
        if let nInput = readLine(), let n = Int(nInput),
           let sequenceInput = readLine() {
            
            // 수열 입력 처리
            let sequence = sequenceInput.split(separator: " ").compactMap { Int($0) }
            
            // 최대 연속 부분합 계산
            let maxSum = findMaximumSubarraySum(sequence)
            
            // 결과 출력
            print(maxSum)
        }

        // 최대 연속 부분합을 찾는 함수 (Kadane's Algorithm)
        func findMaximumSubarraySum(_ array: [Int]) -> Int {
            guard !array.isEmpty else { return 0 }
            
            var maxEndingHere = array[0] // 현재 위치까지의 최대 부분합
            var maxSoFar = array[0]      // 전체 최대 부분합
            
            for i in 1..<array.count {
                // 현재 위치에서의 최대 부분합 계산
                // 이전까지의 최대 부분합 + 현재 값과 현재 값 중 큰 값을 선택
                maxEndingHere = max(array[i], maxEndingHere + array[i])
                
                // 전체 최대 부분합 갱신
                maxSoFar = max(maxSoFar, maxEndingHere)
            }
            
            return maxSoFar
        }
    }
}
