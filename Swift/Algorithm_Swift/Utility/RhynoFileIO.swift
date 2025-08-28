//
//  RhynoFileIO.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/30/24.
//

//  참고 링크: https://gist.github.com/JCSooHwanCho/30be4b669321e7a135b84a1e9b075f88

import Foundation

final class RhynoFileIO {
    private let buffer:[UInt8]
    private var index: Int = 0

    init(fileHandle: FileHandle = FileHandle.standardInput) {
        
        buffer = Array(try! fileHandle.readToEnd()!)+[UInt8(0)] // 인덱스 범위 넘어가는 것 방지
    }

    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }

        return buffer[index]
    }

    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true

        while now == 10
                || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }

        return sum * (isPositive ? 1:-1)
    }
    
    @inline(__always) func readDouble() -> Double {
        var str = ""
        var now = read()
        var isPositive = true
        
        while now == 10 || now == 32 { now = read() }
        if now == 45 { isPositive = false; now = read() }
        
        while (now >= 48 && now <= 57) || now == 46 {
            str += String(Character(UnicodeScalar(now)))
            now = read()
        }
        
        return Double(str)! * (isPositive ? 1 : -1)
    }

    @inline(__always) func readString() -> String {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }

    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return Array(buffer[beginIndex..<(index-1)])
    }
    
    @inline(__always) func readIntOptional() -> Int? {
        var sum = 0
        var now = read()
        var isPositive = true
        
        // 공백/개행 스킵
        while now == 10 || now == 32 { now = read() }
        // EOF 센티널(0) 감지
        if now == 0 { return nil }
        
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리(문제에선 양수지만 일반화)
        var hasDigit = false
        while now >= 48, now <= 57 {
            hasDigit = true
            sum = sum * 10 + Int(now - 48)
            now = read()
        }
        return hasDigit ? sum * (isPositive ? 1 : -1) : nil
    }
}
