//
//  26069.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/24/25.
//

//  문제 링크: https://www.acmicpc.net/problem/26069
//  알고리즘 분류: 자료 구조, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

class BOJ26069: Solvable {
    // 메모리: 79516KB, 시간: 12ms, 코드 길이: 709B
    func run() {
        // 입력 처리
        if let N = Int(readLine() ?? "") {
            var dancers: Set<String> = ["ChongChong"]  // 현재 춤추는 사람들 (초기에는 ChongChong만)
            
            for _ in 0..<N {
                guard let line = readLine()?.split(separator: " ").map(String.init),
                      line.count == 2 else { continue }
                let a = line[0], b = line[1]
                
                // 만난 두 사람 중 한 명이라도 춤을 추고 있으면 두 사람 모두 춤을 추게 된다
                if dancers.contains(a) || dancers.contains(b) {
                    dancers.insert(a)
                    dancers.insert(b)
                }
            }
            
            // 결과 출력: 최종적으로 춤추는 사람 수
            print(dancers.count)
        }
    }
}
