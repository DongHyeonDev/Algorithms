//
//  11444.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 6/15/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11444
//  알고리즘 분류: 수학, 분할 정복을 이용한 거듭제곱

class BOJ11444: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 805B
    func run() {
        let MOD = 1_000_000_007

        // 분할 정복 기법으로 (F(n), F(n+1)) 쌍을 반환
        func fib(_ n: Int) -> (Int, Int) {
            if n == 0 { return (0, 1) }  // F(0)=0, F(1)=1
            let (a, b) = fib(n >> 1)      // (F(m), F(m+1)), m = n/2
            // t = 2*F(m+1) - F(m) (mod MOD)
            let t = (2 * b % MOD - a + MOD) % MOD
            // c = F(2m) = F(m) * t
            let c = Int((Int64(a) * Int64(t)) % Int64(MOD))
            // d = F(2m+1) = F(m)^2 + F(m+1)^2
            let d = Int((Int64(a) * Int64(a) + Int64(b) * Int64(b)) % Int64(MOD))
            if n & 1 == 0 {
                // n이 짝수일 때 (F(2m), F(2m+1))
                return (c, d)
            } else {
                // n이 홀수일 때 (F(2m+1), F(2m+2))
                return (d, (c + d) % MOD)
            }
        }

        // 입력 처리
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()  // 계산할 피보나치 수 n

        // 계산 및 출력
        let result = fib(n).0
        print(result)
    }
}
