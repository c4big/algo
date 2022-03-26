How can I search Google for a negative number? : https://webapps.stackexchange.com/questions/50092/how-can-i-search-google-for-a-negative-number/50113
마이너스기호 붙은 것을 검색하고 싶다. 특히 프로그래밍 관련해서 말이지 근데 구글 검색엔진이 좀 구리다. 어떻게 해야 할까
http://symbolhound.com/		// 이거 쓰란다.


// 철권 노트북 발열 줄이기 전원
https://m.blog.naver.com/PostView.nhn?blogId=nazeiro&logNo=90158583617&proxyReferer=https:%2F%2Fwww.google.com%2F
노트패드단축키
ctrl + {, }	// 6줄 가량 이동
ctrl + b	// 괄호짝 이동
f8 			// 오른쪽 창 왼쪽 창 이동
f11			// 전체화면
ctrl+tab	// 내부 화면 이동
ctrl + up, down	// 마우스 휠  
location navigator 플러그인 깔면 previous view 이동 단축키 사용가능 


https://jacking75.github.io/cpp_stl_fill/ 2차원 배열 세팅, 다차원 배열 세팅, long long 형 세팅은 조심해야함
int a[10][20];
std::fill(a[0], a[10], 100);

int b[10][20][30];
std::fill(b[0][0], b[10][0], 100);

int array[10][20][30];
int val = 100;
std::fill((int*)array, (int*)(array+10), val);		// 처음 포인터랑 끝 포인터만 맞추면 된다능.



http://labspace.naver.com/nmt/	// 영어 번역. 200단어만 지원..
https://github.com/iyaacs/algospot
http://blog.myungwoo.kr/32	// 매우 좋은 사이트
http://dev-strender.github.io/problem_solving/Algorhtim_%EB%8C%80%ED%9A%8C%EA%B4%80%EB%A0%A8_%ED%8C%81.html
// cin 과 scanf를 같이 쓴다면 std::ios_base::sync_with_stdio(false); 를 안하고
// 과부하 걸리는 곳에 scanf를 적용시켜라 (혹시나 런타임 에러가 날 수 있기 때문이다.) 

// double 형의 정수형 표현 범위 2^53 까지 가능하다. 2^53+1 부터는 정확하게 저장안된다.
https://stackoverflow.com/questions/1848700/biggest-integer-that-can-be-stored-in-a-double
9,007,199,254,740,992‬
9007199254740992‬

입출력 개행 테스트
https://m.blog.naver.com/PostView.nhn?blogId=ruvendix&logNo=220953194013&proxyReferer=https%3A%2F%2Fwww.google.com%2F
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<double> arr;
	for (int i = 0; i < 10; ++i) {
		arr.push_back(0.1 * i);
	}
	//cout.width(5);	// 딱 한번만 되므로 안 좋다. : 이쪽 출력에서는 한번 설정시 계속 유지되는 건 없다고 보면 됨.
	for (int i = 0; i < 10; ++i) {
		cout.width(5);
		cout << arr[i];
	}
	
	cout << endl;
	//cout << setw(10);	// 마찬가지로 딱 한번만 되므로 안 좋다.
	for (int i = 0; i < 10; ++i) {
		cout << setw(10) << arr[i];	// iomanip 인클루드 해야함.
	}

	cout << endl;
	cout << setw(7) << arr[0] << arr[1] << '\n';	// 역시나 arr[0] 에서만 setw 가 적용된다.
	for (int i = 0; i < 10; ++i) {
		cout << setw(7) << setfill('#') << arr[i];	// setfill 은 한번 설정하면 다음에도 영향을 미친다.
	}

	cout << endl;
	cout.precision(5);// setprecion(10) 을 직접 호출하는 것과 무슨 차이가 있을까
	cout << fixed;	// 이걸 안해주면 뒤에 소수점이 출력안되더라.
	for (int i = 0; i < 10; ++i) {
		cout <<  setw(10) << arr[i];
	}
	return 0;
}
출력결과
    0  0.1  0.2  0.3  0.4  0.5  0.6  0.7  0.8  0.9
         0       0.1       0.2       0.3       0.4       0.5       0.6       0.7       0.8       0.9
      00.1
######0####0.1####0.2####0.3####0.4####0.5####0.6####0.7####0.8####0.9
###0.00000###0.10000###0.20000###0.30000###0.40000###0.50000###0.60000###0.70000###0.80000###0.90000




http://occamsrazr.net/tt/216 //auto 장점이 잘나온 류광 사이트
아마도 C++0x에서 가장 인기 있는 기능이 auto일 것입니다. auto를 잘 말해주는 예로, 
현재(C++03)는
for (vector<string>::const_iterator it = v.begin(); it!=v.end(); ++it)
라고 써야 하는 것을 C++0x에서는
for (auto it = v.begin(); it!=v.end(); ++it)

https://mbevin.wordpress.com/2012/11/14/range-based-for/
for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
	auto value = *it;
	...;
}
for (auto value: v) { ...; }

// loop-varialbe is a Value
for (auto i: arr) { printf("%d\n", i); }
// loop-variable is a reference, so can change it - this will give a compile error if arr is a const
for (auto& i: arr) { i += 1; }
// loop-variable is a const reference - can't change it
for (const auto& i: arr) { printf("%d\n", i); }

vi myArr(10,0);
for (auto i : myArr) {
	i = 1;	//복사된거기 때문에 myArr이 변경이 안됨 !!!!, 물론 i는 변경 가능하다.
}
for (auto& i : myArr) {
	i = 1;	//myArr이 변경됨
}
for (const auto& i : myArr) {
	i = 2;	//const auto i = myArr[i] 로 초기화 된 놈이라 i를 다시 바꾸면
			//구문 에러임(컴파일 에러남)
}

//std::ios::sync_with_stdio(false) + std::cin 의 속도는 굉장히 빠르다!!!!
//단 cout << .. << endl; 은 쓰면 안됨 //endl은 버퍼를 강제로 비워버린다.
https://algospot.com/forum/read/2496/

//std::ios::sync_with_stdio(false) 를 cin 과 scanf 혼용해서 쓰면 망하네..
// 특히 visual studio 에선 안망하고 G++에서만 망하니 더운 혼돈이 올수 있다.
https://algospot.com/judge/submission/detail/472593
int main() {
	ios::sync_with_stdio(false);	// 요걸 주석처리해야 통과된다.
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, m;
		scanf("%d %d", &n, &m);		// m값이 제대로 세팅이 안된다. web compiler에서도 마찬가지였음













interactive problem !!!!
여기선 내가 출력한 뒤 fflush(stdout); 를 호출해야 함
// 나의 출력이 끝나면 그건 바로 프로그램에게 전달 안되고 버퍼에 쌓이기 때문임
// fflush(stdout)은 버퍼를 비우면서 프로그램으로 전달시킨다.



// 2진수 출력
10 8	//00001010
8 8		//00001000
void print2way(int num, int size) {
	int i = size - 1;
	while (i >= 0) {
		cout << ((num >> i) & 1);
		--i;
	}
	cout << '\n';
}


"string 조작함수들 !!!!"
// string 자체를 교체하는건 없으니 아래처럼 구현 
void ReplaceString(string & strCallId, const char * pszBefore, const char * pszAfter)
{
	size_t iPos = strCallId.find(pszBefore);
	size_t iBeforeLen = strlen(pszBefore);
	while (iPos < std::string::npos)
	{	
		strCallId.replace(iPos, iBeforeLen, pszAfter);
		iPos = strCallId.find(pszBefore, iPos);		// iPos 부터 시작하여 pszBefore 문자를 찾는다.
	}
}
void test() {
	string str1 = "abcdefabcdef";
	ReplaceString(str1, "abcd", "");	// efef
	cout << str1 << endl;

	string str2 = "aaaaaaaa";
	ReplaceString(str2, "aaa", "bb");	// bbbbaa
	cout << str2 << endl;

	string str3 = "aaaaaaaa";
	ReplaceString(str3, "aaa", "ca");	// cccaa	: 순차적임 !!!!
		//	aaa aaaaa
		//	ca aaaaa
		//	caaa aaa
		//	cca aaa
		//	ccca a
	cout << str3 << endl;
}

// 한 원소를 바꾸는 건 std에 있어용
void some_func() {
  std::string s = "example string";
  std::replace( s.begin(), s.end(), 'x', 'y'); // replace all 'x' to 'y'
}

// 한 원소를 제거하는 거
void test() {
	string str = "ab cde fgh ij k l m";
	remove(str.begin(), str.end(), ' ');
	cout << str << endl;	// abcdefghijklmn k l m

	str = "ab cde fgh ij k l m";
	str.erase(remove(str.begin(), str.end(), ' '), str.end());	
	// remove 가 리턴하는 건 string의 쓸모없는 부분 시작 지점임
	cout << str << endl;	// abcdefghijklmn
}

// 특정 원소드을 제거하는거
void test() {
   string str("(555) 555-5555");

   char chars[] = "()-";

   for (unsigned int i = 0; i < strlen(chars); ++i)
   {
      // you need include <algorithm> to use general algorithms like std::remove()
      str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
   }

   // output: 555 5555555
   cout << str << endl;
}
void removeCharsFromString( string &str, char* charsToRemove ) {
   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}
//example of usage:
removeCharsFromString( str, "()-" );


// string 에 erase 참고 예시
int main ()
{											// ^ : 지워지는 부분임
  std::string str ("This is an example sentence.");
  std::cout << str << '\n';
                                           // "This is an example sentence."
  str.erase (10,8);                        //            ^^^^^^^^
  std::cout << str << '\n';
                                           // "This is an sentence."
  str.erase (str.begin()+9);               //           ^
  std::cout << str << '\n';
                                           // "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
  std::cout << str << '\n';
                                           // "This sentence."
  return 0;
}

// string - 숫자자료형 변환 !!!!
void test() {
	ll num = 123456789123456789ll;
	string str = to_string(num);	// num 이 정수형 타입이든 실수형 타입이든 간에 string으로 변환됨

	ll num2 = stoll(str);	// stoll, stoi, stof, stod, stold, ... 거꾸로 변환은 함수 종류가 많네
}
// string 간단 조작글: 참고할 만하다.
http://makerj.tistory.com/127#string의-문자열-대체하기-replace기능


// 스트링 토크나이저 tokenizer 를 기술

// 일반 문자열을 숫자자료형으로 변환하는 기술


// 사전순 비교기 함수의 원형은 다음과 같다.
http://www.cplusplus.com/reference/algorithm/lexicographical_compare/
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
							 InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1) {	// A배열이 끝에 도달하지 않았다면
		if (first2 == last2 || *first1 > *first2)	
			return false;	// B배열이 비교할 원소가 없거나 , 비교시 A[i] < B[i] 이다면
		else if (*first1 < *first2) 
			return true;
		++first1; ++first2;
	}						
	return (first2 != last2);	// B 배열에 비교할 원소가 남았다면 참
								// B 배열 원소도 없다면(즉 완전 일치인 경우) 거짓..
}

// 짠게 가독성도 없고 구린거 같아 일단 이렇게 바꿈
template <class IT1, class IT2>
bool lexico_cmp(IT1 curA, IT1 lastA, IT2 curB, IT2 lastB) {
	while (curA != lastA) {
		if (curB == lastB || *curA > *curB)
			return false;
		else if (*curA < *curB)
			return true;
		++curA; ++curB;
	}
	return (curB != lastB);		// == 이면 같아서 false 임
}
// lexicographical_compare example
#include <iostream>     // std::cout, std::boolalpha
#include <algorithm>    // std::lexicographical_compare
#include <cctype>       // std::tolower

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }	// 사전순 비교기로 쓸수 있겠다.

int main () {
  char foo[]="Apple";
  char bar[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
  std::cout << '\n';

  std::cout << "Using mycomp as comparison object: ";
  std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  std::cout << '\n';

  return 0;
}
Comparing foo and bar lexicographically (foo<bar):
Using default comparison (operator<): true		// A 는 a보다 작기 때문임
Using mycomp as comparison object: false		// p 는 a보다 크므로


// 사전식 정렬을 구현해 보자.
bool mycomp(char c1, char c2) { 
	if (tolower(c1) == tolower(c2)) {	// 소문자 취할시 같은 알파벳이면
		return c1 > c2;		// 대문자를 더 크게 보도록 하자: 실제 사전은 이렇진 않다.
							// 실제로 구현하려면 lexicographicl_compare를 뜯어 고쳐야 할듯..
	}
	return tolower(c1) < tolower(c2); // 다른 알파벳이면
}
bool mycomp2(const string& a, const string& b) {
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), mycomp);
}

int main() {
	ios::sync_with_stdio(false);
	vector<string> arr;

	arr.push_back("a");
	arr.push_back("z");
	arr.push_back("abcd");
	arr.push_back("abc");

	sort(arr.begin(), arr.end());	// 정렬시 arr문자열이 전부 대문자로만 이루어진 거라면 사전순 정렬 가능
									// 마찬가지로 소문자로만 이루어진 거라면 사전순 가능
									// 자체가 lexicographically 하게 비교하고 있었음
	rep(i, arr.size()) cout << arr[i] << endl;

	cout << endl;
	arr.push_back("A");
	arr.push_back("Z");
	arr.push_back("Abcd");
	arr.push_back("aBcd");
	sort(arr.begin(), arr.end());	// 망함요.
	rep(i, arr.size()) cout << arr[i] << endl;

	cout << endl;
	sort(arr.begin(), arr.end(), mycomp2);
	rep(i, arr.size()) cout << arr[i] << endl;
	return 0;
}

bool mycomp1(char c1, char c2) { return tolower(c1) < tolower(c2); }
bool mycomp2(char c1, char c2) { 
	if (tolower(c1) == tolower(c2)) {	// 소문자 취할시 같은 알파벳이면
		return c1 > c2;		// 대문자를 더 크게 보도록 하자 대문자를 뒤에 놓도록 함. (실제 사전은 이렇진 않다.)
							// 		A: 65, a: 97 = 아스키값이 소문자가 더 크기 땜시
							// 실제로 구현하려면 lexicographicl_compare를 뜯어 고쳐야 할듯..
	}
	return tolower(c1) < tolower(c2); // 다른 알파벳이면
}
bool compFunc1(const string& a, const string& b) {
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), mycomp1);
}
bool compFunc2(const string& a, const string& b) {
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), mycomp2);
}

int main() {
	ios::sync_with_stdio(false);
	freopen("output.txt", "w", stdout);
	vector<string> arr;

	arr.push_back("a");
	arr.push_back("z");
	arr.push_back("abcd");
	arr.push_back("abc");

	sort(arr.begin(), arr.end());	// 정렬시 arr문자열이 전부 대문자로만 이루어진 거라면 사전순 정렬 가능
									// 마찬가지로 소문자로만 이루어진 거라면 사전순 가능
									// 자체가 lexicographically 하게 비교하고 있었음
	rep(i, arr.size()) cout << arr[i] << endl;

	cout << endl;
	arr.push_back("A");
	arr.push_back("Z");
	arr.push_back("Abcd");
	arr.push_back("aBcd");
	sort(arr.begin(), arr.end());	// 망함요.
	rep(i, arr.size()) cout << arr[i] << endl;

	cout << endl;
	sort(arr.begin(), arr.end(), compFunc1);
	rep(i, arr.size()) cout << arr[i] << endl;

	cout << endl;
	sort(arr.begin(), arr.end(), compFunc2);
	rep(i, arr.size()) cout << arr[i] << endl;
	return 0;
}


a
abc
abcd
z

A
Abcd
Z
a
aBcd
abc
abcd
z

A
a
abc
Abcd
aBcd
abcd
Z
z

a
abc
abcd
aBcd
A
Abcd
z
Z


// 실제 답은 아래와 같다.(엑셀로 정렬한거임)	// 1. 모든걸 소문자로 만들어 비교해보고, 같은 경우 원본 비교
a
A
abc
abcd
aBcd
Abcd
z
Z

실제 답 소스

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(const string& a, const string& b) {
	string tmpA = a;
	string tmpB = b;
	transform(tmpA.begin(), tmpA.end(), tmpA.begin(), ::tolower);
	transform(tmpB.begin(), tmpB.end(), tmpB.begin(), ::tolower);
	if (tmpA < tmpB)
		return true;
	else if (tmpA == tmpB)
		return a > b;	// 대문자 아스키값이 소문자보다 작으므로 거꾸로 리턴한다.
	return false;
}

int main() {
	vector<string> arr;
	arr.push_back("a");
	arr.push_back("z");
	arr.push_back("abcd");
	arr.push_back("abc");
	
	arr.push_back("A");
	arr.push_back("Z");
	arr.push_back("Abcd");
	arr.push_back("aBcd");

	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << '\n';
	return 0;
}
a
A
abc
abcd
aBcd
Abcd
z
Z





// 비교기 연습은 되었으나 완벽한 구현을 위해선 노력해야함
// 대소문자 구분없이 비교하는 예시
http://www.soen.kr/lecture/ccpp/cpp4/38-1-3.htm		// stricmp를 이용하자. ("abc", "ABC")는 같다고 판단하니 이 경우만 다르게 처리하자
http://www.autobase.biz/korean/AutoBaseHelp/Help10%5CScript%5Cstricmp.htm
https://msdn.microsoft.com/ko-kr/library/cc190529(v=vs.110).aspx?cs-save-lang=1&cs-lang=cpp#code-snippet-1 // 참고용
stricmp
int retn=@stricmp(char *string1, char *string2);
stricmp는 두개의 스트링을 비교하는 함수이다. 이 함수는 대소문자 구별을 하지 않는다.
RETURN값
String1과 string2 가 같다면                     retn -> 0
String1이 string2 보다 더 크다면             retn -> 1
String2가 string1 보다 더 크다면             retn -> -1

// 숫자도 비교하려고 추가해서 테스트
	arr.push_back("1a");
	arr.push_back("a1");
// 엑셀결과				
1a
a
A
a1
abc
abcd
aBcd
Abcd
z
Z

출력결과
1a
a
A
a1
abc
abcd
aBcd
Abcd
z
Z

struct compare {
	// a < b 인 경우 true 리턴한다.
	bool operator() (string a, string b) const {
		int judge = stricmp(a.c_str(), b.c_str());// 대소문자를 구분하지 않고 비교
		if (judge == 0) {
			if (a == b) return 0;
			else {
				for (int i = 0; i < a.size(); ++i) {
					if (a[i] != b[i]) {
						if (a[i] > b[i])	// a[i]가 소문자, b[i]가 대문자
							return true;
						else
							return false;
					}
				}
			}
		}
		else
			return judge < 0;
	}
};
int main() {
	//...
	arr.push_back("1a");
	arr.push_back("a1");

	cout << endl;
	sort(arr.begin(), arr.end(), compare());
	rep(i,arr.size()) cout << arr[i] << endl;
	return 0;
}


/*
https://leetcode.com/problems/largest-number/

3 30 34 5 9 숫자가 들어오면 해당 숫자를 조합해서 가장큰 문자를 만드는 문제로
1. 문자열로 변환한다.
2. 문자열 비교 함수를 통해 정렬을 한다.
	그냥 문자열 사전순 정렬한 뒤 뒤에서부터 붙이면 안되는건가?
		안됨: 30, 3 의 경우 330 이 303 보다 더 크기 때문이다.
*/
static bool compare(string a, string b) {
	return a + b > b + a;		// 굳 아이디어임
}
/*
이게 핵심코드이다.
compare 응용하여서 푸는 문제로 아이디어가 좋다.
난이도 : 미디움
*/
static bool compare(string a, string b) {
	return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
	
	vector<string> vs;
	
	for(auto a:nums) {
		string s = to_string(a);
		vs.push_back(s);
	}
	
	sort(vs.begin(), vs.end(), compare);
	
	string ans;
	for(int i=0; i<vs.size(); i++){
		ans += vs[i];
	}
	return ans[0] == '0' ? "0" : ans;
}


map<int, int> m;
rep(i,500000) m[i]++; //이 코드가 vs에서 디버그 모드 10초 걸림 릴리즈는 0.5초 미만
#include <iostream>
#include <string>
#include <vector>
#include <fstream>		//파일 오픈용 :freopne, freopen_s 에는 필요하진 않다
#include <functional>	//greater 함수객체
#include <algorithm>	//sort용
#include <cstdlib>	//atoi 계열, rand, abs, malloc .. 많다.
#include <cstring>	//memset : vs에선 이거 없어도 됨
#include <map>
#include <iomanip> //setpresion
#include <limits> //없어도 vs에선 컴파일 되던데.. numeric_limits 사용할때 
#include <cmath>	//hopot
#include <numeric> //accumulate

#define rep(i,a) for (int i = 0; i < (a); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef const vi cvi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, int> pli;
typedef vector<pli> vpli;


#define rep(i,n) for(int i = 0; i < (n); ++i)
bool hasDuplicate(const vector<int>& array) {
	rep(i,array.size())
		rep(j,i)
			if (array[j] == array[i])
				return true;
	return false;
}
bool isProperSubset(const IntegerSet& a, const IntegerSet& b) {
	...;	//a > b//a가 b의 진 부분 집합이냐
}
//a가 b의 진 부분 집합일 때 a가 항상 앞에 오도록 집합들을 정렬한다.
bool operator < (const IntegerSet& a, const IntegerSet& b) {
	//a가 b의 진부분집합이면 a가 앞에 와야 한다.
	if (isProperSubset(a, b)) return true;	//true는 그대로
	//b가 a의 진 부분 집합이면 b가 앞에 와야한다.
	if (isProperSubset(b, a)) return false;	//false 는 swap
	//a와 b의 크기가 다르다면 작은 쪽이 앞에 와야한다.
	if (a.size() != b.size()) return a.size() < b.size();
	//a,b가 서로 포함관계도 아니고, 크기도 같다면
	//a와 b를 사전순으로 비교해 반환한다.
	//직접 짠다면 대소문자 처리가 골머리 아프게 되겠지만.
	//아래 함수는 그 부분 처리가 되어 있음요.
	" 대소문자 처리는 내부에서 안 되어 있다..."
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}
//어떤수가 정렬되어 있는가?
bool isSorted(const vector<int>& seq) {
	for (int i = 1; i < seq.size(); ++i)
		if (seq[i - 1] > seq[i])
			return false;
	return true;
}
//부동소수 두 수가 같은지 비교하는 간단한 코드 //더 정확한건 책보삼 (p78)
bool absoluteEqual(double a, double b){
	return fabs(a - b) < 1e-10; //10의 10승 1분의 1
}

int majority1(const vector<int>& A) {
	int N = A.size();
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; ++i) {
		int V = A[i], count = 0;
		for (int j = 0; j < N; ++j) {
			if (A[j] == V)
				++count;
		}
		if (count > majorityCount) {
			majorityCount = count;
			majority = V;
		}
	}
	return majority;
}

int majority1(const vector<int>& arr) {
	int n = arr.size();
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < n; ++i) {
		int v = arr[i], count = 0;
		for (int j = 0; j < n; ++j)
			if (arr[j] == v)
				++count;
		if (count > majorityCount) {
			majorityCount = count;
			majority = v;
		}
	}
	return majority;
}
//주어진 배열에서 가장 많이 등장하는 숫자를 반환하기2(0~100 의 수가 주어짐)
int majority2(const vector<int>& A) {
	int N = A.size();
	vector<int> count(101, 0);
	for (int i = 0; i < N; ++i) {
		count[A[i]]++;
	}
	int majority = 0;
	for (int i = 1; i <= 100; ++i) {
		if (count[i] > count[majority]) {
			majority = i;
		}
	}
	return majority;
}

int majority2(const vector<int>& arr) {
	int n = arr.size();
	vector<int> count(101, 0);
	for (int i = 0; i < n; ++i)
		count[arr[i]]++;
	int majority = 0;
	for (int i = 1; i <= 100; ++i)
		if (count[i] > count[majority])
			majority = i;
	return majority;
}


bool operator < (const vector<int>& str1, const vector<int>& str2) {
	if (str1.size() != str2.size()) 
		return str1.size() < str2.size();
	return str1 < str2;
}
void test(string s) {
	vector<int> tmp1 = { 11, 2, 3 };
	vector<int> tmp2 = { 3, 2 };
	vector<int> tmp3 = { 10 };
	vector<vector<int>> arr;
	arr.push_back(tmp1); arr.push_back(tmp2); arr.push_back(tmp3);
	bool tmp = arr[0] < arr[1];	// 여기서만 operator < 가 호출된다.
	sort(arr.begin(), arr.end());	// 여기서는 operator < 가 호출안된다 !!!!!!!! // 비교기 를 만들자.
}
// 이걸 만들어서 sort(arr.begin(), arr.end(), compare()); 를 호출하면 된다.
struct compare {
	bool operator() (const vector<int>& arr1, const vector<int>& arr2) {
		if (arr1.size() != arr2.size()) return arr1.size() < arr2.size();
		return arr1 < arr2;
	}
};



//p103 음식 메뉴 정하기: !@#_1
const int INF = 987654321;
bool canEverybodyEat(const vector<int>& menu); //이 메뉴로 모두가 식사할 수 있는지 여부를 반환한다.
int M; //요리할 수 있는 음식의 종류 수

//food번째 음식을 만들지 여부를 결정한다.
int selectMenu(vector<int>& menu, int food) {
	//기저 : 모든 음식에 대해 만들지 or 안만들지 여부가 결정 되었을 때
	if(food == M) {
		if(canEverybodyEat(menu)) return menu.size();
		//아무거도 못 먹는 사람이 있으면 아주 큰 값을 반환한다.
		return INF;
	}
	//이 음식(food : 음식 번호)을 만들지 않을 경우의 답을 계산한다.
	int ret = selectMenu(menu, food+1);

	//이 음식(food : 음식 번호)을 만드는 경우의 답을 계산한다.
	menu.push_back(food); //메뉴에 음식을 추가
	ret = min(ret, selectMenu(menu, food+1);
	menu.pop_back();
	return ret;
}
//3개의음식이 있다면 이런식으로 재귀 기저를 타겠군요.
//xxx //안짓고 안짓고 안짓고
//xxo //안짓고 안짓고 짓고
//xox
//xoo
//oxx
//oxo
//oox
//ooo

//p111 선택정렬과 삽입정렬   //각 구간 중 가장 작은 인덱스를 찾아 스웝을 한번씩 한다.
void selectionSort(vector<int>& arr){
	for(int i = 0; i < arr.size(); ++i){
		int minIndex = i;
		for(int j = i+1; j < arr.size(); ++j)
			if( arr[minIndex] > arr[j] )
				minIndex = j;
		swap(arr[i], arr[minIndex]);	//swap은 최대 n-1번만 한다만.. 비교는 무조건 n2이라봄.
	}
}
4 2 8 1 //초기
1 2 8 4 //i == 0, 1이 선택됨 
1 2 8 4 //i == 1, 2가 선택되므로 그대로임
1 2 4 8 //i == 2, 4가 선택됨

void insertionSort(vector<int>& arr){			//swap은 위보다 많이 할수도 있음.. 비교는 재수 좋으면 n, 재수 없으면 n2
	for(int i = 0; i < arr.size(); ++i){
		int j = i;		// i 미만은 정렬되어 있다는게 키워드임
		while(j > 0 && arr[j-1] > arr[j]){
			swap(arr[j-1], arr[j]);
			--j;
		}
	}
}
4 2 8 1	//초기
2 4 8 1 //i == 1
2 4 1 8 //i == 3, j == 3 (8, 1)비교
2 1 4 8 //i == 3, j == 2 (4, 1)비교
1 2 4 8 //i == 3, j == 1 (2, 1)비


//p117 최대 연속 부분 구간 합 문제를 푸는 무식한 알고리즘들
const int MIN = numeric_limits<int>::min();
//A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도: ON3
int inefficientMaxSum(const vector<int>& arr) {
	int n = arr.size(), ret = MIN;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			//구간A[i..j]의 합을 구한다.
			int sum = 0;
			for (int k = i; k <= j; ++k)
				sum += arr[k];
			ret = max(ret, sum);
		}
	return ret;
}
//p118 A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도 ON2
int betterMaxSum(const vector<int>& arr) {
	int n = arr.size(), ret = MIN;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += arr[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}

//분할정복 알고리즘 ONlgN: !@#1_2
int fastMaxSum(const vector<int>& arr, int lo, int hi) {
	//기저 사례: 구간의 길이가 1일 경우
	if(lo == hi) return arr[lo];
	//배열을 A[lo..mid], A[mid+1..hi]의 두조각으로 나눈다.
	int mid = (lo + hi) / 2;

	//두 부분에 모두 걸쳐 있는 최대 합 구간을 찾는다.
	//이 구간은 A[i..mid] 와 A[mid+1..j] 형태를 갖는 구간의 합으로 이루어진다.
	
	//A[i..mid] 형태를 갖는 최대 구간을 찾는다.
	int left = MIN, right = MIN, sum = 0;
	for(int i = mid; i >= lo; --i) {
		sum += arr[i];
		left = max(left, sum);
	}
	//A[mid+1..j] 형태를 갖는 최대 구간을 찾는다.
	sum = 0;
	for(int j = mid+1; j <= hi; ++j) {
		sum += arr[j];
		right = max(right, sum);
	}
	//최대 구간이 두 조각 중 하나에만 속해 있는 경우의 답을 재귀 호출로 찾는다.
	int single = max(fastMaxSum(arr, lo, mid),
					 fastMaxSum(arr, mid+1, hi));
	//두 경우 중 최대치를 반환한다.
	return max(left + right, single);
}


//p119 : 동적 계획법 : 
"점화식 : maxAt(i) = max(0, maxAt(i-1)) + A[i] "//!!!!
//maxAt(i) : i번째 원소를 포함하는 구간의 최대값임
//A[i]에서 끝나는 최대 합 부분 구간은 
//항상 A[i](A[0..i-1] 구간의 오른쪽 부분 유계들의 합이 음수인 경우) 이거나
//A[i-1]에서 끝나는 최대 합 부분 구간에 A[i]가 더해진거임
int fastestMaxSum(const vector<int>& arr){
	int n = arr.size(), ret = MIN, psum = 0;
	for(int i = 0; i < n; ++i) {
		psum = max(0, psum) + arr[i];//i번째 원소를 포함하는 [0..i] 중 일부 구간의 최대값
		ret = max(ret, psum);//전체 중 구간 최대값
	}
	return ret;
}
//통과함, 이게 더 이해하기 편함
int main() {
	int cs; cin >> cs; 
	rep(cc, cs) {
		int n; cin >> n;
		vector<int> arr(n);
		rep(i, n) cin >> arr[i];
		vector<int> dp(n, 0);
		int sol = dp[0] = arr[0];
		rep2(i, 1, n) {
			dp[i] = (dp[i - 1] > 0) ? dp[i - 1] : 0;
			dp[i] += arr[i];
			sol = max(sol, dp[i]);
		}
		cout << sol << endl;
	}
	return 0;
}

//p131 이진탐색
//필수 조건 : A는 오름차순으로 정렬되어 있다.
//결과 : A[i-1] < x <= A[i] 인 i를 반환한다.
//이때 A[-1] = 음의 무한대, A[n] = 양의 무한대라고 가정한다.
int binsearch(const vector<int>& arr, int x) {
	int n = arr.size();
	int lo = -1, hi = n;
	//반복문 불변식 1: lo < hi
	//반복문 불변식 2: A[lo] < x <= A[hi]
	//(*)불변식은 여기서 성립해야 한다.
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		if(arr[mid] < x)
			lo = mid;
		else
			hi = mid;
		//(**)불변식은 여기서도 성립해야 한다.
	}
	return hi;	// x값 이상을 가지는 인덱스를 리턴
}

//p133 불변식 추가한 삽입정렬 알고리즘
void insertionSort(vector<int>& arr) {
	for(int i = 0; i < arr.size(); ++i) {
		//불변식 a: A[0..i-1]은 이미 정렬되어 있다.
		//A[0..i-1] 에 A[i]를 끼워넣는다.
		int j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			//불변식 b: A[j+1 .. i]의 모든 원소는 A[j] 보다 크다.
			//불변식 c: A[0..i] 구간은 A[j]를 제외하면 정렬되어 있다.
			swap(arr[j-1], arr[j]);
			--j;
		}
	}
}

//p147 1부터 n까지의 합을 계산하는 재귀함수
//필수조건 : n >= 1
int recursiveSum(int n) {
	if(n == 1) return 1;
	return n + recursiveSum(n-1);
}

//p148 n개의 원소 중 네개를 골라 모두 출력하는 코드(조합)   
ex) 6C4 = (6 * 5 * 4 * 3) / (4 * 3 * 2 * 1) 
for(int i = 0; i < n; ++i)					//0, 1, 2 선택가능
	for(int j = i+1; j < n; ++j)			//1, 2, 3 선택가능
		for(int k = j+1; k < n; ++k)		//2, 3, 4 선택가능
			for(int l = k+1; l < n; ++l)	//3, 4, 5 선택가능
				cout << i << " " << j << " " << k << " " << l << endl;
//위 코드의 단점은 유연성이 없다는거.. 만약 5개 혹은 6개 혹은 m개의 임의의 원소를 고르도록 한다면 우짜노...ㅠㅠ

//p149 n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘: !@#1_3
//n: 전체 원소의 수
//picked: 지금까지 고른 원소들의 번호
//toPick: 더 고를 원소의 수
void pick(int n, vector<int>& picked, int toPick) {
	//기저 사례: 더 고를 원소가 없을 때 고른 원소들을 출력한다.
	if(toPick == 0) {printPicked(picked); return; }

	//고를 수 있는 가장 작은 번호를 설정한다.
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	//원소를 하나씩 고른뒤 재귀탄다.
	for(int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick -1);
		picked.pop_back();
	}
}

//p152 보글 게임판에서 단어를 찾는 재귀 호출 알고리즘
const int dx[8] = { -1, -1, -1,  1, 1, 1,  0, 0 };
const int dy[8] = { -1,  0,  1, -1, 0, 1, -1, 1 };
//5X5 의 보글 게임판의 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string& word) {
	//기저 사례1: 시작 위치가 범위 밖이면 무조건 실패
	if(!inRange(y, x)) return false;
	//기저 사례2: 첫 글자가 일치하지 않으면 실패
	if(board[y][x] != word[0]) return false;
	//기저 사례3: 단어 길이가 1이면 성공 : 왜냐 첫글자는 일치하므로 마지막 글자까지 일치하는게 되므로
	if(word.size() == 1) return true;

	for(int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction];
		int nextX = x + dx[direction];
		//다음 칸이 범위 안에 있는지, 첫 글자는 일치하는지 확인할 필요가 없다.
		if(hasWord(nextY, nextX, word.substr(1)) )
			return true;
	}
	return false;
}

//p158 소풍 문제를 해결하는 재귀 호출코드 //!!!! imagine: !@#1_4
//학생수(짝수) 친구관계 정보가 주어졌을때 친구끼리 짝을 지어주는 경우의 수를 구하라
int n; //학생수
bool areFriend[10][10];
//taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10]) {
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for(int i = 0; i < n; ++i)
		if(!taken[i]) {
			firstFree = i;
			break;
		}

	//기저사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if(firstFree == -1) return 1;
	int ret = 0;
	//이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith )
		if(!taken[pairWith] && areFriend[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	return ret;
}
고찰
a-b c-d
b-a c-d 
따로 세는 경우는 없다. ff가 7인 경우 7보다 앞의 숫자가 pairWith로 선택될수는 없기 때문이다 !!!

"bitmask dp" 통과확인
int n;
bool bFriend[10][10];
int cache[1 << 10];
int cntPair(int taken) {
	if (taken == (1 << n) - 1) return 1;
	int& ret = cache[taken];
	if (ret != -1) return ret;
	ret = 0;
	int u = -1;
	rep(i, n) if ((taken & (1 << i)) == 0) { u = i; break; }
	for (int v = u + 1; v < n; ++v)
		if (bFriend[u][v] && !(taken & (1 << v))) {
			taken += (1 << u) + (1 << v);
			ret += cntPair(taken);
			taken -= (1 << u) + (1 << v);
		}
	return ret;
}



//p163 게임판 덮기 문제 ㄱ 모양으로 덮어간다. 흰색은 없이 완전히 덮어야 한다. : !@#1_5
//주어진 칸을 덮을 수 있는 네가지 방법
//블록을 구성하는 세 칸의 상대적 위치(dy, dx)의 목록.. 주의하삼 y가 앞에 온다.(y, x)임
const int coverType[4][3][2] = {
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },	//r
	{ { 0, 0 }, { 0, 1 }, {	1, 1 } },	//ㄱ
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },	//ㄴ
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } },	//_I
};
//board의 (y, x)를 type번 방법으로 덮거나 덮었던 블록을 없앤다.
//delta = 1이면 덮고, -1이면 덮었던 블록을 없앤다.
//만약 블록이 제대로 덮이지 않은 경우 (게임판 밖으로 나가거나,
//겹치거나, 검은 칸을 덮을 때) false를 반환한다.
bool set(vector<vector<int> >& board, int y, int x, int type, int delta) {
	bool ok = true;
	for(int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size() )
			ok = false;
		else if((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}
//board의 모든 빈칸을 덮을 수 있는 방법의 수를 반환한다.
//board[i][j] = 1 이미 덮인칸 혹은 검은 칸
//board[i][j] = 0 아직 덮이지 않은 칸
int cover(vector<vector<int> >& board) {
	//아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1, x = -1;
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[0].size(); ++j) {
			if(board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1) break;

	}
	//기저 사례: 모든 칸을 채웠으면 1을 반환한다.
	if(y == -1) return 1;
	int ret = 0;
	for(int type = 0; type < 4; ++type) {
		//만약 board[y][x]를 type 형태로 덮을 수 있으면 재귀 호출한다.
		if(set(board, y, x, type, 1))
			ret += cover(board);
		//덮었던 블록을 치운다.
		set(board, y, x, type, -1);
	}
	return ret;
}
//2중 벡터 크기 설정
vector<vector<int> > board(height, vector<int>(width, 0));
//특정 가로줄에서 0인 개수 세기
count(board[i].begin(), board[i].end(), 0);
//main 참고용
int main() {
  int cases;
  cin >> cases;
  for(int cc = 0; cc < cases; ++cc) {
    int height, width;
    cin >> height >> width;
    assert(1 <= height && height <= 20);
    assert(1 <= width && width <= 20);
    vector<vector<int> > board(height, vector<int>(width, 0));	//중요코드 stl활용
    int whites = 0;
    for(int i = 0; i < (height); i++) {
      string s;
      cin >> s;
      for(int j = 0; j < (width); j++) {
        if(s[j] == '#')
          board[i][j] = 1;
      }
      whites += count(board[i].begin(), board[i].end(), 0);		//중요코드 stl활용
    }
    assert(whites <= 50);
    int ways = cover(board);
    cout << ways << endl;
  }
}

//p167 여행하는 외판원 문제를 해결하는 재귀 호출 알고리즘 (단순 무식한 방법)
int n; //도시의 수
double dist[MAX][MAX]; //두 도시간의 거리를 저장하는 배열
//path: 지금까지 만든 경로
//visited: 각 도시의 방문 여부
//currentLength: 지금까지 만든 경로의 길이
//나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다.
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	//기저 사례: 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
	if(path.size() == n)
		return currentLength + dist[path[0]][path.back()]; //시작도시로 돌아가야 되니까
	double ret = INF; //매우 큰 값으로 초기화
	//다음 방문할 도시를 전부 시도해 본다.
	for(int next = 0; next < n; ++ next) {
		if(visited[next]) continue; //이미 방문한 곳이면 무시
		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		//나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는다.
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}


-----------------------------
    cin >> n;
    vector<double> y(n), x(n);
    for(int i = 0; i < n; i++)
      cin >> y[i] >> x[i];
    REP(i,n) REP(j,n) dist[i][j] = hypot(y[i] - y[j], x[i] - x[j]);


	vector<bool> visited(n, false);
    visited[0] = true;
    vector<int> path(1, 0);
    printf("%.15lf\n", shortestPath(path, visited, 0)); 
	//시작지점을 0번 도시에서 하고 있음 : 
	//사실 되돌아 와야 하므로 시작지점은 어딜되든 상관은 없네요.
------------------------------

-----------------------------
#include<cstdio>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//!@#1_7
// factorials[i] = i!
int factorials[12];
// perm 이 [0..n-1] 의 permutation 일 때 사전순 번호를 반환한다. (0에서 시작)
int getIndex(const vector<int>& perm) {
	int ret = 0;
	for(int i = 0; i < perm.size(); ++i) {
		int less = 0;
		for(int j = i+1; j < perm.size(); ++j) {
			if(perm[i] > perm[j])
				++less;
		}
		ret += factorials[perm.size()-i-1] * less;
	}
	return ret;
}
foctorial[0] = 1;
factorial[1] = 1;
factorial[2] = 2;
factorial[3] = 6;...
3! = 총 6가지
			 i = 0   i = 1
1 2 3 => 0 : 0 * 2 + 0 * 1
1 3 2 => 1 : 0 * 2 + 1 * 1
2 1 3 => 2 : 1 * 2 + 0 * 1
2 3 1 => 3 : 1 * 2 + 1 * 1
3 1 2 => 4 : 2 * 2 + 1 * 0
3 2 1 => 5 : 2 * 2 + 1 * 1


981234567 = 8! * 8 + 7! * 7  
// 뒤에수가 자신보다 작은 경우 swap 한다음 현 위치 다음을 순열로 매긴다
// 그 놈들 갯수를 새는 것이다.
맨앞 9의 경우 8개의 swap 후보가 있고 그때마다의 순열은 8!이 된다.
그 뒤 8의 경우 7개의 swap 후보가 있고 그ㅡ때마다의 순열은 7! 이 된다. !!!!!!!!

int main() {
	factorials[0] = 1;
	for(int i = 1; i < 12; ++i)
		factorials[i] = factorials[i-1] * i;
	vector<int> a;
	for(int i = 0; i < 8; ++i) a.push_back(i);
	int x = 0;
	do {
		assert(getIndex(a) == x++);
	} while(next_permutation(a.begin(), a.end()));
	printf("checked %d permutations\n", x);
}
/-------------------------------------------------------

--------------------------7장 분할정복-------------------------
//p177 1부터 n까지의 합을 구하는 분할 정복 알고리즘
//필수 조건: n은 자연수
int fastSum(int n) {
	//기저사례
	if(n == 1) return 1;
	if(n % 2 == 1) return fastSum(n-1) + n;
	return 2 * fastSum(n/2) + (n/2)*(n/2);
}

//179 행렬의 거듭제곱을 구하는 분할 정복 알고리즘
//정방행렬을 표현하는 SquareMatrix 클래스가 있다고 가정하자
class SquareMatrix;
//n*n 크기의 항등 행렬(identity matrix)을 반환하는 함수
SquareMatrix identity(int n);

//A^m을 반환한다.
SquareMatrix pow(const SquareMatrix& A, int m) {
	if(m == 0) return identity(A.size());
	if(m % 2 > 0) return pow(A, m-1) * A;
	
	SquareMatrix half = pow(A, m/2);
	return half * half;
}
pow(A, 8)
	pow(A, 4)
		pow(A, 2)
			pow(A, 1)
				pow(A, 0)
				ret identity
			ret identity * A
		ret A * A
	ret A^2 * A^2
ret A^4 * A^4

카라츠바의 빠른 정수 곱셈 알고리즘은 생략합니다. 책 설명이 더 잘되어 있으니 참고 바람


!@#1_8
입력
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
출력
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb

예시 그림
4 by 4 
xxwwwbwwb	: // 사이즈가 4임
wwww
wbww
wwbb
wwbb
"상하 반전"  : xwbxwbwww
wwbb
wwbb
wbww
wwww

"이걸보고 상하반전된놈을 imagine 하니 이해가 쉽네 !!!!"
decompress(x, 0, 0, 4)
	decompress(x, 0, 0, 2)
		decompress(w, 0, 0, 1)
		decompress(w, 0, 1, 1)
		decompress(w, 1, 0, 1)
		decompress(b, 1, 1, 1)
	decompress(w, 0, 2, 2)
	decompress(w, 2, 0, 2)
	decompress(b, 2, 2, 2)
//p193 쿼드 트리 압축을 해제하는 재귀 호출 알고리즘(board의 크기를 알고 있어야 하는 단점이 있다)
char decompressed[MAX_SIZE][MAX_SIZE];	//decompd
void decompress(string::iterator& it, int y, int x, int size) {	//decomp
	//한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
	char head = *(it++);
	//기저사례: 첫 글자가 b 또는 w인 경우
	if(head == 'b' || head == 'w')
		for(int dy = 0; dy < size; ++dy)
			for(int dx = 0; dx < size; ++dx)
				decompressed[y+dy][x+dx] = head;
	else{
		int half = size/2;
		decompress(it, y, x, half);
		decompress(it, y, x+half, half);
		decompress(it, y+half, x, half);
		decompress(it, y+half, x+half, half);
	}
}
//p194 쿼드 트리 뒤집기 문제를 해결하는 분할 정복 알고리즘
string reverse(string::iterator& it) {
	char head = *it;
	++it;

	if(head == 'b' || head == 'w')
		return string(1, head);	//이야 이게 되네요..string 생성자에서 이게 되다니...!!!!
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string downLeft = reverse(it);
	string downRight = reverse(it);

	return string("x") + downLeft + downRight + upperLeft + upperRight;  //중요코드 string("x")
}

// 내코드... 좀 지저분하네...
string str;
string rec(int& here) {
	if (str[here] == 'x') {
		here++;
		string arr[4];
		for (int i = 0; i < 4; ++i) {
			if (str[here] == 'x')
				arr[i] = rec(here);
			else {
				arr[i] = str.substr(here, 1);
				here++;
			}
		}
		return string("x") + arr[2] + arr[3] + arr[0] + arr[1];
	}
	else //기저( b, w )
		return str.substr(here, 1);
}
int main() {
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> str;
		int here = 0;
		string sol = rec(here);
		cout << sol << endl;
	}
	return 0;
}

//p197 판자의 높이를 담은 배역 h[]가 주어질 때 사각형의 최대 너비를 반환한다. 무식한 방법
int bruteForce(const vector<int>& h) {
	int ret = 0;
	int n = h.size();

	//모든 left height 조합을 순회한다.
	for(int left = 0; left < n; ++left) {
		int minHeight = h[left];
		for(int right = left; right < n; ++right) {
			minHeight = min(minHeight , h[right]);
			ret = max(ret, minHeight * (right-left+1) );
		}
	}
	return ret;
}
//p199 판자의 높이를 담은 배열 h[]가 주어질 때 : !@#1_9
//사각형의 최대 너비를 반환하는 분할정복알고리즘
//각 판자의 높이를 저장하는 배열
vector<int> h;
//h[left..right] 구간에서 찾아낼 수 있는 가장 큰 사각형의 넓이를 반환한다.
int solve(int left, int right) {
	//기저 사례: 판자가 하나밖에 없는 경우
	if (left == right) return h[left];

	//[left,mid], [mid+1,right] 두 구간으로 문제를 분할한다.
	int mid = (left+right) / 2;
	//분할한 문제를 각개격파(부분문제1, 부분문제2)
	int ret = max(solve(left, mid), solve(mid+1, right) );

	//부분문제3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);

	//[mid, mid+1] 만 포함하는 너비 2인 사각형을 초기값으로 고려한다.
	ret = max(ret, height*2);

	//사각형이 입력 전체를 덮을 때까지 확장해 나간다.
	while(left < lo || hi < right) {  
		"좋은 비교 구문이다. 중간에서 분활 확장 방식, 분활정복에서 많이 볼수 있는 형태이다."
		//항상 높이가 더 높은 쪽으로 확장해 나간다 : 핵심임
		if(hi < right && (lo == left || h[lo-1] < h[hi+1])) {  //오른쪽으로 확장하는 경우 조건
			//1조건 : 오른쪽으로 갈 공간이 있어야 함
			//2.1 조건 : 왼쪽이 다 갔음 or
			//2.2 조건 : 왼쪽보다 오른쪽이 더 큼
			++hi;
			height = min( height, h[hi]);
		}else {
			--lo;
			height = min( height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1) );
	}
	return ret;
}

//p205 알고리즘 카라츠바 연관이라 추후 공부

//p185 카라츠바 알고리즘: !@#1_10
"곱셈의 복잡도는 n^2 이다 
"카라츠바의 복잡도는 n^1.585 이다
//a: 256자리, b: 256자리
a * b = (a1 * 10^128 + a0) * (b1 * 10^128 + b0)
	  = a1 * b1 * 10^256 + (a1 * b0 + a0 * b1) * 10^128 + a0 * b0
"이것만 가지곤 복잡도는 그대로일뿐"
허나
//a1 * b1:				z2
//a1 * b0 + a0 * b1:	z1
//a0 * b0:				z0
//라 할때 z1은 128자리 곱셈을 두번안하고 구할수 있다!!!!
(a0 + a1) * (b0 + b1) = a0 * b0		+	a1 * b0 + a0 * b1	+	a1 * b1
여기에다가 z0, z2를 빼면 z1이 구해진다.
즉 이런거다.
"z1 = (a0 + a1) * (b0 + b1) - z0 - z2;"	
128자리 곱셈이 세번으로 줄어든다. 뭐 정확히는 129자리가 만들어 질수도 있다만...
// 아니 ㅅㅂ (a0 + a1) * (b0 + b1) 자체를 구해야 되는데 이게 무슨 염병이냐...
// 와따 욕하니까 다시 정상기억이 난다.
" 여기서 a0 , a1, b0, b1 은 각각 128 자리의 수임다.!!!!"

a * b =					a1 * b1 * 10000 * 10000		+	(a1 * b0 + a0 * b1) * 10000		+	a0 * b0
17283323 * 12489832 =	1728*1248 * 10000*10000		+	(1728*9832 + 3323*1248)*10000	+	3323*9832 
	z2 = 1728 * 1248	4*4 복잡도	// 2156544
	z0 = 3323 * 9832	4*4 복잡도	// 32671736
	z1 = (1728*9832 + 3323*1248)	4*4 복잡도 * 2 = 32 // 32 -> 16 으로 줄일수 있다!!!!!!!!

	z1 의 복잡도를 4*4에 가깝게 할 수 있다.
	(1728+3323) * (1248+9832) - z2 - z0 = (5051) * (11080) - 2156544 - 32671736 = 21136800

	2156544 * 10000 * 10000 + 21136800 * 10000 + 32671736 = 215865800671736 // 오오 실제 계산 결과랑 같네


//p187 카라츠바의 빠른 정수 곱셈 알고리즘 구현
// a += b * (10^k);를 구현한다.
void addTo(vector<int>& a, const vector<int>& b, int k);
// a -= b;를 구현한다. a >= b를 가정한다.
void subFrom(vector<int>& a, const vector<int>& b);

//두 긴 정수의 곱을 반환한다.
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	// a가 b보다 짧을 경우 둘을 바꾼다.
	if (an < bn) return karatsuba(b, a);
	// 기저 사례: a나 b가 비어있는 경우
	if (an == 0 || bn == 0) return vector<int>();
	// 기저 사례: a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다.
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	// a와 b를 밑에서 half 자리와 나머지로 분리한다.
	// 뒷인뎃스일수록 높은 자리를 나타냄
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	// z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);
	// z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	// a0 = a0 + a1;	b0 = b0 + b1;
	addTo(a0, a1, 0);	addTo(b0, b1, 0);
	// z1 = (a0 * b0) - z0 - z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	// ret = z0 + z1 * 10^half + z2 * 10^(half * 2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}


#include<cassert>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int DIGITS = 4;
const int BASE = 10000;
// num[] 의 자릿수 올림을 처리한다.
void normalize(vector<int>& num) {	//좋은 코드다
	num.push_back(0);
	// 자릿수 올림을 처리한다.
	//for (int i = 0; i < num.size(); ++i) {	//!!!! 첨부 소스 돌려보니 인덱스 오버나서 죽음
	for (int i = 0; i < num.size() - 1; ++i) {
		if (num[i] < 0) {	
			//num[0] = -13, num[1] = 10 인 경우 시뮬하면 알수 있음
			int borrow = (abs(num[i]) + 9) / 10;	//이경우 borrow = 2
			num[i + 1] -= borrow;					//num[1] 은 8이 됨
			num[i] += borrow * 10;					//num[0]에 20을 더해서 7
			//즉 87이 된다.

			//num[0] = -13, num[1] = 0 인 경우
			//망한다만 애초 이 함수를 호출하는건 num이 의미하는게 0 이상이어야 가능
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	//if (num.back() == 0) num.pop_back(); //최상단 자리가 쓸모 없으면 제거
	while (num.size() > 1 && num.back() == 0)		// 아래 multiply 에서 쓸모없는 0들이 추가가 많이 됨. 여기서 처리
		num.pop_back();
	//https://jaimemin.tistory.com/308
}
// 두 긴 정수의 곱을 반환한다. 각 배열에는 각 수의 자리수가 1의 자리에서부터 시작해 저장되어 있다.
// 예: multiply({3,2,1},{6,5,4}) = 123*456 = 56088 = {8,8,0,6,5}
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);	// 이러면 0이 더 많이 생성됨. 추함.
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
	normalize(c);
	return c;
}
// a += b * (10 ^ k); 를 구현한다
void addTo(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); ++i) a[i + k] += b[i];
	normalize(a);
}
/*	//resize할시 일부 원래값 그대로 가짐 !!!!
	vector<int> myarr = { 1,2,3,4,5 };
	myarr.resize(3);	// { 1, 2, 3 }
	myarr.resize(7);	// { 1, 2, 3, 0, 0, 0, 0 }
*/
//a -= b; 를 구현한다. a >= b 를 가정한다.
void subFrom(vector<int>& a, const vector<int>& b) {
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < b.size(); ++i) a[i] -= b[i];
	normalize(a);
}
// 두 긴 정수의 곱을 반환한다.
// 음수끼리의 곱은 지원 안한다. 음수 처리는 외부에서 해라
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	// a가 b보다 짧을 경우 둘을 바꾼다.
	if (an < bn) return karatsuba(b, a);
	// 기저 사례: a나 b가 비어 있는 경우
	if (an == 0 || bn == 0) return vector<int>();
	// 기저 사례: a 가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다.
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	// a 와 b 를 밑에서 half 자리와 나머지로 분리한다.
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));	//b.begin() + b.size() == b.end()
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());	//b1(b.end(), b.end()) //빈백터!!!!
	// z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);
	// z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	// a0 = a0 + a1;	b0 = b0 + b1;
	addTo(a0, a1, 0);	addTo(b0, b1, 0);
	// z1 = (a0 * b0) - z0 - z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	// ret = z0 + z1 * 10^half + z2 * 10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}
string toString(vector<int> a) {
	string ret;
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	for (int i = 0; i < a.size(); ++i)
		ret += char('0' + a[a.size() - 1 - i]);	//맨 큰자리가 앞에 오도록 함
	return ret;
}
vector<int> fromString(const string& s) {
	vector<int> ret;
	for (int i = 0; i < s.size(); ++i)
		ret.push_back(s[i] - '0');
	reverse(ret.begin(), ret.end());	//맨 큰자리가 뒤쪽인덱스(큰인덱스)로 감
	return ret;
}
"프로젝트 - 속성 - 디버깅 - 명령인수 편집: karatsuba !!!!"
int main(int argc, char* argv[]) {
	string a, b;
	int cc = 0;
	while (cin >> a >> b) {
		if (argc == 2 && strcmp(argv[1], "karatsuba") == 0) {
			vector<int> aa = fromString(a);
			vector<int> bb = fromString(b);
			vector<int> sol = karatsuba(aa, bb);//400자리 두개 곱해도 많아봐야 쓸모없는 '0' 2개 옴
												//그뒨 길이가 2배가 될때마다 '0'이 추가될 수 있음
												//뭐 999.... 끼리의 곱은 무조건 0이 하나겠지만..
			cout << toString(karatsuba(aa, bb)) << endl;
		}
		else
			cout << toString(multiply(fromString(a), fromString(b))) << endl;
		fprintf(stderr, "%d ..\n", ++cc);	//으응? 
		//그냥 printf("%d ..\n", ++cc);랑 동일하다 보면 됨(맛이 가도 출력해준다는 점만 빼고)
	}
}
//----------------------------------------------------------------------//
void nor(vi& num) {	//좋은 코드다
	num.pb(0);
	rep(i,num.size() - 1) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;	//상위 자리로 부터 빌려오기
			num[i] += borrow * 10;
		} else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	//if (num.back() == 0) num.pop_back();
	while (num.size() > 1 && num.back() == 0)		// 아래 multiply 에서 쓸모없는 0들이 추가가 많이 됨. 여기서 처리
		num.pop_back();
}
vi mul(cvi& a, cvi& b) {
	vi c(a.size() + b.size() + 1, 0);	//솔직히 +1은 필요 없다고 봄
	rep(i,a.size()) rep(j,b.size()) c[i + j] += a[i] * b[j]; nor(c); return c;
}
void addTo(vi& a, cvi& b, int k) {
	a.resize(max(a.size(), b.size() + k));	rep(i,b.size()) a[i + k] += b[i];	nor(a);
}
void subFrom(vi& a, cvi& b) {
	a.resize(max(a.size(), b.size()) + 1);	rep(i,b.size()) a[i] -= b[i];	nor(a);
}
vi karatsuba(cvi& a, cvi& b) {
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vi();
	if (an <= 50) return mul(a, b);
	int half = an / 2;
	vi	a0(a.begin(), a.begin() + half);
	vi	a1(a.begin() + half, a.end());
	vi	b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vi	b1(b.begin() + min<int>(b.size(), half), b.end());
	vi z2 = karatsuba(a1, b1);	vi z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);	addTo(b0, b1, 0);
	vi z1 = karatsuba(a0, b0);	//a0*b0 + (a0 * b1 + a1 * b0) + (a1*b1)
	subFrom(z1, z0);	subFrom(z1, z2);
	vi ret;
	addTo(ret, z0, 0);	addTo(ret, z1, half);	addTo(ret, z2, half + half);
	return ret;
}

string toString(vi a) {
	string ret;
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	rep(i,a.size()) ret += char('0' + a[a.size() - 1 - i]);
	return ret;
}
vi fromString(const string& s) {
	vi ret;
	rep(i,s.size()) ret.pb(s[i] - '0');
	reverse(ret.begin(), ret.end());
	return ret;
}
int main(int argc, char* argv[]) {
	string a, b;
	int cc = 0;
	while (cin >> a >> b) {
		if (argc == 2 && strcmp(argv[1], "karatsuba") == 0) {
			vi aa = fromString(a);
			vi bb = fromString(b);
			vi sol = karatsuba(aa, bb);
			cout << toString(sol) << endl;
		} else
			cout << toString(multiply(fromString(a), fromString(b))) << endl;
		fprintf(stderr, "%d ..\n", ++cc);
	}
}
//--------------------------------------------------------------------------//
//p205 팬미팅(상): !@#1_11
멤버 20만명, 팬 20만명
멤버와 팬은 포옹을 해야 함 허나 "남성과 남성끼린 악수함"
모든 멤버가 동시에 포옹하는 횟수는 몇번인고?
일반 복잡도 O(NM - M^2)

										A2		A1		A0
		*		B5		B4		B3		B2		B1		B0
-------------------------------------------------------------
										A2*B0	A1*B0	A0*B0
								A2*B1	A1*B1	A0*B1
						A2*B2	A1*B2	A0*B2
				A2*B3	A1*B3	A0*B3
		A2*B4	A1*B4	A0*B4
A2*B5	A1*B5	A0*B5
-------------------------------------------------------------
C7		C6		C5		C4		C3		C2		C1		C0

"Ci = A0*Bi + A1*B(i-1) + A2*B(i-2)"

A의 원소들을 reverse시킨다음 곱셈을 수행하면
"Ci = A2*Bi + A1*(Bi-1) + A0*B(i-2)"

"결론!!!!
"C[2] 부터 C[5]까지 0인 놈의 갯수를 세면 된다 0인경우 모두가 악수를 하지 않고 포옹했다는 것이 된다.

// O( n^(lg_2(3))  ) == O(n^(1.585))
//카라츠바의 빠른 곱셈을 이용해 팬미팅 문제를 해결하는 함수//팬수가 더 작은 경우 외부에서 0이 출력되도록 하자
int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i) A[i] = (members[i] == 'M');	//남자면 1, 아니면 0
	for (int i = 0; i < M; ++i) B[M - i - 1] = (fans[i] == 'M');
	// karatsuba 알고리즘에서 자리 올림은 생략한다.
	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i)
		if (C[i] == 0)
			++allHugs;
	return allHugs;
}



//----------------------------------8장 동적 프로그래밍 --------------------------//
//삼각형, 
//p209 재귀 호출을 이용한 이항 계수의 계산
int bino(int n, int r) {
	//기저 사례: n==r(모든 원소를 다 고르는 경우) or r==0(고를 원소가 없는 경우)
	if(r == 0 || n == r) return 1;
	return bino(n-1, r-1) + bino(n-1, r);
}

//p211 메모이제이션을 이용한 이항 계수의 계산
//-1로 초기화해 둔다
int cache[30][30];
int bino2(int n, int r) {
	//기저 사례
	if(r == 0 || n == r) return 1;
	//-1이 아니라면 한 번 계산했던 값이니 곧장 반환
	if(cache[n][r] != -1)
		return cache[n][r];
	//직접 계산한 뒤 배열에 저장
	return cache[n][r] = bino2(n-1, r-1) + bino2(n-1, r);
}

//p213 메모이제이션의 사용 예
//전부 -1로 초기화해 둔다.
int cache[2500][2500];
//a와 b는 각각[0, 2500) 구간 안의 정수
//반환 값은 항상 int 형 안에 들어가는 음이 아닌 정수
int someObscureFunction(int a, int b) {
	//기저 사례를 처음에 처리한다.
	if(...) return ...;
	//(a, b)에 대한 답을 구한 적이 있으면 곧장 반환
	int& ret = cache[a][b];
	if(ret != -1) return ret;

	//여기에서 답을 계산한다.
	...;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
}

//p216 외발 뛰기 문제를 해결하는 재귀 호출 알고리즘
"캐쉬 적용된거 찾아보자"
int n, board[100][100];
bool jump(int y, int x) {
	//기저 사례: 게임판 밖을 벗어난 경우
	if(y>=n || x>=n) return false;
	//목적지 도착한 경우
	if(y == n-1 && x == n-1) return true;

	int jumpSize = board[y][x];
	return jump(y+jumpSize, x) || jump(y, x+jumpSize);
}
int n, board[100][100];
int cache[100][100];
int jump2(int y, int x) {
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	int jumpSize = board[y][x];
	return ret = (jump2(y + jumpSize, x) ||
				  jump2(y + jumpSize, x + jumpSize));
}

//p221 와일드 카드 문제 종료하는 경우의 수: 
1. s[pos] 와 w[pos]의 일반문자가 대응되지 않는다: 
볼겂도 없이 대응 실패라는 것을 알수 있습니다.
2. w의 끝에 도달했다: 패턴에*이 하나도 없는 경우죠. 이 경우에 패턴과 문자열의 
길이가 정확히 같아야만 패턴과 문자열이 대응된다
3. s의 끝에 도달했다: 패턴은 남았지만 문자열이 이미 끝난 경우이며 
w의 남은 패턴이 전부 *로 구성된 경우에만 참이고 나머진 거짓
4. w[pos]가 *인 경우: *가 몇 글자에 대응될지 모르기 때문에, 
0글자부터 남은 문자열의 길이까지를 순회하며 모든 가능성을 검사합니다.
이때 w의 p+1 부터를 w' 으로 하고, s의 pos+skip이후를 문자열 s'로 해서 
match(w', s')로 재귀 호출했을 때 답이 하나라도 참이면 답은 참

//p222 와일드 카드 문제를 해결하는 완전 탐색 알고리즘 !@#2_1	
//와일드 카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
//히밤 굉장히 복잡도가 높다...자식이 문자열이 100이라면 
//자식이 100개짜리라고 깊이도 100개짜리.... 100의 100승!!
bool match(const string& w, const string& s) {
	//w[pos]와 s[pos]를 맞춰나간다.
	int pos = 0;
	//와일드 카드에서 별표이거나, 비일치, 둘중 하나라도 사이즈 초과면 루프를 빠지겠군.
	while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]) )
		++pos;
	//더이상 대응할 수 없으면 왜 while 문이 끝났는지 확인한다.
	//2. 와일드 카드 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응됨
	if(pos == w.size())
		return pos == s.size();
	
	//4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
	if(w[pos] == '*')
		for(int skip = 0; pos+skip <= s.size(); ++skip)
			if(match(w.substr(pos+1), s.substr(pos+skip))) 
		//s.substr(s.size()) 인 경우 무엇이 리턴되는감 빈 문자열이 리턴됨 ""
				return true;
	//이 외의 경우에는 모두 대응되지 않는다.
	return false;
}
w: *
s: abcde
skip = 5 가 되면 pos(0) + 5 = 5 == s.size() 가 된다.
s.substr(5) 는 빈 문자열이되용

//p223 와일드 카드 동적계획
//-1은 아직 답이 계산되지 않았음요
//1은 해당 입력들이 서로 대응됨을 의미
//0은 해당 입력들이 서로 대응되지 않음을 의미
int cache[101][101];	//w의 위치, s의 위치
string W, S; //패턴과 문자열
bool matchMemoized(int w, int s) {
	//bool& ret = cache[w][s];
	int& ret = cache[w][s];
	if(ret != -1) return ret; 
	"bool 에 대입한다면 ... cout<<ret 를 하면 -1이 대입되어도 1이 출력된다"

	//W[w]와 S[s]를 맞춰나간다.
	while(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]) )
	{
		++w;
		++s;
	}
	//더 이상 대응할 수 없으면 왜 while 문이 끝났는지 확인한다.
	//2. 와일드카드 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 참
	if(w == W.size()) return ret = (s == S.size()); //!!!! 참:1, 거짓 0으로 저장됨

	//4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
	if(W[w] == '*')
		for(int skip = 0; skip+s <= S.size(); ++skip)
			if(matchMemoized(w+1, s+skip) )
				return ret = 1;
	//3. 이 외의 경우에는 모두 대응되지 않는다.
	return ret = 0;	// s가 끝났는데 와일드카드에 *이 아닌 다른 문자가 있는 경우
}

//이해하기 까다로운 부분이 존재하며 약간 느렸다. 13ms
//다른 사람 책 재귀코드는 10ms 정도 였음
int dp[101][101];
string w, s;
int n;
int solve() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep2(i, 1, w.size()) {
		rep2(j, 0, s.size()) {	// 공백 없이 알파벳 대소문자와 숫자만으로 이루어져 있음을 이용
			if (w[i] == s[j] || w[i] == '?')	//따라서 w[1] == s[0] 가 되는 케이스가 없으니 안심
				dp[i][j] = dp[i - 1][j - 1];
			else if (w[i] == '*' && dp[i - 1][j])
				//rep2(k, j - 1, s.size())	//이거 틀린거 같은데 알고스팟은 통과하네
				rep2(k,j,s.size())	//이게 맞는거임 그리고 이걸로 제출하니 10ms 나옴
					dp[i][k] = 1;
		}
	}
	return dp[w.size() - 1][s.size() - 1];
}
int main() {
	int cs; cin >> cs; 
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		cin >> w >> n;
		w = " " + w;
		vector<string> arr(n);
		rep(i, n) cin >> arr[i];
		vector<string> sol;
		rep(iter, n) {
			s = " " + arr[iter];
			int ok = solve();
			if (ok) sol.push_back(arr[iter]);
		}
		sort(sol.begin(), sol.end());	//!!!! 숫자 - 대문자 - 소문자 순으로 정렬해준다.
		rep(i,sol.size())
			cout << sol[i] << endl;
	}
	return 0;
}
//이 예시에서 *가 상대 문자가 없어도 되기에 solve의 for 문이 약간 복잡해짐 rep2(j,0,s.size()) 구문
*p*
3
help
papa
hello


//p229 삼각형 위의 최대 경로 문제를 푸는 동적 계획법 알고리즘(2)   !@#2_2	 //(1) 은 너무 잘못된 방법이라 생략함
int n, triangle[100][100];
int cache2[100][100];
//(y, x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int path2(int y, int x) {
	if(y == n-1) return triangle[y][x];

	int& ret = cache[y][x];
	if(ret != -1) return ret;

	return max( path2(y+1, x), path2(y+1, x+1) ) + triangle[y][x];
}

//p233 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘	!@#2_3
int n;
int cache[100], S[100];
//S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis2(int start) {
	int& ret = cache[start];
	if(ret != -1) return ret;
	//항상 S[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for(int next = start+1; next < n; ++next)
		if(S[start] < S[next])
			ret = max(ret, lis2(next) + 1);
	return ret;
}
int maxLen = 0;
for(int begin = 0; begin < n; ++begin)
	maxLen = max(maxLen, lis2(begin));

int lis3(int start) { //가독성이 없다고 판단하여 생략
}

//차라리 이게 더 났지
int lis2_(){
	int maxLen = 0;
	for(int begin = 0; begin < n; ++begin)
		maxLen = max(maxLen, lis2(begin));
	return maxLen;
}

//재귀 없이 dp로 lis 구하기 !!!! 재귀로 공부했던 나는 힘이 빠지네.. 재귀가 쉽다고? 풋
"쥐기네 간단하고 말야..."
초기값: dy[i] = 1;
점화식: dy[i] = MAX(dy[i], dy[j] + 1) (단, data[j] < data[i], j < i)
	vi test(7);
	vi dy(7, 1);
	test[0] = 10;
	test[1] = 20;
	test[2] = 40;
	test[3] = 30;
	test[4] = 70;
	test[5] = 50;
	test[6] = 60;
	for (int i = 1; i < 7; ++i)			//뒷숫자
		for (int j = 0; j < i; ++j)		//앞숫자
			if (test[j] < test[i] && dy[j] + 1 > dy[i])
				dy[i] = dy[j] + 1;
dy[] = {1, 2, 3, 3, 4, 4, 5}
"물론 일반적으로 dy의 끝 원소가 답이 되는건 절대 아니다. 순회해야 함.."

http://dyngina.tistory.com/16	//indexd tree(펜윅트리) 로 구하는 방법도 있음
nlgn에 lis 구하는 알고리즘
1. lower bound를 이용하기 (이상인 놈의 인덱스, cf: upper bound 초과인 놈의 인덱스)
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
2. 70 앞의 10	20 은 30이 덮어쓰더라도 엄연한 LIS 구조를 유지


"크기는 알수 있어도 10 20 30 80 90이 LIS를 이루는 수열이 되진 않습니다!!!!"
"오오!!! 각 index 대응 prnt를 구하면 LIS 자체를 구할수 있겠다!!!!" 천재~~
//이건 숫자가 중복되지 않은 경우 이용할 수 있겠다고 봄.. 맵을 이용못하니..
//(값, index)pair로 처리하면 숫자 중복도 처리 가능할듯 싶다. 그냥 index 로만 저장하면 어떨까 싶기도..
0	1	2	3	4	5	6	7
50	60	70	80	10	20	30	90
50								: prnt[50] = -1;
50	60							: prnt[60] = 50;
50	60	70						: prnt[70] = 60;
50	60	70	80					: prnt[80] = 70;
10	60	70	80					: prnt[10] = -1;
10	20	70	80					: prnt[20] = 10;	// 0
10	20	30	80					: prnt[30] = 20;	// 1
10	20	30	80	90				: prnt[90] = 80;	// 3
//수열 숫자가 중복이면 맵으로 처리하기 힘들지 
큐에 남은 가장 뒤쪽 값을 가르키는 인덱스는 4이며 q[4] = 90 임
	prnt[q[4]] = prnt[90] = 80
	prnt[80] = 70
	prnt[70] = 60
	prnt[60] = 50
	prnt[50] = -1


0	1	2	3	4	5	6	7	8	9
50	60	70	80	10	20	30	40	50	90
50										: prnt[50] = -1;
50	60									: prnt[60] = 50;
50	60	70								: prnt[70] = 60;
50	60	70	80							: prnt[80] = 70;
10	60	70	80							: prnt[10] = -1;
10	20	70	80							: prnt[20] = 10;
10	20	30	80							: prnt[30] = 20;
10	20	30	40							: prnt[40] = 30;
10	20	30	40	50						: prnt[50] = 40
10	20	30	40	50	90					: prnt[90] = 50

// 만약 중복 숫자가 존재하고 단조 증가 LIS인 경우
0	1	2	3	4	5	6	7
10	20	30	30	10	10	10	10
" prnt[key] 가 key 중복으로 힘들어짐을 확인할 수 있다.


//크기만 구하는 거 예시
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
		// 그냥 upper_bound를 쓰는게 낫다고 봄. 그럼 +1 안해도 되니까 ㅎ
//		int index = upper_bound(cp.begin(), cp.end(), test[i]) - cp.begin();
		int index = lower_bound(cp.begin(), cp.end(), test[i] + 1) - cp.begin();
		cp[index] = test[i];
	}
	cout << cp.size();
	10, 20, 20, 80, 90
	크기가 5가 된다.
//이걸 보니 아래 문제가 생각난다. 캬.!!!!
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=540&sca=30a0

lower_bound 랑 upper_bound는 이름만 다르지 실상 거의 똑같은 일을 하네!!!!
lower_bound의 경우 비교할 놈과 같은 것도 포함, 동일한게 여러개면 가장 작은 인덱스를 리턴
upper_bound의 경우 비교할 놈보다 큰것이어야 함, 동일한게 여러개면 가장 작은 인덱스를 리턴
"						 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12
	vector<int> test = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 7, 7, 9 };
	int index1 = lower_bound(test.begin(), test.end(), 4) - test.begin();	//6:  4를 가르킴
	int index2 = upper_bound(test.begin(), test.end(), 4) - test.begin();	//8:  5를 가르킴
	int index3 = lower_bound(test.begin(), test.end(), 6) - test.begin();	//10: 7을 가르킴
	int index4 = upper_bound(test.begin(), test.end(), 6) - test.begin();	//10: 7을 가르킴

	// "이상"과 "초과"의 차이

	
	//int nIdx = lower_bound(sqArr.begin(), sqArr.end(), n + 1) - sqArr.begin();	// 이하인 인덱스는 정수는 요렇게 하면됨
	//nIdx--;

	// 이하인 인덱스는 실수인 경우 어떤게 편할까.. 실수건, 정수건 상관없이 아랫게 편하네 
	int nIdx = upper_bound(sqArr.begin(), sqArr.end(), n) - sqArr.begin();
	nIdx--;
	
	통과소스
	https://www.acmicpc.net/source/8693246

const double eps = 0.0000000001;
//unordered_map<ll, deque<int>> my;
https://www.acmicpc.net/problem/14919
int main() {
	int m;
	cin >> m;
	vector<double> brr;
	double bi;
	while(cin >> bi) {
		brr.push_back(bi);	// 부동소수점 소수점 6자리까지 표현되어 있다.
	}
	sort(brr.begin(), brr.end());
	double segStart = 0;
	double segEnd = 0;
	for (int i = 0; i < m; ++i) {
		// segStart <= x < segEnd 인 x의 갯수를 구하라.
		segStart = (double)1.0 * i / m;			
		segEnd = (double)1.0 * (i + 1) / m;
		int idxBegin	= lower_bound(brr.begin(), brr.end(), segStart - eps) - brr.begin();
		int idxEnd = lower_bound(brr.begin(), brr.end(), segEnd - eps) - brr.begin() - 1;
		cout << idxEnd - idxBegin + 1 << " ";
	}
	return 0;
}

// 소수점 6자리임을 이용하는 방식도 좋다. // 입력은 0.32123 이런식임
	while (cin >> f) {
		int n = 0, off=100000;
		for (int i = 2; i < f.length(); i++) {
			n += (f[i] - '0')*off;
			off /= 10;
		}
		...
	}


// lis 문제 나오는 경우 정리. 
1. 중복숫자 없음, 증가 lis 구하라 (크기, 수열)
2. 중복숫자 존재, 증가 lis 구하라 (크기, 수열)
3. 중복숫자 없음, 단조 증가 lcs 구하라. // 이 케이스는 1번 케이스로 보면 됨
4. 중복숫자 존재, 단조 증가 lcs 구하라. (크기, 수열)



//p239 합친 LIS 문제 : 생략 : 코드가 이상하다고 여김.. 기회되면 다시 보셈

//p243 원주율 외우기 문제를 해결하는 동적 계획법 알고리즘: 확장성 좋음	!@#2_5
const int INF = 987654321;
string N;
//N[a..b] 구간의 난이도를 반환한다.
//첫글자 만으로 : 난이도 1     등차수열이고 공차가 1 or -1 : 난이도 2     두 수가 번갈아 등장하면 난이도는 4
//공차가 1이 아닌 등차수열 난이도 5             그 외의 모든 난이도 : 10
int classify(int a, int b) {
	//숫자 조각을 가져온다.
	string M = N.substr(a, b-a+1); //!!!! 인덱스를 변환하여 추출하기
	//첫 글자만으로 이루어진 문자열과 같으면 난이도는 1
	if(M == string(M.size(), M[0]) ) return 1;
	//등차수열인지 검사한다.
	bool progressive = true;
	for(int i = 0; i < M.size() -1; ++i)
		if(M[i+1] - M[i] != M[1] - M[0])
			progressive = false;
	//등차수열이고 공차가 1 혹은 -1이면 난이도는 2
	if(progressive && abs(M[1]-M[0]) == 1)
		return 2;
	//두 수가 번갈아 등장하는지 확인한다.
	bool alternating = true;
	for(int i = 0; i < M.size(); ++i)
		if(M[i] != M[i%2])
			alternating = false;

	if(alternating) return 4;
	if(progressive) return 5;
	return 10;
}
int cache[10002];
//수열 N[begin..]를 외우는 방법 중 난이도의 최소 합을 출력한다.
int memorize(int begin) {
	//기저 사례: 수열의 끝에 도달했을 경우
	if(begin == N.size()) return 0;
	//메모이제이션
	int& ret = cache[begin];
	if(ret != -1) return ret;
	ret = INF;
	for(int L = 3; L <= 5; ++L)
		if(begin + L <= N.size()) "사이즈 초과되면 무한대가 된다. 즉 남은 글자가 2개 이하면 무한이된다."
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
	return ret;
}

//p250 Quantization 문제 //양자화할 때 오차 제곱의 합의 최소값을 출력한다	!@#2_6
const int INF = 987654321;
//A[]: 양자화해야 할 수열, 정렬한 상태
//pSum[]: A[]의 부분합을 저장한다. pSum[i]는 A[0]..A[i]의 합
//pSqSum[]: A[]제곱의 부분합을 저장한다. pSqSum[i]는 A[0]^2..A[i]^2의 합
int n;
int A[101], pSum[101], pSqSum[101];
//A를 정렬하고 pSum(부분합), pSqSum(제곱의 부분합)을 계산한다.
void precalc() {
	sort(A, A+n); //정렬의 이점은 ? !!!!
	"p247: 주어진 수열을 정렬하면, 같은 숫자로 양자화되는 숫자들은 항상 인접해 있다"
	pSum[0] = A[0];
	pSqSum[0] = A[0]*A[0];
	for(int i = 1; i < n; ++i) {
		pSum[i] = pSum[i-1] + A[i];
		pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
	}
}
//A[lo]..A[hi]구간을 하나의 숫자로 표현할 때 최소 오차 제곱합을 계산한다.
int minError(int lo, int hi) {
	//부분합을 이용해 A[lo]~A[hi]까지의 합을 구한다. -1을 하는 이유는 당연한거
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
	//평균을 구하고 반올림한다. : 편차의 제곱의 합이 최소가 되게 하는 수임 : 증명 p248 미분을 했음
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	//sum((A[i]-m)^2) 를 전개한 결과를 부분합으로 표현하여 최소 오차 제곱합을 계산
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1); //전개 과정 외워라!!
	return ret;
	//반올림된 평균m을 가지고 최소 오차 제곱합을 계산한다는 것이 꺼림직했다
	//하지만 두 정수중(올림, 내림)에 최소 오차 제곱합을 보장하는 것은 반올림한 정수가 됨을 깨달았다.
	//좌우대칭인 2차함수에서 기울기가 0인 지점을 기점으로 대칭이니까?
}
0, 1
m = 1 인 경우 ret = 1 - 2*1*1 + 1*1*2	= 1
m = 0 인 경우 ret = 1 - 0 + 0			= 1
0, 0.99
m = 1 인 경우 ret = 1 - 2*1*0.99 + 1 * 1 * 2 = 1 보다 약간 크다.
m = 0 인 경우 ret = 1 - 0 + 0				 = 1

int cache[101][11]; //from: 남은것에 대한 시작지점, parts: 남은것을 양자화 할 수 있는 숫자 개수
int quantize(int from, int parts) {
	//기저 사례: 모든 숫자를 다 양자화했을 때
	if (from == n) return 0;
	//기저 사례: 숫자가 아직 남았는데 더 묶을 수 없을 때 아주 큰 값을 반환한다.(중요)
	if(parts == 0) return INF;
	int& ret = cache[from][parts];
	if(ret != -1) return ret;
	ret = INF;
	//조각의 길이를 변화시켜 가며 최소치를 찾는다.
	for(int partSize = 1; from + partSize <= n; ++partSize)
		ret = min(ret, minError(from, from + partSize -1) +
						quantize(from + partSize, parts - 1));
	return ret;
}

"우와!!!!"
2, 2, 2, 2, 2
m = 3	//가상의 평균: 실제 평균이 2이지만 3으로 잡아도 식이 정상 동작하나 보자
sum = 10
sqSum = 4 * 5 = 20
ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	= 20 - 60 + 45 = 5	//(3 - 2)^2 를 5번 더한 5가 된다.
//평균 말고 다른 것들도 대입해도 정상 동작하는 구나!!!!


//p254 타일링의 수를 세는 동적 계획법 알고리즘
const int MOD = 1000000007;
int cache[101];
//2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
	//기저 사례: width 가 1이하인 경우
	if(width <= 1) return 1;
	//메모이제이션
	int& ret = cache[width];
	if(ret != -1) return ret;
	return ret = (tiling(width-2) + tiling(width-1)) % MOD;
}
tiling(n) = tiling(n-1) + tiling(n-2)
n == 1 => 1
n == 0 => 1

//p255 삼각형 위의 최대 경로의 수를 찾는 동적 계획법 알고리즘 !@#2_7
int countCache[100][100];
//path2(y, x) : y, x 지점에서 최대 경로의 합
//(y, x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수를 반환한다.
int count(int y, int x) {
	//기저 사례: 맨 아래줄에 도달한 경우
	if(y == n-1) return 1;
	//메모이제이션
	int& ret = countCache[y][x];
	if(ret != -1) return ret;
	ret = 0;
	if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
	if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
	return ret;
}

//p258 우물을 기어오르는 달팽이 문제를 해결하는 동적 계획법 알고리즘	!@#2_8
int n, m; //n일 기간동안 m미터 이상 기어오른 경우의 수를 찾자 : 1미터 가는 확률 50 프로 2미터 갈 확률 50프로
int cache[MAX_N][2*MAX_N+1]; //MAX_N이 10일때 m 이 20이라 한들
//days가 10인 순간엔 캐시 참조는 안함 즉 cache[9][18]이 최대임 //뒤의 2*MAX_N + 1은 여유잡은거네
//달팽이가 days일 동안 climbed 미터를 기어올라 왔다고 할 때,
//m일 전까지 n미터를 기어올라갈 수 있는 경우의 수
int climb(int days, int climbed) {
	//기저사례: n일이 모두 지난 경우
	if(days == n) return climbed >= m ? 1 : 0;
	//메모이제이션
	int& ret = cache[days][climbed];
	if(ret != -1) return ret;
	ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
	return ret;
}
//호출시에는 climb(0,0)로 시작한다.

//달팽이 문제에서 확률이 각각 50프로가 아니라
//비가 올 확률 75프로 : 이경우 1미터 간다, 비가 안올 확률 25프로 인 경우	!@#2_9
//점화식에서 확률을 곱한다.
//점화식 : climb2(days, climbed) = 0.75 * climb2(days+1, climbed+1) + 0.25 * climb2(days+1, climbed+2);
climb2(days, climbed) = 0.75 * climb2(days+1, climbed+1) 
						+ 0.25 * climb2(days+1, climbed+2);
	//초기화방법
	for(int i = 0; i < MAX_N; i++) {
		for(int j = 0; j < MAX_N*2+1; j++) {
			cache2[i][j] = -1;
		}
	}
double climb2(days, climbed) {
	if(days == n)
		return climbed >= m ? 1 : 0;
	double& ret = cache[days][climbed];
	if(ret >= 0) return ret;
	ret = 0.75 * climb2(days+1, climbed+1) + 0.25 * climb2(days+1, climbed+2);
	return ret;
}

//타일링 복습
const int MOD = 1000000007;
int cache[101];
int tiling(int width) {
	if(width <= 1) return 1;
	int& ret = cache[width];
	if(ret != -1) return ret;
	ret = tiling(width-1) + tiling(width-2);
	ret %= MOD;
	return ret;
}
//비대칭 타일링의 수를 구하라	!@#2_10
int asymmetric(int width) {
	if(width%2 == 1) return (tiling(width) - tiling(width/2) + MOD) % MOD;

	//int ret = 0;
	//ret = tiling(width) - tiling(width/2) - tiling(width/2-1); 
	//이러면 망함//tiling(width)가 tiling(width/2)보다 작은 경우가 존재하므로

	int ret = tiling(width);
	ret = (ret - tiling(width/2) + MOD) % MOD;
	ret = (ret - tiling(width/2-1) + MOD) % MOD;
	return ret;
}
width == 1 >> 1;
width == 0 >> 1;


//p269 폴리오미노의 수 구하기	!@#2_11
const int MOD = 10*1000*1000;
int cache[101][101];
//n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의
//정사각형을 포함하는 폴리오미노의 수를 반환한다.
//n : 남은 정사각형 수, first : 맨윗줄 정사각형 수
int poly(int n, int first) { 
	//기저 사례: n == first
	if(n == first) return 1;
	//메모이제이션
	int& ret = cache[n][first];
	if(ret != -1) return ret;

	ret = 0;
	for(int second = 1; second <= n-first; ++second) {
		int add = second + first -1;	//!!!! 상상할 수 있어야 함
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}
int main() {
    memset(cache, -1, sizeof(cache));	//!!!!여기서 한번만 하군요
	int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
        int n;
        cin >> n;
        int ret = 0;
        for(int i = 0; i < n; i++) {
			ret += poly(n, i+1);
			ret %= MOD;
		}
        cout << ret << endl;
	}
}
"dp[i][here] = sum { dp[i - here][there] * (there + here -1) } //단 there <= i - here
"dp[i][here] = 1 // i == here 기저
==> 아래로 변경
dp[i + there][there] = sum { dp[i][here] * (there + here - 1) } //i + there <= n
sol = sum { dp[총갯수][1 ~ 총갯수] }

//통과했음 21ms임.. 어떤 사람은 3ms 나왔음 (dp를 precalc로 미리 구해놓은 방식)
const int MOD = 10000000;
int dp[101][101];	//dp[i][here]: i = 현재까지 쌓은 갯수, here = 맨 위 갯수
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		memset(dp, 0, sizeof(dp));
		rep2(i, 1, n + 1) dp[i][i] = 1;	//현 갯수 == 윗(here)갯수
		rep2(i, 1, n + 1) {			//현재까지 쌓은 수
			rep2(here, 1, i + 1) {	//쌓인것중 가장 윗쪽 갯수
				rep2(there, 1, n - i + 1) {	//이 다음에 쌓을 갯수
					dp[i + there][there] += dp[i][here] * (there + here - 1);
					dp[i + there][there] %= MOD;
				}
			}
		}
		int sol = 0;
		rep2(i, 1, n + 1) {
			sol += dp[n][i];
			sol %= MOD;
		}
		cout << sol << endl;
	}
	return 0;
}


//p273 두니발 박사 탈옥 문제를 해결하는 완전 탐색 알고리즘
int n, d, p, q; //n: 마을수, d: day, p: 시작지, q: 목적지
//connected[i][j] = 마을 i, j가 연결되어 있나 여부(인접행렬)
//deg[i] = 마을 i와 연결된 마을의 개수
int connected[51][51]; 
int deg[51]; //사실 connected, deg는 50으로 해도 된다 마을의 수는 교도소 포함하여 0번부터 49번까지 50개임 : 뭐 여유를 둔다고 해야되나.
double search(vector<int>& path) {
	//기저 사례: d일이 지난 경우
	if(path.size() == d+1) { //0일에도 감옥이라는 장소가 포함되므로
		//이 시나리오가 q에서 끝나지 않는다면 무효
		if(path.back() != q) return 0.0;
		//path의 출현 확률을 계산한다.
		double ret = 1.0;
		for(int i = 0; i + 1 < path.size(); ++i)
			ret /= deg[path[i]];
		return ret;
	}
	double ret = 0;
	//경로의 다음 위치를 결정한다.
	for(int there = 0; there < n; ++there)
		if(connected[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	return ret;
}
deg[i] = accumulate(connected[i], connected[i]+n, 0) //좋은 기술이다.
printf("%.8lf", search(path)); //!!!! 좋은 기술이다

int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	cin >> n >> d >> p;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++)
    			cin >> connected[i][j];
    		deg[i] = accumulate(connected[i], connected[i]+n, 0);
			//!!!! 좋은 기술
			//accumulate(begin, end, init); init 으로 초기화 된 상태에서 각 원소들을 합하여 리턴한다.
		}
		int queries;
		cin >> queries;
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= d; j++)
				cache[i][j] = -1;
		for(int i = 0; i < queries; i++) {
			cin >> q;
			if(i) printf(" ");	//!!!! 괜찬은 방식이넹
			vector<int> path(1, p);  //원소가 1개인 경우 초기화하는 방법임 원소 수가 앞에 온다.!!
			printf("%.8lf", search(path));
			printf("%.8lf", search3(q, d));
		}
		printf("\n");
    }
}


//내가 안보고 그냥 짠거 -1로 비교해서 이상한 출력이 나온적이 있었음
//(p275 search2 와 유사하며.. 호출시 캐시를 매번 초기화 해주어야 하는 불편함이 있다.)
double search(int here, int day) {
	if(day == d) {
		if(here != q) return 0.0;
		else return 1.0;
	}
	double& ret = cache[here][day];
	//if(ret != -1) return ret;
	if(ret > -0.5) return ret; //소수형일땐 이렇게 해라.. 가끔씩 위 -1로 비교하는 코드는 버그가 났다. 지금은 확인 불가능..ㅠㅠ
	ret = 0.0;
	for(int there = 0; there < n; ++there) {
		if(connected[here][there])
		{
			ret += 1.0/deg[here] * search(there, day+1);
		}
	}
	return ret;
}

//p275 두니발 박사의 탈옥 문제를 해결하는 동적 계획법 알고리즘	:!@#2_12	
int n, d, p, q; //마을수, 지나간 날, 감옥, 목적지
//cache[][]는 -1로 초기화해 둔다.
double cache[51][101];
//connected[i][j] = 마을 i, j가 연결되어 있나 여부
//deg[i] = 마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];
//day일째에 here 번 마을에 숨어 있다고 가정하고
//마지막 날에 q번 마을에 숨어 있을 조건부 확률을 반환한다. 
// 기저는 목적지(q) 이며 거기를 기준으로 계산되어 진다.
double search2(int here, int days) {
	//기저 사례: d일이 지난 경우
	if(days == d) return (here == q ? 1.0 : 0.0);
	//메모이제이션
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(int there = 0; there < n; ++there)
		if(connected[here][there])
			ret += search2(there, days+1) / deg[here];
	return ret;
}

//p276 두니발 박사의 탈옥 문제를 해결하는 동적 계획법 알고리즘	:!@#2_13
d일 후에 각 목적지들에 있을 확률
//수식을 적어서 풀어보자.
int n, d, p, q;
double cache[51][101];
//connected[i][j] = 마을 i, j가 연결되어 있나 여부
//deg[i] = 마을 i와 연결된 마을의 개수
// 기저는 감옥(p) 이며 거기를 기준으로 계산되어 진다.
int connected[51][51], deg[51];
double search3(int here, int days) {
	//기저 사례: 0일때 : 시작지점이 감옥인지 확인한다.
	if(days == 0) return (here == p ? 1.0 : 0.0);
	//메모이제이션
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(int there = 0; there < n; ++there)
		if(connected[here][there]) //== connected[there][here]
			ret += search3(there, days-1) / deg[there];
	return ret;
}

//내가 푼거: 66ms 걸림 , 김동코드는 행렬가속은 쓰지 않았으나 36ms걸림	:!@#2_14
// 김동이 매트릭스 이용한다는걸 어찌 깨우쳤을까? 따라 잡히긋다. 안되
const int MX = 52;
int n, d, p, q;
double sol[MX][MX], base[MX][MX], tmp[MX][MX];
double deg[MX];
void mul(double a[MX][MX], double b[MX][MX]) {
	double val;
	rep(i, n) {
		rep(j, n) {
			val = 0.0;
			rep(k, n) val += a[i][k] * b[k][j];
			tmp[i][j] = val;
		}
	}
	rep(i, n) rep(j, n) a[i][j] = tmp[i][j];
}
int main() {
	int cs;  cin >> cs;
	rep(cc, cs) {
		memset(sol, 0, sizeof(sol));
		cin >> n >> d >> p;			// 마을수 , day, 감옥
		rep(i, n) {
			rep(j, n) cin >> base[i][j];
			deg[i] = accumulate(base[i], base[i] + n, 0.0);
			rep(j, n) base[i][j] /= deg[i];
		}
		rep(i, n) sol[i][i]++;
		for (; d; d /= 2) {
			if (d & 1) mul(sol, base);
			mul(base, base);
		}
		int qr; cin >> qr;
		rep(i, qr) {
			cin >> q;	// 목적지
			if (i) printf(" ");
			double hae = sol[p][q];
			printf("%.9lf", hae);
		}
		printf("\n");
	}
	return 0;
}

2
5 2 0		// 마을수, day, 감옥
0 1 1 1 0
1 0 0 0 1
1 0 0 0 0
1 0 0 0 0
0 1 0 0 0
3
0 2 4		//0.833333	0.0000000	0.1666667

8 2 3
0 1 1 1 0 0 0 0
1 0 0 1 0 0 0 0
1 0 0 1 0 0 0 0
1 1 1 0 1 1 0 0
0 0 0 1 0 0 1 1
0 0 0 1 0 0 0 1
0 0 0 0 1 0 0 0
0 0 0 0 1 1 0 0
4
3 1 2 6

//첫번째 케이스
"0" ---- "1" ---- "4"
 \
  \_____ "2"
   \
    \___ "3"

base를 잡으면 이렇다 // 하루가 지났을때 각 위치로 보면된다.
// 행 -> 열로 이동하는 확률이 표현되었다.
	 0		1		2		3		4
------------------------------------------
0	|0		1/3		1/3		1/3		0			// 0번->1번: 1/3,	0번->2번: 1/3,	0번->3번: 1/3
1	|1/2		0		0		0		1/2
2	|1		0		0		0		0
3	|1		0		0		0		0
4	|0		1		0		0		0




이 base를 거듭제곱하면
|		0		1/3		1/3		1/3		0		|			|		0		1/3		1/3		1/3		0		|	 
|		1/2		0		0		0		1/2		|			|		1/2		0		0		0		1/2		|
|		1		0		0		0		0		|	   *	|		1		0		0		0		0		|
|		1		0		0		0		0		|			|		1		0		0		0		0		|
|		0		1		0		0		0		|			|		0		1		0		0		0		|

	|	"1/6+1/3+1/3"		0		"0"		0		"1/6"		|
=	|	~					~		~		~		~			|
	|	~					~		~		~		~			|
	|	~					~		~		~		~			|
	|	~					~		~		~		~			|

0행 0열 설명; 첫번째 행렬에서 0~4로 분산되고 거기를 두번째 행렬에서
0번->0번 +	1번->0번 +	2번->0번 +	3번->0번 +	4번->0번 = "0 + 1/6 + 1/3 + 1/3 + 0"



거듭제곱 시뮬레이팅: 행렬의 13승 생각해보자 !!!!!!!! 머리속 시뮬레이텅 (base^13)
행렬의 32승으로도 시뮬레이팅 하면 좋음. (마지막만 곱함) (base^32)






https://algospot.com/judge/problem/read/COINS	: !@#2_15
우리 나라에는 10원, 50원, 100원, 500원의 네 가지 동전이 있다. 
(1원짜리와 5원짜리는 거의 안 쓰니까 없는 걸로 하지요) 
이 동전들을 이용해 110원을 거슬러 주는 방법은 몇 가지나 될까? 다음의 네 가지가 있다:

// 순서없이 동시에 주사위를 던진다고 보고 경우의 수를 구하는 문제임.
10원 짜리 11개
10원짜리 6개, 50원짜리 1개
10원짜리 1개, 50원짜리 2개
10원짜리 1개, 100원짜리 1개


금액이 커지거나 동전의 종류가 많아질 수록 이 경우의 수는 많아진다. 
동전의 종류와 금액이 주어질 때, 해당 동전들을 이용해 해당 금액을 환전하는 방법의 수를 
구하는 프로그램을 작성하라.

cf()
// 만약 순서가 존재한다고 치면 각 경우의 수는 다음과 같이 늘어난다.
10원 짜리 11개				=> "11C0": 1가지
10원짜리 6개, 50원짜리 1개	=> "7C1": 7가지
10원짜리 1개, 50원짜리 2개	=> "3C2": 3가지
10원짜리 1개, 100원짜리 1개	=> "2C1": 2가지
total = 1 + 7 + 3 + 2 = 13가지


1, 2, 3 의 합으로 표현 단 순서가 존재하는 경우로 보자.  (방법의 수를 묻는 문제)

정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

int main() {
	int dp[12];
	int cs; cin >> cs;
	rep(cc,cs) {
		memset(dp, 0, sizeof(dp));
		int n; cin >> n;
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (i >= 3)
				dp[i] += dp[i - 3];
			if (i >= 2)
				dp[i] += dp[i - 2];
			if (i >= 1)
				dp[i] += dp[i - 1];
		}
		cout << dp[n] << endl;
	}
	return 0;
}
cf()~







//내가 푼건데 통과는 하는데 ... 마음에 안든다.. 푸는데 생각도 많이 했음에도...
const int MOD = 1000000007;
int n;
int cache[5001][101];
vi arr;
int rec(int m, int idx) {
	if (m < 0) 
		return 0;
	if (m == 0) 
		return 1;	// 마지막까지 도달
	if (m != 0 && idx >= n) 
		return 0;
	int& ret = cache[m][idx];
	if (ret != -1) return ret;
	ret = 0;
	ret += rec(m, idx + 1);	// 이번숫자는 생략하자
	ret %= MOD;
	ret += rec(m - arr[idx], idx); // 이번숫자는 더하자. 자식호출에서 계속 더할수 있다.
	ret %= MOD;
	return ret;
}
int main() {
	// freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(cache, -1, sizeof(cache));
		int m, c;
		cin >> m >> c;
		n = c;
		arr.resize(c);
		rep(i, c) cin >> arr[i];
		int sol = rec(m, 0);
		cout << sol << endl;
	}
	return 0;
}

//초기 좆된 코드. 이래 짜면 좆됨
const int MOD = 1000000007;
const int MX = 5001;
long long dp[MX];
int main() {
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int m, c;
		cin >> m >> c;
		vi arr(c);
		rep(i, c) cin >> arr[i];
		//좆되는 이유: 동전이 10 + 10 + 50 과 50 + 10 + 10 을 따로 계산할 위험성이 있음
		// 동전의 종류를 외각 for로 잡고 한번 시행한 종류의 동전은 뒤에선 사용하지 않도록 해야함!!!!
		rep2(i, 1, m + 1) {
			rep(j, c) {
				if (i < arr[j]) continue;
				if (i % arr[j] != 0) continue; // 이건 또 왜 있냐.. 이부분도 문제넹..
				dp[i] += dp[i - arr[j]];
				dp[i] %= MOD;
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc,cs) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int m, c; cin >> m >> c;
		vi arr(c);
		rep(i,c) cin >> arr[i];
		rep(i,c) {		// 틀렸네.. 밑에 for 도 i를 순회함..
			rep2(i,1,m+1) {
				if (i < arr[i]) continue;
				dp[i] += dp[i - arr[j]];
				dp[i] %= MOD;
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}

// 통과한 코드: 깔끔하고 좋네.
"한가지 배웠다. 중복제거가 필요한 경우 한놈씩 처리하는 과정이 있어야 되는데
//"한번 앞의 동전이 나중에 더해지지 않도록 그 놈들은 바깥 for문으로 둬야 한다!!!!"
"어? 순서를 고려하지 않네, { 1, 1, 2 } , { 1, 2, 1 } 같은 취급이잖아 ... 이렇게 하려면
"바깥에 for를 둔다는 것만 기억해라 !!!!"

"3중 for문이 필요했다만 슬라이딩 윈도우가 매우 예술적으로 처리되었다"
"2중 배열이 필요하다만 슬라이딩 윈도우 덕에 1차원 배열로 해결됨"
" 단 그덕에 점화식 만들기가 코드를 보고 바로 할 수가 없넹..."
const int MOD = 1000000007;
int dp[5001];
int main() {
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int m, c; cin >> m >> c;	// m: 목표가격, c: 동전종류수
		vi arr(c);
		rep(i, c) cin >> arr[i];
		rep(i, c) {
			rep2(j, 1, m + 1) {
				if (j < arr[i]) continue;
				dp[j] += dp[j - arr[i]];
				dp[j] %= MOD;
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}
고찰: 점화식으로 나타내봐라..






sushi 문제랑 비슷하게 보여서 착각했다.
// 바깥에 for를 굳이 안둬도 되는거 아닌가 하고 착각 ~~~~
동전의 순서를 따진다면 이걸로 되겠지만
	위 coin "문제는 순서가 의미 없는 조합이기 때문이다 !!!!"	: !@#2_16 
const int MOD = 1000000007;
int dp[5001];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		int m, c; cin >> m >> c;	// 예산, 동전수
		vi coins(c);
		rep(i, c) cin >> coins[i];
		dp[0] = 1;
		rep2(budget, 1, m + 1) {
			int cand = 0;
			rep(i, c) {
				if (budget >= coins[i])
					cand += dp[budget - coins[i]];
			}
			cand %= MOD;
			dp[budget] = cand;
		}
		cout << dp[m] << '\n';
	}
	return 0;
}
100 4
10 50 100 500j
	
dp[100] 의 경우 9개나 발생해 버렸다... : //순서가 필요한 경우의 수를 요구하는 문제도 있으니 이것또한 기억하라
10 10 10 10 10 10 10 10 10 10 10 10
10 10 10 10 10 50
10 10 10 10 50 10
10 10 10 50 10 10
10 10 50 10 10 10
10 50 10 10 10 10
50 10 10 10 10 10
50 50
100

순서가 없는 경우 실제론 4개가 되어야 한다.

// 2차원 배열이 슬라이딩 윈도우를 이용한 1차원 배열로 풀수가 있음: 동전 점화식
dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i]];

arr[0] = 1, arr[1] = 5, arr[2] = 10

i\j		0	1	2	3	4	5	6	7	8	9	10	11	12
-1		1	0	0	0	0	0	0	0	0	0	0	0	0
0		1	1	1	1	1	1	1	1	1	1	1	1	1	// dp[0][0] = dp[-1][0] + dp[0][-1]
															// dp[0][1] = dp[-1][1] + dp[0][0]
															// dp[0][2] = dp[-1][2] + dp[0][1] = 1
															// dp[0][3] = dp[-1][3] + dp[0][2] = 1
															
1		1	1	1	1	1	2	2	2	2	2	3	3	3	// dp[1][0] = dp[0][0] + dp[1][-5] = 1
															// dp[1][1] = dp[0][1] + dp[1][-4] = 1
															// dp[1][5] = dp[0][5] + dp[1][0] = 2
															// dp[1][6] = dp[0][6] + dp[1][1] = 2
															// dp[1][10] = dp[0][10] + dp[1][5] = 3 !!!!
															
2		1	1	1	1	1	1	1	1	1	1	4	4	4	// dp[2][0] = dp[1][0] + dp[2][-10] = 1
															// dp[2][10] = dp[1][10] + dp[2][0] = 4

다시 적어봄.
// 두 차이를 잘 이해해라
void ttt1() {
	dp[0] = 1;
	int m, c; cin >> m >> c;
	vi arr(c);
	rep(i,c) cin >> arr[i];
	rep(i,c) 
		rep(j,1,m+1) {
			if (j < arr[i]) continue;
			dp[j] += dp[j - arr[i]];
			dp[j] %= mod;
		}
	cout << dp[m] << endl;
}


void ttt2() {l
	dp[0] = 1;
	int m, c; cin >> m >> c;
	vi arr(c);
	rep(i,c) cin >> arr[i];
	rep(i,1,m+1) {
		rep(j,c) {
			if (i < arr[j]) continue;
			dp[i] += dp[i - arr[j]];
			dp[i] %= mod;
		}
	}
	cout << dp[m] << endl;
}
ttt2 : 2차원 배열로 나타내기 힘듬 1차원으로 나타내면 다음과 같다.
dp[0] = 1
dp[1] = 1
dp[2] = 1
dp[3] = 1
dp[4] = 1
dp[5] = dp[4] + dp[0] = 1 + 1 = 2
dp[6] = dp[5] + dp[1] = 2 + 1 = 3	// {1,1,1,1,1,1}, {5,1}, {1,5}
dp[7] = dp[6] + dp[2] = 3 + 1 = 4	// {1,1,1,1,1,1,1}, {5,1,1}, {1,5,1}, {1,1,5}
dp[8] = dp[7] + dp[3] = 4 + 1 = 5	// {1,1,1,1,1,1,1,1}, {5,1,1,1}, {1,5,1,1}, {1,1,5,1}, {1,1,1,5}
dp[9] = dp[8] + dp[4] = 5 + 1 = 6
dp[10] = dp[9] + dp[5] + dp[0] = 6 + 2 + 1 = 9	 


//!@#2_17
sushi 문제는 ttt2 형태임. ttt1 으로도 풀수 있으나 그럴 경우 장점인 슬라이딩 윈도우를 못쓸 것이다.
ttt1 형태로 풀어보자.
int c[mx+1];
int sushi() {
	int ret = 0;
	c[0] = 0;
	for (int budget = 1; budget <= m; ++budget) {
		c[budget] = 0;
		for (int dish = 0; dish < n; ++dish)
			if (budget >= price[dish])
				c[budget] = max(c[budget], c[budget - price[dish]] + prev[dish]);
		ret = max(ret, c[budget]);
	}
	return ret;
}
int myTTT1() {
	int ret = 0;
	c[0] = 0;
	for (int dish = 0; dish < n; ++dish) {
		for (int budget = 1; budget <= m; ++budget) {
			if (budget < price[dish]) continue;
			c[budget] = max(c[budget], c[budget - price[dish]] + prev[dish]);
		}
		ret = max(ret, c[budget]);
	}
	return ret;
}


https://www.hackerrank.com/challenges/max-array-sum/problem
n이 10만개
ai 범위는 -40000 ~ 40000 이다
부분 집합 (최대 붙은 거리가 2이상) 중 합이 가장 큰 놈의 그 합을 구하라. (공집합은 없다.
int maxSubsetSum(vector<int> arr) {
    
    vector<int> dp(arr.size(), 0);
    dp[0] = max(0, arr[0]);
    for (int i = 1; i < arr.size(); ++i) {
        if (i >= 2)
            dp[i] = max(dp[i - 2] + max(0, arr[i]), dp[i - 1]);
        else 
            dp[i] = max(max(0, arr[i]), dp[i - 1]);    
    }
    // 모두가 음수인 경우에는 최대값을 리턴한다. 예외처리    
    int tmp = *(max_element(arr.begin(), arr.end()));
    if (tmp < 0)
        return tmp;
    return dp[arr.size() - 1];
}
나의 실수
// dp[here] : here 를 포함한 최대 합 으로 접근해서 망했다. 정말 많이 제출했다.

// 바로 잡은 풀이
dp[here] = [0 ~ here] 까지의 최대값
dp[here] = max(dp[here - 2] + max(0, arr[i]), dp[i - 1]);	// 현재 값을 취한 최대값, 안취한 최대값 중 max 를 선택




//-----------------------9장 동적계획법 테크닉 ------------------------------//

//p280 최대 증가 부분 수열 실제로 계산하기	//!@#2_18
int n;
int cache[101], S[100], choices[101];
//S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다. start 는 -1에서 시작함
//
//함수와 캐시가 1칸 차이나서 이해하기 힘들었다.
//3,4 수열이 있다고 하면
//lis(-1) = cache[0] = 3, 구하는 과정 lis(0) + 1 => lis(1) + 1 + 1 => 1 + 1 + 1 => 3
//lis( 0) = cache[1] = 2, 구하는 과정 lis(1) + 1 => 1 + 1 => 2 
//실제 답 출력 : cout << lis4(-1) -1 << endl; //ㅅㅂ... 가장 작은걸 앞에 추가 했기에
//빼기 1했다고 보면 되긴한데.. 너무 변태같은 소스다...
//다시 설명한다면 cache[0] 의 의미는 -1 인덱스의 음의 무한대 숫자 하나가 앞에 존재한 상태에서 최장길이 수열을 의미함

int lis4(int start) {
	int& ret = cache[start+1];
	if(ret != -1) return ret;
	//항상 S[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	int bestNext = -1;
	for(int next = start+1; next < n; ++next)
		if(start == -1 || S[start] < S[next]) {
			int cand = lis4(next) + 1;
			if(cand > ret) {
				ret = cand;
				bestNext = next;
			}
		}
	choices[start+1] = bestNext;
	return ret;
}

int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	cin >> n;
    	for(int i = 0; i < n; i++) {
    		cin >> S[i];
    	}
    	memset(cache, -1, sizeof(cache));
    	cout << lis4(-1)-1 << endl;
    	vector<int> seq;
    	reconstruct(-1, seq);
    	for(int i = 0; i < seq.size(); ++i)
    		cout << seq[i] << " ";
    	cout << endl;

    }
}
//S[start]에서 시작하는 LIS를 seq에 저장한다.
void reconstruct(int start, vector<int>& seq) {
	if(start != -1) seq.push_back(S[start]);
	int next = choices[start+1];
	if(next != -1) reconstruct(next, seq);
}

lis2(0)으로 한번에 구할수 없었던 이유
i	 0 1 2 3 4 5 6 7 8 
S[i] 9 8 7 6 5 4 1 2 3
0부터 시작하면 0임.
"최대증가수열의 길이는 6부터 시작하여 길이 3을 이룬다"

//배낭문제: !@#2_19
//p284 여행 짐 싸기 문제를 해결하는 동적 계획법 알고리즘 
int n, capacity;
int volume[100], need[100];
int cache[1001][100];
string name[100];
//캐리어에 남은 용량이 capacity일 때, item 이후의 물건들을 
//담아 얻을 수 있는 최대 절박도의 합을 반환한다.
int pack(int capacity, int item) {
	//기저 사례: 더 담을 물건이 없을 때
	if(item == n) return 0;
	int& ret = cache[capacity][item];
	if(ret != -1) return ret;
	//이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);
	//이 물건을 담을 경우
	if(capacity >= volume[item])
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

//p285 여행 짐 싸기 문제의 답 역추적
//pack(capacity, item) 이 선택한 물건들의 목록을 picked에 저장한다.
void reconstruct(int capacity, int item, vector<string>& picked) {
	//기저 사례: 모든 물건을 다 고려한 경우
	if(item == n) return;
	if(pack(capacity, item) == pack(capacity, item+1)) {
		reconstruct(capacity, item+1, picked);
	}else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item+1, picked);
	}
}
int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	cin >> items >> capacity;
    	for(int i = 0; i < items; i++) {
    		cin >> name[i] >> volume[i] >> need[i];	
			//!!!!괜히 string 을 참조할 맵을 만들지 마라 이게 깔끔
    	}
    	memset(cache, -1, sizeof(cache));

    	vector<string> picked;
    	reconstruct(capacity, 0, picked);	//!!!! 오류 안난다. 내부에서 pack호출함
    	printf("%d %d\n", pack(capacity, 0), int(picked.size()));
    	for(int i = 0; i < picked.size(); ++i)
    		printf("%s\n", picked[i].c_str());							//*******
    }
}

// 위에는 top down 방식임 : 재귀는 top down
// 아래는 botton up 방식임 : for 로 나타내면 bottom up 
// 어떤 이는 top down 은 메모이제이션이고 for 로 풀면 다이나믹 프로그래밍이라 하네...
// https://www.quora.com/What-is-the-difference-between-bottom-up-and-top-down-dynamic-programming-method
// https://www.interviewcake.com/concept/java/bottom-up : 면접대응용
// 구글에서 bottom up top down recursion 으로 검색하면 많이 나온다.
// 접근법에 따라 reconstruct 의 순서가 달라짐을 유의하자.


//i: 용량, j: 물건번호
dp[i][j] = max{	dp[i][j - 1],
				dp[i - vol[j]][j - 1] + need[j] }
==> 변경
//i: 물건번호, j: 용량
dp[i][j] = max{ dp[i - 1][j],
				dp[i - 1][j - vol[i]] + need[i] }

int n, w;
int vol[101], need[101];
int dp[101][1001];
string name[101];
vector<int> sol;
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> n >> w;
		rep2(i,1, n + 1) cin >> name[i] >> vol[i] >> need[i];
		memset(dp, 0, sizeof(dp));
		sol.clear();
		rep2(i,1 ,n + 1) {
			rep2(j, 1, w + 1) {
				dp[i][j] = dp[i - 1][j];
				if (j >= vol[i])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - vol[i]] + need[i]);
			}
		}
		int ww = w;
		for (int i = n; i >= 1; --i) {
			if (dp[i][ww] == dp[i - 1][ww]) continue;
			sol.push_back(i);
			ww -= vol[i];
		}
		cout << dp[n][w] << " " << sol.size() << endl;
		rep(i, sol.size())
			printf("%s\n", name[sol[i]].c_str());
	}
	return 0;
}

//참고!!!!
	cout << log(2.718282) << endl;		// log는 밑이 e인 자연로그다 : 	1이 출력됨
	cout << exp(log(2.718282)) << endl;	//원래대로 돌아감: 자연로그 역함수 exp

	cout << log(0.9) << endl;	//음수 출력
	cout << exp(log(0.9)) << endl;	//원래대로 잘 돌아감 

//p291 : 광학 문자 인식 문제를 해결하는 동적 계획법 알고리즘
int n, m; // n : 분류기에 의해 해석된 문장의 단어 수, m : 전체 후보 단어 수
//분류기가 반환한 문장. 단어 번호로 변환되어 있음
int R[100];
//T[i][j] = i 단어 이후에 j 단어가 나올 확률의 로그값 //단 T[m][j] 처음 시작시 j단어가 나올 확률
double T[501][501];

//M[i][j] = i 단어가 j 단어로 분류될 확률의 로그값
double M[501][501];

int choice[102][502];	//reconstruct 용
double cache[102][502]; //1로 초기화한다.

//Q[segment] 이후를 채워서 얻을 수 있는 최대 g()곱의 로그 값을 반환한다.
//Q[segment-1] == previousMatch 라고 가정한다.
double recognize(int segment, int previousMatch) {
	if(segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if(ret != 1.0) return ret; 
	// 이 문제에서 풀이법으로 확률에 자연로그를 취함
	// 상용로그랑 햇갈리지 마라. 밑이 e이다.
	// Log_e(1) => 0, Log_e(2.718282) => 1
	// cache 가 1로 세팅된 이유는 확률이 1이하이기 때문이다. 
	// 확률값이 2.718282(e)같은 큰 값을 가질 수 없다. 그래서 초기화에 이용 : 
	ret = -1e200; //log(0) = 음의 무한대에 해당하는 값
	int& choose = choice[segment][previousMatch];
	//R[segment]에 대응하는 단어를 찾는다.
	for(int thisMatch = 0; thisMatch < m; ++thisMatch) {
		//g(ThisMatch) = T(previousMatch, thisMatch) * M(thisMatch, R[segment])
		double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]]
				//   사람이 에이즈에 걸릴 확률 * 에이즈에 걸렸는데 양성반응 나올 확률
				// -------------------------------------------------------------------
					"(정상인이 양성나올 확률 + 에이즈 환자가 양성나올 확률) :		분모는 같아서 생략됨"
						+ recognize(segment+1, thisMatch);
		if(ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}
"P(Q|R) 을 최대화 해야 한다."
"P(Q|R) = P(R|Q) * P(Q)  /  P(R)" : 필요한건 P(R|Q) * P(Q) 가 된다.
"P(Q|R) : 분류기에 R이 왔을때 원문이 Q일 확률" 
"P(R|Q) : 원문 Q를 R로 분류할 확률" : M[thisM][R[seg]]
"P(Q)	: Q가 출현할 확률" : T[prevM][thisM];
"P(R)	: 분류기를 통해 R로 판정 나올 확률" //aaa가 올 확률 * R로 판정할 확률 + aab가 올 확률 * R로 판정할 확률 + ...
"P(R)은 동일하여 분모생략을 하는것을 볼수 있다." 
	: P(R) 은 어짜피 구하는것도 매우 까다롭다. sum {prevM 다음 thisM 이 나올 확률 + thisM을 R로 판단할 확률}

//p293 실제답 계산하기
//입력받은 단어들의 목록
string corpus[501];
string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if(segment < n-1)
		ret = ret + " " + reconstruct(segment+1, choose);
	return ret;
}
4개 단어 인식
recon(0,3)	I
	recon(1, ~)		am
		recon(2, ~)		a
			recon(3, ~)		boy
int main() {// n : 분류기에 의해 해석된 문장의 단어 수, m : 전체 후보 단어 수
	int queries;
	cin >> m >> queries; //원문에 출현할 수 있는 단어 수, 질의할 문장 수
	assert(m <= 1000);
	assert(queries <= 100);
	for(int i = 0; i < m; i++) {	//단어들 저장
		cin >> corpus[i];
	}
	corpus[m] = "";
	for(int i = 0; i < m; i++) {
		cin >> T[m][i];
		T[m][i] = log(T[m][i]);
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			cin >> T[i][j];
			T[i][j] = log(T[i][j]);
		}
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}
	while(queries--) {
		cin >> n;
		assert(1 <= n && n <= 100);
		for(int i = 0; i < n; i++) {
			string recognizedWord;
			cin >> recognizedWord;
			for(int j = 0; j < m; ++j)
				if(corpus[j] == recognizedWord) {
					R[i] = j;
					break;
				}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m+1; j++) {
				cache[i][j] = 1;
			}
		}
		recognize(0, m);
		//(0 : segment, m : previousMatch) 
		//최초놈은 m에서 시작함 previoustMatch 가 m이라는 뜻은 단어범위를 넘어감을 의미함
		string original = reconstruct(0, m);  
		//printf("%s\n", original.substr(0, original.size()-1).c_str()); //!!!!이상해
		//I am a bo 로 y가 잘려서 출력된다.
		printf("%s\n", original.c_str()); //이게 맞는 거임
	}
}

int n, m;// n : 분류기에 의해 해석된 문장의 단어 수, m : 전체 후보 단어 수
int R[100];	//분류기가 반환한 문장(단어 번호로 이루어짐)
double T[501][501];	//변함 확률(로그) :단 T[m][j] 처음 시작시 j단어가 나올 확률
double M[501][501];
int choice[102][502];	//recon 용
double cache[102][502];	//1로 초기화	//절대 있을수 없는 확률 log_10(10) 즉 10이므로
string corpus[501];
int main() {
	int queries;
	cin >> m >> queries;
	rep(i,m) cin >> corpus[i];
	corpus[m] = "";
	rep(i,m) { cin >> T[m][i]; T[m][i] = log(T[m][i]); }
	rep(i,m) rep(j,m) { cin >> T[i][j]; T[i][j] = log(T[i][j]); }
	rep(i,m) rep(j,m) { cin >> M[i][j]; M[i][j] = log(M[i][j]); }
	while (queries--) {
		cin >> n;
		rep(i,n) {
			string recWord; cin >> recWord;
			rep(j, m)
				if (corpus[j] == recWord) { R[i] = j; break; }
		}
		rep(i,n) rep(j,m+1) cache[i][j] = 1;
		recog(0, m);
		string origin = reconstruct(0, m);
		cout << origin << endl;
	}
}
double recog(int seg, int preM) {
	if (seg == n) return 0;
	double& ret = cache[seg][preM];
	if (ret != 1.0) return ret;
	ret = -1e200;	//-10^200 //음의 무한대표현 //로그취한거라 원본은 한없이 0에 가까움
	int& choose = choice[seg][preM];
	rep(thisM,m) {
		double cand = T[preM][thisM] + M[thisM][R[seg]] + recog(seg + 1, thisM);
		if (ret < cand) { ret = cand; choose = thisM; }
	}
	return ret;
}
string recon(int seg, int preM) {
	int choose = choice[seg][preM];
	string ret = corpus[choose];
	int maxSegIndex = n - 1;
	//if (seg < n - 1) ret = ret + " " + recon(seg + 1, choose);
	if (seg < maxSegIndex) ret = ret + " " + recon(seg + 1, choose);
	return ret;
}

"베이즈 정리: 조건부 확률 공부
암을 양성(암)이라 판정할 확률: 0.9		암을 음성(암)이라 판정할 확률: 0.1
정상을 양성(암)이라 판정할 확률: 0.1	정상을 음성(암)이라 판정할 확률: 0.9
암걸린 사람 비율: 0.01				정상인 비율: 0.99

양성반응일때 암일 확률을 구해보자
P(암|양성)	= P(암&양성) / P(양성) = 암에 걸릴 확률 * 암에 걸린 상태에서 양성일 확률 / P(양성) = 0.01 * 0.9 / P(양성)
			= P(양성&암) / P(양성) = P(양성|암) * P(암) / P(양성) = 0.9 * 0.01 / P(양성)

P(양성) = 암을 양성이라 판정할 확율 * 암걸린 사람 비율  +  정상을 양성이라 판정할 확율 * 정상인 비율
		= 0.9 * 0.01  +  0.1 * 0.99	= 0.108

"P(암|양성) = 0.9 * 0.01 / 0.108 = 0.083	즉 8.3프로가 된다.!!!!"

//알고스팟에 제출한 코드 
int n, m, qr;
int R[100];
double T[501][501];
double M[501][501];
int choice[102][502];	//choice[seg][thisM] = preM
double dp[102][502];
//dp[seg][thisM] = dp[seg - 1][preM] + T[preM][thisM] + M[thisM][R[seg]];
string my[501];
int main() {
	cin >> m >> qr;
	rep(i, m) cin >> my[i];
	my[m] = "";
	rep(i, m) { cin >> T[m][i]; T[m][i] = log(T[m][i]); }
	rep(i, m) rep(j, m) { cin >> T[i][j]; T[i][j] = log(T[i][j]); }
	rep(i, m) rep(j, m) { cin >> M[i][j]; M[i][j] = log(M[i][j]); }
	rep(qc, qr) {
		cin >> n;
		rep(i, n) {
			string ocrWord; cin >> ocrWord;
			rep(j, m)
				if (ocrWord == my[j]) { R[i] = j; break; }
		}
		rep(thisM, m) dp[0][thisM] = T[m][thisM] + M[thisM][R[0]];
		rep2(seg, 1, n) {
			rep(thisM, m) {
				dp[seg][thisM] = -1e200;
				rep(preM, m) {
					double cand = dp[seg - 1][preM] + T[preM][thisM] + M[thisM][R[seg]];
					if (cand > dp[seg][thisM]) {
						dp[seg][thisM] = cand;
						choice[seg][thisM] = preM;
					}
				}
			}
		}
		//문장 전체에 대한 가장 큰 확률을 가지는 원본후보로 역추적하자
		int selectM = -1;
		double cand = -1e200;
		rep(lastM, m) {
			if (cand < dp[n - 1][lastM]) {
				cand = dp[n - 1][lastM];
				selectM = lastM;
			}
		}
		vector<int> sol;
		sol.push_back(selectM);
		for (int seg = n - 1; seg > 0; --seg) {
			selectM = choice[seg][selectM];
			sol.push_back(selectM);
		}
		reverse(sol.begin(), sol.end());
		rep(i, sol.size()) {
			if (i) printf(" ");
			cout << my[sol[i]];
		}
		cout << endl;
	}
	return 0;
}

// 베이즈 정리 유도: 나무위키 설명좋음(조건부확률로 검색해라)
P(A1|B) = P(B^A1) / P(B) = P(B|A1)*P(A1) / P(B)

				P(B|A1) * P(A1)
		= ----------------------------------
			P(B|A1)*P(A1) + P(B|A2)*P(A2)



//p294 모든 모스 신호를 만드는 완전 탐색 알고리즘
//s: 지금까지 만든 신호
//n: 더 필요한 -의 개수
//m: 더 필요한 o의 개수
void generate(int n, int m, string s) {
	//기저 사례: n = m = 0
	if(n == 0 && m == 0) {
		cout<< s << endl;
		return;
	}
	if(n > 0) generate(n-1, m, s + "-");
	if(m > 0) generate(n, m-1, s + "o");
}

//p295 k-1개 건너뛰고 첫 번째 신호를 출력하는 알고리즘		// !@#2_21
int skip; //skip 개를 건너뛰고 출력한다. skip = 0 : 0개를 건너뜀, 최초를 바로 출력
void generate2(int n, int m, string s) {
	//기저사례: skip < 0
	if(skip < 0) return ;
	//기저사례: n = m = 0
	if(n == 0 && m == 0) {
		//더 건너뛸 신호가 없는 경우
		if(skip == 0)
			cout << s <<endl;
		--skip;
		return;
	}
	if(n > 0) generate2(n-1, m, s + "-");
	if(m > 0) generate2(n, m-1, s + "o");
}

//p296 k-1개 건너뛰고 첫 번째 신호를 출력하는 알고리즘
//K의 최대값 +100. 오버플로를 막기 위해 이보다 큰 값은 구하지 않는다.
const int M = 1000000000+100;
int bino[201][201];
//필요한 모든 이항계수를 미리 계산해 둔다. //파스칼 삼각형 조합  !!!!
void calcBino() {
	memset(bino, 0, sizeof(bino));
	for(int i = 0; i <= 200; ++i) {
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1; j < i; ++j)
			bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
	}
}
//1
//1 1
//1 2 1
//1 3 3 1
0C0 = 1;
1C0 = 1C1 = 1;
2C0 = 1, 2C1 = 2, 2C2 = 1;	//여기서부터 for (int j = 1; j < i; ++j) 루틴 탐
...

---ooooo = (5+3) C 3 //8개의 칸 중에 3개를 선택해 -로 도배하는 경우의 수

//skip개를 건너뛰고 출력한다. skip = 3 : (0,1,2) 3개를 스킵합니다.		// !@#2_22	
//n = 3, m = 5라 할때 만들어지는 갯수는 모두 (3 + 5) C 3 이 된다.
//8개의 칸 중에 3개의 칸을 '-'로 채우는 경우의 수가 되기 때문이다.
void generate3(int n, int m, string s) {
	//기저 사례: skip < 0
	if(skip < 0) return;
	//기저 사례: n=m=0
	if(n == 0 && m == 0) {
		//이 루틴은 의미 없을거 같다. 여기 도당한 순간은 skip은 항상 0이 될듯함
		// assert(skip == 0); 으로 테스트 해보자. 
		// generate3(0, 0, string()); 인 경우에만 skip 이 0이 아니더라도 탄다.
		if(skip == 0) cout << s << endl;
		--skip;	
		return;
	}
	if(bino[n+m][n] <= skip) {
		skip -= bino[n+m][n];
		return;
	}
	if(n > 0) generate3(n-1, m, s + "-");
	if(m > 0) generate3(n, m-1, s + "o");
}
bino[2 + 2][2] = 6
skip = 6;
g3(2, 2, string(""))
--oo
-o-o
-oo-
o--o
o-o-
oo--
//아무 출력도 안한다.

bino[3+2][2] = 10
skip = 6;
g3(3, 2, string(""))
---oo
--o-o
--oo-
-o--o
-o-o-
-oo--	//bino[2][2] = 6 : skip 은 6->0이 된다. g(3-1,2,"-")의 종료
o---o	//g(3,2-1, "o")의 시작시 최초 기저 도달이며 skip이 0이므로 출력하고 종료
o--o-
o-o--
oo---
//알고스팟 제출 코드 6ms
int main() {
	prec();
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, m, k; 
		cin >> n >> m >> k;
		int sz = n + m;
		string sol;
		rep(i, sz) {
			// '-'를 선택한 경우 만들어 지는 자식의 갯수가 k이상인 경우
			if (bino[n - 1 + m][m] >= k && n > 0) {
				n--;
				sol += '-';
			}
			// '-'를 선택한 경우 만들어지는 자식의 갯수가 k(skip) 보다 작은 경우 '-' 선택은 의미가 없으므로 그 경우의 수는 생략
			else	
			{	// 'o' 를 선택하는 경우: '-' 를 선택한 경우의 갯수만큼 빼주면 된다.
				k -= bino[n - 1 + m][m];	// n 이 0일때 bino[m - 1][m] 이 되며 이는 0이다. (이건 의도 못했네)
				m--;
				sol += 'o';
			}
		}
		cout << sol << endl;
	}
	return 0;
}

//302 K번째 LIS 구하기: LIS의 개수 세기	: !@#2_23
//S는 같은 수가 두번 이상 등장 안하는 배열(문제 조건에 있다.)
const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];
//S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis(int start) {
	//메모이제이션
	int& ret = cacheLen[start + 1];
	if(ret != -1) return ret;
	//항상 S[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for(int next = start + 1; next < n; ++next)
		if(start == -1 || S[start] <  S[next])
			ret = max(ret, lis(next) + 1);
	return ret;
}

//S[start]에서 시작하는 최대 증가 부분 수열의 수를 반환한다.
//극단적으로 생각하면 한놈이 가지치기가 n개 만큼 되고 그게 n개 있으니
//n1 * n2 * n3 * n4 , ...., * nn  이니 상당히 클것이다.(극단적 계산임 ㅎ)
int count(int start) {
	//기저 사례: LIS의 길이가 1인 경우
	if(lis(start) == 1) return 1;
	//메모이제이션
	int& ret = cacheCnt[start + 1];
	if(ret != -1) return ret;
	ret = 0;
	for(int next = start + 1; next < n; ++next) {
		if(  (start == -1 || S[start] < S[next]) && 
			  lis(start) == lis(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}
//최장 문자열
-oo, 3, 4, 5, 7 //index: -1, 0, 1, 4, 5
-oo, 3, 4, 5, 6	//index: -1, 0, 1, 4, 6
-oo, 0, 1, 5, 7	//index: -1, 2, 3, 4, 5
-oo, 0, 1, 5, 6	//index: -1, 2, 3, 4, 6

 -1, 0, 1, 2, 3, 4, 5, 6 , 7//index    
-oo, 3, 4, 0, 1, 5, 7, 6 , 2//S 배열
count(-1)	= count(0) + count(2)
count(0)	= count(1)	= count(4)	= count(5) + count(6)	= 2개
count(2)	= count(3)	= count(4)	= count(5) + count(6)	= 2개
고찰 count(7) = cacheCnt[7 + 1] 은 세팅 자체가 안되니 -1이다.

//p305 K번째 LIS 구하기: K번째 LIS 계산하기
//S[start]에서 시작하는 LIS 중 사전순으로 skip 개 건너뛴 수열을 lis에 저장한다.
void reconstruct(int start, int skip, vector<int>& lis) {	//skip = 5 =>1,2,3,4,5번째는 생략하고 6번째를 출력
	//1. S[start]는 항상 LIS에 포함된다.
	if(start != -1) lis.push_back(S[start]);
	//2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다..
	//(숫자, 숫자의 위치)의 목록이 된다.
	vector<pair<int, int> > followers;
	for(int next = start + 1; next < n; ++next)
		if( (start == -1 || S[start] < S[next]) &&	//4,5,6,1,2 같은 경우가 있으니 이 조건이 필요
				lis3(start) == lis3(next) + 1)
			followers.push_back(make_pair(S[next], next));
	sort(followers.begin(), followers.end());
	//3. k번째 LIS의 다음 숫자를 찾는다.
	for(int i = 0; i < followers.size(); ++i) {
		//이 숫자를 뒤에 이어서 만들 수 있는 LIS의 개수를 본다.
		int idx = followers[i].second;
		int cnt = count(idx);
		if(cnt <= skip)
			skip -= cnt;
		else {
			//다음 숫자는 S[idx]임을 알았다.
			//4. 재귀 호출을 통해
			reconstruct(idx, skip, lis);
			break;
		}
	}
}

//통과함: 26ms
const int MX = numeric_limits<int>::max();
int n, k, arr[501];
int dp1[501];	//lis 길이
int dp2[501];	//lis 갯수
map<int, int> child[501];
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> n >> k;
		rep(i, n + 1) child[i].clear();
		arr[0] = -1;
		rep2(i, 1, n + 1) scanf("%d", &arr[i]);
		for (int here = n; here >= 0; --here) {	//길이
			dp1[here] = 1;
			for (int there = n; there > here; --there) {
				if (arr[here] < arr[there])
					dp1[here] = max(dp1[here], dp1[there] + 1);
			}
		}
		for (int here = n; here >= 0; --here) { //갯수
			dp2[here] = 1;
			long long cand = 0;
			for (int there = n; there > here; --there) {
				if (arr[here] < arr[there] && dp1[here] == dp1[there] + 1) {
					child[here][arr[there]] = there;
					cand = min<long long>(MX, cand + dp2[there]);
				}
			}
			dp2[here] = max<long long>(dp2[here], cand);
		}
		vector<int> sol;
		int here = 0;
		map<int, int>::iterator it = child[here].begin();
		//k번째 찾기
		while (it != child[here].end()) {
			for (; it != child[here].end(); ++it) {
				int there = it->second;
				int cnt = dp2[there];
				if (cnt < k)	//skip
					k -= cnt;
				else {
					here = there;
					it = child[here].begin();
					sol.push_back(here);
					break;
				}
			}
		}
		cout << sol.size() << endl;
		rep(i, sol.size())
			cout << arr[sol[i]] << " \n"[(i == sol.size() - 1) ? 1 : 0];
	}
	return 0;
}

//p310 드래곤 커브 문자열을 생성하는 재귀 호출 알고리즘
//초기 문자열 seed를 generations세대 진화한 결과를 출력
void curve(const string& seed, int generations) {
	//기저 사례
	if(generations == 0) {
		cout << seed;	//FX, X+YF, FX-Y 등이 출력됨
		return;
	}
	for(int i = 0; i < seed.size(); ++i) {
		if(seed[i] == 'X')
			curve("X+YF", generations - 1);
		else if(seed[i] == 'Y')
			curve("FX-Y", generations - 1);
		else
			cout<<seed[i];	//F, +, - 등이 출력됨
	}
}

//p311 드래곤 커브 문제를 해결하는 알고리즘
//xLength(n) = 문자열 "X"를 n세대 진화시킨 결과의 길이를 반환
//yLength(n) = 문자열 "Y"를 n세대 진화시킨 결과의 길이를 반환
//xLength(n) = xLength(n - 1) + yLength(n - 1) + 2
//yLength(n) = xLength(n - 1) + yLength(n - 1) + 2
//그러므로 xLength(n) == yLength(n) 이 성립된다.
//xLength(0) = yLength(0) = 1 //치환을 한번도 안했을 시 초기 길이
//종합하면, length(n) = 2 + 2 * length(n-1)
const int MAX = 1000000000 + 1;
//length[i]=X나 Y를 i번 치환한 후의 길이
int length[51];
void precalc() {
	length[0] = 1;
	for(int i = 1; i <= 50; ++i)
		length[i] = min(MAX, length[i-1] * 2 + 2);
}
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";
//dragonCurve를 generations 진화시킨 결과에서 skip번째 문자를 반환한다.
//제기호출은 많이 해봐야 n번 즉 generations 만큼만 한다.
//좋은 알고리즘이다.
char expand(const string& dragonCurve, int generations, int skip) {
	//기저 사례
	if (generations == 0) {
		assert(skip < dragonCurve.size()); //문제 조건 : n세대의 드래곤 커브 문자열의 길이는 항상 p + l 이상이라고 가정
		return dragonCurve[skip];
	}
	for (int i = 0; i < dragonCurve.size(); ++i) {
		//문자열이 확장되는 경우
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generations])
				skip -= length[generations];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else
				return expand(EXPAND_Y, generations - 1, skip);
		}
		else if (skip > 0) //확장되진 않지만 건너뛰어야 할 경우
			--skip;
		else //답을 찾은 경우 skip == 0
			return dragonCurve[i];
	}
	return '#'; //이 줄은 수행되지 않음
}
0세	1세	2세	3세	4세
1	4	10	22	46

expand("FX", 4, 45); //총 47개의 글자(F 1개, X의 확장 46개) 중 1~45 번째 글자는 스킵하고 46번째 글자를 출력한다.
"FX" 의 4세대는 총 47개의 글자를 가지고 있다.

expand("~~~~~", 5, 1);	//1번째 글자를 스킵하고 두번째 글자를 출력한다.
expand("~~~~~", 5, 0);	//아무 스킵없이 1번째 글자를 출력한다.

int main() {
	for(int i = 0; i < 10; ++i) {
		cout << i << ": ";
		curve("FX", i);
		cout << endl;
	}

    precalc();
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	int n, p, l;
    	cin >> n >> p >> l;
    	--p;	
		//!!!! 최초 입력이 p가 2이면 1으로 바꾼다. 1개 스킵 
		//expand는 p가 1인 경우 1번째를 첫번째로 취급하며 한개를 skip한다. 그리고 두번째를 출력한다.
		//최초 p가 2라는 것의 의미를 잘 생각해 보면 알 수 있다.
    	for(int i = 0; i < l; ++i)
    		printf("%c", expand("FX", n, p+i));
    	printf("\n");
    }
}


//통과함 7ms
const int MX = 1000000007;
int length[51];
void precalc() {
	length[0] = 1;
	rep2(i, 1, 51)
		length[i] = min(MX, length[i - 1] * 2 + 2);
}
//target의 인덱스가 1부터 시작함
char curve(int n, int target) {
	int here = 0;
	string str = "FX";
	for (int iter = n; iter >= 0; --iter) {
		rep(i, str.size()) {
			if (str[i] == 'X' || str[i] == 'Y') {
				if (iter == 0 && target == here + 1) 
					return str[i];	//끝까지 도달한 경우
				if (target > here + length[iter]) 
					here += length[iter];
				else {
					if (str[i] == 'X') str = "X+YF";
					else str = "FX-Y";
					break;
				}
			}
			else if (target > here + 1)
				here++;
			else if (target == here + 1)
				return str[i];
			else
				return '*';	//출력되면 안됨
		}
	}
	return '^'; //출력되면 안됨
}
int main() {
	precalc();
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, p, l;	//n: 세대, p: 시작지점, l: 길이
		cin >> n >> p >> l;
		string sol;
		rep(i, l) {
			char ch = curve(n, p + i);
			sol += ch;
		}
		printf("%s\n", sol.c_str());
	}
	return 0;
}


//p317 순열의 사전순 번호 찾기
int factorials[12];
void setFactorials() {
	factorials[0] = 1; //0!
	for (int i = 1; i < 12; ++i) {
		factorials[i] = factorials[i - 1] * i;
	}
}
//factorials[3] = 3!, factorials[4] = 4!
//X의 각 요소는 중복이 되지 않아야 한다!
int getIndex(const vector<int>& X) {
	int ret = 0;
	for (int i = 0; i < X.size(); ++i)
	{
		int less = 0;
		for (int j = i + 1; j < X.size(); ++j) {
			if (X[i] > X[j])
				less++;
		}
		ret +=  factorials[X.size() - i - 1] * less;
	}
	return ret;
}
void main() {
	string Num;
	cin >> Num;
	vector<int> numVector(Num.size());
	for (int i = 0; i < Num.size(); ++i) {
		numVector[i] = Num[i] - '0';
	}
	setFactorials();
	int index = getIndex(numVector);
}

// 사전순 순열 찾기: 프로그래머스 level5 : 줄 서는 방법
int fac[12];
void setFac() {
	fac[0] = 1;
	for (int i = 1; i < 12; ++i)
		fac[i] = fac[i - 1] * i;
}
vector<int> getSol(set<int> sets, int k) {
	vector<int> ret;
	while (sets.empty() != true) {
		int subSetSize = sets.size() - 1;	// 선택한것을 뺀 사이즈를 구한다.
		int subFacSize = fac[subSetSize];	// 순열 크기를 구한다.
		set<int>::iterator it = sets.begin();
		for (; it != sets.end(); ++it) {
			if (subFacSize >= k) {		// 선택될 경우
				ret.push_back(*it);
				sets.erase(it);
				break;
			}
			else						// 선택되지 않은 경우
				k -= subFacSize;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	setFac();
	int n, k; cin >> n >> k;
	set<int> sets;
	for (int i = 0; i < n; ++i) sets.insert(i + 1);
	vector<int> sol = getSol(sets, k);
	for (int i = 0; i < sol.size(); ++i) 
		cout << sol[i] << " ";
	return 0;


//p319 여행하는 외판원 문제를 해결하는 동적 계획법 알고리즘(1 << 0 => 1, 1 << 1 => 2, 1 << 2 => 4)
int n, dist[MAX][MAX]; //n = 지점수, MAX = 10 , dist : 각 지점마다 거리
double dist[MAX][MAX]; //위에거 책의 오타라 본다.
double cache[MAX][1<<MAX]; //-1 로 초기화 해 둔다.  cache[10][2^10] : [here][도시의 방문여부]
//here: 현재 위치
//visited: 각 도시의 방문 여부
//here에서 시작해 남은 도시들을 방문할 수 있는 최단 경로의 길이를 반환한다.
//나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다.
//항상 0번 도시에서 시작한다고 가정한다.!!
double shortestPath2(int here, int visited) {	//최초 호출 : here = 0, visited : 000 0001 //n이 7이라 가정한다면
	//기저 사례: 모든 도시를 다 방문했을 때는 0번 도시로 돌아가고 종료한다.
	if (visited == (1<<n) - 1) return dist[here][0]; //도시수n이 7이라면 1000 0000 - 1 => 0111 1111 
	//메모이제이션
	double& ret = cache[here][visited];
	if (ret >= 0) return ret;
	ret = INF; //매우 큰 값으로 초기화
	//다음 방문할 도시를 전부 시도해 본다.
	for (int next = 0; next < n; ++next) {
		//이미 방문한 도시인 경우
		if(visited & (1<<next)) continue;	// equal : if (visited & (1<<next))
		double cand = dist[here][next] + 
						shortestPath2(next, visited + (1 << next));
		ret = min(ret, cand);
	}
	return ret;
}
//점화식 sp2(here, visited) = min{ dist[here][next] + sp2(next, visited + (1 << next)) } : (next는 호출시 방문하지 않은 도시만 가능)
sp2(h,vstd) = min{ dist[h][t] + sp2(t, vstd + (1 << t)) }

TSP1은 20ms에 통과했으나 TSP2는 시간초과 뜸...
const double INF = 123456789;
const int MX = 16;
double dist[MX][MX];
map<pair<int, int>, double> my[2];
//map<pair<int, int>, double> my[16];
double solve(int n) {
	my[0].clear();
	rep(i, n) my[0][mp(i, (1 << i))] = 0.0;
	rep(i, n - 1) {
		map<pair<int, int>, double>::iterator it = my[i & 1].begin();
		my[(i + 1) & 1].clear();
		for (; it != my[i & 1].end(); ++it) {
			pair<int, int> key = it->first;
			int here = key.first;
			int vstd = key.second;
			double val = it->second;
			rep(next, n) {
				if (vstd & (1 << next)) continue;
				int vstd2 = vstd + (1 << next);
				pair<int, int> key2 = mp(next, vstd2);
				if (my[(i + 1) & 1].count(key2) == 0)
					my[(i + 1) & 1][key2] = INF;
				my[(i + 1) & 1][key2]
					= min<double>(my[(i + 1) & 1][key2], val + dist[here][next]);
			}
		}
	}
	double sol = INF;
	rep(i, n) sol = min<double>(sol, my[(n - 1) & 1][mp(i, (1 << n) - 1)]);
	return sol;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		rep(i, n) rep(j, n) scanf("%lf", &dist[i][j]);
		double sol = solve(n);
		printf("%.10lf\n", sol);
	}
	return 0;
}

//tsp2통과 260ms걸림.. 윗방식으로라면 cache크기 * log2(cache크기) * n 
//윗방식이라면 260 ms 에다가 적어도 log2(cache크기): 20정도 곱한 시간이 걸렸을거음
//그래서 윗방식이 통과 못한듯 싶다.
const double INF = 123456789;
const int MX = 16;
double dist[MX][MX];
double cache[MX][1 << MX];
int n;
double sp(int here, int vstd) {
	if (vstd == (1 << n) - 1) return 0.0;
	double& ret = cache[here][vstd];
	if (ret > -1) return ret;
	ret = INF;
	rep(there, n) {
		if (vstd & (1 << there)) continue;
		ret = min<double>(ret, sp(there, vstd + (1 << there)) + dist[here][there]);
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> n;
		rep(i, n) rep(j, (1 << n)) cache[i][j] = -1;
		rep(i, n) rep(j, n) cin >> dist[i][j];
		double sol = INF;
		rep(here, n)
			sol = min(sol, sp(here, (1 << here)));
		printf("%.10lf\n", sol);
	}
	return 0;
}

//p323 웨브바짐 분제의 답을 모두 찾는 완전 탐색 알고리즘
"지금 계란 가격 e와 m이 주어질때 이전 계란 가격이 몇가지진지 계산하는 프로그램, e보다 작아야 함"
"정렬한 이유는 같은 숫자가 여러 개 남아 있다면 그중 가장 먼저 오는 것만 선택하기 위해"
//digits: e의 자릿수들을 정렬한 것, e: 현재 수
string e, digits;
int n, m;	//n: 숫자카드 갯수, m: 나누기할 수
//e의 자릿수(숫자카드)로 만들 수 있는 숫자들 중 조건(e보다 작고, m으로 나누어 떨어지는)을 만족하는 것을 모두 "출력" 한다.
//price: 지금까지 만든 가격
//taken: 각 자릿수의 사용 여부
void generate(string price, bool taken[15]) {
	//기저 사례
	if (price.size() == n) {
		if (price < e && atoll(price.c_str()) % m == 0)
			cout << price << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!taken[i] &&	//digits[3,5,5,6] 에서
			(i == 0 ||		 // i가 최초사용할 카드으거나
			digits[i-1] != digits[i] ||		//중복된 케이스가 아니되거나 (ex => [3,5]:[1100], [3,5]:[1010] 중복)
			taken[i-1])//위 두 조건이 거짓이더라도 이 조건이 만족되면 다음과 같은 현상이 된다(ex => [3,5]:[1100], [3,5,5]:[1110])
			) {
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}
//3,5,5,5,5에서 price[1]숫자에 5가 들어가는 케이스
//taken[0] = true인 상태에서
//i가 1인 경우 5가 들어감
//i가 2인 경우 taken[1]이 false이므로 generate호출 안됨
//i가 3인 경우 taken[2]가 false이므로 generate호출 안됨
//...
string e, digits;
void generate(string price, bool taken[15]) {
	if (price.size() == e.size()) {
		if (price < e && atoll(price.c_str()) % m == 0)
			cout << price << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if(taken[i] != false &&
			(i == 0 || digit[i-1] != digit[i] || taken[i-1] == true)) {
			//digits[i-1] != digits[i] 가 true이고
			//taken[i-1] 이 false인 경우도 성립되는가 
			//3,4,5,5,5
			//taken[0]이 true인 상태
			//3,4
			//3,5 성립되넹
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}
int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	cin >> e >> m;
    	n = e.size();	//카드의 개수
    	digits = e;
    	sort(digits.begin(), digits.end());
    	bool taken[15] = {0};
    	generate("", taken);
    	memset(cache, -1, sizeof(cache));
    	cout << price(0, 0, 0, 0) << endl;
    	if(n <= 8) assert(brute(e) == price(0,0,0,0)); //index, taken, rmd, less여부
    }
}
1<<10 : 100 0000 0000 카드가 11장
cache[1<<10][20][2] : 카드가 10장이잖아!!!! //불만이었으며 밑에 설명이 있음

//p326 코드 9.17 웨브바짐 문제를 해결하는 동적 계획법 알고리즘
const int MOD = 1000000007;
//digits: e 의 자릿수들을 정렬한 것
string e, digits;
int n, m;
int cache[1<<14][20][2]; //[1<<1][20][2] 카드 1장, [1<<2][20][2] 카드 2장
//[각 비트는 숫자카드이며 최대갯수는 15개:이경우 최대값은 100 0000 0000 0000]
//[사탕의 최대갯수: 제수가 된다][지금까지 만든 가격이 이미 e보다 작으면 1, 같으면 0]

//과거 가격을 앞 자리부터 채워나가고 있다.
//index: 이번에 채울 자리의 인덱스
//taken: 지금까지 사용한 자릿수들의 집합
//mod: 지금까지 만든 가격의 m에 대한 나머지
//less: 지금까지 만든 가격이 이미 e보다 작으면 1, 같으면 0 (큰 경우는 존재 안함. 왜냐면 그 경우 함수 호출 자체를 안하니까)
int price(int index, int taken, int mod, int less) {
	//기저 사례
	if (index == n)	//이 경우 taken 은 꽉 찾다. n: 카드의 개수가 한계치인 15개 인 경우
					//taken				= 111 1111 1111 1111 이 된다
					//이건 cache[1<<14] = 100 0000 0000 0000 이상인 거지만. 이때는 cache를 참조 안한다. 안심~~~ 
					//e가				100 0000 0000 0000 인 상황에서 
					//digits			000 0000 0000 0001 이고 맨 앞의 0을 taken 했다면
					//taken				= 100 0000 0000 0000 이 되고....... 어엇 ㅅㅂ 이상하네
					//다음 taken 이		= 110 0000 0000 0000 오...노... 캐쉬를 오바한다.. ㅅㅂ ㅅㅂ
					
		return (less && mod == 0) ? 1 : 0;
	//메모이제이션
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < n; ++next)	//n 15인 경우 0~14
		if ((taken & (1<<next)) == 0) {
			//과거 가격은 새 가격보다 항상 작아야만 한다.
			if (!less && e[index] < digits[next]) //index 가 이번에 채울 자리의 인덱스임을 유의해라!!
				continue;
			//같은 숫자는 한 번만 선택한다.
			if (next > 0 && digits[next-1] == digits[next] && (taken & (1<<(next-1))) == 0)
				continue;
			//해당 숫자가 이전 숫자랑 같고 이전에 취급되지 않은 숫자면 무시
			//해당 숫자가 이전 숫자랑 같고 이전에 취급된 숫자면 채우자

			int nextTaken = taken | (1<<next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || e[index] > digits[next]; 
			//less 가 false 라도 다음 숫자(digits[next])가 e[index]보다 작을순 없다. 같을수는 있지요. 위 continue조건을 보면 알수 있다.

			ret += price(index+1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	return ret;
}
const int MOD = 1000000007;
string e, digits;
int n, m;
int cache[1<<15][20][2];//int cache[1<<14][20][2]; 로 설정시 100000000000000 10 을 실행시키면 죽는다. 책 소스가 오류로 보임, 첨부된 소스도 오류
//[1<<15] 해봐야 얼마 안된다. 2^15 = 32768임!!!!
int price(int index, int taken, int rmd, int less) {	//rmd: remainder(나머지)
	if (index == n)
		return (less && rmd == 0)? 1 : 0;
	int& ret = cache[taken][rmd][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ((taken & (1<<next)) != 0) continue;	//사용안한 숫자이고
		if (!less && e[index] < digits[next]) continue;	//값이 더 큰 경우(이전까지는 같고, 이번에 채울 숫자는 오버하는 경우)
		if (next > 0 && digits[next-1] == digits[next] && (taken & (1<<(next-1))) == 0) continue;	//중복되는 경우
		int nextTaken = taken | (1<<next);
		int nextRmd = (rmd * 10 + digits[next] - '0') % m;
		int nextLess = less || e[index] > digits[next];
		ret += price(index+1, nextTaken, nextRmd, nextLess);
		ret %= MOD;
	}
	return ret;	
}
const int MOD = 1000000007;
string e, digits;
int n, m;
int cache[1<<15][20][2];
int price(int index, int taken, int mod, int less) {
	if (index == n) return (less && mod == 0)? 1 : 0;
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int select = 0; select < n; ++select) {	//위에 next란 의미가 오히려 헷갈림을 주는것 같아 select로 바꿈
		if (taken & (1 << select) != 0) continue;
		if (!less && e[index] < digits[select]) continue;
		if (select != 0 && digits[select - 1] == digits[select] && (taken & (1 << (select - 1))) == 0) continue;
		int nextTaken = taken | (1 << select);
		int nextMod = (mod * 10 + digits[select]) % m;
		int nextLess = less | e[index] > digits[select];
		ret += price(index + 1, nextTaken, nextMod, nextLess);
		ret %= MOD;
	}
	return ret;
}
const int MOD = 1000000007;
string e, digits;
int n, m;
int cache[1 << 15][20][2];
int price(int index, int taken, int mod, int less) {
	if (index == n) return (less && mod == 0) ? 1 : 0;
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	rep(h,n) {	//h : here
		if (taken & (1 << h) != 0) continue;
		if (!less && e[index] < digits[h]) continue;
		if (h != 0 && digits[h - 1] == digits[h] && (taken & (1 << (h - 1))) == 0) 
			continue;
		int nextTaken = taken | (1 << h);
		int nextMod = (mod * 10 + digits[h]) % m;
		int nextLess = less | e[index] > digits[h];
		ret += price(index + 1, nextTaken, nextMod, nextLess);
		ret %= MOD;
	}
	return ret;
}

//통과 코드 107ms
const int MOD = 1000000007;
int cache[20][1 << 14][2];	//현 나머지, 사용한카드, 작으냐 같으냐 여부	//0: 작음, 1: 같음
//cache[rmd][taken][lessOrEqual] = sum{ cache[nextRmd][nextTaken][nextLessOrEqual] };
string e, digits;
int m;
int n;
int solve(int index, int rmd, int taken, int lessOrEqual) {
	if (taken == (1 << n) - 1) {
		if (rmd == 0 && lessOrEqual == 0)
			return 1;
		return 0;
	}
	int& ret = cache[rmd][taken][lessOrEqual];
	if (ret != -1) return ret;
	ret = 0;
	rep(here, n) {
		if (taken & (1 << here)) continue;
		if (lessOrEqual == 1 && digits[here] > e[index]) continue;
		if (here != 0 && digits[here - 1] == digits[here] 
			&& (taken & (1 << (here - 1))) == 0)
			continue;
		int nextRmd = (rmd * 10 + digits[here] - '0') % m;
		int nextTaken = taken | (1 << here);
		int nextLessOrEqual = 0;
		if (lessOrEqual == 1 && digits[here] == e[index]) nextLessOrEqual = 1;
		ret += solve(index + 1, nextRmd, nextTaken, nextLessOrEqual);
		ret %= MOD;
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(cache, -1, sizeof(cache));
		cin >> e >> m;
		digits = e;
		n = e.size();
		sort(digits.begin(), digits.end());
		int sol = solve(0, 0, 0, 1);
		cout << sol << endl;
	}
	return 0;
}


//p331 실험데이터 복구문제를 해결하는 동적계획법 알고리즘
//각각의 단어들을 모두 포함하는 가장 짧은 문자열 중 하나를 출력하는 문제 geo, oji, jing => geojing
const int MAX_N = 15;	//문자열 조각의 개수(최대)
int k;	//문자열 조각의 개수
string word[MAX_N];
int cache[MAX_N][1<<MAX_N];	//[마지막 문자열 인덱스][현제까지 사용된 문자열]
int overlap[MAX_N][MAX_N];	//[두 문자열간의 겹쳐진 길이]
//restore : 전체 문자열을 가장 많이 overlap을 하는 경우의 겹쳐진 총 길이
int restore(int last, int used) {	//last : 최초호출은 k(word[k] = ""), used : 사용 여부 비트마스크 : 최초호출은 0임
	//기저사례
	if (used == (1 << k) - 1) return 0;
	//메모이제이션
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; ++next)	//next 보단 here라고 명명하는게 좋아보임.. 밑에함수들도 말이지..
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] + restore(next, used + (1 << next));
			ret = max(ret, cand);
		}
	return ret;
}
//reconstruct : 답 구성하기 : 소스코드
string reconstruct(int last, int used) {
	// 기저 사례
	if(used == (1<<k)-1) return "";
	for(int next = 0; next < k; ++next)
		if((used & (1<<next)) == 0 &&
			restore(last, used) ==
			overlap[last][next] + restore(next, used + (1<<next)))
			return word[next].substr(overlap[last][next]) +
				reconstruct(next, used + (1<<next));
	return "_oops_";
}
//reconstruct : 책 코드: 최초 호출시 last는 k 이며 used는 0임. //used 가 1 << k 가 되면 안됨
string reconstruct(int last, int used) {
	//기저 사례
	if (used == (1<<k)-1) return "";
	//다음에 올 문자열 조각을 찾는다.
	for (int next = 0; next < k; ++next) {
		//next가 이미 사용되었으면 제외
		if (used & (1<<next)) continue;
		//next를 사용했을 경우의 답이 최적해와 같다면 next를 사용한다.
		int ifUsed = restore(next, used + (1<<next)) + overlap[last][next];
		if(restore(last, used) == ifUsed)
			return word[next].substr(overlap[last][next]) + reconstruct(next, used + (1<<next));
	}
	//뭔가 잘못된 경우
	return "****oops*****";
}
int getOverlap(const string& a, const string& b) {	//a의 접미사랑 b의 접두사중 최대 겹치는 길이를 리턴한다.
	for (int len = min(a.size(), b.size()); len > 0; --len) {	//최대 길이부터 줄여가며 조사
		if (a.substr(a.size() - len) == b.substr(0, len))
			return len;
	}
	return 0;
}
int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	cin >> k;
    	for(int i = 0; i < k; i++) cin >> word[i];
    	memset(cache, -1, sizeof(cache));
		//포함되는 단어를 제거하는 알고리즘.. 물론 이것보다 좋은게 존재하리라 본다만..
    	while(true) {
    		bool removed = false;
    		for(int i = 0; i < k && !removed; i++)
    			for(int j = 0; j < k; j++)
    				if(i != j && word[i].find(word[j]) != -1) { //j가 포함(중복도)된 놈이면
    					word[j] = word[k-1];	//j번째를 없앤다.
    					--k;
    					removed = true;
    				}

    		if(!removed) break;
    	}
    	word[k] = "";	//word[k]는 정렬에서 제외됨
						//빈문자열을 줌으로써 바깥에서 for문으로 돌릴 수고를 덜수 있군..(깔끔해졌다는 것)
						//이게 없다면 rep(i,k) restore(i) 수행해서 가장 큰 놈을 찾고 그 뒤 reconstruct해야 하는 불편함이 있다.
    	sort(word, word+k);
    	for(int i = 0; i <= k; i++)
    		for(int j = 0; j <= k; j++)
    			overlap[i][j] = getOverlap(word[i], word[j]);
    	restore(k, 0);
    	cout << reconstruct(k, 0) << endl;
    }
}


//p339 틱택토를 해결하는 동적 계획법 알고리즘
// turn 이 한 줄을 만들었는지를 반환한다
bool isFinished(const vector<string>& board, char turn) {
	//turn은 필요없는 인자 같구먼
	return false;//책, 인터넷 소스 미구현임..ㅡㅡ..
}


// 틱택토 게임판이 주어질 때 [0,19682] 범위의 정수로 변환한다
int bijection(const vector<string>& board) {
	int ret = 0;
	for(int y = 0; y < 3; ++y)
		for(int x = 0; x < 3; x++) {
			ret = ret * 3;	//3진수 쳬계를 상상하면 이해쉽다.
			if(board[y][x] == 'o') ++ret;
			else if(board[y][x] == 'x') ret += 2;
		}
	return ret;
}

// cache[] 는 -2 로 초기화한다
int cache[19683];

// 내가 이길 수 있으면 1 을, 비길 수 있으면 0 을, 지면 -1 을 리턴한다
int canWin(vector<string>& board, char turn) {	//turn 은 내가 두는 수임
	// 기저 사례: 마지막에 상대가 둬서 한줄이 만들어진 경우
	if(isFinished(board, 'o'+'x'-turn)) return -1;
	int& ret = cache[bijection(board)];
	if(ret != -2) return ret;
	// 각 반환값 중 상대가 이기는 결과 (1) 보다 비기는 결과 (0),
	// 비기는 결과보다 상대가 지는 결과 (-1)를 원한다:
	// 모든 반환값의 min 을 취하자
	int minValue = 2;
    for(int y = 0; y < 3; ++y)
    	for(int x = 0; x < 3; ++x) {
    		if(board[y][x] == '.') {
    			board[y][x] = turn;
    			minValue = min(minValue, canWin(board, 'o'+'x'-turn));
    			board[y][x] = '.';
    		}
    	}
    // 플레이할수 없거나, 어떻게 해도 비기는 것이 최선인 경우
    if(minValue == 2 || minValue == 0) return ret = 0;
	//minValue == 2 인 경우는 기저에서 비긴 경우임, 그뒤는 ret = 0을 리턴되어 0 이 비긴걸 나타냄
    // 최선이 상대가 이기는 거라면 난 무조건 지고, 상대가 지는 거라면 난 이긴다
	//minValue == -1 이면 나는 이긴겨, 1이면 나는 진겨
    return ret = -minValue;
}

//제출해서 통과한 코드
vector<pair<pair<int, int>, char> > track;

bool isFinished(const vector<string>& board, char turn) {
	//8가지만 체크하면 됨
	bool ret = false;
	for (int i = 0; i < 3; ++i)
		if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			ret = true;
	for (int i = 0; i < 3; ++i)
		if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			ret = true;
	if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		ret = true;
	if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		//맨마지막 비교를 board[1][1]과 board[0][2]로 하는 오타 실수로
		//하루종일 디버깅 으아아아
		//완벽하다생각했는데 여기서 망칠줄이야..
		ret = true;
	return ret;
}

//o..
//.x.
//...
//비겨야 정상인데 x가 승리한다고 뜬다..

int bijection(const vector<string>& board) {
	int ret = 0;
	for (int y = 0; y < 3; ++y)
		for (int x = 0; x < 3; ++x) {
			ret = ret * 3;
			if (board[y][x] == 'o') ++ret;
			else if (board[y][x] == 'x') ret += 2;
		}
	return ret;
}

int cache[19683];
int canWin(vector<string>& board, char turn) {
	if (isFinished(board, 'o' + 'x' - turn)) {
		for (int i = 0; i < track.size(); ++i) {
			cout << endl;
			//cout << track[i].first.first << " " <<  track[i].first.second << " "<< track[i].second << endl;
		}
		return -1;
	}
	int& ret = cache[bijection(board)];
	if (ret != -2) return ret;
	int minValue = 2;
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x)
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
				board[y][x] = '.';
			}
	}
	if (minValue == 2 || minValue ==0) return ret = 0; 
	//2가 되는 케이스는 board를 다 채워서 자식 재귀함수를 호출 못하는 경우
	return ret = -minValue;
}

int main() {
	int cc;
	cin >> cc;
	while (cc--) {
		for (int i = 0; i < 19683; ++i)
			cache[i] = -2;
		vector<string> board(3);
		cin >> board[0];
		cin >> board[1];
		cin >> board[2];

		int xCnt = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[i][j] == 'x')
					xCnt++;
		int oCnt = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[i][j] == 'o')
					oCnt++;
		int ret = 0;
		if (xCnt == oCnt)
			ret = canWin(board, 'x');	// x가 둘 차례
		else
			ret = -canWin(board, 'o');	// o가 둘 차례
		if (ret == 0)
			cout << "TIE" << endl;
		else if (ret == 1)
			cout << "x" << endl;
		else
			cout << "o" << endl;
	}
	return 0;
}

//p343 숫자 게임 문제를 해결하는 동적 계획법 알고리즘
// "현우가 서하보다 몇점 많으냐" = min{ "현우가 한스텝 가저가는 점수" - "서하가 현우보다 몇점 많으냐" } 오타같다. 확인요!!!!
"현우가 서하보다 몇점 많으냐" = max{ "현우가 한스텝 가저가는 점수" - "서하가 현우보다 몇점 많으냐" }
const int EMPTY = -987654321;
int n, board[50];
int cache[50][50];
// 현 상태에서 현우(가정기준임)가 서하보다 몇점 많이 획득 가능할까?
int play(int left, int right) {
	//기저 사례: 모든 수가 다 없어졌을 때
	//left == right 이면 숫자가 하나 남은 경우임
	if (left > right) return 0;

	//left == right, left < right (숫자가 한개거나, 두개인 경우)
	int& ret = cache[left][right]; //EMPTY로 초기화되어 있음
	if (ret != EMPTY) return ret;
	//1개의 수를 가져가는 경우
	ret = max(board[left] - play(left + 1, right),
				board[right] - play(left, right - 1));
	//2개의 수를 그냥 제거하는 경우
	if (right - left + 1 >= 2) { //남은 숫자가 2개 이상이면
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left, right - 2));
	}
	return ret;
}
//!!!!끝이 어딘지 알수 없기에 for 재귀로 바꾸기가 힘드네... 잘하는 사람은 할수 있을듯..


//p347 블록 게임 문제를 해결하는 동적 계획법 알고리즘
vector<int> moves;
inline int cell(int y, int x) { return 1 << (y * 5 + x); }
//핵심부분
//1. 움직임(3칸 블록, 2칸 블록)을 int 형으로 단순화
//2. board의 상태를 int형으로 단순화

//게임판에 놓을 수 있는 블록들의 위치를 미리 계산한다.
void precalc() {
	//세 칸짜리 L자 모양 블록들을 계산한다.
	for (int y = 0; y < 4; ++y)
		for (int x = 0; x < 4; ++x) {
			vector<int> cells;
			for (int dy = 0; dy < 2; ++dy)
				for (int dx = 0; dx < 2; ++dx)
					cells.push_back(cell(y + dy, x + dx));
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			for (int i = 0; i < 4; ++i)
				moves.push_back(square - cells[i]);
		}
	//두 칸짜리 블록들을 계산한다.
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 4; ++j) {
			moves.push_back(cell(i, j) + cell(i, j + 1)); //oo
			moves.push_back(cell(j, i) + cell(j + 1, i)); //8
		}
}

char cache[1 << 25];
//현재 게임판 상태가 board일 때 현재 차례인 사람이 승리할지 여부를 반환한다.
//(y, x)칸에 블록이 있다 <=> (y*5+x)번 비트가 켜져 있다.
char play(int board) {
	//메모이제이션
	char& ret = cache[board];
	if (ret != -1) return ret;
	ret = 0;
	//모든 수를 고려한다.
	for (int i = 0; i < moves.size(); ++i) //104개
		"이 수를 이 게임판에 놓을 수 있는가 확인"
		if ((moves[i] & board) == 0)
			if (!play(board | moves[i])) {
				ret = 1;
				break;
			}
	return ret;
}

int main() {
    precalc();
    memset(cache, -1, sizeof(cache));
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	int state = 0;
    	for(int y = 0; y < 5; y++) {
    		string board;
    		cin >> board;
    		for(int x = 0; x < 5; x++)
    			if(board[x] == '#')
    				state += (1 << (y*5 + x));
    	}
    	if(play(state))
    		printf("WINNING\n");
		else
			printf("LOSING\n");
    }
}


//p349 삼각혀 위의 최대 경로 문제를 해결하는 반복적 동적 계획법 알고리즘
//(y, x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int n, triangle[100][100];
int C[100][100];
int iterative() {
	//기저 사례를 계산한다.
	for(int x = 0; x < n; ++x)
		C[n-1][x] = triangle[n-1][x];
	//다른 부분을 계산한다.
	for(int y = n-2; y >= 0; --y)
		for(int x = 0; x < y+1; ++x)
			C[y][x] = max(C[y+1][x], C[y+1][x+1]) + triangle[y][x];
	return c[0][0];
}

//p350 슬라이딩 윈도를 이용한 삼각형 위의 최대 경로 알고리즘
int C2[2][10000]	//n이 10000으로 커질 경우 C[10000][10000] 메모리 낭비가 심하다.. 물론 문제에선 triangle[10000][10000]의 크기
int iterative2() {
	//기저 사례를 계산한다.
	for(int x = 0; x < n; ++x)
		C2[(n-1)%2][x] = triangle[n-1][x];
	//다른 부분을 계산한다.
	for(int y = n-2; y >= 0; --y)
		for(int x = 0; x < y+1; ++x)
			C2[y%2][x] = max(C[(y+1)%2][x], C[(y+1)%2][x+1]) + triangle[y][x];
	return C2[0][0];
}

//p352 피보나치 수열의 특정 항을 구하는 동적 계획법 알고리즘
int fib(int n) {
	if(n <= 1) return n;
	int seq[3];
	seq[0] = 0;
	seq[1] = 1;
	for (int i = 2; i <= n ; ++i)
		seq[i % 3] = (seq[(i - 2) % 3] + seq[(i - 1) % 3]) % 100000; //뒤에서 5자리까지 구하라고 되어서..
	return seq[n%3];
}

//정방행렬을 기술해봅세
typedef vector<vector<int> > Matrix;
const int M = 100000;
Matrix operator * (const Matrix& a, const Matrix& b)
{
	int n = a.size();
	Matrix ret(n, vector<int>(n)); //typedef vvi 세팅임 Matrix는 클래스가 아니다!!!!
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++) {
				//쥑이네!!~~ 나머지 연산의 분배법칙이 성립되는구나.~~
				ret[i][j] += (a[i][k] * (long long)b[k][j]) % M;
				ret[i][j] %= M;
			}
	return ret;
}
struct SquareMatrix {
	Matrix mat;
	int size() const {return mat.size(); }
	SquareMatrix(int n) : mat(vector<vector<int> >(n, vector<int>(n, 0))) {}
	SquareMatrix(vector<vector<int> >m) : mat(m) {}
	vector<int>& operator[] (int idx) { return mat[idx]; }
};

SquareMatrix operator * (const SquareMatrix& a, const SquareMatrix& b) {
	return SquareMatrix(a.mat * b.mat);
}

SquareMatrix pow(const SquareMatrix& a, int p)
{
	if(p == 0) {
		int n = a.size();
		SquareMatrix ret(n);
		for(int i = 0; i < n; i++)
			ret[i][i] = 1;
		return ret;
	}
	if(p % 2) return pow(a, p-1) * a;
	SquareMatrix half = pow(a, p/2);
	return half * half;
}

fib(i - 1)과 fib(i)를 포함하는 크기가 2인 열벡터를 Ci라 하자.
Ci =	[fib(i - 1)	]	//Ci,0 : 열벡터의 첫번째 요소	
		[fib(i)		]	//Ci,1 : 열벡터의 두번째 요소
Ci+1 =	[fib(i)		]	=	[fib(i)				]	= [Ci,1			]	= [0 1] * Ci
		[fib(i + 1)	]		[fib(i-1) + fib(i)	]	  [Ci,0 + Ci,1	]	  [1 1]
Cn	= W*Cn-1	= W*W*Cn-2	= W*W*W*Cn-3 = ... = W^(n-1) * C1 //C1 는	[0] //!!!! C0은 존재 못하지요
																		[1]	//왜냐면 fib(0 -1)은 없으니까~
Cn	= [fib(n-1)	] = W^(n-1) * [fib(0)] = W^(n-1) * [0] = [W^(n-1)0,1]
	  [fib(n)	] =			  [fib(1)] =		   [1]	 [w^(n-1)1,1]
W^(n-1) = [ A B ]	//여기서 B, D가 Cn을 구성하는 군!!!!
		  [ C D ]	//D 는 구하고자 하는 해가 된다.

//코드 9.26 피보나치 수열의 특정항을 구하는 빠른 행렬 제곱 알고리즘
//A^n을 구한다. 이때 각 계산은 모두 100000에 대한 나머지로 한다.
//n : 0 1 2 3 4 ...
//    0 1 1 2 3 ...
SquareMatrix pow(const SquareMatrix& A, int n);
int fib3(int n) {
	if(n == 0) return 0;
	SquareMatrix W(2);
	W[0][0] = 0;
	W[0][1] = W[1][0] = W[1][1] = 1;
	return pow(W, n-1)[1][1];
}


//p357 회전초밥 문제를 해결하는 메모이제이션 동적 계획법 알고리즘
//테스트 케이스 C(1<=C<=5), 초밥의 종류 n(1<=n<=20), 예산m(1<=m<=1000000000)
//, 초밥의 가격과 선호도.  => 각 테스트 케이스별로 한줄마다 가능한 선호도의 최대합을 구한다.
//음식의 최대값 20000, 100의 배수임
2
6, 10000 //6개의 음식, 10000원 예산
2500 7 //가격과 선호도
3000 9
4000 10
....
//각 음식은 한개씩만 가져갈 수 있는 것이 아니라 무한정 가져갈 수 있다.
int n, m, price[20], pref[20]; //n음식수, m 예산
int cache[MAX_BUDGET+1]; //MAX_BUDGET 이 10억이라 좆됨...
//budget만큼의 예산으로 초밥을 먹어서 얻을 수 있는 최대 선호도
"pack 문제랑 차이점 비교해 보라"
int sushi(int budget) {
	//메모이제이션
	int& ret = cache[budget];
	if(ret != -1) return ret;
	ret = 0;
	for (int dish = 0; dish < n; ++dish) {
		//if (budget < price[dish]) continue;
		if (budget >= price[dish])
			ret = max(ret, sushi(budget - price[dish]) + pref[dish]);
	}
	return ret;
}

//반복적 동적 계획법
"sushi(budget)을 계산하기 위해 우리는 budget에서 초밥 한 접시의 가격을 뺀 값들에 대해 재귀호출을 합니다." 
"따라서 budget을 1부터 m까지 순회하면서 최대 선호도를 계산하는 형식으로 변경할수 있음"
maxFavor[money] = max_{i..n}{Favor[money - price[i]] + favor[i]}
int c[MAX_BUDGET+1];//십업 + 1
int sushi2() {
	int ret = 0;
	c[0] = 0; //책에는 없었는데 있어야 한다고 본다. 아님 main에서 0으로 memset처리하던가
	//budget이 0부터 시작안하는 이유는 0이면 if문에서 제거되는 쓸모없는 구문이니
	for(int budget = 1; budget <= m; ++budget) {
		c[budget] = 0;
		for (int dish = 0; dish < n; ++dish)
			if (budget >= price[dish])
				c[budget] = max(c[budget], c[budget - price[dish]] + pref[dish]);
		ret = max(ret, c[budget]);
	}
	return ret;
}

//슬라이딩 윈도우 적용
"c[budget]을 계산하기 위해 필요한 값은 전부 c[budget - price[dish]] 꼴"
int c[20001]; //최대 음식 가격 20000
int sushi2() {
	int ret = 0;
	c[0] = 0;
	for (int budget = 1; budget <= m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++dish)
//예산이 12인 상태에서 음식이 3이고 최대 음식이 5라면
//budget[12 % 6] = budget[(12 - 3) % 6] + pref[dish] = budget[3] + pref[dish];
			if (budget >= price[dish])
				cand = max(cand, 
							c[(budget - price[dish]) % 20001] + pref[dish]);
		
		c[budget % 20001] = cand;
		ret = max(ret, cand);
	}
}

배낭채우기
//메모리를 줄이는 반복적 동적 계획법을 적용하자.
//1. 슬라이딩 윈도우, 2. 예산과 음식의 가격은 이미 100으로 나눔
//고로 c는 201개만 있으면 됨
int n, m, price[20], pref[20];
int c[201];
//최대 만족도의 합을 반환한다.
//m과 price[]는 이미 100으로 나뉘어 있다고 가정한다.
int sushi3() {
	int ret = 0;
	c[0] = 0;
	for (int budget = 1; budget <= m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++dish)
			if (budget >= price[dish])
				cand = max(cand,
							c[(budget - price[dish]) % 201] + pref[dish]);
		c[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}

//내소스 3000ms 걸림...ㅠㅠ
const int MOD = 20001
int dp[MOD];
int price[20], need[20];
int main() {
	int cs; cin >> cs; 
	rep(cc, cs) {
		int n, m;
		cin >> n >> m;	//종류, 예산
		rep(i, n) cin >> price[i] >> need[i];
		memset(dp, 0, sizeof(dp));
		int sol = 0;
		for (int i = 0; i < m + 1; i += 100) {
			"나의 실수!!!!"
			//if (i >= 100)
			//	dp[i % MOD] = dp[(i - 100) % MOD];	
			//이렇게 하고 나서 sol 대신 dp[m]을 출력하면 답이 될수 없다.
			//m은 100으로 나누어 떨어지지 않기 때문이다.
			//외부에 sol두는게 깔끔하고 낫군요.
			"외부에 sol을 안두어도 풀수 있어요!!!!
			rep(j, n) {
				if (i >= price[j])
					dp[i % MOD] = max(dp[i % MOD], dp[(i - price[j]) % MOD] + need[j]);
				sol = max(sol, dp[i % MOD]);
			}
		}
//		cout << dp[m % MOD] << endl; 좆됨
		cout << sol << endl;
	}
	return 0;
}

//이래도 오답이래... 이유는 뭘까? 그것도 2500ms에서 걸렸으..
int dp[MOD];
int price[20], need[20];
int main() {
	int cs; cin >> cs; 
	rep(cc, cs) {
		int n, m;
		cin >> n >> m;	//종류, 예산
		rep(i, n) cin >> price[i] >> need[i];
		memset(dp, 0, sizeof(dp));
		m = ((m + 99) / 100) * 100;	//올림식임!!!! 망한부분
		for (int i = 0; i < m + 1; i += 100) {
			rep(j, n) {
				if (i >= price[j])
					dp[i % MOD] = max(dp[i % MOD], dp[(i - price[j]) % MOD] + need[j]);
			}
		}
		cout << dp[m % MOD] << endl;
	}
	return 0;
}

정올 배낭채우기는 이래해도 통과됨//통과하는게 당연한데 말야..
int dp[10001];
int price[1001], need[1001];
int main() {
	//freopen("input.txt", "r", stdin);
	//int cs; cin >> cs; 
	//rep(cc, cs) {
		int n, m;
		cin >> n >> m;	//종류, 예산
		rep(i, n) cin >> price[i] >> need[i];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < m + 1; i++) {
			rep(j, n) {
				if (i >= price[j])
					dp[i] = max(dp[i], dp[(i - price[j])] + need[j]);
			}
		}
		cout << dp[m];
	//}
	return 0;
}
//알고스팟 통과됨 ㅠㅠㅠㅠㅠㅠㅠㅠ
int dp[MOD];
int price[20], need[20];
int main() {
	//int test = 2147483647;	//int 형 최대 범위임
	//int tmp = 2147483647 + 99;	//음수
	//int tt = (((long long)test + 99) / 100) * 100;	//이래도 음수..//버림식이 아니라 올림이였어..
	//long long oo = (((long long)test + 99) / 100) * 100;	//2147483700
	//int uu = test / 100 * 100;	//2147483600
	//freopen("input.txt", "r", stdin);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n, m;
		cin >> n >> m;	//종류, 예산
		rep(i, n) cin >> price[i] >> need[i];
		memset(dp, 0, sizeof(dp));
		//m = ((m + 99) / 100) * 100;	//m이 음수가 된다...ㅠㅠ
		//m = (((long long)m + 99) / 100) * 100;	//이래도 음수임...ㅠㅠ 악악악
		m = m / 100 * 100;	//... 나는 바보다...
		for (int i = 0; i < m + 1; i += 100) {
			rep(j, n) {
				if (i >= price[j])
					dp[i % MOD] = max(dp[i % MOD], dp[(i - price[j]) % MOD] + need[j]);
			}
		}
		cout << dp[m % MOD] << endl;
	}
	return 0;
}

책과 같은 구현인디도 속도가 느리다. 3000ms 나 걸림...
cubelover의 경우 4ms 밖에 안 걸렸다..


//지니어스 
/*
------ 입력 ------
3//테스트 케이스
3 6 3	//3: mp3곡수, 6: 6분30초가 지남을 의미, 3: 태윤이가 좋아하는 곡의 수
4 4 2	//각 곡의 길이
0.18	0.40	0.42	//각 행의 합은 '1' => 0번곡 뒤에 0번 올 확률: 0.18, 1번: 0.40, 2번: 0.42
0.15	0.46	0.39
0.58	0.23	0.19
0 1 2	//태윤이가 좋아하는 곡의 번호
...	//나머지 테스트 입렵

------ 출력 ------
0.42360000	0.49660000	0.07980000	//처음에 0번곡을 튼지 6분 30초가 지난 뒤 각 곡들이 재생되고 있을 확률
...	//나머지 테스트 출력
*/

struct SquareMatrix {
	int N;
	vector<vector<double> > v;
	SquareMatrix(int _N);
	~squareMatrix();
	static SquareMatrix identity(int N);
	SquareMatrix operator * (const SquareMatrix& rhs) const;
	SquareMatrix pow(int n) const;
	double* operator [] (int idx);
};

SquareMatrix::SquareMatrix(int _N) {
	N = _N;
	v.resize(N, vector<double>(N, 0));
}

SquareMatrix::~SquareMatrix() {
}

SquareMatrix SquareMatrix::identity(int N) {
	SquareMatrix ret = SquareMatrix(N);
	for(int i = 0; i < N; i++) ret.v[i][i] = 1;
	return ret;
}

SquareMatrix SquareMatrix::operator * (const SquareMatrix& rhs) const {
	assert(N == rhs.N);
	SquareMatrix ret = SquareMatrix(N);
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				ret.v[i][j] += v[i][k] * rhs.v[k][j];
	return ret;
}

SquareMatrix SquareMatrix::pow(int n) const {
	if (n == 0) return identity(N);
	if (n % 2 > 0) return (*this) * pow(n-1);
	SquareMatrix half = pow(n/2);
	return half * half;
}

double* SquareMatrix::operator [] (int idx) {
	return &v[idx][0];
}

int n, k, length[50];
double T[50][50];

vector<double> getProb1() {
	//c[time][song] = time분 후에 song번 노래가 시작할 확률
	double c[5][50];

	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;
	for (int time = 1; time <= k; ++time)
		for (int song = 0; song < n; ++song) {
			double& prob = c[time % 5][song];
			prob = 0;
			//현 곡(song)이 현 시간(time)에 시작 할 확률
"start(time, song) = sigma[..prev](start(time - L[prev], prev) * T[prev][song]) !!!!"
			for (int last = 0; last < n; last++) //이전 마지막 곡
				prob += c[(time - length[last] + 5) % 5][last] //[현시간 - 이전마지막곡 재생시간][이전 마지막곡]
						* T[last][song];	//이전 마지막 곡 -> 현재 시작곡
		}
	vector<double> ret(n);

	//song 번 노래가 재생되고 있을 확률을 계산한다.
	//k가 6이라 가정하여 6분 30초 뒤에 2번곡(4분짜리)가 재생될 확률은
	// => "3분에 시작할 확률 + 4분에.. + 5분에.. + 6분에 시작할 확률"
	for (int song = 0; song < n; song++)
		//song번 노래가 시작하는 지점을 찾아(song 번 노래의 길이 이용) 모두 더한다.
		for (int start = k - length[song] + 1; start <= k; start++)
			//return ret[song] += c[start % 5][song]; //내 생각에는 c[(start + 5) % 5][song] !!!! 책의 오타로 보임
			ret[song] += c[(start + 5) % 5][song];
	return ret;
}

void test(){
Ctime = |start(time-3, 0)	|		Ctime+1 =	|start(time-2, 0)	|
		|...				|					|...				|
		|start(time-3, n-1)	|					|start(time-2, n-1)	|

		|start(time-2, 0)	|					|start(time-1, 0)	|
		|...				|					|...				|
		|start(time-2, n-1)	|					|start(time-1, n-1)	|
		
		|start(time-1, 0)	|					|start(time, 0)		|
		|...				|					|...				|
		|start(time-1, n-1)	|					|start(time, n-1)	|
		
		|start(time, 0)		|					|start(time+1, 0)	|
		|...				|					|...				|
		|start(time, n-1)	|					|start(time+1, n-1)	|

		곡의 최대 길이가 4분이므로 4 * N인 열벡터를 만들수 있다.
Ctime만 있으면 Ctime+1을 만들 수 있음을 알수 있다!!!!
즉 Ctime+1 = W * Ctime가 성립하는 행렬 W만 만들면 이 문제를 풀수 있습니다.

3분짜리 한곡 있는것
Ctime = |start(time-3, 0)	|		Ctime+1 =	|start(time-2, 0)	|
		|start(time-2, 0)	|					|start(time-1, 0)	|
		|start(time-1, 0)	|					|start(time, 0)		|
		|start(time, 0)		|					|start(time+1, 0)	|

Ctime+1 = W * Ctime =	| 0 1 0 0 |
						| 0 0 1 0 |
						| 0 0 0 1 |
						| 0 1 0 0 | //한곡이라서 1임
						//Ctime의 두번째 요소가 Ctime+1의 마지막 요소에 사용된다. 
						// start(time-2, 0) -> start(time+1, 0) 3분짜리 한곡이기 때문이다.
						//네번째 열벡터의 요소들이 답으로 사용된다.
k = 1인 경우 W^1[3][3] = k		시간에 0번곡이 시작될 확률 = 0
			 W^1[2][3] = k - 1	시간에 0번곡이 시작될 확률 = 1
			 W^1[1][3] = k - 2	시간에 0번곡이 시작될 확률 = 0
			 W^1[0][3] = k - 3	시간에 0번곡이 시작될 확률 = 0

3분짜리 1곡(0번), 4분짜리 1곡(1번)
확률 | 0	1 |
  0	  0.3  0.7
  1   0.4  0.6

Ctime =	|start(time-3, 0)	|		Ctime+1	=	|start(time-2, 0)	|
		|start(time-3, 1)	|					|start(time-2, 1)	|
		|start(time-2, 0)	|					|start(time-1, 0)	|
		|start(time-2, 1)	|					|start(time-1, 1)	|
		|start(time-1, 0)	|					|start(time, 0	)	|
		|start(time-1, 1)	|					|start(time, 1	)	|
		|start(time, 0	)	|					|start(time+1, 0)	|
		|start(time, 1	)	|					|start(time+1, 1)	|
Ctime+1 = W * Ctime 을 만족하는 W를 만들면 OK!!!! (W는 4*2 크기를 가진 정방행렬(8 by 8)이 된다)
S(t+1, 0) = sum{ S(t+1-3, 0) * T[0][0],		// (t+1) 의 3분전에 0번곡이 시작하고 * (t+1)에서 0번곡이 끝나고 0번곡이 시작할 확률
				 S(t+1-4, 1) * T[1][0] }	// (t+1) 의 4분전에 1번곡이 시작하고 * (t+1)에서 1번곡이 끝나고 0번곡이 시작할 확률
S(t+1, 1) = sum{ S(t+1-3, 0) * T[0][1],
				 S(T+1-4, 1) * T[1][1] }

| S(t-2, 0) |		| 0 0   1   0 0 0 0 0 |		| S(t-3, 0) | 
| S(t-2, 1) |		| 0 0   0   1 0 0 0 0 |		| S(t-3, 1) |
| S(t-1, 0) |		| 0 0   0   0 1 0 0 0 |		| S(t-2, 0) |
| S(t-1, 1) |	=	| 0 0   0   0 0 1 0 0 |	*	| S(t-2, 1) |
| S(t  , 0) |		| 0 0   0   0 0 0 1 0 |		| S(t-1, 0) |
| S(t  , 1) |		| 0 0   0   0 0 0 0 1 |		| S(t-1, 1) |
| S(t+1, 0) |		| 0 T10 T00 0 0 0 0 0 |		| S(t  , 0) | 
| S(t+1, 1) |		| 0 T11 T01 0 0 0 0 0 |		| S(t  , 1) |
//W의 마지막 두(곡의 수) 행의 원소들은 음악의 길이에 따라 결정된다!!!!

현재 = 10분 경과한 시점
Ctime(10) = W^10 * Ctime(0)	=	| ~ ~ ~ ~ ~ ~ a ~ |		| 0 |		| a |	//(현재 - 3)분 시점에 0번 노래가 시작할 확률
								| ~ ~ ~ ~ ~ ~ b ~ |		| 0 |		| b |	//(현재 - 3)분 시점에 1번 노래가 시작할 확률
								| ~ ~ ~ ~ ~ ~ c ~ |		| 0 |		| c |	//현재 - 2
								| ~ ~ ~ ~ ~ ~ d ~ |	*	| 0 |	=	| d |	//현재 - 2
								| ~ ~ ~ ~ ~ ~ e ~ |		| 0 |		| e |	//현재 - 1
								| ~ ~ ~ ~ ~ ~ f ~ |		| 0 |		| f |	//현재 - 1
								| ~ ~ ~ ~ ~ ~ g ~ |		| 1 |		| g |	//현재 시점에 0번 노래가 시작할 확률
								| ~ ~ ~ ~ ~ ~ h ~ |		| 0 |		| h |	//현재 시점에 1번 노래가 시작할 확률
								"열은 고정되어 있고 행부분으로 답을 찾는다"

//song 번 노래가 재생되고 있을 확률을 계산한다.
for (int song = 0; song < n; ++song)
	//song 번 노래가 시작했을 시간을 찾아 모두 더한다.
	for (int start = 0; start < length[song]; ++start)
		ret[song] += Wk[(3 - start) * n + song][3*n];	//!!!!


6분 30 초 경에 0번(3분짜리) 노래가 재생될 확률
sum	{6분에 시작,
	5분에 시작,
	4분에 시작}
//	3분에 시작 // 이놈은 안됨

6분 30 초 경에 1번(4분짜리) 노래가 재생될 확률
sum	{6분에 시작,
	5분에 시작,
	4분에 시작,
	3분에 시작}

	return;
}

//k분 30초 후에 각 곡이 재생되고 있을 확률을 반환한다.
//bigO : O((nl)^3 * lgk) : n 곡의 수, 곡의 최대길이, k 지나간 시간
vector<double> getProb2() {
	SquareMatrix W(4*n);	//노래 최대 길이(4) * 노래 갯수(n)
	//첫 3*n개의 원소는 그대로 복사해 시프트(위로 올린다.)한다
	for (int i = 0; i < 3 * n; ++i)
		W[i][i+n] = 1.0;
	//마지막 n개의 원소는 이전 원소들의 선형 결합으로 이루어진다.
	for (int i = 0; i < n; ++i)
		//C[time+1][i] = sum { C[time+1-length[j]][j] * T[j][i] }
		//C[time+1-length[j]][j] : 현시간(time+1)에서 j곡 길이만큼 과거에 j곡이 시작할 확률
		//T[j][i] : 현시간(time+1) 에서 j곡이 끝나고 i곡으로 시작할 확률
		for (int j = 0; j < n; ++j)
			W[3*n+i][(4-length[j])*n+j] = T[j][i];	//W[][] = 행: 현재의 곡, 열: 과거의 곡 //이렇게 생각하니 기억이 잘됨
		   "W[3*n+i][(4-length[j])*n+j] = T[j][i]; //!!!!핵심"
	
	SquareMatrix Wk = W.pow(k);
	vector<double> ret(n);
	// song번 노래가 재생되고 있을 확률을 계산한다.
	for (int song = 0; song < n; ++ song)
		// song번 노래가 시작했을 순간을 모두 찾아 더한다.
		for (int start = 0; start < length[song]; ++ start)
			ret[song] += Wk[(3-start)*n + song][3*n]; 
			"열은 고정되어 있고 행부분으로 찾는다."
		//n 이 1개이고(총 곡 수가 1개) 0번 곡의 재생시간이 4분인 경우: 0번 곡에 대한 답 (아래 합이 됨)
		//start = 0 => k	분에 시작 Wk[3][3]
		//start = 1 => k-1	분에 시작 Wk[2][3]
		//start = 2 => k-2	분에 시작 Wk[1][3]
		//start = 3 => k-3	분에 시작 Wk[0][3]

		//n 이 2개이고(총 곡 수가 2개) 1번 곡의 재생시간이 3분인 경우: 1번 곡에 대한 답 (아래 합이 됨)
		//start = 0 => k	분에 시작 Wk[3*2 + 1][6] = Wk[7][6]
		//start = 1 => k-1	분에 시작 Wk[2*2 + 1][6] = Wk[5][6]
		//start = 2 => k-2	분에 시작 Wk[1*2 + 1][6] = Wk[3][6]
		

	return ret;
}

/*
//3분짜리 1곡(0번), 4분짜리 1곡(1번) : n = 2, lengthMax = 4

T
확률 0    1
0	0.3  0.7 
1   0.4  0.6

Ctime+1 = W * Ctime
[s(t-2, 0)]   [    0     0     1     0	0	0	0	0 ]   [s(t-3, 0)]
[s(t-2, 1)]   [    0     0     0     1	0	0	0	0 ]   [s(t-3, 1)]
[s(t-1, 0)]   [    0     0     0     0	1	0	0	0 ]   [s(t-2, 0)]
[s(t-1, 1)]   [    0     0     0     0	0	1	0	0 ]   [s(t-2, 1)]
[s(t  , 0)] = [    0     0     0     0	0	0	1	0 ] * [s(t-1, 0)]
[s(t  , 1)]   [    0     0     0     0	0	0	0	1 ]   [s(t-1, 1)]
[s(t+1, 0)]   [    0 T[1][0] T[0][0] 0	0	0	0	0 ]   [s(t  , 0)]
[s(t+1, 1)]   [    0 T[1][1] T[0][1] 0	0	0	0	0 ]   [s(t  , 1)]
*/

bool eq(double a, double b) {
	return fabs(a-b) <= le-7;
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int cc = 0; cc < cases; ++cc) {
		int m;
		scanf("#d #d #d", &n, &k, &m);
		for (int i = 0; i < n; i++) scanf("&d", &length[i]);

		vector<double> sol2 = getProb2();
		
		for (int i = 0; i < m; i++) {
			int song;
			scanf("%d", & song);
			printf("%s%.8lf", (i ? " " : ""), sol2[song]);
		}
		printf("\n");
	}
}


https://leetcode.com/contest/weekly-contest-182/ranking/1/	// kmjp 의 답
#define FOR(x, to) for (x=0;x<(to);x++)
#define ZERO(a) memset(a, 0, sizeof(a))
#defien MINUS(a) memset(a, 0xff, sizeof(a))
int stt[52][26];	
// stt[30][3] = 0~29 idx 까지 일치하고 30번째는 알파벳  'a'+3: 'd' 로 끝날때 부분 일치 문자열 크기
// stt[0][4] = 0번째에서 알파벳 'e' 로 끝날때 일치 문자열 크기
const char base = 'a';
void CreateSTT(string& pat) {	// 이런거 빨리 짜는 능력도 필요하다 !!!!!!!! 
	int x, y, z, l;
	ZERO(stt);
	l = pat.size();
	FOR(x,l) {
		FOR(y,26) {
			if (pat[x] == base + y) 
				stt[x][y] = x + 1;	// x까지 끝나며 알파벳 y로 끝난 경우 최대 매칭
			else {
				// pat = "aabacde...", x = 4, y = 0 : pre = "aabaa"
				string pre = pat.substr(0, x) + (char)(base + y);
				// x가 0인 경우 base+y 가 글자가 됨
				for (z = 1; z <= x; z++) {
					if (pre.substr(pre.size() - z) == pat.substr(0, z)) stt[x][y] = z;
					// z가 1인 경우 pre.substr(pre.size() - 1) = "a"	// suffix
					// pat.substr(0, 1) = "a"	// prefix
					
					// z가 2인 경우 pre.substr(pre.size() - 2) = "aa"
					// pat.substr(0, 2) = "aa"
				}
			}
		}
	}
	FOR(y, 26) stt[l][y] = l;	// 이걸 넣으서 밑에 recursion 을 간략화 했다.
}
int N;
ll dp[505][52][2][2];
const ll mod = 1000000007;
string S1, S2, E;
class Solution {
public:
	ll hoge(int cur, int ev, int mo, int le) {
		if (cur == N) return (ev < E.size());
		ll& ret = dp[cur][ev][mo][le];
		if (ret != -1) return ret;
		ret = 0;
		int i;
		FOR(i,26) {
			if (mo == 0 && i < S1[cur] - 'a') 
				continue;	// 이전 진행된 부분이 S1 과 equal 이고 현재 S1보다 작게 만들 경우
			if (le == 0 && i > S2[cur] - 'a') 
				continue;	// 이전 진행된 부분이 S2 과 equal 이고 현재 S2보다 크게 만들 경우
			int nextMO = mo | (i > S1[cur] - 'a');	// 다음은 항상 큰 문자열인지 정하기
			int nextLE = le | (i < S2[cur] - 'a');	// 다음은 항상 작은 문자열인지 정하기
			int nextEV = stt[ev][i];	// ev 가 E.size() 이면 항상 ev 로 세팅됨
			ret += hoge(cur+1, nev, nmo, nle);
		}
		ret %= mod;
		return ret;
	}
	int findGoodStrings(int n, string s1, string s2, string evil) {
		MINUS(dp);
		CreateSTT(evil);
		S1 = s1;
		S2 = s2;
		E = evil;
		N = n;
		return hoge(0, 0, 0, 0);
	}
};



//-------------------------------------- 탐욕법 -----------------------------//
//p369 회의실 예약 
//각 회의는 [begin, end) 구간 동안 회의실을 사용한다
//회의가 겹치지 않고 수행할 수 있는 가장 많은 회의갯수를 구한다.
int n;
int begin[100], end[100];
int schedule() {
	//일찍 끝나는 순서대로 정렬한다.
	vector<pair<int, int> > order;
	for (int i = 0; i < n; ++i)
		order.push_back(make_pair(end[i], begin[i]));
	sort(order.begin(), order.end());
	//earliest: 다음 회의가 시작할 수 있는 가장 빠른 시간
	//selected: 지금까지 선택한 회의의 수
	int earliest = 0, selected = 0;
	for (int i = 0; i < order.size(); ++i) {
		int meetingBegin = order[i].second;
		int meetingEnd	 = order[i].first;
		
		if (earliest <= meetingBegin) {
			//earliest를 마지막 회의가 끝난 시간 이후로 갱신한다.
			earliest = meetingEnd;
			++selected;
		}
	}
	return selected;
}


//p375 출전 순서 정하기 문제를 해결하는 탐욕적 알고리즘
int order(const vector<int>& russian, const vector<int>& korean) {
	int n = russian.size(), wins = 0;
	//아직 남아 있는 선수들의 레이팅
	multiset<int> ratings(korean.begin(), korean.end());
	//multiset 중복가능한 집합자료구조로 그 구현은 트리이다.!!!!
	//삽입, 삭제, 검색이 logn에 수행되는 장점이 있다.
	for (int rusI = 0; rusI < n; ++rusI) {
		//가장 레이팅이 높은 선수가 이길 수 없는 경우
		//가장 레이팅이 낮은 선수와 경기시킨다.
		if (*ratings.rbegin() < russian[rusI]) //!!!! rbegin = 가장 큰 값, begin 루트 = 가장 작은 값
			ratings.erase(ratings.begin());
		//이 외의 경우 이길 수 있는 선수 중 가장 레이팅이 낮은 선수와 경기시킨다.
		else {
			ratings.erase(ratings.lower_bound(russian[rusI]));
			//인자russian[rus] 로 들어오는 값 이상(동일한것 포함)들 중에서 가장 작은 값에
			//해당하는 인덱스를 받아서 지운다.
			//동일점수이면 한국팀이 이긴다고 지문에 전제조건으로 있었음
			++wins;
		}
	}
	return wins;
}
lower_bound 값을 확인 하고 싶어서 int형에 대입했는데 컴파일 오류남
lower_bound가 무엇을 리턴하노? iterator를 리턴합니다.
해당 값을 알고 싶다면 int check = *ratings.lower_bound(russians[rus]); 요렇게 하삼
3이상이면서 가장 작은 값을 구하라
int check = *ratings.lower_bound(3);

//아래는 사이트 소스 코드이며 multiset을 안쓸때 얼마나 짜증나는 코드를 작성해야 하는지를 보여준다.
//가독성도 없다. 해석하지 말고 무시해라.. 안 좋은 코드라 생각한다.
int greedy(const vector<int>& russian, vector<int> korean) {
	int n = russian.size();
	vector<bool> taken(n, false);
	sort(korean.begin(), korean.end(), greater<int>());
	int ret = 0;
	for (int kor = 0; kor < n; ++kor) {
		int opponent = -1;
		for (int rus = 0; rus < n; ++rus)
			if (!taken[rus] && russian[rus] <= korean[kor] &&
				(opponent == -1 || russian[opponent] <= russian[rus]))
				opponent = rus;
		if (opponent == -1) break;
		++ret;
		taken[opponent] = true;
	}
	return ret;
}
// 김동현 코드.. 으으.. 깔끔하네..
int main() {
	int C, N;
	cin >> C;
	while (C--)	{
		cin >> N;
		vector<int> R(N), K(N);
		for (auto& n : R) cin >> n;
		for (auto& n : K) cin >> n;
		sort(begin(R), end(R));
		sort(begin(K), end(K));
		int r = 0, k = 0;
		while (k < N)
		{
			if (R[r] <= K[k]) r++;
			k++;
		}
		cout << r << endl;
	}
	return 0;
}

//도시락 데우기
2
3
2 2 2 //각 도시락을 데우는데 걸리는 시간
2 2 2 //각 도시락을 먹는데 걸리는 시간
3
1 2 3
1 2 1

출력
8
7
//p380 도시락 데우기 문제를 해결하는 탐욕적 알고리즘
"전체를 만드는 시간의 합은 같다"
"먹는 시간과 만드는 시간이 많이 겹치게 하려면"
"먹는데 오래걸리는 것부터 먼저 만들자"
int n, e[MAX_N], m[MAX_N]; //e : 먹는 시간, m : 만드는 시간
int heat() {
	//어느 순서로 데워야 할지를 정한다.
	vector<pair<int, int> > order;
	for (int i = 0; i < n; ++i)
		order.push_back(make_pair(-e[i], i));
	sort(order.begin(), order.end());
	//해당 순서대로 데워먹는 과정을 시물레이션한다.
	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; ++i) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
		//ret : 이전 도시락 처리하는데 총걸리는 시간
		//begin + e[box] : 현 도시락까지 만드는 데 걸리는 시간 + 현 도시락 먹는데 걸리는 시간
		//3번 도시락이 먹는데 졸라게 오래 걸린다면 => ret가 졸라크면
		//4번 도시락 까지 만들고 먹는 시간이 무시되겠죠
	}
	return ret;
}

//greater를 설정할 때 주의점
using namespace std;
typedef pair<int, int> myPair; //typedef 를 쓸 경우 std 뒤에 오도록 해라
void main() {
	vector<pair<int, int> > order;
	order.push_back(make_pair(1, 3));
	order.push_back(make_pair(1, 5));
	order.push_back(make_pair(3, 4));
	//sort(order.begin(), order.end(), greater< pair<int, int> >()); //greater 뒤에 ()를 빼먹지 마라
	sort(order.begin(), order.end(), greater< myPair >());

}


//p386 문자열 합치기 문제를 해결하는 탐욕적 알고리즘(매 단계마다 가장 짧은 두 문자열을 하나로 합침)
//문자열들의 길이가 주어질 때 하나로 합치는 최소 비용을 반환한다.
	{al, go, spot}
	al + go : 4		, algo + spot : 8 => 총 12
	al + spot : 6	, alspot + go : 8 => 총 14
int concat(const vector<int>& lengths) {
	//최소 큐를 선언한다.(작은 값이 위로 올라오도록)
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < lengths.size(); ++i)
		pq.push(length[i]);
	int ret = 0;
	//원소가 하나 이상 남은 동안 반복한다.(두개 이상이겠지..책 오타같다.)
	while (pq.size() > 1) {
		//가장 짧은 문자열 두 개를 찾아서 합치고 큐에 넣는다.
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;	
	}
	return ret;
}

// 부동소수점 자료형에서 현 숫자보다 다음의 숫자를 알려면
std::nextafter 함수를 사용해라.

//atan 참고
//atan(y/x) : 리턴 범위(-π/2, π/2)
//atan2(y, x) : 리턴 범위(-π, π]
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
//p388 미나스 아노르 책보고 적자
//성벽은 (0, 0)을 중심으로 하는 반지름 8인 원으로 , 모든 초소는 이 성벽 위에 위치
n: 초소의 개수(1 <= n <= 100)
yi, xi, 감시범위(ri : 0 <= ri <= 16.001
//p392: 미나스 아노르 문제의 원들을 중심각의 구간으로 바꾸기
const double pi = 2.0 * acos(0);	
// 		3.1415926535897931	실제 소수점은 3.1415926535897932	// 15번째 자리에서 다르니까 꽤 정확

int n;
double y[100], x[100], r[100];	// r은 반지름이다. 지름이 아님.
pair<double, double> ranges[100];
void convertToRange() {
	rep(i,n) {
		double loc = fmod(2*pi + atan2(y[i], x[i]), 2*pi); //[0..2pi)
		double range = 2.0 * asin(r[i]/2.0 / 8.0); //r[i]/2.0: 높이, 8.0:빗변
		//range의 최대값은 pi가 된다. (asin의 인자가 1인 경우)
		//만약 r[i]가 16.001이라면 asin에 1보다 큰 인자가 들어 오면 0을 리턴함..의도하지 않은 입력임
		//main문에서도 16.0을 초과하면 assert가 걸린다.
		ranges[i] = mp(loc-range, loc+range);
	}	
	//각 구간을 시작 위치가 작은 것부터 오게끔 정렬한다.
	sort(ranges, ranges+n);
}
"0, 2pi 처리가 까다롭다."
//p395 미나스 아노르 문제를 선형 문제로 변환해서 푸는 알고리즘
const int INF = 987654321;
int n;
pair<double, double> ranges[100];	//각 원이 덮는 중심각의 구간
//0을 덮을 구간을 선택하고 나머지를 선형(solveLinear함수)으로 푼다.
//bigO = n^2: for(n) * solveLinear
int solveCircular() {
	int ret = INF;
	//각 구간을 시작 위치의 오름차순으로 정렬한다.
	sort(ranges, ranges+n);
	//0을 덮을 구간을 선택하자.
	for (int i = 0; i < n; ++i)
		if (ranges[i].first <= 0 || ranges[i].second >= 2*pi) {
			//이 구간이 덮는 부분을 빼고 남는 중심각의 범위는 다음과 같다.(정규화)
			double begin	= fmod(ranges[i].second, 2*pi);
			double end		= fmod(ranges[i].first + 2*pi, 2*pi); //!!!!
			//[begin, end]선분을 주어진 구간을 사용해서 덮는다.
			ret = min(ret, 1 + solveLinear(begin, end));
		}
	return ret;
}
//p396 선분을 덮는 최소 구간 수를 계산하는 탐욕적 알고리즘
//[begin, end]구간을 덮기 위해 선택할 최소한의 구간 수를 반환한다.
//ranges는 시작 위치의 오름차순으로 정렬되어 있다고 가정하자.
int solveLinear(double begin, double end) {
	int used = 0, idx = 0;
	//덮지 못한 선분이 남아 있는 동안 계속한다.
	"분할상환분석 !!!!" "while이 두개지만 bigO = n이 된다."
	while (begin < end) {
		//begin보다 이전에 시작하는 구간 중 가장 늦게 끝나는 구간을 찾는다.
		double maxCover = -1;
		while (idx < n && ranges[idx].first <= begin) {
			maxCover = max(maxCover, ranges[idx].second);
			++idx;
		}
		//덮을 구간을 찾지 못한 경우
		if (maxCover <= begin) return INF;
		//선분의 덮인 부분을 잘라낸다.
		begin = maxCover;
		++used;
	}
	return used;
}
//첨부된 소스 , 16이상의 입력은 예외처리되도록 수정함
int main() {
	int cs; cin >> cs;
	rep(cc,cs) {
		cin >> n;
		bool determined = false;
		rep(i,n) {
			cin >> y[i] >> x[i] >> r[i];
			assert(fabs(8.0 - hypot(y[i], x[i])) < 1e-8);
			assert(0 <= r[i] && r[i] <= 16.0);
			//입력에선 반지름이 16미만이라고 하넹.. 책 문제에선 16.001 이하라고 했으니
			if (r[i] >= 16.0) {
				determined = true;
				break;
			}
		}
		if (determined) {
			cout << 1 << endl;
			continue;
		}
		converToRange();
		int ret = solveCircular();
		if (ret == 987654321)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ret << endl;
	}
}

//-----------------------------11장 조합탐색----------------------------//
p403 TSP를 해결하는 완전 탐색의 구현
const double INF = 1e200;
const int MAX = 30;
int n;
double dist[MAX][MAX];	//두 도시간의 거리를 저장하는 배열
//지금까지 찾은 최적해
double best;
//path: 지금까지 만든 경로
//visited: 각 도시의 방문 여부
//currentLength: 지금까지 만든 경로의 길이
//나머지 도시들을 모두 방문하는 경로들을 만들어 보고 가능하면 최적해를 갱신한다.
void search(vector<int>& path, vector<bool>& visited, double currentLength) {
	//간단한 가지치기
	if (best <= currentLength) return;
	int here = path.back();
	//기저 사례: 모든 도시를 다 방문했을 때는 0번 도시로 돌아가고 종요한다.
	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0];
		return;
	}
	//다음 방문할 도시를 전부 시도해 본다.
	for (int next = 0; next < n; ++next) {
		if (visited[next]) continue;
		path.push_back(next);
		visited[next] = true;
		//나머지 경로를 재귀 호출을 통해 완성한다.
		search(path, visited, currentLength + dist[here][next]);
		visited[next] = false;
		path.pop_back();
	}
}
double solve() {
	//best를 매우 큰 값으로 초기화
	best = INF;
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}

//p408 단순한 휴리스틱을 이용한 가지치기의 구현
//각 도시에 인접한 간선 중 가장 짧은 것을 미리 찾아둔다.
double minEdge[MAX];
//가장 단순한 형태의 휴리스틱
double simpleHeuristic(vector<bool>& visited) {
	double ret = minEdge[0];	//마지막에 시작점으로 돌아갈 때 사용할 간선
	for (int i = 0; i < n; ++i)
		if (!visited[i])
			ret += minEdge[i];
	return ret;
}
void search(vector<int>& path, vector<bool>& visited, double currentLength) {
	//단순한 휴리스틱을 이용한 가지치기
	if (best <= currentLength + simpleHeuristic(visited)) return;
	//생략 ...
}
double solve() {
	//simpleHeuristic() 을 위한 초기화
	for (int i = 0; i < n; ++i) {
		minEdge[i] = INF;
		for (int j = 0; j < n; ++j)
			if (i != j) minEdge[i] = min(minEdge[i], dist[i][j]);
	}
	//.. 생략 ..
}

//p410 가까운 정점부터 방문하는 최적화의 구현
//각 도시마다 다른 도시들을 가까운 순서대로 정렬해 둔다.
vector<int> nearest[MAX];
void search(vector<int>& path, vector<bool>& visited, double currentLength) {
	//다음 방문할 도시를 전부 시도해 본다.
	for (int i =0; i < nearest[here].size(); ++i) {	//앞에선 도시 번호순이었으나
		int next = nearest[here][i];				//여기선 가까운 순으로 되어 있음
		//..생략..									//좀 더 짧은 거리의 후보답이 먼저 만들어짐
	}
}
double solve() {
	//nearest 초기화
	for (int i= 0;i < n; ++i) {
		vector<pair<double, int> > order;
		for(int j =  0; j < n; ++j) 
			if (i != j)
				order.push_back(make_pair(dist[i][j], j));
		sort(order.begin(), order.end());
		nearest[i].clear();
		//for (int j = 0; j < n - 1; ++j)	//그냥 order.size()만큼 반복으로 나타내면 좋았을 텐데
		for (int j = 0; j < order.size(); ++j) //요렇게 말이지 ㅋㅋ
			nearest[i].push_back(order[j].second);	//가까운 순서로 인덱스를 세팅한다.
	}
	//..생략..
}

//p412 지나온 경로를 이용하는 두 가지 가지치기 전략
//1) 현 path의 마지막 네 개의 도시 중 가운데 있는 두 도시의 순서를 바꿨을 때
//경로가 더 짧아지는지 여부를 반환한다.
"p - a - b - q VS p - b - a - q"
bool pathSwapPruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int p = path[path.size() - 4];
	int a = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	return dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q];
	//true를 리턴하면 현재 패스보다 짧은놈이 존재(swap시키보니)한다는 의미하므로
	//caller에서 가지치기 수행
}

//2) 현 path에서 시작 도시와 현재 도시를 제외한 path 의 부분 경로를
// 뒤집어 보고 더 짧아지는지 확인한다
bool pathReversePruning(const vector<int>& path) {
  if(path.size() < 3) return false;				// 왜 갯수가 3도 인정하냐
  int b = path[path.size() - 2];
  int q = path[path.size() - 1];
  for(int i = 0; i + 2 < path.size(); ++i) {	//솔직히 갯수가 3개면 의미가 없다.
    int p = path[i];
    int a = path[i + 1];
    // [.., p, a, ..., b, q] 를 [.., p, b, ..., a, q] 로 바꿔본다.
	"a - ... - b == b - ... - a " //양방향 거리가 같기 때문이다.
    if(dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q])
      return true;
  }
  return false;
}

pathSwapPruning 보단 pathReversePruning 이 성능이 좋음(거의 동적계획법 수준임)
void search(vector<int>& path, vector<bool>& visited, double currentLength) {
  int here = path.back();

  // 지나온 경로를 이용한 가지치기
  if(pathReversePruning(path)) return;
  ...;
}

//p415 MST휴리스틱의 구현
//상호 배타적 집합 자료 구조를 구현한다.	// {a, b, d}, {c, e} 이런 식임
											//만약 {a, b, c}, {c, d} 이면 c가 겹치기 때문에 위배
struct DisjointSet {
	//n개의 원소로 구성된 집합 자료 구조를 만든다.
	DisjointSet(int n);
	//here가 포함된 집합의 대표를 반환한다.
	int find(int here);
	//a가 포함된 집합과 b가 포함된 집합을 합친다.
	bool merge(int a, int b); //true 서로 다른 집함, false 같은 집합
};
//모든 도시간의 도로를 길이 순으로 정렬해 저장해 둔다.
vector<pair<double, pair<int, int> > > edges;	//튜플
"here와 시작점, 아직 방문하지 않은 도시들을 모두 연결하는 MST를 찾는다.!!!!"
double mstHeuristic(int here, const vector<bool>& visited) {
	//Kruskal's MST//응용한 거임: 시작점으로 돌아가야 함
	DisjointSet sets(n);
	double taken = 0;
	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != 0 && a != here && visited[a]) continue;	
		if (b != 0 && b != here && visited[b]) continue;
		if (sets.merge(a, b))
			taken += edges[i].first;
	}
	return taken;
}
double solve() {
	//edges 초기화
	edges.clear();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j) "주의!!!! a-b간선이 들어가면 b-a간선은 안들어감"
			edgs.push_back(make_pair(dist[i][j], make_pair(i, j)));
	sort(edges.begin(), edges.end());
	//...생략...
}
void search(vector<int>& path, vector<bool>& visited, double currentLength) {
  int here = path.back();

  // 지나온 경로를 이용한 가지치기
  if(pathReversePruning(path)) return;

  // MST 휴리스틱을 이용한 가지치기
  double estimation = blowUp * mstHeuristic(here, visited);	//blowUp = 1.0
  //휴리스틱의 반환 값이 항상 남은 실제 최단 경로의 길이 보다 작거나 같아야 함을 보장 해야합니다. 이런 방법들을
  //문제를 과소평가(underestimate)하는 휴리스틱, 혹인 낙관적인 휴리스틱(optimistic heuristic)라고 말합니다.)
  "현재 만들어진것보다 앞으로 만들놈의 최소값이 크거나 같다면 탈락"
  //이말은 estimation이 암만 남은걸 가지고 작은 경로를 만든다 한들 curruntLength가 이미 해를 벗어남을 의미하지요
  //혹은 해랑 같다면 best를 갱신할 필요가 없으니 가지치기 되는 거고요.
  if(best <= currentLength + estimation) return;
  ...  
}
//p418 부분적으로 메모이제이션을 사용하는 최적화의 구현
//남은 도시의 수가 CACHED_DEPTH 이하면 동적 계획법으로 바꾼다.
const int CACHED_DEPTH = 5;
//dp(here, visited) = cache[here][남은 도시의 수][VISITED]
map<int, double> cache[MAX][CACHED_DEPTH + 1];
//here: 현재 위치
//visited: 각 도시의 방문 여부 일때, 나머지 도시를 모두 방문하고
//시작점으로 돌아가는 최단 경로의 길이를 반환한다.
double dp(int here, int visited) {
	//기저 사례: 더 방문할 도시가 없으면 시작점으로 돌아간다.
	if (visited == (1 << n) - 1) return dist[here][0];
	//메모이제이션
	int remaining = n - __builtin_popcount(visited); //남은 도시의 수
	//사실remaining은 필요 없다만 책에서 설명한 바에 따르면
	//map에 접근하는 원소의 수를 좀 줄여서 수행속도를 빠르게 하자는 의도임
	//음..map의 수가 6배 늘어나는 것 만큼 각 맵을 구성하는 트리 높이는 낮아지겠군
	"remaining이 없이 cache[here][visited]로 통과시켜 보자."
	double& ret = cache[here][remaining][visited];
	if (ret > 0) return ret;
	ret = INF;
	//다음 도시를 하나씩 시도한다.
	for (int next = 0; next < n; ++next) {
		if (visited & (1 << next)) continue;	//방문한 도시는 무시한다.
		ret = min(ret,
				dp(next, visited + (1 << next)) + dist[here][next]);
	}
	return ret;
}
맵이 많으면 즉 트리가 많으면 깊이는 줄어드는 효과
	1
	2 3
	4 5 6 7
	8 9 10 11 12 13 14 15

	1		4		7		10		13
	2 3		5 6		8 9		11 12	14 15
void search(vector<int>& path, int visited, double currentLength) {
	//..생략..
	//기저사례: 남은 도시 수가 CACHED_DEPTH 이하면 동적 계획법으로 바꾼다.
	if (path.size() + CACHED_DEPTH >= n) {
		best = min(best, currentLength + dp(path.back(), visited));
		return;
	}
	//..생략..
}
double solve() {
	//..생략..
	//cache초기화//케이스가 여러개니
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j <= CACHED_DEPTH; ++j)
			cache[i][j].clear();
	//..생략..
}

map<int, int> test;
void main() {
	//대입연산자의 rhs에 있어도 크기가 설정되어 부리네...
	int n0 = test[0];	//test.size() => 1, test[0] = 0, n0 = 0;
	int n1 = test[1];	//test.size() => 2, test[1] = 0, n1 = 0;
	int n2 = test[2];	//test.size() => 3, test[2] = 0, n2 = 0
	test[0] = 7;		//test[0] = 7
	n0 = test[0];		//n0 = 7
}

here : 3 
here 3, {1, 2, 4, 5, 0}	남은도시의 개수 5개 
here 1, {2, 4, 5, 0}	남은도시의 개수 4개 
here 2, {4, 5, 0}		남은도시의 개수 3개 
here 4, {5, 0}			남은도시의 개수 2개 
here 5, {0}				남은도시의 개수 1개 
here 0, empty			남은도시의 개수 0개	//이때는 기저만 타고, 캐시는 세팅안함



void main() {

	vector<int> vec1 = { 1,2,0,3,3,0,7,7,7,0,8 };
	vector<int>::iterator new_end;
	new_end = unique(vec1.begin(), vec1.end());	//{1,2,0,3,0,7,0,8, 7,0,8} //마지막 3개는 쓰레기임
	int n1 = *new_end;	//7: new_end가 가리키는 인덱스는 8(시작 0)
	int n2 = *(new_end + 1);	//0
	vec1.erase(new_end, vec1.end());	//쓰레기 값을 지우장(마지막 3개 제거)

	vector<int> vec2 = { 1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8 };
	vector<int>::iterator new_end2;
	sort(vec2.begin(), vec2.end());					//{0, 0, 0, 1, 2, 3, 3, 7, 7, 7, 8}
	new_end2 = unique(vec2.begin(), vec2.end());	//{0, 1, 2, 3, 7, 8, 3, 7, 7, 7, 8}
	n1 = *new_end2;		//3: new_end2 가 가리키는 인덱스는 6(시작 0)
	n2 = *(new_end2 + 1);//7
	vec2.erase(new_end2, vec2.end());				//{0, 1, 2, 3, 7, 8}

	return;
}
vector<string> test(8, "abcd"); //각 스트링들을 "abcd"로 세팅된다.

//게임판 덮기2(p163 게임판 덮기1)
//p424블록의 회전된 형태를 계산하고 상대좌표의 목록으로 변환하기
//블록의 각 회전된 형태를 상대 좌표의 목록으로 저장해 둔다.
vector<vector<pair<int, int> > > rotations;
//블록의 크기
int blockSize;
//2차원 배열 arr을 시계방향으로 90도 돌린 결과를 반환한다.
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));	//!!!!
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0;j < arr[0].size(); ++j)
			ret[j][arr.size() - i - 1] = arr[i][j];	//!!!!
	return ret;
}
//block의 네 가지 회전 형태를 만들고 이들을 상대 좌표의 목록으로 변환한다.
void generateRotations(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; ++rot) {
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); ++i)
			for (int j = 0; j < block[i].size(); ++j)
				if (block[i][j] == '#') {	//.###			   (0,0) (0,1) (0,2)
											//##..		(1,-1) (1,0)
					if (originY == -1) {
						//가장 윗줄 맨 왼쪽에 있는 칸이 '원점'이 된다.
						originY = i;
						originX = j;
					}
					//각 칸의 위치를 원점으로부터의 상대좌표로 표현한다.
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
		//블록을 시계 방향으로 90도 회전한다.
		block = rotate(block);
	}
	//네 가지 회전 형태 중 중복이 있을 경우 이를 제거한다.
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	//블록이 몇 칸 짜리인지 저장해 둔다.
	blcokSize = rotations[0].size();
}
//p426 게임판 덮기2 문제를 해결하는 완전 탐색 알고리즘
//(이전문제는 다 채우는 경우의 수를 묻는 문제였고 이 문제는
//최대한 채우는 경우 몇개가 들어가는지 묻는 문제다.)
//게임판의 정보
int boardH, boardW;
vector<string> board; //그대로 이용안함 covered에 대입한다(#=>1) 빈칸은 0
//게임판의 각 칸이 덮였는지를 나타낸다. 1이면 검은 칸이거나 이미 덮은 칸, 0이면 빈 칸
int covered[10][10];
//지금까지 찾은 최적해
int best;
//(y, x)를 왼쪽 위칸으로 해서 주어진 블록을 delta = 1이면 놓고, -1이면 없앤다.
// (y,x) 를 (0,0) 으로 해서 cells 로 표현된 블록을 내려놓거나, 들어올린다.
// delta 가 1 이면 내려놓고, -1 이면 들어올린다.
// 블록이 검은 칸이나 다른 블록과 겹치거나 게임판 밖으로 나가면 false 를 반환한다.
bool set(int y, int x, const vector<pair<int,int> >& cells, int delta) {
	bool ok = true;
	for(int i = 0; i < cells.size(); i++) {
		int cy = y + cells[i].first, cx = x + cells[i].second;
		if(cy < 0 || cx < 0 || cy >= boardH || cx >= boardW)
			ok = false;
		else {
			covered[cy][cx] += delta;
			if(covered[cy][cx] > 1) ok = false;
		}
	}
	return ok;
}
//placed: 지금까지 놓은 블록의 수
void search(int placed) {
	//아직 채우지 못한 빈 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1, x = -1;
	for (int i = 0; i < boardH; ++i) {
		for (int j = 0; j < boardW; ++j)
			if (covered[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		if (y != -1) break;
	}
	//기저 사례: 게임판의 모든 칸을 처리한 경우
	//게임판 덮기1과는 달리 이곳이 유일한 기저다. 
	//(한칸 덮기가 있어서 이 기저가 아닌 경우에도 search를 무조건 탄다)
	if (y == -1) {
		best = max(best, placed);
		return;
	}
	//이 칸(맨 위쪽의 왼쪽)을 블록으로 덮는다!(정확히는 칸들: 기준칸 + 주위칸 이 되겠죠)
	for (int i = 0; i < rotations.size(); ++i) {
		if (set(y, x, rotations[i], 1))
			search(placed + 1);
		set(y, x, rotations[i], -1);
	}
	"이 칸을 블록으로 덮지 않고 막아둔다."
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}
int solve() {
	best = 0;
	//covered 배열을 초기화한다.
	for (int i = 0; i < boardH; ++i)
		for (int j = 0; j < boardW; ++j)
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
	search(0);
	return best;
}
경로의 최소길이를 구해야 했던 TSP와는 (중간에 현 best보다 긴걸로 예상되면 가지치기 가능)
달리 여기서는 블록의 최대 개수를 찾기 때문에(중간에 현 best보다 작은걸로 예상되면 가지치기)
"이처럼 가장 큰 답을 찾는 최적화 문제에서 낙관적인 휴리스틱들은"
"문제를 과소평가하는 대신에 과대평가합니다."
간단한 휴리스틱으로는 남은 빈 칸의 수에 블록의 크기를 나누어 놓아 과대평가 결과를 예상하는 겁니다.
//.###			   (0,0) (0,1) (0,2)
//##..		(1,-1) (1,0)
이 블록의 경우 크기는 5이며
10 by 10에서 빈칸이 32개 있다면
암만 많이 놓아야 6 개 되겠죠
// 통과함 간단한 가지치기로 말이지~ 213ms 걸ㄻ
int simpleHuristic() {
	int binkan = 0;
	rep(i, boardH) rep(j, boardW) if (covered[i][j] == 0) binkan++;
	return binkan / blockSize;
}
void search(int placed) {
	int maxmumAdd = simpleHuristic();
	if (maxmumAdd + placed <= best) 
		return;

	...
}

//알러지가 심한 친구들 : 최소의 음식 수를 출력하라
2
4 6	//4사람, 6종류의 음식
cl bom dara minzy	//4 사람
2 dara minzy		//0번 음식을 먹을 수 있는 사람은 2명이며 dara, minzy 다
2 cl minzy
2 cl dara
1 cl
2 bom dara
2 bom minzy
10 7
a b c d e f g h i j
6 a c d h i j
3 a d i
7 a c f g h i j
3 b d g 
5 b c f h i
4 b e g j
5 b c g h i

출력
2
3
//p430 알러지 문제를 해결하는 첫 번째 조합 탐색 알고리즘
"집함 덥개(set cover)라고 부르는 문제로, NP complete 문제 임..bioO가 2^n 식임" 
int n, m; //사람수, 음식종류
//eaters[food] = food 를 먹을 수 있는 친구들의 번호
//ex) eaters[0] : 0번 음식을 먹을 수 있는 친구들의 번호들이 vector에 저장되어 있다.
vector<int> eaters[50];
int best;
//food: 이번에 고려해야 할 음식의 번호
//edible: 지금까지 고른 음식 중 i번 친구가 먹을 수 있는 음식의 수
//chosen: 지금까지 고른 음식의 수
void slowSearch(int food, vector<int>& edible, int chosen) {
	//간단한 가지치기
	if (chosen >= best) return;
	//기저 사례: 모든 음식에 대해 만들지 여부를 결정했으면
	//모든 친구가 음식을 먹을 수 있는지 확인하고 그렇다면 최적해를 갱신한다.
	if (food == m ) {
		if (find(edible.begin(), edible.end(), 0) == edible.end())
			best = chosen; //!!!!
		return;
	}
	//food를 만들지 않는 경우
	slowSearch(food + 1, edible, chosen);
	//food를 만드는 경우
	for (int j = 0; j < eaters[food].size(); ++j)
		edible[eaters[food][j]]++;
	slowSearch(food + 1, edible, chosen + 1);
	for (int j = 0; j < eaters[food].size(); ++j)
		edible[eaters[food][j]]--;
}
//위 코드드는 m이 최대값인 20일 경우 2^20 : 100만개의 상태를 탐색합니다.
//한 함수당 20번 처리니 느릴수 있습니다.

//p432 알러지 문제를 해결하는 두 번째 조합 탐색 알고리즘
//탐색의 방향을 바꾸면 별다른 최적화 없이도 많은 효율을 얻을 수 있음
int n, m;
//canEat[i]: i번 친구가 먹을 수 있는 음식의 집합(추가된거)
//eaters[i]: i번 음식을 먹을 수 있는 친구들의 집합
vector<int> canEat[50];
vector<int> eaters[50];
int best;
//chosen: 지금까지 선택한 음식의 수
//edible[i]: 지금까지 고른 음식 중 i번 친구가 먹을 수 있는 음식의 수
void search(vector<int>& edible, int chosen) {
	//간단한 가지치기
	if(chosed >= best) return;
	//아직 먹을 음식이 없는 첫 번째 친구를 찾는다.
	int first = 0;
	while (first < n && edible[first] > 0) ++first;
	//모든 친구가 먹을 음식이 있는 경우 종료한다.
	if (first == n) {best = chosen; return; }

	"첫번째 친구가 먹을 수 있는 음식들을 하나하나 대입시켜 재귀돌린다."
	for (int i = 0; i < canEat[first].size(); ++i) {
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); ++j)
			edible[eaters[food][j]]++;	//!!!!
		search(edible, chosed + 1);  
		for (int j = 0; j < eaters[food].size(); ++j)
			ediblepeaters[food][j]]--;
	}
}


//이기 훨씬 더 가독성 있다. 이걸 외우라!!!!
vector<int> personToFoodArr[50];
vector<int> foodToPersonArr[50];
int best;
int n, m; //사람수, 음식수
void search(vector<int>& edible, int chosen) {
	if (chosen >= best) return;
	int first = 0;
	while (first < n && edible[first] > 0) ++first;
	if (first == n) {
		best = chosen;
		return;
	}
	for (int i = 0; i < personToFoodArr[first].size(); ++i) {
		int food = personToFoodArr[first][i];
		for (int j = 0; j < foodToPersonArr[food].size(); ++j)
			edible[foodToPersonArr[food][j]]++;
		search(edible, chosen + 1);
		for (int j = 0; j < foodToPersonArr[food].size(); ++j)
			edible[foodToPersonArr[food][j]]--;
	}
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> n >> m;
		for (int i = 0; i < 50; ++i) {
			personToFoodArr[i].clear();
			foodToPerosnArr[i].clear();
		}
		map<string, int> names;
		for (int i = 0; i < n; ++i) {
			string name;
			cin >> name;
			names[name] = i;
		}
		for (int food = 0; food < m; ++food) {
			int sz;
			cin >> sz;
			for (int j = 0; j < sz; ++j) {
				string name;
				cin >> name;
				int eater = names[name];
				foodToPersonArr[food].push_back(eater);
				personToFoodArr[eater].push_back(food);
			}
		}
		best = m;
		vector<int> edible(n, 0);
		int sol = search(edible, 0);
		cout << sol << endl;

	}
	return 0;
}


//p434 카쿠로 생략

//------------------ 12장 : 최적화 문제 결정 문제로 바꿔 풀기 ---------------------//
외판원 문제에서
Optimize(G) = 그래프 G의 모든 정점을 한 번씩 방문하고 시작점으로 돌아오는 
최단 경로의 길이를 반환한다.(최적화 문제)
decision(G, x) = 그래프 G의 모든 정점을 한 번씩 방문하고 시작점으로 돌아오면서
길이가 x이하인 경로의 존재 여부를 반환한다.(결정 문제)

결졍문제와 최적화 문제의 관계
"1. 두문제 형태가 똑같이 어려운 경우"
"2. 최적화 문제가 더 어려운 경우"
다시 말해 결정문제가 최적화 문제보다 어려울 수는 없다는 뜻이다.
증명:
double optimize(const Graph& g) {
	bool decision(const Graph& g, double x) {
		return optimize(g) <= x;
	}
}
외판원 문제의 경우 최적화 문제든, 결정 문제든 다항 시간 안에 풀기 힘든것은 마찬가지다
"그러나 특정 문제에서는 최적화 문제보다 결정 문제가 풀기 쉬운 경우가 있다"
이 장에서 다루는 패턴은 이런 문제에 아주 유용하다.

DAPRA Grand Challenge(DARPA, 중)
0         70   90    120                   200  210  220    240
*---------*----*-----*---------------------*----*----*-------|
카메라 설치 공간 7군데, 카메라는 4개 있다고 하면
4개 설치시 가장 가까운 위치의 카메라가 가장 멀리 떨어져 있도록 하라
"가장 가까운 두 카메라 간의 간격을 최대화 하고 싶습니다"

각 테스트 케이스마다 가장 가까운 두 카메라 간의 최대 간격을 소수점 셋째 자리에서 반올림해 출력합니다.
3
2 4 
80 100 120 140 //60.00
4 4 
80 100 120 140.00	//20.00
4 7 
0 70 90 120 200 210 220	//50.00

"잠깐타임..음냐...(int)(0.29 * 100) == 28 히익..."

optimize(locations, cameras) = 카메라를 설치할 수 있는 위치 locations와 카메라의 수
cameras가 주어질 때, 카메라 간 최소 간격의 최대치를 반환한다.

decision(locations, cameras, gap) = 카메라를 설치할 수 있는 위치 locations와 카메라의 수
cameras가 주어질 때, 이들을 적절히 배치해 
"모든 카메라의 간격이 gap 이상이 되도록 하는 방법이 있는가?"

decision()이 대답하는 질문이 "카메라 간의 최소 간격이 gap인 방법이 있는가?" 가 아니라
"카메라들 간의 최소 간격이 gap이상인 방법이 있는가?" 인 것을 유의하라.

//p449: DARPA의 결정 문제 형태를 해결하는 탐욕적 알고리즘
//결정 문제: 정렬되어 있는 locations중 cameras를 선택해 모든 카메라 간의 간격이
//gap이상이 되는 방법이 있는지를 반환한다.
bool decision(const vector<double>& location, int cameras, double gap) { //bigO(n)
	//카메라를 설치할 수 있을 때마다 설치하는 탐욕적 알고리즘
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); ++i) {
		if (limit <= location[i]) {
			++installed;
			//location[i] + gap 이후는 되어야 카메라를 설치할 수 있다.
			limit = location[i] + gap;
		}
	}
	//결과적으로 cameras대 이상을 설치 할 수 있었으면 성공
	return installed >= cameras;
}
//최적화 문제: 정렬되어 있는 locations 중 cameras를 선택해 최소 간격을 최대화한다.
double optimize(const vector<double>& location, int cameras) {
	double lo = 0, hi = 241;
	"반복문 불변식: decision(lo) && !decision(hi)"
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		//간격이 mid 이상이 되도록 할 수 있으면 답은 [mid, hi]에 있다.
		if (decision(location, cameras, mid))
			lo = mid;
		//간격이 mid 이상이 되도록 할 수 없다면 닶은 [lo, mid]에 있다.
		else
			hi = mid;  
	}
	return lo;
}

또 다른 해답
"배열에다 고정된 후보를 넣는 방식" //수치오류시 근사값이 너무 다르게 됨 조심해서 풀자
"동적계획법" 
// algospot 통과함: 34ms 걸림
double dp[101][201];	// 가장 가까운 두 카메라 간의 간격을 최대화하는 거리: 평탄화
" 최적부분 구조: 끝단에 카메라가 위치해야 함 "
/*
	// 3: 놓인 카메라수, 10: 대상 위치 1 ~ 10
	dp[3][10] = max	| min(length(9, 10), dp[2][9])	|
					| min(length(8, 10), dp[2][8])	|
					| ............................. |
					| min(length(2, 10), dp[2][2])	|

	dp[1][1 ~ m] = INF;	// 기저: 한 개만 놓는 경우
*/
double arr[201];
inline double length(int idx1, int idx2) {
	if (idx1 == idx2) return 987654321;	// 이 구문이 없어도 돌아감: 애초 호출시 idx1 == idx2 인 경우가 없도록 되어있음
	return arr[idx2] - arr[idx1];
}
int main() {
	int cs; cin >> cs;
	rep(cc, cs) {
		memset(dp, 0, sizeof(dp));
		int n, m;
		cin >> n >> m;
		rep2(i,1, m+1) scanf("%lf", &arr[i]);
		rep2(i, 1, m + 1) dp[1][i] = INF;	// 한대만 놔두는 경우
		rep2(i, 1, n + 1) {	// 카메라를 몇대 두었는가
			rep2(j, 1, m + 1) {	// 놓을 공간
				if (i > j) continue;	// 공간이 부족하면
				if (i == 1) continue;
				double cand1 = -INF, cand2;
				rep2(k, i - 1, j) {
					cand2 = min<double>(length(k, j), dp[i - 1][k]);
					cand1 = max(cand1, cand2);
				}
				dp[i][j] = cand1;
			}
		}
		printf("%.2lf\n", dp[n][m]);
	}
	return 0;
}

//남극기지
2	: cs
5	//기지수 <= 100
0 0	//각 기지 위치: 0이상 1000이하의 실수
1 0
1 1
1 2 
0 2
//1.00 : 각 테스트 케이스마다 가능한 최소 통신 반경을 소숫점 밑 셌째 자리에서 반올림
...
"기지간 직간접 연결이 되어야 하고 이때 가능한 한 무전기의 최소 통신 반경을 계산하기"
optimize(P) = P에 주어진 기지들을 모두 연결하는 연락망을 구축할 때
가능한 최소 무전기 반경은 얼마인가?
decision{P, d) = 모든 기지를 하나로 연결하되, 가장 먼 두 기지 간의 거리가 d 이하인
연락망이 있는가?
//p453: 남극 기지 문제를 결정 문제로 바꿔 해결하는 이분법 알고리즘
int n;
//두 기지 사이의 거리를 미리 계산해둔다.
double dist[101][101];
//거리 d이하인 기지들만을 연결했을 때 모든 기지가 연결되는지 여부를 반환한다.
//bigO(n^2)
bool decision(double d) {
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;	//발견이 아니라 방문시 증가한다
	while (!q.empty()) {
		int here = q.front();
		q.pop(); //방문
		++seen;
		for (int there = 0; there < n; ++there)
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
			}
	}
	return seen == n;
}
//모든 기지를 연결할 수 있는 최소의 d를 반환한다.
double optimize() {
	double lo = 0, hi = 1416.00; //sqrt(1000*1000 + 1000*1000) + 여유마진
	"반복문 불변식: !decision(lo) && decision(hi)"
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2;
		//mid가 가능하다면, 더 좋은(작은) 답을 찾는다.
		if (decision(mid))
			hi = mid;
		//mid가 불가능하다면, 더 나쁜(큰) 답을 찾는다.
		else
			lo = mid;
	}
	return hi;
}
다른답
"쿠로스칼 MST 알고리즘" : 마지막 정점을 연결시킨 간선이 답인가?
만약 간선크기가 1,1,1,1,1,....,8인 형식의 MST가 있다는 가정하에
1을 제외한 경우 2,2,2,2,2.....7 인 형식의 MST가 존재할 수 있지 않을까???? 실험필요... // 내 예상은 존재 하지 않는다고 봄
"플로이드의 모든 쌍 최단거리 알고리즘"
i,j,k 포문중, k포문에서 처리하도록 하면 구현될듯 싶다.

//캐나다 여행(CANADATRIP, 중)
도시의 수 N(1 <= N <= 5000)
K번째 표지판(1 <= K <= 2^31 - 1)
Li, Mi, Gi (1 <= Gi <= Mi <= Li <= 8030000)
3 15 //도시수, 우리가 찾는 k번째 표지판
500 100 10 //표지판의 위치는 항상 정수
504 16 4
510 60 6
//480
"모든 표지판의 위치를 생성하여 이들을 정렬해서 답을 구한다는 것은 불가능"
//길이:803000, 도시수:5000, C[i]가 1 인 경우 으악!!!!
K번째 표지판의 위치는 어디인가?
	=> decision(x) 시작점부터 x미터 지점까지 가면서 K개 이상의 표지판을 만날 수 있는가?
우리가 원하는 답이 D라고 하면, D는 dicision()이 참을 반환하는 첫 번째 지점이다.
다시 말하면 "decision(D-1) = false, decision(D) = true" 여야 한다는 뜻!!!!

decision(x)를 구하기 위해, [0, x] 범위에 출현하는 모든 표지판의 개수를 세어 봅시다.
0						 Li-Mi			   Li
o---------------x--------S--------x--------L--------x---
[0, x]범위에 출현하는 모든 표지판의 개수는
i번째 도시까지의 거리를 나타내는 표지판은 [Li-Mi, Li] 구간에 출현하므로,
두 구간이 닿아 있지 않은 경우 즉 "(x < Li-Mi)"에서는 표지판을 하나도 볼수 없음
"이 외의 경우 [0, x]구간과 [Li-Mi, Li] 구간의 겹치는 길이는 다음과 같음"
"min(x, Li) - (Li-Mi)"
위 겹치는 길이를 Gi로 나누고 1을 더하면 i번째 도시까지의 거리를 나타내는 표지판을 계산할수 있다.

//p458 캐나다 여행 문제를 결정 문제로 바꿔 푸는 이분법 알고리즘
decision() => n, optimize() => lgn : 따라서 bigO(nlgn)
int n, k;
int l[5000], m[5000], g[5000]; //문제 조건: 도시의 위치는 정수고 l-m은 g의 배수임.
//결정 문제: dist지점까지 가면서 k개 이상의 표지판을 만날 수 있는가?
bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i)
		//i번째 도시 표지판을 하나 이상 보게 되는가?
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
	return ret >= k;
}
//k번째 표지판을 만나는 지점의 위치를 계산한다.
int optimize() {
	//반복문 불변식: 
	"!decision(lo) && decision(hi)" //lo는 거짓이고 hi는 항상 참
	int lo = -1, hi = 8030001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

//수강철회 (WITHDRAWAL, 상)
등수 매기는 시스템은 아래와 같다.
각 과목을 수강하는 학생수
	150	200	15
거기서 백준이가 획득한 등수
	100	10	5
총등수는
	(100 + 10 + 5)
	---------------- = 0.3150684931...
	(150 + 200 + 15)
입력
3
3 2	//수강과목, 남겨야 하는 과목
1 4 6 10 10 17	//(등수, 수강학생수)
//0.5000000000
4 2
4 8 9 12 3 10 2 5
//0.3333333333
10 5
70 180 192 192 1 20 10 200 6 102 60 1000 4 9 1 12 8 127 100 700
//0.0563991323

decision(x) = 적절히 과목들을 철회해 즉 과목들을 잘 선택해서 누적 등수 x이하가 될수 있을까?
decision(x)는 과목들의 집합 [0, ..., n-1]의 모든 부분 집합 중 
"크기가 k이상이며, 아래 조건을 만족하는 S가 있는지를 찾아야 합니다."
"sigma<j(=S>(r[j])
"----------------- <= x
"sigma<j(=S>(c[j])
여기까진 쉬운데 S를 이루는 과목은 어떻게 고를까요...

" 0 <= x * sigma<j(=S>(c[j]) - sigma<j(=S>(r[j]) = sigma<j(=S>(x * c[j] - r[j]) !!!!!"

//p461: 수강 철회 문제를 결정 문제로 바꿔 푸는 이분법 알고리즘
int n, k;
int c[1000], r[1000];
//결정 문제: 누적 등수 average 이하가 되도록 할 수 있나?
bool decision(double average) {  //nlgn
	//sum[c[i]/r[i]) <= x : 책에 있는 문장이지만 맛탱이가 간 오타로 보임
	//sum(c[i]) / sum(r[i]) <= x
	//sum(c[i]) <= x * sum(r[i])
	//0 <= x * sum(r[i]) - sum(c[i])
	//0 <= sum(x * r[i] - c[i])
	//vi = x * r[i] - c[i] 를 계산한다.
	vector<double> v;
	for (int i = 0; i < n; ++i)
		v.push_back(average * c[i] - r[i]);
	sort(v.begin(), v.end());
	//이 문제는 v개수중 k개의 합이 0이상이 될 수 있는지로 바뀐다. 탐욕법으로 해결
	double sum = 0;
	for (int i = n - k; i < n; ++i)
		sum += v[i];
	return sum >= 0;
}
//최적화 문제: 얻을 수 있는 최소의 누적 등수를 계산한다.
double optimize() {
	//누적 등수는 [0, 1] 범위의 실수이다.
	//반복문 불변식: 
	"!decision(lo) && decision(hi)"
	double lo = -1e-9; //-0.000,000,001
	double hi = 1;
	for (int iter = 0; iter < 100; ++iter) {
		double mid = (lo + hi) / 2;
		//누적 등수 mid를 달성할 수 있나?
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

// 달과 그 위에 이는 둥근 그림자에 의해 가려진 영영
// 실제 보이는 달의 면적을 구하라.
https://algospot.com/judge/problem/read/MOON
int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	// 공식유도 생각하기 싫다. 그냥 이분법으로 풀래요.
	// 문제 조건이 r1 < r2 < d && d < r1 + r2 이므로
	// 두 원의 거리는 적어도 자신의 반지름 이상이고 겹치는 영역이 존재해야 한다.
	// 이 조건이면 이분법 적용이 가능.
	int cs; cin >> cs;
	rep(cc, cs) {
		double r1, r2, d;
		cin >> r1 >> r2 >> d; // 각각의 반지름: m, s   중심끼리의 거리: c
		//높이를 구하자
		double lo = 0.0, hi = min(r1, r2);
		double d1, d2;
		for (int it = 0; it < 100; ++it) {
			double mid = (lo + hi) / 2;	// 높이 후보
			d1 = r1 * r1 - mid * mid;
			d1 = sqrt(d1);
			d2 = r2 * r2 - mid * mid;
			d2 = sqrt(d2);
			if (d1 + d2 >= d) lo = mid;
			else
				hi = mid;
		}
		double t1 = asin(lo / r1);
		t1 *= 2;
		double t2 = asin(lo / r2);
		t2 *= 2;
		// 실수한 부분. 호의 넓이는 삼각형의 넓이랑 똑같다.
		// 각도 * 반지름 / 2 가 된다. 
		// 나는 "/2" 를 빠뜨려서 계속 틀렸다. !!!!
		double interS = r1*r1*t1/2 - (lo * d1) + r2*r2*t2/2 - (lo * d2);
		double S = r1*r1*PI - interS;
		printf("%.3lf\n", S);
	}
	return 0;
}
// 공식으로 푼 소스
#define PI acos(-1.0)
int main() {
	int tc;
	cin>>tc;
	while(tc--){
		double m,s,c;
		cin>>m>>s>>c;
		double x=(m*m+c*c-s*s)/(2.0*c);
		double y=sqrt(m*m-x*x);
		printf("%.3f\n",m*m*PI+y*c-asin(y/m)*m*m-asin(y/s)*s*s);
	}
	return 0;
}

//------------------ 13장 : 수치 해석 ---------------------------------------------//

//p469: 이분법의 예제 구현(10^(-7) = 0.000,000,1 이하로 오차가 나오는 해를 구하기) 
//절대 오차를 이용한 판정 종료
double f(double x);
//이분법의 예제 구현
double bisection(double lo, double hi) {
	//반복문 불변식을 강제한다.
	"f(lo)는 항상 0이하이고 f(hi)는 항상 양수라는 반복문 불변식을 유지한다."
	if (f(lo) > 0)
		swap(lo, hi);
	//반복문 불변식: f(lo) <= 0 < f(hi)
	"swap이 실행되면 lo > hi 인 케이스가 발생한다, 이건 fabs로 간단하게 처리"
	while (fabs(hi - lo) > 2e-7) {
		double mid = (lo + hi) / 2;
		double fmid = f(mid);
		if (fmid <= 0)
			lo = mid;
		else
			hi = mid;
	}
	//가운데 값을 반환한다.
	return (lo + hi) / 2; 
}

"절대 오차를 사용한느 방법은 다루는 값의 크기가 작을 때는 훌륭하게 동작하지만
"값(절대값)이 커지면 문제가 발생할 수 있다.
부동소수점은 가수부(mantissa)라고 부르는 정수 부분과 이 변수에서 소수점의 위치를
나타내는 지수부(exponent)의 조합으로 표현되기 때문에, 표현할 수 있는 수의 집합이 제한됨
"숫자의 절대값이 커지면 커질수록 표현할 수 있는 수들이 듬성듬성해지게 됨"
//p471: 영원히 종료하지 않는 이분법의 예
//종료되지 않는다.
void infiniteBisection() {
	double lo = 123456123456.1234588653046875;
	double hi = 123456123456.1234741210937500;	//hi - lo	= 0.000,014,7....
	while (fabs(hi - lo) > 2e-7)				//2e-7		= 0.000,000,1
		hi = (lo + hi) / 2.0;
	"lo, hi 사이에는 double 변수가 표현할 수 있는 값이 하나도 없습니다."
	"게다가 불행히도 (lo + hi) / 2.0 은 hi쪽으로 표현됩니다."
	"ㅅㅂ 무한입니다"
	printf("finished!\n");
}
프로그래밍 대회에서는 이와같은 문제 때문에 절대 오차 외에도 상대 오차를 허용하고 있습니다.
"반환값의 오차가 10^(-7)보다 크더라도" 정답 A에 대해 [A x (1-10^(-7)), A x (1+10^(-7))]
범위에 포함되는 답을 정답으로 인정합니다.
현재의 근사값 (lo + hi) / 2.0 이 정답으로 인정되기 위해선 아래 조건이 참이어야 합니다.
					lo + hi
(1-10^(-7)) * hi < -------- < (1+10^(-7)) * lo
					   2
단, 조건은 lo 와 hi가 전부 양수라고 가정 합니다. 
"두수가 음수인 경우, lo가 음수이고 hi는 양수인 경우 등을 고려하면 코드는 더더욱 복잡"
"결론: 고수 참가자들은 이런 복잡한것 때문에 위 방식은 사용안해요!!!!"
"12장에서 했던 고정된 반복문 횟수를 이용합니다."
반복문을 100번 수행하면 우리가 반환하는 답의 절대 오차는 최대 |lo-hi| / 2^(101) !!!!! 오오


//다변수 다항 방정식의 수치적 해법(ROOTS, 중) 
"이분법 예제로 받아들이시고, 실제로 방정식을 풀어야 할 때는 공개되어 
"있는 다양한 수치해석 알고리즘을 사용하기 바랍니다.
//P473: 다변수 다항 방정식의 해를 이분법으로 찾기// 근은 오차가 10^-8 이하여야 한다.
//단일 변수 다항식 p의 계수가 주어질 때 미분한 결과 p'의 계수를 반환한다.
vector<double> differentiate(const vector<double>& poly);
//1차 혹은 2차 방정식을 푼다.
vector<double> solveNaive(const vector<double>& poly);
//다항식 f(x)의 계수 poly가 주어질 때, f(x0)를 반환한다.
double evaluate(const vector<double>& poly, double x0);
"방정식의 해의 절대 값은 L이하여야 한다" //야박하네.. 응용이 힘들겠네
const double L = 25;
//방정식 sum(poly[i] * x^i ) = 0의 근을 반환한다.
vector<double> solve(const vector<double>& poly) {
	int n = poly.size() - 1;
	//기저 사례: 2차 이하의 방정식들은 풀 수 있다.
	if (n <= 2) return solveNaive(poly);
	//방정식을 미분해서 n-1 차 방정식을 얻는다.
	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(deriavative); //!!!!
	//이 극점들 사이를 하나하나 검사하며 근이 있나 확인한다.
	sols.insert(sols.begin(), -L - 1); "유용하네"//!!!! 벡터의 앞에 집어 넣구나
	sols.insert(sols.end(), L + 1);
	vector<double> ret;
	for (int i = 0; i < sols.size() - 1; ++i) {
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		//f(x1)가 f(x2)의 부호가 같은 경우 답은 없다.
		if (y1 * y2 > 0) continue; //한놈이 0인 경우는 continue 안탐
		//불변 조건: f(x1) <= 0 < f(x2) : y1 <= 0 < y2
		if (y1 > y2) { swap(y1, y2); swap(x1, x2); }
		//이분법을 사용하자.
		for (int iter = 0; iter < 100; ++iter) { //!!!!핵심
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);
			if (y1 * my > 0) {	//my가 음수이면
				y1 = my;
				x1 = mx;
			}
			else {				//my가 0이거나 양수이거나, y1이 0인 경우//오오..
				y2 = my;		//사실 my가 0이면 이분법 탈출 조건에 넣어야 겠죠
				x2 = mx;		//불변조건을 위배하니(안해도 뭐 좀만 시간 잡겠지만..)
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());
	return ret;
}
// 단일 변수 다항식 p의 계수가 주어질 때 미분한 결과 p' 의 계수를 반환한다
vector<double> differentiate(const vector<double>& poly) {
	//n 차 방정식이다
	int n = poly.size() - 1;
	vector<double> q(n);
	for (int i = 1; i <= n; ++i)
		"미분: poly[i]*x^i => i*poly[i]*x^(i-1)"
		q[i - 1] = i * poly[i];
	return q;
}
//1차 혹은 2차 방정식을 푼다.
vector<double> solveNaive(const vector<double>& poly) {
	int n = poly.size() - 1;
	if (n == 1) {
		double a = poly[1], b = poly[0];
		// ax + b = 0
		if (fabs(a) < 1e-8) return vector<double>();
		return vector<double>(1, -b / a);
	}
	double a = poly[2], b = poly[1], c = poly[0];
	double d = b*b - 4*a*c;
	vector<double> ret;
	if (d >= 0) {
		double sqrtd = sqrt(d);
		ret.push_back((-b - sqrtd) / (2*a));
		if (sqrtd > 1e-8)
			ret.push_back((-b + sqrtd) / (2*a));	//중근인 경우 한놈만 저장
	}
	return ret;
}
// 다항식 f(x)의 계수 poly가 주어질 때, f(x0)를 반환한다.
double evaluate(const vector<double>& poly, double x0) {
	double ret = poly.back();	//7x + 6 //최대차항을 넣음
								//(7x + 6) * x + 5 이런식으로 다이나믹하구나.
	for (int i = int(poly.size()) - 2; i >= 0; --i) //!!!!왜 형변환 했는지 알지
		ret = ret * x0 + poly[i]; 
	return ret;
}

x^3 = 0 인 걸로 테스트 해봤다. 미분시 2차 방정식에서 0되는 지점은 원방정식 변곡점이다.
2차방정식 근이 한놈만 리턴(-0.000000000... 이건 0임)이고 그놈은 3차방정식의 근도 된다..
즉 (-L-1) ------ (-0.0000...) -- (L+1) 인 상태임
"여기서 (-L-1) ----- (-0.0000...) ===> (-0.00000... 이건 0이 아니었음) 이 push_back되고 
"	   (-0.0000....) ----- (L+1) ===> (0.00000... 이놈도 0은 아님) 이 push_back된다."
	잠깐 f(-L-1) 과 f(-0.0000...)의 부호가 달라야지 ret에 push_back 되지 않느냐 
	두 곱이 0이라서 ret에 push_back된다.(미분뒤 2차방정식 근이 -0.00000000...인데 
	이건 0.00000000000... 과 같은 취급함.) "즉 그냥 0이다"
	두번째도 구간 처리때도  두 곱은 0.00000000.. 그냥 0이라서임. 따라서 continue
"분석도 힘드네.. 여러가지로 구린게 있어서 저자도 이건 활용 비추천 했구나..."

구려도 어느정도 동작은 하니까. 리턴된놈들 정렬 순으로 앞뒤 비교해서 차가 1e-8 보다 작다면
같은놈 취급하여 지워서 사용해라.

// 알고스팟에 뉴턴법으로 푼 인간 소스
class Equation:
   def __init__(self, p):
       self.n = len(p)-1
       self.p = p
       self.dp = tuple(v*(self.n-i) for i, v in enumerate(self.p[:-1]))

   def eval(self, x):
       return sum(v * x**(self.n-i) for i, v in enumerate(self.p))

   def eval_d(self, x):
       return sum(v * x**(self.n-i-1) for i, v in enumerate(self.dp))

   def newton(self, x):
       return x - self.eval(x)/self.eval_d(x)

   def solve(self):
       if self.n == 1:
           return [-self.p[1]/self.p[0]]

       polars = [-12] + Equation(self.dp).solve() + [12]
       ret = []
       for lo, hi in zip(polars, polars[1:]):
           if self.eval(lo)*self.eval(hi) > 0:
               continue
           x = (lo+hi)/2
           for i in range(50):
               x = self.newton(x)
           ret.append(x)
       return ret

for C in range(int(input())):
   n = int(input())
   p = tuple(map(float, input().split()))

   print(' '.join(map(str, Equation(p).solve())))

//전제금 균등상환(LOAN, 하)
//p475: 전세금 균등상환 문제를 해결하는 이분법의 구현
//amount원을 연 이율 rates퍼센트로 duration월 간 한달에 monthlyPayment로 갚았을때
//대금 잠금은?
double balance(double amount, int duration, double rates, double monthlyPayment) {
	double balance = amount;
	for (int i = 0; i < duration; ++i) {
		//이자가 붙는다.
		balance *= (1.0 + (rates / 12.0) / 100.0);
		//상환액을 잔금에서 제한다.
		balance -= monthlyPayment;
	}
	return balance;
}
//amount원을 연 이율 rates퍼센트로 duration월 간 갚으려면 한달에 얼마씩 갚아야 하나?
double payment(double amount, int duration, double rates) {
	//불변 조건:
	//1. lo원씩 갚으면 duration개월 안에 갚을 수 없다.
	//2. hi원씩 갚으면 duration개월 안에 갚을 수 있다.
	//정확도 (0 + amount * (1.0 + (rates / 12) / 100.0) / 2^100
	double lo = 0, hi = amount * (1.0 + (rates / 12) / 100.0);	// hi는 한달만에 다 갚네
	for (int iter = 0; iter < 100; ++iter) {	
		double mid = (lo + hi) / 2.0;
		if (balance(amount, duration, rates, mid) <= 0)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

//승률올리기(RATIO, 하)
5 //CASE
10 8		// 1
100 80		// 6   (80 + x) / (100 + x) >= (0.80 + 0.01) 을 만족하는 x는 5.263... 올림해서 6임 
47 47		// -1
99000 0		// 1000
1000000000 470000000 //19230770
//p478: 승률 올리기 문제를 해결하는 이분법 알고리즘
//도경이가 할 생각이 있는 최대 게임 수
long long L = 2000000000;
//b게임 중 a게임 승리했을 때의 승률
int ratio(long long b, long long a) {
	return (a * 100) / b;
}
//최소 몇 연승해야 승률이 올라갈까?
int neededGames(long long games, long long won) {
	//불가능한 경우를 미리 걸러낸다.
	if (ratio(games, won) == ratio(games + L, won + L)) //!!!!좋은 예외처리
		return -1;
	long long lo = 0, hi = L;
	//반복문 불변식:
	//1. lo게임 이기면 승률은 변하지 않는다.
	//2. hi게임 이기면 승률은 변한다.
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if (ratio(games, won) == ratio(games + mid, won + mid))
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}
//상수시간에 구하는 알고리즘은 금방 생각해냈기에 생략함


//이분법으로 푼 문제(알고스팟은 분류에 정렬이라고 했다만 난 이분법으로 풀었지롱)
https://algospot.com/judge/problem/read/DOLLS
자신이 가진 인형을 번호순으로 차례차례 기부한다할때 최종 기부량이 m이라 한다면
각 인형들의 기부량은 얼마가 되는가
동일 높이의 기부된 양을 구하고 그 뒤 앞의 인형부터 하나씩 기부량을 증가시킨다.
높이를 구하는데 이분법을 쓰면 된다.


"하나의 극대를 가진 유니모달 함수이면서 극대 왼쪽은 순증가 하고 오른쪽은 순감소하는(단조아님)
"함수의 극대 검색시 유용하게 쓰일수 있는 삼분검색에 대해 알아보자"
//이분법으로 극대를 찾을수 있지 않냐... 그건 0이 되는 지점 찾는데 썼었지...
//삼분서치는 유니모달순증가순감소 함수의 극대(최대치)를 찾는데 유용하네: 극소도 마찬가지
//p482: 삼분 검색의 구현
//우리가 최대치를 찾고 싶어하는 함수
double f(double x);
//[lo, hi]구간에서 f(x)가 최대치를 갖는 x를 반환한다.
double ternary(double lo, double hi) {
	for (int iter = 0; iter < 100; ++iter) {
		double a = (2 * lo + hi) / 3.0;
		double b = (lo + hi * 2) / 3.0;
		if (f(a) > f(b))
			hi = b;	//기존 hi 걸친 1/3 영역이 필요없어짐
		else
			lo = a; //기존 lo 걸친 1/3 영역이 필요없어짐
	}
	return (lo + hi) / 2.0;
}

//철인 2종 경기(알고스팟에 없더라: UVa Online Judge, 10385번, 중)
달리기와 자전거 2종류의 경기를 함
참가자는 0번 부터 n-1번까지 총 n명
달리기 속도와 자전거 속도가 주어지며 총 거리 t가 주어짐
달리기 경주 길이 r과 자전거 경주 길이 t-r이 어떻게 주어져야
n - 1이 우승하면서 2등과의 차이를 가장 좁힐수 있을까(오타같다) 벌릴수 있을까 인듯.
//일단 각 선수의 완주시간: time[i](r) = r/run[i] + (t-r)/cycle[i] 즉
"time[i]()는 r에 대한 선형 함수가 된다.
r = x, t = 300, run[i] = 4, cycle[i] = 10 : =----> time[i] = x / 4 + (300 - x) / 10

cheater(r) = time[n-1](r)

others(r) = min<i=0..n-2> { time[i](r) }

"우리가 구하고 싶은 것은 others(r) - cheaters(r) 의 최대치임
others(r)은 위로 볼록한 유니모달 함수 형태(단 극대가 수평일수 있음)이다.

볼록/오목함수의 중요한 성질
"1) f(x)가 볼록 함수라면 -f(x)는 오목 함수입니다. 물론 f(x)가 오목 함수라면 -f(x)는 볼록함수입니다.
"2) 볼록함수와 볼롬함수를 더한 결과도 볼록 함수입니다.
"3) 볼록함수에 상수를 곱한 결과도 볼록 함수입니다.
"참고로 선형함수는 볼록함수이기도 하지만 오목함수이기도 합니다."
오목함수 + 선형함수 => 오목함수
볼록함수 + 선형함수 => 볼록함수
"즉 others(r) - cheaters(r) => 오목함수 - 선형함수 => 오목함수 + 선형함수 =>오목함수가 됩니다.

//p485: 철인 2종 경기 문제를 해결하는 삼분 검색 알고리즘
double t;	//전체 거리
vector<double> runSpeed, cycleSpeed;
//달리기 구간의 길이가 run일 때, i번 선수가 걸리는 시간
double time(int i, double run) {
	double cycle = t - run;
	return run / runSpeed[i] + cycle / cycleSpeed[i];
}
//달리기 구간 길이가 r일 때, others(r) - cheater(r)를 반환한다.
double diff(double r) {
	int n = runSpeed.size();
	double cheater = time(n-1, r);
	double others = time(0, r);
	for (int i = 1; i < n - 1; ++i)
		others = min(others, time(i, r));
	return others - cheater;
}
//diff() 함수의 최대치의 위치를 삼분 검색으로 계산한다.
double maxDifference() {
	double lo = 0, hi = t;
	for (int it = 0; it < 100; ++it) {
		double aab = (2*lo + hi) / 3;
		double abb = (lo + 2*hi) / 3;
		if (diff(aab) > diff(abb))
			hi = abb;
		else
			lo = aab;
	}
	return (lo + hi) / 2;
}
int main() {
	while (cin >> t) {
		int n; cin >> n;
		runSpeed.resize(n);
		cycleSpeed.resize(n);
		rep(i,n) cin >> runSpeed[i] >> cycleSpeed[i];
		double ret = maxDifference();
		double timeDiff = diff(ret);
		if (diff < 0) printf("The cheater cannot win.\n");
		else {
			printf("The cheater can win by %.0lf second ", timeDiff * 3600);
			printf("with r = %.2lfkm and k = %.2lfkm\n", ret, t - ret);
		}
	}
}

//꽃가루 화석 (FOSSIL, 상)
//p491: 입력에 주어진 볼록 다각형을 껍질로 분해하기
struct point { double x, y; };
//입력에 주어진 볼록 다각형
vector<point> hull1, hull2;
//위 껍질에 속하는 선분들(hull1, hull2둘다 함께 저장)과 
//아래 껍질에 속하는 선분들(마찬가지로 hull1, hull2둘다 함께 저장)
vector<pair<point, point>> upper, lower;	//포인트들의 쌍이다!!!!
//hull이 반시계방향으로 주어지므로, 인접한 두 점에 대해
"x가 증가하는 방향이면 아래쪽 껍질"
"x가 감소하는 방향이면 위쪽 껍질이다!!!!"
void decompose(const vector<point>& hull) {
	int n = hull.size();
	for (int i = 0; i < n; ++i) {
		if (hull[i].x < hull[(i+1) % n].x)	//아래쪽 껍질
			lower.push_back(make_pair(hull[i], hull[(i+1) % n])); //선분이라 점두개
		else if (hull[i].x > hull[(i+1) % n].x)	//위쪽 껍질
			upper.push_back(make_pair(hull[i], hull[(i+1) % n]));
		//x가 같으면 쌩까네: 수직선은 생까야 됨
	}
}
//hull의 점 중 최소의 x좌표를 반환한다.
double minX(const vector<point>& hull) {
	double ret = 1e20;
	for (int i = 0; i < hull.size(); ++i) ret = min(ret, hull[i].x);
	return ret;
}
//hull의 점 중 최대의 x좌표를 반환한다.
double maxX(const vector<point>& hull) {
	double ret = -1e20;
	for (int i = 0; i < hull.size(); ++i) ret = max(ret, hull[i].x);
	return ret;
}
//[a.x, b.x] 구간 안에 x가 포함되나 확인한다.
bool between(const point& a, const point& b, double x) {
	return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x); 
	//내가 바꾼거: 쓸데없는 걱정이었음...
	//return(a.x <= x && x <= b.x) || (b.x <= x && x <= a.x) || fabs(a.x-x) < 1e-9 || fabs(b.x-x) < 1e-9;
}
//(a, b) 선분과 주어진 위치의 수직선이 교차하는 위치를 반환한다.
double at(const point& a, const point& b, double x) {
	double dy = b.y - a.y, dx = b.x - a.x;
	//선분 (a, b)가 수직인 경우 따로 처리한다.
	if (fabs(dx) < 1e-9) return a.y;	//이 코드 책에는 없음: 앞에서 수직을 생까서 그런듯
	
	//두점의 직선의 방정식: (y - a.y) = dy/dx * (x - a.x)
	//return a.y + dy * (x - a.x) / dx; //y = dy/dx * (x - a.x) + a.y 이렇게 하면 내게는 가독성 있는데...
	return dy/dx * (x - a.x) + a.y; //직선의 방정식에 x대입으로 y구한다
}
//두 다각형의 교집합을 수직선으로 잘랐을 때 단면의 길이를 반환한다.
double vertical(double x) {
	double minUp = 1e20, maxLow = -1e20;
	//위 껍질의 선분을 순회하며 최소 y 좌표를 찾는다.
	"두 볼록도형이 수직축을 기준으로 볼록한 선은 많아야 up0, up1 두개가 만들어 질껀데
	"그중 최저를 고른다"
	for (int i = 0; i < upper.size(); ++i)	//upper[i] => 점 두개가 들어있음
		if (between(upper[i].first, upper[i].second, x))//upper[i].first => x 혹은 y가 아님 x,y둘다임
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));
	//아래 껍질의 선분을 순회하며 최대 x 좌표를 찾는다.
	"오목한 선이 많아봐야 lo0, lo1 두개가 만들어 질껀데 그중 최고를 고른다.
	for (int i = 0; i < lower.size(); ++i)
		if (between(lower[i].first, lower[i].second, x))
			maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
	return minUp - maxLow;
}
수직선으로 자른 단면을 보자 o, x의 컨벡스 헐 경계에 대하여
   |
---o--- up0 
   |
---x--- up1
   |
---o--- lo0
   |
---x--- lo1
"이때 vertical(수직선|) 는 up1 - lo0 가 된다"
double solve() {
	//수직선이 두 다각형을 모두 만나는 x좌표의 범위를 구한다.
	//두 볼록 다각형 convex hull에 대하여
	"모든 y와 평형인 수직선과 두개가 동시에 겹치는 케이스가 없는지 확인한다."
	double lo = max(minX(hull1), minX(hull2));
	double hi = min(maxX(hull1), maxX(hull2));
	//예외 처리: 두 다각형이 좌우가 걸치는 x값이 존재 하지 않는 경우
	if (hi < lo) return 0;

	//삼분 검색
	for (int iter == 0; iter < 100; ++iter) {
		double aab = (lo*2 + hi) / 3.0;
		double abb = (lo + hi*2) / 3.0;
		if (vertical(aab) < vertical(abb))
			lo = aab;
		else
			hi = abb;
		//lo == hi인 경우 hi는 계속 유지될수 있겠지
		"단 부동소수의 안정성이 유지된다는 가정하에...
		"(lo*2 + lo) / 3.0 == lo 를 절대 보장하는가? 하겠지.. 적어도 표준 만드는 놈들이면 
		"아악 밑에 기술했지만... 보장을 안합니다..
		"lo, hi가 같은경우 처리 코드가 필요하겠다...
		"between 함수내에 넣으면 깔끔해지네
		//double num = 14.77;					//14.770000000000000
		//double num3 = (num * 2 + num) / 3.0;//14.770000000000001
		"음 테스트 케이스에 한직선에 세점이 올수 없다(두 볼록 포함해서)고 되어 있으니 쓸데 없는 걱정이었다...ㅠㅠ"
	}
	return max(0.0, vertical(hi));	
}
int main() {
	int cs; cin >> cs;
	rep(cc,cs) {
		int n, m;
		cin >> n >> m;
		hull1.resize(n);
		hull2.resize(m);
		rep(i,n) cin >> hull1[i].x >> hull1[i].y;
		rep(i,m) cin >> hull2[i].x >> hull2[i].y;
		upper.clear();
		lower.clear();
		decompose(hull1);
		decompose(hull2);//이러면 hull1,hull2의 볼록껍질은 합쳐지잖소(오목껍질도 마찬가지)
						 //그래도 동작하군요 알았습니다.
		printf("%.10lf\n", max(0.0, solve()));
	}
}

"이런 상황에서도 돌아가는가 imagine" 
"이런 테스트 케이스는 존재하지 않는다: 테스트 케이스에는 한 직선 위에 있는 세점이 주어지는 일도 없습니다."
_________
		|
		|____________
		|			|	
---------			|
		|			|
		|			|
		------------
int main() {
	rep(i, 1000000) {
		double test = (double)rand();
		test /= 123456123456.123456123456123;
		double test3 = test * 3.0;
		test3 /= 3.0; //test3가 클수도 있고 작을수도 있음을 확인했다...
		if (test3 == test)
			cout << i << ": ok" << endl;
		else
			cout << i << ": no" << endl;	//흐미.. 실행결과 조땐 상황이 나온다....여기서 브레이크 걸림...
	}
	return 0;
}

"꽃가루 화석 문제처럼 소수점 처리가 까탈스러울수 있는 경우, 문제를 잘 읽어보면 
"그 부분 신경안쓰도록 해논 테스트 케이스 제약사항이 있다.!!!!!"

struct point { double x, y; };
vector<point> hull1, hull2; vector<pair<point, point>> upper, lower;
void decompose(const vector<point>& hull) {
	int n = hull.size();
	rep(i,n) 
		if (hull[i].x < hull[(i+1) % n].x) //아래쪽 껍질
			lower.pb(mp(hull[i], hull[(i+1) % n])); //선분이라 점두개
		else if (hull[i].x > hull[(i+1) % n].x) //위쪽 껍질
			upper.pb(mp(hull[i], hull[(i+1) % n]));
}
double minX(const vector<point>& hull) {
	double ret = 1e20; rep(i,hull.size()) ret = min(ret, hull[i].x); return ret;
}
double maxX(const vector<point>& hull) {
	double ret = -1e20;	rep(i,hull.size()) ret = max(ret, hull[i].x); return ret;
}
bool between(const point& a, const point& b, double x) {
	return (a.x <= x & x <= b.x) || (b.x <= x && x <= a.x);
}
double at(const point& a, const point& b, double x) {
	double dy = b.y - a.y, dx = b.x - a.x;
	if (fabs(dx) < 1e-9) return a.y;	//이 케이스틑 안탄다.
	return dy/dx * (x - a.x) + a.y;
}
double vertical(double x) {
	double minUp = 1e20, maxLo = -1e20;
	rep(i,upper.size())
		if (between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));
	rep(i,lower.size())
		if (between(lower[i].first, lower[i].second, x))
			maxLo = max(maxLo, at(lower[i].first, lower[i].second, x));
	return minUp - maxLo;
}
double solve() {
	double lo = max(minX(hull1), minX(hull2));
	double hi = min(maxX(hull1), maxX(hull2));
	if (hi < lo) return 0;
	rep(iter,100) {
		double aab = (lo*2 + hi) / 3.0;
		double abb = (lo + hi*2) / 3.0;
		if (vertical(aab) < vertical(abb))
			lo = aab;
		else
			hi = abb;
	}
	return max(0.0, vertical(hi));
}
int main() {
	int cs; cin >> cs;
	rep(cc,cs) {
		int n, m; cin >> n >> m;
		hull1.resize(n);
		hull2.resize(m);
		rep(i,n) cin >> hull1[i].x >> hull1[i].y;
		rep(i,m) cin >> hull2[i].x >> hull2[i].y;
		upper.clear(); lower.clear();
		decompose(hull1); decompose(hull2);
		printf("%.10lf\n", max(0.0, solve()));
	}
}

//---------------------------- 14장 : 정수론 -------------------------------------//
//p496 O(root(n)) 시간에 동작하는 소수 판별 알고리즘
//idea> 100 : 10 * 10
//25가 약수라면 4도 약수겠죠.
//즉 4를 보면 25는 안봐도 됩니다.
//주어진 자연수 n이 소수인지 확인한다.
bool isPrime(int n) {
	//예외 처리: 1과 2는 예외로 처리한다.
	if (n <= 1) return false;
	if (n == 2) return true;
	//2를 제외한 모든 짝수는 소수가 아니다.
	if (n % 2 == 0) return false;
	//2를 제외했으니 3이상의 모든 홀수로 나누어보자.
	int sqrtn = int(sqrt(n));
	for (int div = 3; div <= sqrtn; div += 2)
		if (n % div == 0)
			return false;
	return true;
}
n 이 101 인 경우
101 % 3 = 2
101 % 4 = 3
101 % 5 = 1
101 % 6 = 5
101 % 7 = 3
101 % 8 = 5
101 % 9 = 2
101 % 10 = 1

11 인 경우 제곱인 121 이후부터 커버확인에 필요함 
즉 10 을 가지고 120까지는 확인이 가능하다.

//p497 간단한 소인수 분해 알고리즘(약수찾는게 아니다!!!! 소수 찾는거임)
//주어진 정수 n을 소인수분해하는 간단한 알고리즘
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
div		n(100)
2		50
		25
5		5
		1
ret = {2, 2, 5, 5}가 된다.
n % div == 0 이 성공한 횟수를 기록하여
전체 약수의 개수를 구할 수 있고, 전체 약수도 구할수 있다.
약수의 갯수: (2 + 1) * (2 + 1) = 9개
전체 약수: {1, 2, 4} concat{1, 5, 25} => {1, 2, 4, 5, 10, 20, 25, 50, 100}

div		n(100) : sqrtn = 10
2		55
5		11
루프가 종료시 n은 11이므로 11도 ret에 포함시킨다.
ret = {2, 5, 11}
약수의 갯수: (1 + 1} * {1 + 1} * {1 + 1} = 8
전체 약수: {1, 2} concat {1, 5} concat {1, 11} => {1, 2, 5, 10, 11, 22, 55, 110}


//에라토스테네스의 체
원리
2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  ...
2의 배수를 지운다(2는 제외)
2  3     5     7     9      11      13      15      17      19      21  ...
3의 배수를 지운다(3은 제외): 이때 9부터 지워짐을 주의깊게 보삼 (3 * 2 는 2의 배수에서 처리된 수임)
2  3     5     7            11      13              17      19          ...
4는 지워진 수이므로 생략
5의 배수를 지운다(5는 제외) 5*5 부터 지워짐
2  3     5     7     9      11      13              17      19          ...
//p499 에라토스테네스의 체
int n;
bool isPrime[MAX_N + 1];
//가장 단순한 형태의 에라토스테네스의 체의 구현(좀만 더 최적화 하면 복잡도가 O(nloglogn) 임, 즉 정말 빠름)
//종료한 뒤 isPrime[i] => i가 소수인지 여부가 세팅되어 있음
void eratosthenes() {
	memset(isPrime, 1, sizeof(isPrime)); //bool 인 경우 1로 세팅되음 확인했다(vs2014)
										 //int인 경우 16843009 = 0x01010101 임
										 //byte단위로 세팅됨
	//1은 항상 예외 처리!
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i) //위에선 sqrtn나누었지만 여기선 sqrtn까지 곱해서 찾는 방식임
		//이 수가 아직 지워지지 않았다면(소수라면)
		if (isPrime[i])
			//i의 배수 j들에 대해 isPrime[j] = false로 둔다.
			//i * i 미만의 배수는 이미 지워졌으므로 신경 쓰지 않는다. !!!!
			//왜 sqrtn까진지 알겠군.
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
}		
에라토스테네스의 체를 구현할 때 문제가 되는 것은 시간보다는 메모리 사용량임.
짝수를 별도 처리해서 필요한 배열의 크기를 절반으로 줄이거나
비트마스크를 이용하여 메모리의 양을 줄일 수 있다.
에라토스테네스의 체는 여러 형태로 변형할 수 있기 때문에 
여러 정수론 문제를 푸는 데 가장 유용하게 사용됩니다.!!!!

//p501 에라토스테네스의 체를 이용한 빠른 소인수 분해
//minFactor[i] = i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
int minFactor[MAX_N];
//에라토스테네스의 체를 수행하면서 소인수분해를 위한 정보도 저장한다.
void eratosthenes2() {
	//1은 항상 예외 처리
	minFactor[0] = minFactor[1] = -1;
	//모든 숫자를 처음에는 소수로 표시해 둔다.
	for (int i = 2; i <= n; ++i)
		minFactor[i] = i;
	//에라토스테네스의 체를 수행한다.
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i) {
		if (minFactor[i] == i) {	//i가 소수인 경우
			for (int j = i * i; j <= n; j += i)
				//아직 약수를 본 적 없는 숫자인 경우 i를 써 둔다.(아직 처리되지 않은 수)
				if (minFactor[j] == j)
					minFactor[j] = i;	//넌 소수가 아니야!~
		}
	}
}
//2이상의 자연수 n을 소인수분해한 결과를 반환한다.
"단점: n이 MAX_N 보다 작아야 돌릴수 있네.. 이런 경우엔 simple 이 더 좋겠다.
vector<int> factor(int n) {
	vector<int> ret;
	//n이 1이 될 때까지 가장 작은  소인수로 나누기를 반복한다.
	while (n > 1) {
		ret.push_back(minFactor[n]);
		n /= minFactor[n];
	}
	return ret;
}
n = 100
minFactor[100]	= 2, n = 50
minFactor[50]	= 2, n = 25
minFactor[25]	= 5, n = 5
minFactor[5]	= 5, n = 1

n = 110
minFactor[110]	= 2, n = 55
minFactor[55]	= 5, n = 11
minFactor[11]	= 11, n = 1

소인수: 약수(인수)중에서 소수인 것들을 소인수라 함
12의 소인수는 2, 3이 된다!!!!

//비밀번호486: PASS486
3//테스트 50개, 약수의 개수 400, lo,hi: 10,000,000
2 2 10	//약수의 개수, lo, hi (비밀번호가 될수 있는 숫자의 범위)
12 486 486
200 100000 2000000
//재훈이가 12번째로 금연을 다짐했을 때 쓴 비밀번호중 하나는 486
//486의 약수의 개수는 12개 {1, 2, 3, 6, 9, ..., 243, 486 }
출력
4
1
19
//p504 1천만 이하의 모든 수의 약수의 수를 계산하는 알고리즘
//Ten Million
const int TM = 1000*1000*10;
//minFactor[i] = i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
int minFactor[TM + 1]; //eratosthenes2() 수행해서 세팅됨
//minFactorPower[i] = i의 소인수 분해에는 minFactor[i]의 몇 승이 포함되어 있는가? !!!!
int minFactorPower[TM + 1];
//factor[i] = i가 가진 약수의 수
int factors[TM + 1];
//여긴bigO(N) 이넹.. 준비하는 에라토스테네스에서 더 걸린다.
void getFactorsSmart() {
	factors[1] = 1;
	for (int n = 2; n <= TM; ++n) {
		//소수인 경우 약수가 두 개 밖에 없다.
		if (minFactor[n] == n) {
			minFactorPower[n] = 1;
			factors[n] = 2;
		}
		//소수가 아닌 경우, 가장 작은 소인수로 나눈 수(m)의
		//약수의 수를 응용해 n의 약수의 수를 찾는다.
		else {
			int p = minFactor[n];		//n = 2 x 3^2 x 5, p = 2
			int m = n / p;				//m = n / 2 = 3^2 x 5
			//m이 p로 더이상 나누어지지 않는 경우
			if (p != minFactor[m])		//p = 2 , minFactor[m] = 3
				minFactorPower[n] = 1; //n의 가장 작은 소인수인 2는 한개임
			else
				//m 은 n보다 작으며 따라서 minFactorPower[m]은 이전에 이미 계산되었다
				minFactorPower[n] = minFactorPower[m] + 1;	
			int a = minFactorPower[n];	
			factors[n] = (factors[m] / a) * (a + 1);	"!!!! 기똥차다"
			//가독성 있게 한다면: factors[m] * (a+1) / a
		}
	}
}
33750	= 2^1 * 3^3 * 5^4
67500	= 2^2 * 3^3 * 5^4
101250	= 2^1 * 3^4 * 5^4
33750의	약수의 개수	: (1+1) * (3+1) * (4+1) = 40개
67500의	약수의 개수	: 40 * (2+1)/2 = 60개
101250의 약수의 개수: 40 * (4+1)/4 = 50개 //케케 소스는 이렇게 되지 않았죠 minFactor[101250]은 2입니다.
"즉 50625 = 3^4 * 5^4 의 약수의 개수 25 에다가 2/1 을 곱하여 50을 구하죠"

//p506 1천만 이하의 모든 수의 약수의 수를 계산하는 단순한 알고리즘
//nlogn 인데 너무 내부가 단순해서 1초내 수행 가능
void getFactorsBrute() {
	memset(factors, 0, sizeof(factors));
	for (int div = 1; div <= TM; ++div)
		for (int multiple = div; multiple <= TM; multiple += div)
			factors[multiple] += 1;
}

      \div	1 2 3 4 5 6 7 8 9 10 ...
factors\ 
	0		사용안함
	1		1						factor[1] = 1
	2		1 1						factor[2] = 1 + 1
	3		1   1					factor[3] = 1 + 1
	4		1 1   1					factor[4] = 1 + 1 + 1
	5		1       1				factor[5] = 1 + 1
	6		1 1 1     1				factor[6] = 1 + 1 + 1 + 1
	7		1           1			factor[7] = 1 + 1
	8		1 1   1       1			factor[8] = 1 + 1 + 1 + 1
	9		1   1           1		factor[9] = 1 + 1 + 1
	10		1 1     1         1		factor[10] = 1 + 1 + 1 + 1
	.
	.
	.

//gcd(6, 15) = gcd(9, 6) = gcd(3, 6) = gcd(3, 3) = gcd(0, 3) = 3
int gcd(int p, int q) {
	if (p < q) swap(p, q);
	if (q == 0) return p;
	return gcd(p - q, q);
}

//p507 유클리드 알고리즘의 구현
int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p % q);	"최초호출시 q가 더 크다 한들 여기서 swap 되넹!!!! 짱"
	//gcd(0, 8) = gcd(8, 0) = 8// 0 % 8 = 0
}

//마법의 약
//비율을 일정하게 유지해야 한다고 할때
//넣어야 할 각 재료의 최소량을 계산하는 프로그램을 작성하시오
3
4
4 6 2 4	//재료비율
6 4 2 4 //지금까지 넣은거
<0 5 1 2> //출력
4
4 6 2 4
7 4 2 4
<1 8 2 4>
3
4 5 6
1 2 3
<3 3 3>

두번째 예제를 푸는 과정
첫 번째 재료는 네 숟가락 넣어야 하는데 일곱 숟가락 넣었습니다. 따라서 다른 재료들도 최소한 
원래 레시피의 7/4배는 넣어야 할 겁니다.
이에 따르면 두 번째 재료는 6 * 7/4 = 10.5 숟가락은 넣어야 하는데 우리는 한 숟가락 단위로밖에
넣을 수 없으니 총 열한 숟가락이 되도록 더 넣습니다. 따라서 다른 재료들도 11/6배는 넣어야 할 겁니다.
!!!!
이에 따르면 첫 번째 재료는 4 * 11/6 = 7.33.. 숟가락은 넣어야 하는데 우리는 짜증나게 되고
총 8숟가락이 되도록 더 넣습니다. 따라서 다른 재료들도 최소한 원래 레시피의 8/4 = 2배는 넣어야 할 겁니다.

put[j] >= recipe[j] * put[i]/recipe[i] //!!!!


//p510 마법의 약 문제를 해결하는 단순한 알고리즘
//마법의 약 레시피와 이미 넣은 재료의 양이 주어질 때, 더 넣을 재료의 양을 구한다.
"레시피의 비율은 맞추되 넣을 재료가 정수형으로 맞추어야 되는 제약을 어찌 처리하는가 잘봐라"
"i를 기준으로 레시피에 대한 정수비를 만들면 다른 j에 대해서도 정수비가 만들어지면 편하지만"
"그렇지 않고 소수점형태가 되면 다시 i도 수정해야 되니(나머지 것들도..ㅠㅠ)"
vector<int> solveSimulation(const vector<int>& recipe, vector<int> put) {
	vector<int> oa = put; //쓸모없는 코드(책에 있었음)
	int n = recipe.size();
	vector<int> ret(n);
	//각 재료를 최소한 recipe에 적힌 만큼은 넣어야 한다.
	for (int i = 0; i < n; i++) {	//!!!!
		ret[i] = max(recipe[i] - put[i], 0);
		put[i] += ret[i];
		//recipe =	{4, 6, 2, 4}
		//ret	 =	{0, 2, 0, 0}
		//put	 =	{7, 4, 2, 4} => {7, 6, 2, 4}
	}
	//비율이 전부 맞을 때까지 재료를 계속 추가하자.
	int iter = 0; //쓸모없음 (while 루프 횟수 체크용)
	while (true) {
		++iter;
		//냄비에 재료를 더 넣지 않아도 될 때까지 반복한다.
		bool ok = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				//i번째 재료에 의하면 모든 재료는 put[i] / recipe[i] = X 배 이상은 넣어야 한다.
				//따라서 put[j]는 recipe[j] * X 이상의 정수가 되어야 한다.
				//put[j] = ceil(recipe[j] * put[i], recipe[i])
				int required = (recipe[j] * put[i] + recipe[i] - 1) / recipe[i]; //!!!!오오오오 핵심
				//required = recipe[j] * put[i]/recipe[i]에서 정수화를 위해
				"+ recipe[i] - 1 은 정수화를 위한 멋진 꼼수다. 올림 효과임"

				if (required > put[j]) { //더 넣어야 하는가?
					ret[j] += required - put[j];
					put[j] = required;
					ok = false;
				}
			}
		if (ok) break;
	}
	return ret;
}

효율적으로 짜보세
X = max(put[i] / recipe[i])
recipe[i] * X 는 항상 정수여야 하기 때문해 실제로 레시피에 곱해야 하는 수 
Y는 X이상의 어떤 유리수입니다. 따라서 Y = a/b라고 쓰도록 합시다.
X <= Y = a/b
이때 모든재료에 대해 recipe[i] * Y 가 정수인 최소의 Y를 찾고 싶습니다.
모든 i에 대해 recipe[i] * a/b가 정수가 되기 위해서는 b는 recipe[]의 모든 수들의 약수!!!!
가 되어야 합니다.
따라서 recipe[]의 모든 수들의 최대공약수를 b로 둡시다.
X <= a/b
X * b <= a 를 만족하는 최소의 정수 a를 구해봅시다.

"각 재료 분량의 최대공약수 b를 구하고 나면 원래 레시피를 1/b * rec 분량으로 단위화 할수 있지요"
rec[i] / b 는 항상 정수입니다.
우리가 만든 분량이 X이상이 될 때까지 1/b * rec 분량을 계속 (a횟수만큼 반복하여) 더하면 됩니다.

코드는 put[i]/recipe[i]의 최대값 X를 구하고 거기에 b를 곱해서 올림하여 a를 얻는 것이 아니라
ceil함수를 보면 알수 있듯 유리수가 발생할 분수 연산을 없앴어용.


//p512 마법의 약 문제를 해결하는 O(n)알고리즘
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
//분수 a/b보다 같거나 큰 최소의 자연수를 반환한다. //!!!!
int ceil(int a, int b) {
	return (a + b - 1) / b;
}
//마법의 약 레시피와 이미 넣은 재료의 양이 주어질 때, 더 넣을 재료의 양을 구한다.
vector<int> solve(const vector<int>& recipe, const vector<int>& put) {
	int n = recipe.size();
	//모든 recipe[]의 최대공약수를 구한다.
	int b = recipe[0];
	for (int i = 1; i < n; ++i) b = gcd(b, recipe[i]); //!!!!
	//최소한 b/b = 1배는 만들어야 하므로, a의 초기 값을 b로 둔다.
	int a = b;
	//X를 직접 구하는 대신 ceil(put[i] * b, recipe[i]) 의 최대값을 구한다.
	for (int i = 0; i < n; ++i)
		a = max(a, ceil(b * put[i], recipe[i])); //!!!!
		//a = max{ceil(put[i]/recipe[i] * b)}
	// a/b배 분량을 만들면 된다.
	vector<int> ret(n);
	for (int i = 0; i < n; ++i)
		ret[i] = recipe[i] * a / b - put[i];
	return ret;
}
곱해야 하는 수 를 구하는 원리를 익히삼 
"X <= Y = a / b, Y는 rec[i]에 곱해서 모든것을 정수로 만들어 주는 최소 수"
vector<int> solve(const vector<int>& recipe, const vector<int>& put) {
	int n = recipe.size();
	int b = recipe[0];
	rep2(i,1,n) b = gcd(b, recipe[i]);
	//최소한 b/b = 1배는 만들어야 하므로, a의 초기 값을 b로 둔다.
	int a = b;
	"recipe[i]/b = segRec[i]가 몇배 필요한지 구하고 그중 최고배수를 a로 둔다"
	rep(i,n)
		a = max(a, ceil(put[i], recipe[i] / b));
	vector<int> ret(n);
	rep(i,n)
		ret[i] = recipe[i] / b * a - put[i];
	return ret;
}

ex1)
put[i]		= {7, 4, 2, 4}
rec[i]		= {4, 6, 2, 4}
b(rec의 gcd) = 2
segrec[i]	= {2, 3, 1, 2}
put/rec		= {7/4, 4/6, 2/2, 4/4}
put/rec의 max = 7/4
a = ceil( 7/4 * b ) = ceil( 7/4 * 2 ) = 4
rec[i] * a / b = rec[i] * 4 / 2 = {8, 12, 4, 8}

ex2)
put[i]		= {6, 4, 2, 4}
rec[i]		= {4, 6, 2, 4}
b(rec의 gcd) = 2
segrec[i]	= {2, 3, 1, 2}
put/rec		= {6/4, 4/6, 2/2, 4/4}
put/rec의 max = 6/4
a = ceil(6/4 * b) = ceil(6/4 * 2) = 3
rec[i] * a / b = rec[i] * 3 / 2 = {6, 9, 3, 6}


//모듈라 연산
(a + b) % M = ((a % M) + (b % M)) % M
(a - b) % M = ((a % M) - (b % M) + M) % M
(a * b) % M = ((a % M) * (b % M)) % M

(a / b) % M = ((a % M) / (b % M)) % M //은 성립하지 않는다.
모듈라 연산에서의 나눗셈 a/b는 b로 나누는 대신 b의 곱셈 역원(multiplicative inverse)을
곱하는 방식으로 이루어집니다. b의 곱셈 역원은 항상 존재하는 것이 아니라, b가 M과 서로소
일 때만 존재합니다. 예를 들어 M = 100이라면 25의 곱셈 역원은 존재하지 않습니다.
(p514 페르마의 소정리 위키 보삼)

//읽어볼것(책에는 없당)
//확장 유클리드 알고리즘(Extended Euclidean algorithm)

//중국인 나머지 정리(Chinese Remainder Theorem)

//루카스의 정리(Lucas' Theorem): 모듈라 연산을 이용한 이항 계수 nCr을 빠르게
//구할 수 있게 해주는 정리로써, 모듈라 연산을 이용하지 않을 경우엔 계산하기 어려울
//정도로 큰 n과 r에 대해 이항 계수를 계산할 수 있도록 해 줍니다.

//----------------------------- 15장 계산기하 ------------------------------//

//p518 2차원 벡터를 표현하는 vector2 클래스의 구현
const double PI = 2.0 * acos(0.0); //acos(0.0) = pi/2 = 90도를 의미(물론 라디안 단위다)
			"PI의 정확도는 의심하지 않아도 될 수준이다. 매우 정밀함"
//2차원 벡터를 표현한다.
struct vector2 {
	double x, y;
	//생성자를 explicit으로 지정하면 vector2를 넣을 곳에 잘못해 실수가 들어가는 일을 방지해 준다.
	// https://purestarman.tistory.com/110 위 말이 좀 이상하다. 링크 들어가봐라 도움 됨.
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	//두 벡터의 비교
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;	//x우선 비교 후 y비교: 특이 용도일뿐 일반적인건 아니네
	}
	//벡터의 덧셈과 뺄셈
	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	//실수로 곱셈
	vector2 operator * (double rhs) const {
		return vector2(x * rhs, y * rhs);
	}
	//벡터의 길이를 반환한다.
	double norm() const { return hypot(x, y); } //sqrt(x^2 + y^2)
	//방향이 같은 단위 벡터(unit vector)를 반환한다.
	//영벡터에 대해 호출한 경우 반환 값은 정의되지 않는다.
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	//x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도 , y가 증가할 수록 위로 가는 좌표계
	//[+0, +PI], [-PI, -0] ==> 쓰기 정말 불편하니 [0, 2PI) 로 변경시키자
	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
	//내적/외적의 구현
	double dot(const vector2& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	double cross(const vector2& rhs) const {
		return x * rhs.y - rhs.x * y;
	}
	//이 벡터를 rhs에 사영한 결과
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);	//방향단위벡터 * 사영된 크기(내적 == 사영 시키고 곱한거임)
		//r.dot(*this) : r은 단위벡터이며 단위벡터에 사영된 크기를 구할수 있다.
		//거기에 크기에 단위벡터 r을 곱하니 사영된 결과가 된다.
	}
	this[x: 10, y: 10],		rhs[x: 5, y: 0]
	r = x: 1, y: 0
	r.dot(this) = 10
	return 값은 x: 10, y: 0 인 결과를 가진다.
	
	this[x: -10, y: 10],	rhs[x: 5, y: 0]
	r = x: 1, y: 0
	r.dot(this) = -10
	return 값은 x: -10, y: 0 인 결과를 가진다.
};
//atan2(y, x) : 리턴 범위(-π, π]
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

//세개의 점 p, a, b 가 주어졌을 때 a가 b보다 p에 얼마나 더 가까운지 반환하는 함수를 작성
double howMuchCloser(vector2 p, vector2 a, vector2 b) {
	//Vpb의 길이랑 Vpa의 길이의 차이
	return (b - p).norm() - (a - p).norm();
}
double howMuchCloser(double px, double py, double ax, double ay, double bx, double by) {
	return sqrt((bx - px) * (bx - px) + (by - py) * (by - py))
		 - sqrt((ax - px) * (ax - px) + (ay - py) * (ay - py));
}

//p525 두 벡터의 방향성을 판단하는 ccw() 함수의 구현
//원점에서 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수
//평행이면 0을 반환하다.
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}
//점 p를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수,
//평행이면 0을 반환한다.
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}


//p526 두 직선의 교차점을 계산하는 lineIntersection() 함수의 구현
//(a, b)를 포함하는 직선과 (c, d)를 포함하는 직선의 교점을 x에 반환한다.
//두 선이 평행이면(겹치는 경우를 포함) 거짓을, 아니면 참을 반환한다.
bool lineIntersection(	vector2 a, vector2 b,
						vector2 c, vector2 d,
						vector2& x) {
	double det = (b - a).cross(d - c);	// 두 직선의 외적
	//두 선이 평행인 경우
	if (fabs(det) < EPSILON) return false;
	x = a + (b - a) * ((c - a).cross(d - c) / det);		
	// "선분ac x 선분cd : 면적"  Ratio  "선분ab x 선분cd : 면적" // 비율을 상상하면 이해하기 쉽다.
	return true;
}
https://bowbowbow.tistory.com/17
직선의 방정식 표현 : 
	A + p*B		// A: a벡터,	B: (b - a)벡터,	p 는 스칼라
	C + q*D		// C: c벡터,	D: (d - c)벡터,	q 는 스칼라
직선위의 점은 성분 표현으로 
	(A_x + p*B_x,	A_y + p*B_y)
	(C_x + q*D_x,	C_y + q*D_y)
두 직선위의 점이 일치하려면
	A_x + p*B_x = C_x + q*D_x		// 1)
	A_y + p*B_y = C_y + q*D_y		// 2)
p에 대해 풀면 다음과 같다. // q를 삭제시키위해 위 식 1)의 양변에 D_y를 곱한다. 식 2) 의 양변에 D_x 를 곱한다. 그리고 빼고 p 에 대해 정리
          (C_x - A_x) * D_y - (C_y - A_y) * D_x
	p = ----------------------------------------
				B_x * D_y - B_y * D_x		// 이게 0이 되면 교차점이 존재하지 않는다.
	
위 식을 외적으로 더 간략하게 나타낼 수 있다.
         (C - A) x D		// x 는 cross product
	p = --------------
           (B x D)			// 마찬가지로 0이 되면 교차점이 존재하지 않는다.

교점인 지점 x 는 A + p*B 로 표현하면 다음과 같다.
	// 연산자 오버로딩 구현이 귀찮아서 A + B*p 로 표현함 (구현하려면 friend 가 필요)
	x = A + B * p
	x = A + B * ((C - A) x D / (B x D))
	x = A + B       * ((C - A) x D          / (B x D))
	x = a + (b - a) * ((c - a).cross(d - c) / det);		
	// a 랑 c는 A, C 대응한다만, D == d - c, B == b - a 대응임!!!!!!!!



line(직선), segment(선분)의 차이를 인식하라!!!!
//p527 선분과 선분의 교차점을 계산하는 segmentIntersection()의 구현
//(a, b)와 (c, d)가 평행한 두 선분일 때 이들이 한 점에서 겹치는지 확인한다.
"true 리턴: 접점이 존재"
"false 리턴: 접점이 무존재"
bool parallelSegments(	vector2 a, vector2 b,
						vector2 c, vector2 d,
						vector2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);
	//한 직선 위에 없거나 두 선분이 겹치지 않는 경우를 우선 걸러낸다.
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;	//a---b---c---d || c---d---a---b
	//두 선분은 확실히 겹친다. 교차점을 하나 찾자.(크게는 이 세가지 형태: 총 6가지)
	//a---c---b---d || c---a---b---d || a---bc---d
	if (a < c) p = c;
	else p = a;
	return true;
}
//p가 (a, b)를 감싸면서 각 변이 x, y 축에 평행한 최소 사각형 내부에 있는지 확인한다.
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
	if (b < a) swap(a, b);
	return p == a || p == b || (a < p && p < b);
}
//(a, b) 선분화 (c, d)선분의 교점을 p에 반환한다.
//교점이 여러 개일 경우 아무 점이나 반환한다.
//두 선분이 교차하지 않을 경우 false 를 반환한다.
bool segmentIntersection(	vector2 a, vector2 b,
							vector2 c, vector2 d,
							vector2& p) {
	//(a, b)를 포함하는 직선과 (c, d)를 포함하는 직선이 평행인 경우를 우선 예외로 처리
	if (!lineIntersection(a, b, c, d, p))	//두 직선이 평행(겹침 포함) => false
											//교차시 p 는 두 직선의 교차점이 된다. => true;
											//두 선분의 교차점이 아니다!!!!
		return parallelSegments(a, b, c, d, p);		//두 선분이 기울기가 같은데 겹치지 않으면 false를 리턴
													//겹친다면 true 리턴하고 p는 겹치는 구간중 아무 점이 된다.
	//두 선분이 실제 크로스(직선의 크로스가 아님)가 된다면
	//p가 두 선분에 포함되어 있고 이 경우에만 참을 반환한다.
	return	inBoundingRectangle(p, a, b) &&
			inBoundingRectangle(p, c, d);
}

"실제 두 직선의 관계가 크로스지만 parallelSegments 에서 epsilon 으로 평행관계 판정을 받고 나서"
"segmentIntersection 에서 직선위에 선이 없다고 false 를 리턴받게 되면"
"거리가 먼 평행으로 판정내리게 된다. " 이 문제를 피할려면 우찌 해야 되나.

교차점을 구할 필요 없이 두 선분의 교차 여부를 확인하기만 할 거라면 보다 단순한 방법이 있어용
//p529 두 선분의 교차 여부를 좀더 간단하게 확인하는 segmentIntersects() 함수의 구현
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	//두 선분이 한 직선 위에 있거나 끝점이 겹치는 경우
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);//한 직선 위에 두 선분이 겹치고 있지 않는 경우 false를 리턴
	}
	return ab <= 0 && cd <= 0;
}

//p530 점과 선 사이의 거리를 계산하는 함수 pointToLine()의 구현
//점 p에서 (a, b)직선에 내린 수선의 발을 구한다.(사영벡터에 위치벡터 a를 더함으로써 수선의 발 구함)
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b) {
	return a + (p - a).project(b - a);
}
//점 p와 (a, b)직선 사이의 거리를 구한다.
double pointToLine(vector2 p, vector2 a, vector2 b) {
	return (p - perpendicularFoot(p, a, b)).norm();
}

//핀볼 시뮬렝션(PINBALL, 상)
두 장애물 사이의 거리가 2 이하인 경우는 없습니다.(2 초과임)
시작 위치에서 공은 장애물과 겹쳐 있거나 닿아있지 않습니다.
입력에서 공이나 장애물의 크기가 10^-7 만큼 변하더라도 답은 변하지 않는다고 보십시오(EPSILON을 어느정도 둘지 가늠해준다)
1
5 5 1 1 5	//시작위치, 방향벡터(<6,6>으로 움직이겠군), 장애물 개수
22 40 12	//X, Y, 장애물 반지름
61 26 20
19 78 21
51 86 7
84 57 15
직선의 방정식(벡터표현)
궤적 = P + aQ => "공이 1초에 D만큼 굴러간다고 하고, 공의 궤적을 시간 t에 대해 표현하면"
"f(t) = P + tD (t >= 0) 이 된다" t의 단위는 s(초) 이고, D의 단위는 변위/s 임!!!!
//p535: 장애물과의 충돌 시점을 찾는 함수의 구현
const double EPSILON	= 1e-9;
const double INFTY		= 1e200;
//2차 방정식 ax^2 + bx + c = 0 의 모든 실근을 크기 순서대로 반환한다.
vector<double> solve2(double a, double b, double c) {
	double d = b*b - 4*a*c;
	//해가 없는 경우
	if (d < -EPSILON) return vector<double>();
	//중근
	if (d < EPSILON) return vector<double>(1, -b/(2*a));
	vector<double> ret;
	ret.push_back((-b - sqrt(d)) / (2 * a));
	ret.push_back((-b + sqrt(d)) / (2 * a));
	return ret;
}
//here에 있던 공이 1초마다 dir만큼 굴러갈 때, center를 중심으로 하고
//반지름 radius인 장애물과 몇 초후에 충돌하는지 반환한다.
//충돌하지 않을 경우 '아주 큰 값' INFTY를 반환한다.
double hitCircle(vector2 here, vector2 dir,
				 vector2 center, int radius) {
	//직선과 원이 만나는 점을 구하는 방정식
	double a = dir.dot(dir);
	double b = 2 * dir.dot(here - center);
	double c = center.dot(center) + here.dot(here)
			 - 2 * here.dot(center) - radius * radius;	//이거 전개는 좀 길다...
	vector<double> sols = solve2(a, b, c);
	if (sols.empty() ||		//근이 없거나(원과 직선이 안만남) : 허근을 가짐
		sols[0] < EPSILON)	//과거에 만난 경우(t가 0보다 작은곳에서 만남): 
							// 근이 중근이고 eps 보다 작은 경우: 과거에 접선으로 만남
							// 구든이 모두 eps보다 작은 경우: 과거
							// 두근중 한놈은 과거 한놈은 미래에 만남 : 원안에서 뻗어나가는 형태
							// 두근이 모두 미래인 경우: 좀더 빨리 만나는 놈을 선택
							
		return INFTY;		//만약 -EPSILON < sols[0] < EPSILON 이라면 이건 반사가 시작된 부분이라 INFTY리턴함!!!!
	return sols[0];
}
//P: Here, D: dir
C(center), f(t) = P + tD, r(radius) //대문자, f(t)는 벡터단위임,	소문자 t,r 은 스칼라임
|C - f(t)| = r	//| | 절대값 기호가 아니라 벡터의 크기임
(C - f(t)) * (C - f(t)) = r^2 //*: 내적기호
C*C - 2C*f(t) + f(t)*f(t) = r^2
C*C - 2C*(P + tD) + P*P + 2P*Dt + D*D*t^2 = r^2
C*C - 2C*P -2C*Dt + P*P + 2P*Dt + D*D*t^2 - r^2 = 0
D*D*t^2 + 2(P-C)*D*t + C*C + P*P - 2(C*P) - r^2 = 0

// 벡터의 크기는 벡터의 길이가 된다.
// 벡터 크기를 제곱 == 벡터 dot 벡터 가 된다.

//p536: 공이 장애물에 부딪힌 이후 움직일 각도를 계산하는 reflect
//here에 있던 공이 dir 방향으로 굴러와 center를 중심으로 하는 장애물에서
//contact 위치에서 충돌했을 때 공의 새로운 방향을 반환한다.(단위벡터로 리턴함)
// https://book.algospot.com/errata.html // 정오표 here 입력은 필요없다.
vector2 reflect(vector2 here, vector2 dir, vector2 center, vector2 contact) {	
	return (dir - dir.project(contact - center) * 2).normalize();
}
//p537: 핀볼 시뮬레이션 문제를 해결하는 시뮬레이션 코드
//공의 현재 위치와 방향이 주어질 때 최대 10번의 충돌을 출력한다. (O(nk)) n = 50, k = 10 충분히 돌아가넹
void simulate(vector2 here, vector2 dir) {
	//방향은 항상 단위 벡터로 저장하자.
	dir = dir.normalize();
	int hitCount = 0;
	while (hitCount < 10) {
		//이번에 충돌할 장애물을 찾는다.
		int circle = -1;
		double time = INFTY * 0.5;
		//각 장애물을 순회하며 가장 먼저 만나는 장애물을 찾는다.
		for (int i = 0; i < n; ++i) {
			double cand = hitCircle(here, dir, center[i], radius[i] + 1);
			if (cand < time) {	//가장 빠른 놈을 찾자
				time = cand;
				circle = i;
			}
		}
		//더이상 장애물에 충돌하지 않고 게임판을 벗어난 경우
		if (circle == -1) break;
		//부딪히는 장애물의 번호를 출력한다.
		if (hitCount++) cout << " ";
		cout << circle;
		//공의 새 위치를 계산한다.
		vector2 contact = here + dir * time; //!!!!
		//부딪힌 위치와 새 방향으로 here과 dir을 변경한다.
		dir = reflect(here, dir, center[circle], contact);
		here = contact;
	}
	cout << endl;
}

//p540: 단순 다각형의 넓이를 구하는 area() 함수의 구현
//주어진 단순 다각형 p의 넓이를 구한다.
//p는 각 꼭지점의 위치 벡터의 집합으로 주어진다.
double area(const vector<vector2>& p) {
	double ret = 0;
	for (int i = 0; i < p.size(); ++i) {
		int j = (i + 1) % p.size();
		ret += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return fabs(ret) / 2.0;
}
//p541: 주어진 점이 단순 다각형 내부에 포함되어 있는지 확인하는 isInside()함수의 구현
//점 q가 다각형 p안에 포함되어 있을 경우 참, 아닌 경우 거짓을 반환한다.
//q가 다각형의 경계위에 있는 경우의 반환값은 정의되어 있지 않다.
"y - y1 = dy/dx * (x - x1) ===> dx/dy * (y - y1) + x1 = x(atX)" : y = q.y이므로 
"dx/dy * (q.y - y1) + x1 = x(atX)가 된다.
bool isInside(vector2 q, const vector<vector2>& p) {
	int crosses = 0;
	for (int i = 0; i < p.size(); ++i) {
		int j = (i + 1) % p.size();
		//(p[i], p[j])가 반직선을 세로로 가로지르는가?
		"if ((p[i].y > q.y) != (p[j].y > q.y))" //여러가지가 함축되어 있는 코드다!!!! 
		if ((p[i].y > q.y) != (p[j].y > q.y)) {	//반직선을 우리 마음속에서만 아주 살짝 올리는 효과
			//점 q에서 가로지르는 반직선(y = q.y)과 크로스된 변의 x좌표를 계산한다.
			//double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;//원소스
			double atX = (p[j].x - p[i].x) / (p[j].y - p[i].y) * (q.y - p[i].y) + p[i].x;//가독성
			if (q.x < atX) //q보다 x축 선상에서 오른쪽에 있냐
				++crosses;
		}
	}
	return crosses % 2 > 0;
}
1. 한점(앞점)이 q.y랑 높이가 같을 때	(p[i].y > q.y)
2. 한점(뒷점)이 q.y랑 높이가 같을 때 
3. 두점이 q.y랑 높이가 같을 때	....난중에 정리: 종이엔 예시 적어놨음


//보물섬(TREASURE, 상)
//p546: 보물섬 문제를 해결하는 다각형 클리핑 알고리즘의 구현
typedef vector<vector2> polygon;
//반평면과 단순 다각형(Simple Polygon)의 교집합을 구한다.
//(a, b)를 포함하는 직선으로 다각형 p를 자른 뒤, (a, b)의 왼쪽에 있는 부분들을 반환한다.
polygon cutPoly(const polygon& p, const vector2& a, const vector2& b) {
	int n = p.size();
	//각 점이 반평면 내에 있는지 여부를 우선 확인한다.
	vector<bool> inside(n);
	for (int i = 0; i < n; ++i)
		inside[i] = ccw(a, b, p[i]) >= 0;	//같으면 포함된다.
	polygon ret;
	//다각형의 각 변을 순회하면서 결과 다각형의 각 점을 발견한다.
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		//반평면 내에 있는 점 p[i]는 항상 결과 다각형에 포함된다.
		if (inside[i]) ret.push_back(p[i]);
		//변 p[i]--p[j] 가 직선과 교차하면 교차점을 결과 다각형에 포함시킨다.
		if (inside[i] != inside[j]) {
			vector2 cross;
			assert(lineIntersection(p[i], p[j], a, b, cross));
			ret.push_back(cross);
		}
	}
	return ret;
}
//서덜랜드-호지맨(Sutherland-Hodgman)알고리즘을 이용한 다각형 클리핑
polygon intersection(const polygon& p, double x1, double y1, double x2, double y2) {
	vector2 a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
	polygon ret = cutPoly(p, a, b);
	ret = cutPoly(ret, b, c);
	ret = cutPoly(ret, c, d);
	ret = cutPoly(ret, d, a);
	return ret;
}
double area(const vector<vector2>& p) { //면적이 0인 케이스도 계산되넹~
	double ret = 0;
	rep(i,p.size()) {
		int j = (i+1) % p.size();
		ret = ret + (p[i].x * p[j].y - p[j].x * p[i].y);
	}
	return fabs(ret) / 2.0
}
polygon readPoly() {
	int n; cin >> n;
	polygon p(n);
	rep(i,n) cin >> p[i].x >> p[i].y;
	return p;
}
int main() {
	int cs;
	cin >> cs;
	while (cs--) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		polygon p = readPoly();
		p = intersection(p, x1, y1, x2, y2);
		printf("%.10lf\n", area(p));
	}
}

//보물섬 전체소스
const double EPSILON = 1e-8;
const double PI = 2.0 * acos(0.0);
struct vt2 {
	double x, y;
	vt2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	bool operator == (const vt2& rhs) const { return x == rhs.x && y == rhs.y; }
	bool operator < (const vt2& rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; }
	vt2 operator + (const vt2& rhs) const { return vt2(x + rhs.x, y + rhs.y); }
	vt2 operator - (const vt2& rhs) const { return vt2(x - rhs.x, y - rhs.y); }
	vt2 operator - () const { return vt2(-x, -y); }
	vt2 operator * (double rhs) const { return vt2(x * rhs, y * rhs); } //스칼라곱
	double norm() const { return hypot(x, y); } //벡터의 크기
	vt2 normalize() const { double n = norm(); return vt2(x / n, y / n); }
	double polar() const { return fmod(atan2(y, x) + 2*PI, 2*PI); }
	double dot(const vt2& rhs) const { return x * rhs.x + y * rhs.y; }
	double cross(const vt2& rhs) const { return x * rhs.y - rhs.x * y; }
	vt2 project(const vt2& rhs) const {	//이 벡터를 rhs(R)에 사영한 결과
		vt2 r = rhs.normalize();	// R/|R|
		return r * r.dot(*this);	// R/|R| * R/|R| dot T
		//R/|R| dot T : T벡터를 R벡터에 사영시켰을 때 벡터의 크기가 된다. 거기에 단위 벡터를 곱하면 사영된 벡터가 되지
	}
};
double ccw(vt2 a, vt2 b) { return a.cross(b); } //원점 기준
double ccw(vt2 p, vt2 a, vt2 b) { return ccw(a - p, b - p); } //p 기준
//lineIntersection: 교점 반환, 두 직선이 평행(겹침 포함) 거짓, 아니면 참을 반환
bool lineInter(vt2 a, vt2 b, vt2 c, vt2 d, vt2& p) {
	double det = (b - a).cross(d - c);
	if (fabs(det) < 0) return false;
	p = a + ((c - a).cross(d - c) / det) * (b - a); //오류 날 것이여
	return true;
}
//parallelSegment: 입력이 평행한 두 선분일 때 이들이 한 점에서 겹치나 확인
bool paraSeg(vt2 a, vt2 b, vt2 c, vt2 d, vt2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);
	if (ccw(a, b, c) != 0 || b < c || d < a) return false; //한직선위 아님 or 두 선분 안겹침
	if (a < c) p = c; else p = a; //겹친게 여러개면 그중 가장 작은 놈을 반환
	return true;
}
//inBoundingRectangle: a, b, p가 일직선 상에 있을때 p가 [a, b] 에 있는지 확인
bool inBR(vt2 p, vt2 a, vt2 b) {
	if (b < a) swap(a, b);
	return p == a || p == b || (a < p && p < b);	//연산자 오버로딩 <=이 없어서~
}
//segmentIntersection: 두 선분의 교점을 p에 반환, 교점이 여러일 경우 아무점이나 반환, 교점이 없으면 false리턴
bool segInter(vt2 a, vt2 b, vt2 c, vt2 d, vt2& p) {
	if (!lineInter(a, b, c, d, p))
		//lineInter 평행인 경우 p는 세팅 안된 쓰레기입
		return paraSeg(a, b, c, d, p); //선이 겹치거나 한점에서 만나면 true고 만난 점 아무거나로 p세팅
	return inBR(p, a, b) && inBR(p, c, d);
}
//segmentIntersects: 교차점이 필요없을때, 두 선분이 서로 접촉여부만 반환
bool segInters(vt2 a, vt2 b, vt2 c, vt2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	//두 선분 한직선 위 or 한 직선 위가 아니더라도 양 끝 점이 겹치는 경우
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);	//!!!!
	}
	return ab <= 0 && cd <= 0;	//한 끝점만 겹치면 ab == 0 && cd < 0 , ab < 0 && cd == 0
}
vt2 ppdclFoot(vt2 p, vt2 a, vt2 b) { return a + (p - a).project(b - a); } //수선의 발: perpendicularFoot
double pointToLine(vt2 p, vt2 a, vt2 b) { return (p - ppdclFoot(p, a, b)).norm(); } //norm 벡터의 길이르 반환
double area(const vector<vt2>& p) {
	double ret = 0;
	rep(i,p.size()) {
		int j = (i + 1) % p.size();
		ret = ret + (p[i].x * p[j].y - p[j].x * p[i].y);
	}
	return fabs(ret) / 2.0;
}
//q가 다각형 경계 위에 있는 경우의 반환값은 정의 안되어 있다: 그 부분은 다른걸로 체크하삼
"y - y1 = dy/dx * (x - x1) ===> dx/dy * (y - y1) + x1 = x(atX)" 
: y = q.y이므로 "dx/dy * (q.y - y1) + x1 = x(atX)가 된다.
//보물섬 소스에선 사용안됨
bool isInside(vt2 q, const vector<vt2>& p) {
	int crosses = 0;
	rep(i,p.size()) {
		int j = (i + 1) % p.size();
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			double atX = (p[j].x-p[i].x)/(p[j].y-p[i].y) * (q.y - p[i].y) + p[i].x;
			if (q.x < atX) ++crosses;
		}
	}
	return crosses % 2 > 0;
}
typedef vector<vt2> polygon;
polygon cutPoly(const polygon& p, const vt2& a, const vt2& b) {
	int n = p.size();
	vb inside(n);
	rep(i,n) inside[i] = ccw(a, b, p[i]) >= 0;
	polygon ret;
	rep(i,n) {
		int j = (i + 1) % n;
		if (inside[i]) ret.pb(p[i]);
		if (inside[i] != inside[j]) {
			vt2 cross;
			assert(lineInter(p[i], p[j], a, b, cross));
			ret.pb(cross);
		}
	}
	return ret;
}
//서덜랜드-호지맨: 다각형 클리핑
polygon intersection(const polygon& p, double x1, double y1, double x2, double y2) {
	vt2 a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
	polygon ret = cutPoly(p, a, b);
	ret = cutPoly(ret, b, c);
	ret = cutPoly(ret, c, d);
	ret = cutPoly(ret, d, a);
	return ret;
}
polygon readPoly() {
	int n;
	cin >> n;
	polygon p(n);
	rep(i,n) cin >> p[i].x >> p[i].y;
	return p;
}
int main() {
	int cs; cin >> cs;
	while (cs--) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		polygon p = readPoly();
		p = intersection(p, x1, y1, x2, y2);
		printf("%.10lf\n", area(p));
	}
}

//너드인가, 너드가 아닌가 NERDS, 중
"2차원 공간 상에 주어진 두 종류의 점들을 구분하는 직선이 존재하는지 여부를 찾는 문제"
"선형 분리(linear separability)문제라고 부릅니다."
F = A * 신발사이즈 + B * 분당 타이핑 속도
A*x + B*y >= T
ex) 1*x -1*y >= 0.5 : A=1, B=-1, T=0.5
//p553: 볼록 껍질을 찾는 선물포장 알고리즘의 구현 (gift wrapping algorithm) O(N^2) 5000개는 충분히 돌림
//더 좋은알고리즘 그라함 스캔(Graham Scan): O(NlgN) 각도로 정렬하고 각 점을 스택을 이용해 판별
typedef vector<vector2> polygon;
//points에 있는 점들을 모두 포함하는 최소의 볼록 다각형을 찾는다.
polygon giftWrap(const vector<vector2>& points) {
	int n = points.size();
	polygon hull;
	//가장 왼쪽 아래 점을 찾는다. 이 점은 껍질에 반드시 포함된다.
	vector2 pivot = *min_element(points.begin(), points.end());
	hull.push_back(pivot);
	while (true) {
		//ph에서 시작하는 벡터가 가장 왼쪽인 점 next를 찾는다.
		//평행인 점이 여러개 있으면 가장 먼 것을 선택한다.
		vector2 ph = hull.back(), next = points[0];
		for (int i = 1; i < n; ++i) {
			double cross = ccw(ph, next, points[i]);
			double dist = (next - ph).norm() - (points[i] - ph).norm();
			if (cross > 0 || (cross == 0 && dist < 0))
				next = points[i];
		}
		//시작점으로 돌아왔으면 종료한다.
		if (next == pivot) break;
		//next를 볼록 껍질에 포함시킨다.
		hull.push_back(next);
	}
	return hull;
}
//p555: 두 볼록 다각형의 교차 여부를 확인하는 polygonIntersects() 함수의 구현
//두 다각형이 서로 닿거나 겹치는지 여부를 반환한다.
//한 점이라도 겹친다면 true를 반환한다.
bool polygonIntersects(const polygon& p, const polygon& q) {
	int n = p.size(), m = q.size();
	//우선 한 다각형이 다른 다각형에 포함되어 있는 경우를 확인하자.
	if (isInside(p[0], q) || isInside(q[0], p)) return true;
	//이 외의 경우, 두 다각형이 서로 겹친다면 서로 닿는 두 변이 반드시 존대한다.
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (segmentIntersects(p[i], p[(i+1) % n], q[j], q[(j+1) % m]))
				return true;	//꼭지점 닿는것도 캐치함
	return false;
}
"인공지능의 역사: 퍼셉트론... 관심있으면 검색해보삼"

"평면 스위핑(plane sweeping): 수평선 혹은 수직선으로 주어진 평면을 '쓸고 지나가면서'문제를 해결
//p558: 직사각형 합집합의 면적을 평면 스위핑 디자인 패턴으로 풀어보자
struct Rectangle { int x1, y1, x2, y2; }; //x1 < x2, y1 < y2
int unionArea(const vector<Rectangle>& rects) {
	if (rects.empty()) return 0;
	// 이벤트 정보: (x 좌표, 왼쪽인가 오른쪽인가, 사각형의 번호)
	typedef pair<int, pair<int, int>> Event;
	vector<Event> events;
	vector<int> ys;
	//각 사각형을 순회하면서 y좌표의 모음과 이벤트의 집합을 찾는다.
	rep(i, rects.size()) {
		ys.pb(rects[i].y1);
		ys.pb(rects[i].y2);
		events.pb(Event(rects[i].x1, mp(1, i)));	//1: 왼쪽
		events.pb(Event(rects[i].x2, mp(-1, i)));	//-1: 오른쪽
	}
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());//y좌표의 집합을 정렬하고 중복을 제거
	sort(events.begin(), events.end());	//이벤트 목록을 정렬
	int ret = 0;
	//count[i] = ys[i] ~ ys[i + 1] 구간에 겹쳐진 사각형의 수
	vector<int> count(ys.size() - 1, 0);
	rep(i,events.size()) {
		int x = events[i].first, delta = events[i].second.first;
		int rectangle = events[i].second.second;
		//count[]를 갱신
		int y1 = rects[rectangle].y1, y2 = rects[rectangle].y2;
		rep(j,ys.size())
			if (y1 <= ys[j] && ys[j] < y2)	//!!!!
				count[j] += delta; //시작하는 거면 존재하니 증가, 끝나는 거면 감소
		//cutLength()값을 계산한다.
		int cutLength = 0;
		rep(j,ys.size()-1) 
			if (count[j] > 0) 
				cutLength += ys[j + 1] - ys[j];	//이야 쥐기네예
		//다음 이벤트까지의 거리에 cutLength를 곱한 값을 ret 에 더한다.
		if (i + 1 < events.size())
			ret += cutLength * (events[i+1].first - x);
	}
	return ret;
}
"위 코드는 event와 ys의 원소의 수는 각각 O(N)이기 때문에, 이 알고리즘의 전체 시간 복잡도는
"O(N^2)가 됩니다. 배열 대신 영리한 자료구조(ex: 펜윅트리)를 이용하면 O(NlgN)을 만들수 있어요

//rectunion.cpp
Rectangle getIntersection(const Rectangle& a, const Rectangle& b) {
	return Rectangle(max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2));
}
bool empty(const Rectange& a) { return a.x1 >= z.x2 || z.y1 >= a.y2; }
int area(const Rectangle& a) { return (a.x2 - a.x1) * (a.y2 - a.y1);
int unionAreaBrute(const vector<Rectangle>& rects, int here, int chosen, 
					const Rectangle& intersection) {
	if (empty(intersection)) return 0;
	if (here == rects.size()) {
		if (chosen == 0) return 0;
		int a = area(intersection);
		return chosen % 2 == 1 ? a : -a;
	}
	int ret = unionAreaBrute(rects, here+1, chosen, intersection);
	ret += unionAreaBrute(rects, here+1, chosen+1,
			getIntersection(intersection, rects[here]));
	return ret;
}
int main() {
	srand(12478);
	int TRIALS = 1000000;
	for (int tt = 0; tt < TRIALS; ++tt) {
		if (tt % 9999 == 0) { printf("."); fflush(stdout); }
		vector<Rectangle> input;
		int n = rand() % 12 + 1;
		for (int i = 0; i < n; ++i) {
			int x1 = rand() % 100;
			int x2 = rand() % 100;
			int y1 = rand() % 100;
			int y2 = rand() % 100;
			if (x1 == x2 || y1 == y2) continue;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			input.push_back(Rectangle(x1, y1, x2, y2));
		}
		assert(unionArea(input) == unionAreaBrute(input, 0, 0, Rectangle(0, 0, 100, 100)));
	}
	printf("\nall pass.\n");
}

//p563: 볼록 다각형의 지름을 재는 회전하는 캘리퍼스 알고리즘
//시계 반대 방향으로 주어진 볼록 다각형에서 가장 먼 꼭지점 쌍 사이의 거리를 반환한다.
double diameter(const polygon& p) {
	int n = p.size();
	//우선 가장 왼쪽에 있는 점과 오른쪽에 있는 점을 찾는다.
	int left = min_element(p.begin(), p.end()) - p.begin();
	int right = max_element(p.begin(), p.end()) - p.begin();
	//p[left]와 p[right]에 각각 수직선을 붙인다. 두 수직선은 서로 정반대 방향을 가리키므로,
	//A의 방향만을 표현하면 된다.
	vt2 calipersA(0, 1);
	double ret = (p[right] - p[left]).norm();
	//toNext[i] => p[i]에서 다음 점까지의 방향을 나타내는 단위 벡터
	vector<vt2> toNext(n);
	rep(i,n)
		toNext[i] = (p[(i+1) % n] - p[i]).normalize();
	//a와 b는 각각 두 선분이 어디에 붙은 채로 회전하고 있는지를 나타낸다.
	int a = left, b = right;
	//반 바퀴 돌아서 두 선분이 서로 위치를 바꿀 때까지 계속한다.
	while (a != right || b != left) {
		//a에서 다음 점까지의 각도와 b에서 다음 점까지의 각도 중 어느 쪽이 작은지 확인
		double cosThetaA = calipersA.dot(toNext[a]);
		double cosThetaB = -calipersA.dot(toNext[b]);
		if (cosThetaA > cosThetaB) {	//cosTheta가 클수록 각은 작다 :thetaA < thetaB
			calipersA = toNext[a];
			a = (a + 1) % n;
		}
		else {
			calipersA = -toNext[b];
			b = (b + 1) % n;
		}
		ret = max(ret, (p[a] - p[b]).norm());
	}
	return ret;
}

http://geomalgorithms.com
/*------------- 정수론 2권 page 13 : 중국인의 나머지 정리 ---------------------------*/





