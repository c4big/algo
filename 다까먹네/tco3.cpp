2D 벡터 그래픽 기술(agg)
3D 그래픽스 (opengl)
3D 그래픽스 (non graphic library 로 플랫폼 독립적인 3D 렌더링 기능 구현)

유전알고리즘으로 조명 재질 상수 도출


https://codeforces.com/contest/1244/problem/C		The Football Season
n, p, w, d // (1 <= n <= 10^12,		0 <= p <= 10^17,	1 <= d < w <= 10^5) 이고
	// n은 경기횟수, p는 벌어들인 포인트, w는 
	// 내소스는 long long 을 오버플로우 해서 틀림.
	// 어떤이는 long double 을 사용해서 gcc에서 통과했으나. 이건 너무 불안함. vs 에서는 확인이 안됨(8바이트라)
x*w + y*d = p	// p를 만들어야 함
x + y + z = n	// 이김 + 비김 + 패배 = 경기수를 만족해야 함.

// python3 확장 유클리드 알고리즘을 통한 자연수 솔루션 찾기
import math
import sys
 
def exgcd(a, b):
    if b == 0:
        return (1, 0)
    else:
        y, x = exgcd(b, a % b)
        y -= x * (a // b)
        return (x, y)
 
 
def ceil(x, y):
    return x // y + (x % y != 0)
 
def output(a, b, n):
    if a < 0 or b < 0:
        return
    if a + b > n:
        return
 
    print(a, b, n - a - b)
    sys.exit(0)
 
def main():
    n, p, w, d = [int(x) for x in input().split(' ')]
    g = math.gcd(w, d)
    if p % g != 0:
        print(-1)
        return
    x, y = exgcd(w, d)
    a = w // g
    b = d // g
    g = p // g
    x *= g
    y *= g
 
    if x < 0:               #x가 0보다 작다면 0이상으로 만든다.
        t = ceil(-x, b)
        x += t * b
        y -= t * a
    elif y < 0:             #y가 0보다 작다면 0이상으로 만든다.
        t = ceil(-y, a)
        x -= t * b
        y += t * a
 
    if x < 0 or y < 0:
        print(-1)
    else:
        #output(x, y, n)
        #output(x % b, y + (x // b) * a, n)  #x를 최소로 하는 경우로 투입
        output(x + (y // a) * b, y % a, n)  #y를 최소로 하는 경우로 투입   w > d 인 조건땜시 x가 많을수록 총합은 작아지는 이점이 있음
        print(-1)
 

if __name__ == '__main__':
    main()		// 이 프로그램이 메인인 경우 구동

#10*x + 6*y = 8

#=> 10과 6의 최대공약수 : 2
#=> 우항은 최대공약수인 2의 배수가 되어야 해가 존재함. (여기선 8이니 존재함)

#g = exgcd(10, 6, x, y) 의 경우 
#10*x + 6*y = gcd(10, 6)
#10*x + 6*y = 2 에 대한 x, y 해가 구해짐 (이는 5*x + 3*y = 1 과 동치인 식이 된다.)

#실제 해는 다음과 같이 구해진다.
#	x = x * (8 / gcd(10, 6))
#	y = y * (8 / gcd(10, 6))

#a. 실제 해들중 x가 음수이면 그놈을 최소한 0이상으로 만들어 준다. y가 감소한다.
#b. 실제 해들중 x가 0이상이고 y가 음수면 y를 최소한 0이상으로 만들어 준다. x가 감소한다.
#c. 둘다 양수면 아무것도 하지 말자.

#1. 두 값의 총합이 경기수를 초과하지 않으면 닶이 된다. : 여기선 문제 조건상 필요가 없다. w > d 이므로 3번 케이스만 취해도 된다.
#2. x를 최소화 하여 답을 정하자. 총합이 경기수를 초과 하지 않으면 답이 된다. : 여기선 문제 조건상 필요가 없다. w > d 이므로
#3. y를 최소화 하여 답을 정하자. 총합이 경기수를 초과 하지 않으면 답이 된다. 

또다른 방식으로 푼거. 아마 저자는 이 방식을 의도했으리라 본다.
https://codeforces.com/contest/1244/submission/62473970
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    for(long long i=0;i<=c;i++)
    {
        if((b-i*d)%c)continue;
        long long j = (b-i*d)/c;
		long long q = a-i-j;
        if(j<0 || q<0)continue;
        printf("%lld %lld %lld\n",j,i,q);
        return 0;
    }
    puts("-1");
    return 0;
}
x*12 + y*10 = 2*1000;	// gcd(12, 10) * 1000
y값이 12 이하에서 결정난다. 

좀더 좋은 예제로 설명하자면 
7*12 + 13*10 = 84 + 130 = 214
(7*12 + 10*12) + 1*10 = 204 + 10 = 214	// 12 를 초과하면 12의 배수 부분은 앞쪽에 맞추어 넣을수 있다는 것을 기억하라.
// 소스가 답이 되는 이유는 win의 점수가 draw 점수보다 높기 때문이다.





// straight skeleton algorithm
https://en.wikipedia.org/wiki/Straight_skeleton
In geometry, a straight skeleton is a method of representing a polygon by a topological skeleton.
기하학으로, 스트레이트 스켈레톤은 위상 스켈레톤으로 다각형을 나타내는 방법입니다.

It is similar in some ways to the medial axis but differs in that the skeleton is composed of straight line segments, 
while the medial axis of a polygon may involve parabolic curves.
중앙 축 방식과 유사해 보이지만, 스트레이트 스켈레톤은 뼈대들이 선들로 구성된다. (반변에 중앙 축의 경우 폴리곤은 파라볼릭 커브랑 연관됨)
	참고 "중앙 축 변환 [medial-axis transform]" : 주어진 영상에서 물체의 가장자리부터 동일한 자리에 있는 점들의 집합을 구하는 것

However, both are homotopy-equivalent to the underlying polygon.
그렇지만, 두가지 방식은 모두 베이스가 되는 폴리곤과 동형이다.

Straight skeletons were first defined for simple polygons by Aichholzer et al. (1995),
and generalized to planar straight-line graphs (PSLG) by Aichholzer & Aurenhammer (1996).
1995년에 정의되고 1996년에 planar straight-line graphs(PLSG) 로 일반화 됨

In their interpretation as projection of roof surfaces, they are already extensively discussed by G. A. Peschka (1877).
k01877년에 지붕 표면의 투영으로 해석하고자 이미 Peschka 에 의해 광범위하게 논의 되었다.

"1. Definition"



// ******************** 아펙티브 c++ ********************** //

"3장 낌해만 보이면 const를 들이대 보자"
class TextBlock {
public:
	TextBlock(const string& str) {
		text = str;
	}
	
	// 앞 const, 뒤 const 둘 중 하나라도 없으면 빌드 안됨 : 
	// 앞의 const 를 없애면 return: const char 에서 char& 형으로 변환이 안되기 때문(string 특징)
	// 뒤에 const 를 없애면 비상수 객체에서만 호출되므로 밑에 버전과 모호성 발생
	const char& operator[] (size_t position) const {	// 뒤의 const 덕에 상수객체에서 호출됨
		return text[position];
	}
	
	char& operator[](std::size_t position) {	// 뒤에 const 가 없으니 비상수 객체에서 호출됨
		return text[position];
	}
private:
	string text;
};
void main() {
	TextBlock tb("Hello");
	cout << tb[0];

	const TextBlock ctb("World");
	cout << ctb[0];			// const char& operator[] (size_t position) const; 호출됨
	return;
}


// 상수성이 보장이 안되지만 느슨하게 넘어가자고 설득하는 예제
class TextBlock {
public:
	TextBlock(const string& str) {
		pText = new char[str.size() + 1];
		for (int i = 0; i < str.size(); ++i) {
			pText[i] = str[i];
		}
		pText[str.size()] = NULL;
	}
	char& operator[](size_t position) const {	// 내부가 바뀌면 안되는 const 멤버 함수이지만
		return pText[position];	// 이래서는 바깥에서 내부가 바뀔수 있다.
	}

private:
	char* pText;
};
void main() {
	TextBlock tb("Hello");
	cout << tb[0];	// const 형이 아니지만 const 로 인식하여 [] const 가 호출됨

	const TextBlock ctb("World");
	cout << ctb[0];

	char* pc = &ctb[0];
	pc[0] = '!';
	cout << ctb[0];	// 내부가 바뀜을 확인할수 있다.
	return;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
class CTB {
public:
	CTB(const string str) {
		pText = new char[str.size() + 1];
		for (int i = 0; i < str.size(); ++i) pText[i] = str[i];
		pText[str.size()] = NULL;
		lengthIsValid = false;
	}
	size_t length() const;
	int tmp;
	mutable int tmp2;
private:
	char* pText;
	mutable size_t textLength;
	mutable bool lengthIsValid;
};
size_t CTB::length() const {	// 상수멤버 안에서도 수정이 가능함을 확인할수 있다.
	//tmp = 3; 요놈은 에러남
	if (!lengthIsValid) {
		textLength = strlen(pText);
		lengthIsValid = true;
	}
	return textLength;
}

void main() {
	const CTB ctb("Hello");
	int len = ctb.length();		// 5로 세팅됨(내부 멤버변수들 바뀜)
	//ctb.tmp = 3;		// 빌드 에러(const 객체라서임)
	ctb.tmp2 = 5;		// 잘됨
	return;
}






// 잡다
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
class CG {
public:
	CG() : m_num(1) {}
	CG& operator = (const CG& cg) {
		m_num = cg.m_num;
		return *this;
	}
	int m_num;
};

class CP : public CG
{
public:
	CP() : m_num2(2) {}
	CP& operator = (const CP& cp) {
		*(CG*)this = cp;		// a)
		//CG::operator = (cp);		// b)cp 를 괄호 쒸워야 빌드가 된다. !!!!!!!!
		// a) b) 방식 둘다 같은 결과를 가진다.
		
		m_num2 = cp.m_num2;
		return *this;
	}
	int m_num2;
};
void main() {
	CP cg, cg2;
	cg2.m_num = 10;
	cg2.m_num2 = 20;
	cg = cg2;
	return;
}

// 디버그 -> 창 -> 디스어셈블리
	CP& operator = (const CP& cp) {
00F822F0  push        ebp  
00F822F1  mov         ebp,esp  
00F822F3  sub         esp,0CCh  
00F822F9  push        ebx  
00F822FA  push        esi  
00F822FB  push        edi  
00F822FC  push        ecx  
00F822FD  lea         edi,[ebp-0CCh]  
00F82303  mov         ecx,33h  
00F82308  mov         eax,0CCCCCCCCh  
00F8230D  rep stos    dword ptr es:[edi]  
00F8230F  pop         ecx  
00F82310  mov         dword ptr [this],ecx  
00F82313  mov         ecx,offset _AB9D3638_Main@cpp (0F94025h)  
00F82318  call        @__CheckForDebuggerJustMyCode@4 (0F813ACh)  
		*(CG*)this = cp;
00F8231D  mov         eax,dword ptr [cp]  
00F82320  push        eax  
00F82321  mov         ecx,dword ptr [this]  
00F82324  call        CG::operator= (0F81668h)  
		CG::operator = (cp);		//cp 를 괄호 쒸워야 빌드가 된다. !!!!!!!!
00F82329  mov         eax,dword ptr [cp]  
00F8232C  push        eax  
00F8232D  mov         ecx,dword ptr [this]  
00F82330  call        CG::operator= (0F81668h)  
		m_num2 = cp.m_num2;
00F82335  mov         eax,dword ptr [this]  
00F82338  mov         ecx,dword ptr [cp]  
00F8233B  mov         edx,dword ptr [ecx+4]  
00F8233E  mov         dword ptr [eax+4],edx  
		return *this;
00F82341  mov         eax,dword ptr [this]  
	}

*(CG*)this = cp; 랑 CG::operator = (cp);  가 같은 어셈블리어로 됨을 확인할수 있다.

class CPerson {
public:
	char* m_Name;
};

class CVSPerson {
public:
	char m_Name[1];
};
void main() {
	//CPerson* pPerson = new CPerson;
	//pPerson->m_Name = "Kim Dong Hyun";

	char name[] = "Choi Sung Jun";
	CVSPerson* pVSPerson = (CVSPerson*)malloc(sizeof(CVSPerson) + strlen(name));
	//pVSPerson->m_Name[0] = NULL;
	//strcat_s(pVSPerson->m_Name, name);
	std::cout << strlen(name) << std::endl;			// 13
	std::cout << sizeof(*pVSPerson) << std::endl;	// 1
	return;
}


"복사생성자 호출 시점"
1. 기존에 생성된 객체를 이용해 새로운 객첵를 초기화 하는 경우
2. call-by-value 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우
3. 객체를 반환하되, 참조형으로 반환하지 않는 경우
// 객체 return 시 임시로 객체가 만들어지며 복사생성자가 호출된다. 
// 받는 곳이 존재하면 그놈으로 바로 대입된다.(주소가 같다.)
class Test {
public:
	Test() {
		m_num1 = 3;
	}
	Test(int num) : m_num1(num) {}
	Test(const Test& rhs) {
		m_num1 = rhs.m_num1;
	}
	~Test() {
		m_num1 = -1;
	}
	int m_num1;
};
Test myFunc(Test para) {
	Test ret(10);
	return ret;		// 1) 무조건 임시 객체를 만든다(이때 복사생성자는 ret(10이 들어간 거) 를 인자로 해서 임시 객체 생성함)
					//		만들어진 임시 객체의 주소는 b와 동일하다. 우와 최적화 잘되어 있네
					// 2) ret 의 소멸자가 호출됨
					// 3) para 의 소멸자가 호출됨
}
void main() {
	Test a(3);
	//myFunc(a);	// 아래와 결과가 똑같음. myFunc 에서 ret 를 받기 위해 임시 객체 만들어진다.
	Test b = myFunc(a); // b에서 복사생성자가 호출되지 않는다. 이미 myFunc 에서 호출됨.
	return;
}









//============git==================//
https://backlog.com/git-tutorial/kr/stepup/stepup1_2.html

//------------------- 캐글 ---------------------//

https://www.kaggle.com/c4big2/kernel5049339d03/edit
// 다시 정리

# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load in 

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory

import os
print(os.listdir("../input"))

# Any results you write to the current directory are saved as output.


df_train = pd.read_csv("../input/train.csv")
df_test = pd.read_csv("../input/test.csv")
print(df_train.shape)
print(df_test.shape)


import seaborn as sns
import matplotlib.pyplot as plt
corr = df_train.corr()
plt.subplots(figsize = (15, 10))
sns.heatmap(corr, annot=True, fmt=".3f")
plt.show()


df_train.columns


df_test.columns


sel = ['sqft_living', 'sqft_lot', 'bedrooms', 'bathrooms']
sel


train_problem = df_train[sel]
solution = df_train['price']
real_problem = df_test[sel]
print(train_problem.shape)
print(solution.shape)
print(real_problem.shape)


from sklearn import linear_model
from sklearn.metrics import mean_squared_error
#모델 만들기
model = linear_model.LinearRegression()
model


model.fit(train_problem, solution)


real_sol = model.predict(real_problem)
real_sol


sub = pd.read_csv("../input/sample_submission.csv")
print(sub.columns, sub.shape)
sub.head()


sub['price'] = real_sol
sub.to_csv("mySolution.csv", index=False)


model.intercept_


model.coef_

----------------------------------------------------





백준 acmicpc 문제, 2018이후 쿤제풀이들
// 참고
const ll INF = 1e18; // 정상세팅된다!!!!!!!!


//-------------------------- dp ------------------------------//
https://www.acmicpc.net/problem/16157

구현 문제로 접근했다.
	연속된 값은 하나로 만든다.
		ex) RRGGBBRRGG -> RGBRG
	그 중 가장 많은 문자를 선택한다.
		RGBRG -> // R을 선택해 밑바닥에 뿌임
		GB, G 가 남는다 : 이거 처리하는데 3걸림
	총 걸리는것은
		1 + 3 = 4가 된다.
	
반례가 있다.
	R	G	B	G	R	B	G	B
	R: 2
	G: 3
	B: 3
B를 맨 밑바닥에 그리는 것으로 선택시
	RG, GR, G 가 남고 이거 처리하는데 5가 걸림
	총 6이 됨
허나 R을 맨 밑바닥에 그리는 경우로 선택시
	GBG, BGB 가 남고 이거 처리하는데 4가 걸림
	총 5가 걸리게 된다.
	
따라서 위 접근법은 잘못 된 것이다. ㅠㅠ
풀이 사이트:
https://blog.naver.com/rdd573/221360255332




https://www.acmicpc.net/problem/2698
인접한 비트의 갯수로 점수가 결정됨
n이 5이고, k가 2이면, 수열 S가 될 수 있는 수열은 다음과 같이 6가지가 있다.
// 2점이 되는 케이스
11100, 01110, 00111, 10111, 11101, 11011

// dp[tot][cnt][1] : 1~tot 까지 진행함, cnt 현점수, 1  마지막 숫자
// dp[tot][cnt][0] : 1~tot 까지 진행함, cnt 현점수, 0  마지막숫자
// 점화식
// dp[tot][cnt][1]	=	dp[tot - 1][cnt][0] 
//					+	dp[tot - 1][cnt - 1][1]
// dp[tot][cnt][0]	=	dp[tot - 1][cnt][0] + dp[tot - 1][cnt][1]
unsigned int dp[105][105][2];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		dp[1][0][1] = 1;
		dp[1][0][0] = 1;
		int n, k; 
		cin >> n >> k;
		for (int i = 2; i <= n; ++i)
			for (int j = 0; j <= k; ++j) {
				dp[i][j][1] = dp[i - 1][j][0] + (j > 0 ? dp[i - 1][j - 1][1] : 0);
				dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			}
		cout << dp[n][k][1] + dp[n][k][0] << '\n';
	}
	return 0;
}


http://jaimemin.tistory.com/618 타일링 문제에서 숫자가 매우 큰 케이스 정리
ex) 큰숫자 합하기 코드
const int MAX = 251;
int N;
string cache[MAX];
//long long 자료형으로도 커버 안되는 숫자는 string으로 직접 구현해줘야한다
string bigNumAdd(string num1, string num2) {
	long long sum = 0;
	string result;
	//1의 자리부터 더하기 시작한다
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		//다시 string 형태로 만들어 push_back
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	//1의 자리부터 result에 넣었으므로 뒤집어줘야한다
	reverse(result.begin(), result.end());
	return result;
}
// dp[i] = dp[i - 2] * 2 + dp[i]
int main(void) {
	//아무것도 안하는 것도 하나의 방법, 밑변이 1인 사각형(1*2) 한 가지
	cache[0] = cache[1] = '1';
	//밑변이 2인 사각형(2*2, 2*1) 두 가지, 밑변이 1인 사각형(1*2) 한 가지
	for (int i = 2; i <= 250; i++)
		cache[i] = bigNumAdd(bigNumAdd(cache[i - 2], cache[i - 2]), cache[i - 1]);
	while (~scanf("%d", &N)) {		// eof end of file 입력을 알아내는 법 scanf
									// ~x : all bits in x flipped 반전연산자
		cout << cache[N] << endl;
	}
	return 0;
}
// scanf 로 끝까지 입력 받는 법
1. while (scanf("%d", &n) != EOF)	// EOF 는 -1을 나타냄 결국 아래와 같다.
2. while (scanf("%d", &n) != -1)	
3. while (~scanf("%d", &n))
	


https://www.acmicpc.net/problem/11049 : 행렬 곱셈 순서 : 행렬의 곱셈에서 실제로 곱하는 횟수를 줄이도록 순서를 변경
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// 정답은 2^31-1 보다 작거나 같은수이며, 최악의 순서로 연산해도 이것 이하다.
const int INF = (1 << 31) - 1;		// int 형으로 아슬아슬하게 나타낼수 있다.
int dp[505][505];
int cnt[505];	// 행렬갯수가 2개인 경우 0, 1, 2 에 세팅됨
int rec(int lgt, int rgt) {
	if (lgt == rgt) return 0;
	int& ret = dp[lgt][rgt];
	if (ret != -1) return ret;
	ret = INF;
	for (int k = lgt; k + 1 <= rgt; ++k) {
		//dp[lgt][k] + dp[k + 1][rgt] + cnt[lgt] * cnt[k + 1] * cnt[rgt + 1];
		// cnt[lgt] : 왼쪽행렬의 행
		// cnt[k + 1] : 왼쪽행렬의 열 이자 오른쪽 행렬의 행
		// cnt[rgt + 1] : 오른쪽 행렬의 열
		int cand = 0;
		cand += rec(lgt, k);
		cand += rec(k + 1, rgt);
		cand += (cnt[lgt] * cnt[k + 1] * cnt[rgt + 1]);
		if (ret > cand)
			ret = cand;
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cnt[i];
		cin >> cnt[i + 1];
	}
	int sol = rec(0, n - 1);
	cout << sol;
	return 0;
}

// input
3
5 3
3 2
2 6

// output
90


https://www.acmicpc.net/problem/11066 : 파일 합치기 : 존내 간단한 문젠데 난 왜 고민했을까?? ㅠ
//input
2
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
//output
300
864

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int INF = 987654321;
vector<int> arr;
vector<int> psum;
int dp[505][505];
int rec(int lgt, int rgt) {
	if (lgt == rgt) return 0;
	int& ret = dp[lgt][rgt];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = lgt; i + 1 <= rgt; ++i) {
		int cand = 0;
		cand += rec(lgt, i);
		cand += rec(i + 1, rgt);
		cand += psum[i] - (lgt == 0 ? 0 : psum[lgt - 1]);
		cand += psum[rgt] - (psum[i]);
		if (ret > cand)
			ret = cand;
	}
	return ret;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		arr.resize(n);
		psum.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			psum[i] = (i == 0 ? 0 : psum[i - 1]) + arr[i];
		}
		memset(dp, -1, sizeof(dp));
		int sol = rec(0, n - 1);
		cout << sol << '\n';
	}
	return 0;
}


 

//---------------------- 이분법 -------------------------------//
제자리 멀리뛰기
https://www.acmicpc.net/problem/6209

최소거리 후보를 정하고
그걸로 바이너리 서치를 돌리고
판단함수는 최소거리 후보로 건널때 m 개의 작은 섬이 제거되는지 판단한다.
최소거리의 최대화를 위해 해야 할 짓!!!!
a라는 후보거리로 건널때 m + x 개의 작은 섬이 생략된다면 true // 왜냐면 x개의 섬들은 a 보다 더 크게 이동하면 m개로 맞출수 있기 때문이다.

b라는 후보거리로 건널때 m - x 개의 작은 섬이 생략된다면 fail // b 는 후보거리 실패가 된다.

// 최소값의 최대화 문제 : 구간의 균등화가 목적 : 균등분배문제
"!! 작은 건 무조건 참이라 가정하에 푼다." : 최대값을 구하라는 문제이므로


최소거리는 0부터 가능함이 키워드임

최소거리를 0	으로 둘 때 : 가능
최소거리를 1	으로 둘 때 : 가능
최소거리를 2	으로 둘 때 : 가능
최소거리를 3	으로 둘 때 : 가능
...
최소거리를 sol	으로 둘 때 : 가능
최소거리를 sol+1 로  둘 때 : 불가능
최소거리를 sol+1 로  둘 때 : 불가능
...
최소거리를 mx 로 둘때	  : 불가능
vector<int> arr;
// judge 함수의 의미 mid값 "이상" 값들로 참을 만족 시킬수 있는가다.(m이하의 점프를 하면서)
// mid 값으로 참을 만족 시킬수 있는가가 아니다. !!!!! 오호호호호
bool judge(int mid, int m) {
	int begin = arr[0];
	int cnt = 0;
	for (int i = 1; i < arr.size(); ++i) {
		int diff = arr[i] - begin;
		if (diff >= mid)
			begin = arr[i];
		else
			cnt++;	// 제거된 섬갯수
	}
	if (cnt <= m) // 제거된 섬갯수가 3이고 m이 5이면 아무섬이나 더 지우면 되므로 참 
		return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int d, n, m;
	cin >> d >> n >> m;
	arr.resize(n + 2);
	arr[0] = 0;
	arr[arr.size() - 1] = d;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int lo = 0;	// 무조건 성립
	int hi = 1000000007;	// 무조건 불성립
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (judge(mid, m))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo;
	return 0;
}


//----------------------- 구간트리 ---------------------------//




//------------------------ dsu -------------------------------//



//------------------------ 네트워크 유량 --------------------//



//---------------- 기하 (geometry algorithm) ------------------//
http://codeforces.com/contest/1096/problem/C  :  Polygon for the Angle

어떤 정N 폴리곤에 꼭지점으로 이루어진 각이 x degree 라고 할 때
x degree를 나타내는 가장 작은 정점으로 이루어진 정다각형의 정점을 구하라

xdegree = 1 ~ 179 사이의 정수이다.

// 답은 많아도 1000각형을 넘지는 않는다. 이건 내소스 돌려보고 판단한거다.

정다각형의 내각 : 180 * (n - 2) / n			, 최소표현각 : 180*(n-2) / (n*(n-2))
ex: 3각형 	=> 180 * (3 - 2) / 3 = 60		, 180 / 3 = 60
ex: 4각형 	=> 180 * (4 - 2) / 4 = 90		, 180 / 4 = 45
ex: 10각형 	=> 180 * (10 - 2) / 10 = 144	, 180 / 10 = 18

// 튜토리얼이 좋은 그림을 제공한다. : 원점 포함한 각도(360도에 대한 문제도 생각해보자)
https://codeforces.com/blog/entry/64156

뭐 나는 풀이대로의 머리를 굴리지 못하겠다.
쨉실하게 푸는 방법 : 정수인지 아닌지를 체크하는 부분을 잘 봐라 !!!!!!!!!!!
const double eps = 1e-10;
bool judge(double num) {	// 정수여부 판단
	double tmp = num - ll(num);
	if (tmp < 0) tmp *= -1;
	if (tmp < eps)
		return true;
	return false;
}
int main() {
	map<ll, int> my;
	for (int i = 3; i <= 1000; ++i) {
		double t = (double)180 / i;
		double key = 0;
		for (int j = 1; j <= (i - 2); ++j) {
			k += t;
			long long key2;
			if (judge(key) == true)
				key2 = ll(key + eps);
			else
				continue;
			if (my.count(key2) > 0) continue;
			my[key2] = i;
		}
		if (my.size() == 179) break; // 1~179 각도
	}
	int T; cin >> T;
	while (T--) {
		ll k;
		cin >> k;
		cout << my[k] << '\n';
	}
}
//----------------------stack---------------------------//

http://hsin.hr/coci/archive/2010_2011/contest1_tasks.pdf


백준이는 한 작은 회사에 취직했다. 이 회사에서 백준이는 소스 코드의 뒤죽박죽인 인덴트를 고치고 있다.
인덴트는 각 줄을 탭 키를 이용해 들여 쓰는 것을 말한다.
다행히 백준이가 사용하는 편집기는 연속된 줄을 그룹으로 선택하고, 
여기에서 각 줄의 앞에 탭을 추가하거나, 삭제할 수 있다.

백준이를 도와 코드의 뒤죽박죽인 인덴트를 예쁘게 고치는 방법을 생각해보자.
줄의 개수 N과 각 줄의 앞에 있는 탭의 개수와 올바른 탭의 개수가 주어진다.
이때, 한 번 편집을 할 때, 다음과 같은 명령을 수행할 수 있다.

연속된 줄을 그룹으로 선택한다.
선택된 줄의 앞에 탭 1개를 추가하거나 삭제한다.
위의 두 명령은 각각 선택된 줄의 개수와 상관없이 한 번의 편집이다.
만약, 선택한 줄 중에 단 한 줄이라도 탭이 없을 경우에는, 탭을 삭제하는 명령을 수행할 수 없다.
백준이가 몇 번 편집 만에 코드의 인덴트를 올바르게 고칠 수 있는지 구하는 프로그램을 작성하시오. 
이때, 편집 회수의 최솟값을 구해야 한다.
N <= 1000
각 숫자는 0이상 80 이하
입력
4
5 4 5 5
1 5 0 1
출력: 10


입력
4
1 2 3 4
3 1 1 0
출력: 6

			O					
		O	O					O
	O	O	O		----->		O
O	O	O	O					O	O	O	_

내 방식
탭을 추가하는 경우 +, 그렇지 않은 경우 -
+2	-1	-2	-4

1. 부호가 바뀌기 전 최대 높이: 탭횟수

2. 절대값이 가장 높았다가 내려가는 순간만큼이 탭횟수


10	0	10	10
3	7	3	3
모든칸을 7칸 마이너스 하고 두번째칸을 +14 하면 총 비용은 21

헌데 두번째 칸이 음수가 되면 안된다 아이가.. 하지만 그래도 "정답"과 같다.

정답은
10을 3으로 바꾸고 -> 7 비용
0을 7로 바꾸고	-> 7비용
남은 10, 10 을 둘달 3, 3 으로 바꾼다 -> 7비용

"차이를 구하고 그 차이를 0으로 변경시키는 문제가 된다."

내코드요 ㅠㅠ: 지저분하고 괴로웠다... 많이 틀리기도 하고
int localSol(vector<int> arr) {
	stack<int> st;
	int ret = 0;
	for (int i = 0; i < arr.size(); ++i) {
		// 스택보다 높게 쌓인건 용서못해~
		if (st.empty() == false && st.top() >= arr[i]) {
			int height = st.top();
			st.pop();
			ret += height - arr[i];
		}
		while (st.empty() == false && st.top() >= arr[i])
			st.pop();
		st.push(arr[i]);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n), brr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) cin >> brr[i];
	vector<int> trr(n);
	for (int i = 0; i < n; ++i) trr[i] = brr[i] - arr[i];	// 차이를 구한다.
	
	vector<int> crr, drr;
	for (int i = 0; i < trr.size(); ++i) {
		if (trr[i] > 0)			// 양수만 저장한다.
			crr.push_back(trr[i]);
		else if (crr.size() != 0 && crr.back() != 0)	// 양수가 아닌 경우 seg끝에만 0을 붙임
			crr.push_back(0);
		if (i == trr.size() - 1 && crr.size() && crr.back() != 0)
			crr.push)back(0);		// 맨마지막 원소면 seg끝에 0을 붙임
	}
	
	for (int i = 0; i < trr.size(); ++i) {
		if (trr[i] < 0)
			drr.push_back(trr[i] * -1);
		else if (drr.size() != 0 && drr.back() != 0)
			drr.push_back(0);
		if (i == trr.size() - 1 && drr.size() && drr.back() != 0)
			drr.push_back(0);
	}
	int add1 = localSol(crr);
	int add2 = localSol(drr);
	int sol = add1 + add2;
	cout << sol;
}

// 잘생각해봐라 모든 차이를 0으로 변환하는 문제다.
0	0	0	-4	1	-5	-4	0	0	0


만약 하나의 툭 튀어난 놈이 있다면

0	0	0	-7	0	0	0	0	
===> 너비가 0에 무한이 가까운 줄의 경우 감싸는데 총 7 * 2 의 비용이 든다.


입력
4
5 4 5 5
1 5 0 1
출력: 10

0	-4	1	-5	-4	0	의 경우 감싸는데 드는 총 줄의 길이는
====> 4 + 5 + 6 + 1 + 4 = 20 이다. 

길이 / 2 가 답이 된다. 즉 감싸는 높이 비용 / 2가 답이된다.
0	5	3	5	0 =>	5 + 2 + 2 + 5 = 14  ==> 비용은 7이 된다.


도도이야가 푼거(from dotorya) https://www.acmicpc.net/source/579775
#include <stdio.h>
#include <math.h>
using namespace std;
int in[1050];
int abs(int x) { return (x > 0) ? x : (-x);
int main() {
	int N, i, t;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &t);
		in[i] += t;
	}
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &t);
		in[i] -= t;
	}
	int ANS = 0;
	for (int i = 0; i <= N; ++i) ANS += abs(in[i + 1] - in[i]);
	printf("%d", ANS / 2);
	return 0;
}

//----------------------그래프 graph ------------------------//






//----------------------- etc 수학, 정수론 -------------------------------//
perfect number https://zetawiki.com/wiki/%EC%99%84%EC%A0%84%EC%88%98
"완전수"
자신을 제외한 양의 약수의 합으로 나타낼 수 있는 수
자신을 제외한 양의 약수의 합으로 표현되는 양의 정수
자기 자신을 제외한 양의 약수를 더했을 때 자기 자신이 되는 양의 정수
알려진 완전수는 모두 삼각수임
(레온하르트 오일러) 모든 짝수 완전수는 2^(n-1) * (2^n - 1) 형태임
짝수 완전수와 메르센 소수는 일대일 대응임
홀수 완전수가 존재하는지는 확인되지 않음	: 현재까진 없더라..

레온하르트 공식에 따라
n=1	: 1 => 짝수 완전수가 아님
n=2 : 6 => 짝수 완전수
n=3	: 4*7 = 28 => 짝수 완전수
n=4	: 8*15 = 90 => 짝수 완전수

https://www.acmicpc.net/problem/9506 : 약수들의 합, 완전수 문제 : 직접 노가다 가능하더라
약수 구하기: 복잡도 sqrt(N); 소수를 찾는 factor 함수랑은 다르네
vector<int> measure(int n) {
	vector<int> ret;
	int sqrtn = int(sqrt(n));
	for (int div = 1; div <= sqrtn; ++div)
		if (n % div == 0) {
			ret.push_back(div);
			if (div * div != n)
				ret.push_back(n / div);
		}
	sort(ret.begin(), ret.end());
	return ret;
}


https://www.acmicpc.net/problem/1963 : 쉬워서 뭐.. 생략.. 소수분포갯수는 가우스의 소수 정리 참고
@@@@@@@@소수의 갯수!!!!!!!!
1	10	4	 
2	100	25	 
3	1,000	168	 
4	10,000	1,229	 
5	100,000	9,592	 
6	1,000,000	78,498	 
7	10,000,000	664,579	 
8	100,000,000	5,761,455	

vector<int> makeNextFrime(int base) {	// 최대 40개의 인접 소수를 구한다.
	
}
bfs 돌면서 찾아낸다. : 코드 생략요.



좋은문제다
https://www.acmicpc.net/problem/1038  [BOJ] 1038번: 감소하는 수
숫자 n 이 주어지고 n번째 감소하는 수를 출력한다.
답이 없는 경우 -1 을 출력한다.

ex) 0 -> 0 , 1->1, 2->2, 9->9, 10->10, 11->20, 12->21
// 풀이
https://blog.encrypted.gg/142


집합 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} 에서 공집합이 아닌 임의의 부분집합으로
감소하는 수를 만들수 있기에 이때 경우의 수는 2^10 - 1 이 된다.

// 참고로 조합의 합은 다음과 같다.
10C0 + 10C1 + 10C2 + 10C3 + ... + 10C9 + 10C10 = 2^10
// 직관적으로 생각해봐라 00 0000 0000 총 10칸에서 1로 세팅하냐 0으로 세팅하냐의 
// 경우의 수랑 같다.!!!!!!!!
결론은 문제의 경우 경우의 수가 1023 개 밖에 없으므로 미리 1023개의 수를 구한다음
정렬하고 n 에 대응하는 숫자를 출력하도록 하였다.

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	vector<long long> decimal;
	for (int i = 1; i < (1 << 10); ++i) {
		long long num = 0;
		for (int idx = 9; idx >= 0; --idx) {// 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 숫자중 선택
											// (1<<0) 인 경우 1임 즉 0을 나타내게 됨
											// (1<<1) 인 경우 2임 즉 1을 나타내게 됨
			if (i & (1 << idx))
				num = 10 * num + idx; // 좋네요		
			
		}
		// num 이 10 인 경우 00 0000 0011 이 된다.
		decimal.push_back(num);
	}
	sort(decimal.begin(), decimal.end());
	int n;
	cin >> n;
	if (n >= 1023) // 0이 시작임 1023개 있으므로 마지막 가능 인덱스는 1022임
		cout << -1; 
	else
		cout << decimal[n];
	return 0;
}


https://www.acmicpc.net/source/8690912 : // 내가 짰는데 기억이 안나 ㅠㅠㅠㅠ
vi graph[1005], prnt[1005], sorted;
vb vstd;
vi cost;
vi sumCost;
void dfs(int here) {
	vstd[here] = true;
	for (int i = 0; i < graph[here].size(); ++i) {
		int there = graph[here][i];
		if (vstd[there] == false)
			dfs(there);
	}
	sorted.push_back(here);
}
int main() {
	int cs; cin >> cs;
	rep(cc,cs) {
		rep(i, 1005) graph[i].clear();
		rep(i, 1005) prnt[i].clear();
		cin >> V >> E;
		cost.clear(), sumCost.cloear(), vstd.clear();
		cost.resize(V);	sumCost.resize(V), vstd.resize(V);
		for (int i = 0; i < V; ++i) cin >> cost[i];
		for (int i = 0; i < E; ++i) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
			prnt[b].push_back(a);
		}
		for (int i = 0; i < V; ++i) if (vstd[i] == false) dfs(i);
		reverse(sorted.begin(), sorted.end());
		for (int i = 0; i < sorted.size(); ++i) {
			int here = sorted[i];
			int add = 0;
			// 자신의 부모중 가장 많이 걸리는 놈을 찾는다.
			for (int i = 0; i < prnt[here].size(); ++i) {
				int pp = prnt[here][i];
				int cand = sumCost[pp];
				add = max(add, cand);
			}
			sumCost[here] = add + cost[here];
		}
		int dst;
		cin >> dst;
		dst--;
		cout << sumCost[dst] << '\n';
	}
	return 0;
}


https://www.acmicpc.net/problem/1766
// 종만 방식의 위상정렬로는 해결이 안되는 문제임.
// 위상정렬문제인데 dfs 재귀스택을 이용한 위상정렬로는 구할 수가 없는 문제다

vector<int> graph[33333];
vector<int> sorted;
vector<bool> vstd;
void dfs(int here) {
	vstd[here] = true;
	for (int i = graph[here].size() - 1; i >= 0; --i) { // 이래도 안됨
	//for (int i = 0; i < graph[here].size(); ++i) {	// 이럼 안되죠
		int there = graph[here][i];
		if (vstd[there] == true) continue;
		dfs(there);
	}
	sorted.push_back(here);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
	}
	for (int i = 0; i < N; ++i)
		sort(graph[i].begin(), graph[i].end());
	vstd = vector<bool>(N, false);
	for (int i = N - 1; i >= 0; --i) {
		if (vstd[i] == true) continue;
		dfs(i);
	}
	reverse(sorted.begin(), sorted.end());
	for (int i = 0; i < sorted.size(); ++i) {
		cout << sorted[i] + 1 << " ";
	}
	return 0;
}

반례:
4 3
4 1
1 3
4 2
ouput
4 1 3 2 : // 정답 4 1 2 3 이 되어야 한다.

// 스택을 안쓰고 위상정렬을 구하는 방식으로 접근해야 한다.
http://joonas-yoon.blogspot.com/2016/05/1766.html
// O(v^2) 복잡도임
int V, E;
vector<int> graph[32010];
vector<int> indegree;
vector<int> topological() {
	vector<int> ret;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < V; ++i)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int here = q.top();
		q.pop();
		ret.push_back(here);	// 방문
		for (int i = 0; i < graph[here].size(); ++i) {
			int there = graph[here][i];
			indegree[there] -= 1;
			if (indegree[there] == 0) q.push(there);	// 발견
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> V >> E;
	for (int i = 0; i < V; ++i) {
		graph[i].clear();
	}
	indegree = vector<int>(V, 0);
	for (int i = 0; i < E; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		indegree[v]++;
	}
	vector<int> sol = topological();
	for (int i = 0; i < sol.size(); ++i) cout << sol[i] + 1 << " ";
	return 0;
}


// 재귀스택 위상정렬로도 구할수 있지만 여기선 큐로 구해보자.
https://www.acmicpc.net/problem/1516
int V;
vector<int> graph[505];
vector<int> indegree;
vector<int> cost;
vector<int> solve() {
	vector<int> subMx(V, 0);	// 자식들이 생성하는데 걸리는 가장 큰 시간을 저장
	vector<int> ret(V, 0);
	queue<int> qu;
	for (int i = 0; i < V; ++i)
		if (indegree[i] == 0) {
			qu.push(i);		// 발견
			ret[i] = cost[i];
		}
	while (!qu.empty()) {
		int here = qu.front();	// 방문
		qu.pop();
		for (int i = 0; i < graph[here].size(); ++i) {
			int there = graph[here][i];
			// max(there의 서브중 가장 큰 비용, 현재 도달하는 비용)
			subMx[there] = max(subMx[there], ret[here]);
			indegree[there] -= 1;
			if (indegree[there] == 0) {
				// 부모가 전부 방문이 완료되어야 there 를 발견한걸로 처리한다.
				qu.push(there);
				ret[there] = cost[there] + subMx[there];
			}
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> V;
	for (int i = 0; i < V; ++i) graph[i].clear();
	indegree = vector<int>(V, 0);
	cost = vector<int>(V, 0);
	for (int i = 0; i < V; ++i) {
		int c; cin >> c;
		cost[i] = c;
		int tmp;
		while (cin >> tmp) {
			if (tmp == -1) break;
			tmp--;	// 먼저 지어져야 할 건물
			graph[tmp].push_back(i);
			indegree[i]++;
		}
	}
	vector<int> sol = solve();
	for (int i = 0; i < sol.size(); ++i) cout << sol[i] << '\n';
	return 0;
}



// 큐를 이용한 위상정렬에 사이클 검출 방법 : 인접리스트 그래프
http://js1jj2sk3.tistory.com/96	: 큐로부터 front 하는 갯수가 V 개 초과인지 아닌지로 구분
https://www.acmicpc.net/problem/2623 : 음악 프로그램

// 내방식 : 종만방식 + 인접리스트 + 사이클 체크 
// keyword: 사이클 검출, 사이클 판정, 사이클 유무
int V, M;
vector<int> graph[1010];
vector<int> sorted;
vector<bool> vstd;
void dfs(int here) {
	vstd[here] = true;
	for (int i = 0; i < graph[here].size(); ++i) {
		int there = graph[here][i];
		if (vstd[there] == false)
			dfs(there);
	}
	sorted.push_back(here);
}
// 자식이 root 를 향하면 사이클이다. :  문제점이 많다.!!!!!!!!
bool dfs(int here, int root) {
	vstd[here] = true;
	for (int i = 0; i < graph[here].size(); ++i) {
		int there = graph[here][i];
		if (there == root) return false;
		if (vstd[there] == true) continue;
		if (dfs(there, root) == false) return false;
	}
	return true;
} // 방향그래프에서 사이클 검출이 이렇게 간단히 되지는 않는다.
// 이렇게 하려면 모든 정점마다 다시 시작해야 한다. vstd 초기화를 새로 해야함... 끔찍
for (int i = 0; i < V; ++i) {
	vstd = vector<bool>(V, false);
	bool judge = dfs(i, i);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> V >> M;
	for (int i = 0; i < M; ++i) {
		int n;
		cin >> n;
		int prv = -1;
		for (int i = 0; i < n; ++i) {
			int ai; cin >> ai;
			if (prv == -1)
				prv = ai;
			else {				
				graph[prv - 1].push_back(ai - 1);
				prv = ai;
			}
		}
	}
	vstd = vector<bool>(V, false);
	bool ok = true;
	for (int i = 0; i < V; ++i) {
		if (vstd[i] == false) {
			ok = dfs(i, i);
			if (ok == false) {
				cout << 0;
				return 0;
			}
		}
	}
	vstd = vector<bool>(V, false);
	for (int i = 0; i < V; ++i) {
		if (vstd[i] == true) continue;
		dfs(i);
	}
	reverse(sorted.begin(), sorted.end());
	for (int i = 0; i < V; ++i) cout << sorted[i] + 1<< '\n';
	return 0;
}

// 위 소스로는 사이클을 못찾는다.
1 -> 2 -> 3 -> 4 -> 2 : 이 경우 1부터 탐색시 사이클을 못찾는다.


사이클 판정여부는 역방향 간선이 존재하는가 판단하는 것과 동치이다.

// 그냥 방문한점 또 방문하면 사이클 아니냐 하는 쉬운 생각은 nono 방향그래프라서 그게 안된다.
// ex) 3->4, 5->4 이런놈 있고 3부터 시작하면 사이클인줄 착각하겠죠


// 종만걸로 역방향 간선이 존재하는지 판단하여 풀었다.

int V, M;
vector<int> graph[1010];
vector<int> sorted;
vector<bool> vstd;
void dfs(int here) {
	vstd[here] = true;
	for (int i = 0; i < graph[here].size(); ++i) {
		int there = graph[here][i];
		if (vstd[there] == false)
			dfs(there);
	}
	sorted.push_back(here);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> V >> M;
	vector<vector<int>> board(V, vector<int>(V, 0));
	for (int i = 0; i < M; ++i) {
		int n;
		cin >> n;
		int prv = -1;
		for (int j = 0; j < n; ++j) {
			int ai; cin >> ai;
			if (prv == -1)
				prv = ai;
			else {	
				board[prv - 1][ai - 1] = 1;
				graph[prv - 1].push_back(ai - 1);
				prv = ai;
			}
		}
	}
	vstd = vector<bool>(V, false);
	for (int i = 0; i < V; ++i) {
		if (vstd[i] == true) continue;
		dfs(i);
	}
	reverse(sorted.begin(), sorted.end());
	// 역방향간선이 존재하는지 확인한다.
	for (int i = 0; i < sorted.size(); ++i)
		for (int j = i + 1; j < sorted.size(); ++j) {
			int u = sorted[i];
			int v = sorted[j];
			if (board[v][u] == 1) {
				cout << 0;
				return 0;
			}

		}
	for (int i = 0; i < V; ++i) cout << sorted[i] + 1<< '\n';
	return 0;
}

https://www.acmicpc.net/problem/3273	: !@#3_3
// 투 포인터 two pointer : 가장 좋은 테스트 문제넹
0 1 3  4  6 8  10

3 7
4 6
2 8
1 9
0 10

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int k;
	cin >> k;
	sort(arr.begin(), arr.end());
	int begin = 0, end = arr.size() - 1;
	int sol = 0;
	while (begin < end) {
		int sum = arr[begin] + arr[end];
		if (sum == k) {
			sol++;
		}
		if (sum >= k)
			end--;
		else if (sum < k)
			begin++;
	}
	cout << sol;
	return 0;
}

// !@#3_4
https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3286/
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
요구사항: swap 을 최소로 하며 O(n) 을 만족하도록 한다.
two pointer 로 풀면 됨
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx0 = 0, idxN = 0;
        while (idx0 < nums.size() && nums[idx0] != 0) idx0++;   // 최초 0의 인덱스
        while (idxN < nums.size()) {
            // 최초 "0이 아닌 숫자" 인덱스
            // 그리고 그 인덱스는 최초 0의 인덱스 보다 커야 한다.
            if (nums[idxN] != 0 && idx0 < idxN)
                break;
            idxN++;
        }
               
        while (idx0 < nums.size() && idxN < nums.size() && idx0 < idxN) {
            swap(nums[idx0], nums[idxN]);
            
            while (idx0 < nums.size() && nums[idx0] != 0) idx0++;   // 최초 0의 인덱스
            while (idxN < nums.size()) {
                // 최초 "0이 아닌 숫자" 인덱스
                // 그리고 그 인덱스는 최초 0의 인덱스 보다 커야 한다.
                if (nums[idxN] != 0 && idx0 < idxN)
                    break;
                idxN++;
            }
        }
    }
};

//정답 [0,1,0,3,12] -> [1,3,12,0,0]
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}


!@#3_5	two pointer
https://codeforces.com/problemset/problem/676/C	// a, b로 이루어진 문자열에서 k개 이하로 수정이 이루어질시 연속된 동일문자 최대길이
문자열의 길이가 최대 10만개이며 k는 0 <= k <= n 이다. 
https://codeforces.com/contest/676/submission/18076213



창의력이 필요한 좋은 문제다. (binary search 로도 풀수 있다.)
#include<bits/stdc++.h>

using namespace std;
int N, K;
string S;
int cmp(char c) {
	int ret = 1;
	int tail = 0, count = 0;		// tail 은 left 개념, i 는 right 개념이네
	for (int i = 0; i < N; ++i) {
		if (S[i] != c)
			++count;
		while (tail < N && count > K) {
			if (S[tail] != c)
				--count;
			++tail;
		}
		ret = max(ret, i - tail + 1);
	}
	return ret;
}
int main() {
	cin >> N >> K;
	cin >> S;
	cout << max(cmp('a'), cmp('b')) << endl;
}

12 4
bababbaaabaa
s:		0	1	2	3	4	5	6	7	8	9	10	11
		b	a	b	a	b	b	a	a	a	b	a	a
'a'기준	
I'll explain C using the example: "abbaa" , k = 1

First, find out how many consecutive a's are possible in "abbaa" if we can swap no more than one 'b':

We're going to have "pointerLeft" and "pointerRight" describing the substring we're looking at 
during the execution. Both pointers start from -1.

str = abbaa, k = 1
시작: pointerLeft = -1, pointerRight = -1;

pointerRight++ 
-> "a" possible
pointerRight++;
-> "ab" possible by swapping 1 b		// bCnt[right] - bCnt[left] 로 b의 갯수를 바로 알수 있다.
pointerRight++;
-> "abb" not possible, we cant swap 2 b's
pointerLeft++;
-> "bb" not possible
pointerLeft++;
-> "b" possible by swapping 1 b
pointerRight++;
-> "ba" possible by swapping 1 b
pointerRight++;
-> "baa" possible by swapping 1b, also the longest possible substring so far
We have now looked into all relevant substrings of consecutive a's. Next we would do the same thing for consecutive b's.


소수의 곱
https://www.acmicpc.net/problem/2014
K 개의 소수가 있다. 주어지는 소수는 모두 541보다 작거나 같은 자연수이다
예를 들어 세 소수가 2, 5, 7이었다면, 이러한 곱들을 오름차순으로 나타내 보면,
 2, 4, 5, 7, 8, 10, 14, 16, 20, 25, 28, 32, 35, 등이 된다.
이러한 소수의 곱들 중에서 N 번째 수를 구해보자 (1 <= N <= 1000000)
정답은 2^31 보다 작은 자연수이다. (나는 암만 풀어도 오버플로우 오류났다...ㅠㅠ)

풀이)
우선순위 큐에 집어 넣어 처리한다.
소수의 갯수는 30개 정도 된다.
그들로 이루어진 우선순위 큐는 크기가 빠르게 증가를 한다
증가하더라도 들어가는 수의 갯수는 메모리 용량을 오버하지는 않는다. (정답이 나올때까진 말이다.)
실제로 통과 코드의 메모리는 매우 아슬아슬했다. 128MB 제한에 100MS 약간 넘어서 통과함

맵을 사용한 코드는 메모리 초과가 낫다. ㅠㅠ
중복 제거를 위해 소수의 규칙을 이용해서 수를 생성시키고 큐에 넣은건 좋은 거임
https://www.acmicpc.net/source/4986149 : // 20배빠르고 50배 용량 줄인 코드.. 오 좋다.

내코드 // 이론상 O(N * logN * 30) : 30000000
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int k, n;
	cin >> k ?? n;
	vector<int> arr(k);
	for (int i = 0; i < k; ++i) cin >> arr[i];
	pq.push(1);
	int cnt = 0;
	long long sol = 0;
	long long cur = 0;
	while (cnt <= n) {
		cur = pq.top();
		pq.pop();
		cnt++;
		for (int i = arr.size() - 1; i >= 0; --i) {
			if (cur % arr[i] == 0) {
				long long nxt = (long long)cur * arr[i];
				if (nxt < (1ull << 31))
					pq.push(nxt);
				break;
			}
			long long nxt = cur * arr[i];
			if (nxt < (1ull << 31))
				pq.push(nxt);
		}
	}
	cout << cur;
	return 0;
}


// --------------------------- 규칙성 찾아내는 마치 iq 테스트 식 접근 문제-------------//

http://codeforces.com/contest/1091/problem/D : 문제보소... ㄷㄷㄷ
// 수식전개론 내머리론 절대 못풀어유 ㅠㅠㅠㅠㅠㅠㅠ
// 관계를 알아내어 iq 테스트하듯 수식을 유도하는 방법을 써보자.
// div 1 + 2 통틀어 1000명 이상 풀었다면 iq 테스트 방식으로 접근하자.. 쨉실하지만 어쩔수 없다.

먼저 출력을 해보니 ... 뭔가 규칙성이 나오나 울프람을 돌려도 찾을수가 없네...
3 : 9
4 : 56
5 : 395
6 : 3084
7 : 26621
8 : 253280

일단 각 N 길이는 확실히 합이 N * (N + 1) / 2 를 보장하기에 그것을 따로 두보자
3! = 6
4! = 24
5! = 120
6! = 720
7!
8!

팩토리얼은 확정이니까 빼면 실제로 우리가 구해야 할 규칙성 부분이 나오게 된다.
3: 		9	= 6 + 3 		// x = 3
4:		56	= 24 + 32		// x = 32		: 32는 어떻게 구할까? 앞의 9에다가 현재 4를 곱한뒤 4를 빼니 나오네.. 완전 씹창 감이구나
5:		395	= 120 + 275		// x = 275		: 275는 어떻게 구할까
const ll mod = 998244353;
const double eps = 1e-10;

vi get(vi nums) {
	vi ret;
	sort(nums.begin(), nums.end());
	do {
		ret.insert(ret.end(), nums.begin(), nums.end());
	} while (next_permutation(nums.begin(), nums.end()));
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//vll tmp = getDivsors(1 << 30);
	//int base = 5;
	//while (true) {
	//	cin >> base;
	//	vi nums;
	//	for (int i = 1; i <= base; ++i)
	//		nums.push_back(i);
	//	vi sss = get(nums);
	//	ll cnt = 0;
	//	for (int i = 0; i + base - 1 < sss.size(); ++i) {
	//		long long partSum = 0;
	//		for (int j = 0; j < base; ++j) {
	//			partSum += sss[i + j];
	//		}
	//		if (partSum == (base * (base + 1) / 2))
	//			cnt++;
	//	}
	//	cout << cnt << '\n';
	//}

	vll dp(1000100, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 9;
	
	vll fac(1000100, 1);
	fac[1] = 1;
	fac[2] = 2;
	for (int i = 3; i < 1000010; ++i)
		fac[i] = (fac[i - 1] * i) % mod;

	for (int i = 4; i < 1000010; ++i) {
		ll ad0 = fac[i];
		ll ad1 = (dp[i - 1] * i - i) % mod;
		dp[i] = ad0 + ad1;
		dp[i] %= mod;
	}
	int N;
	cin >> N;
	cout << dp[N];
	return 0;
}


https://www.acmicpc.net/problem/1964
오각형, 오각형, 오각형…
// 다른 사람이 푼거
#include<cstdio>
int main(){
	long long int a;
	scanf("%lld",&a);
	printf("%lld",((3*a*a+5*a)/2+1)%45678);
}
나는 노가다로 품.
계차수열 합 공식을 도출하지 못함...

// 기존 + 위좌변 + 아래우변 + 위우변 점들의 합
//1
//1 + 2 + 2 + 0 = 1 + 4
//5 + 3 + 3 + 1 = 5 + 7 = 12
//12 + 4 + 4 + 2 = 12 + 10 = 22
//22 + 5 + 5 + 3 = 22 + 13 = 35
//35 + 6 + 6 + 4 = 35 + 16 = 51
const int mod = 45678;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int prv = 1;
	int add1 = 2;	// 위쪽 좌변
	int add2 = 2;	// 아래쪽 우변
	int add3 = 0;	// 위쪽 우변(중복점 제외)
	for (int i = 1; i <= n; ++i) {
		int cur = prv + add1 + add2 + add3;
		cur %= mod;
		add1 += 1;		add2 += 1;		add3 += 1;		prv = cur;
	}
	cout << prv;
	return 0;
}
음 1에다가 sigma{4 + 3(n-1)} 를 더해주면 되는구나
계차수열까지도 필요없다.
등차가 3이고 초항이 4인 수열의 합을 구하면 된다.

4 + 7 + 10 + 13 + ...
S = n(a + l) / 2	// a 는 초항 , l 은 끝항
S = n * {a + a + (n - 1) * d} / 2;
S = n * {1 + 1 + (n - 1) * 3} / 2;
const int mod = 45678;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	long long n;
	cin >> n;
	// S = n * (a + l) / 2;
	// S = n * (a + a + (n - 1) * d) / 2
	long long tmp = 1 + (n * (4 + 4 + (n - 1) * 3) / 2);
	tmp %= mod;
	cout << tmp;
	return 0;
} 


https://www.acmicpc.net/problem/2004
출처: http://ksj14.tistory.com/entry/BackJoon2004-조합-0의-개수 [:: ADVANCE ::]
nCm 의 끝자리 0의 개수를 출력하는 알고리즘 작성하라
n, m (0 <= m <= n <= 2000000000, n != 0) 이 들어온다.

음... 10의 배수를 이루려면  min(5의 갯수, 2의 갯수) 이 된다만.


조금 간단하게 한다면
n! 의 0의 갯수 - m!의 0의 갯수 - (n - m)! 의 0의 갯수 // 오오오오 !!!!!!!!
-> (n!의 min(2개수, 5개수) - (m!의 min(2개수, 5개수)) - ((n - m)! 의 min(2개수, 5개수))

게다가 5의 갯수는 항상 2의 갯수보다 많으니 5의 갯수만 신경쓰자.
그런다 해도 n 이 20억이면 ... 20억이라는게 어마어마하다.


관점을 바꾸자.
이 문제를 먼저 보자.
https://www.acmicpc.net/problem/1676
출처: http://ksj14.tistory.com/entry/BackJoon1676-팩토리얼-0의-개수 [:: ADVANCE ::]
N! 에서 뒤에서 부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하라
0 <= N <= 500 // 조건은 느슨한 편이다.
for (int i = 2; i <= n; ++i) {
	temp = i;
	while (!(temp % 5)) {
		five++;
		temp /= 5;
	}
	while (!(temp % 2)) {
		two++;
		temp /= 2;
	}
	printf("%d\n", (two < five) ? two : five);
}

요런 노가다를 펄칠것이다.

헌데 관점을 바꾸어보자.
2의 배수의 개수는 n / 2 가 된다.
4의 배수의 개수는 n / 4 가 된다. : 요놈 4는 2 * 2 이니 2를 한개 더가지고 있음
8의 배수늬 개수는 n / 8 이 된다. : 8은 2 * 2 * 2 이니 2를 4보다 한개 더 가짐
16
32 ...
ㅎㅎㅎ

100! 의 5의 개수는
100 / 5 = 20	// 1에서 100까지의 수 중 5의 배수의 갯수
100 / 25 = 4	// 1에서 100까지의 수 중 25의 배수의 갯수
즉 100! 의 5의 개수는 24가 된다. : 생각보다 작네
5의 갯수는 2의 갯수보다 항상 작으므로 5의 갯수만 구해도 된다.

int main() {
	int n;
	int two = 0, five = 0;
	cin >> n;
	for (int i = 2; i <= n; i *= 2)	// 오오 감동 코드다 !!!!!!!!@@@@@@@@
		two += n / i;
	for (int i = 5; i <= n; i *= 5)
		five += n / i;
	cout << (two < five) ? two : five;
	return 0;
}

// 내소스: 5만 비교한다.
int solve(long long num) {
	int five = 0;
	for (long long i = 5; i <= num; i *= 5)
		five += num / i;
	return five;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int sol = solve(n);
	cout << sol;
	return 0;
}




// 헌데 조합에선 5만 가지고 하면 틀린다. why.....
long long solve(long long num) {
	int five = 0;
	for (long long i = 5; i <= num; i *= 5)
		five += num / i;
	return five;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	long long sol = solve(n) - solve(m) - solve(n - m);
	cout << sol;
	return 0;
}
// 5의 갯수만 쓰면 통과 안됨!!!! ㅅㅂ ㅅㅂ
반례를 못찾겠다 꾀꼬리...
// 이렇게 하니 통과는 한다만... 
long long getTwo(long long num) {
	int two = 0;
	for (long long i = 2; i <= num; i *= 2)
		two += num / i;
	return two;
}
long long getFive(long long num) {
	int five = 0;
	for (long long i = 5; i <= num; i *= 5)
		five += num / i;
	return five;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	int two = getTwo(n) - getTwo(m) - getTwo(n - m);
	int five = getFive(n) - getFive(m) - getFive(n - m);
	cout << min(two, five);
	return 0;
}
조합에서 5를 기준으로 풀면 틀린다.
5C1 의 경우를 보자
5의 갯수는 1이다만 2의 갯수는 0이다. 
"즉 조합에서는 5의 갯수가 2보다 큰 상황이 발생한다."!!!!! 오 천잰데 ㅎㅎㅎ






// ------------------------ 미정리 ----------------------------- //
https://www.acmicpc.net/problem/16917 : 양념 반 후라이드 반 : 내가 해맨거. 간단하니 생략한다. 재훈추천

void test(double up, double N) {
	cout << fixed;	// 이거 안하면 소수점 이하 15개를 보장 못함
	streamsize prec = cout.precision(15);	// 숫자 15개임. fixed 가 있으면 소수점 자리수 15개 항상 보장
	// 셋다 동일하게 나옴
	cout << up * N * 1000000<< '\n';		
	cout << up * N * 1000000<< endl;
	cout << up * N * 1000000;
}
백준 동전 뒤집기: 확률문제 : https://www.acmicpc.net/problem/13255 동전뒤집기 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<double> arr(K);
	for (int i = 0; i < K; ++i) cin >> arr[i];
	double up = 1.0;
	double down = 0.0;
	for (int i = 0; i < arr.size(); ++i) {
		double flip = arr[i] / N;
		double nonFlip = 1.0 - arr[i] / N;
		double nextUp	= up * nonFlip + down * flip;
		double nextDown = down * nonFlip + up * flip;
		up = nextUp;
		down = nextDown;
	}
	cout << fixed;	// 이거 안하면 소수점 이하 15개를 보장 못함
	streamsize prec = cout.precision(15);	// 숫자 15개임. fixed 가 있으면 소수점 자리수 15개 항상 보장
	cout << N * up;
	return 0;
}


https://www.acmicpc.net/problem/1507 : 궁금한 민호 :
// 간선을 없앤다고 MST 가 되지는 않는다.
// 최소거리를 유지하면서 필요한 간선 빼고 나머지를 지운다면 남은 간선은 항상 유일함을 보장한다.
const int INF = 1234567;	// 간선이 삭제될때 사용됨 : n 이 최대 20이고 각 간선은 10000이 최대임
int adj[22][22];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> adj[i][j];
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (adj[i][j] == INF) continue;
				if (k == i || j == k) continue;
				if (adj[i][j] == adj[i][k] + adj[k][j]) {
					adj[i][j] = INF;
				}
				else if (adj[i][j] > adj[i][k] + adj[k][j]) {
					cout << -1;
					return 0;
				}
				// 그외에는 가만 놔둔다.
			}
	int total = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (adj[i][j] != INF)
				total += adj[i][j];
	cout << total / 2;
	return 0;
}



플로이드 문제 좋은거 리스트 http://mygumi.tistory.com/110

https://www.acmicpc.net/problem/1613 역사 매우 좋은 문제 !!!!!!!! 
// 문제를 보고나서 플로이드를 떠올릴줄 알아야 한다 !!!!!!!!@@@@@@@@@
각 시점 u, v에서 어느게 먼저인지 입력됨
그걸로 플로이드를 돌린다.
그리고 쿼리가 날라오면 앞이 먼저이면 -1, 뒤가 먼저이면 1, 모르겠으면 0을 출력하면된다.
점이 5000개임 쿼리가 50000개임 위상정렬로 구하기엔 매우 귀찮으나 플로이드로 하면 매우 편하다
const int INF = 123456789;
const int MX = 405;
int adj[MX][MX];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			if (i != j)
				adj[i][j] = INF;
	for (int i = 0; i < E; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u][v] = 1;
	}
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	int S;
	cin >> S;
	for (int i = 0; i < S; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		// u에서 v로 가는 길이 있다면
		if (adj[u][v] != INF && adj[u][v] > 0)	// 즉 앞의 사건이 먼저 일어났으면
			cout << -1 << '\n';
		else if (adj[v][u] != INF && adj[v][u] > 0)	// 뒤의 사건이 먼저 일어났으면
			cout << 1 << '\n';
		else
			cout << 0 << '\n';	// 연결된 길이 없는 경우
	}
	return 0;
}


https://www.acmicpc.net/problem/2166		// 다각형의 면적
struct point { long long x, y; };
// 다각형 좌표가 들어오면 넓이를 리턴한다.
double getArea(vector<point>& arr) {
	double ret = 0.0;
	for (int i = 0; i < arr.size(); ++i) {
		int cur = i;
		int prv = (i - 1 + arr.size()) % arr.size();
		ret += (arr[cur].x + arr[prv].x) * (arr[cur].y - arr[prv].y);
	}
	if (ret < 0) ret *= -1.0;
	return ret / 2.0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<point> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i].x >> arr[i].y;
	double sol = getArea(arr);
	cout.precision(1);
	cout << fixed << sol;
	return 0;
}


https://www.acmicpc.net/problem/1485		// 정사각형 : 간단해보이지만
// 노가다 구현은 손이 많이 간다. 정사각형이 30도 회전된 형태라던가 한다면 말이다.

 정사각형의 규칙을 이용하면 간단하다.  4변의 길이가 같고 대각선 두변의 길이가 같다.!!!!!!!!@@@@@@@@
 "단 점들이 같은 위치에 있으면 안됨"
 struct point { long long x, y; };
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	vector<point> arr(4);
	while (T--) {
		// 같은 위치의 점이 주어지지는 않는다.
		for (int i = 0; i < 4; ++i)
			cin >> arr[i].x >> arr[i].y;
		vector<long long> sqDist;
		for (int i =0; i < 4; ++i)
			for (int j = i + 1; j < 4; ++j) {
				long long xx = arr[i].x - arr[j].x;
				long long yy = arr[i].y - arr[j].y;
				xx *= xx;
				yy *= yy;
				sqDist.push_back(xx + yy);
			}
		sort(sqDist.begin(), sqDist.end());
		long long base = sqDist[0];
		for (int i = 1; i < 4; ++i) {
			if (base != sqDist[i])
				base = -1;
		}
		if (base == -1) {
			cout << 0 << '\n';
			continue;
		}
		if (sqDist[4] != sqDist[5]) {
			cout << 0 << '\n';
			continue;
		}
		cout << 1 << '\n';
	}
	return 0;
}


https://www.acmicpc.net/problem/1025 // 제곱수 찾기 : 문제 이해하는것도 헬이였다.
// 깔끔하게 잘 짰구나... 좋은 코드다. https://github.com/blisstoner/BOJ/blob/master/1025.cpp
2 3
123
456
output : 64

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
char map[10][10];
int N, M;
bool isSquare(int x) {
	int t = (int)sqrt(x);
	for (int i = t - 2; i <= t + 2; i++)
		if (i*i == x) return true;
	return false;
}
bool isOutOfBounds(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}
int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);
	int ans = -1;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			for (int dx = -N; dx < N; dx++) {
				for (int dy = -M; dy < M; dy++) {
					int val = 0;
					if (dx == 0 && dy == 0)
						continue;
					int curX = x;
					int curY = y;
					while (!isOutOfBounds(curX, curY)) {
						val = 10 * val + (map[curX][curY]-'0');
						if (isSquare(val))
							ans = max(ans, val);
						curX += dx;
						curY += dy;
					}
				}
			}
		}
	}
	printf("%d", ans);
}







/////////////////////////////// 2019년 codeforces 및 실전 대회 회기 /////////////////////////////////////

2019.01.27 // Jan/27/2019 00:35UTC+9
<<< Educational Codeforces Round 59 (Rated for Div. 2) >>>
http://codeforces.com/contest/1107/problem/B : B. Digital root(디지털루트)
S(5) = 5,	S(38) = S(3 + 8 = 11) = S(1 + 1 = 2) = S(2) = 2

3	// test case
1 5	// 1: 첫번째 수, 5: digital 루트 결과
5 2
3 1

// output
5
38		// 2, 11, 20, 29, 38
19		// 1, 10, 19

// 규칙성을 알수있다. 9씩 더하고 있다. : 넘나 긴장해서 이 규칙을 못찾고 마이구미 블로그 찾음
https://mygumi.tistory.com/251

dr(n) = 1 ((n - 1) mod 9) //디지털루트 공식
	위 공식으로 부터 9개씩 커진다는 규칙을 알게 되었고 그 뒤는 쉽게 품 (소스 생략)
	

	
http://codeforces.com/contest/1107/problem/C : C. Brutality

다시 보니 문제 해석이 안된다... 으으
// 각버튼별로 총 k 번 밖에 못 누른다. : 중간에 다른 버튼을 누를때만 0으로 리셋된다
// 스킵한다고 리셋되지는 않는다.
	번역: 버튼이 26개 있고 누르는 타이밍마다 공격이 주어진다.
		허나 임의의 버튼을 k번을 초과하여 누르면 안된다. (more than 이라고 되어 있으면 이상인데... ㅅㅂ)
		그런데 그 연속성에서 다른 버튼이 눌려진다면 초기화 된다.
		//단 같은 문자를은 스킵한다고 초기화가 되지는 않는다.
		남은 입력들로 합해서 최대 공격력을 구하라.

1 <= k <= n <= 2*100000

즉
input
6 3
14 18 9 19 2 15 
cccccc

output
52 // 3개만 선택할 수 있다.


7 3
1 5 16 18 7 2 10
baaaaca
output
54		// a:5 인놈을 제거한다. 마지막 a는 사용가능함. c로 리셋되었기 때문

http://codeforces.com/blog/entry/64847 : 대회때 나도 통과했다만 풀이걸로 대체
갯수가 20만개니 정렬도 10만번 하니 속도 문제가 걱정이였다만
// 분할되기에 정렬이 많더라도 코스트가 높지않다.
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	string s;
	cin >> s;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;
		vector<int> vals;
		while (j < n && s[i] == s[j]) {
			vals.push_back(a[j]);
			++j;
		}
		sort(vals.rbegin(), vals.rend());
		ans += accumulate(vals.begin(), vals.begin + min(k, int(vals.size())), 0ll);
		i = j - 1;
	}
	cout << ans << endl;
}

http://codeforces.com/contest/1107/problem/D : D. Compression
주어진 행렬이 압축이 어느정도 되는지 묻는 문제

00001111
00001111
00001111
00001111
11110000
11110000
11110000
11110000
결과는 4가 된다.

0011
0011
1100
1100
결과는 2가 된다.



0101
1010
0101
1010





Oct/01/2016 20:11  // 왜 여기다 기록 했지... 옛날문제임
<<< Intel Code Challenge Elimination Round (Div. 1 + Div. 2, combined) >>>
http://codeforces.com/contest/722/problem/C : C. Destroying Array
배열이 최대 10만개 주어진다. 각 요소는 10억 이하
임의의 순서대로 숫자가 사라지며 그로 인해 segment 들이 만들어진다.
이때 각 세그먼트의 합중 가장 큰 합을 출력하라

input
4
1 3 2 5		// 배열
3 4 1 2 	// 삭제 인덱스

output
5	// 3번을 삭재하면:	1 3   5 가 되어 5가 가장 크다.
4	// 4번을 삭제하면:	1 3		// 합인 4가 된다
3	// 1번을 삭제하면:	  3
0	// 2번을 삭제하면:	아무것도 없다.

나는 구간트리로 풀었다. : 시험때는 못품....
http://codeforces.com/contest/722/submission/21103967
// 390ms
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MOD 1000000007
#define MAX_N 1000000
typedef long long ll;
using namespace std;
typedef const vector<int> cvi;
const long long INF = 1LL << 60;
struct RangeResult {
	bool allConnect;
	ll leftSum, rightSum, cMaxSum;
	// 만약 생성자를 추가한다면 기본 생성자가 없으면 컴파일이 안됨 !!!! 귀찮네.. 왜 필요한가
	RangeResult() : allConnect(false), leftSum(0), rightSum(0), cMaxSum(0) {} // 기본 생성자
	RangeResult(int val) : allConnect(true), leftSum(val), rightSum(val), cMaxSum(val) {
		if (val == -1) allConnect = false, leftSum = rightSum = cMaxSum = 0;
	}
};
RangeResult merge(const RangeResult& a, const RangeResult& b) {
	RangeResult ret(0);
	ret.leftSum = a.leftSum;
	if (a.allConnect == true) ret.leftSum += b.leftSum;
	ret.rightSum = b.rightSum;
	if (b.allConnect == true) ret.rightSum += a.rightSum;

	if (a.allConnect && b.allConnect)
		ret.allConnect = true;
	else
		ret.allConnect = false;
	ret.cMaxSum = max(a.cMaxSum, b.cMaxSum);
	ret.cMaxSum = max(ret.cMaxSum, a.leftSum);
	ret.cMaxSum = max(ret.cMaxSum, b.rightSum);
	ret.cMaxSum = max(ret.cMaxSum, a.rightSum + b.leftSum);
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
			return segTree[node] = RangeResult(newVal);	// -1 로 대입
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
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<int> arr(n + 1);
	for (int i = 0; i < n; ++i) cin >> arr[i + 1];
	RMQ3 rmq(arr);
	for (int i = 0; i < n; ++i) {
		int index;
		cin >> index;
		RangeResult sol = rmq.update(index, -1);
		cout << sol.cMaxSum << endl;
	}
	return 0;
}


// 역발상: 거꾸로 생각하자. 뒤에서 부터 본다면 하나씩 제거가 아니라 하나씩 증가
// 구간 분열 문제는 dsu 로도 풀수가 있다. 오프라인 알고리즘으로 말이다.
http://codeforces.com/contest/722/submission/21074806 : 구사과 코드
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
lint sz[100005];	// 구간합 기록: idx 는 집합의 루트
int pa[100005];		// 루트를 가르킴
int find(int x) {
	return pa[x] = (pa[x] == x ? x : find(pa[x]));
}
bool uni(int p, int q) {
	p = find(p);
	q = find(q);
	if (p == q) return 0;
	pq[q] = p;		// 간단하게 하넹.. 깊이 비교 없어도 find 가 깊이를 1로 만드니
	sz[p] += sz[q];	// 함
	return 1;
}
int n, a[100005], q[100005];
lint r[100005], cur;	// r: 답을 기록
int ok[100005];		// 거꾸로 돌릴시 재생된(선택) 것
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) pa[i] = i;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &q[i]);
	for (int i = n; i; --i) {
		ok[q[i]] = 1;
		sz[q[i]] = a[q[i]];	// 현재 살리는 놈의 값
		if (ok[q[i] + 1]) uni(q[i], q[i] + 1);
		if (ok[q[i] - 1]) uni(q[i], q[i] - 1);
		r[i] = cur;		// 오오 !!!!!!!!
		cur = max(cur, sz[find(q[i])]);
	}
	for (int i = 1; i <= n; ++i) printf("%lld\n", r[i]);
}



// 온코더 12라운드 c문제
//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
#include <vector>
#include <cmath> // 부동소수 언더플로우 땜시 로그를 써야 될거다.
using namespace std;
class Solution{
public:
	// 한번이라도 칠해질 확률
	double get(int i, int j, int rows, int cols) {
		// i 보다 작거나 같을 확률
		double unI = (i + 1) / (double)rows;
		// i 보다 크거나 같을 확률
		double ovI = (rows - i) / (double)rows;

		// j 보다 작거나 같을 확률
		double unJ = (j + 1) / (double)cols;
		// j 보다 크거나 같을 확률
		double ovJ = (cols - j) / (double)cols;

		double axisX1 = unI * ovI;		// 처음이 i보다 작거나 같고 두번째가 i보다 같거나 큰 경우의 확률
		double axisX2 = unI * ovI;		// 두번째가 i보다 작거나 같고 첫번째가 i보다 같거나 큰 경우의 확률
		double axisX = axisX1 + axisX2 - (1.0 / (rows * rows));		// 처음도 i 이도 두번째도 i인 확률은 두번 더해지니 한번은 뺀다. 
		// 주사위가 순서없이 1,2 가 나올 확률은 1,1이 나올 확률의 두배임을 기억하면 이해된다.
		
		double axisY = unJ * ovJ * 2 - (1.0 / (cols * cols));
		
		// 두 축(x, y)은 서로 독립되어 있기에 곱하면 된다.!!!!!!!! 이개념이 중요하다. 내가 실수한 부분임
		return axisX * axisY;

	}
	// 색칠되어 있는 칸의 기대값을 구한다.
	double solution(int K, int rows, int cols){
		if (K == 0) return 0;
		vector<vector<double>> board(rows, vector<double>(cols, 0.0));
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j) {
				// get(i, j, rows, cols) : i, j 칸에 질해질 확률
				double loc = 1.0 - get(i, j, rows, cols);// 한번 수행시 각 격자별로 칠해지지 않을 확률을 구한다.
				board[i][j] = log(loc); // 언더플로우 방지용으로 로그 취함
			}
			// 각 격자별로 K 번 수행시 한번도 칠해지지 않을 확률을 구한다.
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					board[i][j] = board[i][j] * K;

			// 로그 원복 , // 1 - (한번도 칠해지지 않을 확률) 이 각 격자칸이 한번이라도 칠해질 확률이 된다.
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					board[i][j] = 1 - exp(board[i][j]);

			// 모든 합을 구하면 된다.
			double sol = 0.0;
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					sol += board[i][j];
			return sol;
	}
};

int main() {
	Solution sss;
	double ss = sss.solution(0, 1, 1);
	return 0;
}

// 고찰: 다른방식으로 풀기
// (1 - (x축 범위가 i 미만일 확률 + x축 범위가 i초과일 확률)) * (1 - (y축 범위가 j미만일 확률 + y축 범위가 j초과일 확률))

|	|	| 두 칸이 있고 (0, 0) 에 칠해질 확률
x축 범위가 0미만일 확률 = 0
x축 범위가 0초과일 확률 = (하나가 1이상일 확률: 0.5) * (다른 하나가 1이상일 확률: 0.5) = 0.25
0, 0인 곳에 칠해질 확률 = 1 - (0 + 0.25) = 0.75
(0, 0) + (0, 1) = 0.75 + 0.75 = 1;

// 예제 대입 해서 생각해보자.
K = 1
rows = 2
cols = 1 리턴(정답): 1.5
2칸짜리 격자입니다.
2칸 모두 색이 칠해질 확률은 0.5 이며,
1칸만 색이 칠해질 확률은 0.5 입니다.
따라서 색이 칠해진 칸의 개수의 기대값은 0.5 * 2 + 0.5 * 1 = 1.5 입니다.


K = 2
rows = 2
cols = 1 리턴(정답): 1.875
(0, 0) => 한번던질때 색이 안칠해질 확률 = 1.0 - 한번던질때 색이 칠해질 확률 = 1.0 - 0.75 = 0.25
두번던질때 색이 안칠해질 확률 = 0.25 * 0.25 = 0.0625;
두번던질때 색이 하나라도 칠해질 확률 = 1.0 - 0.0625 = 0.9375
(0, 0) + (1, 0) = 0.9375 + 0.9375 = 1.875



#if 0 //20190601 codeforces round 560 div3


#endif //20190601 codeforces round 560 div3()~



#if 0 //20190602 codeforces round 555 div3
https://codeforces.com/contest/1157/problem/B
no more than once // 뜻을 몰라서 망함. : 직역 1번을 초과할 수 없다. 

https://ilikeen.tistory.com/1576 : 영어공부...ㅠㅠ
참고 : no more than ~ , 반대말 no less than ~
A 보다 더 많이는 아님, A 보다 더 적게는 아님

How much do you have money?
I have no more than 10,000 won.	// 만원밖에 없어 : 부정적. 적게 써야 한다는 늬앙스
I have no less than 10,000 won. // 만원이나 있어 : 긍정적


I know no more than that. // 난 그것보다 더 많이는 알지 않아. // 즉 겨우 그것만 안다는 말
I stayed there no mroe than two day. // 난 거기서 이틀보다 더 많이는 묵지 않았어 // 즉 겨우 이틀만 묵었다는 말
Tom gave me no more than 30,000 won. // 탐은 내게 3만원보다 더 많이는 안 줬어 // 즉, 탐은 나한테 겨우 3만원만 줬어


https://codeforces.com/contest/1157/problem/C2


#endif //20190602 codeforces round 555 div3()~





// -------------------  sw expert stl 구현 --------------------- //
// (vector 예제: sort는 퀵 변종임) : 원조 퀵소트는 간단함. 정 안되도 그곳에서 알고리즘을 알려줌
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

template <class T>
class _vector {
public:
	int _size;	int capacity;	T *arr;
	_vector() {	_size = 0;	capacity = 32;	arr = new T[capacity];	}
	_vector(int k) {	_size = k;	capacity = k;	arr = new T[capacity];	}
	~_vector(){	delete[] arr;	}
	void clear(){	delete[] arr;	_size = 0;	capacity = 32;	arr = new T[capacity];	}
	void resize(int k) {
		T *temp;	temp = new T[k];
		for (int i = 0; i < _size; i++)	temp[i] = arr[i];
		delete[] arr;
		arr = temp;	_size=capacity=k;
	}
	int size() const{	return _size;	}
	T* begin() const{	return &arr[0];	}
	T* end() const{		return &arr[0] + _size;	}
	void push_back(T val) {
		if (_size == capacity) {
			resize(_size * 2);	_size /=2;
		}
		arr[_size++] = val;
	}
	void pop_back() { _size--;	}
	T& operator [](int idx) {	return arr[idx];	}
	T operator [](int idx)const{	return arr[idx];	}
};
template <typename It>
void _swap(It &a, It &b){
	It c(a);a=b;b=c;
}
template <typename It, typename Comp>
void _sort(It begin, It end, Comp comp){
	if(begin==end)
		return;
	_swap(*begin, *((end-begin)/2+begin));
	It pi = begin;
	It le = begin + 1;
	It ri = end - 1;
	while( le <= ri ) {
		while(le <= ri && !comp(*pi, *le))
			le++;
		while(le <= ri && !comp(*ri, *pi))
			ri--;
		if(le<=ri)
			_swap(*le, *ri);
	}
	_swap(*pi, *ri);
	_sort(begin, ri, comp);
	_sort(ri + 1,  end, comp);
}

template <typename A, typename B>
struct _pair{
	A first;	B second;
	_pair(A a, B b):first(a), second(b){}
	_pair(){}
};

bool cmp(const _pair<int, int>& a, const _pair<int, int>& b){
	if(a.first==b.first)
		return a.second<b.second;
	return a.first<b.first;
}
int main() {
	_vector<_pair<int, int> > arr;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		_pair<int, int> tmp(a, b);
		arr.push_back(tmp);
	}
	_sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", arr[i].first, arr[i].second);
	return 0;
}


bool _sw5(int K, int org[5], int trg[5]);	// 최대 5개를 한번에 swap 가능함.

void solution(int N, int* box, int lim) {
	
	
}
// 문제 설명
solution 함수를 구현해야 함.
box 배열은 0부터 n - 1 까지의 숫자가 들어 있다. 임의로 들어 있으며 정렬해야 한다.
box 를 정렬하기 위해 swap5 함수를 호출한다. 단 limit 이하로 호출해야 한다. (limit 을 놓쳤음.. 난..)

swap 읜 거진 항상 2개의 인자만 받아 처리했기에 저런 경우(5개씩 swap)에 대해 생소했다.
핵심 "5개가 한번에 swap 되려면 5개의 인자들의 관계는 사이클을 이루어야 한다."

// 2개짜리 인 경우 두 원소가 사이클을 이룬다.
2 3 4 0 1
0 1 2 3 4

==> 0번 인덱스인 2를 2번 인덱스에 위치한 4랑 swap 시키면 : 0->2, 2->4 로 두 관계는 사이클임. 
// origin 과 target 는 다음과 같은 관계 origin = {0, 2}, target = {2, 0}
4 3 2 0 1

==> 4를 4번 인덱스놈(1) 과 swap 시키면
1 3 2 0 4

==> 1을 1번 인덱스놈(3) 과 swap 시키면
3 1 2 0 4

==> 3을 3번 인덱스놈(0) 과 swap 시키면
0 1 2 3 4

이렇게 된다.

10개의 수가 있고
3 1 0 9 4 5 2 8 7 6
0 1 2 3 4 5 6 7 8 9 // 목표

3->9->6->2->0 : 사이클을 이룬다.  // swap5 로 처리가 가능하다.
1->1	// 무시
4->4	// 무시
5->5	// 무시
8->7	: 사이클을 이룬다.


만약 사이클의 원소가 6개 이상이면
3 0 1 9 4 5 2 8 7 6
0 1 2 3 4 5 6 7 8 9	// 목표

3->9->6->2->1->0 로 사이클을 이룬다면 swap5 로 처리가 불가능하기에 분리해야 한다.
3->9->6->2->1	//사이클을 만들고 : 1은 3과 연결되는 식으로 루프돔
추가로
3->0 으로 사이클을 만들면 된다.

// 이런식으로 11사이클의 경우 5사이클 + 5사이클 + 3사이클로 분해가 가능하다.

좀더 고급 기법을 쓴다면
cir2 짜리가 최소고
cir3 짜리, cir4 짜리 cir5 짜리가 존재하며

cir2 짜리랑 cir3짜리를 묶어서 swap5로 한번에 처리가능하다.
cir2 짜리는 cir2 끼리 묶어서 swap5로 한번에 처리가능하다.

cir3는 3개가 존재하면 swap5 두번 호출로 처리가 가능하다. !!!! 내가 빠뜨린 부분이다.
2->0->1, 4->5->3, 8->6->7 의 경우
2->0->1 은 2->0, 0->1 으로 나뉘어진다. 
	// 2->0 : 2는 2번 위치로 간다. 1은 0번 위치로 가게 된다.
	// 0->1 : 1은 1번 위치로 간다. 0은 0번 위치로 간다.
그걸로 {2->0, 4->5->3}, {0->1, 8->6->7} swap5 호출 한다.

"수도코드" // 이거 전에 먼저 circle 형 사이클들을 다 기록한다. cir4 이상은 끝뜨머리만 분리하자. 끝이 cir3 이하면 축소가 가능하다.
// cir3 짜리를 cir2 와 합쳐서 처리한다.
min minCnt = min(cir2.size(), cir3.size())
int baseIdx = 0;
for (; baseIdx < minCnt; ++baseIdx) {
	// 두개 합쳐서 origin, target 생성 및 swap5 호출
}

남은 cir3 를 처리한다.
cir3 는 3개씩 묶어서 2번의 swap5 로 호출한다.

남은 cir2 를 처리한다. 두묶음씩 처리 하면 된다. 


내 문제점 
a. cir3 끼리 묶지 못한점 : 최적화 실패
b. 급해서 lim 에 대해 신경 쓰지 못한점 : 문제 제약에서 lim 횟수 초과하면 중지해야 된다고 했음.. ㅠㅠ
c. _vector<_vector<int>> 좆망임. _vector<int> 의 복사생성자 대입 연산자 구현 자체가 안되어 있음. 
	그로 인해 소멸자에서 같은 주소 delete [] T; 발생하여 예외를 던짐. 일단 delete[] 구문을 없앴기에 돌아는 가나
	메모리 누수가 난다. (256mb 제약으로 인해 테스트 케이스50개 는 통과 될지도...)









http://www.algolist.net/Algorithms/Sorting/Quicksort
C++ // 동작방식 잘 설명되어 있다.
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

https://github.com/baactree/Algorithm/blob/master/Stl/map.cpp // 박트리 맵(map)
https://cubelover.tistory.com/10	// 박트리 코드에 대한 설명(cubelover)

삼b 
블럭들연결관계를 .. 자식이 사라지면 그것을 가리키는 부모들은 전부 next 를 0 으로 갱신해야함
자식도 부모를 가르키도록 하는 포인터가 있으면 된다.




// 네 귀퉁이가 모두 색칠되어 있는 경우의 수 : 색칠된 칸의 중복이 없어야 함.
long long sol = 0;
for (int i = 0; i < n; ++i)
	for (int j = i+1; j < n; ++j) {		// i, j 두 행을 선택
		long long count = 0;
		for (int k = 0; k < n; ++k) {
			if (color[i][k] == 1 && color[j][k] == 1)
				count++;
		}
		sol += count * (count - 1) / 2;
	}
		


long long sol = 0;
bitset<1010> board[1010];	// board[0]: 0행, board[1]: 1행
for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j) {	// 
		long long count = (board[i] & board[b]).count();
		sol += count * (count - 1) / 2;
	}




https://codeforces.com/contest/1183/problem/E // Round #570(div3)
E. Subsequences (easy version)
글자의 길이랑 찾는 서브셋 수 (1 <= n, k <= 100)
서브셋 하나를 찾을때 비용 글자에서 빠지는 문자의 수(길이차가 됨)
//input
4 5
asdf
//output
4		// asdf, asd, adf, asf, sdf

//input
5 6
aaaaa
//output
15

//input
5 7
aaaaa
//output
-1

//input
10 100
ajihiushda
//output
233
https://codeforces.com/contest/1183/submission/56112548 // JKJeong 31ms
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	ll ans = 0;
	queue<string> q;
	unordered_map<string, bool> chk;
	q.push(s), chk[s] = true;
	while (!q.empty() && k) {
		s = q.front(); q.pop();
		ans += n - s.size();
		k--;
		for (int i = 0; i < s.size(); ++i) {
			string t = s.substr(0, i) + s.substr(i + 1);
			if (!chk[t]) {
				chk[t] = true;
				q.push(t);
			}
		}
	}
	if (k == 0) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}

복잡도 : 100개의 문자열을 하나의 노드로 칠때 노드당 간선은 최대 100개 임. 100 * 100 을 전체 간선으로 잡으면 복잡도는 O(E)= 100000
거기에 map 에서 비교하는 부분에서 오버헤드가 좀 있다만 그래봐야 100만이 안됨



https://codeforces.com/contest/1181/problem/C  // Round #567 (div2)
C. Flag // solved 1694명
for 문을 슬기롭게 짜야 하는 문제..
세 색상이 다르고 (처음과 끝은 같아도 됨. 경계만 달라야 함) 높이가 같은 경우의 수를 찾는 문제
// input
4 3
aaa
bbb
ccb
ddd
// output
6
// n, m 은 (1 <= n, m <= 1000) 이다. 답이 3중 for문이면 복잡도 10억이다. 6억정도면 통과한다. (시간을 2초 줬다.)
// 내가 이런 문제에 약할줄이야.. 복잡도 계산을 먼저 했으면 어땠을지 아쉬움이 든다.
https://codeforces.com/contest/1181/submission/55630739 // chemthan
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
void solve() {
	int n, m; cin >> n >> m;
	vector<string> board(n);
	for (int i = 0; i < n; ++i) cin >> board[i];
	vvi nxt(n, vi(m));
	for (int j = 0; j < m; ++j)
		for (int i = n - 1; i >= 0; --i) {
			nxt[i][j] = i;
			if (i + 1 < n && board[i][j] == board[i + 1][j])
				nxt[i][j] = nxt[i + 1][j];
		}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; i + 3 * j - 1 < n; ++j) {
			int cnt = 0;
			vi pv(3, -1);
			for (int k = 0; k < m; ++k) {
				if (nxt[i][k] == i + j - 1 && 					// 윗 깃발색이 길이를 만족
					nxt[i + j][k] == i + j + j - 1 && 			// 가운데 깃발색이 길이를 만족
					nxt[i + j + j][k] >= i + j + j + j - 1) {	// 밑 깃발색이 길이를 만족
					if (pv[0] == board[i][k] && pv[1] == board[i + j][k] && pv[2] == board[i + j + j][k]) {
						// 만족하는 길이의 색상이 이전과 같으면
						cnt++;
					}
					else {	// 앞에 형성된 깃발과 다른 경우
						res += (long long)cnt * (cnt + 1) / 2;
						cnt = 1;
					}
					pv[0] = board[i][k];
					pv[1] = board[i + j][k];
					pv[2] = board[i + j + j][k];
				}
				else {	// 깃발 형성을 못한 경우
					res += (long long)cnt * (cnt + 1) / 2;
					cnt = 0;
					for (int& x : pv) x = -1;
				}
			}
			res += (long long)cnt * (cnt + 1) / 2;
		}
	}
	cout << res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); // !!!!!!!! 있으면 561ms 걸림 주석 처리하면 686ms 걸림. 여기 설정하면 하위 함수단에도 계속 이어지는 구나...
	solve();
	return 0;
}


https://www.codingame.com/ide/puzzle/the-hooch-clash-grouch : 숫자의 범위가 주어짐
범위 1 ~ 100000 // a, b
갯수 3500개
중복되지 않는 수 네개를 골라서 a^3 + b^3 == c^3 + d^3 을 이루는 경우의 수를 구한다. 그때의 a^3 + b^3 을 vol 이라 하는데
이것의 종류도 출력해라.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
void solve() {
	int n, m; cin >> n >> m;
	vector<ll> arr;
	for (int i = n; i <= m; ++i)
		for (int j = i + 1; j <= m; ++j) {
			long long vol = (ll)i * i * i + (ll)j * j * j;
			arr.push_back(vol);
		}
	sort(arr.begin(), arr.end());
	ll v = 0, c = 0;
	ll pv = -1;
	ll cnt = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (pv == arr[i]) {
			cnt++;
		}
		else {
			if (cnt >= 2) {
				v++;
				c += cnt * (cnt - 1);	// 2개를 선택 (순서 존재)
			}
			pv = arr[i];
			cnt = 1;
		}
	}
	if (cnt >= 2) {
		v++;
		c += cnt * (cnt - 1);
	}
	cout << v << " " << c;
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); 
	solve();
	return 0;
}
"타임 오버 뜨는데 문제가 잘못된거임" vector<long long> 를 long long arr[16000000] 으로 바꾸어 풀면 통과함...







https://codeforces.com/contest/1194/problem/B : //Educational Codeforces Round 68 (Rated for Div. 2)
B. Yet Another Crosses Problem
n * m 은 400000 이하임
// 가로줄과 세로줄 채우기된 것을 위해 * 이 최소 몇개 필요한가
inputCopy
9
5 5
..*..
..*..
*****
..*..
..*..
3 4
****
.*..
.*..
4 3
***
*..
*..
*..
5 5
*****
*.*.*
*****
..*.*
..***
1 4
****
5 5
.....
..*..
.***.
..*..
.....
5 3
...
.*.
.*.
***
.*.
3 3
.*.
*.*
.*.
4 4
*.**
....
*.**
*.**
outputCopy
0
0
0
0
0
4
1
1
2


 #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
vector<string> board;
int main() {
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		board = vector<string>(n);
		for (int i = 0; i < n; ++i) cin >> board[i];
		vector<pair<int, int>> row(n), col(m);
 
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int j = 0; j < m; ++j)
				if (board[i][j] == '.')
					cnt++;
			row[i] = make_pair(cnt, i);
		}
 
		for (int j = 0; j < m; ++j) {
			int cnt = 0;
			for (int i = 0; i < n; ++i)
				if (board[i][j] == '.')
					cnt++;
			col[j] = make_pair(cnt, j);
		}
 
		sort(row.begin(), row.end());
		sort(col.begin(), col.end());
 
		int sol = 10000000;
		for (int i = 0; i < row.size(); ++i) {
			for (int j = 0; j < col.size(); ++j) {
				int cand = row[i].first + col[j].first; // 필요한 * 갯수
				if (board[row[i].second][col[j].second] == '.') // 만약 cross 되는 곳에 '.' 이면 하나만 * 더하면 되므로
					cand--;
				if (cand < sol)
					sol = cand;
			}
		}
		cout << sol << '\n';
 
	}
	return 0;
}

// 좀더 간단하게 짤수 있다. !!!!!!!! 반성하자
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>
#define rep(i,a) for (int i = 0; i < (a); ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		vector<string> board(n);
		for (int i = 0; i < n; ++i) cin >> board[i];
		vi r(n), c(m);
		rep(i, n) rep(j, m) if (board[i][j] == '*') r[i]++, c[j]++;
		int sol = 987654321;
		rep(i, n) rep(j, m) {
			int need = (n + m - 1) - (r[i] + c[j] - (board[i][j] == '*'));
			if (sol > need)
				sol = need;
		}
		cout << sol << '\n';
	}
	return 0;
}





https://codeforces.com/contest/1194/problem/D : //Educational Codeforces Round 68 (Rated for Div. 2)
D. 1-2-K Game
// 1, 2, K칸을 갈수 있다. alice 가 먼저 시작하며 더이상 갈수 없을때 진다.
inputCopy
4
0 3	// n, k: 0번 칸에서 앨리스가 시작하므로 앨리스가 진다.
3 3	// 3번칸에서 앨리스가 시작하며 3칸 이동하면 bob이 0번 칸이 됨
3 4	// 앨리스는 1칸 , 2칸 이동을 한들 밥이 승리함(4칸 이동은 못함)
4 4
outputCopy
Bob
Alice
Bob
Alice

// 이런 유형은 작은거 부터 하나 하나 규칙성을 찾는게 답이다.
1, 2, k

// k가 없는 경우 부터 생각하자.
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
b	a	a	b	a	a	b	a	a	b	a	a	b	a	a	b	a	a	b	a

// 특징이 나옴: b와 a가 교차해서 점프가 가능한지 체크한다.!!!!!!!! (왜 그렇는지 고찰하라)
// a의 승리를 기준으로 한다: b는 !a임
// a에서 점프해서 b를 만나도록 할수 있으면 됨. 못만나면 그놈은 b가 됨
// 기저는 b로 시작함


k가 3인 경우
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
b	a	a	a	b	a	a	a	b	a	a	a	b	a	a	a	b	a	a	a


k가 4인 경우
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
b	a	a	b	a	a	b	a	a	b	a	a	b	a	a	b	a	a	b	a

k가 5인 경우
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
b	a	a	b	a	a	b	a	a	b	a	a	b	a	a	b	a	a	b	a

k가 6인 경우
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
b	a	a	b	a	a	a	b	a	a	b	a	a	a	b	a	a	b	a	a


k가 3의 배수인 경우 주기는 k + 1이 된다.

k가 9인 경우 주기는 10이 된다. 마지막은 a임
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
b	a	a	b	a	a	b	a	a	a	b	a	a	b	a	a	b	a	a	a

특징
k가 3의 배수가 아닌 경우
baa 를 반복함
k가 3의 배수인 경우
baa 반복하다가 k번째(0base) 에서 a가 된다. (주기는 k + 1)

if (k % 3 == 0) {
	n = n % (k + 1);
	if (n == k)
		cout << a;
	else if (n % 3 == 0)
		cout << b;
	else
		cout << a;
} else {
	if (n % 3 == 0)
		cout << b;
	else
		cout << a;
}
// 통과함
#include <iostream>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        if (k % 3 == 0) {
            n = n % (k + 1);
            if (n % (k + 1) == k)
                cout << "Alice";
            else if (n % 3 == 0)
                cout << "Bob";
            else
                cout << "Alice";
        } else {
            if (n % 3 == 0)
                cout << "Bob";
            else
                cout << "Alice";
        }
        cout << '\n';
    }
    return 0;
}




프로그래머스 챌린지 첫번째 4번 문제
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod = 10000000 + 19;
int bino[305][305];
//필요한 모든 이항계수를 미리 계산해 둔다. //파스칼 삼각형 조합  !!!!
void calcBino() {
    memset(bino, 0, sizeof(bino));
    for (int i = 0; i <= 303; ++i) {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; ++j)
            bino[i][j] = min(mod, bino[i - 1][j - 1] + bino[i - 1][j]);
    }
}
long long nCr(long long n, long long r) {
    return bino[n][r];
}

int solution(vector<vector<int>> a) {
    calcBino();
    vector<long long> oneCntArr(a[0].size(), 0);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[0].size(); ++j)
            if (a[i][j] == 1)
                oneCntArr[j]++;
    int row = a.size();
    long long dp[303][303];
    memset(dp, 0, sizeof(dp));
    dp[oneCntArr[0]][0] = nCr(row, oneCntArr[0]) % mod; // nCr 무지 큰거 구한후 
    
    for (int there = 1; there < oneCntArr.size(); ++there) {
        for (int i = 0; i <= row; ++i) {
            int j = oneCntArr[there];
            long long num = i;  // prev 에서 홀수 1의 값
            long long rrr = j;  // 현재 열에서 1의 추가 갯수
            if (num < rrr)
                swap(num, rrr);
            long long sum = 0;
            long long r = 0;
            // 비둘기 집 원리로 최소한 num + rrr - row 만큼은 중첩이 일어남을 고려
            if (num + rrr > row)
                r = num + rrr - row;
            for (; r <= rrr; ++r) {
                sum += nCr(num, r);
                sum %= mod;

                int hereColOneCnt = (num + rrr - (r * 2));
                dp[hereColOneCnt][there] += sum;
                dp[hereColOneCnt][there] %= mod;
            }
        }

    }
    int answer = dp[0][oneCntArr.size() - 1];
    return answer;
}



// immediate window(직접 실행창) 출력용
vector<string> debug2DVector(vector<vector<int>>& board) {
    vector<string> ret;
    int maxLenEle = 0;
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j) {
            string str = to_string(board[i][j]);
            maxLenEle = max(maxLenEle, (int)str.size());
        }
    for (int i = 0; i < board.size(); ++i) {
        string str;
        for (int j = 0; j < board[0].size(); ++j) {
            string ele = to_string(board[i][j]);
            str.append(ele);

            int blankCnt = maxLenEle - ele.size() + 2;
            for (int k = 0; k < blankCnt; ++k)
                str.push_back(' ');
            
        }
        ret.push_back(str);
    }
    return ret;
}




qp2)
소수 구하기

qp3)
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cmath>
#include <functional>
#include <memory.h>
#include <stack>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstdio>
#include <bitset>
typedef long long ll;
#define rep(i,a) for (int i = 0; i < (a); ++i)
using namespace std;
const int INF = 987654321;

const int boardSZ = 16;
vector<int> graph[boardSZ];
bool vstd[boardSZ];
bool vstd2[boardSZ];
const int dy[4] = { 1, 0, 0, -1 };
const int dx[4] = { 0, 1, -1, 0 };

int selLength;
int selNode;

void clearGraph() {
	for (int i = 0; i < boardSZ; ++i) graph[i].clear();
}

void makeGraph(const vector<vector<int>>& board, int target) {
	clearGraph();
	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board[0].size(); ++j) {
			if (board[i][j] != target) continue;
			int u = i * 4 + j;
			if (u > 15)
				break;
			for (int k = 0; k < 4; ++k) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
				if (board[ny][nx] != target) continue;
				int v = ny * 4 + nx;
				graph[u].push_back(v);
			}
		}
}
void dfs(int prev, int cur, int length) {
	//cout << cur << '\n';
	vstd[cur] = true;
	vstd2[cur] = true;		// 한번 수행한 forest는 제외하기
	if (length > selLength) {
		selLength = length;
		selNode = cur;
	}
	for (int i = 0; i < graph[cur].size(); ++i) {
		int nxt = graph[cur][i];
		if (vstd[nxt] == true) continue;
		dfs(cur, nxt, length + 1);
	}
	vstd[cur] = false;
}
int localSolution(const vector<vector<int>>& board, int target) {
	makeGraph(board, target);
	int sol = 0;
	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board[0].size(); ++j) {
			if (board[i][j] == target) {
				// 트리의 지름 찾기: 임의의 노드에서 가장 먼 노드를 찾고 거기서 다시
				// 가장 먼 노드를 다시 찾으면 트리의 지름이다.
				selLength = 0;
				selNode = -1;
				int start = i * 4 + j;
				if (start == 5 || start == 6 || start == 8 || start == 9 || start == 11 || start == 13 || start == 14 || start == 15)
					start = start;
				if (vstd2[start] == true) continue;
				dfs(-1, start, 1);
				int start2 = selNode;
				dfs(-1, start2, 1);
				sol = max(sol, selLength);
			}
		}
	return sol;
}
int solution(vector<vector<int>> board) {
	int sol = 0;
	for (int i = 0; i < board.size(); ++i) for (int j = 0; j < board[0].size(); ++j) board[i][j]--;
	for (int i = 0; i < 4; ++i) {
		int cand = localSolution(board, i);
		sol = max(sol, cand);
	}
	if (sol == 1) sol = -1;
	return sol;

}
int main() {
	//vector<vector<int>> board = { {4,2,3,2}, {2,1,2,4}, {1,2,3,1}, {4,1,4,3} };
	//vector<vector<int>> board = { {3,2,3,2}, {2, 1, 1,2}, {1, 1, 2, 1}, {4, 1, 1, 1} };
	//vector<vector<int>> board = { {1,1,1,2}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1} };
	//vector<vector<int>> board = { {1,1,1,1}, {1, 1, 1, 1}, {1, 2, 2, 1}, {1, 1, 1, 1} };
	//vector<vector<int>> board = { {1,2,1,2},{1,2,2,2}, {2,2,1,2}, {2,2,2,2} };
	vector<vector<int>> board = { {3,2,2,2},{2,1,1,3}, {2,1,3,3}, {1,2,2,2} };
	int tmp = solution(board);

	return 0;
}