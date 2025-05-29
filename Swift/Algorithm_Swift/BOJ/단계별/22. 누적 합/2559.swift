//
//  2559.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/29/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2559
//  알고리즘 분류: 누적 합, 두 포인터, 슬라이딩 윈도우

class BOJ2559: Solvable {
    // 메모리: 80632KB, 시간: 16ms, 코드 길이: 538B
    func run() {
        let fileIO = RhynoFileIO()

        // 입력 처리
        let n = fileIO.readInt()   // 전체 날짜 수
        let k = fileIO.readInt()   // 연속합을 구할 일수

        // 수열 읽기
        var temps = [Int](repeating: 0, count: n)
        for i in 0..<n {
            temps[i] = fileIO.readInt()
        }

        // 첫 윈도우 합 계산
        var windowSum = 0
        for i in 0..<k {
            windowSum += temps[i]
        }
        var maxSum = windowSum

        // 슬라이딩 윈도우: 한 칸씩 밀면서 앞에 뺀 값 빼고 뒤에 더하기
        for i in k..<n {
            windowSum += temps[i]
            windowSum -= temps[i - k]
            if windowSum > maxSum {
                maxSum = windowSum
            }
        }

        // 결과 출력
        print(maxSum)
    }
}
