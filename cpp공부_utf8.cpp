1. 다이나믹 링킹 / 정적 링킹 차이점 (Dll) 컴파일 할때 파일을 합침 / 프로그램을 실행 할때 합쳐짐
2. map / list 차이점 / STL구조 //
3. list / vector 차이점
4. TCP / IP 서버랑 클라이언트 차이점 // Bind Listen Accept
5. 오버로딩 / 오버라이딩 // 함수 중복, 함수 재정의
6. Vitual 함수 // 실제 포인터가 가르키는 함수를 동적으로 바인딩
7. Vital함수 호출
8. encapsulation
9. 소멸자 virtual
10. 바이너리 서치
11. 퀵정렬
12. 디자인패턴
13. 데이터 영역, 힙, 스택
14. 가장자신있는점
15. 더블버퍼링
16. 댕들링 포인터
17. dc쪽
18. 쓰레드
19. precompiler 원리
20. utf-8 utf-16 멀티바이트
21. 자바 C++ 차이점
22. 람다 함수
23. 나중에 어떤 일
24. 트러블 슈팅 해결
25. 스마트 포인터
26. Dynamaic Cas


<<< 검색 팁 >>>
if [-f &debug_file]; then			// 검색을 구글에서 bash shell -f 로 했다.
	ret=$(exec touch $debug_file)	// 허나 그럼 안된다. -f 는 f를 검색에서 제외한단 말임
fi

// 위의 [-f &debug_file]뜻은 bash shell 에서 파일이 존재하는지 체크하는 것이다. 
// 검색을 이렇게 하면 나옴 bashshell file exists



<<<< 잡다. 빌드 >>>>

https://bowbowbow.tistory.com/12

make & Makefile 이란
Makefile 이 있는 디렉토리에서 make 만 치면 컴파일이 실행된다. how?
make는 파일 관리 유틸리티 이기 때문
	파일간의 종속관계를 파악하여 Makefile(기술파일)에 적힌 대로 컴파일러에 명령하여 SHELL 명령이 순차적으로 실행될 수 있게 함.
		"종속관계" 가 중요.


<<<<<<<<Fundamental c++ 프로그래밍 원리>>>>>>>>

/*---------------- 1장 타입 -------------------*/
1.5.3 문자열 타입 변환
void Func(const char* str) {
	cout << "const char*" << endl;
}
void Func(char* str) {
	cout << "char*" << endl;;
}
void main() {
	Func("Hello World");	// 먼저 Func(const char* str) 을 선택함, 그게 없으면 Fun(char* str)로 선택됨
}

1.7.2 우측 값 참조(RVaule Reference)
식이 끄났을 때도 지속되는 객체를 lvalue 라 하고
"유지되지 않는 임시 값을 rValue 라고 한다!!!!!!!!"
쉽게 얘기한다면 모든 변수는 lvalue 다.
아래는 vs2015에서 실행되었다.
int GetValue() {
	int a = 1;
	return a;
}
int& GetReference() {
	int a = 2;
	return a;		// 비록 a가 임시객체지만 vs2015 는 허용하네.. 경고는 뜸.
}
void Func(int& arg) {
	cout << "LValue" << endl;
}
void Func(int&& arg) {
	cout << "RValue" << endl;
}

int main() {
	Func(1);			// RValue
	int a = 1;
	Func(a);			// LValue 출력

	Func(GetValue());		// RValue
	Func(GetReference());	// LValue
	return 0;
}
"우측 값 참조는 주로 클래스의 복사 생성자와 복사 대입 연산자에 사용되어서 메모리 사용 효율을 높이는데 쓰임"

1.8 typedef
유효범험가 존재한다. 전역적으로 정의했을때는 모든곳에서 쓸수 있지만 "함수 안에서 정의시 함수내에서만 사용됨"

배열 혹은 함수 포인터의 정의방법이 햇갈린다. 그건 원래 원칙을 기억해야 함.
배열 예시
1단계: int arr[3];			// 배열을 선언
2단계: typedef int arr[3];	// 앞에 typedef 를 붙인다.
3단계: typedef int ARRAY_INT_THREE[3];	"객체이름을 타입이름으로 변경한다."

함수 포인터 예시
1단계: double (*func)(int arg1, int arg2);
2단계: typedef double (*func)(int arg1, int arg2);
3단계: typedef double (*FUNCTYPE)(int arg1, int arg2);

1.9 auto 
auto 는 초기화식 없이 선언될 경우 타입을 추론 불가능!!!!
따라서 초기화식이 존재하지 않는 경우인 멤버 변수와 함수의 인자에는 사용 불가.
참고로 auto는 오직 "비 참조 타입"으로만 추론된다. // 참조는 auto& 를 붙여야 함.

int& GetRef(int& arg) {
	return arg;
}
void main() {
	int a = 1;
	auto b1 = GetRef(a);	// auto->int
	auto& b2 = GetRef(a);	// auto&->int&
	
	b1++;	// a = 1 그대로임
	b2++;	// a = 2가 된다.
}


/*---------------- 2장 선언과 정의 -------------------*/
"정의란 어떤 대상이 실제로 존재할 수 있도록 자리(메모리 영역)를 만들어주는 작업이다."
	전역객체: 데이터 영역의 메모리 공간을 차지한다.
	지역객체: 스택의 메모리 공간을 차지한다.
	함수: 함수 본체를 어셈블리로 변경하고, 변경된 어셈블리는 코드 영역에 저장된다.
"but 클래스의 경우 정의 개념이 달라진다. 이것은 컴파일러가 사용하는 설계도일 뿐이다."
	클래스 설계가 저장되는 메모리는 실제 프로그램이 사용하는 메모리와는 전혀 관련이 없다.
	클래스의 설계도가 저장되는 메모리 영역은 프로세스와는 상관 없는 컴파일러가 사용하는 메모리인 것이다.

일반적인 객체와 함수들의 경우 정의에 의해서 할당되는 메모리는 가상메모리이지만, 
클래스의 경우는 정의에 의해서 할당되는 메모리는 컴파일러가 사용하는 메모리이다.


2.1.2 선언
"정의는 선언을 포함한다"
//A.cpp
int g_Val;
int Func() {
	return 1;
}

// Main.cpp
void main() {
	g_Val = Func();		// Compile Error	// 선언이 적용된 범위가 A.cpp 뿐이다.
}

즉 이렇게 해야 한다. !!!!!!!!
// Main.cpp
extern int g_Val;	// 선언
int Func();			// 선언
void main() {
	g_Val = Func();
}

// 만약 main 에도 g_Val, Func 를 정의해주면 우짜되는가? 링크 단계에서 중복정의 에러가 난다.
"어떤 소스(cpp) 파일에서 정의를 할 경우 해당 소스 파일에 대해서는 선언까지 자동으로 이루어진다."
"그러나 다른(cpp) 파일에서 이미 정의된 객체를 사용하고자 할 경우에는 순수하게 선언만 해주어야 한다"
"만일 정의를 중복으로 하게 될 경우 링크 에러가 발생한다"

2.1.3 extern & static
local 은 지역 객체이고, 비 local 의 경우
	모든 범위에서 사용될수 있는 전역 객체: extern
	한정된 사용 범위를 가지는 정적 객체: static
	
extern 의 좆같음을 잘 나타낸 페이지 p88. 이래서 햇갈릴수 밖에 없었넹... ㅅㅂ
int g_Val;				// (1) A.cpp - 정의 // 당연히 int g_Val = 1 도 정의가 된다.
extern int g_Val;		// (1) B.cpp - 선언


int g_Val;				// (2) A.cpp - 중복 정의
int g_Val;				// (2) B.cpp - 중복 정의


extern int g_Val = 1;	// (3) A.cpp - 정의
extern int g_Val;		// (3) B.cpp - 선언


extern int g_Val = 1;	// (4) A.cpp - 중복 정의
extern int g_Val = 2;	// (4) B.cpp - 중복 정의


extern int g_Val;		// (5) A.cpp - 선언
extern int g_Val;		// (5) B.cpp - 선언


"정리하자면" 
	extern 이 없는 변수는 정의된 거임. extern 이 초기화와 함께 있어도 정의임
	"extern 이 정의에 사용될 경우에는 객체의 초기화가 이루어질수 있다."
	"extern 이 선언으로 사용될 경우에는 절대로 초기화가 이루어질 수 없다."
	
	
[소스 2-6] extern & static
// A.cpp
extern int g_Val = 0;	// 밑에 static 과 대비하기 위해 extern 변수를 넣은거임. extern 생략해도 extern 취급 됨
static int s_Val = 0;


// Main.cpp
extern int g_Val;
extern int s_Val;
void main() {
	g_Val = 1;	// ok
	s_Val = 2;	// Link Error
}


extern 의 의미는 정의에 사용될 경우 다른 소스(cpp) 파일에서도 사용 가능하도록 링크를 허용 하는 것이고,
static 의 경우 다른 소스(cpp) 파일에서는 사용할 수 없도록 링크를 허용하지 않는 것을 의미한다.


2.1.4. 클래스 선언과 정의
"컴파일러는 오직 소스파일(CPP) 단위로만 독립적으로 컴파일을 한다.

// MyClass.h
class MyClass {
public:
	int a, b;
	int sum(int a, int b);
	int sub(int a, int b);
};
// MyClass1.cpp
#include "MyClass.h"
int MyClass::sum(int a, int b) {
	return a + b;
}
// MyClass2.cpp
#include "MyClass.h"
int MyClass::sub(int a, int b) {
	return a - b;
}
// Main.cpp
#include "MyClass.h"
int main() {
	MyClass ttt;
	int subV = ttt.sub(3, 9);
	int sumV = ttt.sum(3, 9);
	cout << subV << " " << sumV;
}
// 빌드를 3개 함을 확인할 수 있다. cpp 파일 단위
1>  MyClass1cpp
1>  source.cpp
1>  MyClass2.cpp


[소스 2-8] 클래스 선언과 정의
// A.cpp
int g_Val;		// (1) 변수 정의
class CTest {	// (2) 클래스 정의: 정의라기 보다 설명서로 해석하자. 크기를 알기 위해 쓰임
public:
	int m_Val;
};

// Main.cpp
extern int g_Val;		// (3) 변수 선언
class CTest;			// (4) 클래스 선언

void main() {
	g_Val = 1;			// ok
	CTest t;			// compile error
	t.m_val = 1;		// compile error
}


기본자료형은 크기를 알고 있다. 
	Main.cpp 컴파일시 g_Val 의 경우 어셈블리로 특정 기준 주소에서 4Byte 영역을 1로 채우는 코드를 작성한다.
	그리고 링크 단계에서 특정 기준 주소를 실제 g_Val이 위치하는 주소로 변경하면 된다.
	
허나 CTest 객체의 경우 Main.cpp 에서 사이즈를 알수 없기에 문제가 된다. 
	"컴파일은 오직 소스파일(cpp) 단위로만 독립적임을 기억하라!!!!!!!!"	
	"즉 크기를 알기 위해서 Main.cpp 에도 설명서가 필요하다."

설명서를 중복으로 작성하면 되구나. 헌데 그럴경우 실수하는 점 아래에서 확인
// A.cpp
class CTest {
public:
	CTest(int a, int b) {
		m_ValA = a;
		m_ValB = b;
	}
	int m_ValB;			// 1이 세팅되어 있음
	int m_ValA;			// 2가 세팅되어 있음
};
extern CTest g_Test;		// 선언으로 보자. (기본 자료형 기준)

int GetValueA() {
	return g_Test.m_ValA;
}

// Main.cpp
class CTest {
public:
	Ctest(int a, int b) {
		m_ValA = a;
		m_ValB = b;
	}
	int m_ValA;
	int m_ValB;
};
CTest g_Test(1, 2);		// 정의로 보자 (기본 자료형 기준) m_ValA = 1, m_ValB = 2 가 세팅됨
int GetValA();
void main() {
	cout << GetValA();	// 2가 출력된다.
}




// 참고로 CTest(int a, int b) 함수가 달라도 빌드는 된다. ㅅㅂ
// A.cpp
class CTest {
public:
	CTest(int a, int b) {
		m_ValA = a;
		m_ValB = b;
	}
	int m_ValB;
	int m_ValA;
};
extern CTest g_Test;
int GetValA() {
	CTest ttt(5, 6);	"생성자가 현재 파일을 참고하지 않더라. 이건 미정의 인건지.. main 쪽의 생성자로 간다."
	return g_Test.m_ValA;	// 클래스의 두번째 위치의 멤버를 참고한다.
}

// Main.cpp
#include <iostream>

using namespace std;
class CTest {
public:
	CTest(int a, int b) {
		m_ValA = a;
		m_ValB = b;
		m_ValB = 3;		// A.cpp 와 동일 함수의 내용이 달라도 빌드가 된다. ㅅㅂ 
	}
	int m_ValA;
	int m_ValB;
};
CTest g_Test(1, 2);

int GetValA();
int main() {
	//cout << g_Test.m_ValB;
	cout << GetValA();
	CTest ttt(3, 4);
	return 0;
}

"멤버 변수의 이름은 오직 오프셋 계산을 위해서임"
"클래스 설계도(크기를 알수 있는 부분이 정의된)를 여러군데서 작성하면 위험. include 하자"
같은 이름의 클래스가 정의되는 경우 보통은 정의가 완전히 다르기에 런타임 에러가 발생해서 오류를 찾을수 있겠지만..
"같은 라이브러리를 버전이 서로 다른것이 혼합되어 있는 경우 문제 찾기 졸라게 어렵게 된다." 조심조심

명언:
	클래스 이름이 중복되지 않도록 가능하면 이름을 단순하지 않게 지어라
	가장 좋은 방법은 namespace 를 사용하여 원천적으로 이름 중복 발생을 막아라
	라이브러리를 사용할 경우에는 항상 같은 버전만 사용되도록 프로젝트 관리에 신경 쓰라.





<<<<<<<< cpp 문법 >>>>>>>>
전방선언의 장점
전방선언 궁금증: 어떻게 빌드 비용이 줄어드는가?
// big.h
pragma once
class CBig {
public:
	int m_valB;
	int id;
	int add(int a, int b); // 1)추가해봄: small.cpp, big.cpp, 소스(main).cpp 3개 재빌드됨
};
// big.cpp			// 무조건 만드는게 좋다. : obj 를 생성함. 함수 구현부를 여기에 넣으면 됨
#include "big.h"	// big.cpp 파일만 생성해도 big.o 는 만들어진다넹
int CBig::add(int a, int b) { //2)추가해봄: big.cpp만 재빌드
	return a + b;
}

// small.h
#pragma once
class CBig;		// 전방선언을 한다.
class CSmall {
public:
	CSmall();
	int m_valS;
	CBig* m_pBig;
	int id;		// 3) 추가해봄: small.cpp, 소스.cpp 재빌드됨
};
// small.cpp
#include "small.h"
#include "big.h"
CSmall::CSmall() {
	m_pBig = new CBig;
	int tmp = 10;	// 4) 추가해봄: small.cpp 재빌드됨
}

// 소스.cpp
#include "small.h"
#include "big.h"
int main() {
	CSmall a;
	CBig b;
	return 0;
}

// 소스 변경시 재빌드되는게 무엇인지 알수가 있어용
project 속성페이지 -> 구성속성 -> c/c++ -> 고급 -> 포함 표시 : "예(/showIncludes)"!!!!!!!!

big.h 가 변경 ex: int add(int a, int b); // 1)추가해봄
	1>small.cpp	// obj 가 새로 생성됨
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\small.h
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\big.h
	1>big.cpp		// obj 가 새로 생성됨
	1>소스.cpp		// obj 가 새로 생성됨
	
big.cpp 가 변경 ex: 아래 구문 추가
	int CBig::add(int a, int b) {	//2)추가해봄
		return a + b;
	}
	1>big.cpp	// obj 가 새로 생성됨
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\big.h

small.h 가 변경 ex: int id;		// 3) 추가해봄
	1>small.cpp	// obj 가 새로 생성됨
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\small.h
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\big.h
	1>소스.cpp		// obj 가 새로 생성됨

small.cpp 가 변경 ex: int tmp = 10;	// 4) 추가해봄
	1>small.cpp	// obj 가 새로 생성됨
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\small.h
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\big.h

// 여기까진 small.h 에 그냥 include "big.h" 하는거랑 뭔 차이가 있냐 싶었다. 
// 왜냐면 변경시 같은 obj들이 새로 생성되기 때문이다. (big.h 를 변경시 big.cpp, small.cpp, 소스.cpp 가 모드 재빌드됨)
"허나 잘 봐라" small.h 를 다른 곳 aa.h, bb.h, cc.h에서 include 한다면 어찌 되겠는가?	// 모두들 aa.cpp, bb.cpp, cc.cpp 가 존재함
	big.h 가 변경되더라도 small.h 는 big.h 에 의존성이 없다.		// 단지 big 클래스를 실제로 사용하는 small.cpp 만 재빌드 될뿐이다.
	small.h 의 내용이 바뀌더라도, aa.cpp, bb.cpp, cc.cpp 가 새로 빌드될 일은 없다. !!!!!!!! 핵심임. 
	1>CSmall.cpp
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\small.h
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\big.h
	1>big.cpp
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\big.h
	1>소스.cpp
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\small.h
	1>참고: 포함 파일: C:\Users\bruce.s.choi\source\repos\Project4\Project4\big.h








<<<< 윈도우즈 공부 >>>>
메모리 할당량 정책
https://www.viva64.com/en/k/0036/
How much memory can an application access in Win32 and Win64?

When developing a software product for a Windows-family operating system, 
you must keep in mind the restrictions imposed on sizes of data a program can declare and use. 
Windows imposes the following 3 types of restrictions on applications:

1. Static data. The restriction is imposed on the size of the program source code itself 
and the size of statically allocated memory. In C++, such data is usually represented by 
global variables defined by outside procedures. 
The restriction concerning the size of statically allocated memory is 2 Gbytes 
both for 32-bit and 64-bit programs.
정적 데이터. 프로그램 소스 코드 자체의 크기와 정적으로 할당 된 메모리의 크기에 제한이 있습니다. 
C ++에서 이러한 데이터는 일반적으로 외부 프로 시저에 의해 정의 된 전역 변수로 표시됩니다. 
정적으로 할당 된 메모리의 크기에 대한 제한은 32 비트 및 64 비트 프로그램 모두 "2GB"입니다.


2. Dynamic data. This is data for which memory is being allocated while executing the program. 
In C++, this allocation is usually performed by the malloc function or new operator. 
In 32-bit programs the size of dynamically allocated memory is restricted to 2 Gbytes, 
in 64-bit programs to 8 Tbytes.
동적 데이터. 프로그램을 실행하는 동안 메모리가 할당되는 데이터입니다. C ++에서이 할당은 일반적으로 malloc 함수 또는 
new 연산자에 의해 수행됩니다. 32 비트 프로그램에서 동적으로 할당 된 메모리의 크기는 "2GB"로, 64 비트 프로그램에서 "8TB"로 제한됩니다.


3. Stack data. Memory is allocated for this data when entering a procedure, and is released
 after exiting the procedure. The maximum size of program stack is 1 Gbyte for both 
 32-bit and 64-bit applications. (The stack size is defined by the linker and is 1 Mbyte by default)
스택 데이터. 프로 시저를 시작할 때이 데이터에 메모리가 할당되고 프로 시저를 종료 한 후 해제됩니다. 
프로그램 스택의 최대 크기는 32 비트 및 64 비트 응용 프로그램 모두에서 "1GB"입니다. 스택 크기는 링커에 의해 정의되며 기본적으로 "1MB"입니다.


For a 32-bit application launched in a 32-bit Windows, the total size of 
all the mentioned data types must not exceed 2 Gbytes. 
(Actually it is 1.75 Gbytes due to memory requirements of the operating system itself). 
A 32-bit program compiled with the switch /LARGEADDRESSAWARE:YES can allocate up to 3 Gbytes of memory 
if the 32-bit Windows is launched with the /3gb switch. 
The same 32-bit program launched in a 64-bit system can allocate about 4 Gbytes 
(actually about 3.5 Gbytes).
32 비트 Windows에서 시작된 32 비트 응용 프로그램의 경우, 언급 된 모든 데이터 유형의 총 크기는 2GB를 초과하지 않아야합니다. 
(실제로는 운영 체제 자체의 메모리 요구 사항으로 인해 1.75GB입니다). 
/LARGEADDRESSAWARE : YES 스위치로 컴파일 된 32 비트 프로그램은 /3gb 스위치를 사용하여 
32 비트 Windows를 시작하는 경우 최대 3GB의 메모리를 할당 할 수 있습니다. 
64 비트 시스템에서 시작된 동일한 32 비트 프로그램은 약 4GB (실제로 약 3.5GB)를 할당 할 수 있습니다.




















