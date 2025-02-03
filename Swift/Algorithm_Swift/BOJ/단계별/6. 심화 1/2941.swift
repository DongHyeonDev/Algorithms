//
//  2941.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2941
//  알고리즘 분류: 구현, 문자열

class BOJ2941: Solvable {
    // 메모리: 79504KB, 시간: 12ms, 코드 길이: 739B
    func run() {
        // 크로아티아 알파벳 패턴 목록
        let croatianAlphabets = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

        // 입력 받기
        if var word = readLine() {
            // 각 크로아티아 알파벳을 특수 문자로 치환
            // 여기서는 '*'를 사용하여 한 글자로 표시
            for alphabet in croatianAlphabets {
                // dz=는 특별 처리가 필요 (z=보다 먼저 확인해야 함)
                if alphabet == "dz=" {
                    word = word.replacingOccurrences(of: alphabet, with: "*")
                } else {
                    word = word.replacingOccurrences(of: alphabet, with: "*")
                }
            }
            
            // 변환 후 남은 문자열의 길이가 크로아티아 알파벳의 개수
            print(word.count)
        }
    }
}
