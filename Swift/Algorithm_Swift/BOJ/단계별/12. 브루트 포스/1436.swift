//
//  1436.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 3/8/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1436
//  알고리즘 분류: 브루트포스 알고리즘

class BOJ1436: Solvable {
    // 메모리: 79508KB, 시간: 28ms, 코드 길이: 842B
    func run() {
        // N 입력 받기
        if let input = readLine(), let N = Int(input) {
            var count = 0 // 찾은 종말의 수 개수
            var num = 0   // 현재 검사 중인 숫자
            
            while count != N { // N번째 종말의 수를 찾을 때까지 반복
                var temp = num
                
                // 숫자 temp를 10으로 나누면서 666 포함 여부 확인
                while temp >= 666 {
                    if temp % 1000 == 666 { // 마지막 세 자리가 666이면 종말의 수
                        count += 1 // 종말의 수 개수 증가
                        break       // 더 이상 검사할 필요 없음
                    } else {
                        temp /= 10 // 숫자를 10으로 나누며 계속 확인
                    }
                }
                
                num += 1 // 다음 숫자로 이동
            }
            
            print(num - 1) // N번째 종말의 수 출력
        }
    }
}
