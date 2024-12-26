//
//  11654.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/26/24.
//

import Foundation

// 입력 받기
if let input = readLine(), input.count == 1 {
    if let asciiValue = input.first?.asciiValue {
        print(asciiValue)
    } else {
        print("올바른 문자 입력이 아닙니다.")
    }
} else {
    print("한 개의 문자만 입력해주세요.")
}
