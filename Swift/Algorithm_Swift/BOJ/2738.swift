//
//  2738.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/25/24.
//

//  문제 링크: https://www.acmicpc.net/problem/2738
//  알고리즘 분류: 사칙연산, 구현, 수학

class BOJ2738: Solvable {
    func run() {
        // 첫 번째 줄: 행렬의 크기 N, M 입력받기
        if let firstLine = readLine() {
            let dimensions = firstLine.split(separator: " ").compactMap { Int($0) }
            if dimensions.count == 2 {
                let n = dimensions[0]
                let m = dimensions[1]
                
                // 조건 확인: N, M이 1 이상 100 이하
                if n >= 1 && n <= 100 && m >= 1 && m <= 100 {
                    var matrixA = [[Int]]()
                    var matrixB = [[Int]]()
                    
                    // 행렬 A 입력받기
                    for _ in 0..<n {
                        if let row = readLine() {
                            let values = row.split(separator: " ").compactMap { Int($0) }
                            if values.count == m {
                                matrixA.append(values)
                            }
                        }
                    }
                    
                    // 행렬 B 입력받기
                    for _ in 0..<n {
                        if let row = readLine() {
                            let values = row.split(separator: " ").compactMap { Int($0) }
                            if values.count == m {
                                matrixB.append(values)
                            }
                        }
                    }
                    
                    // 결과 행렬 계산
                    var resultMatrix = [[Int]]()
                    for i in 0..<n {
                        var row = [Int]()
                        for j in 0..<m {
                            row.append(matrixA[i][j] + matrixB[i][j])
                        }
                        resultMatrix.append(row)
                    }
                    
                    // 결과 출력
                    for row in resultMatrix {
                        print(row.map { String($0) }.joined(separator: " "))
                    }
                } else {
                    print("N과 M은 1 이상 100 이하의 값이어야 합니다.")
                }
            } else {
                print("행렬의 크기 입력이 잘못되었습니다.")
            }
        }
    }
}
