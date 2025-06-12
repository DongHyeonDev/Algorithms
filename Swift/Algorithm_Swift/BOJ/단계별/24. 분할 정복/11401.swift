//
//  11401.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/12/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11401
//  알고리즘 분류: 수학, 정수론, 조합론, 분할 정복을 이용한 거듭제곱, 모듈로 곱셈 역원, 페르마의 소정리

class BOJ11401: Solvable {
    // 메모리: 110460KB, 시간: 44ms, 코드 길이: 1107B
    func run() {
        let MOD = 1_000_000_007

        // 분할 정복을 이용한 거듭제곱 (a^b mod MOD)
        func power(_ a: Int, _ b: Int) -> Int {
            if b == 0 { return 1 }
            if b == 1 { return a % MOD }
            
            let half = power(a, b / 2)
            let result = (half * half) % MOD
            
            if b % 2 == 1 {
                return (result * a) % MOD
            } else {
                return result
            }
        }

        // 모듈러 역원 구하기 (페르마의 소정리 이용)
        // a^(-1) ≡ a^(MOD-2) (mod MOD)
        func modInverse(_ a: Int) -> Int {
            return power(a, MOD - 2)
        }

        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let k = fileIO.readInt()

        // 예외 처리
        if k == 0 || k == n {
            print(1)
        } else {
            // 팩토리얼 미리 계산
            var factorial = Array(repeating: 1, count: n + 1)
            for i in 1...n {
                factorial[i] = (factorial[i-1] * i) % MOD
            }
            
            // C(n, k) = n! / (k! * (n-k)!)
            // 모듈러 연산에서는 나눗셈 대신 역원을 곱함
            let numerator = factorial[n]
            let denominator1 = factorial[k]
            let denominator2 = factorial[n - k]
            
            // 결과 계산
            let result = (numerator * modInverse(denominator1)) % MOD
            let finalResult = (result * modInverse(denominator2)) % MOD
            
            print(finalResult)
        }
    }
}
