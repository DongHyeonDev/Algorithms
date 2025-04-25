//
//  2108.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/25/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2108
//  알고리즘 분류: 수학, 구현, 정렬

class BOJ2108: Solvable {
    // 메모리: 79508KB, 시간: 192ms, 코드 길이: 1310B
    func run() {
        // 1. 입력 처리
        guard let nLine = readLine(),
              let N = Int(nLine) else {
            fatalError("입력 오류")
        }

        // -4000…4000을 0…8000 인덱스로 매핑하는 카운팅 배열
        var counts = [Int](repeating: 0, count: 8001)
        var sum = 0
        var minVal = 4000, maxVal = -4000

        // 2. 빈도수 계산 및 합·범위 수집
        for _ in 0..<N {
            guard let xLine = readLine(),
                  let x = Int(xLine) else {
                fatalError("입력 오류")
            }
            sum += x
            counts[x + 4000] += 1
            if x < minVal { minVal = x }
            if x > maxVal { maxVal = x }
        }

        // 3. 산술평균 (소수 첫째 자리에서 반올림)
        let mean = Int((Double(sum) / Double(N)).rounded())

        // 4. 중앙값 계산
        let midIndex = (N + 1) / 2
        var cumulative = 0
        var median = 0
        for i in 0..<counts.count {
            cumulative += counts[i]
            if cumulative >= midIndex {
                median = i - 4000
                break
            }
        }

        // 5. 최빈값 계산
        guard let maxFreq = counts.max() else {
            fatalError("빈도 배열이 비어 있습니다")
        }
        var modes = [Int]()
        for i in 0..<counts.count where counts[i] == maxFreq {
            modes.append(i - 4000)
        }
        let mode = (modes.count > 1) ? modes[1] : modes[0]

        // 6. 범위 계산
        let range = maxVal - minVal

        // 7. 결과 출력
        print(mean)
        print(median)
        print(mode)
        print(range)

    }
}
