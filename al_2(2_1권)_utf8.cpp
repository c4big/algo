//---------------------- 16 장-----------------------------//
a ^ b : 두 정수 a, b를 비트별로 XOR연산
~ a   : 정수 a의 비트별 not 연산 결과
//!!!! 유의점
int c = (6 & 4 == 4); //&,|, ^ 등의 비트 연산자는 우선순위가 ==, != 보다 낮다
int d = ((6 & 4) == 4);

//http://www.rapidtables.com/prog/cref/const.htm (ull 확인사이트)
//부호없는 64비트 비트마스크 a의 b번 비트가 켜져 있는지 확인하는 코드
bool isBitSet(unsigned long long a, int b) {
	return (a & (1 << b)) > 0; //틀림 1은 32비트 상수로 취급해서 오버플로우가 발생
	return (a & (1ull << b)) > 0;
}
// 참고
const ll INF = 1e18; // 정상세팅된다!!!!!!!!

//비트마스크의 가장 중요한 사용 사례는 집합을 구현하는 것임
//이 표현에서 N비트 정수 변수는 0부터 N - 1까지의 정수 원소를 가질 수 있는 집합이 됨
ex) 집합 {1, 4, 5, 6, 7, 9 }을 표현하는 정수 754
 2^1 + 2^4 + 2^5 + 2^6 + 2^7 + 2^9 = 10 1111 0010 = 754

 //토핑 20개가 꽉찬 피자 
 int fullPizza = (1 << 20) - 1;
 //원소 추가
 toppings |= (1 << p); //0 <= p < 20
 //원소의 포함 여부 확인(p = peperoni)
 if (toppings & (1 << p)) cout << "peperoni is in" << endl;
 //원소의 삭제
 toppings -= (1 << p); //이 코드는 페페로니가 토핑 목록에 있을 때만 사용할 수 있다.
 //페페로니가 없는데 이렇게 짜면 좃된다!!!!
 toppings &= ~(1 << p);

 //원소의 토글
 topping ^= (1 << p); //xor이 유용하네

 //두 집합에 대해 연산
 int added = (a | b);			//a와 b의 합집합
 int intersection = (a & b);	//a와 b의 교집합
 int removed = (a & ~b);		//a에서 b를 뺀 차집합
 int toggled = (a ^ b);			//a와 b중 하나에만 포함된 원소들의 집합

//집합의 크기 구하기
int bitCount(int x) {
	if (x == 0) return 0;
	return x % 2 + bitCount(x / 2);
	//bitCount(x) = 최하단비트 1 세팅 여부 + bitCount(x를 한칸 쉬프트);
}
gcc/g++		==> __builtin_popcount(toppings);
visual C++	==> __popcnt(toppings);
java		==> Integer.bitCount(toppings); //표준 라이브러리에 포함되어 있음

//최소 원소 찾기
//컴파일러나 언어에 포함된 명령어를 이용한 방법
//정수의 이진수 표현에서 끝에 붙어 있는 0이 몇개인가?의 형태로 지원(결국 최하위의 비트를 나타내는군)
gcc/g++		==> __builtin_ctz(toppings);	//이놈은 0에 대해선 결과가 정의되어 있지 않으니 주의
visual C++	==> _BitScanForward(&index, toppings);
java		==> Integer.numberOfTrailingZeros(toppings);

//최하위 비트의 번호 대신 직접 구하는 것 (3대신 2^3 을 구하는 방식) !!!!
int firstTopping = (toppings & -toppings); //음양을 &하면 최하위비트
//1001 1000 & 0110 1000 ==> 0000 1000

//최소 원소 지우기
toppings &= (toppings - 1);	//!!!!
//10 1000 & 10 0111 ==> 10 0000

//모든 부분집합 순회하기 !!!! (하나씩 빼고 앤드(&) 시키는 스킬을 기억하삼)
for (int subset = pizza; subset; subset = ((subset - 1) & pizza)) {
	//subset 은 pizza의 부분집합
	//pizza는 full pizza가 아니어도 동작함
}
1001 의 서브셋: 1001, 1000, 0001
1101 의 서브셋: 1101, 1100, 1001, 1000, 0101, 0100, 0001

비트마스크의 응용예제
지수 시간 동적 계획법 : 배열대신 정수로 집합을 표현하면 이것을 곧장 배열의 인덱스로 쓸 수 있다는 점

에라토스테네스의 체 : 14.2절 참고해서 이해하삼
//p587 비트마스크를 사용하는 에라토스테네스의 체의 구현(메모리 공간 부족을 해결함)
int n;
unsigned char sieve[(MAX_N + 7) / 8];//+7은 왜 했노? 구하고자 하는 소수의 개수가 5개라 치자
									 //그럼 sieve[5/8] = sieve[0]으로 세팅되어 고자가 된다.
									 //배열의 크기가 0인 놈은 없잖아~~
//K가 소수인지 확인한다.
inline bool isPrime(int k) {
	return sieve[k >> 3] & (1 << (k & 7));
"	return sieve[k /  8] & (1 << (k & 7));	//k의 최하위 3비트를 추출
"	3비트가 나타내는 경우의 수는 8개: char형의 비크 개수랑 일치
}
//K가 소수가 아니라고 표시한다.
inline void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}
//비트마스크를 사용하는 에라토스테네스의 체의 구현
//이 함수를 수행하고 난 뒤, isPrime() 을 이용해 각 수가 소수인지 알 수 있다.
void eratosthenes() {
	memset(sieve, 255, sizeof(sieve)); //전부 비트가 1로 꽉 채워짐
	setComposite(0);	//0은 소수에서 제함 
	setComposite(1);	//1은 소수에서 제함
	//sieve[0 >> 3] &= ~(1 << (0 & 7)); sieve[0] &= 1111110 => 11111110
	//sieve[1 >> 3] &= ~(1 << (1 & 7)); sieve[1] &= 1111101 => 11111100
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i)
		//이 수가 아직 지워지지 않았다면
		if (isPrime(i))
			//i의 배수 j들에 대해 isPrime[j] = false로 둔다
			//i * 9 미만의 배수는 이미 지워졌으므로 신경 쓰지 않는다.
			for (int j = i * i; j <= n; j += i)
				setComposite(j);	//j는 소수에서 제함
}

15퍼즐 상태 표현하기
//각 숫자는 16개(0~15) 이며 그 숫자가 위치할 칸도 16개 이다
//숫자를 표현하는데 4비트가 들며 그 것이 위치할 칸이 16개 있으므로 4 * 16 비트로 표현가능하다
//1111 1110 1101 1100 1011 1010 1001 1000 0111 0110 0101 0100 0011 0010 0001 0000
typedef unsigned long long uint64;
//mask의 index 위치에 쓰인 값을 반환한다.
int get(uint64 mask, int index) {	//mask: 보드상태
	//(index << 2) 접근할때는 4비트씩 이동해야 해서 x 4를 해준것임
	return (mask >> (index << 2)) & 15;		
}
//mask의 index위치를 value로 바꾼 결과를 반환한다.
uint64 set(uint64 mask, int index, uint64 value) {
	//해당 칸의 숫자를 0으로 초기화 한다음 '|' 연산으로 세팅한다.
	//물론 숫자칸 특성상 다른 set을 함더 호출해야겠지요
	return mask & ~(15LL << (index << 2)) | (value << (index << 2));
}
//2번째 칸과 3번째 칸을 바꾼다면
//int value1 = get(mask, index); get(mask, 2);
//int value2 = get(mask, index); get(mask, 3);
//set(mask, 3, value1);
//set(mask, 2, value2);

//극대 안정 집합(maximal stable set) 구하기
//ex) 화학물질 A, B, C, D 가 있는데 A와 B를 같은 상자에 넣거나, C와 D를 같은 상자에 넣으면 폭발
//네 개의 극대 안정 집합이 존재 {A, C}, {A, D}, {B, C}, {B, D}
//그래프 탐색 알고리즘을 사용해 극대 안정 집합을 만들어 나가는 방법이 있음!!!! imagine
//입력의 크기가 그렇게 크지 않으면 비트마스크로 풀어봅세(비효률적이긴 하지만 간편)
//p589 비트마스크를 이용해 모든 극대 안정 집합의 수를 세는 함수의 구현
int n;	//전체 물질의 갯수
//explodes[i]는 i와 같이 두었을 때 폭발하는 물질 집합의 비트마스크 표현
"explodes[3] => 3은 포함되어 있지 않다."
int explodes[MAXN];
//주어진 집합이 안정적인지 확인한다.
bool isStable(int set) {
	for (int i = 0; i < n; ++i)
		//집합에 포함된 i번째 원소와 같이 두었을 때 폭발하는 물질이 set에 있다면
		//주석이 이해하기 힘들다. 다시 적자면

		//집합에 i번째 원소가 존재하는 경우   &&   그 집합이 i번째 원소와 폭발하는 물질을 포함한다면
		if ((set & (1 << i)) && (set & explodes[i]))
			return false;
	return true;
}
// bitmask 를 안쓴다면 set 의 각 요소들을 가지고 set<int> inSet = {0, 4, 5, 8, 9, 11 ...}
// 충돌이 일어나는 것들 set<int> explodes[MAXN]
bool isStable(set<int>& inSet) {
	for (set<int>::iterator it = inSet.begin(); it != inSet.end(); ++it) {
		int node = *it;
		set<int>::iteratoor jt = explodex[node].begin();	// 한 원소와 폭발을 일으키는 다른 원소들을 순회
		for (; jt != explodes[node].end(); ++jt)
			if (inSet.count(*jt) > 0)
				return false;
			
	}
	return true;
}	// 테스트는 해봐야 겠지만 대충 3중 for 문이네.. set.count 를 써서 for를 줄인것 뿐

//모든 극대 안정 집합의 수를 센다.
int countStableSet() {
	int ret = 0;
	//모든 집합을 만들어 보자
	for (int set = 1; set < (1 << n); ++set) {
		//우선 안정적이 아니라면 셀 필요가 없다
		if (!isStable(set)) continue;
		//극대 안정 집합인지 확인하기 위해, 넣을 수 있는 다른 물질이 있나 확인한다.
		bool canExtend = false;
		for (int add = 0; add < n; ++add)
			//add가 set에 포함되어 있지 않고, set에 add를 넣어도 안정적(add와 상극인 집합과 set의 교집합이 없음)이라면
			//if ((set & (1 << add)) == 0 && isStable(set | (1 << add)) {
			if ((set & (1 << add)) == 0 && (set & explodes[add]) == 0) {
				//집합에 다른 원소 add를 넣을 수 있는지를 isStable()를 다시 호출하는
				//isStable(set | (1 << add))
				//대신에 explodes[add]&set 이 0인지만 확인하는 것을 눈여겨 보삼!!!!
				canExtend = true;
				break;
			}
		if (!canExtend)
			++ret;
	}
	return ret;
}
a, b, c, d 
{a, b}, {a, c}, {a, d}는 만나면 폭발할 시 극대 안정 집합(maximal stable set)을 구하라
" {a}, {b, c, d} "


//p590 졸업학기(문제 : GRADUATION 중) 생략

/******************* 17장 부분합 *******************************/
//p598 부분합을 계산하는 함수와 이를 이용해 구간합을 계산하는 함수의 구현
//주어진 벡터 a의 부분합을 계산한다.
vector<int> partialSum(const vector<int>& a) {
	vector<int> ret(a.size());
	ret[0] = a[0];
	for (int i = 1; i < a.size(); ++i)
		ret[i] = ret[i - 1] + a[i];
	return ret;
}
//어떤 벡터의 부분합 psum[]이 주어질 때, 원래 벡터의 a부터 b까지의 합을 구한다.
int rangeSum(const vector<int>& psum, int a, int b) {
	return (a == 0) ? psum[b] : psum[b] - psum[a - 1]; 
}
//variance : 분산(편차의 제곱의 평균)
//p599 특정 구간의 분산을 계산하기
//A[]의 제곱의 부분 합 벡터 sqpsum, A[]의 부분 합 벡터 psum이 주어질 때
//A[a..b]의 분산을 반환한다.
double variance(const vector<int>& sqpsum,
				const vector<int& psum,
				int a, int b) {
	//우선 해당 구간의 평균을 계산한다.
	double mean = rangeSum(psum, a, b) / double(b - a + 1);
	//먼저 편자의 제곱의 합을 구하기 : sigma((A[i] - m)^2) = sigma(A[i]^2 - 2A[i]m + m^2)
										//= sigma(A[i]^2) - 2m*sigma(A[i]) + sigma(m^2) 
										//= sigma(A[i]^2) - 2m*sigma(A[i]) + (b-a+1)*m^2
	double ret = rangeSum(sqpsum, a, b)				
				- 2 * mean * rangeSum(psum, a, b)
				+ mean * mean * (b - a + 1);
	//갯수만큼 나눠서 평균내자
	ret /= (b - a + 1);
	return ret;
}


//2차원으로 확장
//2차원 배열의 부분합을 미리 계산한다
vector<vector<int> > board;
vector<vector<int> > pSum;
void precalc(const vector<vector<int> >& board) {
	pSum = vector<vector<int> >(board.size(), vector<int>(board[0].size(), 0));
	pSum[0][0] = board[0][0];
	for (int i = 1; i < board.size(); ++i)		//y축
		pSum[i][0] = pSum[i - 1][0] + board[i][0];
	for (int j = 1; j < board[0].size(); ++j)	//x축
		pSum[0][j] = pSum[0][j - 1] + board[0][j];

	for (int i = 1; i < board.size(); ++i)
		for (int j = 1; j < board[0].size(); ++j) {
			pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + board[i][j];
		}

}
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1
1 1 1 1 1 1 
1 1 1 1 1 1

1 2 3 4 5 6
2 4 6 8 10 12
3 6 9 12
4
5
6

//(2, 3)까지의 합을 구하려면
//(2, 2)까지의 합인 9 + (1, 3)까지의 합인 8
// - (1, 2)까지의 합인 6
// + (2, 3)의 보드 값인 1
// = 12
void main() {
	board = vector<vector<int> >(10, vector<int>(10, 1));

	precalc(board);

	for (int i = 0; i < pSum.size(); ++i)
		for (int j = 0; j < pSum[i].size(); ++j) {
			if (j == 0) 
				cout << endl;
			cout << pSum[i][j] << " ";
		}
	
}

//p601 2차원 배열의 구간 합을 구하는 함수
//sum(y1, x1, y2, x2) = psum[y2, x2] - psum[y2, x1 - 1] - psum[y1 - 1, x2] + psum[y1 - 1, x1 - 1] //!!!!
//어떤 2차원 배열 A[][]의 부분합 psum[][]이 주어질 때,
//A[y1, x1]과 A[y2, x2]를 양 끝으로 갖는 부분 배열의 합을 반환한다.
int gridSum(const vector<vector<int> >& psum, int y1, int x1, int y2, int x2) {
	int ret = psum[y2][x2];
	if (y1 > 0) ret -= psum[y1 - 1][x2];
	if (x1 > 0) ret -= psum[y2][x1 - 1];
	if (y1 > 0 && x1 > 0) ret += psum[y1 - 1][x1 - 1];
	return ret;
}


//1차원 배열 부분합이 0에 가장 가까운 구간
sigma(i,j)A[k] = psum[j] - psum[i - 1]; 이 값이 0에 가까우면 됨
int calc(const vector<int>& psum, int& hi, int& lo) {
	int leastSum = INF;
	for (int i = 0; i < psum.size(); ++i) {
		for (int j = i; j < psum.size(); ++j) {
			int sum = psum[j] - (i == 0 ? 0 : psum[i - 1]);
			sum = abs(sum);
			if (leastSum > sum) {
				hi = j;
				lo = i;
				leastSum = sum;
			}
		}
	}
	return leastSum; //가장 0에 가까운 구간합의 절대값이 리턴됨
}

//다시 짜보자
0에 가깝다는 말은 psum[]의 두 값의 차이가 가장 적다는 뜻이다.
pair 형태로 (psum[i], i) 만든 후
정렬한 다음 거기서 두 차가 가장 적은 (psum[a], a), (psum[b], b) 를 찾는다.
그런면 답후보 1은 lo = a, hi = b인 구간이 된다.
답후보 2는 인접원소 하나짜리를 의미하며 O(n)으로 탐색가능하다//할 필요 있을까 싶네 후보1로도 충분해 보이는뎅..
후보1, 후보2 를 비교해서 정답을 세팅한다.



//크리스마스 인형 문제 CHRISTMAS : 중 
//테스트 C<=60, 첫번째 줄 인형상자의 개수 N, 어린이 수 K (1<=N, K <= 100000)
//두번째 줄에는 0번 인형상자 부터 N-1번 인형 상자 까지 각 인형 상자에 들어 있는
//인형의 개수 Di가 주어짐 (Di<=100000)

//K명의 어린이에게 인형을 사주기. N개의 인형 상자가 한 줄로 진열되어 있고
//각 인형상자에는 하나 이상의 인형이 들어 있음
//주문은 h상자부터 t번 상자까지 다주세요 이며 K명에게 정확히 같은 수만큼 나누어 떨어져야함

//원하는 출력
//1. 한 번	주문할 수 있다면, 가능한 주문 방법의 갯수는 몇가지인가?
//2. 여러번 주문할 수 있다면 주문이 겹치지 않게 최대 몇 번 주문할 수 있을까?
// (7 - 4) mod 3 = (7 mod 3) - (4 mod 3) = 0
"아이디어 (psum[T] - psum[H-1]) mod K = 0  =>  psum[T] mod K = psum[H-1] mod k //!!!!"
2
6 4		//인형상자의 수, 어린이의 수
1 2 3 4 5 6 
4 1
1 2 3 4

출력
3 1
10 4
//점화식 좋네!!!! 책보고 적으삼
//p605 부분합을 이용해 크리스마스 인형 문제를 해결하는 두 함수의 구현
k = 5
index	0 1 2 3 4 5 6 7 8 9 a
		0 1 1 1 1 1 1 1 1 1 1 
psum	0 1 2 3 4 0 1 2 3 4 0			psum[2] == psum[7] : psum[7 ~ 3] 은 5에 나누어 떨어진다.
count	0 1 2 3 4
		3 2 2 2 2	
//D[]의 부분 합 배열 psum[]과 k가 주어질 때, 몇가지 방법으로 살 수 있는지 반환한다.
//psum[]의 첫 번째 원소 전에 0을 삽입했다고 가정한다.!!!!
int waysToBuy(const vector<int>& psum, int k) {
	const int MOD = 20091101;
	int ret = 0;
	//psum[]의 각 값을 몇 번이나 본 적 있는지 기록한다.
	vector<long long> count(k, 0);
	for (int i = 0; i < psum.size(); ++i)
		count[psum[i]]++;
	//두 번 이상 본 적 있다면 이 값 중 두개를 선택하는 방법의 수를 더한다.
	for (int i = 0; i < k; ++i)
		if (count[i] >= 2) {
			ret = ret + (count[i] * (count[i] - 1)) / 2;
			ret %= MOD;
		}
	return ret;
}
//두 부분합(mod k화 된) 구간이 같다면
//차이는 k에 대해 나누어 떨어짐을 의미한다!!!!

//갑자기 생각난 mod 성질(맞는지 잘 모르겠지만 맞는거 같다)
(7 * 13) mod 5 = 1
((7 mod 5) * (13 mod 5)) mod 5 = 1

int wayToBuy(const vector<int>& psum, int k) {
	const int MOD = 20011101;
	int ret = 0;
	vector<long long> count(k, 0);
	for (int i = 0; i < psum.size(); ++i)
		count[psum[i]]++;
	for (int i = 0; i < k; ++i)
		if (count[i] >= 2) {
			int cal = count[i] % MOD * (count[i] - 1) / 2;
			ret = (ret + cal) % MOD;
		}
}

//2. 여러번 주문할 수 있다면 주문이 겹치지 않게 최대 몇 번 주문할 수 있을까?
//D[]의 부분 합 배열 psum[]과 k가 주어질 때, 겹치지 않게 몇 번이나 살 수 있는지 반환한다.
//psum[]의 첫 번째 원소 전에 0을 삽입했다고 가정한다.!!!!
int maxBuys(const vector<int>& psum, int k) {
	//ret[i] = 첫 번째 상자부터 i번째 상자까지 고려했을 때 살 수 있는 최대 횟수
	vector<int> ret(psum.size(), 0);
	//prev[s] = psum[]이 s였던 마지막 위치
	vector<int> prev(k, -1);
	for (int i = 0; i < psum.size(); ++i) {
		//i번째 상자를 아예 고려하지 않는 경우
		if (i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;
		//psum[i]를 전에도 본 적이 있으면, prev[psum[i]] + 1 부터 여기까지 쭉 사 본다. !!!! 중요포인트
		int loc = prev[psum[i]];
		if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
		//prev[]에 현재 위치를 기록한다
		prev[psum[i]] = i;
	}
	return ret.back();
}

/* 고찰: 나의 오해 psum[1] == psum[2] == psum[3] 인데 1,2를 선택하면 2,3은 겹치는게 아닌가
		 1,2를 선택하면 1에서 하나 더한 것부터 2까지의 부분합을 의미하므로 1은 포함되는게 아니다.
		 마찬가지로 2,3을 선택하면 3하나만 의미하게 된다.
		 만약 2,5를 선택하는 경우가 있다면 3부터 5까지의 부분합이 된다.
점화식
ret[i] = max{ret[i - 1],
			 ret[prev[psum[i]]] + 1    (prev[psum[i]] = -1 : 이전에 한번이상 출현해야함)
imagine 1) : k = 6
index	= 0 1 2 3 4 5 6 7 8 9 a b c ..
          0 2 6 6 7 6 6 5 6 6 7 6 6
psum(%)	=   2 2 2 3 3 3 2 2 2 3 3 3	 
ret		= 0 0 1 2 2 3 4 4 5 6 6 7 8
ret[7]의 값을 구하는 과정
ret[7] = max(ret[7 - 1]													    = 4, //win 
			 ret[prev[psum[7]]] + 1 = ret[prev[2]] + 1 = ret[3] + 1 = 2 + 1 = 3
//prev[psum[7]] 이 있는 최근 위치는 index 3이 된다

imagine 2)
index	= 0 1 2 3 4 5 ..
psum(%)	=   2 2 2 3 2
ret		= 0 0 1 2 2 3
ret[5]의 값을 구하는 과정
ret[5] = max(ret[5 - 1]														= 2,
			 ret[prev[psum[5]]] + 1 = ret[prev[2]] + 1 = ret[3] + 1 = 2 + 1 = 3 //win
*/


/******************* 18장 동적 배열과 연결 리스트의 비교 *******************************/
struct ListNode {
	int element; //담고 있는 원소
	ListNode *prev, *next; //이전 노드, 다음 노드의 포인터
};

//연결 리스트에서 노드를 삭제하고 다시 추가하기 : 이 연산은 프로그램을 되돌리기(undo)연산을 지원하는 데
//유용하게 쓸 수 있습니다. 물론 삭제한 순서의 반대로 복구가 이루어질 때만 사용할 수 있습니다.

//node 이전/이후 노드의 포인터를 바꿔서 node를 리스트에서 삭제한다.
void deleteNode(ListNode* node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
}
//node 이전/이후 노드의 포인터를 바꿔서 자기 자신을 다시 리스트에 삽입한다.
void recoverNode(ListNode* node) {
	node->prev->next = node;
	node->next->prev = node;
}

//p620 조세푸스 JOSEPHUS 하
//N명의 사람들이 모두 원형으로 둘러선 뒤 순서대로 자살
//한 사람이 자살하면, 다음에는 그 사람으로부터 시계방향으로 k번째 살아있는 사람이 자살
//병사 2명만 살아남으면 이들은 마음을 바꿔 항복해서 살아남
//이 때 병사 번호를 오름 차순 순으로 출력해라(번호는 첫번째 병사가 1번 그다음은 시계방향으로 정해짐)
2
6 3
40 3
출력
3 5
//알고리즘은 별루지만 그냥 리스트 사용방법이나 보자는 의미에서 적는다.
//p622 연결 리스트를 이용한 조세푸스 문제의 구현
void josephus(int n int k) {
	//리스트를 준비한다.
	list<int> survivors;
	for (int i = 1; i <= n; ++i) survivors.push_back(i);
	//이번에 죽을 사람을 나타내는 포인터
	list<int>::iterator kill = survivors.begin();
	while(n > 2) {
		//첫 번째 사람이 자살한다. erase() 는 지운 원소의 다음 원소를 반환한다.(정확히는 iterator를 반환한다.)
		//!!!!
		kill = survivors.erase(kill);
		if (kill == survivors.end()) kill = survivors.begin();
		--n;
		//위에서 1칸 이동했으니 여기선 k -1 번 이동시킨다.
		//(남은 사람n이 많이 줄어든 상태에서 k가 무지 크다면 ex : 3명 남은 상태에서 k가 1000이라면
		//1000 % 3 => 1 로 이동을 줄일 수 있으니 시간 나면 구현해보삼
		for (int i = 0; i < k - 1; ++i) {
			++kill;
			if (kill == survivors.end()) kill = survivors.begin();
		}
		//int kMod = (k - 1) % n;
		//for (int i = 0; i < kMod; ++i) { ++kill; ~~ }
	}
	cout <<survivors.front() << " " << survivors.back() << endl;
}

/******************* 19장 큐와 스택, 데크 *******************************/
<성준이 머리 난이도 상>
"평면스워핑"
//스택을 이용한 울타리 자리그 문제의 해법(울타리 자르기 분할 정복 : NlgN => 스위핑 + 스택 : N)
//p632  스택을 사용해 울타리 자르기 문제를 해결하는 스위핑 알고리즘
"이해의 핵심: 오름차순으로 스택에 쌓는것을 기억해라, 오름차순이 이루어지지 않으면 pop시킨다"
//각 판자의 높이를 저장하는 배열
vector<int> h;
//스택을 사용한 O(n)해법
int solveStack() {
	//남아 있는 판자들의 위치들을 저장한다.
	stack<int> remaining;
	h.push_back(0);	//판자들의 가장 오른쪽에 높이가 0인 가상 판자를 둔다.
	int ret = 0;
	for (int i = 0; i < h.size(); ++i) {
		//남아 있는 판자들 중 오른쪽 끝 판자가 h[i] 보다 높다면
		//이 판자의 최대 사각형은 i에서 끝난다.
		"이해의 핵심: pop 할때마다 넓이가 계산된다 !!!!"
		while (!remaining.empty() && h[remaining.top()] >= h[i]) {
			int j = remaining.top();	// j 를 기준으로 
										// 왼쪽: remaining.top() + 1 까지는 높이가 현 높이 이상이다.
										// 오른쪽: i - 1 까지도 높이가 현 높이 "초과"한다.
			remaining.pop();
			int width = -1;
			//j번째 판자 왼쪽에 판자가 하나도 안 남아 있는 경우 left[j] = -1,
			//아닌 경우 left[j] = 남아 있는 판자 중 가장 오른쪽에 있는 판자의 번호가 된다.
			if (remaining.empty())
				width = i;
			else
				width = (i - remaining.top() - 1);	// (i - 1) ~ (remaining.top + 1) 까지의 길이
			ret = max(ret, h[j] * width);
		}
		//while문이 한번 수행될 때마다 remaining에서 원소가 하나 빠지는데ㅎ
		//remaining에는 정확히 N개의 원소가 들어가기 때문에 while 문의 총 수행 회수는
		//O(N)입니다.(i=0 while, i=1 while, ... , i=h.size()-1 while 의 수행의 합)
		remaining.push(i);
	}
	return ret;
}

// 현 remaining.top 과 같은 높이가 들어오면 현 remaining.top 을 pop 한다.
// pop 되는 놈을 기준으로 imagine
왼쪽기준 -------- pop 되는 놈 ---------- 오른쪽기준	// 부연 설명
	왼쪽기준: pop 되는 놈보다 높이가 낮다. 			// "왼쪽기준 + 1" 부터 "pop 되는놈 -1" 까지는 높이가 현 높이(h[pop]) 이상이다.
	오른쪽기준: pop 되는 놈보다 높이가 낮거나 같다.	// "pop 되는놈 +1" 부터 "i - 1" 까지는 높이가 현 높이(h[pop]) 초과이다.
	
	h[왼쪽] ------- h[pop] --------- h[i]
	
   -   -
  - - - - -
 -   -   - --		<--- 이부분의 높이 처리는// 같은 높이가 들어올때마다 이전놈은 버려진다.
-	         -
              -
			 
// 안보고 1년 뒤 아무 생각 없이 내가 짠 코드.
int main() {
	int cs;	cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vi arr(n);
		rep(i, n) cin >> arr[i];
		arr.push_back(0);
		int sol = 0;
		stack<int> st;
		for (int i = 0; i < arr.size(); ++i) {
			int begin = -1;
			int height = 0;
			if (st.size()) {
				begin = st.top();
				height = arr[begin];
			}
			if (height <= arr[i])
				st.push(i);
			else {
				while (true) {
					if (st.size() == 0) break;
					begin = st.top();
					height = arr[begin];
					if (height <= arr[i]) break;
					st.pop();
					int prevBegin = -1;
					if (st.size()) prevBegin = st.top();
					// begin = i - 1 부터 preBegin + 1 까지의 
					// 차지하는 영역 !!!!
					sol = max(sol, (i - prevBegin - 1) * height);
				}
				st.push(i);
			}
			
		}
		cout << sol << '\n';
	}
	return 0;
}



//짝이 맞지 않는 괄호 BRACKETS2, 난이도 하
3
()()		=>	YES
({[}])		=>	NO
({}[(){}])	=>	YES
//p635 스택을 이용해 짝이 맞지 않는 괄호 문제를 해결하는 알고리즘의 구현
bool wellMatched(const string& formula) {
	//여는 괄호 문자들과 닫는 괄호 문자들
	const string opening("({[");
	const string closing(")}]");
	//이미 열린 괄호들을 순서대로 담는 스택
	stack<char> openStack;
	for (int i = 0; i < formula.size(); ++i) {
		// 여는 괄호인지 닫는 괄호인지 확인한다.
		if (opening.find(formula[i]) != -1)
			//여는 괄호라면 무조건 스택에 집어넣는다.
			openStack.push(formula[i]);
		else {
			//이 외의 경우 스택 맨 위의 문자와 맞춰보자
			//스택이 비어 있는 경우에는 실패
			if (openStack.empty()) return false;
			//서로 짝이 맞지 않아도 실패
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			//짝을 맞춘 괄호는 스택에서 뺀다.
			openStack.pop();
		}
	}
	//닫히지 않은 괄호가 없어야 성공
	return openStack.empty();
}

//p639 외계신호 분석 생략: 책 오류가 있음 

/******************* 20장 문자열 *******************************/
//단순한 문자열 검색 알고리즘의 구현
//p645 짚더미 H에서 바늘 N 이 출현하는 시작 위치들을 모두 반환하는 알고리즘.
vector<int> naiveSearch(const string& H, const string& N) {
	vector<int> ret;
	//모든 시작 위치를 다 시도해 본다.
	for (int begin = 0; begin + N.size() <= H.size(); ++begin) {
		bool matched = true;
		for (int i = 0; i < N.size(); ++i)
			if (H[begin + i] != N[i]) {
				matched = false;
				break;
			}
		if (matched) ret.push_back(begin);
	}
	return ret;
}
<성준이 머리 난이도 상>
//p649 kmp문자열 검색 알고리즘의 구현
//짚더미 H에서 바늘 N 이 출현하는 시작 위치들을 모두 반환
//KMP : 최대동일접두접미사를 이용해서 O(H)시간에 문자열 검색을 한다!!!!
vector<int> kmpSearch(const string& H, const string& N) {
	int h = H.size(), n = N.size();
	vector<int> ret;
	//pi[i] = N[..i]의 (진) 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> pi = getPartialMatch(N); //이 함수의 구현은 뒤에 보라
	//begin = matched = 0에서부터 시작하자
	int begin = 0, matched = 0;
	while (begin <= h - n) {	//while (begin + n <= h)
		//만약 집더미의 해당 글자가 바늘의 해당 글자와 같다면
		if (matched < n && H[begin + matched] == N[matched]) {
			++matched;
			//결과적으로 n글자가 모두 일치했다면 답에 추가한다.
			if (matched == n) ret.push_back(begin);
		}
		else {
			//예외:matched가 0인 경우에는 다음 칸에서부터 계속
			if (matched == 0)
				++begin;
			else {
				begin = begin + matched - pi[matched - 1];
				//begin을 옮겼다고 처음부터 다시 비교할 필요가 없다.
				//옯긴 후에도 pi[matched - 1]만큼은 항상 일치하기 때문이다.
				
				// ex: 현재 5개가 일치된 상태고 pi[5 - 1] 는 2 라고 한다면 : aabaa
				// begin = begin + 5 - 2;		: aabaa 에서 앞의 aab 는 필요없게 된다.!!!!!!!!
				// begin = begin + 3 이 된다.		
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
H: aaaaaaaa
N: aaaa
matched = 4라면 
	matched = pi[matched - 1] = 3
	begin = begin + matched - pi[matched - 1] = 0 + 4 - 3 = 1

H: aabaabaabaab
N: aabaaba
matched = 7이라면
	matched = pi[matched - 1] = aabaaba 의 최대동일접두접미사: aaba = 4
	begin = begin + matched - pi[matched - 1] = 0 + 7 - 4 = 3

H: aaaabaab
N: aabaa
begin = 0이고 mached = 2인 상태에서
	H[begin + matched] = a =!= b = N[matched] 가 된다.
	begin = begin + matched - pi[matched - 1] = 0 + 2 - 1 = 1
	matched = pi[matched - 1] = 1
다음 검사는
	H[begin + matched] = H[1 + 1] = H[2]
	N[matched] = N[1]  "이 두개를 검사하게 된다."

//p652 단순한 문자열 알고리즘을 이용해 부분 일치 테이블 계산하기
//제일 무식은 N[..i]의 최대동일접두접미사를 찾는 것이니 
//O(i횟수 *  한 단어에 대한 mips구하기) = O(N^3)
//아래는 그것을 개선한 O(N^2)의 수행시간이 걸린다. (음.. aaaa...aaaa 같은 경우 확실히 N^2이겠굼.)
//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산한다.
//pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatchNaive(const string& N) {
	int n = N.size();
	vector<int> pi(n, 0);
	//단순한 문자열 검색 알고리즘을 구현한다.
	for (int begin = 1; begin < n; ++begin) {
		for (int i = 0; i < n; ++i) {
			if (N[i] != N[begin + i]) break;
			//i + 1 글자가 서로 대응되었다.
			pi[begin + i] = max(pi[begin + i], i + 1);
		}
	}
	return pi;
}
//O(N^2) 원리
/*
			0 1 2 3 4 5 6 7
Needle		a a b a a b a c
begin = 1	  a x	
begin = 2		x
begin = 3	      a a b a x => pi[3] = 1, pi[4] = 2, pi[5] = 3, pi[6] = 4
begin = 4			a x		=> pi[4 + 0] = max(pi[4 + 0], 0 + 1) = max(2, 1) = 2
begin = 5			  x
begin = 6			    a x	  
*/
aabaabaabaa
//p653 kmp알고리즘을 이용해 부분 일치 테이블을 생성하기
"핵심 아이디어: 바늘에서 바늘찾기"
//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산한다.
//pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N) {
	int n = N.size();
	vector<int> pi(n, 0);
	//kmp로 자기 자신을 찾는다.
	//N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안됨!!!!
	int begin = 1, matched = 0;
	//비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while (begin + matched < n) {
		if (N[begin + matched] == N[matched]) {		//a
			++matched;								
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)						//b
				++begin;						
			else {									//c
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
//시뮬
a: ++ma, pi[be+ma-1] = ma
b: ++be
c: be = be + ma - pi[ma-1], ma = pi[ma-1]
ex1)
index 0 1 2 3 4 5 6 7 8
      a a b a a b a c d		op	be		ma		be+ma-1			
		*					a	1		0->1	pi[1+1-1] = pi[1] = 1(ma)
		  *					c	1->2	1->0	
		  *					b	2->3	
		    *				a			0->1	pi[3+1-1] = pi[3] = 1(ma)
			  *				a			1->2	pi[3+2-1] = pi[4] = 2(ma)
			    *			a			2->3	pi[3+3-1] = pi[5] = 3(ma)
				  *			a			3->4	pi[3+4-1] = pi[6] = 4(ma)
				    *		c	3->6	4->1
					*		c	6->7	1->0
					*		b	7->8
					  *		b	8->9

ex2)
index 0 1 2 3 4 5
	  a a a a c a			op	be		ma		be+ma-1
		*					a	1		0->1	pi[1+1-1] = pi[1] = 1(ma)
		  *					a	1		1->2	pi[1+2-1] = pi[2] = 2(ma)
		    *				a	1		2->3	pi[1+3-1] = pi[3] = 3(ma)
			  *				c	1->2	3->2
			  *				c	2->3	2->1
			  *				c	3->4	1->0
			  *				b	4->5
				*			a			0->1	pi[5+1-1] = pi[5] = 1(ma)



//p654 접두사/접미사(NAMING, 하)
//S = "ababbaba"
//output : 1, 3, 8(=|S|)
//s의 접두사도 되고 접미사도 되는 모든 문자열의 길이를 계산하기
//무식하면 O(|S|^2) 이겠지만 우리에겐 부분일치테이블 함수가 있지
vector<int> getPrefixSuffix(const string& s) {
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while (k > 0) {
		//s[..k-1]는 답이다. (원본도 포함이넹~~)
		ret.push_back(k);
		//s[..k-1]의 (진)접미사도 되고 (진)접두사도 되는 문자열도 답이다.
		k = pi[k-1];
		//pi[0] = 1글자에 대하여 (진)접미사, (진)접두사의 길이는 0임
	}
	return ret;
}
abababa
a[6]		= 5(ababa)
a[5 - 1]	= 3(aba)
a[3 - 1]	= 1(a)
a[1 - 1]	= 0

//가능한 짧은 펜린드롬 만들기(PALINDROMIZE, 하)
//S의 역순 문자열 S' 가 있다는 가정하에
//S의 접미사이면서 S'의 접두사가 되는 문자열의 최대 길이를 계산하자
//p655 펜린드롬 만들기 문제를 해결하는 KMP알고리즘의 변형
//a의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다.
int maxOverlap(const string& a, const string& b) {
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);
	//begin = matched = 0에서 부터 시작하자.
	int begin = 0, matched = 0;
	while (begin < n) { //원본과 비교시: 시작위치의 제한이 없군요
		//만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if (matched < m && a[begin + matched] == b[matched]) {
			++matched;
			if (begin + matched == n)
				return matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}
// 012345678
// abbbcbbbb
//  bbbbcbbba	//a[4] != b[3], bbb의 mips는 bb
//   bbb		//(a[2], b[0]), (a[3], b[1])비교는 생략하고 
//     _ 여기서부터 비교 즉 a[4], b[2] 를 비교한다.

// 내가 안보고 짠 코드다. 알고스팟 통과함 44ms 와우.
"일관성이 있어 더 좋다고 생각하는 코드" 자랑~
vi getTable(cs& str) {
	int n = str.size();
	vi ret(n, 0);
	int begin = 1, matched = 0;
	while (begin + matched< n) {		// 위 kmp 랑 조건(begin + n <= h) 다른 이유는?
										// 뭐 begin + matched 로 접근시 주소 초과가 되겠네..
		if (str[begin + matched] == str[matched]) {
			matched++;
			ret[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin = begin + matched - ret[matched - 1];
				matched = ret[matched - 1];
			}
		}
	}
	return ret;
}
int getLongestOverlap(cs& str, cs& rev) {
	vi table = getTable(rev);
	int begin = 0, matched = 0;
	// begin + matched == rev.size() 가 되는 순간 종료한다.
	// 원래는 str.size() 를 써야 되는데 둘은 동일한 사이즈니 상관이 없다.
	// 만약 사이즈가 다른 놈들(strA뒤에 strB를 오버랩) 을 붙여야 한다면
	// strA의 suffixe 를 구한다.(strB사이즈만큼)
	// 그뒤 이 알고리즘을 돌리면 된다. strA 의 앞대가리는 따로 처리하는 거지.
	while (begin + matched < rev.size()) {
		if (str[begin + matched] == rev[matched]) {
			matched++;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin = begin + matched - table[matched - 1];
				matched = table[matched - 1];
			}
		}
	}
	return matched;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		string str;
		cin >> str;
		string rev = str;
		reverse(rev.begin(), rev.end());
		int sol = getLongestOverlap(str, rev);
		sol = str.size() * 2 - sol;
		cout << sol << endl;
	}
	return 0;
}


//p657 kmp알고리즘의 다른 구현
vector<int> kmpSearch2(const string& H, const string& N) {
	int h = H.size(), n = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	//현재 대응된 문자 캐릭의 수
	int matched = 0;
	//짚더미의 각 글자를 순회한다.
	for (int i = 0; i < h; ++i) {
		//matched번 글자와 짚더미의 해당 글자가 불일치할 경우,
		//현재 대응된 글자의 수를 pi[matched - 1]로 줄인다.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		//글자가 대응될 경우
		if (H[i] == N[matched]) {
			++matched;
			if (matched == n) { //바늘을 찾은 경우
				ret.push_back(i - n + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

//재하의 금고 (JAEHASAFE, 중)
금고는 시계 반시계 시계 ... 이런 순으로 계속 돌려야 함
금고를 열기위해 맞춰야 하는 상태의 수는 (1 <= N <= 100)
문자열의 길이는 10000이하의 자연수 흐미...길다.
//P641 O(L) 문자열의 길이에 비례함
int shifts(const string& original, const string& target) {
	return kmpSearch(original + original, target)[0];
}
"반시계의 경우 매개변수를 바꾸어 호출하면 된다"
shifts(target, original);
//a를 시계 방향으로 돌려 b를 만드는 데 필요한 칸의 수나, b를 반시계 방향으로 돌려
//a를 만드느 데 필요한 칸의 수가 같기 때문이다.!!!!
abcdef 를 반시계방향으로 2칸 돌려(왼쪽으로 쉬프팅) cdefab를 만드는 것은
cdefab 를 시계방향으로 2칸 돌려(오른쪽으로 쉬프팅) abcdef를 만드는 것!!!!

orgtrgorgtrg
trgorg
 trgorg
  trgorg
   trgorg

trgorgtrgorg
orgtrg
 orgtrg
  orgtrg
   orgtrg

long long shift(cs& org, cs& trg) {
	return kmp(org + org, trg)[0];
}
int main() {
	ios::sync_with_stdio(false);
	int cs;
	cin >> cs;
	string str1, str2;
	rep(cc, cs) {
		int n; cin >> n;
		cin >> str1;
		long long sum = 0;
		rep(i, n) {
			cin >> str2;
			if (i % 2 == 0) {
				long long Rshift = shift(str2, str1);
				sum += Rshift;
			}
			else {
				long long Lshift = shift(str1, str2);
				sum += Lshift;
			}
			str1 = str2;
		}
		cout << sum << '\n';
	}
	return 0;
}
   
   
//---------------------------------//
//접미사 배열!!!! (suffix array) 문자열의 맥가이버 칼임 유용하다
//접미사 배열: 어떤 문자열 S의 모든 접미사들을 사전순으로 정렬해 둔 것
(모든 접미사를 저장하면 용량이 커지므로 시작위치를 저장)
//문자열 "alohomora"의 접미사 배열 A[]와 각 위치에서 시작하는 접미사
	0 1 2 3 4 5 6 7 8
	a l o h o m o r a

i	A[i](접미사의 시작위치)		S[A[i]..]
0	A[0] = 8					a
1	A[1] = 0					alohomora
2	A[2] = 3					homora
3	A[3] = 1					lohomora
4	A[4] = 5					mora
5	A[5] = 2					ohomora
6	A[6] = 4					omora
7	A[7] = 6					ora
8	A[8] = 7					ra

//p663 접미사 배열을 계산하는 단순한 알고리즘
//(모든 접미사를 만드는 것은 공간 낭비이기에 인덱스를 가지고 정렬 수행)
//두 접미사의 시작 위치 i, j 가 주어질 때 두 접미사 중 어느 쪽이 앞에 와야 할지 비교한다.
struct SuffixComparator {
	const string& s;	//!!!! 멤버 상수 레퍼런스... 익숙치 않은 형태네...
	SuffixComparator(const string& s) : s(s) {}	//상수는 이걸루 초기화
	bool operator() (int i, int j) {	//!!!! 비교자 
		"i, j는 배열의 인덱스가 아닌 값이다 perm의 값임..."
		"perm을 전부 0으로 설정하니 i,j는 전부 0이됨요"
		//s.substr() 대신에 strcmp()를 쓰면 임시 객체를 만드는 비용이 절약된다.
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
		//strcmp(A, B) < 0 에서 strcmp(A, B)의 리턴값은
		//A < B		=> 음수
		//A == B	=> 0
		//A > B		=> 양수
		//substr(A) < subStr(B) 랑 같은 표현
	}
	//비교자의 호출
	//SuffixComparator test(s);	//Function call operator () overloading
	//test(1, 4);	//비교자가 호출된다.
};
//s의 접미사 배열을 계산한다.
vector<int> getSuffixArrayNaive(const string& s) {
	//접미사 시작 위치를 담은 배열을 만든다.
	vector<int> perm;
	for (int i = 0; i < s.size(); ++i) perm.push_back(i);
	//접미사를 비교하는 비교자를 이용해 정렬하면 완성!!!!
	sort(perm.begin(), perm.end(), SuffixComparator(s));
	//클래스를 넘기네: sort 함수가 요 클래스의 멤버연산자함수 '()' 를 이용한다.
	"멤버연산자 함수에 들어가는 인수들은 perm의 값이 된다"

	return perm; 
	//복잡도는 sort()는 O(nlgn)번 비교를 수행하고 한번 비교시 O(n)이크로
	//전체 시간 복잡도는 O(nnlgn)이 된다.
}

SuffixComparator test(s);
sort(perm.begin(), perm.end(), test);

struct FC {
	bool operator() (int i, int j) { 
		"인덱스가 아닌 값이 들어옵니다."
		return i < j; 
	}
};
int main() {
	vi arr;
	rep(i,8) arr.pb(8 - i); //8,7,6,5,4,3,2,1
	sort(arr.begin(), arr.end(), FC()); //1,2,3,4,5,6,7,8
}

0 1 2 3 4 5 6 7 8 9
m i s s i s s i p i
//멘버-마이어스 알고리즘 원리(첫글자 인덱스, 그룹번호)

첫 한글자 기준			첫 두글자 기준			첫 네들자 기준			첫 여덟 글자 기준
		  perm group			  perm group			  perm group
ississipi	1	0		i			9	0		i			9	0		i			9	0
issipi		4	0		ipi			7	1		ipi			7	1		ipi			7	1
ipi			7	0		ississipi	1	2		ississipi	1	2		issipi		4	2
i			9	0		issipi		4	2		issipi		4	2		ississipi	1	3
mississipi	0	1		mississipi	0	3		mississipi	0	3		mississipi	0	4
pi			8	2		pi			8	4		pi			8	4		pi			8	5
ssissipi	2	3		sissipi		3	5		sipi		6	5		sipi		6	6
sissipi		3	3		sipi		6	5		sissipi		3	6		sissipi		3	7
ssipi		5	3		ssissipi	2	6		ssipi		5	7		ssipi		5	8
sipi		6	3		ssipi		5	6		ssissipi	2	8		ssissipi	2	9

//첫 두글자 기준(두 글자까지로 정렬된 상태)에서 첫 네글자 기준으로 진행하기 위해선
//4-2 남은 글자 2개를 반드시 비교해야 한다고 생각했었다.
//허나 접미사들의 정렬이기 때문에 남은 글자 2개애 대해서도 비교가 한번에 가능하다

첫 두글자 기준의 실제 그룹 배열은 다음과 같다
index	그룹번호
0		3
1		2
2		6
3		5
4		2
5		6
6		5
7		1
8		4
9		0
10		-1
이 상태에서 첫 네글자 기준 정렬을 수행하는 경우
sissipi와 sipi는 앞 두글자가 같다. 따라서 남은 두 글자를 비교해야 한다.
남은 두글자를 포함한 각각의 글자는 ssipi, pi이다
근디 이놈들은 이미 두 글자 기준으로 정렬된 놈들이다.
//문자열의 접미사 시작번호인 3과 6에 2식 더하자. 5와 8이 나온다!!!!
그걸로 접미사 ssipi, pi의 대소관계를 바로 찾을수 있다. group[5] = 6, group[8] = 4
따라서  sissipi 는 sipi보다 뒤에 오게 된다.

//p666 첫 t글자로 묶인 그룹 정보를 이용해 첫 2t글자를 비교하는 비교자의 구현
//각 접미사들의 첫 t글자를 기준으로 한 그룹 번호가 주어질 때,
//주어진 두 접미사를 첫 2*t글자를 기준으로 비교한다.
//group[]은 길이가 0인 접미사도 포함한다.
<성준이 머리 난이도 상>
struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}
	bool operator() (int a, int b) {
		//첫 t글자가 다르면 이들을 이용해 비교한다.
		if (group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
		"총 10글자라는 가정하에 t가 8인 경우 a, b는 0, 1 외엔 불가능"
		"0, 1 외에는 group[a], group[b] 값이 다르다.  
		"group[a + t]에서 a + t가 배열 크기를 넘지 않고 따라서 안전하다"
	}
};
//p667 접미사 배열을 계산하는 맨버와 마이어스의 알고리즘 O(n(lgn)^2)
vector<int> getSuffixArray(const string& s) {
	int n = s.size();
	//group[i] = 접미사들을 첫 t글자를 기준으로 정렬했을 때, S[i..]에 해당하는 그룹 번호
	//t = 1일 때는 정렬할 것 없이 S[i..]의 "첫 글자"로 그룹 번호를 정해도 같은 효과가 있다
	//첫글자가 같으면 같은 그룹이네요~
	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; ++i) group[i] = s[i];//그룹에 글자(char)가 대입되넹
	group[n] = -1;
	//결과적으로 접미사 배열이 될 반환 값, 이 배열을 lg(n)번 정렬한다.
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;
	while (t < n) {	//lg(n)번 수행되겠지
		//group[]은 첫 t글자를 기준으로 계산해 뒀다.
		//첫 2t글자를 기준으로 perm을 다시 정렬한다.
		//최초(t == 1)일 때 동작은 1글자_group으로 2글자까지 접근하여 perm을 정렬한다
		//perm은 즉 2글자 기준 정렬이 만들어진다.(무정렬->2글자 기준 정렬)
		//그 뒤론 2->4글자 기준 정렬, 4->8글자 기준 정렬 이렇게 된다. (처음이 무지 헷갈렸다)

		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);	//그룹번호를 가지고 정렬한다.
		//2t 글자가 n을 넘는다면 이제 접미사 배열 완성
		t *= 2;
		if (t >= n) break;
		//2t글자를 기준으로 한 그룹 정보를 다시 만든다.(핵심)!!!!
		vector<int> newGroup(n + 1); //왜 한개 더 있는 거냥?
		newGroup[n] = -1;			//한 문자글자는 좆되니까 이지!!!!(음..그래도 while에서 걸리잖소!!!)
									//그냥 의미없는 방어코든가...아니다!
									//bb를 생각해보자. 접미사 bb, b를 비교한다면 t가 1일때
									//b는 이다음 그룹이 오버되는 구나: t가 꼭 1일때만 타는게 아니다. 아래 설명 보삼.
									// 접미사의 길이가 딱 t 인 경우랑 그걸 초과한 길이의 놈과 비교할때
									// 길이가 딱 t인 놈을 위해 필요하다.!!!!!!!!
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; ++i)
			//비교자가 호출된다.(객체.멤버함수: 멤버함수가 호출, 객채(): 비교자가 호출 )!!!!
			if (compareUsing2T(perm[i - 1], perm[i]))	
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		group = newGroup;
	}
	return perm;
}

aaaaa 에서 t가 4인 경우
0번 인덱스 aaaaa
1번 인덱스 aaaa
같은 그룹인 상태
	0번 인덱스 + t => 4번 인덱스의 값은 0 // a하나만 있는거니 제일 앞임.
	1번 인덱스 + t => 5번 인덱스 의 값은 -1		// 초과하니 -1


//p669 접미사 배열을 사용해 원형 문자열 문제를 해결하는 알고리즘의 구현
  S
  c
b   d
  a
cdab: cdabcdab		S2.substr(a[i], S.size()) = S2.substr(2, 4) = abcd
dabc: dabcdabc		S2.substr(a[i], S.size()) = S2.substr(1, 4) = abcd
abcd: abcdabcd		S2.substr(a[i], S.size()) = S2.substr(4, 4) = abcd
bcda: bcdabcda		S2.substr(a[i], S.size()) = S2.substr(3, 4) = abcd
//사전순으로 가장 앞에 오는 s의 회전 결과를 구한다.
string minShift(const string& s) {
	string s2 = s + s;
	vector<int> a = getSuffixArray(s2);
	for (int i = 0; i < a.size(); ++i)
		if (a[i] <= s.size())
			return s2.substr(a[i], s.size());
	//여기로 올 일은 없어야 한다.
	return "__oops__";
}


//p671 서로 다른 부분 문자열의 수
ex) banana
"a", "an", "ana", "anan", "anana", "b", "ba", "ban", "bana", "banan",
"banana", "n", "na", "nan", "nana"
아이디어: 모든 접미사의 접두사들은 모든 부분 문자열이 된다!!!!
거기서 중복된 접두사들을 제거하자
0 1 2 3 4 5
b a n a n a
i	A[i]	S[A[i]...]		S.size() - a[i] - cp ===> S.size() - a[i]: 접미사 길이, cp: 공통 접두사 길이
0	5		a				6 - 5 - 0 = 1	//a
1	3		a n a			6 - 3 - 1 = 2	//an, ana
2	1		a n a n a		6 - 1 - 3 = 2	//anan, anana
3	0		b a n a n a		6 - 0 - 0 = 6	//b, ba, ban, bana, banan, banana
4	4		n a				6 - 4 - 0 = 2	//n, na
5	2		n a n a			6 - 2 - 2 = 2	//nan, nana

1 + 2 + 2 + 6 + 2 + 2 = 15

//s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string& s, int i, int j) {
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]) {	//간결하넹!!!!
		++i; ++j; ++k;
	}
	return k;
}
//s의 서로 다른 부분 문자열의 수를 센다.
int countSubstrings(const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	int n = s.size();
	for (int i = 0; i < a.size(); ++i) {
		int cp = 0;
		if (i > 0) cp = commonPrefix(s, a[i - 1], a[i]); //캬 좋은 표현이다.!!!!
		//a[i]의 (n - a[i])개의 접두사들 중에서 cp개는 중복이다.
		ret += s.size() - a[i] - cp;
		//s.size() - a[i]: 접미사의 길이 => 접두사의 개수
		//cp: 기존에 있던 접두사랑 중복된 갯수
	}
	return ret;
}

//말버릇(HABIT, 중)
2
uhmhellouhmynameislibe	=> 3: uhm 가 2번 등장하고 그 길이는 3
3
banana					=> 1: a   가 3번 등장하고 그 길이는 1
1
thatsagoodquestion		=> 18: 전체 문장이 1번 등장하고 그 길이는 전체문장길이
3
hello					=> 0: 가장 많이 등장하는 부분 문자열은 "l"로 모두 두 번 출현
//p674 접미사 배열을 이용해 말버릇 문제를 해결하는 알고리즘
//s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string& s, int i, int j) {
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]) {
		++i; ++j; ++k;
	}
	return k;
}
//k번 이상 출현하는 s의 부분 문자열 중 최대 길이를 찾는다. // 1 <= k <= 1000, 1 <= s <= 4000
int longestFrequent(int k, const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); ++i)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]) );
	//k가 1이면 가장 긴 접미사는 문장 자체 길이가 된다.
	//k가 2이면 바로위의 접미사랑 공통된 최장 길이를 구한다.
	//k가 3이면 위로 3개 위의 접미사랑 공통된 접두사의 최장 길이를 구한다.
	//a
	//ana
	//anana
	return ret;
}

3
aaaaa 이면 aaa 가 세번인거냐??	// 그렇다.
a
aa
aaa		ret = 1
aaaa	ret = 2
aaaaa	ret = 3



suffix Automaton 이 suffix array 보다 성능이 더 좋네

//****************** 6부 트리 ********************************/
/******************* 21장 트리의 구현과 순회 *******************************/
//p684
struct TreeNode {
	string label; // 저장할 자료(물론 꼭 문자열일 필요는 없다.)
	TreeNode* parent;	// 부모노드를 가리키는 포인터
	vector<TreeNode*> children;  //자손 노드들을 가리키는 포인터들
};
//트리를 순회하며 모든 노드에 포함된 값을 출력하기
//주어진 트리의 각 노드에 저장된 값을 모두 출력한다.
void printLabels(TreeNode* root) {
	//루트에 저장된 값을 출력한다.
	cout << root->label << endl;
	//각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 출력한다.
	for (int i = 0; i < root->children.size(); ++i)
		printLabels(root->children[i]);
}

//순회를 이용해 트리의 높이를 계산하기 (각 노드를 한번씩 방문 O(n) 의 시간)
//root를 푸트로 하는 트리의 높이를 구한다.
int height(TreeNode* root) {
	int h = 0;	//잎노드는 높이가 0
	for (int i = 0; i < root->children.size(); ++i)
		h = max(h, 1 + height(root->children[i]));
	return h;
}

//p687 트리
//개념정리 : 루트가 2, 왼쪽 자식이 1, 오른쪽 자식이 3 일때 방문순서
//preorder : 2, 1, 3
//inorder  : 1, 2, 3
//postorder: 1, 3, 2
//왼쪽 자식은 항상 오른쪽 자식보다 먼저 방문한다.!!!!
"루트가 어디에 있ㄴ냐가 핵심"
preorder() {
	print 현노드 //처리 프로세스(방문)
	preorder(left) //왼쪽 자식
	preorder(right)//오른쪽 자식
}




//TRAVERSAL 하 :
//어떤 이진 트리를 
//전위 순회했을 때 노드들의 방문순서
//중위 순회했을 때 노드들의 방문순서 이 두 개가 주어질대
//후위 순회했을 때 노드들의 방문 순서를 출력해라
//트리에서 중복되는 숫자가 없음!
재귀 호출을 이용하면 아주 간단하게 구현할 수 있슴
printPostOrder(preorder[], inorder[])
//p689 트리 순회 순서 변경 문제를 해결하는 재귀 호출 코드
vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);	//a가 2, b가 5라면 총 v[2], v[3], v[4] 가 추출된다.
}
//8 6 7 1 2 4 9 13 에서 a = 2, b = 6 이라면
//추출된 벡터는 7 1 2 4 9 가 된다고 생각하기 쉽다! 허나 답은 7 1 2 4 가 된다!!!!
//트리의 전위 탐색 결과와 중위탐색 결과가 주어질 때 후위탐색 결과를 출력한다.
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	//트리에 포함된 노드의 수
	const int N = preorder.size();
	//기저 사례: 텅 빈 트리면 곧장 종료
	if (preorder.empty()) return;//!!!!
	//이 트리의 루트는 전위 탐색 결과로부터 곧장 알 수 있다.
	const int root = preorder[0];
	//이 트리의 왼쪽 서브트리의 크기는 중위 타색 결과에서 루트의 위치를 찾아서 알 수 있다.
	// root 의 위치는 0인덱스 기반이라 left 의 사이즈가 된다.
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();//it끼리 산술이 가능하다(임의 접근 반복자인 경우)!!!!
	//오른쪽 서브트리의 크기는 N에서 왼쪽 서브트리와 루트를 빼면 알 수 있다.
	const int R = N - 1 - L;;
	//왼쪽과 오른쪽 서브트리의 순회 결과를 출력
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));

	//후위 순회이므로 루트를 가장 마지막에 출력한다.
	cout << root << ' ';
}

//요새 FORTRESS 중
2
3		//성벽의 수
5 5 15	//X, Y, 반지름
5 5 10
5 5 5
...


//p694 트리에서 가장 긴 경로를 찾는 재귀 호출 알고리즘
struct TreeNode {
	vector<TreeNode*> children;
};
//지금까지 찾은 가장 긴 잎-잎 경로의 길이를 저장한다.
int longest;
//root를 루트로 하는 서브트리의 높이를 반환한다.
int height(TreeNode* root) {
	//각 자식을 루트로 하는 서브트리의 높이를 계산한다.
	vector<int> heights;
	for (int i = 0; i < root->children.size(); ++i)
		heights.push_back(height(root->children[i]));	//자식들의 높이를 저장
	//만약 자식이 하나도 없다면 0을 반환한다.
	if (heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	//root(현노드)를 최상위 노드로 하는 경로를 고려하자
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	//트리의 높이는 서브트리 높이의 최대치에 1을 더해 계산한다.
	return heights.back() + 1;
}
//두 노드 사이의 가장 긴 경로의 길이를 계산한다.//여기껀 책코드고 실제 코드랑은 안 맞다.
int solve(TreeNode* root) {
	longest = 0;
	//트리의 높이와 최대 잎-잎 경로 길이 중 큰 것을 선택한다.
	int h = height(root);
	return max(longest, h);
}

//트리를 생성하는 과정 //p695
//root성벽을 루트로 하는 트리를 생성한다.
TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ++ch) //오오 자식의 인덱스가 노드의 번호가 된다!!!!
		//ch성벽이 root성벽에 중간에 성벽이 없이 직접적으로 포함되어 있다면
		//트리를 만들고 자손 목록에 추가한다.
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	return ret;
}
//한 성벽이 다른 성벽에 포함되었는지, 그리고 직접 포함되었는지 확인하는 함수
//입력 데이터
int n, y[100], x[100], radius[100];
//x^2을 반환한다.
int sqr(int x) { return x*x; }
//두 성벽 a, b의 중심점 간의 거리의 제곱을 반환한다.
int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}
//성벽 a가 성벽 b를 포함하는지 확인한다.
bool encloses(int a, int b) {
	return radius[a] > radius[b] &&		//a가 b보다 반지름이 크고
		sqrdist(a, b) < sqr(radius[a] - radius[b]);	//a,b의 중심거리가 둘의 반지름 차 보다 작으면
		//선이 겹칠 경우 포함이 안됨
}
//'성벽' 트리에서 parent가 child의 부모인지 확인한다.
//parent는 child를 꼭 "직접포함" 해야 한다.
bool isChild(int parent, int child) {
	if (!encloses(parent, child)) return false;
	for (int i = 0; i < n; ++i)
		if (i != parent && i != child && 
			encloses(parent, i) && encloses(i, child)) //!!!!
			return false;	//parent와 child 사이에 낑긴 놈이 있는지 확인
	return true;
}

int getRoot() {
	for (int i = 0; i < n; ++i) {
		bool isRoot = true;
		for (int j = 0; j < n; ++j)
			if (i != j && encloses(j, i)) {
				isRoot = false;
				break;
			}
		if (isRoot)
			return i;
	}
	return -1;
}

int solve() {
	TreeNode* tree = getTree(getRoot());
	longest = 0;
	return max(longest, height(tree));//longest세팅은 height가 호출된뒤에 하는구나.. 신기
}
int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	cin >> n;
    	for(int i = 0; i < n; i++)
    		cin >> x[i] >> y[i] >> radius[i];
    	cout << solve() << endl;
    }
}


//--------------------- 22장 이진 검색트리 ---------------------------// 

//너드인가, 너드가 아닌가? 2 NERD2
//푼 문제의 수 P
//먹은 라면의 수 Q
//신청자 a가 푼 문제의 수 Pa, 먹은 라면의 수Qa가 모두다 깨지게 하는 인간이 있다면
//a는 너드가 아니게 된다.
//각 사람이 참가 신청을 할 때마다 대회 참가 자격이 되는 사람의 수를 계산한 뒤, 각 테스트 케이스 마다 그 합을 출력합니다.
"두 사람의 푼 문제수나 or 먹은 라면수가 같은 경우는 없습니다."
1
4
72 50	=> 1
57 67	=> 2
74 55	=> 2	//첫번째 놈이 무시된다.
64 60	=> 3

출력 8 //(1 + 2 + 2 + 3)
//p707 한 점이 다른 점에 지배당하는지 확인하는 함수
//현재 다른 점에 지배당하지 않는 점들의 목록을 저장한다.
//coords[x] = y
map<int, int> coords;
//새로운 점(x, y)가 기존의 다른 점들에 지배당하는지 확인한다.(같은점은 지배 안한다고 봐야겠음(false))
bool isDominated(int x, int y) {
	"x보다 오른쪽에 있는 점 중 가장 왼쪽에 있는 점을 찾는다."
	map<int, int>::iterator it = coords.lower_bound(x);
	//그런 점이 없으면 (x, y)는 지배당하지 않는다.
	if (it == coords.end()) return false;
	//이 점은 x보다 오른쪽에 있는 점 중 가장 위에 있는 점이므로
	//(x, y)가 어느 점에 지배되려면 이 점에서도 지배되어야 한다.
	return y < it->second;
}
//선 겹침 포함(Xa == Xnew) or (Ya == Ynew) or (Pa == Pnew)이 있어도 y에 의해서만 참거짓이 결정되어
//논리가 안 맞다만(선겹침으로 포함될시 return이 true가 되어야 된다고 생각하는데, 다른 함수에서 선겹침 포함인 것들이 제거됨)
//P(x, y)예시
//Pa(10, 10), Pnew(10, 5) => true 리턴
//Pa(10, 10), Pnew(5, 10) => false 리턴
//새 점의 x값이 그 누구보다 크면, y의 값은 비교안하고 false를 리턴

//새로운 점(x, y)에 지배당하는 점들을 트리에서 지운다.
void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	//(x, y)보다 왼쪽에 있는 점이 없다.
	if (it == coords.begin()) return;
	--it;
	//반복문 불변식: it는(x, y)의 바로 왼쪽에 있는 점
	while (true) {
		//(x, y)바로 왼쪽에 오는 점을 찾는다.
		//it가 표시하는 점이 (x, y)에 지배되지 않는 다면 곧장 종료
		if (it->second > y) break;
		//이전 점이 더 없으므로 it만 지우고 종료한다.
		if (it == coords.begin()) {
			coords.erase(it); //!!!! 맵 원소 지우기 형태
			break;
		}
		//이전 점으로 이터레이터를 하나 옯겨놓고 it를 지운다. //!!!! 좋은 맵 다루는 예시
		else {
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}
//새 점(x, y)가 추가 되었을 때 coords를 갱신하고
//다른 점에 지배당하지 않는 점들의 개수를 반환한다.
int registered(int x, int y) {
	//(x, y)가 이미 지배당하는 경우에는 그냥 (x, y)를 버린다.
	if (isDominated(x, y)) return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}
//중복된 구간이 있다는 가정을 해보자(문제에선 제외된 가정)
//기존점 (5, 20), (10, 10), (20, 5) 가 있는 상태
기존 점이 (10, 10)이 있는 상태에서 (10, 12) 입력: isDomi = false, 
지배받는 점(10, 10) 제거 안함, coords[10] = 12로 대입함으로써 (10, 10) 제거 효과

기존 점이 (10, 10)이 있는 상태에서 (12, 10) 입력: isDomi = false,
지배받는 점(10, 10) 제거 당함, coords[12] = 10 으로 새점 추가됨

기존 점이 (10, 10)이 있는 상태에서 (10, 5) 입력: isDomi = true,

기존 점이 (10, 10)이 있는 상태에서 (7, 10) 입력: isDomi = false, !!!!!으악
아무점도 제거안함, coords[7] = 10으로 새점 추가됨 좆됨......

중복된 구간도 처리하려면 입력점들을 편집하는 방법이 있지만(x, y중 같은 값이 있으면 큰놈만 살리기)
온라인 입력에 대응된 알고리즘이 필요하다면 함수 수정이 불가피ㅠㅠ
bool isDominated(int x, int y) {
	if (coords.count(x) != 0 && coords[x] == y) return false; //같은 점 예외처리
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end()) return false;
	if (it->first > x) return y <= it->second;//꾸질꾸질한데. 케이스 다 따진 거니 괜찮아
	return y < it->second;
}

// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //20이상의 숫자중 가장 작은 숫자의 가장 작은인덱스(iterator)를 리턴
  up= std::upper_bound (v.begin(), v.end(), 20); //20초과의 숫자중 가장 큰 숫자의 가장 큰 인덱스(iterator) + 1를 리턴!!!!
				// 윗글보단 이렇게 해석하자. lower_bound 20 초과의 숫자중 가장 작은 숫자의 가장 작은 인덱스(iteraotr)
  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
Edit & Run


Output:
lower_bound at position 3
upper_bound at position 6


	int myints2[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	std::vector<int> v2(myints2, myints2 + 8);
	std::vector<int>::iterator up5;
	up5 = std::upper_bound(v2.begin(), v2.end(), 40);	//up5는 50을 가르키고 있음

	lo5 = std::lower_bound(v2.begin(), v2.end(), 45);	//50을 가르킴(45이상의 숫자중 가장 작은거)
	up5 = std::upper_bound(v2.begin(), v2.end(), 45);	//50을 가르킴!!!!(45초과의 숫자중 가장 큰거 + 1)  


// 참고
디폴트 복사 생성자
클래스가 복사 생성자를 정의하지 않으면 컴파일러가 디폴트 복사 생성자를 만든다. 
컴파일러가 만드는 디폴트 복사 생성자는 멤버끼리 1:1로 복사함으로써 원본과 완전히 같은 사본을 만들기만 할 뿐 깊은 복사를 하지는 않는다. 
만약 디폴트 복사 생성자만으로 충분하다면(Position 클래스의 경우) 굳이 복사 생성자를 따로 정의할 필요는 없다. 
이때 만들어지는 디폴트 복사 생성자는 다음과 같을 것이다.
Position(const Position &Other) {
     x=Other.x;
     y=Other.y;
     ch=Other.ch;
}
대응되는 멤버끼리 그대로 대입하는데 전부 단순 타입이라 대입만 하면 잘 복사된다. 
이런 디폴트 복사 생성자가 있기 때문에 별도의 조치가 없어도 "Position There=Here;"가 잘 동작하는 것이다.



//균형잡힌 이진 검색 트리 직접 구현하기: 트립/
"stl의 map도 균형은 잡혀 있어요, 다만 필요한 연산이 없으면 구현해야죠...(k번째 원소 찾기, x보다 작은 원소 세기 등등)
//AVL트리나 레드 블랙 트리등 교과서에 실리는 대부분의 균형 잡힌 이진 검색 트리들은 구현이 매우 까다롭다.
//코드도 길어서 프로그래밍 대회에서 사용하기엔 부적합
//이들보다 간단한 이진 검색 트리가 트립(treap)이다.
트립은 트리의 형태가 원소들의 추가 순서에 따라 결정되지 않고 난수에 의해 임의대로 결정된다.
이때문에 원소들이 어느 순서대로 추가되고 삭제되더라도 트리 높이의 기대치는 항상 일정
(물론 아주, 진짜, 끔찍하게 운이 없는 경우에는 깊이가 n - 1인 최악의 트리를 얻을 수도 있지요.)
(그 확률은 엄청나게 낮습니다)
//712 트립의 노드를 표현하는 객체의 구현
typedef int KeyType;
//트립의 한 노드를 저장한다.
struct Node {
	//노드에 저장된 원소
	KeyType key;
	//이 노드의 우선순위(priority)
	//이 노드를 루트로 하는 서브트리의 크기(size) //노드 갯수임, 깊이가 아니다!!
	int priority, size;
	//두 자식 노드의 포인터
	Node *left, *right;
	//생성자에서 난수 우선순위를 생성하고, size와 left/right를 초기화 한다.
	Node(const KeyType& _key) : key(_key), priority(rand()),
		size(1), left(NULL), right(NULL) {}

	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	//size 멤버를 갱신한다.
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};
//p714 트립에서의 노드 추가와 트립 쪼개기 연산의 구현
typedef pair<Node*, Node*> NodePair;
//root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는 두개의 트립으로 분리한다.
NodePair split(Node* root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	//루트가 key 미만이면 오른쪽 서브트리를 쪼갠다.
	"( 왼쪽서브트리 <= 루트 < key, 오른쪽서브트리 )" //key와 오른쪽서브트리간에 싸움이 일어나야됨
	if (root->key < key) {
		//rsp: right subtree split pair
		NodePair rsp = split(root->right, key);	//오른쪽 서브트리를 key보다 작은 노드들과 key이상인 노드들로 쪼갬
		root->setRight(rsp.first);	//오른쪽 서브트리는 key보다 작은 노드로 구성된 트리(rs.first)로 바뀐다.!!!!
		return NodePair(root, rsp.second);
	}
	//루트가 key 이상이면 왼쪽 서브트리를 쪼갠다.
	"( 왼쪽서브트리, key <= 루트 < 오른쪽서브트리 )" //왼쪽서브트리와 key간에 싸움이 일어나야됨
		//lsp: left subtree split pair
		NodePair lsp = split(root->left, key);
		root->setLeft(lsp.second);
		return NodePair(lsp.first, root);
}
//root를 루트로 하는 트립에 새노드 node를 삽입한 뒤 결과 트립의 루트를 반환한다.
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	//node의 우선순위가 큰경우
	//node가 루트를 대체해야한다 해당 서브트리를 반으로 잘라 각각 자손으로 한다.
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	//node의 우선순위가 같거나 작은 경우
	//node를 root의 왼쪽, 오른쪽 서브트리에 넣는 여부를 결정하여 insert재귀 호출함
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}
//일관성 재고 차원에서 나는 이렇게 짜보고 싶다//테스트 요망
//위랑 비교하면 같은 키값에 대해 왼쪽에 놓냐 오른쪽에 놓냐만 다를 것이다.
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {	//나를 기준으로 쪼개져라~
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

"value 세팅 방법"
root = insert(root, new Node(value));
//최초 호출시점에서 7(우선순위 100)은 4(우선순위 9)이하 모든 노드들 보다 우선순위가 높다. 차기 루트
split( 4(9)  , 7(100) )	//7보다 value 가 클수 있는 노드처리를 위해 오른쪽 서브트리를 처리 루트
	  /  \		//루트가 4이니 왼쪽 서브트리는 7보다 무조건 작음을 착안
	 1	  8
		 /
		6
	split(  8,  7 ) //7보다 클수있는 노드 처리를 위해 왼쪽 서브트리를 처리
		   /		//루트가 8이니 오른쪽 서브트리는 무조건 7보다 크다
		  6
		split( 6, 7 )	//7보다 클수있는 노드 처리를 위해 오른쪽 서브트리를 처리
						//루트가 6이니 왼쪽 서브트리는 모조건 7보다 작다
			split( NULL, 7) 
			ret <NULL, NULL> //기저
		
		ret <6, NULL>	//setRight(null이 붙으니 뭐 도찐개찐)
	
	ret < 6, 8 >	//setLeft(null이 붙으니 뭐 도찐개찐)

ret < 4, 8>		//setRight
	 / \
	1   6	

//p715 트립에서 노드의 삭제와 합치기 연산의 구현
//a와 b가 두 개의 트립이고, max(a) < min(b) 일때 이 둘을 합친다.
//erase시 호출되며 이때 a트리의 최대값은 b트리의 최소값보다 작다.
//내 생각은 같거나 작다 같은디... 이게 키 중복이 성립된다면 말이지.
"(윗 소스가 키중복 허가 하는걸루 보이니...실제로 허용함: measuretime 삽입정렬시간재는 문제에서 사용됨)
//허나 erase, merge 가 쓰인다면 키중복 처리를 해줘야 함: 즉 아래 함수를 사용하려면 키중복안되는 조건이어야 함!
//음... 다시 생각해보니 키에 대한 value 가 없다면 키중복 처리를 안해줘도 됨.. 즉 아래 함수를 그대로 사용해도 무방할 것이야...
Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
		a->setRight(merge(a->right, b));
		return a;
}
//root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다.
Node* erase(Node* root, KeyType key) {
	if (root == NULL) return root;
	//root 를 지우고 양 서브트리를 합친뒤 반환한다.
	if (root->key == key) {
		Node* ret = merge(root->left, root->right); //요기에 쓰였군 merge가 !!!!
										//당연히 max(left) < min(right)를 만족한다.
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

//p717: 트립에서 k번째 원소를 찾는 알고리즘의 구현
//root를 루트로 하는 트리 중에서 k번째 원소를 반환한다. k 는 1부터 시작
Node* kth(Node* root, int k) {
	//왼쪽 서브트리의 크기를 우선 계산한다.
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

//X보다 작은 원소 세기
//[a, b)가 주어질 때 이 범위 안에 들어가는 원소들의 숫자를 계산하는 연산
countLessThan(X)가 있다고 하자
countLessThan(b) - countLessThan(a) 로 표현이 된다.
//p718: 트립에서 X보다 작은 원소의 수를 찾는 알고리즘의 구현
//key 보다 작은 키값의 갯수를 반환한다.
int countLessThan(Node* root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key) //루트의 키가 검색하고자 하는 놈 이상이면
		return countLessThan(root->left, key);
	int leftSize = (root->left ? root->left->size : 0);	//left < root < right, key
	return leftSize + 1 + countLessThan(root->right, key);
}

//p718: 삽입 정렬 뒤집기(INSERTION, 중)
어떤 수열이 있다고 하자.(숫자는 1부터 N까지 한번씩 있다고 전제 함)
그리고 삽입정렬 수행시
해당 수열의 원소가 몇번 왼쪽으로 이동했는지 정보만 알고 있는 상태다.
이 상태에서 원래수열을 구하여라
2
5
0 1 1 2 3
"5 1 4 3 2"
...
음... 3 은 제일 마지막에 추가 되는 놈의 swap횟수이니 이놈을 먼저 처리하자!!!!

5 1 4 3 2 : 초기상태	 0 칸
1 5 4 3 2 : 1을 왼쪽으로 1 칸 옮김
1 4 5 3 2 : 4를 왼쪽으로 1 칸 옮김
1 3 4 5 2 : 3을 왼쪽으로 2 칸 옮김
1 2 3 4 5 : 2를 왼쪽으로 3 칸 옮김 -- "4개가 정렬된 상태에서 새로 원소를 삽입해서 3칸 이동했다면 해당 원소는 2임!!!! 핵심 idea"

0 1 1 2 3 은 ''색칠한거구나

답 만들기
{1, 2, 3, 4, 5}5개가 정렬되어 있다고 가정하에	오른쪽 끝에서 3 칸 이동한 놈이 '2'
{1, 3, 4, 5} 2를 빼고 정렬되어 있다고 가정하에	오른쪽 킅에서 2 칸 이동한 놈이 '3'
{1, 4, 5} 3을 뺀뒤								오른쪽 끝에서 1 칸 이동한 놈이 '4'
{1, 5}											오른쪽 끝에서 1 칸 이동한 놈이 '1'
{5}												오른쪽 끝에서 0 칸 이동한 놈이 '5'

"후보들의 집합 중 k번째 원소가 무엇인지를 찾고, 삭제하는 작업을 빠르게 수행해야한다."
//p720: 삽입정렬 뒤집기 문제를 해결하는 알고리즘
//shifted[i] : A[i]가 왼쪽으로 몇 칸 움직이는가?
int A[50000];
// n, shifted[]를 보고 A[]: 정렬되지 않은 원본 만든다
void solve() {
	//1 ~ N 까지의 숫자를 모두 저장해논 트립을 만든다.
	Node* candidates = NULL;
	for (int i = 0; i < n; ++i)
		candidates = insert(candidates, new Node(i + 1));
	//뒤에서부터 A[]를 채워나간다.
	for (int i = n - 1; i >= 0; --i) {
		int lager = shift[i];	//lager: 후보 중 이 수보다 큰 수가 lager개 있다 !!!!
								//{1, 2, 3, 4, 5} , lager = 3 => 3개의 큰수가 있음
		Node* k = kth(candidates, i + 1 - lager); //k = 1이 시작지점임
		//kth(candidates, candidates.size - lager); // size가 5 이고 lager가 2이면 3이 되겠군
		A[i] = k->key;
		candidates = erase(candidates, k->key);
	}
}
https://algospot.com/judge/submission/detail/212394 
// 간략하다.(필요한 것만 구현되어 있다.) 기회가 되면 보삼 코드도 짧고 좋음


// 트립이 짜기 귀찮아서 펜윅트리로 돌려봤는데 통과함.
// 이 경우 n*log(n)*log(n) 이 걸린다만. 펜윅은 빠르기에 32ms에 통과요
// 구간합 처리 * 이분법
struct FT {
	vi tree;
	FT(int n) : tree(n + 1) {}
	int sum(int pos) {
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos -= (pos & -pos);
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

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n;
		cin >> n;
		vi arr(n);
		rep(i, n) cin >> arr[i];
		FT tree(n);
		for (int i = 1; i <= n; ++i) tree.add(i, 1);
		vi sol;
		for (int i = arr.size() - 1; i >= 0; --i) {
			int swapCnt = arr[i];
			int rank = (i + 1) - swapCnt;
			int lo = 0, hi = arr.size();
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (tree.sum(mid) < rank)
					lo = mid;
				else
					hi = mid;
			}
			tree.add(hi, -1);
			sol.push_back(hi);
		}
		reverse(sol.begin(), sol.end());
		rep(i, sol.size()) cout << sol[i] << " \n"[i != sol.size() - 1 ? 0 : 1]; 
	}
	return 0;
}
각 요소들이 정렬되어 있다고 가정하에 
0 1 1 2 3 //를 처리한다면
1 2 3 4 5 // 여기서 5 - 3번째 순위인 2번째 숫자는 2임
1   3 4 5 // 여기서 4 - 2번째 순위인 2번째 숫자는 3임	// 구간합이 == 순위가 되는 시점의 here를 찾는다.
...

//--------------------------23장 우선순위 큐와 힙 -----------------------------//
우선순위 큐를 구현
1. 균현 잡힌 이진 검색 트리를 사용하는 것: 원소들을 우선순위로 정렬해 두면 최대 원소를 
   찾아 삭제하는 일과 새 원소를 삽입하는 일을 모두 O(lgN)시간에 할 수 있습니다.
허나 우선순위 큐는 굉장히 단순한 것이기 때문에 균형잡힌 이진 검색 트리를 사용하는 것은 자원낭비임
2. 우선순위 큐는 이진 검색 트리를 활용하는 것보다 훨씬 단순한 구조로도 구현할 수 있음
   그중 대표적인 것이 힙(heap)이라는 트리입니다. 힙은 가장 큰 원소를 찾는 데 최적화된 형태의
   이진 트리로, 힙을 사용하면 새 원소를 추가하는 연산과 가장 큰 원소를 꺼내는 연산을 모두
   O(lgN) 시간에 수행할 수 있습니다. 실제로 힙을 사용하면 우선순위 큐를 아주 쉽게 구현
//힙의 정의와 구현 //p724 추가바람 : 해보면 좋은 경험은 되나 솔까 난 stl쓸련다.


//변화하는 중간값 RUNNINGMEDIAN, 난이도 하
//MEDIAN을 구하는 문제(예외로 두는 것: 수열의 길이가 짝수일 때는 가운데 있는 두 값 중 보다 작은 것을 선택)
//1, 2, 3, 4, 5, 6 에서 두 중간값 3, 4 중 3을 선택
//P734 힘을 이용해 변화하는 중간 값 문제를 해결하는 함수의 구현

//cf) 햇갈리게 하는 것들 !!!! (less붙는 놈이 원래놈과 동일하다고 보면 됨)
priority_queue<int> q1; //가장 큰 값이 맨 위에 있다
priority_queue<int, vector<int>, less<int> > maxHeap; //가장 큰 값이 맨 위에 있다.
priority_queue<int, vector<int>, greater<int> > minHeap; //가장 작은 값이 맨 위에 있다.


sort(korean.begin(), korean.end()); //오름차순 정렬
sort(korean.begin(), korean.end(), less<int>()); //오름차순 정렬 : 가장 큰 값이 맨 뒤에 있다.
sort(korean.begin(), korean.end(), greater<int>());	//내림차순 정렬, 뒤에 ()가 붙는걸 유념해라 !!!!

typedef pair<long long, long long> MyPair;
priority_queue<MyPair, vector<MyPair>, greater<MyPair> > pq;	//가장 작은 값이 맨 위에 있다.

std::greater<int> tt;
sort(array.begin(), array.end(), tt);
sort(array.begin(), array.end(), std::greater<int>());


int runningMedian(int n, RNG rng) {
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int ret = 0;
	//반복문 불변식
	//1. maxHeap의 크기는 minHeap의 크기와 같거나 1 더 크다
	//2. maxHeap.top <= minHeap.top()
	for (int cnt = 1; cnt <= n; ++cnt) {
		//우선 1번 불변식 부터 만족시킨다.
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());	//size 개수기준 maxHeap이 1 더 크면 minHeap을 증가시킨다.
										//따라소 minHeap의 size가 maxHeap size보다 커질 순 없다.
		//2번 불변식이 깨졌을 경우 복구하자.
		if (!minHeap.empty() && !maxHeap.empty() &&
			minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
}

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1883) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;	//오버플로우 방어
		return ret;
	}
};


//------------------------------24장 구간트리---------------------------//
http://codeforces.com/blog/entry/15890 
// 구간트리의 모든것, lazy propagation, persistent segment tree 등도 있다


"길이가 15인 배열의 구간 트리"
[0,															 14]

[0,							 7] [8,							 14]

[0,			 3] [4			 7] [8,			  11] [12,		 14]

[0,	 1] [2,  3] [4,  5] [6,  7] [8,  9] [10,  11] [12,  13] [14]

[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13]

"구간트리는 노드마다 해당 구간에 대한 계산 결과(ex: 최대, 최소)를 저장"
[6,12]구간의 최소값 = min([6, 7], [8, 11], [12])
어떤 구간이 주어지건 답을 찾기 위해 고려해야 하는 구간의 수는 O(lgN)이 된다.

루트 노드를 배열의 1번 원소로 둔다(0번이 아니넹), 왼쪽 자손 2 * i, 오른쪽 자손 2 * i + 1
이 배열의 길이는 n이 2의 거듭제곱이라면(ex(2^3) 이 배열의 길이는 2n 이면 충분
허나 다른 경우(n == 6) 이면 13개가 되버림
			   [0, 6]
	 [0, 3]			  [4, 6]
 [0, 1]  [2, 3]     [4, 5] [6]
[0] [1]  [2] [3]   [4] [5] 
배열의 길이를 안전하게 구하려면 가장 가까운 2의 거듭제곱으로 n을 올림한 뒤 2를 곱하면 됨
6 -> 8 : 2 * 8 = 16
"귀찮으면 안전빵으로 n에다가 그냥 4를 곱해라"

//p739: 배열의 구간 최소 쿼리(RMQ)문제를 해결하는 구간 트리의 초기화
//배열의 구간 최소 쿼리를 해결하기 위한 구간트리의 구현
struct RMQ {
	//배열의 길이
	int n;
	//각 구간의 최소치
	vector<int> rangeMin;
	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 1, 0, n - 1);
	}
	//node노드가 array[left..right] 배열을 처리할 경우
	//먼저(1) node를 루트로 하는 서브트리를 초기화 하고, 
	//(2)이 구간(array[left..right])의 최소치를 반환한다.
	int init(const vector<int>& array, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR) //종료조건
			return rangeMin[node] = array[nodeL];
		int mid = (nodeL + nodeR) / 2;
		int leftMin = init(array, node * 2, nodeL, mid); //node * 2 : 왼쪽 자식 번호
		int rightMin = init(array, node * 2 + 1, mid + 1, nodeR); //node * 2 + 1 : 오른쪽 자식 번호
		return rangeMin[node] = min(leftMin, rightMin); 
		//세팅은 postOrder 형식임 8번, 9번, 4번, 10번, 11번, 5번, 2번 노드 순으로 세팅됨
	}
	//중간에 비는거 없는 완전 이진 트리가 된다.
};
						   1[0, 6]
			2[0, 3]			    		3[4, 6]
   4[0, 1]		   5[2, 3]			6[4, 5]			7[6]
8[0]    9[1]  10[2]		11[3]   12[4]    13[5] 
rangeMin
0		1		2		3		4		5		6		7		8	9	10	11	12	13	14	.... 27
x		[0,6]	[0,3]	[4,6]	[0,1]	[2,3]	[4,5]	[6]		[0]	[1]	[2]	[3]	[4]	[5]	x	x..x x

//p741: RMQ 문제를 푸는 구간트리에서 질의 연산의 구현(최소값 질의)
const int INT_MAX = numeric_limits<int>::max();
struct RMQ {
	//..앞부분 생략..
	//node가 표현하는 범위 array[nodeLeft..nodeRight]가 주어질 때
	//이 범위와 array[left..right]의 교집합의 최소치를 구한다.
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	//left, right(고정된 값임: 찾고자 하는 범위)
	//nodeLeft, nodeRight(이분법으로 바뀜)
		//두 구간이 겹치지 않으면 아주 큰 값을 반환한다 : 무시할 목적으로
		//[left	right][nodeLeft	nodeRight] or [nodeLeft	nodeRight][left	right]
		if (right < nodeLeft || nodeRight < left) return INT_MAX;
		//node가 표현하는 범위가 array[left..right] 에 완전히 포함되는 경우
		//[left nodeLeft nodeRight right]
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
		//일부 겹침이 일어 나는 경우
		//양쪽 구간을 나눠서 푼뒤 결과를 합친다.
		int mid = (nodeLeft + nodeRight) / 2;
		return min( query(left, right, node * 2, nodeLeft, mid),
					query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	//복잡도는 O(lgN) 이다. 밑으로 내려갈수록 적어도 절반씩 처리된다고 보면 됨 p742 설명

	//query()를 외부에서 호출하기 위한 인터페이스
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1); 
		//[left,right: 우리가 찾고자 하는 범위] [1: 현노드] [0, n-1: 현노드(1)가 가지는 범위]
		//현노드가 1이면 전체범위를 의미하니 0, n - 1을 집어 넣었군
	}
};

//p743 RMQ문제를 푸는 구간트리에서 갱신 연산의 구현
struct RMQ {
	//..앞부분 생략..
	//array[index] = newValue로 바뀌었을 때 node를 루트로 하는
	//구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다.
	"여기선 굳이 array[index] 를 바꾸지는 않는군요."
	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
	//[node: 현노드] [nodeLeft, nodeRight: 현노드가 array에서 커버하는 범위, 구간트리array에서가 아님]
		//index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다.
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node]; //원래 값에 덮어 쒸워지기 용인가?
									//아니다!, 약간 다르넹. 이걸 리턴해줘야 부모노드가 min 갱신이 가능해지므로
		//트리의 리프까지 내려온 경우
		if (nodeLeft == nodeRight) return rangeMin[node] = newValue; //!!!!
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = min(
			update(index, newValue, node * 2, nodeLeft, mid),
			update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}
	//update()를 외부에서 호출하기 위한 인터페이스
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1); 
		//나의 오해: rangeMin의 index 는 1부터 시작인데 왜 0이 nodeLeft로 보내는가?
		//0, n - 1은 array의 인덱스라 보면 된다(초기화 부분을 보삼) 물론 이놈은
		//멤버로 가질 필요가 없다. 그래서 내가 헷갈린 거다...
	}
	//원래 배열의 index위치의 값이 newValue로 바뀌었다고 합시다. 이 위치를 포함하는 구간은
	//트리에 O(lgN)개 있을겁니다. 따라서 이들만을 재계산하면 O(lgN)시간에 구간트리를 갱신할 수 있습니다.
};

//p743 특정 구간에서 최소치 두개 찾기
구간 트리는 다양한 문제에 쓸 수 있습니다. 예를 들어 구간이 주어졌을 때 최소치 하나만을 찾는 게 아니라
가장 작은 두 개의 값을 찾는 문제를 푸는 구간 트리를 만들어 봅시다. 구간 트리를 사용하려면
두 개의 작은 부분 구간에 대해 계산한 값을 효율적으로 합치는 방법이 있어야 합니다.
두 개의 자식 구간에 대해 각각 최소치 두 개씩을 찾았다고 합시다. 이들을 어떻게 합쳐서 전체 구간에 대한
답을 계산할 수 있을까요? 네 개의 값 중 가장 작은 두개를 선택하면 되겠죠!!!!
"구간의 길이가 1밖에 안 될 때는 해당 구간에 포함된 숫자와 아주 큰 값 oo을 반환하면 될 겁니다."
vector<pair<int, int>> minPair(4*n);
pair<int, int> init(const vector<int>& arr, int left, int right, int node);
pair<int, int> query(int left, int right, int node, int nodeLeft, int nodeRight);
pair<int, int> update(int index, int newValue, int node, int nodeLeft, int nodeRight);
pii selectMinPair(const pii& a, const pii& b) {
	//let) a.first <= a.second, b.first <= b.second;
	//귀찮다 그냥 짜자
	int arr[4];
	arr[0] = a.first; arr[1] = a.second; arr[2] = b.first; arr[3] = b.second;
	sort(arr, arr+4);
	return make_pair(arr[0], arr[1]);
}

//p744 "정렬된" 수열의 특정 구간에서 최대 출현 빈도 계산
	0	1	2	3	4	5	6	7	8	9	10
A ={0,	0,	1,	1,	1,	1,	2,	3,	3,	3,	4 }
A[1] ~ A[5] 구간의 최대 출현 하는 수의 빈도 : "4" (1이 4개 이므로)
A[5] ~ A[7] 구간의 최대 출현 하는 수의 빈도 : "1" (1: 1개, 2: 1개, 3: 1개)
//분할하여 문제를 풀기 위한 고려 사항!!!!
"왼쪽 구간의 오른쪽 끝수와"
"오른쪽 구간의 왼쪽 끝수가 같은 경우"
//p745: 숫자의 최대 출현 회수 문제의 두개의 답을 합치기
//부분 구간의 계산 결과
struct RangeResult {
	int size;	//이 구간의 크기
	int mostFrequent;	//가장 자주 등장하는 숫자의 출현 횟수
	int leftNumber, leftFreq;	//왼쪽 끝 숫자와 왼쪽 끝 숫자의 출현 횟수
	int rightNumber, rightFreq;	//오른쪽 끝 숫자와 오른쪽 끝 숫자의 출현 횟수
};
//왼쪽 부분 구간의 계산결과 a, 오른쪽 부분 구간의 계산 결과 b를 합친다.
RangeResult merge(const RangeResult& a, const RangeResult& b) {
	RangeResult ret;
	//구간의 크기는 쉽게 계산 가능
	ret.size = a.size + b.size;
	//왼쪽 숫자는 a.leftNumber로 정해져 있다.
	//왼쪽 부분 구간이 전부 a.leftNumber인 경우만 별도로 처리
	//예: [1, 1, 1, 1] 과 [1, 2, 2, 2] 를 합칠 때
	ret.leftNumber = a.leftNumber;	// a.leftNumber: 1
	ret.leftFreq = a.leftFreq;
	if (a.size == a.leftFreq && a.leftNumber == b.leftNumber)
		ret.leftFreq += b.leftFreq;

	//오른쪽 끝 숫자도 비슷하게 처리하자
	ret.rightNumber = b.rightNumber;
	ret.rightFreq = b.rightFreq;
	if (b.size == b.rightFreq && b.rightNumber == a.rightNumber)
		ret.rightFreq += a.rightFreq;

	//기본적으로 가장 많이 출현하는 수의 빈도수는 둘 중 큰쪽으로
	ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);

	"왼쪽 구간의 오른쪽 끝 숫자와 오른쪽 구간의 왼쪽 끝 숫자가 합쳐지는 경우"
	//이 두수를 합쳤을 때 mostFrequent 보다 커지는지 확인한다.
	if (a.rightNumber == b.leftNumber)
		ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
	return ret;
}
앞의 구간 트리 코드에서 두답의 최소치는 구하는 min()함수를
여기서 만든 merge()함수로 대체하면 이문제를 푸는 구간트리를 만들수 있습니다.
으으... 각 함수들의 리턴값도 다 바꾸어야 하네 "init, query, update"


// 아래는 내가 짜본거 책에 있는 힌트로 짜 봤음. 검증은... 동작 잘될거야..
// 필요한 문제 있으면 제출해서 검증해보자
vector<pari<int, int>> minPair(4 * n);
pair<int, int> init(const vector<int>& arr, int left, int right, int node);
pair<int, int> query(int left, int right, int node, int nodeL, int nodeR);
pair<int, int> update(int index, int newVal, int node, int nodeL, int nodeR);
pii selectMinPair(const pii& a, const pii& b) {
}

struct RMQ2 {
	int n;
	vpii rangeMin;	//rangeMinPair
	RMQ2(cvi& arr) {
		n = arr.size();
		rangeMin.resize(n * 4);
		//init(arr, 0, n - 1, 1);
		init(arr, 1, 0, n - 1);	//일관성있게
	}
	//원본이랑 인자 순서 바꿈//일관성있게
	pii init(cvi& arr, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR)
			return rangeMin[node] = make_pair(array[nodeL], inf); //!!!!
		int mid = (nodeL + nodeR) / 2;
		pii leftMinPair = init(arr, node * 2, nodeL, mid);
		pii rightMinPair = init(arr, node * 2 + 1, mid + 1, nodeR);
		return rangeMin[node] = selectMinPair(leftMinPair, rightMinPair);
	}
	pii query(int left, int right, int node, int nodeL, nodeR) {
		if (right < nodeL || nodeR < left) return mp(inf, inf);	//!!!!
		if (left <= nodeL && nodeR <= right) return rangeMin[node];
		int mid = (nodeL + nodeR) / 2;
		return selectMinPair(
			query(left, right, node * 2, nodeL, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeR));
	}
	pii query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	pii update(int index, int newVal, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index)
			return rangeMin[node];
		if (nodeL == nodeR) return rangeMin[node] = mp(newVal, inf); //!!!!
		int mid = (nodeL + nodeR) / 2;
		return rangeMin[node] = selectMinPair(
			update(index, newVal, node * 2, nodeL, mid),
			update(index, newVal, node * 2 + 1, mid + 1, nodeR));
	}
	pii update(int index, int newVal) {
		return update(index, newVal, 1, 0, n - 1);
	}
};
pii selectMinPair(const pii& a, const pii& b) {
	//let) a.first <= a.second, b.first <= b.second;
	//귀찮다 그냥 짜자
	int arr[4];
	arr[0] = a.first; arr[1] = a.second; arr[2] = b.first; arr[3] = b.second;
	sort(arr, arr+4);
	return make_pair(arr[0], arr[1]);
}



struct RangeResult {
	int size;
	int mostF;
	int leftN, leftF;
	int rightN, rightF;
	RangeResult(int useLessSize, int number)
		: size(0) {}
	RangeResult(int number) 
		: size(1), mostF(1), leftN(number), leftF(1), rightN(number), rightF(1) {}
};
RangeResult merge(const RangeResult& a, const RangeResult& b) {
	if (a.size == 0) return b;
	if (b.size == 0) return a;

	RengeResult ret;
	ret.size = a.size + b.size;

	ret.leftN = a.leftN;
	ret.leftF = a.leftF;
	if (a.size == a.leftF && a.leftN == b.leftN)
		ret.leftF += b.leftF;

	ret.rightN = b.rightN;
	ret.rightF = b.rightF;
	if (b.size == b.rightF && b.rightN == a.rightN)
		ret.rightF += a.rightF;

	ret.mostF = max(a.mostF, b.mostF);
	if (a.rightN == b.leftN)
		ret.mostF = max(ret.mostF, a.rightF + b.leftF);
	return ret;
}
struct RMQ3 {
	int n;
	vector<RangeResult> segTree;
	RMQ3(cvi& arr) {
		n = arr.size();
		segTree.resize(n * 4);
		//init(arr, 0, n - 1, 1); //일관성
		init(arr, 1, 0, n - 1);
	}
	RangeResult init(cvi& arr, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR)
			return segTree[node] = RangeResult(arr[nodeL]);	//!!!!
		int mid = (nodeL + nodeR) / 2;
		RangeResult leftRangeResult  = init(arr, node * 2, nodeL, mid);
		RangeResult rightRangeResult = init(arr, node * 2 + 1, mid + 1, nodeR);
		return segTree[node] = merge(leftRangeResult, rightRangeResult);	//!!!!
	}
	RangeResult query(int left, int right, int node, int nodeL, int nodeR) {
		if (right < nodeL || nodeR < left) return RangeResult(0, -inf); //!!!!쓸모없는 빈 쓰래기임
		if (left <= nodeL && nodeR <= right) return segTree[node];
		int mid = (nodeL + nodeR) / 2;
		return merge(	query(left, right, node * 2, nodeL, mid),
						query(left, right, node * 2 + 1, mid + 1, nodeR));
	}
	RangeResult query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	RangeResult update(int index, int newVal, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index)
			return segTree[node];
		if (nodeL == nodeR) return segTree[node] = RangeResult(newVal);
		int mid = (nodeL + nodeR) / 2;
		return segTree[node] = merge(
			update(index, newVal, node * 2, nodeL, mid),
			update(index, newVal, node * 2 + 1, mid + 1, nodeR));
	}
	RangeResult update(int index, int newVal) {
		return update(index, newVal, 1, 0, n - 1);
	}
};


http://codeforces.com/contest/722/problem/C
배열이 주어지고 인덱스에 해당하는 값을 제거하는 과정
그 과정에서 각각이 분절 중 
합이 가장 큰 값을 출력하라 : 다른 방식으로도 풀린다... 밑에 더 정리된거 있으니 그거 보자

const long long INF = 1LL << 60;
struct RangeResult {
	int size;
	bool allok;
	ll rightSum, leftSum, mSum;
	RangeResult() : size(0) , allok(false) {}
	RangeResult(int useless, int a) : size(0) , allok(false) {}
	RangeResult(int number)
		: size(1), allok(true), rightSum(number), leftSum(number) , mSum(number) {}
	RangeResult(int number, bool OMG)
		: size(1), allok(false), rightSum(0), leftSum(0), mSum(0) {}
};
RangeResult merge(const RangeResult& a, const RangeResult& b) {
	if (a.size == 0) return b;
	if (b.size == 0) return a;

	RangeResult ret(0);
	ret.leftSum = a.leftSum;
	if (a.allok)
		ret.leftSum += b.leftSum;
	ret.rightSum = b.rightSum;
	if (b.allok)
		ret.rightSum += a.rightSum;

	if (a.allok && b.allok)
		ret.allok = true;
	else
		ret.allok = false;

	if (ret.allok)
		ret.mSum = ret.rightSum;
	else {
		ll cand = max(a.mSum, b.mSum);
		cand = max(cand, ret.leftSum);
		cand = max(cand, ret.rightSum);
		cand = max(cand, a.rightSum + b.leftSum);
		ret.mSum = cand;
	}
	return ret;
}
struct RMQ3 {
	int n;
	vector<RangeResult> segTree;
	RMQ3(cvi& arr) {
		n = arr.size();
		segTree.resize(n * 4);
		//init(arr, 0, n - 1, 1); //일관성
		init(arr, 1, 0, n - 1);
	}
	RangeResult init(cvi& arr, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR)
			return segTree[node] = RangeResult(arr[nodeL]);	//!!!!
		int mid = (nodeL + nodeR) / 2;
		RangeResult leftRangeResult = init(arr, node * 2, nodeL, mid);
		RangeResult rightRangeResult = init(arr, node * 2 + 1, mid + 1, nodeR);
		return segTree[node] = merge(leftRangeResult, rightRangeResult);	//!!!!
	}
	RangeResult query(int left, int right, int node, int nodeL, int nodeR) {
		if (right < nodeL || nodeR < left) return RangeResult(0, -1); //!!!!쓸모없는 빈 쓰래기임
		if (left <= nodeL && nodeR <= right) return segTree[node];
		int mid = (nodeL + nodeR) / 2;
		return merge(query(left, right, node * 2, nodeL, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeR));
	}
	RangeResult query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	RangeResult update(int index, int newVal, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index)
			return segTree[node];
		if (nodeL == nodeR) return segTree[node] = RangeResult(newVal, true);
		int mid = (nodeL + nodeR) / 2;
		return segTree[node] = merge(
			update(index, newVal, node * 2, nodeL, mid),
			update(index, newVal, node * 2 + 1, mid + 1, nodeR));
	}
	RangeResult update(int index, int newVal) {
		return update(index, newVal, 1, 0, n - 1);
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vi arr(n + 1);
	rep(i, n) {
		cin >> arr[i + 1];
	}
	RMQ3 rmq(arr);
	rep(i, n) {
		int index; 
		cin >> index;
		ll sol = rmq.update(index, 0).mSum;
		cout << sol << endl;
	}
	return 0;
}

// 위에거 정리한 소스: query 가 필요없어서 삭제했고 merge시 빈 객체를 머지할 필요도 없음
const long long INF = 1LL << 60;

struct RangeResult {
	bool allConnect;
	ll leftSum, rightSum, cMaxSum;
	// 만약 생성자를 추가한다면 기본 생성자가 없으면 컴파일이 안됨 !!!!
	RangeResult() : allConnect(false), leftSum(0), rightSum(0), cMaxSum(0) {} // 기본 생성자
	RangeResult(int val) : allConnect(true), leftSum(val), rightSum(val), cMaxSum(val) {}
	RangeResult(int val, bool NoUse) : allConnect(false) , leftSum(0), rightSum(0), cMaxSum(0){}
};
RangeResult merge(const RangeResult& a, const RangeResult& b) {
	RangeResult ret(0);
	ret.leftSum = a.leftSum;
	if (a.allConnect == true)
		ret.leftSum += b.leftSum;
	ret.rightSum = b.rightSum;
	if (b.allConnect == true)
		ret.rightSum += a.rightSum;

	if (a.allConnect && b.allConnect)
		ret.allConnect = true;
	else
		ret.allConnect = false;

	if (ret.allConnect)
		ret.cMaxSum = ret.rightSum;
	else {
		ll cand = max(a.cMaxSum, b.cMaxSum);
		cand = max(cand, ret.leftSum);
		cand = max(cand, ret.rightSum);
		cand = max(cand, a.rightSum + b.leftSum);
		ret.cMaxSum = cand;
	}
	return ret;
}
struct RMQ3 {
	int n;
	vector<RangeResult> segTree;
	RMQ3(cvi& arr) {
		n = arr.size();
		segTree.resize(n * 4);
		init(arr, 1, 0, n - 1);
	}
	RangeResult init(cvi& arr, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR)
			return segTree[node] = RangeResult(arr[nodeL]);
		int mid = (nodeL + nodeR) / 2;
		RangeResult leftRangeResult = init(arr, node * 2, nodeL, mid);
		RangeResult rightRangeResult = init(arr, node * 2 + 1, mid + 1, nodeR);
		return segTree[node] = merge(leftRangeResult, rightRangeResult);
	}
	RangeResult update(int index, int newVal, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index)
			return segTree[node];
		if (nodeL == nodeR) 
			return segTree[node] = RangeResult(newVal, true);
		int mid = (nodeL + nodeR) / 2;
		return segTree[node] = merge(
			update(index, newVal, node * 2, nodeL, mid),
			update(index, newVal, node * 2 + 1, mid + 1, nodeR));
	}
	RangeResult update(int index, int newVal) {
		return update(index, newVal, 1, 0, n - 1);
	}
};
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vi arr(n + 1);
	rep(i, n) cin >> arr[i + 1];
	RMQ3 rmq(arr);
	rep(i, n) {
		int index;
		cin >> index;
		RangeResult sol = rmq.update(index, 0);
		cout << sol.cMaxSum << endl;
	}
	return 0;
}


https://www.acmicpc.net/problem/11505 : 구간 곱 구하기 
수의 갯수 	1000000개
update 		10000개
query 		10000개
구간트리를 stl 안쓰고 짜는 좋은 방법이다 !!!!!!!! 삼성용
출처: http://jason9319.tistory.com/54 [ACM-ICPC 상 탈 사람]
// 링크된 코드 내식으로  : 통과 300ms 걸림
typedef long long ll;
using namespace std;

ll seg[4 * MAX_N];	// one based
ll update(ll pos, ll val, ll node, ll nodeL, ll nodeR) {
	if (pos < nodeL || nodeR < pos) return seg[node];
	if (nodeL == nodeR) return seg[node] = val;
	ll mid = (nodeL + nodeR) / 2;
	return seg[node] = (update(pos, val, node*2, nodeL, mid) *
		update(pos, val, node * 2 + 1, mid + 1, nodeR)) % MOD;
}
ll query(ll left, ll right, ll node, ll nodeL, ll nodeR) {
	if (right < nodeL || nodeR < left)
		return 1;
	if (left <=  nodeL && nodeR <= right)
		return seg[node];
	ll mid = (nodeL + nodeR) / 2;
	return (query(left, right, node * 2, nodeL, mid)
			*query(left, right, node * 2 + 1, mid + 1, nodeR)) % MOD;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) { 	// 1번 인덱스부터 채운다. one based
		int ai;
		cin >> ai;
		update(i, ai, 1, 1, N);
	}
	for (int i = 0; i < M + K; i++) {
		int op, u, v;
		cin >> op >> u >> v;
		if (op == 1)
			update(u, v, 1, 1, N);
		else {
			long long ss = query(u, v, 1, 1, N);
			cout << ss << '\n';
		}
	}
	return 0;
}

// init을 취하면 150ms 걸렸다.
ll seg[4 * MAX_N];	// one based
ll arr[MAX_N + 5];
ll init(ll node, ll nodeL, ll nodeR) {
	if (nodeL == nodeR) return seg[node] = arr[nodeL];
	ll mid = (nodeL + nodeR) / 2;
	return seg[node] = (init(node * 2, nodeL, mid)
		* init(node * 2 + 1, mid + 1, nodeR)) % MOD;
}
ll update(ll pos, ll val, ll node, ll nodeL, ll nodeR) {
	if (pos < nodeL || nodeR < pos) return seg[node];
	if (nodeL == nodeR) return seg[node] = val;
	ll mid = (nodeL + nodeR) / 2;
	return seg[node] = (update(pos, val, node*2, nodeL, mid) *
		update(pos, val, node * 2 + 1, mid + 1, nodeR)) % MOD;
}
ll query(ll left, ll right, ll node, ll nodeL, ll nodeR) {
	if (right < nodeL || nodeR < left)
		return 1;
	if (left <=  nodeL && nodeR <= right)
		return seg[node];
	ll mid = (nodeL + nodeR) / 2;
	return (query(left, right, node * 2, nodeL, mid)
			*query(left, right, node * 2 + 1, mid + 1, nodeR)) % MOD;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int ai;
		cin >> ai;
		arr[i] = ai;
		//update(i, ai, 1, 1, N);	// 1번 인덱스부터 채운다. one based
	}
	init(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		int op, u, v;
		cin >> op >> u >> v;
		if (op == 1)
			update(u, v, 1, 1, N);
		else {
			long long ss = query(u, v, 1, 1, N);
			cout << ss << '\n';
		}
	}
	return 0;
}

//p746 등산로 문제(MORDOR 중)
//특정 구간이 주어질때 그 구간내에서 가장 높은 해발고도와 가장 낮은 해발고도의 최대 차이가
//난이도가 된다. 구간에 대한 난이도를 계산하는 프로그램을 작성하세요.
2	//케이스
3 1	//표지판수, 개방고려 등산로수
1 2 3	//High(0 ~ 20000) 해발고도
0 2		//개방할 구간
"출력 3 - 1 = 2"
10 4
3 9 5 6 10 8 7 1 2 4
1 6
4 7
9 9
5 8
"출력"
"10 - 5 = 5"
"10 - 1 = 9"
"4 - 4 = 0"
"8 - 1 = 7"
RMQ를 사용하면 됨
구간에 대한 최대 값은 주어진 높이의 배열을 -1 곱하여 부호를 뒤집어 초기화 하면 간단
"INT_MAX 리턴하는거 우짤건데"!!!! 이거 INT_MIN 리턴으로 바꾸어야 하지않냐!??
-2, -4, -100, INT_MAX 의 Range Minimum Q질의는 -100을 리턴함. 즉 쓸데없는 걱정이었군...

//747 족보 탐험(FAMILYTREE, 상)
//최소 공통조상 찾기 문제(least/lowest common ancestor, LCA) 
				0
			  / | \
			1	6	8
		  / |	|	| \
		2	3	7	9	12
		   / \	   / \
		  4	  5	  10  11	
	LCA(2,5) = 1, LCA(8, 5) = 0, LCA(1, 4) = 1
"전위순회(preorder)하면서 방문하는 노드들을 순서대로 늘어 놓자"
"단 재귀호출이 끝나고 이전 노드로 돌아오는 것도 노드를 방문하는 것으로 친다 !!!!"
P ={0,	1,	2,	1,	3,	4,	3,	5,	3,	1,	0,	6,	7,	6,	0,	8,	9,	10,	9,	11,	9,	8,	12,	8,	0	} //25개
이 경로의 길이는 얼마냐? 이 경로는 부모와 자식 간의 각 연결을 정확히 "한번씩 내려가고 한번씩 올라옵니다"
트리에는 항상 n - 1개의 연결이 있으므로, "2n - 2"번 움직이게 됩니다.(움직이는 간선수라 보면 됨)
그러므로 방문하는 노드의 개수는 총 "2n - 1"개가 됩니다.
위 예시에선 2 * 13 - 1 = 총 노드가 25개가 됨을 확인할 수 있어요

no
				0
			  / | \
			6	3	7
		  / |	|	| \
		11	12	2	5	8
		   / \	   / \
		 10	  4	  1   9

"serial : 임의의 노드의 부모는 항상 더 작은 번호를 가진다.
"				0
			  / | \
"			1	6	8
		  / |	|	| \
"		2	3	7	9	12
		   / \	   / \
"		  4	  5	  10  11
							0	1	2	3	4	5	6	7	8	9	10	11	12
no2serial[here(no의미)] ="	0	10	7	6	5	9	1	8	12	11	4	2	3
serial2no[serial]		=	0	6	11	12	10	4	3	2	7	5	1	9	8
depth[here(no의미)]		=	0	3	2	1	3	2	1	1	2	3	3	2	2
locInTrip[here(no의미)]	=>	here->serial->trip에서 serial이 최초로 발견된 인덱스를 구함
							0	17	12	11	7	16	1	15	22	19	5	2	4
trip
(preorder serial이 저장됨)
(돌아올때 serial도 저장됨)	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24
			최초방문'	=	0	1	2		3	4		5				6	7			8	9	10		11			12
		돌아올때방문	=				1			3		3	1	0			6	0				9		9	8		8	0
here:3 => serial: '6' => trip 에서 serial 이 최초 발견된 index: 11
즉 locInTrip[here(3)] = 11이 된다.

두 노드를 거치는 순환번호중 가장 작은 번호가 공통조상이 된다.

//한 노드를 가리키는 번호가 두개(입력에 주어진 번호:no, 전위순회하면서 다시 매긴 번호:serial)
//전위순회를 통해 각 노드에 새로 붙인 번호를 일련번호(serial)라고 부르자
//순회과정에서 만나는 각 노드들의 일련번호를 순서대로 모은 배열을 trip[]이라고 부르자
"그리고 trip 내에서 각 노드들의 첫번째 위치를 저장하는 배열 locInTrip[], 각 노드의 깊이를 계산하는 배열 depth[]을 만들되
"이 두 배열의 인덱스는 일련번호가 아닌 입력에 주어진 순서라고 합시다"

//p752: 최소 공통 조상문제(최소 경로길이 구함)를 구간 최소 질의(RMQ) 문제로 바꾸기
const int MAX_N = 100000;
int n;
vector<int> child[MAX_N];	//원본트리를 나타냄
//트리의 번호와 일련번호 사이의 대응 관계
int no2serial[MAX_N], serial2no[MAX_N];	//no: 원래번호, serial: 전위순회 일련번호
//각 노드(no)가 trip에 처음 등장하는 위치, 그리고 각 노드의 깊이
int locInTrip[MAX_N];	//인덱스는 원래번호 기준이고 나타내는건 트립을 기준이므로 인덱스를 serial 번호화 한 것으로 처리됨을 명심!!!!
int depth[MAX_N];
//다음 일련번호
int nextSerial;
//깊이가 d인 노드 here이하를 전위 탐색한다. 이전노드의 방문도 탐색에 포함
void traverse(int here, int d, vector<int>& trip) { //trip은 처음엔 빈벡터
	//traverse()가 처음 방문하자마자 일련번호를 부여한다. 
	"다시방문(이전노드) 할 때는 일련번호 부여 안한다."
	//이렇게 하면 항상 부모는 자손보다 작은 일련번호를 갖게 된다.
	no2serial[here] = nextSerial;	//전역변수, 최초 0으로 세팅되어 있음
	serial2no[nextSerial] = here;
	++nextSerial;
	//깊이계산
	depth[here] = d;
	//trip에 현재 노드의 일련번호를 추가한다.
	locInTrip[here] = trip.size();	//here가 구간트리 상에서 존재하는 곳(첫번째 방문임)
									//엄밀히 한다면 구간트리가 아닌 원본 배열상에서 존재하는 곳을 가르킴
									//애초에 구간트리는 시작지점이 1부터 였으니...
	trip.push_back(no2serial[here]);
	//모든 자식 노드를 방문
	for (int i = 0; i < child[here].size(); ++i) {
		traverse(child[here][i], d + 1, trip);
		//자식 노드를 방문하고 현재 노드로 돌아올 때마다 다시 추가하기!!!!
		trip.push_back(no2serial[here]);	//이전 노드로 돌아올땐 일련번호 부여 안함
	}
}
//트리를 전위순회하며 각종 필요한 정보를 계산하고(원번호랑 새로운 번호(전위순위로 매기는 번호) 설정 매칭, trip설정, locInTrip설정, depth설정)
//RMQ구간 트리를 만들어 반환한다.
RMQ* prepareRMQ() {
	nextSerial = 0;
	//순회 과정에서 만나는 노드들의 일련 번호를 담는다.
	vector<int> trip;
	traverse(0, 0, trip);	//here:root, depth:0, trip:빈 벡터
	return new RMQ(trip);	//실제 구간트리를 만든다.
}

//p753: 최소공통조상문제를 이용해 트리 위에서의 경로의 길이를 구하기
//u와 v사이의 거리를 계산한다.
int distance(RMQ* rmq, int u, int v) {
	//trip[]배열에서 u와 v의 첫 출현 위치를 찾는다.
	int lu = locInTrip[u], lv = locInTrip[v];
	if (lu > lv) swap(lu, lv);
	//rmq는 u와 v의 최소 공통조상의 일련번호를 반환한다. (least common ancester)
	int lca = serial2no[rmq->query(lu, lv)]; 
	//query(left, right, 1, 0, n-1); //1은 구같트리상의 인덱스임 그외에는 0부터 시작
	return depth[u] + depth[v] - 2 * depth[lca];
}
//트리 세팅하는거 잘보삼. 유용하다!!!!
int main() {
	int cs; cin >> cs;
	rep(cc,cs) {
		int queries; cin >> n >> queries;
		rep(i,n) child[i].clear();
		rep2(i,1,n) {
			int parent;
			cin >> parent;	//parent:아버지, i: 자식
			child[parent].push_back(i);
		}
		RMQ* rmq = prepareRMQ();	//O(N)
		rep(i,queries) {			//한쌍의 공통조상을 찾는데 걸리는 시간 O(lgN)
			int a, b; cin >> a >> b;
			cout << distance(rmq, a, b) << endl;
		}
	}
}
총 13명이면 0번이 생략된 12개의 숫자가 딸려온다.
"0번은 시조니 부모가 없다"
자식	1	2	3	4	5	6	7	8	9	10	11	12
아버지	0	1	1	3	3	0	6	0	8	9	9	8

const int max_n = 100000; int n; vi child[max_n];
int no2serial[max_n], serial2no[max_n], locInTrip[max_n], depth[max_n];
int nextSerial;
void traverse(int here, int d, vi& trip) {
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	++nextSerial;
	depth[here] = d;
	locInTrip[here] = trip.size();
	trip.pb(no2serial[here]);
	rep(i,child[here].size()) {
		traverse(child[here][i], d + 1, trip);
		trip.pb(no2serial[here]);
	}
}

RMQ* prepareRMQ() { 
	nextSerial = 0; vi trip;
	traverse(0, 0, trip);
	return new RMQ(trip);
}
int distance(RMQ* rmq, int u, int v) {
	int lu = locInTrip[u], lv = locInTrip[v];
	if (lu > lv) swap(lu, lv);
	int lca = serial2no[rmq->query(lu, lv)];
	return depth[u] + depth[v] - 2 * depth[lca];
}
int main() {
	int cs; cin >> cs;
	rep(cc,cs) {
		int queries; cin >> n >> queries;
		rep(i,n) child[i].clear();
		rep2(i,1,n) { int prnt; cin >> prnt; child[prnt].pb(i); }
		RMQ* rmq = prepareRMQ();
		rep(i,queries) { int a, b; cin >> a >> b;
			cout << distance(rmq, a, b) << endl;
		}
	}
}
https://algospot.com/judge/submission/detail/473211	
// 윗소스를 힌트삼아 내가 짜본것.. 정말 더러운 코드


//구간트리의 진화 형태
//펜윅 트리(PenWick Tree) 혹은 이진 인덱스 트리(binary indexed tree) 라고 불림
"구간 합 대신 부분 합 만을 빠르게 계산할 수 있는 자료 구조를 만들어도 구간 합을 계산 할 수 있다"

"길이가 15인 배열의 구간 트리"
[0,															 14]

[0,							 7] [8,							 14]

[0,			 3] [4			 7] [8,			  11] [12,		 14]

[0,	 1] [2,  3] [4,  5] [6,  7] [8,  9] [10,  11] [12,  13] [14]

[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13]
"길이가 15인 배열의 펜윅 트리"
//[0,															 14] //!!!! 이건 없군요 14로 끝나는 놈이 2개 있으면 안되죠
[0,							  7]
[0,			  3]				[8,			  11]
[0,	 1]			[4,	 5]			[8,	 9]			  [12,	13]
[0]		[2]		[4]		[6]		[8]		[10]	  [12]	    [14]
개수는 N 즉 15개가 된다~

"길이가 16인 배열의 구간 트리"
[0,																  15]

[0,							 7] [8,								  15]

[0,			 3] [4			 7] [8,			  11] [12,			  15]

[0,	 1] [2,  3] [4,  5] [6,  7] [8,  9] [10,  11] [12,  13] [14,  15]

[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15]

"길이가 16인 배열의 펜윅 트리"
[0,																  15] //!!!! 이건 있군요
[0,							  7]
[0,			  3]				[8,			  11]
[0,	 1]			[4,	 5]			[8,	 9]			  [12,	13]
[0]		[2]		[4]		[6]		[8]		[10]	  [12]	    [14]
16개를 가지는 군요
tree[i] = 오른쪽 끝 위치가 A[i]인 구간의 합(구간의 왼쪽 위치는 오른쪽 위치가 정해지면 자동으로 결정된다)

"구간의 맨 처음에 빈 원소가 하나 추가 되었다고 가정한 펜윅트리"
[																  16]
[							  8]
[			  4]				[			  12]
[	 2]			[	 6]			[	10]			  [		14]
[1]		[3]		[5]		[7]		[9]		[11]	  [13]		[15]

psum[7]을 구한다면 = tree[7] + tree[6] + tree[4] = 111 + 110 + 100 
"최종 비트를 지운다 !!!!"
while (pos > 0) { ret += tree[pos]; pos &= (pos - 1); }

5번 원소를 세팅하면: tree[5] -> tree[6] -> tree[8] -> tree[16] 순으로 세팅된다. 
					 101	 -> 110		-> 1000	   -> 10000
7번 원소를 세팅하면: tree[7] -> tree[8] -> tree[16] 순으로 세팅된다.
					 111	 -> 1000	-> 10000
"최종 비트를 더한다 !!!!"	p584
while (pos < tree.size()) { tree[pos] += val; pos += (pos & -pos);
1010 => 10		추출 : 1010 & 0110
1000 => 1000	추출 : 1000 & 1000
101  => 1		추출 : 101	& 011

//p757 펜윅 트리의 완전한 구현
//가상의 배열 A[]의 부분합을 빠르게 구현할 수 있도록 한다.
//초기화시에는 A[]의 원소가 전부 0이라고 생각한다.
"구간트리는 O(n)으로 초기화되지만
"펜윅트리는 O(nlon)으로 초기화된다
struct FenwickTree{
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {}	// n은 구간갯수를 의미한다. 인덱스 0은 사용 못하기에 갯수를 1 증가 시켜 공간 할당함
		// sum(n) 은 호출하면 안된다. 0부터 n-1 까지만 호출가능하다. => 내부에선 1~n 으로 매핑됨
		// 정리하자면 n 개의 구간이 있으면 n+1 로 할당해야 함
	//A[0..pos]의 부분 합을 구한다.
	int sum(int pos) {
		//인덱스가 1부터 시작한다고 생각하자
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			//다음 구간을 찾기 위해 최종 비트를 지운다!!!!
			// pos -= (pos & -pos);
			pos &= (pos - 1); //1010 - 1 => 1001, 1010 & 1001 => 1000
		}
		return ret;
	}
	//A[pos]에 val을 더한다 : 이걸 n번 호출하여 초기화한다, 한번 수행시 O(lgn)
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			//다음 구간을 찾기 위해 최종 비트를 더한다.
			pos += (pos & -pos);	//대박코드 !!!! 최종비트 추출
			//pos: 1010 인 경우
			//(pos & -pos) = 1010 & 0110 = 0010
			//1010 + 0010 = 1100
	//고찰
	"pos:십진수 10에서 12로 변경됨"
	"반전비트를 & 시키면 000...0000 이 된다, 반전비트에 + 1을 한 놈을 & 시키면 최초 1만 남지"
		}
	}
};
펜윅트리구현은 30줄도 안되며 간결해서 "계속 변하는 배열의 구간 합"을 구할때는 구간 트리보다
펜윅트리를 훨씬 자주 씁니다.



구간 업데이트를 logN 에 수행, 특정 위치 값을 logN 에 구해주는 펜윅 구현 링크
https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
https://github.com/kartikkukreja/blog-codes/blob/master/src/Range%20Updates%20%26%20Point%20Queries%20with%20BIT.cpp
    
#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))
using namespace std;
typedef long long ll;
// Fenwick tree
// Only the updates are stored. Original array entries are not
// stored and are assumed to be 0. If the original array entries
// are non-zero, we can store them in another array A and modify
// point query to return query(b) + A[b].
ll ft[10005];	
int N;// Array size
// Point query: Returns the value at position b in the array
ll query(int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}
// Point update: Adds v to the value at position k in the array
void update(int k, int v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}
// Range update: Adds v to each element in [i...j] in the array
void range_update(int i, int j, int v)	{
	update(i, v);
	update(j + 1, -v);
}

int main()  {
	int T, U, Q, i, l, r, val;
	scanf("%d", &T);
	while (T--)	{
		scanf("%d %d", &N, &U);
		memset(ft, 0, (N+1) * sizeof(ll));
		
		// U -> no. of updates
		for (i = 0; i < U; i++)	{
			// l and r are zero-based indices
			scanf("%d %d %d", &l, &r, &val);
			range_update(l + 1, r + 1, val);
		}
		// Q -> no. of queries
		scanf("%d", &Q);
		for (i = 0; i < Q; i++)	{
			// val is zero-based index
			scanf("%d", &val);
			printf("%lld\n", query(val + 1));
		}
	}
    return 0;
}


// petr 의 펜윅트리 구간업데이트 구간합 구하기
void update(int left, int right, int by) {
	internalUpdate(left, by, -by * (left - 1));
	internalUpdate(right, -by, by * right);
}
void internalUpdate(int at, int mul, int add) {
	while (at < dataMul.size()) {
		dataMul[at] += mul;
		dataAdd[at] += add;
		at |= (at + 1);
	}
}
int query(int at) {
	int mul = 0;
	int add = 0;
	int start = at;
	while (at >= 0) {
		mul += dataMul[at];
		add += dataAdd[at];
		at = (at & (at + 1)) - 1;
	}
	return mul * start + add;
}
11 => 1011 , 1100 -> 1111
"길이가 16인 배열의 펜윅 트리"
[0,																  15]
[0,							  7]
[0,			  3]				[8,			  11]
[0,	 1]			[4,	 5]			[8,	 9]			  [12,	13]
[0]		[2]		[4]		[6]		[8]		[10]	  [12]	    [14]
16개를 가지는 군요


update(4, 11, 3)	// [4..11] 구간에 3만큼 더한다.
	internalUpdate(4, 3, -3 * (4 - 1))	// left, by, -by * (left - 1)
		dataMul[4] += 3
		dataAdd[4] += -9
		
		dataMul[5] += 3
		dataAdd[5] += -9
		
		dataMul[7] += 3
		dataAdd[7] += -9
		
		dataMul[15] += 3
		dataAdd[15] += -9
	
	internalUpdate(11, -3, 3 * 11)	// right, -by, by * right
		dataMul[11] += -3
		dataAdd[11] += 33
		
		dataMul[15] += -3		// dataMul[15] = 0
		dataAdd[15] += 33		// dataAdd[15] = 24
		
	query(15)
		mul * start + add = 0 * 15 + dataAdd[15] = 24		// [4..11] 에는 3이 채워져 있음 3 * 8 = 24 
		
update(7, 14, 2)	// [7..14] 구간에 2만큼 더한다.


// petr 고찰!!!!!!!!! 상태의 유일성이 보장되는가? 전체 구간이 A일때와 그것을 마구 왔다갔다 update 한뒤 다시 A 가 되도록 할때 dataMul, dataAdd 의 값들이 항상 동일한가?
// 유일하지 않다면 실무에서 쓰기 힘들수 있다. 누적되어 값이 쌓이면 구간 A 를 표현할때 어쩔때는 가능하지만 어쩔때는 불가능하다. 그리고 그 불가능이 너무 쉽게 발생할 수 있다.
// 꼭 test 해보자.
// 시나리오)		A: [0..0] 에 2를 더함, [1..1] 에 2를 더함 .... [15..15] 에 2를 더함
//				A':[0..15] 에 2를 더함
A와 A' 의 내용물(dataMul, dataAdd) 이 같은가? : 다르다.



// 이해를 돕고자 다시 기술한다. !!!!!!!!
// 세팅 되는 과정의 줄기가 뻗어나가는 방향과 질의를 수행하는 과정의 줄기가 뻗어나가는 방향을 상상하라.
// 그리고 그 교착노드는 하나임을 기억하라. (핵심임)
// petr 의 코드는 이해하기 약간 난해하다. 0base 라서 약간 더 까다롭다.
// 구간 업데이트, 구간합을 logn 에 구하는것을 다시 정리해보자. 1base 로 말이다.
1. 펜윅트리의 특징
	update(idx, val) 을 수행하면 노드들이 갱신
	ex) 7번 노드에서 3을 더한다면 : // update(7, 3)
		7번, 8번, 16번 노드에 모두 3이 더해진다.
		3번 노드에서 5를 더한다면 : // update(3, 5)
		3, 4, 8, 16번 노드에서 모두 5가 더해진다.
1base 펜윅트리
[																  16]
[							  8]
[			  4]				[			  12]
[	 2]			[	 6]			[	10]			  [		14]
[1]		[3]		[5]		[7]		[9]		[11]	  [13]		[15]

	query(11) 을 수행시 update 와는 반대로 역방향 대각선으로 뻗어간다.
	그래서 딱 한지점에서 갱신되어진 노드가 만나게 된다.
	query(11) 은 11, 10, 8 // 1011->1010->1000->0 
	노드들을 거치게 되며 이때 8번 노드에 값인 +3, +5 가 수행된 +8을 가지게 되는 것이다.
	명심해라 질의를 할때는 역방향 대각선이며 딱 한 지점에서 갱신된 노드와 만나게 된다. // update 한번의 예시임. 
	

2. 구간 업데이트 logN, 특정 위치값 logN 에 구하기	
	일반 펜윅트리의 query(idx) 는 idx 까지의 구간 합을 구해준다.
	구간업데이트를 다음과 같이 해보자. 
		range_update(left, right, val)
			update(left, val)
			update(right + 1, -val)
			
1base 펜윅트리
[																  16]
[							  8]
[			  4]				[			  12]
[	 2]			[	 6]			[	10]			  [		14]
[1]		[3]		[5]		[7]		[9]		[11]	  [13]		[15]		
	range_update(3, 11, 19) // left, right, value
	3, 4, 8, 16번 노드에는 19가 더해진다.
	12, 16번 노드에는 -19가 더해진다.
	// 기존 펜윅트리에서 구간합으로 전파됨을 여기선 구간 갱신에 이용할 수 있는 것이다.
	// right 요소를 빼고 생각해보자. (right 가 INF 라 치면)
	update(3, 19) // 3이상부터 19라는 값이 구간합으로 전파가 된다. : 3부터 INF 구간까지 19로 세팅되었다고 보면 된다.

	
3. petr 소스는 0base 라 보기 힘드니.. 이걸 참고 https://plzrun.tistory.com/entry/Fenwick-Tree-Range-Update-Range-Sum-%ED%8E%9C%EC%9C%85%ED%8A%B8%EB%A6%AC-%EA%B5%AC%EA%B0%84%EC%97%85%EB%8D%B0%EC%9D%B4%ED%8A%B8-%EA%B5%AC%EA%B0%84%ED%95%A9-OlgN%EC%97%90-%EA%B5%AC%ED%95%98%EA%B8%B0-feat-Segment-Tree-Lazy-Propagation
// 핵심: range 영역의 합 자체를 노드에 세팅한다. at * by - add 형식
// left 로 inupdate 되는 구문만 보면 이해하기 쉽다. inupdate(left, by, -by * (left - 1)) 은
// 각 노드에 세팅되는 값이 at * by - (by * (left - 1)) 이다.
// 이것으로 left .. Inf 지점까지의 구간합이 결정된다.

1base 펜윅트리
[																  16]
[							  8]
[			  4]				[			  12]
[	 2]			[	 6]			[	10]			  [		14]
[1]		[3]		[5]		[7]		[9]		[11]	  [13]		[15]		
// [left..INF] 구간 갱신을 예로 들어보자. 
inupdate(left:5, 7, -7 * (left - 1)) 수행시
	5번, 6번, 8번, 16번 노드에서 갱신이 일어난다. tmul = 7, tadd = -28
inupdate(left:10, 5, -5 * (left - 1)) 수행시
	10번, 12번, 16번 노드에서 갱신이 일어난다. tmul = 5, tadd = -45 // 단 16번 노드는 tmul = 7 + 5, tadd = -28 - 45 이다. !!!!

range_query(16) 을 수행시 갱신과 관련된 노드를 딱 한번씩 만나게 된다. 
이경우 16번 노드를 중복해서 만나는 군 (처음 갱신때 세팅된 16번 노드, 두번째 갱신때 세팅된 16번 노드)
	7 * 16 - 28
	5 * 16 - 45
	// 이 두개의 합이 되며 분배법칙이 성립되므로
	(7 + 5) * 16 - (28 + 45) 가 되어 119 가 된다.
	// 실제 값도 (16 - 5 + 1) * 7 + (16 - 10 + 1) * 5 = 84 + 35 = 119 가 된다.

constexpr int N = 100000;
ll tadd[N + 1], tmul[N + 1];
void inupdate(int at, ll mul, ll add) {
	assert(1 <= at && at <= N);
	for (; at <= N; at += at & -at) {
		tmul[at] += mul;
		tadd[at] += add;
	}
}
void range_update(int left, int right, ll by) {
	inupdate(left, 		by,	-by * (left - 1));
	// left 때랑 똑같다 보면 됨 right + 1 부터 -by 로 각 위치의 값이 갱신되며 right 이하의 값은 -by 한 만큼 보충한다.
	inupdate(right + 1, -by, by * right);	
}
ll range_query(const int at) {
	if (at == 0) return 0;
	assert(1 <= at && at <= N);
	
	ll mul = 0, add = 0;
	for (int i = at; i; i -= i & i) {
		mul += tmul[i];
		add += tadd[i];
	}
	return at * mul + add;
}
int main() {
	int Q; cin >> Q;
	while (Q--) {
		int type; cin >> type;
		if (type == 1) {
			int L, R, by;
			cin >> L >> R >> by;		// 1base 입력
			range_update(L, R, by);
		} else if (type == 2) {
			int L, R;
			cin >> L >> R;
			cout << range_query(R) - range_query(L - 1) << '\n';
		} else exit(1);
	}
	return 0;
}






//삽입 정렬 시작 재기(MEASURETIME, 중)
=>SWAP횟수 재기 문제임
void insertionSort(vector<int>& A) {
	for (int i = 0; i < A.size(); ++i) {
		//A[0..i-1]에 A[i]를 끼워 넣는다.
		int j = i;
		while (j > 0 && A[j - 1] > A[j]) {
			//불변식 b: A[j + 1..i]의 모든 원소는 A[j]보다 커야 한다.
			//불변식 c: A[0..i] 구간은 A[j] 를 제외하면 정렬되어 있다.
			swap(A[j - 1], A[j]);
			--j;
		}
	}
}
7 5 2 3 1	초기상태

5 7 2 3 1	(7, 5)swap

5 2 7 3 1	(7, 2)swap
2 5 7 3 1				(5, 2)swap

2 5 3 7 1	(7, 3)swap
2 3 5 7 1				(5, 3)swap

2 3 5 1 7	(7, 1)swap
2 3 1 5 7				(5, 1)swap
2 1 3 5 7							(3, 1)swap
1 2 3 5 7										(2, 1)swap

인버전 갯수
[7 5 2 3 1]	  7:4개		5:3개		3:1개		2:1개
"삽입 정렬할 때 두 숫자를 바꾸는 경우는 앞의 수가 뒤의 수보다 큰 경우 뿐이기 때문에
"숫자를 움직이는 횟수와 반전의 수는 정확히 같습니다"
인근 두 숫자를 한번 swap할 때마다 정확히 반전이 하나씩 줄어든다. imagin!!!!

문제에서 
	원 배열의 길이: N(1 <= N <= 50000)
	각 배열의 원소 a[i](1 <= a[i] < 1000000)	// 최대 a[i]: 999999
2
5
5 1 4 3 2
10
7 8 6 6 1 9 4 4 3 10 "수의 중복을 허용한다!!!!"
"7"
"25"
//p760 삽입 정렬 시간 재기 문제를 펜윅 트리로 해결하기
long long countMoves(const vector<int>& A) {
	//각 숫자의 출현 횟수를 저장하는 펜윅 트리를 만듭시다!!!!"
	FenwickTree tree(1000000); //배열의 길이가 아닌 수의 범위를 이용 !!!!
	//생성자에서 tree공간은 안쓰는 제로영역이 포함되어 1000001개로 된다.
	long long ret = 0;
	for (int i = 0; i < A.size(); ++i) {
			// 1 ~ 999999 범위에서 정렬된 수의 개수(사실 0도 처리 가능, 그래서 1000000개를 커버할 수 있다.)
			// 1 ~ A[i] 범위에서 정렬된 수의 개수
		ret += tree.sum(999999) - tree.sum(A[i]);
		"7,8,6이 들어간 상태에서 6을 추가한다면 swap은 두번만 하면 되제"
		"tree.tree[7] = 1, tree.tree[8] = 1, tree.tree[6] = 1"
		tree.add(A[i], 1);	"tree[6] = 2"
	}
	return ret;
}
" 1, 2, 5, 7, 11 이 들어간 상태(순서는 맘대로)
tree 구조는
1 (00001):	1						
2 (00010):	1	1
3 (00011):	
4 (00100):	1	1
5 (00101):			1
6 (00110):			1
7 (00111):				1
8 (01000):	1	1	1	1
9 (01001):	
10(01010:
11(01011):					1
12(01100):					1
13(01101):			
14(01110):
15(01111):
16(10000): 1	1	1	1	1
17(10001):
...
여기다가 6을 삽입한다면 뒤집기 갯수는 다음과 같이 구할 수 있다.
	add = tree.sum(999999) - tree.sum(A[i]) 
		= tree.sum(999999) - tree.sum(6)	//정렬된 수라 보고 거기에 6을 넣는다면
		= 5 - 3								//현재까지 정렬된 수 - 6보다 작은 정렬된 수의 갯수 가 된다.!!!!
	tree.add(6, 1);							//수열의 원소는 같은 숫자가 들어와도 동작되는 군요.
"정렬된 수들(1, 2, 5, 7, 11)에서 6을 삽입한다면
"1 ~ 11 범위의 정렬된 수는 5개
"1 ~ 6	범위의 정렬된 수는 3개
그러므로 2개만 이동이 필요.
//O(NlgM) : 50000 * lg(1000000)


//구간트리로 풀고 제출한거 알고스팟 통과함: 1260ms
vi arr;
struct RMQ {
	int n;
	vi rangeSum;
	RMQ(cvi& arr) {
		n = arr.size();
		rangeSum.resize(n * 4);
		init(arr, 1, 0, n - 1);
	}
	int init(cvi& arr, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR) return rangeSum[node] = arr[nodeL];
		int mid = (nodeL + nodeR) / 2;
		int leftSum = init(arr, node * 2, nodeL, mid);
		int rightSum = init(arr, node * 2 + 1, mid + 1, nodeR);
		return rangeSum[node] = leftSum + rightSum;
	}
	int query(int left, int right, int node, int nodeL, int nodeR) {
		if (right < nodeL || nodeR < left) return 0;
		if (left <= nodeL && nodeR <= right) return rangeSum[node];
		int mid = (nodeL + nodeR) / 2;
		return  query(left, right, node * 2, nodeL, mid) +
				query(left, right, node * 2 + 1, mid + 1, nodeR);
	}
	int query(int left, int right) { return query(left, right, 1, 0, n - 1); }
	int update(int index, int newVal, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index)
			return rangeSum[node];
		if (nodeL == nodeR) return rangeSum[node] = newVal;
		int mid = (nodeL + nodeR) / 2;
		return rangeSum[node] = update(index, newVal, node * 2, nodeL, mid) +
								update(index, newVal, node * 2 + 1, mid + 1, nodeR);
	}
	int update(int index, int add) { 
		arr[index] += add;
		int newVal = arr[index]; 
		return update(index, newVal, 1, 0, n - 1); 
	}
};
int main() {
	int cs; scanf("%d", &cs);
	rep(cc,cs) {
		int n; scanf("%d", &n);
		arr.clear();
		arr.resize(1000001);
		RMQ rmq(arr);
		int sol = 0;
		rep(i,n) {
			int index; scanf("%d", &index);
			rmq.update(index, 1);
			//int add = rmq.query(index + 1, 1000000);
			//cout << add << endl;
			//sol += add;
			sol += rmq.query(index + 1, 1000000);	//index보다 큰것만 inversion임
		}
		printf("%d\n", sol);
	}
	return 0;
}


//p   : 삽입정렬 시간 제기 문제를 트립으로해결하기
//만들었던 트리를 지운다.
void deleteTree(Node* node) {
	if (node == NULL) return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}
//트립을 이용해 문제를 해결한다.
"펜윅과 차이점: A에 들어갈 수의 범위가 커도 상관없다!!!!"
long long countMoves2(const vector<int>& A) {
	Node* root = NULL;
	long long ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		//{현재까지 쌓인 갯수} - {현재까지 쌓인 것중 A[i]이하의 갯수}
		// = {"현재까지 쌓인 것중 A[i] 보다 큰 놈의 갯수"}
		ret += i - countLessThan(root, A[i] + 1); //root->size - countLessThan(root, A[i] + 1);
		root = insert(root, new Node(A[i]));
	}
	deleteTree(root);
	return ret;
}

//p762: 주어진 수열에서 반전의 수를 세는 좋은 방법: 병합정렬 merge sort 머지소트
"<이 방식은 많이 사용되는 것이므로 주의깊게 보자>"

주어진 수열 A를 절반으로 나눠 각각 L, R이라고 부릅시다. "이때 A에 포함된 반전들은 다음 분류중 하나에 속합니다"
"1. 두 수가 모두 L에 포함되어 있거나
"2. 두 수가 모두 R에 포함되어 있거나
"3. 더 큰 수가 L에, 더 작은 수가 R에 포함되어 있습니다.
//코드 24.10: 삽입정렬 swap개수 세기(수열에서 반전의 수를 세기): 병합정렬을 이용해 풀기
//A[left..right]를 재귀적으로 병합정렬하고
//해당 범위 내의 inversion의 수를 반환한다.
long long countMoves3(vector<int>& A, int left, int right) {
	//기저사례: 구간의 길이가 1이라면 이미 정렬되었고, inversiton도 없다.
	if (left == right) return 0;
	//반으로 나눠서 부분 정복
	int mid = (left + right) / 2;
	long long ret = countMoves3(A, left, mid) + 
					countMoves3(A, mid + 1, right);
	//임시 배열에 정렬된 두 부분 배열을 합친다.
	vector<int> tmp(right - left + 1);
	int tmpIndex = 0, leftIndex = left, rightIndex = mid + 1;
	//어째 많이 봐온 형식이다. 이런 류는 어떤걸 표현할때 사용되는지 정형화해보자
	while (leftIndex <= mid || rightIndex <= right) {
		if (leftIndex <= mid &&
			(rightIndex > right || A[leftIndex] <= A[rightIndex])) {
			"//왼쪽이 오른쪽보다 같거나 작으면
			tmp[tmpIndex++] = A[leftIndex++];	
		}
		else {
			"왼쪽이 오른쪽보다 크면 inversion
			//A[rightIndex]는 왼쪽 부분 배열에 남아있는 모든 수보다 작다.
			//그러므로 왼쪽 부분 배열에 남아있는 수들 만큼 inversion을 더해준다.
			ret += mid - leftIndex + 1;
			tmp[tmpIndex++] = A[rightIndex++];
		}
	}
	//while 루프가 종료되었는데 rightIndex가 남아 있다면
	//그대로 두도 상관없구나. 이미 정렬된 상태니..

	//tmp에 합친 결과를 A로 다시 복사한다.
	for (int i = 0; i < tmp.size(); ++i)
		A[left + i] = tmp[i];
	return ret;
}

cm(4321, 0, 3)
	cm(4321, 0, 1)
		cm(4321, 0, 0)
		"ret = 0, 4321
		cm(4321, 1, 1)
		"ret = 0, 4321
	"ret = 1, 3421
	cm(3421, 2, 3)
		cm(3421, 2, 2)
		"ret = 1, 3421
		cm(3421, 3, 3)
		"ret = 1, 3421
	"ret = 2, 3412
"ret = 6, 1234 //mid - leftIndex + 1 => 1 - 0 + 1


// 구간합문제를 다르게 푸는 방법: 간단함
sqrt Decomposiion 	// N*logN 의 수행시간대신 N*sqrt(N) 의 수행시간을 가짐
http://kesakiyo.tistory.com/22?category=590414
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. 
M은 수의 변경이 일어나는 회수이고, K는 구간의 합을 구하는 회수이다. 
그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 
그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 
1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.

수의 갯수가 1000000개 있다.
질문이 10000번 한다.
세팅도 10000번 한다.

5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5

// 1. 전처리: O(N)
// 2. 구간의 합을구하는 쿼리: O(sqrt(N))
// 3. 특정 값을 갱신: O(1)
// 쿼리의 수가 Q개라면 우리는 O(N + Qroot(N)) 의 시간이 걸림
// 물론 세그먼트 트리를 사용하면 O(N + Qlog(N)) 이라는 더 좋은 시간에 문제를 해결할 수 있다.
void init() {
	sz = sqrt(n)
	for (int i = 0; i < n; ++i) 
		bucket[i / sz] += A[i];
}
sz 가 5이고 구간 7에서 18까지의 값을 구한다면
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	...
							|			[				]				|
// 구간내 완벽하게 포함된 곳은 [] 로 된다.

sz 가 5이고 구간 8에서 11인 경우
									]	[	// lo 는 10이고 hi 는 9임 ㅎㅎ									
const int MAX = 1e6 + 10;
int sz, n, m, k, q;
long long y, A[MAX], bucket[MAX];									
// 구간 처리가 참 깔끔하다. 재활용하기 좋은 코드다!!!!!!!!
long long query(int lo, int hi) {
	long long ret = 0;
	while (lo % sz != 0 && lo <= hi)	// 구간의 왼쪽에 애매하게 걸쳐있는 묶음의 원소를 더함
		ret += A[lo++];
	while ((hi + 1) % sz != 0 && lo <= hi) // 오른쪽에 애매하게 걸쳐있는 묶음의 원소를 더함
		ret += A[hi--];
	while (lo <= hi) {
		ret += bucket[lo / sz];
		lo += sz;
	}
	return ret;
}
// 원소의 값을 갱신
void update(int pos, long long val) {
	// 원래 원소의 값과 갱신해야 하는 값의 차이를 계산
	long long diff = val - A[pos];
	A[pos] = val;	// 기존 원소를 새로운 값으로 대체
	// 기존 원소가 속해있는 묶음에 댕신으로 인해 생기는 차이만큼의 값을 더해준다.
	bucket[pos / sz] += diff;	
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) scanf("%lld", &A[i]);
	init();
	for (int iter = 0; iter < m + k; ++iter) {
		scanf("%d", &q);
		if (q == 1) {		// 특중 원소의 값을 갱신
			int pos;
			long long val;
			scanf("%dlld", &pos, &val);
			update(pos - 1, val);
		} else {
			int lo, hi;
			scanf("%d%d", &lo, &hi);
			printf("%lld\n", query(lo - 1, hi - 1));
		}
	}
}




//구간트리 확장 (2차원 구간 트리) 2d segment tree
"2D Segment/Quad Tree Explanation with C++"
https://stackoverflow.com/questions/25121878/2d-segment-quad-tree-explanation-with-c/25122078#25122078
#include <bits/stdc++.h>
using namespace std;
#define Max 506
#define INF (1 << 30)
int P[Max][Max]; // container for 2D grid	//[x축][y축] 이라 세팅하기 까탈스럽네...

/* 2D Segment Tree node */
struct Point {
    int x, y, mx;
    Point() {}
    Point(int x, int y, int mx) : x(x), y(y), mx(mx) {}

    bool operator < (const Point& other) const {
        return mx < other.mx;
    }
};

struct Segtree2d {
    Point T[2 * Max * Max];	//!!!!구간트리를 구성하는 것임
    int n, m;

    // initialize and construct segment tree
    void init(int n, int m) {
        this -> n = n;
        this -> m = m;
        build(1, 1, 1, n, m);	//{ 노드번호, {x1, y1}, {x2, y2} }
    }

    // build a 2D segment tree from data [ (a1, b1), (a2, b2) ]
    // Time: O(n logn) : 여기선 (n * m) log (n * m) 이죠
    Point build(int node, int a1, int b1, int a2, int b2) {
        // out of range
        if (a1 > a2 or b1 > b2) //이 경우는 안 발생할거 같다만.. 브레이크 포인트 걸어보자
							//탑니다. a1 == 3, a2 == 3, b1 == 1, b2 == 2 인 경우 아래 자식중 두번째 build 호출시
							//(a1 + a2) / 2 + 1 => 4
							//a2	=> 3	이 되므로 범위 역순이 생길수 있습니다.
							//a1 == a2 가 같으면 1차원 구간트리는 기저가 호출되나
							//2차원은 b1, b2 가 다를 수 있기에 발생하는 현상입니다.
            return def();

        // if it is only a single index, assign value to node
        if (a1 == a2 and b1 == b2)
            return T[node] = Point(a1, b1, P[a1][b1]);

        // split the tree into four segments	//	3	4
        T[node] = def();						//	1	2
        T[node] = maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );		//1
        T[node] = maxNode(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));		//2
        T[node] = maxNode(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );		//3
        T[node] = maxNode(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );	//4
        return T[node];
    }

    // helper function for query(int, int, int, int);
    Point query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
        // if we out of range, return dummy
        if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
            return def();

        // if it is within range, return the node
        if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
            return T[node];

        // split into four segments
        Point mx = def();
        mx = maxNode(mx, query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));

        // return the maximum value
        return mx;
    }

    // query from range [ (x1, y1), (x2, y2) ]
    // Time: O(logn)
    Point query(int x1, int y1, int x2, int y2) {
        return query(1, 1, 1, n, m, x1, y1, x2, y2);
    }

    // helper function for update(int, int, int);
    Point update(int node, int a1, int b1, int a2, int b2, int x, int y, int value) {
        if (a1 > a2 or b1 > b2)
            return def();

        if (x > a2 or y > b2 or x < a1 or y < b1)
            return T[node];

        if (x == a1 and y == b1 and x == a2 and y == b2)
            return T[node] = Point(x, y, value);

        Point mx = def();
        mx = maxNode(mx, update(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value) );
        mx = maxNode(mx, update(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value));
        mx = maxNode(mx, update(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value));
        mx = maxNode(mx, update(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value) );
        return T[node] = mx;
    }

    // update the value of (x, y) index to 'value'
    // Time: O(logn)
    Point update(int x, int y, int value) {
        return update(1, 1, 1, n, m, x, y, value);
    }

    // utility functions; these functions are virtual because they will be overridden in child class
    virtual Point maxNode(Point a, Point b) {
        return max(a, b);
    }

    // dummy node
    virtual Point def() {
        return Point(0, 0, -INF);
    }
};

/* 2D Segment Tree for range minimum query; a override of Segtree2d class */
struct Segtree2dMin : Segtree2d {
    // overload maxNode() function to return minimum value
    Point maxNode(Point a, Point b) {
        return min(a, b);
    }

    Point def() {
        return Point(0, 0, INF);
    }
};

// initialize class objects
Segtree2d Tmax;
Segtree2dMin Tmin;


/* Drier program */
int main(void) {
    int n, m;
    // input
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &P[i][j]);


    // initialize
    Tmax.init(n, m);
    Tmin.init(n, m);

    // query
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int aaa = Tmax.query(x1, y1, x2, y2).mx;
    int bbb = Tmin.query(x1, y1, x2, y2).mx;

    // update
    int x, y, v;
    scanf("%d %d %d", &x, &y, &v);
    Tmax.update(x, y, v);
    Tmin.update(x, y, v);

    return 0;
}
3 4	//x가 3, y가 4임

1 2 3 4
5 6 7 8
9 10 11 12

int aaa = Tmax.query(1, 1, 3, 2)	//10
int bbb = Tmin.query(1, 1, 3, 2)	//1

aaa = Tmax.query(1, 1, 2, 4)		//8
bbb = Tmin.query(1, 1, 2, 4)		//1

내 머릿속에선 대각선 대칭시켜서 하는게 편함...


//구간트리 응용문제
http://poj.org/problem?id=2750
http://egloos.zum.com/musicdiary/v/4177791	//풀이
원형탁자에서 일부를 선택해 최대화하자.
갱신이 실시간 일어나며, 전체를 선택하면 안됨
크기는 10만이며 갱신도 10만이다.

struct Node {
	int sum;	//자식들의 sum 값의 합
	int maxSum;	//가장 큰 부분합
	int lMaxSum;	//왼쪽을 포함한 연속 선택의 가장 큰 부분함
	int rMaxSum;	//오른쪽을 포함한 연속 선택의 가장 큰 부분합
};
1. tree[부모].sum		= tree[왼쪽자식].sum + tree[오른쪽자식].sum

2. tree[부모].maxSum	= max{	tree[왼쪽자식].maxSum,
								tree[오른쪽자식].maxSum,
								tree[왼쪽자식].rMaxSum + tree[오른쪽자식].lMaxSum }

3. tree[부모].lMaxSum	= max{	tree[왼쪽자식].lMaxSum, 
								tree[왼쪽자식].sum + tree[오른쪽자식].lMaxSum }

4. tree[부모].rMaxSum	= max{	tree[오른쪽자식].rMaxSum,
								tree[왼쪽자식].rMaxSum + tree[오른쪽자식].sum }

//원형이기에
답은
1 "한개의 열이거나
2 "1 ~ a .. c ~ N 인(처음이 포함된 열, 끝이 포함된 열) 두개 형태이거나


고로 답은 아래 둘중 하나가 된다.
tree[루트].maxSum	//한개의 열
tree[루트].sum - tree[루트].minSum	//두개의 열

struct Node {
	int sum;
	int maxSum;
	int lMaxSum;
	int rMaxSum;

	int minSum;
	int lMinSum;
	int rMinSum;
}
한가지 간과한 사실은 모든 구간이 포함되면 안된다는 제약조건인데
애초에 모든 구간이 포함되려면
모든 구간은 양수여야 한다.
따라서 모든것이 양수인경우를 예외처리한다.(한개만 뺀것이 답이므로 그중 가장 작은 수를 빼자)

//북경오리 사이트 통과함 516ms 걸림 
//종만이 코드가 대단한점!!!!
//RR의 대표값만 정의하고 merge를 구현하면 나머진 거의 수정할것 없이 종만이 코드로 대체 가능함 짱짱!!!
const int INF = 987654321;
struct RR {	//RR: RangeResult
	int sum, maxSum, lMaxSum, rMaxSum, minSum, lMinSum, rMinSum;
	RR(int val) : sum(val), maxSum(val), lMaxSum(val), rMaxSum(val), minSum(val), lMinSum(val), rMinSum(val) {}
	RR() {}
};
RR merge(const RR& a, const RR& b) {
	if (a.sum == INF) return b;
	if (b.sum == INF) return a;
	RR ret(INF);
	ret.sum = a.sum + b.sum;
	ret.maxSum = max(max(a.maxSum, b.maxSum), a.rMaxSum + b.lMaxSum);
	ret.lMaxSum = max(a.lMaxSum, a.sum + b.lMaxSum);
	ret.rMaxSum = max(b.rMaxSum, b.sum + a.rMaxSum);
	//minSum구하는것은 햇갈리는군..	//양수만 있다해도 하나는 선택해야 하므로 minSum이 0이 될순 없다.
	ret.minSum = min(min(a.minSum, b.minSum), a.rMinSum + b.lMinSum);
	ret.lMinSum = min(a.lMinSum, a.sum + b.lMinSum);
	ret.rMinSum = min(b.rMinSum, b.sum + a.rMinSum);
	return ret;
}
struct RMQ {
	int n;
	vector<RR> segTree;
	RMQ(cvi& arr) {
		n = arr.size();
		segTree.resize(n * 4);
		init(arr, 1, 0, n - 1);
	}
	RR init(cvi& arr, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR)
			return segTree[node] = RR(arr[nodeL]);
		int mid = (nodeL + nodeR) / 2;
		RR leftRR = init(arr, node * 2, nodeL, mid);
		RR rightRR = init(arr, node * 2 + 1, mid + 1, nodeR);
		return segTree[node] = merge(leftRR, rightRR);
	}
	RR query(int left, int right, int node, int nodeL, int nodeR) {
		if (right < nodeL || nodeR < left) return RR(INF);	//쓸모없는 쓰래기
		if (left <= nodeL && nodeR <= right) return segTree[node];
		int mid = (nodeL + nodeR) / 2;
		return merge(query(left, right, node * 2, nodeL, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeR));
	}
	RR query(int left, int right) { return query(left, right, 1, 0, n - 1); }
	RR update(int index, int newVal, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index)
			return segTree[node];
		if (nodeL == nodeR) return segTree[node] = RR(newVal);
		int mid = (nodeL + nodeR) / 2;
		return segTree[node] = merge(
			update(index, newVal, node * 2, nodeL, mid),
			update(index, newVal, node * 2 + 1, mid + 1, nodeR));
	}
	RR update(int index, int newVal) { return update(index, newVal, 1, 0, n - 1); }
};
int main() {
	int n, m;
	cin >> n;
	vector<int> arr(n);
	rep(i, n) scanf("%d", &arr[i]);
	RMQ rmq(arr);
	cin >> m;
	rep(i, m) {
		int idx, val;
		scanf("%d%d", &idx, &val);
		idx--;
		rmq.update(idx, val);
		RR qr = rmq.query(0, n - 1);
		int sol;
		//!!!!원형형태 처리하는걸 잘봐라: 아주 유용하다.
		//모두가 양수라면
		if (qr.minSum > 0) {
			sol = qr.sum - qr.minSum;	//minSum은 한개만 된다.
		}
		else {
			sol = qr.maxSum;	//1. 한개의 열
			sol = max(sol, qr.sum - qr.minSum);	//2. 중간이 떨어진 두개의 열
		}
		printf("%d\n", sol);
	}
	return 0;
}



https://algospot.com/judge/problem/read/CLUBROOM
//2013 KAIST 교내 대회 : CLUBROOM
//판대기 범위 1 ~ 1024, 1 ~ 1024
//입력 100000번
//아래 코드는 10초 시간내에 테스트케이스를 통과 못했다. 
즉 1024 by 1024 보드에서 10만번 UPDATE된다면 sum 리턴식은 너무 느릴수 있다는 점을 주의하자!!!!
"갱신순서가 답에 영향을 끼치므로 lazy propagation을 활용하기도 어렵다고 본다."
//구사과는 2D 펜윅트리로 sum을 저장했음에도 아주 빠르게 약 700ms에 통과했다.
const int MX = 1025;
//const int MX = 7;
vpii fclt;	//facilities

struct segT2D {
	int n;
	vi tree;
	//segT2D() {
	//	n = MX;
	//	tree.resize(n * n * 4);
	//}
	segT2D(int ny, int nx) {
		n = max(ny + 1, nx + 1);
		tree.resize(n * n * 4);
	}
	void init() {
		tree.clear();
		tree.resize(n * n * 4);
	}
	int update(int node, int y, int x, int val, int a1, int b1, int a2, int b2) {
		if (a1 > a2 || b1 > b2) return 0;	//연산에 영향을 미치지 않는 값 혹은 구조체를 리턴한다.
		if (y < a1 || x < b1 || y > a2 || x > b2) return 0;	//위랑 마찬가지
		if (a1 == a2 && b1 == b2) 
			return tree[node] += val;
		int ret = 0;
		ret += update(node * 4 - 2, y, x, val, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2);
		ret += update(node * 4 - 1, y, x, val, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2);
		ret += update(node * 4 + 0, y, x, val, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2);
		ret += update(node * 4 + 1, y, x, val, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2);
		return tree[node] = ret;
	}
	int update(int y, int x, int val) { return update(1, y, x, val, 0, 0, n - 1, n - 1); }
	int query(int node, int y1, int x1, int y2, int x2, int a1, int b1, int a2, int b2) {
		if (a1 > a2 || b1 > b2) 
			return 0;
		if (y2 < a1 || y1 > a2 || x2 < b1 || x1 > b2)
			return 0;
		if (y1 <= a1 && x1 <= b1 && y2 >= a2 && x2 >= b2) {
		//	cout << "(node: " << node << " " << " value: " << tree[node] << ") ";
			return tree[node];
		}
		int ret = 0;
		ret += query(node * 4 - 2, y1, x1, y2, x2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2);
		ret += query(node * 4 - 1, y1, x1, y2, x2, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2);
		ret += query(node * 4 + 0, y1, x1, y2, x2, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2);
		ret += query(node * 4 + 1, y1, x1, y2, x2, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2);
		return ret;	//이거 없는데도 디버그에선 정상동작하네 릴리즈 모드에선 오류나고... 아악!!!!.. visual studio...
	}
	int query(int y1, int x1, int y2, int x2) { 
		return query(1, y1, x1, y2, x2, 0, 0, n - 1, n - 1); 
	} 
	void print(int ss) {
		rep(i, ss) {
			cout << tree[i] << " ";
		}
		cout << endl;
	}
};
vpii getInter(int y, int x) {
	vpii ret(2);
	ret[0].first = ret[0].second = -INF;
	ret[1].first = ret[1].second = INF;
	rep(i, fclt.size()) {
		int fy = fclt[i].first, fx = fclt[i].second;
		int dist = max(abs(fy - y), abs(fx - x));
		ret[0].first = max(ret[0].first, fy - dist);
		ret[0].second = max(ret[0].second, fx - dist);
		ret[1].first = min(ret[1].first, fy + dist);
		ret[1].second = min(ret[1].second, fx + dist);
		if (ret[0].first >= ret[1].first || ret[0].second >= ret[1].second)
			return ret;
	}
	return ret;
}

bool add(int y, int x, segT2D& sT2D) {
	bool ok = true;
	vpii range = getInter(y, x);
	range[0].first++; range[0].second++;
	range[1].first--; range[1].second--;
	//sT2D.print(80);
	if (range[0].first > range[1].first || range[0].second > range[1].second)
		ok = true;	//공간이 없다면 참
	else {

		int cnt = sT2D.query(range[0].first, range[0].second, range[1].first, range[1].second);
		//cout << cnt << endl;
		if (cnt > 0) {
			ok = false;
		}
	}
	//cout << "y: " << y << " , x: " << x << "    ok: " << ok << endl;
	sT2D.update(y, x, 1);
	return ok;
}
int main() {
	//freopen("input.txt", "r", stdin);
	
	//tree.resize(n * n * 2); 이 경우 아래 코드에서 죽는다....
	/*
	fclt.resize(100);
	rep(i, 100) {
		fclt[i].first = rand() % 1025;
		fclt[i].second = rand() % 1025;
	}
	sT2D.init();
	int ttt = 1000000;
	while (ttt >= 0) {
		rep(i, 1025) {
			rep(j, 1025) {
				add(i, j);
				sT2D.update(i, j, 1);
				ttt--;
				if (ttt <= 0) break;
			}
			if (ttt <= 0) break;
		}
	}
	cout << "oooo" << endl;
	*/
	int cs; cin >> cs;
	rep(cc, cs) {

		int m, n; cin >> m >> n;	//m:편의시설(100개),  n:동아리방(10만개)
		fclt.resize(m);
		rep(i, m) //cin >> fclt[i].second >> fclt[i].first;
			scanf("%d%d", &fclt[i].second, &fclt[i].first);
		vpii arr(n);
		int ny = 0, nx = 0;
		rep(i, n) {
			scanf("%d%d", &arr[i].second, &arr[i].first);
			ny = max(ny, arr[i].first);
			nx = max(nx, arr[i].first);
		}
		if (cc >= 20) {	//cc >= 10 은 통과했은, 11 ~ 19 사이에서 타임오버겠군..
			cout << "G B B\n";
			continue;
		}
		segT2D sT2D(ny, nx);
		string sol(n * 2, ' ');
		rep(i, n) {
			//int y, x;
			//scanf("%d%d", &x, &y);
			//bool ok = add(y, x);
			bool ok = add(arr[i].first, arr[i].second, sT2D);
			char ch1, ch2;
			if (ok) {
				//printf("G%c", " \n"[(i == n - 1) ? 1 : 0]);
				ch1 = 'G';
			}
			else {
				//printf("B%c", " \n"[(i == n - 1) ? 1 : 0]);
				ch1 = 'B';
			}
			if (i == n - 1)
				ch2 = '\n';
			else
				ch2 = ' ';
			//putchar(ch1);
			//putchar(ch2);
			sol[i * 2] = ch1;
			sol[i * 2 + 1] = ch2;
		//	putchar('\n');
		}
			cout << sol;
	}
	return 0;
}

//1683ms ㅠㅠ 통과했어유.. int 가 리턴되지 않도록 하고 존재여부(bool: true, false) 로 변경하니
//시간내에 통과함.
//sum으로 리턴한 이전코드는 10초이내인데도 통과 못함...ㅠㅠ 타임오버로 막힘
//update구문보다 query구문에서 많은 시간이 소모되는 것이다!!!!
#include <iostream>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

#define mp make_pair
#define rep(i,a) for (int i = 0; i < (int)a; ++i)
#define rep2(i,a,b) for (int i = a; i < (int)b; ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef const vi cvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const int INF = 987654321;
const int MOD = 1000000007;
using namespace std;
const int MX = 1025;
//const int MX = 7;
vpii fclt;	//facilities

struct segT2D {
	int n;
	//vi tree;
	vb tree;
	//segT2D() {
	//	n = MX;
	//	tree.resize(n * n * 4);
	//}
	segT2D(int ny, int nx) {
		n = max(ny + 1, nx + 1);
		tree.resize(n * n * 4);
	}
	void init() {
		tree.clear();
		tree.resize(n * n * 4);
	}
	int update(int node, int y, int x, int a1, int b1, int a2, int b2) {
		if (a1 > a2 || b1 > b2) return 0;	//연산에 영향을 미치지 않는 값 혹은 구조체를 리턴한다.
		if (y < a1 || x < b1 || y > a2 || x > b2) return 0;	//위랑 마찬가지
		if (a1 == a2 && b1 == b2)
			return tree[node] = true;
		bool ret = false;
		ret = update(node * 4 - 2, y, x, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2);
		ret += update(node * 4 - 1, y, x, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2);
		ret += update(node * 4 + 0, y, x, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2);
		ret += update(node * 4 + 1, y, x, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2);
		return tree[node] = ret;
	}
	bool update(int y, int x) { return update(1, y, x, 0, 0, n - 1, n - 1); }
	bool query(int node, int y1, int x1, int y2, int x2, int a1, int b1, int a2, int b2) {
		if (a1 > a2 || b1 > b2) 
			return false;
		if (y2 < a1 || y1 > a2 || x2 < b1 || x1 > b2)
			return false;
		if (y1 <= a1 && x1 <= b1 && y2 >= a2 && x2 >= b2) {
		//	cout << "(node: " << node << " " << " value: " << tree[node] << ") ";
			return tree[node];
		}
		int ret = false;
		//query구문 하나라도 참이면 나머진 안타겠군.!!!!
		ret = query(node * 4 - 2, y1, x1, y2, x2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2)
			|| query(node * 4 - 1, y1, x1, y2, x2, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2)
			|| query(node * 4 + 0, y1, x1, y2, x2, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2)
			|| query(node * 4 + 1, y1, x1, y2, x2, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2);
		return ret;	//return ret 이거 없는데도 디버그에선 정상동작하네 릴리즈 모드에선 오류나고... 아악!!!!.. visual studio...
	}
	bool query(int y1, int x1, int y2, int x2) { 
		return query(1, y1, x1, y2, x2, 0, 0, n - 1, n - 1); 
	} 
	void print(int ss) {
		rep(i, ss) {
			cout << tree[i] << " ";
		}
		cout << endl;
	}
};
vpii getInter(int y, int x) {
	vpii ret(2);
	ret[0].first = ret[0].second = -INF;
	ret[1].first = ret[1].second = INF;
	rep(i, fclt.size()) {
		int fy = fclt[i].first, fx = fclt[i].second;
		int dist = max(abs(fy - y), abs(fx - x));
		ret[0].first = max(ret[0].first, fy - dist);
		ret[0].second = max(ret[0].second, fx - dist);
		ret[1].first = min(ret[1].first, fy + dist);
		ret[1].second = min(ret[1].second, fx + dist);
		if (ret[0].first >= ret[1].first || ret[0].second >= ret[1].second)
			return ret;
	}
	return ret;
}

bool add(int y, int x, segT2D& sT2D) {
	bool ok = true;
	vpii range = getInter(y, x);
	range[0].first++; range[0].second++;
	range[1].first--; range[1].second--;
	//sT2D.print(80);
	if (range[0].first > range[1].first || range[0].second > range[1].second)
		ok = true;	//공간이 없다면 참
	else {

		bool cnt = sT2D.query(range[0].first, range[0].second, range[1].first, range[1].second);
		//cout << cnt << endl;
		if (cnt == true) {
			ok = false;
		}
	}
	//cout << "y: " << y << " , x: " << x << "    ok: " << ok << endl;
	sT2D.update(y, x);
	return ok;
}
int main() {
	//freopen("input.txt", "r", stdin);
	
	//tree.resize(n * n * 2); 이 경우 아래 코드에서 죽는다....
	/*
	fclt.resize(100);
	rep(i, 100) {
		fclt[i].first = rand() % 1025;
		fclt[i].second = rand() % 1025;
	}
	sT2D.init();
	int ttt = 1000000;
	while (ttt >= 0) {
		rep(i, 1025) {
			rep(j, 1025) {
				add(i, j);
				sT2D.update(i, j, 1);
				ttt--;
				if (ttt <= 0) break;
			}
			if (ttt <= 0) break;
		}
	}
	cout << "oooo" << endl;
	*/
	int cs; cin >> cs;
	rep(cc, cs) {

		int m, n; cin >> m >> n;	//m:편의시설(100개),  n:동아리방(10만개)
		fclt.resize(m);
		rep(i, m) 
			scanf("%d%d", &fclt[i].second, &fclt[i].first);
		vpii arr(n);
		int ny = 0, nx = 0;
		rep(i, n) {
			scanf("%d%d", &arr[i].second, &arr[i].first);
			ny = max(ny, arr[i].first);
			nx = max(nx, arr[i].first);
		}

		segT2D sT2D(ny, nx);
		string sol(n * 2, ' ');
		rep(i, n) {
			bool ok = add(arr[i].first, arr[i].second, sT2D);
			char ch1, ch2;
			if (ok) {
				ch1 = 'G';
			}
			else {
				ch1 = 'B';
			}
			if (i == n - 1)
				ch2 = '\n';
			else
				ch2 = ' ';
			sol[i * 2] = ch1;
			sol[i * 2 + 1] = ch2;
		}
		cout << sol;
	}
	return 0;
}

//나의 타임오버 코드에서 query 부분만 변경하였을때 2296ms 로 통과했다.
//update를 변경시 걸리는 단축 시간은 2296ms - 1683ms : 600ms 로 추측할수 있다.
//이 결과는 query에서 merge(sum) 하는데 무진장 시간이 걸리는 예제들이 있다고 유추할 수 있다.
//10000ms에 통과 못했는데 query만 변경하니 2296ms에 통과 했기 때문이다.


//구사과의 2D펜윅코드. 배울점이 많다... !!!!
//sum을 구하는 식인데도, 나의 구간트리보다 훨씬 빠르다.
//725ms
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m;	int p[105], q[105];
struct bit{
	int tree[1025][1025];
	void init(){ memset(tree,0,sizeof(tree)); }
	//인덱스를 +1 하지 않는다. 문제 조건상 x, y 가 0이 오지 않기 때문이다.
	void add(int x, int y){
		while(y <= 1024){
			int px = x;
			while(px <= 1024){
				tree[px][y]++;
				px += px & -px;
			}
			y += y & -y;
		}
	}
	int sum(int x, int y){
		int ret = 0;
		while(y){
			int px = x;
			while(px){
				ret += tree[px][y];
				px -= px & -px;
			}
			y -= y & -y;
		}
		return ret;
	}
}bit;
int main(){
	int t;	cin >> t;
	while(t--){
		bit.init();
		scanf("%d %d",&m,&n);
		for(int i=0; i<m; i++) scanf("%d %d",&p[i],&q[i]);
		for(int i=0; i<n; i++){
			int x, y;	scanf("%d %d",&x,&y);
			int sx = 1, ex = 1024;
			int sy = 1, ey = 1024;
			for(int j=0; j<m; j++){
				int d = max(abs(p[j] - x), abs(q[j] - y));
				sx = max(sx, p[j] - d + 1);	ex = min(ex, p[j] + d - 1);
				sy = max(sy, q[j] - d + 1);	ey = min(ey, q[j] + d - 1);
			}
			if(sx <= ex && sy <= ey)
				if(bit.sum(ex, ey) - bit.sum(sx-1, ey) - bit.sum(ex, sy-1) + 
					bit.sum(sx-1, sy-1) > 0){
					printf("B ");	bit.add(x, y);	continue;
				}
			printf("G ");	bit.add(x, y);
		}
		puts("");	//엔터친 효과
	}
}
puts는 변환문자나 제어문자를 사용하지 않고 바로 출력함
	puts("abcd");
	puts("\n\n%d");
	결과
	abcd
		

	%d	//%d가 바로 출력됨을 볼수 있다!!!!

등산로 통과 354ms걸림
https://algospot.com/judge/problem/read/MORDOR
vi arr;
struct Node {
	int val;
	Node() {}
	Node(int _val) : val(_val) {}
	bool operator < (const Node& other) const {
		return val < other.val;
	}
};
struct RMQ {
	int n;
	vector<Node> segT;
	RMQ() {}
	RMQ(int sz) {
		n = sz;
		segT.resize(n * 4);
		build(1, 0, n - 1);
	}
	Node build(int node, int nodeL, int nodeR) {
		if (nodeL == nodeR)
			return segT[node] = Node(arr[nodeL]);
		int nodeM = (nodeL + nodeR) / 2;
		segT[node] = def(); 
		segT[node] = merge(segT[node], build(2 * node, nodeL, nodeM));
		segT[node] = merge(segT[node], build(2 * node + 1, nodeM + 1, nodeR));
		return segT[node];
	}
	Node query(int node, int left, int right, int nodeL, int nodeR) {
		if (left > nodeR || right < nodeL) return def();
		if (left <= nodeL && nodeR <= right) return segT[node];
		Node ret = def();
		int nodeM = (nodeL + nodeR) / 2;
		ret = merge(ret, query(node * 2, left, right, nodeL, nodeM));
		ret = merge(ret, query(node * 2 + 1, left, right, nodeM + 1, nodeR));
		return ret;
	}
	Node query(int left, int right) {
		return query(1, left, right, 0, n - 1);
	}
	Node update(int node, int idx, int value, int nodeL, int nodeR) {
		if (idx < nodeL || nodeR < idx)
			return segT[node];
		if (idx == nodeL && idx == nodeR)
			return segT[node] = Node(value);
		Node ret = def();
		int nodeM = (nodeL + nodeR) / 2;
		ret = merge(ret, update(node * 2, idx, value, nodeL, nodeM));
		ret = merge(ret, update(node * 2 + 1, idx, value, nodeM + 1, nodeR));
		return segT[node] = ret;
	}
	Node update(int idx, int value) {
		return update(1, idx, value, 0, n - 1);
	}
	virtual Node merge(Node a, Node b) { 
		return max(a, b);	
	}
	virtual Node def() { 
		return Node(-INF);	
	}
};
struct RMQ2 : RMQ {
	RMQ2(int size) : RMQ() {	//RMQ() 아무짓도 안하는 놈을 만들어야 함..
		n = size;				//안그럼 RMQ(int size)에서 사이즈 갱신이 일어날 경우
		segT.resize(n * 4);		//부모함수의 merge랑 def가 호출된다네...ㅅㅂ
		build(1, 0, n - 1);
	}
	Node merge(Node a, Node b) { 
		return min(a, b); 
	}
	Node def() { 
		return Node(INF); 
	}
};
int main() {
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, q;
		cin >> n >> q;
		arr.resize(n);
		rep(i, n) scanf("%d", &arr[i]);
		RMQ rmq1(arr.size());
		RMQ2 rmq2(arr.size());
		rep(i, q) {
			int a, b;
			scanf("%d %d", &a, &b);
			Node rMax = rmq1.query(a, b);
			Node rMin = rmq2.query(a, b);
			int sol = rMax.val - rMin.val;
			printf("%d\n", sol);
		}
	}
	return 0;
}








"lazy propagation" 설명
http://musicdiary.egloos.com/4191792
요약하자면, Lazy Propagation은 연속된 구간을 한꺼번에 갱신할 때에 사용되는 방법으로, 
쿼리문이 M개이고 원소의 개수가 N개이면 M*(logN)^2 의 시간복잡도를 가진다. 
그런데 갱신 순서가 바뀌면 안되는 경우에는 그에 대한 처리를 따로 해주어야 한다.
"bigO(M * (logN)^2)"

http://bowbowbow.tistory.com/4
Lazy Propagation 구현 // 구간 합, 구간 업데이트
update와 sum함수에 lazy 전파 부분만 추가하면 쉽게 Lazy Propagation을 적용하여 
구간 업데이트가 가능한 자료구조인 Segment Tree를 이용할 수 있습니다.
이때 lazy 전파는 합을 구하는 과정 뿐만 아니라 구간 업데이트 시에도 행해져야 합니다.
백준 온라인 저지 10999번 구간 합 구하기2 문제를 Lazy Propagation을 적용한 Segment Tree로 구현해보겠습니다.
구간 10만개 질문 10만번
(질문 10만) * (log(구간 10만))^2 = 100000 * 17^2

접기
"모든 인덱스가 1부터 시작임"
#include <cstdio>
#define MAXN 1000010
#define ll long long
ll arr[MAXN];
typedef struct Tree{ ll value, lazy; }Tree;
Tree tree[3*MAXN];
//최초로 Segment트리의 대표값을 지정하는 함수
ll init(int node, int start, int end){
    if(start == end)
        return tree[node].value = arr[start];
    else
        return tree[node].value = init(node*2, start, (start+end)/2)
								+ init(node*2+1, (start+end)/2+1, end);
}
//i~j 구간에 diff만큼 더해줄 때 SegmentTree를 업데이트 하는 함수
void update_range(int node, int start, int end, int i, int j, ll diff){
    if(tree[node].lazy != 0){
        tree[node].value += (end-start+1)*tree[node].lazy;
        if(start != end){
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy =0;
    }
    if(j < start || i > end) return;
    if(i <= start &&  end <= j){
        tree[node].value += (end-start+1)*diff;
        if(start != end){
            tree[node*2].lazy += diff;
            tree[node*2+1].lazy += diff;
        }
        return;
    }
	// 범위가 일치하지 않으면 tree[node].value 를 다시 계산한다.
    update_range(node*2, start, (start+end)/2, i, j, diff);
    update_range(node*2+1, (start+end)/2+1, end, i, j, diff);
    tree[node].value = tree[node*2].value+tree[node*2+1].value;
}
//i번째 값부터 j번째 값 까지의 합을 구하는 함수
ll sum(int node, int start, int end, int i, int j){
    if(tree[node].lazy != 0){
        tree[node].value += (end-start+1)*tree[node].lazy;
        if(start != end){
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy =0;
    }
    if(i> end || j < start) return 0;
    if(i <= start && end <= j) return tree[node].value;
    return sum(node*2, start, (start+end)/2, i, j)
			+ sum(node*2+1, (start+end)/2+1, end, i, j);
}

int main(){
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<= N; i++)
        scanf("%lld", &arr[i]);
    init(1, 1, N);	// 1 부터 N 까지로 범위 지정(인덱스 시작이 1임)
    for(int i=1; i<= M+K; i++){
        int t1, a, b;
        ll diff;
        scanf("%d", &t1);
        if(t1==1){
            scanf("%d%d%lld", &a, &b, &diff);
            update_range(1, 1, N, a, b, diff);
        }else{
            scanf("%d%d", &a, &b);
            printf("%lld\n", sum(1, 1, N, a, b));
        }
    }
    return 0;
}

N 이 8이라 한다고 가정하고
                     1
           2                  3
	  4        5           6      7
	8	9	10	11		12	13 	14	15
"value가 갱신된 노드는 lazy가 항상 0으로 세팅됨. 그건 아래 설명에선 생략"
		node, start, end, i, j, diff
update_range(1, 1, N, 1, N, 5);	// tree[1].value = 8*5 : 1번 노드의 value에 (N-1+1)*5 가 더해짐  
								// tree[2].lazy = 5,		tree[3].lazy = 5 : 2번 노드의 lazy = 5, 3번 노드의 lazy = 5
update_range(1, 1, N, 1, N, 7); // tree[1].value = 8*5 + 8*7 : 1번 노드의 value에 (N-1+1)*7 가 더해짐
								// tree[2].lazy = 5+7,		tree[3].lazy = 5+7
update_range(1, 1, N, 3, 8, 3);		
	u_r(2, 1, 4, 3, 8, 3);			// tree[2].val = 4*12,	tree[4].lazy = 12,	tree[5].lazy = 12
		u_r(4, 1, 2, 3, 8, 3);			// tree[4].val = 2*12,	tree[8].lazy = 12,	tree[9].lazy = 12
		|
		u_r(5, 3, 4, 3, 8, 3);			// tree[5].val = 2*12,	tree[10].lazy = 12, tree[11].lazy = 12,
										// tree[5].val = 2*12 + 2*3,	tree[10].lazy = 12 + 3,	tree[10].lazy = 12 + 3
		|
	|								// tree[2].val = tree[4].val + tree[5].val = 24 + 30 = 54
	u_r(3, 5, 8, 3, 8, 3);			// tree[3].val = 4*12,	tree[6].lazy = 12,	tree[7].lazy = 12
									// tree[3].val = 4*12 + 4*3,	tree[6].lazy = 12 + 3,	tree[7].lazy = 12 + 3
	|
|								// tree[1].val = tree[2].val + tree[3].val = 54 + 60 = 114


http://poj.org/problem?id=3468
1735ms 통과됨
const int MX = 100010;
ll arr[MX];
struct Tree { ll value, lazy; };
Tree tree[3 * MX];
ll init(int node, int start, int end) {
	if (start == end) 
		return tree[node].value = arr[start];
	else 
		return tree[node].value = init(node * 2, start, (start + end) / 2)
		+ init(node * 2 + 1, (start + end) / 2 + 1, end);
}
void update_range(int node, int start, int end, int i, int j, ll diff) {
	if (tree[node].lazy != 0) {
		tree[node].value += (end - start + 1) * tree[node].lazy;
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (j < start || i > end) return;
	if (i <= start && end <= j) {
		tree[node].value += (end - start + 1) * diff;
		if (start != end) {
			tree[node * 2].lazy += diff;
			tree[node * 2 + 1].lazy += diff;
		}
		return;
	}
	update_range(node * 2, start, (start + end) / 2, i, j, diff);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, i, j, diff);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}
ll sum(int node, int start, int end, int i, int j) {
	if (tree[node].lazy != 0) {
		tree[node].value += (end - start + 1) * tree[node].lazy;
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (i > end || j < start) return 0;
	if (i <= start && end <= j) return tree[node].value;
	return sum(node * 2, start, (start + end) / 2, i, j)
		+ sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
	//freopen("input.txt", "r", stdin);
	int n, q;
	scanf("%d%d", &n, &q);
	rep2(i, 1, n + 1) scanf("%lld", &arr[i]);
	init(1, 1, n);
	rep(i, q) {
		int a, b, c;
		char ch; 
		//scanf("%c"는 처음 써본듯 하네.. scanf("%d", scanf("%s 는 아래 현상 없었는데...
		//scanf("%c", &ch);	//이거 쓰니까 엔터('\n') 가 ch에 들어가 버리냐..
		scanf(" %c", &ch);	//이거 하니까 정상 출력됨 !!!!! //공백 무시하고 읽어옴.
		//cin >> ch;
		if (ch == 'Q') {
			scanf("%d%d", &a, &b);
			long long sol = sum(1, 1, n, a, b);
			printf("%lld\n", sol);
		}
		else if (ch == 'C') {
			scanf("%d%d%d", &a, &b, &c);
			update_range(1, 1, n, a, b, c);
		}
	}
	return 0;
}


//최대값을 기록하는 lazy propagation
https://gist.github.com/shobhit6993/7088061
int arr[N];
int tree[MAX];
int lazy[MAX];
void build_tree(int node, int a, int b) {
	if (a > b) return;	//필요없는 예외. (1차원 구간트리에선 있을수 없어요 2차원에선 발생합니다만..)
	if (a == b) { tree[node] = arr[a]; return; }
	build_tree(node*2, a, (a + b) / 2);
	build_tree(node*2+1, (a + b) / 2 + 1, b);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}
/* Increment elements within range [i, j] with value */
void update_tree(int node, int a, int b, int i, int j, int value) {
	if (lazy[node] != 0) {	// This node needs to be updated
		tree[node] += lazy[node]; // Update it !!!!
		if (a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[ndoe*2+1] += lazy[node]; // Mark child as lazy
		}
		lazy[node] = 0;	// Reset it
	}
	if (a > b || a > j || b < i) return; // Current segment is not within range [i, j]
	if (a >= i && b <= j) { // Segment is fully within range
		tree[node] += value;
		if (a != b) {	// Not leaf node
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	update_tree(node * 2, a, (a + b) / 2, i, j, value); // Updating left child
	update_tree(node * 2 + 1, (a + b) / 2 + 1, b, i, j, value); // Updating right child
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Updating root with max value
}
/* Query tree to get max element value within range[i, j] */
int query_tree(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return -inf;	// Out of range
	if (lazy[node] != 0) { // This node needs to b e updated
		tree[node] += lazy[node]; // Update it !!!!
		if (a != b) {
			lazy[node * 2] += lazy[node]; // Mark child as lazy
			lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
		}
		lazy[node] = 0; // Reset it
	}
	if (a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
	int q1 = query_tree(node*2, a, (a + b) / 2, i, j); // Query left child
	int q2 = query_tree(node*2+1, (a + b / 2 + 1, b, i, j); // Query right child
	int res = max(q1, q2);
	return res;
}
int main() {
	rep(i,N) arr[i] = 1;
	build_tree(1,0,N-1);
	memset(lazy, 0, sizeof(lazy));
	update_tree(1, 0, N - 1, 0, 6, 5); // Increment range[0, 6] by 5
	update_tree(1, 0, N - 1, 7, 10, 12); // Increment range[7 10] by 12
	update_tree(1, 0, N - 1, 10, N - 1, 100); // Increment range[10, N - 1] by 100
	cout << query_tree(1, 0, N - 1, 0, N - 1) << endl; // Get max element in range [0, N - 1]
}



자, 그런데 한가지 주의해야할 점이 있다. 갱신할때 "갱신 순서"가 바뀌면 안되는 경우가 있다.
무슨 말이냐면, 위 문제처럼 값을 더하는 경우는 어떤 노드에 3을 더하고 5를 더하는 경우랑 5를 더하고 3을 더하는 경우랑 똑같은 결과가 나온다. 하지만 그런 교환법칙이 성립하지 않는 문제의 경우 Lazy Propagation을 사용할 때에 각별한 주의를 요한다. 
다음 문제를 보자.

-------------------------------------------------------------------------------------------------------------

PKU 2777 - Count Color
http://poj.org/problem?id=2777

칠판에 L개의 칸이 있고, T가지의 색깔이 있다. 이제 다음 O개의 쿼리문이 입력으로 들어온다.
"C a b c" 형태의 쿼리는 a번째 칸부터 b번째 칸까지 c번째 색깔로 칠하라는 의미이다. 이미 다른 색깔이 칠해져 있다고 해도 그 위에 덮어서 칠한다. 색이 섞여서 변해버리는 경우는 없다.
"P a b" 형태의 쿼리는 a번째 칸부터 b번째 칸까지의 연속된 칸들에 칠해진 색깔의 종류가 몇개인가를 출력하라는 의미이다.

L, O는 최대 십만이며, T는 최대 30이다. 또한, 입력된 쿼리문에서 a가 b보다 더 클 수도 있다.

Sample Input
2 2 4
C 1 1 2
P 1 2
C 2 2 2
P 1 2

Sample Output

2
1

짜봤는데 내가 설정한 인풋들이 통과함에도 불구하고 poj에선 통과가 안된다.. ㅠㅠ 
	// 분석좀 더하고 아래건 지워라: 통과 못한 소스다. : 
		// sum 리턴을 bit OR 로 해야 한다. 그러면 통과
	https://www.acmicpc.net/source/11462798 : 화려한 마을 동일한 문제임 통과함
const int MX = 100010;
struct Tree { int value, lazy; }; Tree tree[3 * MX];	//lazy 는 하나의 color
														//문제상 init은 필요없다.
void update_range(int node, int start, int end, int i, int j, int color) {
	if (tree[node].lazy != 0) {	//거부감이 들지만 밑에서 수정시켜주네
		tree[node].value = tree[node].lazy;
		if (start != end) {
			tree[node * 2].lazy = tree[node].lazy;
			tree[node * 2 + 1].lazy = tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (j < start || i > end) return;
	if (i <= start && end <= j) {	// 한가지 칼라만 가지는 경우
		tree[node].value = color;
		if (start != end) {
			tree[node * 2].lazy = color;	// 상위 노드에 세팅 된 놈으로 덮어씌워짐
			tree[node * 2 + 1].lazy = color;
		}
		return;
	}
	update_range(node * 2, start, (start + end) / 2, i, j, color);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, i, j, color);
	tree[node].value = tree[node * 2].value | tree[node * 2 + 1].value;
}
int query(int node, int start, int end, int i, int j) {
	if (tree[node].lazy != 0) {	//거부감이 들지만 밑에서 수정시켜주네
		tree[node].value = tree[node].lazy;
		if (start != end) {
			tree[node * 2].lazy = tree[node].lazy;
			tree[node * 2 + 1].lazy = tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (j < start || i > end) return 0;
	if (i <= start && end <= j) return tree[node].value;
	//return sum(node * 2, start, (start + end) / 2, i, j)
	//	+ sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	return 	  query(node*2, start, (start + end) / 2, i, j)
			| query(node*2+1, (start + end) / 2 + 1, end, i, j);	// or 로 하면 통과염
}
int main() {
	//freopen("input.txt", "r", stdin);
	int n, t, o;	// 길이, 칼라수, 질의 수
	scanf("%d%d%d", &n, &t, &o);
	update_range(1, 1, n, 1, n, 1);	//1번째 비트 세팅(흰색)
	rep(i, o) {
		int a, b, c;
		char ch; 
		scanf(" %c", &ch);
		if (ch == 'P') {
			scanf("%d%d", &a, &b);
			if (a > b) swap(a, b);
			int colors = query(1, 1, n, a, b);
			int sol = 0;
			rep(i, 31) {
				if (colors & (1 << i))
					sol++;
			}
			//int sol = __builtin_popcount((unsigned int)colors);
			//int sol = __popcnt(colors);
			printf("%d\n", sol);
		}
		else if (ch == 'C') {
			scanf("%d%d%d", &a, &b, &c);
			if (a > b) swap(a, b);
			int bitC = (1 << (c - 1));
			update_range(1, 1, n, a, b, bitC);
		}
	}
	return 0;
}


// 기타: -------------------------- Mo's algorithm -------------------------------//
http://kesakiyo.tistory.com/25?category=590414
MO's algorithm 은 쿼리를 정렬한 뒤 정렬된 순서대로 처리를 한다. 이론은 이게 끝
연습문제: https://www.acmicpc.net/problem/13547
길이가 N 인 수열에서 쿼리(범위)가 주어짐ㄴ 그 범위에 존재하는 서로 다른 수의 개수를 출력한다.
수열크기 N : 100000
각 요소는 1 <= Ai <= 1000000
쿼리의 갯수 Q: 100000
// 노가다로 짜면 O(QN) : 100억 으악

MO's 알고리즘을 이용하면 O((N + Q)root(N)) 이 걸린다.
// 마치 로드 밸런싱 문제와 같구나.
#include <stdio.h>	#include <math.h>	#include <vector>	#include <algorithm>
using namespace std;
struct Query {
	int lo, hi, idx;
	Query(int lo, int hi, int idx) : lo(lo), hi(hi), idx(idx) {}
};
int n, m, A[100010], cnt[1000010], ans[100010], distinctNumbers;
vector<Query> query;
void add(int num) {
	// num 이 새롭게 cnt배열에 들어올 때만 카운팅 해준다.
	if (++cnt[num] == 1)
		++distinctNumbers;
}
void erase(int num) {
	// num 이 cnt배열에서 완전히 없어질때 카운팅 해준다.
	if (--cnt[num] == 0) 
		--distinctNumbers;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int lo, hi;
		scanf("%d%d", &lo, &hi);
		query.emplace_back(lo - 1, hi - 1, i);
	}
	int sz = sqrt(n);
	// hi 묶음기준으로 정렬함
	sort(query.begin(), query.end(), [&](const Query& a, const Query& b) {
		// 쿼리가 끝나는 부분이 어떤 hi 묶음에 속하는지 확인한다.
		// hi 묶음의 인덱스가 더 작은곳에 속하는 쿼리를 먼저 처리한다.
		// 만약 묶음의 인덱스가 같다면 쿼리의 시작지점이 작은것을 먼저 처리한다.
		int aIdx = a.hi / sz;
		int bIdx = b.hi / sz;
		return aIdx == bIdx ? a.lo < b.lo : aIdx < bIdx;
	});
	int lo = 0, hi = 0;
	// 아래 add(A[0]); 이게 생각보다 매우 중요하다. 이런식의 처리가 내부 for 문을 매우매우 간략하게 한다. !!!!!!!
	add(A[0]);	// 시작값은 cnt 배열에 넣고 시작한다. 
	for (auto cur : query) {
		int nlo = cur.lo,	nhi = cur.hi;		// 현재 위치는 [lo, hi]이고 다음 위치는 [nlo, nhi]
		
		// lo를 nlo 로 움직이는 부분
		// 1. lo 가 nlo보다 왼쪽에 있는 경우 : 수를 제거할 필요가 있다.
		for (int i = lo; i < nlo; ++i)
			erase(A[i]);
		// 2. lo 가 nlo 보다 오른쪽에 있는 경우 : 수를 더할 필요가 있다
		for (int i = lo - 1; i >= nlo; --i)
			add(A[i]);
		
		// hi를 nhi 로 움직이는 부분
		// 1. hi 가 nhi 보다 왼쪽에 있는 경우 : 수를 더할 필요가 있다.
		for (int i = hi + 1; i <= nhi; ++i)
			add(A[i]);
		// 2. hi 가 nhi 보다 오른쪽에 있는 경우 : 수를 제거할 필요가 있다.
		for (int i = hi; i > nhi; --i) 
			erase(A[i]);
		lo = nlo;	// 이터레이터가 현 쿼리의 범위를 나타내도록 한다.
		hi = nhi;
		
		// 답을 저장할 배열에 실제 쿼리의 순서에 맞게 답을 기록해 준다.
		ans[cur.idx] = distinctNumbers;	// !!!!!!!!! 이렇게 깔끔하다니...
	}
	for (int i = 0; i < m; ++i) 
		printf("%d\n", ans[i]);
}
// 정렬코드 한개를 넣은 것만으로 성능을 N*(rootN) 으로 낮출수 있다 !!!!!!!!! 적용도 편하다. 꼭 기억하자
배열이 10만개로 이뤄졌고 질문이 10만개면
hi버킷은 최대 약 316개 존재함
최악의 시간을 상정한 밸런싱 배치는 다음과 같게 된다.
0 1 .........................................5만...........................................10만
5												159번버킷
         5										159번버킷        
                                            3   159번버킷
4                                                    160번버킷
		3											 160번버킷
											7		 160번버킷
											....
											....
											....
9																						316번버킷
            1                                                                           316번버킷
			                               9											316번버킷
										   
한버킷당 최대 lo 이동량 5만
한버킷내에서 hi 최대 이동량 316 번 // 316 * 316 = 100000

한버킷당 처리량 5만 // 원위치 이동으로 10만으로 해뿌자.

10만 * 버킷수(316) = 3160만번 수행으로 풀린다.
		
	
	
// k번째 수 
https://www.acmicpc.net/problem/7469
// 배열이 주어지고 (최대 10만개)
// 질문갯수가 주어진다 (최대 5000개)
// left, right 로 구간배열을 설정후 그안에서 kth 번째 크기의 배열을 구하라

접근법
각 구간에 대해 배열을 정렬시켜 가지고 있는다.
	// 바이너리 서치로 조사 (boundPoint)
	구간별로 접근하면서 완전 포함인 경우 boundPoint 이하의 갯수를 구한다.
	구간이 쪼개질 필요가 있으면 분리한다.
	범위 밖은 카운트가 0임
	
	// 갯수를 세어서 kth 이하이면 hi
	// 미만이면 lo 로 재설정후 바이너리 서치한다.
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct SegmentTree {
	int n;
	vector<vector<int>> rangeArr;
	SegmentTree(const vector<int>& arr) {
		n = arr.size();
		rangeArr.resize(n * 4);
		init(arr, 1, 0, n - 1);
		sortRangeArr();
	}
	void init(const vector<int>& arr, int node, int nodeL, int nodeR) {
		for (int i = nodeL; i <= nodeR; ++i)
			rangeArr[node].push_back(arr[i]);
		if (nodeL == nodeR) 
			return;
		int mid = (nodeL + nodeR) / 2;
		init(arr, node * 2, nodeL, mid);
		init(arr, node * 2 + 1, mid + 1, nodeR);
		return;
	}
	void sortRangeArr() {
		for (int i = 0; i < rangeArr.size(); ++i)
			sort(rangeArr[i].begin(), rangeArr[i].end());
	}
	// left와 right 범위가 주어지고 boundPoint 이하의 갯수를 카운팅한다.
	int query(int left, int right, int boundPoint, int node, int nodeL, int nodeR) {
		if (right < nodeL || nodeR < left) return 0;
		if (left <= nodeL && nodeR <= right)
			return upper_bound(rangeArr[node].begin(), rangeArr[node].end(), boundPoint)
					- rangeArr[node].begin();	// !!!!!!!! boundPoint 이하의 갯수를 구한다.
		int mid = (nodeL + nodeR) / 2;
		return	query(left, right, boundPoint, node * 2, nodeL, mid) +
			query(left, right, boundPoint, node * 2 + 1, mid + 1, nodeR);
	}
};
// vector<int> arr; // 빈벡터
// upper_bound(arr.begin(), arr.end(), 10) - arr.begin();	// 0을 가르킨다.
// arr.push_back(3);
// upper_bound(arr.begin(), arr.end(), 10) - arr.begin();	// 1을 가르킨다.
// arr 최대값보다 크다면 한칸 더 뒤의 인덱스를 가르키며
// 없는 경우 0번 인덱스를 가르킨다.
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	SegmentTree segTree(arr);
	while (q--) {
		int left, right, kth;
		cin >> left >> right >> kth;
		left--; right--;
		int lo = -1e9, hi = 1e9;
		// 반복문 불변식 hi결과: 반드시 x개 이상이다. lo결과: 반드시 x개 미만이다.
		while (lo + 1 < hi) {
			int m = (lo + hi) / 2;
			// 구간배열에서 m 이하의 갯수가 x 미만인 경우를 체크하여 답을 구한다.
			if (segTree.query(left, right, m, 1, 0, n - 1) < kth)
				lo = m;
			else
				hi = m;
		}
		cout << hi << '\n';
	}
}
		
		
		
		
https://www.acmicpc.net/problem/3653
영화수집
map 으로 구현하고 싶은디...
map 의 키값이 몇번째 키인지 알수 있는가? 없는거 같다. 그냥  treap으로 구현해야 될거 같다 ㅠㅠ.

펜윅으로 그냥 하자 귀찮다.

// 접근법
	pos[영화번호] : update 되어 갱신된다. 처음 시작은 n + m
	FenwickT
	
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		FenwickTree FT(n + 1 + m); // 종만소스: FT(n+ 인 경우 0 ~ n - 1 까지의 범위를 표현한다. 참고
		vi pos(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			pos[i] = i + m;
			FT.add(pos[i], 1);
		}
		int top = m;
		for (int i = 0; i < m; ++i) {
			int movie;
			cin >> movie;
			int idx = pos[movie];
			int cost = FT.sum(idx - 1);
			cout << cost << " ";

			// 현 위치를 최상단으로 옮기기
			FT.add(idx, -1);
			FT.add(top, 1);
			pos[movie] = top;
			top--;
		}
		cout << '\n';
	}

	return 0;
}
		
		
//------------------------------25장 상호 배타적 집합 -------------------//
//p768 트리를 이용한 (단순한) 상호 배타적 집합 자료 구조의 구현
//트리를 이용해 상호 배타적 집합을 구현한다.
struct NaiveDisjointSet {
	vector<int> parent;
	NaiveDisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	//u가 속한 트리의 루트의 번호를 반환한다.
	int find(int u) const {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	//u가 속한 트리와 v가 속한 트리를 합친다.
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		//u와 v가 이미 같은 트리에 속하는 경우를 걸러낸다.
		if (u == v) return;
		parent[u] = v;
	}
};


//최적화 : 랭크에 의한 합치기(union-by-rank)
//두 노드를 합칠때 높이를 비교해서 낮은 쪽을 높은 트리의 서브트리로 포함하되,
//두 트리의 높이가 같은 경우에만 결과 트리의 높이를 1 늘려 주는 것
//또 다른 최적화는 경로압축이며 find 함수 호출시 트리가 변경된다
//p769 최적화된 상호 배타적 집합의 구현
//트리를 이용해 상호 배제적 집합을 구현한다.
struct OptimizedDisjointSet {
	vector<int> parent, rank;
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	//u가 속한 트릐의 루트의 번호를 반환한다.
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);	//경로압축
	}
	//u가 속한 트리와 v가 속한 트리를 합친다.
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		//u와 v가 이미 같은 집합에 속하는 경우를 걸러낸다.
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		//이제 rank[v]가 항상 rank[u] 이상이므로 u를 v의 자식으로 넣는다.
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
}

//에디터 전쟁(EDITORWARS, 난이도 중)
//댓글에 주어진 정보 중 모순이 없는 경우 한 파티에 올 수 있는 사람의 최대수를
//"MAX PARTY SIZE IS x"의 형태로 출력
//댓글들에 주어진 정보중 모순이 있는 경우 최초 모순이 발생하는 댓글을
//"CONTRADICTION AT i" 의 형태로 출력(댓글의 번호는 1번부터 시작함)
4
4 4
ACK 0 1
ACK 1 2
DIS 1 3
ACK 2 0
100 4
ACK 0 1
ACK 1 2
ACK 2 3
ACK 3 4
3 3
ACK 0 1
ACK 1 2
DIS 2 0
8 6
DIS 0 1
ACK 1 2
ACK 1 4
DIS 4 3
DIS 5 6
ACK 5 7
MAX PARTY SIZE IS 3
MAX PARTY SIZE IS 100
CONTRADICTION AT 3
MAX PARTY SIZE IS 5

두 개의 원칙이 존재
//1. 동지의 적은 나의 적
//2. 적의 적은 나의 동지
//P 776 에디터 전쟁 문제를 해결하는 상호 배타적 집합의 구현
//각 집합간의 적대 관계와 크기를 두개의 별도 변수 enemy[], size[]를 이용해 추적
struct BipartiteUnionFind{	//bipartite 는 이분 그래프의 이름에서 따옴
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

	//u와 v가 서로 적이다. 모순이 일어났다면 false, 아니면 true를 반환한다.
	bool dis(int u, int v) {}
	//u와 v가 서로 동지다. 모순이 일어났다면 false, 아니면 true를 반환한다.
	bool ack(int u, int v) {}
};
//p778에디터 전쟁 문제를 해결하는 ask()과 dis()의 구현
struct BipartiteUnionFind {
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
}

//아래 코드에서 각 집합 쌍을 정확히 한 번만 세기 위해, 적대 집합의 번호가 
//현 집합의 번호보다 작은 경우만을 세는 것을 눈여겨 봅시다.
//이 경우 적대 집합이 없는 경우(-1)도 예외 처리하지 않고 구현 할 수 있지요.
//p779 상호 배타적 집합이 주어질 때 에디터 전쟁 문제의 답을 구하는 함수의 구현
//BipartiteUnionFind 인스턴스가 주어질 때,
//한 파티에 올 가능성이 있는 최대 인원을 구한다.
int maxParty(const BipartiteUnionFind& buf) {
	int ret = 0;
	for (int node = 0; node < n; ++node) {
		if (buf.find(node) == node) { //buf.parent[node]로 수정해야함 : buf.find(node)는 컴파일 오류난다고 함
			int enemy = buf.enemy[node];
			//같은 모임 쌍을 두 번 세지 않기 위해, enemy < node인 경우만 센다.
			//집합의 크기가 아니라 집합의 루트 번호임을 명심하라!!!!
			//쌍이 성립안되는 즉 적이 없는: enemy == -1 인 경우도 정확히 한 번 씩 세게 된다.
			if (enemy > node) continue;
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			//두 집합 중 큰 집합을 더한다.
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}
'색깔은 집합의 루트'
mySize	enemySize	node		enemy
x		x			2{1, '2', 4}	, 3{0, '3'}	 	: 2가 node인 경우 continue
2		3			3{0, '3'}		, 2{1, '2', 4}	: 3이 node인 경우에 루틴 탐
x		x			6{'6'}		, 7{5, '7'}		: 6이 node인 경우 continue
2		1			7{5, '7'}		, 6{'6'}	 		: 7이 node인 경우에 루틴 탐
2		0			8{'8', 9}		, -1			: 8이 node인 경우에 루틴 탐
따라서 3+2+2 가 답이된다.{1, 2, 4, 5, 7, 8, 9}


//굳이 안봐도 된다. 10분만에 풀어서 기뻐서 그냥 기록함
입력

첫 줄에는 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스에는 금속 점의 개수 2 ≤ N ≤ 100000과 전선으로 연결된 금속 점의 쌍 수 
1 ≤ M ≤ 100000이 주어진다.
아래 M개의 줄에는 두 개의 정수 x와 y가 주어진다. 
이는 금속 점 x와 금속 점 y가 전선으로 이어져 있다는 의미이다. 1 ≤ x,y ≤ N이고, x와 y는 항상 다르다.

출력
각 테스트 케이스 마다 서로 전류가 통하는 가장 큰 집합의 크기를 구한다.
//dsjointSet의 최대 사이즈를 묻는 문제
//420ms가 걸렸다. 다른 사람의 제일 빠른 코드도 속도가 334ms임요
https://algospot.com/judge/problem/read/BRAVE
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
		if (u == v) return u;	// size[u]를 리턴해야 되지 않냐??
		if (rank[u] > rank[v]) swap(u, v);
		if (rank[u] == rank[v]) rank[v]++;
		prnt[u] = v;
		size[v] += size[u];
		return size[v];
	}
};
int main() {
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, m;
		cin >> n >> m;
		dsjSet sets(n + 1);	//0은 안써요.
		int u, v;
		int sol = 0;
		rep(i, m) {
			scanf("%d %d", &u, &v);
			int cand = sets.merge(u, v);
			sol = max(sol, cand);
		}
		cout << sol << endl;
	}
	return 0;
}


//26장 트라이
//p783 트라이의 노드를 표현하는 객체의 선언
//알파벳 대문자를 저장하는 경우 각 노드는 26개의 자손을 가질 수 있다.
const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }
//트라이의 한 노드를 나타내는 객체
struct TrieNode {
	TrieNode* children[ALPHABETS];
	//이 노드가 종료 노드인가?
	bool terminal;
	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; ++i)
			if (children[i])
				delete children[i];
	}
	//이 노드를 루트로 하는 트라이에 문자열 key 를 추가한다.
	void insert(const char* key) {	//!!!! key는 현 노드가 아닌 다음노드를 의미
									//아래 자식(다음노드)는 손자노드를 처리하라고 key + 1을 했음
		//문자열이 끝나면 teminal만 참으로 바꾸고 종료
		if (*key == 0)
			terminal = true;
		else {
			int next = toNumber(*key);
			//해당 자식 노드가 없다면 생성한다.
			if (children[next] == NULL)
				children[next] = new TrieNode();
			//해당 자식 노드로 재귀 호출
			children[next]->insert(key + 1);//다음 노드는 다다음 노드를 처리
		}
	}
	//이 노드를 루트로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다.
	//없으면 NULL을 반환한다.
	TrieNode* find(const char* key) {
		if (*key == 0) return this;	//찾는 문자열이 포함되어 있다면 종요된 노드의 포인트를 리턴
									//콜러에서 종료노드의 terminal 의 값이 false 인지 아닌지 확인한다.
									//false 인 경우: 트라이에 the가 존재하는 상태에서 찾는 문자열이 th인 경우
									//h트라이의 terminal 의 값이 false
									//false 아닌 경우: 트라이에 the가 존재하는 상태에서 찾는 문자열이 the인 경우
									//e트라이의 terminal 의 값이 true!!!!
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;	//찾는 문자열이 아예 없다면 NULL리턴
		return children[next]->find(key + 1);
	}
};
a 입력시 객체는 총 두개
tn->insert(a0)
  tn->insert(0)

상세기록하면
the 입력					terminal	tn(TrieNode) 객체
tn->insert(the0)			false		최상단부모
  tn->insert(he0)			false		t번 자식
    tn->insert(e0)			false		h번 자식
	  tn->isert(0)			true		e번 자식
there 입력(the입력된 상태에서)
tn->insert(there0)			false		최상단부모
  tn->insert(here0)			false		t번 자식
	tn->insert(ere0)		false		h번 자식
      tn->insert(re0)		true		e번 자식
		tn->insert(e0)		false		r번 자식
		  tn->insert(0)		true		e번 자식
			

//p787 안녕히, 그리고 물고기는 고마웠어요! (SOLONG, 중)
//타블렛의 자동 완성 알고리즘이 사용하는 단어들과 각 단어들의 출현 빈도가 주어질 때,
//주어지는 긴 문자열을 입력하기 위해 필요한 최소 타이핑 수를 계산하는 프로그램을 작성해라
//각 테스트 케이스 마다 한 줄에 모든 단어들을 입력하기 위해 필요한 최소 타자수를 출력
사전에 들어갈 단어의 갯수 10000
각 단어의 길이 최대 10
	트라이를 만드는데 걸리는 시간 10000 * 10 * 26(알파벳 갯수)
검색 단어 갯수 10000
	한 케이스를 처리하는데 걸리는 시간 10000 * 10 * 2 
		단어 찾는데(find) : 10000 * 10
		타이핑하는데(type):	10000 * 10
2
7 8
ALL 4
AND 3
FISH 8
FOR 6
SO 4
THANKS 9
THE 9
SO LONG AND THANKS FOR ALL THE FISH // output 28
....
//p791 안녕히, 그리고 물고기는 고마웠어요 문제를 해결하는 트라이 노드의 구현
// 알파벳 소문자를 저장하는 경우 각 노드는 26개의 자손을 가질 수 있다
const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }
// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
	TrieNode* children[ALPHABETS];
	// 이 노드에서 종료하는 문자열의 번호
	int terminal;
	// 이 노드를 루트로 하는 트라이에 가장 먼저 추가된 단어의 번호
	int first;
	TrieNode() {
		memset(children, 0, sizeof(children));
		terminal = first = -1;
	}
	~TrieNode() {
		for(int i = 0; i < ALPHABETS; i++)
			if(children[i])
				delete children[i];
	}
	// 이 노드를 루트로 하는 트라이에 번호 id 인 문자열 key 를 추가한다
	// 현 노드는 key의 맨 앞 글자보다 한칸 앞의 글자노드라는 점을 유의하자!!!!
	// key : "there0" 이면 현 노드는 루트이고
	// key : "here0" 이면 현 노드는 t노드임
	void insert(const char* key, int id) {
		// first 를 우선 업데이트
		if(first == -1) first = id;
		// 문자열이 끝났다면 terminal 만 바꾸고 종료
		if(*key == 0)
			terminal = id;
		else {
			int next = toNumber(*key);
			// 해당 자식 노드가 없다면 생성한다
			if(children[next] == NULL)
				children[next] = new TrieNode();
			// 해당 자식 노드로 재귀호출
			children[next]->insert(key + 1, id);
		}
	}
	// 이 노드까지 타이핑해 왔을 때, 번호 id 인 key 를 타이핑하기 위해
	// 최소 몇 번의 키를 더 눌러야 하나?
	int type(const char* key, int id) {
		// 문자열 종료시
		if(*key == 0) return 0;
		// 이 노드에서 추천되는 문자열이 이 문자열이면 탭 누르고 종료
		if(first == id) return 1;
		// 아니면 다음 문자를 타이핑한다
		int next = toNumber(*key);
		return 1 + children[next]->type(key + 1, id);
	}
	// 이 노드를 루트로 하는 트라이에 문자열 key 와 대응되는 노드를 찾는다.
	// 없으면 NULL 을 반환한다.
	TrieNode* find(const char* key) {
		if(*key == 0) return this;
		int next = toNumber(*key);
		if(children[next] == NULL) return NULL;
		return children[next]->find(key+1);
	}
};

insert	id					first	terminal	tn객체
the		5
tn->insert(the0)			5		-1			최상단부모
  tn->insert(he0)			5		-1			t자식
    tn->insert(e0)			5		-1			h자식
	  tn->insert(0)			5		5			e자식

there	6	(the가 입력된 상태에서)
tn->insert(there0)			5		-1			최상단부모
  tn->insert(here0)			5		-1			t자식
    tn->insert(ere0)		5		-1			h자식
	  tn->insert(re0)		5		5			e자식
	    tn->insert(e0)		6		-1			r자식
		  tn->insert(0)		6		6			e자식

모든 insert가 끝나면
tn->first = -1	최상단 부모가 가르키는 놈의 id를 -1로 해줘야 함(입력도 안했는데 가르키면 안되니까)
// 사전을 나타내는 트라이가 주어질 때, 단어 word 를 타이핑하는 데
// 몇 번이나 키를 눌러야 하는지 계산한다
int countKeys(TrieNode* trie, const char* word) {
	// 이 문자열이 사전에 있는지 확인하고, 있다면 번호를 구한다
	TrieNode* node = trie->find(word);
	// 사전에 없으면 직접 타이핑할 수밖에 없다
	//node == NULL : 해당 문자가 사전에 전혀 없다.
	//node->terminal == -1 : 해당 문자가 사전에 있으나 완전 동일하지 않다
	//ex) 사전에는 there가 있는데 찾으려는 글자가 ther이면 r노드가 리턴된다. 그놈의 terminal은 -1이다.

	if(node == NULL || node->terminal == -1) return strlen(word);
	// 탐색하면서 타이핑할 방법을 찾는다
	return trie->type(word, node->terminal);
}

// 입력에 주어지는 단어들을 정렬해서 트라이로 변환한다
TrieNode* readInput(int words) {
	// 단어들을 출현 빈도의 내림차순, 단어의 오름차순으로 정렬한다
	vector<pair<int,string> > input;
	for(int i = 0; i < words; i++) {
		char buf[11];
		int freq;
		scanf("%s %d", buf, &freq);
		input.push_back(make_pair(-freq, buf));
	}
	sort(input.begin(), input.end());
	// 이 때 앞에 있는 단어일 수록 우선 순위가 높다.
	// 배열의 인덱스를 각 단어의 번호로 쓰자.
	TrieNode* trie = new TrieNode();
	for(int i = 0; i < input.size(); i++)
		trie->insert(input[i].second.c_str(), i);
	// 아무 문자도 입력하지 않은 상황에서는 자동 완성되지 않아야 한다
	trie->first = -1;
	return trie;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for(int cc = 0; cc < cases; ++cc) {
    	int n, m;
    	scanf("%d %d", &n, &m);
    	TrieNode* trie = readInput(n);
    	int ret = 0;
    	for(int i = 0; i < m; i++) {
    		char buf[11];
    		scanf("%s", buf);
    		int add = countKeys(trie, buf);
    		ret += add;
		}
    	delete trie;
    	printf("%d\n", ret + m-1);
    }
}

//p797아호 코라식에는 트라이에 추가적으로 정보가 필요
struct TrieNode {
	//현 위치에서 끝나는 문자열의 번호
	int terminal;
	//실패연결: 이 노드에서 i번의 매칭이 실패했을때  실패연결노드로 가서 i번부터 계속 수행한다.
	//이 노드에 대응되는 문자열의 진 접미사이면서 트라이에 포함된 최대 문자열
	TrieNode* fail; //실패연결은 한놈만 있음
	//출력 문자열 목록: 이 노드가 방문되었을 때 등장하는 바늘 문자열들의 번호
	//바늘이 there, here, her 이 있고 there 노드를 방문했을때 : there, here 가 저장
	//바늘이 he, cache 가 있고 che노드를 방문했을 때 : he가 저장됨 , 참고로 che노드의 terminal은 -1임
	vector<int> output;
	...//앞의 코드라 생략
}
//트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다.
void computeFailFunc(TrieNode* root) {
	//루트에서부터 시작해 한 단계씩 아래로 내려가며 각 노드의 실패 연결을 계산한다.
	queue<TrieNode*> q;
	root->fail = root; //루트의 실패 연결은 자기 자신
	q.push(root);
	while (!q.empty()) {
		TrieNode* here = q.front(); q.pop();
		//here의 모든 자손에 대해 실패 연결을 계산하고 이들을 큐에 넣는다.
		for (int edge = 0; edge < ALPHABETS; ++edge) {
			TrieNode* child = here->children[edge];
			if (!child) continue;
			"1레벨(root의 1차 자식)노드의 실패 연결은 항상 루트"
			if (here == root)
				//1차 자식은 부모가 루트이며 루트의 실패연결도 루트
				//루트에서 edge(H)로 가는게 실패연결이라고 오해하지 마라!!!!
				//(루트의 루트인 가상루트는 일단 H로 가는 길이 없어)
				child->fail = root;
			else {
				//아닌 경우: 자식(CH)과 부모(C)를 연결하는 기준은 edge(H) 인 상태에서
				//현 here는 부모(C)이며 부모에서의 실패연결을 찾는다.(여기선 루트가 되겠죠)
				//부모의 실패연결노드에서 edge(H)로 이어진 자식(H)는 바로 자식(CH)의 실패연결이 된다.
				//없다면 부모의 실패연결들을 따라가면서 edge(H)와 연결된 놈이 자식의 실패연결이 된다.
				// root--C--CH
				TrieNode* t = here->fail;	//here : 부모
				while (t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge]) t = t->children[edge];	//핵심이네!!!!
				child->fail = t;
			}
			//출력 문자열 목록: 실패 연결을 따라간 노드에서 복사해온 뒤, 이 위치에서 끝나는
			//바늘 문자열이 있으면 추가한다.
			child->output = child->fail->output;
			if (child->terminal != -1) //바늘인 경우
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}
//!!!! 바늘에 해당하는 것은 트라이임 !!!!
//p800 아호-코라식 알고리즘의 실제 탐색 과정
//trie에 포함된 패턴들을 s에서 찾는다.
//s내에서 패턴이 출현할 때마다(마지막 글자(집더미의 인덱스), 패턴 번호)의 쌍을 저장한다.
vector<pair<int, int> > ahoCorasick(const string& s, TrieNode* root) {
	vector<pair<int, int> > ret;
	TrieNode* state = root;
	//실제 반복문 내는 KMP와 별로 다를 것이 없다.
	for (int i = 0; i < s.size(); ++i) {
		int chr = toNumber(s[i]);
		while (state != root && state->children[chr] == NULL)
			state = state->fail;	//for x while 의 총 수행 횟수 O(N) (N:짚더미)의 길이 이하가 된다.
									//물 부은 것 만큼 뺄 수 있듯이
		if (state->children[chr]) state = state->children[chr];
		for (int j = 0; j < state->output.size(); ++j)
			ret.push_back(make_pair(i, state->output[j]));
	}
	return ret;
}
그림 26.7(p796참고)
index		0 1 2 3 4 5 ...
짚더미		A C H E D F ...
빈노드		A		AC		ACH		CH		CHE
		A		C		H		fail	E	
											이 노드에서 ouput에 HE의 인덱스를 가지고 있다.
ret.push(make_pair(짚더미의 인덱스 3, HE의 인덱스 0)


//KMP알고리즘과의 차이 : 몇 글자나 대응되었는지를 나타내는 matched변수가 현재 상태를 나타내는 노드의
//포인터로 바뀌고, 부분 일치 테이블을 참조하는 대신 노드의 실패 연결을 따라가는 것만이 다르지요
//참고 비교용 p657 KMP 알고리즘의 다른 구현
vector<int> kmpSearch2(const string& H, const string& N) {
	int h = H.size(), n = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	//현재 대응된 글자의 수 //단어가 하닌 문자 캐릭 하나를 기준으로 대응되는 수를 센다
	int matched = 0;
	//짚더미의 각 글자를 순회한다.
	for (int i = 0; i < h; ++i) {
		//matched번 글자와 짚더미의 해당 글자가 불일치할 경우,
		//현재 대응된 글자의 수를 pi[matched - 1]로 줄인다.
		while (matched > 0 && H[i] != N[matched])	 
			matched = pi[matched - 1];		
			//aabaabac 에서 pi[6]즉 aabaaba의 mips는 aaba임
			//바늘이 8글자 인 상태에서 7개까지 일치하고 8번째에서 틀린다면
			//N[7]: 8번째 글자에서 while 루프 탈출함 , matched = 4가 됨
			//N[4]: 5번째 글자부터 다시 확인한다.
		
		//글자가 대응될 경우
		if (H[i] == N[matched]) { //N[4] 바늘의 5번째(시작이 1번째인 인덱스) 글자랑 일치시
			++matched;	//4 -> 5 이 된다.
			if (matched == n) {
				ret.push_back(i - n + 1);	//8글자 바늘이면 i는 7일때 대응확인
				matched = pi[matched - 1];
			}
		}
	}
	//bigO(2H) 내부 while들에 대한 전체 수행횟수는 H의 길이에 비례한다.
	//while 루프는 집더미의 일치되지 않고 pi[matched - 1]의 값이 길수록 길어진다
	//pi[matched - 1]의 길이가 긴만큼 짚더미 H에 대한 처리한 량도 증가한다.
	return ret;
}

//p802 보안종결자(NH 상) : 바늘들에게 걸리지 않는 짚더미를 만들어라 !!!!
전산망의 루트 비밀번호는 알파벳 소문자로 구성된 길이 n의 문자열인데
길이 n인 소문자 문자열 중 침입 감지 시스템(IDS)에 인식되지 않는 문자열의 개수를 계산하라
//집더미(IDS)에 바늘이 하나도 존재하면 안됨
//p805 보안종결자 문제를 해결하는 동적 계획법 알고리즘
const int MOD = 10007;
int cache[101][1001]; //트라이 노드수 : ids패턴수 X 각 패턴의 길이 : 100 X 10
//!!!! 아래 아이디어가 핵심
//앞으로 length글자를 더 만들어야 하는데, 아호-코라식 알고리즘의
//현재 상태가 state에 주어질 때 IDS에 걸리지 않는 문자열의 수는? 
int count(int length, TrieNode* state) {
	//기저 사례: 이 상태에 IDS문자열이 출현하면 곧장 종료
	if (state->output.size()) return 0;
	//기저 사례: 문자열을 전부 만든 경우
	if (length == 0) return 1;
	int& ret = cache[length][state->no];	//[남은 글자 길이][트라이 노드 상태]
	if (ret != -1) return ret;
	ret = 0;
	//다음으로 letter 글자를 넣을 경우
	for (int letter = 0; letter < ALPHABETS; ++letter) {
		//next를 사용한것은 실패연결을 쭉 따라간다음 letter쪽으로 가는 경우
		//바늘문자열의 가지치기가 ALPHABETS지수승이라 바늘이 많다 그래서 중복계산이 많아서 줄일려구 한 것임
		ret += count(length - 1, state->next[letter]);
		ret %= MOD;
	}
	return ret;
}
//p806 트라이의 각 노드에 no(노드번호)와 next테이블을 계산하는 재귀 함수의 구현
void computeTransition(TrieNode* here, int& nodeCounter) {
	//0에서 시작하는 번호를 매긴다: cache[]의 인덱스
	here->no = nodeCounter++;
	//here 뒤에 글자 chr를 붙였을 때 어느 상태로 가는가?
	for (int chr = 0; chr < ALPHABETS; ++chr) {
		//next[] 값을 계산해 저장한다.
		TrieNode* next = here;
		while (next != next->fail && next->children[chr] == NULL)
			next = next->fail;
		if (next->children[chr]) next = next->children[chr];
		here->next[chr] = next;	//next가 자식 chr이 없다면 root 인가영? 넹.
		//재귀적으로 모든 노드에 대해 전이 테이블을 계산한다.
		if (here->children[chr])
			computeTransition(here->children[chr], nodeCounter);
	}
}
//dfs시에는 이미 방문한 노드를 체크해야 하는데 위에선 그런 코드가 없다. 이것은 트라이의 구조때문이다.
//분기된 노드의 자손이 만나는 트라이는 없어요. 
//자손이 만나려면 바늘이 같아야 되지요. 허나 바늘이 같으면 분기자체가 안되는 모순이 있어요.

//------------------------보안종결자 소스-------------------//
// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
	TrieNode* children[ALPHABETS];
	TrieNode* next[ALPHABETS];
	// 현 위치에서 끝나는 문자열의 번호
	int terminal;
	// 트라이 노드의 번호
	int no;
	// 이 노드에서 매칭이 실패했을 때 이 곳으로 가서 계속한다.
	// 이 노드에 대응되는 문자열의 접미사이면서 트라이에 포함된 최대 문자열.
	TrieNode* fail;

	// 이 노드가 방문되었을 때 등장하는 문자열들의 번호
	vector<int> output;
	TrieNode() : terminal(-1) {	memset(children, 0, sizeof(children)); }
	~TrieNode() { for(int i = 0; i < ALPHABETS; i++) if(children[i]) delete children[i]; }

	// 이 노드를 루트로 하는 트라이에 번호가 id 인 문자열 key 를 추가한다
	void insert(const char* key, int id) {
		if(*key == 0) terminal = id;// 문자열이 끝나면 terminal 만 참으로 바꾸고 종료
		else {
			int next = toNumber(*key);
			if(children[next] == NULL) children[next] = new TrieNode();
			children[next]->insert(key + 1, id);
		}
	}
	TrieNode* find(const char* key) {
		if(*key == 0) return this;
		int next = toNumber(*key);
		if(children[next] == NULL) return NULL;
		return children[next]->find(key+1);
	}
};

// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다.
"더럽게 햇갈리니 " "조상노드의 실패연결노드의 자손노드를 연결한다!!!!" " 이것만은 기억하자."
void computeFailFunc(TrieNode* root) {
	// 루트에서부터 시작해 한 단계씩 아래로 내려가며 각 노드의 실패 연결을 계산한다.
	queue<TrieNode*> q;
	// 루트의 실패 연결은 자기 자신
	root->fail = root;
	q.push(root);
	// 큐에 중복노드가 채워질 위험성은 없는가? 없다. 
	// 큐에 중복노드가 있다 
	// -> 두개의 문자열이 insert시 중간에 분기된뒤 한노드에 다시 만나야 한다.
	// -> 허나 그것은 insert 시 같은 글자가 서로 나뉜 path를 가지며 한노드에 만나야 한다는 것이므로 모순.
	while(!q.empty()) {
		TrieNode* here = q.front();
		q.pop();
		// here 의 모든 노드에 대해 실패 연결을 계산하고 이들을 큐에 넣는다
		for(int edge = 0; edge < ALPHABETS; ++edge) {
			TrieNode* child = here->children[edge];
			if(!child) continue;

			// 1레벨 노드의 실패 연결은 항상 루트
			if(here == root)
				child->fail = root;
			else {
				// 아닌 경우 부모의 실패 연결을 따라가면서 실패 연결을 찾는다
				TrieNode* t = here->fail;
				while(t != root && t->children[edge] == NULL)
					t = t->fail;
				if(t->children[edge]) t = t->children[edge];
				child->fail = t;
			}
			// output 배열을 계산: 이 위치에서 끝나는 문자열이 있으면 추가한다
			child->output = child->fail->output;
			if(child->terminal != -1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

const int MOD = 10007;
int cache[101][1001]; //트라이 노드수 : ids패턴수 X 각 패턴의 길이 : 100 X 10

// 앞으로 length 글자를 더 만들어야 하는데, 아호-코라식 알고리즘의
// 현재 상태가 state 에 주어질 때 IDS 에 걸리지 않는 문자열의 수는?
int count(int length, TrieNode* state) {
	// 기저 사례: 이 상태에 문자열이 출현하면 곧장 종료
	if(state->output.size()) return 0;
	// 기저 사례: 문자열을 전부 만든 경우
	if(length == 0) return 1;
	int& ret = cache[length][state->no];
	if(ret != -1) return ret;
	ret = 0;
	for(int letter = 0; letter < ALPHABETS; letter++) {
		ret += count(length-1, state->next[letter]);
		ret %= MOD;
	}
	return ret;
}


// 상태간의 전이 테이블을 next[] 에 채운다. computeFailFunc()
// 를 통해 이미 실패 함수가 계산되어 있다고 가정한다.
void computeTransition(TrieNode* here, int& nodeCounter) {
	// 0 에서 시작하는 번호를 매긴다: table[] 의 인덱스
	here->no = nodeCounter++;
	// here 뒤에 글자 chr 를 붙였을 때 어느 상태로 가는가?
	for(int chr = 0; chr < ALPHABETS; chr++) {
		// next[] 값을 계산해 저장한다
		TrieNode* next = here;
		while(next != next->fail && next->children[chr] == NULL)
			next = next->fail;
		if(next->children[chr]) next = next->children[chr];
		here->next[chr] = next;

		// 재귀적으로 모든 노드에 대해 전이 테이블을 계산한다
		// 자식이 있는 경우에 한해서다.!!!!
		if(here->children[chr])
			computeTransition(here->children[chr], nodeCounter);
	}
}
//no의 중복세팅이 이루어 지지 않는다. next테이블과 no(노드번호)를 헷갈리지 말자.
//no는 자식으로만 전달되며 no번호가 이미 세팅된 노드를 만날수 없다.
//만난다면 그건 같은 문자열이기 때문이며 이는 중간에 분기후 만나게 된다는 것을 부정하는 모순이 발생.
//next테이블을 만드는 것은 앞의 아호코라식 알고리즘에서는 실패연결시 while로 찾는 과정이
//있는데 이것이 호출과정마다 while을 수행하면 많은 시간낭비가 발생하기 때문이다.


int solve(int length, const vector<string>& patterns) {
	// 트라이를 만든다
	TrieNode trie;
	for(int i = 0; i < patterns.size(); i++)
		trie.insert(patterns[i].c_str(), i);

	// 실패 함수를 계산
	computeFailFunc(&trie);

	// 상태 전이 테이블을 생성한다
	int t = 0;
	computeTransition(&trie, t);

	// 동적 계획법을 위한 캐시를 초기화
	memset(cache, -1, sizeof(cache));
	return count(length, &trie);
}


int main() {
	int cases;
	cin >> cases;
	while(cases--) {
		int n, m;
		cin >> n >> m;
		vector<string> patterns(m);
		for(int i = 0; i < m; i++)
			cin >> patterns[i];
		cout << solve(n, patterns) << endl;
	}
}

//--------------------------------------------------------//


//------------------------ ETC---------------------------------------//
//간단한 트라이 예시 문제(책은 p793에 자세히 있을 거얌)
//editorial 은 맵으로 해결했음. 지금 보니 쉽네
//맵에다 하나씩 틀린거 전부 집어 넣어봐야 100만개가 안되거등
"질의시 한문자만 다른거야 한다", "동일문자면 false"
//트라이로 푼건 응용력이 높다
"한개 틀리거나 하나도 안 틀린거 찾기", "3개 이하 틀린거 찾기" 등등으로 말이지
http://codeforces.com/contest/514/problem/C
2 3
aaaaa	//트라이 구성
acacaca	//트라이 구성
aabaa	//질의
ccacacc	//질의
caaac	//질의
//Khagan

#include <algorithm>
#include <string.h>
#include <stdio.h>
#define  maxn      600005
using    namespace std;

struct data {
	bool ok;
	data *next[3];
	data() { ok = false; next[0] = next[1] = next[2] = NULL; }
};
int N, n, m;
char s[maxn];
void update(data *tree, int curr, int len) {
	if (curr == len) {
		tree->ok = true;
		return;
	}
	if (tree->next[s[curr] - 'a'] == NULL)
		tree->next[s[curr] - 'a'] = new data();
	update(tree->next[s[curr] - 'a'], curr + 1, len);
}
bool query(data* tree, int curr, int len, bool st) {
	if (curr == len) {
		// 여기까지 도착하는데 딱 한개 틀린 경우 참
		if (tree->ok && st) return true;
		return false;
	}
	//st: 한개만 틀린가를 나타냄
	bool ret = false;
	for (int i = 0; i < 3; ++i)	// 이부분 참 잘 짰음 !!!! 예술임
		if (tree->next[i]) {
			if (s[curr] - 'a' == i)
				ret |= query(tree->next[i], curr+1, len, st);
			if (s[curr] - 'a' != i)
				if (st == false)
					ret |= query(tree->next[i], curr+1, len, true);	//1개 틀림 전달
		}
/*
	// if (tree->next[i]) 는 중복이니 밖으로 뺀것
	for (int i = 0; i < 3; ++i) {
		if (s[curr] - 'a' == i)
			if (tree->next[i])
				ret |= query(tree->next[i], curr+1, len, st);
		if (s[curr] - 'a' != i)
			if (tree->next[i])
				if (st == false)
					ret |= query(tree->next[i], curr+1, len, true);
	}
*/
	return ret;
}
int main() {
	data* root = new data();
	scanf("%d%d", &n, &m);
	rep(i,n) {
		scanf("%s", s);
		N = strlen(s);
		update(root, 0, N);
	}
	rep(i,m) {
		scanf("%s", s);
		N = strlen(s);
		bool ok = query(root, 0, N, false);
		if (ok) printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}

!!!!! 폴리노미얼 해시
//폴리노미얼 해시... 어렵네.. 위에거 이해하니 이건 더 어렵다는 사실을 알게됨
const ll mod=1000000000000000003; //의미 없는줄 알았는데 의미 있다..
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=601000;
int n,m;
ll pw[N];
char s[N];
unordered_set<ll> ff;
int main() {
	scanf("%d%d",&n,&m);
	pw[0]=1;
	rep(i,1,600001) pw[i]=pw[i-1]*3%mod;
	rep(i,0,n) {
		scanf("%s",s);
		int l=strlen(s);
		ll hs=0;
		for (int j=0;j<l;j++) hs=(hs*3+s[j]-'a')%mod;
		ff.insert(hs);
	}
	rep(i,0,m) {
		scanf("%s",s);
		int l=strlen(s);
		ll hs=0;
		bool fg=0;
		for (int j=0;j<l;j++) hs=(hs*3+s[j]-'a')%mod;
		for (int j=0;j<l;j++) {
			ll nhs=(hs-(s[l-1-j]-'a')*pw[j])%mod;
			if (nhs<0) nhs+=mod;
			rep(k,0,3) if (s[l-1-j]-'a'!=k) {
				if (ff.count((nhs+k*pw[j])%mod)) fg=1;
			}
			if (fg) break;
			// s[l-1-j]
		}
		puts(fg?"YES":"NO");
	}
}
http://codeforces.com/contest/514/submission/9841163
틀린 코드네...;	//키 중복에 대한 처리가 안되었다.
				//mod를 엄청큰 값으로 두어 훼이크로 풀었구나...
a	//key가 0으로 잡힘
cabcccbcccbacbabbbaacabacaccacbcacaabb	//mod 값임 즉 key랑 매치됨

b //key가 1로 잡힘
cabcccbcccbacbabbbaacabacaccacbcacaabb	//0임 하나 차이로 인식 될듯

를 입력시키면 좆될거다//테스트 결과 좆됩을 확인
1 1
b
cabcccbcccbacbabbbaacabacaccacbcacaabb

YES 라고 뜸//

해결책은 mod가 넘어갈때마다 카운트를 같이 기록해서 set에다 집어 넣는거지
sets.insert(mp(long long, long long)) //mod한 것과, mod이상이 되어 mod된 횟수
sets.insert(mp(long long, int)) 로 충분하다.;
"문자열이 30만개이면 곱해서 오버되는 케이스의 경우는 30만개 미만이라서임
	long long test = 0;
	const long long mod = 1000000000000000007;
	long long cnt = 0;
	rep(i, 300000) {
		test = (test + 1) * 3;
		if (test >= mod) {
			test %= mod;
			cnt++;
			cout << "i: " << i << ", " << cnt << endl;
		}
	}
이게 해결책이라 볼수 없네(아래 경우) pair(test, cnt)가 같거등
(x + 1) * 3 = mod * 2 + 1
(y + 1) * 3 = mod * 1 + 1
	"결국 충돌처리를 따로 만들어야 하는군 GG"

여기 까지다.. 덕분에 set 공부를 하게 되었네.. trie를 강력 추천함.. 이상한 코드 땜시 해매기만 했네.

// set 예시: 중복원소에 대한것
	set<int> sets;
	sets.insert(1);
	sets.insert(5);
	sets.insert(5);
	cout << sets.count(5) << endl;		// 1

	unordered_set<int> u_sets;	//#include <unordered_set>
	u_sets.insert(1);
	u_sets.insert(5);
	u_sets.insert(5);
	cout << u_sets.count(5) << endl;	// 1

	multiset<int> m_sets;
	m_sets.insert(1);
	m_sets.insert(5);
	m_sets.insert(5);
	cout << m_sets.count(5) << endl;	// 2

























