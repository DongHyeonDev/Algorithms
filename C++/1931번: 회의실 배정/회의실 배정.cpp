/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1931                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1931                           #+#        #+#      #+#    */
/*   Solved: 2025/12/23 13:26:00 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
};

// 비교 함수: 종료 시간 우선, 같으면 시작 시간 우선
bool compare(const Meeting &a, const Meeting &b) {
    if (a.end != b.end) {
        return a.end < b.end;  // 종료 시간 오름차순
    }
    return a.start < b.start;  // 시작 시간 오름차순
}

int main() {
    int N;
    cin >> N;

    vector<Meeting> meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].start >> meetings[i].end;
    }

    // 정렬
    sort(meetings.begin(), meetings.end(), compare);

    int count = 0;
    int last_end = 0;

    for (int i = 0; i < N; i++) {
        // 이전 회의가 끝난 시간 이후에 시작하는 회의 선택
        if (meetings[i].start >= last_end) {
            count++;
            last_end = meetings[i].end;
        }
    }

    cout << count << "\n";

    return 0;
}