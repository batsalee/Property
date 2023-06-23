/* 1차원 배열의 누적합 */

// 0은 비워두고 1부터 사용해야 index-1 코드 작성할때 코드가 짧고 단순해짐
// 그러므로 N+1칸의 공간이 필요
vector<int> a(n + 1, 0);
vector<int> s(n + 1, 0);

// 누적합 배열 만들기    
for (int i = 1; i < n + 1; i++) {
	cin >> a[i]; // arr을 입력받으면서
	s[i] = s[i - 1] + a[i]; // 동시에 누적합도 연산함
}

// x~y의 누적합 출력하기
int x, y;
cin >> x >> y;

if (x <= 0) cout << s[y]; // 그냥 예외처리
else cout << s[y] - s[x - 1]; // 여기가 핵심


////////////////////////////////////////////////////////////////////////////

/* 2차원 배열의 누적합 */

// 마찬가지로 0은 비워두고 1부터 사용해야 코드가 짧아짐
// 즉 row + 1칸의 공간, col + 1칸의 공간이 필요
vector<vector<int>> a(row + 1, vector<int>(col + 1, 0));
vector<vector<int>> s(row + 1, vector<int>(col + 1, 0));

// 2차원 누적합 배열 만들기
for (int i = 1; i < row + 1; i++) {
	for (int j = 1; j < col + 1; j++) {
		cin >> a[i][j];
		s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
	}
}

// [x1][y1] ~ [x2][y2]의 누적합 출력하기
int x1, y1;
int x2, y2;
cin >> x1 >> y1 >> x2 >> y2;

// 예외처리 구간
if (x1 <= 0 && y1 <= 0) cout << s[x2][y2];
else if (x1 <= 0) cout << s[x2][y2] - s[x2][y1 - 1];
else if (y1 <= 0) cout << s[x2][y2] - s[x1 - 1][y2];
// 여기가 핵심
else cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];