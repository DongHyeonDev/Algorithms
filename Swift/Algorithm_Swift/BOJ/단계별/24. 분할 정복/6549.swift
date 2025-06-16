//
//  6549.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/16/25.
//

//  문제 링크: https://www.acmicpc.net/problem/6549
//  알고리즘 분류: 자료 구조, 세그먼트 트리, 분할 정복, 스택

class BOJ6549: Solvable {
    // 메모리: 85896KB, 시간: 36ms, 코드 길이: 908B
    func run() {
        func largestRectangleArea(_ heights: [Int]) -> Int {
            var stack: [Int] = [] // 인덱스를 저장하는 스택
            var maxArea = 0
            let heights = heights + [0] // 마지막에 0을 추가해서 모든 막대를 처리하도록 함
            
            for i in 0..<heights.count {
                // 현재 높이가 스택 top의 높이보다 작으면
                // 스택에서 더 높은 막대들을 pop하면서 넓이 계산
                while !stack.isEmpty && heights[i] < heights[stack.last!] {
                    let height = heights[stack.removeLast()]
                    let width = stack.isEmpty ? i : i - stack.last! - 1
                    maxArea = max(maxArea, height * width)
                }
                stack.append(i)
            }
            
            return maxArea
        }
        
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        
        while true {
            let n = fileIO.readInt()
            
            if n == 0 {
                break
            }
            
            var heights: [Int] = []
            for _ in 0..<n {
                heights.append(fileIO.readInt())
            }
            
            let result = largestRectangleArea(heights)
            print(result)
        }
    }
}
