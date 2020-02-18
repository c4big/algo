
//계산기 사이트
https://www.functions-online.com/atan2.html

//TCO 2015 Round 1B DIV1
//250점 짜리
/*
	문제 간단 해석
	어떤 int 벡터를 인자로 받는 함수
	각 인자의 크기는 1에서 1000을 가지며 벡터의 사이즈는 최대 50이 된다.
	각 인자들을 나누어 떨어지게 하는 숫자 v(1 < v)가 존재한다고 할때
	특정 구간 i ~ j 상에서 v에 의해 나누어 떨어지는 갯수가 구간의 크기(j - i + 1) 의 절반 이상임을
	만족하는 j - i의 최대 값을 구해라

	이문제를 대회때 못 풀었던 이유
	시간복잡도 오천만번은 타임 오류날것 같아 겁이 나서 다른 빠른 방법이 없나 고민해서 못품
	최대 복잡도는 1000 * 50 * 50 이므로 충분히 돌아감
	이 문제를 해석 잘못하여 50 * 1000 * 1000 으로 시간 복잡도를 해석함
	허나 이 정도라도 2초내에 충분히 돌아감
*/

#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>	//TCO 컴파일러에서는 memset할때 이걸 인클루드 시켜야 되넹...
using namespace std;

int arr[1000][50]; //TCO 전역변수 사용가능하구나
class TheNicePair {
public:
	int solve(vector<int> A) {
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i < 1000; ++i) {
			for (int j = 0; j < A.size(); ++j) {
				if (A[j] % (i + 1) == 0)
					arr[i][j] = 1;
			}
		}
		int ret = -1;
		for (int i = 1; i < 1000; ++i) {
			for (int j = 0; j < A.size(); ++j) {
				int oneCnt = 0;
				for (int k = j; k < A.size(); ++k) {
					if (arr[i][k] == 1) oneCnt++;
					if (oneCnt * 2 >= (k - j + 1))
						ret = max(ret, k - j);
				}

			}
		}
		return ret;
	}
};
void main() {
	vector<int> A = { 8, 8, 5, 5, 5 };
	TheNicePair test;
	int ret = test.solve(A);
}


http://codeforces.com/contest/540/problem/B
//n, k, p, y, x : 
//전체테스트 수, 현재까지의 점수의 갯수, 한 테스트당 최대점수, 점수의 합이 y를 넘기면 안됨, 중간값이 x이상은 되어야함
//전체테스트는 항상 홀수임 즉 중간값은 (n + 1) / 2 번째의 값
//n1, n2, ..., nk : 현재까지의 점수들
//y 조건과 x조건 둘다 만족시키지 못하면 -1을 리턴
//둘다 만족하면 아무 답이나 오케이
//내가 틀린 이유 : 너무 성급하게 판단하여 예외처리를 고려하지 못한 부분이 발생하였다.
void main() {
	int yOver = 0;
	int yLower = 0;
	int sum = 0;
	int n, p, k, x, y;
	cin >> n >> p >> k >> x >> y;
	for (int i = 0; i < p; ++i) {
		int num;
		cin >> num;
		sum += num;
		if (y <= num) yOver++;
		else yLower++;
	}
	if (yOver >(n + 1) / 2) { //내가 빠뜨린것..기존의 숫자만 가지고 최소중간값을 결정가능
		sum += (n - p); //1로 더해준다
		if (sum > x)
			cout << -1 << endl;
		else {
			for (int i = 0; i < n - p; ++i)
				cout << 1 << " ";
		}
	}
	else {
		int needYOver = (n + 1) / 2 - yOver; 
		//전체 수가 7개, 중간값이 3인경우 1 1 1 1 1 3 3
		int remainNums = n - p;
		if (remainNums < needYOver) { //내가 빠뜨린것..
			cout << -1;
		}
		else {
			sum += needYOver * y + remainNums - needYOver;
			if (sum > x)
				cout << -1 << endl;
			else {
				for (int i = 0; i < needYOver; ++i)
					cout << y << " ";
				for (int i = 0; i < remainNums - needYOver; ++i)
					cout << 1 << " ";
			}
		}
	}
	//문제를 푸는데 너무 방심해서 확실한 체크를 하지 못했다.
	//1 1 1 1 1 이런식의 숫자 테스트를 했어도...
}

http://codeforces.com/contest/540/problem/C
//코드포스 301div2 C 얼음동굴
//목적지에 도달할때 X이면 성공
//목적지에 도달할때 .이면 X로 만든다음 다시 도달하면 성공
//시작점도 X가 된 상태임
/*
4 7
..X.XX.
.XX..X.
X...X..
X......
2 2
1 6
*/
vector<string> board;
int cache[501][501][2];
int sy, sx, dy, dx;	//-1해서 저장한다.
int n, m;

int dfsBug(int y, int x, int firstVisit) {
	if (y < 0 || y >= n || x < 0 || x >= m) return 0;
	if (!(y == sy && x == sx))
		if (!(y == dy && x == dx))
			if (board[y][x] == 'X') return 0;
	if (y == dy && x == dx && board[y][x] == 'X') return 1;
	if (y == dy && x == dx && board[y][x] != 'X') firstVisit = 1;

	
	int& ret = cache[y][x][firstVisit];
	if (ret != -1) return ret;

	board[y][x] = 'X';
	
	ret = 0;
	if (dfsBug(y - 1, x, firstVisit)) ret = 1;
	if (dfsBug(y + 1, x, firstVisit)) ret = 1;
	if (dfsBug(y, x - 1, firstVisit)) ret = 1;
	if (dfsBug(y, x + 1, firstVisit)) ret = 1;

	return ret;
}
//int cache2[501][501];
//문제 해석을 잘 못한 순간 새로 짜는게 더 빠르고 정확할 수 있다는 것을 명심하자.
//버그 코드때 나는 정신적 공항상태로 너무 땜질만 하려고 했다.
//정리를 다시 하고 차분히 새로 짜는게 더 좋구나..
vector<string> board;
int cache[501][501][2];
int sy, sx, dy, dx;	//-1해서 저장한다.
int n, m;
int dfs(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return 0;
	if (y == dy && x == dx) {
		if (board[y][x] == 'X') return 1;
		else board[y][x] = 'X';
	}
	else if (board[y][x] == 'X') return 0;
	board[y][x] = 'X';
	//캐쉬는 사실 필요없다. 재사용되는 것 없으며 한놈만 true면 모든게 종료되므로
	//길의 갯수를 구한다면 필요할지도 모르지만 ㅎㅎ
	//일단 dfs는 정점수 * 엣지수의 복잡도이며 500 x 500 좌표에서
	//정점 250000에 각 정점당 4개의 엣지만 고려하면 되므로 250000 * 4의 복잡도를 가짐
	//테스트 수행시 500 x 500에서 30ms내에 대부분 수행 완료되었음
	//int& ret = cache2[y][x]; 
	//if (ret != -1) return ret;
	
	int ret = 0;
	if (dfs(y - 1, x)) ret = 1;
	if (dfs(y + 1, x)) ret = 1;
	if (dfs(y, x - 1)) ret = 1;
	if (dfs(y, x + 1)) ret = 1;
	return ret;
}

void main() {
//	int firstVisit = 0;
	//memset(cache2, -1, sizeof(cache2));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		board.push_back(str);
	}
	cin >> sy >> sx >> dy >> dx;
	sy--; sx--; dy--; dx--;
//	if (board[dy][dx] == 'X')
//		firstVisit = 1;
	board[sy][sx] = '.';
	//int ret = dfs2(sy, sx, firstVisit);
	int ret = dfs(sy, sx);
	if (ret == 1)
		cout << "YES" <<endl;
	else
		cout << "NO" <<endl;
}


https://code.google.com/codejam/contest/8224486/dashboard#s=p0&a=2
Problem A. Counter Culture
//코드잼 2015 Round 1B a : 숫자를 n이 되도록 한다 숫자는 1증가 , 혹은 뒤집기 둘중 하나의 액션을 취한다.
//small = 10^6, large = 10 ^ 14
//나의 문제점 : 초반에 긴장하여 2시간동안 수의 변화 법칙을 깨닫지 못했다.
//자릿수가 하나 없어질 때마다 뒤집기는 1번이하만 수행되어야 한다.
200000 -> 199001 -> 100991 -> 100000 -> 99999 : 뒤집기 한번 수행
99999 -> 99001 -> 10099 -> 10000 -> 9999 : 뒤집기 한번 수행

99999 에서 1000의 나머지를 빼고 1을 더하여 99001을 만든다
뒤집어서 10099를 만든다
10099 에서 1000의 나머지를 빼서 10000을 만든다
10000에서 1을 빼서 9999를 만든다.

예외 1001의 경우 뒤집은 숫자가 더 크므로 뒤집기를 하면 안된다

	for (int cc = 0; cc < nCase; ++cc) {
		string num;
		cin >> num;
		long long ret = 0;
		while (num != "1") {
			long long temp = atoll(num.c_str());
			long long mod = 10;
			for (int i = 1; i < (num.size()) / 2; ++i)
				mod *= 10;
			long long remainder = temp % mod;
			if (remainder == 0) {
				temp--;
				ret++;
				num = to_string(temp);
				continue;
			}
			temp -= remainder; 
			temp++;
			ret += remainder;//빼기횟수
			ret--;

			if (temp == 1) break;
			
			num = to_string(temp);
			string rNum = num;
			reverse(rNum.begin(), rNum.end());
			
			if (rNum < num) {
				num = rNum;
				ret++;
			}

			temp = atoll(num.c_str());
			remainder = temp % mod;
			temp -= remainder;
			temp--;
			ret += remainder;
			ret++;
			num = to_string(temp);
		}

		cout << "Case #" << cc + 1 << ": " << ret + 1<<  endl;
	}

/*	dp로 무식하게 풀어보자	*/ small만 통과하는 정도로 빠르게 작성하는 능력을 키워보자
// 이 알고리즘은 n이 1000이 넘어가면 호출 스텍이 너무 많이 쌓여 스택오버플로우가 난다.
// 반복적인 형식으로 점화식을 구현해야하나..ㅠㅠ
int n;
int cache[1000001];
int dp(int start) {
	if (start == n) return 1;
	if (start > n) return 987654321;
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = dp(start + 1) + 1;

	string num = to_string(start);
	reverse(num.begin(), num.end());
	start = atoi(num.c_str());
	ret = min(ret, dp(start));
	return ret;
}

//흠 깊이를 줄이면 되겠지.. 안된다. dp2(1) -> dp2(2) ->...->dp2(2000) 호출스택의 깊이가 그대로임
int dp2(int start) {
	if (start == n) return 1;
	if (start > n) return 987654321;
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 987654321;
	for (int add = 1; add < 20; ++add)
		ret = min(ret, dp2(start + add) + add);
	string num = to_string(start);
	reverse(num.begin(), num.end());
	start = atoi(num.c_str());
	ret = min(ret, dp2(start) + 1);
	return ret;
}

//3분 걸린다.. 겨우 통과
int iterCache[1000001];
int iterative(int n) {
	memset(iterCache, -1, sizeof(iterCache));
	iterCache[n] = 1;
	for (int i = n - 1; i >= 1; --i) {
		iterCache[i] = iterCache[i + 1] + 1;
		if (i % 10 == 0) continue;
		string strNum = to_string(i);
		reverse(strNum.begin(), strNum.end());
		int rNum = atoi(strNum.c_str());
		if (strNum[0] != '0')	//i의 1의 자리가 0이 아니고
			if (rNum <= n && rNum > i)	//i를 뒤집은 숫자가 n이하이고 i보다 큰 경우
				iterCache[i] = min(iterCache[i], iterCache[rNum] + 1);
	}
	return iterCache[1];
}

//중요한 사실을 깨달았다!!
//일단 내가 output의 정답 자체를 추측 못하겠다면
//small을 일단 무식하게 짠다음
//large 목표로 했던 코드의 결과와 비교한다.
//small을 무식하게 짜는게 large를 바로 짜는 것보다 검증에 무지 도움된다.

//단순한거 제일 빠르게 구현한것
//20초 만에 small 답을 다 계산
int iterCache2[1000001]; //precalc 형식으로 미리 계산한다
void iterative2(int n) {
	iterCache2[1] = 1;
	for (int i = 2; i <= n; ++i) {
		iterCache2[i] = iterCache2[i - 1] + 1;
		if (i % 10 == 0) continue;
		string rNumStr = to_string(i);
		reverse(rNumStr.begin(), rNumStr.end());
		int rNum = atoi(rNumStr.c_str());
		if (rNum < i) "!!!! : 작은 숫자에서 큰 숫자로 가는 길이 왕도기 때문"
			iterCache2[i] = min(iterCache2[i], iterCache2[rNum] + 1);
		//좌항이 우항보다 작은 경우가 존재하는가?
		//존재한다
		//ca[92] : ca[91] + 1 < ca[29] + 1 : 21 < 22
	}
}
//ca[21] < ca[20]
//ca[92] = 1 + 1 + 19 : 19만큼 증가, 뒤집기, 1증가  == 21
//ca[92] => 29 + 1 => 21 + 8 + 1 => 12 + 1 + 8 + 1 == 22

int dp1[1000001];
int dp2[1000001];
void iter1(int n) {
	dp1[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp1[i] = dp1[i - 1] + 1;
		if (i % 10) continue;
		string rNumStr = to_string(i);
		reverse(rNumStr.begin(), rNumStr.end());
		int rNum = atoi(rNumStr.c_str());
		if (rNum < i)
			dp1[i] = min(dp1[i], dp1[rNum] + 1);
	}
}
void iter2(int n) {
	dp2[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp2[i] = dp2[i - 1] + 1;
		if (i % 10) continue;
		string rNumStr = to_string(i);
		reverse(rNumStr.begin(), rNumStr.end());
		int rNum = atoi(rNumStr.c_str());
		if (rNum < i)	// 당연히 rNum 이 i보다 작다면 dp2[rNum] + 1 은 dp2[i - 1] + 1  보다 무조건 작다.
			dp2[i] = dp2[rNum] + 1;
	}
}
int main() {
	int n = 1000;
	iter1(n);
	iter2(n);
	rep2(i, 1, n + 1) {
		cout << dp1[i] << "\t" << dp2[i] << endl;;
		if (dp1[i] != dp2[i])
			cout << "not equal" << endl;	//안 탄다. 위 두 함수는 똑같다.
	}
	return 0;
}
"a 를 뒤집은 수 b가 a보다 큰 경우에는 dp[a] < dp[b] 임을 항상 보장한다." 몇번 해보면 안다.
// 그렇지 않다면 윗 코드가 성립 안되었겠지.


//2행 n열짜리 정원이 있음
//울타리나 모퉁이가 공유된 나무는 못 자란다.
//현 상태에서 더 심을수 있는 나무와 현 나무의 합을 출력해라
using namespace std;

class DevuAndPlantingTrees
{
public:
	int maximumTreesDevuCanGrow(vector <string> garden) {
		int ret = 0;
		int len = garden[0].size();
		string str(garden[0].size(), '.');
		for (int i = len - 1; i >= 0; --i) {
			if (garden[0][i] == '*' || garden[1][i] == '*') {
				str[i] = '*';
				ret++;
			}
		}

		for (int i = len - 1; i >= 0; --i) {
			if (str[i] == '*') continue;
			bool rOk = false, lOk = false;	//if문을 길게 만들어 오류가 날 바엔 이렇게 쪼개서 하니 편했음
			if ((i + 1) > (len - 1) || str[i + 1] == '.')
				rOk = true;
			if ((i - 1) < 0 || str[i - 1] == '.')
				lOk = true;
			if (rOk && lOk) {
				str[i] = '*';
				ret++;
			}
		}
		return ret;
	}
};

void main() {
	vector<string> garden;
	//garden.push_back("....*.*.*...........*........");
	//garden.push_back("*..........*..*.*.*....*...*.");
	garden.push_back(".......");
	garden.push_back(".*.....");

	DevuAndPlantingTrees test;
	int ret = test.maximumTreesDevuCanGrow(garden);
}


void atanTest() {
	double a0, a1, a2, a3, a4, a5, a6, a7, a8;
	//atan2((double)y, (double)x); 라디안 값 리턴
	a0 = atan2((double)-1, (double)-1) * 180 / PI;	//-135.00000015425999
	a1 = atan2((double)-1, (double)0) * 180 / PI;	//-90.000000102839991
	a2 = atan2((double)-1, (double)1) * 180 / PI;	//-45.000000051419995
	a3 = atan2((double)0, (double)-1) * 180 / PI;	//180.00000020567998
	a4 = atan2((double)0, (double)0) * 180 / PI;	//0.00000000000000000
	a5 = atan2((double)0, (double)1) * 180 / PI;	//0.00000000000000000
	a6 = atan2((double)1, (double)-1) * 180 / PI;	//135.00000015425999
	a7 = atan2((double)1, (double)0) * 180 / PI;	//90.000000102839991
	a8 = atan2((double)1, (double)1) * 180 / PI;	//45.000000051419995
	//	angle = fmod((angle + 360.0), 360.0);
}
http://www.geeksforgeeks.org/counting-inversions/
//O(n^2) 무식한거
int getInvCount(int arr[], int n) {
	int inv_count = 0;
	rep(i,n-1)
		rep2(j,i+1,n)
			if (arr[i] < arr[j])
				inv_count++;
	return inv_count;
}
//인버전
long long getInversionCnt(vd& arr, int left, int right) {
	if (left == right) return 0;
	int mid = (left + right) / 2;
	long long ret = getInversionCnt(arr, left, mid) +
		getInversionCnt(arr, mid + 1, right);
	vd tmp(right - left + 1);
	int tmpIndex = 0, leftIndex = left, rightIndex = mid + 1;
	while (leftIndex <= mid || rightIndex <= right) {
		if (leftIndex <= mid &&
			(rightIndex > right || arr[leftIndex] < arr[rightIndex]))
			tmp[tmpIndex++] = arr[leftIndex++];
		else {
			ret += mid - leftIndex + 1;
			tmp[tmpIndex++] = arr[rightIndex++];
		}
	}
	rep(i, tmp.size())
		arr[left + i] = tmp[i];
	return ret;
}

"https://algospot.com/judge/submission/detail/326462"(외적으로 정렬comp활용 코드)
내가 푼건 통과는 했다만... 각도로 정렬하면 범위가 10000000이 넘어가면 불가능 하지 않을까 싶다.
	test = atan2((double)1, (double)200000);
	test2 = atan2((double)1, (double)199999);
	//2.5000125000094976e-11 차이가 남 엄청 작지만 일단 차이가 발생한다. annitibber를 통과할 수 있었던 이유
	cha = fabs(test - test2);
http://codeforces.com/contest/618/problem/C //atan2각도 정렬했더만 49번 테스트 케이스에서 망함
//좌표 범위가 -10억 ~ 10억 이었음 atan2를 썼을때 동일한 값이 나오더라...

"ANNIETIBBER" 문제
int main() { //슬프다..
	//	angle = fmod((angle + 360.0), 360.0); 를 취할 필요는 없겠다.. 범위는 양수에서 커버치니
	
	//하늘의 점 두개 A, B에 대하여 Apq < Bpq 이면서 Aqp > Bqp 즉 
	//"{ Apx < Bpx && Aqx < Bqx: x는 x축의 임의의 큰 값 }" 인 경우 두 점은 p와 q에서 left, right가 각각 달라 보인다.
	//p와 이루게 되는 각도를 정렬시켜서 순회하면 Apx < Bpx는 자연히 만족함
	//거기에 Aqx 와 Bqx의 대소관계를 비교하여 inversion 이 일어나는 경우의 수를 찾자
	//두개의 조건이 동시에 맞는 경우의 수를 찾는 문제에서 활용할수 있겠네. 좋은 문제다~
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, p, q;
		cin >> n >> p >> q;
		if (p > q) swap(p, q);
		vpii arr(n);
		rep(i, n) cin >> arr[i].first >> arr[i].second; //first:x , second:y
		vector<pair<double, double> > anglePair(n);
		rep(i, n) {
			double dx = arr[i].first - p;
			double dy = arr[i].second;
			double pAngle = atan2(dy, dx) * 180 / PI;

			dx = arr[i].first - q;
			dy = arr[i].second;
			double qAngle = atan2(dy, dx) * 180 / PI;

			anglePair[i] = mp(pAngle, qAngle);
		}
		sort(anglePair.begin(), anglePair.end());
		vd qAngleArr(n);

		rep(i, n) qAngleArr[i] = anglePair[i].second;
		long long sol = getInversionCnt(qAngleArr, 0, n - 1);	//알고스팟통과 320 ms
		cout << sol << endl;
		//이렇게도 풀수 있다.
		/*
		vd qAngleArr2 = qAngleArr;
		sort(qAngleArr2.begin(), qAngleArr2.end());
		map<double, int> m;
		rep(i, n) m[qAngleArr2[i]] = i;
		vi mapping(n);
		rep(i, n) mapping[i] = m[qAngleArr[i]];
		long long sol = countMoves(mapping);	//알고스팟 통과	514ms
		long long sol = countMoves2(mapping);	//알고스팟 통과 594ms
		cout << sol << endl;
		*/
	}
	return 0;
}
struct FenwickTree {
	vi tree;
	FenwickTree(int n) : tree(n + 1) {}
	int sum(int pos) {
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);	//1이 기록된 최하위 비트를 0으로 바꿈
		}
		return ret;
	}
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);	//1이 기록된 최하위 비트에 1을 더함
		}
	}
};
//algospot 에서 돌아가는거 확인했음// A[i] 의 값이 0이라도 돌아갑니다.
long long countMoves(cvi& A) {
	FenwickTree tree(100001);
	long long ret = 0;
	rep(i, A.size()) {
		ret += tree.sum(100000) - tree.sum(A[i]);	// 삽입시 swap 갯수의 합 = inversion 총 갯수
		tree.add(A[i], 1);
	}
	return ret;
}

//아래 방식으로도 돌아갑니다.
typedef int KeyType;
struct Node {
	KeyType key;
	int priority, size;
	Node *left, *right;
	Node(const KeyType& _key) : key(_key), priority(rand()),
		size(1), left(NULL), right(NULL) {}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};
typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key) {
		NodePair rsp = split(root->right, key);
		root->setRight(rsp.first);
		return NodePair(root, rsp.second);
	}
	NodePair lsp = split(root->left, key);
	root->setLeft(lsp.second);
	return NodePair(lsp.first, root);
}
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	if (root->key < node->key)
		root->setRight(insert(root->right, node));
	else
		root->setLeft(insert(root->left, node));
	return root;
}
//root = insert(root, new Node(valud));
int countLessThan(Node* root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int leftSize = (root->left ? root->left->size : 0);
	return leftSize + 1 + countLessThan(root->right, key);
}
void deleteTree(Node* node) {
	if (node == NULL) return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

long long countMoves2(cvi& A) {
	Node* root = NULL;
	long long ret = 0;
	rep(i, A.size()) {
		//{현재까지 쌓인 갯수} - {현재까지 쌓인 것중 A[i]이하의 갯수}
		// = {현재까지 쌓인 것중 A[i]보다 큰 놈의 갯수}
		int treapSize = (root) ? root->size : 0;
		ret += treapSize - countLessThan(root, A[i] + 1);
		root = insert(root, new Node(A[i]));
	}
	deleteTree(root);
	return ret;
}



// 해커컵 1번, 10점짜리: Boomerang constellations
// 디버그 모드에서 map의 사용은 좆됨 6분 초과함
// 릴리즈 모드에서 20초 정도 걸림
// 해커컵은 6분이내에 여러번 제출이 가능하나.. 6분이 지나면 영원히 제출 불가 ㅠㅠ
// ㅅㅂ ㅅㅂ ㅅㅂ ㅅㅂ... 망했어요...

int main() {
	FILE *fp;
	freopen_s(&fp, "boomerang_constellations.txt", "r", stdin);
	//freopen_s(&fp, "input.txt", "r", stdin);

	freopen_s(&fp, "output.txt", "w", stdout);
	int t, n;
	vi xArr, yArr;
	cin >> t;
	rep(cc, t) {
		cin >> n;
		xArr.resize(n); yArr.resize(n);
		rep(i, n) cin >> xArr[i] >> yArr[i];
		long long sol = 0;
		rep(i, n) {
			map<int, int> m;
			rep(j, n)
				if (i != j) {
					int sDist = (xArr[i] - xArr[j]) * (xArr[i] - xArr[j])
						+ (yArr[i] - yArr[j]) * (yArr[i] - yArr[j]);
					if (m.count(sDist) == 0)
						m[sDist] = 1;
					else
						m[sDist] += 1;
				}
			map<int, int>::iterator it;
			long long cnt = 0;
			for (it = m.begin(); it != m.end(); it++) {
				if (it->second >= 2)
					cnt += (it->second * (it->second - 1)) / 2;
			}
			sol += cnt;
		}
		cout << "Case #" << cc + 1 << ": " << sol << endl;
	}
	return 0;
}

해커컵 2번
Laundro, Matt
론드로는 세탁을 좋아함
론드로는 "L"개의 구분할 수 없는 세탁일을 지역세탁소("N"개의 빨래기기와 "M"개의 말리기기가 있음)
에 가지고 갔다.
각 머신은 한번에 하나의 세탁일만을 처리가능하다
하나 예상대로, 론드로맷은 각각을 빨래하고 말리기를 순차적으로 수행되길 원한다.
각 빨래물은 다음 차례를 따른다.

1. 음이아닌 총 시간이 지난 후, 론드로는 세탁물을 빈 세탁기 i에 넣는다.
2. Wi 분이 지나면, 그는 세탁기로 부터 세탁물을 꺼낸다. 임시적으로 바스켓에 놔둔다.
3. 음이아닌 총 시간이 지난 후, 그는 세탁물을 건조기에 넣는다.
4. D분이 지난후 그는 건조기에서 세탁물을 꺼낸다.

맷은 세탁물을 꺼내고 넣는데 걸리는 시간은 0다.


빨래를 끝내는 최소시간을 출력하라

1 ≤ T ≤ 50				//테스트 케이스
1 ≤ L ≤ 1,000,000		//세탁 수
1 ≤ N ≤ 100,000			//빨래기기 수
1 ≤ M ≤ 1,000,000,000	//건조기 수
1 ≤ D ≤ 1,000,000,000	//건조시간
1 ≤ Wi ≤ 1,000,000,000	//각 빨래기기 수행시간

5	//테스트 케이스
1 1 1 34	//L, N, M, D: 세탁 수, 빨래기기 수, 건조기 수, 건조시간
1200		//빨래기기 수행시간
2 3 2 10
100 10 1
3 3 3 3
1 2 3
4 2 2 7
5 8
999 1 999 6
3
//디버그 모드: 시간 많이 걸림
//릴리즈 모드: 10초
#define rep(i,a) for (int i = 0; i < (a); ++i)
int main() {
	FILE *fp;
	freopen_s(&fp, "laundro_matt.txt", "r", stdin);
	freopen_s(&fp, "output.txt", "w", stdout);
	int cs; cin >> cs;
	rep(cc, cs) {
		int L, N, M, D;	//세탁수, 빨래기기 수, 건조기 수, 건조시간
		cin >> L >> N >> M >> D;
		if (M > L)  M = L;
		vi WArr(N);	//각 빨래기기 수행시간
		rep(i, N) cin >> WArr[i];
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
		rep(i, N) pq1.push(mp(WArr[i], WArr[i])); //핵심: 미리 쌓였을때 걸리는 시간을 가지고 우선순위를 정한다. !!!!
		priority_queue<long long, vector<long long>, greater<long long>> pq2;
		rep(i, M) pq2.push(0);
		long long sol;
		rep(i, L) {
			int washer = pq1.top().second;
			long long lastWashTime = pq1.top().first;
			pq1.pop();
			pq1.push(mp(lastWashTime + washer, washer));
			
			long long idleDryerTime = pq2.top();
			long long nextDryerTime = max<long long>(idleDryerTime, lastWashTime) + D;
			pq2.pop();
			pq2.push(nextDryerTime);
			if (i == L - 1)
				sol = nextDryerTime;
		}
		cout << "Case #" << cc + 1 << ": " << sol << endl;
	}
	return 0;
}



부메랑 토너먼트

토너먼트가 끝나면 배치가 주어집니다.
C의 배치는 C보다 많이 이긴 경쟁자의 수보다 큰 정수가 된다.
best와 worst를 찾아내라

풀이
worst는 쉬움

best는 어렵다. bitmask dp를 쓰네
bool DP[b][i]; //b: 2의 지수승
//i번째 선수가 서브 토너먼트(bitmask b: the number of bits set in b shoud be a power of 2)
//에서 이길수 있다면 true, 그렇지 않다면 false;
// Everyone can win a sub-tournament consisting only of themselves(DP[1 << i][i] = 1 for 1 <= i <= N).
// For a larger sub-tournament consisting of the x competitors in some bitmask b,
//we must consider all possible subdivisions of the competitors into two equal halves
//(bitmasks b_1 and b_2, each with x/2 bits set, and with b_1 | b_2 = b).
// For all pairs of winners of the two halves i and j (such that DP[b_1][i] = DP[b_2][j] = true),
//we know tha DP[b][i] = true if W[i][j] = 1, and otherwise we know that DP[b][j] = true.
// Finally, for each competitor i, their best possible placing can be determined
//by the size of the largest sub-tournament that they can win.

//최초설정: 자기 자신은 이김으로 설정
int DP[1<<16][16];	//(DP[1 << i][i] = 1 for 1 <= i <= N : for 0 <= i < N (인덱스가 0부터 시작))
DP[1 << 0][0] = 1;
DP[1 << 1][1] = 1;
DP[1 << 2][2] = 1;
DP[1 << 3][3] = 1;
...
DP[1 << 15][15] = 1;


//다른 사람이 짠거
#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

int dp[100050][20];
int in[20][20];
vector <int> V;

vector <int> al[20];

int good[20];
int bad[20];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 65536; i++) {
		int cnt = 0;
		for (int j = 0; j < 16; j++) if (i & (1 << j)) cnt++;
		al[cnt].push_back(i);
	}

	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int N = 0, i, j, k;
		scanf("%d", &i);
		while (i != 1) {
			N++;
			i /= 2;
		}
		for (i = 0; i < (1 << N); i++) for (j = 0; j < (1 << N); j++) scanf("%d", &in[i][j]);

		for (i = 1; i < (1 << (1 << N)); i++) {
			V.clear();
			for (j = 0; j < (1<<N); j++) if (i & (1 << j)) V.push_back(j);
			if (V.size() != 1) continue;
			dp[i][V[0]] = 1;
		}

		for (i = 0; i < (1 << N); i++) {
			good[i] = 1;
			bad[i] = INF;
		}
		for (int sz = 2; sz <= (1 << N); sz *= 2) {
			for (i = 1; i < (1 << (1 << N)); i++) {
				V.clear();
				for (j = 0; j < (1<<N); j++) if (i & (1 << j)) V.push_back(j);
				if (V.size() != sz) continue;

				for (auto it : al[sz/2]) {
					if ((i & it) != it) continue;
					int it2 = (i ^ it);
					for (j = 0; j < (1 << N); j++) {
						if (!(it & (1 << j))) continue;
						if (!(1 & dp[it][j])) continue;
						for (k = 0; k < (1 << N); k++) {
							if (!(it2 & (1 << k))) continue;
							if (!(1 & dp[it2][k])) continue;
							if (in[j][k] == 1) {
								dp[i][j] |= 1;
								dp[i][k] |= 2;
								good[j] = sz;
								bad[k] = min(bad[k],sz);
							}
							else {
								dp[i][k] |= 1;
								dp[i][j] |= 2;
								good[k] = sz;
								bad[j] = min(bad[j], sz);
							}
						}
					}
				}
			}
		}

		printf("Case #%d:\n", tc);
		for (i = 0; i < (1 << N); i++) {
			printf("%d ", (1 << N) / (2 * good[i]) + 1);
			if (bad[i] == INF) printf("1\n");
			else printf("%d\n", (1 << N) / bad[i] + 1);
		}

		for (i = 0; i < (1 << (1 << N)); i++) for (j = 0; j < (1 << N); j++) dp[i][j] = 0;
	}
	return 0;
}

//내가 짠 코드: 통과했음. 잔 실수 때문에 시간 허비가 무지 많았다...ㅠㅠ
"bitmask dp 를 하기 위해 절반 나누기 스킬이 어떻게 사용되는지 잘보시오"
"좀더 좋은 절반 나누기 알고리즘은 없는지 찾아봅세"
int n;
int W[16][16];
vi two_subset[1 << 16];
//절반 나누기 !!!! //bitmask dp 용 //bigO 300만번 수행: 충분하다.. 허나 1 << 20이면 2억정도 된다..
// rep(i,1<<16) sum += two_subset[i].size() // 결과 924930 밖에 안됨.!!!!
void precalc(int orgSet, int orgSetSize) {
	if (orgSetSize == 0) return;
	if (two_subset[orgSet].size()) return; //이미 세팅되어 있는 놈인경우
	for (int subset = orgSet; subset; subset = ((subset - 1) & orgSet)) {
		int test = __popcnt(subset);
		if (__popcnt(subset) == orgSetSize / 2)
			two_subset[orgSet].push_back(subset);
	}
	rep(i, two_subset[orgSet].size())
		precalc(two_subset[orgSet][i], orgSetSize / 2);
}
int cache[1 << 16][16];	//cache[16 << 1][16] 이런 지랄같은 오타를 해서 시간을 많이 낭비했다. ㅠㅠ
int me_bestSZ[16];
int me_best[16];
int me_win[16], me_worst[16];
int dp(int taken, int size, int me) {
	if ((taken & (1 << me)) == 0) 
		return 0;	
	if ((taken & (1 << me)) != 0 && __popcnt(taken) == 1) {
		me_bestSZ[me] = max(me_bestSZ[me], size);
		return 1;	//하나만 있고 그게 자신인 경우
	}
	int& ret = cache[taken][me];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < two_subset[taken].size(); ++i) {
		//집합을 반띵한다.
		int takenA = two_subset[taken][i];
		int takenB = taken - takenA;
		int t1 = dp(takenA, size / 2, me);	//절반에서 내가 올라올수 있는지 여부 계산
		if (t1 == 0) continue;
		for (int enemy = 0; enemy < n; ++enemy)
			if (me != enemy) {
				int t2 = dp(takenB, size / 2, enemy);	//적이 올라올수 있는지 여부
				int t3 = W[me][enemy];		//나 VS 적 
				if (t2 > 0 && t3 > 0) {
					me_bestSZ[me] = max(me_bestSZ[me], size);	//
					return ret = 1;
				}
			}
	}
	return ret;
}
int main() {
	FILE *fp;
	freopen_s(&fp, "input3.txt", "r", stdin);
	freopen_s(&fp, "output.txt", "w", stdout);
	precalc((1 << 16) - 1, 16);
	int t; cin >> t;
	rep(cc, t) {
		memset(cache, -1, sizeof(cache));
		memset(W, 0, sizeof(W));
		memset(me_bestSZ, 0, sizeof(me_bestSZ));
		cin >> n;
		rep(i, n) rep(j, n) cin >> W[i][j];
		rep(i,n) 
			dp((1 << n) - 1, n, i);
		cout << "Case #" << cc + 1 <<":" << endl;
		rep(i, n){
			me_best[i] = n / (me_bestSZ[i] * 2) + 1; //손으로 적으면 알수 있음요
		}

		rep(i, n) {
			me_win[i] = accumulate(W[i], W[i] + n, 0);
			if (me_win[i] == n - 1)	//상대를 다이기면 무조건 1등
				me_worst[i] = 1;
			else
				me_worst[i] = n / 2 + 1;
		}
		rep(i, n) cout << me_best[i] << " " << me_worst[i] << endl;
	}
	return 0;
}


//정올 모자이크( n * k * k)
const int max_n = 1002;
const int max_k = 102;
const int max_len = 1000000;
struct point { int x, y; };
// 비교기
bool comp(const point& a, const point& b) { if (a.x < b.x) return true; else return false; } //!!!!
"x는 같은데 y는 다르면 정렬 결과는 유일하지 않군" //내마음은 이런코든 비추한다.
point p[max_n];
int DP[max_n][max_k];
int imax(int a, int b) { if (a > b) return a; else return b; }
int imin(int a, int b) { if (a > b) return b; else return a; }
void main() {//이건 통관데.. 내거 재귀코드는 1케이스에서 오류남.. 원인을 알수가 없다. ㅠㅠ
	int se, ga; cin >> se >> ga;
	int k, n; cin >> k >> n;	//k: 색종이 수, n: 까만칸 수
	rep(i,n) cin >> p[i+1].y >> p[i+1].x;
	sort(&p[1],&p[n+1],comp);
	fill(DP[0], DP[n+1], MAX); 
	for(i=0;i<=k;i++)
		DP[0][i] = 0;// DP[0][0] = 1 만 있어도 됨 넣어줘야 함
	rep2(j,1,k+1)	//색종이 갯수	//1000
		rep2(i,1,n+1) {	//까만칸갯수	//100
			if (j == 1 && i == 4)
				j = j;	//왜있는겨? 디버거 용인가?
			//get d[i][j];
			minx = p[i].x - 1;
			maxx = p[i].x;
			miny = 0;
			maxy = p[i].y;
			min_cost = MAX;
			for (int l = i; l >= 1; --l) { //i번 까만칸 부터 1개 남을 때까지//많아야 100번
				minx = p[l].x - 1;
				maxy = imax(maxy, p[l].y);
				cost = imax( DP[l - 1][j - 1], imax(maxx - minx, maxy - miny));
				min_cost = imin(min_cost, cost);
			}
			DP[i][j] = imin(DP[i][j - 1], min_cost);
		}
	cout << DP[n][k] << endl;	
}

// 통과 소스임
const int INF = 987654321;
int dp[1005][105];
int main() {
	ios::sync_with_stdio(false);
	int w, h;	cin >> w >> h;
	int k, n;	cin >> k >> n; // k: 색종이 수, n: 까만칸 수
	vpii p(n + 1);
	rep(i, n) cin >> p[i + 1].second >> p[i + 1].first;
	sort(p.begin() + 1, p.end());
	fill(dp[0], dp[n + 1], INF);
	dp[0][0] = 0;
	rep2(j, 1, k+1)	// 색종이 갯수
		rep2(i, 1, n + 1) {	// 까만칸 갯수
			int lx = p[i].first - 1;
			int rx = p[i].first;
			int dy = 0;
			int uy = p[i].second;
			int min_cost = INF;
			for (int l = i; l >= 1; --l) {// i번 까만칸부터 1개 남을때까지
				lx = p[l].first - 1;
				uy = max(uy, p[l].second);
				int cost = max(dp[l - 1][j - 1], max(rx - lx, uy - dy));
				min_cost = min(min_cost, cost);
			}
			dp[i][j] = min(dp[i][j - 1], min_cost);
		}
	cout << dp[n][k] << endl;
	return 0;
}
//i번까지 j개의 색종이를 사용하여 가리려고 할 때 필요한 색종이의 최소 크기
DP[i][j]: 가릴칸 수 n, 색종이 수 k
열을 기준으로 정렬(솔직히 의미 없다고 봄)//아니야.. cost편하게 구하려고 정렬한거 였어...//아니야.. 그것말고도 정렬이 되어야 답이 구해져
"만일 p( <= i)번 칸 부터 i번 칸을 한개의 색종이로 가린다고 가정하면"
DP[i][j] = min{ max{ DP[p - 1][j - 1], cost(p, i) } } //cost(p, i): p번 ~ i번 까지 한개의 색종이를 사용하여 가릴때 필요한 색종이의 길이

			   
DP[5][3] =     | max{ DP[5 - 1][3 - 1], cost(5, 5) } |//cost(5, 5): 5번~5번까지 한개의 색종이를 사용하여 " "
			   | max{ DP[4 - 1][3 - 1], cost(4, 5) } |
			   | max{ DP[3 - 1][3 - 1], cost(3, 5) } |
		   min | max{ DP[2 - 1][3 - 1], cost(2, 5) } |
			   | max{ DP[1 - 1][3 - 1], cost(1, 5) } |//DP[0][~]: INF
			   | DP[5][3 - 1]						 |// 1 ~ 5번 까지를 2장의 색종이를 가지고 채울때 색종이의 최소 크기

int main() {
	int* test1 = cost[100];				//0x013c4ac0
	int* test2 = cost[100 + 1];			//0x013c4c54
	int* test3 = &cost[100][100];		//0x013c4c50
	int* test4 = &cost[100][100] + 1;	//0x013c4c54
	// test2 == test4 !!!! 이중배열을 fill로 초기화 하는 코드
	//fill(cost[0], cost[row + 1], MAX);
	return 0;
}

//프로그램이 죽고 갑자기 뜸금없이 벡터의 사이즈가 바뀌었다면
//전역 변수 배열의 크기를 잘못 설정했는지 의심해라.. ㅠㅠ
//아래는 한 테스트 케이스에서 죽어라 오류 났던 코드다.
const int INF = 987654321;
vpii points;
int dp[1001][101];	//[까만 칸][색종이]
int cost[1001][1001];
int row, col;
void precalc() {
	"실수한 부분: minY = 항상 바닥이 된다."
	//fill(cost[0], cost[101], 0);
	memset(cost, 0, sizeof(cost));
	int cnt = points.size();
	rep2(i, 1, cnt) {
		int minX = points[i].first, maxX = points[i].first;
		int minY = points[i].second, maxY = points[i].second;
		cost[i][i] = 1;
		//위 코드는 이렇게 고쳐져야 한다.
		"cost[i][i] = maxY;"
		rep2(j, i + 1, cnt) {
			minX = min(minX, points[j].first);
			maxX = max(maxX, points[j].first);
			minY = min(minY, points[j].second);
			maxY = max(maxY, points[j].second);
			cost[i][j] = max(maxX - minX + 1, maxY - minY + 1);
			//위 코드는 이렇게 고쳐져야 한다.
			"cost[i][j] = max(maxX - minX + 1, maxY);" //minY가 필요없다.
		}
	}
}
int recur(int bb, int nn) {	//i: 까만점(1 ~ bb), nn: 사용되는 색종이 수
	if (bb == 0) return INF;			//까만게 한게도 없다면 무시하도록 무한대를 리턴
	//위 코드는 이렇게 고쳐라
	"if (bb == 0) return 0; 
	if (nn == 1) return cost[1][bb];	//한개의 색종이로 1~bb의 검을 점을 채움
	int& ret = dp[bb][nn];
	if (ret != -1) return ret;
	ret = recur(bb, nn - 1);
	rep(i, bb) 
		ret = min(ret, max(recur(i, nn - 1), cost[i + 1][bb]));
	return ret;
}
int main() {
	cin >> row >> col;
	int n, b; cin >> n >> b;	// 색종이, 까만칸 수
	points.resize(b + 1);
	rep(i, b) cin >> points[i + 1].second >> points[i + 1].first;	//y, x 입력
	sort(points.begin() + 1, points.end());	//이거 없으면 안 돌아감, x에대한 우선 정렬
	precalc();
	memset(dp, -1, sizeof(dp));
	int ret = recur(b, n);
	cout << ret << endl;
	return 0;
}
"10개중 3번 테스트 케이스 1개만 빼고 나머진 통과함.. 도저히 오답원인을 모르겠다. "
"새로 짜보자."


"이거 정답코드도 10을 리턴한다. 오류같다"
10 10
2
3
1 1
10 1
2 1
"밑변에 맞추어 붙인다" 이게 문제였구나...ㅅㅂ
(조건 3) 모든 색종이는 반드시 도화지의 밑변에 맞추어 붙인다. 이 때 색종이를 겹쳐서 붙일 수 있다.

//테스트 통과한 코드.. 에휴...
vpii points;
int dp[1001][101];	//[까만 칸][색종이]
int cost[1001][1001];
int row, col;
void precalc() {
	memset(cost, 0, sizeof(cost));
	int cnt = points.size();
	rep2(i, 1, cnt) {
		int minX = points[i].first;
		int maxX = points[i].first;
		int maxY = points[i].second;
		cost[i][i] = maxY;
		rep2(j, i + 1, cnt) {
			minX = min(minX, points[j].first);
			maxX = max(maxX, points[j].first);
			maxY = max(maxY, points[j].second);
			//minY = 0: 바닥면으로 고정됨
			cost[i][j] = max(maxX - minX + 1, maxY);
		}
	}
}
//i: 까만점(1 ~ bb), nn: 사용되는 색종이 수
int recur(int bb, int nn) {
	if (bb == 0) return 0;	//까만점이 없다면 색종이는 필요없으니 0 리턴
	if (nn == 1) return cost[1][bb];	//한개의 색종이로 1~bb 의 점을 채움
	int& ret = dp[bb][nn];
	if (ret != -1) return ret;
	ret = recur(bb, nn - 1);
	rep(i, bb)
		ret = min(ret, max(recur(i, nn - 1), cost[i + 1][bb]));
	return ret;
}
int main() {
	cin >> row >> col;
	int n, b; cin >> n >> b;	//색종이, 까만칸 수
	points.resize(b + 1);
	rep(i, b) cin >> points[i + 1].second >> points[i + 1].first;
	sort(points.begin() + 1, points.end());
	precalc();
	memset(dp, -1, sizeof(dp));
	int ret = recur(b, n);
	cout << ret << endl;
	return 0;
}

/*
//i번까지 j개의 색종이를 사용하여 가리려고 할 때 필요한 색종이의 최소 크기
DP[i][j]: 가릴칸 수 n, 색종이 수 k
열을 기준으로 정렬(솔직히 의미 없다고 봄)//아니야.. cost편하게 구하려고 정렬한거 였어...//아니야.. 그것말고도 정렬이 되어야 답이 구해져
"만일 p( <= i)번 칸 부터 i번 칸을 한개의 색종이로 가린다고 가정하면"
DP[i][j] = min{ max{ DP[p - 1][j - 1], cost(p, i) } } //cost(p, i): p번 ~ i번 까지 한개의 색종이를 사용하여 가릴때 필요한 색종이의 길이

DP[5][3] =  | max{ DP[5 - 1][3 - 1], cost(5, 5) } |//cost(5, 5): 5번~5번까지 한개의 색종이를 사용하여 " "
            | max{ DP[4 - 1][3 - 1], cost(4, 5) } |
            | max{ DP[3 - 1][3 - 1], cost(3, 5) } |
        min | max{ DP[2 - 1][3 - 1], cost(2, 5) } |
            | max{ DP[1 - 1][3 - 1], cost(1, 5) } |//DP[0][~]: 0
            | DP[5][3 - 1]                        |// 1 ~ 5번 까지를 2장의 색종이를 가지고 채울때 색종이의 최소 크기
*/












LASER
"입력"
입력의 첫 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 줄에는 N (1≤N≤1000)이 주어진다. N은 알고리늄 결정의 갯수이다.
다음 N 줄에는 알고리늄이 놓일 좌표의 정수 쌍이 주어진다. ( 1≤X,Y≤10000)
이 N 개의 정수 쌍은 서로 겹치지 않는다.
"출력"
각 테스트 케이스마다 5개 이상의 알고리늄이 일직선 상에 놓인 경우의 직선 수를 출력한다. 
6개 이상의 알고리늄이 한 직선에 놓인 경우도 직선은 하나로 취급한다.
"당금 1000개가 한줄에 있어도 알고리늄의 총 수는 1개이다!!!!!"
//laser 김동코드
https://algospot.com/judge/submission/detail/359136
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int INF
int main() {
	int T, N, X, Y;
	cin >> T;
	while (T--) {
		cin >> N;
		vpii arr(N);
		rep(i,N) cin >> arr[i].first >> arr[i].second;

		vector<set<int>> skip(N, set<int>());
		int count = 0;
		for (int i = 0; i < N; ++i) {
			map<int, vector<int>> Ac;	//key: 기울기, val: 해당 기울기를 가진 점들(index)
			for (int k = i + 1; k < N; ++k) {
				if (skip[i].find(k) != skip[i].end()) continue;
				auto A = arr[i];
				auto B = arr[k];
				int dy = A.second - B.second;
				int dx = A.first - B.first;
				int a;
				if (dx == 0)
					a = INF;
				else
					a = 10000 * dy / dx;	//dX는 10000이하이므로
											//기울기 곱하기 
											// 허나 10000 * 10000 을 곱해야 한다.
				Ac[a].push_back(k);//맵에다가 기울기가 같은 놈들을 집어넣는다.
			}
			for (auto e: Ac) {
				auto L = e.second;	//vector<int>
				if (L.size() >= 4) {	// 동일 기울기를 가진게 4개 이상인가
					count++;
					for (int p = 0; p < L.size(); ++p)
						for (int t = p + 1; t < L.size(); ++t)
							skip[L[p]].insert(L[t]);
					// 0------1------2------3------4------5------6
					//i == 0 이면 L.size()는 6이 된다.
					//1은 2, 3, 4, 5, 6을 볼필요가 없다
					//2는 3, 4, 5, 6을 볼 필요가 없다.
					//...
				}
			}
		}
		cout << count << endl;
	}
}
//auto 안쓸래 짜증나....
int inf;
int main() {
	int cs, n;
	cin >> cs;
	rep(cc,cs) {
		cin >> n;
		vpii arr(n);
		rep(i,n) cin >> arr[i].first >> arr[i].second;
		vector<set<int>> skip(n, set<int>());
		int count = 0;
		rep(i,n) {
			map<int, vi> ac;	// key: 기울기, val: 해당 기울기를 가진 점들(index)
			for (int k = i + 1; k < n; ++k) {
				// 이미 처리를 했던 기울기면 넘어간다.
				if (skip[i].find(k) != skip[i].end()) continue;
				pii A = arr[i];
				pii B = arr[k];
				int dy = A.second - B.second;
				int dx = A.first - B.first;
				int key;
				if (dx == 0)
					key = INF;
				else
					key = 10000 * 10000 * dy / dx;
				ac[key].pb(k);
			}
			map<int, vi>::iterator iter = ac.begin();
			for(; iter != ac.end(); ++iter) {
				// i번 점을 기준으로 같은 기울기를 가지는 점들 인덱스
				vi points = iter.second;	
				if (points.size() >= 4) {	// 한 직선상에 5개 이상의 점이 있으면 하나의 알고리늄
					count++;
					for (int p = 0; p < points.size(); ++p)
						for (int t = p+1; t < points.size(); ++t)
							skip[points[p]].insert(L[t]);
					// 0------1------2------3------4------5------6
					//i == 0 이면 L.size()는 6이 된다.
					//1은 2, 3, 4, 5, 6을 볼필요가 없다
					//2는 3, 4, 5, 6을 볼 필요가 없다.
					//...
				}
			}
		}
		cout << count << endl;
	}
}
// 복잡도~
// n이 1000개
map:ac 의 용량은 많아야 100만 ( 1000 * 1000)
vector<set<int>> skip(n, set<int>()) 의 용량은 많아야 100만 

// 김동이 짠 코드 ax + by = c;	// c 에 -1곱하면 사실상 ax + by + c = 0 으로 될듯.
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
using Tp = tuple<int, int, int>;
int main() {
	int t, n, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> in(n);
		for (auto & i : in)
			cin >> i.first >> i.second;
		map<Tp, int> lines;
		for (int i = 0; i < n; i++) {
			for (int k = i + 1; k < n; k++) {
				auto &p = in[i], &q = in[k];
				int a = q.second - p.second;
				int b = p.first - q.first;
				int c = p.first * q.second - q.first * p.second;	// 실제론 -c가 되겠군
				
				int g = gcd(a, gcd(b, c));
				lines[make_tuple(a/g, b/g, c/g)]++;
			}
		}
		// !!!! count_if 구문
		auto cnt = count_if(lines.begin(), lines.end(),		// 람다 표현 오오.. 가독성 쩔구나 !!!! 지린다.
				[&](const pair<Tp, int>& k) { return k.second >= 5*4/2;});
		// 아래서 람다에 대해 궁금하면 알아보세
		//http://vallista.tistory.com/entry/C-11-Lambda-Expression-%EB%9E%8C%EB%8B%A4-%ED%91%9C%ED%98%84%EC%8B%9D-%ED%95%A8%EC%88%98-%EA%B0%9D%EC%B2%B4-Functor
		cout << cnt << endl;
	}
}
     x, y        x, y
p = (1, 3), q = (2, 5)
a = 5 - 3 = 2;
b = 1 - 2 = -1;
c = p.first * q.second - q.first * p.second = 1 * 5 - 2 * 3 = -1;  // 핵심
ax + by = c			ax + by - c = 0;
2x + -1y = -1;		2x + -1y + 1 = 0;

어어 a, b, c 가 음양이 뒤집어질수 있잖아 그럼 곤란하지 않냐?
https://algospot.com/judge/submission/detail/359317
실제로 뒤집어 진다. 내코드는 그걸 대비하고 있었다.
허나 중요한 사실
"맨 외곽의 놈은 음양이 뒤집어질 리가 없고"				"1 --- 0 --- 2 --- 3 ---- 4"
"맨 외곽점을 포함한 알고리늄 판별이 답에 포함되므로"
"이문제에선 음양이 뒤집어 지는걸 신경 안써도 된다."
// 으음.. 신경 써야 되는 뎁쇼..
key{2,-1,-1} != key{-2,1,1} 요런 경우가 있잖수.
// 김동코드에서 a,b,c는 음양이 바뀔지 언정 gcd 값도 읍양이 바뀌기 때문에 결론적으로 key값은 유일해진다.!


코드포스
http://codeforces.com/contest/618/problem/C
삼각형 찾기(안에 아무 점이 없는)

bool absoluteEqual(double a, double b) {
	return fabs(a - b) < 1e-15;
}
struct point {
	//int base;
	long long x, y;
};
void precalc(const vector<point>& points, int base, 
	vector<pair<double, int>>& arr) {
	rep(i, points.size()) {
		if (base != i) {
			double a = atan2(double(points[i].y - points[base].y),	//double 안붙이니 컴파일 에러난다...(codeforce에서만 남..vs랑 algospot은 안남)
				double(points[i].x - points[base].x));
			arr.push_back(mp(a, i));
		}
	}
	sort(arr.begin(), arr.end());
}
//bool comp
int main() {
	double test = atan2((double)1000000000, (double)1);
	double test2 = atan2((double)999999999, (double)1);
	//test, test2 둘다 1.5707963257948967 를 가짐 내가 테스트 49번을 통과 못한 이유임.
	//테스트 49번에선 모두 한 직선에 존재한다고 판단해 버렸음
	double cha = fabs(test - test2);

	FILE *fp;
	freopen_s(&fp, "input2.txt", "r", stdin);

	int n; cin >> n;
	vector<point> points(n);
	rep(i, n) {
		cin >> points[i].x >> points[i].y;
	}
	int LLBIndex = 0;
	rep2(i,1, n) {
		if (points[LLBIndex].y > points[i].y)
			LLBIndex = i;
		else if (points[LLBIndex].y == points[i].y)
			if (points[LLBIndex].x > points[i].x)
				LLBIndex = i;
	}
	vector<pair<double, int>> arr;
	precalc(points, LLBIndex, arr);

	int nextArr;
	int p1 = arr[0].second;
	double p1Angle = arr[0].first;
	rep2(i,1, arr.size()) {
		// p1을 찾는다.
		if (absoluteEqual(p1Angle, arr[i].first)) {
			int temp = arr[i].second;
			long long distSquareP1 = (points[p1].y - points[LLBIndex].y) * (points[p1].y - points[LLBIndex].y) +
				(points[p1].x - points[LLBIndex].x) * (points[p1].x - points[LLBIndex].x);
			long long distSquareTemp = (points[temp].y - points[LLBIndex].y) * (points[temp].y - points[LLBIndex].y) +
				(points[temp].x - points[LLBIndex].x) * (points[temp].x - points[LLBIndex].x);
			if (distSquareP1 > distSquareTemp)
				p1 = temp;
		}
		else {
			nextArr = i;
			break;
		}
	}
	int p2 = arr[nextArr].second;
	double p2Angle = arr[nextArr].first;
	rep2(i, nextArr, arr.size()) {
		//p2를 찾는다.
		if (absoluteEqual(p2Angle, arr[i].first)) {
			int temp = arr[i].second;
			long long distSquareP2 = (points[p2].y - points[LLBIndex].y) * (points[p2].y - points[LLBIndex].y) +
				(points[p2].x - points[LLBIndex].x) * (points[p2].x - points[LLBIndex].x);
			long long distSquareTemp = (points[temp].y - points[LLBIndex].y) * (points[temp].y - points[LLBIndex].y) +
				(points[temp].x - points[LLBIndex].x) * (points[temp].x - points[LLBIndex].x);
			if (distSquareP2 > distSquareTemp)
				p2 = temp;
		}
		else {
			//nextArr = i;
			break;
		}
	}

	cout << LLBIndex + 1 << " " << p1 + 1 << " " << p2 + 1;
	return 0;
}
"좌표의 범위가 -10억 ~ 10억 이다" 너무 커서 동일한 각도를 이루지 않아도
atan2는 동일한 각도라고 해뿌네....
오류난 49번 테스트
10
999999999 1
999999998 1
999999997 1
1000000000 1
999999996 1
999999995 1
999999994 1
999999992 1
999999993 1
0 0

point base;
long long ccw(point ab, point ac) { return ab.x * ac.y - ab.y * ac.x; }
long long ccw(point a, point b, point c) {
	point ab(b.x - a.x, b.y - a.y);
	point ac(c.x - a.x, c.y - a.y);
	long long t = ccw(ab, ac);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}
bool comp(point b, point c) { return ccw(base, b, c) < 0; } 
//반시계는 -ccw(base, b, c) < 0; 혹은 ccw(base, b, c) > 0 
"반대라고 ccw(base, b, c) >= 0 해뿌면 죽는다.. 양변에 -1을 곱한걸 구해야 됨"
결과는 아래와 같다.
"시계 정렬이 안됨" 왜냐면 완전 일치가 아닌데 ccw결과가 같은 놈들이 있기 때문
	vector<point> testPoints(10);
	testPoints[9] = point(-2, 1);
	testPoints[8] = point(-2, 0);
	testPoints[7] = point(-1, 1);
	testPoints[6] = point(-1, 0);
	testPoints[5] = point( 0, 1);
	testPoints[4] = point( 0, 0);
	testPoints[3] = point( 1, 1);
	testPoints[2] = point( 1, 0);
	testPoints[1] = point( 2, 1);
	testPoints[0] = point( 2, 0);
	base = point(0, 0);
	sort(testPoints.begin(), testPoints.end(), comp);

"시계 정렬이 된다" ccw결과가 같은 놈들이 없어서
	vector<point> testPoints(5);
	testPoints[4] = point( -1, 0);
	testPoints[3] = point( 1, 1);
	testPoints[2] = point( 1, 0);
	testPoints[1] = point( -1, 1);
	testPoints[0] = point( 0, 1);
	base = point(0, 0);
	sort(testPoints.begin(), testPoints.end(), comp);

"수정 버전"
"반시계 방향으로 돌린다." base랑 같은 좌표가 있으면 그 좌표는 맨 처음에 존재하네..
"같은 외적이면 가까운 놈부터 앞에둔다"
long long sqDist(point pt) { return pt.x * pt.x + pt.y * pt.y; }
point base;
long long ccw(point ab, point ac) { return ab.x * ac.y - ab.y * ac.x; }
long long ccw(point a, point b, point c) {
	point ab(b.x - a.x, b.y - a.y);
	point ac(c.x - a.x, c.y - a.y);
	long long t = ccw(ab, ac);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}
bool comp(point b, point c) { 
	long long t = ccw(base, b, c);
	if (t == 0) {
		long long baseB = sqDist(point(b.x - base.x, b.y - base.y));
		long long baseC = sqDist(point(c.x - base.x, c.y - base.y));
		//외적이 0이고(base:{0,0}, b:{-1,0}, c:{1, 0}, 거리도 같은 경우 x로 비교
"좃댐요"
		//외적이 0이고 거리가 다른 경우도 x로 비교해야 하는 경우가 있어욤
		//base:{0,0}, b:{-2,0}, c:{1,0}
"어째 불안불안하더라"
"해결하려면 base를 맨 좌측 아래로 두어 180도 외적이 형성 안되게 하면 됨요!!! 오오 해결함"
// 얍실하잖아.. 그렇지 않은 경우엔 어쩌노. // base가 중간 안쪽에 있다면 말야.
		if (baseB == baseC) return b.x - base.x < c.x - base.x;
		else return baseB < baseC;
	}
	else
		return t > 0;
}
	vector<point> testPoints(10);
	testPoints[9] = point(-2, 1);
	testPoints[8] = point(-2, 0);
	testPoints[7] = point(-1, 1);
	testPoints[6] = point(-1, 0);
	testPoints[5] = point(0, 1);
	testPoints[4] = point(0, 0);
	testPoints[3] = point(1, 1);
	testPoints[2] = point(1, 0);
	testPoints[1] = point(2, 1);
	testPoints[0] = point(2, 0);
	base = point(0, 0);
	sort(testPoints.begin(), testPoints.end(), comp);

"시계방향정렬 버전" base는 맨 뒤에 존재함
"같은 외적이면 먼놈부터 앞에 둔다"
bool comp(point b, point c) { 
	long long t = ccw(base, b, c);
	if (t == 0) {
		long long baseB = sqDist(point(b.x - base.x, b.y - base.y));
		long long baseC = sqDist(point(c.x - base.x, c.y - base.y));
		if (baseB == baseC) return b.x - base.x > c.x - base.x;
		else return baseB > baseC;
	}
	else
		return t < 0;
}

"고찰: 중간에 base가 있는 경우의 각도 정렬을 위한 외적 활용"


//헌데.. C번 문제 더 해결하기 좋은 방법이 생각났다.
맨좌측아래는 base
base랑 가장 가까운 점 p1
(base, p1, p2)가 일직선 상에 안 놓이면서 base랑 가장 가까운 p2
ㅅㅂ 간단하네....ㅠㅠ

"내가 원래 의향대로 푼거" codeforce 통과함
"외적 정렬의 가장 중요한 것은 base를 외각 모서리로(왼쪽아래, 아래왼쪽 등등) 두는 것이다.!!!!"
struct point {
	long long x, y;
	point() {}
	point(long long _x, long long _y) : x(_x), y(_y) {}
};

long long sqDist(point pt) { return pt.x * pt.x + pt.y * pt.y; }
point base;
long long ccw(point ab, point ac) { return ab.x * ac.y - ab.y * ac.x; }
long long ccw(point a, point b, point c) {
	point ab(b.x - a.x, b.y - a.y);
	point ac(c.x - a.x, c.y - a.y);
	long long t = ccw(ab, ac);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}
bool comp(pair<point, int> bb, pair<point, int> cc) { 
	point b = bb.first;
	point c = cc.first;
	long long t = ccw(base, b, c);
	if (t == 0) {
		long long baseB = sqDist(point(b.x - base.x, b.y - base.y));
		long long baseC = sqDist(point(c.x - base.x, c.y - base.y));
		if (baseB == baseC) return b.x - base.x < c.x - base.x; // 같을 리가 없지만..
		else return baseB < baseC;
	}
	else
		return t > 0;
}

int main() {
	//FILE *fp;
	//freopen_s(&fp, "input2.txt", "r", stdin);
	int n; cin >> n;
	vector<point> points(n);
	rep(i, n) {
		cin >> points[i].x >> points[i].y;
	}
	int p0 = 0;
	rep2(i,1, n) {	//맨 아래쪽의 왼쪽을 집어낸다.
		if (points[p0].y > points[i].y)
			p0 = i;
		else if (points[p0].y == points[i].y)
			if (points[p0].x > points[i].x)
				p0 = i;
	}
	vector<pair<point, int>> sortArr;
	rep(i, n) {
		if (p0 == i) continue;
		sortArr.push_back(mp(points[i],i));	//억 마소 2010은 {} 지원 안하는 구만 제길
	}
	base = points[p0];
	sort(sortArr.begin(), sortArr.end(), comp);

	int p1 = sortArr.begin()->second;
	int p2 = p1;
	rep2(i, 1, sortArr.size()) {
		
		if (ccw(base, points[p1], sortArr[i].first) != 0) {
			p2 = sortArr[i].second;
			break;
		}
	}
	cout << p0 + 1 << " " << p1 + 1 << " " << p2 + 1;
	return 0;
}


//외적정렬 없이 푼거: 통과함
//맨 아래쪽의 왼쪽을 기준으로 가장 가까운 점 두개를 찾는다. 
//마지막 점은 남은 두점과 일직선이 되면 안됨( 각도가 0이 되면 안됨)
struct point {
	long long x, y;
	point() {}
	point(long long _x, long long _y) : x(_x), y(_y) {}
};
long long sqDist(point pt) { return pt.x * pt.x + pt.y * pt.y; }
long long ccw(point ab, point ac) { return ab.x * ac.y - ab.y * ac.x; }
long long ccw(point a, point b, point c) {
	point ab(b.x - a.x, b.y - a.y);
	point ac(c.x - a.x, c.y - a.y);
	long long t = ccw(ab, ac);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}
int main() {
	int n; cin >> n;
	vector<point> points(n);
	rep(i, n) {	cin >> points[i].x >> points[i].y;	}
	int p0 = 0;
	rep2(i,1, n) {	//맨 아래쪽의 왼쪽을 집어낸다.
		if (points[p0].y > points[i].y)
			p0 = i;
		else if (points[p0].y == points[i].y)
			if (points[p0].y > points[i].x)
				p0 = i;
	}
	vector<pair<long long, int>> distArr;
	rep(i, n) {
		if (i == p0) continue;
		distArr.pb(mp(sqDist(point(points[i].x - points[p0].x, points[i].y - points[p0].y)), i));
	}
	sort(distArr.begin(), distArr.end());
	int p1 = distArr.begin()->second;
	int p2 = -1;
	rep2(i, 1, distArr.size()) {
		if (ccw(points[p0], points[p1], points[distArr[i].second]) != 0) {
			p2 = distArr[i].second;
			break;
		}
	}
	cout << p0 + 1 << " " << p1 + 1 << " " << p2 + 1;
	return 0;
}




http://codeforces.com/contest/618/problem/D
//스패닝 트리를 만든다: 단 한 해밀토니안 패스를 이루어야 한다.
//즉 한노드를 두번이상 방문하면 안된다.
5 2 3	//점갯수, x비용, y비용
1 2	// 연결된건 x비용을 가짐
1 3
3 4
5 3
//5-3-4-1-2 //2 + 2 + 3 + 2	// 일렬의 스패닝 트리를 만든다.(최소비용을 가진)
output
9


// 이문제는 아래와 동치이다. 해밀토니안 패스는 각 노드가 최대 2개의 엣지를 가지기 때문이다.
Choose the maximum number of edges such that all nodes are incident to at most 2 edges.
(한 노드당 최대 2개의 x비용의 엣지만을 가질수 있는 경우, 최대 엣지 갯수를 구하라)
http://codeforces.com/contest/618/submission/15669516
import java.io.*;
import java.util.*;
public class HamiltonianTree {
	private static InputReader in;
	private static PrintWriter out;
	public static ArrayList<Integer>[] graph;

	public static void main (String[] args) {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out, true);

		int n = in.nextInt();
		long x = in.nextInt(), y = in.nextInt();

		if (x > y) {
			int[] deg = new int[n];
			for (int i = 0; i < n - 1; ++i) {
				int a = in.nextInt() - 1, b = in.nextInt() - 1;
				deg[a]++;
				deg[b]++;
			}
			int max = 0;
			for (int i = 0; i < n; ++i) {
				max = Math.max(max, deg[i]);	//최대차수를 기록
			}
			out.printIn(y * (n - 2) + (max == n - 1 ? x : y));	//한놈 한테 다 엉킨 경우를 처리
		} else {
			graph = new ArrayList[n];
			for (int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
			for (int i = 0; i < n - 1; ++i) {
				int a = in.nextInt() - 1, b = in.nextInt() - 1;
				graph[a].add(b);
				graph[b].add(a);
			}
			ans = 0;
			dfs(0, -1);	//현노드 , 부모노드
			out.printIn((n - 1 - ans) * y + ans * x);
		}
		out.close();
		System.exit(0);
	}
	//활용: mst에서 가장 긴 줄기 크기를 찾을수 있겠군!!!!
	public static long ans;
	public static int dfs(int node, int par) {	//핵심
		int left = 2;
		for (int next : graph[node]) {
			int (next == par) continue;	//부모면 생략
			int x = dfs(next, node);
			if (left > 0 && x == 1) {	//x == 1: next노드의 부모뺀 자식이 2개 미만
				ans++;
				left--;
			}
		}
		return left > 0 ? 1 : 0;
	}
	static class InputReader {
		...; //생략
	}
}
//내가 짠거: 통과함
vi graph[200000];
int sEdge;	// 남겨야 할 x 엣지 갯수
bool dfs(int here, int prnt) {
	int remain = 2;
	rep(i, graph[here].size()) {
		int child = graph[here][i];
		if (child == prnt) continue;
		bool hereChild = dfs(child, here);
		if (hereChild == true && remain > 0) {
			remain--;
			sEdge++;
		}
	}
	//자식놈이 부모를 제외하고 2갈래 엣지가 있으면
	//자식과 부모를 연결하는 엣지는 제외시켜야 함(그걸 포함시키는 순간 한 노드의 엣지가 3개가 되니)
	return remain > 0 ? true : false;
}
int main() {
	long long n, x, y; cin >> n >> x >> y;
	rep(i, n - 1) {
		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	if (x <= y) {
		//스패닝 트리에서 한 노드당 선택되는 엣지가 2개 이하가 되도록 한다.
		int prnt = -1;
		sEdge = 0;
		dfs(0, -1);
		long long sol = sEdge * x + (n - 1 - sEdge) * y;
		cout << sol;
	}
	else {	//x > y
		bool bStar = false;
		rep(i, n)
			if (graph[i].size() == n - 1)
				bStar = true;
		if (bStar) 
			cout << (n - 2) * y + x;	// 반드시 x비용의 간선이 포함되어야 한다.
		else
			cout << (n - 1) * y;
		
	}
	return 0;
}
6 2 3
1 2
1 3
1 4
4 6
4 5

2-----1------4------5
      |      |
      |      |
	  3      6

선택된 엣지는 4개가 되어야 정답이다.//한노드당 2개 이하의 간선이 선택되어야 한다
//나의 잘못된 생각: 3개가 되어야 되지 않느냐 였음!!!!" //2----1-----4------5 로 말이지


http://codeforces.com/contest/580/problem/C
vi tree[100000];
vb vstd;
vi cats;
int n, m;
int ans;
void dfs(int here, int consec) {
	if (vstd[here]) return;
	vstd[here] = true;
	if (cats[here] == 0)
		consec = 0;
	else
		consec++;
	if (consec > m) return;
	rep(i, tree[here].size()) {
		int there = tree[here][i];
		dfs(there, consec);
	}
	if (tree[here].size() == 1 && here != 0) //잎노드이면, (루트도 사이즈가 1일수 있다)
		ans++;
}
int main() {
	cin >> n >> m;
	cats.resize(n);
	vstd = vb(n, false);
	rep(i, n)
		cin >> cats[i];
	rep(i, n - 1) {
		int u, v; cin >> u >> v;
		u--; v--;	//루트를 제외하면 자식의 숫자가 부모보다 높을수 있다.
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	ans = 0;
	dfs(0, 0);
	cout << ans;
	return 0;
}


http://codeforces.com/contest/621/problem/C
기대값을 찾는 문제
3 2	// n(3 <= n <= 100000), p(소수 10^9 미만) : 인접한 두개의 곱이 p로 나눠떨어지면 각각 1000씩 받음
1 2
420 421
420420 420421

1. (1, 420, 420420) : 6000
2. (1, 420, 420421) : 4000
3. (1, 421, 420420) : 4000
4. (1, 421, 420421) : 0
5. (2, 420, 420420) : 6000
6. (2, 420, 420421) : 6000
7. (2, 421, 420420) : 6000
8. (2, 421, 420421) : 4000

기대값은 1~8 의 총 합에서 8로 나눈 4500 이 된다.


"선형성(linearity)이 어디에 있는지 간파하는 능력이 중요하다"
Let f(x) be the probability that the product of the number of flowers of sharks x
and (x + 1) mod n is divisible by p.
"f(x)를 두 지점의 곱이 p로 나누어질 확률이라고 두자"

We want the expected value of the number of pairs of neighbouring sharks
whose flower numbers are divisible by p.

From "linearity" of expectation, this is equal to the probabilities that each
pair multiplies to a number divisible by p, or f(0) + f(1) + ... + f(n).
(Dont forget about the wrap-around at n)


Now, for each pair of neighbouring sharks, we need to figure out the probability that
their product is divisible by p. Consider an interval [li, ri].

How many numbers in this interval are divisible by p? 
Well, it is easier if we break the interval [li, ri] up into [1, ri] - [1, li - 1].
Since 1, 2, ..., x contains x/p numbers divisible by p, the interval [li, ri] 
contains ri/p - (li - 1)/p numbers divisible by p.

Now, consider two numbers fi (- [li, ri] and fj (- [lj, rj], with j = (i + 1) mod n.
Let 'ai' be the number of integers divisible by p in the interval [li, ri], and define
'aj' similarly.	//ai, aj: p로 나누어 떨어지는 수의 갯수
Now whats the probability that fi*fj is divisible by p?
We can countt the opposite: the probability that fi*fj is not divisible by p.
Since p is a prime, this means neither fi nor fj is divisible by p.
The number of integers in [li, ri] not divisible by p is "ri - li + 1 - ai".
//[li, ri]구간에서 p로 나누어 지지 않는 숫자들의 갯수
Similar for j. Therefore, the probability fi*fj is not divisible by p is given by
"(ri - li + 1 - ai) / (ri - li + 1) * (rj - lj + 1 - aj) / (rj - lj + 1). "
//두 지점의 곱이 p로 나누어지지 않을 확률
Therefore, the probabilit it is can be given by
1 - "(ri - li + 1 - ai) / (ri - li + 1) * (rj - lj + 1 - aj) / (rj - lj + 1)".
//두 지점의 곱이 p로 나누어 떨어질 확률
Now, just sum over this for all i.

si * sj 가 p로 나누어 떨어지면 1000달러를 받는다. 양쪽 노드이니 총 2000 달러를 받는다.
이때 기대값을 구하라.
3 2			// n의 수, prime 값
1 2			
420 421
420420 420421	// 각각의 수 10억 이하 : left, right
//통과함요
int main() {
	int n, p; cin >> n >> p;
	vpii arr(n);
	rep(i, n)
		cin >> arr[i].first >> arr[i].second;
	vector<double> fArr(n);
	rep(i, n) {
		int j = (i + 1) % n;
		double ai = arr[i].second / p - (arr[i].first - 1) / p;	//ai 구간의 p로 나누어 떨어지는 갯수
		double aj = arr[j].second / p - (arr[j].first - 1) / p;
		double li = arr[i].first;
		double ri = arr[i].second;
		double lj = arr[j].first;
		double rj = arr[j].second;
		fArr[i] = 1.0 	- (ri-li+1 - ai) / (ri-li+1)	// i에서 p로 나눠떨어지지 않을 확률
						* (rj-lj+1 - aj) / (rj-lj+1);	// j ""
				// 1.0 - (i에서 p로 나눠 떨어지지 않는 확률 * j에서 p로 나눠떨어지지 않는 확률)
				// = p로 떨어지지 않는 확률
	}
	double sol = 0.0;
	rep(i, n)
		sol += fArr[i] * 2000;
	printf("%.7f", sol);
	return 0;
}


http://codeforces.com/contest/621/problem/D
"로그를 응용하는 좋은 문제"
대소비교

int main() {
	double v[3];
	rep(i, 3) cin >> v[i];
	int type = -1;
	int overOne = 0;
	rep(i, 3) 
		if (v[i] > 1.0)
			overOne++;
	if (overOne == 3) type = 0;
	else if (overOne == 0) type = 2;
	else type = 1;
	int first, second, third;
	bool bPowerPower = false;
	double doubleLog = -numeric_limits<double>::max();	//min은 소수점으로 작은거임..음수가 아님!!!!
	if (type == 2) doubleLog = numeric_limits<double>::max();	//역수를 취함
	rep(i,3)
		rep(j, 3)
			if (i != j)
				rep(k, 3)
					if (j != k && i != k) {
						if (type == 0) {
							double p1 = v[k] * log(v[j]) + log(log(v[i]));
							double p2 = log(v[j]) + log(v[k]) + log(log(v[i]));
							if (doubleLog < p1 || doubleLog < p2) {
								doubleLog = max<double>(p1, p2);
								if (p1 >= p2) bPowerPower = true;	//같으면 리스트의 첫번째를 선택
								else bPowerPower = false;
								first = i; second = j; third = k;
							}
						}
						else if (type == 1) {
							if (v[i] <= 1.0) continue;
							double p1 = v[k] * log(v[j]) + log(log(v[i]));
							double p2 = log(v[j]) + log(v[k]) + log(log(v[i]));
							if (doubleLog < p1 || doubleLog < p2) {
								doubleLog = max<double>(p1, p2);
								if (p1 >= p2) bPowerPower = true;
								else bPowerPower = false;
								first = i; second = j; third = k;
							}
						}
						else {	//type == 2
							double inverse = 1.0 / v[i];
							double p1 = v[k] * log(v[j]) + log(log(inverse));
							double p2 = log(v[j]) + log(v[k]) + log(log(inverse));
							if (doubleLog > p1 || doubleLog > p2) {
								doubleLog = min<double>(p1, p2);
								if (p1 <= p2) bPowerPower = true;
								else
									bPowerPower = false;
								first = i; second = j; third = k;
							}
						}
					}
	char a , b , c;
	a = char('x' + first);	//
	b = char('x' + second);
	c = char('x' + third);
	if (bPowerPower)
		cout << a << "^" << b << "^" << c;
	else
		cout << "(" << a << "^" << b << ")^" << c;
	return 0;
}
//1.0 2.0 4.0 오류남
//(y^x)^z	내꺼 : 7
//y^z^x		정답 : 6

// 통과함
int main() {
	double v[3];
	rep(i, 3) cin >> v[i];
	int type = -1;
	int overOne = 0;
	rep(i, 3) if (v[i] > 1.0) overOne++;
	if (overOne == 3) type = 0;
	else if (overOne == 0) type = 2;
	else type = 1;
	int first, second, third;
	
	double doubleLog = -numeric_limits<double>::max();	//min은 소수점으로 작은거임..음수가 아님!!!!
	if (type == 2) doubleLog = numeric_limits<double>::max();	//역수를 취함

	rep(i,6)	//i가 짝수: 괄호가 있는거
		rep(j,3)
			if (i/2 != j)
				rep(k,3)
					if (j != k && i/2 != k)
						if (type == 0 || type == 1) {
							if (type == 1 && v[i/2] <= 1.0) continue;
							double cand;
							if (i % 2 == 0)
								cand = v[k] * log(v[j]) + log(log(v[i/2]));
							else
								cand = log(v[j]) + log(v[k]) + log(log(v[i/2]));
							if (doubleLog < cand) {
								doubleLog = cand;
								first = i; second = j; third = k;
							}
						}
						else {	//type == 2
							double inv = 1.0 / v[i/2];
							double cand;
							if (i % 2 == 0)
								cand = v[k] * log(v[j]) + log(log(inv));
							else
								cand = log(v[j]) + log(v[k]) + log(log(inv));
							if (doubleLog > cand) {
								doubleLog = cand;
								first = i; second = j; third = k;
							}
						}
	bool bPowerPower = (first % 2 == 0);
						
	char a , b , c;
	a = char('x' + first/2);
	b = char('x' + second);
	c = char('x' + third);
	if (bPowerPower)
		cout << a << "^" << b << "^" << c;
	else
		cout << "(" << a << "^" << b << ")^" << c;
	return 0;
}


http://codeforces.com/contest/622/problem/C
//cin, cout 을 쓰면 1000ms 초과함 ... TRE발생 !!!!
//printf, scanf 사용하니 170ms 걸리면서 통과...제길...
int main() {
	//while (true) {
	int n; cin >> n;
	int q; cin >> q;
	vi arr(n);
	//rep(i, n) cin >> arr[i];
	rep(i, n) scanf("%d", &arr[i]);
	vpii arr2(n);
	rep(i, n) {
		if (i == 0)
			arr2[i].first = 0;
		else {
			if (arr[i - 1] == arr[i])
				arr2[i].first = arr2[i - 1].first;
			else
				arr2[i].first = i;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1)
			arr2[i].second = n - 1;
		else {
			if (arr[i + 1] == arr[i])
				arr2[i].second = arr2[i + 1].second;
			else
				arr2[i].second = i;
		}
	}
	rep(i, q) {
		int left, right; //cin >> left >> right;
		scanf("%d%d", &left, &right);
		left--; right--;
		int x; //cin >> x;
		scanf("%d", &x);
		int sol;
		if (arr[left] != x) sol = left;
		else if (arr2[left].second >= right) sol = -2;//for -1
		else sol = arr2[left].second + 1;
		sol++;
		//cout << sol << endl;
		printf("%d\n", sol);
	}

	//}
	return 0;
}
//입력의 값은 200이하, 소수첫째자리가 한계였기에 이 코드는 absolute equal 없이 돌릴수 있었다.
"이중로그를 취하고 싶은데 음수가 로그의 인자로 올수 없어서 제하는 방법(버림, 역수취함)을 기억해라"

int main() {
	cout << setw(3) << 3 << endl;					//  3
	cout << setw(5) << 5 << endl;					//    5
	cout << setw(3) << setfill('g') << 3 << endl;	//gg3
	cout << setfill('k') << 3 << endl;				//3
	cout << setfill('0') << 3 << endl;				//3
	cout << setw(3);
	cout << setfill('k') << 3 << endl;				//kk3
	cout << setfill('0') << 3 << endl;				//3

	cout << setw(3);
	cout << setfill('0') << 5 << 7 << endl;			//0057
	//setw가 효과 보는 건 딱 한번이구나, 글구 그때에만 setfill이 먹히는 구나
	return 0;
}

inline void solve() {
    int ans = h * 60 + m + a;
    ans %= 24 * 60;
    cout << setw(2) << setfill('0') << ans / 60;
    cout << ":";
    cout << setw(2) << setfill('0') << ans % 60;
    cout << endl;
}


http://codeforces.com/blog/entry/23196
// 최대 12가지의 크기를 비교 => ((i, j, k)의 순열 : 6가지) * 2종류의 로그형식
케이스 나누기:
1) x, y, z 세계의 수가 모두 1보다 클때 : "더블로그를 사용한다"
	i^(j^k) ----로그---->			j^k * ln(i) -----로그-----> kln(j) + lnln(i)	// bPowerPower: 괄호없어도 동일한 식임: i^j^k
	(i^j)^k = i^(j*k) ----로그 ----> jkln(i) ----로그-----> ln(j) + ln(k) + lnln(i)

	// ln(i) 가 음수가 되면 망하겠군
2) x, y, z 중 일부(1개 or 2개)가 1보다 클때 : 
	1 이하(less than or equal to 1) 인 놈은 base에 들어가 봐야 의미없는 놈이 됨
	1 이상인 놈만 base로 한다.
	그뒤 1)케이스를 돌려도 무방하다. ln(i)가 음수만 아니면 두번째 로그 취할때
	"로그의 인자가 음수가 되지 않기 때문에"
3) x, y, z 세계의 수가 모두 1이하 일때 : 
	첫번째 로그를 취할때 음수가 튀어나오기에
	첫번째 로그를 취할 수(base)를 역수로 변경한다.
	그런다음 1)번을 돌린다. 다만 이번엔 작은 놈을 찾아야 한다.(역수이기 때문에)

	"(0.30)^0.4^0.5			>		(0.29)^0.4^0.5
	"1 / (100/30)^0.4^0.5	>		1 / (100/29)^0.4^0.5
	//분모만을 비교한다면
	"(100/30)^0.4^0.5		<		(100/29)^0.4^0.5

http://codeforces.com/contest/621/problem/E
문제상에서 합성된 숫자가 같아도 위치가 다르니 경우의 수는 증가함!!!!
3 2 1 2	//숫자카드가 3종류가 있고 그들중 중복포함 2장을 이어붙여 숫자를 만들때,
3 3 2	//2로 나누어 1이 남는 경우의 수를 구하라

33 % 2 = 1
33 % 2 = 1
32 % 2 = 0
33 % 2 = 1
33 % 2 = 1
32 % 2 = 0
23 % 2 = 1
23 % 2 = 1
22 % 2 = 0
"6가지"

잘못해석한 부분
33
32
23
22
"2가지" 로 오해했었다.

//http://codeforces.com/blog/entry/23196 : fushar 의 글임
//j는 열이 아닌 행번호를 가르킨다.
To simplify the explanation, it is assumed that all computations are done modulo
1,000,000,007.
First, note that the n given digits are not important -- what is important is the
occurences of each digit. Let occ[d] be the occurrences of digit d.

We will try solving this problem using DP. let 
dp[i][j] = the number of ways we can pick i digits such that the final modulo is j.
"i개의 숫자를 가지고 수행시 나머지가 j가 되는 갯수"

The base case is obviously dp[0][0] = 1.
For i > 0, the recurrence can be given as:
dp[i][j] = sum{ occ[d] * dp[i - 1][a] }, for all 1 <= d <= 9, and for each d, a 
is an integer 0 <= a < X where (a * 10 + d) % X = j. //j행임!!!!
"i-1개의 숫자로 만든 나머지가 a인 수에다가
" * 10 + d 를 한 결과가 j가 되는 경우의 수" !!!!(핵심)

(Intuitively, given a number consisting i - 1 digits that is a modulo x, we can form
a number consisting of i digits that is "a * 10 + d modulo X = j", by appending the
digit d.)

The final answer would be dp[B][K]. "숫자 B개를 사용해서 만든 나머지가 K인 갯수"
Unfortunately, this DP will get TLE as B can be up to 10^9.
To speed it up, we will use matrix exponentiation trick on the recurrence.

Suppose we have a vector F0 consisting of X elements, where
	 | dp[0][0]		|
	 | dp[0][1]		|
F0 = | .			| = 
	 | .			|
	 | dp[0][X - 1]	|

"Exercise 1": Compute the value of the elements F0'
Now, construct a X * X matrix T, in such a way that
F1 = TF0,
where
	 | dp[1][0]		|
	 | dp[1][1]		|
F1 = | .			|
	 | .			|
	 | dp[1][X - 1]	|

"Exercise 2": Compute the value of the elements of T
In a similar way, we can compute F2 = TF1 = T^2 * F0. now we want to compute
FB = T^B * F0, 
which is,
	 | dp[B][0]		|	
	 | dp[B][1]		|
FB = | .			|
	 | .			|
	 | dp[B][X - 1]	|
The answer will be ... FB[k], which is dp[B][K]
T^B can be computed in O(X^3 * logB) using exponentiation-by-squaring, 
which will fit the time limit.


//에디토리얼 풀이법 소스
input 
7 50 2 6		// 6으로 나누어 2가 나머지가 되어야한다.
1 2 3 4 1 1 2	//arr[]
matrix[T][(10 * T + arr[i]) % x]++
		 0 1 2 3 4 5	//정방행렬의 size는 mod인 x가 된다.!!!!
mat = 0    3 2 1 1
	  1  2 1 1     3
	  2  1     3 2 1
	  3    3 2 1 1
	  4  2 1 1     3
	  5  1     3 2 1

"T 가 3(행)일때 다음이 2(열)이 되는 경우의 수" mat[3][2] : [3][(3 * 10 + 2) % 6] // 3뒤에는 2가 두번 들어옴
"T 가 1(행)일때 다음이 5(열)이 되는 경우의 수" mat[1][5] : [1][(1 * 10 + 1) % 6] // 1뒤에는 1이 세번
" 1(행) 도 3개니 3*3 해서 9가 되어야 정상 아닌가?" // mat[0][1] = 3 이고 mat[0]은 최초시작임을 보삼.
// 위 mat는 맞는 예시다. 의심을 했군.. 첫 시작이 0부터니 안심해라.!!!!
mat[이전나머지][현재나머지] = 1, 2, ...//가능한 가짓수
mat^2[이전이전나머지][현재나머지]
mat^50[최초나머지][현재나머지]
//http://codeforces.com/contest/621/submission/15703295
using namespace std;
typedef long long ll;
typedef ll LL;

const int MX = 105;
const int M = 1000000007;
int x;
int r[MX][MX], a[MX][MX];
int tp[MX][MX];
int c[10];
inline void add(int& left, int right) {
	left += right;
	if (left >= M) left -= M;
}
void mul(int a[MX][MX], int b[MX][MX]) {
	int val;
	rep(i,x)
		rep(j,x) {
			val = 0;
			rep(k,x) add(val, LL(a[i][k]) * b[k][j] % M);
			tp[i][j] = val;
		}
	rep(i, x) rep(j, x) a[i][j] = tp[i][j];
}
int main() {
	while (true) {
		int n, b, k;	//n: arr크기, b: 수행햇수: 행렬곱셈 햇수
		scanf("%d%d%d%d", &n, &b, &k, &x);	//k 목표, x 나눌수
		while (n--) {
			int t; //1~9 까지의 수가 들어온다.
			scanf("%d", &t);
			c[t]++;
		}
		rep(i, x) // 왜 9까지 안해도 되는지 생각해보삼: % t 니까~
			rep(t, 10)
				add(a[i][(i * 10 + t) % x], c[t]);
		rep(i, x) r[i][i]++;
		for (; b; b /= 2) {	//매우 귀중한 패턴!!!! 외우라 외우라 외우라!!!!
			if (b & 1) mul(r, a);
			mul(a, a);
		}
		printf("%d\n", r[0][k]);
	}
	return 0;
}

"al_1(1권) 에서 두니발 메트릭스로 해결한 코드 한번 보삼!!!!"


//생각의 관점을 바꾸는 좋은 문제다!!!!
http://codeforces.com/contest/626/problem/C
a학생들은 각각 2블럭으로 쌓고 (혹은 2의 배수 블럭을 쌓고)
b학생들은 각각 3블럭으로 쌓음 (혹은 3의 배수 블럭을 쌓고)
a, b학생들은 쌓아가는 가정 중 같은 높이가 만들어지면 안됨
이 제약상황에서 전체를 쌓을때 가장 낮은 높이를 구하라

input
1083 724
output
2710 //내답은 3252 ㅠㅠ

// 좀만 간단하게 생각하면 될걸... 괜히 어렵게 생각해서 망함.
// 깊게 보니 어렵게 느껴진다... ㅠㅠ!!!!
// n, m 이 1000000이하라서 문제풀기 편함
http://codeforces.com/blog/entry/23522
const int MAX = 5000000;
int main() {
	int n, m; cin >> n >> m;	// a쪽은 n번 수행, b쪽은 m번 수행
	int i = 1;
	for (; i < MAX; ++i) {
		if (i / 2 >= n && i / 3 >= m
			&& i / 2 + i / 3 - i / (2 * 3) >= (n + m))	// !!!!
			break;
	}
	cout << i;
	return 0;
}
i가 답이 되기 위한 조건 n <= i/2 && m <= i/3 이어야하고 이 두식을 합한 n + m <= i/2 + i/3 에서 교집합(i/6)을 빼주자.

2 3 인 경우 
i = 7일때 : 7/2 + 7/3 - 7/(2*3) = 4임
i = 8일때 : 8/2 + 8/3 - 8/(2*3) = 5 임 // 답이됨.

6 4 인 경우
i = 12 일때 : 12/2 + 12/3 - 12/(2*3) = 8
i = 13 일때 : 13/2 + 13/3 - 13/(2*3) = 8
i = 14 일때 : 14/2 + 14/3 - 14/(2*3) = 9
i = 15 일때 : 15/2 + 15/3 - 15/(2*3) = 10
//만약 MAX, n, m이 훨신큰 숫자면 이분법으로 풀면된다. (사실 상수 O(1) 로도 풀린다만...)
http://codeforces.com/contest/626/submission/15993001 //종만이 형식으로 바꿔보자


http://codeforces.com/contest/626/problem/D
//!!!!좋은 문제
3라운드짜리 게임이 있음.
항아리에는 n개의 공이 있고 공들은 각각 다른 양수 번호를 가짐
// The second line contains n integers ai (1 ≤ ai ≤ 5000) — 
// the number written on the ith ball. It is guaranteed that 
// no two balls have the same number.
Andrew랑 Jerry는 항아리에서 공을 꺼내고 두공 중 높은 숫자를 가진 자가 승리함
각 라운드 마다 공은 원복해서(n개로 되돌려서) 승부함
3라운드 중 2라운드를 이기면 게임에서 승리한다.

Andrew 는 1,2 라운드를 이기고 Jerry는 3라운드를 이긴다.
따라서 Andrew 가 게임을 승리한다.
그러나 Jerry는 이 시스템에대해 만족 못한다. Jerry는 종종 토탈점수가 높은데도
게임에서 진다고 토를 단다.

확률을 구해라(Jerry 가 Andrew 보다 3개의 숫자 합이 높을, 앞의 2경기는 Andrew가 이김)
const int INF = 987654321;
int arr[2000];
int dt1[5001];
long long dt2[10001];
int main() {
	int n; cin >> n;
	rep(i, n) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	rep(i, n)
		rep2(j, i + 1, n)
			dt1[arr[j] - arr[i]]++;	//dt1[x]: x만큼 차이나는 쌍의 갯수
	rep(i, 5000)
		rep(j, 5000)
			dt2[i + j] += dt1[i] * dt1[j];
			//3 + 2만큼 차이나는 경우의 수: 3차이 갯수 * 2차이 갯수
			//2 + 3만큼 차이나는 경우의 수: 2차이 갯수 * 3차이 갯수
			//...
	//x 가 y보다 작다는 조건하에 dt2[x] * dt1[y]
	long long cases = 0;
	rep2(i, 1, 5000) {	//dt2의 인덱스 5000 넘어가는 건 필요가 없음
		dt2[i] += dt2[i - 1];	//!!!! //long long 형이 되어야 겠군 int로 하면 오류
		cases += dt2[i - 1] * dt1[i];
	}
	double sol = double(cases) * 8.0 / (n*(n - 1)) / (n*(n - 1)) / (n*(n - 1));
	//곱하기 8하는 이유
	//2개를 선택할때 한쪽이 커야되므로 한경기당 경우의 수가 n*(n-1) / 2 가 된다.
	printf("%.7f", sol);
	return 0;
}
cubelover가 푼거
http://codeforces.com/contest/626/submission/15993896
#include <cstdio>
#include <algorithm>
using namespace std;
int a[2002];
int c[5005];
long long d[10001];
int main()
{
	long long r = 0;
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	for (i = 1; i < n; i++) for (j = 0; j < i; j++) c[a[i] - a[j]]++;
	for (i = 0; i < 5000; i++) for (j = 0; j < 5000; j++) d[i + j] += (long long)c[i] * c[j];
	for (i = 1; i < 5000; i++)
	{
		d[i] += d[i - 1];
		r += d[i - 1] * c[i];
	}
	printf("%.12f", 8.*r / n / n / n / (n - 1) / (n - 1) / (n - 1));	//!!!!이래도 double 로 출력되구나
}

	long long a = 123456789123456789;
	printf("%d\n", a);	//-1395630315: 깨진다.
	printf("%I64d\n", a);	//123456789123456789




626E-Simple Skewness (평균 - 중간값: 최대값을 찾아라)
We can show that any subset with maximal simple skewness should have odd size.
(otherwise we drop the larger middle element: this decreases the median by more than
it decreases the mean, assuming the mean is larger than the median)
평균이 중간값보다 크다고 가정할때
짝수인 경우 중간 요소중 두번째(med2)는 평균 - 중간값((med1+med)/2) 의 값을 작게함
//decreases라는 단어가 오해를 굉장히 유발시키네
		1 2 10		1 2 3 10	1 2 4 10	1 2 5 10	1 2 9 10
평균	13/3		16/4		17/4		18/4		22/4
중간값	2			2.5			3			3.5			5.5
//평균이 커지는 것보다 중간값이 더 빨리 커짐을 확인할 수 있다.
"평균은 더해진 수에 전체 갯수를 나눠야 하지만"
"중간값은 앞, 뒤 즉 2로 나누면 되기 때문이다"

Let's' fix the median at Xi(in the sorted list), and set the size of the set to
2j + 1. We'd' like to maximize the mean, so we can greedily choose the largest
j elements below the median and the largest j elements above teh median:
Xi-j, ..., Xi-1 and Xn-j+1, ..., Xn.

Now, notice that by increasing j by 1, we add in the elements Xi-j-1 and Xn-j, which
decreases as j increases. Thus, for a fixed i, the overall mean is bitonic in j
(it increases then decreases), so we can binary search on the marginal utility to
find the optimum.
//종이에 적은거 옮겨적자

참고: 한쪽은 증가, 한쪽은 감소 수열
bitonic mergesort//Ken Batcher 근래에 고안된 소팅 알고리즘
https://www.youtube.com/watch?v=GEQ8y26blEY
//조건 assending part, desending part 둘로 나눠져 있다.!!!!
11	13	16	35	15	4	3	1	
o---------------o
	o---------------o
		o---------------o
			o---------------o
11				15
	4				13
		3				16
			1				35

11	4	3	1 |	15	13	16	35
o-------o		o-------o
	o-------o		o-------o
3		11		15		16
	1		4		13		35

3	1 |	11	4 |	15	13 |16	35
o---o	o---o	o---o	o---o
1	3	4	11	13	15	16	35

//아래껀 안되는데... 조건이 있나보다. //바꿔야 한다. 바이토닉 폼으로 말이지
99	3	13	8	7	6	12	1	//바이토닉 이 아니다.



//F 문제는 일단 해석도 안되고 있다... GG 3일 고민해도 답 안나옴 ㅠㅠ
그룹으로 나눌때 각 그룹간의 imbalance 의 합이 최대 k 이하로 나눌수 있는 경우의 수를 구

http://codeforces.com/contest/626/problem/F //Group Projects //dp
This is a dynamic programming problem. Notice that the total imbalance of the groups
only depends on which students are the maximum in each group and which are the minimum
in each group.

We thus can think of groups as intervals bounded by the minimum and maximum student.
Moreover, the total imbalance is the sum over all unit range of the number of intervals
covering that range. We can use this formula to do our DP.

If we sort the students in increasing size, DP state is as follows:
the number of students processed so far,
the number of g groups which are currently "open" (have a minimum but no maximum),
and the total imbalance k so far.
dp[현재까지 처리된 학생][닫히지 않은 그룹수][지금까지의 불균형 합]

For each student, we first add appropriate value to the total imbalance (g times
the distance to the previous student), and then either put the student in his
own group (doesn't' change g), start a new group (increment g), add the student to
one of the g groups (doesn't' change g), or close one of the g groups (decrement g).

Runtime: O(n^2 * k)
//해석에 참고할 좋은 사이트. 그림으로 설명되어 있음. 공부해보자(일본사이트 정리잘되어 있음)
https://translate.google.co.kr/translate?hl=ko&sl=ja&u=http://pekempey.hatenablog.com/entry/2016/02/16/021555&prev=search

"dp[현재까지 처리된 학생][닫히지 않은(열린) 그룹수][지금까지의 불균형 합] = 경우의 수"
long long dp[2][205][1050], t, ret = 0;
int a[205];
const int mod = 1e9 + 7;
//해석을 위해 mod를 취하지는 않았음
int main() {
	int x, n, k, i, j, temp;
	cin >> n >> k;	// n: 학생수(그룹의 최대값), k: 불균형 합의 최대 허용치
	for (i = 1; i <= n; ++i) cin >> a[i];
	int d = 0;
	sort(a + 1, a + 1 + n);
	dp[0][0][0] = 1;// 아무 학생도 진행안하고 열린그룹이 없고 불균형이 0인 경우의 수 : 1
	for (i = 0; i < n; ++i) {
		d^=1;
		memset(dp[d], 0, sizeof(dp[d]));	// 다차원 배열의 일부를 초기화 하는 방법 !!!!
		for (j = 0; j <= i; ++j)	//열린 그룹의 최대가능 한 수
			for (x = 0; x <= k; ++x)	// 불균형 합
				if (t = dp[d^1][j][x]) {
					temp = x + j * (a[i + 1] - a[i]);
					if (temp > k) break;
					//원 그룹들 j개중 한놈에 새로운 숫자를 넣는 경우의 수(j개)
					"+1은 어디서 발생하노"!!!!
					"단일 한개짜리 그룹(열자마자 닫히는 놈)을 의미하는군
					dp[d][j][temp] += t * (j + 1);
					if (j)
						dp[d][j - 1][temp] += t * j;	//닫을수 있는 그룹은 j개중 1개
					dp[d][j + 1][temp] += t;	// 새로 열리는 그룹은 1개
				}
	}
	for (i = 0; i <= k; ++i)
		ret += dp[d][0][i];
	cout << ret << endl;
}
long long dp[2][205][1050], t, ret = 0;
int a[205];
const int mod = 1e9 + 7;
int main() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	dp[0][0][0] = 1;	//현 처리된 학생 0명(현 그룹수 0), 현재 열린 그룹수 0개, 지금까지 불균형 합 0
						//인 경우의 수는 1개
	int d = 0;
	for (int i = 0; i < n; ++i) {	// 그룹의 최대 갯수: 학생수만큼 돌린다. 
		d ^= 1;
		memset(dp[d], 0, sizeof(dp[d]));
		for (int j = 0; j <= i; ++j)	//열린 그룹의 최대가능 한 수
			for (int x = 0; x <= k; ++x)	//불균형 합
				if (dp[d^1][j][x]) {
					int t = dp[d^1][j][x];
					temp = x + j *(a[i + 1] - a[i]);	//j개의 열린 그룹 * 새로 추가로 인한 불균형
														// 정렬을 하는 중요한 이유다.!!!!
								// j 가 0: 열린그룹이 없으면 temp는 x 그대로고
								// dp[d][0][temp] += dp[d^1][0][x] // 단일 그룹 추가
								// dp[d][0][temp] += dp[d^1][1 - 1][x - (a[i+1] - a[i])]	// 한개 열린거 닫힘
					if (temp > k) break;
					//원 그룹들 j개중 한놈에 새로운 숫자를 넣는 경우의 수(j개)
					"+1은 어디서 발생하노"!!!!
					"단일 한개짜리 그룹(열자마자 닫히는 놈)을 의미하는군
					dp[d][j][temp] += t * (j + 1);	

					if (j)
						dp[d][j - 1][temp] += t * j;//닫을 수 있는 그룹은 j개 중 1개
					dp[d][j + 1][temp] += t;	//새로 열리는 그룹은 1개
				}
	}
	for (int i = 0; i <= k; ++i)
		ret += dp[d][0][i];
	cout << ret << endl;
}
// <시뮬> //
학생수가 7명이고
각 학생의 능력치는
2 4 7 1 9 1 3 이라 할 때

정렬하면
idx 1	2	3	4	5	6	7
	1	1	2	3	4	7	9 가 된다.
a  ---             ---
b	   --- ---             ---
c	           ---     ---

위와같이 그룹핑한 경우 (a, b, c 세개로)
b의 경우 불균형을 계산함에 있어 세번째 값인 2 는 아무런 영향을 주지 않는다. !!!!

// 두번째 1까지 처리된 경우
// 2를 처리 할때
dp[3][0][temp]	+= dp[2][0][0] * (0 + 1);	// (열린그룹수: 0 + 단일 한개짜리 그룹)
				+= dp[2][1][0] * 1			// (열린그룹수: 1) 를 닫아야 하므로

dp[3][1][temp]	+= dp[2][1][0] * (1 + 1);	// (열린그룹수: 1 + 단일 한개짜리 그룹)
				+= dp[2][2][0] * 2			// (열린그룹수: 2) 중 1개를 닫는다.
				+= dp[2][0][0]				// 새로운 그룹을 개설(open) 한다.

"단일 한개짜리 그룹은 open + close 가 합친거라 보면 된다"



//줄세우기
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1144&sca=3050
예를 들어, 7명의 아이들이 다음과 같은 순서대로 줄을 서 있다고 하자.

3 7 5 2 6 1 4

아이들을 순서대로 줄을 세우기 위해, 먼저 4번 아이를 7번 아이의 뒤로 옮겨보자. 그러면 다음과 같은 순서가 된다.

3 7 4 5 2 6 1

이제, 7번 아이를 맨 뒤로 옮긴다.

3 4 5 2 6 1 7

다음 1번 아이를 맨 앞으로 옮긴다.

1 3 4 5 2 6 7

마지막으로 2번 아이를 1번 아이의 뒤로 옮기면 번호 순서대로 배치된다.

1 2 3 4 5 6 7

"옮겨지는 수 = 전체수 - 정렬된 부분수열 갯수"//내가 못품
//생각을 하자! 유도해 낼수 있어야 한다. 정렬된 놈은 고정 시키고 나머지 놈들만 이동 시킨다.
int n;
vi arr;
int cache[202];
int dp(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		int cand = 0;
		if (start == -1 || arr[start] < arr[next])
			cand = dp(next) + 1;
		ret = max(ret, cand);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	arr.resize(n);
	rep2(i, 0, n) 
		cin >> arr[i];
	int lis = dp(-1);	//맨앞에 -1을 원소로 추가한다.(외부 for문 돌리기 싫거든)
	lis = lis - 1; //-1 원소 추가 했으니 그 개수인 1을 lis에서 빼줘야 한다.
	cout << n - lis;
	return 0;
}

//색종이 올려 놓기
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=782&sca=3050
"직관으로 그냥 짯는데 통과 되니 의아 스럽다"
"핵심은 가로 세로 길이를 한쪽이 긴 상태로 회전 시키고 정렬해서 처리하는 것임"
int n;
vpii arr;
int cache[1001];
int dp(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		int cand = 0;
		if (start == -1 || 
			(arr[start].first <= arr[next].first && arr[start].second <= arr[next].second))
			cand = dp(next) + 1;
		ret = max(ret, cand);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	arr.resize(n);
	rep(i, n) {
		int a, b; cin >> a >> b;
		if (a < b) swap(a, b);
		arr[i].first = a;
		arr[i].second = b;
	}
	sort(arr.begin(), arr.end());
	int sol = dp(-1) - 1;
	cout << sol;
	return 0;
}
색종이들을 쌓을 때 위의 색종이가 아래의 색종이를 벗어나지 않게 쌓을 수 있는
최대 색종이 장수를 구하는 문제로, 동적 계획법을 이용하여 해결할 수 있다. 
먼저 두 색종이를 올려놓을 수 있는 조건을 살펴보자. 색종이 (a, b)를 색종이 (c,
d) 위에 올려놓을 수 있으려면, a<=c 그리고 b<=d를 만족하거나 a<=d 그리고
b<=c를 만족해야 한다. 이 조건을 조금 더 정리해 보면 색종이 (c, d)의 짧은 변이
색종이 (a, b)의 짧은 변보다 작거나 같아야 하고, 색종이 (c, d)의 긴 변도 마찬가
지로 색종이 (a, b)의 긴 변보다 작거나 같아야 한다는 것을 알 수 있다. 
이제 각 색종이에 대해 두 변의 길이 중 짧은 것을 앞으로 오도록 한 뒤, 모든 색
종이를 두 변의 길이 중 짧은 변의 길이가 증가하는 순서로 정렬한다. 만일 짧은
변의 길이가 같은 경우에는 다른 변의 길이가 작은 것이 앞에 오도록 한다. 이렇게
하여 색종이 (a, b)를 색종이 (c, d) 위에 올려놓을 수 있는 한 가지 경우, 즉 a<=c
그리고 b<=d를 만족하는지만 확인하면 된다. 
이와 같이 색종이를 정렬하여 순서대로 색종이가 쌓여 있는 경우를 생각하면, 짧
은 변의 길이에 대한 조건은 자동적으로 해결된다. 다음으로 긴 변의 길이에 대한
조건을 처리하기 위해서는 긴 변의 길이를 가지고 만들어지는 수열에서 증가하는
가장 긴 부분 수열을 구하면 된다. 
긴 변의 길이를 나타내는 수열을 L[1], ..., L[n]이라고 놓자. 그리고 동적 계획법을
위한 배열 D[i]를 ‘1번부터 i번까지의 색종이를 이용하여 색종이를 쌓아 나가되 i번
색종이를 가장 아래에 놓을 때 최대로 쌓을 수 있는 색종이의 수’로 정의하자. 그러
면 자연스럽게 D[1]=1임을 알 수 있고, D[i]를 채우기 위해서는 L[k]<L[i]인 1<=k<i
들에 대해 D[k]+1 중 최대값을 선택하면 된다. 이렇게 하면 k의 색종이를 위에 놓
는 경우의 조건이 만족되고, 이 때 그 위로는 D[k]만큼의 색종이를 더 쌓을 수 있
기 때문이다. 따라서 이와 같이 배열을 채운 후, 우리가 구하고자 하는 답은 D[i]들
중 가장 큰 값이 된다.

//배낭채우기2: 물건을 하나씩만 채울수 있음
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=561&sca=3050
//안보고 짰는데 다른 소스도 비슷한 형식이였군
http://www.sanfoundry.com/cpp-program-solve-knapsack-problem-using-dynamic-programming/
//재귀는 쉬워서 생략함
//i: 물건번호, j: 배낭 남은 용량
memo[i][j] = max{	memo[i - 1][j], 
					memo[i - 1][j - arr[i].first] + arr[i].second }
int memo[1001][10001];
int main() {
	int n; cin >> n;
	int w; cin >> w;
	vpii arr(n + 1);
	rep2(i, 1, n + 1) cin >> arr[i].first >> arr[i].second;

	memset(memo, 0, sizeof(memo));
	rep2(i, 1 , n + 1) {
		rep(j, w + 1) {
			memo[i][j] = memo[i - 1][j];	//물건 i를 선택하지 않는 경우
			if (j - arr[i].first >= 0)
				memo[i][j] = max(memo[i][j],
					memo[i - 1][j - arr[i].first] + arr[i].second);
		}
	}
	int sol = 0;
	rep(i, w + 1) sol = max(sol, memo[n][i]);
	cout << sol;
	return 0;
}
"슬라이딩 윈도우 적용"
int memo[2][10001];
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int n; cin >> n;
	int w; cin >> w;
	vpii arr(n + 1);
	rep2(i, 1, n + 1) cin >> arr[i].first >> arr[i].second;

	memset(memo, 0, sizeof(memo));
	rep2(i, 1 , n + 1) {
		rep(j, w + 1) {
			memo[i&1][j] = memo[(i - 1)&1][j];
			if (j - arr[i].first >= 0)
				memo[i&1][j] = max(memo[i&1][j],
					memo[(i - 1)&1][j - arr[i].first] + arr[i].second);
		}
	}
	int sol = 0;
	rep(i, w + 1) sol = max(sol, memo[n&1][i]);
	cout << sol;
	return 0;
}

//양팔저울
제18회 한국정보올림피아드 (2001.7.7) 초등부 문제 2
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=627&sca=3050
"어려웠는데 아무 힌트 없이 풀었다. 우히히히"
suffix, dp 문제 였다고 보임//코드포스에서 공부한게 도움이 되었네
추의 갯수 30개 이하: 각 추는 500 이하의 무게를 가짐
구슬의 개수 7 개 이하
구슬의 무게 0 <= Gi <= 40000

//add를 더한건 음수 처리용임
//추를 자기쪽에 더하냐 상대쪽에 더하냐에 따라 더하고 빼고로 나뉨(혹은 아예 제외하던가)
"memo[i][j] = OR{ memo[i-1][j], memo[i-1][j+chu[i]], memo[i-1][j-chu[i]] }
const int add = 15000;
bool memo[31][15001 + add];	//memo[15001 + add]; 만으로도 충분함
int main() {
	int n; cin >> n;
	vi chu(n + 1);
	rep(i, n) cin >> chu[i + 1];
	int g; cin >> g;
	vi guu(g);
	rep(i, g) cin >> guu[i];
	memset(memo, 0, sizeof(memo));
	memo[0][0 + add] = true;
	rep2(i, 1, n + 1) {
		rep(j, 30001) {
			memo[i][j] += memo[i - 1][j];
			if (j + chu[i] <= 30000)
				memo[i][j] += memo[i - 1][j + chu[i]];
			if (j - chu[i] >= 0)
				memo[i][j] += memo[i - 1][j - chu[i]];
		}
	}
	rep(i, g) {
		if (i) cout << " ";
		if (memo[n][guu[i] + add])
			cout << "Y";
		else
			cout << "N";
	}
	return 0;
}

//자동차경주대회
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=763&sca=3050
재귀는 짜긴 쉽지만 디버깅이 정말 어렵다. ㅠㅠ
const int INF = 987654321;
int maxL;
int n;
vi timeArr;
vi distArr, pDistArr;
int cache[101]; int choice[101];
int dp(int here) { 
	if (here == n) return 0;
	//return 시 cache[here]를 세팅 안하면 나중에 dp_()함수에서 잘못된 결과를 리턴함 -1 같은...
	if (pDistArr.back() <= pDistArr[here] + maxL) { return cache[here] = timeArr[here]; }
	int& ret = cache[here];
	if (ret != -1) return ret;
	int minChild = INF;
	int next = here + 1;
	int select = -1;
	while (next != n && (pDistArr[next] - pDistArr[here] <= maxL)) {
		if (minChild > dp(next)) {
			minChild = dp(next);
			select = next;
		}
		next++;
	}
	choice[here] = select;
	ret = minChild + timeArr[here];	// 해가 되는 자식들의 정비시간 + 자신의 정비시간
	return ret;
}
int dp_(int& minStart) {
	memset(cache, -1, sizeof(cache));
	memset(choice, -1, sizeof(choice));
	int ret = INF;
	dp(0);
	rep(i, n) {
		if (pDistArr[i] <= maxL)
			if (ret > cache[i]) {
				ret = cache[i];
				minStart = i;
			}
	}
	return ret;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> maxL >> n;
	distArr.resize(n + 1);
	timeArr.resize(n);
	rep(i, distArr.size()) cin >> distArr[i];
	rep(i, timeArr.size()) cin >> timeArr[i];
	pDistArr = distArr;
	rep2(i, 1, distArr.size()) 
		pDistArr[i] += pDistArr[i - 1];
	int minStart = -1;
	int sol = dp_(minStart);
	if (sol == -1) { cout << 0; return 0; }
	cout << sol << endl;
	vi sol2;
	int nextChoice = minStart;
	while (nextChoice != -1) {
		sol2.push_back(nextChoice);
		nextChoice = choice[nextChoice];
	}
	cout << sol2.size() << endl;
	rep(i, sol2.size()) {
		if (i) cout << " ";
		cout << sol2[i] + 1;
	}
	return 0;
}
//이거 for문으로 통과 시켜 보자.
한번 정비를 받고 최대 140km 을 갈수 있다.
최소 총 정비시간과 방문하는 정비소들을 구하여라
           5        10       4        11        7
출발 ----- 1 ------ 2 ------ 3 ------ 4 ------- 5 ------ 도착
      100     30       100      40        50        60

dp[here] = 정비소 here를 방문하는 것을 포함하여 1 ~ here 까지의 최소 총 정비시간
sl[here] = here 이전에 방문하는 정비소

int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int maxL, n; cin >> maxL >> n;
	vi dist(n + 1);
	rep(i, dist.size()) cin >> dist[i];
	vi time(n + 2, 0);
	rep2(i, 1, time.size() - 1) cin >> time[i];
	vi dp(n + 2);	//2: + begin + end
	vi sl(n + 2, -1); //이전에 선택한거 기록
	dp[0] = 0;
	for (int i = 1; i < dp.size(); ++i) {
		dp[i] = time[i];
		int hereDist = 0;
		int preIndex = i - 1;
		int cand = 987654321;
		while (preIndex >= 0) {
			hereDist += dist[preIndex];
			if (hereDist > maxL) break;
			if (cand > dp[preIndex]) {
				cand = dp[preIndex];
				sl[i] = preIndex;
			}
			preIndex--;
		}
		dp[i] += cand;
	}
	cout << dp.back() << endl;
	vi ret;
	int select = sl.back();
	while (select != -1 && select != 0) { //0은 출발지라서 제외시킨다.
		ret.push_back(select);
		select = sl[select];
	}
	reverse(ret.begin(), ret.end());
	if (ret.size())
		cout << ret.size() << endl;
	rep(i, ret.size()) cout << ret[i] << " ";
	return 0;
}

//가장 높은 탑쌓기

밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다.
탑은 벽돌을 한 개씩 아래에서 위로 쌓으면서 만들어 간다. 
아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프로그램을 작성하시오. 
 
(조건1) 벽돌은 회전시킬 수 없다. 즉, 옆면을 밑면으로 사용할 수 없다.
(조건2) 밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
(조건3) 벽돌들의 높이는 같을 수도 있다.
(조건4) 탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
(조건5) 무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.
"lis의 응용력이 많다는걸 깨닳았다"
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=811&sca=3050
// 벽돌갯수 최대 100개
//vt a, w, i;	//밑면넓이, 무게, 원본인덱스
vector<pair<pair<int, int>, int>> vt;
vi h; //원본 순서대로의 높이
int cache[102];
int nextSL[102]; //다음 벽돌 번호
int dp(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	if (start != -1) ret = h[vt[start].second];
	rep2(next, start + 1, vt.size()) {
		int cand = 0;
		// first.first 에 대해선 이미 정렬되어 있으므로 고려 안해도 된다. !!!!
		if (start == -1 || vt[start].first.second < vt[next].first.second)
			cand = dp(next);
		if (start != -1) cand += h[vt[start].second];
		if (ret < cand) {
			ret = cand;
			nextSL[start + 1] = next;
		}
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	memset(nextSL, -1, sizeof(nextSL));
	int n; cin >> n;
	vt.resize(n);
	h.resize(n);
	rep(i, n) {
		//밑면넓이, 높이, 무게
		cin >> vt[i].first.first >> h[i] >> vt[i].first.second;
		vt[i].second = i;	//캬 내가 생각해도 쥐기는 방법이데 덕분에 map을 사용안해도 됨
	}
	sort(vt.begin(), vt.end()); //밑면 넓이, 무게 순으로 정렬: 작은 넓이, 무게가 앞에 옴
	int sol = dp(-1);
	vi sol2;
	int select = nextSL[-1 + 1];
	while (select != -1) {
		int index = vt[select].second;
		sol2.push_back(index);
		select = nextSL[select + 1];
	}
	cout << sol2.size() << endl;
	//reverse(sol2.begin(), sol2.end())	//거꾸로 처리 했으니 reverse 할 필욘 없다.
	//위에서 부터 출력
	rep(i, sol2.size()) {
		if (i) cout << endl;
		cout << sol2[i] + 1;
	}
	return 0;
}
//윗 소스가 통과는 했는데 내가 정확하게 맞는지 여부를 확인하고자 검색한 사이트
http://cafe.daum.net/_c21_/bbs_search_read?grpid=VDxm&fldid=FYFT&datanum=22


//소형기관차 문제//답보고 품 ㅠㅠ
"매우 좋은 dp문제" !!!! 유형을 기억해라 (n개를 특정크기의 3 묶음으로 묶는 문제)
"크게 뭉쳐놓은 캐시를 생각하자"
"dp[i][j]: 1번부터 j번 객차에 대해, 소형기관차를 i개 이하로 이용해서 최대 운송 손님수"
https://www.digitalculture.or.kr/koi/showOlymPiadDissentDetail.do
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=298&sca=3050
int dp[4][50001];
int psum[50001];
int n;
int k;
int rangeSum(int left, int right) {
	int temp = (left == 0) ? 0 : psum[left - 1];
	return psum[right] - temp;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> n;
	vi arr(n + 1);
	arr[0] = 0;
	rep2(i,1, arr.size()) cin >> arr[i];
	cin >> k;
	rep(i, arr.size()) 
		psum[i] = (i == 0) ? arr[i] : arr[i] + psum[i - 1];
	rep2(i, 1, 4)
		rep2(j,1, n + 1) {
			dp[i][j] = dp[i][j - 1];
			//중요 특징!!!!
			if (j - k >= 0)	// 각 소형기관차는 객실 k개만큼 포함하는 정답이 존재한다.
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k]
					+ rangeSum(j - k + 1, j));
			//else
			//	dp[i][j] = max(dp[i][j], rangeSum(1, j));	//없어도 돌아감.
			// 문제에서 k * 3 <= n 을 보장 하기 때문이다.
		}
	cout << dp[3][n];
	return 0;
}
//i: 소형기관차, j: 1 ~ j까지의 객식들
//dp[i][j] = min{	dp[i - 1][j - k] + sum(arr[j-k+1] ~ arr[j]),
//					dp[i][j - 1] }
//dp[0][j]: 기관차가 한대도 없는 경우 태울 수 있는 손님은 0명이다.
//dp[i][j]: 1번부터 j번 객차에 대해, 소형기관차를 i개 이하로 이용해서 최대 운송 손님수
"j번 객차가 마지막 소형기관차에 포함되는 경우
//dp[i][j] = dp[i - 1][j - k] + sum(arr[j-k+1] .. arr[j]);
"j번 객차가 마지막 소형기관차에 포함되지 않은 경우
//dp[i][j] = dp[i][j - 1];
마지막 답은 "dp[3][n]"이 된다.



동전 바꿔주기//답보고 품 ㅠㅠ
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=657&sca=3050
지폐의 금액		0 < T <= 10000
동전의 종류		0 < K <= 100
각 동전의 금액	0 < Pi <= T
각 동전의 갯수	0 < Ni <= 1000
"동전 교환 방법의 가짓수를 구하라"
풀이
이 문제는 동전에 대한 정보가 주어졌을 대, 지폐를 동전으로 교환하는 방법의 경우
의 수를 계산하는 문제이다. 가능한 답의 크기가 매우 커질 수 있으므로 모든 경우를
직접 하나하나 해보는 것은 불가능하고, 경우의 수를 효율적으로 구하는 방법을 선택
해야 한다. 이러한 방법의 하나로 동적 계획법을 선택할 수 있다. 
이를 위해서 
!!!!"D[i][j]를 i번째 동전까지 사용했을 때 j원을 교환할 수 있는 경우의 수"
로 정의한다. 이제 p[i]원짜리 동전을 쓰지 않는 경우, 한 개 쓰는 경우, ..., n[i]개 쓰
는 경우를 각각 생각해 보면 각 경우에 
"D[i][j]는 D[i-1][j] + D[i-1][j-p[i]] + ... +D[i-1][j-n[i]×p[i]]가 된다. 
이 때 이러한 경우가 가능해야 하므로, 물론 j-k×p[i]가 양수인 경우에만 고려해 주면 된다. 
일관된 처리를 위해서는 D[0][0] = 1로 초기화해 주어야 한다. 
시간을 줄이기 위해서는 j를 0부터 T까지 모두 고려하는 것이 아니라, 
"현재 교환할 수 있는 가장 많은 액수까지만 보도록 해 불필요한 반복문을 돌지 않도록 하면 된다." 
또한 메모리 사용량을 줄이기 위해서는, D[i]가 D[i-1]만 참조한다는 것을 고려하여
일차원 배열 두 개만을 가지고 구현하면 된다.

"D[i][j]를 i번째 동전까지 사용했을 때 j원을 교환할 수 있는 경우의 수"
"D[i][j]는 D[i-1][j] + D[i-1][j-p[i]] + ... +D[i-1][j-n[i]×p[i]]가 된다. 
//나도 이 생각은 했지만 bigO(동전종류 * 지폐금액 * 동전갯수) = 100*10000*1000
// = 10억이 되니 타임오버 날거라 봐서 후보에서 제외시켰는데
//의외로 성능항상 부분들이 많이 있었구나.(마치 조합 탐색처럼 성능 향상시킴)
"!!!! 깨닳을 점: 소스도 3중 for문이라 시간이 많이 걸릴줄 알았는데 의외로 빠름"
"50원짜리 동전은 최대한 많이 써봐야 200개 사용가능
"100원짜리 동전은 최대한 많이 써봐야 100개 사용가능
"답이 2^32: 20억을 넘지 않는다고 했음"
"최악의 케이스로 테스트해도 전체 forCnt가 185425878 이었음요: 바로 1초내 수행했음"
10000
100
1 1000
2 1000
...
100 1000
이 문제에선
D[i+1][j + 동전] += D[i][j] 이런식 구현은 가지치기가 힘들어 런타임 시간이 많이 걸림
``
20	//지폐
3	//동전수
5 3	//동전의 가치와 갯수
10 2
1 5
int memo[101][10001];
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int t; cin >> t;
	int k; cin >> k;
	vi pArr(k + 1);
	vi nArr(k + 1);
	rep2(i, 1, k + 1) 
		cin >> pArr[i] >> nArr[i];
	memo[0][0] = 1; //동전을 하나도 사용하지 않고 0원을 교환하는 경우의 수
	rep2(i, 1, k + 1) {
		rep2(j, 0, 10001) {
			memo[i][j] = memo[i - 1][j];
			rep2(iter, 1, nArr[i] + 1) {
				if (j < iter * pArr[i]) break; //가지치기시 81ms가 걸림
											//continue; 로 한 경우 761ms로 힘겹게 통과
				memo[i][j] += memo[i - 1][j - iter * pArr[i]];
			}
		}
	}
	cout << memo[k][t];
	return 0;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int t; cin >> t;
	int k; cin >> k;
	vi pArr(k + 1);
	vi nArr(k + 1);
	rep2(i, 1, k + 1)
		cin >> pArr[i] >> nArr[i];
	memo[0][0] = 1;
	rep2(i, 1, k + 1) {
		rep2(j, 0, t + 1) {	//교환액수t를 넘어간 건 계산할 필요 없다 이렇게 하니 3ms나옴
			memo[i][j] = memo[i - 1][j];
			rep2(iter, 1, nArr[i] + 1) {
				if (j < iter * pArr[i]) break;
				memo[i][j] += memo[i - 1][j - iter * pArr[i]];
			}
		}
	}
	cout << memo[k][t];
	return 0;
}
https://www.acmicpc.net/problem/2624 에 똑같은 문제 있다.
3중for를 2중for 로 바꾸는 방법 알아보세 : 이건 아직 못찾겠다. 
	프로그래밍 콘테스트 챌린징 로드북은 비슷한데 다른 문제임
2중배열을 썼는데 갯수제한없는 코인 문제처럼 1차원 배열로 처리하는 방안은 없는가 : 백준에 있다.



" 왜 위에건 2중 배열이고 아래건 1차원 배열인지 고찰하라!!!!
// 동전의 갯수가 정해지지 않은(무한대) 문제랑 비교해보자
const int MOD = 1000000007;
int dp[5001];
int main() {
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int m, c; cin >> m >> c;	//m: 목표가, c: 동전종류
		vi arr(c);
		rep(i, c) cin >> arr[i];
		rep(i, c) {
			rep2(j, 1, m + 1) {
				if (j < arr[i]) continue;
				dp[j] += dp[j - arr[i]];	// 시작할땐 i - 1 까지 동전 처리된 dp[j]군
				dp[j] %= MOD;
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}
// 동전의 갯수가 무한대인 경우 사실 식은 이렇게 되겠지
dp[i][j] = sum{ dp[i - 1][j], dp[i][j - arr[i]]	}
i, j는 증가순으로 세팅되고
dp[i][j] 는 값이 덮여도 상관이 없음(슬라이딩윈도우 보는 기분...)
"고로 일차원 배열로 변경가능"
//2차원 배열로 푼거 45ms 걸림
const int MOD = 1000000007;
int dp[501][5001];
int main() {
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		//dp[0][0] = 1;
		int m, c; cin >> m >> c;	//m: 목표가, c: 동전종류
		vi arr(c);
		rep(i, c) cin >> arr[i];
		rep(i, c) {
			dp[i][0] = 1;
			rep2(j, 1, m + 1) {
				if (i != 0)
					dp[i][j] = dp[i - 1][j];
				if (j < arr[i]) continue;
				dp[i][j] += dp[i][j - arr[i]];	// 이전값을 활용했네
				dp[i][j] %= MOD;
			}
		}
		cout << dp[c-1][m] << endl;
	}
	return 0;
}
int dp[501][5001];
int main() {
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc,cs) {
		memset(dp, 0, sizeof(dp));
		int m, c; cin >> m >> c;
		vi arr(c + 1);2016-06-17
		rep(i,c + 1) cin >> arr[i + 1];
		dp[0][0] = 1;
		rep2(i, 1, c + 1) {
			rep2(j,1,m+1) {
				dp[i][j] = dp[i - 1][j];
				rep2(iter, 1, INF) {
					if (j < iter * arr[i]) break;
					dp[i][j] += dp[i - 1][j - k * arr[i];
				}
			}
		}
		cout << memo[c][m] << endl;
	}
	return;
}
좀더 자세히 풀어쓰면 이래된다. (통과됨 단 1041ms 나 걸림 기존보다 훨신 오래 걸림)
const int INF = 987654321;
const int MOD = 1000000007;
int dp[501][5001];
int main() {
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		int m, c; cin >> m >> c;
		vi arr(c + 1);
		rep(i, c) cin >> arr[i + 1];
		dp[0][0] = 1;
		rep2(i, 1, c + 1) {
			rep2(j, 0, m + 1) {
				dp[i][j] = dp[i - 1][j];
				rep2(iter, 1, INF) {	// 무한의 갯수
					if (j < iter * arr[i]) break;
					dp[i][j] += dp[i - 1][j - iter * arr[i]];
					dp[i][j] %= MOD;
				}
			}
		}
		cout << dp[c][m] << endl;
	}
	return 0;
}
다시비교해보자 "똑같네용"
20	//지폐
3	//동전수
5 3	//동전의 가치와 갯수
10 2
1 5
int memo[101][10001];
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int t; cin >> t;
	int k; cin >> k;
	vi pArr(k + 1);
	vi nArr(k + 1);
	rep2(i, 1, k + 1) 
		cin >> pArr[i] >> nArr[i];
	memo[0][0] = 1; //동전을 하나도 사용하지 않고 0원을 교환하는 경우의 수
	rep2(i, 1, k + 1) {
		rep2(j, 0, 10001) {
			memo[i][j] = memo[i - 1][j];
			rep2(iter, 1, nArr[i] + 1) {
				if (j < iter * pArr[i]) break; //가지치기시 81ms가 걸림
											//continue; 로 한 경우 761ms로 힘겹게 통과
				memo[i][j] += memo[i - 1][j - iter * pArr[i]];
			}
		}
	}
	cout << memo[k][t];
	return 0;
}



//색상환
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1525&sca=3050
//아래 코드는 80점 짜리.. 20개중 4개가 틀렸다고 나옴
const int MOD = 1000000003;
long long d[505][1001];
//memo[i][j] : 1~j 까지의 색중 인접하지 않은 색을 i만큼 선택할 수 있는 경우의 수
//memo[1][k] = k
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int n, k; cin >> n >> k;
	if (n < k * 2) { cout << 0; return 0; }
	if (n == k * 2) { cout << 2; return 0; }
	rep2(i, 1, n + 1) d[1][i] = i;
	rep2(i, 2, k + 1) 
		rep2(j, 1, n + 1) {
			d[i][j] = d[i][j - 2];	//1 ~ j-2 까지 i개가 선택된 경우의 수
			long long temp1 = 0, temp2 = 0, temp3 = 0;
			if (j > 2) temp1 = d[i - 1][j - 2];
			if (j > 3) temp2 = d[i - 1][j - 3];
			if (j > 3) temp3 = d[i - 1][j - 3] * 2;
			//temp1 : 1 ~ j-2 까지 i-1개가 선택된 경우의 수
			//temp2 : 1 ~ j-3 까지 i-1개가 선택된 경우의 수
			//temp1 - temp2: j-2를 포함하여 i-1개가 선택된 경우의 수
			//temp3 : d[i - 1][j - 3] 에 다가 j-1, j 번째 원소중 둘중 하나를 선택하면 
			//되기에 경우의 수는 2배 증가 시킨다.
			long long sum;
			//j-2를 포함한 i-1개가 선택된 경우 j-1, j 번째 원소중
			//j원소는 선택할 수 없기에 (temp1 - temp2)만큼 도로 빼야됨
			if (j == n) sum = temp3;
			else
				sum = temp1 - temp2 + temp3;
			d[i][j] += sum;
			d[i][j] += MOD;
			d[i][j] %= MOD;
		}
	cout << d[k][n];
	return 0;
}

첫째 줄에 N색상환에서 어떤 인접한 두 색도 동시에 선택하지 않고 K개의 색을 고를 수 있는
경우의 수를 1,000,000,003 (10억 3) 으로 나눈 나머지를 출력한다.
"헐 ㅅㅂ d[505][1002]로 크기 바꾸니까
"1000 5 에 대하여 정상동작 한다. 나머지도 다 통과함...
"답안보고 푸니까 뿌듯하다
const int MOD = 1000000003;
long long d[505][1001];
//memo[i][j] : 1~j 까지의 색중 인접하지 않은 색을 i만큼 선택할 수 있는 경우의 수
//memo[1][k] = 1~k 까지의 색중 인접하지 않은 색을 1만큼 선택할 수 있는 경우의 수
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int n, k; cin >> n >> k;
	if (n < k * 2) { cout << 0; return 0; }
	if (n == k * 2) { cout << 2; return 0; }
	rep2(i, 1, n + 1) d[1][i] = i;  
	rep2(i, 2, k + 1) 
		rep2(j, 1, n + 1) {
			"요기서 문제가 있었던 거였군 배열크기가 오버되었다면 이전 주소라 
			"1002 세팅시 소가 쥐잡은 격으로 정상 동작했었네..."
			if (j >= 2)	
				d[i][j] = d[i][j - 2];	//1 ~ j-2 까지 i개가 선택된 경우의 수 //a)
			long long temp1 = 0, temp2 = 0, temp3 = 0;
			if (j > 2) temp1 = d[i - 1][j - 2];
			if (j > 3) temp2 = d[i - 1][j - 3];
			if (j > 3) temp3 = d[i - 1][j - 3] * 2;
			//temp1 : 1 ~ j-2 까지 i-1개가 선택된 경우의 수
			//temp2 : 1 ~ j-3 까지 i-1개가 선택된 경우의 수
			//temp1 - temp2: j-2를 포함하여 i-1개가 선택된 경우의 수
			//temp3 : d[i - 1][j - 3] 에 다가 j-1, j 번째 원소중 둘중 하나를 선택하면 
			//되기에 경우의 수는 2배 증가 시킨다.
			long long sum;
			//1 ~ j-2 원소중
			//j-2를 포함한 i-1개가 선택된 경우의 수 == 1번을 포함하여 i-1개가 선택된 경우의 수
			//추가할 j-1, j 번째 원소중
			//j원소는 선택할 수 없기에 (temp1 - temp2)만큼 도로 빼야됨
			if (j == n) sum = temp3;
			else
				sum = temp1 - temp2 + temp3;	//b: temp1 - temp2 // c: temp3
			d[i][j] += sum;
			d[i][j] += MOD;
			d[i][j] %= MOD;
		}
	cout << d[k][n];
	return 0;
}
1	2	3	4	5	5	6	7	8	9	10
d[1][1]: 1~1 까지 중 1개가 선택되는 경우의 수 : 1
d[1][2]: 1~2 까지 중 1개가 선택되는 경우의 수 : 2
...
d[1][10]: 1~10 까지 중 1개가 선택되는 경우의 수 : 10

d[3][10]: sum { a) d[2][8]
				b) d[2][8] - d[2][7]	//1~8번까지 중 2개 선택한것 갯수 - 1~7번까지 중 2개 선택한것 갯수:
									//8번을 포함하여 2개 선택한 갯수이며 이 경우 10번 하나만 추가 가능하니
									//곱하기 1임
				c) d[2][7] * 2		//8번이 제외하고 2개 선택한 갯수이겨 이 경우 9번 10번 두개가 추가
									//가능하니 곱하기 2임
			  }
"단 10번이 마지막 번호라면 d[2][8] 에서 1번을 포함하여 2개 선택된 갯수만큼 빼줘야 한다.
//그 값은 b)구하는 거랑 완전 똑같다.
//1~8 중 1을 포함하여 2개 선택한 것 갯수 == 1~8번 중 8을 포함하여 2개 선택한 것 갯수
땨라서 이 경우 a + c 가 된다.
"이런 류는 종이에 적지 않고는 스스로 풀었더라도 다시 봐도 모름"



// 더 간단한 풀이법: 이건 뭐 종이에 안써도 되넹...
https://plzfdaylife.tistory.com/132
dp[n][k] 를 구한다
dp[i][0] = 1;	// 아무것도 안고른 케이스도 1로 취급
dp[i][1] = i;	// for (int i = 1; i <= n; ++i)
dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j]	// j번째걸 선택 + j번째걸 안선택

dp[n][k] 는 끝부분 처리가 안되어 있으므로 끝부분 처리가 필요
n번째 색을 고른 경우 n - 3 을 제외하고 k를 고른 경우의 수가 된다.
n번째 색을 고르지 않은 경우는 n - 1 개 중 k개를 고른 경우의 수가 된다.

const int mod = 1000000003;
int dp[1010][1010];
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) dp[i][0] = 1;
	for (int i = 1; i <+ N; ++i) dp[i][1] = i;
	for (int i = 2; i <= N; ++i) {
		for  (int j = 2; j <= N; ++j) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) # mod;
	return 0;
}

// 물론 다른 방식으로도 표현 가능
dp[N - 4][K - 2] // 시작과 끝이 선택된 케이스를 빼야 한다.
cout << ((dp[N][K] - dp[N - 4][K - 2]) + mod) % mod; // 뺄샘땜시 mod를 주의





//앱
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1878&sca=3050
int d[10001][101];	//i:비활성화비용, j: 1~j 까지 앱들
//d[i][j]: 1~j 까지 앱들중 일부를 선택(비활성화 비용합이 i)해서
//최대로 확보되는 메모리 공간을 저장
"d[i][j] = max(	d[i][j - 1],		//j번째를 무시한 경우
"				d[i - cArr[j]][j - 1] + mArr[j]);	//j번째를 고려한 경우
현 비용으로 최대의 메모리 확보
==> 최대의 메모리 확보를 위한 최소의 비용을 구할 수 있다. i는 순서대로 커지니

//!!!!우와아 한방에 통과했다... 난 완전 돌려서 풀었다고 생각했는데.. 감동.ㅠㅠ
//배열 d[101]로도 충분히 돌릴수 있다.
//다른 통과 코드를 봅세.. 내가 내코드 이해 안되는 수준이라...

int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vi mArr, cArr;
	mArr.resize(n + 1); cArr.resize(n + 1);
	rep2(i, 1, n + 1) cin >> mArr[i];
	rep2(i, 1, n + 1) cin >> cArr[i];
	int sumC = 0;
	rep2(i, 1, n + 1) sumC += cArr[i];
	rep2(i, 1, 10001) {
		if (sumC < i) break;
		rep2(j, 1, n + 1) {
			//1~j-1 개중 일부를 선택(비활성화 비용합이 i)해서 최대로 확보되는 메모리
			d[i][j] = d[i][j - 1];
			//(현 비용 - j번째 비용, 1~j-1 개중 일부를 선택) 한것이 최대로 확보되는 메모리
			// + j번째로 확보되는 비용
			if (i >= cArr[j])
				d[i][j] = max(d[i][j], d[i - cArr[j]][j - 1] + mArr[j]);
		}
	}
	int sol = 0;
	rep(i, sumC + 1)
		if (d[i][n] >= m) { sol = i; break; }
	cout << sol;
	return 0;
}
//재귀 코드
int n, m, sumC;
vi mArr, cArr;
int d[10001][101];	//[비활성화 비용][앱번호] = 최대로 확보되는 메모리 공간
int rec(int cost, int num) {
	if (num == 0) {
		d[cost][num] = 0;  return 0;
	}
	int& ret = d[cost][num];
	if (ret != -1) return ret;
	ret = rec(cost, num - 1);
	if (cost >= cArr[num])
		ret = max(ret, rec(cost - cArr[num], num - 1) + mArr[num]);
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	cin >> n >> m;
	mArr.resize(n + 1); cArr.resize(n + 1);
	rep2(i, 1, n + 1) cin >> mArr[i];
	rep2(i, 1, n + 1) cin >> cArr[i];
	sumC = accumulate(cArr.begin(), cArr.end(), 0);
	int test = rec(sumC, n);//이건 여기서 할 필욘 없어용 // 이거 한번만 한다고 d 가 전부 세팅되는건 아닙니다.
	int sol = 0;

	rep(i, sumC + 1)
	//	if (d[i][n] >= m) { sol = i; break; }	
	// 이럼 망합니다.!!!! d[i][n] == -1인 케이스가 허다하거든요.
		if (rec(i, n) >= m) { sol = i; break; }
	cout << sol;
	return 0;
}

int d[101][10001];
int main() {
	int n, m; cin >> n >> m;
	vi mArr, cArr;
	mArr.resize(n + 1); cArr.resize(n + 1);
	rep2(i, 1, n + 1) cin >> mArr[i];
	rep2(i, 1, n + 1) cin >> cArr[i];
	int sumC = 0;
	rep2(i, 1, n + 1) sumC += cArr[i];
	rep2(i, 1, n + 1)
		rep2(j, 1, 10001) {
			if (sumC < i) break;
			d[i][j] = d[i - 1][j];
			if (j >= cArr[i])
				d[i][j] = max(d[i][j], d[i - 1][j - cArr[i]] + mArr[i]);
		}
	int sol = 0;
	rep(i, sumC + 1)
		if (d[n][i] >= m) { sol = i; break; }
	cout << sol;
	return 0;
}
//유전자
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=974&sca=30a0
유전자에 대한 정보가 주어졌을 때, 주어진 조건을 만족하는 KOI 유전자의 최대 길
이를 구하는 문제이다. 이를 위해서 at, gc로부터 차례로 가능한 KOI 유전자를 만들
어나가는 방법을 생각할 수도 있지만, 그러한 방법을 사용할 경우 가능한 경우의 수
가 폭발적으로 증가하게 된다. 따라서 역으로 큰 문자열을 잘 잘라가면서, 최종적으로
at, gc와 같은 KOI 유전자에 도달하는 식의 접근을 사용한다. 이러한 방법의 한 가지로 동적 계획법을 이용하여 주어진 문제를 해결할 수 있다. 주어진 문자열을 S[1...L]이라 하고, D[i][j]를 스트링 S[i...j]의 부분 서열 중 가장 긴
KOI 유전자의 길이로 정의하면, 아래와 같이 문제에서 주어진 세 가지 조건을 순서대
로 따져 가며 구하면 된다. 이 때 항상 i<j의 조건이 만족된다고 하자.

(1) S[i...j]의 길이가 2인 경우, "at"나 "gc" 이면 D[i][j]=2, 그렇지 않으면 D[i][j]=0
(2) S[i]='a', S[j]='t'이거나 S[i]='g', S[j]='c'이면 D[i][j]=D[i+1][j-1]+2
(3) i<=k<j에 대해, D[i][j]는 D[i][k]+D[k+1][j]중 가장 큰 값

이 때 각각은 문제에서 주어진 세 가지 조건에 순서대로 대응된다. 이 때 두 번째
경우, D[i+1][j-1]이 실제로 KOI 유전자를 구성해야 한다고 생각할 수 있다. 그러나 X
가 빈 문자열의 경우라면, 이는 at, gc에 해당하므로 이는 자연스럽게 KOI 유전자가
된다. 따라서 전체 배열을 초기화 한 후 위의 알고리즘을 수행하면 답을 구할 수 있
다.이와 같은 방식으로 배열을 구하면, D[1][L]이 구하고자 하는 답이 된다. 앞의 두 경
우는 자연스럽게 구해질 수 있으며, 세 번째 경우는 가능한 k를 모두 고려해야 하므
로 전체 시간복잡도는 길이 L인 문자열에 대해 O(L^3)이 된다

"사이즈 순으로 증가시켜 DP를 푼다" 좋은 문제다!!!! 
"사이즈 DP 문제라고 명명하자~!!!!"
int d[500][500];
int main() {
    string str; cin >> str;
    int n = str.size();
    memset(d, 0, sizeof(d));
    rep(i, n) d[i][i] = 0;  //하나짜리
    rep(i, n - 1) {         //두개짜리
        if ((str[i] == 'a' && str[i + 1] == 't') ||
            (str[i] == 'g' && str[i + 1] == 'c'))
            d[i][i + 1] = 2;
    }
    rep2(sz, 2, n) {    //3개 이상
        for (int i = 0; i + sz < n; ++i) {
            int j = i + sz;
            //d[i][j] = d[i+1][j-1] + 2
            if ((str[i] == 'a' && str[j] == 't') ||
                (str[i] == 'g' && str[j] == 'c'))
                d[i][j] = d[i + 1][j - 1] + 2;
            int cand = 0;
            //d[i][j] = max{d[i][k] + d[k+1][j]}
            for (int k = i; k < j; ++k)
				//D[i][j] = D[i+1][j-1]로 설정 굳이 안해도 여기서 처리가 되네요.
                cand = max(cand, d[i][k] + d[k + 1][j]);
            d[i][j] = max(cand, d[i][j]);
        }
    }
    int sol = d[0][n - 1];
    cout << sol;
    return 0;
}
//재귀형식: cache[][]//for문 2개 커버, 내부 for문 1개 커버 
//=> iterative 총3중 for문을 재귀로 나타냄 !!!!
string str;
int d[500][500];
int rec(int i, int j) {
	if (i > j) return 0;
	int& ret = d[i][j];
	if (ret != -1) return ret;
	if (i == j) return ret = 0;
	if (j - i + 1 == 2)
		if ((str[i] == 'a' && str[i + 1] == 't') ||
			(str[i] == 'g' && str[i + 1] == 'c'))
			return ret = 2;
	//3개 이상부턴
	ret = rec(i + 1, j - 1);
	if ((str[i] == 'a' && str[j] == 't') ||
		(str[i] == 'g' && str[j] == 'c'))
		ret += 2;
	int cand = 0;
	for (int k = i; k < j; ++k)
		cand = max(cand, rec(i, k) + rec(k + 1, j));
	ret = max(ret, cand);
	return ret;
}
int main() {
	cin >> str;
	int n = str.size();
	memset(d, -1, sizeof(d));
	int sol = rec(0, n - 1);
	cout << sol;
	return 0;
}


//악수
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=518&sca=30a0
//사이즈 DP문제
O(n^3)이라 통과 못할줄 알았는데 통과함... 191ms 걸림
500 * 1000 * 500 = 250000000//2억 5천만임
//포기했었는데 유전자 문제 보고 그냥 돌려봄. 히익 통과했네...

// 코드는 홀수개의 처리가 안되는데 만약
// 세개짜리 1, 2, 2 가 들어오면 망하잖소
"입력은 짝수 p로 시작한다" // 이런 경우 괞찮다.
const int INF = 987654321;
int d[1000][1000];
int main() {
	memset(d, 0, sizeof(d));
	int n; cin >> n;
	vi arr(n);
	rep(i, n) cin >> arr[i];
	rep(i, n) 			//두개짜리
		if (arr[i] == arr[(i + 1) % n])	// 사실 나머지 처리할 필요는 없다. d[n - 2][n - 1] 까지만 해도 무방
			d[i][(i + 1) % n] = 1;
	
	//4개짜리 이상
	for (int sz = 3; sz < n; sz += 2) {
		for (int i = 0; i + sz < n; i++) {
			int j = i + sz;
			d[i][j] = d[i + 1][j - 1];
			//d[i][j] = d[i+1][j-1] + 1
			if (arr[i] == arr[j])
				d[i][j]++;
			int cand = 0;
			//d[i][j] = max{ d[i][k] + d[k + 1][j] }
			for (int k = i + 1; k + 1 < j; k += 2)
				cand = max(cand, d[i][k] + d[k + 1][j]);
			d[i][j] = max(cand, d[i][j]);
		}
	}
	int sol = d[0][n - 1];
	cout << sol;
	return 0;
}
//재귀버전//3배느리네
int d[1000][1000];
vi arr;
int rec(int i, int j) {
	int& ret = d[i][j];
	if (ret != -1) return ret;

	int size = j - i + 1;
	if (size == 2) {	// 2개짜리
		if (arr[i] == arr[j])
			ret = 1;
		else
			ret = 0;
		return ret;
	}
	//4개짜리 이상
	ret = rec(i + 1, j - 1);
	if (arr[i] == arr[j]) ret++;
	int cand = 0;
	for (int k = i + 1; k + 1 < j; k += 2)
		cand = max(cand, rec(i, k) + rec(k + 1, j));
	ret = max(cand, ret);
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	int n; cin >> n;
	arr.resize(n);
	rep(i, n) cin >> arr[i];
	int sol = rec(0, n - 1);
	cout << sol;
	return 0;
}

//건물 세우기
  1 2 3
A 4 7 3
B 2 6 1
C 3 9 4
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=532&sca=30a0
//bitwise dp
//!!!! 응용하기 좋은 코드같다.
"포기하다가 shortest path2 알고리즘이 생각나 응용하니 통과함"
const int INF = 987654321;
const int MAX = 20;
int board[MAX][MAX];
int cache[1 << MAX];
int choice[1 << MAX];
int n;
"index라는 걸 생각하니 문제가 쉬워졌다!!!!"
int dp(int taken, int index) {
	//taken == 0 && index == n
	if (taken == 0) 
		return 0;
	int& ret = cache[taken];
	if (ret != -1) return ret;
	ret = INF;
	for (int select = 0; select < n; ++select) {
		if (taken & (1 << select)) {
			int cand = board[select][index] 
				+ dp(taken - (1 << select), index + 1);
			if (ret > cand) {
				choice[taken] = select;
				ret = cand;
			}
		}
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	rep(i, n) rep(j, n)	cin >> board[i][j];

	int sol = dp((1 << n) - 1, 0);
	cout << sol << endl;
	//각 위치별 건물번호
	vi rot_build(n);
	int taken = (1 << n) - 1;
	rep(i, n) {
		rot_build[i] = choice[taken];	// taken 취할것중 가장 위에 둘것 선택
		taken -= (1 << rot_build[i]);
	}
	//건물번호별 위치
	vi build_rot(n);
	rep(i, n) {
		build_rot[rot_build[i]] = i;
	}
	rep(i, n) {
		if (i) cout << " ";
		cout << build_rot[i] + 1;
	}
	return 0;
}
int board[MAX][MAX];	//[건물번호][각 건물이 놓일 위치번호]
int dp[1 << MAX];
int choice[1 << MAX];
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> n;
	rep(i,n) rep(j,n) cin >> board[i][j];
	rep(i,n) dp[1 << i] = board[i][n-1];//다 채우고 마지막 한개 남았을 때 그 한놈을 지을 비용
	//비트 두개짜리
	//비트 세개짜리
	//...
	int taken = 0;
	for (int iter = 2; iter <= n; ++iter) {
		
	}
	"bitwise dp (bitmask dp) 를 for문으로 나타내려면 n 에 비례하며 for가 많아질수 있다"
	"이런건 정신건강에 안좋다. 재귀로 풀자 ㅠㅠ...!!!!"
}



//Permanent Computation
"!!!!좋은문제다"
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1313&sca=30a0
const int MAX = 16;
int n;
int cache[1 << MAX];
int mat[MAX][MAX];
//dp(taken, index) = sum[순열]{아직 선택되지 못한 곳들로 이루어진 곱의 합}
//index 행에서 선택된 수 하나 * sum[순열]{아직 선택되지 못한 곳들로 이루어진 곱의 합}
int dp(int taken, int index) {
	if (taken == 0) return 1;
	int& ret = cache[taken];
	if (ret != -1) return ret;
	ret = 0;
	for (int select = 0; select < n; ++select) {
		if (taken & (1 << select)) {
			int temp = mat[index][select]
				* dp(taken - (1 << select), index + 1);
			ret += temp;
			ret %= 10000;
		}
	}
	return ret;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	rep(i, n) rep(j, n) cin >> mat[i][j];
	int sol = dp((1 << n) - 1, 0);
	cout << sol;
	return 0;
}

//가지치기: dp라기보단 그래프 문제 같다.
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=836&sca=30a0
vector<pair<int, int>> graph[1001];
//루트가 아니고 연결된 놈이 하나만 있으면 그건 잎노드: 부모와의 간선 가중치 리턴
//중간 노드: min(부모와의 간선 가중치, 하위 루틴 리턴값의 합)
//루트: 하위 루틴 리턴값의 합
int dfs(int here, int parent, int parentCost) {
	int ret = 0;
	if (parent == -1) {
		for (int i = 0; i < graph[here].size(); ++i) {
			int there = graph[here][i].first;
			int cost = graph[here][i].second;
			ret += dfs(there, here, cost);
		}
		return ret;
	}
	ret = parentCost;
	if (graph[here].size() == 1) return ret;
	int cand = 0;
	for (int i = 0; i < graph[here].size(); ++i) {
		int there = graph[here][i].first;
		int cost = graph[here][i].second;
		if (there != parent)
			cand += dfs(there, here, cost);
	}
	ret = min(ret, cand);
	return ret;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	while (true) {
		
		int n; cin >> n;
		int root; cin >> root;
		if (n == 0) break;
		rep(i, n + 1) graph[i].clear();
		rep(i, n - 1) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(mp(b, c));
			graph[b].push_back(mp(a, c));
		}
		int sol = dfs(root, -1, -1);
		cout << sol << endl;
	}
	return 0;
}


http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=540&sca=30a0
//cross 갯수
A	B
1	8	5
2	2	2
3	9	4
4	1	3
5		0
6	4	2
7	6	2
8		0
9	7	2
10	10	0

8	2	9	1	4	6	7	10        
//정올 답안 소스: 내식으로 바꾼거임
const int N = 100000, INDEX = 1000000;
int qc; int ans; int n;
int hash_[INDEX]; int abovePt[INDEX]; int check[N];
vpii arr; int q[N];
//[a..b]범위내에서 v가 삽입될 위치를 리턴한다.
//초기호출 [0..qc]
//q[0] = 0, q[1] = 2 라 할 때 find_place(0,1,1)은 1을 리턴함
//q[0] = 0, q[1] = 2 라 할 때 find_place(0,1,3)은 1을 리턴함	//두번째 인자 q_size를 초과하지 않고 리턴함!!!!
// q[0] = 10, q[1] = 0 , qsize = 1 인 경우 find_place(0,1,15) 는 1을 리턴함 !!!!!!!
int find_place(int a, int b, int v) {	//v와 같거나 그 이상인 놈의 인덱스를 리턴함(문제에선 v랑 같을리가)
	if (b == a) return a;
	int m = (a + b) / 2;
	if (v < q[m]) return find_place(a, m, v);
	else if (q[m] < v) return find_place(m + 1, b, v);
	return m;	//이거 호출될 경우가 있나???? 없다고 생각함
}

// q[i - 1] < x <= q[i] 인 i를 반환한다. q[i]가 x랑 같은것도 리턴된다.
int search(int qSize, int x) { //find_place대신 이걸 써도 동작합니다.
	int lo = -1;
	int hi = qSize;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (q[mid] < x) 
			lo = mid;
		else 
			hi = mid;
	}
	return hi;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> n;
	arr.resize(n);
	rep(i, n) cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	//A전봇대에 연결되는 위치의 번호를 오름차순으로 출력
	rep(i, n) hash_[arr[i].second] = i; //b 랑 매치되는 a의 인덱스를 저장//
	qc = 0;
	rep(i, n) {
		//큐 범위 내에서 arr[i].second 가 있을 곳을 찾는다.
		int index = find_place(0, qc, arr[i].second);
		q[index] = arr[i].second;
		if (index == 0) abovePt[arr[i].second] = -1;
		else abovePt[arr[i].second] = q[index - 1];

		if (index == qc) qc++;//큐의 크기를 초과하는 index면 큐를 증가시킨다.
		//cout << "point[" << arr[i].second << "] = " << point[arr[i].second] << endl;
	}
	rep(i, n) check[i] = 0;
	int v = q[qc - 1];	//큐에 남은것(b)에서 맨 마지막은 남겨두도록 한다.
	while (v != -1) {
		check[hash_[v]] = 1;
		v = abovePt[v];	//남은 점들중 자신의 바로 윗점을 찾아간다.
		if (v == -1) break;
	}
	ans = n - qc;	//없애야하는 전깃줄의 최소 갯수: 전체 갯수 - 큐사이즈(남겨야 하는 전깃줄의 갯수)
	cout << ans << endl;
	rep(i, n) {
		if (check[i] == 1) continue;	//남겨야 되면 넘어감
		printf("%d\n", arr[i].first);	//지울놈만 출력
	}
	return 0;
}
//A의 크기 순으로 수행
//A[i]를 추가했을때 크로스 되는 것이 없다면 q사이즈를 증가 시키고 
//A[i]에 대응되는 B[i]를 저장한다.
//크로스 된다면 q사이즈는 그대로 두고 해당 위치 인덱스:index에 B[i]를 덮어쓴다.
//그리고 위쪽 점을 의미하는 point[B[i]] (B[i] 의 바로 위쪽)
//의 값은 q[index - 1] 가 된다.
"이제야 이해가 되넹...ㅠㅠ"
"응용 DP문제임"
"응용하기 좋은 코드다!!!!"


크로스의 갯수 구하기는 펜윅트리로 간단하게 구할 수 있다.





http://codeforces.com/contest/633/problem/A
세개의 숫자 a, b, c 가 주어지고 ( 1 <= a, b <= 100, 1 <= c <= 10000)
a,b 로 c를 표현 가능한가 판단하는 문제 (a, b의 갯수는 아무렇게나 사용 가능)

//tourist 가 짠 코드... 너무 간단해서 DP로 푼 내가 한심스럽게 됨...
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  for (int x = 0; a * x <= c; x++) {
    int y = c - a * x;
    if (y % b != 0) {
      continue;
    }
    puts("Yes");
    return 0;
  }
  puts("No");
  return 0;
}





http://codeforces.com/contest/633/problem/C
For example, when this cipher is applied to the sentence
Kira is childish and he hates losing
the resulting string is
"ariksihsidlihcdnaehsetahgnisol"
이걸을 원문으로 바꾸어야 함
원문
Kira is childish and he hates losing
1) 각 단어를 소문자로 바꾼다
kira is childish and he hates lowing
2) 각 단어를 뒤집는다.
arik si hsidlihc dna eh setah gniwol
3) 스페이스를 없앤다.
ariksihsidlihcdnaehsetahgnisol

input 은 이런 식으로 들어온다. 힌트 단어가 10개다.
30	// 1 <= n <= 10000
ariksihsidlihcdnaehsetahgnisol
10	// 1 <= m <= 100000
Kira	// 각 단어의 길이는 1000 이하이며 모든 힌트단어를 합한 길이는 1000000을 넘지 않는다.
hates	// 각 단어는 여러번 사용될 수도 있다.
is
he
losing
death
childish
L
and
Note
// 답이 많은 경우 하나만 출력해도 무방하다. 답은 존재한다.


// 라빈 카프 문자열 검색으로도 풀수 있다만 나는 그 알고리즘 구현경험이 없어요
// 다중문자열 패턴 매칭 알고리즘인 아호코라식으로 해결했어요
// 한번에 통과하니 너무너무 신기하고 뿌듯합니다.
// 출현패턴의 위치를 계산한 뒤 그것들을 DP돌려서 풀었어요!!!!
// 라빈 카프 알고리즘 보고 싶다면 해당문제 다른 사람 답 봅시다
const int APB = 26;
int toN(char ch) { return ch - 'a'; }
struct TN {
	TN* children[APB];
	int tmn;
	TN* fail;
	vi output;
	int first;
	TN() {
		memset(children, 0, sizeof(children));
		tmn = first = -1;
	}
	~TN() {
		rep(i, APB)
			if (children[i]) delete children[i];
	}
	void insert(const char* key, int id) {
		if (*key == 0)
			tmn = id;
		else {
			int next = toN(*key);
			if (children[next] == NULL)
				children[next] = new TN();
			children[next]->insert(key + 1, id);
		}
	}
	TN* find(const char* key) {
		if (*key == 0) return this;
		int next = toN(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};
void computeFailFunc(TN* root) {
	queue<TN*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		TN* here = q.front(); q.pop();
		rep(edge, APB) {
			TN* child = here->children[edge];
			if (!child) continue;
			if (here == root)
				child->fail = root;
			else {
				TN* t = here->fail;
				while (t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge]) t = t->children[edge];
				child->fail = t;
			}
			child->output = child->fail->output;
			if (child->tmn != -1)
				child->output.push_back(child->tmn);
			q.push(child);
		}
	}
}
vector<pair<int, int>> ahoCorasick(const string& s, TN* root) {
	vpii ret;
	TN* state = root;
	rep(i, s.size()) {
		int chr = toN(s[i]);
		while (state != root && state->children[chr] == NULL)
			state = state->fail;
		if (state->children[chr]) state = state->children[chr];
		for (int j = 0; j < state->output.size(); ++j)
			ret.push_back(make_pair(i, state->output[j]));
	}
	return ret;
}
vs patterns, patterns2;
map<int, vi> idxPt;	//indexPattern;
int cache[100002];
int choice[100002];
int dp(int here) {		// 이게 핵심 처음 here은 문자열의 마지막 인덱스임 거기서 부터 시작함
						// 완전히 마무리 되면 -1 이고 그렇지 않으면 0
	if (here == -1) return 1;
	else if (here < -1) return 0;
	int& ret = cache[here];
	if (ret != -1) return ret;
	ret = 0;
	int cand = 0;
	if (idxPt.count(here))
		for (int i = 0; i < idxPt[here].size(); ++i) {
			int index = idxPt[here][i];
			int size = patterns2[index].size();
			int tmp = dp(here - size);
			if (tmp == 1)
				choice[here] = index;
			cand += tmp;
		}
	if (cand > 0) ret = 1;
	return ret;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	memset(cache, -1, sizeof(cache));
	memset(choice, -1, sizeof(choice));
	int n; cin >> n;
	string str; cin >> str;
	int m; cin >> m;
	patterns.resize(m), patterns2.resize(m);
	rep(i, m) cin >> patterns[i];

	rep(i, m) {
		patterns2[i] = patterns[i];
		transform(patterns2[i].begin(), patterns2[i].end(), patterns2[i].begin(), tolower);	// !!!!
	}
	TN trie;
	rep(i, patterns2.size())
		trie.insert(patterns2[i].c_str(), i);
	computeFailFunc(&trie);
	string revStr = str;
	reverse(revStr.begin(), revStr.end());
	vpii pairpair = ahoCorasick(revStr, &trie);
	
	rep(i, pairpair.size()) {
		idxPt[pairpair[i].first].push_back(pairpair[i].second);
	}
	int ddd = dp(str.size() - 1);
	int sel = revStr.size() - 1;
	vs sol;
	while (true) {
		if (sel < 0) break;
		int index = choice[sel];
		if (index == -1) break;
		sol.push_back(patterns[index]);
		sel = sel - sol.back().size();
	}
	//reverse(sol.begin(), sol.end());
	rep(i, sol.size())
		cout << sol[i] << " ";
	return 0;
}


//막대기!!!! 아주 좋은 문제다.
//내 머리가 처음엔 이해가 안되어 정말 힘들었다. 정올 설명이 어렵게 적혀 있었다.
"코드 구조도 응용하기 좋다"!!!!!
const int N = 111111;
struct Stick { int t, d, x; };
int n, l;
Stick arr[N];
int t_x[N], d_x[N];
long long e[N][2], v1, v2, ans; //e[N][2]의 의미는?	
//e[i][0]: 끝이 내려가는 선	,	 e[i][1]: 끝이 올라가는 선
int cmp(const Stick &p, const Stick &q) {
	return p.t < q.t || (p.t == q.t && p.d < q.d);
}
int main() {
	int i, v;
	cin >> n >> l;
	rep(i,n) {
		cin >> arr[i].t >> arr[i].d;
		arr[i].s = abs(arr[i].t - arr[i].d) + l;
		t_x[i] = arr[i].t;
		d_x[i] = arr[i].d;
	}
	//t_x, d_x 는 상대위치를 나타낼려고 사용한것일뿐. dp에선 쓰이지 않는다.
	sort(t_x, t_x + n); //윗 좌표들을 정렬
	sort(d_x, d_x + n); //아랫 좌표들을 정렬
	rep(i,n) {
		"유용한 기술1" // !!!!
		// arr[i]에 실제 좌표가 아닌 상대 위치로(자신보다 좌측에 있는 점의 갯수 저장)
		arr[i].t = lower_bound(t_x, t_x + n, arr[i].t) - t_x;
		arr[i].d = lower_bound(d_x, d_x + n, arr[i].d) - d_x;
	}
	sort(arr, arr + n, cmp);
	//dp돌리기
	rep(i,n) {
		v1 = e[arr[i].t][0] + arr[i].s;	// 위에서 백트랙해 아래로 내려간 길 중 최대 길이 + 현 간선 길이
		v2 = e[arr[i].d][1] + arr[i].s; // 밑에서 백트랙해 위로   내려간 길 중 최대 길이 + 현 간선 길이
		if (v1 > e[arr[i].d][1]) e[arr[i].d][1] = v1;
		if (v2 > e[arr[i].t][0]) e[arr[i].t][0] = v2;
		if (v1 > ans) ans = v1;
		if (v2 > ans) ans = v2;
		//Di+1 = { arr[i+1].s	//같은 top 위치에 이전 놈이 없다면	:	\
		//		 { Ti + a[i+1].s //이전 top이 겹친 경우				:	/\
		//e[arr[i].d][1] = { arr[i].s OR e[arr[i].d][1] + arr[i].s }
		"핵심: 이전 top이 겹첩다면 arr[i].d 는 arr[i - 1].d 이거든요"
	}
	cout << ans << endl;
	return 0;
}

// 윗코드가 햇갈린다. 아래를 보자.
"끝이 위에선에 위치하고 백트랙시 내려가는 경우 " // 아래 예시에서 d번 막대기를 갱신하는 경우 
e[arr[i].t][0] = max{	e[arr[i].d][1] + arr[i].s,
						e[arr[i].t][0] }		// 요게 정답이 된다. !!!! 까먹지 말자.. 원리는 이해했다.
"끝이 아래선에 위치하고 백트랙시 올라가는 경우 "
e[arr[i].d][1] = max{	e[arr[i].t][0] + arr[i].s,
						e[arr[i].d][1] }

시뮬레이션
							0        1                        2
--------------------------- a ------ b ---------------------- cd ----------





-- c -------------------- a ----------------- bd --------------------------
   0                      1                   2
a.s = 5,	b.s = 6,	c.s = 15,	d.s = 7

// a, b, c, d 변 순서로 진행
i = 0
	e[0][0] = 5	// a번 막대기의 top 을 끝으로 취급하고 a번 막대기 아래로 내려가며 백트랙하는 길이
	e[1][1] = 5 // a번 막대기의 down 을 끝으로 취급하고 a번 막대기 위로 올라가며 백트랙하는 길이

i = 1
	e[1][0] = 6
	e[2][1] = 6
i = 2
	e[2][0] = 15
	e[0][1] = 15
i = 3 // !!!!
	e[2][0] = e[2][1] + 7 = 6 + 7 = 13 but e[2][0] 의 이전 값은 15 이므로 생깐다 !!!!
	e[2][1] = e[2][0] + 7 = 15 + 7 = 22
	// d번 막대기의 down 을 끝으로 취급하고 d번 막대기 위로 올라가며 백트랙하면 일단 7을 더하는게 됨
	// 그뒤 e[2][0] : 윗선 2번 지점에서 내려가며 백트랙한 최대 길이는 15 이며 이걸 더하면
	// 답은 22가 된다.

sol 는 22 가 된다.




http://codeforces.com/contest/633/problem/D
5		// 1000개 이하
28 35 7 14 21	// 각 숫자는 절대값이 1000000000 이하

최대 길이의 피보나치를 이루려면
7 14 21 35 가 되어야 한다.
이경우 출력 값은 4가 된다.
//피보나치: 속도가 아슬아슬하게 통과했음. 2000ms근접...
//unordered_map을 쓴다면 어찌 될까//별 차이 없더라..ㅠㅠ
//다른 사람들 소스는 정말 빠른게 많다 기회되면 구현한거 보는건 좋을거임(31ms짜리도 있었다.)
vi arr;
map<long long, int> myMap, tMap;
vi used;
int n;
int calc(int i, int j) {
	used.clear();
	long long a = arr[i], b = arr[j];
	tMap[a]--;
	tMap[b]--;
	used.push_back(a);
	used.push_back(b);
	int length = 2;
	while (true) {
		long long temp = a + b;
		//if (tMap.count(temp) && tMap[temp] > 0)
		if (tMap[temp] > 0) {
			used.push_back(temp);
			tMap[temp]--;
			length++;
		}
		else
			break;
		if (length == n) break;
		a = b;
		b = temp;
	}
	return length;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> n;
	arr.resize(n);
	int zeroCnt = 0;
	rep(i, n) {
		int a; 
		scanf("%d", &a);
		arr[i] = a;
		myMap[a]++;
		if (arr[i] == 0) zeroCnt++;
	}

	int length = zeroCnt;
	tMap = myMap;
	rep(i,n) 
		rep(j, n) 
		if (i != j) {
			if (arr[i] == 0 && arr[j] == 0) continue;// 59test 이상부턴 이거 해야 통과...
			int cand = calc(i, j);
			length = max(length, cand);
			//중간에 그만 둔 경우 전부를 원복 시킬 필요가 없으니
			//사용된것만 원복시킨다. 상당한 성능 항샹을 가져옴
			//3test 에서 3000ms 이상이었는데 바꾸니 265ms 걸림
			rep(i, used.size())
				tMap[used[i]] = myMap[used[i]];
		}
	cout << length;
	return 0;
}
http://codeforces.com/contest/633/my
//윗소스 성능 비굔데
//unordered_map이 별로 빠르지 않았다.(아마도 데이터 충돌때문이려나?..)
//마소 컴파일2010은 성능이 좋이 않았다.
http://lab.gamecodi.com/board/zboard.php?id=GAMECODILAB_QnA_etc&no=2129
"좋은 글이네"
//unordered의 경우에는 내부적으로 75%정도의 해시코드가 차게 되면 자동으로
//rehash작업을 진행합니다. 이게 오버헤드가 상당합니다.(새로 인덱스 정보를 모두 할당받아야 하므로 O(n)의 시간이 필요합니다.)	
"근데 윗 문제랑은 별로 관련없다"


//먹이사슬
활동영역이 (x1, x2)인 동물 i와 (x3, x4)인 동물 j에 대하여, 다음 세 조건 중 하나를 만족하면 i가 j보다 먹이사슬에서 상위에 있다고 한다. 
조건 1: x1 < x3 이고 x2 > x4
조건 2: x1 = x3 이고 x2 > x4
조건 3: x1 < x3 이고 x2 = x4

i	------------------------
j		--------------
	
i		--------------------
j		--------------

i	------------------
j		--------------
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1834&sca=30a0
n 이 무지 크다 (1 <= n <= 500000)
typedef pair<pair<int, int>, int> tp;
vector<tp> arr;
int n;
int depth[500001];
inline bool inclose(tp u,
	tp v) {
	int x1 = u.first.first;
	int x2 = -u.first.second;
	int x3 = v.first.first;
	int x4 = -v.first.second;
	if (x1 < x3 && x2 > x4) return true;
	if (x1 == x3 && x2 > x4) return true;
	if (x1 < x3 && x2 == x4) return true;
	return false;
}
//stack에 push와 pop은 한번씩만 한다.
//정렬을 제외하면 bigO는 n이 된다넹
int main() {
	cin >> n;
	arr.resize(n);
	rep(i, n) {
		int index, a, b;
		cin >> index >> a >> b;
		arr[i].first.first = a;
		arr[i].first.second = -b;
		arr[i].second = index;
	}
	sort(arr.begin(), arr.end(), less<tp>());
	stack<tp> Stack;
	rep(i, n) {
		while (!Stack.empty() && !inclose(Stack.top(), arr[i]))
			Stack.pop();
		Stack.push(arr[i]);
		depth[i] = Stack.size();
	}
	int sol = -1;
	rep(i, n) sol = max(sol, depth[i]);
	cout << sol;
	return 0;
}

"스택구조를 사용할 수 없는 이유"
70프로의 데이터만 통과함
다음 조건을 만족하는 테스트데이터가 전체의 70%이다.
모든 두 동물의 활동영역은 서로 겹치지 않거나, 겹친다면 먹이사슬에서 하나가 나머지 하나의 상위 관계에 있다.
그러니까 이렇게 겹치며 포함관계가 없고 고 사이 낀 놈이 있는 경우
반례가 형성된다.
     3---4
     3---------6		// 이걸 제거시 윗놈이 아래랑 연결이 안되어야 "스택"을 사용할 수 있다!!!!"
2--------4
2------------5
"3,4 를 2,4 와 2,5 가 쌓인 스택위에 올리고 싶지만
"3,6 이 앞 두놈을 팝시켜 버리니 ㅠㅠ..

//재귀 없이 dp로 lis 구하기 !!!! 재귀로 공부했던 나는 힘이 빠지네.. 재귀가 쉽다고? 풋
"쥐기네 간단하고 말야..."
초기값: dy[i] = 1;
점화식: dy[i] = MAX(dy[i], dy[j] + 1) (단, data[j] < data[i], j < i)
void my() {
	vi test(7);
	vi dy(7, 1);
	test[0] = 10;
	test[1] = 20;
	test[2] = 40;
	test[3] = 30;
	test[4] = 70;
	test[5] = 50;
	test[6] = 60;	//이놈이 9 라면 dy[6] = 1이군
	for (int i = 1; i < 7; ++i)			//뒷숫자
		for (int j = 0; j < i; ++j)		//앞숫자
			if (test[j] < test[i] && dy[j] + 1 > dy[i])
				dy[i] = dy[j] + 1;
}
dy[] = {1, 2, 3, 3, 4, 4, 5}
"dy[6] 이 lis크기라고는 보장 못한다. for문 수행해서 dy[]중 가장 큰 값을 찾아야 한다.

//타이핑용
	rep(cc, cs) {
		int n; cin >> n;
		vi arr(n);
		rep(i, n) cin >> arr[i];
		vi dp(n, 1);
		for (int j = 1; j < n; ++j)
			for (int i = 0; i < j; ++i)
				if (arr[i] < arr[j] && dp[j] < dp[i] + 1) 
					dp[j] = dp[i] + 1;
				
		int maxL = -1;
		rep(i, n) if (maxL < dp[i]) maxL = dp[i];
		cout << maxL << endl;
	}


http://dyngina.tistory.com/16	//indexd tree(펜윅트리) 로 구하는 방법도 있음
nlgn에 lis 구하는 알고리즘
1. lower bound를 이용하기
간단한데 크기밖에 모름..(실제 수열을 알기 힘듬: 이경우 인덱스 트리를 이용해서 lis 구해라)
ex)
50	60	70	80	10	20	30	90
50	60	70	80 쌓인 상태에서 10 이 들어오면
10	60	70	80	//lower bound(10)은 50을 가리키고 그놈을 10으로 덮어 씌운다.
10	20	70	80	//20을 넘음
10	20	30	80	//30을 넣음
10	20	30	80	90	//90을 넣음
최종적으로 배열 사이즈가 답이 된다.
앞에서 70에다 30을 덮어 넣을수 있는 이유는
1. 자기 뒤에서 참조를 한다면 더 적은 값에서 참조하는 것이 유리
2. 70 앞의 10	20 은 70을 30으로 덮어쓰더라도 엄연한 LIS 구조를 유지

"크기는 알수 있어도 10 20 30 80 90이 LIS를 이루는 수열이 되진 않습니다!!!!"

	vi test(8);
	test[0] = 50;
	test[1] = 60;
	test[2] = 70;
	test[3] = 80;
	test[4] = 10;
	test[5] = 20;
	test[6] = 20;	//요거 어찌되나 잘보삼
	test[7] = 90;
	//중복된 숫자가 있고 단조 증가 lcs구하라
	vi cp;
	cp.push_back(test[0]);
	rep2(i, 1, test.size()) {
		if (cp.back() <= test[i]) {
			cp.push_back(test[i]);
			continue;
		}
		//+1을 해주는 이유는 lower_bound는 같은 숫자인 경우 가장 작은 인덱스를 리턴하기 때문이다.
		int index = lower_bound(cp.begin(), cp.end(), test[i] + 1) - cp.begin();
		cp[index] = test[i];
	}
	cout << cp.size();
	10, 20, 20, 80, 90
	크기가 5가 된다.

만약 위 +1 이 없었다면 아래 예시는 결과가 어떻게 되나
50	60	70	80	10	20	20	40	50
/*
50
50 60
50 60 70
50 60 70 80 
10 60 70 80
10 20 70 80
10 20 70 80	// 오류: 단조증가를 표현 못함
10 20 40 80
10 20 40 50
cp size: 4
*/

+1을 했을때
/*
50
50 60
50 60 70 80
10 60 70 80
10 20 70 80
10 20 20 80
10 20 20 40
10 20 20 40 50
cp size: 5
*/


//먹이 사슬 통과 소스요.	i 가 j보다 상위인 경우
i	------------------------
j		--------------
	
i		--------------------
j		--------------

i	------------------
j		--------------

http://www.jungol.co.kr
int n;
vpii arr;
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> n;
	arr.resize(n);
	rep(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i].first = b;
		arr[i].second = -c;
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());	//중복되는건 지운다.
	vi tmp;
	tmp.push_back(arr[0].second);
	int size = 1;
	//second 로 LIS 의 크기를 구하자.
	rep2(i,1, arr.size()) {
		if (tmp.back() <= arr[i].second) {	//같아도 먹이사슬이 성립된다. first가 앞쪽이 크기때문
			tmp.push_back(arr[i].second);
			continue;
		}
		//+1을 해준 이유...중복숫자
		//lovwer_bound는 같은 숫자가 들어 있는 경우 같은 숫자의 가장 작은 인덱스를 리턴하므로
		int index = lower_bound(tmp.begin(), tmp.end(), arr[i].second + 1) - tmp.begin();
		tmp[index] = arr[i].second;
	}
	cout << tmp.size();
	return 0;
}
//단조증가 lis 문제다. 사용될 인덱스들을 가지고(물론 정렬되어서 사용될 인덱스는 아니지만) 사이즈를 구해서 출력해보자.
int n;
vpii arr;
int main() {
	cin >> n;
	arr.resize(n);
	rep(i, n) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);	
		//50만번을 cin >> a >> b >> c로하니 1016ms타임오버남
		//scanf 로 바꾸니 300ms나옴(제약시간 1초)
		arr[i].first = b;
		arr[i].second = -c;
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	vi Q;
	rep(i, arr.size()) {
		//<= 대신에 <를 사용하면 순증가 lis크기가 됨
		if (Q.size() == 0 || Q.back() <= arr[i].second)	
			Q.push_back(arr[i].second);
		else {
			
			int index = upper_bound(Q.begin(), Q.end(), arr[i].second) - Q.begin();
			Q[index] = arr[i].second;
		}
	}
	cout << Q.size();
	return 0;
}

사용될 인덱스들을 가지고(물론 정렬되어서 사용될 인덱스는 아니지만) 사이즈를 구해서 출력해보자.


//일반증가 lcs크기는 다음과 같이 구한다. algospot 통과함(입력에 동일 숫자가 없다는게 보장되어)
//lower_bound에서 +1을 하는 귀차니즘은 없어도 됨다... 음..upper_bound가 편해~~
"lower_bound 나 upper_bound 나 같은게 여러개면 그중 가장 작은 인덱스를 가르키게 된다.!!!!"
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vi arr(n);
		rep(i, n) cin >> arr[i];
		vi q;
		q.push_back(arr[0]);
		rep2(i, 1, arr.size()) {
			if (q.back() < arr[i]) {
				q.push_back(arr[i]);
				continue;
			}
			int index = lower_bound(q.begin(), q.end(), arr[i]) - q.begin();
			//int index = upper_bound(q.begin(), q.end(), arr[i]) - q.begin(); // 요래도 되겠지
			q[index] = arr[i];
		}
		cout << q.size() << endl;
	}
	return 0;
}

//순증가 lis (입력에 숫자가 중복된 놈이 있을시.)
int qu[100001];
int qc;
int main() {
	int cs;
	cin >> cs;
	for (int cc = 0; cc < cs; ++cc) {
		int n; 
		scanf("%d", &n);
		qc = 0;
		for (int i = 0; i < n; ++i) {
			int num;
			scanf("%d", &num);
			if (qc == 0 || qu[qc - 1] < num) {
				qu[qc] = num;
				qc++;
			}
			else {
				int idx = upper_bound(qu, qu + qc, num) - qu;
				qu[idx] = num;
			}
		}
		printf("%d\n", qc);
	}
	return 0;
}

	vi q;
	int index = lower_bound(q.begin(), q.end(), 0) - q.begin();		// 0 //!!!!
	q.push_back(3);
	int index2 = lower_bound(q.begin(), q.end(), 0) - q.begin();	// 0

	int index3 = lower_bound(q.begin(), q.end(), 3) - q.begin();	// 0

	int index4 = lower_bound(q.begin(), q.end(), 4) - q.begin();	// 1
	//전깃줄: longest Increasing sequence
//통과함요: 깔끔
const int N = 100000, INDEX = 1000000;
int myMap[INDEX]; int prnt[INDEX]; int check[N];
int main() {
    memset(prnt, -1, sizeof(prnt));
    memset(check, 0, sizeof(check));
    int n; cin >> n;
    vpii arr(n);
    rep(i, n) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    rep(i, n) myMap[arr[i].second] = i;
    vector<int> q;
    rep(i, n) {
        int index = lower_bound(q.begin(), q.end(), arr[i].second) - q.begin(); //!!!!
        if (index == q.size()) q.push_back(arr[i].second);
        else q[index] = arr[i].second;
 
        if (index != 0) prnt[arr[i].second] = q[index - 1];
    }
    int v = q.back();
    while (v != -1) {
        check[myMap[v]] = 1;
        v = prnt[v];
    }
    int sz = n - q.size();
    cout << sz << endl; //없애야 하는 전깃줄 갯수
    rep(i, n) {
        if (check[i] == 1) continue;
        printf("%d\n", arr[i].first);   //없애야 하는 전깃줄 출력
    }
    return 0;
}

입력에 동일한 값이 있는 경우 단조증가수열의 크기는 구하기 쉽지만
단조증가수열 자체는 구하기가 힘드네. prnt[입력값] 으로 설정해서 그렀다만. 그런경우의 코드를 찾아보자 (짜긴 귀찮아.)



lower_bound 랑 upper_bound는 이름만 다르지 실상 거의 똑같은 일을 하네!!!!
lower_bound의 경우 비교할 놈과 같은 것도 포함, 동일한게 여러개면 가장 작은 인덱스를 리턴
upper_bound의 경우 비교할 놈보다 큰것이어야 함, 동일한게 여러개면 가장 작은 인덱스를 리턴
"						 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12
	vector<int> test = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 7, 7, 9 };
	int index1 = lower_bound(test.begin(), test.end(), 4) - test.begin();	//6:  4를 가르킴
	int index2 = upper_bound(test.begin(), test.end(), 4) - test.begin();	//8:  5를 가르킴
	int index3 = lower_bound(test.begin(), test.end(), 6) - test.begin();	//10: 7을 가르킴
	int index4 = upper_bound(test.begin(), test.end(), 6) - test.begin();	//10: 7을 가르킴






//내리막 길
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=303&sca=30a0
//고3 지역본선치곤 문제가 너무 쉽다... 내가 좋아하는 유형인감..
//재귀로 안한다면 어려울 수도 있겠다.
//난 재귀로 하니 바로 풀리네 20분만에 품..헤헤..
const int MAX = 501;
int m, n;
int board[MAX][MAX];
int cache[MAX][MAX];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };
int dp(int y, int x) {
	//if (y < 0 || x < 0 || y == m || x == n) return 0;
	if (y == m - 1 && x == n - 1) return 1;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	ret = 0;
	rep(i, 4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny == m || nx == n) continue;
		if (board[y][x] <= board[ny][nx]) continue;
		ret += dp(ny, nx);
	}
	return ret;
}
int main() {
	//FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	memset(cache, -1, sizeof(cache));
	cin >> m >> n;
	rep(i, m) rep(j, n) cin >> board[i][j];
	int sol = dp(0, 0);
	cout << sol;
	return 0;
}

iterator 를 대입시 rbegin() 을 조심해야 함 !!!!
int main() {
	map<int, int> my1, my2;
	my1[3] = 5;
	my1[2] = 6;
	map<int, int>::iterator it = my1.lower_bound(3);
	it->second = 3;			// my1맵 내부 값이 변경된다.
	it = my1.begin();		// 이건 컴파일 됨
	//it = my1.rbegin();	// 요래하면 컴파일 에러 !!!!
	//my1.erase(my1.rbegin());	// 요래해도 컴파일 에러 // 가장 의외성 높은 부분이였음..
	//my1.erase(my1.begin()); 이건 됨...
	//map<int, int>::reverse_iterator jt = my1.rbegin(); 요래해야 컴파일 됨

	my1.erase(my1.rbegin()->first); // 키를 전달받아 지움

	map<int, int>::reverse_iterator jt = my2.rbegin();
	my2.erase(jt); // 요래도 컴파일 에러 남.. 
	" 맘 편하게 키를 가지고 제거하자.. rbegin() 을 인자로 넣을수가 없다...!!!!"

}
// 딱히 안봐도 된다. iterator 를 바꾸면 원본도 바뀐다는 것만 알고 있자.
// rbegin()을 인자로 해서 지우는것은 힘들다. begin()은 가능함...
int main() {
	map<int, int> my1, my2;
//	freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		my1.clear(); my2.clear();
		int n;
		cin >> n;
		rep(i, n) {
			int rus;
			scanf("%d", &rus);
			my2[rus]++;
		}
		rep(i, n) {
			int kor;
			scanf("%d", &kor);
			my1[kor]++;
		}
		int win = 0;
		rep(i, n) {
			if (my1.rbegin()->first >= my2.rbegin()->first) {
				map<int, int>::iterator it = my1.lower_bound(my2.rbegin()->first);
				//cout << it->first << " " << my2.rbegin()->first << endl;
				if (it->second > 1)
					it->second--;	// 맵의 값이 변경되네
				else
					my1.erase(it);
				
				win++;

				if (my2.rbegin()->second > 1)
					my2.rbegin()->second--;
				else
					my2.erase(my2.rbegin()->first);
			}
			else {
				if (my1.begin()->second > 1)
					my1.begin()->second--;
				else
					my1.erase(my1.begin()->first);

				if (my2.rbegin()->second > 1)
					my2.rbegin()->second--;
				else
					my2.erase(my2.rbegin()->first);
			}
		}
		cout << win << endl;
	}
	return 0;
}


http://codeforces.com/contest/631/problem/C  C. Report
3 1		// 갯수: 최대 20만개, 명령: 최대 20만개
1 2 3	// 원본
2 2		// 명령) 2: 내림차순 정렬, 2: 1~2 범위를 의미
// 2 1 3 //출력

4 2
1 2 4 3
2 3		// 2: 내림차순, 3: 1~3 범위
1 2		// 1: 오름차순, 2: 1~2 범위

// 4 2 1 3
// 2 4 1 3 // 최종 출력본


순서대로 해당 범위만큼 (0 ~ rot) 정렬한다(오름차순, 내림차순)
그냥 무턱대고 정렬하면 타임 오버난다.
스택을 이용해 필요한 정렬만 남긴다.
그리고 pq를 활용해서 가장 작은값과 큰값을 뽑아낸다. 
왜 항상 시간이 지나면 답이 생각날까?...ㅠㅠ
int main() {
//	FILE *fp;
//	freopen_s(&fp, "input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	vi arr(n);
	rep(i, n) cin >> arr[i];
	
	vpii qr(m);
	rep(i, m) cin >> qr[i].first >> qr[i].second;
	stack<pii> st;
	// 필요없는거 지우는 이 아이디어가 핵심임
	rep(i, m) {
		while (!st.empty() && st.top().second <= qr[i].second)
			st.pop();	// 범위가 더 크면 앞에껀 덮어쓰기 되니 필요 없다.
		if (!st.empty() && st.top().first == qr[i].first)
			continue;	// 같은 부호라면 무의미하다.
		st.push(qr[i]);
	}
	vpii temp;
	int stSize = st.size();
	rep(i, stSize) {
		pii it = st.top(); st.pop();
		temp.push_back(it);
	}
	reverse(temp.begin(), temp.end());
	int lastIndex = temp[0].second - 1;
	priority_queue<int> pq1, pq2;
	map<int, int> myMap;
	rep(i, lastIndex + 1) {
		pq1.push(arr[i]);
		pq2.push(-arr[i]);
		myMap[arr[i]]++;
	}
	vi sol;
	rep(i, temp.size()) {
		int ndna = temp[i].first;
		int index = temp[i].second - 1;
		int nextIndex = (i == temp.size() - 1 ? -1 : temp[i + 1].second - 1);
		int cnt = index - nextIndex;
		
		if (ndna == 1) {	//오름차순//여기선 가장 큰 값이 뒤에 옴
			rep(j, cnt) {
				int t = pq1.top(); pq1.pop();
				if (myMap[t] != 0)
					sol.push_back(t);
				myMap[t]--;
			}
		}
		else {	//내림차순
			rep(j, cnt) {
				int t = -pq2.top(); pq2.pop();
				if (myMap[t] != 0)
					sol.push_back(t);
				myMap[t]--;
			}
		}
	}
	reverse(sol.begin(), sol.end());
	int iter = 0;
	rep(i, sol.size()) {
		iter++;
		printf("%d ", sol[i]);
	}
	for (int i = iter; i < arr.size(); ++i)
		printf("%d ", arr[i]);
	return 0;
}

0	1	2	3	4	5	6	7	8	9
1	5	7	7	9	3	5	4	6	7

m이 4개
1	4	// 0~3 까지 오름차순
2	8	// 0~7 까지 내림차순
1	4	// 0~3 까지 오름차순
2	2	// 0~2 까지 내림차순

stack에는
//1	4	// 무쓸모
2	8
1	4
2	2

pq1:	9	7	7	5	5	4	3	1
pq2:	1	3	4	5	5	7	7	9
(8 - 4) 개 만큼 pq2에서 빼낸다.						1	3	4	5	//  5	7	7	9 남음	(pq2)

(4 - 2) 개 만큼 pq1에서 빼낸다.				9	7	// 7	5	5	4	3	1 남음	(pq1)

(2 - 0) 개 만큼 pq2에서 빼낸다.		5	7			//	7	9 남음			(pq2)

" 음 딱히 map 도 필요없고
" 우선순위 큐도 필요 없겠군
" 정렬한 뒤 
" 그 숫자를 앞에서부터 빼서 붙이냐
" 뒤에서 부터 빼서 붙이냐로 구현이 끝나겠다.



//각도 정렬하기(간단하고 좋네) 테스트 해보자
http://amugelab.tistory.com/entry/%EA%B0%81%EB%8F%84-%EC%A0%95%EB%A0%AC%ED%95%98%EA%B8%B0
sort(v.begin(), v.end(), [&](const pnt &p, const pnt &q) {
	if (p.y == 0 && p.x > 0) return true;
	if (q.y == 0 && q.x > 0) return false;
	if (1ll * p.y * q.y <= 0) return p.y > q.y;
	return ccw(origin, p, q) > 0;
});


http://codeforces.com/problemset/problem/650/B
Image preview
//tow pointer 알고리즘에 대해 알아보자
http://codeforces.com/blog/entry/4586	: 예시를 봅세
"오름차순으로 정렬된 두 배열 A, B 가 있다
"a[i] + b[j] == X 를 만족하는 i, j를 구하라
i = 0;
j = b.size() - 1;
while (i < a.size()) {
	while (a[i] + b[j] > X && j > 0) j--;
	if (a[i] + b[j] == X) print(i, j);
	i++;
}
"i	0	1	2	3	4	5	6
A:	1	2	3	5	5	9	10
B:	2	4	6	8	8	11	13
X = 10
http://codeforces.com/problemset/tags/two%20pointers //two pointers algorithm으로 풀리는 문제들

http://codeforces.com/problemset/problem/650/B	// div1 임
T 시간 동안 최대한의 사진을 볼때 그 사진 갯수를 구하라
왼쪽, 오른쪽 사질 이동시 걸리는 시간이 a
수직 수평 변환시 걸리는 시간이 b
사진을 보는데 걸리는 시간은 1 걸림
한번 본 사진은 이동시만 시간이 걸리지
사진의 수는 20만임

//Image preview 푼거
//sol = 최대 갯수{오른쪽으로 쭉, 왼쪽으로 쭉, 오른쪽->왼쪽, 왼쪽->오른쪽}
int arr[500001];
long long costL[500001];
long long costR[500001];
int n, a, b, T;// a: 다음 사진으로 옮기는데 걸리는 시간, b: 사진을 회전시키는데 걸리는 시간
				// T: T시간 이하를 전제로함
long long calc(int L, int R) {
	long long ret = 0;
	ret += costR[R];
	ret += R * a;	//오른쪽 간만큼 되돌리기 swipe
	if (L != 0)
		ret += costL[L];
	return ret;
}
int main() {
	cin >> n >> a >> b >> T;	//a: swipe, b: rotate
	//1 second to notice
	string str; cin >> str;
	//오른쪽 갖다가 왼쪽 가기
	arr[0] = (str[0] == 'h') ? 1 : 1 + b;
	rep2(i,1,n)
		arr[i] = (str[i] == 'h') ? 1 : 1 + b;

	costR[0] = arr[0];
	rep2(i,1, n)
		costR[i] = costR[i - 1] + arr[i] + a;
	for (int i = n - 1; i >= 1; --i)
		costL[i] = (i == n - 1) ? arr[i] + a : costL[i + 1] + arr[i] + a;
	int sol = 0;
	int iLeft = 1;
	int iRight = 0;
	// 분활상환: two_pointer !!!!
	while (iLeft < n + 1) {
		while (iRight < n) {
			if (calc(iLeft % n, iRight) <= T) {
				sol = max(sol, iRight + (n - iLeft) + 1);
				iRight++;
			}
			else break;
		}
		iLeft++;
	}

	//왼쪽 갖다가 오른쪽가기: 문자열을 바꾸어서 윗코드 재사용하자.
	reverse(str.begin(), str.end());
	string strA = str.substr(0, str.size() - 1);
	string strB = str.substr(str.size() - 1);
	str = strB + strA;

	arr[0] = (str[0] == 'h') ? 1 : 1 + b;
	rep2(i, 1, n)
		arr[i] = (str[i] == 'h') ? 1 : 1 + b;

	costR[0] = arr[0];
	rep2(i, 1, n)
		costR[i] = costR[i - 1] + arr[i] + a;
	for (int i = n - 1; i >= 1; --i)
		costL[i] = (i == n - 1) ? arr[i] + a : costL[i + 1] + arr[i] + a;
	//int sol = 0;
	iLeft = 1;
	iRight = 0;
	while (iLeft < n + 1) {
		while (iRight < n) {
			if (calc(iLeft % n, iRight) <= T) {
				sol = max(sol, iRight + (n - iLeft) + 1);
				iRight++;
			}
			else break;
		}
		iLeft++;
	}

	if (sol > n)
		sol = n;
	cout << sol;
	return 0;
}
//나의 오류: 오른쪽갔다가 왼쪽가기 하나만으로도 정답이 나올줄 알았음요.
// hhwhh 의 경우 오른쪽->왼쪽, 왼쪽->오른쪽의 답이 다름을 알수 있다.
5 2 4 13
hhwhh
		확장
		1	2	3	4	0	1	2	3	4
		h	w	h	h	h	h	w	h	h
감상	1	1	1	1	1	1	1	1	1
swipe	2	2	2	2	0	2	2	2	2
회전		4					4
누적	16	13	6	3 |	1	4	11	14	17
//센터에서 오른쪽 1로 갔다가 왼쪽 3로 돌아오면 비용 총 12 = 10 + 2(원점오기)
//센터에서 왼쪽 3로 갔다가 오른쪽 1로 돌아오면 비용 총 14 = 10 + 4(원점오기)






//삼성 코드 그라운드. 체스판위의 길
https://www.codeground.org
보드위의 함정(2000개)을 피하고 (1, 1)에서 (N, M)으로 도착할 수 있는 경우의 수
보드 사이즈가 크다 가로 100000, 세로 100000
"4 x 8" 보드에서 원점(0, 0) 에서 (4, 8) 로 가는 경우의 수
(4+8)C4 //총 12개의 길을 놓을 수 있는 곳에 세로길 4개를 놓는 경우의 수
--------||||

q에서 u, v를 하나도 안 거치고 d로 가는 경우의 수
.
 .
  q
   u
    v
	 d

A) dp[q] = 6C3 - 2C1*4C2 - 2C1*4C2 + 2C1*2C1*2C1 
//q--d로 가는 모든 경우의 수 - u를 거치는 경우의 수 - v를 거치는 경우의 수 + u와 v를 동시에 거치는 경우의 수
"중간에 거치는 놈이 3개가 되면 계산하기 더욱 복잡해짐
마치 AUBC를 구할때
A + B + C - A^B - A^C - B^C + A^B^C		//^ : 교집합
//거치는 점들이 많을수록 복잡도가 증가하겠지...


B) dp[q] = 6C3 - u를 거치나 v는 안거침 - v를 거침
		 = 6C3 - 2C1*dp[u] - 4C2*dp[v]

---dp[q]-----------------------
	 
    (  u  (   ) v    )
	
-------------------------------

---dp[q]-----------------------
	 
    (  u  (     v    )         //u를 거치나 v는 안 거침 + v를 거침
	
-------------------------------

"앞서 계산한 것을 활용함으로써 복잡도를 줄일수 있게 됨!!!!"

"알고스팟 : 알고리즘에 필요한 수학"
http://theyearlyprophet.com/programming-contest-math.html
https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EC%88%98%ED%95%99

nCr 구하는 알고리즘//전부다가 아님 한놈 특화방식
http://stackoverflow.com/questions/19818762/most-efficient-way-to-calculate-ncr-modulo-142857?lq=1
nCr = nC(r-1) * (n - r + 1) / r
//r은 둘중 한놈에게 나눠 떨어진다네..//아니네 중간 이상 넘어가면 양쪽의 인수를 이용해야 되네
9C0 = 1
9C1 = 9C(1-1) * (9 - 1 + 1) / 1 = 1 * 9 / 1 = 9			//왼쪽
9C2 = 9C(2-1) * (9 - 2 + 1) / 2 = 9 * 8 / 2 = 36		//오른쪽
9C3 = 9C(3-1) * (9 - 3 + 1) / 3 = 36 * 7 / 3 = 84		//왼쪽
9C4 = 9C(4-1) * (9 - 4 + 1) / 4 = 84 * 6 / 4 = 126		//왼쪽
9C5 = 9C(5-1) * (9 - 5 + 1) / 5 = 126 * 5 / 5 = 126		//오른쪽
9C6 = 9C(6-1) * (9 - 6 + 1) / 6 = 126 * 4 / 6 = 84		//왼쪽
9C7 = 9C(7-1) * (9 - 7 + 1) / 7 = 84 * 3 / 7 = 36		//왼쪽
9C8 = 9C(8-1) * (9 - 8 + 1) / 8 = 36 * 2 / 8 = 9		//양쪽
9C9 = 9C(9-1) * (9 - 9 + 1) / 9 = 9 * 1 / 9 = 1			


//헌데 mod를 취하게 된다면 골때리는데..
nCr = {(nC(r-1) + m) * (n - r + 1) / r} % m //이렇게 하면 되지 않을까?(내생각 방식 : 안됨요 ㅠㅠ)

//이항계수 계산하기(구사과)
http://amugelab.tistory.com/entry/%EC%9D%B4%ED%95%AD%EA%B3%84%EC%88%98-nCr-mod-p-%EA%B3%84%EC%82%B0%ED%95%98%EA%B8%B0


//루카스의 정리로 구할수 있다//위에거랑 결과값 비교해보자
//n이 크고 p가 작을때 매우 유용하다.	//소수p 로 진법변환하여 구함
http://bowbowbow.tistory.com/2
#include <iostream>
#include <memory.h>
using namespace std;
#define MAXN 1500
int cache[MAXN][MAXN];
int binomial(int n, int k, int p) {
	if (cache[n][k] != -1) return cache[n][k];
	if (k == 0 || k == n)
		return cache[n][k] = 1;
	return cache[n][k] = (binomial(n - 1, k - 1, p) + binomial(n - 1, k, p)) % p;
}
int main() {
	memset(cache, -1, sizeof(cache));
	int N, K;
	cin >> N >> K;
	cout << binomial(N, K, 7) << endl;
	return 0;
}

//페르마의 소정리
"P가 소수일때
"A^(P-1) % P = 1"//KMO 단골이며 매우 많이 사용된다.
A의 mod P inverse 인 A^(-1)은 어떻게 구하는가
A * A^(p-2) = 1
따라서 A^(p-2)가 inverse가 된다.
3^k, M = 7
3^1 % 7 = 3
3^2 % 7 = 2
3^3 % 7 = 6
3^4 % 7 = 4
3^5 % 7 = 5
3^6 % 7 = 1	//(3 * 3^5) % 7 = 1 따라서 3^5는 3의 MMI가 된다. 
3^7 % 7 = 3

p가 1000000007 정도로 크다한들
승수를 구하는 것은 단순히 분할정복으로 한다.
https://codeaccepted.wordpress.com/tag/modulo-1000000007/
MMI: modulo multiplicative inverse: 나머지 연산 역수
x / y == x * y^(-1) == x * z(where z is multiplicative inverse of y)
"MMI of a number y is z iff (z & y) % M == 1.
int findMMI_bruteforce(int n, int M) {
	for (int i = 1; i < M)
		if (((long long)i * n) % M == 1)
			return i;
	return -1; //MMI doesn't exist;
}
int fast_pow(long long base, long long n, long long M) {
	if (n == 0) return 1;
	if (n == 1) return base;
	long long halfn = fast_pow(base, n/2, M);
	if (n % 2 == 0)
		return (halfn * halfn) % M;
	else
		return (((halfn * halfn) % M) * base) % M;
}
int findMMI_fermat(int n, int M) {
	return fast_pow(n, M - 2, M);
}
//이것 사용하는걸 추천한다. 이상없이 돌아감을 확인했어용!!!!
int fast_pow2(long long base, long long n, long long M) {
	long long ret = 1;
	for (; n; n /= 2) {
		if (n & 1) ret = (ret * base) % M;
		base = (base * base) % M;
	}
	return ret;
}
2^7 을 구한다고 할때
ret = 1

ret = 1 * 2 = 2
base = 2 * 2 = 4

ret = 2 * 4 = 8
base = 4 * 4 = 16

ret = 8 * 16 = 128
base = 16 * 16 = 256

return 128
int findMMI_fermat2(int n, int M) { return fast_pow2(n, M - 2, M); }

int main() {
	long long fact[100001];
	fact[0] = 1;//0! = 1
	int i = 1;
	for (int i = 1; i <= 100000; ++i)
		fact[i] = fact[i - 1] * i % MOD;
	int n, r; //nCr
	cin >> n >> r;
	long long numerator, denominator//분자 분모
	long long mmi_denominator, ans;
	numerator = fact[n];
	denominator = (fact[n - r] * fact[r]) % MOD;
	mmi_denominator = findMMI_fermat(denominator, MOD);
	//long long test = numerator * mmi_denominator % MOD // 1이 됨을 확인함
	ans = (numerator * mmi_denominator) % MOD;
	cout << ans;
	return 0;
}


//8ms
https://algospot.com/judge/problem/read/BRUTEFORCE
MOD = 1000000007; //소수임
//등비수열, 공비수열의 합
//등비수열의 합: a1(r^n - 1) / (r - 1)	: <단 공비 r이 1이 아닌 경우
//공비가 1인경우: a1 * n
long long fast_pow(long long base, long long power) {
	long long ret = 1;
	for (; power; power /= 2) {
		if (power & 1) ret = (ret * base) % MOD;
		base = (base * base) % MOD;
	}
	return ret;
}
int findMMI(long long n) { return fast_pow(n, MOD - 2); }
int main() {
//	freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		long long a, b, n;
		cin >> a >> b >> n;
		if (n == 1) {	//공비가 1인 경우
			cout << b - a + 1 << endl;
			continue;
		}
		int power = b - a + 1;
		long long a1 = fast_pow(n, a);	//초항
		long long numerator = a1 * fast_pow(n, power) % MOD;
		numerator = (numerator - a1 + MOD) % MOD;
		long long mmi_denominator = findMMI(n - 1);
		long long sol = numerator * mmi_denominator % MOD;
		cout << sol << endl;
	}
	return 0;
}

"체스판 위의 길 최종 답 !!!! 좋은 문제였다.
const int MOD = 1000000007;
long long fact[200001];	//n, r이 100000 이 max라면 이것 두배는 잡아줘야함
void precalc() {
	fact[0] = 1;
	for (int i = 1; i <= 200000; ++i)
		fact[i] = fact[i - 1] * i % MOD;
}
int fast_pow(long long base, long long n, long long M) {
	long long ret = 1;
	for (; n; n /= 2) {
		if (n & 1) ret = (ret * base) % M;
		base = (base * base) % M;
	}
	return ret;
}
int findMMI_fermat(int n, int M) { return fast_pow(n, M - 2, M); }
int nCr(long long n, long long r) {
	long long numerator, denominator, mmi_denominator, ans; 
	numerator = fact[n];
	denominator = (fact[n - r] * fact[r]) % MOD;
	mmi_denominator = findMMI_fermat(denominator, MOD);
	ans = (numerator * mmi_denominator) % MOD;
	return ans;
}
int pathCnt(pii u, pii v) {
	if (u.first <= v.first && u.second <= v.second) {
		int rowSZ = v.first - u.first;
		int colSZ = v.second - u.second;
		int ret = nCr(rowSZ + colSZ, rowSZ);
		return ret;
	}
	return 0;
}
int main() {
	precalc();
	int T; cin >> T;
	rep(cc, T) {
		int N, M, K; cin >> N >> M >> K;
		vpii points;
		points.push_back(mp(1, 1));
		for (int i = 1; i <= K; ++i) {
			int y, x; cin >> y >> x;
			if (y >= 1 && y <= N && x >= 1 && x <= M)
				points.push_back(mp(y, x));
		}
		points.push_back(mp(N, M));
		sort(points.begin(), points.end());
		vector<long long> dp(points.size());
		dp[0] = 1; //원점에서 원점으로 갈 경우의 수//useless
		dp[1] = pathCnt(points[0], points[1]);
		for (int i = 2; i < points.size(); ++i) {
			//dp[i] : 원점에서 i번째 점까지 중간에 아무 점도 안 거치고 지나가는 경우의 수
			//dp[i] = pathCnt(0, i) - sum[1..j]{ pathCnt(j, i) * dp[j] }
			dp[i] = pathCnt(points[0], points[i]);
			for (int j = 1; j < i; ++j) {
				int temp = (pathCnt(points[j], points[i]) * dp[j]) % MOD;
				dp[i] += MOD;
				dp[i] -= temp;
				dp[i] %= MOD;
			}
		}
		int sol = dp.back();
		cout << "Case #" << cc + 1 << endl;
		cout << sol << endl;
	}
	return 0;
}
"이해가 안되면 아래 시뮬을 보라"
dp[4] : 원점에서 4번째 점까지 중간에 아무 점도 안 거치고 지나가는 경우의 수
dp[4]	= pathCnt(0, 4)				// 전체 경우의 수
		- pathCnt(1, 4) * dp[1]		// 1번 점을 지나는 경우의 수
		- pathCnt(2, 4) * dp[2]		// 2번 점을 지나고 1번 점을 지나 않는 경우의 수
		- pathCnt(3, 4) * dp[3]		// 3번 점을 지나고 1번, 2번 점을 지나지 않는 경우의 수

http://codeforces.com/contest/652/problem/C
Foe Pairs
길이 n짜리 순열 p를 가지고 있다. m 개의 Foe쌍 (ai, bi) 를 가지고 있다.
(1 <= ai, bi <= n, ai != bi).
1 <= n, m <= 3*10^5
두개를 선택한다. interval (x, y) ( 1 <= x <= y <= n )

4 2		// n, m
1 3 2 4	// 여기서 두개를 선택한다. (중복은 가능함)
3 2
2 4

답: 5	// (1, 2), (1, 1), (3, 3), (2, 2), (4, 4)

//스스로 풀었으며 오류테스트 케이스 보고 문제를 바로 해결했다. 
const int MAX = 300003;
long long dp[MAX];
int H[MAX];
//H_pairL[pairR] = max {pairL }
int H_pairL[MAX];//H2[i] = j //i에서 끝나는 원소가 있는 쌍중 시작하는 원소의 가장 큰 위치 
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int p; cin >> p;
		H[p] = i;	// 각 숫자의 위치를 기록
	}
	rep(i, m) {
		int a, b;
		//cin >> a >> b;	//700ms
		scanf("%d%d", &a, &b);	//370ms
		//좀더 빠르게 입력받으면 실행타임이 80ms 급으로 나옴
		//putchar() 를 써서 문자열을 int로 변형 시켜야 한다만.. 번그럽다.
		int ha, hb;
		ha = H[a]; hb = H[b];	// 해당 숫자의 위치를 알아낸다.
		if (ha > hb) swap(ha, hb);
		H_pairL[hb] = max(H_pairL[hb], ha); // 오른쪽 위치hb 에 대한 왼쪽의 최대 위치를 구한다.
	}
	int maxLeft = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if (H_pairL[i] > 0)
			maxLeft = max(maxLeft, H_pairL[i]); //OMG ...maxLeft = H_pairL[i] error
		int size = i - maxLeft;
		size;
		dp[i] += size;
	}
	cout << dp[n];
	return 0;
}

시뮬
4 2		// n, m
1 3 2 4	// 여기서 두개를 선택한다. (중복은 가능함)
3 2
2 4

H[1] = 1, H[3] = 2, H[2] = 3, H[4] = 4

(3, 2) : ha = H[3] = 2		hb = H[2] = 3
H_pairL[3] = 2

(2, 4) : ha = H[2] = 3		hb = H[4] = 4
H_pairL[4] = 3

1	2	3	4	// (2, 3), (3, 4) 구간이 존재함
dp[1] = (1, 1) 1개
dp[2] = dp[1] + (1, 2), (2, 2) 2개
dp[3] = dp[2] + (3, 3) 1개
dp[4] = dp[3] + (4, 4) 1개

http://codeforces.com/contest/659/problem/E
E. New Reform

양방향 간선들이 여러개 존재함
시장이 간선을 단방향으로 하려고 함
이때 섬이 되는 도시의 수를 가장 적게 할때 (어떤 도로도 그 도시로 갈 수 없는)
그 도시들의 수를 출력하라.

"시간만 있었다면 풀수 있었는데 D번에서 오타로 인해 너무 시간을 지체 했다.
"한번에 통과함..." 30분만에 작성함
"맑은 정신의 중요성을 깨달은 문제임" 메롱인 상태에선 절대 못 풀었을 거다!!!!

각 컴포넌트에 싸이클이 존재하는 걸로 풀이가 변경된다. 
vi graph[100001];
bool visited[100001];
bool dfs(int here, int prnt) {
	visited[here] = true;
	bool hasCycle = false;
	//부모가 아닌데도 방문한 놈이면 사이클이 있다는 것
	for (int i = 0; i < graph[here].size(); ++i) {
		int t = graph[here][i];
		if (prnt != t) {
			if (visited[t] == true)
				hasCycle = true;
			else
				hasCycle = hasCycle || dfs(t, here);
		}
	}
	return hasCycle;
}
int main() {
	memset(visited, 0, sizeof(visited));
	int n, m; cin >> n >> m;
	rep(i, m) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int solCnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == false) {
			bool hasCycle = dfs(i, -1);
			if (hasCycle == false) solCnt++;
		}
	}
	cout << solCnt;
	return 0;
}

http://codeforces.com/contest/659/problem/F
영어 더럽게 길다. 예시를 보면 한번에 이해 될거다.
4 4 50
5 9 1 1
5 1 1 5
5 1 5 5
5 5 7 1

YES
5 5 0 0 
5 0 0 5 
5 0 5 5 
5 5 5 0 

건초 stack 이 쌓인 놈들은 이어져 있어야 한다.
stack 의 높이는 기존 높이랑 같은 셀이 반드시 존재한 것이어야 한다.
stack 높이의 합은 k (위에선 50) 가 되어야 한다.

나머지 들은 높이가 0인 empty 상태로 만들어야 한다.

답이 없으면 no출력해라

//disjointSet 응용문제다. 
"서로 연결되어 있는지 빠른 판단이 필요하고, 
"사이즈도 빠르게 구할 필요가 있고
"연결시 갱신도 빨라야 하는 것을 요구하는 문제였다"
//cin, cout 을 쓰면 scanf, printf 보다 훨씬 느렸다.
//딴건 안봐도 된다만(막짠 코드라...) dsjSet 개조 버전은 잘 봐둬라
const int dy[4] = { 1, 0, 0, -1 };
const int dx[4] = { 0, 1, -1, 0 };
int n, m;
long long k;
int board[1000][1000];
vpii pArr;
vb bUsed;
inline int getNum(int i, int j) { return i * m + j; }
pii getCoord(int num) {
	pii ret;
	ret.first = num / m;
	ret.second = num % m;
	return ret;
}
vi getNeighborhood(int num) {
	pii coord = getCoord(num);
	vi ret;
	rep(i, 4) {
		int ny = coord.first + dy[i];
		int nx = coord.second + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
			continue;
		ret.push_back(ny * m + nx);
	}
	return ret;
}
struct dsjSet {
	vi prnt, rank, size;
	dsjSet(int n) : prnt(n), rank(n, 0), size(n, 1) {
		rep(i, n) prnt[i] = i;
	}
	int find(int u) {
		if (prnt[u] == u) return u;
		return prnt[u] = find(prnt[u]);
	}
	int merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return u;
		if (rank[u] > rank[v]) swap(u, v);
		if (rank[u] == rank[v]) rank[v]++;
		prnt[u] = v;
		size[v] += size[u];
		return v;
	}
	int getSize(int u) {
		u = find(u);
		return size[u];
	}
};

int solBoard[1000][1000];
void dfs(int y, int x, int& cnt, int height) {
	if (y < 0 || y >= n || x < 0 || x >= m) return;
	if (board[y][x] < height) return;
	if (solBoard[y][x] == height) return;
	if (cnt == 0) return;
	solBoard[y][x] = height; cnt--;
	dfs(y + 1, x, cnt, height);
	dfs(y - 1, x, cnt, height);
	dfs(y, x + 1, cnt, height);
	dfs(y, x - 1, cnt, height);

}
void printBoard() {
	rep(i, n) {
		rep(j, m)
			//cout << solBoard[i][j] << " ";
			printf("%d\n", solBoard[i][j]);
		//cout << endl;
		printf("\n");
	}
}
"!!!!!"
//2200ms: cin, cout
//1450ms: scanf, cout
//1075ms: scanf, printf
int main() {
//	FILE* fp;
//	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> n >> m >> k;
	pArr.resize(n * m); bUsed.resize(n * m);
	int iter = 0;
	rep(i, n) rep(j, m) { 
		scanf("%d", &(board[i][j]));
		//cin >> board[i][j]; 
		pArr[iter] = mp(board[i][j], getNum(i, j));
		iter++;
	}
	dsjSet sets(n * m);
	sort(pArr.begin(), pArr.end(), greater<pair<int, int>>());
	int i = 0;
	int count = 0, height = INF, sz;
	" 아래 for문이 핵심 "
	for (i; i < pArr.size(); ++i) {	// 높이를 낮춰가며 추적한다.
		height = pArr[i].first;
		int coordNum = pArr[i].second;
		vi neighborhood = getNeighborhood(coordNum);
		rep(j, neighborhood.size())
			if (bUsed[neighborhood[j]])	// 이전에 방문한 처리된 것이면(현재보다 높거나 같은 것들)
				sets.merge(coordNum, neighborhood[j]);
		sz = sets.getSize(coordNum);
		bUsed[coordNum] = true;
		if ((long long)height * sz >= k)
			if (((long long)height * sz - k) % height == 0) {
				count = k / height;
				break;
			}
	}
	if (i == pArr.size()) { 
		cout << "NO"; return 0; 
	}
	pii start = getCoord(pArr[i].second);
	int startY = start.first;
	int startX = start.second;
	int cnt = count;
	dfs(startY, startX, cnt, height);
	cout << "YES" << endl;
	printBoard();
	return 0;
}



https://code.google.com/codejam/contest/6254486/dashboard#s=p1
// 모든 팬케익이 +가 되도록 하라
5		// 오른쪽이 스택의 밑에 있는 팬캐익임
-
-+
+-
+++
--+-	// 전체 뒤집기 +-++ 후 --++ 로 만든뒤 ++++ 로 만든다.

Case #1: 1
Case #2: 1
Case #3: 2
Case #4: 0
Case #5: 3
//greedy한 방법은 large까지 다 풀수 있다만...
//나는 greedy의 증명을 할수 없었다. 강제로 small set에 대하여 bfs 를 돌려 문제를 풀었다.
//그걸로 greedy 방법이 옳은지 검증을 했으며 모든 small케이스에 대해 greedy가 옳다고 판정이 나왔다.
//제출은 greedy로 했음요.
//내코드에서 눈여겨 볼것은 비트 내부 reverse이다. bfs 돌리는 정도 그외엔 
//다른건(변환이라던가) 볼 필요 없다.
"!!!! 비트 내부 reverse 
//http://articles.leetcode.com/reverse-bits/
int swapBits(int x, int i, int j) {
	int lo = ((x >> i) & 1);
	int hi = ((x >> j) & 1);
	if (lo ^ hi)
		x ^= ((1 << i) | (1 << j));
	return x;
}
int reverseXor(int x, int len) {
	int n = len;
	for (int i = 0; i < n / 2; ++i)
		x = swapBits(x, i, n - i - 1);
	return x;
}
vi getAdj(int state, int len) {
	vi ret;
	int tmp = 0;
	for (int i = 0; i < len; ++i) {
		tmp += (state & (1 << i));
		int invTmp = ~tmp;
		int revTmp = reverseXor(invTmp, i + 1);
		revTmp = revTmp & ((1 << (i + 1)) - 1);
		int pushItem = state & (((1 << 30) - 1) - ((1 << (i + 1)) - 1));
		pushItem += revTmp;
		ret.push_back(pushItem);
	}
	return ret;
}
원본 숫자 1111101000
이중 5개를 추출 하면 tmp = 01000
invTmp = 10111
revTmp = 11101

map<int, int> stateMap;
void precalc() {
	stateMap[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int cost = stateMap[here];
		vi adj = getAdj(here, 11);	//10으로도 충분한데 그냥 안정성으로
		rep(i,adj.size())
			if (stateMap.count(adj[i]) == 0) {
				int there = adj[i];
				stateMap[there] = cost + 1;
				q.push(there);
			}
	}
}
int stringToInt(string str) {
	int ret = 0;
	int add = 1;
	rep(i, str.size()) {
		if (str[i] == '-')
			ret += add;
		add *= 2;
	}
	return ret;
}

-+-+-- => 1 + 0 + 4 + 0 + 8 + 16 => 110101 // 제일 큰 숫자는 제일 뒤 '-' 임
110101 => -+-+--
string intToString(int num) {
	string ret;
	for (; num; num /= 2)
		if (num % 2)
			ret.push_back('-');
		else
			ret.push_back('+');
	//reverse(ret.begin(), ret.end());
	return ret;
}
long long getGreedy(string str) {
	long long ret = 0;
	char prevC = str[0];
	rep2(i, 1, str.size()) {
		if (prevC != str[i]) {
			ret++;
			prevC = str[i];
		}
	}
	if (str.back() == '-')
		ret++;
	return ret;
}
int main() {
	FILE* fp;
	freopen_s(&fp, "B-large.in", "r", stdin);
	freopen_s(&fp, "output.txt", "w", stdout);
	precalc();
	/*
	for (int num = 1; num < 2048; ++num) {
		string str = intToString(num);
		int sol1 = stateMap[num];
		int sol2 = getGreedy(str);
		if (sol1 != sol2)
			cout << "not Equal!!!: " << sol1 << sol2 << endl;
		else
			cout << "num: " << num << ", sol: " << sol1 << endl;
	}
	*/
	int T; cin >> T;
	rep(cc, T) {
		string str; cin >> str;
		int state = stringToInt(str);
		//int sol1 = stateMap[state];
		int sol2 = getGreedy(str);
		//if (sol1 != sol2)
		//	cout << "not Equal!!!!" << endl;
		//else
			cout << "Case #" << cc + 1 << ": " << sol2 << endl;
	}
	return 0;
}


http://codeforces.com/contest/660/problem/C
7 1
1 0 0 1 1 0 1

4
1 0 0 1 1 1 1

분활상환 문제
int arr[300001];
int sz[300001];		// sz[i] : i를 끝으로 하는 경우 사이즈
int main() {
	int useCnt = 0;
	int p = -1;
	int n, k; cin >> n >> k;
	rep(i, n) cin >> arr[i];

	rep(i, n) {
		if (arr[i] == 0) 
			useCnt++;
		if (k < useCnt) {
			++p;
			while (true) {
				if (arr[p] == 0) break;
				++p;
			}
			useCnt--;
		}
		sz[i] = i - p;
	}
	int idx = 0;
	int maxSize = sz[idx];
	
	rep(i, n) if (sz[i] > sz[idx]) {
		idx = i;
		maxSize = sz[i];
	}
	int tran = 0;
	for (int i = idx; i >= 0; --i) {
		if (tran == k) break;
		if (arr[i] == 0) {
			arr[i] = 1;
			tran++;
		}
	}
	cout << maxSize << endl;
	rep(i, n) cout << arr[i] << " ";
	return 0;
}

http://codeforces.com/contest/638/problem/B
"아래 코드는 오류 납니다."
"위상정렬로 풀려고 했는데 위상정렬은 이 문제의 해결방법이 아닙니다."
3
bps
lb
cd
cd가 사이에 들어가도 위상정렬이 되므로
l c d b p s	//"c d"가 사이에 들어가도 위상정렬임
문제의 답이 될수 없다.
"위상정렬의 특징을 기억하시오"
int nex[26];
bool vstd[26];
vector<int> sol;
void dfs(int here) {
	vstd[here] = true;
	if (nex[here] != -1)
		if (vstd[nex[here]] == false)
			dfs(nex[here]);
	sol.push_back(here);
}
int main() {
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	//while (100) {
		int n; cin >> n;
		memset(nex, -1, sizeof(nex));
		memset(vstd, 1, sizeof(vstd));
		rep(i, n) {
			string str; cin >> str;
			rep2(j, 0, str.size() - 1) {
				int u = str[j] - 'a';
				int v = str[j + 1] - 'a';
				nex[u] = v;
				vstd[u] = false;
			}
			int u = str.back() - 'a';
			vstd[u] = false;
		}
		for (int i = 0; i < 26; ++i) if (vstd[i] == false) dfs(i);
		
		reverse(sol.begin(), sol.end());
		rep(i, sol.size()) cout << char(sol[i] + 'a');
	//}
	return 0;
}


https://code.google.com/codejam/contest/4304486/dashboard#s=p2
//해답이 "2노드 69페어"가 들어 있는 경우 "2노드 69페어"가 아닌 원형은 답이 될수 없다. sol2
//해답이 3노드 이상인 원형인 경우 "2노드 69페어"가 답이 될수 없다.
//2노드 69페어가 들어 있는 놈들은 여러개를 합쳐도 문제 없다.
vector<int> Prev[1001];
int Next[1001];
bool vstd[1001];
vpii pair69;
int height(int here) {
	int ret = 1;
	rep(i, Prev[here].size()) {
		int cand = 0;
		int child = Prev[here][i];
		if (child != -1)
			cand = height(child) + 1;
		ret = max(ret, cand);
	}
	return ret;
}
int circular(int here) {
	int sz = 0;
	memset(vstd, 0, sizeof(vstd));
	int start = here;
	vstd[start] = true;
	here = Next[here];
	while (vstd[here] == false) {
		vstd[here] = true;
		sz++;
		here = Next[here];
	}
	if (start == here) { sz++; return sz; }
	return 0;
}
int main() {
	FILE *fp;
	freopen_s(&fp, "C-large-practice.in", "r", stdin);
	freopen_s(&fp, "output.txt", "w", stdout);
	int T; cin >> T;
	rep(cc, T) {
		pair69.resize(0);
		int n; cin >> n;
		memset(Next, -1, sizeof(Next));
		rep(i, n + 1) Prev[i].clear();
		rep2(i, 1, n + 1) {
			int u; cin >> u;
			Prev[u].push_back(i);
			Next[i] = u;
			if (Next[u] == i)
				pair69.push_back(mp(u, i));
		}
		int sol1 = 0;//원형인 경우
		rep2(i, 1, n + 1) sol1 = max(sol1, circular(i));
		int sol2 = 0; //69 노드들로 구성될 경우 경우
		rep(i, pair69.size()) {
			int part1 = 0, part2 = 0;
			int u = pair69[i].first;
			int v = pair69[i].second;
			rep(iter, Prev[u].size()) {
				int there = Prev[u][iter];
				if (there == v) continue;
				int temp = height(there);
				part1 = max(part1, height(there));
			}
			rep(iter, Prev[v].size()) {
				int there = Prev[v][iter];
				if (there == u) continue;
				int temp = height(there);
				part2 = max(part2, height(there));
			}
			sol2 += (part1 + part2 + 2);
		}
		int sol = max(sol1, sol2);
		cout << "Case #" << cc + 1 << ": " << sol << endl;
	}
	return 0;
}

https://code.google.com/codejam/contest/8224486/dashboard#s=p0&a=2
Problem A. Counter Culture
//large풀이
map<long long, long long> myMap;
map<long long, int> myMap2;
int getJari(long long num) {
	int ret = 0;
	while (num != 0) {
		num /= 10;
		ret++;
	}
	return ret;
}
long long power10(int n) {
	long long ret = 1;
	while (n--) {
		ret *= 10;
	}
	return ret;
}
void precalc() {
	long long key = 1;
	myMap[key] = 1;
	key *= 10;
	myMap[key] = 10;
	rep(i, 14) {
		long long num = myMap[key];
		int jari = getJari(key);
		int front = jari / 2;
		int back = jari - front;
		
		long long part1 = power10(back);	//...9로 만든후 뒤집기 횟수
		long long part2 = power10(front) - 1;
		long long num2 = num + part1 + part2;

		key *= 10;
		myMap[key] = num2;
	}
	key = 1;
	rep(i, 15) {
		myMap2[key] = 1;
		key *= 10;
	}
}
int main() {
	precalc();
	FILE *fp;
	freopen_s(&fp, "A-large-practice.in", "r", stdin);
	freopen_s(&fp, "output.txt", "w", stdout);
	int T; cin >> T;
	rep(cc, T) {
		long long num; cin >> num;

		long long sol = 0;
		if (myMap.count(num) > 0)
			sol = myMap[num];
		else {
			int jari = getJari(num);
			int front = jari / 2;
			int back = jari - front;

			int backNum = power10(back);
			int mod = num % backNum;
			if (mod == 0 && myMap2.count(num / backNum) == 0) {

				sol++;
				num--;
				mod = num % backNum;
			}
			
			int part1 = num % backNum;
			int part2 = num / backNum;
			string str = to_string(part2);
			reverse(str.begin(), str.end());
			int rPart2 = atoi(str.c_str());
			if (rPart2 == 1) rPart2 = 0; //reverse할 필요가 없으므로 계산 취소

			long long keyPart = 0;
			if (jari - 1 > 0) keyPart = myMap[power10(jari - 1)];
			sol += keyPart + part1 + rPart2;
		}
		cout << "Case #" << cc + 1 << ": " << sol << endl;
	}
	return 0;
}


https://algospot.com/judge/problem/read/JLIS
int dp[2][102][102];	//dp[0][3][2] //arr1의 세번째(시작이 1번임), arr2의 2번째 원소를 사용했을때
						//arr1이 가장 뒤에 있는 경우 jlis 의 길이
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		int n1; cin >> n1;
		int n2; cin >> n2;
		vi arr1(n1 + 1), arr2(n2 + 1);
		rep(i, n1) cin >> arr1[i + 1];	arr1[0] = 987654321;
		rep(i, n2) cin >> arr2[i + 1];	arr2[0] = 987654321;
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = dp[1][0][0] = 0;
		dp[0][1][0] = 1;	//n1 한개
		dp[1][0][1] = 1;	//n2 한개
		rep(j, n1 + 1) {
			rep(k, n2 + 1) {
				if (j == 0 && k == 0) continue;
				int cand1 = 1, cand2 = 1;
				rep(iterJ, j + 1) {
					rep(iterK, k + 1) {
						if (iterJ == j && iterK == k) continue;
						if (cand1 < dp[0][iterJ][iterK] + 1 && iterJ != j 
							&& arr1[iterJ] < arr1[j])	//arr1, arr2의 [0]번째 원소를 참고할 수도 있으니
							cand1 = dp[0][iterJ][iterK] + 1;	//arr1[0] = arr2[0] = INF로 설정해놨음
						if (cand1 < dp[1][iterJ][iterK] + 1 && iterJ != j
							&& arr2[iterK] < arr1[j])
							cand1 = dp[1][iterJ][iterK] + 1;

						if (cand2 < dp[1][iterJ][iterK] + 1 && iterK != k 
							&& arr2[iterK] < arr2[k])
							cand2 = dp[1][iterJ][iterK] + 1;
						if (cand2 < dp[0][iterJ][iterK] + 1 && iterK != k 
							&& arr1[iterJ] < arr2[k])
							cand2 = dp[0][iterJ][iterK] + 1;
					}
				}
				dp[0][j][k] = cand1;
				dp[1][j][k] = cand2;
				//if (j == 0) dp[0][j][k] = 0;	//없어도 동작은 한다. 다만 dp[0][0][1] = 1이 되어 문제긴 하지만
				//if (k == 0) dp[1][j][k] = 0;	//답 구하는덴 문제 없었다.
			}
		}
		int maxL = 1;
		rep(i, 2) rep(j, n1 + 1) rep(k, n2 + 1)
			maxL = max(maxL, dp[i][j][k]);
		cout << maxL << endl;
	}
	return 0;
}


//https://algospot.com/judge/problem/read/PI  //원주율 외우기
//넘 쉽다. 그냥 알아두자. //타이핑 할 가치도 없다. 읽어두기만 하자.
const int INF = 987654321;
string str;
int dp[10002];
int calc(int index, int len) {
	string part = str.substr(index, len);
	if (part == string(part.size(), part[0])) return 1;
	bool prog = true;
	rep2(i, 1, part.size()) if (part[i] - part[i - 1] != part[1] - part[0]) prog = false;
	if (prog && abs(part[1] - part[0]) == 1) return 2;
	bool alte = true;
	rep(i, part.size()) if (part[i] != part[i % 2]) alte = false;
	if (alte) return 4;
	if (prog) return 5;
	return 10;
}
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> str;
		rep(i, 10002) dp[i] = INF;
		dp[0] = 0;
		int n = str.size();
		rep2(i, 1, n + 1)
			rep2(j, 3, 5 + 1)
			if (i - j >= 0)
				dp[i] = min(dp[i], dp[i - j] + calc(i - j, j));
		cout << dp[n] << endl;
	}
	return 0;
}

//아래소스도 다시 안봐도 된다. 훑어 보기나 하삼. 다만 오류난 원인은 뼈에 새겨라...
https://algospot.com/judge/problem/read/QUANTIZE
const int INF = 987654321;
int dp[11][101];	"!!!!//dp[101][11] 로 설정해서 7번 제출하는 동안 눈치 못까고 틀림
					"뭔가 낌새가 이상타 싶으면 배열사이즈를 꼭 확인하삼 ㅠㅠ
int arr[101]; 
int pSum1[101], pSum2[101];
int n, s;
void precalc(int n) {
	pSum1[0] = arr[0];
	pSum2[0] = arr[0] * arr[0];
	rep2(i,1, n) {
		pSum1[i] = pSum1[i - 1] + arr[i];
		pSum2[i] = pSum2[i - 1] + arr[i] * arr[i];
	}
}
int rSum1(int u, int v) { return pSum1[v] - (u == 0 ? 0 : pSum1[u - 1]);}
int rSum2(int u, int v) { return pSum2[v] - (u == 0 ? 0 : pSum2[u - 1]);}
int calc(int u, int v) {
	u--; v--;
	int sum1 = rSum1(u, v);
	int sum2 = rSum2(u, v);	//square sum
	//int m = (double)sum1 / (v - u + 1) + 0.5;
	int m = int(0.5 + (double)sum1 / (v - u + 1));
	int ret = sum2 - 2 * m * sum1 + m * m * (v - u + 1);
	return ret;
}
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> s;

		rep(i, n) cin >> arr[i];
		sort(arr, arr + n, less<int>());
		precalc(n);
		if (s >= n) { cout << 0 << endl; continue; }
		//양자화 여유분이 없는 상태에선 숫자를 표현 못하므로 INF
		rep2(i, 1, n + 1) dp[0][i] = INF;	
		rep2(i,1, s + 1) {
			rep2(j, 1,n + 1) {
				int cand = dp[i - 1][j];
				rep(k, j) 
					cand = min(cand, dp[i - 1][k] + calc(k + 1, j));
				dp[i][j] = cand;
			}
		}
		cout << dp[s][n] << endl;
	}
	return 0;
}
dp[11][101];
dp[i][j]; i: 양자 그룹갯수(이하도 됨), j: 현재까지 처리한 숫자들

dp[3][5] = min	| dp[2][5]
				| dp[2][4] + calc(5, 5)
				| dp[2][3] + calc(4, 5)
				| dp[2][2] + calc(3, 5)
				| dp[2][1] + calc(2, 5)
				| dp[2][0] + calc(1, 5)
dp[0 ~ s][0] = 0 임 //
dp[0][1 ~ n] = INF	//그룹 용량이 없는데 숫자가 남으면 그건 불가능하므로 INF
sol = dp[s][n]


https://algospot.com/judge/problem/read/SNAIL
"이렇게 세팅하면 틀려용... !!!!	//제약사항에 입력에 들어오는 목표 깊이가 1000이라고
"달팽이가 도달할수 있는 최대 높이가 1000인 것은 아니기 때문이다!!!!
//const int MAX_DEPTH = 1001;	
const int MAX_DEPTH = 2002;	//하루에 2미터 갈 수 있으므로
const int MAX_DAY = 1001;
double dp[MAX_DAY][MAX_DEPTH];

int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, m; cin >> n >> m;	//n: 깊이, m: 장마기간
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		int max_depth = m * 2;
		rep2(i, 1, m + 1) {
			rep2(j, 1, max_depth + 1) {
				dp[i][j] = dp[i - 1][j - 1] * 0.25;
				if (j - 2 >= 0)
					dp[i][j] += dp[i - 1][j - 2] * 0.75;
			}
		}
		double sol = 0;
		rep2(i, n, max_depth + 1)
			sol += dp[m][i];
		//printf("%.10lf", sol); !!!!//printf 를 사용할 때 endl 을 자꾸 빼먹는 실수를 범함
		printf("%.10lf\n", sol);
	}
	return 0;
}




TCO_SRM_689_DIV2_C_ColorfulGardenHard

#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int cache[1 << 16][17];
string sorted, forbid2;
int n;
class ColorfulGardenHard {
public:
	int count(string garden, string forbid) {
		memset(cache, -1, sizeof(cache));
		n = garden.size();
		sorted = garden; forbid2 = forbid;
		sort(sorted.begin(), sorted.end());
		int ret = rec(0, 0, -1);
		return ret;
	}
	int rec(int index, int taken, int last) {
		if (index == n) return 1;
		int& ret = cache[taken][last + 1];
		if (ret != -1) return ret;
		ret = 0;
		for (int next = 0; next < n; ++next) {
			if ((taken & (1 << next)) != 0) continue;
			if (next > 0 && sorted[next - 1] == sorted[next] &&
				(taken & (1 << (next - 1))) == 0) continue;
			if (last != -1 && sorted[last] == sorted[next]) continue;
			if (sorted[next] == forbid2[index]) continue;
			int nextTaken = taken | (1 << next);
			ret += rec(index + 1, nextTaken, next);
			ret %= MOD;
		}
		return ret;
	}
};
"위 방식은 책방식인데 나한텐 네이밍이 익숙치 않아서 변수명 변경함
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int cache[1 << 16][17];
string sorted, forbid2;
int n;
class ColorfulGardenHard {
public:
	int count(string garden, string forbid) {
		memset(cache, -1, sizeof(cache));
		n = garden.size();
		sorted = garden; forbid2 = forbid;
		sort(sorted.begin(), sorted.end());
		int ret = rec(0, 0, -1);
		return ret;
	}
	int rec(int index, int taken, int prevM) {
		if (index == n) return 1;
		int& ret = cache[taken][prevM + 1];
		if (ret != -1) return ret;
		ret = 0;
		for (int thisM = 0; thisM < n; ++thisM) {
			if ((taken & (1 << thisM)) != 0) continue;	//!!!!실수 절라게 많이 하는 부분 1.
			//if ((taken && (1 << thisM)) != 0) continue; 이렇게 해서 망함.
			if (thisM > 0 && sorted[thisM - 1] == sorted[thisM] &&	"!!!!중복된 숫자조합 방지 구문: 핵심부위임"
				(taken & (1 << (thisM - 1))) == 0) continue;	//!!!!실수 많이 하는 부분 2.
			//	(taken & (1 << (thisM - 1)) == 0)) continue; 이렇게 해서 망함
			if (prevM != -1 && sorted[prevM] == sorted[thisM]) continue;
			if (sorted[thisM] == forbid2[index]) continue;
			int nextTaken = taken | (1 << thisM);
			ret += rec(index + 1, nextTaken, thisM);
			ret %= MOD;
		}
		return ret;
	}
};


https://www.codechef.com/problems/LEALCO
"문제 자체는 DP도 아니고 비트마스크로 전수조사하는 문제였음
"각 배열의 값 마다 1씩만 증가 가능하다는것, 한번 증가한놈에 다시 증가시키는 것은 불가능하다는것
"이 영어가 해석이 안되어 괜히 머리 골매고 해맸다.
"간단하니 별볼일 없다만...
"popcount 구현만 보삼.!!!!
/**
 * January 2013 Long Challenge at Codechef
 *
 * Problem:     LEALCO - Little Elephant and Alcohol
 * Author:      Anton Lunyov (Tester and Editorialist)
 * Complexity:  O(2^N * (N-K+1) * K) per test
 * Timing:      0.32 out of 1.00
 *
 * Description:
 * We iterate over all subsets of elephants representing them as bit-masks.
 * For each subset we increase by 1 elements of the array, corresponding to this subset,
 * and check whether the new array is bad (see editorial) strictly by definition
 */
#include <iostream>
#include <vector>
using namespace std;

// check that array is bad (see editorial)
bool isBad(vector<int> R, int K, int M) {
	// the size of the array
	int N = R.size();
	// loop over required values of i
	for (int i = 0; i <= N - K; ++i) {

		// finding maximum, since R[i] >= 1 we could init it by 0
		int maxR = 0;
		for (int j = i; j < K + i; ++j) {
			maxR = max(maxR, R[j]);
		}

		// count the number of elements equal to maximum
		int count = 0;
		for (int j = i; j < K + i; ++j) {
			if(R[j] == maxR) {
				++count;
			}
		}

		// if we found at least M such elements, the array is bad
		// and we could not check other values of i
		if (count >= M) {
			return true;
		}
	}
	return false;
}

// count the number of ones in binary form of x
// you can also use __builtin_popcount as well
int popcount(int x) { //!!!! 좋은 코드
	int res = 0;
	while (x > 0) {
		// delete the lowest bit
		// like 6 -> 4, or 3 -> 2, or 104 -> 32
		x -= x & -x;
		++res;
	}
	return res;
}

int main() {
	// input number of tests
	int T;
	cin >> T;

	// loop over tests
	for (int t = 0; t < T; ++t) {

		// input numbers N, K, M
		int N, K, M;
		cin >> N >> K >> M;

		// creating and input array R[]
		vector<int> R(N);
		for (int i = 0; i < N; ++i) {
			cin >> R[i];
		}

		// we init res by N + 1 since it is strictly larger
		// than the size of any subset
		int res = N + 1;

		// loop over subsets, we call them masks
		for (int mask = 0; mask < (1<<N); ++mask) {

			// we at first count the size of the subset
			// it is just the number of ones in binary form of mask
			int size = popcount(mask);

			// if the size appears to be not less than res
			// then there is no sense to check this subset
			// so we skip it
			if (res <= size) {
				continue;
			}

			// create new array after increasing by 1 elements
			// of the subset mask in the initial array
			vector<int> newR(N);
			for (int i = 0; i < N; ++i) {
				// check that R[i] belongs to the subset
				if (mask & 1<<i) {
					newR[i] = R[i] + 1;
				} else {
					newR[i] = R[i];
				}
			}

			// if array is not bad then the subset is a candidate for the answer
			if (!isBad(newR, K, M)) {
				// but actually we know already that size < res
				// so this subset is indeed better than the previous candidate
				res = size;
			}
		}

		// we adjust result to conform the output format
		// res equals N+1 if we did not find any proper subset
		// hence we should set the answer to -1 in this case
		if (res == N + 1) {
			res = -1;
		}

		// output the result
		cout << res << endl;
	}
}







http://codeforces.com/contest/669/submission/17508066
//규칙성 찾기 문제였음.
"음수에 대해 나머지 연산을 취할때 어찌 하는지만 기억하자...
//long long 형에다가 자꾸 쌓아놓고 (oddShift, evenShift)에 
//아주 큰수를 더하고(n * 10000000) 그 뒤 % n을 했는데도 틀렸다고 떴었다.

//중간 계산마다 나머지 연산을 취하니 통과한다.
//앞으론 중간 계산마다 나머지 연산을 하자.. 괜히 꼼수써서 틀렸다.
int main() {
	int n, q; cin >> n >> q;
	int odd = 1;
	int even = 0;

	long long oddShift = 0;
	long long evenShift = 0;
	rep(i, q) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			cin >> op;
			oddShift += op;
			evenShift += op;
			oddShift %= n;
			evenShift %= n;
		}
		else {
			if ((odd + oddShift) % 2) 
				oddShift++;
			else
				oddShift--;
			if ((even + evenShift) % 2) 
				evenShift++;
			else
				evenShift--;

			oddShift %= n;
			evenShift %= n;
		}
	}
	oddShift += n;
	oddShift %= n;
	evenShift += n;
	evenShift %= n;
	vi arr(n);
	rep(i, n) arr[i] = i + 1;
	vi sol(n);
	rep(i, n)
		if (i % 2 == 0)	//odd
			sol[(i + oddShift) % n] = arr[i];
		else
			sol[(i + evenShift) % n] = arr[i];
	rep(i, n)
		printf("%d ", sol[i]);
	return 0;
}

"오오 단축코딩 정말 좋은거다" "!!!!!!!!!"
	int test[4][6];
	int a = 0;
	rep(i, 4) rep(j, 6) test[i][j] = a++;
	rep(i, 4) rep(j, 6) cout << test[i][j] << " \n"[j != 6 - 1 ? 0 : 1];
	rep(i, 4) rep(j, 6) printf("%d%c", test[i][j], " \n"[j != 6 - 1 ? 0 : 1]);
0 1 2 3 4 5
6 7 8 9 10 11
12 13 14 15 16 17
18 19 20 21 22 23
0 1 2 3 4 5
6 7 8 9 10 11
12 13 14 15 16 17
18 19 20 21 22 23



https://www.acmicpc.net/problem/1014
//책 424 쪽 참고하였고 가지치기를 넣어서 통과하였다. 
//가지치기로 타임아웃 안 날때까지 약 10번을 제출하는 굴욕을 당함....ㅠㅠ
//굳이 다시 타이핑연습할 필욘 없다.
//그냥 굴욕만 기억하자..
//실제 사람들 제출한 소스는 나랑 전혀 다른것 같았음....
//10ms이내에 통과한 사람도 있음(제한시간은 2000ms)
//나는 250ms에 통과했다.
"sys7961의 소스를 보니 네트워크유량문제로 풀었군.. 시간내서 보자. 구글 sub1 수준보단 높으니 일단 나중에 보자
"0ms 라고 떠있음. 커닝2도 풀수 있을거라 봄.
int dx[5] = { 0, 1, 1, -1, -1 };
int dy[5] = { 0, -1, 0, -1, 0 };
int h, w;
int check[10][10];int covered[10][10];int fence[10][10];
vector<string> board;
int best;
int cnt;
vi rowXcnt;
//가지치기
int remain(int y, int x) {
	int ret = 0; 
	int a = (w + 1 - x) / 2;
	int b = 0;
	if (y + 1 < h) b = rowXcnt[y + 1];
	ret = a + b;
	return ret;
}
bool sett(int y, int x, int dt) {
	bool ok = true;
	rep(i, 5) {
		int cy = y + dy[i], cx = x + dx[i];
		if (cy < 0 || cx < 0 || cy >= h || cx >= w) continue;
		if (fence[cy][cx] == 1) continue;
		check[cy][cx] += dt;
		if (covered[cy][cx] > 0) ok = false;
	}
	covered[y][x] += dt;
	return ok;
}
void search(int placed) {
	//cnt++;
	//if (cnt > 800000) return;
	int y = -1, x = -1;
	rep(i, h) {
		rep(j,w)
			if (covered[i][j] == 0 && check[i][j] == 0 && fence[i][j] == 0) {
				bool ok = true;
				//rep2(iter, 1, 5) {
				//	int cy = y + dy[iter], cx = x + dx[iter];
				//	if (cy < 0 || cx < 0 || cy >= h || cx >= w) continue;
				//	if (covered[cy][cx] == 1) ok = false;
				//}
				if (ok) { y = i; x = j; break; }
			}
		if (y != -1) break;
	}
	if (y == -1) { 
		best = max(best, placed); 
		return; 
	}
	int pmax = remain(y, x);
	if (placed + pmax <= best) 
		return;
	if (sett(y, x, 1))
		search(placed + 1);
	sett(y, x, -1);
	fence[y][x] = 1;
	search(placed);
	fence[y][x] = 0;
}
int solve() {
	cnt = 0;
	best = 0;
	for (int i = h - 1; i > 0; --i) {
		rowXcnt[i - 1] += rowXcnt[i];
	}
	search(0); 
	return best;
}
void precalc() {
	rep(i, h) {
		int maxCnt = 0;
		int consec = 0;
		rep(j, w) {
			if (fence[i][j] == 1) {
				maxCnt += ((consec + 1) / 2);
				consec = 0;
				continue;
			}
			if (fence[i][j] == 0)
				consec++;
			if (j == w - 1) {
				maxCnt += ((consec + 1) / 2);
			}
		}
		rowXcnt[i] = maxCnt;
	}
}
int main() {
	//FILE* fp;
	//freopen_s(&fp, "input.txt", "r", stdin);

	int cs; cin >> cs;
	rep(cc, cs) {
		memset(check, 0, sizeof(check));
		memset(covered, 0, sizeof(covered));
		cin >> h >> w;
		board.resize(h);
		rowXcnt = vi(h, 0);
		rep(i, h) cin >> board[i];
		rep(i, h) {
			rep(j, board[i].size()) {
				if (board[i][j] == 'x') {
					fence[i][j] = 1;
				}
				else
					fence[i][j] = 0;
			}
		}
		precalc();
		solve();
		cout << best << endl;
	}
	return 0;
}

//sys7961 소스임
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v, cap);
        Edge *rev = new Edge(u, 0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int dfs(int x, int c) {
        if (check[x]) return 0;
        check[x] = true;
        if (x == sink) {
            return c;
        }
        for (int i = 0; i<graph[x].size(); i++) {
            if (graph[x][i]->capacity > 0) {
                int nc = graph[x][i]->capacity;
                if (c != 0 && c < nc) {
                    nc = c;
                }
                int f = dfs(graph[x][i]->to, nc);
                if (f) {
                    graph[x][i]->capacity -= f;
                    graph[x][i]->rev->capacity += f;	//1!!! 참고할만하다.
                    return f;
                }
            }
        }
        return 0;
    }
    int flow() {
        int ans = 0;
        while (true) {
            fill(check.begin(), check.end(), false);
            int f = dfs(source, 0);	//최대 유량을 찾는다.
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};
"아래 배열땜시 해석이 ㅈ같이 어렵게 될뻔했다..."
const int X[] = { -1, 0, +1, -1, 0, +1 };	//이거 Y의 변화임
const int Y[] = { +1, +1, +1, -1, -1, -1 };	//이거 X의 변화임
char ma[20][20];
int main(){
    int tc;
    scanf("%d", &tc);
    while (tc--){
        int n,m;
        scanf("%d%d", &n, &m);	//n: row, m: col
        for (int i = 0; i < n; i++){
            scanf("%s", ma[i]);	//cin >> ma[i]; 해도 됨
        }
        int source = 0;
        auto idx = [&](int i, int j){return i*m + 1 + j; };//!!!! 처음보는 문법이넹...
        auto inner = [&](int i, int j){return i >= 0 && i < n && j >= 0 && j < m; };
        int sink = n*m + 1;	//모든 칸 갯수 + 1
        MaximumFlow flow(sink + 1, source, sink);	//모든 칸캣수 + 1 + 1, source, sink
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (ma[i][j] == '.'){
                    cnt++;
                    if (j % 2 == 0){
                        flow.add_edge(source, idx(i, j), 1);	//idx(i,j)의 리턴은 int임
                        for (int k = 0; k < 6; k++){
                            int nx = i + X[k];
                            int ny = j + Y[k];
                            if (inner(nx, ny) && ma[nx][ny]=='.'){
                                flow.add_edge(idx(i,j), idx(nx,ny), 1);
                            }
                        }
                    }
                    else{
                        flow.add_edge(idx(i, j), sink, 1);
                    }
                }
            }
        }
        printf("%d\n", cnt - flow.flow());	//전체 점 갯수
    }
}

\ /
-.-
/ \

a 1
b 2
c 3
d 4


src -- a
src -- b
src -- c
src -- d

a -- 1
a -- 2
b -- 1
b -- 2
b -- 3
c -- 2
c -- 3
c -- 4
d -- 3
d -- 4

1 -- snk
2 -- snk
3 -- snk
4 -- snk

networkFlow = 4;
sol = 8 - 4 = 4;



a 1
x 2
c 3
d 4

src -- a
src -- c
src -- d

a -- 1
a -- 2
c -- 2
c -- 3
c -- 4
d -- 3
d -- 4

1 -- snk
2 -- snk
3 -- snk
4 -- snk

networkFlow = 3;	//이것이 무엇을 의미하는가: !!!!
sol = 7 - 3 = 4;






TCO2016 round1C div1 b "TreeProgrammers"
B는 한번 일하면 다음날 쉬어야 하고
C는 한번 일하면 이틀을 쉬어야 하고
A는 계속 일하는 것이 가능함

Constraints
- code will contain between 1 and 50 characters, inclusive.
- Each character in code will be one of 'A', 'B', and 'C'.
"CBB"
Returns: "BCB"
Bob cannot work on two consecutive days. Hence, "BCB" is the only valid code history that is a permutation of the given input.

#include <string>
#include <cstring>
#define rep(i,a) for (int i = 0; i < (a); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)
using namespace std;

//dp[aCnt][bCnt][cCnt][prev][prev_prev][index]
int dp[51][51][51][3][3][51];	//마지막 index 차수는 없어도 돌아감. //index is for debugging
class ThreeProgrammers {
public:
	string validCodeHistory(string code) {
		memset(dp, -1, sizeof(dp));
		int cntABC[3] = { 0, 0, 0 };
		rep(i, code.size()) cntABC[code[i] - 'A']++;
		string ret = recon(cntABC[0], cntABC[1], cntABC[2], -1, -1, 0);
		return ret;
	}
	//최초호출: rec(an, bn, cn, -1, -1, 0);
	int rec(int a, int b, int c, int prev_abc, int prev_prev_abc, int index) {
		if (a == 0 && b == 0 && c == 0) return 1;
		if (a < 0 || b < 0 || c < 0) return 0;
		int& ret = dp[a][b][c][prev_abc][prev_prev_abc][index];
		if (ret != -1) return ret;
		ret = 0;
		//A를 넣는 경우
		int here_abc = 0;
		ret += rec(a - 1, b, c, here_abc, prev_abc, index + 1);
		//B를 넣는 경우
		if (prev_abc != 1) {
			here_abc = 1;
			ret += rec(a, b - 1, c, here_abc, prev_abc, index + 1);
		}
		//C를 넣는 경우
		if (prev_abc != 2 && prev_prev_abc != 2) {
			here_abc = 2;
			ret += rec(a, b, c - 1, here_abc, prev_abc, index + 1);
		}
		if (ret > 0) ret = 1;
		return ret;
	}
	//최초호출: recon(an, bn, cn, -1, -1, 0);	//reconstruct
	string recon(int a, int b, int c, int prev_abc, int prev_prev_abc, int index) {
		//무사히 끝까지 도달한다면
		if (a == 0 && b == 0 && c == 0) return "";
		int here_abc = 0;
		int ok = rec(a - 1, b, c, here_abc, prev_abc, index + 1);
		if (ok == 1) 
			return "A" + recon(a - 1, b, c, here_abc, prev_abc, index + 1);
		if (prev_abc != 1) {
			here_abc = 1;
			ok = rec(a, b - 1, c, here_abc, prev_abc, index + 1);
			if (ok == 1)
				return "B" + recon(a, b - 1, c, here_abc, prev_abc, index + 1);
		}
		if (prev_abc != 2 && prev_prev_abc != 2) {
			here_abc = 2;
			ok = rec(a, b, c - 1, here_abc, prev_abc, index + 1);
			if (ok == 1)
				return "C" + recon(a, b, c - 1, here_abc, prev_abc, index + 1);
		}
		return "impossible"; //불가능한 경우
	}
};

"!!!!아주 좋은 문제" 그래프 응용 좋네용.
http://codeforces.com/contest/557/problem/D
//홀수개의 사이클을 가지도록 엣지를 추가한다고 할때
//1. 필요한 최소 엣지수, 2. 선택가능한 경우의 수를 출력하라.
//예시를 보면 알수 있듯 2.의 선택가능한 경우의 수는 선택하는 엣지들의 조합갯수임. 
//만들어 질수 있는 사이클의 갯수가 아니다.(오해를 일으키는 부분이었음)
"the minimum number of edges that should be added to the graph to 
"form a simple cycle of an odd length consisting of more than one vertex 
"where each vertex occurs at most once, and the number of ways to do this.
input
4 4
1 2
1 3
4 2
4 3
output
1 2

"내가 영문해석 오해한 부분 
"최소 홀수 사이클"을 만드는 최소 엣지를 구하는게 아님
"홀수 사이클"을 만드는 최소 엣지를 구하는 것임!!!!
input
5 4
1 2
2 3
3 4
4 5
output
1 4
//	1 ----- 2
//    ____/
//  3 ----- 4
//    ____/
//  5
3 -- 1 추가 //(1 -- 2 -- 3" -- 1")
5 -- 1 추가//(1 -- 2 -- 3 -- 4 -- 5" -- 1")
5 -- 3 추가//(3 -- 4 -- 5" -- 3")
4 -- 2 추가//(2 -- 3 -- 4" -- 2")

//통과소스
http://codeforces.com/contest/557/submission/11877237
const int maxn = 100000 + 5;
vector<int> adj[maxn];
int vstd[maxn], cnt1, cnt2;
bool dfs(int here, int col = 1) {
	(col == 1 ? cnt1 : cnt2)++;
	vstd[here] = col;
	rep(i, adj[here].size()) {
		int there = adj[here][i];
		//이미 방문한 정점이고 사이클인데 크기가 홀수인 사이클을 이룬다면
		if (vstd[there] != -1 && vstd[here] == vstd[there]) return 0;
		//아직 방문은 안했지만 후손들이 홀수 사이클을 가진다면
		if (vstd[there] == -1 && !dfs(there, 3 - col)) return 0;
	}
	return 1;	//홀수 사이클이 없어용
}
"0이 리턴된다 --> 홀수 사이클이 존재한다 --> 2분 그래프가 아니게 된다!!!!
int main() {
	int n, m; cin >> n >> m;
	if (m == 0) {	//a: 전체점중 3개를 선택하는 경우의 수를 구한다.
		cout << 3 << " " << (long long)n * (n - 1) * (n - 2) / 6; return 0;
	}
	rep(i, m) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	memset(vstd, -1, sizeof(vstd));
	long long ans = 0;
	rep2(i, 1, n + 1)
		if (vstd[i] == -1) {
			cnt1 = 0; cnt2 = 0;
			if (!dfs(i)) {	//d: 홀수 사이클이 존재한다면	//!!!!이런 구조 좋네.. 
				cout << 0 << " " << 1; return 0;
			}
			//bipartite 구조를 따름
			ans += (long long)cnt1 * (cnt1 - 1) / 2
				+ (long long)cnt2 * (cnt2 - 1) / 2;
		}
	if (ans) {	//b: 점에 붙어있는 엣지가 최소 2개 이상인 케이스
		cout << 1 << " " << ans; return 0;
	}
	else	//c: 점에 붙어있는 엣지가 최대 한개인 케이스
		cout << 2 << " " << (long long)m * (n - 2);
	return 0;
}

To solve this problem we can use dfs which will check every connected component of graph on bipartite. 
It is clearly that count of edges which we need to add in graph to get the odd cycle is no more than three.
//a:
Answer to this problem is "three" if count of edges in graph is zero. 
Then the number of ways to add three edges in graph to make odd cycle is equals to 
n * (n - 1) * (n - 2) / 6 where n — count of vertices in graph.
//c:
Answer to this problem is "two" if there is no connected component with number of vertices more than two. 
Then the number of ways to add two edges in graph to make odd cycle is equals to
m * (n - 2) where m — number of edges in graph.

Now we have one case when there is at least one connected component with number of vertices more than two. 
Now we need to use dfs and try to split every component in two part.
//d:
If for some component we can't do it that means that graph already has odd cycle and we need to print "0 1" 

and we can now finish our algorithm.
//b: !!!!
If all connected components in graph are bipartite then we need to iterate on them. 
Let cnt1 is the count of vertices in one part of current component and cnt2 — count of vertices in the other part. 
If number of vertices in this component more than two 
we need to add to answer cnt1 * (cnt1 - 1) / 2 and cnt2 * (cnt2 - 1) / 2.

Asymptotic behavior of this solution — O(n + m), where n — number of vertices in graph and m — number of edges



http://codeforces.com/contest/667/problem/C
more than 4 ==> 구글 번역은 4이상: ㅅㅂ, "실제론 4보다 큰: 4초과를 의미 !!!!"
//오호 통재라...
//첨엔 영어해석이 살짝 잘못되어 1번 틀렸으나(분리된 각 단어끼리 비교해야 하는데 그렇게 생각 못함)
//곧 의미 파악하고 수정해서  pre test는 통과 했다
//헌데... prevSize가 최초 호출일때 0으로 호출하는데( root는 기본적으로 크기가 5이상이므로)
"테스트 aaaaaaa는 해볼려고 했었는데 안해서... 슬프네....
//내꺼 0
//정답 
1
aa

input
abacabaca
output
3
aca
ba
ca
//수정해서 통과시킨 코드.
map<string, int> my;
string str;
int n;
int cache[10002][4];
int rec(int here, int prevSize) {	//prevSize: 0, 2: 2size, 3: 3size
	if (here == n) return 1;
	if (here > n) return 0;
	int& ret = cache[here][prevSize];
	if (ret != -1) return ret;

	int prev3 = here - 3, prev2 = here - 2;
	string pstr3 = str.substr(prev3, 3);
	string pstr2 = str.substr(prev2, 2);

	string nstr3 = "", nstr2 = "";	//다음 스트링
	ret = 0;
	if (here + 3 - 1 < n)
		nstr3 = str.substr(here, 3);
	if (here + 2 - 1 < n)
		nstr2 = str.substr(here, 2);
	if (pstr3 != nstr3 || prevSize != 3) {	//이전 사이즈가 3이 아닐때
//	if (pstr3 != nstr3 || prevSize == 2) {	//이래서 틀림... 이전 사이즈가 0도 들어오는데 말야...
		int ok = rec(here + 3, 3);
		if (ok == 1 && nstr3.size() == 3) {
			my[nstr3]++;
			ret++;
		}
	}
	if (pstr2 != nstr2 || prevSize != 2) {	//이전 사이즈가 2가 아닐때
//	if (pstr2 != nstr2 || prevSize == 3) {  //요것도 위랑 같이 오류 부분...ㅠㅠ
		int ok = rec(here + 2, 2);
		if (ok == 1 && nstr2.size() == 2) {
			my[nstr2]++;
			ret++;
		}
	}
	//int ok = rec(here + 1);
	//if (ok == 1) ret++;
	if (ret > 0) ret = 1;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	my.clear();
	cin >> str;
	n = str.size();
	for (int i = 5; i < n; ++i) {
		rec(i, 0);
	}
	cout << my.size() << endl;
	map<string, int>::iterator it;
	for (it = my.begin(); it != my.end(); ++it) {
		cout << it->first << endl;	//map자체가 정렬순서로 key 순회합니다.!!!!
	}
	return 0;
}
//짜투리!!!!
	string str123 = "0123456789";
	string sub_str = str123.substr(8, 10);	//이래도 사이즈 오바안함
	cout << sub_str << endl;	//"89" , size = 2 로 세팅됨을 확인함
//아래는 짜투리 활용 짧게 해서 통과한 코드임
map<string, int> my;
string str;
int n;
int cache[10002][4];
int rec(int here, int prevSize) {
	if (here == n) return 1;
	if (here > n) return 0;
	int& ret = cache[here][prevSize];
	if (ret != -1) return ret;

	ret = 0;
	//이전 사이즈가 3이 아니거나 3이라도 다음 글자랑 다르다면
	if (prevSize != 3 || str.substr(here - 3, 3) != str.substr(here, 3)) {
		int ok = rec(here + 3, 3);
		if (ok == 1) {
			my[str.substr(here, 3)]++;
			ret++;
		}
	}
	//이전 사이즈가 2가 아니거나 2라도 다음 글자랑 다르다면
	if (prevSize != 2 || str.substr(here - 2, 2) != str.substr(here, 2)) {
		int ok = rec(here + 2, 2);
		if (ok == 1) {
			my[str.substr(here, 2)]++;
			ret++;
		}
	}
	if (ret > 0) ret = 1;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	my.clear();
	cin >> str;
	n = str.size();
	rep2(i, 5, n) rec(i, 0);
	cout << my.size() << endl;
	map<string, int>::iterator it;
	for (it = my.begin(); it != my.end(); ++it)
		cout << it->first << endl;
	return 0;
}

//윗코드를 점화식으로 나타내고 for 문으로 작성해보자.



http://codeforces.com/contest/667/problem/D
//총 서로 다른 4지점을 가고 싶음
//지점간 가장 가까운 이동 통로를 거친다고 할때
//총거리가 가장 큰 패스를 구하라.//이런 문제는 한글 해석도 어렵더라...ㅠㅠ

//돈 아낄려고 각 지점간엔 최소 거리를 통해 가고 싶음
Of course, to save money, he will chose the shortest paths between these cities.
But as you have probably guessed, Cicasso is a weird person.

//총 이동 거리는 가능한 가장 크게 하고 싶음.
So he wants the total distance which he will travel to be as large as possible.


http://codeforces.com/contest/667/submission/17578505
//아래는 윗 소스를 내가 읽기 편하게 살짝 변경만 한거임. 제출은 안했음 
//기준 엣지랑 그 양옆 점으로 부터 탐색. 
//양방향 탐색 효과로 시간을 줄인듯. 정답 해설을 보자
int n, m;
vi g[maxn], gr[maxn];
vector<pii> order[maxn], orderr[maxn];
int matr[maxn][maxn];	//vector<int> gg배열 전달을 잘 보삼!!!!
void bfs(int v, vi gg[], vector<pii> &vec, bool ok) {	//bfs : bigO(V + E) 
	vi dist(n + 1, INF);									//여기선 bigO(VlgV)	//E가 작아서
	dist[v] = 0;	//현 노드는 거리 제로
	queue<int> q; q.push(v);
	while (!q.empty()) {
		int here = q.front(); q.pop();
		rep(i, gg[here].size()) {
			int there = gg[here][i];
			if (dist[there] > dist[here] + 1) {
				dist[there] = dist[here] + 1;
				if (ok) matr[v][there] = dist[there];
				q.push(there);
			}
		}
	}
	rep2(i,1,n+1) vec.pb(mp(dist[i], i));
	sort(vec.begin(), vec.end());
	while (!vec.empty() && vec.back().first >= INF) vec.pop_back(); //거리가 무한인 놈은 필요없음
	reverse(all(vec));	//큰놈부터 저장
}
int solve() {
	cin >> n >> m;
	rep(i,m) { int u, v; cin >> u >> v;	g[u].pb(v);	gr[v].pb(u); }
	rep2(i,1,n+1) rep2(j,1,n+1) if (i == j) matr[i][i] = 0; else matr[i][j] = INF;
	//대부분의 시간 차지: 복잡도 사천만 정도.. 3000 * 3000 * lg(3000) = 900000 * 12
	rep2(i,1,n+1) {	bfs(v, g, order[v], 1);	bfs(v, gr, orderr[v], 0); } 
	int answer = 0;	vi vans;
	rep2(u,1,n) {
		rep2(v,1,n) {
			if (u == v) continue;
			rep(i,4) {
				if (orderr[u].size() <= i) continue;	//orderr[u].size() > i
				rep(j,4) {	
//rep(i,4) rep(j,4) 이 짓을 하는 이유는 u2, v2가 v, u랑 동일할 수 있기 때문이다.!!!!
//rep(i,3) rep(j,3) 사이즈 3개 까지로 충분하다고 생각한다만..
					if (order[v].size() <= j) continue;	//order[v].size() > j
					int u2 = orderr[u][i].second,	du = orderr[u][i].first;
					int v2 = order[v][j].second,	dv = order[v][j].first;
					int sum = du + matr[u][v] + dv;
					if (sum < INF && sum > answer) {
						set<int> mset;
						mset.insert(u), mset.insert(v);
						mset.insert(u2), mset.insert(v2);
						if (mset.size() == 4) {
							answer = sum; vans = { u2, u, v, v2 }; //!!!!
						}
					}
				}
			}
		}
	}
	rep(i,vans.size()) cout << x << ' ';
	return 0;
}
"고찰: 엣지가 얼마 안되는데도 플로이드만 생각해서 복잡도를 너무 커게 잡아 헤메었다"
"각 정점당 최대 거리들 순으로 정렬된 형태를 만들어도 사이즈는 대략 90만 이니 돌아간다.
"중간 라인 잡고 뒷쪽, 앞쪽 을 붙이자는 생각까지 했다는건 나자신에게 칭찬~~


https://code.google.com/codejam/contest/11254486/dashboard#s=p2&a=2
Problem C. Technobabble

Every year, your professor posts a blank sign-up sheet for a prestigious scientific
research conference on her door. 
If a student wants to give a lecture at the conference, 
they choose a two-word topic that is not already on the sheet and write it on the sheet. 
Once the deadline has passed, the professor has one of her grad students put the topics in a random order,
to avoid biasing for or against students who signed up earlier. Then she presents the topics to you for review.

Since the snacks at the conference are excellent, some students try to fake their way into the conference. 
They choose the first word of some topic already on the sheet and the second word of some topic already on the sheet, 
and combine them (putting the first word first, and the second word second) 
to create a new "topic" (as long as it isn't already on the sheet). 
Since your professor is open-minded, sometimes this strategy actually works!

//해석하기 어려웠어요...ㅠㅠ
The fakers are completely unoriginal and can't come up with any new first or second words on their own; 
they must use existing ones from the sheet. 
Moreover, they won't try to use an existing first word as their own second word 
(unless the word also already exists on the sheet as a second word), or vice versa.


"뭔 생각으로 아래가 돌아갈거라 추측했을까...ㅠㅠ
"C번이면 이런 간단한 알고리즘으로 돌아갈리가 없다. 
"구글 코드잼이다 이건 ....
"코드포스 div2수준이 아니란 말이다!!!!...

map<string, int> my1;
map<string, int> my2;
map<string, string> my3;
vector<string> s1, s2;
int main() {
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	//freopen_s(&fp, "C-small-attempt3.in", "r", stdin);
	//freopen_s(&fp, "output.txt", "w", stdout);
	int T; cin >> T;
	rep(cc, T) {
		s1.clear(); s2.clear();
		my1.clear();
		my2.clear();
		my3.clear();
		int n; cin >> n;
		long long sol = 0;
		rep(i, n) {
			string str1, str2, sumstr;
			cin >> str1 >> str2;
			my1[str1]++;
			my2[str2]++;
			s1.push_back(str1);
			s2.push_back(str2);
		}
		rep(i, n) {
			string str11 = s1[i];
				string str22 = s2[i];
				if (my1[str11] > 1 && my2[str22] > 1) {
					my1[str11]--;
					my2[str22]--;
					sol++;
				}
		}
		cout << "Case #" << cc + 1 << ": " << sol << endl;
		
	}
	return 0;
}
"반례만 찾았어도 이 코드를 수정해서 풀수 있었을 건데..."
"반례 찾기가 무지 어려웠어요..." //반례 찾고 그 원인을 분석해 보자... 
//반례 : 
//이 경우는 확실히 SOL 이 0이 된다. 
A ----- B
C ----- D
A ----- E
F ----- D
//여기에 하나만 추가하면
C ----- E

SOL 이 2가 된다. //근데 정답이다..  { C, E }, { F, D }, { A, B } 를 가지고 { C, D }, { A, E } 를 만들수 있기 때문이다...
반례찾기 무지 힘들다...
"반례를 못 찾으니 내가 문제를 잘못 해석했나로 빠져 무한 츠쿠요미상태에 빠져 버렸다.. "
"이 경우 그리디에 대한 확신보단.. 케이스가 작은 SMALL에 대해 완전탐색을 먼저 구하도록 했어야 했다..."

//반례 찾았다..: 답이 3인데 4가 출력됨
1
9
A B
A D
A F
C B
C D
C F
E B
E D
E F
//각각 완전 연결되있음
A    B
C    D
E    F
str1[A] = 3		str2[B] = 3
str1[C] = 3		str2[D] = 3
str1[E] = 3		str2[F] = 3



//whether or not 뜻.. 몰랐다...ㅠㅠ
//Do you know whether or not this bus goes to the CN tower.
Each topic on the list could be "faked" or "un-faked." One natural brute force solution is to enumerate
all possible orderings of the topics, and pick the one that has the most faked topics.

It's easy to check whether a topic could have been faked: 
simply check whether the first word of the topic appears as a first word earlier in the list,
and the second word of the topic appears as a second word earlier in the list. 
//첫번째 단어가 이전 리스트에 있느냐 & 두번째 단어가 이전 리스트에 있느냐

//해석 졸라게 어렵다...
Note that marking a topic as faked does not change whether or not topics later in the list can be marked as faked, 
so using this strategy, it is optimal to always count a topic as faked if possible.

However, there are N! possible orderings, which is too large to enumerate even for the small dataset where N ≤ 16 
(16! is on the order of 21 trillion). We need a better approach. 
Rather than trying to maximize the number of faked topics, 
let's think about the reverse problem:
"trying to minimize the number of un-faked topics. //!!!!"

The key observation is that any possible set of un-faked topics must contain 
every first word at least once and every second word at least once — 
otherwise, there would be a faked topic that contained a word 
that was not available for the faker to use. 
Conversely, any set containing every first word at least once and every second word at least once 
could be a possible set of un-faked topics — simply put all the topics from the un- faked set at the top of the list. 
So, the question we need to answer is this: 
"What is the smallest set of topics that contains every first word at least once and every second word at least once?"

A brute-force approach, which works for the Small dataset, is to enumerate all subsets of topics 
and pick the subset with the fewest topics that covers every first word at least once and every second word at least once.
Since there are 2^N subsets, this solution runs in exponential time, which is fine for the Small dataset (2^16 = 65,536).

map<string, int> my1;
map<string, int> my2;
map<string, int> tp1;
map<string, int> tp2;
vector<pair<string, string>> varr;
int main() {
	FILE *fp;
	freopen_s(&fp, "C-small-practice (1).in", "r", stdin);
	freopen_s(&fp, "output.txt", "w", stdout);
	int T; cin >> T;
	rep(cc, T) {
		my1.clear();
		my2.clear();
		int n; cin >> n;
		varr.resize(n);
		rep(i, n) {
			string str1, str2;
			cin >> str1 >> str2;
			my1[str1]++;
			my2[str2]++;
			varr[i] = mp(str1, str2);
		}
		//int minUnfake = max(my1.size(), my2.size());	//안됩니다... 젠장..
		int minUnfake = 987654321;
		//왜 이런식의 검증 방법을 생각 못했을까... 반성하자...
		//small은 의외로 쉬웠네요...ㅠㅠ
		for (int subset = 0; subset < (1 << n); ++subset) {	//n은 최대 16
			int cnt = __popcnt(subset);	//이만큼을 unfake라 가정하자
			if (cnt < max(my1.size(), my2.size())) continue;
			tp1.clear(); tp2.clear();
			rep(iter, n) {
				if (subset & (1 << iter)) {
					tp1[varr[iter].first]++;
					tp2[varr[iter].second]++;
				}
			}
			// 원본을 나타낼수 있는 최소의 unfake 를 찾는다.
			if (my1.size() == tp1.size() && my2.size() == tp2.size())
				minUnfake = min(minUnfake, cnt);
		}
		cout << "Case #" << cc + 1 << ": " << n - minUnfake << endl;
	}
	return 0;	//릴리즈 모드 2초, 디버그모드 2분... map쓸때 조심하자..
}

large 를 푸는 방법
minimum edge cover 문제: "각 정점들을 포함하는 가장 작은 엣지집합"을 찾는 문제이다.
The problem we are trying to solve on this graph is the minimum edge cover; 
that is, finding the smallest set of edges such that each vertex is connected to 
at least one edge. This corresponds to the smallest set of topics containing every 
first word at least once and every second word at least once.

최소 엣지 덥개(minimum edge cover) 문제는 최대 매칭과 관련있다.

minUnfake 의 최소값은 최대독립집합의 크기로 구할 수 있다  
"최대 독립집합의 크기는 최대독립집합을 안 구해도 알수 있다.!!!! 
"=> 최대 매칭 크기(엣지 수) + 매칭 안된정점들 갯수 로 구할수 있음요
minUnfake = 최대매칭 간선 갯수 + match가 안된 노드들의 합
//통과했어유.. 디버그 모드인데도 라지 인풋 2초만에 통과요!!!! (구글문제는 2~5초 통과가 기본인듯 합니다.)
bool adj[2001][2001];
int n, m;
vector<int> aMatch, bMatch;
vb vstd;
bool dfs(int a) {
	if (vstd[a]) return false;
	vstd[a] = true;
	rep(b, m)
		if (adj[a][b])
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
	return false;
}
int bpttMatch() {	//복잡도 O(n^2) 얼마 안된다.
	aMatch = vi(n, -1);	bMatch = vi(m, -1);
	int size = 0;
	rep(start, n) {
		vstd = vb(n, false);
		if (dfs(start))	++size;
	}
	return size;
}
int solve() {
	int C = bpttMatch();
	int addA = 0, addB = 0;
	rep(i, n) if (aMatch[i] == -1) addA++;
	rep(i, m) if (bMatch[i] == -1) addB++;
	return C + addA + addB;
}
int main() {
	FILE *fp;
	freopen_s(&fp, "C-large-practice (1).in", "r", stdin);
	freopen_s(&fp, "output1.txt", "w", stdout);
	int T; cin >> T;
	rep(cc, T) {
		memset(adj, 0, sizeof(adj));
		map<string, int> my1, my2;
		int nStr; cin >> nStr;
		int cntL = 0, cntR = 0;
		rep(i, nStr) {
			//string 마다 번호 매기기
			string str1, str2; cin >> str1 >> str2;
			int numL, numR;
			if (my1.count(str1))
				numL = my1[str1];
			else
				numL = my1[str1] = cntL++;
			if (my2.count(str2))
				numR = my2[str2];
			else
				numR = my2[str2] = cntR++;
			adj[numL][numR] = true;
		}
		n = cntL; m = cntR;
		int unFake = solve();
		cout << "Case #" << cc + 1 << ": " << nStr - unFake << endl;
	}
	return 0;
}


https://code.google.com/codejam/contest/11254486/dashboard#s=p0&a=0 구글
//입력된 문자열을 가지고 원본 숫자를 만든다. (단조증가여야 함)
//large 2000길이의 문자열임
"왜 나는 제거 하는 순서가 있음을 발견하지 못했을까...ㅠㅠ"
"게다가 small 통과 소스를 가지고 최악 케이스를 돌렸는데 타임오버 뜬걸 알면서도 왜 무모하게 
"large 돌렸을까...?
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER

Case #1: 012
Case #2: 2468
Case #3: 114
Case #4: 3

//large 통과함요...
int my[26];
char orderOnly[10] = { 'Z', 'X', 'W', 'G', 'T', 'R', 'O', 'F', 'S', 'N' };
int my2[10] = { 0, 6, 2, 8, 3, 4, 1, 5, 7, 9 };
string order[10] = { "ZERO", "SIX", "TWO", "EIGHT", "THREE", "FOUR", "ONE", "FIVE", "SEVEN", "NINE" };
int main() {
	FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	freopen_s(&fp, "A-large-practice (1).in", "r", stdin);
	freopen_s(&fp, "output1.txt", "w", stdout);
	int T; cin >> T;
	rep(cc, T) {
		vi sol;
		memset(my, 0, sizeof(my));
		string str; cin >> str;
		rep(i, str.size()) {
			my[str[i] - 'A']++;
		}
		rep(i, 10) {
			while (my[orderOnly[i] - 'A'] > 0) {
				rep(j, order[i].size()) {
					my[order[i][j] - 'A']--;
					if (my[order[i][j] - 'A'] < 0) { 
						cout << "OMG" << endl;
					}
				}
				sol.push_back(my2[i]);
			}
		}
		sort(sol.begin(), sol.end());
		cout << "Case #" << cc + 1 << ": ";
		rep(i, sol.size()) cout << sol[i];
		cout << endl;
	}
	return 0;
}




https://code.google.com/codejam/contest/4224486/dashboard#s=p1
//이분서치로 문제를 풀수 있다.
int arr[100003];
int n, me;
//현 시간으로 주인공 처리가 충분한지 여부를 리턴
bool decision(long long time) {
	long long sum = 0;
	rep(i, n) {
		sum += time / arr[i] + 1;
	}
	return sum >= me;
}
//주인공이 시작하는 시간을 구한다.
long long optimize() {
	//LL을 안붙이면 좆됩니다!!!! hi 가 276447232로 세팅되는 불상사가 발생했네요...ㅠㅠ
	//이런경우 라지는 한번밖에 못 돌리니 돌이킬수 없게 됩니다.. 조심 또 조심 합니다.!!!!!
	long long lo = -1, hi = 1000000000LL * 100000;	//주인공 최대 순서 * 한 이발사의 최대 걸리는 시간
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
long long solve() {
	long long t = optimize();
	//호호 약간의 머리쓰기가 필요했네요.
	//각 사람들은 아이들상태인 이발사들중 번호 짧은 이발사한테서 처리되니 말이죠.
	//3 12	//이발사3명, 나 : 12번
	//7 7 7
	//output : 3번 이발사 되어야 함
	int cnt = 0;
	//rep(i, n) cnt += t / arr[i] + (t % arr[i] == 0) ? 0 : 1; //이경운 오류남.. 연산자 우선순위가 어찌 되나 보세!!!!
	rep(i, n) cnt += t / arr[i] + ((t % arr[i] == 0) ? 0 : 1);
	rep(i, n) {
		if (t % arr[i] == 0) cnt++;	
		if (cnt == me) return i;
	}
	return -1;
}
int main() {
	FILE *fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	freopen_s(&fp, "B-large-practice (1).in", "r", stdin);
	freopen_s(&fp, "output1.txt", "w", stdout);
	int T; cin >> T;
	rep(cc, T) {
		cin >> n >> me;
		rep(i,n) cin >> arr[i];
		long long sol = solve();
		cout << "Case #" << cc + 1 << ": " << sol + 1<< endl;
	}
	return 0;
}

//내가 풀었다는 사실이 자랑스러워 다시 타이핑 적어봅니다.
int arr[100003];
int n, me;
bool decision(long long time) {
	long long sum = 0;
	rep(i,n) sum += time / arr[i] + 1;
	return sum >= me;
}
long long optimize() {
	long long lo = -1, hi = 1000000000LL * 100000;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
long long solve() {
	long long t = optimize();
	int cnt = 0;
	rep(i,n) cnt += t / arr[i] + ((t % arr[i] == 0) ? 0 : 1);
	rep(i,n) {
		if (t % arr[i] == 0) cnt++;
		if (cnt == me) return i;
	}
	return -1;
}
int main() {
	int T; cin >> T;
	rep(cc,T) {
		cin >> n >> me;
		rep(i,n) cin >> arr[i];
		long long sol = solve();
		cout << "Case #" << cc + 1 << ": " << sol + 1 << endl;
	}
	return 0;
}


https://algospot.com/judge/problem/read/BOGGLE
int dy[] = { -1, -1, -1,  0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int main() {
	//FILE* fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		int dp[5][5][11];
		vs board(5);
		rep(i, 5) cin >> board[i];
		int qr; cin >> qr;
		rep(qc, qr) {
			memset(dp, 0, sizeof(dp));
			rep(i, 5) rep(j, 5) dp[i][j][0] = 1;
			string str; cin >> str;
			rep2(j, 1,str.size() + 1) {
				rep(iter, 25) {
					int y = iter / 5, x = iter % 5;
					rep(dir, 8) {
						int ny = y + dy[dir], nx = x + dx[dir];
						if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || board[ny][nx] != str[j - 1]) continue;
						dp[ny][nx][j] += dp[y][x][j - 1];
					}
				}
			}
			cout << str << " ";
			bool ok = false;
			rep(i, 5) rep(j, 5) if (dp[i][j][str.size()] > 0) ok = true;
			if (ok) 
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;
//디버깅을 눈으로 하지 말고 아래와 같이 출력해라!!!!
//			rep(index, str.size() + 1) {
	//			rep(i, 5) rep(j, 5) cout << dp[i][j][index] << " \n"[(j != 5 - 1) ? 0 : 1];
		//		cout << endl;
			//}
		}
	}
	return 0;
}
"깨달음!!!!"
"삼중배열 이상의 경우 눈으로 디버깅은 절대 네버 하지 마라 미친짓이다."
윗문제의 확장 보드 사이즈 500 * 500 에 검사 스트링이 100
각 지점에서 bfs돌리는것 중복계산이 많아서 힘들거야 .. (각지점 bfs : 500 * 500 * 100) * (각지점 갯수 :500)
dp로 돌릴려고 해도 메모리 오바 날수 있다.
내가 제출한 방식에서 슬라이딩 윈도우를 적용하면 돌릴수 있다.
//내코드의 단점은 recursion버전보단 아무래도 시간이 걸린다. (필요없는 부분도 다 계산하기 때문이다)
//실 제출 속도는 18ms이며 김동현의 재귀 코드는 9ms였다.
w




//컨벡스 폴리곤을 만들기
https://code.google.com/codejam/contest/4224486/dashboard#s=p2
Limits
-10^6 ≤ Xi, Yi ≤ 10^6.
Small dataset
1 ≤ T ≤ 100.
1 ≤ N ≤ 15.
Large dataset
1 ≤ T ≤ 14.
1 ≤ N ≤ 3000.

https://code.google.com/codejam/contest/4224486/dashboard#s=a&a=2 //해설 그림 있음
If there is only one tree in the forest, then obviously there is no need to cut anything down, and the answer for that tree is zero.

Otherwise, let's assume we have cut down some trees so that a given point P is on the boundary. 
If we follow the boundary clockwise from P, we will reach another boundary point Q. 
Imagine we are standing at P and looking along the boundary line towards Q. 
There can be no trees still standing to the left of this line, otherwise this would not be the boundary.

This suggests an algorithm for determining the minimum number of trees to cut down — for each point P, 
try each other point as a candidate for the next point around the boundary, Q; 
then check how many points lie on the left of the line PQ. 
"The size of the smallest of those sets of points is the best answer:"

Cutting down all the trees to the left of PQ for some Q is sufficient 
to produce a valid solution, because no matter where the remaining trees are, 
P will be on the boundary. We can also be sure that this method will find the minimal solution, since whatever the minimal solution is, it will have some point Q which is the next along the boundary, and we have cut down the minimal number of trees to make that so.

//구현에 있어 4가지 주의상황
//1. 시작지점으로 헤더가 도착할 시 종료
The head of the window will reach the end of S before the tail does. 
The head pointer then needs to wrap around to the start of S again,
to include all the points to the left of PQ. 
For example, when Q = #6, the head of the window is #11. 
Then when Q advances to #7, the head of the window needs to wrap around to #2,
which is at the start of the list, because point #2 is to the left of the line PQ.


//2. 헤더 테일 동일//즉 바운드리에 있는 경우
There may be no points to the left of PQ at all; 
for example, if P=#4, and Q=#2. A simple way to deal with this case is 
to have the head of the window equal to the tail. The calculation of the number 
of trees to cut down should naturally give zero. 
Then, when we advance the tail of the window by one point, 
also advance the head if it was at the same point.	//이건 왜 필요한지 모르겠다.

//3. 같은 각도를 가진 두점 //알아서 잘 동작함. 굳이 추가 코드가 필요 없음
There may be more than one point at the same angle from P. This case is handled automatically. 
The points that are at the same angle will occur consecutively in S. 
When we choose the last such point as Q, we will correctly calculate 
the number of trees that need to be cut down. 
For the other points at the same angle, we will mistakenly think that 
extra trees need to be cut down, but we will still find the minimum, 
so we needn't write extra code to handle this case.

//4. epsilon//1.25 * 10^-13이 나오는 케이스는 어찌 구할꼬...
//종만이 책은 10^-10을 쓰던데..
//내가 찾은 최소차는 10^-7 정도고 ...
	double at1 = atan2((double)2000000, (double)2000000);
	double at2 = atan2((double)2000000, (double)2000001);
	double diff = at1 - at2;
	printf("%.14lf\n", diff); //0.00000024999994

When updating the position of the head of the window, we need to stop 
when the next point will be at an angle π or more greater than the angle of Q.
Floating point numbers are imprecise, so we need to use an epsilon 
when doing comparisons in these calculations. 
The largest difference in angle between two points is approximately 
1.25 * 10^-13 radians. 64-bit floating point values have easily enough precision 
to represent angles with this difference, so using these with an epsilon of 10^-13 will work.


/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.18
 */
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
long double eps = 1e-15;

void solve() {
  int n;
  cin >> n;
  int x[n], y[n];
  forn(i, n)
    cin >> x[i] >> y[i];
  long double a[2 * n];
  forn(i, n) {
    int an = 0, ans = n - 1;
    forn(j, n)
      if (j != i)
        a[an++] = atan2l(y[j] - y[i], x[j] - x[i]);
    sort(a, a + an);
    forn(i, an)
      a[i + an] = a[i] + 2 * M_PI;
/*
    forn(i, 2 * an)	//이걸로 eps의 사이즈를 어느정도로 할지 유추할수 있구나!!!!
      printf("%.3f ", (double)a[i]);	//한 입력은 고정이니 말이야.
    puts("");
*/
	//그냥 두바퀴를 돌려버리네.. 소스를 깔끔하게 만들어 버리넹..
	//문자열에서도 두바퀴 돌리는게 있었지
	//한바퀴 돌려도 돌아가지 않을까?
    int l = 0, r = 0;	//l: tail, r: head
    forn(i, an) {
      while (l + 1 < 2 * an && a[l] - a[i] < eps)	//tail
		//a[l], a[i]가 같은 각도 일때 0 < eps 임
        l++;
      while (r < 2 * an && a[r] - a[i] < M_PI - eps)	//head
        //a[r] - a[i]가 거의 파이에 근접해서
		//파이(180도) - eps보다 크다면 일직선으로 인정
		r++;
      ans = min(ans, r - l);
    }
    printf("%d\n", ans);
  }
}
int main() {
  int tn;
  scanf("%d", &tn);
  forn(t, tn) {
    printf("Case #%d:\n", t + 1);
    fprintf(stderr, "Case #%d:\n", t + 1);
    solve();
  }
  return 0;
}


//내식대로 약간 변경
//참고로 atan2(0, -1)은 양수다 PI임
//#define PI 3.14159265359	//끝에 세미클론 붙이지 마라!!!!
#define PI 3.14159265358979323846
//const double eps = 1e-15;	//원작자 소스 통과
//const double eps = 1e-20;	//small, large 통과못함!!!! //eps는 너무 작아도 문제라는 사실!!!!
const double eps = 1e-8;	//이래도 small, large 통과했어요.
void solve() {
	int n; cin >> n;
	vi x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vd arr(2 * n);
	rep(i, n) {
		int cnt = 0, sol = n - 1;
		rep(j, n)
			if (j != i)
				arr[cnt++] = atan2(y[j] - y[i], x[j] - x[i]);
		sort(arr.begin(), arr.begin() + cnt);	//!!!!부분 정렬용
		rep(i, cnt)
			arr[i + cnt] = arr[i] + 2 * PI;
		int l = 0, r = 0;
		rep(i, cnt) {
			//while (l + 1 < 2 * cnt && arr[l] - arr[i] < eps)
			//tail	//솔직히 tail은 이게 가독성도 좋음: 꼬리위치는 한번만 타도 되므로.(small, Large통과함)
			while (l < cnt && arr[l] - arr[i] < eps)	//arr[i] : tail이 된다.
				l++;
			//head는 꼬리로 부터 180미만 확장될수있으니 여유있게 2배로 잡자
			while (r < 2 * cnt && arr[r] - arr[i] < PI - eps)
				r++;
			sol = min(sol, r - l);
			//구글 설명상 엄밀히 l 과 r은 이렇다.
			//l = tail + 1, r = head + 1임
		}
		//디버그 모드에선 시간 체크 불가능..
		//cout << sol << endl;	//어째 릴리즈에선 별 차이가 없는거 같다. 릴리즈 모드 둘다 약 8초임
		printf("%d\n", sol);
	}
}
int main() {
	FILE* fp;
	freopen_s(&fp, "C-small-practice (3).in", "r", stdin);
	freopen_s(&fp, "outputS.txt", "w", stdout);
	int cs; cin >> cs;
	rep(cc, cs) {
		cout << "Case #" << cc + 1 << ":\n";
		solve();
	}
	return 0;
}







https://algospot.com/judge/problem/read/CLOCKSYNC
//책의 풀이랑 완전 달라요...
//내 풀이는 구글 숫자 문제랑 비슷하넹..
"차이점은 1대 1 매핑이 아닌거 처리하는 알고리즘이 핵심임!!!!"
//순서를 찾고 그것들의 기저가 존재하는지 확인후 존재할 경우 뺀다.
//좀더 깔끔하게 짜도록 해보자...
int main() {
	//FILE* fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	//freopen_s(&fp, "outputS.txt", "w", stdout);
	vi arr[10];
	int num[16];
	memset(num, 0, sizeof(num));
	arr[0] = { 0,1,2 };
	arr[1] = { 3, 7, 9, 11 };
	arr[2] = { 4, 10, 14, 15 };
	arr[3] = { 0, 4, 5, 6, 7 };
	arr[4] = { 6, 7, 8, 10, 12 };
	arr[5] = { 0, 2, 14, 15 };
	arr[6] = { 3, 14, 15 };
	arr[7] = { 4, 5, 7, 14, 15 };
	arr[8] = { 1, 2, 3, 4, 5 };
	arr[9] = { 3, 4, 5, 9, 13 };
	rep(i, 10) rep(j, arr[i].size()) num[arr[i][j]]++;
	vi cir;
	vvi circir(10);
	rep(i, 10) {
		int dscv = -1;
		rep(j, 16) {
			if (num[j] == 1) {
				dscv = j;	//한개만 남음. 기저로 취할수 있다.
				break;
			}
		}
		if (dscv == -1) cout << "OMG" << endl;
		int sel = -1;
		rep(j, 10) {
			rep(iter, arr[j].size()) {
				if (find(cir.begin(), cir.end(), j) != cir.end()) continue;
				if (arr[j][iter] == dscv) {
					sel = j;	//기저가 발견된 버튼을 찾는다.
					break;
				}
			}
			if (sel != -1) break;
		}
		cir.push_back(sel);	//사이즈가 10이 아니면 오류남
		rep(j, arr[sel].size()) {
			num[arr[sel][j]]--;	//기저버튼으로 각 시계를 컨트롤한다.
			if (num[arr[sel][j]] == 0)
				circir[sel].push_back(arr[sel][j]);	//베이시스 저장
		}
	}
	
	int cs; cin >> cs;
	rep(cc, cs) {
		int clockA[16];
		rep(i, 16) cin >> clockA[i];
		rep(i, 16) clockA[i] %= 12;
		int sol = 0;
		bool basisOk = true;
		rep(i, cir.size()) {
			bool isAdapt = false;	//적용하는가?
			int sel = cir[i];
			int base = circir[sel][0];
			int baseClock = clockA[base];
			rep2(j, 1, circir[sel].size()) {
				base = circir[sel][j];
				//선택된 버튼의 베이시스가 2개 이상이면 가르키는 시계방향은 모두 같아야 됨!!!!
				if (baseClock != clockA[base]) {	
					basisOk = false;	//베이시스를 모두 만족 못시킴
					break;
				}
			}
			if (basisOk == false) {
				sol = -1;
				break;
			}
			if (baseClock != 0) {
				int rot = 12 - baseClock;	//적용한다면 몇바퀴 회전 시킬꼬?
				isAdapt = true;
				rep(j, arr[sel].size()) {
					int id = arr[sel][j];
					clockA[id] += rot;
					clockA[id] %= 12;
				}
				sol += rot / 3;	//회전버튼을 몇번 누를꼬
			}
		}
		cout << sol << endl;
	}
	return 0;
}

https://code.google.com/codejam/contest/8224486/dashboard#s=p1&a=2
//Problem B. Noisy Neighbors
//small은 간단히 통과했는데 large는 꾸질꾸질하다.
//특성을 찾아내야하는데 많은 예외가 있는거 같다.
//풀이봐도 길어서 GG친다요.
int board[16][16];
int row, col, n;
int getNoisy(int taken) {
	rep(i, row) {
		rep(j, col) {
			if (taken & (1 << (i * col + j)))
				board[i][j] = 1;
		}
	}
	int ret = 0;
	rep(i, row) {
		rep(j, col) {
			if (board[i][j] == 1) {
				if (i - 1 >= 0 && board[i - 1][j] == 1)
					ret++;
				if (j - 1 >= 0 && board[i][j - 1] == 1)
					ret++;
			}
		}
	}
	return ret;
}
int main() {
	FILE* fp;
	freopen_s(&fp, "B-small-practice (1).in", "r", stdin);
	freopen_s(&fp, "outputS.txt", "w", stdout);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> row >> col >> n;
		int sol = INF;
		int all = row * col;
		for (int i = 0; i < (1 << all); ++i) {
			memset(board, 0, sizeof(board));
			int cnt = __popcnt(i);
			if (cnt != n) continue;
			int cand = getNoisy(i);
			if (sol > cand)
				sol = cand;
		}
		cout <<"Case #" << cc + 1 <<": " << sol << endl;
	}
	return 0;
}



https://code.google.com/codejam/contest/8224486/dashboard#s=p2&a=2
Problem C. Hiking Deer




ROUND 1C PROBLEM B
https://code.google.com/codejam/contest/4314486/dashboard#s=p1
//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll n, m;
int a[100][100];

int main()
{
	int i, j, k;
	int T, TT;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>TT;
	for(T=1;T<=TT;T++)
	{
		printf("Case #%d: ", T);
		cin>>n>>m;
		if(m > (1ll<<(n-2)))	//숫자 뒤에 ll이 붙었다고 long long이 바로 대입되는건 아님
		{						//숫자 뒤에 바로 오는 ll은 long long 리터럴을 의미함
								//실제로 long long test = 10000000000000long long; 하면 컴파일 안됨요.
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=0;
		for(i=0;i<n-1;i++) for(j=0;j<i;j++) a[j][i]=1;
		if(m == (1ll<<(n-2)))
		{
			//열벡터를 쫙 채운다
			for(i=0;i<n-1;i++) a[i][n-1]=1;
		}
		else
		{
			//그렇지 않을 경우 a[0][끝놈] = 0으로 내벼두고 다른것들만 세팅한다.
			for(i=0;i<n-2;i++)
			{
				if((1ll<<i)&m)
				{
					a[i+1][n-1]=1;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) printf("%d", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
//*/
10	256
Case #1: POSSIBLE
0111111111		1: special
0011111111		2^0
0001111111		2^1
0000111111		2^2
0000011111		2^3
0000001111		2^4
0000000111		2^5
0000000011		2^6
0000000001		2^7
0000000000

10	255
Case #2: POSSIBLE
0111111110
0011111111
0001111111
0000111111
0000011111
0000001111
0000000111
0000000011
0000000001
0000000000
Case #3: POSSIBLE
0111111110
0011111110
0001111111
0000111111
0000011111
0000001111
0000000111
0000000011
0000000001
0000000000

//내방식 정리
1----6		1: special

1---56		2^0

1--4-6		2^1
1--456

1-3--6		2^2
1-3-56
1-34-6
1-3456

12---6		2^3
12--56
12-4-6
12-456
123--6
123-56
1234-6
123456

//통과함
"더블링 접근이 필요했음
"내가 못푼 이유: 첫째 영어, 둘째 안풀어본 유형에 대해 어려워함, 대회 압박감...
"1번부터 차례대로 풀자.ㅠㅠ
typedef long long ll;//9,223,372,036,854,775,807
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;


int board[100][100];
int main()
{
	freopen("B-small-practice (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int cs; cin >> cs;
	rep(cc, cs) {
		printf("Case #%d: ", cc + 1);
		ll n, m;
		cin >> n >> m;
		//cout << n << " " << m << endl;
		//최대한 나타낼수 있는 갯수 2^(n - 2) //ex: n 이 6이면 16개가 최대다
		if (m > (1ll << (n - 2)))	//숫자 뒤에 ll이 붙었다고 long long이 바로 대입되는건 아님
		{						//숫자 뒤에 바로 오는 ll은 long long 리터럴을 의미함
								//실제로 long long test = 10000000000000long long; 하면 컴파일 안됨요.
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		memset(board, 0, sizeof(board));
		rep2(i, 1, n - 1) rep2(j, i + 1, n) board[i][j] = 1;
		if (m == (1ll << (n - 2)))
			rep2(i, 1, n) 
				board[0][i] = 1; //행벡터를 채운다 //boar[0][0]은 0유지
		else
		{
			//그렇지 않을 경우 a[0][n-1(끝놈)] = 0으로 내벼두고 다른것들만 세팅한다.
			//board[0][(n - 1) - 1] => 2^0
			//board[0][(n - 1) - 2] => 2^1
			//board[0][(n - 1) - 3] => 2^2
			rep(i, n - 2) {
				if ((1ll << i) & m)
					board[0][(n - 1) - 1 - i] = 1;
			}
		}
		rep(i, n) rep(j, n) {
			printf("%d", board[i][j]);
			if (j == n - 1) printf("\n");
		}
	}
	return 0;
}


ROUND 1C PROBLEM C Fashion Police
https://code.google.com/codejam/contest/4314486/dashboard#s=p2
//이 소스는 통과 못함... 원인을 찾아야 함..
int fs[11][11];
int ft[11][11];
int st[11][11];
int main() {
	//freopen("C-small-practice.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(fs, 0, sizeof(fs));
		memset(ft, 0, sizeof(ft));
		memset(st, 0, sizeof(st));
		int J, P, S; cin >> J >> P >> S;
		int K; cin >> K;
		vector<vector<int>> sol;
		rep2(i, 1, J + 1) rep2(j, 1, P + 1) rep2(k, 1, S + 1) {
			if (fs[i][j] == K || ft[i][k] == K || st[j][k] == K) continue;
			vector<int> ar(3);
			ar[0] = i; ar[1] = j; ar[2] = k;
			sol.push_back(ar);
			fs[i][j]++; ft[i][k]++; st[j][k]++;
		}
		cout << "Case #" << cc + 1 << ": " << sol.size() << endl;
		rep(i, sol.size()) rep(j, 3) 
			printf("%d%c", sol[i][j], " \n"[(j != 3 - 1) ? 0 : 1]);
	}
	return 0;
}
차례대로 숫자 증가 시키고 K개 인지 아닌지 체크하면 되는줄 알았는데 그게 아님

순서를 구해내야 함..
small인 경우 brute force 로 풀면 됨
S <= 3 이므로
최대 3^3 인 27개 의 ar이 나옴
그중 몇개를 선택하냐에 그 선택된 것들이 <= k를 만족하는가는 조사하면 된다.

Let us denote the number of possible outfits by W; W = J * P * S.
A viable brute force approach is to produce all 2^W subsets of the set of possible outfits,
check them for violations, and take one of the largest sets with no violation.
"We cand check a set of outfits without worrying about what order they are worn in;"
"그것들이 어떤 순서로 박히건 간에 신경쓸 필요는 없다"
if some outfits in that set create a fashion violation, it will eventually happen 
no matter what order those outfits (and any other outfits) are worn in.
Another helpful observation is that if S <= K, then answer is trivial:
simply return every possible outfit; //전체 출력하면 됨

This approach works for most of the Small cases; but not all of them.
For the cases 3 3 3 1 and 3 3 3 2, there are 2^27 possible sets of outfits, and that is over 100 million.
One approach is to just solve these "problem cases" before downloading a dataset.
//쨉실한 방법이군
You can notice a pattern in ther other answers (more on this later) and infer that 
"the maximum numbers of outfits you can wear are 9 and 18, rewpectively."	
//많이 커봤자9랑 18로 추론된다. (3 3 3 1) (3 3 3 2) 각각은 말이다.
It is more tractable to find a set of outfits of a particular size than to find
the set of outfits of maximum size.
if you are pretty sure that that size is 18, for instance, you can check all sets of size 18
until you find a working one, and maybe enven check all sets of size 19 to confirm that none of them work.
Whis is much faster than checking every size between 1 and 19, especially since 27 choose 18 is
much smaller than 17 choose 13 and 27 choose 14, for example.

"미리 만들어놓고 해라는 방식인데 미리 만드는 복잡도는 대략 5000만 * 27 정도 됨.."


One pitfall to watch out for in this problem is that there exist sets of outfits that are maximal 
— that is, you cannot add any new outfit to such a set without going to jail — 
but are not the largest possible. That is, they are maximal but not maximum.

For instance, for an input of J = 1, P = 3, S = 3, K = 2, the following is a maximal set of outfits 
that is not maximum (the maximum size is 6): 1 1 1, 1 1 2, 1 2 2, 1 2 1, 1 3 3. //이 극대 집합의 사이즈는 5
//내가 틀린 이유는 극대 == maximum이라고 생각했기 때문이다.
1 1 1
1 1 2
1 1 3 x
1 2 1
1 2 2 
1 2 3 x
1 3 1 x
1 3 2 x
1 3 3

//이렇게 하면 6가지가 됨.
1 1 1
1 1 2
1 1 3 x
1 2 1 x
1 2 2 
1 2 3 
1 3 1 
1 3 2 x
1 3 3


//artberryx 코드염..
int x, y, z, K;
int main()
{
	int i, j, k;
	int T, TT;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>TT;
	for(T=1;T<=TT;T++)
	{
		printf("Case #%d: ", T);
		cin>>x>>y>>z>>K;
		K=min(K, z);
		vector<pii> v[20];
		for(i=1;i<=x;i++)
		{
			int now=i;
			for(j=0;j<y*K;j++)
			{
				v[i].emplace_back(j/K+1, now);
				now++;
				if(now == z+1) now=1;
			}
		}
		cout<<x*y*K<<endl;
		for(i=1;i<=x;i++)
		{
			for(auto e : v[i]) printf("%d %d %d\n", i, e.first, e.second);
		}
	}
	return 0;
}


https://www.acmicpc.net/problem/1300
k번째 수
//이분 탐색 !!!! 이분탐색이라는 걸 아니까 푸는데 10분도 안 걸림. 편리하당 이분탐색
long long n, k;
bool decision(long long base) {
	long long cnt = 0;
	rep2(i, 1, n + 1) {
		long long last = min<long long>(n * i, base);
		cnt += last / i;
	}
	return cnt >= k;
}
long long optimize() {
	long long lo = -1, hi = 100000LL * 100000;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
int main() {
	cin >> n >> k;
	long long sol = optimize();
	cout << sol;
	return 0;
}



"emplace_back()를 알아보자"
std::list::emplace_back()
class나 어떠한 형식을 list의 instance로 정하여 element를 push_back 할 때 보통은 아래와 
같이 push_back을 이용해서 list에 값을 넣는다.

    std::list<MyClass> list;
    list.push_back(MyClass(1,2,3));


나도 이렇게 현재까지 사용하다가 공부를 조금만 하고 관심을 조금만 기울이면 알 수 있었던 
emplace_back() 함수에 대해 알게되어 기록해둔다.

먼저 class형식을 list의 객체로 쓸 때
push_back()을 쓰는 것이 emplace_back()을 쓸 때와 무슨 차이가 있나? 왜 쓰나?
어차피 값을 넣는 것은 똑같지 않나? 생각 할 수 있다.

push_back()을 써도 무방하다.
하지만 아래 cppreference에 나와있는 것을 읽어보면 push_back()에서 있는
move와 copy를 피할 수 있기 때문에 좋다고는 말하지 않지만 쓸데 없는 동작이 없으면
좋은 것이지 않나?

이제 어떻게 move와 copy가 없이 사용하냐 이것이 문제인데,
그 것은 아래의 cppreference에서 따온 예제를 보면 금방 이해 할 수 있다.

CODE
//흠냐 문법 공부가 필요한데... "&&" , "move(p_name)", "= default"
#include <list>
#include <string>
#include <iostream>
struct President
{
    std::string name;
    std::string country;
    int year;
    President(std::string && p_name, std::string && p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "I am being constructed.\n";
    }
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being moved.\n";
    }
    President& operator=(const President& other) = default;
};
int main()
{
    std::list<President> elections;
    std::cout << "emplace_back:\n";
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);
    std::list<President> reElections;
    std::cout << "\npush_back:\n";
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));
    std::cout << "\nContents:\n";
    for (President const& president: elections) {
        std::cout << president.name << " was elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
    for (President const& president: reElections) {
        std::cout << president.name << " was re-elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
}
output
emplace_back:
I am being constructed.
push_back:
I am being constructed.
I am being moved.
Contents:
Nelson Mandela was elected president of South Africa in 1994.
Franklin Delano Roosevelt was re-elected president of the USA in 1936.


https://www.acmicpc.net/problem/7469	//k번째 숫자
배열: 10만개, 수의 범위: 1000000000, 질의 (i, j, k) 5000번 
//(i ~ j)구간을 정렬시 k번째 값을 구한다.
http://morris821028.github.io/2014/08/30/oj/zj/a331/	중국 코드 대단해
//O(nlgn)
struct Node { int l, r, lson, rson, sum; } node[2097152];
int nodeSize = 0; int A[131072], B[131072], root[131072];
int build(int l, int r) {
	if (l > r) return 0;
	int k = nodeSize++;
	node[k].l = l, node[k].r = r, node[k].sum = 0, node[k].lson = node[k].rson = 0;
	if (l == r) return k;
	int m = (l + r) / 2;
	node[k].lson = build(l, m);	node[k].rson = build(m + 1, r);
	return k;	//lson, rson : 자식 노드 번호임
}
int change(int p, int x, int val) {
	int k = nodeSize++;
	node[k] = node[p];	node[k].sum += val;
	if (node[k].l == node[k].r) return k;
	int m = (node[k].l + node[k].r) / 2;
	if (x <= m)	node[k].lson = change(node[p].lson, x, val);
	else		node[k].rson = change(node[p].rson, x, val);
	return k;
}
int query(int tp, int tq, int k) {
	if (node[tp].l == node[tp].r) return node[tp].l;
	int t = node[node[tp].lson].sum - node[node[tq].lson].sum;
	if (k <= t)	return	query(node[tp].lson, node[tq].lson, k);
	else return			query(node[tp].rson, node[tq].rson, k - t);
}
int main() {
	int n, m, x, y, k;
	while (scanf("%d %d", &n, &m) == 2) {
		map<int, int> R;
		rep2(i, 1,n + 1) scanf("%d", &A[i]), R[A[i]] = 0;
		int size = 0;
		for (map<int, int>::iterator it = R.begin(); it != R.end(); ++it) {
			it->second = ++size;		//수의 정규화(-5, 4, 10) => (1, 2, 3)
			B[it->second] = it->first;	//실제 원본 숫자 찾기용
		}
		nodeSize = 1; root[0] = build(1, size);	//root[0]에는 노드 번호가 기록된다. 1번
		rep2(i, 1, n + 1) {
			A[i] = R[A[i]];	root[i] = change(root[i - 1], A[i], 1);
		}
		rep(i, m) {
			scanf("%d %d %d", &x, &y, &k);
			printf("%d\n", B[query(root[y], root[x - 1], k)]);
		}
	}
	return 0;
}

https://twitter.com/bluepygmi/status/733639775039553537
//트위터 풀이에 문제가 좀 있다.
//coupon collector problem
//쿠폰이 a, b, c 세개 있고 뽑고나서 넣는걸 반복시
//a, b, c 세개의 쿠폰을 모두 모으게 되는 시행횟수 기대값
Sum[n((2^(n - 1) - 2) / 3^(n - 1)), {n, 3, Infinity}]
https://www.wolframalpha.com/input/?i=Sum%5Bn+((2%5E(n+-+1)+-+2)%2F3%5E(n+-+1)),+%7Bn,+3,+Infinity%7D%5D

3번 시행시 모두가 뽑힐 확률 (2^(3 - 1) - 2) / 3^(3 - 1) = 2 / 9
a, b, c 가 하나씩 나옴: 3!
모든 시행횟수: 3^3
6 / 27 = 2 / 9  //음 맞군요..

4번 시행시 모두가 뽑힐 확률 (2^(4 - 1) - 2) / 3^(4 - 1) = 6 / 27	= 2 / 9
5번 시행시 모두가 뽑힐 확률 (2^(5 - 1) - 2) / 3^(5 - 1) = 14 / 81
6번 시행시 모두가 뽑힐 확률 (2^(6 - 1) - 2) / 3^(6 - 1) = 30 / 243	= 10 / 81
...일반화(n = 3 ~ oo)		(2^(n - 1) - 2) / 3^(n - 1)

시행 기대값 = sum{ 각 시행횟수 * 그 시행횟수의 확률 }
sum{ n * ((2^(n - 1) - 2) / 3^(n - 1)) } , 3 <= n <= Infinity
//김동이 준 풀이랑 아래 링크 읽어보삼
http://math.stackexchange.com/questions/647587/sum-of-a-power-series-n-xn

//랜덤활용하는것 김동 코드
#include <iostream>
#include <random>
#include <vector>
using namespace std;
int main() {
	int cs;	cin >> cs;
	long long totalCost = 0;

	for (int c = 0; c < cs; c++)
	{
		std::uniform_real_distribution<double> unif(0.0, 100.0);
		std::random_device rand_dev;
		std::mt19937 rand_engine(rand_dev());

		bool T[3] = { false, };
		int trial = 0;
		while (true)	{
			trial++;
			double x = unif(rand_engine);
			// int t = (int)(x / (16.0/ 3.0 / 3.0));
			int t = (int)(x / (5.5 / 3.0));
			if (t < 3)
				T[t] = true;

			if (T[0] && T[1] && T[2])
				break;
		}
		totalCost += trial;
	}
	cout << (double)totalCost / cs << endl;
	return 0;
}


//자동생산: 10000ms 시간제한 10ms에 통과해서 기쁨~~~
//구현 문제이고 딱히 눈여겨 볼건 없음, 한방에 통과해서 그냥 여기에 기념으로 놔둠.

https://algospot.com/judge/problem/read/AUTOPRODUCTION
// 자동 생산 기능을 한차례 작동시켜 만들어낼 수 있는 최대 생산물 갯수를 구하라
// 한번에 전체 재료들의 칸의 합은 최대 10칸까지만 선택할수 있다
2 // 케이스 수
1 // 생산을 위해 필요한 재료의 가짓수(종류) (1 <= N <= 10)
5 3	//생산을 위해 필요한 그 재료의 갯수 Ri, 가방에 있는 그 재료 칸의 수 Ci
20 18 13	// 가방의 각 칸에 들어 있는 재료의 갯수

2
3 6
1 3 3 4 4 4
3 6
2 3 4 7 8 10

vector<int> board[10];
int rArr[10];	//생산에 필요한 i재료의 갯수
int cArr[10];	//i재료를 집어넣은 칸수
int main() {
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;	//생산을 위해 필요한 재료의 종류 수 (1 <= N <= 10)
		rep(i, n) {
			cin >> rArr[i] >> cArr[i];	// 1개 생산을 위해 필요한 각 종류별 재료의 갯수 Ri, 가방에 있는 그 재료의 칸수 Ci
			board[i].resize(cArr[i]);
			rep(j, cArr[i])
				cin>>board[i][j];
			sort(board[i].begin(), board[i].end());
		}
		int sol = 0;
		bool bEmpty = false;
		int kan = 0;
		vector<int> cnt(n, 0);
		while (kan != 10 && bEmpty == false) {
			rep(i, n) {	// 한놈씩 채워본다, 빈칸이 있거나 선택된 칸이 10개가 되면 종료한다
				while (cnt[i] < rArr[i]) {
					if (board[i].empty()) {
						bEmpty = true;
						break;
					}
					cnt[i] += board[i].back();
					board[i].pop_back();
					kan++;	// 이 칸으로 채움
					if (kan >= 10) break;
				}
				if (kan >= 10 || bEmpty) break;
			}
			int add = INF;
			rep(i, n) {
				int cand = cnt[i] / rArr[i];
				add = min(add, cand);
			}
			sol += add;
			rep(i, n) {
				cnt[i] -= rArr[i] * add;
			}
		}
		cout << sol << endl;
	}
	return 0;
}
" 위는 그리디하게 풀었다.", "물론 만들어지는것의 갯수를 정해놓고 이게 성립되나로 이분법으로 풀수도 있다"




https://algospot.com/judge/problem/read/ESCAPEGEESE
//통과 못함... ㅠㅠ 
//int cache[501][101][501];
vector<vector<vector<int>>> cache;
int n, k;
//릴리즈에서도 30초 걸림 (input: 500 100 인 케이스 하나에 말이지..)
//지저분하다 다시 정리해서 제출해보자...
//need는 here번째는 반드시 포함한다.
int solve(int here, int need, int rmd) {
	if (need == 1) 
		return ((rmd + here) % n == 0) ? 1 : 0;
	int& ret = cache[here][need][rmd];
	if (ret != -1) return ret;
	ret = 0;
	//for (int next = here + 1; next < n; ++next) {
	for (int next = here + 1; n - next  > need - 2; ++next) {
		ret += solve(next, need - 1, (rmd + here) % n);
		ret %= MOD;
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		cache.clear();
		cache = vector<vector<vector<int>>>(501, vector<vector<int>>(101, vector<int>(501, -1)));
		cin >> n >> k;
		int sol = 0;
		rep(i, n - k + 1) {
			sol += solve(i, k, 0);
			sol %= MOD;
		}
		cout << sol << endl;
	}
	return 0;
}

//371ms 로 통과함
//배낭채우기에서 하나씨만 선택하는 문제응용버전임, 생각하면 간단히 구현 가능..
//int dp[501][101][501];	//거위 인덱스, 선택된 거위수, 숫자합 % n
//dp[5][2][3] //거위를 5마리 까지 스캐닝, 그중 2개를 선택시, 나머지가 3이 되는 경우
//주의점 dp[i][j][k]에서 i가 1인경우 0번 거위를 가르킴
int dp[2][101][501];
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		int N, M;
		cin >> N >> M;
		rep2(i, 1, N + 1) {
			rep(j, M + 1)
				rep(k, N) {
				int i1 = i & 1;
				int i0 = i1 ^ 1;
				dp[i1][j][k] = dp[i0][j][k];
				if (j != 0)
					//i = (i - 1) 번 오리를 가르킴 따라서 이전 오리는 (i - 2)번임
					dp[i1][j][k] += dp[i0][j - 1][(k - (i - 2) + N) % N];
				dp[i1][j][k] %= MOD;
			}
		}
		cout << dp[N & 1][M][0] << endl;
		int d;
		d = 3;
	}
	return 0;
}



//백준: 판게아 
스패닝트리가 주어지고 엣지가(100000)번 추가될때
그순간순간의 갱신되는 mst의 합
//link cut tree
O(lgN) for link, cut, find value on path
O(mlgV) for model solution

coders high 2015 동영상 해석
https://www.youtube.com/watch?v=pe65s8s05sU !!!!

//coupon collector's problem
https://en.wikipedia.org/wiki/Coupon_collector%27s_problem

//주작 주 주작
//1대1매칭임(문제에는 그런 내용이 없음)
//모든게 다 달라야 됨
//각 사이클들을 찾고 답은 사이클의 배수들이 되면 안됨
//3부터 쭉 찾아가서 어느 사이클의 배수도 아닌 놈이 답이 된다. 
int main() {
	int n; cin >> n;
	vector<int> arr(n + 1);
	vector<bool> vstd(n + 1, false);
	vector<bool> use(1000001, false);
	map<int, int> use2;
	bool ok = true;
	rep(i, n) {
		scanf("%d", &arr[i + 1]);
		if (arr[i + 1] == i + 1)
			ok = false;
	}
	if (ok == false) {
		cout << -1;
		return 0;
	}
	vector<int> cntArr;
	for (int i = 1; i < arr.size(); ++i) {
		int here = i;
		int sz = 0;
		while (vstd[here] == false) {
			sz++;
			vstd[here] = true;
			here = arr[here];
		}
		if (sz > 0) {
			cntArr.push_back(sz);
			if (use2.count(sz) == 0) {
				use2[sz]++;
				for (int i = sz; i < 1000001; i += sz)
					use[i] = true;
			}
		}
	}

	sort(cntArr.begin(), cntArr.end());
	int sol = 3;
	for (int i = 3; i < 1000001; ++i) {
		if (use[i] == false) {
			sol = i;
			break;
		}
	}
	cout << sol;
	return 0;
}

백준//나의 행렬곱셈 답사기: 문제 졸라 쉬운데...
..아아 ㅠㅠ
int main() {
	int n; cin >> n;
	printf("3\n");
	printf("1 %d 1 1", n + 1);
	return 0;
}




https://algospot.com/judge/problem/read/BST
Binary Search Tree	//키는 유일함, 키가 가진 값은 유일하지 않음
//BST가 되려면 입력된 키는 하나만 되어야 하고
//키와 연결된 놈들(엣지)의 갯수는 key갯수 - 1이 되어야 한다.

//그래프 특징. 문제에서 Each node in the tree has a unique numeric key.
//문장 해석에서 해맴..
//노드값에 대응하는 유일한 키는 가지고 있다는 말은 
//각 키는 서로 다른 노드값을 보장하진 않음
bool vstd[1001];
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(vstd, 0, sizeof(vstd));
		int n; cin >> n;
		int edges = 0;
		int lNode, rNode, hKey;
		bool ok = true;
		rep(i, n) {
			scanf("%d%d%d", &lNode, &rNode, &hKey);
			if (vstd[hKey]) ok = false;
			vstd[hKey] = true;
			if (lNode != 0) edges++;
			if (rNode != 0) edges++;
		}
		if (ok && edges == n - 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//각종 대회 후기 및 에디토리얼(없는것도 많음)!!!!
https://algospot.com/wiki/read/%EB%8C%80%ED%9A%8C_%ED%9B%84%EA%B8%B0_%EB%B0%8F_%EC%97%90%EB%94%94%ED%86%A0%EB%A6%AC%EC%96%BC


https://algospot.com/judge/problem/read/RECAPTCHA  //통과함
//최대 유사도를 갖는 단어는 유일하다. 엄밀히 말해, 최대 유사도를 x라 할 때 
//0.999999 x 이상의 유사도를 갖는 다른 단어는 존재하지 않는다고 가정해도 무방하다.
// 윗 지문상 곱셈을 로그의 합으로 나타낼 필요는 없겠군.
double prob[52][52][27];
double dp[52];
int prnt[52];	//dp를 갱신시킨 경우 부모를 저장
int ch[52];		//dp를 갱신시킨 문자를 저장
int main() {
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		memset(prnt, -1, sizeof(prnt));
		memset(ch, 0, sizeof(ch));
		dp[1] = 1.0;
		int n; cin >> n;
		rep2(i, 1, n + 1) rep2(j, i + 1, n + 1) rep2(k, 1, 27) cin >> prob[i][j][k];
		rep2(here, 1, n + 1) {
			rep2(prev, 1, here) {
				rep2(k,1, 26 + 1) {
					double cand = prob[prev][here][k];
					if (prev != 1)
						cand *= dp[prev];
					if (dp[here] < cand) {
						dp[here] = cand;
						prnt[here] = prev;
						ch[here] = k;
					}
				}
			}
		}
		int here = n;
		string str;
		while (here != 1) {
			str.push_back(ch[here] + 'a' - 1);
			here = prnt[here];
		}
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}


https://algospot.com/judge/problem/read/BASEBALL	//나는 그리디에 많이 약한거 같다..
일단 아래처럼 짜서 풀어보자. 
//1. 자신에게 몰빵
//2. 자신을 제외한 나머지 세놈(최대한 점수를 얻을때 강력한 승률을 가지는 순으로) 몰빵
//3. 나머지놈들은 자신의 이하로 나누되 불가능하면 "NO" 이것이 가능하면 "YES"
int main() {
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		
	}
	return 0;
}


//어려워서 기록한게 아니라 졸라 빡치는 거라 기록한다.
http://codeforces.com/contest/677/problem/C
//종니 빡치네.. 이걸 왜 계속 틀렸을까...ㅠㅠ!!!!
001111 은 7개가 아니야... 9개라고
011111 111111 011111 은 9개인거 알았는데
왜 
001111 은 7개라고 공식을 만들었냐 등신아...ㅠㅠ((2 ^ zeroCnt) * 2 - 1)이라는 괴랄한 공식을 만들고
그 공식에서 벗어나질 못했다.. "V_V" 예시랑 비교하고 좀더 생각했으면 했는데....
long long pow_2(long long nn) {
	long long ret = 1;
	rep(i, nn) ret *= 2;
	return ret;
}
int main() {
	string str; cin >> str;
	long long sol = 1;
	rep(i, str.size()) {
		int tmp;
		if (str[i] >= '0' && str[i] <= '9') {
			tmp = int(str[i] - '0');
		}
		if (str[i] >= 'A' && str[i] <= 'Z') {
			tmp = int(str[i] - 'A' + 10);
		}
		if (str[i] >= 'a' && str[i] <= 'z') {
			tmp = int(str[i] - 'a' + 36);
		}
		if (str[i] == '-') tmp = 62;
		if (str[i] == '_') tmp = 63;
		long long zeroCnt = 6 - __popcnt(tmp);
		while (zeroCnt--) {
			sol *= 3;
			sol %= MOD;
		}
	}
	cout << sol<< endl;
	return 0;
}



//codeforces
//내소스 TLE 뜬다.
한스텝이 "color - 1" 의 갯수랑 "color"의 갯수의 곱이 45000 * 45000 이 나올수도 있기 때문이다.
저자는 그런 많은 경우를 대비해 bfs로 예외처리한다. //이 경우 한 스텝의 경우 O(90000)이 된다.
O(n * m * sqrt(n * m))이라 하는디.. 잘 인식이 안됨


vector<pair<int, int>> arr[90001];	//수행시간을 줄이고자 사용한거
//인접행렬대신 연결리스트를 쓰는 효과가 나옴
int dp[2][301][301];	//무한대로 잡되 첫지점만 0.
int dist(const pair<int, int>& a, const pair<int, int>& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
	//freopen("input.txt", "r", stdin);
	int n, m, p; cin >> n >> m >> p;
	rep2(i,1,n + 1) rep2(j,1, m+1) {
		int a; 
		scanf("%d", &a);
		arr[a].push_back(mp(i, j));
	}
	arr[0].push_back(mp(1, 1));
	rep(i, 2)rep(j, 301)rep(k, 301) dp[i][j][k] = INF;
	dp[0][1][1] = 0;
	rep2(i, 1, p + 1) {
		int i0 = (i + 1) & 1;
		int i1 = i & 1;
		rep(j, arr[i].size()) {
			pair<int, int> here = arr[i][j];	//here
			rep(k, arr[i - 1].size()) {
				if (dp[i1][here.first][here.second] == -1)
					dp[i1][here.first][here.second] = INF;
				pair<int, int> prev = arr[i - 1][k];
				int cand = dp[i0][prev.first][prev.second] + dist(here, prev);
				dp[i1][here.first][here.second] = min(dp[i1][here.first][here.second], cand);
			}
		}
		//!!!!이걸 안해서 틀림... 슬라이딩 윈도우의 주의점
		//계산영역이 살아있으면 안됨...
		//계산이 끝나면 초기화	//간단한 방법 없나...
		//rep(i, 301) rep(j, 301) dp[i0][i][j] = INF;	
		memset(dp[i0], -1, sizeof(dp[i0]));
	}
	cout << dp[p & 1][arr[p][0].first][arr[p][0].second];
	return 0;
}
//윗소스의 복잡도는 (n * m) * (n * m) 이 되겠군..


//에디토리얼 저자 소스(내가 편집한거)
//저자도 (n * m) * (n * m) 이 되는 것을 언급했다. 그것을 피하기 위해 bfs로 예외처리한다
"bfs부분은 눈여겨 볼 만한다."
#define X first
#define Y second;
ll i,j,n,h,x,y,cur_h,k,m,p,fx,fy;
ll a[505][505], dp[505][505], d[505][505];	//301이면 있으면 되는디..너무 여유를 잡는거 같다.
vector<pair<ll, ll>> g[250505];	//마찬가지로 크게 잡음
ll dir[4][2] = { { -1, 0 }, {1, 0}, {0, 1}, { 0, -1 }};
vector<pair<ll, pair<ll, ll>>> lst, bfs;	//list 랑 bfs에 사용하는 queue
ll Abs(ll x) { return x > 0 ? x : -x; }
ll find_dist(ll x1, ll y1, ll x2, ll y2) { return Abs(x1 - x2) + Abs(y1 - y2); }
bool in_range(ll x, ll x_limit) { return (x >= 0 && x < x_limit); }
int main() {
	cin >> n >> m >> p;		rep(i,n) rep(j,m) dp[i][j] = (ll)1e+9;
	rep(i,n) rep(j,m) {
		scanf("%d", &a[i][j]);	g[a[i][j]].pb(mp(i,j));
		if (a[i][j] == 1) dp[i][j] = i + j;		if (a[i][j] == p) fx = i, fy = j;
	}
	rep2(i,2,p+1) {
		ll cur_size = g[i].size();	ll last_size = g[i - 1].size();
		if (cur_size * last_size <= n * m) {
			rep(j,cur_size) {
				ll cur_x = g[i][j].X, cur_y = g[i][j].Y;
				rep(k,last_size) {
					ll last_x = g[i - 1][k].X, last_y = g[i - 1][k].Y;
					dp[cur_x][cur_y] = min(dp[cur_x][cur_y], dp[last_x][last_y]
						+ find_dist(cur_x, cur_y, last_x, last_y));
				}
			}
		} else {	//이 한스텝 구간은 bfs로 time복잡도가 O(n * m) 이다.
			rep(k,n) rep(j,m) d[k][j] = -1;
			bfs.clear(); lst.clear();	//vector<pair<ll, pari<ll, ll>>> lst, bfs;
			rep(j,last_size) {
				ll last_x = g[i - 1][j].X;	ll last_y = g[i - 1][j].Y;
				lst.pb(mp(dp[last_x][last_y], mp(last_x, last_y)));
			}
			sort(lst.begin(), lst.end());
			ll pointer = 1; j = 0;
			bfs.pb(lst[0]);
			d[lst[0].Y.X][lst[0].Y.Y] = lst[0].X;
			while (j < bfs.size()) {
				ll x = bfs[j].Y.X, y = bfs[j].Y.Y, val = bfs[j].X;
				j++;
				//다중 위치에서의 BFS 우와!!!!!
				while (pointer < lst.size() && lst[pointer].X <= val)	//이 구문 참 멋진 방법이다.
					bfs.pb(lst[pointer++]);	//큐에 추가
				rep(k,4)
					if (in_range(x + dir[k][0], n) && in_range(y + dir[k][1], m)
						&& d[x + dir[k][0]][y + dir[k][1]] == =1) {
						d[x + dir[k][0]][y + dir[k][1]] = val + 1;
						bfs.pb(mp(val + 1, p(x + dir[k][0], y + dir[k][1])));	//큐에 추가
					}
			}
			rep(j,cur_size) {
				ll cur_x = g[i][j].X, cur_y = g[i][j].Y, dp[cur_x][cur_y] = d[cur_x][cur_y];
			}
		}
	}
	cout << dp[fx][fy] << endl;
	return 0;
}
//또다른 풀이법임 대충 알겠는데. 시간복잡도가 O(n^3) 라는데 잘 모르겠다..(아마 분할 상환때문인듯하다)
http://codeforces.com/blog/entry/45181  by Errichto
//249ms통과됨
const int MX = 305;
int type[MX][MX];
vector<int> col[MX];	//v+1 의 좌표: index 가 열의 값(x), 값들은 y들이 된다.
int dp[MX][MX];
vector<pair<int, int>> arr[MX * MX];
bool vst[MX];	//v가 존재하는 행들을 true로 세팅
int main() {
	//freopen("input.txt", "r", stdin);
	int h, w, p; cin >> h >> w >> p;
	rep(y, h) rep(x, w) {
		scanf("%d", &type[x][y]);
		if (type[x][y] == 1) dp[x][y] = x + y;
		else dp[x][y] = INF;
		arr[type[x][y]].push_back(mp(x, y));
	}
	for (int v = 1; v <= p - 1; ++v) {
		rep(i, w) col[i].clear();
		rep(i, h) vst[i] = false;
		rep(i, arr[v + 1].size()) {
			int x = arr[v + 1][i].first, y = arr[v + 1][i].second;
			col[x].push_back(y);
		}
		rep(i, arr[v].size()) vst[arr[v][i].second] = true;
		rep(y, h) if (vst[y]) {
			int best = INF;
			rep(x, w) {// 수직 작대기가 왼쪽에서 오른쪽으로 훑어감
				++best;	
				if (type[x][y] == v) best = min(best, dp[x][y]);	//수평축 거리
				rep(i, col[x].size()) {
					int h = col[x][i];
					dp[x][h] = min(dp[x][h], best + abs(h - y));
				}
			}
			best = INF;
			for (int x = w - 1; x >= 0; --x) {	//수직 작대기가 오른쪽에서 왼쪽으로 훑어감
				++best;
				if (type[x][y] == v) best = min(best, dp[x][y]);
				rep(i, col[x].size()) {
					int h = col[x][i];
					dp[x][h] = min(dp[x][h], best + abs(h - y));
				}
			}
		}
	}
	rep(x, w) rep(y, h) if (type[x][y] == p) printf("%d\n", dp[x][y]);
}


https://algospot.com/judge/problem/read/ORIVIRUS
오리독감
//노드수가 100개임: 그냥 전수조사함(bigO(100 * 100 * 100 * 100) : 1억) 
실제론 아래를 통해 26ms에 통과함
//2개 초과는 무시해서 속도 향상
//이미 감염된것은 무시해서 속도 향상


https://algospot.com/judge/problem/read/WEIRD
//앞에서 부터 차례로 더해서 n과 비교하는 것보다
//다 합친것에서 하나씩 빼서 n과 비교하는 것이 더 빠른 경우임 !!!! // 1. 좋은거 배움
//solve, solve2 시간은 약 80ms로 동일했음요.
//solve2 의 경우 탐색순서가 변경되면 타임 오버 된다. !!!! // 2. 좋은거 배움
int n;
vi divisor;
bool solve(int prev, int sum) {
	if (sum == n) return true;
	if (sum < n) return false;
	for (int here = prev + 1; here < divisor.size(); ++here) 
		if (solve(here, sum - divisor[here]))
			return true;
	return false;
}
bool solve2(int prev, int sum) {
	if (sum == n) return true;
	if (sum < n) return false;
	//prev+1 = here;
	if (prev + 1 == divisor.size())
		return false;
	if (solve2(prev + 1, sum - divisor[prev + 1]))
		return true;
	if (solve2(prev + 1, sum))
		return true;

	//이렇게 탐색하면 타임오버난다. 탐색이 2^약수의 갯수 만큼 탈 수 있기 때문이다. 
	//탑을 찾는 빠른 탐색순으로 해야하는 중요성을 알수 있다.
	/*
	if (solve2(prev + 1, sum))
		return true;
	if (solve2(prev + 1, sum - divisor[prev + 1]))
		return true;
	*/
	return false;
}
"의심: 음..input data에 의해 false가 호출이 많이 있다면 solve2는 통과 못할 것 같다...
int main() {
	//freopen("input.txt", "r", stdin);
	int cs;	scanf("%d", &cs);
	rep(cc, cs) {
		cin >> n;
		divisor.clear();
		for (int i = 1; i <= n / 2; ++i) 
			if (n % i == 0)
				divisor.push_back(i);
		int sum = accumulate(divisor.begin(), divisor.end(), 0);
		if (sum <= n) {
			cout << "not weird\n";
			continue;
		}
		//bool same = solve(-1, sum);
		bool same = solve2(-1, sum);
		if (same)
			cout << "not weird\n";
		else
			cout << "weird\n";
	}
	return 0;
}


http://codeforces.com/contest/679/submission/18312030 //구사과소스(koosaga)
long long root(long long x) {
	long long lo = 0, hi = 100005;
	while (lo + 1 < hi) {
		long long m = (lo + hi) / 2;
		if (m * m * m > x)
			hi = m;
		else
			lo = m;
	} 
	return lo;
}
map<long long, int> my;
int f(long long x) {
	if (x == 0) return 0;
	if (mp.find(x) != mp.end()) return mp[x];
	long long p = root(x);
	return mp[x] = max(f(x - p * p * p) + 1, f(p * p * p - 1));
}
long long tra(long long x) {
	if (x == 0) return 0;
	long long p = root(x);
	if (mp[x - p * p * p] + 1 == mp[x]) {
		return tra(x - p * p * p) + p * p * p;
	}
	return tra(p * p * p - 1);
}
int main() {
	long long x;
	cin >> x;
	printf("%d ", f(x));
	printf("%lld", tra(x));
	//printf("%d", tra(x));	//%d로 출력하면 망함
	return 0;
}
!!!!! 새로운거 배웠다.
"프로젝트 속성->링커->시스템->스택 예약 크기: 200000000으로 잡아라
"기본적인 스택 사이즈는 1MB이며 이는 짧은 함수의 깊이가 약 3000정도 가능하다
"구사과소스는 재귀 깊이가 넉넉 잡아 최대 10만 정도 필요하니(실제 깊이는 4만정도 될듯싶다만)
"일단 1MB의 100배 해서 테스트 해라
999999999999999
18 999999993541753


//제출했는데 22.5MB 사용했다고 하네
long long root(long long x) {
	int lo = 0, hi = 100005;
	while (lo + 1 < hi) {
		long long m = (lo + hi) / 2;
		if (m * m * m > x)
			hi = m;
		else
			lo = m;
	}
	return lo;
}
map<long long, int> my;
int rec(long long x) {
	if (x == 0) return 0;
	if (my.count(x) > 0)
		return my[x];
	long long p = root(x);
	return my[x] = max(rec(x - p*p*p) + 1, rec(p*p*p - 1));
}
long long reconstruct(long long x) {
	if (x == 0) return 0;
	long long p = root(x);
	if (rec(x - p * p * p) + 1 >= rec(p * p * p - 1))
		return p * p * p + reconstruct(x - p * p * p);
	else
		return reconstruct(p * p * p - 1);
}
int main() {
	long long x;
	cin >> x;
	printf("%d ", rec(x));
	//printf("%lld", reconstruct(x));
	printf("%I64d", reconstruct(x));	//대문자 I임 .. vs2010에선 엘엘디(lld)로 하면 안됨.
	return 0;
}



http://codeforces.com/contest/680/problem/C
interactive problem !!!!
//소수로 다 나누면 된다고 생각했으나
//질문을 20번까지 할수 있음
//1에서 100까지 소수의 갯수는 25개임
//질문을 줄일려면 어떤 머리를 써야 하나 잘 보삼!!!! 좋은 문제였군.


//100이하 합성수일 조건
//소수중 한개("p")는 무소건 10이하임 { 2, 3, 5, 7 }
//또 다른 소수("q")는 무조건 50 이하임 (p의 최소값이 2 이므로 100 / 2)

"풀이: {1 ~ 50 사이의 소수로 나눠본다}
"예외적으로 10이하의 소수 자신끼리의 곱으로 구성된 합성수를 체크해야 함
"2^2, 3^3, 5^5, 7^7
bool isPrime(int x) {
	int cnt = 0;
	rep2(i, 1, 101) {
		if (x % i == 0)
			cnt++;
	}
	if (cnt == 2) return true;
	else return false;
}
int main() {
	bool ok = 0;
	int cnt = 0;
	rep2(i, 2, 51) {
		if (isPrime(i)) {
			cout << i << endl;
			fflush(stdout);
			string str; cin >> str;
			if (str == "yes") {
				cnt++;
				if (i * i < 100) {
					cout << i * i << endl;
					fflush(stdout);
					cin >> str;
					if (str == "yes")
						cnt++;
				}
			}
		}
		if (cnt >= 2) {
			ok = 1;
			break;
		}
	}
	if (ok) cout << "composite";
	else	cout << "prime";
	return 0;
}

//n 이 최소 1 ~ 최대 10억
int main() {
	ll n;
	cin >> n;
	ll a = 1234567, b = 123456, c = 1234;
	bool ok = 0;
	for (ll i = 0; i*a <= n; i++){
		for (ll j = 0; j*b + i*a <= n; j++){
			ll need = n - i*a - j*b;
			if (need%c == 0)
				ok = 1;
		}
	}
	if (ok) cout << "YES";
	else cout << "NO";
	return 0;
}

// 내꺼 보니 한심스럽다..ㅠㅠ (이전에 해킹당한 코드는 nonnegative를 0보다 큰 정수로 해석했기 때문임.. 썅)
int n;
set<int> myS;
long long arr[3];
void set1() {
	for (int i = 0; i * arr[0] <= n; ++i)
		myS.insert(i * arr[0]);
	set<int> tmp = myS;
	set<int>::iterator it = tmp.begin();
	for (; it != tmp.end(); ++it) {
		for (int i = 0; i * arr[1] + *it <= n; ++i)
			myS.insert(i * arr[1] + *it);
	}
}
int main() {
	arr[0] = 1234567;
	arr[1] = 123456;
	arr[2] = 1234;
	cin >> n;
	set1();
	bool ok = false;
	set<int>::iterator it = myS.begin();
	for (; it != myS.end(); ++it) {
		int d2 = (n - *it) % arr[2];
		if (d2 == 0) {
			ok = true;
			break;
		}
	}
	if (ok)		cout << "YES";
	else		cout << "NO";
	return 0;
}

//http://codeforces.com/contest/681/problem/C
딱히 눈여겨 볼필욘 없음.. 단지 실수한거(빈 큐 고려)는 기억해라...
int main() {
	//	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	priority_queue<int, vi, greater<int>> q;
	int n; cin >> n;
	string str;
	int num;
	vector<pair<int, int>> arr;
	rep(i, n) {
		cin >> str;
		if (str == "removeMin") {
			if (q.empty()) {	//빈 큐를 고려해야 함... ㅠㅠ
				q.push(0);
				arr.push_back(mp(0, 0));	//0인 놈을 하나 넣어줌	//이거 없어서 틀렸음
			}
			q.pop();
			arr.push_back(mp(2, 0));
			//cout << str;
			//puts("");
		}
		else
		{
			cin >> num;
			if (str == "insert") {
				q.push(num);
				arr.push_back(mp(0, num));
				//cout << str << " " << num;
				//puts("");
			}
			else if (str == "getMin") {
				if (q.empty() || q.top() > num) {
					q.push(num);
					//cout << "insert" << " " << num;
					//puts("");
					arr.push_back(mp(0, num));
				}
				else if (q.top() < num) {
					while (!q.empty() && q.top() < num) {
						int tmp = q.top(); q.pop();
						//cout << "removeMin";
						//puts("");
						arr.push_back(mp(2, 0));
					}
					if (q.empty() || q.top()> num) {
						q.push(num);
						//cout << "insert" << " " << num;
						//puts("");
						arr.push_back(mp(0, num));
					}
				}
				//cout << str << " " << q.top();
				//puts("");
				arr.push_back(mp(3, q.top()));
			}
		}
	}

	cout << arr.size() << endl;
	rep(i, arr.size()) {
		if (arr[i].first == 0)
			printf("insert %d\n", arr[i].second);
		else if (arr[i].first == 2)
			printf("removeMin\n");
		else if (arr[i].first == 3)
			printf("getMin %d\n", arr[i].second);
	}
	return 0;
}

https://algospot.com/judge/problem/read/BASEBALL
// 딱히 다시 볼 필욘 없다.. 통과 9ms.. 실수를 곱십어라
int MX = 8;
int win[8], draw[8], lose[8];
double rate[8];
int Rank[8];
bool absoluteEqual(double a, double b) {
	return fabs(a - b) < 1e-10; //10의 10승 1분의 1
}
void setRate() {
	map<double, vi> mm;
	rep(i, 8) {
		if (win[i] + draw[i] + lose[i] == 0)
			rate[i] = 0.0;
		else
			rate[i] = (double)win[i] / (win[i] + draw[i] + lose[i]);
		mm[-rate[i]].push_back(i);
	}
	int ranking = 0; int cnt = 0;
	double preKey = -1;
	for (map<double, vi>::iterator it = mm.begin(); it != mm.end(); ++it) {
		if (preKey == -1 || absoluteEqual(preKey, it->first)) {
		}
		else {
			ranking += cnt;
			cnt = 0;
		}
		for (int i = 0; i < it->second.size(); ++i) {
			cnt++;
			Rank[it->second[i]] = ranking;
		}
		preKey = it->first;
	}

}
map<string, int> my;
int main() {
	//freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		rep(i, 8) {
			string str;
			cin >> str >> win[i] >> draw[i] >> lose[i];
			my[str] = i;
		}
		setRate();
		string str; cin >> str;
		int t = my[str];
		int r; cin >> r;
		rep(i, r) {
			string a, b;
			cin >> a >> b;
			if (t == my[a]) {
				win[t]++;
				lose[my[b]]++;
			}
			else if (t == my[b]) {
				win[t]++;
				lose[my[a]]++;
			}
			else {
				draw[my[a]]++; draw[my[b]]++;	//지는것과 비기는 것은 승률상 같음.
				//승패가 나는것은 누군가는 이겨서 승률을 올리는 행위임
				//비기면 둘다 패배하는 효과를 가짐.
				//문제를 잘 읽자구나...ㅠㅠ !!!!
			}
		}
		setRate();
		if (Rank[t] < 4)	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}


//topcoder TCO2016 2C 250
// 구리게 풀었다만 돌아간다.//내가 작성한 알고스팟 레이저 코드 재활용함(사이트에 있음)
// 깔끔하게 푼 사람 소스를 보세.
// map에 키로 넣는 방식이 간단한 소스들이 많았다.
const int INF = 987654321;
const int MOD = 1000000007;
class BearBall {
public:
	int gcd(int p, int q) {
		if (q == 0) return p;
		return gcd(q, p % q);
	}
	void makeCoprime(int& a, int& b, int& c) {
		int nGCD = gcd(a, b);
		nGCD = gcd(nGCD, c);
		a /= nGCD;
		b /= nGCD;
		c /= nGCD;
	}
	void getABC(const pii& pt1, const pii& pt2, int& a, int& b, int& c) {
		int x1, y1, x2, y2;
		x1 = pt1.first; y1 = pt1.second;
		x2 = pt2.first; y2 = pt2.second;
		a = x2 - x1;
		b = y1 - y2;
		c = x1 * (y2 - y1) - y1 * (x2 - x1);
		makeCoprime(a, b, c); //약분시키자
							  //부호유일하게
		if (a < 0) { a *= -1; b *= -1; c *= -1; }
		else if (a == 0 && b < 0) { a *= -1; b *= -1; c *= -1; }
	}
	int countThrows(vector<int> x, vector<int> y) {
		// 일렬인 경우
		map<pair<pair<int, int>, int>, int> m;
		int n = x.size();
		rep(i,n)
			rep2(j, i + 1, n) {
			int a, b, c;
			pii aa = mp(x[i], y[i]);
			pii bb = mp(x[j], y[j]);
			getABC(aa, bb, a, b, c);
			m[mp(mp(a, b), c)]++;
		}
		long long cc = 0;
		map<pair<pii, int>, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second >= 3) {
				int sz = sqrt(it->second * 2);
				sz += 1;
				int tmp = (sz) * (sz - 1) - (sz - 1) * 2;
				cc += tmp;
			}
		}
		if (m.size() == 1) {
			long long ret = 0;
			it = m.begin();
			int sz = sqrt(it->second * 2);
			sz += 1;
			for (int i = 1; i < sz; ++i) {
				ret += i * (sz - i) * 2;
			}
			return ret;
		}
		long long nn = n * (n - 1);
		long long ret = nn - cc + cc * 2;
		return ret;
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	BearBall test;
	vi x, y;
	int cs; cin >> cs;
	rep(cc, cs) {
		int sz; cin >> sz;
		x.resize(sz);
		y.resize(sz);
		rep(i, sz) cin >> x[i];
		rep(i, sz) cin >> y[i];
		int sol = test.countThrows(x, y);
		cout << sol << endl;
	}
	return 0;
}

http://codeforces.com/contest/682/problem/C
// 좀더 깔끔하게 풀고 지우자. 영어해석에서 힘들었다...ㅠㅠ
dist(v, u) > arr[u] 인 놈들을 지우자
//윗놈 지우면 아랫놈들은 다 지워져야 하는 까다로움이 있다.
ll sol;
int n;
vector<pair<ll, ll>> adj[100001];
vector<ll> arr;
vector<bool> vstd;
int dfs(int here, ll trans, bool sin) { // sin: 죄의 낙인이 자식한테 전달
	vstd[here] = true;
	bool check = false;
	if (arr[here] < trans && sin == false) {	// 여기서 지워진다면 밑에 자식도 다 지워야 함
		check = true;
		sin = true;
	}
	if (trans < 0) trans = 0;
	int cnt = 1;
	rep(i, adj[here].size()) {
		int there = adj[here][i].first;
		if (vstd[there]) continue;
		ll nextTrans = adj[here][i].second + trans;
		cnt += dfs(there, nextTrans, sin);	// 자식들 카운팅
	}
	if (check == true)
		sol += cnt;
	return cnt;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	cin >> n;
	arr.resize(n + 1);
	vstd.resize(n + 1, false);
	rep2(i, 1, n + 1) scanf("%d", &arr[i]);
	rep2(i, 2, n + 1) {
		ll u, dist;
		cin >> u >> dist;
		adj[i].push_back(mp(u, dist));
		adj[u].push_back(mp(i, dist));
	}
	sol = 0;
	dfs(1, 0, false);
	cout << sol;
	return 0;
}

http://codeforces.com/contest/682/problem/D
Group Projects 랑 비슷한 식이네. 닫힌걸 고려해야 한다는 점이 말이지 !!!!
int n, m, k;
string str1, str2;
int cache[1001][1001][11][2];
// state : 열린상태: 0, 닫힌상태: 1
int rec(int ni, int mi, int ki, int state = 1) {
	if (ni == n || mi == m) {
		if (ki != k) return -INF;
	}
	if (ki == k)
		if (state == 1) return 0;
		else
			return -INF;
	int& ret = cache[ni][mi][ki][state];
	if (ret != -1) return ret;
	ret = 0;
	if (state == 0) {// 열린상태
		if (str1[ni] == str2[mi]) { //현재 닫을지 열고 전달할지
			ret = max(ret, 1 + rec(ni + 1, mi + 1, ki + 1, 1));
			ret = max(ret, 1 + rec(ni + 1, mi + 1, ki, 0));
		}
			ret = max(ret, rec(ni + 1, mi, ki + 1, 1));
			ret = max(ret, rec(ni, mi + 1, ki + 1, 1));
	}
	else {
		if (str1[ni] == str2[mi]) { //현재 닫을지 열고 전달할지
			ret = max(ret, 1 + rec(ni + 1, mi + 1, ki + 1, 1));
			ret = max(ret, 1 + rec(ni + 1, mi + 1, ki, 0));
		} 
			ret = max(ret, rec(ni + 1, mi, ki, 1));
			ret = max(ret, rec(ni, mi + 1, ki, 1));
	}
	return ret;
}
int main() {
//	freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	cin >> str1 >> str2;
	int sol = rec(0, 0, 0, 1);
	cout << sol << endl;
	return 0;
}

// 내거보다 10배 빠르다.. 칫
#define N (1<<10)
#include <bits/stdc++.h>
using namespace std;
char s[N],t[N];
int n,m,f,dp[N][N][11][2];
int main()
{
	cin>>n>>m>>f>>(s+1)>>(t+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=f;k++)
			{
				dp[i][j][k][0]=max(dp[i-1][j][k][0],dp[i][j-1][k][0]);
				if(s[i]==t[j])
				{
					if(dp[i-1][j-1][k][1]) dp[i][j][k][1]=dp[i-1][j-1][k][1]+1;
					if(k>0) dp[i][j][k][1]=max(dp[i][j][k][1],dp[i-1][j-1][k-1][0]+1);
				}
				dp[i][j][k][0]=max(dp[i][j][k][0],dp[i][j][k][1]);
			}
	cout<<dp[n][m][f][0]<<endl;

	return 0;
}




// 기하 !!!! 삼각형
// 점의 갯수는 3 ~ 5000개 , 1 <= ss <= 10^18
http://codeforces.com/contest/682/problem/E
http://codeforces.com/contest/682/submission/18579237
pii p[maxn];
int n;
// 외적은 평형사변형 면적이 된다.
inline ll area(pii a, pii b, pii c) {
	return abs((ll)(b.x - a.x) * (c.y - a.y) - (ll)(b.y - a.y) * (c.x - a.x));
}
void input() {
	int ss;
	scanf("%d%d", &n, &ss);	// ss: 임의의 세점의 삼각형 넓이의 상한 // 코드에선 이용안함
	rep2(i,1,n) scanf("%d%d", &p[i].x, &p[i].y);
}
void init() {
	sort(p+1,P+1+n);
	unique(p+1,p+1+n);
}
int solve() {
	int a = 1, b = 2, c = 3;
	ll s = area(p[a], p[b], p[c]);
	//while 부분은 이해가 안됨...
	// a, b, c 는 최대 넓이를 구성하게 된다는 결과만 알고 있자...ㅠㅠ!!!!
	// 활용도 높은 소스같다.
	while (1) {
		bool ch = false;
		rep2(i,1,n) {
			ll ns = area(p[a], p[b], p[i]);
			if (ns > s) s = ns, c = i, ch = true;
		}
		rep2(i,1,n) {
			ll ns = area(p[a], p[c], p[i]);
			if (ns > s) s = ns, b = i, ch = true; 
		}
		rep2(i,1,n) {
			ll ns = area(p[b], p[c], p[i]);
			if (ns > s) s = ns, a = i, ch = true;
		}
		if (!ch) break;
	}
	printf("%d %d\n", p[b].x + p[c].x - p[a].x, p[b].y + p[c].y - p[a].y);
	printf("%d %d\n", p[b].x + p[a].x - p[c].x, p[b].y + p[a].y - p[c].y);
	printf("%d %d\n", p[a].x + p[c].x - p[b].x, p[a].y + p[c].y - p[b].y);
}
int main() {
	input();
	init();
	solve();
	return 0;
}

http://codeforces.com/contest/686/problem/D
// 각 점을 기준한 서브트리에 대한 centroid 를 찾는다.
const int N = 300005;
int p[N];
int cen[N], sz[N];
vector<int> adj[N];
int n, m;
void dfs(int here) {
	sz[here] = 1;
	int MX = 0, sltd = -1;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		dfs(there);
		sz[here] += sz[there];
		if (MX < sz[there]) {
			MX = sz[there];
			sltd = there;
		}
	}
	if (MX == 0) cen[here] = here;
	else {
		int subCen = cen[sltd];
		// 문제 조건에서 각 서브트리의 센트로이드는 무조건 존재하는 인풋을 준다고 했다.
		while (sz[here] - sz[subCen] >= (sz[here] + 1) / 2)
			subCen = p[subCen];
		cen[here] = subCen;
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", p + i);
		adj[p[i]].push_back(i);
	}
	dfs(1);
	while (m--) {
		int v;
		scanf("%d", &v);
		printf("%d\n", cen[v]);
	}
	return 0;
}


// 매우좋은 dp 문제 !!!!
https://algospot.com/judge/problem/read/ANDROMEDA
// 연경이가 정정당당히 승부시 얻게되는 기대 승수
expected(a, b, c): 이김 : b == n - 1 : expected(a - 1, 0, 0) + 1
						  b < n - 1  : expected(a - 1, b + 1, c)
				   졌음 : c == n - 1 : expected(a - 1, 0, 0)
				          c < n - 1  : expected(a - 1, b, c + 1)
				   비김 :			 : expected(a - 1, b, c)
기저: expected(0, ...) = 0.0

double sol(int steps, int n) {
	double prev[10][10] = {0};
	double next[10][10] = {0};
	for (int j = 1; j <= steps; ++j) {
		rep(k,n) rep(l,n) {
			next[k][l] = prev[k][l];	// 비김
			// 이김
			if (k == n - 1) next[k][l] += 1 + prev[0][0];
			else			next[k][l] += prev[k + 1][l];
			// 졌음
			if (l == n - 1) next[k][l] += prev[0][0];
			else			next[k][l] += prev[k][l + 1];
			next[k][l] /= 3.0;
		}
		rep(k,n) rep(l,n) prev[k][l] = next[k][l];
	}
	printf("%lf\n", prev[0][0]);
}


expected(a, b, c): a개의 개단이 남아 있고, 이번 세트에서 연경이가 b승 c패인 상태에서
					이제부터 얻을 수 있는 기대 승수

expected(a, b, c): 이김 : b == n - 1 : expected(a - 1, 0, 0) + 1
						  b < n - 1	 : max(expected(a - 1, b + 1, c), expected(a - 1, 0, 0))
				   졌음 : c == n - 1 : expected(a - 1, 0, 0)
						  c < n - 1  : max(expected(a - 1, b, c + 1), expected(a - 1, 0, 0))
				   비김 :			   max(expected(a - 1, b, c), expected(a - 1, 0, 0))
기저: expected(0, ...) = 0.0 이니까, 여기서부터 시작해서 점화식을 사용해
expected(1, ...), expected(2, ...), ... 를 차례대로 구해나가다 보면 언젠가는 문제에서
원하는 답인 "expected(steps, 0, 0)"을 구할 수 있을 겁니다.
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int cs;
	cin >> cs;
	rep(cc,cs) {
		int steps, n;
		cin >> steps >> n;
		double prev[10][10] = {0};
		double next[10][10] = {0};
		for (int j = 1; j <= steps; ++j) {
			for (int k = 0; k < n; ++k)
				for (int l = 0; l < n; ++l) {
					next[k][l] = max(prev[k][l], prev[0][0]);	// 비김

					if (k == n - 1)
						next[k][l] += 1 + prev[0][0];	// 이김
					else
						next[k][l] += max(prev[k + 1][l], prev[0][0]);	// 이김

					if (l == n - 1)
						next[k][l] += prev[0][0];	// 졌음
					else
						next[k][l] += max(prev[k][l+1], prev[0][0]);	// 졌음

					next[k][l] /= 3.0;
				}
			rep(k,n) rep(l,n) prev[k][l] = next[k][l];
		}
		printf("%lf\n", prev[0][0]);
	}
	return 0;
}

여기까지는 많은 참가팀들도 생각해봤을 방법인데... 여기에는 두 가지 문제가 있습니다.// 나는 생각 안나더라..ㅠㅠ
(1) steps <= 100000000 이니 O(steps*n^2) 짜리 알고리즘은 TLE가 나겠죠.
(2) double을 1억번 더하면 precision error가 쌓여서 거대해질 수가 있습니다.
(2)번은 double 대신 long double을 사용하면 해결됩니다.
(1)번이 문제인데요.. 직관적으로 생각해보면 앞으로 남은 계단의 수가 많을 수록 한 계단의 가치는 일정해집니다. 이것은 n이 상대적으로 작기 때문인데요, 다시 말하면 계단 수가 적게 남은 경우에서의 기대값의 흔들림은 계단수가 많아질 수록 희미해지게 됩니다. a>40000일 때 expected(a, 0, 0) - expected(a-1, 0, 0) 을 expected(40000, 0, 0) - expected(39999, 0, 0) 이라고 가정하면, expected(steps, 0, 0) - expected(40000, 0, 0) = (steps-40000) * (expected(40000, 0, 0) - expected(39999, 0, 0)) 이 될 것입니다.
실제로 이렇게 해 보면, 상대오차가 1e-9보다 훨씬 작아지게 됩니다.
이렇게 구현한 코드는 다음과 같습니다.
https://algospot.com/forum/read/577/
// step 이 커질수록 step + 1 과 step 의 차이의 흔들림은 거의 없어진다.
// 개조버전
int main() {
	int cs; cin >> cs;
	rep(cc,cs) {
		int steps, n;
		cin >> steps >> n;
		long double prev[10][10] = {0};
		long double next[10][10] = {0};
		long double plus = 0.0;
		for (int j = 1; j <= steps; ++j) {
			rep(k,n) rep(l,n) {
				next[k][l] = max(prev[k][l], prev[0][0]);
				
				if (k == n - 1) 
					next[k][l] += 1 + prev[0][0];
				else
					next[k][l] += max(prev[k + 1][l], prev[0][0]);

				if (l == n - 1)
					next[k][l] += prev[0][0];
				else
					next[k][l] += max(prev[k][l + 1], prev[0][0]);

				next[k][l] /= 3.0;
			}
			if (j == 40000) plus = (steps - 40000) * (next[0][0] - prev[0][0]);// !!!!
			rep(k,n) rep(l,n) prev[k][l] = next[k][l];
			if (j == 40000) break;	
		}
		double res = prev[0][0] + plus;
		printf("%.16lf\n", res);
	}
	return 0;
}

// diff 가 얼마나 평탄화 되는지 아라보지
https://algospot.com/forum/read/578/
int main() {
	while (true) {
		int steps, n;
		cin >> steps >> n;
		int range1, range2;
		cin >> range1 >> range2;
		long double prev[10][10] = { 0 };
		long double next[10][10] = { 0 };
		long double plus = 0.0;
		for (int j = 1; j <= steps; ++j) {
			rep(k, n) rep(l, n) {
				next[k][l] = max(prev[k][l], prev[0][0]);

				if (k == n - 1)
					next[k][l] += 1 + prev[0][0];
				else
					next[k][l] += max(prev[k + 1][l], prev[0][0]);

				if (l == n - 1)
					next[k][l] += prev[0][0];
				else
					next[k][l] += max(prev[k][l + 1], prev[0][0]);

				next[k][l] /= 3.0;
			}
			if (j >= range1 && j <= range2) {
				long double cha = next[0][0] - prev[0][0];
				printf("%.16lf\n", cha);
			}
			rep(k, n) rep(l, n) prev[k][l] = next[k][l];
		}
	}
	return 0;
}

100 3
30 40		// step 이 30 ~ 40 구간에서의 차이: n 이 3이라 작아서 별반 차이가 안남
0.0894321828525784
0.0894317342670625
0.0894311074285752
0.0894307153069964
0.0894306273104282
0.0894307218028874
0.0894308516137787
0.0894309320926094
0.0894309496264754
0.0894309297323534
0.0894309028533828
100 10
10 20		// step 이 10 ~ 20 구간에서의 차이
0.0000169350878084
0.0001129005853895
0.0004139688130950
0.0011039168349199
0.0023918198089931
0.0044647303101205
0.0074412171835341
0.0113389976130044
0.0160635799517562
0.0214181066023417
0.0271170523112593
100 10
70 80
0.0222894212877565
0.0226751101776452
0.0231081457170783
0.0235565043041281
0.0239833735568677
0.0243605708977221
0.0246701927423578
0.0249024959712649
0.0250538940058060
0.0251256406292903
0.0251228794454548
1000 10
500 510		// step 이 500 ~ 510 구간에서의 차이: 거의 안난다
0.0238466944270854
0.0238466944269664
0.0238466944269060
0.0238466944268989
0.0238466944269433
0.0238466944270321
0.0238466944271547
0.0238466944273039
0.0238466944274656
0.0238466944276361
0.0238466944277995

http://codeforces.com/contest/688/problem/C
// 통과는 했는디.. 내 소스는 영 지저분해서 잘짠 소스 적는다.
// 그래프가 주어질때 각 정점을 2명에게 나눠준다고 할때
// 각자는 정점이 간선으로 이어지지 않은 집합을 가져야 한다.
// 3개짜리 루프는 성립안됨
// 4개짜리 루프는 성립됨
const int N = 120021;
vi vc[2];
vi graph[N];
int mark[N];
bool dfs(int here, int color = 2) {
	mark[here] = color;
	vc[color - 1].push_back(here);
	rep(i,graph[here].size()) {
		int there = graph[here][i];
		if (!mark[there] && dfs(u, 3 - color))	// 아직 방문하지 않았고 손자가 모순이 발생하면
			return 1;
		if (mark[there] != 3 - color)
			return 1;	// 자식이 모순이 발생하면
	}
	return 0;
}
int main() {
	int n, m;
	cin >> n >> m;
	rep(i,m) {
		int u, v;
		scang("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	rep(i,n) 
		if (!mark[i]) {
			if (graph[i].empth()) continue;
			if (dfs(i)) {
				cout << -1 << endl;
				return 0;
			}
		}
	rep(i,2) {
		cout << vc[i].size() << endl;
		for(int v: vc[i]) cout << v + 1 << " ";
		cout << endl;
	}
}
http://codeforces.com/contest/688/problem/D
임의의 수 x에 대해 y라는 수로 나눈 나머지를 알수 있는가? 알수 있다면 Yes, 알수 없다면 No
: 전제조건 
x를 c1로 나눈 나머지를 알고 있다.
x를 c2로 나눈 나머지를 알고 있다.
x를 ....
x를 cn으로 나눈 나머지를 알고 있다.
// 중국인의 나머지 정리를 알아야 한다...
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }	// !!!! 
long long lcm(int x, int y) { return x * 1ll * y / gcd(x, y); } // !!!!
int main() {
	int n, k;
	cin >> n >> k;
	int cur = 1;
	rep(i,n) {
		int x;
		cin >> x;
		cur = gcd(k, lcm(cur, x));
	}
	if (cur == k)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

http://codeforces.com/contest/688/problem/E
// dp 문제임
6 18	// n, k (the number of coins and the price ot the chocolate, respectively)
5 6 1 10 12 2


동전으로 18을 만들어야 함: 그 때 동전을 가지고 만들수 있는 숫자들을 출력하라
5 + 10 + 1 + 2			// 0 1 2 3 5 6 7 8 10 11 12 13 15 16 17 18
6 + 10 + 2				// 0   2     6   8 10    12             18
6 + 12					// 0   2     6   8       12             18

let dp(i,j,k) be true if and only if there exists a subset of the first icoins iwth sum j,
that a subset with sum k. There are 3 cases to handle:
 * The i-th coin is not used in the subsets;
	// i번째 코인은 18을 만들기 위해 사용되지 않음
 * The i-th coin is used in the subset to make j, but its not used in the subset of this subset.
	// i번째 코인은 18을 만들기 위해 사용됨 , 허나 18을 만든 수들을 가지고 새로 만들어지는 수에는 사용안됨
 * The i-th coin is used in both subsets.
	// 18을 만들기 위해 사용되고 그 뒤 새로 만들어지는 수에도 사용됨
So dp(i,j,k) is equal to dp(i-1, ji, k) OR dp(i-1, j - ci, k) OR dp(i - 1, j - ci, k - ci)
The complexity is O(n * k^2)

" 오오 좋은 dp 문제다 !!!! 전체를 바라보는 안목을 길러야 겠다..."
dp[9][32][18] // 9개의 동전을 사용 32를 만듬 32를 구성하는 동전들로 18을 만듬
dp[9][32][18] =		dp[8][32][18]	
				OR	dp[8][32 - arr[9]][18] 
				OR	dp[8][32 - arr[9]][18 - arr[9]]

const int N = 505;
bool dp[2][N][N];
int main() {
	int n, k;
	cin >> n >> k;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		int now = i % 2;
		int last = 1 - now;
		int x; cin >> x;
		for (int j = 0; j <= k; ++j)
			for (int y = 0; y <= j; ++y) {
				dp[now][j][y] = dp[last][j][y];
				if (j >= x) {
					dp[now][j][y] |= dp[last][j - x][y];
					if (y >= x)
						dp[now][j][y] |= dp[last][j - x][y - x];
				}
			}
	}
	vector<int> res;
	for (int i = 0; i <= k; ++i)
		if (dp[n % 2][k][i])	// 호 훌륭하군요.
			res.push_back(i);
	cout << res.size() << endl;
	rep(i,res.size())
		cout << res[i] << " ";
	cout << endl;
}


http://codeforces.com/contest/706/problem/C
" INF 설정시 조심해야 한다"
const long long INF = 1000000000000000LL;	// numeric_limits<long long>::max() 로 잡으면 아래에서 오버플로우 발생
const double EPSILON = 1e-10;
long long dp[100003][2];
int main() {
	//memset(dp, -1, sizeof(dp));
	//string a = "aa";
	//string aa = "aa";
	//bool test = lexicographical_compare(a.begin(), a.end(), aa.begin(), aa.end());
	// test 는 false 가 된다.
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> arr(n);
	vs arr2(n);
	vs arr3(n);	// reverse
	rep(i, n) scanf("%d", &arr[i]);
	rep(i, n) {
		cin >> arr2[i];
		arr3[i] = arr2[i];
		reverse(arr3[i].begin(), arr3[i].end());
	}
	dp[0][0] = 0;
	dp[0][1] = arr[0];	// 뒤집기
	rep2(i,1, n) {
		dp[i][0] = INF;
		if (arr2[i] == arr2[i - 1])			dp[i][0] = min<long long>(dp[i][0], dp[i - 1][0]);
		if (arr2[i] == arr3[i - 1])			dp[i][0] = min<long long>(dp[i][0], dp[i - 1][1]);

		if (lexicographical_compare(arr2[i - 1].begin(), arr2[i - 1].end(), arr2[i].begin(), arr2[i].end()))
			dp[i][0] = min<long long>(dp[i][0], dp[i - 1][0]);
		if (lexicographical_compare(arr3[i - 1].begin(), arr3[i - 1].end(), arr2[i].begin(), arr2[i].end()))
			dp[i][0] = min<long long>(dp[i][0], dp[i - 1][1]);

		dp[i][1] = INF;
		if (arr3[i] == arr2[i - 1])			dp[i][1] = min<long long>(dp[i][1], dp[i - 1][0] + arr[i]);
		if (arr3[i] == arr3[i - 1])			dp[i][1] = min<long long>(dp[i][1], dp[i - 1][1] + arr[i]);

		if (lexicographical_compare(arr2[i - 1].begin(), arr2[i - 1].end(), arr3[i].begin(), arr3[i].end()))
			dp[i][1] = min<long long>(dp[i][1], dp[i - 1][0] + arr[i]); // 뒤집기
		if (lexicographical_compare(arr3[i - 1].begin(), arr3[i - 1].end(), arr3[i].begin(), arr3[i].end()))
			dp[i][1] = min<long long>(dp[i][1], dp[i - 1][1] + arr[i]); // 두집기
	}
	long long sol = min<long long>(dp[n - 1][0], dp[n - 1][1]);
	if (sol >= INF)
		sol = -1;
	cout << sol;
	return 0;
}

http://www.codeforces.com/contest/705/problem/C
// 여러가지 응용 가능한 좋은 문제다.
" re read 해석 주의해라"
// 핵심 아이디어
1) 이벤트 쌓기:		해당 이벤트를 만든 앱번호를 매핑
					현재 남은 전체 이벤트에 쌓는다.
					해당 앱번호의 남은 이벤트에도 쌓는다.

2) 앱번호로 읽기:	남은 전체 중 해당 이벤트를 제거
					해당 앱번호에서 남은 이벤트는 0
3) 순자적으로 읽기:	해당 이벤트를 호출한 앱을 찾는다. 그 앱에서 해당 이벤트는 제거
					남은 전제 중 해당 이벤트를 제거

const int maxN = 300 * 1000 + 10;// 이벤트 숫자, 앱의 최대 갯수도 됨
set<int> curr, b[maxN];	
// curr: 현재 안 읽은 이벤트들, b[maxN]: 각 앱들에서 안 읽은 이벤트들
int a[maxN];	// a[event]: x  이벤트를 인덱스로 가짐, 호출한 앱을 값으로 가짐
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); // 이거 없으면 1404ms, 있으면 702ms 걸림. 모지..?
	int n, q; cin >> n >> q;
	int en = 0;
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 1) {
			int x;	cin >> x;	// 어느 앱이 이벤트를 발생시켰노? x요
			x--;
			//a[x] = en; // 풀이 소스가 잘못되었어요. 아래로 고쳐야 됨.
			a[en] = x;	// 이번 이벤트를 발생시킨 놈은 x앱이라우
			curr.insert(en);	// 현재 안 읽은 이벤트 번호 저장
			b[x].insert(en);	// x앱의 안 읽은 이벤트 번호 저장
			en++;
		}
		else if (t == 2) {
			int x;
			cin >> x;
			x--;
			//for (auto y : b[x]) // ms2010 에선 지원 안되는구나
			//	curr.erase(y);	
			for (set<int>::iterator it = b[x].begin(); it != b[x].end(); it++) {
				// x앱의 안 읽은 이벤트 번호를 하나하나 순회
				int y = *it;
				curr.erase(y); // 현재 남은 이벤트에서 제거
			}
			b[x].clear();	// x앱의 안 읽은 이벤트는 없어짐
		}
		else {
			int t;	cin >> t; // 시작부터 t번까지 이벤트를 읽음 (re read임)
			while (curr.size() && *curr.begin() < t) {
				b[a[*curr.begin()]].erase(*curr.begin()); // !!!! 제일 중요
				// 현 남아 있는 이벤트들을 t번까지 읽음(0부터 시작임을 고려)
				// a[event]: 남은 이벤트를 만든 x앱을 찾음
				// b[x].erase(*curr.begin()); x앱의 안 읽은 이벤트를 지워라.
				curr.erase(curr.begin());
				// 자신도 지움
			}
		}
		cout << curr.size() << '\n'; // endl 쓰지마라
	}
	return 0;
}

"cin.tie(0);" 의 대략적인 기능
//	https://algospot.com/judge/problem/read/FAMILYTREE#c14886
c++ 스타일의 출력을 하고 싶다면 std::ios_base::sync_with_stdio(false) 와 endl대신 '\n'을 쓰고, 
cin.tie(0)까지 해줘야 합니다(cin 사용시 cout flush방지)
마지막 cin.tie(0)를 안할경우 시간초과나네요..


// 내방식으로 푼거, get, setting 추가함
struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {}
	int sum(int pos) {
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
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
	int get(int pos) {
		return sum(pos) - sum(pos - 1);
	}
	void setting(int pos, int val) {
		int k = get(pos);
		add(pos, -k);
	}
};
const int maxN = 300 * 1000 + 10;
int lastEvent[maxN];	//각각의 앱의 마지막 이벤트
int appFinishEvent[maxN];	//앱의 읽어들인 마지막 이벤트
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;
	FenwickTree FT(n + 1); // 사이즈 1 더 추가함// 그냥 수정 귀찮아서.
	//FT.sum(n) 이 인덱스를 n+1 로하기에, FT 내부 사이즈는 n + 2 가 되어야 함
	memset(lastEvent, -1, sizeof(lastEvent));
	memset(appFinishEvent, -1, sizeof(appFinishEvent));
	vector<int> my(q);
	int en = 0;
	int prog = 0;	//순차적으로 읽어들인 이벤트
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			x--;
			//lastEvent[x] = en;
			FT.add(x, 1);
			my[en] = x; // 해당 이벤트를 만드는 앱을 저장
			lastEvent[x] = en;	// 애당 앱이 생성한 마지막 이벤트번호 저장
			en++;
		}
		else if (t == 2) {
			int x; cin >> x;
			x--;
			FT.setting(x, 0);
			appFinishEvent[x] = lastEvent[x];
		}
		else {
			int t; cin >> t;
			for (; prog < t; ++prog) {
				int x = my[prog];
				if (appFinishEvent[x] < prog) //!!!! 
				// 기존에 처리된 이벤트면(2번 버튼으로) 생략
				// 기존 처리된 이벤트 보다 뒤라면 아직 미처리라 처리한다.
					FT.add(x, -1);
			}
		}
		cout << FT.sum(n) << '\n';
	}
	return 0;
}

// 내가 앞에서 틀린 이유
4 10
1 1	// 1
2 1 // 0 : 다지움
1 1 // 1 
3 1	// 1이어야 하는데 0이 나오는 오류를 범함
appFinishEvent[x]가 필요한 이유이다.


// 사실 펜윅트리 없어도 쉽게 풀리네.
const int numN = 300003;
deque<int> app[numN];
int appPrevProcessEV[numN];
vector<int> allEV;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(appPrevProcessEV, -1, sizeof(appPrevProcessEV));
	int n, q;
	cin >> n >> q;
	int eventNum = 0;	// for index
	int unreadCnt = 0;	// for total unread count
	int sequential = 0;
	rep(i, q) {
		int type; cin >> type;
		if (type == 1) {
			int x; cin >> x;
			app[x].push_back(eventNum);
			//allEV[eventNum] = x;
			allEV.push_back(x);
			eventNum++;
			unreadCnt++;
		}
		else if (type == 2) {
			int x; cin >> x;
			if (app[x].size() != 0) {
				unreadCnt -= app[x].size();
				appPrevProcessEV[x] = app[x].back();
				app[x].clear();
			}
		}
		else {
			int t; cin >> t;
			for (; sequential < t; ++sequential) {
				int x = allEV[sequential]; // 번째 이벤트의 주인 앱 x
				if (sequential > appPrevProcessEV[x]) { // !!!! 핵심
					unreadCnt--;
					app[x].pop_front();
				}
			}
		}
		cout << unreadCnt << '\n';
	}
	return 0;
}
// 이전까지 각앱의 마지막 처리된 이벤트를 가지고 있을 필요는 없지
// 데큐의 처음과 비교하면 되니
// 따라서 appPrevProcessEV 변수는 없애도 됨.
const int numN = 300003;
deque<int> app[numN];
vector<int> allEV;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;
	int eventNum = 0;	// for index
	int unreadCnt = 0;	// for total unread count;
	int sequential = 0;
	rep(i, q) {
		int type; cin >> type;
		if (type == 1) {
			int x; cin >> x;
			app[x].push_back(eventNum);
			allEV.push_back(x);
			eventNum++;
			unreadCnt++;
		}
		else if (type == 2) {
			int x; cin >> x;
			if (app[x].size() != 0) {
				unreadCnt -= app[x].size();
				app[x].clear();
			}
		}
		else {
			int t; cin >> t;
			for (; sequential < t; ++sequential) {
				int x = allEV[sequential];
				if (!app[x].empty() && sequential >= app[x].front()) {
					unreadCnt--;
					app[x].pop_front();
				}
			}
		}
		cout << unreadCnt << '\n';
	}
	return 0;
}


http://www.codeforces.com/contest/705/problem/D
Reduction to TSP is easy. // tsp 유도화는 쉽다.
We need the shortest Hamiltonian path from 's' to 'e'.
// 해밀턴패스가 필요하다.(모든 정점을 한번씩 지나는 경로)
Consider the optimal answer. its graph is a directed path.
// 최적해를 상상해봐. 그건 그래프며 방향이 있는 패스야.
Consider the induced graph on first i chairs.
// i번째 의자로부터 유도 그래프를 만들어 보자구
In this subgraph, there are some components.

Each components forms a directed path. Among these paths, there are 3types of paths:

	1. In the future (in chairs in right side of i), 
		we can add vertex to both its beginning and its end.
	2. In the future (in chairs in right side of i),
		we can add vertex to its beginning but not its end(because its end is vertex e).
	3. In the future (in chairs in right side of i),
		we cannot add vertex to its beginning (because its beginning is vertex s)
		but we can add to its end.

There are at most 1 paths of types 2 and 3 (note that a path with beginning 's' and 
ending 'e' can only exist when all chairs are in the subgraph. i.e. induced subgraph
on all vertices).
// 해석이 개같아서 그냥 소스 보고 이해가 빠름.
// 일단 해밀토니안 경로를 구하는 것은 프로그래밍 문제를 벗어남.(조합탐색접근임 n! 이라)
// 해밀토니안 경로는 뭐로든 바로 구할 수 있는 조건이기에
// 그 중 가장 짧은 경로를 찾는건 복잡도 난이도가 해밀토니안 경로 구하는 것보다 훨신 낮음
// bigO (n^2) 임
// 한점씩 넣어버리면 됨. !!!!
ll sum;
ll mn, co;
int next[5005];
ll getC(int i, int j) {	// i번째 의자에서 j번째 의자로 이동 비용
	if (j < i)
		return labs(x[i] - x[j]) + c[i] + b[j]; // 왼쪽 이동
	else
		return labs(x[i] - x[j]) + d[i] + a[j]; // 오른쪽 이동
}
int main() {
	scanf("%d%d%d", &n, &s, &e);
	rep2(i,1,n+1) scanf("%I64d", &x[i]);
	rep2(i,1,n+1) scanf("%I64d", &a[i]);
	rep2(i,1,n+1) scanf("%I64d", &b[i]);
	rep2(i,1,n+1) scanf("%I64d", &c[i]);
	rep2(i,1,n+1) scanf("%I64d", &d[i]);
	next[s] = e;
	sum = gecC(s, e);
	rep2(i,1,n+1) {
		if (i != s && i != e) {
			mn = INF;
			for (int xi = s; xi != e; xi = next[xi]) {
				co = gecC(xi, i) - getC(xi, next[xi]) + getC(i, next[xi]); // 핵심!!!!
				if (co < mn) {
					mn = co;	// 작은 비용 갱신
					minP = xi;
				}
			}
			sum += mn;
			// minP ----> next[minP] 사이에 i를 집어넣자.
			next[i] = next[minP];	
			next[minP] = i;
			// minP ----> i ----> next[minP]
		}
	}
	printf("%I64d\n", sum);
}
7 4 3
i)	1	2	3	4	5	6	7	// index
x:	8	11	12	16	17	18	20
a:	17	16	20	2	20	5	13
b:	17	8	8	16	12	15	13
c:	12	4	16	4	15	7	6
d:	8	14	2	11	17	12	8

// start: 4, end: 3
// 4 ----> 3
최초: sum	= gecC(s, e) = gecC(4, 3) = labs(x[4]-x[3]) + c[4] + b[3]
			= labs(16-12) + 4 + 8 = 16
	
1번을 넣음 // 4 ----> 1 ----> 3	// next 형태
	co	= getC(xi, i) - getC(xi, next[xi]) + getC(i, next[xi]);
		= getC(4, 1) - getC(4, 3) + getC(1, 3);
		= (8+4+17) - (16) + (4+8+20)	= 29 - 16 + 32 = 45
	sum = sum + 29 - 16 + 32 = 61

2번을 넣음 
	// 4 ----> 1 사이에 넣음 : 4 ----> 2 ----> 1
	co	= getC(xi, i) - getC(xi, next[xi]) + getC(i, next[xi]);
		= getC(4, 2) - getC(4, 1) + getC(2, 1)
		= (5+4+8) - (8+4+17) + (3+4+17)	= 17 - 29 + 24	= 12 // 요게 더 비용이 작네
	
	// 1 ----> 3 사이에 넣음 : 1 ----> 2 ----> 3
	co	= getC(xi, i) - getC(xi, next[xi]) + getC(i, next[xi]);
		= getC(1, 2) - getC(1, 3) + getC(2, 3)
		= (3+8+16) - (4+8+20) + (1+14+20) = 20
	
	sum = sum + 12 = 73
	// 4 ----> 2 ----> 1 ----> 3 이 된다.

// 이런식으로 뒤에도 진행하면 됨


// 고찰 // tsp 에서 적용이 안되는 이유(counter example)
      
          e


          
1          2



    s

에서 최적해는

s ----> 1 ----> 2 ----> e 가 된다.

s ----> 1 ----> 2 ----> e 를 최적해로 두고 진행한다면
3 이 아래와 같이 위치한 상태면
s ----> 1 ----> 2 ----> e 사이에 3을 넣어도 죽어도 정답이 될수 없다. !!!!
"즉 3을 추가할시 진행되는 해는 s 2 1 e 서브시퀀스를 가질수가 없다는 말임"
          e


          
1          2
          
        3

    s
// 위의 진행 답은 s ----> 3 ----> 2 -----> 1 ----> e 가 된다.

" 2차원에선 통하지 않는가 보다..."
" 해밀토니안 패스를 윗 방식으로 구할수 있는 조건을 잘 느끼자 !!!!"
" 답을 진행중일 때 서브시퀀스를 유지할 수 있다면 tsp 인 경우에도 활용할 수 있다"
// 예를 들면 사이클이 없는 그래프에서 1에서 n으로 가는 길을 구해라 들은 윗방식 응용이 가능하다 !!!!"
"음... 잠깐 모든 정점을 들러야 하는게 아니라서 tsp 문제가 아니다. 오히려 shortest path 문제에 가깝군..."
ex)
http://codeforces.com/contest/721/problem/C
 The roads in Berlatov are designed in a way such that there are no cyclic routes between showplaces.
 // 정해진 길이 이하에서 최대한 많은 정점을 지나가게 하는 문제임 !!!! 좋다


http://codeforces.com/contest/701/problem/D
D. As Fast As Possible
n명의 학생이 여가를 함께 감
l 미터의 길을 가야함
각 개인은 v1 의 속도를 가짐
버스는 v2의 속도를 가지며 n 명 이하로 태울수 있음
각 학생은 한번만 버스를 탈 수 있음
 
"n명의 학생이 l 미터의 길에 도착하는데 걸리는 시간을 최소화 한 경우 그 시간은 얼마인가?"
5 10 1 2 5	// 5명학생, 10미터 길, 학생속도 v1:1, 버스속도 v2:2, 버스 인원수 5명
5.0000000000
 
 
This problem can be solved with formula or with help of the binary search.
Let`s describe the solution with binary search on the answer. 
If the target function of the binary search returns true we need to move in mid the right end of the search,
else we need to move in mid the left end of the search. 
The target function must works in the following way. 
 
Let`s divide all pupils on the groups, the number of the groups equals to
"(n + k - 1) / k", where n is the total number of pupils and k is the number of seats in the bus.
// 학생을 그룹화 하자, 그룹의 수는 n / k 를 소수점 자리를 버림한 거랑 같다. (n + k - 1) / k
 
Then for the current mid we know the minimal time which the first group of the pupils is
needed to ride on the bus to reach the finish point in the time mid.
// 첫번째 그룹이 도달에 걸리는 시간을 mid 로 가정
 
Then we need to solve simple equation and get that this time equals to 
T - (v2*T - (l - posM)) / (v2 - v1),	// 첫그룹도착시간 - (버스의 이동 거리) / (버스랑 학생간 속도차) : 첫그룹도착시간 - 첫그풉이버스타서 줄인시간
 
where for the first group T equals to mid,	// T는 시간단위
posM equals to 0 (in posM we will store the position of the pupils, who did not already rode on the bus).
T = mid
posM = 0
 
Than we need to accurate recalculate T and posM for every following group (do not forget that
the bus must returns back to get the other group). If for some group v2*T became less than 
l - posM or T became less than 0,
the target function must return false.
If all groups of pupils will reach the finish point in time mid the target function must return true.
Also do not forget that the bus does not need to ride back after it took to the needed point
the last group of the pupils.
"참고로 풀이 해석은 지랄같다고 사람들이 다들 동의함!!!!" 풀이는 보지 마라 차라리 아래 코드의 주석이 훨신더 잘 되어 있다.

//위 설명대로 구현된 소스
http://www.codeforces.com/contest/701/submission/19451211
" 핵심은 최적해일 때 그룹들의 통과 시간이 동일할 거란거다"
" 가상의 해를 넣고 그것과 비교한 결과해를 가지고 이분법을 취하는 특이한 형태임 "!!!!
" 덕분에 식만들기도 까다롭다."
" mid 와 timePassed 는 같은걸 의미할수 있기에 윗 영어문장이 더욱 좆같음을 느낄 수 있었다."
" 원어민도 GG치는 풀이였음 ㅠㅠ 개객기 개객기 개개기....ㅠㅠ
/*
	v2*busTime + v1*(mid - timePassed - busTime) = totalDist - v1*timePassed
	busTime*(v2-v1) + v1*(mid - timePassed) = totalDist - v1*timePassed
	busTime*(v2-v1) = totalDist - v1*timePassed - v1*(mid - timePassed)
					= totalDist - v1*mid
	busTime		=	(totalDist - v1*mid) / (v2 - v1)	// constant
	backBusTime =	busTime * (v2 - v1) / (v2 + v1)		// constant
*/

음... 내가 생각한 아래 방식이 더 쉬운디...
/*
	// 먼저 거리를 이동한 요소들로 나타낸다.
	v2*busTime + v1*(mid - busTime)	=	totalDist
	busTime*(v2 - v1) + v1*mid		=	totalDist
	busTime*(v2 - v1)				=	totalDist - v1*mid
	busTime		=	(totalDist - v1*mid) / (v2 - v1)	// constant
	backBusTime =	busTime * (v2 - v1) / (v2 - v1)		// constant
*/
int n, k, group;
double v1, v2, length;
int main() {
	cin >> n >> length >> v1 >> v2 >> k;
	group = (n + k - 1) / k;
	double lo = 0, hi = ((double)length) / ((double)v1);
	double timePassed = 0;
	while ((hi - lo) >= 5e-7) { // !!!! 좋은 표현이다.
		double mid = (lo + hi) / 2;	// mid 시간 이하로 학생들이 도착되는지 아라보자
		// 핵심은 최적해는 학생들이 모두 동시에 도달한다는 것이다.
		timePassed = 0;
		rep(i, group) {
			double busTime = (length - v1 * mid) / (v2 - v1); // 버스탄 시간
			timePassed += busTime;
			if (i + 1 < group) {
				// 버스가 다시 돌아가서 남은 그룹과 만나는데 걸리는 시간을 계산
				// 버스가 압지른 거리 (busTime * (v2 - v1)) 만큼 돌아가야함
				double backBusTime = busTime * (v2 - v1) / (v2 + v1);
				timePassed += backBusTime;
			}
		}
		if (timePassed <= mid) hi = mid; // 가정한 시간보다 실제 걸린 시간이 같거나 작다면 여유가 있다.
		else lo = mid;	// 가정한 시간보다 실제 걸린 시간이 더 크면 여유가 없으므로 증가시킨다.
	}
	printf("%.10lf\n", hi);
	return 0;
}

    Now, the current group has not gotten on the bus yet, so it has gone walkingSpeed*timePassed distance.
	We want it to go totalDist-walkingSpeed*timePassed more distance in order to complete the journey.
	If it goes on the bus for x seconds, it goes busSpeed*x distance and has mid-timePassed-x seconds left.
	In those last seconds, it can walk the rest, so it goes walkingSpeed*(mid-timePassed-x) distance.
	As we said in the second sentence, the total distance must be totalDist-walkingSpeed*timePassed 
	in order to complete the journey, so we have the following equation: 
	// 방정식을 만들어보자
		busSpeed*x + walkingSpeed*(mid-timePassed-x)	// 버스속력*버스탄시간 + 걷기속력 * (전체시간 - 버스가 그룹과 만나기까지 걸린 시간 - 버스탄시간)
			= busSpeed*x + walkingSpeed*(mid-x) - walkingSpeed*timePassed
			= totalDist-walkingSpeed*timePassed

	// 버스속력*버스탄시간 + 걷기속력 * (전체시간 - 버스가 걷는 그룹과 만나기까지 걸린 시간 - 버스탄시간)
	//	= 전체거리 - 걷기속력 * 버스가 걷는 그룹과 만나기까지 걸린 시간
	// => 식을 버스탄 시간(x)으로 맞추어 보자
	//	x * (busSpeed - walkingSpeed) + walkingSpeed * (mid - timePassed) = totalDist - walkingSpeed * timePassed
	//	x * (busSpeed - walkingSpeed) = totalDist - walkingSpeed*timePassed - walkingSpeed*(mid - timePassed)
	//	x * (busSpeed - walkingSpeed) = totalDist - walkingSpeed*mid
	//	x = (totalDist - walkingSpeed*mid) / (busSpeed - walkingSpeed)
" 신기하게도 timePassed 는 상쇄되어 버리네: 즉 각 그룹의 버스타는 시간 x는 항상 일정하다!!!!"
	Solve this equation for x to get:
		x=(totalDist-walkingSpeed*mid)/(busSpeed-walkingSpeed)

	This is how much time this group spends on the bus, so we add that to timePassed:


mid 는 우리가 가정해본 걸린 시간
완료된 timePassed 는 mid 로 값을 세팅한 다음 걸린 시간
"mid == timePassed 인 상태가 우리의 정답이여"

시뮬레이팅
		if (timePassed <= mid) hi = mid;	// 가정한 시간보다 실제 걸린 시간이 더 작으면 여유가 있다. -> 가정한 시간을 줄이자.
		else lo = mid;						// 가정한 시간보다 실제 걸린 시간이 더 크면 -> 가정한 시간을 늘리자	
v1: 1
v2: 4
length: 10
총시간 t: 4	//mid임
그룹은 하나만 있다고 가정함
lo = 0, hi = 8 이라 하고 시뮬

mid = (0 + 8) / 2 = 4
timePassed = (L - v1 * t) / (v2 - v1) = (10 - 1 * 4) / (4 - 1) = 2
timePassed < mid	lo = 0,		hi = 4

mid = 2
timePassed = (10 - 1 * 2) / (4 - 1) = 8 / 3
timePassed > mid	lo = 2,		hi = 4

mid = 3
timePassed = (10 - 1 * 3) / (4 - 1) = 7 / 3
timePassed < mid	lo = 2,		hi = 3

mid = 2.5
timePassed = (10 - 1 *2.5) / (4 - 1) = 7.5 / 3
timePassed == mid	lo = 2,		hi = 2.5

mid = 2.25
timePassed = (10 - 1*2.25) / (4 - 1) = ...
timePassed > mid	lo = 2.25,	hi = 2.5

mid = 2.235
...
timePassed > mid	lo = 2.235, hi = 2.5

계속 가면 lo는 hi값에 근접해진다.



 
공식으로 바로 풀기 
// http://codeforces.com/blog/entry/46283#comment-310597 의 Noble_Mushtak 댓글을 참고
x: busTime, y = backBusTime
length = v2*x + v1*(mid - x) = x*(v2-v1) + v1*mid

x = (length - v1*mid) / (v2 - v1)	// Since x is constant for each group, we adding y where:
y = x*(v2 - v1) / (v2 + v1) = (length - v1*mid) / (v2 + v1) // also constant

timePassed	= group*x + (group-1)*y
			= group*(length-v1*mid)/(v2-v1) + (group-1)*(length-v1*mid)/(v2+v1)
Now, we can complete the journey in under 'mid' seconds if and only if:
	"timePassed <= mid"
group*(length-v1*mid)/(v2-v1) + (group-1)*(length-v1*mid)/(v2+v1) <= mid
(length-v1*mid)*(group/(v2-v1) + (group-1)/(v2+v1)) <= mid

	let we have the following definition:
	c = (group/(v2-v1) + (group-1)/(v2+v1))

length - v1*mid <= mid / c
length <= mid(1/c + v1)
lentgh / (1/c + v1) <= mid	// length / (1/c + v1) : constant 임 따라서 게다가 mid 이하임
//그러니 답이된다.
// mid 는 좌항의 상수보다 크거나 같은수 중 가장 작은것이 되어야 하니 말이다.

int n, k, group;
double v1, v2, length;
int main() {
	cin >> n >> length >> v1 >> v2 >> k;
	group = (n + k - 1) / k;
	double c = (group / (v2 - v1) + (group - 1) / (v2 + v1));
	double sol = length / (1 / c + v1);
	printf("%.10lf\n", sol);
	return 0;
}

// 그래도 풀이법이 약간 거슬리긴 하다. mid 랑 걸리는 시간을 같도록 맞추어야 한다는 것만 기억하자.
// 이분법으로 풀땐 특정 mid 를 잡아서 그것의 결과가 큰지 이하인지를 보고 다음 mid를 설정 후 탐색하였다.
내맘대로 네이밍: 이런 이분 탐색을 "애돌이 이분 서치"라 하자. !!!!
	 자기 자신(mid)을 넣어서 나온 자신(timePassed)과 비교해서 자기자신(mid)을 
	 변경시킨다. ㅋ
고찰: 이런 유형의 문제들은 어떤식으로 출제될까?


http://codeforces.com/contest/701/problem/E
E. Connecting Universities
n개의 도시가 트리처럼 연결됨(당연히 n - 1개의 연결선이 있음)
게다가 연결선은 two-way 양방향임 즉 모든 도시는 어떠한 도시로든 갈 수 있다.
2k 만큼의 대학들이 있음(각각 다른 도시들에 위치함)
대통령이 대학들을 빠른속도의 네트워크로 연결되도록 법령을 만듬
교육부장관은 지맛에 해석하고 결정함: 각각의 대학은 다른 대학과 하나의 케이블로 연결되도록
// 대학이 두개의 케이블로 연결을 하면? 그런건 신경쓰지 않아도 된다고 보자
 
예산합을 최대화하기위해, 그 장관은 대학교들을 둘로 쪼개기로 함(전체 필요한 케이블 길이가 최대가 되기 위해)
//문장이해가 안되는 부분...// 대학교들을 쌍으로 연결을 시킨다는 것임!!!!
//k개의 연결쌍이 나오고 그것의 최대화를 해라는 것임.
//각 지점에 케이블이 겹치는 건 신경끄고
"각 대학교들을 쌍으로 선택시 그 대학교간 거리의 합의 최대값을 찾아라!"
 
 
장관을 도와서 최대 길이를 구하라.
 
input
7 2		// 도시수, 대학쌍 수
1 5 6 2 // u11, u12, u21, u22 - indices of towns in which universities are located
1 3		// 이후론 간선들: 도시수 - 1 만큼 옴
3 2
4 5
3 7
4 3
4 6
output
6
 
input
9 3
3 2 1 6 5 9
8 9
3 2
2 7
3 4
7 6
4 5
2 1
2 8
output
9

// 내 생각
// 아무점(대학)이나 선택후 그것과 가장 멀리있는 점(대학)을 매칭시킨다.
// 그렇게 하면 답이 될거라 생각... 음
// 그럴 필요 없구나...

http://codeforces.com/blog/entry/46283 에서 haleyk100198 이 사람이 쓴 글을 보삼
haleyk100198 소스
http://codeforces.com/contest/701/submission/19436598
"핵심 아이디어"
A ---- B ------ central ----- C ----- D
각 점 A, B, C, D 를 둘로 쪼개는는 지점으로 부터 거리를 계산하면 답이된다. !!!!
// tree이기 때문에 splitted 된다는것을 생각해서 코드를 짜면 된다.

bool has[200010];
vector<int> near[200010];
int n, k, best = INF;
ll res = 0;
int root1, root2;	// root2 : central point
int dfs1(int now, int prev) {	// central point를 찾는다.
	int cnt = has[now];
	rep(i,near[now].size()) {
		int x = near[now][i];
		if (x - prev) cnt += dfs1(x, now);
	}
	if (cnt >= k && cnt < best) {	
		root2 = now; best = cnt;
	}
	return cnt;
}
// central point 로 부터 각 대학간 거리를 더하면 답이 된다.
void dfs2(int now, int prev, int d) {	
	if (has[now]) res += 1LL * d;
	rep(i,near[now].size()) {
		int x = near[now][i];
		if (x - prev)
			dfs2(x, now, d + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;	// n: 마을수, k : 대학수/2
	rep(i,2*k) { int val; cin >> val; has[val] = true; }// 대학교 존재함
	rep(i,n-1) {
		int u, v; cin >> u >> v;
		near[u].pb(v); near[v].pb(u);
	}
	rep(i,n) {
		if (near[i].size() == 1) {
			root1 = i; break;
		}
	}
	int sink = dfs1(root1, -1);
	dfs2(root2, -1, 0);
	cout << res << endl;
	return 0;
}
central point 를 찾는 코드(dfs1) 에서
if (cnt >= k && cnt < best) { // 이 부분이 있는 이유
	root2 = now; best = cnt; 
}
central pt 에서 cnt는 3이 된다.
//				  univ pt
//					|
//					|
// univ pt ----- central pt ----- univ pt
//					|
//					|
//				  univ pt



에디토리얼 풀이: // 해설이 개같음을 인지하자.
Let`s root a tree with vertex 1 by single DFS and by the way find two values for
every vertex v:
	lv : length of the edge that leads from parent of v to vertex v;
	// v의 부모 점과 길이는 1밖에 안되는데 무슨 개소리냐? 1 맞음.. 필요도 없는 문장
	sv : the number of universities in the subtree of vertex v (including v itself).
	// v를 포함한 v의 서브트리내의 대학 개수

Consider any optimal solution, i.e. such solution that the total length is maximum.
Look at some edge that leads from the parent of v to v.
We claim that it should be used in
	"min(sv, 2*k-sv) paths."

It obviously cannot be used more time than this value, however, if it is used
less number of times, that means there is at least one connected pair
(let`s say a and b) located in the subtree of v and at least one connected pair
located outside (vertices c and d).

By the properties of the tree, paths from a to c and from b to d cover all edges
of the paths from a to b and from c to d plus some extra edges, meaning the
current answer is not optimal.

Thus, this edge will be used exactly min(sv, 2*k - sv) times.

The above means we can compute the answer values as 
	"sigma(v (- V){ min(sv, 2*k - sv) }"
Note that the above method doesn`t provide the optimal matching itself
(though, not many modifications required).

// 에디토리얼대로 풀어봄
vi graph[200020];
bool univ[200020];
ll ans;
int n, k;
ll dfs(int here, int prev) {
	// 자식 노드의 서브트리의 대학 개수랑
	// 그 이외 서브트리의 대학 개수랑 
	// 둘중 작은게 그 연결 간선을 지나가는 패스 쌍이 된다.
	ll ret = 0;
	if (univ[here]) 
		ret++;
	rep(i, graph[here].size()) {
		int a = graph[here][i];
		if (prev == a) continue;
		ll sub = dfs(a, here); // 대학개수
		ll add = min(sub, 2 * k - sub);
		ans += add;
		ret += sub;
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	rep(i, 2 * k) {
		int u;
		scanf("%d", &u);
		univ[u] = true;
	}
	int a, b;
	rep(i, n - 1) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int root = -1;
	for (int i = 1; i < n + 1; ++i) {
		if (graph[i].size() == 1)
			root = i;
	}
	ll test = dfs(root, -1);
	printf("%I64d", ans);
	return 0;
}



http://www.codeforces.com/contest/703/problem/C
int n;
double w, v, u;
vector<pair<double, double>> arr;
bool check(double t0) {
	int cntL = 0, cntR = 0;
	//y = (u/v) * (x - v*t0)
	rep(i, n) {
		double y = (u / v) * (arr[i].first - v * t0);
		if (y >= arr[i].second)
			cntL++;
		if (y <= arr[i].second)
			cntR++;
	}
	if (cntL == n || cntR == n)
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> w >> v >> u;
	arr.resize(n);
	rep(i, n) cin >> arr[i].first >> arr[i].second;
	double sol;
	if (check(0))
		sol = w / u;
	else {
		double lo = 0, hi = 1e+11;
		for (int iter = 0; iter < 100; ++iter) {
			double mid = (lo + hi) / 2;
			if (check(mid))
				hi = mid;
			else
				lo = mid;
		}
		sol = hi + w/u;
	}
	printf("%.10lf", sol);
	return 0;
}
// big(O) 가 n인 걸 계산하려면 폴리곤의 각 점에 대해 방정식을 돌리보자
y = (u / v) * (x - v*t0) 식을 t0에 대한 식으로 바꾸어 체크하자.
y = (u/v)*x - (u/v)*v*t0
y - (u/v)*x = - u*t0
u*t0 = -y + (u/v)*x
t0 = ((u/v)*x - y) / u
각점에 대하여 구해진 t0중 가장 큰 놈이 대기시간이 된다.
// 이동 직선에 대해 전부 왼쪽에 있는 상태거나 전부 오른쪽에 위치한 상태면
// 대기할 필요가 없다.

int n;
double w, v, u;
vector<pair<double, double>> arr;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> w >> v >> u;
	arr.resize(n);
	rep(i, n) cin >> arr[i].first >> arr[i].second;
	double sol;
	double minWait = 1e11;
	double maxWait = -1e+11;
	rep(i, n) {
		double cand = ((u / v)*arr[i].first - arr[i].second) / u;
		if (maxWait < cand) 
			maxWait = cand;
		if (minWait > cand) 
			minWait = cand;
	}
	double wait = maxWait;
	// 전부 오른쪽이거나, 전부왼쪽인 상황을 체크한다.
	if (minWait >= 0.0 || maxWait <= 0) wait = 0; // 애초 대기할 필요가 없다.
	sol = wait + w / u;
	printf("%.10lf", sol);
	return 0;
}



http://www.codeforces.com/contest/699/problem/B
// 크레이지 아케이드가 생각나게 하는 문제다.
// 쉬운거 같은데 의외로 체크할 상황이 많다.
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vs arr(n);
	rep(i, n) cin >> arr[i];
	vi raw(n);
	vi col(m);
	int starCnt = 0;
	rep(i, n) rep(j, m) {
		if (arr[i][j] == '*') {
			starCnt++;	raw[i]++;	col[j]++;
		}
	}
	bool judge = false;
	int r = 0, c = 0;
	rep(i, n) rep(j, m) {
		if (raw[i] + col[j] - 1 == starCnt) {
			r = i; c = j; judge = true;
		}
		// for check .*
		//			 *.
		else if (raw[i] + col[j] == starCnt && arr[i][j] != '*') {
			// arr[i][j] != '*' 가 없으면 엄한 곳을 답으로 체킹한다.
			// 유념해야 할 부분이다. !!!! 사소한것같지만 의외로 실수하기 쉬운부분
			r = i; c = j; judge = true;
		}
		if (judge) break;
	}
	if (judge || starCnt == 0) {	// '*' 가 하나도 없다며 무조건 예스다!!!!
		cout << "YES" << '\n';
		cout << r + 1 << " " << c + 1;
	}
	else cout << "NO";
	return 0;
}


!!!! 고찰
for (int i = 0; i < n*2; ++i) {
            for (int j = 0; j < n * 2; ++j) 
                //scanf("%d", &mat[i][j]); // 이거 vs는 잘되는데 
				//https://www.hackerrank.com/contests/world-codesprint-6/challenges/flipping-the-matrix 여기선 맛이가버리네..
                cin >> mat[i][j];
        }

//ios_base::sync_with_stdio(false); // 이걸 주석처리하니까 scanf 값이 받아짐
//ios::sync_with_stdio(false);		// 이것 있어도 오류나서 mat가 0으로만 세팅되어 있음
    int cs, n;
    cin >> cs;
    for (int cc = 0; cc < cs; ++cc) {
        cin >> n;
        for (int i = 0; i < n*2; ++i) {
            for (int j = 0; j < n * 2; ++j) {
                scanf("%d", &mat[i][j]);
                printf("%d ", mat[i][j]);   
                //cin >> mat[i][j];
            }
            printf("\n");
        }
    ...
"ios_sync_with_stdio(false); 를 넣을땐 scanf를 쓰지 말자.. hackkerrank.com 에선 문제 있어 보인다."


https://www.hackerrank.com/contests/world-codesprint-6/challenges/bonetrousle
const long long INF = 1LL << 62;
//const long long INF = (1e+18) + 10; // 이렇게 해도 1000000000000000000 으로 설정됨.. 
//망할 부동소수표현을 방지하려면
//const long long INF = (long long)(1e+18) + 10; // 요렇게 하삼 !!!!
long long n;	// n: the number of sticks to buy
long long b;	// b: select
long long k;	// k: the number of boxes the store has for sale
long long check() {
	long long sum1 = 0;
	for (long long i = 1; i <= b; ++i)
		sum1 += i;
	//sum1 = b * (b + 1) / 2;
	long long sum2 = 0;
	for (long long i = k - b + 1; i <= k; ++i) { // 시불 여기에 int i = ~~ 해서 계속 틀렸음 !!!!
		sum2 += i;
		if (sum2 >= INF) {
			sum2 = INF;
			break;
		}
	}
	if (sum1 <= n && n <= sum2) return n - sum1;
	return -1;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	//freopen("input.txt", "r", stdin);
	int cs;
	cin >> cs;
	for (int cc = 0; cc < cs; ++cc) {
		cin >> n >> k >> b;
		long long diff = check();
		if (diff == -1)
			cout << "-1";
		else {
			long long i;
			for (i = b; i >= 1; --i) {
				if (i + diff <= k) {
					if (i != 1) {
						printf("%lld ", i + diff);
					} else
						printf("%lld", i + diff);
					--i;
					break;
				}
				else {
					diff -= (k - i);
					if (i != 1) {
						printf("%lld ", k);
					} else
						printf("%lld", k);
					
					k--;
				}
			}
			for (; i >= 1; --i) {
				if (i != 1) {
					printf("%lld ", i);
				} else
					printf("%lld", i);
			}
		}
		printf("\n");
	}
	return 0;
}


http://codeforces.com/contest/711/problem/C //
const long long INF = 1LL << 48; //!!!! 범위 땜시로 이정도로 해줘야 함. 넘크게 잡아도 안됨..
//const long long INF = (1e+18) + 10; // 이렇게 해도 1000000000000000000 으로 설정됨.. 망할 부동소수표현
ll parr[101][101];
ll tree[101];
long long cache[102][101][101];
int n, m, k;
ll rec(int prevC, int index, int remainG) {
	if (index == n) {
		if (remainG > 0) return INF;
		else if (remainG == 0) 
			return 0;
	}
	if (remainG < 0) return INF;
	ll& ret = cache[prevC][index][remainG];
	if (ret != -1) return ret;
	ret = INF;
	if (prevC == tree[index]) {
		ret = min(ret, rec(prevC, index + 1, remainG));
	}
	else {
		if (tree[index] == 0) {
			rep2(i,1, m + 1) {
				ll cand;
				if (prevC == i)
					cand = rec(prevC, index + 1, remainG) + parr[index][i - 1];
				else
					cand = rec(i, index + 1, remainG - 1) + parr[index][i - 1];
				ret = min(ret, cand);
			}
		}
		else if (prevC != tree[index]) {
			ll cand;
			cand = rec(tree[index], index + 1, remainG - 1);
			ret = min(ret, cand);
		}
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	rep(i, n) cin >> tree[i];
	rep(i, n) rep(j, m) cin >> parr[i][j];
	ll sol = rec(101, 0, k);
	if (sol >= INF || sol == -1)
		cout << -1;
	else
		cout << sol;
	return 0;
}


http://codeforces.com/contest/711/problem/D
n towns numbered from 1 to n.
n directed roads (i번 도로는 i번 마을에서 시작해서 다른 마을에 도착)
도로들이 사이클을 만들면 confusing 이라 한다.
원하는 만큼 도로들을 선택하여 반전 시키는 경우 not confusing이 이루어질수 있다.
(애초에 not consfusing 이더라도 상관없다.)
이렇게 해주는 경우의 수를 구하라
the number of ways to flip some set of the roads 를 구하라
물론 수가 매우 클태니 (int)(1e+9) + 7 로 나눈 나머지를 구하라

각 도로 마다 반전은 딱 한번하는거고
이경우 모든 경우의 수는 2^n 개가 발생한다.
그중 사이클이 없는 경우를 찾으면 된다.

2 <= n <= 2*10^5


입력시 각 도시마다 뻗는건 하나 뿐이다.
따라서 크게 본다면
포리스트들은 이런 모양이 될 것이다.
"한 정점마다 밖으로 나가는 간선이 하나만 있는 그래프의 특성은"
"포리스트들은 반드시 한개뿐인 사이클이 있고 그건 외각에 위치한다.!!!!"
"마치 콩나물 대가리처럼 말이지"

내 생각 풀이는
들어오는 게 없는 도시를 체크하고
들어오는게 2개인 도시를 체크한다.
들어오는게 없는 도시로 부터 들어오는게 2개인 도시까지의 간선수를 k라 한다면
2^k 개 만큼 조합으로 바꾸어도 사이클은 안 발생한다.
그리고 2개인 도시부터 사이클을 이루는 간선 수를 t 란 한다면
2^t - 2 만큼의 조합으로 사이클은 안 발생한다.
이 두개의 곱인 2^k * (2^t - 2) 가 한 포리스트의 not confusing 경우의 수가 된다.

다른 포리스트들도 구해서 각각을 곱해주면 답이 된다.



const int INF = 1e9 + 7; const int MOD = 1e9 + 7; const int N = 1e6 + 3;
int a[N]; int vstd[N];
ll ans;
vi cycles;
ll dp[N];
int cycleCnt;
void dfs2(int u) {
	cycles[cycleCnt]++;
	vstd[u] = 3;
	if (vstd[a[u]] == 3) return;
	dfs2(a[u]);
}
void dfs(int u) {
	vstd[u] = 2;
	if (vstd[a[u]] == 0)
		dfs(a[u]);
	else if (vstd[a[u]] == 1) {
		vstd[u] = 1;
		return;
	} else {
		cycles.push_back(0);
		dfs2(u);
		cycleCnt++;
	}
	vstd[u] = 1;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) dp[i] = (dp[i - 1] * 2LL) % MOD;
	ans = 1;
	memset(vstd, 0, sizeof(vstd));
	for (int i = 1; i <= n; ++i) if (vstd[i] == 0) dfs(i);
	ll cnt = n;
	for (int i = 0; i < cycles.size(); ++i) {
		cnt -= cycles[i];
		ans = (ans * (dp[cycles[i]] - 2 + MOD)) % MOD;
	}
	ans = (ans * dp[cnt]) % MOD;
	if (ans < 0) ans += MOD;
	int ans2 = ans;
	printf("%d\n", ans2);
	return 0;
}


https://www.hackerrank.com/contests/infinitum16/challenges/hyperspace-travel
// 중앙값의 중요성을 알수 있는 문제다.
// 편차의 최저치는 평균이 아닌 중앙값이 된다. !!!!
// 분산, 표준편차의 최저치는 평균일때 된다. 


https://www.hackerrank.com/contests/infinitum16/challenges/divisor-exploration
// 공식 유도가 힘들었다...
const int MOD = 1000000007;
const int maxN = 100001;
long long dp[200200];
void precalc() {
	long long sum = 1;
	dp[1] = 1;
	for (int i = 2; i < maxN + maxN + 1; ++i) {
		sum += i;
		sum %= MOD;
		dp[i] = (dp[i - 1] * sum) % MOD;
	}
}
long long fast_pow(long long base, long long n, long long M) {
	long long ret = 1;
	for (; n; n /= 2) {
		if (n & 1) ret = (ret * base) % M;
		base = (base * base) % M;
	}
	return ret;
}
long long findMMI_fermat(long long n, long long M) { return fast_pow(n, M - 2, M); }
long long solve(long long m, long long a) {
	long long rangeL, rangeR;
	rangeL = a + 2;
	rangeR = a + m + 1;
	rangeL--;
	long long mulR = dp[rangeR];
	long long mulL = dp[rangeL];
	long long inv = findMMI_fermat(mulL, MOD);
	long long ret = (mulR * inv) % MOD;
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	precalc();
	int cs;	cin >> cs;
	for (int cc = 0; cc < cs; ++cc) {
		long long m, a;
		cin >> m >> a;
		long long sol = solve(m, a);
		cout << sol << '\n';
	}
	return 0;
}
// 문제 정의
약수의 약수의 갯수의 총합을 구하는 문제
먼저 숫자 n은 두 숫자 m, a로 나타낼 수 있다.
	n = ㅠ[i=1, m]{pi^(a+i)}, where pi is the ith prime
	예시로 m = 2, a = 0 인 경우
	n = 2^(0+1) + 3^(0+2) = 18 이 된다.
	18의 약수는
		1, 2, 3, 6, 9, 18 이 된다.
	각 약수별 약수의 갯수는
		1, 2, 2, 4, 3, 6 이 된다.
	이것의 합이 출력값이 된다( 물론 크기가 엄청 크기 때문에 1000000009 로 나눈 나머지를 취함)

// 공식 유도
n = 2^1 * 3^2 형태를 가지고 약수갯수를 추측해보자
	(0+1)(0+1) = 1	// 1
	(1+1)(0+1) = 2	// 2
	(0+1)(1+1) = 2	// 3
	(1+1)(1+1) = 4	// 6
	(0+1)(1+2) = 3	// 9
	(1+1)(1+2) = 6	// 18
즉 output = sigma[i,0,1]sigma[j,0,2]{ (i + 1)(j + 1) } 이 된다.

m: 소수의 숫자갯수
a: 지수승의 시작이 된다.
따라서 일반화 시키면
	output = sigma[i,0,a+1] sigma[j,0,a+2] ... sigma[x,0,a+m] { (i+1)(j+1)...(x+1) }
	// i 에 해당하는 놈들을 밖으로 빼보자
	(1+2+3+...+ a+2) * {sigma[j,0,a+2] ... sigma[x,0,a+m] { (j+1)...(x+1) }
	// 다른것도 다 유도하면
	(1+2+3+...+ a+2) * (1+2+3+...+ a+3) * (1+2+3+...+ a+4) *...* (1+2+3+...+ a+m+1)
	
	일반화 시키면
		a, m 에 대하여
		ㅠ[i, a+1+1, a+m+1] { sigma[j,1,i] } 가 된다. 
	부분곱 형태를 활용하자
		output = ㅠ[i,2,a+m+1]{sigma[j,1,i] } * inv(ㅠ[i,2,a+2 - 1] {sigma[j,1,i]} )
	inv는 페르마의 소정리및 거듭제곱가속화로 빠르게 구할수 있다.
	또한 부분곱은 미리 정의가 가능하다.









http://codeforces.com/contest/707/problem/C
C. Pythagorean Triples // google 에서 검색하면 설명을 볼수 있네(wiki)
한변이 주어질때 나머지 두변을 구하는 문제
주어진 변 크기: (1 <= n <= 10^9)
나머지 두 변들의 크기: (1 <= m, k <= 10^18)
용어: http://elsenaju.eu/Arithmetic/Trigonometry.htm
kathete : 빗변을 제외한 변
hypotenuse : 빗변
Note that the side which length is specified can be a cathetus as well as hypotenuse.
//길이로 주어진 변은 삼각형의 세변중 하나다.

// 내 고민: 나머지 변들이 10^18을 넘기지 않을까 하는 무서움... 그럴 필요가 없네..!!!!
int main() {
	ll a, b, n;
	cin >> n;
	if (n <= 2)
		cout << "-1" << "\n";
	else if (n % 2 == 1) {
		n = pow(n, 2);
		a = (n + 1) / 2;
		b = (n - 1) / 2;
	} else {
		n = (po2(n, 2);
		a = (n + 4) / 4;
		b = (n - 4) / 4;
	}
	printf("%lld %lld\n", b, a);
}
a^2 = b^2 + c^2
	// c = n 이라 두면 n^2 = a^2 - b^2
	n^2 = (a - b) * (a + b)
		1. n이 홀수면 n^2 은 홀수가 되고 (a - b), (a + b) 둘다 홀수가 되어야 한다.
		이때 (a - b) 가 1이라 가정하면 (a + b) = n^2 이 된다.
		적당히 a, b 를 나눈다면
			a = n^2 / 2, b = n^2 / 2 꼴에서
			"a, b는 달라야 하고 n^2은 홀수이므로 두개에서 1씩을 더하고 빼자
			a = (n^2 + 1) / 2, b = (n^2 - 1) / 2
		2. n이 짝수면 n^2은 짝수가 된다 여기서 (a - b)가 2라고 가정한다면
		(a + b) 는 2를 인수로 가져야 한다.
		(a - b) 를 2라 가정한다면 
			(a - b) * (a + b) = n^2
			2 * (a + b) = n^2
			(a + b) = n^2 / 2
				적당히 a, b를 나눈다면
				a = (n^2/2)/2,	b = (n^2/2)/2
				"a, b는 달라야 하고 n^2 은 적어도 4는 약수로 가짐
				a = (n^2+4)/4,	b = (n^2-4)/4
	" 물론 n 이 1,2인 경우는 답이 없다.

http://codeforces.com/contest/707/problem/D
D. Persistent Bookcase //영구 책장: 유용할거 같은 문제다!!!!
입력
1 i j : 책을 책장의 i 높이의 j 번째 위치에 놓는다. // 2차원 board 생각하면 됨
		// 물론 놓을수 있는건 최대 한개니 없는 공간일때만 추가할 수 있따.
2 i j : 책장의 i높이의 j번째 위치의 책이 하나 존재할 경우 제거한다. // 물론 여러개 있을수 없지
3 i	  : i 번째 높이의 책들을 반전시킨다.
		.#.	// 에서 1번째 높이를 반전시키면	#.#
		..#									..#
		##.									##.
4 k	  : 과거 스텝으로 돌아간다. k operation 이 수행한 상태로 돌아가야함
		// 예를 들면 k 가 0이면 최초상태임
input
4 2 6
3 2
2 2 2
3 3
3 2
2 2 2
3 2

..		..		..		..		..		..
##		#.		#.		.#		..		##
..		..		##		##		##		##
..		..		..		..		..		..

output
2
1
3
3
2
4

책장크기 n, m (1 <= n, m <= 10^3)
질의 q (1 <= q <= 10^5)

const int MAX = 1e3 + 10, MAXQ = 1e5 + 5;
bitset<1010> books[MAX], dummy;
int shelves[MAX], sum;
int n, m, q, Q[MAXQ], U[MAXQ], V[MAXQ], ans[MAXQ];
vector<int> g[MAXQ];
void dfs(int u) {
	ans[u] = sum;
	for (auto v: g[u]) {
		if (Q[v] == 1) {
			if (!books[U[v]][V[v]]) {
				sum++;	shelve[U[v]]++;	books[U[v]][V[v]] = 1;
				dfs(v);
				sum--;	shelve[U[v]]--;	books[U[v]][V[v]] = 0;
			} else dfs(v);
		} else if (Q[v] == 2) {
			if (books[U[v]][V[v]]) {
				sum--;	shelve[U[v]]--;	books[U[v]][V[v]] = 0;
				dfs(v);
				sum++;	shelve[U[v]]++;	books[U[v]][V[v]] = 1;
			} else dfs(v);
		} else if (Q[v] == 3) {
			sum -= shelve[U[v]];	shelve[U[v]] = m - shelve[U[v]];
			sum += shelve[U[v]];
			books[U[v]] ^= dummy;	// 반전용 !!!! bitset 이 이런게 되군
			dfs(v);
			sum -= shelve[U[v]];	shelve[U[v]] = m - shelve[U[v]];
			sum += shelve[U[v]];
			books[U[v]] ^= dummy;
		} else
			dfs(v);	// 아무것도 안함. books는 변홤없다. 이 부분은  ans[u] 를 위해서다.
	}
	//자식이 없으면 조상은 또다른 자식을 찾게 된다. 그 부분이 과거 books로 이동인 거다.
}
int main() {
	scanf("%d %d %d", &n, &m, &q);
	rep(i,1001) dummy.set(i,1);
	sum = 0;
	for (int i = 1; i <= q; ++i) {
		scanf("%d %d", Q+i, U+i);
		if (Q[i] <= 2) scanf("%d", V + i);	// 1: 책넣기, 2: 책빼기
		if (Q[i] == 4) g[U[i]].push_back(i);	// 4: 상태롤백(물론 노드는 다름: 이게 햇갈렸음)
			// 롤백상태가 부모 노드며, 자식노드는 롤백상태를 그대로 가져간다.
		else g[i - 1].push_back(i);	// 1, 2, 3 이면 바로 앞이 부모노드이며 부모 상태
	}
	dfs(0);
	for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
	return 0;
}

4 2 7
3 2		//1: 2행을 반전시킨다.
2 2 2	//2: 2행 2열의 책을 지운다
3 3		//3: 3행을 반전시킨다.
3 2		//4: 2행을 반전시킨다.
2 2 2	//5: 2행 2열의 책을 지운다.
3 2		//6: 2행을 반전시킨다.
4 1		//7: 1번 상태로 돌아간다.
4 7		//8: 7번 상태로 돌아간다: 
"상태 되돌리기 명령도 카운팅에 포함된다.!!!!(이걸 인식 못해서 어려웠음)"
	0
	|
	|3
	1---
	|	\
	|2	 \ //(4, 1) 로 인해 추가된 분기
	2	  7 // 7번 노드는 1번 노드의 상태랑 동일하다.
	|	   \	
	|3		\
	3		 8
	|
	|3
	4
	|
	|2
	5
	|
	|3
	6

// bitset 공부
#include <bitset>
int main() {
	ios::sync_with_stdio(false);
	bitset<8> bit;
	bit.set();
	bit.reset();
	int bitsize = (int)bit.size();
	bool bAny = bit.any();	// 하나라도 1이면 true: 여기선 false
	bit.set(0, true);
	bAny = bit.any();	// true

	bit.set();
	bool bNone = bit.none();	// 하나라도 1이면 false: 여기선 false
	bit.set(0, false);
	bNone = bit.none();	// false
	bit.reset();
	bNone = bit.none(); // true

	bit.set(0, true);	// {1, 0, 0, 0, 0, 0, 0, 0 }
	bit.set(2, true);	// {1, 0, 1, 0, 0, 0, 0, 0 }

	bit.flip(4);		// {1, 0, 1, 0, 1, 0, 0, 0 }
	bit.flip();			// {0, 1, 0, 1, 0, 1, 1, 1 }
	bool bFlag = bit.test(3);	// true
	bFlag = bit[5];	// true

	int setcount = (int)bit.count(); // 5 : 1로 set 된 비트 갯수

	bit = 0x01;	// {1, 0, 0, 0, 0, 0, 0, 0 } !!!!주의 거꾸로임

	bit = 0xF0; // {0, 0, 0, 0, 1, 1, 1, 1 } // 인덱스가 뒤로 갈수록 높은 자리임

	string strBits = bit.to_string();	// "11110000"	// 앞의 인덱스는 낮은 자리임
	int nBitVal = bit.to_ulong();	// 240
	return 0;
}

// 얼마 안걸림: 270ms로 통과함
// 반전연산은 수행은 많으나 간단해서 그런거 같다.
const int MX = 1010, MXQ = 100010;
bool books[MX][MX];
int sum;
int n, m, q, Q[MXQ], Y[MXQ], X[MXQ], sol[MXQ];
vector<int> graph[MXQ];
void dfs(int here) {
	sol[here] = sum;
	rep(i, graph[here].size()) {
		int there = graph[here][i];
		if (Q[there] == 1) {
			if (!books[Y[there]][X[there]]) {
				sum++;	books[Y[there]][X[there]] = 1;
				dfs(there);
				sum--;	books[Y[there]][X[there]] = 0;
			}
			else dfs(there);
		}
		else if (Q[there] == 2) {
			if (books[Y[there]][X[there]]) {
				sum--;	books[Y[there]][X[there]] = 0;
				dfs(there);
				sum++;	books[Y[there]][X[there]] = 1;
			}
			else dfs(there);
		}
		else if (Q[there] == 3) {
			int rowSum = accumulate(&books[Y[there]][1], &books[Y[there]][1] + m, 0); //!!!!
			int invSum = m - rowSum;
			sum -= rowSum; sum += invSum;
			rep2(i, 1, m + 1)	// 여기에서 1000번 수행이 되고 쿼리가 10만번이니 bigO : 1억.. 아슬아슬이라 생각했지만 233ms로 통과됨
				if (books[Y[there]][i]) books[Y[there]][i] = false;
				else books[Y[there]][i] = true;
				dfs(there);
				sum -= invSum; sum += rowSum;
				rep2(i, 1, m + 1)
					if (books[Y[there]][i]) books[Y[there]][i] = false;
					else books[Y[there]][i] = true;
		}
		else
			dfs(there);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> q;
	sum = 0;
	rep2(i, 1, q + 1) {
		scanf("%d%d", Q + i, Y + i);
		if (Q[i] <= 2) scanf("%d", X + i);
		if (Q[i] == 4) graph[Y[i]].push_back(i);
		else graph[i - 1].push_back(i);
	}
	dfs(0);
	rep2(i, 1, q + 1) printf("%d\n", sol[i]);
	return 0;
}





http://codeforces.com/contest/703/problem/D
n개의 음이 아닌 정수 a1, a2, ..., an
쿼리:
	a. 범위가 주어진다. l, r (1 <= l <= r <= n)
	b. 해당범위안에서 짝수번 나타난 숫자가 있으면 출력한다.
	c. XOR-sum of written down integers is calculated, and this value is the answer
		for a query.
		Formally, if integer written down in point 2 are x1, x2, ..., xk then Mishka
		wants to know value x1^x2^...^xk, where ^ - operator of exclusive bitwise OR

input
7
1 2 1 3 3 2 3
5
4 7		// 같은 숫자가 짝수개인게 없으니 0
4 5		// 3이 2개 : 3
1 3		// 1이 2개 : 1
1 7		// 1이 두개, 2가 두개 1^2 = 3
1 5		// 1이 두개, 3이 두개 1^3 = 2

// xor sum의 성격

1 = 001,  2 = 010,   3 = 011,   4 = 100,   5 = 101,   6 = 110  

 1^2          = 1^2  = 001^010 = 011 = 3  
(1^2)^3       = 3^3  = 011^011 = 000 = 0
(1^2^3)^4     = 0^4  = 000^100 = 100 = 4
(1^2^3^4)^5   = 4^5  = 100^101 = 001 = 1
(1^2^3^4^5)^6 = 1^6  = 001^110 = 111 = 7 --> XOR sum

그냥 각 자리의 비트 수의 합이 짝수면 0, 홀수면 1이라 생각해도 된다.
"게다가 중요한 성질중 하나가 부분합처럼 이용해서 계산이 가능하다는 것이다"
3^4^5 = (1^2^3^4^5)^(1^2) 가 된다. 짝수면 0이 되는 성질을 이용한 것이다!!!!


"질문은 범위내에서 짝수번 나온 수들의 xor을 구하는 것이다"
	a) 홀수번 나온 수들의 xor을 구하는 것은 그냥 부분합처럼 구하면 된다. 간단함
	b) 짝수번 나온 수들의 xor Sum =
		"현재까지 나온 숫자들을 한번씩만 xor Sum - 홀수번 나온 수들의 xor sum"

// 핵심은 distinct 한 숫자들을 기록하려면 맨 우측 놈만 기록한 뒤
// 맨 범위 구간이 우측이 작은 쪽부터 정렬한 상태로 만든 뒤 순회한다면
" 범위의 왼쪽 바깥 구간에서 중복될수 있는 숫자를 걱정하지 않아도 된다는 것이다!!!! 핵심"

7
1 2 1 3 3 2 3
5
4 7		// i: 0		l: 3	r: 6	// bucket[6].push_back(0)
4 5		// i: 1		l: 3	r: 4	// bucket[4].push_back(1)
1 3		// i: 2		l: 0	r: 2	// bucket[2].push_back(2)
1 7		// i: 3		l: 0	r: 6	// bucket[6].push_back(3)
1 5		// i: 4		l: 0	r: 4	// bucket[4].push_back(4)

index	0	1	2	3	4	5	6
		1	2	1	3	3	2	3
		1
		1 ^ 2
			2 ^ 1	-------------	ans[bucket[2][0]] = ans[2] = bit.query(2)^bit.query(0-1) ^ sum[2]^sum[0-1]	// 소스에선 음수 인덱스가 허용 안되서 sum[3]^sum[0] 임
			2 ^ 1 ^ 3
			2 ^ 1     ^ 3	-----	ans[bucket[4][0]] = ans[1] = bit.query(4)^bit.query(3-1) ^ sum[4]^sum[3-1]
							-----	ans[bucket[4][1]] = ans[4] = bit.query(4)^bit.query(0-1) ^ sum[4]^sum[0-1]
				1	  ^ 3 ^ 2
				1		  ^ 2 ^ 3	ans[bucket[6][0]] = ans[0] = bit.query(6)^bit.query(3-1) ^ sum[6]^sum[3-1]
									ans[bucket[6][1]] = ans[3] = bit.query(6)^bit.query(0-1) ^ sum[6]^sum[0-1]


int main() {
	int n; cin >> n;
	vi a(n);
	rep(i,n) scanf("%d", &a[i]);
	vi sum(n + 1);
	rep(i,n) sum[i + 1] = sum[i] ^ a[i];
	int m; cin >> m;
	vi l(m), r(m);
	vvi bucket(n + 1);
	rep(i,m) {
		scanf("%d %d", &l[i], &r[i]);
		l[i]--; r[i]--;
		bucket[r[i]].push_back(i);
		
	}
	vi ans(m);
	map<int, int> pos;
	BIT bit(n + 10);
	rep(i,n) {
		if (pos.count(a[i])) // a[i] 값이 현재 들어 있다면(포지션이 있다면)
			bit.update(pos[a[i]], a[i]);
		pos[a[i]] = i;	// a[i] 의 위치를 기록
		bit.update(pos[a[i]], a[i]);
		for (int j : bucket[i])
			ans[j] = bit.query(r[j]) ^ bit.query(l[j] - 1) ^ sum[r[j] + 1] ^ sum[l[j]];
	}
	rep(i,m) printf("%d\n", ans[i]);
}
struct BIT {
	vi bit;
	BIT(int n) : bit(n) {}
	void update(int k, int v) {
		for (k++; k < bit.size(); k += k & -k) bit[k] ^= v;
	}
	int query(int k) {
		int res = 0;
		for (k++; k > 0; k -= k & -k) res ^= bit[k];
		return res;
	}
};


// 다른 식으로 짠거: 1543ms 걸림: 위보단 빠를듯
// http://codeforces.com/contest/703/submission/19664319
// 맵을 안쓰고 매핑하는 부분은 눈여겨 볼만하다 !!!! 외우자 응용많이 된다.
const int N = 2e6+5;
int n, m, a[N], b[N], l[N], r[N], last[N];
ll ans[N];
ll pre[N];
vi v, q[N];
ll bit[N];
void add(int p, int v) { while (p <= N) bit[p] ^= v, p += p & -p; }
ll query(int p) {
	ll sum = 0;
	while (p) sum ^= bit[p], p -= p & -p;
	return sum;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]), pre[i] = pre[i-1]^a[i], v.pb(a[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; ++i)
		// b[i] = a[i] 가 v[]의 몇번째에 해당하는가(맵역할을 하도록)
		b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;	// 굳이 +1 할 필요는 없을듯..
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d%d", &l[i], &r[i]), q[r[i]].pb(i);
	for (int i = 1; i <= n; ++i) {
		if (last[b[i]]) add(last[b[i]], a[i]);	// a[i]가 이전에 출현 했으면 없앰
		last[b[i]] = i;	// a[i]가 출현한 위치를 기록
		add(last[b[i]], a[i]);
		for (int j = 0; j < q[i].size(); ++j) {
			int k = q[i][j];
			ans[k] = query(r[k])^query(l[k] - 1) ^ pre[r[k]]^pre[l[k]-1];
		}
	}
	rep(i,m) printf("%lld\n", ans[i]);
	return 0;
}
index		0	1	2	3	4	5	6
a[i]		1	2	1	3	3	2	3

index		0	1	2	3
v[]			1	2	3	4	// a[i]의 숫자중 중복 제외되고 정렬 됨

index		0	1	2	3	4	5	6
a[i]		1	2	1	3	3	2	3
b[i]		0	1	0	2	2	1	2	// a[i] 값에 대응하는 v[]위치를 기록!!!! ... 실제론 +1 해졌음..
last[b[i]]
	last[0]:0
		last[1]:1
			last[0]:2
				last[2]:3
					last[2]:4
						last[1]:5
							last[2]:6

// 윗소스를 내식대로 수정한거. 가독성용 1622ms 걸림
const int maxn = 1e6 + 2;
int bit[maxn];
int n;
void add(int p, int v) { while (p <= n) bit[p] ^= v, p += p & -p; }
int query(int p) {
	int sum = 0;
	while (p) sum ^= bit[p], p -= p & -p;
	return sum;
}
int main() {
	//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	vi a(n + 1), psum(n+1), my(n + 1);
	vi uni;
	rep2(i, 1, n + 1) scanf("%d", &a[i]), psum[i] = psum[i - 1] ^ a[i], uni.pb(a[i]);
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	rep2(i, 1, n + 1)	// my는 uni로 매핑되어 있다.
		my[i] = lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin();
	int m;	scanf("%d", &m);
	vi l(m), r(m), sol(m);
	vvi bucket(n + 1);
	vi last(n+1);
	rep(i, m) scanf("%d%d", &l[i], &r[i]), bucket[r[i]].pb(i);
	rep2(i, 1, n + 1) {
		if (last[my[i]]) add(last[my[i]], a[i]);
		last[my[i]] = i;	// uni 가 출현한 맨 오른쪽 위치를 기록
		add(last[my[i]], a[i]);
		rep(j, bucket[i].size()) {
			int k = bucket[i][j];
			sol[k] = query(r[k]) ^ query(l[k] - 1) ^ psum[r[k]] ^ psum[l[k] - 1];
		}
	}
	rep(i, m) printf("%d\n", sol[i]);
	return 0;
}

// 깔끔하게 수정한거: 2495ms 걸림(제한 3.5초)
// cin, cout 쓰면 초반부터 tle 걸림 ㅠㅠ.. (백만개 입력은 크구냥..)
struct BIT {
	vi bit;
	BIT(int n) : bit(n + 1) {}
	void add(int pos, int val) {
		for (pos++; pos < bit.size(); pos += pos & -pos) bit[pos] ^= val;
	}
	int sum(int pos) {
		int ret = 0;
		for (pos++; pos > 0; pos -= pos & -pos) ret ^= bit[pos];
		return ret;
	}
};
int main() {
	//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vi a(n);
	rep(i, n)
		//cin >> a[i];
		scanf("%d", &a[i]);
	vi sum(n);
	sum[0] = a[0];
	rep2(i, 1, n) sum[i] = sum[i - 1] ^ a[i];
	int m; cin >> m;
	vi left(m), right(m);
	vvi bucket(n);
	rep(i, m) {
		//cin >> left[i] >> right[i];
		scanf("%d%d", &left[i], &right[i]);
		left[i]--; right[i]--;
		bucket[right[i]].push_back(i); // !!!! 좋은 표현
	}
	vi sol(m);
	map<int, int> last; // 해당값이 마지막에 위치한 인덱스를 기록한다.
	BIT bit(n);
	rep(i, n) {
		if (last.count(a[i]))	// a[i] 값이 현재 포함되어 있다면 그 놈을 일단 제거
			bit.add(last[a[i]], a[i]);	// : 그보다 오른쪽에 있는 놈을 기록하기 위해서다
		last[a[i]] = i;	// 현재 진행중 같은 수들 중 가장 오른쪽에 있는 수의 위치를 기록
		bit.add(last[a[i]], a[i]);
		// i(right) 를 가지는 질의가 있다면
		for (int j = 0; j < bucket[i].size(); ++j) {
			int qr = bucket[i][j];
			int distinctXSum = bit.sum(right[qr]) ^ bit.sum(left[qr] - 1);
			int oddXSum = sum[right[qr]] ^ (left[qr] == 0 ? 0 : sum[left[qr] - 1]);
			sol[qr] = distinctXSum ^ oddXSum;
		}
	}
	rep(i, m) //cout << sol[i] << '\n';
		printf("%d\n", sol[i]);
	return 0;
}


http://codeforces.com/contest/706/problem/D
D. Vasiliy's Multiset
1. "+ x" : add integer x to multiset A	// 숫자 넣기
2. "- x" : erase one occurrence of integer x from multixet A.
			It`s guaranteed that at least one x is present in the multiset A before
			this query	// 숫자 삭제: 같은 숫자가 3개 있으면 1개 삭제되니 2개 남음
3. "? x" : x와 multiset A 에 속한 숫자들을 xor 시킨 값들중 가장 큰 것을 출력한다.

input
10		// query q (1 <= q <= 200000)
+ 8		/ 1000	// 입력되는 숫자는 1이상 10^9 이하임
+ 9		/ 1001
+ 11	/ 1011
+ 6		/ 0110
+ 1		/ 0001
? 3		// 8^3 = 1000^0011 = 1011 = 11
- 8
? 3		// 9^3 = 1001^0011 = 1010 = 10
? 8		// 6^8 = 0110^1000 = 1110 = 14
? 11	// 6^11= 0110^1011 = 1101 = 13

output
11
10
14
13

// 고찰: xor의 규칙성에 대해 기술해보자

http://codeforces.com/contest/706/submission/19797539
multiset<int> q[33];
int x, y, cs;
string typ;
int main() {
	ios::sync_with_stdio(false);
	cin >> cs;
	rep(i,32) q[i].insert(0);
	while (cs--) {
		cin >> typ >> x;
		if (typ == "+") {
			q[0].insert(x);
			rep(i,31) {
				if (x & (1 << i))
					x ^= (1 << i);
				q[i + 1].insert(x);
			}
		} else if (typ == "-") {
			q[0].erase(q[0].find(x));
			rep(i,31) {
				if (x & (1 << i))
					x ^= (1 << i);
				q[i + 1].erase(q[i + 1].find(x));
			}
		} else {
			y = 0;
			for (int i = 30; i >= 0; --i) {
				if (!(x & (1 << i))
					y ^= (1 << i);
				if (!q[i].count(y))
					y ^= (1 << i);
			}
			cout << x ^ y << endl;
		}
	}
	return 0;
}

시뮬해보자.


// 위랑 비슷한 방식임: multiset의 lower_bound를 어찌 쓰는지 보자 !!!!
http://h-noson.hatenablog.jp/entry/2016/08/13/030920



http://codeforces.com/contest/706/problem/E
E. Working routine
n rows and m columns matrix // 2 <= n, m <= 1000
q task	// 1 <= q <= 10000

a, b, c, d, h, w
// 1 <= a, c, h <= n
// 1 <= b, d, w <= m

Each task is to swap two submatrices of the given matrix. ? // 해석이 어렵네

input
4 4 2		// n, m, q
1 1 2 2
1 1 2 2
3 3 4 4
3 3 4 4
1 1 3 3 2 2		// 1행1열 기준으로 2by2 subMtx, 3행3열 기준 2by2 subMtx를 서로 교환
3 1 1 3 2 2		// 3행1열 기준으로 2by2 subMtx, 1행3열 기준 2by2 subMtx를 서로 교환

output
4 4 3 3
4 4 3 3
2 2 1 1
2 2 1 1

시뮬
// q1실행시
4 4 2 2
4 4 2 2
3 3 1 1
3 3 1 1

// q2실행시
4 4 3 3
4 4 3 3
2 2 1 1
2 2 1 1

		
LRU
http://codeforces.com/contest/699/problem/E
" 어럽다.. 수식을 더 알아야 겠다.. 밑에 설명은 해석에 불과함.. 진정 내가 이해한게 아님"
N 개의 비디오가 비디오 i는 각 pi확률로 선택된다. 
캐시는 새로 선임 된 비디오를 K 개의까지 기억할 수 있고 K 개의 캐시 한 상태에서 
캐시에 포함되지 않은 비디오가 선택되었을 때 캐시에서 가장 오래된 비디오를 삭제한다.
10^1000 시간이 지난 후 각 비디오가 캐시에 남아있는 확률을 출력하라.
"참고 소스: 일본사이트 일본어, 소스가 간결하고 좋다."
http://kenkoooo.hatenablog.com/entry/2016/07/21/005739 : 이것 베이스로 제출하여 통과함
http://codeforces.com/contest/699/submission/19446322 // 0.0인 놈 중복처리
/*
	" 핵심 개념 시뮬임"
	dp[00001111] = dp[00001110] * P[0] / (P[4~7] + P[0])
				 + dp[00001101] * P[1] / (P[4~7] + P[1])
				 + dp[00001011] * P[2] / (P[4~7] + P[2])
				 + dp[00000111] * P[3] / (P[4~7] + P[3])
*/
double dp[1 << 21];
double P[21];
double ans[21];
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	dp[0] = 1;
	rep(i, n) cin >> P[i];
	rep2(mask, 1, (1 << n)) {
		if (__popcnt(mask) > k) 
			continue;
		double othersP = 0.0;
		rep(other, n) if ((mask & (1 << other)) == 0) 
			othersP += P[other];
		rep(sel, n) {
			if (P[sel] == 0.0) continue;
			if ((mask & (1 << sel)) == 0) continue;
			double p = P[sel] / (othersP + P[sel]);
			dp[mask] += dp[mask - (1 << sel)] * p;
			ans[sel] += dp[mask - (1 << sel)] * p;	// 여기 놓아야 됨
		}
		//if (__popcnt(mask) == k)	// 여기에 놓으면 오답됨 (17번째 케이스에서..)
		//	rep(i, n) if ((mask & (1 << i)) != 0)	
		//	ans[i] += dp[mask]; // 여기다 놓고 싶다면 애초 확률이 0.0인 놈을 제거해야함
	}
	rep(i, n) printf("%.7lf ", ans[i]);
	return 0;
}
// 처음엔 근냥 생 dp로 하려 했지만 10^1000은 너무 많다. 로그도 취할수 없음
// 키워드는 평형상태를 생각하라는 것과
// 선택된 놈들을 0인 것에서 시작해서 차례대로 증가시킴으로서
// 과거가 참조하더라도 불안한 점이 없다. (과거참조 시점에선 결정되어 있기 때문이다.)
"핵심적으로 어려웠던 개념"
p = P[sel] / (othersP + P[sel]) // 시뮬봐라. 
"일단 1로 세팅된건 더 이상 건딜수 없다.
"0으로 세팅된 것중 하나를 선택할 수 있다!!!!

"이렇게 글을 적었다만.. 정작 캐쉬에 자기것이 있는 상태에서 다시 자기것이 선택된다면
우찌되는지 설명이 안된다..." 내 머리가 이해가 안됨.. ㅠㅠ!!!! 지지gg

김동이 알려준 사이트보고 다시 고찰
http://codeforces.com/blog/entry/46169#comment-323867
tinytiny 의 글 중 핵심
so its probability also equal to the event 
	"the first k different elements in the choosing sequence consist of b1,b2,..bk"
맨마지막 캐시를 이루었던 순서들을 거꾸로 해도 확률은 같다.

// ffao 소스
http://codeforces.com/contest/698/submission/19241130
editorial 의 ffao 글이 그나마 이해하기 쉬운 형식이였음
dp[mask] 의 의미는 "현 캐시가 최초로 딱 되었얼 때 시점의 확률을 의미한다."
// mask1 에서 j를 선택해서 mask + j 가 된다는 확률은
(The probability you move from mask1 to mask2, picking j, is 
	P (mask1, j)= pj + sum of ps in mask1 * P (mask1,j), 
	solving we get P (mask1,j) = pj / (1-sum of ps in mask1)).
// mask1 에서 j번째를 선택해서 mask2 로 갈 확률은
// = j를 선택할 확률 + mask1 에서 j를 제외한 것을 선택할 확률 * mask1 에서 j를 선택할 확률

sum of ps in mask1 * P(mask1, j) 의 뜻을 다시 설명하자면
	p(mask1, j)는 mask1에서 j를 선택할 확률이고 sum of ps 는 mask1 + (1 << j) 가 되기전인 mask1 의 상태임
	mask1 상태에서 mask1의 원소중 하나를 선택한뒤 끝에 j를 선택한다는 것으로
	
"급수로 표현한다면
// p(mask1, j) = pj + (ps) * pj + (ps)^2 * pj + (ps)^3 * pj + ... + (ps)^oo * pj

// 약간 거슬린다. 확률 통계 책을 살펴봐야 겠다...!!!! 비슷한 문제가 있을거야..

// 다시 정리(예시와 함계)
	0		1		2
	a		b		c
p	0.1		0.2		0.7
Prob(001, 1) : 마스크 001 에서 b를 취해서 011 이 되는 순간의 확률(at the point!!!!) "순간이 중요하다."

	Prob(001, 1)	= 0.2		// 이 순간 b를 취했다.
					+ 0.1 * Prob(001, 1)	// mask 001 에 있는 놈을 선택한다면 재귀로 떠 넘긴다.
	
	Prob(001, 1)	= 0.2 + 0.1 * (0.2 + 0.1 * Prob(001, 1))
					= 0.2 + 0.1 * (0.2 + 0.1 * (0.2 + 0.1 * Prob(001, 1)))
					= 0.2 + 0.1 * (0.2 + 0.1 * (0.2 + 0.1 * (0.2 + 0.1 * Prob(001, 1))))
	"				= 0.2 + (0.1)*(0.2) + (0.1^2)*(0.2) + (0.1^3)*(0.2) + (0.1^4)*(0.2) ...
					// 등비수열의 합
					= 0.1 / (1 - 0.2)

	
					
"나의 오해: self reference equation 상에서 dp[011] 된 상태에서 다시 dp[011]이 될 확률을 고려해야 되는거 아닌가?"
Prob(001, 1)	= 0.2 + (0.1 + 0.2) * Prob(001, 1) 
// dp[011] += mask[001] * 0.2 + (0.1+0.2) * mask[011]	
// 011 상태에서 011이 되려면 011 의 원소를 취하면 되지 않느냐 
// 허나 이것은 at the point 를 나타내지 않는다.

"순간(at the point) 가 중요한 이유, 확률의 성질을 고려: //확률의 곱은 순서를 바꿔도 동일
			   <-------
	~~~~~~~~~~~[......] // 뒤로 가는 순간 캐시가 maskA를 형성한 순간의 확률만 알면 된다. !!!! 핵심이다. 오오오오
						// 당연 ~~~~~~ 물결 부분은 뭔 값이 선택되던 관계가 없으니 생깔수 있다.

// 편하게 거꾸로 돌려서 보자(동치다)
	[......]~~~~~~~~~~~ // 앞으로 가는 순간 캐시가maskA를 형성한 순간의 확률



// 나의 오해를 다시 곱씹기
	0		1		2		3
p	0.1		0.2		0.3		0.4
// 내 오해로 성립된 식
dp[0111]	= dp[0011] * p2 
			+ dp[0101] * p1 
			+ dp[0110] * p0 
			+ "dp[0111] * (p0 + p1 + p2)" // 자신 참조
// 위식의 의미는 캐시가 (0, 1, 2) 3개를 채웠을 순간을 의미하지 않는다.
// 그리고 문제를 풀기엔 무쓸모인 식이 될 뿐이다.

at the point 를 적용한 올바른 식
dp[0111]	= dp[0011] * p2 / (1 - (p0 + p1))
			+ dp[0101] * p1 / (1 - (p0 + p2))
			+ dp[0110] * p0 / (1 - (p1 + p2))


// 다시 적자면
// dp[0111] 은 캐시 사이즈가 3이라 할때 {0, 1, 2} 로 채워진 순간, 바로 그 시점의 확률이다.
// 다른 말로 무한한 시간이 흐른뒤 캐시 사이즈가 3이고 그 안에 {0, 1, 2} 가 채워질 확률이다.


http://codeforces.com/contest/714/problem/C
"숫자가 입력되거나 삭제되고, 해당 질의에 맞는 숫자의 갯수를 출력하라"
"단 해당 질의중 0이 앞에 오는 것도 있다는 사실을 주의해야함

// 문제가 구현할때 중간에 더럽다고 생각되면 다시 짜라...
// 더러워진 코드 공사한다고 시간 다 보내고 통과 못했다....ㅠㅠ
// 아래는 다시 짜서(10분 걸림...) 통과하였다.
// 1등한 사람은 트라이로 빠른 속도로 통과하였음.
map<string, ll> my1;
string tmp;
void insert(ll a, int val) {
	tmp.resize(19);
	int m;
	for (int i = 0; i < 19; ++i) {
		m = a % 10;
		m %= 2;
		a /= 10;
		tmp[i] = m + '0';
	}
	for (int i = 18; i >= 0; --i) {
		my1[tmp] += val;
		if (tmp.back() == '1') {
			break;
		}
		else
			tmp.pop_back();
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	char type;
	ll a;
	string str;
	rep(i, t) {
		cin >> type;
		if (type == '+') {
			cin >> a;
			insert(a, 1);
		}
		else if (type == '-') {
			cin >> a;
			insert(a, -1);
		}
		else {
			cin >> str;
			reverse(str.begin(), str.end());
			cout << my1[str] << '\n';
		}
	}
	return 0;
}

http://codeforces.com/contest/714/submission/20581597
1등한 인간의 트라이 코드. 109ms로 나보다 5배 빠름..


// 간단한 문제임. 그러나 영어해석이 잘 안되어 1시간 해맴...
// 멋대로 추가 해석한 부분이 있음.
// 꽉 차면 압착을 한다라는 것으로 오인 해석함
" 넘치면 압착을 한다고 되어 있다" !!!!
	"정확한 해석을 하자.."
The juicer has a special section to collect waste. 
It overflows if Kolya squeezes oranges of the total size strictly greater than d. 
When it happens Kolya empties the waste section 
(even if there are no more oranges) and continues to squeeze the juice. 
How many times will he have to empty the waste section?
http://codeforces.com/contest/709/problem/A




http://codeforces.com/contest/710/problem/D
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
// 7x + 4 = X
// 13y + 8 = X
// 7x - 13y = 4	// a:7	b:13	c: 4
int main() {
	//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	ll a, b, x, y;
	a = 7;
	b = 13;
	b *= -1;
	ll g = gcd(a, b, x, y);	// 7x - 13y = 1 의 확장 유클리드 해를 구함
							// x : 2, y : 1 로 세팅된다.
	// 실제 값은 c가 4이므로 4배가 된다
	return 0;
}
// 약간 구린 점: a = 7, b = 11 넣으니 (물론 gcd에 들어가는 b 는 -11이 되고)
// g 가 -1이 됨, x = 3, y = 2 가 됨: 즉 3*7 - 2*11 = -1 임
// g 가 -1 이면 x, y의 값을 -1 곱해줘야함..
" 구린게 아니라 정확한 거임 b = -11 이 되기 때문이다. !!!!"

li a1, b1, a2, b2, l, r;

bool read() {
	return !!(cin >> a1 >> b1 >> a2 >> b2 >> l >> r);
}

ll _ceil(ll, ll);	// 상호참조용 !!!!, 클래스 뿐만이 아니라 함수도 되구낭: 바보야 원래 이게 기원이야!
// a를 양수 b로 나누고 반올림, 올림 해서 리턴함
ll _floor(ll a, ll b) { return b < 0 ? _floor(-a, -b) : a < 0 ? -_ceil(-a, b) : a / b; }
ll _ceil(ll a, ll b) { return b < 0 ? _ceil(-a, -b) : a < 0 ? -_floor(-a, b) : (a + b - 1) / b; }

// 유용하네. 일반적으로 서로 다른 부호로 나눴을때 음수가 나오고 그때는 올림, 반올림이 거꾸로지
					_floor(a, b)		_ceil(a, b)
a = 37, b = 5			7					8
a = 37, b = -5			-8					-7
a = -37, b = 5			-8					-7
a = -37, b = -5			7					8

li gcd(li a, li b, li& x, li& y) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	li xx, yy, g = gcd(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}

void solve() {
	l = max(0ll, _ceil(l - b1, a1));
	r = _floor(r - b1, a1);
	if (l > r) {
		puts("0");
		return;
	}

	li A = a1, B = -a2, C = b2 - b1;
	li x0, y0;
	li g = gcd(A, B, x0, y0);
	if (C % g) {	// C 는 A, B의 최대공약수인 g의 배수가 되어야만 정수해가 존재한다.
		puts("0");
		return;
	}

	if (g < 0) {
		g = -g;
		x0 = -x0;
		y0 = -y0;
	}

	li L = _ceil(r * g - x0 * C, B);
	li R = _floor(l * g - x0 * C, B);
	R = min(R, _floor(y0 * C, A));

	li ans = max(0ll, R - L + 1);
	cout << ans << endl;
}

// k, l >= 0 인 문제 조건이 이 문제를 더욱 어렵게 만든다. // GG다. 완전 꼬운 문제다.
// 위 조건이 아닌경우 아래와 같이 풀면 된다.
http://codeforces.com/contest/710/submission/21315589 // k, l 조건은 더러워서 GG다.
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
	//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	ll a1, b1, a2, b2, L, R;
	//cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	a1 = 4, a2 = -8, b1 = 10, b2 = 30;
	L = 0, R = 100;
	if (R < L) {
		cout << "0";
		return 0;
	}
	// x = a1*k + b1
	// x = a2*t + b2
	// a1*k - a2*t = b2 - b1;
	ll c = b2 - b1;
	ll xx, yy;
	ll g = gcd(a1, -a2, xx, yy);
	if (c % g != 0) {
		cout << "0";
		return 0;
	}
	if (g < 0) {
		g *= -1;	xx *= -1;	yy *= -1;
	}
	ll xxx = xx * c / g;	// c가 g의 배수인 점을 상상하라
	ll yyy = yy * c / g;
	ll lcd = (a1*a2) / g;	// 최소공배수
	if (lcd < 0) lcd *= -1;
	ll base = (a1 * xxx + b1);	// 실제 수
	ll left = _ceil((L - base), lcd) * lcd + base;
	ll right = _floor((R - base), lcd) * lcd + base;
	ll sol = (right - left) / lcd + 1;
	cout << sol;
	return 0;
}
//a1 = 4, a2 = -8, b1 = 10, b2 = 30;
//L = 0, R = 100;
// a1x - a2y = b2 - b1
// 4x + 8y = 20
// x = 1, y = 0, g = 4
// so xxx = x * 20 / g = 5, yyy = y * 20 / g	// !!!!
// base = 12 = a1 * xxx + b1 = 4*5+10 = 30 = a2 * yyy + b2 = -8*0 + 30;
// 모든 숫자는 30 + 8*t 형식을 갖는다.
// 확장 유클리드는 기억해라 활용도 높다.

li gcd(li a, li b, li& x, li& y) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	li xx, yy, g = gcd(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}
void test() {
	ll a, b, x, y;
	a = 4; b = 8;
	ll g = gcd(a, b, x, y);	// g(최대공약수) = 4가 된다.
	// x = 1, y = 0; 즉 4*x + 8*y = 4 에서의 답이 됨. 4는 a, b 즉 4, 8의 최대공약수
	// 만약 식이 4*x + 8*y = 20 이면 20 / g 를 곱한 값이 답이 된다.
}
ll gcd(ll a, ll b, ll& x, ll& y) {
	if (!a) {
		x = 0, y = 1;
		printf("base:: a: %I64d, b: %I64d, x: %I64d, y: %I64d\n", a, b, x, y);
		return b;
	}
	ll xx, yy, g = gcd(b % a, a, xx, yy);

	x = yy - b / a * xx;
	y = xx;
	printf("other:: a: %I64d, b: %I64d, x: %I64d, y: %I64d\n", a, b, x, y);
	return g;
}

ll x, y;
ll re = gcd(401, 42, x, y);		// 401*x + 42*y = 1										xx, yy: 한깊이 밑의 것임
													  a*x		+		b*y				x = yy - b/a*xx,	y = xx,		a = preB
base:: a: 0, b: 1, x: 0, y: 1				"1"		= 0*0		+		1*1				
other:: a: 1, b: 3, x: 1, y: 0						= 1*1		+		3*0				1 = 1 - 3/1*0,		0 = 0
other:: a: 3, b: 4, x: -1, y: 1						= 3*(-1)	+		4*1				-1 = 0 - 4/3*1,		1 = 1
other:: a: 4, b: 19, x: 5, y: -1					= 4*5		+		19*(-1)			5 = 1 - 19/4*(-1)	-1 = -1
other:: a: 19, b: 23, x: -6, y: 5					= 19*(-6)	+		23*5
other:: a: 23, b: 42, x: 11, y: -6					= 23*11		+		42*(-6)
other:: a: 42, b: 401, x: -105, y: 11				= 42*(-105)	+		401*11
other:: a: 401, b: 42, x: 11, y: -105				= 401*11	+		42*(-105)

42	= 0*401 + "42"
401 = 9*42	+ "23"
42	= 1*23	+ "19"
23	= 1*19	+ "4"
19	= 4*4	+ "3"
4	= 1*3	+ "1"
3	= 3*1	+ "0"
1	= 1*1	+ "0"

설명적을러다 스왑한건 생략하기 위해 아래 예시로 설명.

ll x, y;
ll re = gcd(42, 401, x, y);		// 42*x + 401*y = 1										xx, yy: 한깊이 밑의 것임
													  a*x		+		b*y				x = yy - b/a*xx,	y = xx,		a = preB
base:: a: 0, b: 1, x: 0, y: 1				"1"		= 0*0		+		1*1				
other:: a: 1, b: 3, x: 1, y: 0						= 1*1		+		3*0				1 = 1 - 3/1*0,		0 = 0
other:: a: 3, b: 4, x: -1, y: 1						= 3*(-1)	+		4*1				-1 = 0 - 4/3*1,		1 = 1
other:: a: 4, b: 19, x: 5, y: -1					= 4*5		+		19*(-1)			5 = 1 - 19/4*(-1)	-1 = -1
other:: a: 19, b: 23, x: -6, y: 5					= 19*(-6)	+		23*5
other:: a: 23, b: 42, x: 11, y: -6					= 23*11		+		42*(-6)
other:: a: 42, b: 401, x: -105, y: 11				= 42*(-105)	+		401*11


b	  t*a						a*x					+		b*y						a*x			+	b*y
401 = 9*42	+ "23"				42*(-6-401/42*11)	+		401*11
42	= 1*23	+ "19"				23*(5-42/23*(-6))	+		42*(-6)			// !!!! 이 스텝에서 위로가는걸 보자.
23	= 1*19	+ "4"				19*(-1-23/19*5)		+		23*5
19	= 4*4	+ "3"				4*(1-19/4*(-1))		+		19*(-1)
4	= 1*3	+ "1"				3*(0-4/3*1)			+		4*1
3	= 3*1	+ "0"				1*(1-3/1*0)			+		3*0
1	= 0*0	+ "1"		"1"	=	0*0					+		1*1


//스텝에서 위로가는걸 보자(밑으로 풀이함) x = yy - (b / a * xx) 인 이유를 알수 있다
1	= 23*11							+		42*(-6)				// 오른쪽에 불어난 것 만큼 왼쪽에 빼준다 : (378*11)
	= 42*(-6) + (-378)*11			+		23*11 + 378*11		// 378은 무슨 숫잔지 고찰해라	378 = 401 / 42 * 42				
	= 42*(-6) + (-401/42*42)*11		+		23*11 + 378*11		// 이때 401/42 는 정수형 연산이라 당연히 소수는 생략된다.
	= 42*(-6 - 401/42*11)			+		23*11 + 378*11
	= 42*(-6 - 401/42*11)			+		401*11

378은 401을 42로 나눌때 나온 몫에다가 42를 곲한 값이 된다. 즉 42의 배수가 된다.
	"378*11 은 11의 배수도 되므로	오른쪽 23*11 에다가 더해주면 401의 배수로 나타나넹

1	= 23*xx						+		42*yy
	= 42*yy + (-378)*xx			+		23*xx + 378*xx
	= 42*yy + (-401/42*42)*xx	+		(23+378)*xx
	= 42*(yy - 401/42 * xx)		+		401*xx

좀더 일반화하면 이렇게 된다. 이제야 약간 소화가 될 정도네.. 헷갈린다.
1	= p*xx						+		a*yy
	= a*yy + (-b/a*a)*xx		+		p*xx + (b/a*a)*xx		// 이때 b = (b/a) * a + p 이므로 
	= a*yy + (-b/a*a)*xx		+		(p+(b/a)*a)*xx			// 몫의 a배한것에 나머지 p를 더하면 피제수 b가 나옴
	= a*(yy + (-b/a)*xx)		+		b*xx



// 정해진 길이 이하로 가장 많은 지점들을 지나가는 1~n 의 길을 구하라!!!!
http://codeforces.com/contest/721/problem/C
http://codeforces.com/contest/721/submission/21024854
dp[i][here] // 갯수가 총 i개를 지나가고 현재 위치가 here 가 될 때까지 가장 짦은 거리
			// 최초 here가 1 이다.
"dp[i+1][there] = min{ dp[i][here] + cost[here][there] }"
// 음.. dp[n][n] 은 1 부터 n까지 지나가는 동안 가장 짧은 거리가 되네
// tsp 에 응용되는건가 싶었다만..
// 문제 조건이 directed acyclic graph임
// 이 상태에서 dp[n][n] 이 값이 무한대가 아닐려면.. 당연 그래프는
// 일렬로 이루어진 상태가 되겠지... 
// 즉 문제 조건상 tsp 를 구하라는 건 일렬형태 빼곤 답이 무한대임. 따라서 무쓸모..
const ll LINF = 1e18;
vi adj[5005], cost[5005], radj[5005], rcost[5005];
int n, m, t;
ll dp[5005][5005];
vi ans;
void go(int num, int here) {
	if (num == 1) return;
	for (int i = 0; i < radj[here].size(); ++i) {
		int there = radj[here][i];
		int c = rcost[b][i];
		if (dp[a - 1][there] + c == dp[a][b]) {
			ans.pb(there);
			go(a - 1, there);
			return;
		}
	}
}
int main() {
	cin >> n >> m >> t;
	rep(i,m) {
		int u, v, c;	cin >> u >> v >> c;
		adj[u].pb(v);	radj[v].pb(u);
		cost[u].pv(c);	rcost[v].pb(c);
	}
	rep2(i,1,n+1) rep2(j,1,n+1) dp[i][j] = LINF;
	dp[1][1] = 0;
	rep2(i,1,n)
		rep2(j,1,n+1)
			if (dp[i][j] < LINF)
				rep(k,adj[j].size()) {
					int nxt = adj[j][k];
					int c = cost[j][k];
					dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j] + c);
				}
	for (int i = n; i >= 1; --i)
		if (dp[i][n] <= t) {
			ans.pb(n);
			go(i,n);
			break;
		}
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; --i) printf("%d ", ans[i]);
}

// 내가 푼거
const int INF = 1000000001;	// 문제제약상 (각 간선은 최대 10억이며, t도 10이하임)
	// 21억으로 잡으니 오류남!!!!: 20억까지 된 상테에서 10억 더해지면 오버플로우겠죵~ // 자주 일어나니 조심하자
// dp[accN][here] : 현재까지 accN개의 도시를 지나고 현 도시가 here 일때 가장 짦은 거리
// dp[accN + 1][there] = min{ dp[accN][here] + dist[here][there] }
int dp[5005][5005];	// ll 로 하니 총 용량이 300megabytes에 육박해서 메모리 넘침으로 에러
int prnt[5005][5005];
vi adj[5005], cost[5005];
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	memset(prnt, -1, sizeof(prnt));
	int n, m, t; cin >> n >> m >> t;
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back(b);
		cost[a].push_back(c);
	}
	rep2(i, 1, n + 1) rep2(j, 1, n + 1) dp[i][j] = INF;
	dp[1][1] = 0;
	rep2(accN, 1, n) {
		rep2(here, 1, n + 1) {
			if (dp[accN][here] >= INF) continue;
			rep(i, adj[here].size()) {
				int there = adj[here][i];
				int c = cost[here][i];
				if (dp[accN][here] + c >= INF) continue;
				if (dp[accN + 1][there] > dp[accN][here] + c) {
					dp[accN + 1][there] = dp[accN][here] + c;
					prnt[accN + 1][there] = here;
				}
			}
		}
	}
	vi sol;
	for (int i = n; i >= 1; --i) {
		if (dp[i][n] <= t) {
			int accN = i;
			int here = n;
			while (prnt[accN][here] != -1) {
				sol.push_back(here);
				here = prnt[accN][here];
				accN--;
			}
			sol.push_back(1);
			break;
		}
	}
	cout << sol.size() << '\n';
	for (int i = sol.size() - 1; i >= 0; --i) cout << sol[i] << " ";
	return 0;
}

"쓰레기 같은 getline... string 에다가 문장을 세팅하려면 어쩔수 없이 써야 되네...
// 다른 사람이 쓴 답
int n;
int p[12000];

int gl(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
		return 1;
	else
		return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	string s;
	getline(cin, s);	// "" 빈 문자열로 세팅 되어 있음...
	" 이걸 쓴 이유는 처음부터 getline 을 쓰면 문제 없으나
	" 중간부터 getline 을 쓰면 엔터를 입력으로 생각함
	" 허나 앞에 cin으로 버퍼들은 비워졌기에 빈문자열로 세팅된다고 추측함"
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		int cnt = 0;
		for (int j = 0; j < (int)s.size(); ++j)
			if (gl(s[j]))
				++cnt;
		if (cnt != p[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}
// 내거
, int> my1;

const string vowels = "aeiouy";
int main() {
	//freopen("input.txt", "r", stdin);
	//ios::sync_with_stdio(false);
	int n; //cin >> n;
	scanf("%d", &n);
	vi arr(n);
	rep(i, n) //cin >> arr[i];
		scanf("%d", &arr[i]);
	bool sol = true;
	cin.ignore(); //!!!!	빈 문제열 제거용
	rep(i, n) {
		string str;	
		// 여기다가 cin.ignore() 를 쓰면 좆됨. 각 문자열의 맨 앞글자 하나가 날라감...
		getline(cin, str);
		//cout << str << endl;
		int cnt = 0;
		rep(j, str.size()) {
			bool match = false;
			rep(k, vowels.size()) {
				if (str[j] == vowels[k])
					match = true;
			}
			if (match)
				cnt++;
		}
		if (arr[i] != cnt)
			sol = false;
	}
	if (sol)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}




// 좋은 문제다.
http://codeforces.com/contest/722/problem/C
// 배열이 주어지고
// 삭제될 인덱스가 주어짐
// 삭제될시 연결된 값들의 합중 가장 큰 값을 출력한다.
// 나는 rmq 로 풀었음. (al_2 소스에 적음)

// 구사과 풀이: 거꾸로 생각 !!!! dsjSet으로 풀었음
" 왜 거꾸로 간다는 생각을 못했을까..."
http://codeforces.com/contest/722/submission/21074806
ll sz[100005];
int prnt[100005];
int find(int x) {
	return prnt[x] = (prnt[x] == x ? x : find(prnt[x]));
}
bool merge(int p, int q) {
	p = find(p);
	q = find(q);
	if (p == q) return 0;
	prnt[q] = p;
	sz[p] += sz[q];
	return 1;
}
int n, a[100005], q[100005];
ll sol[100005], cur;
int ok[100005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) prnt[i] = i;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &q[i]);
	for (int i = n; i; --i) {	// 거꾸로 간다. !!!!
		ok[q[i]] = 1; // 사용했음을 세팅
		sz[q[i]] = a[q[i]];	// 인덱스의 값
		if (ok[q[i] + 1]) merge(q[i], q[i] + 1);
		if (ok[q[i] - 1]) merge(q[i], q[i] - 1);
		sol[i] = cur;
		cur = max(cur, sz[find(q[i])]);
	}
	for (int i = 1; i <= n; ++i) printf("%lld\n", sol[i]);
	return 0;
}


http://codeforces.com/contest/722/problem/D
// 문제이해하기 참 어렵네..
input
6		// 5만개, 각 원소는 1이상 10억이하
15 14 3 13 1 12		// Y
output
12 13 14 7 3 1		// X

Y가 주어질 때 X를 찾아라.
Y는 distinct 하고
최초 X는 값들이 distinct
	X를 변경시켜 Y가 되도록 해야함(변경 과정에서 X가 distinct 될 필요는 없다)
	변경연산: a, b 둘중 하나를 취함
a)	어떤 xi 하나를 골라 xi * 2 를 취한다.
b)	어떤 xi 하나를 골라 xi * 2 + 1 를 취한다.
	"최초 X를 구하되 X의 원소중 가장 큰 값이 최대한 작게 하도록 해라"
15	14	3	13	1	12		// Y
7	14	3	13	1	12		// X: 15에 역연산 취함
7	7	3	13	1	12		// 14에 역연산 취함: 중복된 숫자가 있음
7	3	3	13	1	12		// 7에 역연산 취함: 중복된 숫자가 있음..

결국 15에 역연산 취한거 하나만 답이 된다.
// 구사과 소스는 꿀사과임. 좋네
http://codeforces.com/contest/722/submission/21077900
set<int> s;
int n, a[500050];
bool trial(int x) {	// 한번 수행시 bigO(50000 * log2(10억) = 50000 * 30 )
	s.clear();
	for (int i = 0; i < n && a[i] <= x; ++i)
		s.insert(a[i]);
	for (int i = n - 1; i >= 0 && a[i] > x; --i) {
		int v = a[i];
		while (v > x) v /= 2;
		bool ok = 0;
		for (int j = v; j >= 1; j /= 2) {
			if (s.find(j) == s.end()) {	// 중복되는거 없이 집어 넣을수 있으면
				s.insert(j);
				ok = 1;
				break;
			}
		}
		if (!ok) return 0;	// 집어넣을수 없는 경우
	}
	return 1;
}
// bigO = 50000 * 30 * 30
int main() {
	cin >> n;
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);
	int left = 1, right = 1e9;
	while (left != right) {	// 2^30 이 10억 정도 되니 최대 약 30번 반복한다
		int m = (left + right) / 2;
		if (trial(m)) right = m;
		else left = m + 1;
	}
	trial(right);
	for (auto &i : s) printf("%d ", i);
	return 0;
}


// 꼭 다시 풀어볼 문제
http://codeforces.com/contest/723/problem/C
input
7 3
1 3 2 2 2 2 1		// 1번밴드: 2곡, 2번밴드: 4곡, 3번밴드: 1곡
output
2 1
1 3 3 2 2 2 1 

// "평탄화" 좋은 문제 !!!!	n^2 알고리즘(n이 여기선 2000이 최대임)
"오해하지마라 평탄화가 아니다..."
// 좋아하는 밴드들의 곡으로 채운다
// 각 밴드들은 고르게 곡이 나오도록 해야함
"즉 각 밴드들 부르는 곡의 갯수 중 가장 작은 갯수가
"가장 최대가 되도록 조작하라!( 평탄화 !!!!)
추가로, 그렇게 만들기 까지의 조작 연산은 최소화해야함
http://codeforces.com/contest/723/submission/21147398	// sjo200 코드...
// 간단한데 왜 복잡하게 생각했을까...? 반성하자 ㅠㅠㅠㅠㅠㅠ
int band[2020], arr[2020];
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	rep2(i, 1, n + 1) {
		cin >> arr[i];
		if (arr[i] > m) continue;
		band[arr[i]]++;
	}
	int sol1 = n / m;
	int cnt = 0;
	rep2(i, 1, m + 1) {
		rep2(j, 1, n + 1) {
			if (band[i] < sol1) {
				if (arr[j] > m || (arr[j] <= m && band[arr[j]] > sol1)) {
					if (arr[j] <= m)
						band[arr[j]]--;
					band[i]++;
					arr[j] = i;
					cnt++;
				}
			}
			else {
				break;
			}
		}
	}
	cout << sol1 << " " << cnt << '\n';
	rep2(i, 1, n + 1) cout << arr[i] << " ";
	return 0;
}

밴드	곡수
1번		4
2번		4
3번		5
4번		5
5번		6

최저곡의 수는 24 / 5 = 4곡이 된다.
나의 오해는 5번 밴드의 곡수를 하나 옮겨서 1번 혹은 2번에 줘야 하는 거였다.
"그럴 필요없이 이 자체가 답이었다" 즉 평탄화 문제가 아니었음..


http://codeforces.com/contest/723/problem/D
5 4 1	// 5, 4 는 맵 사이즈,		1은 남길 호수의 갯수
****
*..*
****
**.*
..**		// ..**에서 ..은 호수가 될수 없다. 외각인 경우는 안됨

"호수를 막아서 k개의 호수를 만든다. 
"초기 호수수는 k이상이다(k포함)

1
****
*..*
****
****
..**

// 그냥 가장 작은 호수부터 제거하면 된다.
// 앞전엔 뭔가 오타로 잘 안돌아갔음 (c4big3 로 제출..)
// 새로짜니 돌아간다..(c4big2 로 제출...)
// 알고리즘이 맞는데도 계속 틀리면 분석하지 말고 새로짜라는 교훈을 얻음..
int n, m, k;
vs board;
bool vstd[52][52];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> trac;
vector<pair<int, vpii>> ar;
bool dfs(int y, int x) {
	if (y == 0 || y == n - 1 || x == 0 || x == m - 1)
		return true;	// 바다랑 연결됨
	trac.pb(mp(y, x));
	vstd[y][x] = true;
	bool ret = false;
	rep(i, 4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (vstd[ny][nx] == false && board[ny][nx] == '.') {
			bool cand = dfs(ny, nx);
		//	cout << "ny, nx: " << ny << " " << nx << endl;
		//	cout << "cand: " << cand << endl;
			ret = ret || cand;
		}
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	board.resize(n);
	rep(i, n) cin >> board[i];
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			if (board[i][j] == '.' && vstd[i][j] == false) {
				bool ocean = dfs(i, j);
				if (ocean == false) {
					ar.pb(mp(trac.size(), trac));
				}
			}
			trac.clear();
		}
	}
	int lakeCnt = ar.size();
	sort(ar.begin(), ar.end());
	int iter = 0;
	int fillCnt = 0;
	while (k != lakeCnt) {
		int lakeSZ = ar[iter].first;
		rep(i, lakeSZ) {
			int y = ar[iter].second[i].first;
			int x = ar[iter].second[i].second;
			board[y][x] = '*';
			fillCnt++;
		}
		iter++;
		lakeCnt--;
	}
	cout << fillCnt << '\n';
	rep(i, n) cout << board[i] << '\n';
	return 0;
}

//1등한 TooDifficuIt 의 소스를 보자 (너무나 간결하다)
http://codeforces.com/contest/724/problem/A
http://codeforces.com/contest/724/problem/B
http://codeforces.com/contest/724/problem/C	ray-tracing: 중국인 나머지 정리의 유용함
http://codeforces.com/contest/724/problem/D
http://codeforces.com/contest/724/problem/E	: DP로 어떻게 푸는지 보삼



http://codeforces.com/contest/727/problem/D
D. T-shirts Distribution	// 구사과는 네트워크 플로우로 품


http://codeforces.com/contest/727/problem/E
E. Games on a CD		// hashing, string suffix structures, string


http://codeforces.com/contest/731/problem/C
C. Socks		// 문제 해석을 잘 못했음. 그리고 그래프에 익숙해질 필요가 있다고 보임.. ㅠㅠ
// "초창기 한번만 바꾼다" 그리고 짝째기는 없어야 된다는게 핵심임.
그래프로 각 양발들을 dfs돌리고
그 순회과정 중 들리게 되는 color들의 갯수를 세고
그 중 가장 많은 갯수의 color을 기준으로 나머지 노드의 color를 바꾼다는 접근이 필요.





// 좁밥 dp 문제다. 그냥 적어봄.
https://algospot.com/judge/problem/read/CONCERT
int dp[2][1010];
int main() {
	//ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		int n, vs, vm;
		cin >> n >> vs >> vm;
		dp[0][vs] = 1;
		bool ok = true;
		rep2(i,1, n+1) {
			int v;
			cin >> v;
			int pre = (i - 1) % 2;
			int cur = i % 2;
			memset(dp[cur], 0, sizeof(dp[cur]));	// !!!!
			if (ok) {
				bool check = false;
				rep(j, vm + 1) {
					if (dp[pre][j] == 1) {
						if (j - v >= 0) {
							check = true;
							dp[cur][j - v] = 1;
						}
						if (j + v <= vm) {
							check = true;
							dp[cur][j + v] = 1;
						}
					}
				}
				if (check == false)
					ok = false;
			}
		}
		if (ok) {
			for (int i = vm; i >= 0; --i) {
				if (dp[n % 2][i] == 1) {
					cout << i << endl;
					break;
				}
			}
		}
		else
			cout << -1 << endl;
	}
	return 0;
}
// 좁밥문제다. 해설 생략
https://algospot.com/judge/problem/read/KOOGLE
int main() {
	double a = log(26);
	double b = log(10);
	int cs; 
	cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vector<pair<double, string>> arr;
		rep(i, n) {
			string str; cin >> str;
			int aCnt = 0;
			int bCnt = 0;
			rep(iter, str.size()) {
				if (str[iter] >= 'a' && str[iter] <= 'z')
					aCnt++;
				else
					bCnt++;
			}
			double difficulty = aCnt*a + bCnt*b;
			arr.pb(mp(-difficulty, str));
		}
		sort(arr.begin(), arr.end());
		cout << arr.front().second << '\n';
	}
	return 0;
}

https://algospot.com/judge/problem/read/BOOKSTORE#
// 내 추측: 포인트를 많이 주는 책부터 선택하여 산다.
// 정당성 시뮬을 해보자
	책가격		포인트
a	1000		300
b	500			400		
	// b를 먼저 사는게 이득

a	1000		400
b	500			300		
	// a를 먼저 사는게 이득

어떤 A라는 책을 남은것 중 가장 먼저 사야 답이 되는 후보해가 존재한다 치자. 
만약 A를 제외한 책들중 포인트가 더 많이 주는게 존재한다면

A	aaa			aa
B	bbb			aa + alpha

후보해는 aa만큼 절약하지만
B를 먼저 사는 경우 aa + alpha 만큼 절약을 할 수 있다.(alpha는 aaa - aa 이하의 수가 된다.)
"즉 모순이 생기므로 답이 될수 없다."
따라서 포인트를 많이 주는 순으로 순서를 결정하자.
// 소스설명은 생략하고 링크건다.
https://algospot.com/judge/submission/detail/473009


// 중간부터 파고 들어가는 dp형식 
"너무 좋은 dp 문제다. 내가 못풀어서 힌트 보고 짬."!!!!
https://algospot.com/judge/problem/read/BRACKETS
((()))
()()()
([]])
)[)(
([][][)
end

6
6
4
0
6
// 힌트만 보고 내가 짠거임.
string str;
int cache[101][101];
inline bool isSymmetry(char ch1, char ch2) {
	if (ch1 == '(' && ch2 == ')') return true;
	if (ch1 == '[' && ch2 == ']') return true;
	return false;
}
int count(int here, int there) {
	if (here == there) return 0;	// 하나짜리
	if (here > there) return 0;		// 한개도 없는 경우
	int& ret = cache[here][there];
	if (ret != -1) return ret;
	ret = 0;
	if (str[here] == ')' || str[here] == ']')
		ret = count(here + 1, there);
	else {
		ret = count(here + 1, there); // 열린 괄호에서도 생략이 필요하다. :ex) ([](
		for (int i = here + 1; i < there + 1; ++i) {
			if (isSymmetry(str[here], str[i])) {
				int cand = 2 + count(here + 1, i - 1) + count(i + 1, there);
				ret = max(ret, cand);
			}
		}
	}
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	while (true) {
		memset(cache, -1, sizeof(cache));
		cin >> str;
		if (str == "end") break;
		int sol = count(0, str.size() - 1);
		cout << sol << '\n';
	}
	return 0;
}


// 할일 순서 정하기
https://algospot.com/judge/problem/read/ORDERING
https://algospot.com/judge/submission/detail/474872
// 위상정렬로 오인했음.
// 위상정렬을 한다 해도 사전순을 구하긴 매우 어려움
// 알파벳이 겨우 26개 밖에 안되니
// 알파벳 순으로 찾고
map<int> map;
vi sol;
while (true: n개를 다 찾으면 종료) {
	rep(i,n) {	// 알파벳 순으로 체킹
		if (i가 이미 처리된건가) continue;
		if (i 보다 앞에 있는 알파벳이 있는가) continue;
		else {
			map.insert(i);
			sol.pb(i);
			delNext(i);	// i의 뒤에 연결된 알파벳 의존관계는 없앤다.
			break;
		}
	}
}