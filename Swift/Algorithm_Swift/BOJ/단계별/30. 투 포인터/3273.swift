//
//  3273.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/3273
//  알고리즘 분류: 정렬, 두 포인터

class BOJ3273: Solvable {
    // 메모리: 81272KB, 시간: 20ms, 코드 길이: 529B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        var arr = [Int](repeating: 0, count: n)
        for i in 0..<n {
            arr[i] = fileIO.readInt()
        }
        let x = fileIO.readInt()

        // 정렬 (두 포인터를 위해)
        arr.sort()

        // 두 포인터로 쌍 개수 세기
        var left = 0
        var right = n - 1
        var count = 0

        while left < right {
            let sum = arr[left] + arr[right]
            if sum == x {
                count += 1
                left += 1
                right -= 1
            } else if sum < x {
                left += 1
            } else {
                right -= 1
            }
        }

        // 결과 출력
        print(count)
    }
}
