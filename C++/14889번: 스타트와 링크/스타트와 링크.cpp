/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14889                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14889                          #+#        #+#      #+#    */
/*   Solved: 2025/11/29 12:34:42 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N;
int S[20][20];
vector<bool> team;  // team[i] = true이면 스타트팀, false이면 링크팀
int min_diff = INT_MAX;

// 팀 능력치 계산
int calculate_team_ability(bool team_id) {
    int ability = 0;
    for (int i = 0; i < N; i++) {
        if (team[i] != team_id) continue;
        for (int j = 0; j < N; j++) {
            if (team[j] != team_id) continue;
            ability += S[i][j];
        }
    }
    return ability;
}

// 백트래킹으로 팀 구성
// idx: 현재 사람의 번호
// count: 스타트팀에 선택된 사람 수
// start: 다음에 선택할 사람의 최소 번호 (조합)
void backtrack(int idx, int count, int start) {
    // N/2명을 선택했으면 능력치 차이 계산
    if (count == N / 2) {
        int start_ability = calculate_team_ability(true);
        int link_ability = calculate_team_ability(false);
        int diff = abs(start_ability - link_ability);
        
        min_diff = min(min_diff, diff);
        return;
    }

    // start부터 N-1까지 선택 시도
    for (int i = start; i < N; i++) {
        team[i] = true;  // 스타트팀에 추가
        backtrack(idx + 1, count + 1, i + 1);
        team[i] = false;  // 백트래킹
    }
}

int main() {
    cin >> N;
    team.resize(N, false);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    backtrack(0, 0, 0);

    cout << min_diff << "\n";

    return 0;
}