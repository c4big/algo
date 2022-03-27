
C. Epidemic in Monstropolis
http://codeforces.com/contest/733/problem/C
http://codeforces.com/contest/733/submission/21937979	// pretest만 통과하고 실전은 실패한 비통한 소스
문제는 간단하다 큐에 최대 500개의 원소가 있고
그 값들을 몇몇을 합침으로써 (큰쪽이 작은 쪽을 먹는 식으로)
타깃 큐 형태를 만들수 있다. (물론 아무짓도 안 할수 있다. 타깃 큐랑 처음 큐가 같다면 말이지)
6
1 2 2 2 1 2	// 처음 큐
2
5 5			// 목표 큐

YES
2 L
1 R
4 L
3 L

목표큐에 들어간 갯수랑 일치시켜 범위를 나눈다.
즉 (1 2 2), (2, 1, 2) 로 나눈뒤
각각의 최고치 (중복이라면 인근에 작은게 있는 최고치) 를 선택하여 합친다.
n 이 500개 이하라 노가다 코드로 짤 수 있다. // 내가 제출한 코드를 참고해서 보삼 
// 하나씩 지우는 식으로 vector<ll> tmp 에 다시 저장하고 
// 그런식으로 범위내의 갯수가 1개가 될때 까지 한다.

// 여기까지는 순조로웠다.....

허나 
4
1 2 3 4	// 4가 남음
2
3 3		

이라던다.
4
1 2 3 4
2
10 1	// 1이 남음

이런 인풋에 대해 고려를 안했다. ㅠㅠ 이것만 맞췄어도 순위가 상위 5프로에 들었다.. ㅠㅠ 아악...


D. Kostya the Sculptor
http://codeforces.com/contest/733/problem/D
input
6	// n 이 10^5 개 : 10만개다...
5 5 5
3 2 4
1 4 1
2 1 3
3 2 4
3 3 4
output
1
1

input
7
10 7 8
5 10 3
4 2 6
5 5 5
10 2 8
4 2 1
7 7 7
output
2
1 5

가장 큰 원을 만들수 있는 직육면체를 찾는다.
직육면체는 1개 혹은 2개를 합한 직육면체를 이용할 수 있다.
(두개의 합도 직육면체이여야 하며, 이때 각 직육면체는 회전, 플립을 해서 합칠수 있다.)
 If there are several answers print any of them. // 답이 여러개면 어느것도 가능하다.

고찰:
두변이 같으면 나머지 한 변을 합친 길이로 정육면체를 만들수 있다.
(3 2 4) + (2 1 3) = (3 2 5)
// 플립이 되기에 (1 2 3) = (1 3 2) = (2 1 3) = (2 3 1) = (3 1 2) = (3 2 1) 는 같은 정육면체로 보면 된다.
"핵심 맵에다가 두변을 키로 잡고 세번째 변을 값으로 취한다. 이때 값도 2개는 되어 야 하므로 제일 큰 두 놈이 들어간다."
//헌대 만약 입력된 정육면체가 변의 길이가 동일한게 있을 수 있으므로
//선택된 것을 기록하는 맵을 따로 두어 1놈인지 아닌지 구분할 수 있다.

http://codeforces.com/contest/733/submission/21944521 // 1초나 걸림.. 제한시간은 3초니 뭐.
map<pair<ll, ll>, pair<ll, ll>> my;
map<pair<ll, ll>, pair<int, int>> my2;	//index ���
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n) {
		vector<ll> arr(3);
		rep(j, 3) cin >> arr[j];
		sort(arr.begin(), arr.end());
		if (my.count(mp(arr[0], arr[1])) == 0) {	// 한번도 안 발견된 놈이면
			my[mp(arr[0], arr[1])] = mp(0, 0);		// 등록한다.
			my2[mp(arr[0], arr[1])] = mp(-1, -1);
		}
		// value 가 가장 큰 두 놈을 기록한다.
		if (my[mp(arr[0], arr[1])].first < arr[2]) {	// 첫번째보다 크다면 첫번째를 갱신
			my[mp(arr[0], arr[1])].second = my[mp(arr[0], arr[1])].first;  //기존 첫번째는 두번째로 이동시킴
			my[mp(arr[0], arr[1])].first = arr[2];
			my2[mp(arr[0], arr[1])].second = my2[mp(arr[0], arr[1])].first;
			my2[mp(arr[0], arr[1])].first = i;
		}
		else if (my[mp(arr[0], arr[1])].second < arr[2]) {
			my[mp(arr[0], arr[1])].second = arr[2];
			my2[mp(arr[0], arr[1])].second = i;
		}


		if (my.count(mp(arr[1], arr[2])) == 0) {
			my[mp(arr[1], arr[2])] = mp(0, 0);
			my2[mp(arr[1], arr[2])] = mp(-1, -1);
		}
		if (my[mp(arr[1], arr[2])].first < arr[0]) {
			my[mp(arr[1], arr[2])].second = my[mp(arr[1], arr[2])].first;
			my[mp(arr[1], arr[2])].first = arr[0];
			my2[mp(arr[1], arr[2])].second = my2[mp(arr[1], arr[2])].first;
			my2[mp(arr[1], arr[2])].first = i;
		}
		else if (my[mp(arr[1], arr[2])].second < arr[0]) {
			my[mp(arr[1], arr[2])].second = arr[0];
			my2[mp(arr[1], arr[2])].second = i;
		}


		if (my.count(mp(arr[0], arr[2])) == 0) {
			my[mp(arr[0], arr[2])] = mp(0, 0);
			my2[mp(arr[0], arr[2])] = mp(-1, -1);
		}
		if (my[mp(arr[0], arr[2])].first < arr[1]) {
			my[mp(arr[0], arr[2])].second = my[mp(arr[0], arr[2])].first;
			my[mp(arr[0], arr[2])].first = arr[1];
			my2[mp(arr[0], arr[2])].second = my2[mp(arr[0], arr[2])].first;
			my2[mp(arr[0], arr[2])].first = i;
		}
		else if (my[mp(arr[0], arr[2])].second < arr[1]) {
			my[mp(arr[0], arr[2])].second = arr[1];
			my2[mp(arr[0], arr[2])].second = i;
		}
	}
	ll mxC = 0;
	pii sol;
	map<pair<ll, ll>, pair<ll, ll>>::iterator it = my.begin();
	for (; it != my.end(); ++it) {
		ll a = it->first.first;
		ll b = it->first.second;
		ll c = it->second.first + it->second.second;
		ll cand = min(a, min(b, c));
		if (mxC < cand) {
			sol = my2[mp(a, b)];
			mxC = cand;
		}
	}
	// 한놈만 선택된 경우 sol.second == -1 이 올수 있다.
	// 한 정육면체가 만약 같은 변을 여러개 가지고 있다면 sol.first == sol.second 인 것을 체크해야 한다.
	if (sol.second == -1 || (sol.first == sol.second)) {
		cout << 1 << '\n';
		cout << sol.first + 1;
	}
	else {
		cout << 2 << '\n';
		cout << sol.first + 1 << " " << sol.second + 1;
	}
	return 0;
}
1: {6, 6, 2}
2: {6, 6, 6}
합치면 : {6, 6, 8} 이 될텐데 오류 나지 않냐?? 
// 안에 들어가는 최대원의 지름은 6이다.
// 으음... 소 뒷걸음 쳐서 맞춘 거 같다...



// 참고 소스
http://codeforces.com/contest/733/submission/22386394
int main() {
	vi v(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 2;
	do {
		cout << v[0] << " " << v[1] << " " << v[2] << '\n';
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}
next_permutation
123
132
213
231
312
321

// 122인 경우
122
212
221

// 321인경우
당연히 321만 출력되고 종료 // next_permutation이 없다.
// 정말 간단하고 좋은 코드
int n, a, b, k, x, h, mx = 0;
int main() {
	cin >> n;
	vi v(3);
	map<pii, pii> mp;
	rep(i,n) {
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		// 한개짜리가 해가 되는 경우
		if (v[0] > mx) { k = 1; mx = v[0]; a = i; }
		do {
			pii p = { v[0], v[1] };
			// 같은변이 2개 존재하는 직육면체가 존재 안 할 경우
			if (mp.find(p) == mp.end()) mp[p] = { v[2], i};
			else {
				x = mp[p].first;
				// 두 직육면체를 합칠시 가장 작은 변
				h = min(min(v[0], v[1]), x + v[2]);	
				if (h > mx) mx = h
					, a = mp[p].second	// 아이디
					, b = i				// 아이디
					, k = 2;			// 합쳤으니 2개
				// 두변이 같고 나머지 변이 더 큰 쪽이 있다면 그걸 취한다.
				if (x < v[2]) mp[p] = { v[2], i };
			}
		} while (next_permutation(v.begin(), v.end()));
	}
	if (k == 1) cout << 1 << '\n' << a + 1;
	else cout << 2 << '\n' << a + 1 << " " << b + 1;
}
idx
0		7 5 1
1		7 5 3					// mx = 4, a = 0, b = 1
map은 value 가 큰 쪽만 저장한다. mp[{7, 5}] = { 3, 1 }
...
6		7 5 2					// mx = 5, a = 1, b = 2


"일렬순환성립"
또다른 일렬순환성립 구조를 보자.
배열 arr에서 큰 순서대로의 원소 2개의 합을 구하라(arr 원소는 양수)
int get(vi arr) {
	int mx = 0;
	int ret = 0;
	for (int i = 0; i < arr.size(); ++i) {
		ret = max(ret, arr[i] + mx);
		mx = max(mx, arr[i]);
	}
	return ret;
}


http://codeforces.com/contest/734/problem/C
http://codeforces.com/contest/734/submission/22233574	// 도레아몬소스
// 문제 해석하기 더럽게 복잡해..
// 각 포션을 만드는 주문 종류는 2가지임
// 하나는 스피드 업 주문
// 두번째는 즉시 생성주문
// 각 주문들도 여러가지가 있다.

목표갯수만큼 포션을 만들때 가장 짧은 시간을 구하라
스피드 업 주문에서 최대 한가지를 사용할수 있고
즉시생성주문에서 최대 한가지를 사용할수 있다.
즉시 생성주문은 입력은
생성량 단조 증가 (not decreasing)
비용 단조 증가(not decreasing) 이다.


// 1 <= n <= 2*10^9,	1 <= m, k <= 2 * 10^5
20 3 2	// n: 만들 포션 목표수량, m: 스피드 업 주문 갯수, k: 즉시 생성 주문 갯수 
10 99	// x: 기본 속도,	s: 자금
2 4 3		// ai: 변경된 스피드 , 기본속도보단 작음을 보장(빠르다)
20 10 40	// bi: 그것을 수행하는데 드는 비용
4 15		// ci: 즉시 생성하는 갯수
10 80		// di: 그것을 수행하는데 드는 비용

내 생각:
분할 상환을 이용하여 풀자..
허나 뭔가 실수가 있는지 통과를 못한다. // 이럴 경우 계속 잡지 말고 다른 방법이 생각나면 그걸로 바로 바꿔라!!
그냥 도레아몬 소스를 봅세

"각 주문은 20만개씩 선택해야 하니 무식하게 한다면 
총 20만 * 20만 의 경우의 수를 고려해야 한다!!!!

const int INF = 2e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;	// 목표량, 타입1 수, 타입2 수
	int x, s; cin >> x >> s;	// 기본생성시간, 자금
	vi a(m), b(m), c(k), d(k);
	rep(i, m) cin >> a[i];	// 변경된 스피드
	rep(i, m) cin >> b[i];
	rep(i, k) cin >> c[i];	// 즉시 생성하는 갯수 : 단조증가
	rep(i, k) cin >> d[i];	// 그에 대한 비용 : 단조 증가
	vpii dc;
	rep(i, k) dc.pb(mp(d[i], c[i]));
	ll sol = INF * (ll)INF;
	a.push_back(x), b.push_back(0);	// 기본속도: x, 비용: 0
	rep(i, m + 1) {
		if (b[i] <= s) {
			pii base = mp(s - b[i], INF);	// 남은 자금
			// 비용이 비싼게 제일 많이 즉시 생성을 해준다.
			// 참 좋은 표현이다.
			int idx = upper_bound(dc.begin(), dc.end(), base) - dc.begin();
			if (idx == 0)	// 기준보다 왼쪽에 아무것도 없다면
				sol = min(sol, a[i] * (ll)n);
			else
				sol = min(sol, a[i] * (ll)max(0, n - c[idx - 1]));
		}
	}
	cout << sol;
	return 0;
}



http://codeforces.com/contest/734/problem/D
// 각 좌표는 -10^9 <= xi, yi <= 10^9
2	// 검은 알들(rooks, bishops, queens)의 총 수	// 1 <= n <= 500000
4 2	// 흰색 왕의 좌표 x0, y0 // 예시로 보기엔 y0, x0 로 보임
R 1 1	// rooks 1, 1 좌표	// 수직, 수평으로 움직임: 뛰어넘진 못함
B 1 5	// bishops 1, 5 좌표	// 양 대각선으로 움직임: 뛰어넘진 못함
		// queen 의 경우 수직, 수평, 양 대각선으로 움직임: 뛰어넘진 못함
		"어떠한 두 알들도 겹치지 않음을 보장함"

output
YES
// r000b
// 00000
// 00000
// 0K000	// K는 비숍에게 잡힌다.


2
4 2
R 3 3
B 1 5

output
NO
// 0000b
// 00000
// 00r00
// 0K000	// K는 비숍에게 잡힐거 같았으나 rooks 가 비숍을 방해했음
// 00000


// 킹을 기준으로 8 방향을 체크하자.
// 점들을 x를 기준으로 오름차순 정렬	// 1,2,3
// 점들을 x를 기준으로 내림차순 정렬	// 6,7,8
// 점들을 y를 기준으로 오름차순 정렬	// 5
// 점들을 y를 기준으로 내림차순 정렬	// 4

//1 오른쪽 체크: y가 같고 x가 증가, 중간에 비숍을 만나면 false, 그외를 만나면 true
//2 오른쪽 위 체크: 동일량의 y가 감소 x가 증가함, 중간에 rooks 를 만나면 false ..
//3 오른쪽 아래 체크: 동일량의 y가 증가, x가 증가, 중간에 rooks 를 만나면 false ..

//4 위 체크: x가 같고 y가 감소, 중간에 비숍을 만나면 false ..
//5 아래 체크: x가 같고 y가 증가, 중간에 비숍을 만나면 false ..

//6 왼쪽
//7 왼쪽 위
//8 왼쪽 아래


// 1000ms 나 걸림.. 게다가 3번 틀리고 틀린 예시 보고 문제를 고칠수 있었다. ㅠㅠ
int y, x;
vector<pair<pair<int, int>, char>> arr, arr2;
bool check1(bool acc) { // 위아래 체크
	// y를 기준으로 오름차순 체크
	if (acc) {
		rep(i, arr.size()) {
			if (y >= arr[i].first.first) continue;
			if (x != arr[i].first.second) continue;
			if (arr[i].second == 'B') break;
			else return true;
		}
	}
	else {
		rep(i, arr.size()) {
			if (y <= arr[i].first.first) continue;
			if (x != arr[i].first.second) continue;
			if (arr[i].second == 'B') break;
			else return true;
		}
	}
	return false;
}
bool check2(bool acc) {
	if (acc) {
		rep(i, arr2.size()) {
			int ny = arr2[i].first.second;	// x값을 기준으로 정렬되었기에 바꾼다.
			int nx = arr2[i].first.first;
			if (nx <= x) continue;
			if (ny <= y) continue;
			if ((nx - x) != (ny - y)) continue;
			if (arr2[i].second == 'R') break;
			else return true;
		}
		rep(i, arr2.size()) {
			int ny = arr2[i].first.second;	// x값을 기준으로 정렬되었기에 바꾼다.
			int nx = arr2[i].first.first;
			if (nx <= x) continue;
			if (ny != y) continue;
			if (arr2[i].second == 'B') break;
			else return true;
		}
		rep(i, arr2.size()) {
			int ny = arr2[i].first.second;	// x값을 기준으로 정렬되었기에 바꾼다.
			int nx = arr2[i].first.first;
			if (nx <= x) continue;
			if (ny >= y) continue;
			if ((nx - x) != (y - ny)) continue;
			if (arr2[i].second == 'R') break;
			else return true;
		}
	}
	else {
		rep(i, arr2.size()) {
			int ny = arr2[i].first.second;	// x값을 기준으로 정렬되었기에 바꾼다.
			int nx = arr2[i].first.first;
			if (nx >= x) continue;
			if (ny >= y) continue;
			if ((x - nx) != (y - ny)) continue;
			if (arr2[i].second == 'R') break;
			else return true;
		}
		rep(i, arr2.size()) {
			int ny = arr2[i].first.second;	// x값을 기준으로 정렬되었기에 바꾼다.
			int nx = arr2[i].first.first;
			if (nx >= x) continue;
			if (ny != y) continue;
			if (arr2[i].second == 'B') break;
			else return true;
		}
		rep(i, arr2.size()) {
			int ny = arr2[i].first.second;	// x값을 기준으로 정렬되었기에 바꾼다.
			int nx = arr2[i].first.first;
			if (nx >= x) continue;
			if (ny <= y) continue;
			if ((x - nx) != (ny - y)) continue;
			if (arr2[i].second == 'R') break;
			else return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	cin >> y >> x;
	arr.resize(n), arr2.resize(n);
	rep(i, n) {
		char piece; cin >> piece;
		int yy, xx; cin >> yy >> xx;
		arr[i] = mp(mp(yy, xx), piece);
		arr2[i] = mp(mp(xx, yy), piece);
	}
	bool ok = false;
	sort(arr.begin(), arr.end());	// y를 기준으로 정렬
	ok = check1(true);
	sort(arr.begin(), arr.end(), greater<pair<pii, int>>());
	ok = (ok || check1(false));

	sort(arr2.begin(), arr2.end());	// x를 기준으로 정렬
	ok = (ok || check2(true));
	sort(arr2.begin(), arr2.end(), greater<pair<pii, int>>());
	ok = (ok || check2(false));

	if (ok) cout << "YES";
	else cout << "NO";
	return 0;
}


doreamon 의 소스를 보자
http://codeforces.com/contest/734/submission/22235589
// cin을 쓰면 아무래도 느리긴 하넹.. 826ms 나옴.. 도레아몬 소스는 300ms 정도 나왔음
const int INF = 2e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<char> ch(n + 1);
	vector<int> x(n + 1), y(n + 1);
	cin >> x[0] >> y[0];
	rep2(i, 1, n + 1) 
		cin >> ch[i] >> x[i] >> y[i];
	char rightC = ' ', leftC = ' ';		// left, right는 왼쪽, 오른쪽 만을 의미하는게 아님
	int maxLeft = -INF, minRight = INF;	
	rep2(i, 1, n + 1) {
		if (y[i] == y[0]) {
			if (x[i] > x[0] && x[i] < minRight) {
				rightC = ch[i];
				minRight = x[i];
			}
			if (x[i] < x[0] && x[i] > maxLeft) {
				leftC = ch[i];
				maxLeft = x[i];
			}
		}
	}
	if (rightC == 'R' || rightC == 'Q' || leftC == 'R' || leftC == 'Q') {
		cout << "YES"; return 0;
	}

	rightC = ' ', leftC = ' ';
	maxLeft = -INF, minRight = INF;
	rep2(i, 1, n + 1) {
		if (x[i] == x[0]) {
			if (y[i] > y[0] && y[i] < minRight) {
				rightC = ch[i];
				minRight = y[i];
			} 
			if (y[i] < y[0] && y[i] > maxLeft) {
				leftC = ch[i];
				maxLeft = y[i];
			}
		}
	}
	if (rightC == 'R' || rightC == 'Q' || leftC == 'R' || leftC == 'Q') {
		cout << "YES"; return 0;
	}

	rightC = ' ', leftC = ' ';
	maxLeft = -INF, minRight = INF;
	rep2(i, 1, n + 1) {
		if (x[i] + y[i] == x[0] + y[0]) {
			if (y[i] > y[0] && y[i] < minRight) {
				rightC = ch[i];
				minRight = y[i];
			}
			if (y[i] < y[0] && y[i] > maxLeft) {
				leftC = ch[i];
				maxLeft = y[i];
			}
		}
	}
	if (rightC == 'Q' || rightC == 'B' || leftC == 'Q' || leftC == 'B') {
		cout << "YES"; return 0;
	}
	rightC = ' ', leftC = ' ';
	maxLeft = -INF, minRight = INF;
	rep2(i, 1, n + 1) {
		//if (x[i] + y[i] == x[0] + y[0]) {
		if (x[i] - y[i] == x[0] - y[0]) { //!!!!	대각선 처리하는거 깔끔하구낭..
			if (y[i] > y[0] && y[i] < minRight) {
				rightC = ch[i];
				minRight = y[i];
			}
			if (y[i] < y[0] && y[i] > maxLeft) {
				leftC = ch[i];
				maxLeft = y[i];
			}
		}
	}
	if (rightC == 'Q' || rightC == 'B' || leftC == 'Q' || leftC == 'B') {
		cout << "YES"; return 0;
	}
	cout << "NO";
	return 0;
}


http://codeforces.com/contest/734/problem/E
문제 그림을 보면 금방 이해된다.
특정 노드에서 뻗어 나가는 길들 중 칼라 변경이 가장 큰 길이 ans 라고 하자
ans의 값을 최소화 하는 노드를 찾아서 그에 해당되는 ans를 출력하라.


http://codeforces.com/contest/740/problem/C
// 배열이 주어져 있고
// 각 구간이 주어질때
// 구간들의 mex 의 최소값이
// 최대가 되도록 하는 배열을 구하라
// mex 란: 속한 수들 중 빠진 값이(0이상 중) 가장 작은거
	mex({1, 2, 3}) = 0
	mex({0, 2, 4, 6, ...}) = 1
	mex({0, 1, 4, 7, 12}) = 2
"각 구간별 mex는 그 구간의 길이가 될 뿐이다."
" mex의 최소값은 가장 짧은 구간이 된다.
" 그 걸 순회하는 배열을 구하면 된다.
int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	int length = INF;
	rep(i, m) {
		int a, b; cin >> a >> b;
		int cand = b - a + 1;
		length = min(cand, length);
	}

	cout << length << '\n';
	length--;
	int tmp = length;
	rep2(i, 1, n + 1) {
		cout << tmp << " ";
		tmp--;
		if (tmp == -1)
			tmp = length;
	}
	return 0;
}
input
5 3
1 3
2 5
4 5
output
2
1 0 1 0 1

http://codeforces.com/contest/735/problem/D
D. Taxes
n: (2 <= n <= 2*10^9)
ex) n = 6 :: pay 3 burles	// n 보다 작은 약수중 최대값이 세금이다.
	n = 25 :: pay 5 burles

헌데 n 을 1보다 큰 임의의 수로 쪼개서 세금을 낼 수 있다.
이 경우
n = 27	:: 23, 4 로 쪼갠다 :: // 뭐 23, 2, 2 로 쪼개도 답이 된다.
		:: 1 + 2 가 되어
		:: 총 세금은 3이 된다.

총 세금이 가장 적게 되도록 할 때 그 세금을 출력하라.
// 소수로 쪼개면 될거 같다만.. n 이 무지 크네.. 과연 될까?
// n 이하의 수중 가장 큰 소수를 찾는 빠른 방법이 있나 ㅠㅠ...
// 일단 어떤수가 소수인지 판별하는 방법은 O(sqrt(n)) 이 걸린다.
// 소수의 간격이 연속된 600개 수 내에서 적어도 2개가 발견된다고 한다.
// 출처가 웃대라 믿긴 힘들다만 http://m.todayhumor.co.kr/view.php?table=total&no=10966012
// n이하의 숫자 중 홀수에 대해 소수인지 체크하는 방법으로 갈 수 있다.

// 풀이에서는
" n 자체가 소수인 경우
답은 1

//짝수는 골드바흐의 추측을 이용했다.
" 2보다 큰 짝수는 두 개의 소수의 합으로 표시할 수 있다 !!!!"

" n 이 홀수의 경우
(n - 2) 가 소수라면 답은 2가 된다.
그렇지 않다면
3 + (n - 3) 에서 n - 3 이 짝수이므로
답은 1 + 1 + 1  = 3 이 된다.

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int sqrtn = int(sqrt(n));
	for (int div = 3; div <= sqrtn; div += 2)
		if (n % div == 0)
			return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;	// n 은 2보다 이상임
	if (isPrime(n))
		cout << 1;
	else if (n % 2 == 0)
		cout << 2;
	else if (isPrime(n - 2))	// n은 5 이상인 합성수임이 보장됨
		cout << 2;
	else
		cout << 3;	// (n - 3) 은 짝수임, 3은 홀수임
	return 0;
}




http://codeforces.com/problemset/problem/742/C
C. Arpa's loud Owf and Mehrdad's evil plan
각 노드의 시작 지점과 끝 지점이 동일 간격으로 이동가능하면 hoon hoon 이라 한다.
각 정점들의 hoon hoon 이 이루어지는 간격이 있다고 할 때
모든것을 만족 시키는 간격을 구하라(최소의)
n = 100 개 이하

4
2 3 1 4	// 3	// 3짜리 홀수 사이클과 1짜리 홀수 싸이클이 존재 
				// 3 간격으로 hoon hoon 이 이루어진다.
				// 2 --> 3 --> 1 --> 2 // i = 2, j = 2 인 경우 i, j 를 바꾸어도 3간격으로 hoon hoon
				// 3 --> 1 --> 2 --> 3
				// 1 --> 2 --> 3 --> 1

4
4 4 4 4 // -1

4
2 1 4 3 // 1	// node[1] --> node[2] : 간격이 1이고
				// node[2] --> node[1] : 역시 간격이 1 이므로 
				// 짝수 싸이클은 나누기 2한것 만큼 hoon hoon 길이가 된다.
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll tree[101];
bool vstd[101];
ll dfs(int here, int start, bool& cycle) {
	vstd[here] = true;
	if (vstd[tree[here]] == false) {
		return 1 + dfs(tree[here], start, cycle);
	}
	else if (vstd[tree[here]] == true && tree[here] == start) {
		cycle = true;
		return 1;
	}
	else
		return -INF;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	rep2(i,1, n+1) {
		int crush;
		cin >> crush;
		tree[i] = crush;
	}
	vector<ll> szArr;
	rep2(i, 1, n + 1) {
		bool selfCycle = false;
		if (vstd[i] == true) continue;
		ll sz = dfs(i, i, selfCycle);
		if (selfCycle == true) {
			//if (sz == 2) sz = 1;
			if (sz % 2 == 0) sz /= 2;
			szArr.push_back(sz);
		}
		else {	// 자기 자신으로 돌아갈 수 없는 정점이 있다면
			cout << -1;
			return 0;
		}
	}
	// 모든 사이클에서 해가 되려면 최소공배수가 되어야 한다.
	ll tmp = szArr[0];
	rep2(i,1, szArr.size()) {
		tmp = tmp / gcd(tmp, szArr[i]) * szArr[i];
	}
	cout << tmp;
	return 0;
}


// 반성의 코드
나의 미친짓!!!!
"이 실수로 900점이 날라갔다"	// 어디가 오륜지 한눈에 찾아보삼
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vs board(n);
	rep(i, n) cin >> board[i];
	int sy = INF, sx = INF, ey = -INF, ex = -INF;
	rep(i, n) rep(j, n) {
		if (board[i][j] == 'X') {
			sy = min(sy, i);
			sx = min(sx, j);
			ey = max(ey, i);
			ex = max(ex, j);
		}
	}


http://codeforces.com/contest/742/problem/D
사람들을 선택하고 허용 최대 무게를 초과하지 않는 선에서 최고의 아름다움을 구하라
	"이때 각 친구집합에서 적어도 한명은 차출되어야 한다"
n: 1000 이하, 친구쌍 1000 * 1000 미만, 허용 최대 무게 : 1000
3 1 5	// 사람(호스)수, 친구쌍 수, 허용 최대 무게
3 2 5	// 각자의 무게
2 4 2	// 각자의 beauty
1 2		// 친구쌍

6		// {1, 2} 에서 2번과 {3} 에서 3번을 차출? 단독그룹은 차출안해도 된다.
		// 그룹으로 지목된거라도 차출 안해도 된다!!
		// {1, 2} 에서 1번 2번 두개 차출함
	"ㅅㅂ" no more than one 은 뜻이 많아야 1개 임. 구글, 네이버 번역은 1개 이상이라고 함..
ex) The PDF contains no more than one non-scanned page.
	pdf에는 스캔되지 않은 페이지가 하나만 있습니다.
cf) The cube contains more than one distinct count measure
	큐브에 둘 이상의 고유한 카운트 측정값이 들어 있습니다.

4 2 11
2 4 6 6
6 4 2 1
1 2
2 3

7		// {1,2,3} 에서 1을 선택 {4} 에서 4를 선택
		// {1,2,3} 에서 1,2를 동시 선택은 불가능 함// no more than one...

// 한방에 통과요 히힛
// 집합셋 설정뒤에 dp 로 풀었음 146ms 걸림
const int INF = 987654321;
int cache[1001][1001];
int sCnt;	// 집합그룹갯수
int wi[1001], bi[1001];	// 각 원소별 무게, 아름다움
vi myS[1001];	// 집합그룹당 원소를 저장함
int sWSum[1001], sBSum[1001];	// 각 그룹전체의 무게, 아름다움 합
int n, m, w;	// 원소수, 친구쌍 수, 한계무게
int f[1001];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int rec(int remain, int here) {
	if (remain < 0) return -INF;
	if (here == sCnt) return 0;
	int& ret = cache[remain][here];
	if (ret != -1) return ret;
	ret = rec(remain - sWSum[here], here + 1) + sBSum[here];
	for (int i = 0; i < myS[here].size(); ++i) {
		int an = myS[here][i];
		ret = max(ret, rec(remain - wi[an], here + 1) + bi[an]);
	}
	ret = max(ret, rec(remain, here + 1));
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> w;
	rep2(i,1, n+1) cin >> wi[i];
	rep2(i,1, n+1) cin >> bi[i];
	rep2(i, 1, n + 1) f[i] = i;
	rep(i, m) {
		int a, b; cin >> a >> b;
		f[find(a)] = find(b);
	}
	map<int, vi> tmp;
	rep2(i, 1, n + 1) tmp[find(i)].push_back(i);
	sCnt = tmp.size();
	map<int, vi>::iterator it = tmp.begin();
	int i = 0;
	for (; it != tmp.end(); ++it) myS[i++] = it->second;
	for (i = 0; i < sCnt; ++i) {
		for (int j = 0; j < myS[i].size(); ++j) {
			int an = myS[i][j];
			sWSum[i] += wi[an], sBSum[i] += bi[an];
		}
	}
	memset(cache, -1, sizeof(cache));
	int sol = rec(w, 0);
	cout << sol;
	return 0;
}



http://codeforces.com/contest/745/problem/C
C. Hongcow Builds A Nation
n개의 정점, m개의 기존 간선, k개의 거점 // 1000개, 10만개 간선, 1 <= <= n;

거점은 정점과 연결이 되어 있어야 하고
각 나라간 연결은 없어야 된다고 가정할때

간선을 많이 추가할 경우 최대 추가 간선의 수를 출력하라.

간선 정보에 대해
정점집합을 처리하면서 동시에 각 거점영역에 대한 간선, 정점 처리하기는 힘들다.

일차로 dsjSet를 세팅한다.
그뒤 다시 거점영역에 포함된 간선, 정점을 세팅하도록 한다.

그 다음은 추가할 엣지들의 수가 된다.
어느 거점영역에도 포함 되지 않는 정점들은
"최대 거점 영역을 가진 놈에 포함시키는게 답을 구하는데 필요하다."

그리고
최대 거점 영역이 아닌 놈들도 간선을 추가해야 하니 그것을 더해 주자.


// 139ms 걸림
const int INF = 987654321;
struct dsjSet {
	vi prnt, rank, size;
	dsjSet(int n) : prnt(n), rank(n, 1) , size(n, 1) {
		rep(i,n) prnt[i] = i;
	}
	//u가 속한 트릐의 루트의 번호를 반환한다.
	int find(int u) {
		if (u == prnt[u]) return u;
		return prnt[u] = find(prnt[u]);	//경로압축
	}
	//u가 속한 트리와 v가 속한 트리를 합친다.
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		//u와 v가 이미 같은 집합에 속하는 경우를 걸러낸다.
		if (u == v) return size[u];

		if (rank[u] > rank[v]) swap(u, v);
		//이제 rank[v]가 항상 rank[u] 이상이므로 u를 v의 자식으로 넣는다.
		if (rank[u] == rank[v]) rank[v]++;
		prnt[u] = v;
		size[v] += size[u];
		return size[v];
	}
	int getSize(int u) { return size[find(u)]; }
};
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	ll n, m, k; 	cin >> n >> m >> k;
	dsjSet sets(n + 1);
	map<int, ll> my;	// 간선수를 기록
	vi keys;
	rep(i, k) {	int ci; cin >> ci;	keys.push_back(ci);	my[ci] = 0;	}
	vpii arr;
	rep(i, m) {	int a, b; cin >> a >> b; arr.push_back(mp(a, b)); sets.merge(a, b);	}
	ll indiEdge = 0;
	// 두번째 돌리기
	rep(i, m) {
		int a, b; a = arr[i].first; b = arr[i].second;	int kk = -1;
		rep(i, keys.size()) 
			if (sets.find(keys[i]) == sets.find(a) ||
				sets.find(keys[i]) == sets.find(b)) {		// 주 거점을 포함한 간선이라면
				kk = keys[i]; break;
			}
		if (kk != -1) my[kk]++;
		else indiEdge++;
	}
	ll indiNode = 0;
	rep(i, keys.size()) indiNode += sets.getSize(keys[i]);
	indiNode = n - indiNode;
	ll sol = 0;
	int maxKey = -1;
	rep(i, keys.size()) {
		int kk = keys[i];
		ll sz = sets.getSize(kk);
		ll tmp = sz * (sz - 1) / 2; // 거점과 연결된 엣지
		ll tmp2 = sz * indiNode;
		ll tmp3 = indiNode * (indiNode - 1) / 2 - indiEdge;
		ll cand = (tmp - my[kk]) + tmp2 + tmp3;	
		// (거점 최대 연결 엣지 - 기존 거점 연결 엣지) 
		// + 거점과 독림된 노드랑 추가 연결 + 독립된 노드 내의 추가 연결 
		if (sol < cand) { sol = cand; maxKey = kk; }
	}
	if (sol == 0) {	// 거점 중 최대한 추가할 엣지가 0개라면 다른건 다해봐야 0;
		cout << sol; return 0;
	}
	"그냥 sol 을 출력하면 안된다. 다른 나라의 거점과 정점들 사이에 추가할 선이 있다면 추가해야 하기 때문이다.
	rep(i, keys.size()) {		// 내가 빼먹은 부분 ㅠㅠㅠㅠㅠ
		int kk = keys[i];
		if (kk == maxKey) continue;
		ll sz = sets.getSize(kk);
		ll tmp = sz * (sz - 1) / 2;
		ll add = tmp - my[kk];	// my[kk] 현 거점과 기존 연결된 간선이 아니라 거점 영역에 기존 연결된 간선임
		sol += add;
	}
	cout << sol;
	return 0;
}

int main() {
	ll n, m, k; cin >> n >> m >> k;
	dsjSet sets(n + 1);
	map<int,ll> my;
	vi keys;
	rep(i,k) { int ci; cin >> ci; keys.pb(ci); my[ci] = 0; }
	vpii arr;
	rep(i,m) { int a, b; cin >> a >> b; arr.pb(mp(a, b)); sets.merge(a, b); }
	ll indiEdge = 0;
	rep(i,m) {
		int a, b; a = arr[i].first; b = arr[i].second; int kk = -1;
		rep(i,keys.size()) if ( sets.find(key[i]) == sets.find(a) ||
								sets.find(key[i]) == sets.find(b)) 
		{ kk = key[i]; break;}
		if (kk != -1) my[kk]++;
		else indiEdge++;
	}
	ll indiNode = 0;
	rep(i,keys.size()) indiNode += sets.getSize(keys[i]);
	indiNode = n - indiNode;
	ll sol = 0;
	int maxKey = -1;
	rep(i,keys.size()) {
		int kk = keys[i];
		ll sz = sets.getSize(kk);
		ll tmp = sz * (sz - 1) / 2;
		ll tmp2 = sz * indiNode;
		ll tmp3 = indiNode * (indiNode - 1) / 2 - indiEdge;
		ll cand = (tmp - my[kk]) + tmp2 + tmp3;
		if (sol < cand) { sol = cand; maxKey = kk; }
	}
	if (sol == 0) { cout << sol; return 0; }
	rep(i,keys.size()) {
		int kk = keys[i];
		if (kk == maxKey) continue;
		ll sz = sets.getSize(kk);
		ll tmp = sz * (sz - 1) / 2;
		ll add = tmp - my[kk];
		sol += add;
	}
	cout << sol;
	return 0;
}


" 이건 인생 코드야.. 대단해"
// 내랑 원리는 비슷한데. 기록된 간선을 퉁쳐서 뺄수 있어서 간략화가 쉬웠넹
http://codeforces.com/contest/744/submission/23053853
TooDifficult 의 예술같은 코드 30ms 걸림
const int N = 1010;
int f[N], c[N], sz[N], p[N];
int n, m, k, u, v;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep2(i,1,n+1) f[i] = i;
	rep2(i,1,k+1) scanf("%d", c + i);	// 거점
	rep2(i,0,m) {
		scanf("%d%d", &u, &v);
		f[find(u)] = find(v);	// 이렇게 간단하게 표현할 수 있다니..!!!!
	}
	rep2(i,1,n+1) sz[find(i)]++;	// 캬!!!!
	int ts = n;	// 독립된 정점개수 기록용
	rep2(i,1,k+1) {
		p[i] = sz[find(c[i])];	// 거점이 포함된 영역 사이즈
		ts -= p[i];
	}
	int v = max_element(p+1, p+k+1) - p; // 최대영역 거점 위치
	int ae = 0;
	p[v] += ts;	// 최대영역 거점에 독립된 점들도 포함시킨다.
	rep(i,1,k+1) ae += p[i] * (p[i] - 1) / 2;
	printf("%d\n", ae - m);
}


http://codeforces.com/contest/745/problem/D	// 구글스타일
interactive problem
각 행들의 최소값을 맞추어야 한다. (대각 행렬 제외)
대각 행렬은 0 이다.
질문은 20번까지 할 수 있다.


16 by 16 행렬이 있다 치자 (최대 1024로 확장 될수 있다만)
" 요런 식으로 질의를 하면 "
	xoxoxoxoxoxoxoxo		// 1행의 최소값을 알 수 있다.
	xxooxxooxxooxxoo
	xxxxooooxxxxoooo
	xxxxxxxxoooooooo

"	oxoxoxoxoxoxoxox		// 2행의 최소값을 알 수 있다.
	xxooxxooxxooxxoo
	xxxxooooxxxxoooo
	xxxxxxxxoooooooo

"	xoxoxoxoxoxoxoxo		// 3행의 최소값을 알 수 있다.
"	ooxxooxxooxxooxx		
	xxxxooooxxxxoooo
	xxxxxxxxoooooooo


"	oxoxoxoxoxoxoxox		// 4행의 최소값을 알 수 있다.
"	ooxxooxxooxxooxx		
	xxxxooooxxxxoooo
	xxxxxxxxoooooooo


		....

이런걸 만드는것도 귀찮다만 어떻게 하면 간단하게 짤수 있을까?
	그걸 솔루션에선 엄청 간단하게 표현했다.
	단 질의가 약간 한쪽으로 치우쳐 버렸다만 right shilt bit가 1 이상부턴 왼쪽으로 한간 치우친 질의가 되었다.
	물론 답을 푸는데 충분히 커버가 가능하다. n은 1000 이하이므로 (실제 n이 1022 까지 커버 될걸로 보임)
// solution의 질의는 내 생각과 약간 다른디... // 다른 사람들 솔루션엔 내 생각과 비슷한 사람들이 많았음
int n;
void printBin(vi query) {
	int here = 1;
	for (int i = 0; i < query.size(); ++i) {
		int there = query[i];
		for (; here < there; ++here) cout << 'x';
		cout << 'o'; ++here;
	}
	for (; here <= n; ++here) cout << 'x';
	cout << '\n';
}
int main() {
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	n = 20;
	for (int bit = 0; bit < 10; bit++) {
		for (int val = 0; val <= 1; val++) {
			vi query;
			for (int i = 1; i <= n; ++i)
				if (((i >> bit) & 1) == val)
					query.push_back(i);
			if (query.size() != n && query.size() != 0) {
				cout << query.size() << '\n';
				for (int j = 0; j < query.size(); ++j) {
					if (j != 0) cout << " ";
					cout << query[j];
				}
				cout << '\n';
				printBin(query);
				cout << '\n';
			}
		}
	}
	return 0;
}

10
2 4 6 8 10 12 14 16 18 20
xoxoxoxoxoxoxoxoxoxo
10
1 3 5 7 9 11 13 15 17 19
oxoxoxoxoxoxoxoxoxox

10							// bit: 1, val: 0 // ((i>>bit)&1) == val
1 4 5 8 9 12 13 16 17 20	((1>>1)&1) == 0,
							((10>>1)&1) !=0, 
							((11>>1)&1) != 0, 
							((100>>1)&1) == 0,
							((101>>1)&1) == 0,
							((110>>1)&1) != 0, ...
oxxooxxooxxooxxooxxo
10
2 3 6 7 10 11 14 15 18 19
xooxxooxxooxxooxxoox

11
1 2 3 8 9 10 11 16 17 18 19	
oooxxxxooooxxxxoooox
9
4 5 6 7 12 13 14 15 20
xxxooooxxxxooooxxxxo		// 4행4열, 5행5열, 6행6열, ..., 20행20열은 무쓸모임

12
1 2 3 4 5 6 7 16 17 18 19 20
oooooooxxxxxxxxooooo
8
8 9 10 11 12 13 14 15
xxxxxxxooooooooxxxxx

15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
oooooooooooooooxxxxx
5
16 17 18 19 20
xxxxxxxxxxxxxxxooooo

// 풀이대로 짠거 100ms 걸림
const int INF = 987654321;
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vi mini(n + 1, 1 << 30);
	for (int bit = 0; bit < 10; ++bit) {	// bit: right shift 갯수!!!!
		for (int val = 0; val <= 1; ++val) {
			vi query;
			for (int i = 1; i <= n; ++i)
				if (((i >> bit) & 1) == val)
					query.push_back(i);		// 한 질의를 만들어냄
			if (query.size() != n && query.size() != 0) {	
				// 질의 사이즈가 n이면 무조건 '0'인 놈이 포함되니 무시하자
				// 사이즈 0인것도 당연히 무시
				cout << query.size() << '\n';
				for (int j = 0; j < query.size(); ++j) {
					if (j != 0) cout << " ";
					cout << query[j];
				}
				cout << '\n';	fflush(stdout);

				for (int i = 1; i <= n; ++i) {
					int d; cin >> d;
					if (((i >> bit) & 1) == 1 - val)	// 각 행의 최소값 설정 
														// bit: 0, val: 0, xoxoxoxo 인 경우 // 2, 4, 6, 8 행이 유효하다
														// 노노!!!! 1, 3, 5, 7 행이 유효하다.
														// 2행2열, 4행4열, 6행6열, 8행8열 의 0이 포함되므로 해당 행은 무시
  						mini[i] = min(mini[i], d);
				}
			}
		}
	}
	cout << -1 << '\n';
	for (int i = 1; i <= n; ++i) {
		if (i != 1) cout << " ";
		cout << mini[i];
	}
	cout << '\n';	fflush(stdout);
	return 0;
}
20개의 질의가 각 1000개의 행을 커버 칠수 있다는 것만 몸으로 느낀다.
허나 그 질의가 저렇게 간단히 생성되는게 이해가 안된다.

[
 [0, 3, 2],
 [5, 0, 7],
 [4, 8 ,0],
]

input: 처음 3을(3 by 3 matrix) 뺀 나머지는 컴터가 나의 질문에 출력한 값임
3
0 0 0
2 7 0
0 0 4
3 0 8
0 5 4

output: 내가 출력하는 것
3
1 2 3	// 1, 2, 3 열의 각 최소값을 알고 싶다.
1
3		// 3열의 각 최소값을 알고 싶다.
2
1 2		// 1, 2 열의 각 최소값을 알고 싶다.
1
2		// 2열의 각 최소값을 알고 싶다.
1
1		// 1열의 각 최소값을 알고 싶다.
-1
2 5 4


http://codeforces.com/contest/747/problem/D
// 영어해석이 안된다. ㅅㅄㅄㅄㅠㅠㅠㅠㅠ


http://codeforces.com/contest/747/problem/E
dfs 로 순회하면서 각 깊이대로 기록후 출력하면 되는 문제이다.
',' 부분에서 오류가 남. ㅅㅂ..
	문제를 간략하게 하기 위해
	vs arr 에다가 파싱하여 집어 넣고 할걸... 젠장

input
hello,2,ok,0,bye,0,test,0,one,1,two,2,a,0,b,0

3
hello test one	// 최상단 높이 
ok bye two		// 그다음 높이
a b				// 그그다음 높이

// input을 나타내면
hello
	ok
	bye
test
one
	two
		a
		b

string str;
map<int, vs> my;
"이렇게 파싱하는 함수를 따로 두는게 좋다. 괜히 오류 생기면 고치기도 편하다!!!!"
pair<string, int> get(int& here) {
	if (here == str.size()) return pair<string, int>(); // 필요는 없다.
	string ret1;
	while (here < str.size()) {
		if (str[here] == ',') break;
		ret1.push_back(str[here]);
		here++;
	}
	here++;
	string ret2;
	while (here < str.size()) {
		if (str[here] == ',') break;
		ret2.push_back(str[here]);
		here++;
	}
	here++;
	return mp(ret1, atoi(ret2.c_str()));
}
void rec(int& here, int depth) {
	pair<string, int> ps = get(here);
	my[depth].push_back(ps.first);
	rep(i, ps.second) 
		rec(here, depth + 1);
}
int main() {
	cin >> str;
	int here = 0;
	while (here < str.size()) rec(here, 1);
	cout << my.size() << '\n';
	map<int, vs>::iterator it = my.begin();
	for (; it != my.end(); ++it) {
		rep(i, it->second.size()) 
			cout << it->second[i] << " ";
		cout << '\n';
	}
	return 0;
}



http://codeforces.com/contest/749/problem/C
VOTING
앞에 있는 순서부터 다른 사람의 선거를 방해 할 수 있다.
맨 마지막까 순회를 한 뒤
남은 사람이 DR 조합이면 
남은 사람들 끼리 승부를 반복한다.
승부가 났을때
그 결과를 출력하라


길이 n은 20만까지 가능하다.
5
DDRRR	// D

6
DDRRRR	// R


7
0123456
RDRDDRD	// 내가 틀린것: R // 정답은 D
XXOXOOX		// 4번 D가 0번 R을 죽인다면 (앞놈을 먼저 죽인다면.)

RDR
OXO		// RR 이 되어 R이 남는데....


RDRDDRD // 4번 D가 5번 R을 죽이면 (뒷놈을 먼저 죽이는 식으로 수행한다면)
XXOXOXO	// 6번이 살아 남는다.

RDD
OXO -> XX0 // D가 이긴다.

마지막 D가 남는다.
	// 선거를 무효화 공격하려면 뒷놈을 먼저 조지야 된다.
	// 앞놈은 이미 딴 놈을 조진 상태이기 때문이다. !!!!
	// 뒤엣놈 죽일 거 없으면 그때가서 앞놈을 조져라.

"3번 문제를 너무 만만하게 봤다. 탐욕법으로 풀되 그렇게 간단하진 않을 거란걸 
"생각 좀만 하고 짰으면 하는 아쉬움이 든다.
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;	string str; 	cin >> n >> str;
	while (str.size() > 1) {
		string str2;
		vb deny(str.size(), false);
		int fD = 0, fR = 0;
		int eD = 1, eR = 1;	// 이후에 조질것들 // 이게 더 우선시 된다.
		rep(i, str.size()) {
			if (deny[i] == true) continue;
			bool backDenyUpdate = false;
			if (str[i] == 'D') {
				if (eR < i) eR = i + 1;
				while (eR < str.size()) {
					if (deny[eR] == false && str[eR] == 'R') {
						deny[eR] = true;	eR++;	backDenyUpdate = true;	break;
					}
					eR++;
				}
				if (backDenyUpdate) continue;
				while (fR < str.size()) {
					if (deny[fR] == false && str[fR] == 'R') {
						deny[fR] = true;	fR++;	break;
					}
					fR++;
				}
			}
			else {
				if (eD < i) eD = i + 1;
				while (eD < str.size()) {
					if (deny[eD] == false && str[eD] == 'D') {
						deny[eD] = true;	eD++;	backDenyUpdate = true;	break;
					}
					eD++;
				}
				if (backDenyUpdate) continue;
				while (fD < str.size()) {
					if (deny[fD] == false && str[fD] == 'D') {
						deny[fD] = true;	fD++;	break;
					}
					fD++;
				}
			}
		}
		rep(i, str.size()) {
			if (deny[i] == false) {
				str2.push_back(str[i]);
			}
		}
		if (str == str2) break;
		str = str2;
	}
	cout << str[0];
	return 0;
}


http://codeforces.com/contest/749/problem/D	// 구글스타일
D. Leaving Auction
	
n 명의 사람이 옥션에 참여
n 개의 입찰이 있다.
그들 각각이 다른 사람이란 보장은 없다. !!!!
몇몇은 아예 입찰을 안 할 수도 있다.

ai 입찰한 사람 범호
bi = 입찰 크기

입찰은 연대순

input
6	// 연대순으로 주문한것
1 10		// 1번 사람이 10을 제시
2 100		// 2번 사람이 100을 제시
3 1000
1 10000
2 100000
3 1000000
3
1 3			// 3번 사람이 없다면 누가 낙찰되고 그 금액은 우찌되는가?
2 2 3		// 2, 3번 사람이 없다면 ...
2 1 2		// 1, 2번 사람이 없다면.


output
2 100000
1 10
3 1000


n 이 20만이나 되고
질의도 20만이나 된다...
	" 뭐 유일한 힌트라 할 만한건 k의 합이 20만을 안 넘는다는 거."
	" k의 합이란 생략된 사람의 합"

삽입 삭제를 set처럼 하되 "정렬이 된 상태인" 자료형이 필요하다 !!!!
	" 원소가 pair<최대값, id> 가 되면 된다 !!!!" 특별한 자료형을 요구하진 않네.

먼저 모든 사람에 대해 두개의 값을 저장하자
	하나는 최대 입찰가격
	두번째는 그 사람의 고든 입찰가격 리스트

그 뒤 최대 입찰가격을 기준으로 사람들을 정렬하여 저장한다. (set 형태)

질의가 왔을때 :
	떠나는 사람은 set에서 제거한다. 그뒤 질의에 대한 응답을 한다"(1)"
	그뒤 set을 복원한다.
	이것이 시간내에 가능한 것은 제거되는 사람의 합이 20만을 안 넘기에 가능한 거다

(1) 부분을 계산 하려면
	set이 비었으면 답은 0이다. 그렇지 않으면 최대 값을 지닌 사람이 winner가 된다.
	입찰가격은 두번째로 높은 가격을 가진 사람의 값을 참고하면 된다.
	
		두번째 사람이 없으면 1명만 존재하므로 그 인간의 가장 적은 입찰가가 답임
		그렇지 않으면 두번째로 높은 최대 입찰가보다 크면서
		가장 작은 값이 답이 된다.
		We can apply binary search and find the maximal bid of the second man there.

// 집합형 자료구조며 해당 인덱스별로 지우면서
// 가장 큰 크기를 실시간으로 알려 할때
"set<pair<크기, index>>" 이런 식으로 해결 할 수 있음을 기억해라!!!!! 유용하다.
내가 짜면서 스스로 알게 된거다. 나도 이런걸 짤수 있구나... 시간은 1700ms 로 아슬아슬하게 통과했다.
vi arrList[200002];
int arrMx[200002];
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);	// 요거넣으니까 800ms 로 줄어든다 대박이다. 한번에 출력하려면 이걸 쓰라!!!!
	set<pair<int, int>> my;
	int n; cin >> n;
	rep(i, n) {
		int a, b; cin >> a >> b;
		arrMx[a] = b;
		arrList[a].push_back(b);
	}
	rep2(i, 1, n+1) {
		if (arrMx[i] == 0) continue;	// 인원이 7이더라도 초반에 낙찰에 참가 안한 사람도 있음
		my.insert(mp(arrMx[i], i));
	}
	int q; cin >> q;
	rep(i, q) {
		int k; cin >> k;
		vi delList(k);
		rep(j, k) cin >> delList[j];
		rep(j, k) if (arrMx[delList[j]] != 0) my.erase(mp(arrMx[delList[j]], delList[j]));
		if (my.empty())
			cout << 0 << " " << 0 << '\n';
		else if (my.size() == 1) {
			int id = my.begin()->second;
			cout << id << " " << arrList[id][0] << '\n';
		}
		else {
			set<pair<int, int>>::reverse_iterator jt = my.rbegin();
			int idMx = jt->second;
			jt++; //reverse_iterator 주의점임 !!!!
			int idSe = jt->second;
			int secondMx = arrList[idSe].back();
			int index = upper_bound(arrList[idMx].begin(), arrList[idMx].end(), secondMx)
					  - arrList[idMx].begin();
			cout << idMx << " " << arrList[idMx][index] << '\n';
		}
		rep(j, k) if (arrMx[delList[j]] != 0) my.insert(mp(arrMx[delList[j]], delList[j]));
	}
	return 0;
}



http://codeforces.com/contest/752/problem/B
두 문장이 주어지고 스왑 된 알파벳 쌍을 출력한다. (물론 한번만이다.)
helloworld
ehoolwlroz
3
h e
l o
d z

아래 코드의 병신짓을 찾으시오.
http://codeforces.com/contest/752/submission/23293092
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	map<char, char> my;
	bool ok = true;
	rep(i, str1.size()) {
		if (str1[i] != str2[i]) {
			if (my.count(str1[i])) {
				if (my[str1[i]] != str2[i])
					ok = false;
			}
			else 
				my[str1[i]] = str2[i];
		}
	}
	if (ok == false) {
		cout << -1; 
		return 0;
	}
	//cout << my.size() << '\n';
	map<char, char>::iterator it = my.begin();
	map<char, int> my2;
	map<char, char> my3;
	for (; it != my.end(); ++it) {
		char a = it->first, b = it->second;
		if (my2[a] == 1)
			continue;
		//cout << it->first << " " << it->second << '\n';
		my3[a] = b;		my2[a] = 1;		my2[b] = 1;
	}
	cout << my3.size() << '\n';
	map<char, char>::iterator jt = my3.begin();
	for (; jt != my3.end(); ++jt)
		cout << jt->first << " " << jt->second << '\n';

	return 0;
}
//입력에 대해 처리를 제대로 못함
ss
ms 


아아악.. 그나마 위안인건 2번 문제 해킹 div1 인간들도 많이 당했음요.


int main() {
	string str1, str2;
	cin >> str1 >> str2;
	map<char, char> my;
	bool ok = true;
	rep(i, str1.size()) {
		if (my.count(str1[i]) > 0 && my.count(str2[i]) > 0) {
			if (my[str1[i]] != str2[i])
				ok = false;
			if (my[str2[i]] != str1[i])
				ok = false;
		}
		else if (my.count(str1[i]) == 0 && my.count(str2[i]) == 0) {
			my[str1[i]] = str2[i];
			my[str2[i]] = str1[i];
		}
		else
			ok = false;
	}
	if (ok == false) {
		cout << -1;
		return 0;
	}
	map<char, char> my2;
	map<char, char>::iterator it = my.begin();
	bool use[27];
	memset(use, 0, sizeof(use));
	for (; it != my.end(); ++it) {
		char ch1 = it->first;
		char ch2 = it->second;
		if (ch1 == ch2) continue;
		if (use[ch1 - 'a'] && use[ch2 - 'a']) continue;
		my2[ch1] = ch2;
		use[ch1 - 'a'] = use[ch2 - 'a'] = 1;
		//my.erase(ch2);	// 지우면 안됨 죽어버림..
	}
	cout << my2.size() << '\n';
	it = my2.begin();
	for (; it != my2.end(); ++it)
		cout << it->first << " " << it->second << '\n';
}


http://codeforces.com/contest/748/problem/D
(1 ≤ k, n ≤ 100 000; n·k  ≤ 100 000).
7 3	// k, n, k 줄만큼 문자열과 아름다움:ai ( - 10 000 ≤ ai ≤ 10 000). 이 존재함
abb 2
aaa -3
bba -1
zyz -4
abb 5
aaa 7
xyx 4

12	// beauty 합이 최대가 되는 회문을 만들때 beauty 합을 출력하라 [회문][palindrome]
Santa can obtain abbaaaxyxaaabba by concatenating strings 5, 2, 7, 6 and 3 (in this order).
5 + -3 + 4 + 7 + -1 = 12
각 k개의 문자열은 최대 한번만 사용 가능하다.

// 나의 생각
셀프회문과 그렇지 않은 문장을 구분한다.
map<string, set<int>> org_word;
map<string, set<int>> rev_word;
map<string, set<int>> self_palin;

1)
org_word의 각 단어랑 반대되는 단어들(rev_word의 원소)의
두 beauty 합이 양수인 경우 합한다. // 높은 순서로 처리한다.

2_1)
self_palin 의 각 단어들의 beauty에 대해
양수가 한개 혹은 하나도 남기지 않고 처리한다. // 높은 순서로 짝수개 차감이다.
ex) aba: 9, 4, 5, 22, -1, -3, -4 라면 sol += (22 + 9 + 5 + 4)	// 더이상 aba에 대해 처리할 필요가 없다.
es) bbb: 9, 4, 5, 22, 10, -1, -3 라면 sol += (22 + 10 + 9 + 5)
	// bbb: 10, -1 을 처리해야 한다.

2_2)
양수 음수 그룹에 대해
7, -5		8, -3		// 둘 중 어느걸 가운데에 두는게 유리한고
						// 7 - (7 - 5) : 5만큼 유리
						// 8 - (8 - 3) : 3만큼 유리
						// 7인 놈을 가운데로 두면 됨 // 음수가 큰 놈을 가운데로 두면 답이 된다. 
						// 모든 쌍을 합하고 대신 그 음수만큼 공제해라


윗대로 짰는데 8번째 테스트에서 오류남
const int INF = 7654321;
bool isSelfPalin(const string& str) {
	int n = str.size();
	for (int i = 0; i < n / 2; ++i) {
		int back = n - 1 - i;
		if (str[i] != str[back])
			return false;
	}
	return true;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	if (isSelfPalin("a")) {
		cout << "ok" << endl;
	}
	int k, n; cin >> k >> n;
	map<string, set<int>> org_word;
	map<string, set<int>> rev_word;
	map<string, set<int>> self_palin;

	rep(i, k) {
		string str; int ai; cin >> str >> ai;
		if (isSelfPalin(str))
			self_palin[str].insert(ai);
		else {
			if (org_word.count(str) > 0)
				org_word[str].insert(ai);
			else if (rev_word.count(str) > 0)
				rev_word[str].insert(ai);
			else {
				org_word[str].insert(ai);
				string rev = str;
				reverse(rev.begin(), rev.end());
				rev_word[rev] = set<int>();
			}
		}
	}
	ll sol = 0;
	map<string, set<int>>::iterator it = org_word.begin();
	for (; it != org_word.end(); ++it) {
		string orgKey = it->first;
		string revKey = orgKey;
		reverse(revKey.begin(), revKey.end());
		set<int>::reverse_iterator jt1 = org_word[orgKey].rbegin();
		set<int>::reverse_iterator jt2 = rev_word[revKey].rbegin();
		while (jt1 != org_word[orgKey].rend() &&
			jt2 != rev_word[revKey].rend()) {
			if ((*jt1 + *jt2) < 0) break;
			sol += (*jt1 + *jt2);
			++jt1; ++jt2;
		}
	}

	vpii tmp;
	it = self_palin.begin();
	for (; it != self_palin.end(); ++it) {
		set<int>::reverse_iterator jt = it->second.rbegin();
		bool zero = true;	// 두개씩 넣기 위해
		int prv = 0;
		while (jt != it->second.rend()) {
			if (*jt < 0) break;
			if (zero) {
				prv = *jt;
				zero = false;
			}
			else {
				sol += (prv + *jt);
				zero = true;
			}
			++jt;
		}
		if (zero == false) {
			if (jt == it->second.rend())
				tmp.push_back(mp(prv, -INF));
			else
				tmp.push_back(mp(prv, *jt));
		}
	}
	int cand = 0;
	rep(i, tmp.size()) {
		cand = min(cand, tmp[i].second);
		sol += (tmp[i].first + tmp[i].second);
	}
	sol = sol - cand;	// tmp가 존재시 음수 절대값이 가장 큰 놈을 제거 하면 된다.
	cout << sol;

	return 0;
}


7 1
a 10
a -3
b 9
b -2
b -3
c 8
c 8

beauty 값이 같을때 set은 망했어요.... ㅠㅠ 
// 허나 지문에서 beauty 값은 다 다르다고 했으니 상관없엉
// 뭔 소리냐!! 같을 수도 있다고 하구만... set을 쓰지말고 멀티셋 어때?


// 무사 통과 소스 multiset 사용 187ms 5000kb 메모리 사용. 생각보다 성능 좋네
bool isSelfPalin(const string& str) {
	int n = str.size();
	for (int i = 0; i < n / 2; ++i) {
		int back = n - 1 - i;
		if (str[i] != str[back])
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	int k, n; cin >> k >> n;
	map<string, multiset<int>> org_word;
	map<string, multiset<int>> rev_word;
	map<string, multiset<int>> self_palin;

	rep(i, k) {
		string str; int ai; cin >> str >> ai;
		if (isSelfPalin(str))
			self_palin[str].insert(ai);
		else {
			if (org_word.count(str) > 0)
				org_word[str].insert(ai);
			else if (rev_word.count(str) > 0)
				rev_word[str].insert(ai);
			else {
				org_word[str].insert(ai);
				string rev = str;
				reverse(rev.begin(), rev.end());
				rev_word[rev] = multiset<int>();
			}
		}
	}
	ll sol = 0;
	map<string, multiset<int>>::iterator it = org_word.begin();
	for (; it != org_word.end(); ++it) {
		string orgKey = it->first;
		string revKey = orgKey;
		reverse(revKey.begin(), revKey.end());
		multiset<int>::reverse_iterator jt1 = org_word[orgKey].rbegin();
		multiset<int>::reverse_iterator jt2 = rev_word[revKey].rbegin();
		while (jt1 != org_word[orgKey].rend() &&
			jt2 != rev_word[revKey].rend()) {
			if ((*jt1 + *jt2) < 0) break;
			sol += (*jt1 + *jt2);
			++jt1; ++jt2;
		}
	}

	vpii tmp;
	it = self_palin.begin();
	for (; it != self_palin.end(); ++it) {
		multiset<int>::reverse_iterator jt = it->second.rbegin();
		bool zero = true;	// 두개씩 넣기 위해
		int prv = 0;
		while (jt != it->second.rend()) {
			if (*jt < 0) break;
			if (zero) {
				prv = *jt;
				zero = false;
			}
			else {
				sol += (prv + *jt);
				zero = true;
			}
			++jt;
		}
		if (zero == false) {
			if (jt == it->second.rend())
				tmp.push_back(mp(prv, -INF));	// 숫자(0이상)가 하나만 존재하는 경우 
			else
				tmp.push_back(mp(prv, *jt));	// 숫자(0이상)이 하나 있고 그 뒤 음수가 존재한 경우
		}
	}
	ll cand = 0;
	rep(i, tmp.size()) {
		if ((tmp[i].first + tmp[i].second) > 0) {
			cand += (tmp[i].first + tmp[i].second);
		}
	}
	// 아래 add 계산이 애를 먹였다. ㅋ
	ll add = cand;
	rep(i, tmp.size()) {
		if (tmp[i].second == -INF) {
			// cand 에 더해지지 않은 놈: 두 짝이 아닌 경우
			if (add < cand + tmp[i].first)
				add = cand + tmp[i].first;
		}
		else if ((tmp[i].first + tmp[i].second) <= 0) {
			// cand 에 더해지지 않은 놈: 두 짝의 합이 0 이하인 경우
			if (add < cand + tmp[i].first)
				add = cand + tmp[i].first;
		}
		else {
			// cand 에 더해진 놈: 가운데 두면 두번째 원소를 없는셈
			if (add < cand - tmp[i].second)
				add = cand - tmp[i].second;
		}
	}
	sol = sol + add;	
	cout << sol;
	return 0;
}



http://codeforces.com/contest/752/problem/E
문제 해석하기 조같은 문제 임
고수도 한 두번 틀리고 통과함... ㅅㅄㅂ
푸는방식은 내가 생각한 거랑 똑같다. (이분법)
// 해석이 조같으니 넘긴다. ㅅㅂ
// 다시 도전한다.


학생들이 가질수 있는 귤 조각 중 가장 작은 값이
산타의 즐거움이 된다. 
"산타의 즐거움을 최대화 해라"
// 학생들은 귤을 전체를 가지거나 쪼개진 부분 한 파트를 가질수 있다(한 조각이 아니다)
// 조각으로 나누는데는 규칙성이 있다.
// 항상 귤조각은 되도록 절반으로 쪼갠다.
// 만약 귤 조각이 홀수면 ex) 9 => 4, 5 로 쪼갠다.
// ex) 45 => 22, 23
			11,11,11,12
		5,6, 5,6, 5,6, 6,6
			.......
3 2 // n, k (1 <= n <= 10^6, 1 <= k <= 2*10^9) // n: 귤 수, k: 학생수
5 9 3	// 각 귤의 조각 // 1 <= ai <= 10^7

output
5	// {5}, {5,4} 에서 5조각짜리 선택이므로

2 3
1 1
output
-1

// 왜 21번 테스트에서 틀렸다고 하는지 모르겠다. ㅠㅠㅠㅠㅠㅠ아아아아아
vi arr;
ll n, k;
bool decision(const int slice) {
	ll totalCnt = 0;
	rep(i, n) {
		if (slice > arr[i]) continue;
		ll cnt = 1;
		ll tmp = arr[i];
		while ((tmp/2) >= slice) {
			cnt *= 2;
			tmp /= 2;
		}
		totalCnt += cnt;
	}
	return totalCnt >= k;
}
int main() {
	ios::sync_with_stdio(false);
	while (true) {
		cin >> n >> k;
		arr.resize(n);
		rep(i, n) cin >> arr[i];
		int lo = 0, hi = 10000002;
		// decision(lo) == true, decision(hi) == false
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (decision(mid)) // 이 항수에 0이 인자로 들어갈 일은 없으니 안심하자
				lo = mid;
			else
				hi = mid;
		}
		if (lo == 0) lo = -1;
		cout << lo << '\n';
	}
	return 0;
}

1 3
19

output 이 "5" 가 나와야 됨
	헌데 4가 나오는 오류를 범함...ㅠㅠ


통과함 1700ms 걸림...
vi arr;
ll n, k;
bool decision(const int slice) {
	ll totalCnt = 0;
	rep(i, n) {
		if (slice > arr[i]) continue;
		if (slice == 1) {		// 1에 대해선 예외처리요.. ㅅㅂ
			totalCnt += arr[i];
			continue;
		}
		ll denom = 1;
		while (denom * 2 * slice <= arr[i]) denom *= 2;
		ll cand1 = denom;

		// 한쪽이 slice 보다 1개 작으면 남은쪽은 그것보다 1큼 (slice)
		// 1큰 수의 갯수는 전체 잎노드의 갯수를 넘길수 없다.
		if (slice > 1) {
			denom = 1;
			while (denom * 2 * (slice - 1) <= arr[i])
				denom *= 2;
			ll tmp = arr[i] - denom * (slice - 1);
			ll cand2 = 0;
			if (tmp <= denom) cand2 = tmp;

			ll cnt = max(cand1, cand2);
			totalCnt += cnt;
		} else
			totalCnt += cand1;
	}
	return totalCnt >= k;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	arr.resize(n);
	rep(i, n) cin >> arr[i];
	int lo = 0, hi = 10000002;
	// decision(lo) == true, decision(hi) == false
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid)) 
			lo = mid;
		else
			hi = mid;
	}
	if (lo == 0) lo = -1;
	cout << lo;
	return 0;
}

// 균등하게 나눌때 잎의 결과를 빨리 계산할 수 있는 방법을 알아내자 !!!!"
		17
	   /  \
	  8    9
	 /\    /\
    4  4  4  5

즉 5가 하나는 존재한다.

	    18
	   /  \
	  9    9
     /\    /\
    4  5  4  5
5가 2개 존재한다.
		
		19
	   /  \
	  9	   10
     /\    / \
    4  5  5   5
5가 3개 존재한다

암만 차이나야 1칸 차이가 난다. (균등하게 쪼개진다면 말이지)
그렇담 slice 가 x 인 경우 최대 x개수는 얼마인가?
a = x - 1 이라고 치자.
잎이 a라 가정하에 잎의 수는 2의 지수승 (1, 2, 4, 8 ...) 이 된다.
전체갯수 - a * (잎의수) = x의 개수가 될 수 있다.
허나 이때 x의 갯수가 총 잎의 수를 넘긴다면 "무효"가 된다!!!!

무효 예시)
		19
	   /  \
	  17   2
이 경우 잎은 당연히 1개이며(19는 17의 두배가 안되기에) 나머지는 2이므로 모순 발생


코드상 slice가 1인 경우 내코드는 무한루프에 빠져버렸다.
1인 경우 예외처리 했다만 "if (slice > 1)
그런 경우 다른 문제점이 생긴다.
그래서 추가 예외코드를 또 집어 넣었다.
더럽다. 코드....ㅠㅠ

// 깔끔하고 빠른 코드... 감동코드 !!!! (정답보다 더 깔끔한거 같다...) 구글용급에네
http://codeforces.com/contest/748/submission/23329666
int a[2000000];	// 8메가바이트
ll b[10000002], c[10000002];	// 166메가바이트임 ..(문제 제약은 256메가바이트)
"long long 1천만개 : 80메가바이트
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	rep2(i,1,n+1) scanf("%d", &a[i]);
	ll int count = 0, lol = 0;
	rep2(i,1,n+1) b[a[i]] += 1;
	for (int i = 10000000; i >= 1; --i) {
		lol += b[i];
		lol -= c[i];	// c[i] 중복덧셈을 공제하는 용도
		b[i - i/2] += b[i];
		b[i/2] += b[i];
		c[i - i/2] += b[i];	// 만약 i가 3이면 두수는 1, 2 가 될텐데
							// 이땐 높은 숫자에 공제를 한번 하면
							// 낮은 숫자엔 공제를 할 필요가 없지
							// 천젠데...
		if (lol >= k) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
}
1 3
3 

i = 3	lol = b[3] = 1				b[2] = 1		b[1] = 1	c[2] = 1
i = 2	lol += (b[2] - c[2]) = 1	b[1] += 2 = 3				c[1] = 1
i = 1	lol += (b[1] - c[1]) = 3




http://codeforces.com/contest/750/problem/C
"아악 "
변동하는 점수량이 음수 혹은 0도 가능이라 해석했다..
"유저의 점수는 음수, 혹은 0도 가능이란 뜻이다. !!!!" ㅠㅠ
Every Codeforces user has rating, described with one integer, possibly negative or zero.

input
3
-7 1	// 현재 div1 에서 시험을 치고 점수변화 -7을 받음	// div1) a: 1900,	b: INF
5 2		// div2에서 시험을 치고 점수변화 +5을 받음			// div2) a:1893,	b: 1899
8 2		// div2에서 시험을 치고 점수변화 +2를 받음			// div2) a:1898,	b: 1899
															// b에서 +8을 하면 sol : 1907
output
1907

input
2		// n: 200000
57 1	// ci: -100 ~ 100
22 2
output
Impossible

1
-5 1
Infinity

"Infinity 처리는 범위처리를 해야함"
점수변화가 일어난 뒤 b(작은점수범위) 가 div2 기준을 충족 못시키거나(1900 이상)
					 a(큰점수범위) 가 div1 기준을 충족 못시키면(1900 미만)
"Impossible"임


const ll INF = 1ull << 55;
bool isINF(ll a) {	// 이런 식으로 체킹하는 것 좋았음요.
	if ((INF - (1ull << 50)) < a && a < (INF + (1ull << 50)))
		return true;
	return false;
}
// a,b 과거의 점수가 현재의 레벨을 만족시키는가 확인 및 점수 범위 갱신
bool check(ll& a, ll& b, int div) {	
	if (div == 1) {
		if (b >= 1900) {
			if (a < 1900)
				a = 1900;
			return true;
		}
		else return false;
	}
	else {
		if (a >= 1900) {
			return false;
		}
		else {
			if (b >= 1900)
				b = 1899;
			return true;
		}
	}
	return true;	// oops
}
int main() {
	ios::sync_with_stdio(false);
	bool allOK = true;
	int n; cin >> n;
	ll a, b;
	vector<ll> ci(n), di(n);
	cin >> ci[0] >> di[0];
	if (di[0] == 1) a = 1900, b = INF;
	else a = -INF, b = 1899;	// 내가 틀린것 a = 0 이라 설정해서 였음...ㅠㅠ
	int prePt = ci[0];
	int preDiv = di[0];
	rep2(i,1, n) {
		cin >> ci[i] >> di[i];
		a += prePt, b += prePt;
		bool ok = check(a, b, di[i]);	// a, b는 과거의 점수, di[i]: 현재의 레벨
		if (ok) {
			prePt = ci[i];
			preDiv = di[i];
		}
		else {
			allOK = false;
		}
	}
	if (allOK == false)
		cout << "Impossible";
	else {
		a += prePt, b += prePt;
		if (isINF(b))
			cout << "Infinity";
		else
			cout << b;
	}
	return 0;
}

http://codeforces.com/contest/750/problem/C	// 구사과소스
int st = -1e9, ed = 1e9;
int n;
int c[200005], d[200005];
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d %d",&c[i],&d[i]);
	}
	int pl = 0;
	for(int i=n-1; i>=0; i--){
		pl -= c[i];
		if(d[i] == 1){
			st = max(st, 1900 - pl);
		}
		else{
			ed = min(ed, 1899 - pl);
		}
	}
	if(ed > 1e8){
		cout << "Infinity";
		return 0;
	}
	if(st > ed){
		cout << "Impossible";
		return 0;
	}
	cout << ed;
}

http://codeforces.com/contest/750/submission/23428409
int n,c[200001],d[200001];
int main()
{

	int LL=-1e9, RR=1e9, now_x=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&c[i],&d[i]);
		if(d[i]==2) /// x+(now_x) <= 1899
			RR=min(RR, 1899-now_x);
		else /// x+(now_x) >= 1900
			LL=max(LL, 1900-now_x);
		now_x+=c[i];
	}
	if(RR==1e9) puts("Infinity");
	else if(LL>RR) puts("Impossible");
	else cout<<RR+now_x;
	return 0;
}


http://codeforces.com/contest/750/problem/D
// 불꼿놀이
// 30번의 분기가 있음
// 2갈래로 뻗음
// 한 불꼿분기의 길이는 1 ~ 5 임
// 칸이 칠해진 갯수를 구하라
나는 특별한 수의 규칙성이 있나 그리디하게 풀려고 생각했음..ㅠㅠ
비둘기집을 생각해낼걸.... 아쉽다. ㅠㅠ
전체 칠할수 있는 범위가 작다는 걸 알았어야 했어..
"게다가 bool 로는 공간복잡도가 커버 안되니 bitset을 사용한걸 눈여겨 보자!!!!"
"전체복잡도는 165*165*32* 8 * 5 가 된다."
// 871200 * 8 * 5 = 6969600 * 5 = 34848000
int t[105];
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1 };
const int C = 30 * 5 + 15;	// 위로 5칸 쭉 가봐야 30번, 150칸임
bitset<8> M[2*C][2*C][32];	// 165 * 165 * 32 * 8
bool ans[2*C][2*C];
int total;
void rec(int x, int y, int i, int n, int dir) {
	if (i == n) return;
	if (M[x+C][y+C][i][dir]) return;
	M[x+C][y+C][i][dir] = true;
	for (int it = 0; it < t[i]; ++it) {	// 최대: 5번 시행
		x += dx[dir], y += dy[dir];
		if (!ans[x + C][y + C]) {
			++total;
			ans[x + C][y + C] = true;
		}
	}
	rec(x, y, i + 1, n, (dir + 1) % 8);
	rec(x, y, i + 1, n, (dir + 7) % 8);
}
int main() {
	int n;
	scanf("%d", &n);
	rep(i,n) scanf("%d", &t[i]);
	rec(0, 0, 0, n, 0);
	printf("%d\n", total);
}



http://codeforces.com/contest/750/submission/23430583
int mk[333][333];
int vis[333][333][31][8];	// 이래도 용량부족은 안일어나넹
int n, t[31];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void mark(int x, int y, int sz, int dir){
	for(int i=1; i<=sz; i++){
		mk[x+dx[dir] * i][y + dy[dir] * i] = 1;
	}
}
void bktk(int x, int y, int d, int v){
	if(d == n) return;
	if(vis[x][y][d][v]) return;
	vis[x][y][d][v] = 1;
	mark(x, y, t[d], v);
	bktk(x + dx[v] * t[d], y + dy[v] * t[d], d+1, (v+1)%8);	// 이런 형식 (v+1)%8 은 좋네!!!!
	bktk(x + dx[v] * t[d], y + dy[v] * t[d], d+1, (v+7)%8);
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> t[i];
	bktk(160, 160, 0, 0);	// 기준을 160, 160으로 함
	int cnt = 0;
	for(int i=0; i<333; i++){
		for(int j=0; j<333; j++){
			if(mk[i][j]) cnt++;
		}
	}
	cout << cnt;
}

// 안보고 (외워서...) 내가 제출한 코드 31ms 걸린다. 위에건 15ms임
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int mark[330][330];
int cache[330][330][32][8];
int n, t[31];
void rec(int x, int y, int k, int dir) {
	if (k == n) return;
	if (cache[x][y][k][dir]) return;
	cache[x][y][k][dir] = 1;
	rep2(i, 1, t[k] + 1)
		mark[x + dx[dir] * i][y + dy[dir] * i] = 1;
	x += dx[dir] * t[k];	y += dy[dir] * t[k];
	rec(x, y, k + 1, (dir + 1) % 8);
	rec(x, y, k + 1, (dir + 7) % 8);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) cin >> t[i];
	rec(165, 165, 0, 0);
	int sol = 0;
	rep(i, 330) rep(j, 330) if (mark[i][j] == 1) sol++;
	cout << sol;
	return 0;
}


http://codeforces.com/contest/757
http://codeforces.com/contest/757/problem/B
n개의 포켓몬이 있다. 10^5 이하
각각의 힘은 1이상 10^5 이하이다
	각 힘의 최대공약수가 1인 경우 싸운다.
싸움을 피하는 포켓몬 집합의 최대 크기를 구하라.(최대공약수가 1이 아닌 최대집합을 구하라)
각 숫자가 어떤 소수를 약수로 가지는지 기록한다.
가장 많이 기록된 소수의 갯수가 답이 된다.

복잡도 sqrt(n) * n 이 된다.
// 234ms 걸림
vector<int> factorSimple(int n) {
	vector<int> ret;
	int sqrtn = int(sqrt(n));
	for (int div = 2; div <= sqrtn; ++div)
		//div가 2인 상태에서 n%div == 0인 케이스를 처리했다면
		//div가 4, 6, 8, ...은 당연히 n%div == 0이 될 수 없군
		while (n % div == 0) {
			n /= div;
			ret.push_back(div);
		}
	if (n > 1) ret.push_back(n);
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vi arr(n);
	rep(i, n) cin >> arr[i];
	map<int, int> my;
	rep(i, n) {
		vi tt = factorSimple(arr[i]);
		map<int, int> tmp;
		rep(j, tt.size()) tmp[tt[j]]++;
		map<int, int>::iterator it = tmp.begin();
		for (; it != tmp.end(); ++it) {
			int key = it->first;
			my[key]++;
		}
	}
	int sol = 1;
	map<int, int>::iterator it = my.begin();
	for (; it != my.end(); ++it) {
		int key = it->first;
		if (key == 1) continue;
		sol = max(sol, it->second);
	}
	cout << sol;
	return 0;
}

// algoshipda 코드 109ms 걸림
int p[100005];
int n;
int a[100005];
int cnt[100005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    int m = x;
    for (int j = 2; j * j <= x; ++j) {
      bool chk = false;
      while (m % j == 0) {
        m /= j;
        chk = true;
      }
      if (chk) cnt[j]++;
    }
    if (m > 1) cnt[m]++;
  }
  int ans = 1;
  for (int i = 2; i <= 100000; ++i) ans = max(ans, cnt[i]);
  printf("%d\n", ans);
}


http://codeforces.com/contest/757/problem/C
각각의 체육관이 있고 그 체육관에는 포켓몬들이 있음
	체육관의 수는 1 <= n <= 10^5
	포켓몬의 총 종류는 1 <= m <= 10^6

각 체육관별 포켓몬의 수는 1 <= gi <= 10^5 이다.
	그리고 전체 포켓몬의 수는 (the sum of all gi) 5 * 10^5 를 넘지 않는다.

진화 계획서를 만든다. 각 포켓몬 종류별 진화하는 표를 만드는 것이다.
제약이 있다. 진화한 뒤에도 포켓몬 종류별 갯수는 같아야 한다. (그것도 체육관별로 말이다.)
the number of Pokemon of each type in each of the gyms remains the same.

지 경우 진화 계획서는 총 몇개를 만들수 있을까?
답이 엄청 커질수 있으므로
출력은 해의 10^9 + 7를 나눈 나머지를 한다.

2 3
2 1 2	// 1번 체육관 포켓몬 2개 (타임 1, 2)
2 2 3	// 2번 체육관 포켓몬 2개 (타입 2, 3)

이경우 { 1->1, 2->2, 3->3 } 진화 계획서는 하나만 만들수 있다.


2 4
2 1 2		// 1번 체육관 포켓몬 2개 (타입 1, 2)
3 2 3 4		// 2번 체육관 포켓몬 3개 (타입 2, 3, 4)
이 경우 { 1->1, 2->2, 3->3, 4->4 }
		{ 1->1, 2->2, 3->4, 4->3 } 두개가 된다.

1 2		// 1번 체육관
2 3 4	// 2번 체육관

1 2		// 1번 체육관
2 4 3	// 2번 체육관	// 각 타입별 갯수는 과거랑 동일하니 성립된다.




페이스북 헤커컵 라운드1 1번문제
// https://www.facebook.com/hackercup/problem/1800890323482794/
N day가 있음
i번째 날엔 M개의 파이들을 판다	// M 은 고정
	그 날 j번째의 파이의 비용은 Cij 이다
너는 그날 서브셋만큼의 파이를 선택해서 살수 있다(안사도 됨)
가게는 파이에 미친 놈을 막고자 특별한 장치를 가짐
	니가 p파이들을 산다면 세금이 p^2 달러 만큼 붙는다(갯수의 제곱)
"파이를 매일 먹을수 있도록 하는 최소비용을 구하라"
3 2			// N, M
1 1			// 이날 2개를 산다 : 1*2 + 2^2 = 6
100 100		// 이날 1개를 산다 : 100*1 + 1^1 = 101
10000 10000

// 토탈 107이 된다.

1 <= N, M <= 300		// 하루 파이 최대 300개 // 전체 최대 9만개
1 <= Cij <= 1000000 // 파이의 비용

N일까지 N개의 파이를 모으면 된다.

int cache[305][305];	// day, 모은 파이들
int psum[305][305];
int N, M;
int partCalc(int day, int cnt) {
	if (M < cnt) return INF;
	return psum[day][cnt] + cnt * cnt;
}
int rec(int day, int pie) {
	if (day == 0 && pie == 0) return 0;
	if (day == 0 && pie != 0) return INF;
	int& ret = cache[day][pie];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = day - 1; i <= pie; ++i)
		ret = min(ret, rec(day - 1, i) + partCalc(day, pie - i));
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	rep(cc, T) {
		memset(cache, -1, sizeof(cache));
		memset(psum, 0, sizeof(psum));
		cin >> N >> M;
		vvi cArr(N + 1, vi(M+1));

		rep(i, N) rep(j, M) cin >> cArr[i + 1][j + 1];
		rep(i, N) sort(cArr[i + 1].begin(), cArr[i + 1].end());
		rep2(i, 1, N + 1) {
			rep2(j,1,M+1)
				psum[i][j] = psum[i][j - 1] + cArr[i][j];
		}
		int sol = rec(N, N);
		cout << "Case #" << cc + 1 << ": " << sol << '\n';
	}
	return 0;
}


ll N, R;
vector<pair<ll, ll>> arr;
int check[51];
void rectCheck(int here, int dt, int type) {
	ll x = arr[here].first, y = arr[here].second;
	rep(i, arr.size()) {
		if (here == i) check[i] += dt;
		else {
			ll nx = arr[i].first, ny = arr[i].second;
			if (type == 0) {	// 1사분면
				if (nx < x || ny < y) continue;
				if (x + R >= nx && y + R >= ny) check[i] += dt;
			}
			if (type == 1) {	// 2사분면
				if (nx > x || ny < y) continue;
				if (x - R <= nx && y + R >= ny) check[i] += dt;
			}
			if (type == 2) {	// 3사분면
				if (nx > x || ny > y) continue;
				if (x - R <= nx && y - R <= ny) check[i] += dt;
			}
			if (type == 3) {	// 4사분면
				if (nx < x || ny > y) continue;
				if (x + R >= nx && y - R <= ny) check[i] += dt;
			}
		}
	}
}
int getCnt() {
	int ret = 0;
	rep(i, N) if (check[i]) ret++;
	return ret;
}
void printC() {
	rep(i, N) cout << check[i] << " ";
	cout << '\n';
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	rep(cc, T) {
		cin >> N >> R;
		arr.resize(N);
		rep(i, N) {
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr.begin(), arr.end());
		int sol = 0;
		rep(i, arr.size()) {
			for (int type1 = 0; type1 < 4; ++type1) {
				memset(check, 0, sizeof(check));
				rectCheck(i, 1, type1);
				rep(j, arr.size()) if (i != j) {
					for (int type2 = 0; type2 < 4; ++type2) {
						//cout << "start i:" << i << " " << "j: " << j <<'\n';
						rectCheck(j, 1, type2);
						//printC();
						int cand = getCnt();
						if (sol < cand) sol = cand;
						rectCheck(j, -1, type2);
						
						//printC();

						cand = getCnt();
						if (cand >= 2)
							cand = cand;
					}
				}
			}
		}
		cout << "Case #" << cc + 1 << ": " << sol << '\n';
	}
	return 0;
}

http://codeforces.com/contest/755/problem/C
5
2 1 5 3 3	// 각 노드별 가장 멀리 떨어진 노드를 input으로 준다. // 한개짜린 자기자신

// 몇개의 포리스트가 있는가 
// 기본적으로 입력에 주어진 포리스트들은 최소 2개의 노드를 갖는다고 생각하고 풀었으나 .. 
// 1개짜리 노드를 가진 포리스트도 있네
1
1
	output 1

// 내 인생 코드라 기록해둔다.
int f[10003];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep2(i, 1, n + 1) f[i] = i;
	for (int i = 1; i <= n; ++i) {
		int v; cin >> v;
		f[find(i)] = find(v);
	}
	map<int, int> my;
	rep2(i, 1, n + 1) my[find(i)]++;
	cout << my.size();
	return 0;
}



http://codeforces.com/contest/755/problem/D
대각선이 한점에 3개가 겹치지 않는 도형이 있고
gcd 가 1이 아닌 것 만큼 대각선을 그린다고 할때
	나누어진 도형의 갯수를 구하여라

"그림 그리면 규칙성 나옴"

구사과 소스가 내 생각과 비슷함.
k 만큼 이동된 곳과 선분을 그리면 
	그 사이에 그려진 변들을 만나는 것만큼 쪼개지는 부분이 증가. 
	자체 그리는 것(+1) 을 추가해줘야 함

	"그 사이에 그려진 변들의 갯수를 빨리 파악하는 방법" bit(fenwick tree) 를 사용하면 된다.


ll n, k;
struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {}
	//A[0..pos]의 부분 합을 구한다.
	int sum(int pos) {
		//인덱스가 1부터 시작한다고 생각하자
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1); //1010 - 1 => 1001, 1010 & 1001 => 1000
		}
		return ret;
	}
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);	
		}
	}
};
ll calc(ll pre, ll here, FenwickTree& tree) {
	ll ret = 0;
	// here 이전의 점과 pre 이후의 점의 갯수를 샌다.(그놈들이 새로 긋는 엣지랑 크로스 되는 갯수)
	if (pre < here) ret = tree.sum(here - 1) - tree.sum(pre); 
	// pre 가 n - 1 이면 here 이전만 계산
	else if (pre == n - 1) ret = tree.sum(here - 1);
	else {
		// 0번 정점을 걸치게 되면
		ll tmp1 = tree.sum(n - 1) - tree.sum(pre);
		ll tmp2 = tree.sum(here - 1);
		ret = tmp1 + tmp2;
	}
	ret++;
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	ll here = 0;	// 나머지 연산을 취하는게 있다면 here 을 
					// 1 감소시킨 0부터 시작하는게 좋다.!!!! 구현이 쉬워짐
	ll cnt = 1;
	FenwickTree tree(n);
	for (int i = 1; i <= n; ++i) {
		int pre = here;
		here += k;
		here %= n;
		ll tmp = calc(pre, here, tree);
		cnt += tmp;
		cout << cnt << " ";
		tree.add(pre, 1);
		tree.add(here, 1);
	}
	return 0;
}

"상상력을 키우자!!!!"
1000000 500001 // 이럼 내 생각이 망하네 : 이 케이스는 생각도 못했다. ㅠㅠ 
2 4 7 11 16 22 29 37	// ... 내거 출력
2 3 5 8 12 17 23 30		// 정답

500001 을 움직일때 반시계방향이라 생각하면 100000 - 500001 만큼 이동으로 취급해도 된다!!!!
// 888ms 걸림 통과~
ll n, k;
... 상동
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if (n < k * 2) k = n - k; // !!!! 요것만 추가
	ll here = 0;	// 나머지 연산을 취하는게 있다면 here 을 
					// 1 감소시킨 0부터 시작하는게 좋다.!!!! 구현이 쉬워짐
	ll cnt = 1;
	FenwickTree tree(n);
	for (int i = 1; i <= n; ++i) {
		int pre = here;
		here += k;
		here %= n;
		ll tmp = calc(pre, here, tree);
		cnt += tmp;
		cout << cnt << " ";
		tree.add(pre, 1);
		tree.add(here, 1);
	}
	return 0;
}


http://codeforces.com/contest/758/problem/D	// 구글형식
2 <= n <= 10^9		// 진법
0 <= k < 10^60		// x 라는 수를 n 진법으로 표현했을 때 나타난 숫자열임
					// 단 10 이상인 경우 두자리이상으로 나타낼 수 있다.
					// ex) n이 16 이고 k가 11311
					// x는 1*16^2 + 13*16 + 11 = 475 가 된다.
					// 이때 x는 가장 작은 수여야 한다.
					// (k는 사이즈가 최대 61인 스트링이다.)
					// n 이 10진법이고 k가 10^60 - 1 이면
					// x 는 10^60 - 1 이 되므로 long long 으로 표현 불가능하다...으
input
13
12 // 12

16
11311	// 475

20
999	// 3789

17
2016	// 594


// 알고스팟 원주율 문제랑 유사하다고 판단 
// 통과는 안된 코드임. 
const ll INF = 1ull << 62;
ll n;
string str;
ll cache[500][10000];
ll set1(ll here, ll r) {
	string tmp = str.substr(r, here - r + 1);
	ll ret = atoll(tmp.c_str());
	return ret;
}
ll set11(ll here, ll r) {
	string tmp = str.substr(r, here - r + 1);
	if (tmp[0] == '0') tmp[0] = '1';
	ll ret = atoll(tmp.c_str());
	return ret;
}
ll set2(ll place, ll tt) {
	if (tt == 0) return 0;
	ll ret = 1;
	for (int i = 0; i < place; ++i) ret *= n;
	ret *= tt;
	return ret;
}
ll rec(ll here, ll place) {
	if (here < 0) return 0;
	ll& ret = cache[here][place];
	if (ret != -1) return ret;
	ret = INF;
	for(int r = here; r >= 0; r--) {
		ll value = set1(here, r);
		if (value > n) break;
		if (set11(here, r) > n) break;
		ll value2 = set2(place, value);
		ret = min(ret, rec(r - 1, place + 1) + value2);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> n >> str;
	ll sol = rec(str.size() - 1, 0);
	cout << sol;
	return 0;
}


128비트 정수형에 자유로운 파이썬이 부럽다.
http://codeforces.com/contest/758/submission/23962814
// pypy2 : 109ms 걸림
n = input()
m = raw_input()
if (int(m) == 0):
    print 0
    exit()

ok = [[0] * (len(m)+1) for i in xrange(len(m)+1)]

ok[0][len(m)] = 1;
for i in xrange(len(m)-1, -1, -1):
    for j in xrange(1, len(m)+1):
        for k in xrange(i, len(m)):
            st = m[i:k+1]
            if (len(st) > 1 and st[0] == '0'):
                continue
            if (int(st) < n and ok[j-1][k+1]):
                ok[j][i] = 1;

rem = -1
for q in xrange(1, len(m)+1):
    if ok[q][0]:
        rem = q
        break

cur = 0
l = len(m)
ans = 0
while (cur < l):
    for i in xrange(cur, len(m)):
        st = m[cur:i+1]
        val = int(st)
        if (val < n and ok[rem-1][i+1]):
            ans += n ** (rem-1) * val
            rem -= 1
            cur = i+1
            break
print ans

"헌데 솔직히 128비트 자료형이 필요한 코드는 문제에선 거의 안나온다"
"이경우 내 생각을 바꿔서 그리디하게 접근하면 풀릴것이다"!!!!



http://codeforces.com/contest/760/problem/D
버스표
	1: 한 여행에 20 rubles
	2: 90 분간 사용가능 50 rubles
	3: 1440 분간 사용가능 120 rubles

여행갯수 n : (1 <= n <= 10^5)
각 공용차량의 시작시간 ti : (0 <= ti <= 10^9)
	ti+1 > ti holds for all (1 <= i < n)
추가설명: 90 분짜리 티켓을 사용한다 할 경우 시작시간이 30 이면
			119 분에 출발을 시작하는 차량을 탈수 있다.
			// 120분에 출발을 시작하는 차량은 탈수 없다네
10		// 출발할 수
13	// 20
45	// 20	: 추가될 비용만 출력하면 됨
46	// 10	: 이때부턴 90분짜리 표를 끊는다. 
60	// 0
103	// 20
115	// 0	: 13분에 출발하는 걸 1번 표로 처리하고 45분에 출발하는것 2번표 사용하면 됨
126	// 0
150	// 20
256	// 20	: min{ dp[255] + 20, dp[166] + 50, dp[0] + 120 } // 첫번째거 선택됨, index 의 의미는 이하중 가장 큰 key
516	// 10	: min{ dp[515] + 20, dp[426] + 50, dp[0] + 120 } // 세번째거 선택됨
	// dp[516] - dp[256] = 120 - 110 = 10

dp[103] = min{	dp[13 이하 중 가장 큰 key] + 90,
				dp[102 이하 중 가장 큰 key] + 20,
				dp[(103 - 1440) 이하 중 가장 큰 key] + 120 }
키를 찾는건 lower_bound 를 이용하자

각 출력은 dp[현 key] - dp[이전 key] 로 하면 된다.

// 시작하기에 앞서, bound 관련 함수는 요래 돌아간다.
map<int, int> my;
	map<int, int>::iterator it, jt;
	my[1] = 3;
	my[5] = 10;
	it = my.lower_bound(0);	// 0 이상 중에서 가장 작은거 my[1]
	it = my.lower_bound(1); // 1 이상 중에서 가장 작은거 my[1]
	it = my.lower_bound(2); // 2 이상 중에서 가장 작은거 my[5]
	it = my.lower_bound(5); // 5 이상 중에서 가장 작은거 my[5]
	it = my.lower_bound(6);	// end
	it = my.lower_bound(7);	// end

	jt = my.upper_bound(0);	// 0 초과 중에서 가장 작은거 my[1]
	jt = my.upper_bound(1); // 1 초과 중에서 가장 작은거 my[5]
	jt = my.upper_bound(2); // 2 초과 중에서 가장 작은거 my[5]
	jt = my.upper_bound(5); // 5 초과 중에서 가장 작은거 end
	jt = my.upper_bound(6); // end
	jt = my.upper_bound(7); // end
	// 해당 수 이상이거나, 초과하는 경우를 찾는 때만 쓸수 있넹..
	// 그럼 지저분하게 음수처리로 공략해야하나...
	// 아님 해당 수 이하이거나, 미만인 경우를 찾아주는 함수가 있나?
"음수 처리나 공략하자..ㅠㅠ" 더 어려운데..
꼼수로 해결합세


int main() {
	ios::sync_with_stdio(false);
	map<int, int> my;
	map<int, int>::iterator it;
	int n; cin >> n;
	my[-1] = 0;	// key 가 0도 가능한데 나는 그걸 착각해서
				// my[0] = 0 으로 해서 4번째 케이스 0에서 출발하는게 있는 놈에서 out됨
	rep(i, n) {
		int t; cin >> t;
		my[t] = INF;
		int key1 = -1, key2 = -1, key3 = -1;
		it = my.lower_bound(t - 1);
		if (it->first > t - 1) {	// 해당키를 넘기는 경우
			if (it != my.begin()) {	// 최초인 경우 예외처리됨 key 는 -1 유지함
				it--;
				key1 = it->first;
			}
		} else key1 = it->first;
		
		it = my.lower_bound(t - 90);
		if (it->first > t - 90) {
			if (it != my.begin()) {
				it--;
				key2 = it->first;
			}
		} else key2 = it->first;
		
		it = my.lower_bound(t - 1440);
		if (it->first > t - 1440) {	// it->first 가 -1 이면 key 는 -1을 유지함요.
			if (it != my.begin()) {
				it--;
				key3 = it->first;
			}
		} else key3 = it->first;
		
		int value = min(my[key1] + 20, my[key2] + 50);
		value = min(value, my[key3] + 120);
		my[t] = value;
		cout << my[t] - my[key1] << '\n';
	}
	return 0;
}







http://codeforces.com/contest/762/problem/B
2 1 1	// usb 규격 컴퓨터 수, ps/2 컴퓨터 수, 범용 컴퓨터 수
4		// 총 마우스 4개
5 USB	// 비용과 마우스 규격
6 PS/2
3 PS/2
7 PS/2

output 3 14	// 총 3개 USB: 5, PS/2: 3, 6

// 선택의 우선순위: USB == PS/2 > 범용 순으로 채우면 된다. (범용은 맨 마지막이다)
// 아래 소스에선 USB, PS/2, 범용 순으로 선택을 하였다.
// 다른것은 볼 필요 없다만 set, multiset 의 iterator 를 요소로 erase 를 수행하면
"리턴되는 값은 다음 iterator!!!! 가 된다."
// 가격과 타입이 같은 경우를 관가해서 set을 사용해서 테스트에서 실패함 !!!!
// multiset 으로 바꾸니 통과
// 다른건 특별히 볼 필요 없다. 솔직히 구린 코드다.
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	/*
	set<int> test;
	rep(i, 10) test.insert(i);
	set<int>::iterator it1, jt;
	it1 = test.begin();
	it1++;
	jt = test.erase(it1);
	*/
	int a, b, c;
	cin >> a >> b >> c;
	int n; cin >> n;
	multiset<pair<int, int>> myS;
	rep(i, n) {
		int price;
		string str;
		cin >> price >> str;
		if (str == "USB")
			myS.insert(mp(price, 0));
		else
			myS.insert(mp(price, 1));

	}
	set<pair<int, int>>::iterator it = myS.begin();
	ll sol1 = 0, sol2 = 0, cnt = 0;
	rep(i, a) {
		while (it != myS.end()) {
			if (it->second == 0) break;
			it++;
		}
		if (it == myS.end()) break;
		sol1++;
		sol2 += it->first;
		it = myS.erase(it);
	}
	it = myS.begin();
	rep(i, b) {
		while (it != myS.end()) {
			if (it->second == 1) break;
			it++;
		}
		if (it == myS.end()) break;
		sol1++;
		sol2 += it->first;
		it = myS.erase(it);
	}
	it = myS.begin();
	rep(i, c) {
		if (it == myS.end()) break;
		sol1++;
		sol2 += it->first;
		it = myS.erase(it);
	}
	cout << sol1 << " " << sol2;
	return 0;
}

깔끔한 코드
typedef pair<int, int>pii;
int a, b, c;
int m;
int main(){
	ios_base::sync_with_stdio(false);
	string str; int p;
	cin >> a >> b >> c;
	cin >> m;
	priority_queue<pii>q;
	for(int i=0;i<m;i++){
		cin >> p >> str;
		if(str == "USB") q.push({-p, 1});
		if(str == "PS/2") q.push({-p, 2});
	}
	long long cnt = 0, cost = 0;
	while(!q.empty()){
		pii f = q.top(); q.pop();
		long long cst = -f.first, tp = f.second;
		if(tp == 1){
			if(a) a--, cnt++, cost+=cst;
			else if(c) c--, cnt++, cost+=cst;
		}
		else{
			if(b) b--, cnt++, cost += cst;
			else if(c) c--, cnt++, cost+=cst;
		}
	}
	cout << cnt << ' ' << cost << endl;
	return 0;
}


"일반적으로 lcs(longest common subsequence:최장 공통 부분열) 를 구하는데 필요한 복잡도"
time: O(mn)
공간: O(mn)
http://codeforces.com/contest/762/problem/C
이 문제는 a, b 두 문자열에 대해
	t 는 b의 특정 연속 부분을 제거 하고 남은걸 연결한거
	t 가 a의 서브시퀀스를 이루는 문자열이라 할때
	최대 길이가 되는 경우 t를 구하라

hi
bob	// - : 존재하지 않는 경우 - 를 출력함

abca
accepted	// ac

abacaba
abcdcba		// abcba : 중간의 cd 가 제거

// 제약상황
1 <= a.size, b.size <= 10^5
"문제 풀때 오해: lcs는 복잡도가 길이의 제곱이잖아..."
"lcs 가 아니라 한쪽은 원본, 한쪽은 sebsequence 임"

풀이
	온전한 b에 대해 sebsequnce를 이루는 위치를 prefix 기준으로 pre 배열에 기록
	마찬가지로 suffix 기준으로 suf 배열에 기록

b string (사이즈가 100)에서 b[0:8] + b[94:99]  인 서브스트링 이 있음
pre[8] : 13 이고, suf[94] : 14 면 괞찮음 
허나 pre[8] : 13 이고, suf[94] : 13 이하면 해당 서브시퀀스는 존재 불가

복잡도
	최초 pre, suf 배열 계산 10^5 걸림
	ok 함수의 복잡도 10^5
	이분법 log2(10^5)

	총 복잡도 10^5 * log2(10^5)

// 중간에서 삭제될 경우
abcdefg
0123456		3개 삭제
0, 456
01, 56
012, 6


const int INF = 987654321;
string a, b;
vi pre, suf;
int ok(int r) {		// r: 남길 문자수, 리턴값은 두 부분 중 앞에 남겨질 문자갯수
	if (r > b.size()) return -1;
	if (pre[r - 1] < a.size()) return r;
	if (suf[b.size() - r] >= 0) return 0;
	int rr = b.size() - r; // 중간에서 삭제될 문자 수
	for (int i = 0; i + rr + 1 < b.size(); ++i) 
		if (pre[i] < suf[i + rr + 1]) return i + 1;
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b;
	pre.resize(b.size(), INF), suf.resize(b.size(), -INF);
	string::iterator it = a.begin();
	for (int i = 0; i < b.size(); ++i) {
		while (it != a.end() && b[i] != *it) ++it;
		if (it == a.end()) break;
		pre[i] = it - a.begin();
		++it;
	}
	string::reverse_iterator jt = a.rbegin();	// !!!! 숫자 햇갈리니까 짤때 대입해서 확인하자.
	for (int i = b.size() - 1; i >= 0; --i) {
		while (jt != a.rend() && b[i] != *jt) ++jt;
		if (jt == a.rend()) break;
		suf[i] = (a.rend() - 1) - jt;
		++jt;
	}
	int lo = 0, hi = 100003;
	// 반복문 불변식:
	// 1. lo 개를 남길시 서브시퀀스는 항상존재
	// 1. hi 개 이상인 길이를 가지는 서브시퀀스는 존재할 수 없음
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (ok(mid) != -1)
			lo = mid;
		else
			hi = mid;
	}
	if (lo == 0) cout << "-";
	else {
		int preLength = ok(lo);
		string str1 = b.substr(0, preLength);
		string str2 = b.substr(b.size() - (lo - preLength));
		cout << str1 + str2;
	}
	return 0;
}


" 제비뽑기 "
어느 날 친구가 봉지를 들고 와 당신에게 게임을 제안했습니다. 봉지에는 숫자가 쓰여 있는 n장의 종
이가 들어 있습니다. 당신은 봉지에서 종이를 한 장 뽑고, 숫자를 확인한 후 다시 봉지에 넣는 동작을
4번 반복하여, 그 숫자의 합이 m이면 당신의 승리, 그렇지 않으면 친구가 승리하게 됩니다. 당신은 이
게임을 몇 번이나 해 보았지만 한번도 이기지 못했습니다. 화가 난 당신은 봉지를 찢어 모든 종이를 꺼
낸 후 정말 이길 수 없었는지 조사를 했습니다. 종이에 쓰여 있는 숫자가 K1, K2 ..., Kn일 경우, 합이 m
이 되는 경우가 있는 지를 조사하고, 방법이 있다면 Yes, 없다면 No를 출력하는 프로그래밍을 작성하
세요.
	중복해서 선택이 가능 : 4개를 선택
	1 <= n <= 50
	1 <= m <= 10^8
	1 <= ki <= 10^8

4중 포문으로 쉽게 해결된다.
	rep(i,n)
		rep(j,n)
			rep(k,n)
				rep(l,n)
					if (m == arr[i] + arr[j] + arr[k] + arr[l])
						return true;

허나 n 이 1000 개라면 우떻게 할까?


두 부분으로 나눠 보세
rep(i,n) rep(j,n)
	myMap[arr[i] + arr[j]] = true;
for (it: myMap 순회)
	if (myMap.count(m - it->first))
		return true;



http://codeforces.com/contest/764/problem/C
// 영어해석 정말 어렵네... ㅠㅠ // 김동 해석 도와줌
// 특정 노드를 선택한다
// 그 노드의 서브트리의 색상은 한가지만 가능하다
// 특정 노드를 찾아라.

나의 풀이
칼라가 바뀌는 정점을 찾아서
그걸 기준점으로 해서 답을 구한다.
바뀐다는 건 하나만 되면 안된다는 걸 간과했다.
	"상대적인 것이라 순회 순서에 따라 바뀌는 건 2개가 될 수 있다"
4
1 4
2 4
3 4
1 2 3 1
	// 내 출력 "NO"
// 답
YES
4

	1번 노드 부터 순회하면 칼라가 바뀐 노드는 2번 노드가 된다.
	허나 2번 노드부터 시작하면 칼라가 바뀐 노드는 4번 노드가 된다.
	결론적으로 후보는 2개가 되어야 한다.

vi graph[100002];
int col[100002];
int sel, sel2;
void dfs1(int here, int prnt) {		// 후보점을 찾는다. // 사실 개 뻘짓이었음.
	rep(i, graph[here].size()) {	// 각 엣지중 칼라가 다른 엣지 하나만 찾으면 될 일 인데...ㅠㅠ
		int child = graph[here][i];
		if (child == prnt) continue;
		if (col[child] != col[here]) {
			sel = child;
			sel2 = here;
			break;
		}
		if (sel == -1)
			dfs1(child, here);
	}
}
int dfs2(int here, int prnt) {
	rep(i, graph[here].size()) {
		int child = graph[here][i];
		if (child == prnt) continue;
		if (child == sel) continue;
		if (col[child] != col[here]) return false;
		if (dfs2(child, here) == false) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	sel = -1;
	int n; cin >> n;
	rep(i, n - 1) {
		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	map<int, int> colCnt;
	rep(i, n) {
		int ccc; cin >> ccc;
		col[i] = ccc;
		colCnt[ccc]++;
	}
	if (colCnt.size() == 1) {
		cout << "YES" << '\n' << 1;
		return 0;
	}
	int start;
	rep(i, n) if (graph[i].size() == 1) {
		start = i;
		break;
	}
	bool allOK = true;
	dfs1(start, -1);
	rep(i, graph[sel].size()) {
		int child = graph[sel][i];
		bool chk = dfs2(child, sel);
		if (chk == false)
			allOK = false;
	}
	if (allOK == false) {
		allOK = true;
		rep(i, graph[sel2].size()) {
			int child = graph[sel2][i];
			bool chk = dfs2(child, sel2);
			if (chk == false)
				allOK = false;
		}
		if (allOK) sel = sel2;
	}
	if (allOK) {
		cout << "YES" << '\n' << sel + 1;
	}
	else
		cout << "NO";
	return 0;
}

이를 간단히 표현한다면
칼라가 다른 엣지를 찾아서 후보1, 후보2로 정하면 되는 것이었다.
	"다른 엣지를 1만 찾으면 된다"


// 다른 사람 풀이
int c[maxn] , x[maxn] , y[maxn];
vector <int> g[maxn];

bool dfs(int u , int p , int col){
    if(c[u]!=col)
        return false;
    for(int v:g[u])
        if(v!=p){
            if(!dfs(v , u , col))
                return false;
        }
    return true;
}
bool find_ans(int u){
    for(int v:g[u]){
        if(!dfs(v , u , c[v]))
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0 ; i<n-1 ; i++){
        cin>>x[i]>>y[i];
        x[i]--;
        y[i]--;
        g[x[i]].pb(y[i]);
        g[y[i]].pb(x[i]);
    }
    for(int i=0 ; i<n ; i++)
        cin>>c[i];
    for(int i=0 ; i<n-1 ; i++){
        if(c[x[i]]!=c[y[i]]){	// 칼라가 다른 엣지 한놈만 찾으면 된다.
            if(find_ans(x[i])){
                cout<<"YES"<<endl;
                cout<<x[i]+1;
                return 0;
            }
            else if(find_ans(y[i])){
                cout<<"YES"<<endl;
                cout<<y[i]+1;
                return 0;
            }
            else{
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES"<<endl<<1;
    return 0;
}


http://codeforces.com/contest/764/problem/D
기하 문제이며 링크 들어가서 그림 보는게 편함. 따라서 해석은 안 적음
요약하자면
	2차원 평면에 사각형들이 놓여 있으며
	그것들이 겹치는 면적은 없는 상태임
	그 상태에서
	인접한 색이 안 겹치도록 색깔을 칠하는 것이 가능한가 판별하고,
	각 사각형의 색을 구하라 (4가지 색만 가능: 1,2,3,4)

	"사각형의 수가 50만개나 되고 좌표의 범위도 +- 10 만이나 된다..."
	정상적으론 구현하기 어렵다.. 절대 div2 D번 수준의 문제가 아니야!!!!
	
	"쨉실한 사고가 필요하다"
	"일단 답이 NO 가 되는 경우는 절대 없다" // 지도의 색은 4개로 모든 영토의 구분이 가능함을 우린 배웠다.
	
	사각형의 가로세로변은 모두 홀수라고 했다.
	"각 사각형의 칼라는 맨 끝 좌표로 결정할 수 있다는 사실!!!!"
	// 그럼 특정 사각형이 위에 큰게 있고
	// 밑에 조그만 사각형이 여러개 따닥따닥 붙어있으면 어찌 되는가!!!!
	// 큰 사각형의 칼라가 1, 3 인 경우 (ms 좌표, 맨 밑 y가 홀수인 경우)
	// 그 뒤 밑에 붙는 사각형은 맨 밑 y가 짝수만 가능하다
	// 즉 2, 4 의 색상만 나올 뿐이다.

int main() {
	ios::sync_with_stdio(false);
//	cout << -1 % 2 << '\n';	// -1
//	cout << -2 % 2 << '\n';	// 0
//	cout << -3 % 2 << '\n';	// -1
	int n;	cin >> n;
	cout << "YES" << '\n';
	rep(i, n) {
		int a, b, c, d; 
		cin >> a >> b >> c >> d;
		c += 1e9; // 음수처리 필요함: 나머지 연산을 위해
		d += 1e9;
		if (c % 2 == 0 && d % 2 == 0) 
			cout << 1 << '\n';
		if (c % 2 == 0 && d % 2 == 1) 
			cout << 2 << '\n';
		if (c % 2 == 1 && d % 2 == 0) 
			cout << 3 << '\n';
		if (c % 2 == 1 && d % 2 == 1) 
			cout << 4 << '\n';
	}
	return 0;
}}


http://codeforces.com/contest/766/problem/C
// 주어진 스트링을 분리해야 각 마법종이에 분리해야한다.
// 이때 각 마법 종이는 각각 한계치가 존재한다.
// 한계치란 무엇인가? 이거 영어 해석이 까탈스러웠다.
// 만약 a 가 2라면
// a가 포함된 서브스트링은 그 글자길이가 2를 넘기면 안된다. 
3
aab
2 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1	
output
3	// 3가지 분리방법이 존재한다. // {aa, b}, {a, ab}, {a, a, b}
2	// 분리된 서브스트링 중 가장 긴 길이
2	// 분리갯수를 가장 적게 한다고 할때 몇개로 가능한고


10
abcdeabcde
5 5 5 5 4 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
output
401
4
3

그리 어렵지 않다.
	먼저 분할을 크게 진행해서 끝까지 도달할 경우 seg 갯수가 sol3 가 된다. (greedy)
	그리고 크게 진행한 것중 가장 긴 길이는 sol2 가 된다.
	cache[i] : 현 위치에서 진행할 경우 경우의 수는 몇개인가?
	cache[i] = sum {cache[i + (1 ~ 가능한 사이즈)]}
	// 가능한 사이즈를 계산잘하면 된다능~

http://codeforces.com/contest/766/submission/24507277	// 187ms 걸림
const int INF = 987654321;
const int MOD = 1000000007;
int n;
string str;
map<int, int> alCnt;	// 해당 문자 카운트
int sol1, sol2, sol3;
int cache[1005];
int dp(int here, int minSeg) {
	if (here >= n) {
		if (sol3 == -1) 
			sol3 = minSeg - 1;
		return 1;
	}
	int& ret = cache[here];
	if (ret != -1) return ret;
	ret = 0;
	map<int, int> tmp;// = alCnt;
	int vLength = 0;
	for (int i = here; i < n; i++) {
		int ch = str[i] - 'a';
		tmp[ch]++;
		vLength++;
		bool ok = true;
		map<int, int>::iterator it = tmp.begin();
		for (; it != tmp.end(); ++it) {
			int key = it->first;
			if (alCnt[key] < vLength) {	// 해당 사이즈를 초과하는감?
				ok = false;
				break;
			}
		}
		if (ok == false) {	// 해당사이즈를 초과하면 최대길이를 원복시킨다.
			vLength -= 1;
			break;
		}
	}
	if (vLength > sol2) sol2 = vLength;	// 가장 긴 길이 설정
	for (int i = vLength; i > 0; i--) {	// 가장 긴 길이 부터 탐색해나간다. (greedy)
		int there = i + here;			// 최초 끝 도달시 조각이 최소가 되는 걸 보장한다.
		ret += dp(there, minSeg + 1);	
		ret %= MOD;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	sol2 = -1;
	sol3 = -1;
	cin >> n;
	cin >> str;
	rep(i, 26) cin >> alCnt[i];
	sol1 = dp(0, 1);
	
	cout << sol1 << '\n' << sol2 << '\n' << sol3;
	return 0;
}
// 짧고 좋은 코드 !!!!
http://codeforces.com/contest/766/submission/24503002	// 30ms
int n;
string str;
int a[100];
int dp[3][2000];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	cin >> str;
	for (int i = 0; i < 26; ++i) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 1; i <= str.size(); ++i) {
		int len = INF;
		dp[1][i] = -INF;
		dp[2][i] = INF;
		for (int j = i - 1; j >= 0; --j) {	// 길이 역추적
			len = min(len, a[str[j] - 'a']);
			if (len < i - j) break;	// 길이보다 짧으면 NONO
			dp[0][i] = (dp[0][i] + dp[0][j]) % mod;
			dp[1][i] = max(dp[1][i], max(i - j, dp[1][j]));
			dp[2][i] = min(dp[2][i], dp[2][j] + 1);	// 결국 마지막 제일 적은 j를 답으로 챙기게 됨
													// 길이가 가장 긴놈으로 greedy 한다는 거랑 같은 결과
		}
	}
	cout << dp[0][n] << endl;
	cout << dp[1][n] << endl;
	cout << dp[2][n] << endl;
}




http://codeforces.com/contest/766/problem/D
D. Mahmoud and a Dictionary
	사전에서 동의어랑 반대어를 계산하는 문제
	모순된 입력이 들어오면 NO 를 출력, 정상적인 입력시 YES 출력
	만들어진 관계도를 이용해서
	각각의 단어쌍에 대한 관계를 출력한다.// 아무 관계도 아닌 경우 3을 출력

3 3 4
hate love like	// 단어 종류
1 love like		// 동의어	YES
2 love hate		// 반대어	YES
1 hate like		// 모순 발생 NO
love like	// 1 동의어
love hate	// 2 반대어
like hate	// 2
hate like	// 2

YES
YES
NO
1
2
2
2

http://codeforces.com/contest/766/submission/24509950
//두 개의 원칙이 존재
//1. 동지의 적은 나의 적
//2. 적의 적은 나의 동지
//P 776 에디터 전쟁 문제를 해결하는 상호 배타적 집합의 구현
//각 집합간의 적대 관계와 크기를 두개의 별도 변수 enemy[], size[]를 이용해 추적
struct BipartiteUnionFind {	//bipartite 는 이분 그래프의 이름에서 따옴
							//(실제 적대 관계를 그림으로 그리면 이들은 항상 이분 그래프임)
							//parent[i] = i의 부모 노드. 루트라면 i
							//rank[i] = i가 루트인 경우, i를 루트로 하는 트리의 랭크
							//enemy[i] = i가 루트인 경우, 해당 집합과 적대 관계인 집합의 루트의 번호. (없으면 -1)
							//size[i] = i가 루트인 경우, 해당 집합의 크기
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; ++i) parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	//인자 u, v는 루트입니다.
	int merge(int u, int v) {
		//u나 v가 공집합인 경우 나머지 하나를 반환한다..
		if (u == -1 || v == -1) return max(u, v);
		u = find(u); v = find(v);
		//이미 둘이 같은 트리에 속한 경우
		if (u == v) return u;
		if (rank[u] > rank[v]) swap(u, v);
		//이제 항상 rank[v]가 더 크므로 u를 v의 자식으로 넣는다.
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
		size[v] += size[u];
		return v;
	}
	//u와 v가 서로 적대하는 집합에 속한다.
	bool dis(int u, int v) {	//u, eu, v, ev => a = merge(u, ev), b = merge(v, eu)
								//우선 루트를 찾는다.
		u = find(u); v = find(v);
		//같은 집합에 속해 있으면 모순!
		if (u == v) return false;
		//적의 적은 나의 동지
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	// dis 를 호출시 관계도가 새로 생성되니. dis 관곈지 판별용으로만 사용
	bool dis2(int u, int v) {		
		u = find(u); v = find(v);
		if (u == v) return false;
		int a = enemy[u];
		int b = enemy[v];
		if (a == -1) return false;
		if (b == -1) return false;
		if (find(a) == find(v)) return true;
		if (find(b) == find(u)) return true;
		return false;
	}
	//u와 v가 같은 집합에 속한다.
	bool ack(int u, int v) {	//u, eu, v, ev => a = merge(u, v), b = merge(eu, ev)
								//우선 루트를 찾는다.
		u = find(u); v = find(v);
		//두 집합이 서로 적대 관계라면 모순!
		if (enemy[u] == v) return false;
		//동지의 적은 나의 적
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		//두 집합 다 적대하는 집합이 없으면 b는 -1 일 수도 있다.//!!!!
		if (b != -1) enemy[b] = a;//!!!!
		return true;
	}
};
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int n, m, q; cin >> n >> m >> q;
	map<string, int> my;
	rep2(i, 1, n + 1) {
		string str; cin >> str;
		my[str] = i;
	}
	BipartiteUnionFind dsj(n + 1);
	rep(i, m) {
		int tp;  cin >> tp;
		string str1, str2;
		cin >> str1 >> str2;
		int a = my[str1], b = my[str2];
		if (tp == 1) {
			bool ok = dsj.ack(a, b);
			if (ok == false) cout << "NO" << '\n';
			else cout << "YES" << '\n';
		}
		else {
			bool ok = dsj.dis(a, b);
			if (ok == false) cout << "NO" << '\n';
			else cout << "YES" << '\n';
		}
	}
	rep(i, q) {
		string str1, str2;
		cin >> str1 >> str2;
		int a = my[str1], b = my[str2];

		if (dsj.find(a) == dsj.find(b)) cout << 1 << '\n';
		else if (dsj.dis2(a, b)) cout << 2 << '\n';
		else
			cout << 3 << '\n';
	}
	return 0;
}


아래 문제를 풀기전에 고찰할 것
	1) 예시
	base점을 기준으로 5개의 갈래가 있다
	각 갈래는 2, 3, 5, 7, 9 라는 value를 가지고 있다.
	base점을 사이에 두고 2개의 갈래를 고를때 점수를 얻는다. 점수 계산은 다음과 같다.
	각 갈래의 value 의 곱이 된다.
	각 갈래를 2개씩 선택시 중복이 되지 않는다고 가정하에
	얻게 되는 전체 점수는 다음과 같다.
"	total = (2*3 + 2*5 + 2*7 +2*9)  +  (3*5 + 3*7 + 3*9)  +  (5*7 + 5*9)  + (7*9)"
	즉 갈래가 100000 개 있으면
	복잡도는 100000^2 으로 된다.

	이걸 빠르게 구하려면 !!!!
	2n의 연산으로 가능하다. 
	total							tmp
									9
	7*9								9+7
	63 + 16*5						16+5
	153 + 21*3						21+3
	216 + 24*2						24+2

	// 갈래가 100000 개 있으면 복잡도도 100000

	2) 예시
	정점이 n이고 엣지수는 n-1 이며 모든 정점은 연결되어 있다.(undirected)
	각 정점은 ai 라는 value 를 가지며
	각 패스의 비용은 path 의 정점 value 들의 합이된다.
	패스는 서로 다른 두 정점이라고 할 때 , & (u, v) 랑 (v, u) 는 같은 놈 취급이라 할 경우
	모든 패스에 대한 비용의 합을 구하라.

	// 노노노노노 위는 예시가 잘못됨
	// 아래로 정정
	정점이 n이고 엣지수는 n-1 이며 모든 정점은 연결(undirected)
	2정점을 잇는 패스의 갯수를 모두 구하여라 (u,v) 랑 (v,u) 는 같은 놈 취급
	// 사실 이것은 조합으로도 간단히 풀린다만 nC2
	// 응용을 위해서 직접 풀어보면

"pr을 뺀 나머지 서브트리의 base 통과하는 갯수 
"SUM {arr[i] * arr[j](i != j, 0 <= i,j <=2) {1,2,3} }
                   v	// 1개
                  /
                 /
	pr ----- base ----- v ---- v	// 2개
                 \	// 3개
			      \v______v
                   |
				   |
                   v

8
1 2
2 3
2 4
2 5
4 6
5 7
5 8

8C2 : 28 개가 답이 된다. // 아래 코드에서 테스트 했음


// 뭐 dfs() 의 리턴값으로 던져도 된다만
// 여기선 배열에 세팅을 해봄 // 분리해서 생각하기로
vi g[10001];
int cnt1[10001];	// prnt 간선과의 연결을 제외한 해당점을 경유 모든 패스의 갯수(자식)
					// 단 해당 점을 끝으로 가지면 안됨
int cnt2[10001];	// prnt 간선과의 연결을 제외한 해당점을 끝으로 가지는 패스의 갯수
ll sum;
void dfs(int v, int pr = -1) {
	// pr을 제외한 모든 패스의 갯수 세팅
	cnt1[v] = cnt2[v] = 0;
	int sum = 0;
	rep(i,g[v].size()) {
		int t = g[v][i];
		if (pr == t) continue;
		dfs(t, v);
		cnt1[v] += cnt2[t] * cnt2[v];	// v를 중간 경유 하는 모든 패스의 갯수
		cnt2[v] += cnt2[t];
	}
	sum = cnt1[v] + cnt2[v];
}
vi g[1000];
int cnt1[1000];		// [v] 를 중간에 경유하는 모든 패스의 갯수(단 prnt 연결은 제외)
int cnt2[1000];		// [v] 를 끝에 경유하는 모든 패스의 갯수(단 prnt 연결은 제외)
int local[1000];
ll sum;
void dfs(int v, int pr = -1) {
	cnt1[v] = cnt2[v] = 0;
	rep(i, g[v].size()) {
		int t = g[v][i];
		if (pr == t) continue;
		dfs(t, v);
		int sub = cnt2[t] + 1;	// sub: 자식 하나에 대한 [v] 를 끝에 경유하는 패스의 갯수
		cnt1[v] += sub * cnt2[v];
		cnt2[v] += sub;
	}
	local[v] = cnt1[v] + cnt2[v];	// [v] 를 포함한 모든 패스들의 수(단 prnt 연결은 제외
	sum += local[v];
}
// 굳이 dfs를 잎노드에서 안해도 됨
int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n - 1) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(4);
	return 0;
}




http://codeforces.com/contest/766/problem/E
E. Mahmoud and a xor trip
n 개의 정점 (1 <= n <= 10^5)
각 정점에 정수가 있음 a1, a2,..., an (0 <= ai <= 10^6)
각 정점은 모두 연결되어 있고
n-1 개의 간선으로 연결되어 있음 (1 <= u, v <= n, u != v)
	모든 정점이 연결되어 있으며 두 정점을 연결한 패스를 
	path(u,v) 라 둘때 path 의 비용은 path 에 포함된 정점의 정수를 모두 xor 한 것이 된다
	자체(itself)도 path 에 포함되며 이경우 정점의 정수 자체가 비용이 된다.

	"모든 path 의 비용의 합을 구하라"

	문제 접근
	xor은 자리 이동이 없는 연산이다
	따라서 각 자리별로 따로 계산하도록 한다.
( 아래는 이진수 임 )
	1을 가지는 패스의 갯수		* 1
	10을 가지는 패스의 갯수		* 10
	100을 가지는 패스의 갯수	* 100
	...
	1 0000 0000 0000 0000 0000 을 가지는 패스의 갯수 * 1 0000 0000 0000 0000 0000
	의 합이 답이된다.

		즉 bigO(20 * dfs) 가 된다.
		dfs는 N의 시간복잡도로 구현 가능하다.
			bigO(20*N) 이 된다.

5	// 정점 5개
1 2 3 4 5	// 각 정점별 정수값
1 2		// 간선들(4개)
2 3
3 4
3 5

//답: 52

// 982ms
ll n, a[100005], b[100005];
int cnt[100005][2];	// [v][1]: v정점에서 패스가 끝나고 그 xor 결과가 1
					// [v][0]: v정점에서 패스가 끝나고 그 xor 결과가 0
ll sum;
vi g[100005];
void dfs(int v, int pr = -1) {
	cnt[v][0] = cnt[v][1] = 0;
	cnt[v][b[v]]++;	// 한개짜리일 때의 카운트
	sum += b[v];
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == pr) continue;
		dfs(to, v);
		// 아래는 참 중요한 방식이니 기억하자!!!!
		// 기존의 끝에 연결된 패스의 갯수 * 새로 더할 패스의 갯수: 위에서 설명한 거
		sum += cnt[v][1] * cnt[to][0];	
		sum += cnt[v][0] * cnt[to][1];
		if (b[v] == 1) {	// 현 노드가 1이면	v를 끝으로 한 패스들이 더해질 형태
			cnt[v][1] += cnt[to][0];	// 는 자식 패스가 0인 놈은 xor 시키면 1에 대입된다
			cnt[v][0] += cnt[to][1];	// 자식 패스가 1인 놈은 xor 시키면 0에 대입
		}
		else {	// 현 노드가 0이면 to 에서 끝나는 패스랑 연결시 
			cnt[v][0] += cnt[to][0];	// 0 ^ 0 = 0 // path_to 가 0인 경우
			cnt[v][1] += cnt[to][1];	// 0 ^ 1 = 1 // path_to 가 1인 경우
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	rep2(i, 1, n + 1) cin >> a[i];
	for (int i = 2, u, v; i < n + 1; ++i) {
		cin >> u >> v; g[u].pb(v); g[v].pb(u);
	}
	ll ans = 0;
	for (int i = 0; i <= 20; ++i) {
		sum = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[j] & (1 << i)) b[j] = 1;
			else b[j] = 0;
		}
		dfs(1);
		ans += (sum << i);
	}
	cout << ans;
	return 0;
}



http://codeforces.com/contest/765/problem/C
input
11 11 5
output 
1

input
11 2 3
out
-1

탁구의 게임이 완료가 된 상테임(그전까지 중도 그만둔 세트가 없다는 뜻)
k 번 이기면 세트를 가져감
게임이 완료가 된 상태에서 
misha 는 a번 이겼고
vanya 는 b번 이긴 상태임

그렇담 최대 몇 세트의 게임을 했을까?
혹은 초기 조건에 모순이 있으면 -1 을 출력하라

10 91 3
-1	// misha 가 9번 이겼을때 나오는 나머지 1개에 대한 처리가 불가능
	// 따라서 초기조건에 모순

C. Table Tennis Game 2
논리적 수식 전개의 중요성
쌍성효과, a랑 b가 서로 의존적인경우 어찌할꼬?	
그냥 논리식 다 적어서 if 문 중첩시키자!!!!
괜히 멋지게 하려단 가독성도 떨어지고 망한다.

"	a가 해결되려면 b가 해결되어야 하고 
"	b가 해결되려면 a가 해결되어야 하는 문제"
이경우
	a체크 -> b체크,
	b체크 -> a체크
식으로 하면 편하게 된다.

int main() {
	ios::sync_with_stdio(false);
	int k, a, b;
	cin >> k >> a >> b;
	int ad, bd; // 몫
	int ar, br; // 나머지
	ad = a / k;
	ar = a % k;
	bd = b / k;
	br = b % k;
	bool ok = false;
	// a를 기준으로 체크 -> b를 체크
	if (ar && bd > 0)	// a가 딱 떨어지지 않고 b의 몫이 1 이상이고
		if (br == 0 || ad > 0) ok = true; // b가 딱 떨어지거나 나머지가 남아도 그걸 해결할 a의 몫이 1이상이면
	if (ar == 0)	// a가 딱 떨어지고
		if (br == 0 || ad > 0) ok = true; // b가 딱 떨어지거나 나머지가 남아도 그걸 해결할 a의 몫이 1 이상이면

	// b를 기준으로 체크 -> a를 체크
	if (br && ad > 0)
		if (ar == 0 || bd > 0) ok = true;
	if (br == 0)
		if (ar == 0 || bd > 0) ok = true;
		
	if (ok)	cout << a / k + b / k;
	else cout << "-1";
	return 0;
}
	

http://codeforces.com/contest/765/problem/D
D. Artsem and Saunders	// 합성함수의 특징을 알수 있는 문제
n 개의 x에 대해 (1,2,3,..., n)
f(x) 가 주어져 있다.

g(h(x)) = x for all x (- [m]	// 1 ~ m 이 x값이 된다
h(g(x)) = f(x) for all x (- [n]	// 1 ~ n 이 x값이 된다.

여기서부턴 직접 구현해보자.
풀이 뒷 부분이 이해가 안된다.
h(g(x)) = (h o g)(x) = f(x)
h(g(h(g(x))) = (h o g o h o g)(x) = f(f(x)) // 여기서 (g o h) = x 이므로 생략이 가능하다
										// 거부감이 들면 자기 자신으로 돌아간다는 걸 생각해봐!!!!
(h o g)(x) = f(f(x))
so, f(x) = f(f(x)) 가 성립되어야 한다.

즉 초반 x에 대해 f를 적용한 뒤 그 값을 다시 f 적용 시킬 경우 제자리가 되어야 한다.
(초반 만 빼고다)
f(x) 가 적용된 치역을 다시 정의역으로 넣은뒤 다시 f(x) 를 적용시켜 제자리가 되어야
답은 존재하게 된다.


"코드포스 풀이에는 유도과정이 없다. ㅅㅂ"
// 함수는 대문자로 표현했다.
F(x) = F(F(x)) 이기에 최초 x에 f를 적용한 다음부턴
그 값을 인자로 넣을시엔 도로 그 값이 튀어 나온다.

F(x) 의 인자 x는 1 ~ n 이 된다.
F(x) 의 결과의 갯수는 m개다. ( m <= n)

m개의 안정화된 수에 번호를 매기자. 
안정화된 수를 pi = { p1, p2, p3, ..., pm }

그리구 나서 Q 라는 함수를 만들자. P 함수도 만들자. // 둘의 관계는 역함수
Q 의 정의: pi = i // 즉 Q(pi) = i 가 된다. 숫자에 대한 인덱스 번호를 반환
P 의 정의: i = pi // P(i) = pi 가 된다.
P(Q(pi)) = pi
Q(P(i)) = i	 "둘은 역함수 관계라 고대로 튀어 나오게 된다."

그런 다음
G(x) = Q(F(x)) 로 두자. // 번호가 반환
H(x) = P(x) 로 두자		// 번호에 대한 값이 반환

증명
x (- [n] // 1 ~ n 이 인자로 들어갈 경우
	H(G(x)) = P(Q(F(x))) = F(x)
x (- [m] // 1 ~ m 이 인자로 들어갈 경우
	G(H(x)) = G(P(x)) = Q(F(P(x))) =	// P(x) : 안정화된 인덱스가 가르키는 값
	= Q(P(x)) = x						// F(P(x)) = P(x) // 안정화 된건 F 적용해도 제자리임
										// 그러므로 Q(P(x)) 가 된다. !!!!(내가 막힌 부분임)

"요약"
일단 F(F(x)) = F(x) 임을 유도하고
안정화 된 것과 그것을 나타내는 index 를 H(i) = x 로 나타낸다. // index  => 안정화 된 수 매핑 
G(H(x)) = x for all x (- [m]	// 1 ~ m 이 x값이 된다 // 안정화 된 수 => index 매핑
H(G(x)) = f(x) for all x (- [n]	// 1 ~ n 이 x값이 된다.
G(x) 는 들어오는 것을 안정화된 수들의 index로 나타내는 함수가 된다.

음.. 이해는 했는데 인자로 들어오는 x가 동일한게 아니란걸 항상 기억해라.
그렇지 않으면 많이 햇갈릴 거야. 다시 봐도...ㅠㅠ

http://codeforces.com/problemset/problem/767/C
트리에서 2개의 엣지를 제거하여 3등분한다.
각 3개의 부분들의 밝기(각 노드의 합)가 동일해야 한다.
불가능하면 -1
가능한 경우
엣지의 밑 부분 노드를 출력하라.
입력시 prnt 가 0이면 루트 노드이다.

6		// 6개의 노드
2 4		// 1번 노드의 부모는 2번 노드이고, 1번노드의 밝기는 4
0 5		// 2번 노드는 루트이며, 2번 노드의 밝기는 5
4 2
2 1
1 1
4 2

output
1 4

입력은 n (3 <= n <= 10^6)
각 노드의 밝기는 ti (-100 <= ti <= 100)

// 고찰 : postOrder 로 처리가능 !!!! (음수를 고려안해서 많이 틀렸다 ㅠㅠ)
// 아래에서 올라오면서 밝기 합을 누적한다
// 만약
// t3(삼등분 밝기) 랑 일치하는 경우 sol 에 집어 넣는다.
// 답이 존재한다면 3개 혹은 그 이상일 수 있다(음수 땜시)
// 출력은 2개만 하면 된다.

vi g[1000005];
int t[1000005];
int t3;
vi sol;
bool ok;
int postOrder(int here) {
	int sub = t[here];
	if (g[here].size() == 0) {
		if (sub == t3) {
			sol.push_back(here);
			return 0;
		}
		return sub;
	}
	rep(i, g[here].size()) {
		int child = g[here][i];
		sub += postOrder(child);
	}
	if (sub == t3) {
		sol.push_back(here);
		return 0;
	}
	return sub;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);	// tie(0) 넣으니 1650ms -> 1450ms
	// 입력이 백만개라서 느릴수 밖에 없다...
	// 암만 빠른 놈것도 400ms 이상이었으며 그 인간들 코드는 input 자체 함수를 만들어 썼음.
	// 즉 입력을 빨리 받는 것 이었다.
	int sum = 0;
	ok = true;
	int n; cin >> n;
	int root;
	rep2(i, 1, n + 1) {
		int pr, ti; cin >> pr >> ti;
		sum += ti;
		t[i] = ti;
		if (pr != 0)
			g[pr].push_back(i);
		else
			root = i;
	}
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}
	t3 = sum / 3;
	postOrder(root);
	if (sol.size() < 3) {
		cout << -1;
	}
	else {
		rep(i, 2)	// 2개만 출력하면 된다.
			cout << sol[i] << " ";
	}
	return 0;
}



http://codeforces.com/contest/776/problem/C		// 동전dp 관련 // google, 구글 유형임
C. Molly's Chemicals
n이 주어지고(1 <= n <= 10^5)
k 가 주어진다 (1 <= n <= 10^5)
다음 줄에는 
a1, a2, ..., an (-10^9 <= ai <= 10^9) 의 수들이 주어진다.
k의 지수승 을 만족하는 구간합의 갯수를 구하라

input
4 2
2 2 2 2
output
8
2^0 : 불가능
2^1 : segments [1, 1], [2, 2], [3, 3], [4, 4]
2^2 : segments [1, 2], [2, 3], [3, 4]
2^3 : segments [1, 4]
총 8개가 존재한다.

input
4 -3
3 -6 -3 12
output
3
(-3)^0 : 불가능
(-3)^1 : segments [1, 2], [3, 3]
(-3)^2 : segments [3, 4]
총 3개가 존재한다.
"틀린이유: 누적합으로 처리하기 힘들거라 판단했다. 
"10만개에 대해 2개씩의 쌍짓는건 100억을 넘기는데 우짜노 하며 자절함...
http://codeforces.com/contest/776/submission/24919677	// 아인타(ainta) 소스: 1750ms 걸림
map<ll, int> my;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//int n, k; scanf("%d%d", &n, &k);	// 이걸 쓰면 vs는 정답인데 cf에선 오류남
	int n, k; cin >> n >> k;	// scanf랑 cin을 같이 쓰지 말자...!!!!
	ll psum = 0, sol = 0;
	my[psum] = 1;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		psum += a;
		if (k == 1)	// 지수승이 1만 존재
			sol += my[psum - 1];
		else if (k == -1)	// 지수승이 1, -1 만 존재
			sol += my[psum - 1] + my[psum + 1];
		else {
			ll t = 1;
			while (true) {
				sol += my[psum - t];
				t *= k;
				if (t > 1e15 || -t > 1e15) break; // 표현 좋네.
			}
		}
		my[psum]++;
	}
	printf("%I64d\n", sol);
	return 0;
}
http://codeforces.com/contest/776/submission/24946687	// 미친듯이 빠름 78ms 걸림..


http://codeforces.com/contest/776/problem/D		// 구글형식, google 좋은 문제
D. The Door Problem		//2sat 문제
2개의 정수가 주어짐 
n : (2 <= n <= 10^5)	// 방의 수
m : (2 <= m <= 10^5)	// 스위치의 수
n 개의 분리된 정수들이 주어진다. 
r1, r2, ..., rn (0 <= ri <= 1) 이것들은 방의 문의 잠김 여부를 나타냄
// 0: 닫힌상태, 1: 열린상태
m 개의 스위치가 주어진다.
각 스위치는 한번에 여러 방문의 문들을 토글시킨다. (0->1, 1->0)
(각 스위치는 0 ~ n 개의 문들을 동시에 토글한다. : 첫 숫자가 컨트롤 하는 갯수)
(그뒤엔 컨트롤 할 문들의 인덱스가 주어진다.)
"나의 고민: 방의 수가 10만개라 방갯수를 상태로 해서 bfs 하면 당연 아웃이다.. "
"이 문제를 2sat 로 결부시킬 단서는 무엇인가?"
"It is guaranteed that each door is controlled by exactly two switches."

"각 문을 컨트롤하는 스위치는 정확히 2개임" !!!! 2sat 쓸수 있다.
// 이 문장을 봤어야 했다...
input
3 3		// 3개의 방, 3개의 스위치
1 0 1	// 현재의 방 상태
2 1 3	// 2개를 컨트롤 하는 스위치 (1, 3 번 방)
2 1 2	// 2개를 " (1, 2 번 방)
2 2 3	// 2개를 " (2, 3 번 방)
output
NO	// 모두를 동시에 1로 만들 수가 없다.

input
3 3
1 0 1
3 1 2 3
1 2
2 1 3
output
YES	// 2번 스위치를 사용해서 2번 방을 토글 시키면 모두가 1이 된다.

int main() {
	cin >> n >> m;
	2SAT 용 그래프를 만들어 봅세~~
	// 기존이 0인 경우
	"한개만 선택해야 하는 조건"
	// 1개는 꼭 선택  (A || B) => A를 선택안하면 B는 무조건 선택, 역도
	// !A->B, !B->A
	// 2개는 동시 선택하면 안되 (A && B) == false 즉 !(A && B) == true , (!A || !B) // 드모르간
	// A->!B, B->!A
	"(A || B) && (!A || !B)"	// 종만책의 회의실 배정 문제는 (!A || !B) 는 없다. 이는 둘다 가능한 경우도 참이기 때문

	// 기존이 1인 경우
	"0개이거나 2개를 동시 선택해야 하는 경우"
	// 0개 선택
	// !A->!B, !B->!A
	// 2개 동시 선택
	// A->B, B->A	// 한놈 선택서 다른놈도 선택되어야 한다. 이건 OR 식으로 못나타내네..
	// (!A || B) 를 넣는 순간 !B->!A 가 존재하니 말이다. 응? 되는데
	"(!A || B) && (A || !B)"

}
"초기 상태 땜시 네트워크 유량의 이분매칭으론 풀기 어렵다"
애초 초기 상태가 0 0 0 ... 0 이면 이분매칭이 가능함.
허나 1인 놈이 있으면 둘중 하나 선택이 아니라 "둘다 선택하던지 하나도 선택 안해야 함"
그래서 이분매칭 문제를 벗어나네....

// 280ms 걸림
vvi adj;
vi sccId, dscv; stack<int> st; int sccCnt, vtxCnt;
int scc(int here) {
	int ret = dscv[here] = vtxCnt++;
	st.push(here);
	rep(i, adj[here].size()) {
		int there = adj[here][i];
		if (dscv[there] == -1)
			ret = min(ret, scc(there));
		else if (dscv[there] < dscv[here] && sccId[there] == -1)
			ret = min(ret, dscv[there]);	// 여기서 오타나서 2일을 해맴...
	}
	if (ret == dscv[here]) {
		while (true) {
			int t = st.top(); st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}
vi tarjanSCC() {
	sccId = dscv = vi(adj.size(), -1);
	sccCnt = vtxCnt = 0;
	rep(i, adj.size()) 
		if (dscv[i] == -1) 
			scc(i);
	return sccId;
}
int my[100005][2];
vi status;
int n, m;
void mkG() {	// 핵심 !!!!
	int mtSize = m;
	adj.resize(mtSize * 2);
	rep(i, n) {
		int t = status[i];
		int A = my[i][0] * 2;
		int B = my[i][1] * 2;
		if (t == 0) {
			adj[A + 1].push_back(B);
			adj[B + 1].push_back(A);
			adj[A].push_back(B + 1);
			adj[B].push_back(A + 1);
		}
		else {
			adj[A + 1].push_back(B + 1);
			adj[B + 1].push_back(A + 1);
			adj[A].push_back(B);
			adj[B].push_back(A);
		}
	}
}
vi solve2SAT() {
	vi label = tarjanSCC();
	for (int i = 0; i < adj.size(); i += 2) if (label[i] == label[i + 1]) return vi();
	vpii order;
	rep(i, adj.size()) order.pb(mp(-label[i], i));
	sort(order.begin(), order.end());
	vi vbChoose(adj.size() / 2, -1);
	rep(i, order.size()) {
		int node = order[i].second;
		int index = node / 2;
		if (vbChoose[index] != -1) continue;
		vbChoose[index] = !((node % 2) == 0);
	}
	return vbChoose;
}
vi solve() {
	mkG();
	vi ret = solve2SAT();
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	status.resize(n);
	memset(my, -1, sizeof(my));
	rep(i, n) cin >> status[i];
	rep(i, m) {
		int cnt; cin >> cnt;
		rep(j, cnt) {
			int r; cin >> r;
			r--;
			if (my[r][0] == -1)
				my[r][0] = i;
			else
				my[r][1] = i;
		}
	}
	vi value = solve();
	if (value.empty()) cout << "NO";
	else cout << "YES";
	return 0;
}
http://codeforces.com/contest/776/submission/24923588 // ainta 소스: 나랑 비슷한 방식이다.



http://codeforces.com/contest/777	... 최악의 라운드다. 머리 회전이 정말 안되었다.
									// 밥먹고 바로 하지 말자. 혼자서 풀자. 전화기 끄자
http://codeforces.com/contest/777/problem/A
카드가 3장 있음
0, 1, 2 번 인덱스를 가짐
이것에 대해 총 n 번의 스웹을 가짐
1,3,5,7 ... 번째 스웝은 0, 1 번 카드를 대상으로 한다.
2,4,6,8 ... 번째 스웝은 1, 2 번 카드를 대상으로 한다.

입력에 
총이동 횟수, 최종 위치가 주어진 경우
최초위치를 출력하라.
input
4		// n (1 <= 2 * 10^ 9)
2		// x (0 <= x <= 2)
output
1		// 1번 카드가 최초위치가 된다.

- * -	// 최초위치			
* - -	// 1번째 스웝		// 0
* - -	// 2번째 스웝		// 0
- * -	// 3번째 스웝		// 1
- - *	// 4번째 스웝		// 2
- - *	//					// 2
- * -						// 1
* - -						// 0
* - -						// 0
- * -						// 1
- - *						// 2

// 6번의 위치가 반복됨을 알 수 있다.
n 이 무지 크다만
n = n % 6 으로 처리하고
rep(h,3) {
	arr[h] = 1;
	for (int i = 1; i <= n; ++i) {
		if (i % 2 == 1)
			swap(arr[0], arr[1]);
		else
			swap(arr[1], arr[2]);
	}
	if (arr[x] == 1) { cout << h; return 0; }
}
요런식으로 간단하게 하면 된다만

내 코드는 ㅠㅠㅠㅠㅠㅠ	// 반성하자... 가독성도 없다. 
						// 해석 하지도 말라. 가치 없는 코드다.
						// 크게 보고 판단해야 하는데 너무 협소했다.
" 왜 틀렸을까? 김동이 6개로 반복된다는 말을 들었다만"
" 그렇지 내 생각도임 그럼 그 6개에 대한 배열을 만들고 처리하면 되겠지 
" 하고 그만 생각을 고정해 버렸다.
" 더 편한 방법을 생각해 내었어야 했다. ㅠㅠ 
" 거기에 나의 외골수가 발동되어. 생각을 넓게 하는 걸 막았다...!!!!
// 명심하자 1번 문제다... 좁밥이며 귀찮게 안 낸다..
int main() {
	ll n, x; cin >> n >> x;
	vi arr(6);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 2;
	arr[3] = 1;
	arr[4] = 0;
	arr[5] = 0;

	vi arr2(6);
	arr2[0] = 0;
	arr2[1] = 0;
	arr2[2] = 1;
	arr2[3] = 2;
	arr2[4] = 2;
	arr2[5] = 1;

	vi arr3(6);
	arr3[0] = 2;
	arr3[1] = 1;
	arr3[2] = 0;
	arr3[3] = 0;
	arr3[4] = 1;
	arr3[5] = 2;
	
	ll move = n % 6;
	move = (move + 6 - 1) % 6;
	if (arr[move] == x) cout << 0;
	else if (arr2[move] == x) cout << 1;
	else cout << 2;
	return 0;
}


http://codeforces.com/contest/777/problem/B
// 반성점
// 일단 문제 개념을 제대로 적고 해야 했다. // 흐리멍텅한 정신상태..ㅠㅠ
// 두 명 (A, B) 가 있고
// 숫자로 이루어진 문자열 2개가 존재
// 각 숫자로 두명이 거룬다.
// 작은 숫자를 가진 놈이 지게 된다.

이때 B가 가장 적게 지는 경우의 갯수랑
A가 가장 많이 지는 경우의 갯수를 구하라(B가 가장 많이 이기는 갯수가 된다.)

n : (1 <= n <= 1000)
input
3
123
321
output
0
2

input
3457
2345
output
1	"b가 가장 적게 지는 갯수(총 갯수 - b가 비기거가 이기는 갯수)		7-2, 3-3, 4-4, 5-5
2	// b가 가장 많이 이기는 갯수

"p375 출전 순서 정하기" 참고
코드 그대로 쓰려다 망했다 !!!!
실제 함수에 들어가는 배열은 sorting 이 된 상태에서 들어가야 한다. !!!!
int order(const vector<int>& russian, const vector<int>& korean) 
// 게다가 이기는 갯수를 구할 경우
// lower_bound 가 아닌 upper_bound 를 써야 했다.
"비긴것도 이긴걸로 해주는 문제가 아니기 때문이다."


// B가 가장 적게 지는 갯수
int order(cvi& A, cvi& B) {	// A, B는 정렬된 상태이다.
	int n = A.size(), ret = 0;
	multiset<int> ratings(B.begin(), B.end());
	for (int ai = 0; ai < n; ++ai) {
		if (*ratings.rbegin() < A[ai]) {	// 무조건 진다.
			ratings.erase(ratings.begin());	// B의 가장 작은 수를 집어넣는다.
			ret++;
		}
		else {
			// A에게 비기거나 이기는 수 중 가장 작은 수를 없앤다.
			ratings.erase(ratings.lower_bound(A[ai]));
		}
	}
	return ret;
}

// B가 가장 많이 이기는 갯수
int order2(cvi& A, cvi& B) {
	int n = A.size(), ret = 0;
	multiset<int> ratings(B.begin(), B.end());
	for (int ai = 0; ai < n; ++ai) {
		if (*ratings.rbegin() <= A[ai])	// 무조건 같거나 지는 경우
			ratings.erase(ratings.begin());	// B의 가장 작은 수를 제거
		else {
			// A에게 이기는 수 중 가장 작은 수를 없앤다.
			ratings.erase(ratings.upper_bound(A[ai]));	// !!!! lower_bound를 써서 망함
			ret++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	vi arr1(n), arr2(n);
	rep(i, n) arr1[i] = str1[i] - '0';
	rep(i, n) arr2[i] = str2[i] - '0';
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	int sol1 = order(arr1, arr2);
	int sol2 = order2(arr1, arr2);
	cout << sol1 << '\n' << sol2;
	return 0;
}

// 김동 코드를 참고해보자.
input
3457
2345
output
1	// b가 가장 적게 지는 갯수(총 갯수 - b가 비기거가 이기는 갯수)		7-2, 3-3, 4-4, 5-5
2	// b가 가장 많이 이기는 갯수
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	vi A(n), B(n);
	rep(i, n) A[i] = str1[i] - '0';
	rep(i, n) B[i] = str2[i] - '0';
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int ai = 0, bi = 0;

	"B가 지는 것의 최소화: 총갯수 -  B가 비기거나 이기는 최대 갯수
	while (bi < n) {	
		if (A[ai] <= B[bi])
			ai++;
		bi++;
	}
	cout << n - ai << '\n';

	ai = 0, bi = 0;
	while (bi < n) {	// B가 이기는 갯수 최대화
		if (A[ai] < B[bi]) 
			ai++;
		bi++;
	}
	cout << ai << '\n';
	return 0;
}


http://codeforces.com/contest/777/problem/C
C. Alyona and Spreadsheet
보드판이 주어지고 각각 정수 요소를 1 이상 10^9 이하의 정수값을 가진다.
보드의 크기는 가로 세로 곱이 100000이하다. (1 <= n*m <= 100000)
질의가 k 개 주어진다. (1 <= k <= 100000)

각 질의는 위부터 아래를 의미하는 구간이며
m 개의 열중 단조 증가하는 구간이 한개라도 존재하면 "YES" , 그렇지 않으면 "NO"를 출력한다.

"틀린이유: 너무 긴장, 오타, bigO 착각, map<int, int> 의 무리한 사용으로 인한 오타 못찾음
	map<up, bottom>을 기록하고
	lower_bound 로 접근할려고 했다만.. 사실 배열로 간단하게 할 수 있었다.
	big(O)를 착각했는데 
	"각 기준 up 에대한 모든 최대 bottom 설정은 O(n*m) 즉 100000 이하로 가능하다.
// 반성: 항시 코드를 종이에 적어서 차분한 마음으로 작성하자.

input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5

output
Yes
No
Yes
Yes
Yes
No

내가 짠 코드 map<int, int> my; // up, bottom
my[2] = 5, 인데 my[3] = 4 인 좆같은 경우가 존재할 것이다.
ㅅㅂ
6 2
5 6
6 5
1 6
2 3
3 4
4 1
1
4 6 // NO 가 출력되네.. 코드상 인덱스는 3, 5 임
my[3] = 4 라서 "No" 출력됨... 아으..
// 이거 처리하려면 세팅할 키보다 앞에 있는 놈을 찾아서 그 값과 비교하는 구문이 있어야 함
// 개떡같이 지저분.

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vvi board(n, vi(m, 0));
	rep(i, n)
		rep(j, m) cin >> board[i][j];
	map<int, int> my;
	rep(i, m) {
		int pre = -1;
		int st = 0;
		rep(j, n) {
			if (pre <= board[j][i]) {
				pre = board[j][i];
				if (j == n - 1) // 끝에 도착
					my[st] = j;
			}
			else {
				if (my[st] < j - 1)
					my[st] = j - 1;
				pre = board[j][i];
				st = j;
				if (st == n - 1) // 끝에 도달
					my[st] = j;
			}
		}
	}
	int k; cin >> k;
	rep(i, k) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		// lower_bound 로 위치를 먼저 찾는다.
		map<int, int>::iterator it;
		it = my.lower_bound(a);	// a이상인 것중 가장 작은것
		if (it != my.end() && it->first == a) {
			if (it->second >= b)
				cout << "Yes" << '\n';
			else
				cout << "No" << '\n';
		}
		else {
			if (it != my.begin()) {
				it--;
				if (it->second >= b)
					cout << "Yes" << '\n';
				else
					cout << "No" << '\n';
			}
			else
				cout << "No" << '\n';;
		}
	}
	return 0;
}

// 배열을 이용해서 짜자. 202ms 걸림 // 간단하고 빠르노... ㅠ
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vvi board(n, vi(m, 0));
	rep(i, n) rep(j, m) cin >> board[i][j];
	vi dp(n, 0);	// index: top, value: 최대 bottom
	rep(j, m){
		int preI = 0;
		// !!!! 핵심부분, O(n*m) 에 세팅이 가능함을 보삼.
		rep2(i,1, n) {
			// 단조 증가가 그만 둔 시점
			if (board[i - 1][j] > board[i][j]) {
				while (preI != i) {
					dp[preI] = max(dp[preI], i - 1);
					preI++;
				}
			}
			if (i == n - 1)	// 끝에 도달한다면
				while (preI <= i) {
					dp[preI] = max(dp[preI], i);
					preI++;
				}
		}
	}
	int k; cin >> k;
	int l, r;
	rep(i, k) {
		cin >> l >> r;
		l--; r--;
		if (dp[l] >= r) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}

http://codeforces.com/contest/777/problem/D
D. Cloud of Hashtags
// 쉬운 문제라 딱히 설명을 길게 적지 않음.
사전순으로 만들기 위해 각 단어의 뒤를 최소한으로 지워서 출력해라.
n : (1 <= n <= 500000)
전체 문자열은 '#' 을 제외하고 총 합이 500000을 넘지 않는다.

input
3
#book
#bigtown
#big

output
#b
#big
#big

"맨 뒤부터 처리하면 됩니다." 265ms 걸림 greedy, 그리디
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vs arr(n);
	rep(i, n) cin >> arr[i];
	for (int i = n - 2; i >= 0; --i) {
		string a = arr[i];
		string b = arr[i + 1];
		string tmp;
		int sz = min(a.size(), b.size());
		rep(j,sz) {
			if (a[j] == b[j]) tmp.pb(a[j]);
			else if (a[j] < b[j]) {
				tmp = a;
				break;
			}
			else 
				break;
		}
		arr[i] = tmp;
	}
	rep(i, n) cout << arr[i] << '\n';
	return 0;
}


http://codeforces.com/contest/777/problem/E
E. Hanoi Factory // 구글 같은 문제(google)
링이 n 개 주어짐 (1 <= n <= 100000)
"n 이 1000개 정도면 종만 소스 응용으로 풀면 될건데... //가장 높은 탑쌓기 문제
"플이 보고 푼거여...ㅠㅠ"
"스택(stack) 을 이용하기 좋은 문제들 특징!!!! 을 기억하지. 이 느낌을 기억하자."
!!!! 아래 중요 요약
a b c d e 에서 a, b 가 쌓여 있는데 거기서 만약 c가 쌓을 수 없는 놈이면
c 대신 d, e도 쌓을 수가 없는 구조가 된다. 이런 구조에선 stack 을 이용하자.
"dfs 그래프가 생각나고 깊이가 너무 깊다면 스택구조를 떠올리도록 하자 !!!!"
// 먹이사슬 문제에서 스택구조를 쓸수 있는 문제랑 아닌 문제의 차이를 설명해놓음.
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<pair<pair<int, int>, int>> abh(n);
	//                   바깥지름        안쪽지름
	// 정렬을 위해서 first.second , first.first 순으로 입력받음
	rep(i, n) cin >> abh[i].first.second >> abh[i].first.first >> abh[i].second;
	sort(abh.begin(), abh.end(), greater < pair<pair<int, int>, int>>());
	vector<ll> ans(n);
	stack<int> opt;
	for (int i = 0; i < n; ++i) {
		while (!opt.empty() // 앞 구멍이 커서 못 쌓을때
			&& abh[opt.top()].first.second >= abh[i].first.first)
			opt.pop();
		if (!opt.empty())
			ans[i] = ans[opt.top()];
		ans[i] += abh[i].second;	// 높이를 더한다.
		opt.push(i);
	}
	ll sol = 0;
	rep(i, ans.size()) if (sol < ans[i]) sol = ans[i];
	cout << sol;
	return 0;
}
// lis 될거 같아서 풀어보려 도전해봤다만 내머리론 각이 안나오네 .. 
// 풀이엔 구간트리나 펜윅으로 가능하다고 되어 있다. lis 로 풀기는 다음에 생각해보자.


http://codeforces.com/contest/777/submission/25064896
pair<pair<int, int>, int> a[100001];
pair<int, long long> s[100001];
int sn;
int main() {
	long long t, r = 0;
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second);
	// 매우 멋진 정렬 코드...!!!! cubelover!!!!
	sort(a, a + n, [](auto &u, auto &v) { 
		return u.first.second == v.first.second ? u.first.first > v.first.first : u.first.second > v.first.second; 
		}
		);


http://codeforces.com/contest/779/problem/D		D. String Game
t, p 문자열이 주어지고
t에서 순차적으로 삭제하는 index가 주어진다.
t에서 순차적으로 삭제시 결과를 t_ 라 할때,
t_ 가 서브시퀀스로 p 를 가짐을 만족한다면
"만족하며 삭제되는 갯수는 최대 몇개인가?"

input
ababcba		// t
abb			// p
5 3 4 1 7 6 2	// 해당 인덱스 순으로 지운다. 첫 인덱스가 1임
최대 3개까지 지운다 해도 서브쉬컨스 "abb" 가 가능하다.
abab-ba
ab-b-ba
ab---ba
-b---ba	// 여기선 암만해도 서브시퀀스 "abb"를 만들 수 없다.

output
3		// 최대 3개까지 지울수 있다능.

두 문자열의 크기 (1 <= |t|, |p| <= 200000)
20만개나 되니 매우 크다.
"이분법을 사용할 수 있는 조건"
순서대로
10만개까지 지워도 서브시퀀스가 존재한다면
10만개 이하로 지워도 서브시퀀스는 존재한다능!!!!

// 124ms 걸림, 31분만에 짰다.
string t, p;
vi per;
vb use;
int n;
bool exist(int mid) {
	use.clear();	// clear 를 안하면 resize시 초기화가 안된다. ㅅㅂ !!!!
	use.resize(t.size(), true);
	rep(i, mid)
		use[per[i]] = false;
	int cnt = 0;
	// 서브시퀀스 존재여부를 체크해보자.
	rep(i, n) {
		if (use[i] == false) continue;
		if (p[cnt] == t[i])
			cnt++;
		if (cnt == p.size())
			return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t >> p;
	n = t.size();
	per.resize(t.size());
	use.resize(t.size(), true);
	rep(i, t.size()) {
		cin >> per[i];
		per[i]--;
	}
	int lo = 0, hi = t.size();
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (exist(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo;
	return 0;
}

// 참고 getline 및 파싱 예시
void test() {
	int n, m; cin >> n >> m;
	string str;
	rep(i, n) {
		getline(cin, str);
		string buf;
		stringstream ss(str);
		vector<string> tokens;
		while (ss >> buf)
			tokens.push_back(buf);
		cout << tokens.size() << '\n';
	}
}
10 100 // 무시 //
0	// 엔터 입력을 받아 텅빈 사이즈가 str 에 세팅 되었다. 
"이 경우 함더 getline 을 호출해서 해결할 수 있다. 현상은 탑코드 대회1.cpp 를 참고"
"검색어 getline
10 100 10000 100 20 1000 1000
7	// tokens 에 위에것 파싱되어 들어가 있음


http://codeforces.com/contest/779/problem/E
E. Bitwise Formula

"틀린 이유: 영어해석이 빠뜨린 부분들이 있음, 제약을
"이용해서 짧게 짤 수 있었는데 getline 을 써서 구현에 시간이 걸림.
"꼼꼼하게 해석하자 ㅠㅠ"
"이런 문제는 클래스로 질의를 저장하는 습관을 기르자.!!!!
// 구현 문제임... 헌데 구현하는데 시간이 좀 걸린다.
getline 을 쓸까 했는데
대입 뒤 연산자의 피연산자는 '?' 이거나 이름 문자열 이다.
// 숫자가 안 온다는 점을 이용하면 굳이 getline 을 쓸 필요가 없는 셈이다... ㅠㅠ
// 보통 코드포스는 이런식으로 getline 을 피하도록 한다. 그점을 기억하자. !!!!
즉 := 뒤 binary 숫자가 아닌 '?' 혹은 "이름문자열" 입력방식을 바꾸자.


The following n lines contain descriptions of the variables. 
Each line describes exactly one variable. Description has the following format: 
name of a new variable, space, sign ":=", space, followed by one of:

1. Binary number of exactly m bits.
2. The first operand, space, bitwise operation ("AND", "OR" or "XOR"), space,
the second operand. 
Each operand is either the name of variable defined before or symbol '?', 
indicating the number chosen by Peter.

:= 뒤에 오는 건 
1. binary number 
2. 이전에 "정의된 이름"이거나, '?' 을 2개 가지고 그사이엔 연산자가 있다.

'?' 란 수를 정의할때
각 정의된 이름에 해당하는 binary number 의 합의 최소값을 만드는 '?' 를 구하라
그리고
합의 최대값을 만드는 '?' 를 구하라. 
"마찬가지로 binary number 로 표현한다."


input
3 3
a := 101
b := 011
c := ? XOR b
output
011		// ? 가 011 이면 c가 000 이 되며 모든 합은 1000 이 된다. 이경우의 합이 최소임
100		// ? 가 100 이면 c가 111 이 되며 모든 합은 1111 이 된다. 최대가 된다.

input
5 1
a := 1
bb := 0
cx := ? OR a
d := ? XOR ?
e := d AND bb
output
0		// ? 가 0 이던 1이던 항상 같은 값인 2(합의 최소 == 합의 최대)를 가진다.
0
// 이 경우 가장 작은 값을 출력한다.
n : (1 <= n <= 5000)
m : (1 <= m <= 1000)	// binary bit depth 2^1000 까지라 보면 된다.

? 의 각 비트별로 계산하자.
string sol1, sol2; // 최소만드는 것, 최대만드는 것
rep(i,m) {
	int outFromZero = calc(i, 0);
	int outFromOne = calc(i, 1);
	if (outFromZero < outFromOne) {
		sol1.pb('0');
		sol2.pb('1');
	} else if (outFromZero > outFromOne) {
		sol1.pb('1');
		sol2.pb('0');
	} else {
		sol1.pb('0');
		sol2.pb('0');
	}
}

http://codeforces.com/contest/779/submission/25063762
2480ms 걸림.. 겨우 통과네..
map 접근을 미리 설정하면 좀 빨라지겠다.

int n, m;
map<string, int> my;	// string 에 대한 index
struct assign {
	int type;	// 0: 그냥 대입, 1: 계산 대입
	string value;
	string op;
	string aa, bb;
};
assign arr[5001];
int calc(int loc, int tp) {
	int ret = 0;
	rep(i, n) {
		if (arr[i].type == 0) {
			ret += arr[i].value[loc] - '0';
		}
		else {
			int a, b;
			if (arr[i].aa[0] == '?')
				a = tp;
			else {
				int idx = my[arr[i].aa];
				a = arr[idx].value[loc] - '0';	// 앞에서 부터 덮어쓰기 
			}
			if (arr[i].bb[0] == '?')
				b = tp;
			else {
				int idx = my[arr[i].bb];
				b = arr[idx].value[loc] - '0';
			}
			int result;
			if (arr[i].op == "AND")
				result = a & b;
			else if (arr[i].op == "OR")
				result = a | b;
			else
				result = a ^ b;
			ret += result;
			arr[i].value[loc] = result + '0';	// 다시 초기화 할 필욘 없다.
			// tp 가 0에서 계산 후 1 에서 계산시에도 덮어씌우기 때문
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		string str; cin >> str;
		my[str] = i;
		cin >> str;
		cin >> str;
		if (str[0] == '1' || str[0] == '0') {
			arr[i].type = 0;
			arr[i].value = str;
		}
		else {
			arr[i].type = 1;
			arr[i].value.resize(m, '0');
			string a, o, b;
			a = str;
			cin >> o >> b;
			arr[i].aa = a, arr[i].op = o, arr[i].bb = b;
		}
	}
	string sol1, sol2; // 합을 최소로 만드는 '?', 합을 최대로 만드는 '?'
	rep(i, m) {
		int outFromZero = calc(i, 0);
		int outFromOne = calc(i, 1);
		if (outFromZero < outFromOne) {
			sol1.pb('0');
			sol2.pb('1');
		}
		else if (outFromZero > outFromOne) {
			sol1.pb('1');
			sol2.pb('0');
		}
		else {
			sol1.pb('0');
			sol2.pb('0');
		}
	}
	cout << sol1 << '\n' << sol2;
	return 0;
}

http://codeforces.com/contest/779/submission/25041597
200 ms 걸린 소스
aa, bb 에 string 이 아닌 index 번호를 직접 주고 있다. (질의가 1부터 시작임)
'?' 인 경우 0 으로 세팅 함.




http://codeforces.com/contest/782/problem/D		// 문제 설명이 조같은 문제임.
// 영어 내용 정리하자면
// 각각은 둘중 하나를 선택 가능함
// 이때 첫번째가 같은 놐들은 항상 두번째를 선택해야함
// 그리고 모든 선택은 중복이 없어야 함.

input
2		// n은 최대 1000개
DINAMO BYTECITY
FOOTBALL MOSCOW
output
YES
DIN
FOO

input
2
DINAMO BYTECITY
DINAMO BITECITY
output
NO

input
3
PLAYFOOTBALL MOSCOW
PLAYVOLLEYBALL SPB
GOGO TECHNOCUP
output
YES
PLM
PLS
GOG

input
3
ABC DEF
ABC EFG
ABD OOO
output
YES
ABD
ABE
ABO


나의 접근:
1) 첫번째 중복인 놈을 처리
	먼저 첫번째가 2개 이상인 놈은 두번째를 선택한다.	my2[second]++
	이때 my2[second] 의 값도 2개 이상이면 답은 존재하지 않게 된다.
	
2) 남은 것들 처리
	남은 각각은 첫번째가 중복이 안된 것들이 남을 것이다.
	따라서 my2.count(fisrt) 가 0 이라면 첫번째를 선택하자. 물론 my2[first]++ 처리 필요.

	만약 my2 랑 중복이면 my2.count(second) 가 0 이라면 두번째를 선택한다. my2[second]++ 처리 필요.
		이경우도 중복이면 답은 존재하지 않게 된다.
	
틀렸다. ㅅㅂ
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<pair<string, string>> arr(n);
	rep(i, n) {
		string str1, str2; cin >> str1 >> str2;
		arr[i].first = str1.substr(0, 3);
		arr[i].second = str1.substr(0, 2) + str2[0];
	}
	map<string, int> my, my2;
	rep(i, n) my[arr[i].first]++;
	vi choose(n, 0);
	rep(i, n) if (my[arr[i].first] > 1) {
		choose[i] = 1;	// 두번째꺼 선택
		my2[arr[i].second]++;	// 선택된거 기록
	}
	map<string, int>::iterator it = my2.begin();
	for (; it != my2.end(); ++it) if (it->second > 1) {
		cout << "NO"; return 0;
	}
	rep(i, n) {
		if (choose[i] == 1) continue;
		string key = arr[i].first;
		if (my2.count(key) > 0) {
			string key2 = arr[i].second;
			if (my2.count(key2) > 0) {
				cout << "NO"; return 0;
			}
			else {
				choose[i] = 1;
				my2[key2]++;
			}
		}
		else {
			my2[key]++;
			choose[i] = 0;	// 굳이 할 필욘 없다.
		}
	}
	cout << "YES" << '\n';
	rep(i, choose.size()) {
		if (choose[i] == 0) cout << arr[i].first << '\n';
		else cout << arr[i].second << '\n';
	}
	return 0;
}

반례
	3
	AAA	C	// AAC
	AAA	K	// AAK
	AAB	D	// AAB
	AAC	B	// 으악!!

답은
	3
	AAA	C	// AAC
	AAA	K	// AAK
	AAB	D	// AAD
	AAC	B	// AAB

my2.count(arr[i].first) 가 존재하는 것을 먼저 처리하는 루틴을 추가해야 한다.
	http://codeforces.com/contest/782/submission/25392385  헌데 그래도 망하네 ㅠㅠ

반례
	5			1차		2차		남은것 처리
	A	K		K
	A	C		C
	D	E						D
	B	D						B	// 망함...
	C	B				B


답은
	5			1차		2차		dfs(B)	dfs(D)		남은것 처리(여기선 없으니 생략)
	A	K		K
	A	C		C
	D	E								"E"		// 뱀이 꼬리를 물듯 따라가야 한다.
	B	D						"D"
	C	B				B

my2.count(arr[i].first) 가 존재하는 놈을 처리하면서 dfs 로 연결된 놈들을 처리한다.

// 통과 함... 30ms 걸림 // 지저분한데..
map<string, int> my, my2, my3;
vi choose;
vector<pair<string, string>> arr;
// 현 노드는 오른쪽 것만 선택해야 한다.
int dfs(int node) {
	if (choose[node] != 0) return 0;	// 이미 처리된거면 이상무
	string keyL = arr[node].first, keyR = arr[node].second;
	if (my2.count(keyL) > 0) {			// 연결된 놈이 있으면 keyR 을 선택해야 한다.
		if (my2.count(keyR) > 0)
			return -1;	// 선택 불가능한 경우
		my2[keyR]++;
		choose[node] = 2;	// 오른쪽이 선택된다.
		int nextNode = my3[keyR];	// keyR 을 왼쪽 키로 갖는 노드를 찾는다.
		if (nextNode == -1)	" 이 루틴은 안탄다.. nextNode 가 -1 이 될일은 없다"
			return 0;		" 그래도 통과하네...ㅅㅂ 이런 코드는 대충 원리만 기억하자"
							" 내가 짠 코드 ... 내가 보기 힘드네.. 
		return dfs(nextNode);
	}
	// 아무 노드에도 연결 된 것이 아니면 일단 무시한다.
	return 0;	// 이건 첫 호출에만 타는 루틴이 된다.
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	arr.resize(n);
	rep(i, n) {
		string str1, str2; cin >> str1 >> str2;
		arr[i].first = str1.substr(0, 3);
		arr[i].second = str1.substr(0, 2) + str2[0];
	}
	rep(i, n) my[arr[i].first]++;
	choose.resize(n, 0);
	rep(i, n) if (my[arr[i].first] > 1) {
		choose[i] = 2;	// 두번째꺼 선택
		my2[arr[i].second]++;	// 선택된거 기록
	}
	map<string, int>::iterator it = my2.begin();
	for (; it != my2.end(); ++it) if (it->second > 1) {
		cout << "NO"; return 0;
	}
	// left 인덱스 기록 (일단 right 확정이 아니면 모두 left 로 설정)
	// 여기 left key 는 서로 같은게 없음 (choose[i] != 2 가 아닌 놈들)
	rep(i, n) if (choose[i] != 2) my3[arr[i].first] = i;
	
	// 첫번째 키가 중복될 시 두번째 키를 선택하도록 한다. 그리고 dfs 탄다.
	rep(i, n) {
		if (choose[i] == 2) continue;	// 항상 2번째 선택은 무시
		string keyL = arr[i].first;
		if (my2.count(keyL) > 0) {	// 첫번째 키가 중복인 놈들로 dfs
			int node = my3[keyL];
			int judge = dfs(node);
			if (judge == -1) {
				cout << "NO"; return 0;
			}
		}
	}
	// 그다음 나머지들을 처리한다	// choose[i] == 0 인 것들은 완전 독립된 놈들이라 아무거나 선택해도 무방
	cout << "YES" << '\n';
	rep(i, choose.size()) {
		if (choose[i] == 0 || choose[i] == 1) cout << arr[i].first << '\n';
		else cout << arr[i].second << '\n';
	}
	return 0;
}


// dfs 로 푼거: 
const int N = 1010;
int n, canUse[N][2];
char a[30], b[30];
string arr[N][2], sol[N];
map<string, int> vstd, pre;	// pre 는 이전에 방문했을 때의 인덱스가 기록되었음
// 과거 연결을 백트랙킹으로 바꿀 때 좋은 코드다. !!!!
int dfs(int here) {
	// 왼쪽, 오른쪽 중 사용 가능 하며(이건 최초 호출시만 연관됨)
	// 현재 처리 안된 즉, 맵에 기록이 안된 놈이면
	rep2(i, 0, 2) if (canUse[here][i] && !vstd[arr[here][i]]) {
		string str = arr[here][i];
		vstd[str] = 1;
		// pre[str]: 이전에 중복된 str의 인덱스를 찾아가서 갱신한다.
		// 이전에 중복 선택된 str 이 없거나, 중복선택된 str을 교체하여 ok 가 된다면
		if (pre[str] == 0 || dfs(pre[str])) {
			pre[str] = here;	// 이 str의 주인은 이제부턴 here 이얌!!!!
			sol[here] = str;
			return 1;
		}
	}
	return 0;
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	rep2(i, 1, n + 1) {
		scanf("%s%s", a, b);
		arr[i][0] = string{ a[0], a[1], a[2] };	// 좋은 표현이다.
		arr[i][1] = string{ a[0], a[1], b[0] };
	}
	rep2(i, 1, n + 1) {
		canUse[i][0] = canUse[i][1] = 1; // 일단 둘다 후보군임
		rep2(j, 1, n + 1) if (i != j && arr[i][0] == arr[j][0]) {
			canUse[i][0] = 0; break; // 뭐 갯수가 1000개 뿐이니 가능함.
		}
		vstd.clear();
		if (!dfs(i)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	rep2(i, 1, n + 1) printf("%s\n", sol[i].c_str());
	return 0;
}
	5		canUse	1번	2번			3번			4번			5번: 백트랙
1	A	K	1		pre[K] = 1

2	A	C	1			pre[C] = 2
		
3	D	E	0						pre[D] = 3
			1		
4	B	D	0									pre[B] = 4
			1
5	C	B	0												pre[C] 가 0 이 아님!!!! 즉 과거에 세팅 된 놈이기에 중복된 거라 보면 된다.
			1												dfs(pre[B]), pre[B] 도 0 이 아님
																dfs(pre[D], pre[D] 도 0 이 아님
																	pre[E]는 0임 즉 pre[E] = 3 으로 세팅됨
																pre[D] = 3 --> 4
															pre[B] = 4 --> 5

결과 고찰: 1000의 제곱만큼의 복잡도가 들지 않을까? "백트랙으로 계속 갱신이 일어나지 않을까?"
// 많아봐야 pre 세팅은 최대 2번 이라 본다.
// 최적 해로 정해진 거면 더이상 갱신이 안 일어나도 될테니
// 마치 유량 네트워크에서 본 그거(이분매칭) 같다...
" scc 를 이용 vs 이분매칭을 이용 "
// 범용성은 scc 를 가지고 함의그래프로 푸는게 더 좋은거 같다.


위 예시를 이분매칭으로 나타낸 그림

					A
	1 ______________			
					K
	2_______________
					C
	3_______________
	 \			   /D
	  \___________/_
	  ___________/	E
	4/______________
					B

	5 // C , B 랑 연결된 간선이 있음. 지저분해서 생략...



종만책 소스 이분매칭으로 푼거
bool adj[1010][2020] 의 사이즈가 클거 같았는데 2메가 바이트 밖에 안되넹.. bool 이라서 그런가..
int adj[1010][2020] 의 사이즈는 4배인 8메가 바이트임.. 결론은.. 작네..
통과도 15ms 로 매우 빠르다.
저정도 양에 대해선 매우 빠르군을 느낌.
	"O(VE)" 의 복잡도를 가진다 함. 아마 여긴 인접 행렬이니
	"이 코드의 복잡도는 V * 2V 가 된다고 봄."

const int N = 1010, M = 2020;
int n, m; bool adj[N][M];
vi aM, bM; vb vstd;
bool dfs(int a) {
	if (vstd[a]) return false;
	vstd[a] = true;
	for (int b = 0; b < m; ++b)	// 좀더 빠르게 하고 싶다면 인접리스트 구조로 하삼.
		if (adj[a][b])
			if (bM[b] == -1 || dfs(bM[b])) {
				aM[a] = b; bM[b] = a; return true;
			}
	return false;
}
int bpttM() {
	aM = vi(n, -1); bM = vi(m, -1);
	int size = 0;
	for (int start = 0; start < n; ++start) {
		vstd = vb(n, false);
		if (dfs(start)) ++size;
	}
	return size;
}

string arr[N][2];
map<string, int> cntF;	// 첫놈의 중복여부를 체크
map<string, int> keyS;	// string 에 대한 인덱스를 저장
map<int, string> valS;	// 인덱스에 대한 string
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n; m = n * 2;
	int idx = 0;
	rep(i, n) {
		string str1, str2; cin >> str1 >> str2;
		arr[i][0] = string{ str1[0], str1[1], str1[2] };
		arr[i][1] = string{ str1[0], str1[1], str2[0] };
		cntF[arr[i][0]]++;
		if (keyS.count(arr[i][0]) == 0)
			keyS[arr[i][0]] = idx, valS[idx] = arr[i][0], idx++;
		if (keyS.count(arr[i][1]) == 0)
			keyS[arr[i][1]] = idx, valS[idx] = arr[i][1], idx++;
	}
	rep(i, n) {
		int k1 = keyS[arr[i][0]], k2 = keyS[arr[i][1]];
		//if (cntF.count(arr[i][0]) == 1) // map 에선 count를 셀땐 최대 1... !!!!
		// 앞에게 같은 놈이 없는 경우 두개 다 연결, 그렇지 않으면 뒷놈만 연결
		if (cntF[arr[i][0]] == 1)
			adj[i][k1] = 1;
		adj[i][k2] = 1;
	}
	int sz = bpttM();
	if (sz != n)
		//puts("NO");
		cout << "NO";
	else {
		//puts("YES");	// ms 에선 정상 출력인데 gcc에선 puts 가 맨마지막에 출력됨..
						// cin, cout, sync_with_stdio  랑 puts 는 같이 쓰지 말자 !!!!
		cout << "YES" << '\n';
		rep(i, aM.size()) {
			int b = aM[i];
			string str = valS[b];
			cout << str << '\n';
		}
	}
	return 0;
}
" 위 코드의 이분매칭 부분을 제외한 핵심은
1) 앞 문자열 중복에 대한 체크: cntF; // countFirst
2) 각 문자열에 대한 번호 매기기: keyS;
3) 역참조용 : valS

void mapCountTest() {
	map<int, int> test1;
	test1[0]++;
	test1[0]++;
	cout << test1.count(0) << '\n';		// 1

	map<int, int> test2;
	test2[0] = 1;
	test2[0] = 2;
	cout << test2.count(0) << '\n';		// 1

	multimap<int, int> test3;
	//test3[0]++;	// 불가능
	//test3[0]++;	// 불가능
	//test3[0] = 1;	// 불가능
	//test3[0] = 2; // 불가능
	test3.insert(mp(0, 1));
	test3.insert(mp(0, 2));
	cout << test3.count(0) << '\n';		// 2
}

// 함의 그래프로 문제 풀기: 30ms 걸림
// 종만 소스 응용버전: 노드 갯수는 각 선택갯수의 2배임: 선택하는 자 * 4 배가 됨
// 김동이 제출한 소스는 각 선택갯수 그대로임. (선택하는 자 * 2배)
vvi adj;
vi sccId, dscv;
stack<int> st;
int sccCnt, vtxCnt;
int scc(int here) {
	int ret = dscv[here] = vtxCnt++;
	st.push(here);
	rep(i, adj[here].size()) {
		int there = adj[here][i];
		if (dscv[there] == -1)
			ret = min(ret, scc(there));
		else if (dscv[there] < dscv[here] && sccId[there] == -1)
			//return min(ret, dscv[there]); ㅅㅂ 오탄데도 재수로 통과네
			ret = min(ret, dscv[there]);
	}
	if (ret == dscv[here]) {
		while (true) {
			int t = st.top(); st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}
vi tarjanSCC() {
	sccId = dscv = vi(adj.size(), -1);
	sccCnt = vtxCnt = 0;
	rep(i, adj.size()) if (dscv[i] == -1) scc(i);
	return sccId;
}
set<int> ddSet;
void makeGraph(const vi& meetings) {
	int mtSize = meetings.size();
	adj.clear();
	adj.resize(mtSize * 2);
	// left 가 두개 이상 있는 놈들을 따로 기록
	map<int, int> mm;
	for (int i = 0; i < mtSize; i += 2) {
		mm[meetings[i]]++;
	}
	for (int i = 0; i < mtSize; i += 2) {
		if (mm[meetings[i]] > 1)
			ddSet.insert(i);	// 왼쪽이 같은게 두개 이상인 것들을 기록
	}
	" 이부분 6줄이 핵심이다!!!!" 2sat 이 아닌 1sat 추가하는 방법이다.
	// 무조건 거짓이 되어야 하는 선택이라면 (무조건 참이어야 되는 선택이라면 을 간선으로 어찌 표현 못했음.. 대신 거짓을 이용)
	// 참노드에서->거짓노드로 가는 엣지를 집어 넣는다.
	" 이건 내가 발견한 건데.. 그림으로 그리자면 scc 위상정렬에서 처음 선택 된 것을 
	" 바로 거짓으로 설정 함으로써: 참노드 는 거짓이 됨.
	" 그래서 참노드->거짓노드로 가는 간선을 그냥 넣어 봤는데
	" accepted 되네... 종이에 그려서 시뮬 해보자.
	multiset<int>::iterator it = ddSet.begin();	// set<int> 인데도 돌아가네.. 미친.. 물론 set<int>::itearator it 로도 당연히 돌아감.
	for (; it != ddSet.end(); ++it) {
		int trueNode = *it * 2;
		int falseNode = *it * 2 + 1;
		adj[trueNode].push_back(falseNode);
	}

	for (int i = 0; i < mtSize; i += 2) {
		int j = i + 1;
		adj[i * 2 + 1].push_back(j * 2);
		adj[j * 2 + 1].push_back(i * 2);
	}
	for (int i = 0; i < mtSize; ++i)
		for (int j = 0; j < i; ++j) {
			if (meetings[i] == meetings[j]) {
				adj[i * 2].push_back(j * 2 + 1);
				adj[j * 2].push_back(i * 2 + 1);
			}
		}
}
vi solve2SAT() {
	vi label = tarjanSCC();
	for (int i = 0; i < adj.size(); i += 2) if (label[i] == label[i + 1]) return vi();
	vpii order;
	for (int i = 0; i < adj.size(); ++i) order.push_back(mp(-label[i], i));
	sort(order.begin(), order.end());
	vi vbChoose(adj.size() / 2, -1); // 선택여부
	for (int i = 0; i < order.size(); ++i) {
		int node = order[i].second;
		int index = node / 2;
		if (vbChoose[index] != -1) continue;
		vbChoose[index] = !((node % 2) == 0);
	}
	return vbChoose;
}
vi solve(const vi& meetings) {
	makeGraph(meetings);	vi ret = solve2SAT();	return ret;
}
int idx = 0;
int getIndex(string str, map<string, int>& my, map<int, string>& myR) {
	if (my.count(string) == 0) {
		my[str] = idx;
		myR[idx] = str;
		idx++;
	}
	return my[str];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi meetings(n * 2);
	map<string, int> my;
	map<int, string> myR;
	int index = 0;
	rep(i, n) {
		string str1, str2;	cin >> str1 >> str2;
		str1 = str1.substr(0, 3);
		str2 = str1.substr(0, 2) + str2[0];
		// getIndex 함수 호출하는 형식으로 하는게 직관적이고 깔끔하네.... !!!!
		
		if (my.count(str1) == 0) {		
			myR[index] = str1;  my[str1] = index++;
		}
		if (my.count(str2) == 0) {
			myR[index] = str2;	my[str2] = index++;
		}
		meetings[i * 2] = my[str1];
		meetings[i * 2 + 1] = my[str2];
	}
	vi value = solve(meetings);
	if (value.empty()) cout << "NO";
	else {
		cout << "YES" << '\n';
		for (int i = 0; i < 2 * n; i += 2) {
			if (value[i] == 1) {
				int idx = meetings[i];
				cout << myR[idx] << '\n';
			}
			else {
				int idx = meetings[i+1];
				cout << myR[idx] << '\n';
			}
			/*	// 이렇게 해도 통과 됨.
			if (value[i + 1] == 1) {
				int idx = meetings[i + 1];
				cout << myR[idx] << '\n';
			}
			else {
				int idx = meetings[i];
				cout << myR[idx] << '\n';
			}
			*/
		}
	}
	return 0;
}
// 이제야 깨달았다 확실히~~
1.	A	B
2.	C	D
3.	E	F
4.	F	H	// 여기선 F를 선택하면 안된다고 할때
논리식으로 나타내면
1번방식 " (A U B) ^ (C U D) ^ (E U F) ^ (H)	" // 이렇게 된다.
2번방식 " (A U B) ^ (C U D) ^ (E U F) ^ (!F) " // 위랑 동급이다. // 이게 더 좋다고 본다.
2번 방식으로 
	이때 !F를 "(!F U !F)" 로 나타 낼수 있다.
	그걸 함의 그래프로 나타내면
	F->!F 가 된다.

void makeGraph(const vi& meetings) {
	...
	for (int i = 0; i < mtSize; i += 2) {
		if (mm[meetings[i]] > 1)
			ddSet.insert(i);	// 왼쪽이 같은게 두개 이상인 것들을 기록
	}
	set<int>::iterator it = ddSet.begin();	
	for (; it != ddSet.end(); ++it) {
		int trueNode = *it * 2;
		int falseNode = *it * 2 + 1;
		adj[trueNode].push_back(falseNode);
	}
	...
}

1번 방식으론 만약 (H)를 그대로 표현 한다면
	!H->H 가 된다.
void makeGraph(const vi& meetings) {
	...
	for (int i = 0; i < mtSize; i += 2) {
		if (mm[meetings[i] > 1)
			ddSet.insert(i+1);	// 왼쪽이 같은게 두개 이상인 경우 오른쪽을 기록
	}
	set<int>::iterator it = ddSet.begin();
	for (; it != ddSet.end(); ++it) {
		int trueNode = *it * 2;
		int falseNode = *it * 2 + 1;
		adj[falseNode].push_back(trueNode);
	}
	...
}
이럼 과연 통과되냐??
	"안된다!!!!"
Input
3
PLAYFOOTBALL MOSCOW
PLAYVOLLEYBALL SPB
GOGO TECHNOCUP
Participant's output
YES
PLA	// 이건 답이 될 수 없다. 
PLS
GOG
Jury's answer
YES
PLM
PLS
GOG
	else {
		cout << "YES" << '\n';
		for (int i = 0; i < 2 * n; i += 2) {
									// makeGraph에서 만든 간선들이
//			if (value[i] == 1) {	// value[i] == 1 && value[i+1] == 1 인 케이스를 잡아내지 못한다.
									// 2번 방식이 더 편한 이유가 된다. 
									// 직접 F 를 선택하지 못하도록 간선을 만들기 때문이다.
			if (value[i] == 1 && value[i+1] == 0) {
				int idx = meetings[i];
				cout << myR[idx] << '\n';
			}
			else {
				int idx = meetings[i+1];
				cout << myR[idx] << '\n';
			}
		}
	}
// 깔끔 버전
int index;
map<string, int> my;
map<int, string> myR;
int getIndex(string& str) {
	if (my.count(str) == 0) {
		my[str] = index;
		myR[index] = str;
		index++;
	}
	return my[str];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi meetings(n * 2);

	rep(i, n) {
		string str1, str2;	cin >> str1 >> str2;
		str1 = str1.substr(0, 3);
		str2 = str1.substr(0, 2) + str2[0];
		int idx1 = getIndex(str1);	" 오오. 이런식으로 분리해 놓으니까 머리가 복잡해 지지 않고 너무 좋다"
		int idx2 = getIndex(str2);
		meetings[i * 2] = idx1;
		meetings[i * 2 + 1] = idx2;
	}
	vi value = solve(meetings);
	if (value.empty()) cout << "NO";
	else {
		cout << "YES" << '\n';
		for (int i = 0; i < 2 * n; i += 2) {
			if (value[i] == 1) {
				int idx = meetings[i];
				cout << myR[idx] << '\n';
			}
			else {
				int idx = meetings[i+1];
				cout << myR[idx] << '\n';
			}
		}
	}
	return 0;
}

// 김동소스
http://codeforces.com/contest/782/submission/25296651
// 내식으로 수정버전 적을까 했는데... 안적음요. 별로 2sat 해결에 좋은건 아니라 봄.

// 최종 버전: 좀더 확실히 하기 위해
vvi adj;
vi sccId, dscv;
stack<int> st;
int sccCnt, vtxCnt;
int scc(int here) {
	int ret = dscv[here] = vtxCnt++;
	st.push(here);
	rep(i, adj[here].size()) {
		int there = adj[here][i];
		if (dscv[there] == -1)
			ret = min(ret, scc(there));
		else if (dscv[there] < dscv[here] && sccId[there] == -1)
			//return min(ret, dscv[there]); ㅅㅂ 오탄데도 재수라 통과해서
			// 다른 문제에 그대로 활용하다 망함요..
			ret = min(ret, dscv[there]);
	}
	if (ret == dscv[here]) {
		while (true) {
			int t = st.top(); st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}
vi tarjanSCC() {
	sccId = dscv = vi(adj.size(), -1);
	sccCnt = vtxCnt = 0;
	rep(i, adj.size()) if (dscv[i] == -1) scc(i);
	return sccId;
}
set<int> ddSet;
void makeGraph(const vi& meetings) {
	int mtSize = meetings.size();
	adj.clear();
	adj.resize(mtSize * 2);
	// left 가 두개 이상 있는 놈들을 따로 기록
	map<int, int> mm;
	for (int i = 0; i < mtSize; i += 2) {
		mm[meetings[i]]++;
	}
	for (int i = 0; i < mtSize; i += 2) {
		if (mm[meetings[i]] > 1)
			ddSet.insert(i);	// 왼쪽이 같은게 두개 이상인 것들을 기록
	}
	"아래 8줄이 핵심이 된다." (!F U !F) ^ (S U S) !!!!
	set<int>::iterator it = ddSet.begin();
	for (; it != ddSet.end(); ++it) {
		int fTrueNode = *it * 2;
		int fFalseNode = *it * 2 + 1;
		adj[fTrueNode].push_back(fFalseNode);

		int sTrueNode = (*it + 1) * 2;
		int sFalseNode = (*it + 1) * 2 + 1;
		adj[sFalseNode].push_back(sTrueNode);
	}

	for (int i = 0; i < mtSize; i += 2) {
		int j = i + 1;
		adj[i * 2 + 1].push_back(j * 2);
		adj[j * 2 + 1].push_back(i * 2);
	}
	for (int i = 0; i < mtSize; ++i)
		for (int j = 0; j < i; ++j) {
			if (meetings[i] == meetings[j]) {
				adj[i * 2].push_back(j * 2 + 1);
				adj[j * 2].push_back(i * 2 + 1);
			}
		}
}
vi solve2SAT() {
	vi label = tarjanSCC();
	for (int i = 0; i < adj.size(); i += 2) if (label[i] == label[i + 1]) return vi();
	vpii order;
	for (int i = 0; i < adj.size(); ++i) order.push_back(mp(-label[i], i));
	sort(order.begin(), order.end());
	vi vbChoose(adj.size() / 2, -1); // 선택여부
	for (int i = 0; i < order.size(); ++i) {
		int node = order[i].second;
		int index = node / 2;
		if (vbChoose[index] != -1) continue;
		vbChoose[index] = !((node % 2) == 0);
	}
	return vbChoose;
}
vi solve(const vi& meetings) {
	makeGraph(meetings);
	vi ret = solve2SAT();
	return ret;
}
int index;
map<string, int> my;
map<int, string> myR;
int getIndex(string& str) {
	if (my.count(str) == 0) {
		my[str] = index;
		myR[index] = str;
		index++;
	}
	return my[str];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi meetings(n * 2);

	int index = 0;
	rep(i, n) {
		string str1, str2;	cin >> str1 >> str2;
		str1 = str1.substr(0, 3);
		str2 = str1.substr(0, 2) + str2[0];
		int idx1 = getIndex(str1);
		int idx2 = getIndex(str2);
		meetings[i * 2] = idx1;
		meetings[i * 2 + 1] = idx2;
	}
	vi value = solve(meetings);
	if (value.empty()) cout << "NO";
	else {
		cout << "YES" << '\n';
		for (int i = 0; i < 2 * n; i += 2) {
			if (value[i] == 1) {
				int idx = meetings[i];
				cout << myR[idx] << '\n';
			}
			else {
				int idx = meetings[i+1];
				cout << myR[idx] << '\n';
			}
		}
	}
	return 0;
}



// 망한 실수: 중간에 코드를 변경 하는데 앞에놈도 수정해야 하는데 못했다.!!!!
http://codeforces.com/contest/787/submission/25737236
	rep2(i, 1, 200001) {
		if (i - a < 0) continue;	// i - b 로 수정되어야 함
		if (i - c < 0) continue;	// i - d 로 수정되어야 함
		int tmp1 = i - b;	// 원랜 i - a 였으며 수정됨
		int tmp2 = i - d;	// 원랜 i - c 였으며 수정됨.
		if ((tmp1 % a == 0) && (tmp2 % c == 0)) {
			ok = true;
			sol = i;
			break;
		}
	}
이런건 변수를 한군데에 나둬서 처리해야 중간 변경시 오타가 안생긴다.
	rep2(i,1,200001) {
		int tmp1 = i - b;
		int tmp2 = i - d;
		if (tmp1 < 0) continue;
		if (tmp2 < 0) continue;
		if ((tmp1 % a == 0) && (tmp2 % c == 0)) {
			ok = true;
			sol = i;
			break;
		}
	}


http://codeforces.com/contest/789/problem/B
// 영어가 좆같은 문제여.
input
3 2 30 4	// b1, q, l, m // 초기치, q: 공비, l: 한계, m: 나오면 안되는 수들
6 14 25 48	// 나오면 안되는 수
output
3			// 3, 6, 12, 24, 48 ... 에서 6은 안됨 30보다 큰 수도 안됨 그래서 카운트는 3

llabs(b1) 이 처음부터 l 보다 크면 루프는 바로 종료가 되어야 하는 문제였음.
내 생각은 무한히 돌려서 l보다 큰건 제외로 해석한 거 였고...
대다수가 나의 생각과 비슷해서 망함요.
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	ll b1, q, l, m;
	cin >> b1 >> q >> l >> m;
	map<ll, int> my;
	rep(i, m) {
		ll a; cin >> a;
		my[a]++;
	}
	ll sol = 0;
	if (llabs(b1) > l) {
		cout << 0;		// !!!! 으아아악 영어가 좆같은 문제네. 
						// terminate 된다를 정확히 명시 했어야지.
						// 이런 좆같은 상황도 예측하여 풀자. ㅅㅂ
	}
	else if (b1 == 0) {
		if (my.count(0) > 0 )
			cout << 0;
		else
			cout << "inf";
	}
	else {
		if (q == 0) {	// 0 이 반복될 경우
			ll a1 = b1;
			ll a2 = 0;
			if (my.count(a2) == 0) {
				cout << "inf";
			}
			else if (my.count(a1) == 0 && llabs(a1) <= l)
				cout << 1;
			else
				cout << 0;
			return 0;
		}
		else if (q == -1 || q == 1) {	// 자신, -자신이 반복될 경우
			ll a1 = b1;
			ll a2 = b1*q;
			map<ll, int> my2;
			if (llabs(a1) <= l) my2[a1]++;
			if (llabs(a2) <= l) my2[a2]++;
			map<ll, int>::iterator it = my2.begin();
			for (; it != my2.end(); ++it) {
				ll key = it->first;
				if (my.count(key) == 0) {
					cout << "inf";
					return 0;
				}
			}
			cout << 0;
			return 0;
		}
		else {
			ll tmp = b1;
			while (llabs(tmp) <= l) {
				if (my.count(tmp) == 0)
					sol++;
				tmp *= q;
			}
			cout << sol;
		}
	}
	return 0;
}

// 좀더 깔끔하게 짜자.
int main() {
	ll b1, q, l, m;
	cin >> b1 >> q >> l >> m;
	map<ll, int> my;
	rep(i, m) {
		ll ai; cin >> ai;
		my[ai]++;
	}
	ll sol = 0;
	ll tmp = b1;
	map<ll, int> my2;
	int roopCnt = 0;
	while (llabs(tmp) <= l) {
		if (my.count(tmp) == 0)
			my2[tmp]++;
		tmp *= q;
		if (roopCnt++ > 64) break;
	}
	map<ll, int>::iterator it = my2.begin();
	bool isINF = false;
	for (; it != my2.end(); ++it)
		if (it->second > 1)
			isINF = true;
	if (isINF)
		cout << "inf";
	else
		cout << my2.size();
	return 0;
}


http://codeforces.com/contest/789/problem/C
구간의 합 중 가장 큰 값을 구하는 문제 응용 버전
6
1	4	2	3	1	7
// 음수랑 양수가 반복된다.
3	-2	1	-2	6		// 시작 인덱스에 따라 음양이 뒤집힘을 알수 있다.
	2	-1	2	-6
		1	-2	6
			2	-6
				6

f(1, 4) = 3 + -2 + 1 = 2
f(2, 5) = 2 + -1 + 2 = 3
f(x, y) 가 최대가 되는 값을 구하라. // 6

ll fMS1(const vector<ll>& arr) {
	int n = arr.size();
	ll ret = arr[0], psum = arr[0];
	for (int i = 1; i < n - 1; i += 2) {
		// psum: i번째 원소를 포함하는 [0..i] 중 일부 구간의 최대값
		// arr[i]: 음수, arr[i+1]: 양수
		psum = max<ll>(0, psum) + arr[i] + arr[i + 1];
		// 앞 psum이 0이고 arr[i] 가 음수인 경우 arr[i+1] 만 취하도록 한다.
		psum = max<ll>(psum, arr[i + 1]);
		ret = max<ll>(ret, psum);
	}
	return ret;
}
ll fMS2(const vector<ll>& arr) {
	int n = arr.size();
	if (arr.size() == 1) return 0;	// 선택할게 없다.
	ll ret = arr[1], psum = arr[1];
	for (int i = 2; i < n - 1; i += 2) {
		psum = max<ll>(0, psum) + arr[i] + arr[i + 1];
		psum = max<ll>(psum, arr[i + 1]);
		ret = max<ll>(ret, psum);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<ll> arr(n), fArr1, fArr2;
	rep(i, n) cin >> arr[i];
	rep(i, n - 1) {
		ll mul = -1;
		if (i % 2 == 0) mul = 1;
		fArr1.push_back(llabs(arr[i] - arr[i + 1]) * mul);
		fArr2.push_back(llabs(arr[i] - arr[i + 1]) * mul * (-1));
	}
	ll sol1 = fMS1(fArr1);
	ll sol2 = fMS2(fArr2);
	cout << max<ll>(sol1, sol2);
	return 0;
}


http://codeforces.com/contest/789/problem/D
input
5 4
1 2
1 3
1 4
1 5
output
6

각 모든 간선을 2개 빼고 2번씩 돌아가는 패스의 수를 구하시오.
단 패스의 구분은 1번통과하는 패스의 집합으로 결정됩니다.

 m개의 간선이 있는 경우 m - 2 개 간선은 총 두번 통과해야 하고 2 개의 간선은 한번씩 통과가 되어야 한다.
"오일러패스 문제"
셀프패스도 있으며 노드쌍(u, v) 에 대한 최대 패스 수는 한개씩 있다.
먼저 셀프패스를 제외하고 생각 해보자
	"각 노드를 기준으로 2개의 엣지는 한번씩 선택되면 
	"그래프의 모양은 홀수점이 2개가 된다.
	"즉 한 노드에 대해 edge[i] C 2 가 된다.
셀프패스가 한개만 선택된 경우
	"셀프패스로 인한 노드 차수는 짝수개 증가한다. 즉 오일러 패스는 제약받지 않는다.
	"셀프패스가 아닌 하나의 엣지만 선택하면 그건 양 끝단을 홀수차수가 되도록 하기에
	"이경우 갯수는 selfEdge * (m - selfEdge) 가 된다. 
	// 셀프엣지에서 하나 선택 * 셀프엣지가 아닌 것에서 하나 선택
셀프패스가 두개다 선택된 경우
	"selfEdge C 2 가 된다.

int n, m;
vi graph[1000005];
int edge[1000005];
// 정점수, 엣지수가 백만개라 타임 오버가 난다.
set<int> vstd;
void dfs(int h) {
	vstd.insert(h);
	rep(i, graph[h].size()) {
		int t = graph[h][i];
		if (vstd.count(t)) continue;
		dfs(t);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int selfEdgeCnt = 0;
	rep(i, m) {
		int u, v; cin >> u >> v;
		u--; v--;
		if (u != v) {
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		else {
			selfEdgeCnt++;
		}
	}
	// 도로가 없는 노드는 생략해야함.
	int noEdgeCnt = 0;
	rep(i, n) if (graph[i].size() == 0) noEdgeCnt++; 
	rep(i, n) {
		if (graph[i].size() > 0) {	// 도로가 있는 노드에서 시작해야 한다.
			dfs(i);	
			break;
		}
	}
	ll sol = 0;
	if (vstd.size() != n - noEdgeCnt) 
		cout << sol;
	else {
		rep(i, n) {
			ll edgeCnt = graph[i].size();
			if (edgeCnt <= 1) continue;
			ll add = edgeCnt * (edgeCnt - 1) / 2;
			sol += add;
		}
		ll add1 = (ll)selfEdgeCnt * (selfEdgeCnt - 1) / 2;
		ll add2 = (ll)selfEdgeCnt * (m - selfEdgeCnt);
		sol = sol + add1 + add2;
		cout << sol;
	}
	return 0;
}


5 5
1 1
2 2
3 3
4 4
5 5
// 내코드 10 // 답 0 // vstd 가 필요하네.


int n, m;
vi graph[1000005];
int vstd[1000005];
int f[1000005];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int selfEdgeCnt = 0;
	rep(i, n) f[i] = i;
	rep(i, m) {
		int u, v; cin >> u >> v;
		u--; v--;
		vstd[u] = vstd[v] = 1;
		if (u != v) {
			graph[u].push_back(v);
			graph[v].push_back(u);
			f[find(u)] = find(v);
		}
		else {
			selfEdgeCnt++;
		}
	}
	int base = -1;
	rep(i, n) if (graph[i].size() != 0) {
		base = i; break;
	}
	/*	// 잘못된 코드..
	rep(i, n) if (find(i) != find(base) && graph[i].size() == 0) {
		cout << 0; return 0;
	}*/
	// 같능 집합에 속한 노드가 아니고 방문이 필요한 노드라면 패스가 존재하지 않는다.
	rep(i, n) if (find(i) != find(base) && vstd[i] == 1) {
		cout << 0; return 0;
	}
	ll sol = 0;
	rep(i, n) {
		ll edgeCnt = graph[i].size();
		if (edgeCnt <= 1) continue;
		ll add = edgeCnt * (edgeCnt - 1) / 2;
		sol += add;
	}
	ll add1 = (ll)selfEdgeCnt * (selfEdgeCnt - 1) / 2;
	ll add2 = (ll)selfEdgeCnt * (m - selfEdgeCnt);
	sol = sol + add1 + add2;
	cout << sol;

	return 0;
}


// 정말 깔끔한 코드
http://codeforces.com/contest/788/submission/25902453
const int N=1010000;
int n,m,u,v,f[N],vis[N];
ll sf,deg[N],ans;
int find(int x) {	// 부모를 리턴한다.
	return f[x]==x?x:f[x]=find(f[x]);
}
int main() {
	scanf("%d%d",&n,&m);
	if (m<2) {
		puts("0");
		return 0;
	}
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		f[find(u)]=find(v);
		vis[u]=1; vis[v]=1;
		if (u==v) sf++;
		else deg[u]++,deg[v]++;
	}
	int r=0;
	rep(i,1,n+1) if (vis[i]) r=i;
	rep(i,1,n+1) if (find(i)!=find(r)&&vis[i]) {
		puts("0");
		return 0;
	}
	ans=sf*(sf-1)/2+sf*(m-sf);
	rep(i,1,n+1) ans+=deg[i]*(deg[i]-1)/2;
	printf("%lld\n",ans);
}




http://codeforces.com/contest/789/problem/E
"!!!! 매우 좋은 문제"
// 농도 맞추기 문제
// 기본 1000 짜리 
n(0 <= n <= 1000)	k(1 <= k <= 1000000)
400 4		// 400 농도를 만들자, 각 종류가 4가지 농도가 있다.
100 300 450 500	// 100/1000 , 300/1000 , 340/1000 , 500/1000

2	// 300/1000 + 500/1000 => 800/2000 = 400/1000

50 2	// 50/1000 , 2가지
100 25	// 100/1000 , 25/1000

3	// 100+25+25 / 1000+1000+1000 => 150/3000


// 농도 문제 풀이
n/1000 을 맞추기 위해 m 개가 필요하다면 (s1, s2, ..., sm) 
 (s1 + s2 + ... + sm)      n
--------------------- = ------
       1000 * m          1000

 (s1 + s2 + ... + sm)      
--------------------- = n
         m          
	  
 (s1 + s2 + ... + sm) = n * m      
s1 + s2 + ... + sm = n + n + ... + n
"(s1-n) + (s2-n) + ... + (sm-n) = 0 " !!!! 이거 유도가 핵심이네. 
	 "거치는 모든 합을 0으로 만드는 걸 찾는 문제" 4000개 종류는 확실히 돌릴거라 봄.
	 5 -1 -2 -2 = 0
"합이 0이 되는 최단 갯수를 찾으면 된다" 철인 N종 경기 문제
각 농도들은 (0 <= ai <= 1000) 의 값을 가지고 있다.
농도 상자 종류수 k 는 (1 <= k <= 1000000) 백만개까지 된다
각 상자는 무한히 쓸수 있다.

이 경우 상자 종류수 k는 의미가 없다.
최대 1001 (0 ~ 1000)가지의 농도만 신경쓰면 된다.
	// 복잡도 O(2000 * 1000) // pq 는 상수시간이라 생각하자. spfa

// 다익스트라 알고리즘을 이용해 철인 N종 경기 문제 를 참고하자 (종만)
// 물론 코드포스 풀이대로 bfs 로 풀어도 된다.
// 시작지점을 2010 으로 해놓자.
const int MX = 2020;
const int START = 2010;
int V;
vpii adj[MX];
vi dijkstra(int src) {
	vi dist(MX, INF);
	dist[src] = 0;
	priority_queue<pii> pq;
	pq.push(mp(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(mp(-nextDist, there));
			}
		}
	}
	return dist;
}
int vertex(int dt) { return dt + 1000; }
int solve(cvi& arr) {
	V = MX;
	rep(i, V) adj[i].clear();
	rep(i, arr.size()) {
		int dt = arr[i];
		adj[START].push_back(mp(vertex(dt), 1));
	}
	for (int dt = -1000; dt <= 1000; ++dt) {
		rep(i, arr.size()) {
			int next = dt + arr[i];
			if (abs(next) > 1000) continue;
			adj[vertex(dt)].push_back(mp(vertex(next), 1));
		}
	}
	vi shortest = dijkstra(START);
	int ret = shortest[vertex(0)];
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	map<int, int> my;
	rep(i, k) {
		int a; cin >> a;
		my[a - n]++;
	}
	vi arr;
	map<int, int>::iterator it = my.begin();
	for (; it != my.end(); ++it) arr.push_back(it->first);
	int sol = solve(arr);
	if (sol == INF)		cout << -1;
	else				cout << sol;
	return 0;
}

// bfs로 구현 해봤다. 500ms 위랑 거의 같은 속도다.
// 입력이 백만개라 거기서 시간을 대부분 차지하는거 같다.
const int MX = 1010;
const int START = 2010;
int adj[2020][2020];
void dfs(int src, vi& dist) {
	dist = vi(2020, -1);
	queue<int> q;
	dist[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int here = q.front(); q.pop();
		rep(i, 2020) {
			if (adj[here][i] == 1) {
				int there = i;
				if (dist[there] == -1) {
					q.push(there);
					dist[there] = dist[here] + 1;
				}
			}
		}
	}
}
int vertex(int dt) { return dt + 1000; }
int solve(cvi& arr) {
	rep(i, arr.size()) {
		int nxt = vertex(arr[i]);
		adj[START][nxt] = 1;
	}
	for (int dt = -1000; dt <= 1000; ++dt) {
		rep(i, arr.size()) {
			int dt2 = dt + arr[i];
			int here = vertex(dt);
			int there = vertex(dt2);
			if (abs(dt2) > 1000) continue;
			adj[here][there] = 1;
		}
	}
	vi dist;
	dfs(START, dist);
	return dist[vertex(0)];
}


// 임시 코드 구글 qu 3번
#include <cstdio>
#include <queue>
#include <iostream>       
#include <string>
#include <vector>
#include <fstream>        
#include <functional> 
#include <algorithm>  
#include <cstdlib>    
#include <cstring>    
#include <map>        
#include <iomanip>    
#include <limits> 
#include <unordered_map>
#include <set>
#include <cmath>
#include <numeric> //accumulate
#include <stack>
#include <bitset>

//#include <unordered_set>//unordered_set

#define rep(i,a) for (int i = 0; i < (a); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define PI 3.14159265359;

using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef const vector<int> cvi;
typedef vector<bool> vb;

//const ll INF = 1ull << 62;
const int INF = 987654321;
const int MOD = 1000000007;


int main() {
	//freopen("B-large.in", "r", stdin);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	rep(cc, cs) {
		ll n, k; cin >> n >> k;
		ll oddCnt = 0, evenCnt = 0;
		ll preCnt = 0, needCnt = 0, add = 1;
		if (n % 2 == 1) 
			oddCnt++;
		else 
			evenCnt++;
		ll n1, n2; // n1: 큰쪽, n2: 작은쪽
		n1 = n;
		ll sol1, sol2;
		while (true) {
			ll hiCnt;
			if (k <= preCnt + add) {
				needCnt = k - preCnt;
				if (n1 % 2 == 1)
					hiCnt = oddCnt;
				else
					hiCnt = evenCnt;
				ll tmp;
				if (needCnt <= hiCnt) 	// 여유가 있으면
					tmp = n1;
				else 
					tmp = n2;
				tmp--;
				sol2 = tmp / 2;
				sol1 = tmp - sol2;
				break;
			}
			preCnt += add;
			add *= 2;
			ll oddTmp = evenCnt;
			ll evenTmp = oddCnt * 2 + evenCnt;
			evenCnt = evenTmp;
			oddCnt = oddTmp;
			n--;
			n1 = (n + 1) / 2;
			
			n2 = n1 - 1;
			n = n1;
		}
		cout << "Case #" << cc + 1 << ": " << sol1 << " " << sol2 << '\n';
	}
	return 0;
}


// uva the archeologist's dilemma 책문제 35
2의 지수승으로 123456789123456789를 prefix로 가지는
숫자를 만드는데 가장 작은 지수승 값을 구하라. (단 prefix 의 칸수는 제외된 칸수보다 작다)
여기선 prefix 말고 제외된 칸수는 19개 이상이 된다.

// 나의 의문
"2의 지수승으로 prefix 를 만족하는 수를 다 나타낼 수 있는가?" // 왠지 될거 같거등...

https://apps.topcoder.com/forums/%3bjsessionid=D9405DCD7CE2FE76C5AAE18865745C11?module=Thread&threadID=599092&start=0&mc=4#913120
 One can prove that for any irrational number r, the set {n*r (mod 1) | n = 1,2,...} is dense in [0,1]
	// (mod 1) 소수점만 남긴다는 뜻
	// 어떤 무리수든 간에 저 집합은 [0, 1] 을 꽉 채웁니다.
	// 0에서 1까지 들어가는 소수점 이하들이 빈틈없이 빽빽하다는 겁니다.
	// https://books.google.co.kr/books?id=QZ1QY4CWZv4C&printsec=frontcover&redir_esc=y#v=onepage&q&f=false


로그의 성질
	"log2(x) = log10(x) / log10(2)"
	// ex) log2(8) = log10(8) / log10(2) = 3*log10(2) / log10(2) = 3



http://blog.csdn.net/liukaipeng/article/details/3361701
	"104 * 10^T <= 2^N < 105 * 10^T"	//!!!! 이해핵심 답은 2^N = 1048576 즉 N: 20
	"log2(104) + Tlog2(10) <= N < log2(105) + Tlog2(10)

/*
	Let P denotes the prefix, T denotes the # of lost digits. We are searching
	for N, that the prefix of 2^N is P.
	P가 표시된 수임, T는 안보이는 숫자칸 갯수.
	2^N 의 prefix 가 P 랑 일치하는 최소 N을 구한다.
	
	2^N은 아래와 같은 방정식을 만족하는 것이 반드시 존재한다.
		P * 10^T <= 2^N < (P+1) * 10^T
	thus
		log2(P*10^T) <= log2(2^N) < log2((P+1)*10^T)
		log2(P) + T*log2(10) <= N < log2(P+1) + T*log2(10)
	
	"좌항을 올림한 값과 우항을 내림한 값이 한가지로 일치한다면 그게 답이지롱"

	추가로 안보이는 숫자칸의 갯수는 P의 자리값을 무조건 넘어야 한다.
		P < 10^(T-1)
		ex) P가 2자리 수면 안보이는 숫자칸의 수 T는 3이상이 된다.
		다르게 표현하자면
		log10(P) < log10(10^(T-1))
		log10(P) < T - 1
		log10(P) + 1 < T
*/
long double minexpof2with(long double prefix) {
	long double lower = log2l(prefix);
	long double upper = log2l(prefix + 1);
	long double f = log2l(10);	// 10을 로그 취한거
	long double t = ceill(log10l(prefix + 0.5)) + 1;	// 안보이는 칸은 적어도 t개
	// 0.5를 더한 이유는 prefix가 1인 경우 avoid log10l(1) == 0 이 되니까 올림해도 0이므로
	// 뭐 가독성 좋게 log를 안쓰고 자릿수를 구해서 할 수도 있다.
	// 짧은 코드니 기억해 놓자.!!!!
	for (; ceill(lower + t * f) != floorl(upper + t * f); t += 1) {
		// t를 하나씩 늘리는것은 2 씩 곱해주는 거라고 보면 된다.
		//cout << lower + t * f << " " << upper + t * f << '\n';
		"t * f 가 의미하는 것: log2(10^t) = t * log2(10)
		"최초 t는 최소한 차지하는 자리칸 수" 
	}
	//cout << lower + t * f << " " << upper + t * f << '\n';
	return ceill(lower + t * f);
}
int main() {
	long double prefix;
	while (cin >> prefix)
		cout << (long long)minexpof2with(prefix) << '\n';
	return 0;
}


prefix 가 10 일때
10	// input, 아래는 debug용 포함: debug 는 소수점 4자리까지 표현
// t는 3이상부터 시작한다. f: 3.3219
13.2877		13.4252		// 2^13.2877 = 10000		2^13.4252 = 11000		// 3.3219 + 3*3.3219		3.4594 + 3.3219
16.6096		16.7471		// 2^16.6096 = 100000		2^16.7471 = 110000
19.9316		20.0691		// 2^19.9316 = 1000000		2^20.0691 = 1100000
						// 1000000 과 1100000 사이에 2^20 이 존재한다능
" 게다가 10 * 10^T 와 11* 10^T 사이에 존재가능한 2^의 지수승은 절대 1개를 초과 못함. 이해의 핵심 !!!!
20	// 답임 : 2^20 = 1048576


//  123456789~~~ 인 숫자가 있다. 앞에서 부터 9개의 숫자가 일치하는 2^N 인 수가 있다고 할때 N의 값을 구하여라
2^158591339.00000000 = 123456789~~~
2^158591339.00000003 = 123456790~~~

// OMG 울프람으로 2^158591339 를 돌려보니 123456789~~~ 가 안나온다.
62759188 이 정답이다.
// 근디 아래소스는 정답을 출력하네.. https://github.com/morris821028/UVa/blob/master/volume007/701%20-%20The%20Archeologists%27%20Dilemma.cpp
// len * log(10) / log(2) 가 정확도가 더 높아서 발생한 현상으로 보인다.
// 그렇담 윗 소스가 틀렸단 거냐?
" NO NO vs 에선 long double 을 제대로 지원 안해서 생긴 문제다."
// web compiler 에서 돌려보니 정답인 62759188 을 출력한다.
int main() {
	int len;
	double a, left, right;
	char s[20];
	while (scanf("%s", s) != EOF)
	{
		len = strlen(s) + 1;
		a = atof(s);
		while (1)
		{
			left = log(a) / log(2) + len*log(10) / log(2);
			right = log(a + 1) / log(2) + len*log(10) / log(2);
			if ((int)left<(int)right)
				break;
			len++;
		}
		int ans = ceil(left);
		printf("%d\n", ans);
	}
	return 0;
}


책 풀이 소스는 log10() 을 이용했다. 해설이 좆같고 코드도 가독성이 떨어져서 gg
	단 더블링 형식 이분서치를 이용하여 속도를 빠르게 할 수 있다는 것 기억하자.
"존나 빠르다...ㄷㄷㄷ 답도 정확하네.."
미리 계산한 건 70777 개 밖에 안되는데
	어떻게 123456789 에 대한 답인 62759188 을 구할 수 있는건가.. 신기하네
70777 -> 777 로 고치면 답은 안나옴 (209723496 이 출력된다만 2^209723496 취하면 123456789~~~ 가 출력되긴 함)






"고찰 만약 기본이
1.1 + t * 0.5
1.2 + t * 0.5 
인 경우 
	1.6		2.1		2.6		3.1 ...
	1.7		2.2		2.7		3.2 ...
	// 영원히 답이 안나오지 않는가?
"맨 위에 설명했듯이
t * f 의 소수점 부분은 [0, 1] 을 빽빽하게 채운다.
답은 항상 존재한다.
	lower + t * f 의 소수점 부분이 좌측에서 0에 가까운 놈이 존재 할 것이다.
	이 경우
	upper + t * f 의 소수점 부분은 0보다 크게 된다.
	// 즉 답은 반드시 존재한다.

// 문제는 시간복잡도다... 어찌 해결할꼬??




uva 문제36 1의 개수(Ones)
2나 5로 나눌 수 없는 0이상 10000이하의 정수 n이 주어졌는데, n의 배수 중에는 10진수로
표기 했을 때 모든 자리 숫자가 1인 것이 있다.
그러한 n의 배수 중에서 가장 작은 것은 몇 자리 수일까?
입력	출력
3		3	// 111
7		6	// 111111
9901	12	// 111111111111

그냥 1, 11, 111, 1111, 11111, ... 을 입력된 수로 나누면 답이 나오지요.
	// 그런데 그건 느린건감...? 안느리고 통과 될듯 함.

책 풀이
111...111 (x개의 1이 연속된 수) = sigma[i=0 ~ i=x-1]{ 10^i } 가 주어진 수 n의 배수가 되려면,
다음이 만족되어야 한다.
	sigma[i=0 ~ i=x-1]{ 10^i } = 0 (mod n) 즉, 1 + 10 + 100 + ... + 10^(x-1) = 0 (mod n)
따라서, 1 을 n으로 나눈 나머지, 10을 n으로 나눈 나머지, ..., 10^(x-1) 을 n으로 나눈
나머지를 모두 더해서 그 결과 0(mod n) 이 되는지 확인하면 된다.
이 코드는 x를 계속 증가시켜가면서 t(10^i 항)를 더해 나간다.
"물론 연산 결과에 계속 %n 연산을 하므로 아주 큰 값을 계산해야 하는
"문제를 고려하지 않아도 된다.
void main() {
	int n, x, t, sum;
	while (scanf("%d", &n) == 1) {
		sum = 0;
		x = 0;
		t = 1;
		do {
			sum = (sum + t) % n;
			x++;
			t = (t * 10) % n;	// 다음 더할 나머지를 구한다.
		} while (sum != 0);
		printf("%d\n", x);
	}
}

uva 문제37 곱하기 게임(A Multiplication Game)
	p = 1 부터 시작 하며 2이상 9이하의 수를 곱해 나간다.
	주어진 정수 n 이상인 p를 만드는 사람이 게임의 승자가 된다.

	두 사람은 모두 완벽하게 게임을 한다고 가정하자.
	n 은 1 < n < 4294967295

// 내소스.. uva 가 맛이 가서 북경대에서 테스트 통과 78ms 걸림
ll n;
map<ll, int> cache;
int play(ll p) {
	if (cache.count(p) > 0) return cache[p];
	if (p >= n) return cache[p] = -1;	// 현재 차례가 진거니까 -1 리턴

	for (int mul = 2; mul <= 9; ++mul) {
		ll tmp = play(p * mul);
		if (tmp == -1) return cache[p] = 1;
	}
	return cache[p] = -1;	// 이긴 경우가 없으니까 -1 리턴
}
int main() {
	while (cin >> n) {
		cache.clear();
		int judge = play(1);
		if (judge == 1)
			cout << "Stan wins.\n";
		else
			cout << "Ollie wins.\n";
	}
	return 0;
}

책의 답은 나처럼 쨉실한 코드가 아니네..
원론적인 방법이며 매우 빠른 거다.
"ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ... 책 구매하기 전에 내가 9년전에 짲던 코드다." 북경대...
int main(){
	unsigned long int c;
	long int winner=0;
	
	while(cin>>c){
		winner = 0;
		for(;;){
			if(c%9==0)	// 최종 사람은 9를 곱하는게 답이 될거고.
				c=c/9;
			else
				c=c/9+1;
			
			winner++;
			if(c==1)
				break;
			
			if(c%2==0)	// 최종 사람 전에 있던 인간은 2를 곱해서 개길거다.
				c=c/2;
			else
				c=c/2+1;
			
			winner++;
			if(c==1)
				break;
		}
		if(winner%2==0)
			cout<<"Ollie wins."<<endl;
		else
			cout<<"Stan wins."<<endl;

	}
	return 0;
}
// 오마이갓.. 내머리가 많이 죽었구나...


uva 문제38 다항식의 계수(Polynomial Coefficients)
	다항식을 전개했을 때의 특정 monomial의 계수를 구하라
2 2	//  승수 n, 항의 종류 2개
1 1 // monomial x1*x2 의 계수를 구하라	: 2임
2 12
1 0 0 0 0 0 0 0 0 0 1 0 // monomial x1*x11 의 계수를 구하라 : 2임


고등학교때 배운 이항정리를 기억해라
	(x1 + x2)^7 에서 (x1^4)*(x2^3) 의 계수는 얼마인가? // 7개의 상자에서 4개를 선택하는 경우의 수
	"7C4 * x1^(7-3) * x2^3 이므로 계수는 7C3 이 된다.

	(x1 + x2 + x3)^8 에서 (x1^2)(x2^3)(x3^3) 의 계수는 얼마인가?

	8개의 상자에서 2개를 선택하는 경우의 수
  * 6개의 상자에서 3개를 선택하는 경우의 수
  * 3개의 상자에서 3개를 선택하는 경우의 수
	
	8C2 * 6C3 * 3C3
	(8*7 / 2*1) * (6*5*4 / 3*2*1) * (3*2*1 / 3*2*1) = 8! / (2! * 3! * 3!) 이 답이된다.

코드는 너무 간단해서 생략요.




uva 문제39 스턴-브로콧 수체계(The Stern-Brocot Number System)
문제설명은 책을 보삼 그림이라 적기 힘듬...

내 생각
string sol;
void dfs(현재값, 왼쪽add값, 오른쪽add값) {
	if (현재값 == 목표값) return;
	if (현재값 < 목표값) {
		sol.push_back('L');
		dfs(현재값 + 왼쪽add값, 왼쪽add값, 현재값);
	} else {
		sol.push_back('R');
		dfs(현재값 + 오른쪽add값, 현재값, 오른쪽add값);
	}
}
"왼쪽 add값이랑 오른쪽 add값이 어떻게 변화하는지 깨달으면 쉬운 문제다."
http://www.programming-challenges.com/pg.php?page=showproblem&probid=110507
// 제출한 코드 12ms 걸림
string sol;
int trgA, trgB;
void dfs(int a, int b, int leftAddA, int leftAddB, int rightAddA, int rightAddB) {
	if (a == trgA && b == trgB) 
		return;
	double cur = double(a) / b;
	double trg = double(trgA) / trgB;
	if (trg < cur) {
		sol.push_back('L');
		dfs(a + leftAddA, b + leftAddB, leftAddA, leftAddB, a, b);
	}
	else {
		sol.push_back('R');
		dfs(a + rightAddA, b + rightAddB, a, b, rightAddA, rightAddB);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	while (1) {
		sol.clear();
		cin >> trgA >> trgB;
		if (trgA == 1 && trgB == 1) break;
		dfs(1, 1, 0, 1, 1, 0);
		cout << sol << '\n';
	}
	return 0;
}


uva 문제40 모든 쌍의 합(Pairsummonious Numbers)
각 줄에는 n과 정수와 n(n-1)/2개의 정수가 입력된다.
(2 < n < 10) 
각 줄에 대해 두 개씩 더하면 입력된 수들을 만들어 낼수 있는 정수 n개를 오름차순으로 출력한다.
가능한 답이 여러 개 있으면 아무 답이나 출력해도 된다.
답이 없으면 "Impossible"이라고 출력한다.

3 1269 1160 1663
3 1 1 1
5 226 223 225 224 227 229 228 226 225 227
5 216 210 204 212 220 214 222 208 216 210
5 -1 0 -1 -2 1 0 -1 1 0 -1
5 79950 79936 79942 79962 79954 79972 79960 79968 79924 79932

output
383 777 886
Impossible
111 112 113 114 115
101 103 107 109 113
-1 -1 0 0 1
39953 39971 39979 39983 39989

// 타임오버난다. 이유는 간단하다. n 이 10인 경우
// 들어오는 숫자들은 10 * 9 / 2 , 즉 45개가 된다.
// 45! 의 횟수만듬 루프돈다 생각해봐라...ㅠㅠ
int main() {
	vi arr;
	int n;	// 2 < n < 10
	while (cin >> n) {
		arr.clear();
		int nn = (n * (n - 1) / 2);
		arr.resize(nn);
		rep(i, nn) cin >> arr[i];

		// (f, g) + (f, h) - (g, h) = 2f	// f, g, h 의 값을 구함
		// (e, f) + (e, g) + (e, h) - (f, g, h) = 3e	// 3을 나눠 e를 구함
		// (d, e) + (d, f) + (d, g) + (d, h) - (e, f, g, h) = 4d
		// (c, d) ... (c, h) - (d, e, f, g, h) = 5c
		// (b, c) ... (b, h) - (c, d, e, f, g, h) = 6b
		// (a, b) ... (a, h) - (b, c, d, e, f, g, h) = 7a
		vi solArr;
		bool sol = false;
		sort(arr.begin(), arr.end());
		do {
			solArr.clear();
			int cnt = 0;
			int f = arr[0] + arr[1] - arr[2];
			if (f % 2 == 1) continue;
			f = f / 2;	solArr.push_back(f);
			int g = arr[0] + arr[2] - arr[1];
			if (g % 2 == 1) continue;
			g = g / 2;	solArr.push_back(g);
			int h = arr[1] + arr[2] - arr[0];
			if (h % 2 == 1) continue;
			h = h / 2;	solArr.push_back(h);
			
			int sum = f + g + h;
			int acc = 1;	cnt += acc;
			acc++;			cnt += acc;
			bool ok = true;
			while (1) {
				if (cnt == nn) break;
				acc++;
				int tmp = 0;
				for (int i = cnt; i < cnt + acc; ++i) {
					tmp += arr[i];
				}
				tmp -= sum;
				if (tmp % acc != 0) {
					ok = false;
					break;
				}
				tmp /= acc;
				solArr.push_back(tmp);
				sum += tmp;
				cnt += acc;
			}
			if (ok == false) continue;	// 나눠 떨어지지 않는 숫자이면
			else {
				sol = true;
				break;
			}
		} while (next_permutation(arr.begin(), arr.end()));
		if (sol == true) {
			rep(i, solArr.size())
				cout << solArr[i] << " ";
			cout << '\n';
		}
		else
			cout << "Impossible\n";
	}
	return 0;
}

책풀이
n 이 6인 경우
s[0..(6*5/2)-1]	// 입력된 값들을 정렬한 것
a[0..5]	// 실제 답
							
a[0]+a[1]	a[0]+a[2]	a[0]+a[3]	a[0]+a[4]	a[0]+a[5]
			a[1]+a[2]	a[1]+a[3]	a[1]+a[4]	a[1]+a[5]
						a[2]+a[3]	a[2]+a[4]	a[2]+a[5]
									a[3]+a[4]	a[3]+a[5]
												a[4]+a[5]

a[0]+a[1] = s[0]
a[0]+a[2] = s[1]
// 그렇다면 a[1]+a[2] 는 어디에 있는가??
s[2] ~ s[5] 중 하나가 된다. (6 - 2)개중 하나이며 이것은 빨간 부분이된다.
a[0]+a[1]	a[0]+a[2]	"a[0]+a[3]	a[0]+a[4]	a[0]+a[5]"
			"a[1]+a[2]"	a[1]+a[3]	a[1]+a[4]	a[1]+a[5]
						a[2]+a[3]	a[2]+a[4]	a[2]+a[5]
									a[3]+a[4]	a[3]+a[5]
												a[4]+a[5]

편의상 "s[4] 가 a[1]+a[2]" 라 가정할 때
	s[0]+s[1]+s[2]는 반드시 짝수가 되어야 한다.
	t = (s[0] + s[1] + s[2]) / 2 = (2a[0]+2a[1]+2a[2])/2 = a[0]+a[1]+a[2]
	a[0] = t - s[2];
	a[1] = t - s[1];
	a[2] = t - s[0];

// a[0], a[1], a[2]를 알고 있고 s[0], s[1], s[4] 를 제거 한 뒤 (s[4] 를 a[1]+a[2]라 가정)
'-'			'-'			a[0]+a[3]	a[0]+a[4]	a[0]+a[5]
			'-'			a[1]+a[3]	a[1]+a[4]	a[1]+a[5]
						a[2]+a[3]	a[2]+a[4]	a[2]+a[5]
									a[3]+a[4]	a[3]+a[5]
												a[4]+a[5]

남은 s에서 가장 작은 값은 a[0]+a[3] 이 된다. 
a[0]은 알고 있으니 "a[3] 을 구할 수 있다." s에서 제거
그런 다음 s에서 a[1]+a[3]와 같은 값은 제거한다.	
		// 이때 s[4~6] 에 들어 있나 체크할 필요는 없다. 
		// 범위 4~6 넘어간 놈이 삭제시 끝까지 완료가 안되기 때문이다.
		  s에서 a[2]+a[3]과 같은 값은 제거한다.

'-'			'-'			'-'			a[0]+a[4]	a[0]+a[5]
			'-'			'-'			a[1]+a[4]	a[1]+a[5]
						'-'			a[2]+a[4]	a[2]+a[5]
									a[3]+a[4]	a[3]+a[5]
												a[4]+a[5]

반복하면 된다.
복잡도는 n * n^2 이 된다. n이 10이니 매우 빠르겠군.
const int mx = 10;
int getPairCnt(int n) { return n * (n - 1) / 2; }
int sum[45];
int checked[45];
int ans[10];
int n, num_pairs;
int solve() {
	rep2(i, 3, num_pairs) checked[i] = 0;
	int t = sum[0] + sum[1] + sum[2];
	if (t % 2 == 1) return 0;	// (2a[0] + 2a[1] + 2a[2])!!!!
	t /= 2;	// a[0] + a[1] + a[2]
	rep(i, 3) {
		ans[i] = t - sum[2 - i];
		checked[i] = 1;
	}
	rep2(i, 3, n) {
		// check되지 않은 가장 작은 값이 a[0] + a[i] 이다 !!!!
		t = 0;
		while (checked[t]) t++;
		ans[i] = sum[t] - ans[0];
		// ans[i] + ans[j] (0 <= j < i) 값들을 check 한다.
		rep(j, i) {
			while (t < num_pairs
				&& (checked[t] || sum[t] != ans[i] + ans[j]))
				t++;
			if (t == num_pairs)	// 원하는 unchecked sum 이 없으면 답이 존재하지 않음.
				return 0;
			checked[t] = 1;
		}
	}
	return 1;
}
int main() {
	while (scanf("%d", &n) == 1) {
		num_pairs = getPairCnt(n);
		rep(i, num_pairs) scanf("%d", &(sum[i]));
		sort(sum, sum + num_pairs);
		// sum[2], sum[3], ..., sum[n - 1] 을 a[1] + a[2] 로 가정
		bool ok = false;
		for (int i = 2; !ok && i < n; ++i) {
			swap(sum[2], sum[i]);
			ok = solve();
		}
		if (ok == false) printf("Impossible\n");
		else {
			rep(i, n) {
				printf("%d", ans[i]);
				if (i != n - 1)
					putchar(' ');
			}
			printf("\n");
		}
	}
	return 0;
}



http://suhak.tistory.com/77		// 카탈란 수
1. 잘 짜인 괄호
	n 쌍의 ()를 잘 짜인 모양으로 늘어 놓는 방법은 모두 몇 가지가 있을까?
	n = 0	*		1 way
	n = 1	()		1 way
	n = 2	()(),	(())	2 way
	n = 3	()()(),	()(()),	(())(),	(()()),	((()))		5 way
	n = 4	()()()(),	...,	(((())))				14 way

Cn = sigma[k=0][n-1]{ Ck*C(n-1-k) } = (1 / n+1)*2nCn
C1 = C0*C0 = 1;
C2 = sigma[k=0][1]{	Ck*C(1-k) } = C0*C1 + C1*C0 = 1+1 = 2
C3 = sigma[k=0][2]{ Ck*C(2-k) } = C0*C2 + C1*C1 + C2*C0 = 2 + 1 + 2 = 5
C4 = sigma[k=0][3]{ Ck*C(3-k) } = C0*C3 + C1*C2 + C2*C1 + C3*C0 = 5+2+2+5 = 14


점화식 유도과정
	(-------)======= 의 경우 
	// ------ 부분도 잘 짜인 괄호
	// ====== 부분도 잘 짜인 괄호임
	()==============
+	(--)============
+	(----)==========
+	(------)========
+	(--------)======
+	(----------)====
+	(------------)==
+	(--------------)





책풀이 문제 51 유클리드 문제(Euclid Problem)

임의의 자연수 A, B에 대해 A와 B의 최대공약수를 D라고 할 때
Ax + By = D 를 만족하는 정수 x, y 가 존재한다.
A, B가 주어졌을 때 위식을 만족시키는 x, y와 최대공약수를 구하라
답은 |x| + |y| 가 최소가 되어야 한다.
만약 최소가 되는 것이 2개 이상이 있다면
	x <= y 가 되는 것을 출력한다.
"확장유클리드 알고리즘으로 일차합동을 풀면 초기해 x0, y0 는 
절대치의 합이 최소치가 된다. 답 소스는 약간 인근의 값도 비교한거 같다만...
절대값의 합이 중복이 되는 경우 x <= y 조건을 만족하는 답을 선택하자
	"이것도 인근에 무조건 있게 된다."

/*
ll a, b, x, y, d;
ll r[100], k[100], xy[100][2];
int check;

void solve() {
	ll i;
	ll x0, y0, dx, dy;
	// 확장 유클리드 알고리즘을 이용해서 최대공약수와 x, y 를 구한다.
	if (a < b) {
		r[0] = b;
		r[1] = a;
	}
	else {
		r[0] = a;
		r[1] = b;
	}
	xy[0][0] = 1;
	xy[0][1] = 0;
	xy[1][0] = 0;
	xy[1][1] = 1;
	for (i = 0; r[i + 1] != 0; ++i) {
		k[i] = r[i] / r[i + 1];
		r[i + 2] = r[i] % r[i + 1];

		xy[i + 2][0] = xy[i][0] - k[i] * xy[i + 1][0];
		xy[i + 2][1] = xy[i][1] - k[i] * xy[i + 1][1];
	}
	d = r[i];
	if (a < b) {
		x = x0 = xy[i][1];
		y = y0 = xy[i][0];
	}
	else {
		x = x0 = xy[i][0];
		y = y0 = xy[i][1];
	}
	dx = b / d;
	dy = -a / d;
	if ((abs(x) - abs(x0 + dx)) + (abs(y) - abs(y0 + dy)) > 0 ||
		(abs(x) + abs(y) == abs(x0 + dx) + abs(y0 + dy) && x0 + dx <= y0 + dy)) {
		x = x0 + dx;
		y = y0 + dy;
	}
	else if ((abs(x) - abs(x0 - dx)) + (abs(y) - abs(y0 - dy)) > 0 ||
		(abs(x) + abs(y) == abs(x0 - dx) + abs(y0 - dy) && x0 - dx <= y0 - dy)) {
		x = x0 - dx;
		y = y0 - dy;
	}
}

*/
// 확장 유클리드
ll gcd(ll a, ll b, ll& x, ll& y) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	ll xx, yy, g = gcd(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}
void solve2(ll a, ll b) {
	ll x, y;
	ll g = gcd(a, b, x, y);
	ll dx = b / g;
	ll dy = -a / g;

	if ((abs(x) + abs(y)) > (abs(x + dx) + abs(y + dy))
		|| (abs(x) + abs(y) == abs(x + dx) + abs(y + dy) && (x + dx <= y + dy))) {
		x = x + dx; y = y + dy;
	}
	else if ((abs(x) + abs(y)) > (abs(x - dx) + abs(y - dy))
		|| (abs(x) + abs(y) == abs(x - dx) + abs(y - dy) && (x - dx <= y - dy))) {
		x = x - dx; y = y - dy;
	}
	cout << x << " " << y << " " << g << '\n';
}

int main() {
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	ll a, b;
	//while (scanf("%I64d %I64d", &a, &b) != EOF) {
	while (cin >> a >> b) {
		solve2(a, b);
		//printf("%I64d %I64d %I64d\n", x, y, d);
		//cout << x << " " << y << " " << d << '\n';
	}
	return 0;
}


문제 52 팩토리얼 나누기(Factovisors)
n! 이 m 으로 나누어 떨어지는가 판단하라
	"n과 m은 모두 2^31 보다 작다... 흐미"	// 음이 아닌 정수이며 숫자가 매우 크다.
											// m 이 0이 올수도 있다는 ...
											// m 이 0이 오면 무조건 out

m을 소인수분해해서
	각 소수들의 차수가 n! 를 소인수분해한 것의 차수보다 같거나 작아야 한다.

	공식이 있어욤!!!!
"소수 p가 n! 에서 몇 승까지 존재하는 지는 floor(n/p) + floor(n/p^2) + floor(n/p^3) ...
ex)
	8! 에는 2의 승수가 몇개나 될까요?
	8/2 + 8/4 + 8/8 = 4 + 2 + 1 = 7개

	1	2	3	4	5	6	7	8
		2		2*2		2		2*2*2 => 총 7개가 존재한다.

// 우리가 필요로 하는 소수들은 어디까지 일까?
p^2 이 int 범위를 넘기면 필요없어요.
	60000까지 알아봅시다.

map<int, int> my;
//주어진 정수 n을 소인수분해하는 간단한 알고리즘
// 빨리 돌아가는건 메모리 용량이 커서 GG
void factorSimple(int n) {
	my.clear();
	int sqrtn = int(sqrt(n));	// 60000이하의 소수의 개수들을 저장하겠네
	for (int div = 2; div <= sqrtn; ++div)
		while (n % div == 0) {
			n /= div;
			my[div]++;
		}
	if (n > 1) 
		my[n]++;
}
bool solve(ll n, ll m) {
	if (m == 0) return false;	// 무조건 안된다
	if (m == 1 || n >= m) return true;	// 무조건 된다.
	factorSimple(m);
	map<int, int>::iterator it = my.begin();
	for (; it != my.end(); ++it) {
		int key = it->first;
		int value = it->second;	// m을 소인수분해시 key 의 차수
		int cnt = 0;	// n 에 해당 소수의 차수를 구한다.
		for (int i = key; cnt < value; i *= key) {
			if (n < i)	// 이 뒤론 나눠봐야 의미가 없으니
				break;
			cnt += n / i;
		}
		if (cnt < value) return false;
	}
	return true;
}
int main() {
	ll n, m;
	while (cin >> n >> m) {
		bool ok = solve(n, m);
		if (ok)
			cout << m << " divides " << n << "!\n";
		else
			cout << m << " does not divide " << n << "!\n";
	}
	return 0;
}

"고찰:"
	n 이 1000 , m 이 1000보다 큰 소수인 경우 ok 가 절대 될수 없다.!!!!



문제 53 유리구슬 : 책에선 노가다로 풀던데 난 머리좋게 하려고 확장 유클리드 썼음
	//그런데 wong answer 이 뜨네.. 어떤 예시인지 알수가 없어서 죽겠다..
// 각 입력에 들어오는 수는 1 이상 2000000000이하임 // 20억..
43	//n
1 3	//c1 n1	
2 4	//c2 n2
output
13 1	// 3칸짜리 상자 13개랑 4칸짜리 상자 1개로 43을 만족 시킨다.



// 확장 유클리드
ll gcd(ll a, ll b, ll& x, ll& y) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	ll xx, yy, g = gcd(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	ll n; 
	while (true) {
		cin >> n;
		if (n == 0) break;
		ll c1, n1, m1, c2, n2, m2;
		cin >> c1 >> n1 >> c2 >> n2;
		bool isChange = false;
		if (double(c1) / n1 >= double(c2) / n2) {
			isChange = true;
			swap(c1, c2);
			swap(n1, n2);
		}
		ll x0, y0;
		ll g = gcd(n1, n2, x0, y0);
		if (n % g != 0) {
			cout << "failed\n";
			continue;
		}
		ll mul = n / g;
		x0 *= mul; y0 *= mul;
		ll dx, dy;
		// 특수해를 가지고 일반해 중 가장 효율이 좋은걸 찾자
		// 앞쪽이 효율이 높으니 뒤쪽의 계수 y가 0이상인 것 중 가장 작은걸 찾으면 된다.
		if (y0 < 0) {
			dx = -n2 / g, dy = n1 / g;
			//m2 = y0 + (-y0 + dy) / dy * dy;	// 여기서 망했네요. 원인은 아직 모르겠음.
			m2 = (y0 + 2000000001 * dy) % dy;
			m1 = (n - (m2 * n2)) / n1;
		}
		else {
			dx = n2 / g, dy = -n1 / g;
			m2 = y0 % dy;
			m1 = (n - (m2 * n2)) / n1;
		}
		if (m1 < 0 || m2 < 0) {
			cout << "failed\n";
			continue;
		}
		if (isChange)
			swap(m1, m2);
		cout << m1 << " " << m2 << '\n';
	}
	return 0;
}
/*
	효율이 앞쪽이 높다고 가정하에
	일차잉여방정식을 아래와 같이 만들면
	7x + 6y = 1
	dx = 6, dy = -7 // 혹은 dx = -6, dy = 7
	x = 1, y = -1 이 된다.

	만약 n이 20이라면
	x = 20, y = -20 이 된다 // dx, dy 는 그대로다.
	뒤쪽이 효율이 않좋기에 음이 아닌 최소의 정수를 만들면 된다.
	7*20 + 6*-20 = 20
	7*14 + 6*-13 = 20
	7*8  + 6*-6  = 20
	7*2  + 6*1   = 20

	물론 y를 음이아닌 정수로 두는 경우
	x 가 음이 되버리는 상황이 있으니 그 점도 잘 처리해야함
	7x + 6y = 1 // n이 1이라 할때
	빼도박도 못하고 한쪽은 음수가 되어야 함...
*/


// 범위 안에 포함 되는 류의 문제에 활용이 가능할 거 같은 유용한 문제다. !!!!
http://codeforces.com/contest/816/problem/B
B. Karen and Coffee

3 2 4	// 레시피 갯수:커피가 만들어질 허용온도, 쾌적한 기온의 기준, 질의
91 94	// 91~94 에서 좋은 커피가 만들어지는 레시피
92 97	// 92~97 ""
97 99	// 97~99 ""
92 94		// 92도, 93도, 94도 중 각각 2개 이상의 레시피를 만족시키는 온도는 몇개인가? // 3개
93 97		// 3개 : 93도, 94도, 97도
95 96		// 0개
90 100		// 4개
레시피가 20만개나 된다.
질문도 20만개나 된다.
온도 범위도 (1 <= li <= ri <= 200000) 로 매우 크다.

내 해결법: 레이지 프로퍼게이션으로 풀었다.
레시피에 만족되는 범위는 1씩 다 더해주고

psum 으로 1도부터 20만도까지 k를 만족시키는 경우 1씩 누적 시켜 더했다.

즉 질의 93 97 이 오면
	psum[97] - psum[93-1] 이 답이된다.

http://codeforces.com/contest/816/submission/27858779
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init(1, 1, 200200);
	int n, k, q;
	cin >> n >> k >> q;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		update_range(1, 1, 200200, a, b, 1);	// 범위 구간(a, b) 를 1씩 증가시킨다.
	}
	vi psum(200001);
	rep2(i, 1, 200001) {
		int t = sum(1, 1, 200200, i, i);
		// i도에서 k개 이상의 레시피를 만족하는가를 누적합으로 기록한다.
		psum[i] = psum[i - 1] + ((t >= k) ? 1 : 0);	
	}
	rep(i, q) {
		int a, b;
		cin >> a >> b;
		cout << psum[b] - psum[a -1]<< '\n';
	}
	return 0;
}
// 복잡도
// 트리만드는데 걸리는 시간 O(nlogm) // n 횟수, m: 커피온도 범위 1 ~ 최대값
// 트리로부터 추출하는데 걸리는 시간 O(qlogm)
lazy pro~~ 을 그냥 복붙해서 통과는 시켰다만.. 이해는.. 까먹었다.
도저히 div2 2번 문제라 보기에 힘들 정도의 난이도다.
// 다르게 푸는 방법을 찾아보자.

누적합을 응용한다.
	arr1: { 4, 10 }
	arr2: { 7, 14 }

c[4] = 1;
c[11] = -1;
c[7] = 1;
c[15] = -1;

idx		1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17
c		0	0	0	1	0	0	1	0	0	0	-1	0	0	0	-1	0	0
psum	0	0	0	1	1	1	2	2	2	2	1	1	1	1	0	0	0

10도일시 만족하는 건 2개
11도일시 만족하는 건 1개

"응용력이 매우 높은 원리다 !!!!"


http://codeforces.com/contest/821/problem/C
7
add 3
add 2
add 1
remove	
add 4	// 최상단이 제일 작지 않다: sorted = fasle
remove	// 여기서 재정렬 시킨다.	sorted = true
remove
remove
add 6
add 7	// 최상단이 6이어야 하는데 7이 되므로 sorted = false;
add 5	// 
remove	// 여기서 재정렬 시킨다. sorted = true
remove
remove

output : 2


스택에 add도 쌓고 remove로 제거를 한다.
이때 제거되는 박스는 1, 2, 3, ..., n 순서대로 가야 한다.
그렇지 않은 경우 스택의 내용물의 순서를 재정렬한다.

재정렬의 횟수가 가장 적게 하는 경우
그 횟수값을 출력하라.

// 스택의 top보다 하나 작은게 들어온다 : 정렬 유지
// 그렇지 않으면 : 정렬 깨짐
// priority_queue 를 이용할 수 있겠다.
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	priority_queue<int, vi, greater<int>> pq;
	int sol = 0;
	int n; cin >> n;
	string op;
	int x;
	bool sorted = true;
	rep(i, 2 * n) {
		cin >> op;
		if (op == "add") {
			cin >> x;
			if (pq.empty() == false) {
				if (pq.top() - 1 != x)
					sorted = false;
			}
			pq.push(x);
		}
		else {
			if (sorted == false) {
				sol++;
				sorted = true;
			}
			pq.pop();
		}

	}
	cout << sol;
	return 0;
}
// 헌데 틀렸다고 한다. 어째서냐???

// 정답코드
// remove 횟수를 맞출 필요가 없다.

int main()
{
    int n;
    cin >> n;
    stack<int> st;
    int curr=1;
    int ans = 0;
    REP(i,2*n){
        string str;
        cin >> str;
        assert(str[0]=='a' || str[0]=='r');
        if(str[0]=='a'){
            int x;
            cin >> x;
            st.push(x);
        }else if(str[0]=='r'){
            if(!st.empty()){
                if(st.top()==curr){ //last thing added is what we need to remove
                    st.pop();
                }else{ //last thing we added is NOT what we need to remove
                    ans++;
                    while(!st.empty()) st.pop(); //clears the stack
                }
            }
            curr++;
        }
    }
    cout << ans << endl;
}


http://codeforces.com/contest/820/problem/B
B. Mister B and Angle in Polygon

	정다각형에서 각 꼭지점을 이을시 목표한 각도랑 가장 유사한 각도를 만드는 3개의 점을 구하라
	(당연히 중복이 되면 안됨)
정다각형에서 모든 생성각들은 특정각의 배수임.
=> 만들수 있는 각도 또한 n-2 개가 된다.
int main() {
	double n, a;
	cin >> n >> a;
	double tA = 180 * (n - 2);
	double aA = tA / n;	// 하나의 각도
	double base = aA / (n - 2);
	int tmp = (a / base) + 0.5;
	int sol = 2;
	if (tmp == 0)	// 0이면 점이 중복
		sol += 1;
	else
		sol += tmp;
	if (sol > n)	// n 보다 크면 사실 1을 가르키므로 중복
		sol = n;
	cout << 2 << " " <<1 << " " << sol;
	return 0;
}



// 좋은 문제다. 좋은문제
http://codeforces.com/contest/796/problem/C
C. Bank Hacking

정점이 n 개, 간선이 n-1 개 주어진 트리상에서 // n은 최대 30만...
각 정점은 에너지를 가지고 있음.
각 정점을 깨려면 에너지 이상의 전투력이 필요함
그런데 한 정점을 깨는 순간
인근에 있는 정점들의 에너지가 올라감, 범위가 인근, 인근인근 까지임
(정점을 깨는 순간이며 한번 깨진 정점에 의해 길이 없어진 다음 부터는 인근인근은 통용안됨)

	// 1 -- 2 -- 3 -- 4 -- 5	// 3이 깨지면
	// 2 -- 3 -- x -- 5 -- 6	이 된다.
	여기서 5를 깬다한들
	// 2 --'3'-- x -- x -- 7	//  '3'은 그대로이다.

	내 유추:
		5 5 5 5 5	인접한 mx 수가 4 이상이면 답은 5 + 2 가 된다.
		5 5 5		인접한 mx 수가 2 이상 3 이하이면 답은 5 + 1 이 된다.
		5			인접한 mx 수가 1 개이면 답은 5가 된다.
//p694 트리에서 가장 긴 경로를 찾는 재귀 호출 알고리즘 을 활용하면 되겠다. 생각했다.
	"인근인근까지라는게 문제였다 !!!!"
	반례
		4 4 5 4 4	// 여기서 mx 인 에너지 5를 제거하면
		5 5 x 5 5	// 오잉 ?? ㅠㅠ


"문제 조건중 빠진거: 처음 해킹한 다음 그 인근을 해킹해야 하는 원칙이 있다." 이걸 몰라서 힘들었어용.!!!!
http://par.hateblo.jp/entry/2017/04/11/122417 // 여기 삽입된 그림만 보면 아래 코드가 이해 될거다.
정답소스
http://ideone.com/B9pjyi	// 문제저자소스

int a[300005];
vi way[300005];
int main() {
	int n; cin >> n;
	int maxval = -1e9;
	for (int i = 1; i <= n; ++i) cin >> a[i], maxval = max(maxval, a[i]);
	rep(i,n-1) {
		int u, v; cin >> u >> v;
		way[u].pb(v);
		way[v].pb(u);
	}
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == maxval) x++;	// 최고값의 갯수 (두번 밑의 자식인 경우 +2를 취해 준게 되지용)
		else if (a[i] == maxval - 1) y++;	// 그보다 1 작은 갯수(두번 밑의 자식인 경우 +2 해준게 되지)
	}

	int res = maxval + 2;
	for (int i = 1; i <= n; ++i) {
		// minus
	
		// 루트에 있는 것은 그대로 함.
		if (a[i] == maxval) x--;	
		else if (a[i] == maxval - 1) y--;
		
		// 1 차 자식의 경우 +1 을 취해준 것이 되기 때문에
		// 최대값인 경우 실제론 +1 한 값의 파워가 필요하므로 x를 하나 지우고 y를 하나 늘린다.
		for (int j = 0; j < way[i].size(); ++j) {
			int pos = way[i][j];	// 인근 은행을 해킹한다.
			if (a[pos] == maxval) x--, y++;
			else if (a[pos] == maxval - 1) y--;		// 해킹시도시 최대값을 넘지 못하고 사라짐
		}

		// 최고값이 남아 있다면 +2 되는 부분이기에 답은 max+2 고대로 일거고
		// 최고값이 없다면 최고값보다 하나 작은 값이 남았다면 max+1 일거고
		// 그것도 아니면 max 겠지요.
		if (x == 0) {
			res = min(res, maxval+1);
			if (y == 0) res = min(res, maxval);
		}

		// plus	: 원복시키기
		if (a[i] == maxval) x++;
		else if (a[i] == maxval - 1) y++;
		for (int j = 0; j < way[i].size(); ++j) {
			int pos = way[i][j];
			if (a[pos] == maxval) x++, y--;
			else if (a[pos] == maxval - 1) y++;
		}
	}
	cout << res;
}

// root 에서 2차 이상 자식의 경우 mx는 mx + 2 를 가지게 된다.
// mx - 1 은 mx + 1 이 된다.
vi graph[300300];
int main() {
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vi arr(n);
	int mx = -INF;
	rep(i, n) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	rep(i, n - 1) {
		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].pb(v);	graph[v].pb(u);
	}
	int x = 0, y = 0;
	rep(i, n) {
		// mx 로 비교했지만 사실 mx+2, mx+1 의 개수를 세팅한다.
		if (arr[i] == mx) x++;	// 2차 서브트리 노드라 가정하고 mx+2 의 개수를 저장 
		else if (arr[i] == mx - 1) y++;	// 2차 서브트리 노드라 가정하고 mx+1 의 개수를 저장
	}
	int sol = mx + 2;
	rep(i, n) {
		// root 인 경우 증가를 할 필요 없으니 그냥 비교해서 x, y 적용
		if (arr[i] == mx) x--;
		else if (arr[i] == mx - 1) y--;

		// 1차 subtree 인 경우 증가를 한번 해야 함
		rep(j, graph[i].size()) {
			int there = graph[i][j];
			int value = arr[there] + 1;	// 한번의 증가
			if (value == mx + 1) {	// 앞에서 mx+2 갯수를 증가시킨 노드이므로
				x--;	// mx+2 갯수를 감소시킨다.
				y++;	// mx+1의 개수를 증가시킨다.
			}
			else if (value == mx)
				y--; // 앞에서 mx-1 로서 y를 증가시킨 요소였죠. 처리되었으니 삭제요	
		}
		// 2차 이상의 subtree의 남은것들을 비교한다.
		if (x == 0) {
			if (y == 0) 
				sol = min(sol, mx);
			else sol = min(sol, mx + 1);
		}
		else sol = min(sol, mx + 2);

		// 원복
		if (arr[i] == mx) x++;
		else if (arr[i] == mx - 1) y++;

		rep(j, graph[i].size()) {
			int there = graph[i][j];
			int value = arr[there] + 1;	
			if (value == mx + 1) {	
				x++;	
				y--;	
			}
			else if (value == mx)
				y++; 		}
	}
	cout << sol;
	return 0;
}
/*
5 - 5 - 5 - 5 - 5 - 5
7 - 7 - 7 - 7 - 7 - 7	// 7의 개수 7개로 취급
* - 7 - 7 - 7 - 7 - 7	// 첫노드 루트 처리시 원본으로 취급해서 뺀다, 7의 개수 6개
* - 6 - 7 - 7 - 7 - 7	// 1차 자식 노드는 원본+1 로 취급해서, 6의 개수 1개, 7의 개수 5개
* - 6 - 7 - 7 - 7 - 7	// y 즉 6의 갯수가 하나라도 있으면 답은 mx + 1 or mx + 2 이다.
// x 즉 7의 갯수가 하나라도 있으면 답은 mx + 2 가 된다.
*/




	


// 좋은 문제다. 좋은문제
// 요약하자면
// 두개의 기간의 합이 x가 되게 하는 경우 최소 비용을 구하라.
http://codeforces.com/contest/822/problem/C
C. Hacker, pack your bags!

연차 x일을 받았다.
두개의 여행을 가되 두 여행일수는 딱 x연차가 되도록 한다.
여행 일정은 겹치면 안된다. 
4 5
1 3 4
1 2 5
5 6 1
1 2 4

output 
5	// 1~3: 4, 5~6: 1

//20만개의 여행일정이 있다. 받은 연차는 총 x(최대 20만)일이다
나의 생각
map[기간] 
= vector{ 휴가시작일, 현비용, 동일 기간 휴가중 뒤에 시작하는 것들까지 포함해서 최소비용}

하나의 휴가에 대해 (L: 15, R: 24, Cost: 30)
x: 34인 경우
기간: 24-15 + 1 = 10
map[34 - 10] 인 값이 존재해야 한다.
그리고 25일부터 뒤로 기간이 24일인 휴가중 비용이 가장 적은 것을 찾아낸다. 
	// 기간중 최소비용은 미리 구해놓자.


time complixity = 
30만 * log30만	// 맵에 데이터 접근 복잡도
* 30만 * log30만 // 맵의 데이터에 대한 정렬

흐미 하고 무식하다 하며 짰다.

	// 무식한 방법으로 짰다.
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	map<int, vector<pair<int, pair<int, int>>>> my;
	int n, x; cin >> n >> x;
	int l, r, c;
	vector<pair<int, pair<int, int>>> arr(n);
	rep(i, n) {
		cin >> l >> r >> c;
		my[r - l + 1].push_back(mp(l, mp(c, INF)));
		arr[i].first = l;
		arr[i].second.first = r;
		arr[i].second.second = c;
	}
	sort(arr.begin(), arr.end());
	map<int, vector<pair<int, pair<int, int>>>>::iterator it = my.begin();
	for (; it != my.end(); ++it) {
		sort(it->second.begin(), it->second.end());
		vector<pair<int, pair<int, int>>>::reverse_iterator rt = it->second.rbegin();
		if (rt == it->second.rend()) break;
		rt->second.second = rt->second.first;
		int prev = rt->second.second;
		++rt;
		for (; rt != it->second.rend(); ++rt) {
			rt->second.second = min(rt->second.first, prev);
			prev = min(rt->second.first, prev);
		}
	}
	int sol = INF;
	rep(i, arr.size()) {
		l = arr[i].first; r = arr[i].second.first; c = arr[i].second.second;
		int du = r - l + 1;
		int rdu = x - du;
		if (my.count(rdu) == 0) continue;
		int idx = upper_bound(my[rdu].begin(), my[rdu].end(), mp(r, mp(0, 0))) - my[rdu].begin();
		if (idx == my[rdu].size()) continue;
		//vector<pair<int, pii>>  test = my[rdu];
		int cand = c + my[rdu][idx].second.second;
		sol = min(cand, sol);
	}
	if (sol == INF)
		cout << -1;
	else
		cout << sol;
	return 0;
}


오류 원인 찾았다. // 무식한거 같은데 640ms 로 통과는 하네...
const int INF = 2147483647;	// 문제에서 숫자 범위확인이 중요하다 !!!! // 나의 실수한 부분이다 ㅠㅠ
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	map<int, vector<pair<int, pair<int, int>>>> my;
	int n, x; cin >> n >> x;
	int l, r, c;
	vector<pair<int, pair<int, int>>> arr(n);
	rep(i, n) {
		cin >> l >> r >> c;
		my[r - l + 1].push_back(mp(l, mp(c, INF)));
		arr[i].first = l;
		arr[i].second.first = r;
		arr[i].second.second = c;
	}
	//sort(arr.begin(), arr.end());
	map<int, vector<pair<int, pair<int, int>>>>::iterator it = my.begin();
	// 아래 for문은 대략 NlogN
	for (; it != my.end(); ++it) {
		sort(it->second.begin(), it->second.end());
		vector<pair<int, pair<int, int>>>::reverse_iterator rt = it->second.rbegin();
		if (rt == it->second.rend()) break;
		// rt는 동일일수의 휴가를 가진 key 에 대한 value 를 의미하며 각 요소는 다음과 같다.
		// rt->first : 휴가 시작 날짜를 의미한다. (Left)
		// rt->second.first : 비용을 의미한다.
		// rt->second.second : 동일 휴가일수를 가진 것들중 시작 날짜가 현보다 뒤에 있는 것까지 
		// 모두를 포함하여 가장 비용이 작은 값을 의미한다.
		rt->second.second = rt->second.first;
		int prev = rt->second.second;	// 가장 작은 비용 기록
		++rt;
		for (; rt != it->second.rend(); ++rt) {
			rt->second.second = min(rt->second.first, prev);
			prev = rt->second.second;
		}
	}
	int sol = INF;

	// 음.. 복잡도가 (N * logN) * (N * logN) 인데요...
	// 왼쪽과 오른쪽은 서로 상보적임. 왼쪽이 크면 오른쪽은 1에 가깝게 되고
	// 오른쪽이 크면 왼쪽이 1에 가깝게 된다.
	// 평균 N*logN 으로 보면 된다고 생각한다.
	"감각적으로 이해하자", "직관력이 필요했다"
	// 무식했는데 맞는 방법 같다..
	rep(i, arr.size()) {
		l = arr[i].first; r = arr[i].second.first; c = arr[i].second.second;
		int du = r - l + 1;		// 앞의 휴가 기간
		int rdu = x - du;		// 남은 휴가 기간
		if (my.count(rdu) == 0) continue;
		int idx = upper_bound(my[rdu].begin(), my[rdu].end(), mp(r, mp(INF, INF))) - my[rdu].begin();
		// {r, 0, 0} 인 경우 r 도 포함되어 버리기 때문에!!!! : 나의 실수한 부분이다. ㅠㅠ
		if (idx == my[rdu].size()) continue;
		int cand = c + my[rdu][idx].second.second;
		sol = min(cand, sol);
	}
	if (sol == INF)
		cout << -1;
	else
		cout << sol;
	return 0;
}


좀더 간략화.
const int INF = 2147483647;	// 문제에서 숫자 범위확인이 중요하다 !!!!
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	map<int, vpiii> my;
	int n, x; cin >> n >> x;
	int l, r, c;
	vi left(n), right(n), cost(n);
	rep(i, n) {
		cin >> l >> r >> c;
		my[r - l + 1].push_back(mp(l, mp(c, INF)));
		left[i] = l; right[i] = r; cost[i] = c;
	}
	map<int, vpiii>::iterator it = my.begin();
	for (; it != my.end(); ++it) {
		vpiii& sameD = it->second;
		sort(sameD.begin(), sameD.end());	// 같은 길이를 가진 휴가, 날짜별로 정렬
		vpiii::reverse_iterator rt = sameD.rbegin();
		if (rt == sameD.rend()) break;
		rt->second.second = rt->second.first;
		int prev = rt->second.second;	// 가장 작은 비용 기록
		++rt;
		for (; rt != sameD.rend(); ++rt) {
			rt->second.second = min(rt->second.first, prev);
			prev = rt->second.second;
		}
	}
	int sol = INF;
	rep(i, n) {
		l = left[i];	r = right[i];	c = cost[i];
		int du = r - l + 1;
		int rdu = x - du;
		if (my.count(rdu) == 0) continue;
		vpiii& sameD = my[rdu];	// 같은 길이를 가진 휴가들: 날짜별로 정렬되어 있다.
								// second.second 값은 현 포함 그 이후로 사용 가능한 
								// 휴가중 가장 비용이 싼 값을 저장
		//int idx = upper_bound(my[rdu].begin(), my[rdu].end(), mp(r, mp(INF, INF))) - my[rdu].begin();
		int idx = upper_bound(sameD.begin(), sameD.end(), mp(r, mp(INF, INF)))
				- sameD.begin();
		// {r, 0, 0} 인 경우 r 도 포함되어 버리기 때문에!!!! 나의 실수한 부분
		if (idx == my[rdu].size()) continue;
		int cand = c + my[rdu][idx].second.second;
		sol = min(cand, sol);
	}
	if (sol == INF)
		cout << -1;
	else
		cout << sol;
	return 0;
}


// 출제자의 풀이: 매우 좋다. 좋은문제.!!!!
const int maxn = 200500;	// 최대 휴가 길이
const int inf = (2e9) + 2;
vector<pair<pii, pii>> queries;
int l[maxn], r[maxn], cost[maxn];
int sol(int n, int needLen) {
	queries.clear();
	rep(i,n) {	// n: 휴가일수: 최대 30만개 있다.
		queries.pb(mp(mp(l[i], -1), mp(r[i], cost[i])));
		queries.pb(mp(mp(r[i], 1) , mp(l[i], cost[i])));
	}
	rep(i,maxn) bestCost[i] = inf;
	ll ans = 2LL * inf;
	sort(queries.begin(), queries.end());
	int sz = queries.size();
	rep(i,sz) {
		int type = queries[i].f.s;
		if (type == -1) {
			int curLen = queries[i].s.f - queries[i].f.f + 1;
			if (curLen <= needLen)
				ans = min(ans, 1LL * queries[i].s.s + 1LL * bestCost[needLen - curLen]);
		}
		if (type == 1) {
			int curLen = queries[i].f.f - queries[i].s.f + 1;
			bestCost[curLen] = min(bestCost[curLen], queries[i].s.s);
		}
	}
	return ans >= inf ? -1 : ans;
}

x가 7인 경우
3 6 5	// 3~6, 비용 5
7 9 4	// 7~9, 비용 4

queries[0] = { (3, -1), (6, 5) }	// (시작일, -1), (마지막일, 비용)
queries[1] = { (6, 1) , (3, 5) }	// (마지막일,1), (시작일, 비용)
queries[2] = { (7, -1), (9, 4) }
quereis[3] = { (9, 1) , (7, 4) }

정렬후

i == 1 일때
	bestCost[4] = 4
i == 2 일때
	ans = queries[2].s.s + bestCost[4] = 5 + 4 = 9
	// quereis[2].f.f 는 시작 날짜이며
	// 이보다 일찍 끝나는 여행들은 이미 다 처리 되어 있다. (정렬로 인해) // 핵심 !!!!



http://codeforces.com/contest/822/problem/D
D. My pretty girl Noora

	12명의 사람이 있다 토너먼트(다수도 가능)를 하되 가장 적은 수의 비교가 되려면 
	
12 을 가장 작은 약수인 2로 나눈다. 2 * 6

	2 2 2 2 2 2		각 그룹은 2*(2-1)/2 의 비교 즉 한번씩 비교경기를 한다.

6명이 올라올거다 그럼 거기서 가장 작은 약수인 2로 나눈다.

	2 2 2 2 2 2
	 2   2   2		마찬가지로 2*(2-1)/2의 비교

3명인 경우 소수이기에 더이상 나눌 수가 없다. 따라서 3*(3-1) / 2 의 비교를 한다.


// 숫자를 가장 작은 소수로 나누면 답이 되겠지 하고 생각 했다만 ...
// 저자의 풀이는 숫자를 구성하는 모든 소수를 체크하는 코드였다.
// 증명도 하기 쉬워서 였지.
const int maxn = 5000500;	오백만...
int isPrime[maxn];
ll dp[maxn];
int main() {
	int t, l, r;
	cin >> t >> l >> r;	// t^0*f(l) + t^1*f(l+1) + t^2*f(l+2) + ... + t^r*f(r)
	// l, r 은 500만 이하다.
	// t는 10억7 미만이다...
	// f(~) 를 빠르게 구하기만 하면 된다.
	
	"O(N*(loglogN)) !!!!" 시간복잡도
	rep2(i, 2, maxn) isPrime[i] = i;
	for (int i = 2; i*i < maxn; ++i)
		if (isPrime[i] == i)
			for (int j = i * i; j < maxn; j += i)
				isPrime[j] = min(i, isPrime[j]);
	dp[1] = 0;
	for (int i = 2; i < maxn; ++i) {
		dp[i] = 1LL * inf * inf;
		// i를 소인수분해한 수들을 가지고 전부 확인한다.
		// 나는 가장 작은 소수만 취하면 되는 줄 알았다. 그게 아닌가 보다.
		// 시간 복잡도는 에라토스테네스 체랑 동일하다.
		"O(N*(loglogN)) 이 된다." !!!! 기억하자.
		for (int x = i; x != 1; x /= isPrime[x])	
			dp[i] = min(dp[i],
					1LL * dp[i / isPrime[x]] + 1LL * i * (isPrime[x] - 1) / 2LL);
				//  dp[i/isPrime[x]] + (i/isPrime[x]) * isPrime[x] * (isPrime[x] - 1) / 2
		// dp[81] = dp[27] + 4 * 3 * (3 - 1) / 2
	}
	int ans = 0;
	int cnt = 1;
	for (int i = l; i <= r; ++i) {
		dp[i] %= MOD;
		ans = (1LL * ans + 1LL * cnt * dp[i]) % MOD;
		cnt = (1LL * cnt * t) % MOD;
	}
	cout << ans;
}

// 허나 가장 작은 소수 하나만 취해도 통과한다.
// 분기가 많을 수록 더욱 효율적이기 때문이다.
// 일반 토너먼트의 경기 룰이 2명씩 붙이는 이유를 생각해봐
const int maxn = 5000500;
int isPrime[maxn];
ll dp[maxn];

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	int t, l, r; cin >> t >> l >> r;
	rep2(i, 2, maxn) isPrime[i] = i;
	for (int i = 2; i*i < maxn; ++i)
		if (isPrime[i] == i)
			for (int j = i * i; j < maxn; j += i)
				isPrime[j] = min(i, isPrime[j]);
	dp[1] = 0;	// 한개인 경우 비교를 안한다.
	for (int i = 2; i < maxn; ++i) {
		// 최소 약수를 가지고 그룹을 나누면 
		// 분기가 더 많기에 효율적이다.
		dp[i] = dp[i / isPrime[i]] 
			  + (ll)(i / isPrime[i])	// 분기 갯수 
			  * isPrime[i] * (isPrime[i] - 1) / 2;	// 각 그룹당 비교횟수
	}
	int ans = 0;
	int cnt = 1;
	for (int i = l; i <= r; ++i) {
		dp[i] %= MOD;
		ans = ((ll)ans + (ll)cnt * dp[i]) % MOD;
		cnt = ((ll)cnt * t) % MOD;
	}
	cout << ans;
	return 0;
}



http://codeforces.com/contest/822/problem/E
E. Liar

9
hloyaygrt	// s문자열
6
loyyrt		// t문자열 // loy y rt 세개의 연속된 조각으로 표현 가능하다.
3
output : YES


9
hloyaygrt
6
loyyrt
2	// x: 2 개의 연속된 조각으로 표현 불가능
output : NO

n: 10^5, m: n이하
x: 1 <= x <= 30

s랑 t를 순차적으로 비교하며 존재의 여부는 확인 가능하다만. 
	조각개수의 한계로 인해 되돌아가는 부분이 발생
dbcatatt	: s
datt		: t

d bc at att	: d를 취하고 at를 취한 뒤 at를 다시 지우고 att를 취해야 된다.
// 여기서 시간이 걸리게 되는 구나.

풀이
	f(s, t) <= x 가 되어야 한다.
//DP(prefS, prefT) = f(s[1...prefS], t[1...prefT])
DP값이 x보다 큰 경우 무시하자
// 그렇지만 DP 상태수는 10만 * 10만 이므로 꽤 크다.
// 이걸 줄일수 있을까?

G(prefS, cnt) = prefT // cnt 는 이전 DP 값, prefT 는 최대한 매칭된 거

G의 상태수는 |s| * x 가 된다 // 10만 * 30
"G로 바꾸면 상태수가 줄어든다 transition 을 어떻게 하면 될까?"
2가지 고려사항
	G(prefS, cnt) = prefT -> G(prefS + 1, cnt) = prefT	// 고대로여
	G(prefS, cnt) = prefT -> G(prefS + lcp, cnt + 1) = prefT + lcp
		// lcp = LongestCommonPrefix(	s[prefS + 1...|s|],
		//								t[prefT + 1...|t|])
	lcp 는 suffix array 로 구할 수 있다. how ??
	// 빠르게 구하는 방법없나요??
	// 두 문자열의 접미사 쌍들에 대하여
	// 가장 긴 lcp 를 구하는데 걸리는 시간
	// 한 접미사 쌍에 대해 logN 만에 푸는 방법이 기술 되어 있다.
	// 그 부분이 이해가 안되서 GG여...


	이해했다. 자고나니까.
group[0][i]: 1글자 기준으로 그룹번호 매겨진다
group[1][i]: 2글자 기준으로 그룹번호 매겨진다
group[2][i]: 4글자 기준으로 그룹번호 매겨진다
group[3][i]: 8글자 기준으로 그룹번호 매겨진다
...

q = s + "#" + t 
q를 가지고 접미사 array 를 만든다.
이때 만드는 중간 계산 과정을 슬라이딩 윈도우로 지우지 말고 // 종만 코드
"따로 group[][] 배열에 기록해 놓는다."

"3번 인덱스의 글자와 13번 인덱스의 글자의 최대 길이 접두사를 logN으로 구하는 시나리오'!!!!

group[2][3]: 3번 인덱스에서 시작하는 접미사이며 4글자 기준으로 그룹번호
group[2][13]: 13번 인덱스에서 시작하는 접미사이며 4글자 기준으로 그룹번호

만약 같은 그룹이라면 3~, 13~ 접미사는 앞의 4문자는 같음을 의미한다.
	
그렇다면 그 뒤 2 문자를 체크해보자
group[1][3 + 4]: 7번 인덱스에서 시작하는 접미사이며 2글자 기준으로 그룹번호
group[1][13 + 4]: 17번 인덱스에서 시작하는 접미사이며 2글자 기준으로 그룹번호

이것도 같은 그룹이라면 3~, 13~ 접미사는 앞의 6문자는 같음을 의미한다.


group[0][3 + 4 + 2]: 9번 인덱스에서 시작하는 접미사이며 1글자 기준으로 그룹번호
group[0][13 + 4 + 2]: 19번 인덱스에서 시작하는 접미사이며 1글자 기준으로 그룹번호 
여기서 다른 그룹을 가진다면 중지하면 된다.
여기서도 같다면 앞의 7문자가 같음을 의미한다.


http://codeforces.com/contest/839/problem/A		// 쉬운문젠데 간단하게 짜는 법이 필요
// 도도리아의 예술 코드..	// 1분만에 짜다니..
http://codeforces.com/contest/839/submission/29379506
int main() {
	int n, k, i, j;
	cin >> n >> k;	// scanf 
	int s = 0;
	for (i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		s += t;
		k -= min(s, 8);
		s -= min(s, 8);
		if (k <= 0) return !printf("%d\n", i);
	}
	return !printf("%-1\n");
}

http://codeforces.com/contest/839/problem/B		// 좋은 문제 코드잼, codejam 급
http://codeforces.com/contest/839/submission/29387711
비행기에 사람을 채우는 문제, 비행기 좌석 문제

1,2 는 다른 그룹이 서로 앉으면 안된다.

3,4 ""
4,5 ""
5,6 ""

7,8 도 마찬가지로 다른 그룹이 서로 앉으면 안된다.



내생각: 노가다. 8명 이상인 그룹은 8로 나눈 나머지만 처리하자. 
		7명 그룹을 처리하면 seat4 를 감소 3명 그룹증가
			or seat2를 감소 5명 그룹증가.
		6명 그룹을 처리하면 seat4 를 감소 2명 그룹증가
			of seat2를 감소 4명 그룹증가.
		...
		단 2명 그룹을 처리하면 seat4 를 감소, "1명 seat 증가" 
내가 빠뜨린 예시
2 5
8 2 2 2 2	// YES가 나와야 하는데 나는 NO 다 

2 "4" 2
2 "4" 2

첫번째 그룹을 쪼개서 4, 4 로 나눠어서 채워야 한다. 
나의 처리는 8을 생략하기에 아래의 답과 같이 나온다.
1 4
2 2 2 2 // 여기서 NO가 나오겠지

int main() {
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	int s = 0, c1 = 0, c2 = 0;
	for (i = 1; i <= k; ++i) {
		int t;
		scanf("%d", &t);
		s += t;
		c1 += t / 4;	// 4seat 에 앉힐 수
		if (t % 4 >= 2) c2++;	// 2seat 에 앉힐 수
	}
	int v1 = 0, v2 = 0;
	if (s > 7 * N)
	... 코드는 짧은데 내머리론 이해 불가능...ㅠㅠ
}
// 에디토리얼 설명을 보자. 설명 잘되어 있었다. // 도출하는데는 시행착오가 걸리며 어렵다.
// C 번을 B번보다 2배 많이 풀었다.
// 이런 문제는 종이로 정리를 철저히 할 필요가 있었다. 나는 괜히 map 을 써서 고생만했고
// 충분한 생각 없이 짜는걸 우선시 해서 망했다. while 을 사용할걸 고려 했는데도 쓰지 못함...
http://codeforces.com/contest/839/submission/29412154
int n, k, have[5], cnt[5];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	have[2] = 2 * n, have[4] = n;
	for (int i = 0; i < k; ++i) {
		int x; cin >> x;
		while (x >= 3) {
			if (have[4] > 0)
				x -= 4, have[4]--;
			else if (have[2] > 0)
				x -= 2, have[2]--;
			else
				return cout << "NO" << '\n', 0;	// 이러면 뭐가 리턴되나? 0 요
		}
		if (x > 0)
			cnt[x]++;	// cnt[1], cnt[2]
	}
	while (cnt[2]) {
		if (have[2] > 0)
			cnt[2]--, have[2]--;
		else if (have[4] > 0)
			cnt[2]--, have[4]--, have[1]++;
		else
			cnt[2]--, cnt[1] += 2;// 남은 cnt는 cnt[1] 로 쪼개서 해결하자.. !!!! 생각하기 힘든 부분
	}
	if (cnt[1] > have[1] + have[2] + have[4] * 2)
		return cout << "NO" << '\n', 0;
	return 0;
}

return cout << "abcd" << '\n';	// 컴파일 불가
return cout << "abcd" << '\n', 3;	// "abcd"를 출력하고 3을 리턴한다.


D. Winter is here
http://codeforces.com/contest/839/problem/D
http://codeforces.com/contest/839/submission/29385097
John 은 n명의 군인으로 이루어진 군대를 가지고 있다.
그는 그의 군대가 얼마나 강한지 판단하는 메소드를 만들었다.
i번째 군인의 강함이 Ai 라 하자. 
John은 k명의 군인을 선택한다 (i1 < i2 < i3 < ... < ik ) // 번호가 오름차순으로
그것들은 gcd(Ai1, Ai2, ..., Aik) > 1 인 조건을 만족되는 걸로 선택된다.

John은 그 k명으로 이루어진 클랜의 강함을 k * gcd(Ai1, Ai2, ..., Aik) 라고 정했다.

마지막으로 군대의 강함은 그 만들수 있는 모든 만들수 있는 클랜의 강함의 합으로 결정된다. 

input
3
3 3 1
output
12	// {1}, {2}, {1, 2} so the answer will be 1*3 + 1*3 + 2*3 = 12
"n 이 20만개다... ㅡㅡ... 우짜지.."



hint: 포함 배제 // inclusion exclusion
// 포함 배제 간단한 설명 : http://blog.myungwoo.kr/51
Topcoder나 codeforces에서 문제들을 풀다보면 포함-배제의 원리를 이용해야 시간안에 해결할
수 있는 문제들이 존재한다. 
포함-배제의 원리는 원리 자체로는 중학교 수학에서 공부하여 잘 알려져 있다.
"벤다이어그램"으로 말이다. 허나 실제 문제에서 이를 응용하는 것은 "꽤 까다롭게" 느껴질 수 있다.
// 까다롭더라.. ㅠㅠ

1) 집합이 두 개인 경우
	|A|를 유한 집합 A의 크기라고 하면, 두 유한 집합 A, B의 합집합의 크기 |A U B| 는
	아래와 같다.
		|A U B| = |A| + |B| - |A^B|	// ^ 는 교집합
2) 집합이 세 개인 경우
		|A U B U C| = |A| + |B| + |C| - |A^B| - |B^C| - |C^A| + |A^B^C|

3) 일반항
	일반적으로 n개의 유한 집합 A1, A2, ..., An 이 있다고 하자. 그 합집합의 크기는
	아래와 같다.	// 좋다. 타이핑쳐서 암기하자.
	|U<i:1..n> Ai| =	sigma<i:1..n>|Ai| - sigma<i,j:1<=i<j<=n>|Ai^Aj|
					+	sigma<i,j,k:1<=i<j<k<=n>|Ai^Aj^Ak| - ...
					+ (-1)^(n-1)|A1^...^An|
					
// 원소가 3개 있으면 마지막이 -
// 원소가 4개 있으면 마지막이 +
// 원소가 5개 있으면 마지막이 - 
// ...

4) 여러 응용
	a. 완전 순열의 개수
	b. 이진수 and 연산 경우의 수
	c. 합이 s가 되는 경우의 수

a. 완전순열의 갯수 // 완전순열(또는 교란순열)
예시) n 명의 사람들이 n개의 의자에 아무렇게나 앉을 때, 전부 자기 자리에 앉지 않는
	경우의 수를 구하시오.
	n 명의 사람이 모자를 무작위로 벗어두었다. 모든 사람이 다시 무작위로 모자를 썼을때
	모두 자신의 모자가 아닐 경우의 수를 구하시오
"좋은 설명 같다만.."
	http://blog.naver.com/PostView.nhn?blogId=leebs&logNo=40179725176

공식
Ai 를 i가 i번째 자리에 위치하는 경우의 수라고 하면 //n이 5라고 하고
1 2 3 4 5
A1: 1이 제자리에 없을 순열의 경우의 수는 (n-1)!
A2: 2가 제자리에 없을 순열의 경우의 수는 (n-1)!
	...
A3: 5가 제자리에 없을 순열의 경우의 수는 (n-1)!

// 공식에서 n! 에 곱하기가 완전순열의 수라서 더 커지면 이상하잖아 (순열보다 작아야 하니까)
// 하고 생각했는데 곱하는 수들의 합은 1보다 작다.!!!!
완전순열의 갯수
Dn	= n! - n(A1 U A2 U A3 U A4 U A5)
	= n! - n!(1 - (1/2!) + (1/3!) - (1/4!) + (1/5!))
	= n! - n! - n! * ((1/2!) - (1/3!) + (1/4!) - (1/5!))
	= n! * ((1/2!) - (1/3!) + (1/4!) - (1/5!))
"	= n! * sigma<i:0..n>{(-1)^i / i! }	// 왜 0부터지 2부터가 아니고...? n이 1일때 0 되게 깔끔해 져서구나.
	= n! * { 1 + (-1) + (1/2) + (-1/6) + (1/24) + (-1/120) } 
	= n! * { (1/2) + (-1/6) + (1/24) + (-1/120) }
	= 120 * { (1/2) + (-1/6) + (1/24) + (-1/120) }
	= 60 + (-20) + 5 + (-1) 
	= 44 개

실재로 너무 많으니까 n 이 4인 경우로 확인해보자
Dn	= 4! - 4!(1 - (1/2!) + (1/3!) - (1/4!))
	= 24 * ((1/2) + (-1/6) + (1/24))
	= 12 + (-4) + 1
	= 9 개가 된다.

2143	2341	2413
3142	3412	3412
4123	4312	4321




백준 가장 가까운 점 거리 찾는 문제
const int INF = 1987654321;
//const int INF = 2147483647;	// 문제에서 숫자 범위확인이 중요하다 !!!!
struct point { int x, y; };
int dist(point& p, point& q) { return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y); }
bool cmpX(point& p, point& q) { return p.x < q.x; }
bool cmpY(point& p, point& q) { return p.y < q.y; }
int closestPair(point* P, int n) {
	if (n == 2) return dist(P[0], P[1]);
	if (n == 3)
		return min({ dist(P[0], P[1]), dist(P[1], P[2]), dist(P[2], P[0]) });
	int line = (P[n / 2 - 1].x + P[n / 2].x) / 2;
	int d = min(closestPair(P, n / 2), closestPair(P + n / 2, n - n / 2));

	vector<point> Mid(n);
	int midN = 0;
	for (int i = 0; i < n; ++i) {
		int t = line - P[i].x;
		if (t*t <= d) Mid[midN++] = P[i];
	}
	sort(Mid.begin(), Mid.begin() + midN, cmpY);

	for (int i = 0; i < midN; ++i)
		for (int j = i + 1; j < midN && j <= i + 3; ++j)	
		// 3개만 비교해도 통과하더라. 원저자는 6이라 했다만.. 6이 안전하긴 하겠다만...
			d = min(d, dist(Mid[i], Mid[j]));
	return d;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	point P[100001];
	rep(i, n) cin >> P[i].x >> P[i].y;
	sort(P, P + n, cmpX);
	int sol = closestPair(P, n);
	cout << sol;
	return 0;
}


카카오 1차 예선 문제
1번: 쉬워서 생략
2번: 쉽다만. 깔끔하게 구현을 하는게 중요하다. 
3번: LRU 에 10만개의 정보들을 넣는다. cache 크기가 주어져 있고 적중시 1 비적중시 5 의 비용이 든다.
	LRU 구현이 힘들었다. 
	map<string, int> my:
	map<pair<int, string>, bool> my2

vs arr; 
rep(i,arr.size());
	string key = arr[i];
1.	적중시: my.count(key) != 0 으로 판단 // count가 map 에선 항상 1만 리턴하더라. key 의 갯수니까.!!! value 가 아니다.!!!!
	int val = arr[key];
	my[key] = i;	// 현 시간으로 변경

	my2.erase(mp(val, key));	// 캐시에 있는것중 제일 쓰임이 마지막인 놈을 지운다.
	my2.erase(mp(i, key));

2. 비적중시: cache 사이즈가 0인 경우 비용만 5증가하고 continue;
	cache사이즈가 꽉찼다면
		string delKeyS = my2.begin()->first.first;
		string delKeyV = my2.begin()->first.second;
		my.erase(delKeys);	// 제일 마지막놈은 지운다.
		my2.erase(my2.begin());	// iterator 로 받을까..

		my[key] = i;
		my2[mp(i, key)] = true;

	cache사이즈가 여유면
		my[key] = i;
		my2[mp(i, key)] = true;
	

4번: 무슨문제인지 기억이 안난다.
5번: 두 집합의 "교집합 크기" / "합집합 크기"
	단 집합에서 같은 원소가 여러개가 있는 경우
	{a, a, b}, {a, b, b, b}
	교집합: {a, b}	// a : min(앞의 a 갯수, 뒤의 a갯수), b : ""
	합집합: {a, a, b, b, b} // a : max(앞의 a갯수, 뒤의 a갯수), b: ""

	map<string, int> my1, my2, my3, my4;
	prec(my1, str1);	// my1 에 2문자씩 추출
	prec(my2, str2);	// my2 에 2문자씩 추출

	for (my1.size()...) {
		// my1, my2 동일 원소 존재하면 
		my3[] = min()	// 교집합 원소 갯수
		my4[] = max()	// 합집합 원소 갯수

		// 동일원소 존재 안할시
		my3[] = 0;
		my4[] = val;
	}
	for (my2.size()...) {
		// my1 순회시 존재안한 key 에 대해
		my3[] = 0;
		my4[] = my2[];
	}

	분자: my3[] 순회한 value 합
	분모: my4[] 순회한 value 합
	sol = int(분자/분모 * 65536)

const int M = 1000000007;
void prec(map<string, int>& my, string str) {
	string tmp = str;
	transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
	for (int i = 0; i < tmp.size() - 1; ++i) {
		string a = tmp.substr(i, 2);
		if (!('a' <= tmp[i] && tmp[i] <= 'z'))
			continue;
		if (!('a' <= tmp[i + 1] && tmp[i + 1] <= 'z'))
			continue;
		my[a]++;
	}
}
int solution(string str1, string str2) {
	map<string, int> my1, my2, my3, my4;
	prec(my1, str1);
	prec(my2, str2);

	map<string, int>::iterator it = my1.begin();
	for (; it != my1.end(); ++it) {
		string key = it->first;
		int val = it->second;

		int val2 = 0;
		if (my2.count(key)) // 왜 count가..
			val2 = my2[key];
		
		int cnt1 = min(val, val2);          // 공통된 원소의 최소갯수
		int cnt2 = max(val, val2);          // "" 최대갯수
		my3[key] = cnt1;
		my4[key] = cnt2;
	}
	// str2 베이스로 중첩이 아닌 원소를 처리하자.
	it = my2.begin(); 
	for (; it != my2.end(); ++it) {
		string key = it->first;
		int val = it->second;

		if (my3.count(key)) continue; // 중첩 된 (처리된 거라면)

		my3[key] = 0;
		my4[key] = val;
	}
	it = my3.begin();
	int molecule = 0;
	for (; it != my3.end(); ++it) molecule += it->second;

	it = my4.begin();
	int denom = 0;
	for (; it != my4.end(); ++it) denom += it->second;

	double tmp = (double)molecule / (double)denom;
	// 0 / 0 꼴에 대한 예외처리 필요
	int answer = (tmp * 65536);
	return answer;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n, t, m;
	vs input;
	n = 3, t = 6, m = 2;
	int idx = 0;
	for (idx; idx < 5; ++idx) {
		if (idx == 3)
			break;
	}
	//input = { "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" };
	input = {"00:01", "00:01"}; !!!! vector<string> 초기화에 좋네


	//string output = solution(n, t, m, input);
	string str1 = "E=M*C^2";
	string str2 = "shake hands";
	//string str1 = "abc";
	//string str2 = "ABC";
	int sol = solution(str1, str2);
	vector<int> arr = { 0, 1, 1, 2, 2, 4 };
	vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), 2);
	vector<int> testee(arr.begin(), it);
	return 0;
}



http://codeforces.com/contest/864/problem/D
1 ~ n 까지 순열을 만들어야 하는데
주어진 수는 그렇지 않다
1 ~ n 중 몇몇수가 중복되어 있다.
최소한의 숫자 변경으로
순열을 만들어라
그리고 최소한의 경우 가장 작은 순열이 되어야 한다.
 
4 
3 2 2 3
 
output
2		// 가장 적게 변경
1 2 4 3	// 가장 작은 순열
 
#include <iostream>
#include <vector>
#define rep(i,a) for (int i = 0; i < (a); ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
 
int main() {
	int n; cin >> n;
	vi arr(n);
	rep(i,n) cin >> arr[i];
	vi arr2(n + 1);
	rep(i,n) arr2[arr[i]]++;	// 0이면 없는 숫자	, 2개 이상이면 한개만 남긴다.
	
	vb useSelf(n+1);	// 2개 이상인 수 에서 한놈을 자신으로 설정완료시 true
	int sol = 0;
	int idx = 0;
	for (int num = 1; num <= n; ++num) {
		if (arr2[num] == 0) {	// 없는 숫자를 생성하자.
			while (true) {	// 없는 숫자를 넣기 위해 변경해야 할 곳을 찾는다.
				if (idx == n) break;
				int num2 = arr[idx];
				if (arr2[num2] >= 2) {	// 2개 이상이면
					// 숫자를 그대로 두는 경우
					if (num > num2 && useSelf[num2] == false) {
						useSelf[num2] = true;
						idx++;
					}
					else {
						// 없는 숫자를 넣을 장소를 찾았다.
						sol++;
						arr[idx] = num;	// 없는 숫자를 채운다.
						idx++;
						arr2[num2]--;
						break;
					}
				} else
					idx++;	// 못찾아도 배열 인덱스 증가
				if (idx == n) break;
			}
		}
	}
	cout << sol << '\n';
	rep(i,n) cout << arr[i] << " ";
	return 0;
}
 
 
http://codeforces.com/contest/864/problem/E
아이템이 불타고 있고 그것들을 구해야 함
총 n개의 아이템이 있음 (1 <= n <= 100)
각 아이템음 구하는데는 ti 시간이 걸림	(1 <= ti <= 20)
각 아이템은 di 시간 이상이 되는 순간 구할 수가 없음	(1 <= di <= 2000) 유효시간
각 아이템은 pi 의 가치를 가지고 있음	(1 <= pi <= 20)
 
3
3 7 4	// 구하는데 걸리는 시간 3,  유효시간 7, 가치 4
2 6 5
3 7 6
 
output
11	// 총 살린 가치
2	// 살린 아이템 수
2 3 // 살린 아이템 번호
 
 
2와 3은 다 해결하는 동안 총 5시간 걸림.
허나 그뒤 1은 완전 해결하려면 3을 더해서 8시간이 걸림 이는 유효시간 7을 초과이므로 수행 못함
 
 
si = di - ti : 적어도 이것보다 빠른 시간에 구조가 시행되어야 한다.
 
si 별로 정렬한다. (두번째 요소도 필요하다 ti 시간이 지난후 다음 살릴수 있는 아이템 을 가르키도록)
 
dp[index][hereTime] = max{	dp[index-1][hereTime]
							dp[index-1][hereTime - t(index)] + p(index)}
음... 이것보다 더 간단명료하게 표현하는 법 풀이 보자.


// 코드포스 풀이 http://codeforces.com/blog/entry/54765
두개의 아이템을 구한다고 할때, d값이 작은 쪽을 먼저 구하는게 낫다.	// 이런 생각이 중요!!!!
따라서 d값을 기준으로 정렬을 한다.

"dp[i][j] = i 미만의 번호를 가진 아이템들을 처리하여 j시간에 도달할 시 최대 가치"
// i = 아이템
// j 시간
"i 아이템을 취하는 경우"
dp[i+1][j+ti]	= max(dp[i+1][j+ti], dp[i][j] + pi), if j + ti < di
"i 아이템을 안 취하는 경우"
dp[i+1][j]		= max(dp[i+1][j], dp[i][j])


for (int i = 0; i < n; ++i) {
	for (int j = 0; j < time; ++j) {
		if (j + t[i] < d[i]) {
			tmp = d[i][j] + p[i];
			dp[i+1][j + t[i]] = max(dp[i+1][j + t[i]], tmp);	
		}
		dp[i+1][j] = max(dp[i+1][j], dp[i][j];
	}
}

// 통과함 15ms
const int N = 123;
const int N2 = 2345;
int t[N], d[N], p[N];	// t: 불끄는데 걸리는 시간, d: 제한시간, p: 가치
int dp[N][N2];	// 
int sel[N][N2];
// 현시간 + 끄는데 걸리는 시간 >= 제한시간이면 못구한다.
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	rep(i, n) cin >> t[i] >> d[i] >> p[i];
	vpii sorted(n);
	rep(i, n) {
		sorted[i].first = d[i];
		sorted[i].second = i;
	}
	memset(sel, -1, sizeof(sel));
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < n; ++i) {
		int idx = sorted[i].second;
		for (int j = 0; j < N2; ++j) {
			// i 아이템을 취하는 경우
			if (j + t[idx] < d[idx]) {
				int tmp = dp[i][j] + p[idx];
				if (dp[i + 1][j + t[idx]] < tmp) {
					dp[i + 1][j + t[idx]] = tmp;
					sel[i + 1][j + t[idx]] = idx;	// 취한 아이템 번호 저장
				}
			}
			// i 아이템을 안 취하는 경우
			if (dp[i + 1][j] < dp[i][j]) {
				dp[i + 1][j] = dp[i][j];
				sel[i + 1][j] = -1;	// 안선택하므로 그보다 앞에걸로 취함
			}
		}
	}
	// 가장 큰 값이 나오는 끝나는 시간을 찾는다.
	int lastT = -1;
	int sol = 0;
	rep(i, 2001) if (dp[n][i] > sol) { sol = dp[n][i]; lastT = i; }
	cout << sol << endl;
	vi sol2;
	
	int idx = n;
	int here = lastT;
	if (here == -1) { cout << 0;  return 0; }
	while (true) {
		if (idx < 0) break;
		int tmp = sel[idx][here];
		if (tmp == -1) {
			idx--;
		}
		else {
			sol2.push_back(tmp);
			idx--;
			here = here - t[tmp];
		}
	}
	reverse(sol2.begin(), sol2.end());	// sort 써서 망했음요.. !!!!
	cout << sol2.size() << '\n';

	rep(i, sol2.size()) cout << sol2[i] + 1<< " ";
	return 0;
}




http://codeforces.com/contest/866/problem/B

input
3 12	// (1 <= N <= 10^5), (1 <= S <= 10^5)	// 사람수, 피자당 조각 수
3 5 7	// 3조각을 먹음, a피자조각당 만족도, b피자조각당 만족도.
4 6 7
5 9 5

output	// 최대 만족도
84	// 1번 사람은 b피자를 선호, 2번사람도 b피자를 선호, 3번사람은 어쩔수 없이 b피자를 선택

http://codeforces.com/contest/866/submission/30874326	// tourist
// 모두들 가장 선호하는 피자를 선택시 얻는 점수들과 "합"을 기록하고
// 공유가 되는 피자가 어느쪽이냐에 따라 잃는 점수들이 생기니 
// 둘중 어느 피자인지 보고 빠지는 점수가 적은 쪽을 택한다.
const int N = 1234567;
int eat[N], a[N], b[N];
int main() {
	int n, s;	cin >> n >> s;	ll total = 0;
	rep(i,n) {	cin >> eat[i] >> a[i] >> b[i];	total += eat[i]; }
	ll pizzas = (total + s - 1) / s;
	eat[n] = s * pizzas - total;	// 남은 피자조각수
	a[n] = 0, b[n] = 0;	n++;	// 맨 끝 설정
	vector<pair<ll, ll>> a_to_b, b_to_a;
	ll ans = 0, cnt_a = 0, cnt_b = 0;
	rep(i,n) {
		if (a[i] > b[i]) {
			ans += eat[i] * 1LL * a[i];
			a_to_b.push_back(a[i] - b[i], eat[i]);	// a피자를 선택해서 더 얻는 슬라이스 점수 , 슬라이스 수 기록
			cnt_a += eat[i];	// 슬라이스 수 기록
		} else {
			ans += eat[i] * 1LL * b[i];
			b_to_a.push_back(b[i] - a[i], eat[i]);
			cnt_b += eat[i];
		}
	}
	ll best = (ll)1e18;
	{
		ll extra = cnt_a % s;	// 이 갯수만큼은 원복
		sort(a_to_b.begin(), a_to_b.end());	// 음이 아닌 값들이 정렬된다. // a피자 선택시 더 얻는 점수들
		ll cur = 0;
		for (int i = 0; i < (int)a_to_b.size(); ++i) {
			auto& p = a_to_b[i];
			ll take = min(p.second, extra);	// a->b시킬 갯수<점수를 잃는다.>	// extra는 0 미만이 되면 의미없는 루틴 (루프종료나 마찬가지)
			cur += take * p.first;	// 그만큼 잃는 점수
			extra -= take;
		}
		best = min(best, cur);	// "a피자 조각들" -> "b피자 조각들"  옮길때 잃는 점수.
	}
	{
		ll extra = cnt_b % s;
		sort(b_to_a.begin(), b_to_a.end());
		ll cur = 0;
		for (int i = 0; i < (int)b_to_a.size(); ++i) {
			auto& p = b_to_a[i];
			ll take = min(p.second, extra);
			cur += take * p.first;
			extra -= take;
		}
		best = min(best, cur);
	}
	cout << ans - best << endl;	// 둘중에 옮길시 잃는게 작은 점수를 택한다.
}
// 만약 이 공유피자가 없는 경우엔 어찌 동작할까?
2 4
3 5 1
2 1 5
// n++ 을 하고 빈 값을 넣은 이유를 보면 정상동작함을 알 수 있다.!!!! 대단해 



http://codeforces.com/contest/869/problem/C // 독립되는 부분을 판단해야 하는 좋은 문제
C. The Intriguing Obsession

1 1 1 // input
8	// output

1 2 2 // input
63	// output

// 그림으로 그리면
	a1
b1		c1
b2		c2

// 여기다가 b와b 가 직접 연결되는 간선은 존재하면 안된다.
// b1 - a1 - b2	// 이렇게 b끼리 연결길이가 2가 되어도 안된다. 
// b1 - a1 - c2 - b1 // 이렇게 길이가 3이면 가능하다. // 3이상은 가능하단 식으로 기술 되었지만
"최대가 3이 되겠군"
// 풀이는 생략한다. 다시 풀어봐라.!!!!



http://codeforces.com/contest/872/problem/B
5 2				// n개가 주어지고 k개로 분리할때  n and k (1 ≤ k ≤ n ≤  10^5)
1 2 3 4 5		// 그 분리된 각각의 그룹의 최소값에 대한 최대값을 구하라.  
// ( - 10^9  ≤  ai ≤  10^9).

k가 1인 경우 minimum 출력
k가 3이상인 경우 maximum 출력
"문제는 k가 2인 경우 순회해야 한다!!!" 생각은 했는데 단순한걸로 풀수 있겠지 하고 다른 방식으로 제출했다 망함.
처음 생각
	arr[0] , arr[1], arr[2], arr[3], ...
multiset<int> s1, s2;
s1.insert(arr[0])

s2.insert(... 나머지 전부)

sol = max(s1의 최소, s2의 최소)
for (int i = 1; i < n-1; ++i) {
	s1.insert(arr[i]);
	s2.erase(arr[i]);
	int cand = max(s1의 최소, s2의 최소);
	sol = max(sol, cand);
}


굳이 집합을 쓰지 않아도 된다. // 긴장을 풀고 합시다..
int main() {
	int n, k;
	cin >> n >> k;
	vi arr(n);
	rep(i, n) cin >> arr[i];
	if (k == 1) 
		cout << *min_element(arr.begin(), arr.end());
	else if (k >= 3)
		cout << *max_element(arr.begin(), arr.end());
	else if (k == 2) {
		vi s1(n, INF), s2(n, INF);
		s1[0] = arr[0];
		for (int i = 1; i < n; ++i)
			s1[i] = min(arr[i], s1[i - 1]);	// 시작부터 i까지의 구간 최소값
		s2[n - 1] = arr[n - 1];
		for (int i = n - 1 - 1; i >= 0; --i)
			s2[i] = min(arr[i], s2[i + 1]);	// 끝부터 i까지의 구간 최소값

		int sol = max(s1[0], s2[1]);
		for (int i = 1; i < n - 1; ++i) {
			int cand = max(s1[i], s2[i + 1]);
			sol = max(sol, cand);
		}
		cout << sol;
	}
	return 0;
}


http://codeforces.com/contest/872/problem/C
어떤수를 합성수의 합으로 만든다고 할때 합성수의 갯수를 최대화 한다고 하면 몇개가 나오는가?
ex 10 -> 4 + 6 = 2개

만약 "합성수의 합"으로 나타낼수 없다면 -1 을 리턴한다. 
	1인 경우도 -1을 리턴한다.

1 -> -1
2 -> -1
3 -> -1
4 -> 1
5 -> -1
6 -> 1
7 -> -1
8 -? 2
9 -> 1

... 처음엔 어떤수를 합성수의 곱으로 만드는 건줄 알고 에라토스 테네스를 쓰려고 했다.. 망했다.

각설하고
	어떤수를 몇몇 수의 합으로 나타낸다고 할때
	2 와 3으로 거진 다 나타낼수 있다.

	문제에선 합성수이니까
		짝수와 홀수에서 제일 작은 합성수를 골라보면
		4, 9// 홀수도 필요하니
		가 된다.
		그사이 합성수도 고려해야 하니 6도 생각해두자.

		그런 다음
			홀수인 경우 -9를 고려

			짝수인 경우 -6을 할찌 고려
			
			마지막으로 / 4 를 해서 몫을 고려하자.
int main() {
	int q; cin >> q;
	rep(i,q) {
		int a; cin >> a;
		int sol = 0;
		if (a % 2 == 1) {
			int tmp = 0;
			if (a - 9 >= 0) {
				a -= 9;
				tmp++;
				if (a - 6 >= 0 && a % 4 == 2) {	// 짝수이며 6을 빼줄 필요가 있는 케이스
					a -= 6;
					tmp++;
				}
				if (a % 4 == 0) {
					tmp += (a / 4);
					sol = tmp;
				}
			}
				
		} else {
			int tmp = 0;
			if (a - 6 >= 0 && a % 4 == 2) {
				a -= 6;
				tmp++;
			}
			if (a % 4 == 0) {
				tmp += (a / 4);
				sol = tmp;
			}
		}
		cout << sol << '\n';
	}
}


"프로그래머스 알고리즘 강사"
// 10만개의 점, 10만개의 박스, 10만 by 10만 좌표 공간
// 폭탄을 최소 몇개 터트려야 되나.
// 입력을 그래프로 만들고 dfs돌리면 된다.
// 힘든점은 10만개를 잘 처리하는 기술이다.
// y 가 같은 점들을 모아서 정렬한 후
// 작은거 부터 순회하여 연결이 되어 있는지 본다. (앞 뒤만 연결시키면 된다. !! 핵심)
// 
// x 가 같은 것에 대해서도 마찬가지로 처리한다.
// 중간에 박스가 있을수 있으므로 체크하자.

// map 으로 했을시 약간 타임 오버였는데 unordered_map 으로 하니 타임오버가 없다.

map<pair<int, int>, bool> boxMap;
vector<vector<int>> graph;
unordered_map<int, pair<int, int>> graphDB;
vector<bool> vstd;
long long numbering1(int y, int x) {
	return y * 100000 + x;
}
unordered_map<long long, int> numM;
int numbering2(int y, int x) {
	long long idx = y * 100000 + x;
	if (numM.count(idx))
		return numM[idx];
	int msize = numM.size();
	numM[idx] = msize;
	graphDB[msize] = make_pair(y, x);
	return numM[idx];
}
unordered_map<int, vector<int>> yMap, xMap;
void makeGraph(const vector<vector<int>>& bomb, const vector<vector<int>>& box, const int K) {
	for (int i = 0; i < bomb.size(); ++i) {
		int y = bomb[i][0], x = bomb[i][1];
		yMap[y].push_back(x);	xMap[x].push_back(y);
	}
	for (int i = 0; i < box.size(); ++i) {
		int y = box[i][0], x = box[i][1];
		yMap[y].push_back(x);	xMap[x].push_back(y);
		boxMap[make_pair(y, x)] = true;
	}
	// 그래프화
	unordered_map<int, vector<int>>::iterator it = yMap.begin();
	for (; it != yMap.end(); ++it) {
		int y = it->first;
		vector<int> xArr = it->second;
		sort(xArr.begin(), xArr.end());
		for (int i = 0; i < xArr.size() - 1; ++i) {
			int x = xArr[i];
			int nxtX = xArr[i + 1];

			bool box1 = boxMap.count(make_pair(y, x)) > 0;
			bool box2 = boxMap.count(make_pair(y, nxtX)) > 0;

			if (box1 == false && box2 == false)
				if (nxtX - x <= K) {
					int u = numbering2(y, x);
					int v = numbering2(y, nxtX);
					graph[u].push_back(v);	graph[v].push_back(u);
				}
		}
	}

	it = xMap.begin();
	for (; it != xMap.end(); ++it) {
		int x = it->first;
		vector<int> yArr = it->second;
		sort(yArr.begin(), yArr.end());
		for (int i = 0; i < yArr.size() - 1; ++i) {
			int y = yArr[i];
			int nxtY = yArr[i + 1];

			bool box1 = boxMap.count(make_pair(y, x)) > 0;
			bool box2 = boxMap.count(make_pair(nxtY, x)) > 0;
			
			if (box1 == false && box2 == false)
				if (nxtY - y <= K) {
					int u = numbering2(y, x);
					int v = numbering2(nxtY, x);
					graph[u].push_back(v);	graph[v].push_back(u);
				}
		}
	}
}
void dfs(int here) {
	vstd[here] = true;
	for (int i = 0; i < graph[here].size(); ++i) {
		int there = graph[here][i];
		if (vstd[there] == false)
			dfs(there);
	}
}
int solution(vector<vector<int>> bomb, vector<vector<int>> box, int K) {
	numM.clear(); yMap.clear(); xMap.clear();	graph.clear();
	graph.resize(bomb.size());
	makeGraph(bomb, box, K);

	vstd = vector<bool>(graph.size(), false);

	int answer = 0;
	for (int i = 0; i < graph.size(); ++i)
		if (vstd[i] == false) {
			++answer;
			dfs(i);
		}
	return answer;
}
int main() {
	while (true) {
		graphDB.clear();
		vector<vector<int>> bomb;
		vector<vector<int>> box;
		int K;
		int t; 
		cin >> t;// 폭탄수
		for (int i = 0; i < t; ++i) {
			vector<int> pt(2);
			cin >> pt[0] >> pt[1];
			bomb.push_back(pt);
		}
		int b; // 박스수
		cin >> b;
		for (int i = 0; i < b; ++i) {
			vector<int> pt(2);
			cin >> pt[0] >> pt[1];
			box.push_back(pt);
		}
		cin >> K;
		int sol = solution(bomb, box, K);
		cout << sol << endl;
		sol = sol;
	}
	return 0;
}



// 입력값 num : (1 <= num < (1 << 30)) 에 대하여
// 그 수를 2진수로 하였을때 나오는 1의 개수를 k 라 할 때
// 
int num, k;
int cache[31][31][2];
int getMxIdx(int n) {
	int ret = 0;
	while (n != 0) { n /= 2; if (n) ret++; }
	return ret;
}
int __popcnt(int n) {
	int ret = 0;
	while (n != 0) {
		int isOne = (n % 2);
		if (isOne) ret++;
		n /= 2;
	}
	return ret;
}
int rec(int here, int remainOne, int isLess) {
	if (remainOne < 0) return 0;
	if (here < 0) {
		if (remainOne == 0 && isLess) return 1;
		return 0;
	}
	int & ret = cache[here][remainOne][isLess];
	if (ret != -1) return ret;
	ret = 0;
	if (isLess == true) {
		if (remainOne > 0)
			ret += rec(here - 1, remainOne - 1, isLess);
		ret += rec(here - 1, remainOne, isLess);
	}
	else {
		// 같을 경우
		bool isOne = ((num & (1 << here)) != 0);
		if (isOne == false)
			ret += rec(here - 1, remainOne, isLess);
		else {
			ret += rec(here - 1, remainOne - 1, isLess);
			ret += rec(here - 1, remainOne, 1);
		}
	}
	return ret;
}
int solution(int n) {
	num = n;
	memset(cache, -1, sizeof(cache));
	int k = __popcnt(n);
	int remainOne = k;
	int mxIdx = getMxIdx(n);
	long long ret = rec(mxIdx, remainOne, 0);
	int ret2 = ret;

	return ret2;
}
int main() {
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int input;
	int test = solution(1 << 30);
	cout << test << endl;
	while (true) {
		cin >> input;
		int ret = solution(input);
		cout << ret << endl;
	}
	int ret = solution(9);
	cout << ret;
	return 0;
}




// 숫자 합이 10 인 것중 k 번째것 찾기
// INF 값을 키워보니
// 10000번째의 수는 10800100 인 것을 알수 있었다.!!!!
vector<long long> arr;
void rec(long long num, int sum) {
	if (sum == 0)
		arr.push_back(num);
	if (num >= 20000000) return;
	//if (num >= (1ull << 40)) return;
	for (int i = (num == 0) ? 1 : 0; i < min(sum + 1, 10); ++i)
		rec(num * 10 + i, sum - i);
}
int main() {
	int k;
	cin >> k;
	rec(0, 10);
	sort(arr.begin(), arr.end());
	//cout << arr[9999] << endl;
	cout << arr[k - 1];
	return 0;

}




http://codeforces.com/contest/948/submission/36170268
C. Producing Snow








// 야근 지수 문제.
// 시간 제약이 없음
// 인풋 제약이 없는 관계로 어떤식으로 짜야 하는지 매우 곤란.
// https://programmers.co.kr/learn/challenge_codes/145

// 알고리즘을 많이 하는 경우 제약 조건이 있으면 
// 만약 시간이 10억정도 된다면 
// 일의 종류가 10만개 인경우


#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
using namespace std;

int noOvertime(int no,vector<int> works)
{
  long long sum = 0;
  for (int i = 0; i < works.size(); ++i) sum += works[i];
  if (sum <= no) return 0;
  works.push_back(0);
  sort(works.begin(), works.end(), greater<int>());
  int use = 0;	// 모양을 깍는데 사용되는 시간
  int useI = -1;	// 해당 인덱스 뒤로는 일을 자르지 않는다.
  int mod = -1;	// 잘리는 것들 중 다른 것들 보다 1 더 잘린다.
  int solHeight = -1;	// 자르기 처리가 끝난 뒤 일들의 시간중 최대높이
  for (int i = 0; i < works.size() - 1; ++i) {
  	int curHeight = works[i];
    int nxtHeight = works[i + 1];
    int diff = curHeight - nxtHeight;
    int add = diff * (i + 1);
    
    if (use + add >= no) {
    	int cut = (no - use) / (i + 1);
      mod = (no - use) % (i + 1);
      solHeight = curHeight - cut;
      useI = i;
      use = no;
      break;
    }
    use += add;
  }
  vector<int> trim = works;
  for (int i = 0; i < trim.size(); ++i) {
  	if (useI >= i) {
    	trim[i] = solHeight;
      if (mod > i)
        trim[i]--;
    }
  }
  long long ret = 0;
  for (int i = 0; i < trim.size(); ++i) ret += trim[i] * trim[i];
  return ret;
}

int main()
{
	vector<int> works{4,3,3};
	int testNo = 4;

	int testAnswer = noOvertime(testNo,works);

	cout<<testAnswer;
}



https://programmers.co.kr/learn/challenge_codes/156
// 숫자의 표현 문제
// 등비수열의 합으로 처리
#include<iostream>
#include<string>
using namespace std;
long long asSum(int a, int l, int n) {
	return n * (a + l) / 2;
}
int expressions(int num)
{
	int answer = 0;
	int base = 1;
	while (true) {
		int medi = num / base;
		int tmp1 = base / 2;
		int tmp2 = tmp1;
		if (base % 2 == 0) tmp1--;	// 중앙값을 기준으로 앞쪽은 뒤로 가는 것보다 한칸 적을 수 있다.
		int a = medi - tmp1;
		if (a <= 0)
			break;
		int l = medi + tmp2;
		long long chk = asSum(a, l, base);
		if (num == chk)
			answer++;
		base++;
	}
	return answer;
}

int main()
{
	vi test{ 4, 3, 3 };
	int no = 4;
	int te = expressions(15);
	cout << te << endl;
	return 0;
}


https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/0000000000007a30
Go, Gopher!
코드잼 팀은 구매했다 과수원을 that is 2차원 매트릭스 구조 of 준비되지 않은 토양셀 with
 1000 rows and 1000 colums.
-> 코드잼팀은 1000 by 1000 의 셀크기인 2차원 매트릭스 구조의 준비되지 않은(땅이 안 파인) 과수원을 구매했다.

우리는 이 과수원을 이용할 것이다 다양한 나무들을 재배하기 위해
-> 우리는 이 과수원을 이용하여 다양한 나무를 재배 할 계획입니다.

그래서 우리는 몇몇 셀들에 구명을 팔 필요가 있습니다.


* 매년 나무 문제들에 사용하려는 충분한 수의 나무를 생산하기 위해, 
	우리는 준비된(땅 파인) 셀들을 준배해야 합니다.
* 우리의 나무를 적절히 키우기 위해 모든 준비된 셀들은 single grid-aligned rectangle ㄹㄹ
	만족한다. 
	
	
~~~

땅파기는 인간이 하기엔 매우 힘들다. 그래서 우리는 고고퍼를 빌려왔다. 그리고 고고퍼에게
훈련시켰다. 우리가 준비된 땅을 가질수 있도록.
우리는 고퍼를 배치시켰다. 
	
그러나 우리는 고퍼의 훈련이 완료되지 않은 상태로 배치했기에, 고퍼는 타겟 중심으로부터 
3x3 블럭중 하나를 균등램덤으로 선택할 것이다. 그 셀을 준비(땅파기) 한다.
(이미 땅파진 셀은 의미없이 한번 더 땅을 팔 뿐이다.)

우리는 고퍼 배치를 최대 1000번 할 수 있다. 
그래서 우리는 너의 도움이 필요하다 어떻게 전략적으로 배치할지를.

너가 고퍼를 배치할 때, 너는 들을 것이다 어떤 셀이 선택되어 배치되었는지를
그리고 너는 이 정보를 다음 배치에 활용할 것이다. (필요하다면)



~~~~

처음엔 테스트 케이스 T 를 입력받는다.
매 케이스마다 A 라는 값을 입력받는다. A 는 최소한의 직사각형 넓이가 된다.
그 뒤 너의 프로그램은 최대 1000번동안 judge 랑 정보교환(exchange)을 한다.

각각의 교환에는,
너의 프로그램은 standard output 으로 두 정수 i, j 를 보낸다. (고퍼를 배치할 위치이다.)
i, j 는 2에서 999 까지의 값을 가진다. 
너의 output format 이 잘못되면 틀린게 된다. (판정은 -1 -1 이 난다.)


bool check3by3Fill(const vector<vector<int>>& board, int x, int y) {
	bool check = true;
	for (int i = x - 1; i <= x + 1; ++i)
		for (int j = y - 1; j <= y + 1; ++j) {
			if (board[i][j] == 0)
				check = false;
		}
	return check;
}

int main() {
	int cs; cin >> cs;
	for (int cc = 0; cc < cs; ++cc) {
		int area; cin >> area;
		vector<vector<int>> board(1005, vector<int>(1005, 0));
		int baseX = 2, baseY = 2;
		while (true) {
			cout << baseX << " " << baseY << '\n';
			fflush(stdout);
			int i, j;
			cin >> i >> j;
			if (i == 0 && j == 0) break;
			board[i][j]++;
			bool check = check3by3Fill(board, baseX, baseY);
			if (check == true)
				baseX += 3;
		}
	}
	return 0;
}

4번 스몰테스트 는 아래로 통과함

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	for (int cc = 0; cc < cs; ++cc) {
		double area; cin >> area;
		double piDiv4 = PI / 4.0;
		double cosPiDiv4 = cos(piDiv4);
		area *= cosPiDiv4;
		double solAngle = piDiv4 - acos(area);
		double x0 = 0.5,	y0 = 0,		z0 = 0;
		double x1 = 0,		y1 = 0.5,	z1 = 0;
		double x2 = 0,		y2 = 0,		z2 = 0.5;
		x0 = 0.5 * cos(solAngle);
		y0 = 0.5 * -sin(solAngle);
		x1 = 0.5 * sin(solAngle);
		y1 = 0.5 * cos(solAngle);

		cout << "Case #" << cc + 1 << ":\n";
		printf("%.10f %.10f %.10f\n", x0, y0, z0);
		printf("%.10f %.10f %.10f\n", x1, y1, z1);
		printf("%.10f %.10f %.10f\n", x2, y2, z2);
	}
	return 0;
}


라지는 이렇게 통과함
와이어프레임으로 정사영 시켰을때를 생각하면 이해하기 쉬울 거임
#include <cstdio>
#include <queue>
#include <iostream>       
#include <string>
#include <vector>
#include <fstream>        
#include <functional> 
#include <algorithm>  
#include <cstdlib>    
#include <cstring>    
#include <map>        
#include <iomanip>    
#include <limits> 
#include <unordered_map>
#include <set>
#include <cmath>
#include <numeric> //accumulate
#include <stack>
#include <bitset>

//#include <unordered_set>//unordered_set

#define rep(i,a) for (int i = 0; i < (a); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define PI 3.14159265359

using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<int, pair<int, int>>> vpiii;
typedef vector<vector<int>> vvi;
typedef const vector<int> cvi;
typedef vector<bool> vb;

//const ll INF = 1ull << 61;
//const int INF = 1987654321;
const int INF = 2147483647;
//const int INF = 1587654321;
//const int INF	= 987654321;
const double eps = 0.0000000001;

vector<vector<double>> getRotYMat(double yRot) {
	vector<vector<double>> mat(3, vector<double>(3, 0.0));
	mat[0][0] = cos(yRot);
	mat[0][2] = sin(yRot);
	mat[1][1] = 1;
	mat[2][0] = -sin(yRot);
	mat[2][2] = cos(yRot);
	return mat;
}
vector<vector<double>> getRotZMat(double zRot) {
	vector<vector<double>> mat(3, vector<double>(3, 0.0));
	mat[0][0] = cos(zRot);
	mat[0][1] = -sin(zRot);
	mat[1][0] = sin(zRot);
	mat[1][1] = cos(zRot);
	mat[2][2] = 1;
	return mat;
}
vector<double> getRotatePoint(vector<vector<double>> mat, vector<double> pt3) {
	vector<double> ret(3, 0);
	ret[0] = mat[0][0] * pt3[0] + mat[0][1] * pt3[1] + mat[0][2] * pt3[2];
	ret[1] = mat[1][0] * pt3[0] + mat[1][1] * pt3[1] + mat[1][2] * pt3[2];
	ret[2] = mat[2][0] * pt3[0] + mat[2][1] * pt3[1] + mat[2][2] * pt3[2];
	return ret;
}
double getArea(double zTheta) {
	// projectedArea = cos(zTheta) * triangle(:1/2) * 2 + sin(zTheta) * rectangle(:1.414)
	double projectedArea = cos(zTheta) * 1 / 2 * 2 + sin(zTheta) * 2 * cos(PI / 4.0);
	return projectedArea;
}
double binerySearch(double base) {
	double lo = 0.0;
	double hi = PI / 4.0;
	if (fabs(getArea(lo) - base) < eps)
		return lo;
	if (fabs(getArea(hi) - base) < eps)
		return hi;
	int t = 50;
	while (t--) {
		double mid = (lo + hi) / 2;
		if (base <= getArea(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	for (int cc = 0; cc < cs; ++cc) {
		// projectedArea = cos(zTheta) * triangle(:1/2) * 2 + sin(zTheta) * rectangle(:1.414)
		// binery search
		double area; cin >> area;
		double piDiv4 = PI / 4.0;	// 45 degree
		double solZAngle = binerySearch(area);

		vector<double> pt3_0 = { 0.5, 0, 0 };
		vector<double> pt3_1 = { 0, 0.5, 0 };
		vector<double> pt3_2 = { 0, 0, 0.5 };
		vector<vector<double>> rotYMat = getRotYMat(piDiv4);
		vector<double> pt3_YRot_0 = getRotatePoint(rotYMat, pt3_0);
		vector<double> pt3_YRot_1 = getRotatePoint(rotYMat, pt3_1);
		vector<double> pt3_YRot_2 = getRotatePoint(rotYMat, pt3_2);

		vector<vector<double>> rotZMat = getRotZMat(solZAngle);
		vector<double> pt3_ZYRot_0 = getRotatePoint(rotZMat, pt3_YRot_0);
		vector<double> pt3_ZYRot_1 = getRotatePoint(rotZMat, pt3_YRot_1);
		vector<double> pt3_ZYRot_2 = getRotatePoint(rotZMat, pt3_YRot_2);


		cout << "Case #" << cc + 1 << ":\n";
		printf("%.10f %.10f %.10f\n", pt3_ZYRot_0[0], pt3_ZYRot_0[1], pt3_ZYRot_0[2]);
		printf("%.10f %.10f %.10f\n", pt3_ZYRot_1[0], pt3_ZYRot_1[1], pt3_ZYRot_1[2]);
		printf("%.10f %.10f %.10f\n", pt3_ZYRot_2[0], pt3_ZYRot_2[1], pt3_ZYRot_2[2]);
	}
	return 0;
}

소스 설명: y축으로 45도 회전 시키고 z축으로 회전해서 답을 찾는다.
 z축 회전은 45도가 최대값을 가지니까 거기까지 증가 함수라서 바이너리 서치를 적용한다.
 // 문제점: z축 회전 45도가 최대값을 가지는게 아니다.!!!!
 // 46도가 약간 더 크다.
 // 정사영된 그림자가 regular hexagon 정육각형 이 되어야 넓이가 가장 크다.
 // 삼각형쪽 모서리변: square( (root(2)/2)^2 + (cos(theta)*(root(2)/2))^2 )
 // 사각형의 모서리변: sin(theta)
 // 두 변의 길이가 같은 theata 를 구하려면... 
 // ㅅㅂ 귀찮다. 삼분서치로 찾자..
The cube shadow theorem // 뭔가 검색하고 싶으면 키워드단어에 theorem 을 넣어보세!!!!

코드잼 R1 A 
1번 문제
https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard
Waffle Choppers

2차원 보드가 주어지고 거기에 초코칩이 있는 상태에서
가로로 칼질을 v번 수행하고 세로로 칼질을 h번 수행 한 상태에서 각
구간에 남은 초코칩이 모두 같을수 있는가 판단하는 문제36

-> 가로로 칼질을 해서 "모든 초코칩 / (v + 1)" 이 나누어 떨어지고
&& 가로로 잘린 부분들이  "모든 초코칩 / (v + 1)" 만큼의 초코칩을 가져야 하고

-> 세로로 칼질을 해소 "모든 초코칩 / (h + 1)" 이 나누어 떨어지고
&& 세로로 잘린 부분들이 "모든 초코칩 / (h + 1)" 만큼의 초코칩을 가져야 한다.

그리고 마지막으로 각 가로 세로 잘린 부분들이 "모든 초코칩 / ((v + 1) * (h + 1))" 만큼의 초코칩을
가져야 한다 !!!!
void setPsumC(vi& psum, vs& board) {
	vi arr(psum.size(), 0);
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < board.size(); ++j)
			if (board[j][i] == '@')
				arr[i]++;
	}
	psum[0] = arr[0];
	for (int i = 1; i < psum.size(); ++i) {
		psum[i] = psum[i - 1] + arr[i];
	}
	psum = arr;
}
void setPsumR(vi& psum, vs& board) {
	vi arr(psum.size(), 0);
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j)
			if (board[i][j] == '@')
				arr[i]++;
	}
	psum[0] = arr[0];
	for (int i = 1; i < psum.size(); ++i)
		psum[i] = psum[i - 1] + arr[i];
	psum = arr;
}

bool check(vi col, vi row, vs& board, int base) {
	rep(i, col.size())
		rep(j, row.size()) {
		int bR, eR, bC, eC;
		if (i == 0) bC = 0;
		else bC = col[i - 1] + 1;
		eC = col[i];

		if (j == 0) bR = 0;
		else bR = row[j - 1] + 1;
		eR = row[j];

		int tmp = 0;
		for (int ii = bR; ii <= eR; ++ii) {
			for (int jj = bC; jj <= eC; ++jj)
				if (board[ii][jj] == '@')
					tmp++;
		}
		if (tmp != base)
			return false;
	}
	return true;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	rep(cc, cs) {
		int r, c, h, v;
		cin >> r >> c >> h >> v;
		vs board(r);
		rep(i, r) cin >> board[i];
		int cnt = 0;
		rep(i, r) rep(j, c) if (board[i][j] == '@') cnt++;
		if (cnt == 0) {
			cout << "Case #" << cc + 1 << ": POSSIBLE\n";
			continue;
		}
		int totalPiece = (h + 1) * (v + 1);
		int hPieces = (h + 1);
		int vPieces = (v + 1);
		bool ok = true;
		if ((cnt % totalPiece) != 0)
			ok = false;

		vi psumC(c);
		setPsumC(psumC, board);

		vi psumR(r);
		setPsumR(psumR, board);


		int baseCntC = cnt / (v + 1);
		if (baseCntC * (v + 1) != cnt)
			ok = false;
		int proc = 0;
		vi pc;
		for (int i = 0; i < c; ++i) {
			proc += psumC[i];
			if (baseCntC == proc) {
				proc = 0;
				pc.push_back(i);
			}
			else if (baseCntC < proc) {
				ok = false;
			}
		}

		int baseCntR = cnt / (h + 1);
		if (baseCntR * (h + 1) != cnt)
			ok = false;
		proc = 0;
		vi pr;
		for (int i = 0; i < r; ++i) {
			proc += psumR[i];
			if (baseCntR == proc) {
				proc = 0;
				pr.push_back(i);
			}
			else if (baseCntC < proc) {		// 요거 오타나서 틀린듯하다....
				ok = false;
			}
		}

		if (ok) {
			ok = check(pc, pr, board, cnt / totalPiece);
		}
		if (ok == true)
			cout << "Case #" << cc + 1 << ": POSSIBLE\n";
		else
			cout << "Case #" << cc + 1 << ": IMPOSSIBLE\n";
	}
	return 0;
}

// 한글 주석을 못달게 하니 너무 힘드네. 코드잼 2018...
// 한글 주석 달고나서 제거하든지 하자. 주석을 안적으면서 진행하면 무지 에로사항이 많았다..!!!!


2번 문제

https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard/000000000002fff6
Bit Party

로봇 R 개
캐나다식 파티는 매우 심플
B bits : 지역에서 발견되는 작은 도넛형 음식인 bits
로봇이 가능한 모든 비트를 구입할 수 있도록 돕고 싶다.


슈퍼는 C 명의 계산원이 있다.

accept a maximum of Mi items per customer ? 

고객당 Mi 아이템 중 최대값을 수용
각 아이템은 Si 초 걸림
Pi 초가 더 걸림 (지불처리랑 포장에)


로봇 에 할당할 bits 의 양을 니가 바꿀 수 있다.
bits 는 쪼개지지 못함

두 로봇이 하나의 캐시어를 사용 못함
또한 한 로봇은 한명의 캐시어만 사용함



bits 를 가장 많이 처리할 수 있는 시간을 구하라.

각 캐시어의 처리 능력은 다음과 같다.
N bits 처리 시간 = si * N + pi // 단 N 은 mi 를 넘지 않는다.

ex)
0번 캐시어가 (m0: 4, s0: 3, p0: 5) 
10 bits 처리하는데 걸리는 시간
= (s0 * m0 + p0) * (10 / m0)
+ (s0 * (10 % m0) + p0) * (10 % m0);



vll mi, si, pi;
ll ok2(ll bit, ll second, int i) {	// 물건 갯수 주고 시간 되는지 확인
	ll a = (si[i] * mi[i] + pi[i]) * (bit / mi[i]);
	ll b = (si[i] * (bit % mi[i]) + pi[i]) * ((10 % mi[i]) > 0 ? 1 : 0);
	ll total = a + b;
	if (total <= second) return true;
	return false;
}
ll bs2(ll second, int idx) {	// second 시간에 대한 처리갯수 찾기(직접 수식을 유도 못해서 이짓을 또하네...ㅠㅠ)
	int test1 = ok2(1, 5, 0);
	ll lo = 0, hi = 1000000009;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (!ok2(mid, second, idx)) // 해당 할당양을 못채우면 hi = mid, 그렇지 않으면 lo = mid;
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}
bool ok(ll bit, ll second, ll cntR) {
	ll test1 = bs2(5, 0);
	ll test2 = bs2(5, 1);
	int n = mi.size();
	ll sum = 0;
	vll sorted;
	for (int i = 0; i < n; ++i) {
		ll add = bs2(second, i);	// second 만큼 시간내에 캐시어가 처리 가능한 bit 수를 구한다.
		sorted.push_back(add);
	}
	sort(sorted.begin(), sorted.end(), greater<ll>());
	for (int i = 0; i < cntR; ++i) {
		sum += sorted[i];
	}
	if (sum >= bit) return true;
	return false;
}
ll bs(ll bit, ll cntR) {
	ll lo = 0, hi = 1000000006;
	bool test = ok(bit, 5, cntR);	// 시간을 구한다.
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (ok(bit, mid, cntR))		//mid 시간내 bit 만큼 처리가 가능하냐?
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		mi.clear(); si.clear(); pi.clear();
		ll r, b, c;
		cin >> r >> b >> c;
		mi.resize(c); si.resize(c); pi.resize(c);
		rep(i, c) {
			cin >> mi[i] >> si[i] >> pi[i];
		}
		ll sol = bs(b, r);
		cout << "Case #" << cc + 1 << ": "<< sol << '\n';
	}
	return 0;
}


// 1시간 30분이 남았는데도 못 푼 이유(바이너리 서치로 접근한다고 생각하고 1시간 10분이나 남았다...ㅠㅠ)
// 첫번째 바이너리 서치는 구했는데 각 캐시어가 정해진 시간에 얼마나 만들지 계산하는 수식을 
// 직접 만든다고 시간을 다보냄.. 결국 그것도 바이너리 서치로 편하게 갔으면 됬는데.. 아쉽다.

"억지로 수식 만들바에 바이너리서치를 내부에서 다시 돌려라!!!!" 



// 한글 주석 한번에 지우기 !!!! 코드잼2018 대비.. 
https://stackoverflow.com/questions/3885723/how-to-delete-all-comments-in-a-selected-code-section?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
VS 의 정규식 바꾸기를 쓰자.

0. 먼저 다른 빌드안되는 문서에다가(ascii로 된) 붙여넣기 하고
1. ctrl + shift + h 를 누르자
2. 찾을 내용에 //.* 를 넣자
3. 바꿀 내용은 비워둔다.
4. 찾는 위치는 현재문서로 한다.
5. 찾기옵션에 정규식 사용을 체크
6. 모두 바꾸기를 누른다.


// 기타 유용한 스킬
뱀부 로그가 깨진현상 처리: 크롬 확장 프로그램 'Charset' 설치 후 거기 옵션에 현재 페이지를 유니코드 (UTF-8) 로 변경하라. // 매우 유용
뱀부 로그가 \n 이 개행문자 처리가 되지 않고 연결되어 나타난 부분들 보기 쉽게 하기
	vs code 를 연다. -> ctrl + h -> 정규식 아이콘 클릭 -> "\\n 검색" , "\n" 대치 -> all 

// cout 포멧 format !!!!!
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	rep(cc, cs) {
		int h, w, n;
		cin >> h >> w >> n;
		n--;
		int a = n % h;
		a++;

		int b = n / h;
		b++;

		cout.fill('0');
		int tmp = h;
		int width = 0;
		while (tmp) {
			tmp /= 10;
			width++;
		}
		cout.width(width);
		cout << a;

		tmp = w;
		width = 0;
		while (tmp) {
			tmp /= 10;
			width++;
		}
		cout.width(width);
		cout << b << endl;
	}
	return 0;
}



BOJ 행렬 스택 문제: !!!! 좋은 문제
										8
			4				6		7	7	7
		3	3	3		5	5	5	5	5	5	5
	2	2	2	2	2	2	2	2	2	2	2	2	2		
1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	

+	+	+	+	-	-	+	+	-	+	+	-	-	-	-	-


즉 pop 하는 순서가 input 임
stack 에 숫자들을 쌓고 input의 front들과 동일한지 봐서 동일하면 pop 하는 식으로 처리
다 돌리고 나서도 stack 에 찌꺼기가 있다면
불가능 



현재 시간 출력예시!!!!!!!!
#include <ctime>
int main() {
	// 참고: 주의점들 http://hurderella.tistory.com/76
	tm * t;
	time_t timer;
	timer = time(NULL);
	//t = gmtime(&timer);	// 기준시간
	t = localtime(&timer); // 서울시간: utf+9
	printf("%d-%02d-%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	
	return 0;
}
2018-05-29 로 출력된다.







금일 배운거
// 세점 삼각형 넓이
double triArea(double x1, double y1, double x2, double y2, double x3, double y3) {
	double tmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if (tmp < 0) tmp *= -1;
	return tmp / 2.0;
}
// 사각형안에 점이 존재하는지 판단하는 것
https://math.stackexchange.com/questions/190111/how-to-check-if-a-point-is-inside-a-rectangle
bool checkIn(vpll& square, bool dig, double x, double y) {
	double apd = triArea(square[0].first, square[0].second,
						x, y,
						square[3].first, square[3].second);
	double dpc = triArea(square[3].first, square[3].second,
		x, y,
		square[2].first, square[2].second);
	double cpb = triArea(square[2].first, square[2].second, x, y, square[1].first, square[1].second);
	double pba = triArea(x, y, square[1].first, square[1].second, square[0].first, square[0].second);
	double sum = apd + dpc + cpb + pba;
	
	double minX = 1000000;
	double maxX = -1000000;
	double minY = 1000000;
	double maxY = -1000000;

	double squareArea = triArea(square[0].first, square[0].second,
		square[1].first, square[1].second,
		square[2].first, square[2].second) +
		triArea(square[0].first, square[0].second,
			square[2].first, square[2].second,
			square[3].first, square[3].second);
	if (sum <= squareArea + eps)
		return true;
	return false;
}

http://codeforces.com/contest/994/problem/C 문제해석을 잘못했음...ㅠㅠㅠㅠㅠㅠㅠㅠ

http://codeforces.com/contest/994/problem/B
기사들은 자신보다 낮은 power 를 최대 k 개 만큼 잡아 먹을 수 있다.
기사의 수: 100000
k : 최대 10
기사가 소지한 금액인 c[i] 를 거둬들인다.
각 기사가 최선을 다할때 최대 재산은 얼마가 되는가?

고민1: k가 10이 아니라 정말 큰 값이 온다면 어떻게 처리하면 좋을까 : 거기까지 생각해서 짜봄

input
4 2
4 5 9 7
1 2 11 33
output
1 3 46 36

input
5 1
1 2 3 4 5
1 2 3 4 5
output
1 3 5 7 9

input
1 0
2
3
output
3

내소스: 정렬 후 k개를 넣을 수 있는 공간에다가 소지금액이 많은 것들만 집어넣으며 진행한다.
void update(multiset<ll>& sets, ll add, int k) {
	if (k == 0) return;
	multiset<ll>::iterator it = sets.begin();
	if (sets.size() == k) {
		if (*it < add) {
			sets.erase(it);
			sets.insert(add);
		}
	}
	else
		sets.insert(add);
}
ll getSum(multiset<ll>& sets) {
	multiset<ll>::iterator it = sets.begin();
	ll ret = 0;
	for (; it != sets.end(); ++it) {
		ret += *it;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vll arr(n);
	vll crr(n);
	
	rep(i, n) cin >> arr[i];
	rep(i, n) cin >> crr[i];
	vector<pair<ll, ll>> pArr(n);
	for (int i = 0; i < n; ++i) {
		pArr[i].first = arr[i];
		pArr[i].second = i;
	}
	sort(pArr.begin(), pArr.end());
	multiset<ll> sets;
	vector<ll> sol(n);
	for (int i = 0; i < pArr.size(); ++i) {
		int idx = pArr[i].second;
		ll cost = crr[idx];
		ll power = pArr[i].first;
		ll sum = getSum(sets);	//  앞에 합쳐진것들
		sol[idx] = sum + cost;
		update(sets, cost, k);
	}
	for (int i = 0; i < sol.size(); ++i)
		cout << sol[i] << " ";
	return 0;
}


http://codeforces.com/contest/994/submission/39296659
jkJoeng 의 소스. 답이 int  를 넘길거 같다만.. long long 이였다. 햇갈리게 했넹 ㅋㅋ
나랑 비슷하며 sort 에 걸리는 시간이 매우 작아서 그냥 sort 로 처리하였다.
sort 하는 방법이 편해서 좋네!!!!

int n, k, W[10];	// 여기다 있으면 디버깅이 편하다만..
struct P{ int p, c, id, w; } a[100010];
ll f(void) {
	ll ret = 0;
	for (int i = 0; i < k; ++i)
		ret += W[i];
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i].p, a[i].id = i;
	for (int i = 0; i < n; ++i) cin >> a[i].c, a[i].w = a[i].c;
	sort(a, a + n, [](P x, P y) {
		if (x.p == y.p) return x.c > y.c;
		return x.p < y.p;
	});
	for (int i = 0; i < n; ++i) {
		a[i].w += f();
		if (W[0] < a[i].c) W[0] = a[i].c;
		sort(W, W + k);
	}
	sort(a, a + n, [](P x, P y) {
		return x.id < y.id;
	});
	for (int i = 0; i < n; ++i) cout << a[i].w << " ";
	return 0;
}

// 통과소스
struct Point { ll p, c, id, w; } arr[100100];
ll subSum(int k, int* w) {
	ll ret = 0;
	for (int i = 0; i < k; ++i)
		ret += w[i];
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k, w[10];
	memset(w, 0, sizeof(w));
	cin >> n >> k;
	rep(i, n) cin >> arr[i].p, arr[i].id = i;
	rep(i, n) cin >> arr[i].c, arr[i].w = arr[i].c;
	sort(arr, arr + n, [](Point x, Point y) {
		return x.p < y.p;
	});
	for (int i = 0; i < n; ++i) {
		arr[i].w += subSum(k, w);
		if (w[0] < arr[i].c) w[0] = arr[i].c;
		sort(w, w + k);
	}
	sort(arr, arr + n, [](Point x, Point y) {
		return x.id < y.id;
	});
	for (int i = 0; i < n; ++i) cout << arr[i].w << " ";
	return 0;
}



20181117
http://codeforces.com/contest/1077/problem/D
k개의 숫자들을 한 더미로 만들고 그걸 반복적으로 s에서 제거한다면
최대 반복은 t 번 걸릴거다.
이때 그 제거하는 더미를 구하라. 
s = [1, 2, 3, 2, 4, 3, 1] and k = 3
sol = [1, 2, 3]

s = [1, 2, 3, 2, 4, 3, 1]
	=>	[2, 4, 3, 1]
		=> [1]
k가 3일때 최대 반복 횟수는 2가 된다.

10 4
1, 3, 1, 3, 10, 3, 7, 7, 12, 3
sol = [7, 3, 3, 1]

15 2
1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 1
sol = [1, 1] // 아 골때린다.

고찰
a가 1개
b가 2개
c가 4개
d가 6개
인 경우 k가 3이면

a, b, c, d
1, 2, 6, 10
c, d, d 로 5회 반복이 된다.
바이너리 쓰면 되겠네.... 너무 피곤했네 ㅅㅂ 바보!!!!!!!!

lo = 1, hi = n + 1;	// lo 는 가능, hi = 불가능
mid = (lo + hi) / 2;	// mid 횟수만큼 반복 가능한가

while (lo + 1 < hi) {
	mid = (lo + hi) / 2;
	judge = check(mid);
	if (judge == true) 
		lo = mid;
	else
		hi = mid;
}
ret = lo;
ret 는 최대 가능 횟수가 나옴.

각 요소로부터 ret 개 뽑아내면 된다.
만약 a[i]가 ret 의 2배 이상이면
나눠처리하자.


다시 정리하자면 먼저 최대 반복횟수를 구한다.
그걸로 답을 만들어내면 된다. 난 왜 이걸 대회땐 못풀었을까... 끝나고 나서 생각나네 




20181119 : 이번 라운드는 무효판이 되었다.
http://codeforces.com/contest/1079/problem/C
손가락 건반 움직이기

고려사항
5 4 3 2 1 1 2 3 4 5	// 좆망케이스
두번째 1에서 바로전 건반이 1이고 손가락도 1이면 답이 존재 못함

5 4 3 2 1 1 1 2 3 4 5	// 가운데 1은 손가락이 2~4가 되어야 한다.




// http://codeforces.com/contest/1093/problem/D  : 아아 억울하다 ㅠㅠㅠㅠㅠㅠㅠㅠ!!!!!!!!!!
memset 은 결코 비용이 공짜가 아니다. 빠르긴 하지만 시간복잡도가 O(n) 이다.
30만개 memset 하는데 0.5 ms 걸린다고 생각하자.
그걸 30만번 한다면 15초 걸리겠지...

문제 내용: 각 간선에 연결된 양 정점에 매겨진 숫자(1, 2, 3중 하나)의 합이 모두 홀수가 되도록 번호를 매긴다고 할때
그 경우의 수를 구하여라

접근법
홀수: 1, 3
짝수: 2

사이클이 생기고 그 사이클이 홀수개의 점으로 이루어 져 있으면 두 정점의 합이 짝수가 되는 지점이 반드시 존재
1번		2번		3번	  1번	
홀수 - 짝수 - 홀수 - 홀수
1		2		3		4	 1
홀수 - 짝수 - 홀수 - 짝수 - 짝수

칼라링 문제라 보면 된다.
단 홀수는 종류가 두개이기 때문에
	홀수로 칠해지는 점의 수 -> pow(2, 홀수로 칠해지는 점의 수)

게다가 시작지점이 반대면 모든 칼라링 한 색도 반대가 되므로
짝수로 칠해지는 점의 수를 다시 홀수 취급해서 계산한다.
	pow(2, 짝수로 칠해지는 점의 수)

게다가 그래프가 모두 하나로 이어져 있지 않기 때문에
서로 독립되어 있으므로 각각을 곱해주어야 한다.

나의 문제점은 memset 이 거의 상수라고 생각했던 점이 었다.	
// memset 은 매우 최적화가 잘되어 있지만 
// 걸국 time complexity 는 O(n) 이다.
// 30만개를 초기화 하는데 약 0.5 ms 가 걸린다 해도
// 그걸 30만번 수행하면 15초가 된다...ㅠㅠ
	int color[300300];
	clock_t begin, end;
	begin = clock();
	for (int i = 0; i < 300300; ++i) 
		memset(color, 0, sizeof(color));
	end = clock();
	double ms = double(end - begin) / CLOCKS_PER_SEC;	
	cout << "걸린시간(초) : " << ms << '\n';	// 내컴퓨터로 릴리즈모드에서 15초 걸림

테스트 상의 모든 점들의 갯수는 30만개를 넘지 않는다고 되어 있다.
따라서 memset(30만 사이즈) 를 취하지 말고
vector<int> color 	
vector<bool> vstd
를 사용해야 했다... ㅠㅠ ㅆㅂ
	
const long long mod = 998244353;
vi graph[300300];
int color[300300];
bool vstd[300300];
bool judge;
ll oddCnt;
ll evenCnt;
int n, m;
void dfs(int here, int prnt, int val) {
	vstd[here] = true;
	color[here] = val;
	if (val % 2 == 1)	// 홀수이면
		oddCnt++;
	else
		evenCnt++;
	for (int i = 0; i < graph[here].size(); ++i) {
		int nxt = graph[here][i];
		if (nxt == prnt) continue;	// 직속부모
		if (vstd[nxt] == true) {
			if (color[nxt] == color[here])
				judge = false;
			continue;
		} 
		int nxtVal = val;
		if (val % 2 == 1)
			nxtVal = 2;
		else
			nxtVal = 1;
		dfs(nxt, here, nxtVal);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int T; cin >> T;
	while (T--) {
		memset(color, 0, sizeof(color));		// 문제가 되었던 부분
		memset(vstd, 0, sizeof(vstd));			// 문제가 되었던 부분
		judge = true;
		oddCnt = 0;
		cin >> n >> m;
		for (int i = 0; i <= n; ++i)
			graph[i].clear();

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		ll sol = 1;
		for (int i = 1; i <= n; ++i) {
			if (vstd[i] == true) continue;
			oddCnt = 0;
			evenCnt = 0;
			dfs(i, -1, 1);
			ll cnt = 1;
			for (int i = 0; i < oddCnt; ++i) {
				cnt *= 2;
				cnt %= mod;
			}
			oddCnt = evenCnt;
			ll cnt2 = 1;
			for (int i = 0; i < oddCnt; ++i) {
				cnt2 *= 2;
				cnt2 %= mod;
			}
			ll localSol = (cnt + cnt2) % mod;
			sol *= localSol;
			sol %= mod;
		}
		if (judge == false) {
			cout << 0 << '\n';
			continue;
		}
		cout << sol << '\n';
	}
	return 0;
}




















