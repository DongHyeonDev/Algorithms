//
//  12015.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/12015
//  알고리즘 분류: 이분 탐색, 가장 긴 증가하는 부분 수열 문제

class BOJ12015: Solvable {
    // 메모리: 110824KB, 시간: 200ms, 코드 길이: 606B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        // 꼬리 배열: 길이가 k인 증가 부분 수열의 최소 마지막 값 저장
        var lis: [Int] = []

        for _ in 0..<n {
            let x = fileIO.readInt()
            if lis.isEmpty || lis.last! < x {
                lis.append(x)
            } else {
                // 이분 탐색으로 교체할 위치 찾기
                var left = 0, right = lis.count - 1
                while left < right {
                    let mid = (left + right) / 2
                    if lis[mid] < x {
                        left = mid + 1
                    } else {
                        right = mid
                    }
                }
                lis[left] = x
            }
        }

        // 결과 출력: LIS의 길이
        print(lis.count)
    }
}
