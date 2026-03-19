#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[10][10];
long long ans = -1;
int dat[210];
int temparr[10][10];

//세로 겹치는 거 확인
int samecheck(int col) {
    memset(dat, 0, sizeof(dat));
    for (int i = 0; i < N; i++) {
        if (dat[temparr[i][col] + 100] == 1) return -1;
        dat[temparr[i][col] + 100] = 1;
    }
    return 0;
}

//세로 다 더하기
int onesum(int col) {
    int sumcol = 0;
    for (int i = 0; i < N; i++) {
        sumcol += temparr[i][col];
    }
    return sumcol;
}

//회전
void rotate(int row, int col) { //회전할 row, 맨 앞에 올 col
    for (int i = 0; i < M; i++) {
        temparr[row][i] = map[row][col];
        if (col == M - 1) col = 0;
        else col++;
    }
}

void func(int level) {
    if (level == N) {
        long long mul = 1;
        for (int i = 0; i < M; i++) {
            if (samecheck(i) == -1) return;
            mul *= onesum(i);
        }
        //ans 갱신
        ans = max(ans, mul);
        return;
    }
    for (int j = 0; j < M; j++) {
        rotate(level, j);
        func(level + 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    func(0);
    cout << ans << "\n";
}