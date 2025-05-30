//
//  16139.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/30/25.
//

//  문제 링크: https://www.acmicpc.net/problem/16139
//  알고리즘 분류: 누적 합

class BOJ16139: Solvable {
    // 메모리: 91116KB, 시간: 216ms, 코드 길이: 1183B
    func run() {
        let fileIO = RhynoFileIO()

        // 원본 문자열 읽기
        let sBytes = fileIO.readByteSequenceWithoutSpaceAndLineFeed()
        let n = sBytes.count

        // 알파벳별 등장 인덱스 저장
        var positions = [[Int]](repeating: [], count: 26)
        for i in 0..<n {
            let c = Int(sBytes[i] - UInt8(ascii: "a"))
            positions[c].append(i)
        }

        // 이분 탐색 구현
        func lowerBound(_ arr: [Int], _ target: Int) -> Int {
            var lo = 0, hi = arr.count
            while lo < hi {
                let mid = (lo + hi) >> 1
                if arr[mid] < target { lo = mid + 1 }
                else { hi = mid }
            }
            return lo
        }
        func upperBound(_ arr: [Int], _ target: Int) -> Int {
            var lo = 0, hi = arr.count
            while lo < hi {
                let mid = (lo + hi) >> 1
                if arr[mid] <= target { lo = mid + 1 }
                else { hi = mid }
            }
            return lo
        }

        // 질의 처리
        let q = fileIO.readInt()
        var output = [String]()
        output.reserveCapacity(q)

        for _ in 0..<q {
            let alphaStr = fileIO.readString()
            let a = Int(alphaStr.utf8.first! - UInt8(ascii: "a"))
            let l = fileIO.readInt()
            let r = fileIO.readInt()
            let arr = positions[a]
            let cnt = upperBound(arr, r) - lowerBound(arr, l)
            output.append(String(cnt))
        }

        // 결과 출력
        print(output.joined(separator: "\n"))
    }
}
