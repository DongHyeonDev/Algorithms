//
//  1735.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/31/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1735
//  알고리즘 분류: 수학, 정수론, 유클리드 호제법

class BOJ1735: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 1408B
    func run() {
        // 최대공약수(GCD)를 구하는 함수 (유클리드 호제법)
        func gcd(_ a: Int, _ b: Int) -> Int {
            var num1 = a
            var num2 = b
            while num2 != 0 {
                let temp = num2
                num2 = num1 % num2
                num1 = temp
            }
            return num1
        }

        // 첫 번째 분수 입력 받기 (분자, 분모)
        if let firstFractionLine = readLine()?.split(separator: " ").compactMap({ Int($0) }), firstFractionLine.count == 2 {
            let numerator1 = firstFractionLine[0]
            let denominator1 = firstFractionLine[1]

            // 두 번째 분수 입력 받기 (분자, 분모)
            if let secondFractionLine = readLine()?.split(separator: " ").compactMap({ Int($0) }), secondFractionLine.count == 2 {
                let numerator2 = secondFractionLine[0]
                let denominator2 = secondFractionLine[1]

                // 분수 합 계산 (통분하여 더하기)
                let sumNumerator = (numerator1 * denominator2) + (numerator2 * denominator1)
                let sumDenominator = denominator1 * denominator2

                // 최대공약수를 이용한 약분
                let commonDivisor = gcd(sumNumerator, sumDenominator)

                // 기약분수로 변환
                let reducedNumerator = sumNumerator / commonDivisor
                let reducedDenominator = sumDenominator / commonDivisor

                // 결과 출력
                print("\(reducedNumerator) \(reducedDenominator)")
            }
        }
    }
}
