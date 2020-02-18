------- 27장 --------

다중그래프(multigraph) : 두 정점 사이에 두개 이상의 간선
단순그래프(simple graph) : 두 정점 사이에 최대 한개의 간선
트리 혹은 루트없는 트리(unrooted tree) : 부모 자식 관계가 없을 뿐,
  간선들의 연결 관계만 보면 트리와 같은 무향 그래프를 말함
  간선들의 연결관계가 트리와 같다는 말은, 
  간선을 통해 두 정점을 잇는 방법이 딱 하나빡에 없다는 의미가 된다
이분그래프(bipartite graph) : 그래프의 정점들을 겹치지 않는 두 개의 그룹으로 나눠서
  서로 다른 그룹에 속한 정점들 간에만 간선이 존재
DAG(directed acyclic graph) : 방향그래프이며 한 점에서 출발해 자기 자신으로 돌아오는
  경로(사이클)가 존재하지 않는 경우를 말함,
  DAG는 여러 작업들 간의 상호 의존 관계등을 그래표로 표현할 때 흔하게 출현한다.

그래프의 경로(path)
  현대 그래프 이론에서는 경로라고 하면 대부분은 단순 경로를 의미하며,
  한 정점을 두 번 이상 지날 수 있는 경로를 이야기 할때는 별도로 이 사실을 명기하곤 함
  시작한 점에서 끝나는 경로를(cycle)혹은 회로라고 부름

그래프의 사용 예
철도망의 안정성 분석 : 어떤 철도망에서 한 역이 폐쇄되어 열차가 지나지 못할 경우
  철도망 전체가 두 개 이상으로 쪼개질 가능성이 있는지, 만약 있다면 어느 역이 그런 위험성을
  갖고 있는지 분석 할 때... 28장의 절단점 찾기 알고지름을 이용
소셜 네트워크 분석 : 사람들 간의 지인/친밀도 관계가 있음, 두 회원이 서로 친구 사이인 경우
  간선으로 연결하는 그래프를 만들었다고 하자. 29장에서 다루는 그래프의 너비 우선 탐색을
  이용하면 내가 한 다리 건너 알고 있는 사람은 몇 명이나 되는지, 몇 다리나 건너가야
  오바마와 내가 아는 사이인지 등을 쉽게 알 수 있습니다.
인터넷 전송 속도 계산 : 어쩐 경로의 시간당 전송용량은 이 경로가 지나는 케이블 중 가장
  작은 전송 용량을 갖는 케이블에 좌우된다고 합시다. 이 때 두 컴퓨터 간의 전송 용량을
  계산하는 문제를 31장에서 소개하는 최소 스패닝 트리 알고리즘을 응용해서 해결할 수 있음
한 붓 그리기 : 주어진 그래프의 모든 간선을 한 번씩만 지나는 경로를 찾는 문제가 되는데,
  이 문제는 오일러 경로(Eulerian path)라고 부르며 깊이 우선 탐색을 응용해서 해결
  28.4절 참고
외환 거래 : 어떤 사이클 간선의 가중치 곱이 1보다 크면 개이득
 //각 가중치를 로그화 한뒤 -1을 곱해라
 //그렇게 하여 간선의 가중치의 합이 음수인 사이클이 찾는 문제로 변경됨(30장 : 최단거리 알고리즘)

 암시적 그래프 구조들
 할 일 목록 정리 : 어느 순서대로 하면 되는지를 계산하는 문제를 위상 정렬(topological sorting)
   28장 깊이 우선 탐색 응용해서 풀면 됨
 15-퍼즐 : 게임판의 배치 상태를 하나의 정점으로 취급, 종료 상태로 가는 가장 짧은 경로
   를 구하는 문제로 바꾸자
 게임판 덮기 : 가로 N, 세로N칸으로 나뉘어 있는 정사각형의 게임판을 1 x 2크기의 블록으로
   덮는 문제를 생각해 봅시다. 단 게임판의 모든 칸에 블록을 놓을 수 있는 것이 아니라
   일부는 막혀 있습니다. 블록을 겹쳐서 놓을 수 없을 때, 막히지 않은 모든 칸에 블록을
   놓을 수 있는 방법이 있을까요? 게임판의 막히지 않은 각 칸을 정점으로 하고,
   상하좌우로 인접한 칸들 사이에 간선을 연결하는 그래프를 만들도록 합시다.
   32장에서 이 그래프가 사실 이분 그래프라는 것을 보이고, 이 문제를 
   해결할 수 있는 이분 매칭 알고리즘을 소개합니다.
 회의실 배정 : N개의 팀이 각각 회의를 하려고 하는데, 회의실은 하나뿐인 경우를 생각해 봅시다.
   각 팀은 회의실을 사용하고 싶은 시간을 각각 두 개씩 적어 냅니다.
   회의실은 한 번에 한 팀만 사용할 수 있으며, 한 번 시작한 회의를 중간에 끊거나
   두번에 나누어 할 수 없다고 가정합니다. 각 팀마다 적어낸 두 시간 중 하나씩을 배정해서
   모든 팀이 회희하도록 할 수 있을까요? 이와 같은 문제를 만족성 문제
   (satisfiability problem)라고 부르는데, 이렇게 모든 사람이 두 선택지 중 하나를
   선택해야 하는 문제를 2-SAT이라고 부릅니다. 28장에서 이 문제를 그래프에서의
   강 결합성 문제로 변환해서 푸는 방법을 소개합니다.
 
 ------- 28장 --------
//p827 dfs
//그래프의 인접리스트 표현
vector<vector<int> > adj;
vector<bool> visited;
void dfs(int here) {
	cout << "dfs visits " << here << endl;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}
void dfsAll() {
	visited = vector<bool> (adj.size(), false);
	for (int i = 0; i < adj.size(); ++i)
		if (!visited[i])
			dfs(i);
}

위상정렬 이해하자
1-->3-->5-->7
	   >
	  /
	 2

7 5 3 1 + 2 = 7 5 3 1 2
// reverse 하면 2 1 3 5 7 이 된다.

1-->2-->3-->5
	 \
	  >4
5 3 4 2 1 => 1 2 4 3 5

//p834 고대어 사전 문제의 그래프를 생성
//알파벳의 각 글자에 대한 인접 행렬 표현
//간선 (i, j)는 알파벳 i가 j보다 앞에 와야 함을 나타낸다.
vector<vector<int> > adj;
//주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다.
void makeGraph(const vector<string>& words) {
	adj = vector<vector<int> >(26, vector<int>(26, 0)); //!!!! 오오 이중벡터 초기화하기
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
		//word[i]가 word[j]앞에 오는 이유를 찾는다.
		for (int k = 0; k < len; ++k)
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
	}
}
//p863 깊이 우선 탐색을 이용한 위상정렬
vector<int> seen, order;
void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there)
		if (adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here);	//음.. postOrder 같아 보인다.
	"자신보다 뒷놈이 order에 다 들어간 뒤 자신이 들어감"
}
//adj로 세팅된 그래프를 가지고 위상정렬한 결과를 order에 반환한다.
// 위상정렬한 결과가 실제 위상정렬된것(DAG)인지는 다시 한번더 확인해야 한다.
//그래프가 DAG가 아니라면 빈 벡터를 반환한다.
vector<int> topologicalSort() {
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	for (int i = 0; i < n; ++i)
		if (!seen[i])
			dfs(i);
	reverse(order.begin(), order.end()); //뒤집으면 DAG가 된다. //!!!!
	//만약 정상적인 DAG가 아니라면 역방향 간선이 있게 된다.
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (adj[order[j]][order[i]])	//역방향 간선이 있는가 //!!!!
				return vector<int>();
	//없는 경우라면 DAG를 반환한다.
	return order;
}

오일러 서킷(Eulerian circuit) 모든 간선을 정확히 한 번씩 지나서 시작점으로 돌아오는 경로
//p841 깊이 우선 탐색을 이용한 오일러 서킷 찾기
//그래프의 인접 행렬 표현. adj[i][j] = i와 j사이의 간선의 수
vector<vector<int> > adj; //인접리스트는 반대쪽에서 오는 간선을 지우는 구현이 좀 까다로워서..
//무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
//결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
//(방향 그래프 고려한것이며 사실 무향이기 때문에 reverse를 안해도 된다만...)
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj.size(); ++there)
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}

오일러 트레일(Eulerian trail) : 모든 간선을 정확히 한 번씩 지나지만, 
  "시작점과 끝점이 다른 경로이다."
  점 a에서 시작해서 b에서 끝나는 오일러 트레일이 찾고 싶다고 합시다.
  a와 b사이에 간선(b, a)를 추가한 뒤 오일러 서킷을 찾습니다. 그리고 (b, a)간선을
  지워서 서킷을 끊으면 우리가 원하는 오일러 트레일을 얻을 수 있지요
  따라서 오일러 트레일의 존재 조건은 오일러 서킷과 별로 다를 것이 없습니다.
  시작점과 끝점을 잇는 간선을 하나 추가한 뒤 모든 점이 짝수점이 되려면,
  "시작점과 끝점을 제외한 모든 점은 짝수점이고 시작점과 끝점은 홀수점이어야 하지요."

//현대 그래프 이론에서 경로라고 하면 대개 한 점을 한번만 지나는 단순 경로를 가리킵니다.
//오일러 트레일은 한점을 두 번 이상 지날 수도 있기 때문에 경로 대신 트레일(trail)이라고 부릅니다.

//단어제한 끝말잇기(WORDCHAIN, 하)
3
4
dog
god
dragon
need // need dog god dragon
3
aa
ab
bb //aa ab bb
2
ab
cd //IMPOSSIBLE
이 문제를 그래프로 표현하는 가장 직관적인 방법은 입력에 주어진 각 단어를 정점으로 하는 방향 그래프를
만드는 것입니다. 한 단어의 마지막 글자가 다른 단어의 마지막 글자와 같다면 두 단어를 연속해서 사용할 수 
있으므로 간선을 추가합니다. 
"그래프의 모든 정점을 정확히 한 번씩 지나는 경로를 해밀토니안 경로 (Hamiltonian path)라고 부릅니다."
"하지만 큰 그래프에 대해 해밀토니안 경로를 빠르게 찾는 방법은 아직 고안되지 않았습니다."
// 정점을 한번씩 지남 -> 간선이 남는다.
해밀토니안 경로를 찾는 유일한 방법은 조합탐색으로, 모든 정점의 나열을
하나하나 시도하며 이들이 경로가 되는지를 확인하는 것입니다. 이 방법으로 문제를 풀기 위해서는
최악의 경우 n!개의 후보를 만들어 봐야 하는데, 이 문제에서는 단어의 수가 최대 100이기 때문에
절대로 답을 찾을 수 없다는 것을 쉽게 알 수 있지요.

이 문제를 시간안에 해결하는 방법은 입력에 주어진 각 단어를 정점이 아니라 간선으로 갖는
방향 그래프를 만드는 것입니다. 이 그래프의 정점들은 알파벳의 각 글자를 표현하며, 각 단어는
첫 글자에서 마지막 글자로 가는 간선이 됩니다. 그 뒤 이 그래프의 오일러 트레일 혹은 서킷을
찾으면 원래 문제의 답이 됨을 쉽게 알 수 있지요.

"그래프 변형기술 -> 정점의 간선화!!!!!(단어를 간선화 한다)"
"해밀토니안 패스 구하기 싫어요 --> 오일러 패스로 답을 구할래요~" !!!!!!!!

//p844 끝말잇기ㅣ 문제의 입력을 그래프로 만들기
//그래프의 인접행렬 표현. adj[i][j] = i와 j사이의 간선의 수
vector<vector<int> > adj;
//graph[i][j] = i로 시작해서 j로 끝나는 단어의 목록 
vector<string> graph[26][26]; //graph[a][b] = "asorb", "addkkb", "akb" ... !!!!
//indegree[i] = i 로 시작하는 단어의 수(오타같다: 끝나는 단어같음)
//outdegree[i] = i 로 끝나는 단어의 수(오타같다: 시작하는 단어같음)
vector<int> indegree, outdegree;
void makeGraph(const vector<string>& words) {
	//전역 변수 초기화
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			graph[i][j].clear();
	adj = vector<vector<int> > (26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	//각 단어를 그래프에 추가한다.
	for (int i = 0; i < words.size(); ++i) {
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}
방향 그래프에서의 오일러 서킷
 지금까지는 무향 그래프의 오일러 서킷을 찾는 방법만을 다뤘는데, 이 문제에서 오일러 서킷을
찾을 그래프는 방향 그래프입니다. 다행히 방향 그래프에서 오일러 서킷을 찾는 알고리즘은
무향 그래프에서와 거의 다르지 않습니다만, 오일러 서킷의 존재 조건이 무향 그래프와 다릅니다.
오일러 서킷의 모든 점에서는 경로가 들어온 횟수와 나간 횟수가 같아야 하기 때문에, 무향 그래프
에서는 각 정점에 인접한 간선이 짝수 개여야 했지요. 반면 방향 그래프에서 각 간선은 둘 중
한 방향으로만 쓸 수 있기 때문에, 각 정점에 들어오는 간선의 수와 나가는 간선의 수가 같아야만 합니다.
이 외의 조건은 무향 그래프와 같습니다. 간선들의 방향을 무시했을 때 방향 그래프의 정점들이 서로
연결되어 있어야 한다는 말이지요.
 오일러 서킷을 이용해 오일러 트레일을 어떻게 찾아냈는지를 돌이켜 보면, 방향 그래프에서
 오일러 트레일의 존재 조건도 쉽게 알 수 있습니다. a에서 시작하고 b에서 끝나는 오일러 트레일을
 찾기 위해서는 간선(b, a)를 그래프에 추가한 뒤 오일러 서킷을 찾아야 하지요. 이때 오일러 서킷의
 존재 조건이 만족 되려면 a에서는 나가는 간선이 들어오는 간선보다 하나 많고, b는 들어오는 간선이
 나가는 간선보다 하나 많고, 다른 모든 정점에서는 나가는 간선과 들어오는 간선의 수가 같아야 합니다.
 
이 문제에서 우리가 찾는 경로는 오일러 서킷을 수도 있고 트레일일 수도 있습니다. 문제에
주어진 첫 번째 예제 입력에서는 오일러 서킷을 찾게 되고, 두 번째 예제 입력에서는 오일러 트레일을 찾게 되지요.
우리가 오일러 트레일을 찾을지, 오일러 서킷을 찾을지 알기 위한 좋은 방법은 각 정점의 차수를 확인하는
것입니다. 오일러 트레일의 시작점에서는 나가는 간선의 수가 들어오는 간선의 수보다 하나 많아야
합니다. 따라서 이런 정점이 있다면 오일러 트레일을, 아니면 오일러 서킷을 찾는 함수를 작성 할 수 있지요.

// 간단정리
// 해밀토니안 경로를 찾는 방법은 조합탐색이라 어렵다.
abc, caf, cde, efgc
abc - caf 	// 답을 구성할 수 없다.
abc - cde - efgc - caf	// 답이 된다. 
// abc 다음에 올것을 알기 힘들다.

a ----> c		// abc
c ----> f		// caf
c ----> e		// cde
e ----> c		// efgc

위상정렬 비스무리한거로 처리
circuit = f, c, e, c, a  ==> reverse 수행: a, c, e, c, f
// 답이 쉽게 나온다.


//p864 방향 그래프에서 오일러 서킷 혹은 트레일을 찾아내기
//유향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을 계산한다.
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj.size(); ++there)
		while(adj[here][there] > 0) {
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}
//현재 그래프의 오일러 트레일이나 서킷을 반환한다.
vector<int> getEulerTrailOrCircuit() {
	vector<int> circuit;
	//우선 트레일을 찾아본다: 시작점이 존재하는 경우
	for (int i = 0; i < 26; ++i)
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	//아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작한다.
	for (int i = 0; i < 26; ++i)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	//모두 실패한 경우 빈 배열을 반환한다.
	return circuit;
}
//p847 끝말잇기 문제를 오일러 트레일 문제로 바꿔 해결하는 알고리즘
//현재 그래프의 오일러 서킷/트레일 존재 여부를 확인한다.
bool checkEuler() {
	//예비 시작점과 끝점의 수
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; ++i) {
		int delta = outdegree[i] - indegree[i];
		//모든 정점의 차수는 -1, 1, 또는 0 이어야 한다.
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}
	//시작점과 끝점은 각 하나씩 있거나 하나도 없어야 한다.
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}
string solve(const vector<string>& words) {
	makeGraph(words);
	//차수가 맞지 않으면 실패!
	if (!checkEuler()) return "IMPOSSIBLE";
	//오일러 서킷이나 경로를 찾아낸다.
	vector<int> circuit = getEulerTrailOrCircuit();
	//모든 간선을 방문하지 못했으면 실패!
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";

	//아닌 경우 방문 순서를 뒤집은 두 간선들을 모아 문자열로 만들어 반환한다.
	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 1; i < circuit.size(); ++i) {
		int a = circuit[i - 1];
		int b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}


그래프의 간선 구분은 깊이 우선탐색이 어느 순서대로 정점을 방문하느냐에 따라 다를 수 있다!!!!
트리 간선
순방향 간선
역방향 간선
교차 간선 : 위 세개를 제외한 나머지 간선

//p853 간선을 구분하는 깊이 우선 탐색의 구현
//그래프의 인접 리스트 표현
vector<vector<int> > adj;
//discovered[i] = i번 정점의 발견 순서
//finished[i] = dfs(i)가 종료했으면 1, 아니면 0
vector<int> discovered, finished;
//지금까지 발견한 정점의 수
int counter;

void dfs2(int here) {
	discovered[here] = counter++;
	//모든 인접 정점을 순회하면서
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		cout << "(" << here << ", " << there << ") is a ";
		//아직 방문한 적 없다면 방분한다.
		if (discovered[there] == -1) {
			cout << "tree edge" << endl;
			dfs2(there); //!!!!
		}
		//만약 there가 here보다 늦게 발견됐으면 there 는 here의 후손이다.
		else if (discovered[here] < discovered[there])
			cout << "forward edge" << endl;
		//만약 dfs2(there)가 아직 종료하지 않았으면 there는 here의 선조다
		else if (finished[there] == 0)
			cout << "back edge" << endl;
		//이 외의 경우는 모두 교차 간선
		else
			cout << "cross edge" << endl;
	}
	finished[here] = 1;
}


//p856 무향 그래프에서 절단점을 찾는 알고리즘
무향 그래프에서는 교차 간선이 없기 때문에, discovered[]만 있으면 모든 간선을 구분할 수 있다. : 순방향간선도 없다
//그래프의 인접 리스트 표현
vector<vector<int> > adj;
//각 정점의 발견 순서, -1로 초기화한다.
vector<int> discovered;
//각 정점이 절단점인지 여부를 저장한다. false로 초기화 한다.
vector<bool> isCutVertex;
int counter = 0;
//here를 루트로 하는 서브트리에 있는 절단점들을 찾는다.
//반환 값은 해당 서브트리에서 역방향 간선으로 갈 수 있는 정점 중
//가장 일찍 발견된 정점의 발견 시점을 리턴한다. 처음 호출할 때는 isRoot = true로 둔다.
int findCutVertex(int here, bool isRoot) {
	//발견 순서를 기록한다.
	discovered[here] = counter++;
	int ret = discovered[here];
	//루트인 경우의 절단점 판정을 위해 자손 서브트리의 개수를 센다.
	int children = 0;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (discovered[there] == -1) {
			++children;
			//이 서브트리에서 갈 수 있는 작은 정점의 번호
			//가장 먼저 발견된 즉 가장 작은 번호 임!!!!(책의 높은 정점은 큰 번호로 오해하기 쉽다)
			int subtree = findCutVertex(there, false);
			//그 번호가 현재노드의 발견번호보다 같거나 크다면
			if (!isRoot && subtree >= discovered[here]) //!!!! 이기 핵심이다
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		} else
			ret = min(ret, discovered[there]);	//루트는 역방향 간선이 없어용 : 루트로 향하는 역방향 간선은 있다. (ex:루프)
			//그래서 여기선 children 을 증가시킬 루틴이 필요가 없어용 루트에선 아예 안타니까~
	}
	//루트인 경우 절단점 판정은 서브트리의 개수로 한다.
	if (isRoot) isCutVertex[here] = (children >= 2);
	//!!!! 원모양의 루프를 이룬다 해도 루트의 서브트리는 2개가 아닌 하나로 인식된다~  
	return ret;
}


// 순회시 자기 부모를 따라가서 ret가 갱신된다는 사실을 대다수 설명들이 생략하고 있음 ㅅㅂ
// 1 -- 2 -- 3 -- 4 에서 3번노드에서 findCV(4, false) 가 호출되면 
// 4번 노드는 다시 부모노드로 한번 더 접근(질의)해서 dscv[3] 을 얻어온다.
// 즉 findCV(4, false) 는 3을 리턴한다. 그래도 위 코드는 돌아간다만. 설명은 찝찝하다.

// 그래서 아래 부모를 안타도록 갈끔하게 바꾼 코드임. 백준 통과함 11266 단절점
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <string>
#define rep(i,a) for (int i = 0; i < (a); ++i)
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

typedef const vector<int> cvi;
const long long INF = 1LL << 60;
ll max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
vi dscv;
vb isCV;
vvi adj;
int counter = 0;
int findCV(int here, int prnt) {
	dscv[here] = counter++;
	int ret = dscv[here];
	int children = 0;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (there == prnt) continue;
		if (dscv[there] == -1) {
			++children;
			int subtree = findCV(there, here);
			if (prnt != -1 && subtree >= dscv[here])
				isCV[here] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, dscv[there]);
	}
	if (prnt == -1) isCV[here] = (children >= 2);
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	adj = vvi(n);
	dscv = vi(n, -1);
	isCV = vb(n, false);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) if (dscv[i] == -1) 
		findCV(i, -1);
	int solCnt = 0;
	for (int i = 0; i < n; ++i) if (isCV[i]) solCnt++;
	cout << solCnt << '\n';
	for (int i = 0; i < n; ++i) if (isCV[i]) cout << i + 1 << " ";
	return 0;
}


// 단절선 문제 : 위 단절점 코드를 살짝만 바꾸면 된다. (위 코드가 깔끔하니 편하네)
https://www.acmicpc.net/problem/11400
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <string>
#define rep(i,a) for (int i = 0; i < (a); ++i)
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

typedef const vector<int> cvi;
const long long INF = 1LL << 60;
ll max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
vi dscv;
vb isCV;
vvi adj;
vector<pair<int, int>> sol;
int counter = 0;
int findCV(int here, int prnt) {
	dscv[here] = counter++;
	int ret = dscv[here];
	int children = 0;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (there == prnt) continue;
		if (dscv[there] == -1) {
			++children;
			int subtree = findCV(there, here);
			//if (prnt != -1 && subtree >= dscv[here])	// 단절점과 차이
			//isCV[here] = true;
			if (subtree > dscv[here])
				sol.push_back(make_pair(min(here, there), max(here, there)));
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, dscv[there]);
	}
	// 원을 이루어도 root 노드의 ret 값은 0 이며 이는 suttree > dscv[here] 에 의해 처리되니
	// 아래부분에 대응대는 논리는 필요가 없다.
	//if (prnt == -1) isCV[here] = (children >= 2);
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	adj = vvi(n);
	dscv = vi(n, -1);
	isCV = vb(n, false);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) if (dscv[i] == -1) 
		findCV(i, -1);
	sort(sol.begin(), sol.end());
	cout << sol.size() << '\n';
	for (int i = 0; i < sol.size(); ++i)
		cout << sol[i].first + 1 << " " << sol[i].second + 1 << '\n';

	return 0;
}



무향 그래프에서 절단점을 포함하지 않는 서브그래프를 이중 결합 컴포넌트(biconnected component)
라고 부릅니다. 이중 결합 컴포넌트 내에서는 임의의 한 정점을 그래프에서 지우더라도
정점 간의 연결 관계가 유지되지요.


//동치증명/
https://www.acmicpc.net/problem/3682	// 동치증명 : 112ms 걸림 
첫 번째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 100)가 주어지고,
각 테스트 케이스에 대해서는 다음과 같은 입력이 주어진다:
명제의 수 n(1 ≤ n ≤ 20,000)와 이미 증명된 함축의 수 m(0 ≤ m ≤ 50,000)이 첫 번째 줄에 주어진다.

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <string>
#include <stack>
#define rep(i,a) for (int i = 0; i < (a); ++i)
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

typedef const vector<int> cvi;
const long long INF = 1LL << 60;
ll max3(ll a, ll b, ll c) { return max(a, max(b, c)); }

vvi adj, sAdj;
vi sccId, dscv;
stack<int> st;
int sccCnt, vtxCnt;

int scc(int here) {
	int ret = dscv[here] = vtxCnt++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (dscv[there] == -1)
			ret = min(ret, scc(there));
		else if (dscv[there] < dscv[here] && sccId[there] == -1)
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
	//st = stack<int>();
	sccId = dscv = vi(adj.size(), -1);
	sccCnt = vtxCnt = 0;
	for (int i = 0; i < adj.size(); ++i) if (dscv[i] == -1) scc(i);
	return sccId;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		adj.clear();	sAdj.clear();
		int n, m; cin >> n >> m;
		//if (n == 1) {		// 이걸 고려하면 안되고 scc컴포넌트가 한개인가를 고려해야 함
		//	cout << 0 << '\n';
		//	continue;
		//}
		adj.resize(n);
		sAdj.resize(n);
		for (int i = 0; i < m; ++i) {
			int u, v; cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
		}
		tarjanSCC();
		for (int here = 0; here < n; ++here) {
			for (int j = 0; j < adj[here].size(); ++j) {
				int there = adj[here][j];
				if (sccId[here] != sccId[there])
					sAdj[sccId[here]].push_back(sccId[there]);
			}
		}
		vi in(sccCnt), out(sccCnt);
		for (int i = 0; i < sccCnt; ++i)
			for (int j : sAdj[i]) {
				in[j]++;
				out[i]++;
			}
		// scc컴포넌트가 동 떨어져 있어도 성립된다. !!!!!!!!
		// out 간선을 3개 추가하면 in 간선은 자동으로 3개 추가되는 효과가 있다.
		// 그 역도 마찬가지임. 따라서 in, out 중 필요한 최대 갯수를 구하면 된다.
		// 다른 곳에도 응용하기 좋을 듯
		int needOut = 0, needIn = 0;
		for (int i = 0; i < sccCnt; ++i) {
			if (in[i] == 0) needIn++;
			if (out[i] == 0) needOut++;
		}
		if (sccCnt == 1)	// 컴포넌트가 한개일때를 유의하자
			cout << 0 << '\n';
		else
			cout << max(needOut, needIn) << '\n';
	}
	return 0;
}


https://www.acmicpc.net/problem/11097	// 도시 계획 Urban Planning
그래프 G0 에 대해 입력으로
Reachability list 가 주어짐 (G0의 Transitive closure 가 G1 임)
G1의 Transitive reduction 가 G2(문제의 출력) 이 된다.
https://lyzqm.blogspot.com/2017/07/11097.html // DAG를 transitive reduction 하는 기똥찬 방법이 기술되어 있다.!!!!!!!!

// 기똥찬 플로이드 방식 응용이다. 길이 이상 있을때 롱점프 길을 제거하고 노드가 가장 많은 패스를 남기는 기술이다.
// 신기하도다 !!!!!!!!  scc문제자체보다 이부분이 더 신기하넹.

        //연결된것은 최적값이 아님 (scc간에 연결은 간선 1개면 충분)
        for (int k = 0;k < scc_cnt;k++) {
            for (int n = 0;n < scc_cnt;n++) {
                for (int m = 0;m < scc_cnt;m++) {
                    //n->k, k->m으로 간다면 n->m은 삭제 가능
                    if (adj_scc[n][m] && adj_scc[n][k] && adj_scc[k][m]) adj_scc[n][m] = 0;
                }
            }
        }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <string>
#include <stack>
#define rep(i,a) for (int i = 0; i < (a); ++i)
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

typedef const vector<int> cvi;
const long long INF = 1LL << 60;
ll max3(ll a, ll b, ll c) { return max(a, max(b, c)); }

vvi adj, sComponent;
vi sccId, dscv;
stack<int> st;
int sccCnt, vtxCnt;

int scc(int here) {
	int ret = dscv[here] = vtxCnt++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (dscv[there] == -1)
			ret = min(ret, scc(there));
		else if (dscv[there] < dscv[here] && sccId[there] == -1)
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
	for (int i = 0; i < adj.size(); ++i) if (dscv[i] == -1) scc(i);
	return sccId;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		adj = vvi(n);
		for (int i = 0; i < n; ++i) {
			string str; cin >> str;
			for (int j = 0; j < n; ++j) {
				if (i != j)
					if (str[j] == '1')
						adj[i].push_back(j);
			}
		}
		vector<pair<int, int>> sol;
		tarjanSCC();
		sComponent = vvi(sccCnt);	// 각 scc에 들어갈 노드들을 기록한다.
		vi sccToBaseNode(sccCnt);	// 각 scc 의 대표노드들을 세팅한다.
		for (int i = 0; i < n; ++i) {
			int sccIdx = sccId[i];
			if (sComponent[sccIdx].size() == 0)
				sccToBaseNode[sccIdx] = i;
			sComponent[sccIdx].push_back(i);
		}
		for (int i = 0; i < sComponent.size(); ++i) {
			if (sComponent[i].size() > 1) {
				for (int j = 0; j < sComponent[i].size(); ++j) {
					if (j == 0) {
						//cout << sComponent[i].back() + 1 << " " << sComponent[i][j] + 1;
						sol.push_back(make_pair(sComponent[i].back() + 1, sComponent[i][j] + 1));
					}
					else {
						//cout << sComponent[i][j - 1] + 1 << " " << sComponent[i][j] + 1;
						sol.push_back(make_pair(sComponent[i][j - 1] + 1, sComponent[i][j] + 1));
					}
					//cout << '\n';
				}
			}
		}
		int sccBoard[305][305];
		memset(sccBoard, 0, sizeof(sccBoard));
		for (int here = 0; here < n; ++here)
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i];
				if (sccId[here] != sccId[there])
					sccBoard[sccId[here]][sccId[there]] = 1;
			}
		// 플로이드 응용 : 롱점프하는 놈들을 없애고 자잘한 길로 연결되도록 한다.
		// 그래야 간선이 최소가 되는 transitive eduction 이 된다.
		for (int k = 0; k < sccCnt; ++k)
			for (int i = 0; i < sccCnt; ++i)
				for (int j = 0; j < sccCnt; ++j)
					if (sccBoard[i][j] && sccBoard[i][k] && sccBoard[k][j])
						sccBoard[i][j] = 0;
		
		for (int here = 0; here < sccCnt; ++here)
			for (int there = 0; there < sccCnt; ++there)
				if (sccBoard[here][there]) {
					//cout << sccToBaseNode[here] + 1 << " " << sccToBaseNode[there] + 1 << '\n';
					sol.push_back(make_pair(sccToBaseNode[here] + 1, sccToBaseNode[there] + 1));
				}
		cout << sol.size() << '\n';
		for (int i = 0; i < sol.size(); ++i)
			cout << sol[i].first << " " << sol[i].second << '\n';
	}
	return 0;
}
		
		
		
		



p860 ~ p861 의 tarjanSCC() 정의와 구현은 정오표를 참조하시오

//감시카메라 설치(GALLERY, 중) 
//모든 갤러리를 감시하기 위해 필요한 최소 감시 카메라의 수는 몇개?
//한 번 관람한 갤러리를 다시 가기 위해서는 이전에 지나왔던 복도를 반드시 한번
//지나야 되는 구조 => 사이클이 없다!!!!
3

6 5 //정점 갯수, 엣지 갯수
0 1
1 2
1 3
2 5
0 4

4 2
0 1
2 3

1000 1
0 1

//OUTPUT
3
2
999

//p867 감시 카메라 문제를 해결하는 알고리즘의 구현
int V;
vector<int> adj[MAX_V];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
//지금까지 설치한 카메라의 총 수
int installed;
//here로부터 깊이 우선 탐색을 하고, here의 정보를 반환한다.
int dfs(int here) {
	visited[here] = true;
	int children[3] = {0, 0, 0};//UNWATCHED, INSTALLED만 이용하는데 3개가 될 필요 있나?
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)];
	}
	//자손 노드 중 감시되지 않는 노드가 하나라도 있을 경우 카메라를 설치한다.
	if (children[UNWATCHED]) {
		++installed;
		return INSTALLED;
	}
	//자손 노드들은 감시(watch, install)되고 있으며
	//자손 노드 중 하나라도 카메라가 설치된 노드가 있을 경우 현노드는 설치할 필요가 없다.
	if (children[INSTALLED])
		return WATCHED;

	//자손 들이 감시가 모두 되어 있고, 자손들 전부 카메라가 설치되지 않았으면
	//혹은 아무런 자손이 없다면(잎노드라면)
	return UNWATCHED;

	//자손을 기준으로 생각하면 이해하기 쉽다!!!!
	//자손이 하나라도 감시안됨, 자손이 감시되나 설치된 곳도 있음, 자손이 모두 감시만됨(설치된 곳은 없음)
}
//그래프를 감시하는 데 필요한 카메라의 최소 수를 반환한다.
int installCamera() {
	installed = 0;
	visited = vector<bool>(V, false);
	for (int u = 0; u < V; ++u)
		if (!visited[u] && dfs(u) == UNWATCHED)
			++installed;
	return installed;
}

Tarjan의 SCC 분리 알고리즘 오류
1쇄 ~ 3쇄의 28.7절의 "강결합 컴포넌트 분리를 위한 타잔의 알고리즘"의 유도 과정과 코드에 오류가 
있습니다. 유도 과정에서의 오류와 정정된 코드를 아래에서 보실 수 있습니다. 혼란을 드려 죄송합니다.
새로 쓴 부분을 여기에서 보실 수 있습니다
교차 간선의 중요성
860쪽 마지막 문단("유의할 것은 교차 간선입니다." 로 시작)에서는 교차 간선을 무시해야 한다고 
말하고 있습니다. 그러나 이것은 사실이 아닙니다. 
어떤 정점이 같은 SCC 안의 정점과 연결되는 경로는 교차 간선을 통할 수도 있기 때문입니다.
A<->B //간선두개로 서로 연결
A->C
C->B
위 그래프가 이와 같은 반례의 예를 보여줍니다. A에서 깊이 우선 탐색을 시작해 B를 방문한 뒤,
C를 방문했다고 합시다. A, B, C는 모두 같은 강결합 컴포넌트에 속하지만, 
교차 간선을 무시할 경우 C는 컴포넌트의 다른 정점들과 연결되지 않으므로 
책의 알고리즘은 C가 별도의 컴포넌트에 속한다고 잘못 판단하게 됩니다.

vector<vector<int> > adj;// 그래프의 인접 리스트 표현
// 각 정점의 컴포넌트 번호. 컴포넌트 번호는 0 부터 시작하며, 
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;
vector<int> discovered, finished;// 각 정점의 발견 순서와 scc() 종료 여부
stack<int> st;// 정점의 번호를 담는 스택
int sccCounter, vertexCounter;
// here 를 루트로 하는 서브트리에서 역방향 간선으로 닿을 수 있는 최소의 발견 순서를 반환
int scc(int here) {
  int ret = discovered[here] = vertexCounter++;
  // 스택에 here 를 넣는다. here 의 후손들은 모두 스택에서 here 후에 들어간다.
  st.push(here);  
  for(int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    if(discovered[there] == -1)     // (here,there) 가 트리 간선
      ret = min(ret, scc(there));
    // (here,there) 가 역방향이나 교차 간선
    else if(discovered[there] < discovered[here] && sccId[there] == -1) 
      ret = min(ret, discovered[there]);
	//discovered[there] > discovered[here] 이면 순방향 간선
	//그렇지 않으면 나머지 들임(역방향이거나, 교차간선)
	//역방향 간선은 항상 sccId[there] == -1이지만
	//교차간선의 경우 다른 컴포넌트 일수도 있으므로 sscId[there] == -1인지 확인한다.
//엄밀히 적자면 아래 두 개가 합친거
//	else if (discovered[there] < discovered[here] && finished[there] == -1 && sccId[there] == -1)
//		ret = min(ret, discovered[there]); //역방향간선
//	else if (discovered[there] < discovered[here] && finihsed[there] == 1 && sccId[there] == -1)
//		ret = min(ret, discovered[there]); //교차면서 there가 다른 컴포넌트가 아닌 가선
//(A & B & C) | (A & !B & C) = (A & C) & ( B | !B) = (A & C)
  }  
  // here 가 강결합 컴포넌트의 루트인가 확인한다
  if(ret == discovered[here]) {
    // here 를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다
    while(true) {
      int t = st.top(); st.pop();
      sccId[t] = sccCounter;
      if(t == here) break;
    }
    ++sccCounter;
  }]
  finished[here] = 1; //여기선 무의미한 존재이다.. 왜 있는지.. 디버깅 용인감..?
  return ret;
}
// tarjan 의 SCC 알고리즘
vector<int> tarjanSCC() {
  sccId = discovered = vector<int>(adj.size(), -1);  // 배열들을 전부 초기화
  finished = vector<int>(adj.size(), 0);
  sccCounter = vertexCounter = 0;   // 카운터 초기화
  // 모든 정점에 대해 scc() 호출
  for(int i = 0; i < adj.size(); i++) if(discovered[i] == -1) scc(i);
  return sccId;
}



회의실 배정(MEETINGROOM, 상)
함의 그래프를 유도하는 문제임
//input
3
2
1 10 10 20
1 10 10 20

3
1 10 10 20
1 10 10 20
1 10 10 20

3
2 5 6 9
1 3 8 10
4 7 11 12
//output
POSSIBLE
1 10
10 20
IMPOSSIBLE
POSSIBLE
2 5
8 10
11 12

//p873 회의 시간으로부터 2-SAT 문제의 함의 그래프 만들기
//그래프의 인접 리스트 표현
vector<vector<int> > adj;
//두 구간 a와 b가 서로 겹치지 않는지를 확인한다.
bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second <= b.first || b.second <= a.first;
}
//meetings[]가 각 팀이 하고 싶어하는 회의 시간의 목록일 때, 이를
//2-SAT문제로 변환한 뒤 함의 그래프를 생성한다.
//i번 팀은 meetings[2 * i] 혹은 meetings[2 * i + 1]중 하나 시간에 회의실을 써야 한다.
void makeGraph(const vector<pair<int, int> >& meetings) {
	int mtSize = meetings.size();
	//그래프는 각 변수마다 두 개의 정점을 갖는다.
	adj.clear();
	adj.resize(mtSize * 2);
	for (int i = 0; i < mtSize; i += 2) {	//한번에 두 회의씩 처리
		//각 팀은 i번 회의나 j번 회의 둘 중 하나는 해야 한다.
		
		// 그 둘 중 선택은 아무거나 하면 됨. 둘다 선택 가능시에는 외부에서 선택 하도록 한다. 배타적으로 보고 아래처럼 하면 안됨
		// i => ~j
		// j => ~i
		// (~i U ~j) 이므로 둘다 선택이 불가능함에도 true 가 되기 때문이다.
		
		//(i or j) 절을 추가한다.
		int j = i + 1;
		adj[i * 2 + 1].push_back(j * 2); //~i => j
		adj[j * 2 + 1].push_back(i * 2); //~j => i

		//i == 0, j == 1
		//adj[1].push_back(2)
		//adj[3].push_back(0)
		//실제 의미
		//i = 0, ~i = 1, j = 2, ~j = 3

		//i == 2, j == 3
		//adj[5].push_back(6)
		//adj[7].push_back(4)
		//i = 4, ~i = 5, j = 6, ~j = 7
	}
	for (int i = 0; i < mtSize; ++i)	//2중for문 역삼각 조회(내가 지은 말)!!!! 아.. 삼각 조회네...
		for (int j = 0; j < i; ++j) {
			//i번 회의와 j번 회의가 서로 겹칠 경우
			if (!disjoint(meetings[i], meetings[j])) {
				//i번 회의가 열리지 않거나, j번 회의가 열리지 않아야 한다.
				//(~i or ~j) 절을 추가한다.
				adj[i * 2].push_back(j * 2 + 1); //i => ~j
				adj[j * 2].push_back(i * 2 + 1); //j => ~i
				//고찰 : 역을 가지고 그래프를 만들어도 성립될까?
				//성립 안됨 : ~i => j 의 경우 j가 다른 놈에 종속될 수 있기 때문에!!!!
			}
		}
	
}
"참고"
i	j	(~i U ~j)	(i U j)
0	0		1			0		// a
0	1		1			1		// b
1	0		1			1		// c
1	1		0			1		// d
// 우리가 필요한건 b, c 케이스라고 봄 헌데 d케이스를 막는 간선을 굳이 추가 안해도 된다.
// d 케이스인 경우에는 한놈만 true 로 선택하면 되기 때문이다.
// 그래서 (i U j) 를 이용한다.
// (~i U ~j) 는 0, 0 도 true 로 하기때문에 안된다. (i->~j, j->~i 로 간선을 만들면 안되는 이유다.)




//p878 2-SAT 문제 해결하기
//adj에 함의 그래프의 인접 리스트 표현이 주어질 때, 2-SAT 문제의 답을 반환한다.
vector<int> solve2SAT() {
	int n = adj.size() / 2; //변수의 수((전체노드(A, notA..)개수 / 2) : 회의의 수  
	//함의 그래프의 정점들을 강결합 요소별로 묶는다.
	vector<int> label = tarjanSCC();	"label[i]: 노드i의 scc번호"
	
	//이 SAT문제를 푸는 것이 불가능한지 확인한다. 한 변수를 나타내는 두 정점이
	//같은 강결합 요소에 속해 있을 경우 답이 없다.
	for (int i = 0; i < 2 * n; i += 2)
		if (label[i] == label[i + 1])
			return vector<int>();
	//SAT 문제를 푸는 것이 가능하다. 답을 생성하자!
	vector<int> value(2 * n, -1);//회의의 갯수 * 2로 세팅할 필욘 없다
	//vector<int> value(n, -1); 이게 더 옳음!!!!
	//Tarjan 알고리즘에서 SCC번호는 위상 절렬의 역순으로 배정된다.
	//SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 된다.
	vector<pair<int, int> > order;
	for (int i = 0; i < 2 * n; ++i)
		order.push_back(make_pair(-label[i], i));
	sort(order.begin(), order.end());
	//각 정점에 값을 배정한다.
	for (int i = 0; i < 2 * n; ++i) {
		int vertex = order[i].second;
		int variable = vertex / 2;
		
		if (value[variable] != -1) continue;
		//not A가 A보다 먼저 나왔으면 A는 참
		//A가 not A보다 먼저 나왔으면 A는 거짓
		int isTrue = !((vertex % 2) == 0);	//not node가 먼저 나오면 node는 참
											//node가 먼저 나오면 node는 거짓
		value[variable] = isTrue;
	}
	return value;
}
//위에는 가독성이 영 아니다
vector<int> solve2SAT() {
	vector<int> label = tarjanSCC();	// 함의 그래프의 정점들을 강결합 요소별로 묶는다.
	for (int i = 0; i < adj.size(); i += 2)
		if (label[i] == label[i + 1])	// 한 변수를 나타내는 두 정점이 같은 강결합 요소에
			return vector<int>();		// 속해 있을 경우 답이 없다.
	// SAT 문제를 푸는 것이 가능하다. 답을 만들어 보자!
	vector<pair<int, int>> order;
	// Tarjan 알고리즘에서 SCC번호는 위상 정렬의 역순으로 배정된다.
	// SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 된다.
	for (int i = 0; i < adj.size(); ++i)
		order.push_back(make_pair(-label[i], i));
	sort(order.begin(), order.end());
	vector<int> vbChoose(adj.size() / 2, -1);	// 회의의 선택여부
	for (int i = 0; i < order.size(); ++i) {
		int node = order[i].second;
		int index = node / 2;
		if (vbChoose[index] != -1) continue;
		vbChoose[index] = !((node % 2) == 0);	//not node가 먼저 나오면 참, 그렇지 않으면 거짓
		//vbChoose[index] = node % 2;
	}
	return vbChoose;
}
vector<int> solve(const vector<pair<int, int>>& meetings) {
	makeGraph(meetings);	// 2-SAT 문제로 변경하기 위해 함의 그래프를 만든다.
	vector<int> ret = solve2SAT();
	return ret;
}

CNF논리식의 어떤 절 (X || Y) 이 거짓이라고 하자 (X, Y 는 둘다 거짓이군)
!X -> Y : P 이면 Q 이다 : 참이면 거짓이다 : CNF논리식이 거짓이 되버림
!Y -> X : P 이면 Q 이다 : 참이면 거짓이다 : CNF논리식이 거짓이 되버림

(X || Y) 가 참이라고 하자 (X, Y는 적어도 한놈은 참)
!X -> Y : (X참, Y거짓 일때) : 거짓이면 거짓이다 : CNF논리식은 참임
		  (X거짓, Y참 일때) : 참이면 참이다.	: CNF논리식은 참임
|Y -> X : (Y참, X거짓 일때) : 거짓이면 거짓이다 : CNF논리식은 참임
		: (Y거지, X참 일때) : 참이면 참이다.	: CNF논리식은 참임
		: X, Y 둘다 참이면  : 거짓이면 참이다.	: CNF논리식이 참이다. !!!!!!!!
"여기서 명제 P가 거짓이면 Q는 참이든 거짓이든 상관없이 논리식이 참이 된다"
// 위상 정렬순서로 가장 앞의 컴포넌트를 거짓으로 설정하면 모든 간선에 대해
" 참에서 거짓으로 가는 노드가 발생하지 않는다" 오오
	scc0(반시계 사이클)		scc1(시계 사이클)
	 !A2<--------------------A1
  A3  A0					!A0  !A3
	 !A1<---===--------------A2
scc1을 참으로 해버리면 A1(참)---->!A2(거짓) 이므로 절이 거짓이 되어 버리며 CNF논리식은 거짓이 된다.
"scc1을 거짓으로 하면 이런 문제가 발생하지 않는다."

	
int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	int n;
    	cin >> n;
    	vector<pair<int,int> > meetings(2*n);
    	for(int i = 0; i < 2*n; i++) 
    		cin >> meetings[i].first >> meetings[i].second;
    	vector<int> value = solve(meetings);
		//value의 size는 전체 회의 갯수랑 동일하다
    	if(value.empty()) {
    		cout << "IMPOSSIBLE" << endl;
    	}
		else {
			cout << "POSSIBLE" << endl;

			// 각 팀이 회의할 수 있는 시간을 출력한다
			for(int i = 0; i < 2*n; i += 2) 
				if(value[i] == 1) //팀의 첫째 회의, 두번째 회의가 둘다 가능하다면
					cout << meetings[i].first << " "	//첫째 회의놈이 출력된다. i += 2를 보삼
						<< meetings[i].second << endl;	// 위에말은 무시해라. 팀의 첫째 회의 두번째 회의가 동시에 가능하진 않다.
						// 라고 생각 했다만... 함의 그래프를 만들때 Fi->!Se 를 넣지 않았다.(Se->!Fi 도 넣진 않았다.)
						// 따라서 value[i] == 1 && value[i+1] == 1 인 케이스도 분명 존재할거다.
				else									
					cout << meetings[i+1].first << " " 
						<< meetings[i+1].second << endl;
		}
	}
}

"참고"
Conjunctive Normal Form
Example: Put the following into CNF:
	!(p->q) || (r->p)
solution:
1. Eliminate implication signs:
	!(!p||q) || (!r||p)			// p->q 하나만 있는데 그걸로 !p||q 를 만들수 있다. !!!!!!!!
								// p->q 의 대우가 !q->!p 임을 생각해보자.
2. Move negation inwards; eliminate double negation:
	(p&&!q) || (!r||p)

3. Convert to CNF using associative/distributive laws
	(p||~r||p) && (!q||!r||p)



//29장 그래프의 너비 우선 탐색
//p882 그래프의 너비 우선 탐색
//그래프의 인접 리스트 표현
vector<vector<int> > adj;
//start 에서 시작해 그래프의 너비 우선 탐색하고 각 정점의 방문 순서를 반환한다
//발견과 방문의 차이를 잘 이해해라!!!!
vector<int> bfs(int start) {
	//각 정점의 방문 여부
	vector<bool> discovered(adj.size(), false);
	//방문할 정점 목록을 유지하는 큐
	queue<int> q;
	//정점의 방문순서
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		//here를 방문한다.
		order.push_back(here);
		//모든 인접한 정점을 검사한다.(발견한다)
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
			// 처음 보는 정점이면 방문할 목록에 집어넣는다.
			if (!discovered[there]) {
				discovered[there] = true;
				q.push(there);
			}
		}
	}
	return order;
}

//p885 최단 경로를 계산하는 너비 우선 탐색
//start에서 시작해 그래프를 너비 우선 탐색하고 시작점부터 각 정점까지의 
//최단거리와 너비 우선 탐색 스패닝 트리를 계산한다.
//distance[i] = start 부터 i까지의 최단 거리
//parent[i] = 너비 우선 탐색 스패닝 트리에서 i의 부모의 번호. 루트인 경우 자신의 번호
void bfs2(int start, vector<int>& distance, vector<int>& parent) {
	distance = vector<int>(adj.size(), -1);
	parent = vector<int>(adj.size(), -1);
	//방문할 정점 목록을 유지하는 큐
	queue<int> q;
	distance[start] = 0;
	parent[start] = start;
	q.push(start);
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		//here의 모든 인접한 정점을 검사한다.
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
			//처음 보는 정점이면 방문 목록에 집어넣는다.
			if (distance[there] == -1) {
				q.push(there);
				distance[there] = distance[here] + 1;
				parent[there] = here;
			}
		}
	}
}
//v로부터 시작점까지의 최단 경로를 계산한다.
vector<int> shortestPath(int v, const vector<int>& parent) {
	vector<int> path(1, v);//사이즈 1개 v로 초기화
	while(parent[v] != v) {	// 같으면 start 지점임
		v = parent[v];
		path.push_back(v);
	}
	reverse(path.begin(), path.end());
	return path;
}


문제 Sorting Game(SORTGAME, 중)
INPUT

OUTPUT

//p888 Sorting Game문제를 해결하는 너비 우선 탐색 알고리즘
//perm을 정렬하기 위해 필요한 최소 뒤집기 연산의 수를 계산한다.
int bfs(const vector<int>& perm) {
	int n = perm.size();
	//목표 정점을 미리 계산한다.
	vector<int> sorted = perm;
	sort(sorted.begin(), sorted.end());
	//방문 목록(큐)과 시작점부터 각 정점까지의 거리
	queue<vector<int> > q;
	map<vector<int>, int> distance;
	//시작점을 큐에 넣는다.
	distance[perm] = 0;
	q.push(perm);
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		//목표 정점을 발견했으면 곧 장 종료한다.
		if (here == sorted) return distance[here];
		int cost = distance[here];
		//가능한 모든 부분 구간을 뒤집어 본다.
		for (int i = 0; i < n; ++i)
			for (int j = i + 2; j <= n; ++j) {	//!!!!
				reverse(here.begin() + i, here.begin() + j);
				if (distance.count(here) == 0) {    //!!!! map의 원소 존재 여부
					if (sorted == here) return cost + 1;
					distance[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
	}
	//oops
	return -1;
}
//조사하는 삼각형을 이매진해라(난 위 bfs코드처럼 역삼각형이 좋더라)
		for (int i = 0; i < vars; ++i)
			for (int j = 0; j < i; ++j) {
				if (!disjoint(meetings[i], meetings[j])) {
					adj[i * 2].push_back(j * 2 + 1);
					adj[j * 2].push_back(i * 2 + 1);
				}
			}

		for (int i = 0; i < vars; ++i)
			for (int j = i + 1; j < vars; ++j)
				if (!disjoint(meetings[i], meetings[j])) {
					adj[i * 2].push_back(j * 2 + 1);
					adj[j * 2].push_back(i * 2 + 1);
				}
array = {A, B, C, D} //2개짜리 부분 집합을 출력해보자
for (int i = 0; i < array.size(); ++i) {
	for (int j = i + 1; j < array.size(); ++j)
		cout << "{ " << array[i] << ", " << array[j] << " }, ";
	cout << endl;
}
{A, B}, {A, C}, {A, D}
{B, C}, {B, D}
{C, D}

for (int i = 0; i < array.size(); ++i) {
	for (int j = 0; j < i; ++j)
		cout << "{ " << array[i] << ", " << array[j] << " }, ";
	cout << end;
}
{B, A},
{C, A}, {C, B}
{D, A}, {D, B}, {D, C}
	


//p890 Sorting Game문제를 빠르게 해결하는 너비 우선 탐색의 구현
//상태공간이 양방향 그래프!!!! 그래서 시작지점에서 목표지점으로 가는 최단 거리는
//목표지점에서 시작지점으로 가는 것과 같음을 이용
map<vector<int>, int> toSort;
//[0, ..., n-1]의 모든 순열에 대해 toSort[]를 계산해 저장한다.
void precalc(int n) {
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;
	queue<vector<int> > q;
	q.push(perm);
	toSort[perm] = 0;
	while(!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int cost = toSort[here];
		for (int i = 0; i < n; ++i) {
			for (int j = i + 2; j <= n; ++j) {
				reverse(here.begin() + i, here.begin() + j);
				if (toSort.count(here) == 0) {
					toSort[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}
void precalcAll() {
	const int MAX_N = 8;
	for (int i = 0; i < MAX_N; ++i)
		precalc(i);
}
int solve(const vector<int>& perm) {
	//perm을 [0,..., n-1]의 순열로 변환한다.
	int n = perm.size();
	vector<int> fixed(n);
	for (int i = 0; i < n; ++i) { //!!!!순열표현방법 좋네
		//7 1 5 10 => 2 0 1 3
		int smaller = 0; //i 자신보다 작은 놈 갯수
		for (int j = 0; j < n; ++j)
			if (perm[i] > perm[j])
				++smaller;
		fixed[i] = smaller;
	}
	return toSort[fixed];
}
  


어린이날(CHILDDRENDAY, 상)
INPUT
5	// test case
1 7 0	// 자릿수의 목록 D, 총인원 N, 욕심쟁이 M	// 1111111 : 7로 나누어 떨어지는 최소 숫자임.
1 10 1	// 11 : 10명에게 1개씩 주고 욕심쟁이에게 1개 더 감
0 7 3	// "impossible"
345 9997 3333	// 35355353545
35 9 8	// 35
OUTPUT

//P896 그래프 모델링을 통해 어린이날 문제를 해결하는 알고리즘
//현재 정점 번호가 here이라면, 간선번호 edge를 따라갔을 때
//나오는 정점의 번호는?
(c * 10 + x) mod n = ((c mod n) * 10 + x) mod n
//88 % 7 => (8 % 7) * 10 % 7 : 우리가 일반적으로 하는 나머지 계산이랑 똑같다고 보면됨
int append(int here, int edge, int mod) {
	int there = here * 10 + edge; 
	if (there >= mod) //전체인원 이상이면
		return mod + there % mod; //회색정점으로 간다.
	return there % mod; //흰색정점으로 간다.
}
//digits에 속한 숫자들만으로 구성되고,
//C mod n == m인 최소의 C를 찾는다.
string gifts(string digits, int n, int m) {
	//간선의 번호를 오름차순으로 정렬해 두면 사전순으로 가장 앞에
	//있는 경로를 찾을 수 있다.
	sort(digits.begin(), digits.end());
	//흰색 정점 i는 0 ~ n-1, 회색 정점 i는 n ~ 2n-1 로 표현한다.
	//parent[i] = BFS 스패닝 트리에서 정점 i의 부모
	//choice[i] = parent[i] 에서 i로 연결된 간선의 번호
	vector<int> parent(2 * n, -1), choice(2 * n, -1);
	queue<int> q;
	//흰색 0번을 큐에 추가
	parent[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < digits.size(); ++i) {
			//간선 digits[i] - '0' 을 따라가본다.
			int there = append(here, digits[i] - '0', n);
			if (parent[there] == -1) {
				parent[there] = here;
				choice[there] = digits[i] - '0'; //there 로 가는 간선 가중치
				//choice[there]는 한번 정해지면 시마이. 덮여쓰여지지 않는다.
				q.push(there);
			}
		}
	}
	//회색 m번에 도달하지 못했으면 실패!
	if (parent[n + m] == -1) return "IMPOSSIBLE";
	//부모로 가는 연결을 따라가면서 C를 계산한다.
	string ret;
	int here = n + m; 
	while (parent[here] != here) {
		ret += char('0' + choice[here]); //!!!! 좋은 방법
		//string 형에 int를 대입하면 전혀 출력시 해당 숫자 값이 아닌 아스키 코드 값이 출력된다.
		here = parent[here];
	}
	reverse(ret.begin(), ret.end());
	return ret;
}



//p900 15-퍼즐 : 응용력이 좋은 코드, 구현에 생략이 있으나 이해는 해라 //!!!!
//실제 소스는 아래 주석을 가지고 검색하면 나옴(꽤 됨)
//게임판의 상태를 표현한다.
class State {
	//인접한 상태들의 목록을 반환한다.
	vector<State> getAdjacent() const;
	//map에 State를 넣기 위한 비교연산자
	bool operator < (const State& rhs) const;//map의 키가 되기 위해선 필요
	//종료 상태와 비교하기 위한 연산자
	bool operator == (const State& rhs) const;
};
typedef map<State, int> StateMap;
//start에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bfs(State start, State finish) {
	//예외: start == finish인 경우
	if (start == finish) return 0; //!!!!
	//각 정점까지의 최단 경로의 길이를 저장한다.
	StateMap c;
	//앞으로 방문할 정점들을 저장한다.
	queue<State> q;
	q.push(start);
	c[start] = 0;
	//너비 우선 탐색
	while (!q.empty()) {
		State here = q.front();
		q.pop();	// 방문
		int cost = c[here];
		//인접한 정점들의 번호를 얻어낸다. //객체에 위임하니 존나게 편하구나!!!!
		vector<State> adjacent = here.getAdjacent();
		for (int i = 0; i < adjacent.size(); ++i) {
			//거리가 정해져 있지 않음 => 아직 방문하지 않음(방문보단 아직 발견하지 않음임)
			"스택에 쌓을지 안 쌓을지는 발견여부가 결정한다"
			if (c.count(adjacent[i]) == 0) { //!!!!이렇게 한 이유가 있다.
			//키가 없는 경우 if (c[adjacent[i]] == 0) 이렇게 쓸 수 없기 때문이다.
				//답을 찾았나?
				if (adjacent[i] == finish) return cost + 1; //인접상태가 finish면 거리를 계산하여 리턴
				c[adjacent[i]] = cost + 1; //인접상태의 거리를 계산한다
				q.push(adjacent[i]);
			}
		}
	}
	//답을 찾지 못한 경우
	return -1;
}

//p903 15-퍼즐 양방향 탐색 알고리즘
//15 퍼즐 문제의 상태를 표현하는 클래스
class State;
//x의 부호를 반환한다.
int sgn(int x) { if(!x) return 0; return x > 0 ? 1 : -1; }
//x의 절대값을 1 증가 시킨다.
int incr(int x) {if (x < 0) return x - 1; return x + 1; } // 0 -> 1 이 됨
//start에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bidirectional(State start, State finish) {
	//각 정점까지의 최단 경로의 길이를 저장한다.
	map<State, int> c;
	//앞으로 방문할 정점들을 저장한다.
	queue<State> q;
	//시작 상태와 목표 상태가 같은 경우는 예외로 처리해야 한다.
	if (start == finish) return 0;
	q.push(start); c[start] = 1; //앞의 코드에선 0으로 세팅했는데 여기선 1로 세팅
	//1로 세팅해야 편한 이유가 존재한다. (노드수를 기준으로 했음)
	q.push(finish); c[finish] = -1;
	//너비 우선 탐색
	while (!q.empty()) {
		State here = q.front();
		q.pop();
		//인접한 상태들을 검사한다.
		vector<State> adjacent = here.getAdjacent();
		for (int i = 0; i < adjacent.size(); ++i) {
			map<State, int>::iterator it = c.find(adjacent[i]); //!!!!맵 원소 여부
			if (it == c.end()) {							//방문여부를 판단한다.
				c[adjacent[i]] = incr(c[here]);
				q.push(adjacent[i]);
			}
			//가운데서 만난 경우
			else if (sgn(it->second) != sgn(c[here]))
				return abs(it->second) + abs(c[here]) - 1; //노드수 - 1 = 간선수
			//맵의 요소를 iterator로 접근하는 방법 it->second !!!! pair랑 똑같네.
		}
	}
	return -1; //답을 찾지 못한 경우
}


하노이의 탑(HANOI4B, 중)
//작은 원반 위에 큰 원반을 놓아서는 안됨, 맨 오른쪽 기둥으로 옮겨라
//기둥은 4개임
INPUT
5 //원반의 총 개수
1 1		//0번 기둥에 1번 원반(풀이에선 0번 원반 취급, 나머지들도 -1 했음)
1 3		//1번 기둥에 3번 원반
2 5 4	//2번 기둥에 5, 4번 원반
1 2		//3번 기둥에 2번 원반

OUTPUT
10


//p915 하노이의 탑 문제를 해결하는 너비 우선 탐색 코드 풀이
const int MAX_DISCS = 12;
// getPole, setState
int get(int state, int index) {	//state : 기둥 상태, index : 원반번호
	return (state >> (index * 2)) & 3; //원반이 꽃혀있는 기둥의 번호를 리턴
}
int set(int state, int index, int value) { //value : 기둥번호(0~3), 상태를 리턴함
	return (state & ~(3 << (index * 2))) | (value << (index * 2)); //!!!!
	//0번 원반을 세팅한다면 먼저 state의 0, 1번째 비트들을 초기화 한다.
	//1번 원반을 세팅한다면 먼저 state의 2, 3번째 비트들을 초기화 한다.
}
//힌트 : 각 원반이 꽂혀 있는 기둥의 번호를 모두 알고 있다면 원반들의 배치가 유일하게
//결정된다!!!!
//원반(disc)가 총 5개가 맨 오른쪽 기둥에 있는 상태
00..000 11 11 11 11 11
//예제의 상태
10 10 01 11 00 //!!!! 
int c[1 << (MAX_DISCS * 2)];
//discs개의 원반이 있고, 각 원반의 시작 위치와 목표 위치가 
//begin, end에 주어질 때 최소 움직임의 수를 계산한다.
int bfs(int discs, int begin, int end) {
	if (begin == end) return 0;
	queue<int> q;
	memeset(c, -1, sizeof(c));
	q.push(begin);
	c[begin] = 0;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		//각 기둥에서 제일 위에 있는 원반의 번호를 계산한다.
		int top[4] = { -1, -1, -1, -1 };
		for (int i = discs - 1; i >= 0; --i) //!!!! 구조가 깔끔하다.
			top[get(here, i)] = i;
		//i번 기둥의 맨 위에 있는 원반을 j번 기둥으로 옮긴다.
		for (int i = 0; i < 4; ++i)
			//i번 기둥에 원반이 하나도 없으면 안된다.
			if (top[i] != -1)
				for (int j = 0; j < 4; ++j)
					//j번 기둥은 비어 있거나, 맨 위의 원반이 더 커야 한다.
					if (i != j && (top[j] == -1 || top[j] > top[i])) {
						int there = set(here, top[i], j); //!!!! 이해가 잘 안된 부분
						//i번 기둥의 가장 윗 원반을 j번 기둥에 놓으면 두개 정도는 구문이 있어야 된다고 생각했는데
						//가장 윗 원반이 놓인 기둥 위치만 변경하는 것으로 간단화 되네... 신기
						if (c[there] != -1) continue;
						c[there] = c[here] + 1;
						if (there == end) return c[there];
						q.push(there);
					}
	}
	return -1;
}

//p916 하노이의 탑 문제를 해결하는 양방향 탐색의 구현
//x의 부호를 반환한다.
int sgn(int x) { if (!x) return 0; return x > 0 ? 1 : -1; }
//x의 절대값을 1 증가시킨다.
int incr(int x) { if (x < 0) return x - 1; return x + 1; }
//discs개의 원반이 있고, 각 줜반의 시작 위치와 목표 위치가
//begin, end에 주어질 때 최소 움직임의 수를 계산한다.
int bidir(int discs, int begin, int end) {
	if (begin == end) return 0;
	queue<int> q;
	//초기화를 0으로 하는데 주의
	memset(c, 0, sizeof(c));
	//정뱡향 탐색은 양수로, 역방향 탐색은 음수로 표시한다.
	q.push(begin); c[begin] = 1;
	q.push(end); c[end] = -1;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		int top[4] = { -1, -1, -1, -1 };
		for (int i = discs - 1; i >= 0; --i)
			top[get(here, i)] = i;
		for (int i = 0; i < 4; ++i)
			if (top[i] != -1)
				for (int j = 0; j < 4; ++j)
					if (i != j && (top[j] == -1 || top[j] > top[i])) {
						int there = set(here, top[i], j);
						//아직 방문하지 않은 정점인 경우(발견이 맞다고 봄)
						if (c[there] == 0) {
							c[there] = incr(c[here]);
							q.push(there);
						}
						//가운데에서 만난 경우
						else if (sgn(c[there]) != sgn(c[here]))
							return abs(c[there]) + abs(c[here]) - 1;
					}
	}
	return -1;
}

//30장 최단 경로 알고리즘-------------------------------------
다익스트라 수도코드 http://wcipeg.com/wiki/Dijkstra%27s_algorithm
구현1
intput G, s
for each v <- V(G)
	let dist[v] = oo	// 모든 정점까지의 거리는 무한대
let dist[s] = 0		// 시작지점
let T = @	// @: 공집합
while T != V(G)	// 모든 정점이 선택되면 종료
	let v <- V(G) , v !<- T such that dist[v] is minimal
	add v to T
	for each w <- V(G) such that (v, w) <- E(G)
		dist[w] = min(dist[w], disw[v] + wt(v, w))

구현2
input G, s
for each v <- V(G)
	let dist[v] = oo
add(s, 0) to Q	//우선순위 큐에 집어넣는다.: pair 형으로 두번째 인자가 first에 오도록 하자
while Q is nonempty
	let (v, d) <- Q such that d is minimal
	remove (v, d) from Q
	if dist[v] = oo
		dist[v] = d
		for each w <- V(G) such that (v, w) <- E(G)
			add (w, d + wt(v, w)) to Q
"구현2 를 cpp로 짜봤다. (통과함요)"
int n;
vector<pair<int, double>> adj[MX];
vector<double> dijkstra(int s) {
	vector<double> dist(n, INF);
	dist[s] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push(mp(0, src));
	while (!pq.empty()) {
		double cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();	// 한번 팝되면 영원히 거리는 영원히 cost임. (음수간선이 없다면 말이지)
		if (dist[here] == INF) {
			dist[here] = cost;	// 팝된놈 거리를 알박기하자
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].first;
				double nextDist = cost + adj[here][i].second;
				pq.push(nextDist, there);
			}
		}
	}
	return dist;
}

/* http://wcipeg.com/wiki/Shortest_Path_Faster_Algorithm */
Shortest Path Faster Algorithm: 수도코드
input G, v
for each u <- V(G)
	let dist[u] = oo
let dist[v] = 0	// 시작 거리를 설정
let Q be an initially empty queue
push(Q, v)
while not empty(Q)
	let u = pop(Q)
	for each (u, w) <- E(G)
		if dist[w] > dist[u] + wt(u, w)
			dist[w] = dist[u] + wt(u, w)	// 거리가 설정
			if w is not in Q
				push(Q, w)
"Note: We use an array of boolean flags to keep track of which vertices are currently in the queue."
// Q 가 우선순위 큐가 아니구나....
!!!!!!!!
"종만책은 음수처리해서 spfa인줄 알았는데... 비슷하다. 특히 
"if dist[w] > dist[u] + wt(u, w) 부분은 말이디
"게다가 원본 다익스트라는 거리가 한번 설정되면 영원히 변경안되는데
"종만책과 spfa는 거리가 계속 변경된다.(음수간선때문)

//개인적으론 다익스트라에 음수간선 처리를 더하면 SPFA 가 된다고 생각한다.

//p923 다익스트라의 최단 거리 알고리즘의 구현 //우선순위 큐 사용: bigO(E * log(V)
int V;//정점의 개수
//그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0;		//발견루틴
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;	//방문루틴
		int here = pq.top().second;
		pq.pop();

		//만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
		//사실 (cost, here)쌍중 최초 꺼내진 here로 dist[here]는 고정이며
		//그뒤 꺼내진 (cost, here)쌍은 무조건 dist[here] 보다 cost가 크다
		if (dist[here] < cost) continue;//쓰레기들 제거한다고 보면됨 //없어도 돌아감!!!! 
		//주석 처리해도 알고스팟에서 돌아감
		//수행속도는 있을때 38ms 없을때 43ms 임
		
		//여기서 부턴 here은 방문한것으로 취급된다 즉 dist[here]는 평생 바뀌지 않음 (음수간선이 없다면 말이지)
		//뭔말이냐 하면 dist[here] 가 continue로 빠져나가지 않는 순간 부터 dist[here]는 안바뀜
		//즉 최초 pop된 dist[here] 가 최단 거리라는 것임
		//최초 push된 dist[here]랑은 연관 없음!!!!

		//인접한 정점들을 모두 검사한다.
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			//더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			// 이런식으로 하면 음수 간선도 돌릴수 있다. 위의 쓰레기 제거 코드는 사실 음수 간선 대비한 코드였다 오오!!!!
			if (dist[there] > nextDist) {	//발견루틴
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}
//가독성을 위해 이걸 사용해도 됨
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

//p930 우선순위 큐를 사용하지 않는 다익스트라 알고리즘의 구현
//알고스팟 테스트 결과 속도는 우선순위 큐 이용한게 70프로 빠름
// 완전 그래프에선 이게 더 좋음 bigO(V^2)
vector<int> dijkstra2(int src) {
	vector<int> dist(V, INF);
	//각 정점을 방문했는지 여부를 저장한다.
	vector<bool> visited(V, false);
	dist[src] = 0; //visited[src] = false; //책의 오타로 보임, 없어도 알고스팟 통과
	while (true) {
		//아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
		int closest = INF, here;
		for (int i = 0; i < V; ++i)
			if (closest > dist[i] && !visited[i]) {
				here = i;
				closest = dist[i];
			}
		if (closest == INF) break;
		//가장 가까운 점을 방문한다.
		visited[here] = true; //!!!!

		//인접한 점을 발견한다.(거리를 세팅함은 발견이라고 보면 됨)
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			if (visited[there]) continue;
			int nextDist = dist[here] + adj[here][i].second;
			dist[there] = min(dist[there], nextDist);
		}
	}
	return dist;
}
// 바로 위에건 음수간선이 존재시 제대로 동작 못한다.: dist[3] 은 2가 아니라 1이 되어야 한다.
V = 4;
	adj[0].push_back(mp(2, 1));
	adj[0].push_back(mp(1, 10));
	adj[1].push_back(mp(3, -9));
	adj[2].push_back(mp(3, 1));
	vi sol = dijkstra2(0);



//p930 신호라우팅 문제 : 회선을 지날때마다 노이즈가 몇 배 증폭된다.
//노이즈의 증폭이 최소화 되는 값을 찾아라
//곱셈을 로그덧셈으로 바꾸고 다익스트라 돌린다.!!!!
// 증폭은 1이상의 실수이다.
1
7 14
0 1 1.3
0 2 1.1
0 3 1.24
3 4 1.17
3 5 1.24
3 1 2
1 2 1.31
1 2 1.26
1 4 1.11
1 5 1.37
5 4 1.24
4 6 1.77
5 6 1.11
2 6 1.2

8 * 32 => log8 + log32
0.1 * 0.01 => log 0.1 + log 0.01
상용로그라 가정하면 -1 + -2 
0.1 * 100 => log 0.1 + log 100 => -1 + 2 = 1
// 위 문제에선 log 값은 무조건 양수겠구나. 노이즈는 항상 증폭이니 말이지 : 밑이 e인 log(1) = 0.0
318ms로 통과됨요
https://algospot.com/judge/problem/read/ROUTING
const int MX = 10001;
int n;
vector<pair<int, double>> adj[MX];
double dijkstra(int src) {
	vector<double> dist(n, INF);
	dist[src] = 0;
	priority_queue<pair<double, int>> pq;	// 큰 값이 top 에 온다.
	pq.push(mp(-0, src));
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		rep(i, adj[here].size()) {
			int there = adj[here][i].first;
			double nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {	// 발견루틴 + 음수간선 처리용
				dist[there] = nextDist;
				pq.push(mp(-nextDist, there));
			}
		}
	}
	return dist[n - 1];
}
int main() {
	//freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> n;		//컴퓨터 수
		rep(i, n) {	//초기화를 안해줘서 6번 제출하고도 깨닫지 못함...
			adj[i].clear();	//초기화 안하면 segmentation fault 남(stack overflow 됨) !!!!
							// 간선이 계속 쌓이니 말이지
		}
		int m; cin >> m;//간선수
		rep(i, m) {
			int u, v;
			double edge;
			cin >> u >> v >> edge;
			edge = log(edge);
			adj[u].push_back(mp(v, edge));
			adj[v].push_back(mp(u, edge));	//양방향 전송이 가능하므로
		}
		double dist = dijkstra(0); // 0 : 시작점
		double sol = exp(dist);	// 자연로그 역함수
		printf("%.10lf\n", sol);
	}
	return 0;
}


https://algospot.com/judge/problem/read/BOJ
// 시작 - 도착점까지 깨는 벽의 수를 제일 적게 하라
다익스트라로 해결, 벽에 도달하는 간선의 경우 거리는 1이 된다.
// 알고스팟에 통과함 만세~~ 404 ms 걸림
// 다른 사람들은 dp 로 해결하더라. 나랑 별 속도 차이는 없음..
// 시간나면 다른 사람들 코드 봐도 좋을거얌.. dp가 이해가 안되..
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int n, m;	// x, y
char board[101][101];
bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= m || x >= n) return false;
	return true;
}
int dijkstra() {
	vi dist(m * n, INF);
	int src = 0 * n + 0;	// y * n + x
	dist[src] = 0;
	priority_queue<pii, vpii, greater<pii>> pq;
	pq.push(mp(0, src));
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		int y = here / n;
		int x = here % n;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			//printf("ny: %d, nx: %d\n", ny, nx);
			if (inRange(ny, nx) == false) continue;
			int there = ny * n + nx;
			// 벽을 만나는 경우 1 증가한다.
			int nextDist = cost + (int)(board[ny][nx] - '0');
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));
			}
		}
	}
	int snk = m * n - 1;
	return dist[snk];
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;	// x_size, y_size
	rep(i, m) 
		scanf("%s", board[i]);
	int sol = dijkstra();
	printf("%d", sol);
	return 0;
}


//p933 소방차 문제 : 그래프에 가상의 시작점을 하나 추가한 뒤 이 시작점에서 
//다른 모든 소방서로 가중치 0인 간선을 연결한다고 생각하면 쉬움 !!!!

//철인 N종 경기(NTHLON, 상)
//그래프로 나타내되 노드 수의 적정개수를 이해하면 된다.
//-180 -30 +X +(잡다간선들) +Y = 0 이 경우 중간 계산이 -210이 되는데 계산순서를 바꾸면
//절대값이 199를 벗어나지 않는다.
//-199 -50 -30 +100 +179 = 0
//-199 +100 -50 -30 +179 = 0

INPUT
2
1 2
7 3

OUTPUT
11 //두 선수가 비기는 코스의 최소 완주 시간

//P941 다익스트라 알고리즘을 이용해 철인 N종 경기 문제를 해결하기
//정점의 개수
int V;
//그래프의 인접리스트. (연결된 정점 번호, 간선 가중치)쌍을 담는다.
vector<pair<int, int> > adj[410]; //여유있게
const int START = 401;
//(A국 선수의 예상시간 - B국 선수의 예상 시간)의 점점 번호를 반환한다.
int vertex(int delta) {
	return delta + 200; // A - B + 200(양수화)
}
//a[] = A국 선수의 종목별 예상 시간
//b[] = B국 선수의 종목별 예상 시간
int solve(const vector<int>& a, const vector<int>& b) {
	//그래프를 만든다.
	V = 402;
	for (int i = 0; i < V; ++i) adj[i].clear();
	for (int i = 0; i < a.size(); ++i) {
		int delta = a[i] - b[i];
		//시작지점과 인접한 간선을 세팅
		adj[START].push_back(make_pair(vertex(delta), a[i]));//!!!! a한놈만 가중치로 넣음
	}
	//현재 차이
	for (int delta = -200; delta <= 200; ++delta) {
		//i번 종목을 뒤에 붙인다면? 
		//vertex(delta)정점에 i번 간선이 붙어 다른 정점과 이어지게 하기
		for (int i = 0; i < a.size(); ++i) {
			int next = delta + a[i] - b[i];
			//시간 차이의 절대 값이 200을 넘는 정점은 만들 필요가 없다.
			if (abs(next) > 200) continue;
			adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
		}
	}
	vector<int> shortest = dijkstra(START);
	int ret = shortest[vertex(0)];
	if (ret == INF) return -1;
	return ret;
}
http://codeforces.com/contest/789/problem/E	// 참고 문제



//p946 벨만-포드 알고리즘의 구현(음수 간선, 사이클에서도 사용가능)
//정점의 개수
int V;
//그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치)쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
//음수 사이클이 있을 경우 텅 빈 배열을 반환
vector<int> bellmanFord(int src) {
	//시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	//V번 순회한다.(V-1번 순회시 답은 결정됨, 단 음수 사이클 판정은 V번째에서 가능하니까)
	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for (int here = 0; here < V; ++here)
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				//(here, there) 간선을 따라 완화를 시도한다.
				if (upper[there] > upper[here] + cost) {
					//성공
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		//모든 간선에 대해 완화가 실패했을 경우 V-1 번도 돌 필요 없이 곧장 종료한다.
		if (!updated) break;
	}
	//V번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
	if (updated) upper.clear();
	return upper;
}
//!!!! 주의사항: 빠지기 쉬운 함정
//upper[DST]의 값이 INF가 아니라고 해도 길이 없을 수 있다.
//무한대(INF)를 경로가 없다의 기준으로 바로 삼으면 안됨
//음의 가중치로 있다면 그것이 완화 작용을 하기 때문에
//경로가 존재하는지 확인방법 : 큰 값 M에 대해 upper[DST] < INF - M 인지를 확인해라!!!!

// 또한 INF도 numer_limit<>::max()를 써선 절대 안된다. 오버플로우 위험이 있다고 봄
// 아니네 오버플로우는 일어 나진 않음... 대신 비교문에서 
// upper[there] > upper[here] + cost 에서 큰 자료형으로 형변환을 해야 하는 귀차니즘이 존재
// 그냥 INF = 987654321로 해뿌자

//p951 벨만 포드 알고리즘을 이용해 시간여행 문제 해결하기
// 정점 수 100개 간선수 1000개
// O(100 * 100 * 1000) = O(v^2 * e)
INPUT
4 4	//정점(은하)의 수, 간선(웜홀)의 수
0 2 -7
0 3 -4
3 2 9
2 1 3
OUTPUT
-4 8 //가장 빠른 시간, 가장 느린 시간
//주의할 점: 그래프에 음수 사이클이 존재한다고 해서 가중치가 음의 무한대인 경로가
//항상 존재하지는 않는다.
int V;
vector<pair<int, int> > adj[MAX_V];	//방향그래프
//reachable[u][v] = u에서 v로 가는 경로가 있는가?
bool reachable[MAX_V][MAX_V]; //이거 짜는 코드가 필요한데...
//reachable 이건 플로이드를 이용하면 쉽다.
//src에서 target으로 가는 최단 거리를 계산한다.
//가중치가 음의 무한대인 경로가 있으면 -INF를 반환한다.
int bellman2(int src, int target) {
	//시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
	vector<int> upper(V, INF);
	upper[src] = 0;
	// V-1 번 순회한다.
	for (int iter = 0; iter < V - 1; ++iter)
		for (int here = 0; here < V; ++here)
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				//(here, there)간선을 따라 완화를 시도한다.
				upper[there] = min(upper[there], upper[here] + cost);
			}
	//음수 사이클의 존재 여부를 확인하자.
	for (int here = 0; here < V; ++here)
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			//완화가 성공한다면 here와 there는 모두 음수 사이클에 들어 있다.
			if (upper[there] > upper[here] + cost)
				//경로(src ~ target)가 이 음수 사이클을 포함하는가?
				if (reachable[src][here] && reachable[there][target])
					return -INF;
		}
	return upper[target];
}
//윗문제의 최장경로는 그래프의 부호를 전부 바꾸고 bellman2를 돌리면 된다.
한가지 고찰할 점은 임의의 그래프상에서 단순 최장 경로(사이클이 없는)를 찾는 문제는
NP-완전 문제임 
위 코드가 부호를 바꾸면 최장경로를 구할 수 있는 이유는 사이클을 취급했기 때문에라고 생각하자
물론 사이클이 없는 그래프라는 전제가 된다면야 가중치 부호 바꾸고 벨만 돌리면 단순 최장 거리를
NP-완전이 아닌 bellmanFord 복잡도로 구할 수 있다!!!!
임의의 그래프 , 단순 최장 경로 구하기 : NP complete(사이클이 있는 경우), bellmanFord(사이클이 없는 경우)
임의의 그래프 , 일반 최장 경로 구하기 : bellmanFord 복잡도
1, 3, 2, 5, 9, 7 => -1, -3, -2, -5, -9, -7



const int INF	= 987654321;
const int mx = 105;
bool reachable[mx][mx];
int v, m;	// 은하계 수, 웜홀 수
vpii adj[mx];
void floyd() {
	for (int i = 0; i < v; ++i) reachable[i][i] = true;
	for (int k = 0; k < v; ++k)
		for (int i = 0; i < v; ++i)
			for (int j = 0; j < v; ++j)
				reachable[i][j] = reachable[i][j]
								|| (reachable[i][k] && reachable[k][j]);
}
int bellman(int src, int dst) {
	vi upper(v, INF);
	upper[src] = 0;
	for (int iter = 0; iter < v - 1; ++iter)
		for (int here = 0; here < v; ++here)
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				upper[there] = min(upper[there], upper[here] + cost);
			}
	for (int here = 0; here < v; ++here)
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			if (upper[there] > upper[here] + cost) {
				if (reachable[src][here] && reachable[there][dst])
					return -INF;
			}
		}
	return upper[dst];
}

vpii adj2[mx];
int bellman2(int src, int dst) {
	vi upper(v, INF);
	upper[src] = 0;
	for (int iter = 0; iter < v - 1; ++iter)
		for (int here = 0; here < v; ++here)
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj2[here][i].first;
				int cost = adj2[here][i].second;
				upper[there] = min(upper[there], upper[here] + cost);
			}
	for (int here = 0; here < v; ++here)
		for (int i = 0; i < adj2[here].size(); ++i) {
			int there = adj2[here][i].first;
			int cost = adj2[here][i].second;
			if (upper[there] > upper[here] + cost) {
				if (reachable[src][here] && reachable[there][dst])
					return -INF;
			}
		}
	return upper[dst];
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		memset(reachable, 0, sizeof(reachable));
		cin >> v >> m;
		rep(i, mx) adj[i].clear();
		rep(i, mx) adj2[i].clear();
		rep(i, m) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back(mp(b, d));
			adj2[a].push_back(mp(b, -d));
			reachable[a][b] = true;
		}
		floyd();	// 도달 가능성 체크
		int sol1 = bellman(0, 1);
		int sol2 = bellman2(0, 1);

		if (sol1 >= INF - 1000 * 105) {
			// 한번만 출력하면 됨. 이게 도달 못하는 거면
			// sol2 도 도달 못한는 거기 때문에 여기서 continue;
			cout << "UNREACHABLE";
			cout << '\n';
			continue;
		}
		else if (sol1 == -INF) cout << "INFINITY";	// 무한히 과거로 감
		else cout << sol1;

		cout << " ";

		if (sol2 >= INF - 1000*105) cout << "UNREACHABLE";	// 필요는 없다.
		else if (sol2 == -INF) cout << "INFINITY";	// 무한히 미래로 감.
		else cout << -sol2;	// 부호를 바꾸어 출력한다.
		
		cout << '\n';
	}
	return 0;
}




//플로이드의 모든 쌍 최단 거리 알고리즘
//p954 플로이드 알고리즘의 프로토타입 구현
//정점의 개수
int V;
//그래프의 인접 행렬 표현.
//adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
//-1로 세팅 안함을 조심하자!!!!
int adj[MAX_V][MAX_V];
int C[MAX_V][MAX_V][MAX_V]; //답의 접근 src, target 
//C[V-1][src][target] 이 (0~V-1번을 경유점후보로 하는)src ~ target의 최단 거리가 된다.
void allPairShortestPath1() {
	//C[0]을 초기화 //0번 정점이 경유점 후보
	for (int i = 0; i < V; ++i) 
		for (int j = 0; j < V; ++j)
			if (i != j)
				C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
			else
				C[0][i][j] = 0;
	//C[k - 1]이 있으면 C[k]를 계산할 수 있다.
	for (int k = 1; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				C[k][i][j] = min(C[k - 1][i][j],
								 C[k - 1][i][k] + C[k - 1][k][j]);
}
//C[k][i][j] = min(C[k - 1][i][j], C[k - 1][i][k] + C[k - 1][k][j]); //!!!!

//메모리 줄이는 법 
int C[2][MAX_V][MAX_V];
void floyd_my() {
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			if (i != j)
				C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
			else
				C[0][i][j] = 0;
	for (int k = 1; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				C[k % 2][i][j] = min(C[(k - 1) % 2][i][j], 
									 C[(k - 1) % 2][i][k] + C[(k - 1) % 2][k][j]);
}

//p956 플로이드 알고리즘의 구현(최종) O(v^3)
//정점의 개수
int V;
//그래프의 인접 행렬 표현
//adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
//플로이드의 모든 쌍 최단 거리 알고리즘
void floyd() {
	for (int i = 0; i < V; ++i) adj[i][i] = 0; //!!!!
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	//총 10개의 정점이 있다면 adj[i][k(고정)] , adj[k(고정)][j]
	//최대 100개중 20개의 간선만 값이 고정된 상태를 가지는 구나
	//20개의 고정된 놈들의 2개 선택한 합과
	//adj[i][j]이전값 중 작은 것으로 세팅된다. 
	//20개의 간선이 고정이란 의미를 잘 기억해라
	//adj[i][j]가 이 20개에 포함된 놈이면 그 놈은 값 변경이 없다!!!!
	//k 가 1인 상태라 치면 다음 값을 구한다면
	//다음값인 adj[i][k] 는  이전값 들로 이루어지며 
	//min(adj[i][k], adj[i][k] + adj[k][k])이며
	//이전값 adj[k][k] 는 당연히 0이니까 adj[i][k] == adj[i][k] 고정이 유지 되는군
}

//p957 플로이드 알고리즘에서 실제 최단 경로 계산하기
//정점의 개수
int V;
//그래프의 인접 행렬 표현.
//adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
//via[u][v] = u에서 v까지 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점
//-1로 초기화해 둔다.
int via[MAX_V][MAX_V];
//플로이드의 모든 쌍 최단 거리 알고리즘
void floyd2() {
	for (int i = 0; i < V; ++i) adj[i][i] = 0;
	memset(via, -1, sizeof(via));
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					via[i][j] = k; //경유점들 중 가장 큰 노드번호가 저장된다.
					//경유점에는 양 끝점은 포함안된다. !!!!
					adj[i][j] = adj[i][k] + adj[k][j];
				}
}
//u 에서 v로 가는 최단 경로를 계산해 path에 저장한다.
void reconstruct(int u, int v, vector<int>& path) {
	//기저사례
	if (via[u][v] == -1) {//경유점이 없다면
		path.push_back(u);		//push_back이 한번만 실행하는 경우는 최초호출이 같은 노드
		if (u != v) path.push_back(v);	//즉 (src == dst)인 경우다
	}
	else {
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back(); //w가 중복으르 들어가므로 지운다.
		reconstruct(w, v, path);
	}
}
3---1---0---2 //via[3][2] = 1, via[1][2] = 0

//!!!! u에서 v로 도달 가능성 있는지 세팅하는 방법
C[k][u][v] = C[k - 1][u][v] || (C[k - 1][u][k] && C[k - 1][k][v]);
int V;
bool adj[MAX_V][MAX_V]; //도달가능성으로 덮어진다. 
void floyd3() {
	for (int i = 0; i < V; ++i) adj[i][i] = true;
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j) {
				//최소치를 구하는 연산을 or연산으로
				//덧셈 연산을 and연산으로 바꿨어용
				adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
			}
}



//음주 운전 단속(DRUNKEN, 중)
//p963 플로이드 알고리즘을 개선해 음주 운전 문제를 해결하는 알고리즘의 구현
//그래프의 인접 행렬 표현
int V, adj[500][500];
//각 정점에서 음주 운전 단속을 할 때 걸리는 시간
int delay[500];	//
int W[500][500];
//입력을 받을 때 1부터 시작하는 정점 번호를 0부터 시작하도록 변경했다고 가정한다.
void solve() {
	//모든 정점들을 예상 시간 별로 정렬한다.
	vector<pair<int, int> > order;
	for (int i = 0; i < V; ++i)
		order.push_back(make_pair(delay[i], i));
	sort(order.begin(), order.end());
	//정점을 하나도 거치지 않고 얻을 수 있는 최단 경로
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			if (i == j)
				W[i][j] = 0;
			else
				W[i][j] = adj[i][j];
	int ret = INF; //책에는 있던데 왜 있는지 모르겠다...
	for (int k = 0; k < V; ++k) {
		//k번째로 예상 시간이 적게 걸리는 정점 w까지를 지나서 얻을 수 있는 최단 거리
		int w = order[k].second;	//!!!!
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);	//갱신이 된다면 이순간엔 w는 반드시 지나가는 놈이 된다.
				W[i][j] = min(W[i][j], adj[i][w] + delay[w] + adj[w][j]);
			}
	}
	/*
	//w = 0, 1, 2, 3 : delay[0], delay[1] ...
	W[i][j] = adj[i][j]
	W[i][j] = min W[i][j], adj[i][0] + delay[0] + adj[0][j]	//딜레이가 {가장 작은 점} 을 경유 혹은 아무 경유없는 것 중 작은값
	W[i][j] = min W[i][j], adj[i][1] + delay[1] + adj[1][j]	//딜레이가 {가장 작은 점, 그 다음 점} 
	W[i][j] = min W[i][j], adj[i][2] + delay[2] + adj[2][j]
	W[i][j] = min W[i][j], adj[i][3] + delay[3] + adj[3][j]
	W[i][j] = min W[i][j], adj[i][4] + delay[...] + adj[4][j]
	W[i][j] = min W[i][j], adj[i][w] + delay[order[V-1].second] + adj[w][j]
	
	즉 전부 돌렸을때는 아래중 최소값이 세팅되겠군요
	숫자는 노드의 번호라고 생각하지 말고 delay량이라고 보시오
	adj[i][j] : 직접 연결된 경우(경유점이 없는 경우)
	adj[i][0] =	adj[i][0] + delay[0] + adj[0][j] //경유점 후보가 한놈인데 그놈 반드시 지나감
	adj[i][1] = adj[i][1] + delay[1] + adj[1][j] //경유점 후보가 두놈인데 그중 딜레이가 가장 큰 놈1은 반드시 지나감
	...
	adj[i][k] = adj[i][k] + delay[k] + adj[k][j] //경유점 후보가 k개인데 그 중 딜레이가 가장 큰 k는 반드시 지나감
	*/
}
input
8 12	// 정점수, 간선순
8 6 5 8 3 5 8 4	// 정점당 딜레이
1 6 9	// 간선들: 정점이 1부터 시작임
1 2 3
2 8 3
6 8 5
6 7 3
8 7 3
6 5 5
4 5 7
3 4 4
3 5 2
2 3 6
7 5 1
2		// 질의 갯수
1 5		// 1번에서 5번으로 가는 순간 최선으로 간다고 할시 최악의 시간
6 3
output
17
10


const int INF = 100 * 505;
int v, m, adj[500][500];
int delay[500];
int w[500][500];
void solve() {
	vpii order;
	rep(i, v) order.push_back(mp(delay[i], i));
	sort(order.begin(), order.end());
	rep(i, v) rep(j, v) {
		if (i == j) 
			w[i][j] = 0;
		else 
			w[i][j] = adj[i][j];
	}

	for (int k = 0; k < v; ++k) {
		int kk = order[k].second;
		rep(i, v) rep(j, v) {
			adj[i][j] = min(adj[i][j], adj[i][kk] + adj[kk][j]);
			w[i][j] = min(w[i][j], adj[i][kk] + delay[kk] + adj[kk][j]);
		}
	}

}
int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	cin >> v >> m;
	rep(i, v) rep(j, v) w[i][j] = INF, adj[i][j] = INF;
	
	rep(i, v) cin >> delay[i];
	rep(i, m) {
		int a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		adj[a][b] = d;
		adj[b][a] = d;
	}
	solve();
	int query; cin >> query;
	rep(i, query) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << w[a][b] << '\n';
	}
	return 0;
}


//p967 선거공약(PROMISES, 중)
// adj[][]는 floyd() 의 수행 결과
int V, adj[200][200];
// 간선 (a,b) 를 추가했을 때 그래프의 최단 거리 배열 adj를
// 적절히 갱신한다. 간선이 아무런 의미가 없을 경우 false를 반환한다.
bool update(int a, int b, int c) {	
	if(adj[a][b] <= c) return false;
	for(int x = 0; x < V; ++x) 
		for(int y = 0; y < V; ++y) 
			// x~y 최단경로가 (a,b)를 이용하려면
			// x~a-b~y 혹은 x~b-a~y 의 형태를 가져야 한다. //!!!!
			"정점경유 플로이드 알고리즘을 간선경유로 응용"
			adj[x][y] = min(adj[x][y], 
						min(adj[x][a] + c + adj[b][y],
							adj[x][b] + c + adj[a][y]));
	return true;
}
void display() {
	for(int i = 0; i < V; ++i) {
		for(int j = 0; j < V; ++j) 
			printf("%d ", adj[i][j]);
		printf("\n");
	}
	printf("===\n");
}
int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	int M, N;
    	cin >> V >> M >> N;
    	for(int i = 0; i < V; ++i) 
    		for(int j = 0; j < V; ++j) 
    			if(i == j)
    				adj[i][j] = 0;
				else
					adj[i][j] = 987654321;
		for(int i = 0; i < M; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a][b] = adj[b][a] = min(adj[a][b], c);
		}
		for(int k = 0; k < V; ++k) 
			for(int i = 0; i < V; ++i) 
				for(int j = 0; j < V; ++j) 
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		//display();
		int meaningless = 0;
		for(int i = 0; i < N; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			if(!update(a, b, c))
				++meaningless;

			//display();
			
		}
		cout << meaningless << endl;
    }
}

//31장 최소 스패닝 트리(무방향 그래프 기준)-------------------------------------
//방향그래프의 MST는 "MCA"라고 하며 따로 놀고 있네(책에는 없어용)

//p973 크루스칼의 최소 스패닝 트리 알고리즘 O(E(logE))


//트리를 이용해 상호 배제적 집합을 구현한다.
//자세한 구현은 25장을 참조한다.
struct DisjointSet;
const int MAX_V = 100;
//정점의 개수
int V;
//그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
//주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 selected에
//저장하고, 가중치의 합을 반환한다.
int kruskal(vector<pair<int, int> >& selected) { 
	int ret = 0;
	selected.clear();
	//(가중치, (정점1, 정점2))의 목록을 얻는다.
	vector<pair<int, pair<int, int> > > edges; //!!!!
	for (int u = 0; u < V; ++u)
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			int cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	//가중치 순으로 정렬
	sort(edges.begin(), edges.end());	// 복잡도 O(ElogE)
	//처음엔 모든 정점이 서로 분리되어 있다.
	DisjointSet sets(V);
	for (int i = 0; i < edges.size(); ++i) {
		//간선 (u, v)를 검사한다.
		int cost = edges[i].first;
		int u = edges[i].second.first;	//!!!! 이 형식 기억해라
		int v = edges[i].second.second;
		//이미 u와 v가 연결되어 있을 경우 무시한다. //사이클 방지
		if (sets.find(u) == sets.find(v)) continue;
		//이 둘을 합친다. //연결시킴
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
} 

//프림 알고리즘 수도 코드
input G
let u = some vertex <- V(G)	// u는 그래프의 어떤 점
let T = ({u}, @ )	// @ : 공집합
while V(T) != V(G)	// 점이 모두 선택되면 종료
	// V(T): mst의 점들, wt(v,w): (mst의 점과 거기에 없는 점) 거리가 가장 작은 엣지
	let (v, w) <- E(G) such that v <- V(T), w !<- V(T), and wt(v,w) is minimal
	add w to V(T)
	add (v, w) to E(T)	// 엣지 저장

//p977 프림 알고리즘의 구현 // 다익스트라랑 매우 유사하다
//다익스트라는 각 정점에 대해 지금까지 알려진 최단 거리를 저장하는 것이었으며
//프림은 마지막 간선의 가중치를 저장하고 있다는 점만이 다르다. !!!!
const int MAX_V = 100;
const int INF = 987654321;
//정점의 개수
int V;
//그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
// 음수간선에 대해서도 무난히 돌아갈거라 예상함
vector<pair<int, int> > adj[MAX_V];
//주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 SELECTED에
//저장하고, 가중치의 합을 반환한다.
int prim(vector<pair<int, int> >& selected) {	// 이거 복잡도 그리 안 느릴듯. 알아보자.
	selected.clear();
	//해당 정점이 트리에 포함되어 있나?
	vector<bool> added(V, false);
	//트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장한다.
	vector<int> minWeight(V, INF), parent(V, -1);
	//가중치의 합을 저장할 변수
	int ret = 0;
	//0번 정점을 시작점으로: 항상 트리에 가장 먼저 추가한다.
	minWeight[0] = parent[0] = 0;	//1. 발견루틴
	for (int iter = 0; iter < V; ++iter) {
		//다음에 트리에 추가할 정점 u를 찾는다.
		int u = -1;
		for (int v = 0; v < V; ++v)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v])) //!!!!깔끔하다
				u = v;
		//(parent[u], u)를 트리에 추가한다.
		if (parent[u] != u)
			selected.push_back(make_pair(parent[u], u));
		ret += minWeight[u];
		added[u] = true; //2. 방문루틴

		//u에 인접한 간선 (u, v)들을 검사한다.!!!!
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			int weight = adj[u][i].second;
			//아직 방문은 안했고 && 도달 거리가 기존보다 짧은 놈이면
			if (!added[v] && minWeight[v] > weight) {
				parent[v] = u;				//1. 발견루틴
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}

//위 코드를 힙을 써서 짜기(앞의 다익스트라 알고리즘 참고하삼
//내가 짜봤는데 맞는진 잘 모르겠네.. 맞겠지.
bigO(Elog(V))	//완전그래프에선 별로 이득이 없음// 게다가 음수 간선에 대해선 테스트 해봐야함...ㅠㅠ
"...": 위에건 복잡도가 최악인 경우 V^2 임 괜찮다.
int V;
vector<pair<int, int> > adj[MAX_V];
int prim2(vector<pair<int, int> >& selected) {
	selected.clear();
	vector<bool> added(V, false); //방문여부
	vector<int> minWeight(V, INF), parent(V, -1);
	int ret = 0;
	minWeight[0] = parent[0] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, 0)); //가중치 0, 시작지점 0
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//아래 두 조건 중 하나만 있어도 된다.(added 변수가 없는게 낫네) : 아니다 added 빼면 안된다.
		// minWeight[here] < cost 구문을 빼도 됨.. 
		if (added[here] || minWeight[here] < cost) continue; //쓰레기는 걸러내자
		added[here] = true;
		if (parent[here] != here)
			selected.push_back(make_pair(parent[here], here));
		ret += minWeight[here];

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int thereWeight = adj[here][i].second;
			if (minWeight[there] > thereWeight) {
				parent[there] = here;
				minWeight[there] = thereWeight;
				pq.push(make_pair(-thereWeight, there));
			}
		}
	}
	return ret;
}




//p979 근거리 네트워크(LAN, 하)
//일부 건물들만이 서로 근거리 네트워크로 연결되어 있는 상태에서 모든 건물들을
//연결하려고 한다. 모든 건물을 연결하기 위해 추가로 설치해야 할 케이블 길이의
//최소합을 계산하라
//--> 기존 연결되는 간선들의 가중치를 0으로 두고, 설치해야할 케이블의 길이를
//설정한뒤 쿠로스칼 OR 프림 mst알고리즘을 돌린다.
https://algospot.com/judge/problem/read/LAN
// 통과함요
double prim2() {
	vector<bool> added(n, false); //방문여부
	vector<double> minWeight(n, INF);
	double ret = 0.0;
	minWeight[0] = 0;
	priority_queue<pair<double, int>> pq;
	pq.push(mp(0, 0));	//가중치 0, 시작지점 0
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		// 아래 두 조건 중 하나만 있어도 된다(added변수가 없는게 낫네.. 음수간선도 처리하려면 말이지)
		if (added[here] || minWeight[here] < cost) continue; // 쓰레기 걸러내자
		added[here] = true;	//방문 표시함
		ret += minWeight[here];
		for (int there = 0; there < n; ++there) {
			if (here == there) continue;
			double thereWeight = adj[here][there];
			if (minWeight[there] > thereWeight) {
				minWeight[there] = thereWeight;
				pq.push(mp(-thereWeight, there));
			}
		}
	}
	return ret;
}
"added 없으니까 예시 통과가 안된다 ...이런: 
"다익스트라 변종인 spfa 와는 다르게 음수 간선이 있어도 프림은 먼저 방문하게 만든 간선을 무시 못함"
"당연히 그려보면 자명한것을 알 수 있다."
a---b , 10
b---c , 100

a---d , 11
c---d , -100

mst는
a에서 b로 연결
a에서 d로 연결
d에서 b로 연결
 
다익스트라변종(spfa)에서 a에서 d로 연결되는 길은 초반에 넣어졌다가 나중에 음수간선덕에 없애게 된다.
mst는 당연히 이 간선이 필요하며 음수 간선도 적용가능하다.
 

const int MX = 501;
int n, m;	//건물수, 케이블수
double adj[MX][MX];
double prim3(vector<pair<int, int>>& sltd) {
	sltd.clear();
	vector<bool> added(n, false);
	vector<double> minWeight(n, INF), prnt(n, -1);
	double ret = 0.0;
	minWeight[0] = prnt[0] = 0;
	priority_queue<pair<double, int>> pq;
	pq.push(mp(0, 0));	//가중치 0, 시작지점 0
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//...
		//이건 돌아감 if (added[here] || minWeight[here] < cost) continue; // 쓰레기 걸러내자
		//이건 안됨 if (minWeight[here] < cost) continue;
		if (added[here]) continue; //방문한것이면 생략
		added[here] = true;
		if (prnt[here] != here)
			sltd.push_back(mp(prnt[here], here));
		ret += minWeight[here];
		for (int there = 0; there < n; ++there) {
			if (here == there) continue;
			double thereWeight = adj[here][there];	// 기 방문한 there의 minWeight[there(3)] 이 2.37 인 상태에서
			if (minWeight[there] > thereWeight) {	// adj[here(5)][there(3)] 이 0 이면 좆됨
				prnt[there] = here;					// minWeight 가 0이 되도록 전부 바꾸어야 되네
				minWeight[there] = thereWeight;		// minWeight는 전 트리와 정점과의 거리기에
				pq.push(mp(-thereWeight, there));	// 다익스트라처럼 한번 설정되면 끝나는게 아니라 그런가 봄.
			}
		}
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> n >> m;
		vi x(n), y(n);
		rep(i, n) cin >> x[i];
		rep(i, n) cin >> y[i];
		rep(i, n) rep(j, n) if (i != j)
			adj[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
		rep(i, m) {
			int u, v;
			cin >> u >> v;
			adj[u][v] = 0; adj[v][u] = 0;
		}
		vpii sltd;
		double sol = prim3(sltd);
		printf("%.10lf\n", sol);
	}
	return 0;
}


//p981 여행 경로 정하기 (TPATH, 상)
//두 도시를 여행하려고 함. 경로의 속도 차가 크지 않는 구간을 찾아라
//출발역 0번, 도착역 V - 1번
//모든 구간은 양방향 통행이며, 속도는 1000이하의 자연수

//p984 minUpperBound()를 이용해 여행 경로 문제 해결하기
const int INF = 987654321;
int V, E;
//그래프의 연결 리스트 표현
vector<pair<int, int> > adj[MAX_V];
//모든 간선의 가중치의 목록. 정렬(오름차순)해 둔다.
vector<int> weights;
//가중치가 weights[low]이상인 간선으로 시작점과 도착점을 연결하는 경로를
//만들기 위해 필요한 "경로의 최소 상한"을 계산한다. 두 정점을 연결할 수 없을
//경우 큰 값을 반환한다.
int minUpperBound(int low);
//0과 V-1을 연결하는 경로 중 가중치의 상한과 하한 차이의 최소 값을 계산한다.
int minWeightDifference() {
	int ret = INF;
	for (int i = 0; i < weights.size(); ++i)
		//최소상한 - 하한
		ret = min(ret, minUpperBound(i) - weights[i]);
	return ret;
}


//p985 이분 검색으로 minUpperBound()구현하기
//0과 V - 1을 잇는 경로 중 사용 가중치 범위가 [lo, hi] 안인 경로가 있는가?
bool hasPath(int lo, int hi); //가중치 범위를 만족하는 조건에서
//ㄴ> bfs or dfs 를 수행해서 0번 점에서 V-1번 점으로 가는지 검사
int binarySearchMinUpperBound(int low) {
	//반복문 불변식: //내가 국어가 딸리나? 코드는 이해 되는데 주석은 이해안됨
	//1. 가중치가 [weights[low], weights[lo]] 범위에 있는 간선을 사용하면 두 정점을
	//연결할 수 없다.
	//2. 가중치가 [weights[low], weights[hi]] 범위에 있는 간선을 사용하면 두 정점을
	//연결할 수 있다.
	int lo = low - 1;
	int hi = weights.size();
	while (lo + 1 < hi) {//hi가 lo보다 적어도 2커야 돌아감
		int mid = (lo + hi) / 2;	//그렇기 때문에 mid는 많이 커봐야 hi보다 1작다
		//길이 있으면 hi를 낮추고, 길이 없으면 lo를 키운다
		if (hasPath(weights[low], weights[mid]))
			hi = mid;
		else 
			lo = mid;//lo는 많이 커봐야 hi보다 1 작다
	}
	if (hi == weights.size()) return INF;
	return weights[hi];

	//고찰: lo: 4, hi: 6 이며 4,5,6인덱스는 모두 hasPath가 참이면
	//mid = (4 + 6) / 2 = 5 이면 hi 는 5가 되고 루프는 종료다
	//그때 4는 생까지 않는가?
	//답 : 애초에 4가 hasPath가 참이면 lo가 4가 될수가 없다!!!!
}

//x o 는 lo hi 사이에 있는 놈들임(선에 겹치지 않는다.)
//lo , hi를 가지고 mid를 구해서 숨통을 조이자!!
-10123456789abc  lo  hi  mid
  xxxxxxxxoooo   -1  12  5
        xxoooo   5   12  8
        xx       5   8   6
         x       6   8   7
		 %       7   8   (lo + 1 < hi)에 위배되어 루프 탈출

//책에 없는 코드: bfs로 짜도 됨
//0과 V-1을 잇는 경로중 사용가중치 범위가 [lo, hi]인 경로가 있는가?
int seen[MAX_V];
bool dfs(int here, int lo, int hi) {
	if (here == V - 1) return true;
	seen[here] = 1;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i].first;
		int edge = adj[here][i].second;
		if (edge < lo || hi < edge || seen[there]) continue;
		if (dfs(there, lo, hi)) return true;
	}
	return false;
}
bool hasPath(int lo, int hi) {
	memset(seen, 0, sizeof(seen));
	return dfs(0, lo, hi);
}
	
	
다시 정리	O(E * logE * E) : // 각 low 간선들 * 바이너리서치 * dfs 복잡도
const int INF = 987654321;
int V, E;
//그래프의 연결 리스트 표현
vector<pair<int, int> > adj[MAX_V];
vi weights;
int seen[mxv];
bool dfs(int here, int lo, int hi) {
	if (here == V - 1) return true;
	seen[here] = 1;
	rep(i,adj[here].size()) {
		int there = adj[here][i].first;
		int edge = adj[here][i].second;
		if (edge < lo || hi < edge || seen[there]) continue;
		if (dfs(there, lo, hi)) return true;
	}
}
bool hasPath(int lo, int hi) {
	memset(seen, 0, sizeof(seen)); return dfs(0, lo, hi);
}
int minUB(int low) {
	int lo = low - 1; int hi = weights.size();
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (hasPath(weights[low], weights[mid])) hi = mid;
		else lo = mid;
	}
	if (hi == weights.size()) return INF;
	return weights[hi];
}
int minWeightDiff() {
	int ret = INF;
	rep(i,weights.size()) ret = min(ret, minUB(i) - weights[i]);
	return ret;
}	
	
//p986 변형한 크루스칼 알고리즘으로 여행 경로 문제 해결하기 //!!!!
//(가중치, (정점1, 정점2))의 목록. 미리 정렬해 둔다.
vector<pair<int, pair<int, int> > > edges; //한번만 정렬하면 됨
int kruskalMinUpperBound(int low) {
	DisjointSet sets(V);
	for (int i = 0; i < edges.size(); ++i) {
		if (edges[i].first < weights[low]) continue;
		//여기선 사이클 검사를 하지 않네(같은 집합이면 merge해도 뭐 같겠지만..)
		//merge내부에서 같은 집합인지 확인 하는 구나!!!!
		//edges[i]를 그래프에 추가하자
		sets.merge(edges[i].second.first, edges[i].second.second);
		//0과 V - 1이 연결되었다면 마지막에 추가한 간선의 가중치를 반환한다.
		if (sets.find(0) == sets.find(V - 1))
			return edges[i].first;
	}
	return INF;
}


// 알고스팟 통과소스
const int INF	= 987654321;
struct DSJSet {
	vi prnt, rank;
	DSJSet(int n) : prnt(n), rank(n, 1) {
		rep(i, n) prnt[i] = i;
	}
	int find(int u) {
		if (u == prnt[u]) return u;
		return prnt[u] = find(prnt[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		prnt[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};
vpii adj[2020];
int N, M;
vi weights;
vector<pair<int, pii>> edges;
int kMinUB(int low) {
	DSJSet sets(N);
	rep(i, edges.size()) {
		if (edges[i].first < weights[low]) continue;
		sets.merge(edges[i].second.first, edges[i].second.second);
		if (sets.find(0) == sets.find(N - 1))
			return edges[i].first;
	}
	return INF;
}

int getSol() {
	int ret = INF;
	rep(i, weights.size()) ret = min(ret, kMinUB(i) - weights[i]);
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> N >> M;
		rep(i, 2020) adj[i].clear();
		weights.clear();
		edges.clear();
		rep(i, M) {
			int u, v, c;
			cin >> u >> v >> c;
			adj[u].push_back(mp(v, c));
			weights.push_back(c);
			edges.push_back(mp(c, mp(u, v)));
		}
		sort(weights.begin(), weights.end());
		sort(edges.begin(), edges.end());
		int sol = getSol();
		cout << sol << endl;
	}
	return 0;
}





//p987 여행 경로 문제를 해결하는 가장 무식한 알고리즘
//경우에 따라선 이런 무식한 방법도 빠르게 도출할 수 있어야 한다.
//모든 상한/하한의 쌍에 대해 경로가 존재하는지 전부 확인해보고,
//경로가 존재하는 최소 너비를 반환한다.
int brute() {
	int ret = INF;
	for (int lo = 0; lo < weights.size(); ++lo)
		for (int hi = lo; hi < weights.size(); ++hi) {
			//상한/하한의 쌍이 주어질 때, 두 점을 잇는 경로가 존재하는가?
			if (hasPath(weights[lo], weights[hi])) {
				ret = min(ret, weights[hi] - weights[lo]);
				break;
			}
		}
	return ret;
}
//hint 간선들의 가중치가 10, 20, 30, 40, 50 중의 하나라고 합시다. 하한을 10으로
//뒀을 때 필요한 최소 상한이 40이었다고 하지요. 그뒤 하한을 20으로 늘려서 다시
//시도합니다. 이 때 최소 상한은 40보다 작을까요? 안 그렇지요!!
//p988 무식한 알고리즘 최적화하기
//brute()를 더 빠르게 개선한 알고리즘
//!!!! 응용하기 좋은 코드다. 충족하는 최소 범위 찾는 문제 등!
int optimized() {
	//foundPathUsing = 경로를 찾기 위해 마지막으로 사용했던 상한의 위치
	int ret = INF, foundPathUsing = 0;
	for (int lo = 0; lo < weights.size(); ++lo) {
		//이 하한에 대해 경로를 발견했는가?
		bool foundPath = false;
		for (int hi = foundPathUsing; hi < weights.size(); ++hi) {
			if (hasPath(weights[lo], weights[hi])) {
				ret = min(ret, weights[hi] - weights[lo]);
				foundPath = true;
				foundPathUsing = hi;
				break;
			}
		}
		//경로가 없다면 곧장 종료한다.
		if (!foundPath) break;
	}
	return ret;
}//복잡도는 2 x E 임 //hasPath()를 한번 호출할 때마다 lo나 hi 둘중 하나가
//정확히 1씩 증가하게 되어 있으니!!!!

// p989 optimized() 간결하게 구성하기//가독성은 없다고 생각한다만 형식은 훌륭하다.
//가중치 목록을 훑고 지나가며 경로의 최소 너비를 찾는다.
//졸라 간단하지만 어떻게 이런 알고리즘에 도달했는지는 알지 못하면 이해하기는 더 어려움
int scanning() {	//!!!!우아한 코드 감동
	int lo = 0, hi = 0, ret = INF;
	while (true) {
		if (hasPath(weights[lo], weights[hi])) {  
			ret = min(ret, weights[hi] - weights[lo]);
			++lo;
		}
		else {
			if (hi == weights.size() - 1) break;
			++hi;
		}
	}
	return ret;
}


//32장 네트워크 유량-------------------------------------

//p996 네트워크 유량 문제를 해결하는 포드-풀커슨 알고리즘의 구현
const int INF = 987654321;
int V;
//capacity[u][v] = u에서 v로 보낼 수 있는 용량
//flow[u][v] = u 에서 v로 흘러가는 유량(반대 방향인 경우 음수)
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V]; //인접행렬임
//flow[][]를 계산하고 총 유량을 반환한다.
int networkFlow(int source, int sink) {
	memset(flow, 0, sizeof(flow));//flow를 0으로 초기화한다.
	int totalFlow = 0;
	while(true) {
		//너비 우선 탐색으로 증가 경로를 찾는다.
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty()) {
	//	while (!q.empty() && parent[sink] == -1) //훨씬 빠름//source[sink]가 -1이 아니
	//	라면 경로를 찾았다는 의미이므로
			int here = q.front(); q.pop();
			for (int there = 0; there < V; ++there)
				if (capacity[here][there] - flow[here][there] > 0 &&
					parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
		}
		if (parent[sink] == -1) break;//증가 경로가 없으면 종료한다.
		//증가 경로를 통해 유량을 얼마나 보낼지 결정한다.
		int amount = INF;	//최소 잔여 용량을 계산하자
		for (int p = sink; p != source; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		//증가 경로를 통해 유량을 보낸다.
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

//p1001 인접 리스트로 포드-풀커슨 알고리즘 구현하기
//간선의 정보를 나타내는 구조체
struct Edge {
	int target, capacity, flow;
	//역방향 간선의 포인터
	Edge* reverse;
	//이 간선의 잔여 용량을 계산한다.
	int residualCapacity() const { return capacity - flow; }
	//이 간선을 따라 용량 amt를 보낸다.
	void push(int amt) {
		flow += amt;
		reverse->flow -= amt; //!!!!
	}
};
//유량 네트워크의 인접 리스트
vector<Edge*> adj[MAX_V];
//u에서 v로 가는 간선을 추가한다.
void addEdge(int u, int v, int capacity) {
	Edge* uv = new Edge(), *vu = new Edge();
	//u에서 v로 가는 간선을 초기화 한다.
	uv->target = v;
	uv->capacity = capacity;
	uv->flow = 0;
	uv->reverse = vu;
	//v에서 u로 가는 간선을 초기화한다. 이 간선의 용량은 0이다.
	vu->target = u;
	vu->capacity = 0;
	vu->flow = 0;
	vu->reverse = uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
//addEdge(u, v, 4), addEdge(v, u, 7) 이렇게 두노드를 서로 크로스하는 간선인 경우 어찌되나!!!!
//uv간선을 add시킨 후에 vu간선을 add한다면
//따로 addEdge할 필요없이!!!!
//먼저 u에서 타깃이 v로 가는 간선이 있는지 검색
//있다면 uv->reverse->capacity를 세팅한다.

//!!!!차라리 이렇게 하자
void addEdge(int u, int v, int capacity) {
	//이미 uv간선(vu가 생성될때 reverse 도 생성되기에)이 존재한다면 그걸 활용하자
	for (int i = 0; i < adj[u].size(); ++i) {
		Edge* ui= adj[u][i];
		if (ui->target == v) {
			ui->capacity = capacity;
			return;
		}
	}
	...
}
// 그냥 간선을 여러개 만들어도 동작하고 그게 더 깔끔하지 싶다.
" 그냥 간선을 여러개 만들어 쓴다.
" 간선을 합하는 방식은 여러모로 불편하고 나중에 MCMF 모델에서는 더욱 불가능한 방식이다
" MCMF 는 간선마다 코스트가 달라지기 때문이다.!!!!
// 승부조작 문제에서 풀었음!!!!


//p1002 마일리지로 여행가기(MILEAGE, 중)
//소스에서 마일리지량을 보낸다 (항공사 마일리지, 이통사 마일리지...)
//결재항목 - 싱크 는 비용이다 (항권권 비용, 렌터카 비용)
//마일리지에서 결재항목으로 가는 간선들은 무한의 용량
소스 - 마일리지들 - 결재항목들 - 싱크
" 양과 사용처가 제한된 자원을 효율적으로 분배하는 방법을 찾는 문제는 
" 네트워크 유량 문제의 단골 손님입니다.

//P1003 도난당한 조각상(SAINTTAIL, 중)
간선대신 정점을 감시해야 하는 문제 -> 정점을 간선으로 변경하여 해결
각 정점은 두 정점으로 분리되며
원본 정점의 간선이 3개인 경우
들어오는 간선이 3개인 정점
나가는 간선이 3개인 정점으로 분리된다.
들어오는 정점과 나가는 정점은 감시 가중치를 가진다.
"ex)"
A정점이 3개의 간선(무방향)을 가짐, A정점 가중치는 7임
A정점 분리: Ain, Aout
Ain 으로 들어오는 간선 3개(가중치는 무제한)
Aout 에서 나가는 간선 3개(가중치는 무제한)
Ain --> Aout 으로 연결된 간선(가중치는 7)

//P1005 승부 조작(MATCHFIX, 중)
const int MAX_V = 220;
// 그래프의 인접 행렬 표현
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int networkFlow(int source, int sink) {
  // flow 를 0으로 초기화한다
  memset(flow, 0, sizeof(flow));
  int totalFlow = 0;

  while(true) {
    // 너비 우선 탐색으로 증가 경로를 찾는다
    vector<int> parent(MAX_V, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);
    while(!q.empty()) {
      int here = q.front(); q.pop();
      for(int there = 0; there < V; ++there)
        // 잔여 용량이 남아 있는 간선을 따라 탐색한다
        if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
          q.push(there);
          parent[there] = here;
        }
    }
    // 증가 경로가 없으면 종료한다
    if(parent[sink] == -1) break;
    // 증가 경로를 통해 유량을 얼마나 보낼지 결정한다
    int amount = 987654321;
    for(int p = sink; p != source; p = parent[p])
      amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
    // 증가 경로를 통해 유량을 보낸다
    for(int p = sink; p != source; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }
    totalFlow += amount;
  }

  return totalFlow;
}


//p1009 MATCHFIX 중 네트워크 유량을 이용해 승부조작 문제를 해결하는 함수
const int MAX_V = 220;
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];// 그래프의 인접 행렬 표현
int n, m;//선수, 남은 경기
int wins[20], match[200][2];
//0번 선수가 총 totalWins승으로 우승할 수 있는지 여부를 확인한다.
bool canWinWith(int totalWins) {
	//이미 totalWins승 이상한 선수가 있으면 안된다.
	if (*max_element(wins + 1, wins + n) >= totalWins) //!!!!
		return false;
	//0번은 소스, 1번은 싱크
	V = 2 + m + n; //m: 남은 경기의 수, n: 선수의 수, 2: 싱크소스 => 전체 정점의 수 V
	memset(capacity, 0, sizeof(capacity));
	for (int i = 0; i < m; ++i) {
		//소스에서 각 경기로 가는 간선
		capacity[0][2 + i] = 1;
		//각 경기에서 두 선수로 가는 간선
		for (int j = 0; j < 2; ++j)
			capacity[2 + i][2 + m + match[i][j]] = 1;
	}
	//각 선수에서 싱크로, 가능한 추가경기 최대승수를 용량으로 하는 간선을 추가
	for (int i = 0; i < n; ++i) {
		int maxWin = ( i == 0 ? totalWins : totalWins - 1 );
		capacity[2 + m + i][1] = maxWin - wins[i];
	}
	return networkFlow(0, 1) == m;
}
int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> n >> m;//선수의 수, 남은 경기의 수
		for (int i = 0; i < n; ++i) cin >> wins[i]; //각자의 현재 승수
		int matches = 0;//0번이 앞으로 붙을 경기수 => 0번이 추가로 이길수 있는 승수
		for (int i = 0; i < m; ++i) {
			// a, d두놈이 남은 첫경기에서 붙는다면: match[0][0] = a, match[0][1] = d
			cin >> match[i][0] >> match[i][1];
			if (match[i][0] == 0 || match[i][1] == 0)	//두놈중 한놈이라도 0번이면
				++matches;
		}
		bool ok = false;	//!!!!좋은 방식이네
		for (int m = 0; m <= matches; ++m) {
			if (canWinWith(wins[0] + m)) {
				printf("%d\n", wins[0] + m);
				ok = true;
				break;
			}
		}
		if (!ok) printf("-1\n");
	}
}

// 인접리스트로 구현한 포드 풀커슨 알고리즘을 활용하여 통과함 10ms 걸림 오오
// 	std::ios::sync_with_stdio(false); // 이거 없어도 15ms 임..
// 동적활당땜시 시간 많이 걸릴줄 알았는데..
// 종만이건 36ms 임
const int MAX_V = 12 + 100 + 2;	//선수 + 경기수 + SNK, SRC
struct Edge {
	int trg, cp, fl;
	Edge* reverse;
	int residualCp() const { return cp - fl; }
	void push(int amt) { fl += amt; reverse->fl -= amt; }
};
vector<Edge*> adj[MAX_V];
void addEdge(int u, int v, int cp) {
	Edge* uv = new Edge(), *vu = new Edge();
	uv->trg = v;	uv->cp = cp;	uv->fl = 0;	uv->reverse = vu;
	vu->trg = u;	vu->cp = 0;		vu->fl = 0;	vu->reverse = uv;
	adj[u].push_back(uv);	adj[v].push_back(vu);
}
int networkFlow(int src, int snk) {
	int totalFlow = 0;
	while (true) {
		vector<int> prnt(MAX_V, -1);
		vector<int> edgeNo(MAX_V, -1);
		queue<int> q;
		prnt[src] = src;
		q.push(src);
		while (!q.empty() && prnt[snk] == -1) {
			int here = q.front(); q.pop();
			rep(i, adj[here].size()) {
				Edge* edge = adj[here][i];
				int there = edge->trg;
				if (edge->residualCp() > 0 && prnt[there] == -1) {
					q.push(there);
					prnt[there] = here;
					edgeNo[there] = i;	// here --- there 간선
				}
			}
		}
		if (prnt[snk] == -1) break;
		int amount = INF;
		for (int p = snk; p != src; p = prnt[p]) {
			int here = prnt[p];
			int idx = edgeNo[p];	// here ----> p 로 연결된 간선 번호
			amount = min(amount, adj[here][idx]->residualCp());
		}
		for (int p = snk; p != src; p = prnt[p]) {
			int here = prnt[p];
			int idx = edgeNo[p];
			adj[here][idx]->push(amount);
		}
		totalFlow += amount;
	}
	return totalFlow;
}
int n, m; // 선수, 남은 경기
int wins[12], match[100][2];
bool canWinWith(int totalWins) {
	rep(i, n + m + 2) {
		rep(j, adj[i].size()) {
			delete adj[i][j];
		}
		adj[i].clear();
	}
	if (*max_element(wins + 1, wins + n) >= totalWins) return false;
	rep(i, m) {
		addEdge(0, 2 + i, 1);
		rep(j, 2)
			addEdge(2 + i, 2 + m + match[i][j], 1);
	}
	rep(i, n) {
		int maxWin = (i == 0 ? totalWins : totalWins - 1);
		addEdge(2 + m + i, 1, maxWin - wins[i]);
	}
	return networkFlow(0, 1) == m;
}
int main() {
	//freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> n >> m;
		rep(i, n) cin >> wins[i];
		int matches = 0;	// 0번이 추가로 이길수 있는 승수
		rep(i, m) {
			cin >> match[i][0] >> match[i][1];
			if (match[i][0] == 0 || match[i][1] == 0) ++matches;
		}
		int sol = -1;
		for (int m = 0; m <= matches; ++m)
			if (canWinWith(wins[0] + m)) {
				sol = wins[0] + m; break;
			}
		printf("%d\n", sol);
	}
	return 0;
}


//p1015 국책사업(PROJECTS, 상) 네트워크 유량을 이용해 국책 사업문제를 해결하는 함수
//최대 순이익
int maxProfit() {
	//네트워크를 만들자
	const int SRC = 0, SNK = 1;
	V = n + m + 2; //국책사업수, 장비수, 소스, 싱크
	memset(capacity, 0, sizeof(capacity));
	memset(flow, 0, sizeof(flow));
	for (int i = 0; i < n; ++i)	//소스 -- 국책사업이익 연결
		capacity[SRC][2 + i] = profit[i];
	for (int i = 0; i < m; ++i)	//장비비용 -- 싱크 연결
		capacity[2 + n + i][SNK] = cost[i];
	for (int i = 0; i < n; ++i)	//국책사업이익 -- 장비비용 연결
		for (int j = 0; j < m; ++j)
			if (requires[i][j])
				capacity[2 + i][2 + n + j] = INF; //!!!!
	//모든 사업의 수익의 합을 구한다.
	int M = accumulate(profit, profit + n, 0); //!!!! 0을 초기값으로 나머지들을 다 더함
	int C = networkFlow(SRC, SNK);
	return M - C; //모든 수익의 합(상수) - 최소컷(최대유량) : 최대 순이익 !!!!
}
//용량이 유한한 컷이 주어졌을 경우
//컷의 용량 C = 비선택한 국책사업이익 합 + 선택된 장비가격 합
//순이익	X = 선택한 국책사업이익 합 - 선택된 장비가격 합
//C + X		  = 전채 국책사업이익 합(상수로 고정됨)
//따라서 순이익 X 가 최대가 되려면 컷이 가장 작은 값이 되면 된다.(최대유량을 구하면 됨)

     ---<profit0> --- n0 ---<inf>-- m0 ----- <cost0> --\
    /                                                   \
SRC ----<profit1> --- n1 ---<inf>-- m1 ----- <cost1> ---- SNK
    \                    \                              /
	 \			          \-<inf>-- m2 ---- <cost2> ---/
      \                             /
       \-<profit2> -- n2 ---<inf>--/

//ex: 용량이 유한한 컷의 예
SRC---n0 : profit0
m1---SNK : cost1
m2---SNK : cost2

//p1019 이분 매칭 문제를 해결하는 증가 경로 알고리즘
//A와 B의 정점의 개수

int n, m;
//adj[i][j] = Ai와 Bj가 연결되어 있는가?
bool adj[MAX_N][MAX_M];
//각 정점에 매칭된 상대 정점의 번호를 저장한다.
vector<int> aMatch, bMatch; //aMatch : a정점들에 대하여 매치되는 b를 기록 
//dfs()의 방문여부
vector<bool> visited;
//A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로를 찾는다.
bool dfs(int a) {	//항상 A의 정점중 하나가 기준이구나!!!!
	if (visited[a]) return false; //유량감쇄가 안됨을 의미
	visited[a] = true;
	for (int b = 0; b < m; ++b)
		if (adj[a][b])
			//b가 매칭되어 있지 않다면, 즉 bMatch[b]가 -1 이면 증가경로를 찾은거임
			//b가 매치되어 있다면, 즉 bMatch[b] != -1 이면 bMatch[b]를 가지고 시작해
			//증가경로를 찾는다. !!!!
			//bMatch[b] == -1 이란 말은 a에서 b로 가는 길이 존재함을 의미한다.!!!!
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				//증가 경로 발견!! a와 b를 매치시킨다.
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
	return false;
}
//aMatch, bMatch배열을 계산하고 최대매칭의 크기를 반환한다.
int bipartiteMatch() {
	//처음에는 어떤 정점도 연결되어 있지 않다.
	aMatch = vector<int> (n, -1);
	bMatch = vector<int> (m, -1);
	int size = 0;
	for (int start = 0; start < n; ++start) {
		visited = vector<bool> (n, false); //방문기록 초기화 !!!!
		//포드 풀커슨에선 부모가 설정되었나로 방문여부를 알았는데 여기선 visited로 판단
		
		//깊이우선 탐색을 이용해 start에서 시작하는 증가경로를 찾는다.
		//수문이 여러개 있고 하나씩 문을 개방한다고 상상해봐
		//i수문이 개방될 때 유량이 증가 한다면 size를 증가하는 것!!!!
		if(dfs(start))
			++size;
	}
	return size;
}
a1 -- b1
   \/	
   /\
a2    b2

a1 -- b1 매칭세팅된 상태에서
a2수문을 열면 dfs(bMatch[b1]) 즉 dfs(a1)이 호출되고
그 상태에서 다시 dfs(bMatch[b1])이 호출되면 이번엔 vstd[a1]이 true이므로 false리턴함
bMatch[b2] == -1이므로 
aMatch[a1] = b2
bMatch[b2] = a1 
즉 a1 -- b2 매칭으로 변경된다.
또한 상위 dfs 콜러는
aMatch[a2] = b1
bMatch[b1] = a2 로 세팅하도록 함

//p1020 여행사진(TRAVELPICTURES, 중)
//각 사진의 찍은 장소의 범위가 나옴
//사진 찍은 장소를 최대한 유추하기이며 최대 매칭이 되도록 하는 것

//P1021 도미노로 직사각형 채우기(DOMINOS, 중)
//격자그래프란 무엇인가?
//격자그래프는 이분매칭을 이용해 문제를 해결가능하다
//P1023 도미노로 직사각형 채우기 문제 해결하기
int n, m; bool adj[MAX_N][MAX_M]; vector<int> aMatch, bMatch; vector<bool> visited;
bool dfs(int a); int bipartiteMatch(); //생략 : p1021에 없던거예요.

const int dx[4] = {1, -1, 0, 0 };
const int dy[4] = {0, 0, 1, -1 };
//(y, x)가 직사각형 범위 안의 칸인지 확인한다.
bool inRange(int y, int x);
//직사각형의 정보
int H, W;
vector<string> board;
//주어진 직사각형에 도미노를 채울 수 있는지 여부를 반환한다.
bool fillDomino() {
	//각 칸을 표현하는 정점의 번호를 계산한다.
	vector<vector<int> > id(H, vector<int>(W, -1));
	//각 칸을 순회하며 번호를 매긴다.
	n = m = 0;
	for (int y = 0; y < H; ++y)
		for (int x = 0; x < W; ++x)
			if (board[y][x] != '#') {
				if ((y + x) % 2 == 0)	//짝수점
					id[y][x] = n++;
				else					//홀수점
					id[y][x] = m++;
			}
	//adj[n][m]를 채운다.
	memset(adj, 0, sizeof(adj));
	//A에 속한 모든 칸에 대해 인접한 칸을 검사한다.
	for (int y1 = 0; y1 < H; ++y1)
		for (int x1 = 0; x1 < W; ++x1)
			if ((y1 + x1) % 2 == 0 && board[y1][x1] != '#') {	//짝수점이고 빈칸을 기준
				//(y1, x1)의 모든 인접한 칸을 검사한다.
				for (int k = 0; k < 4; ++k) {
					int y2 = y1 + dy[k];	//요놈은 홀수점
					int x2 = x1 + dx[k];
					//(y2, x2)가 범위 안에 있는 빈 칸이라면 두 정점을 연결한다.
					if (inRange(y2, x2) && board[y2][x2] != '#')
						adj[id[y1][x1]][id[y2][x2]] = 1;
//이해하기 어려웠던 부분: 같은 숫자면 같은 정점아닌가 하는 불만을 가졌음
//단방향 그래프(a에서 b로 가는)가 된다.
//bipartiteMatch() 에서 같은 숫자라도 다른 취급으로 돌림을 확인할 수 있었다.
				}
			}
	//이분 매칭의 크기가 빈 칸의 수의 절반이어야 한다. !!!!
	return bipartiteMatch() * 2 == (n + m); //짝수점 개수 + 홀수점 개수
}


//NQUEEN 문제는 연습장(그래프랑은 관련없음) 
// 연습장에 적은코드 그대로 옮겼는데 통과네.. 감동
const int MX = 12;
int n;
bool col[MX], major[MX * 2], minor[MX * 2];
int nQueen(int y) {
	if (y == n) return 1; //퀸의 갯수가 n이 되면 종료
	int ret = 0;
	rep(x, n) {
		// y 가 1씩 증가하므로 옆(row) 는 고려안해도 된다.!!!!
		if (!col[x] && !major[y - x + n] && !minor[y + x]) {
			col[x] = major[y - x + n] = minor[y + x] = 1;
			ret += nQueen(y + 1);
			col[x] = major[y - x + n] = minor[y + x] = 0;
		}
	}
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		cin >> n;
		int sol = nQueen(0);
		cout << sol << endl;
	}
	return 0;
}


//p1024 비숍(BISHOPS, 중)
//이분 그래프 활용 : 비숍하나는 두 묶음(major, minor)
//이분 매칭을 이용해 비숍 문제를 해결하는 함수의 구현
//대각선의 방향: 왼쪽 아래로 내려가는 대각선(/), 오른쪽 아래로 내려가는 대각선(\)
const int dx[2] = { -1, 1 };
const int dy[2] = { 1, 1 };
//체스판의 정보
vector<string> board;
//id[dir][y][x] = dir방향 대각선을 따라 인접한 빈 칸 묶음들 중 (y, x)가 속한 묶음의 번호
int id[2][8][8];
//이분 그래프의 정보
int n, m;
int adj[64][64];
//최대 매칭의 크기를 반환한다.
int bipartiteMatch();
int placeBishops() {
	//각 묶음에 번호를 붙인다. //!!!!
	memset(id, -1, sizeof(id));
	int count[2] = { 0, 0 };
	for (int dir = 0; dir < 2; ++dir)
		for (int y = 0; y < board.size(); ++y)
			for (int x = 0; x < board.size(); ++x)
				if (board[y][x] == '.' && id[dir][y][x] == -1) {
					int cy = y, cx = x;
					while ( 0 <= cy && cy < board.size() &&
							0 <= cx && cx < board.size() &&
							board[cy][cx] == '.') {
						id[dir][cy][cx] = count[dir];
						cy += dy[dir];
						cx += dx[dir];
					}
					count[dir]++;
				}
	//이분 그래프를 만든다.
	n = count[0];
	m = count[1];
	memset(adj, 0, sizeof(adj));
	for (int y = 0; y < board.size(); ++y)
		for (int x = 0; x < board.size(); ++x)
			//빈칸 하나는 두개를 이어주는 간선이 되는구나
			if (board[y][x] == '.')
				adj[id[0][y][x]][id[1][y][x]] = 1;
	return bipartiteMatch();
}


//p1028 함정설치 (TRAPCARD, 상)
//함정은 서로 인접할 수 없음(상하좌우)
//가장 많은 함정 설치 갯수와 배치를 구하라(함정 표시는 '^', 빈칸은 '.' , 벽은 '#')
//p1034 풀이 (이분 그래프의 최대 독립 집합 계산하기를 이용)
//각 정점에 매칭된 상대 정점의 번호를 저장한다.   
vector<int> aMatch, bMatch;
//aChosen[i] = 최대 독립 집합에 A_i가 포함되었는가?
//bChosen[i] = 최대 독립 집합에 B_i가 포함되었는가?
vector<bool> aChosen, bChosen;
//이분 그래프의 정보가 주어질 때 실제 최대 독립 집합을 계산한다.
void calcMaxIndependentSet() { //O(v3) : 소스 있음요: 그래프 생성은 소스 보삼
	//aMatch[]와 bMatch[]를 계산한다.
	int C = bipartiteMatch();
	//1. A의 모든 정점들을 선택하고, B에서 대응되지 않은(매치되지 않은) 정점들을 선택한다.
	// A U (B - M)
	aChosen = vector<bool>(n, true);	//n : A에 포함된 정점의 수
	bChosen = vector<bool>(m, false);	//m : B에 포함된 정점의 수
	for (int i = 0; i < m; ++i)
		if (bMatch[i] == -1)
			bChosen[i] = true;	//(B - M) : B에서 매치 안 된것만을 선택
	//2. 두 정점이 연결되어 있을 경우, 그중 A 정점을 지우고 B에 대응된 점점을 
	//대신 선택한다. 더 이상 변화가 일어나지 않을 때까지 반복한다.
	//bipartiteMatch 로 정해진 매치는 고정임!!!!
	while (true) { //while 은 많이 수행해봐야 매치갯수만큼이겠지.
		//어라.. 솔직히 while을 안돌려도 한번에 해결될거 같다.
		bool changed = false;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (aChosen[i] && bChosen[j] && adj[i][j]) {//!!!!
					//A는 항상 매칭에 포함된 정점임을 책에서 증명하였음
					assert(aMatch[i] != -1);
					aChosen[i] = false;
					bChosen[aMatch[i]] = true;
					changed = true;
				}
		if (!changed) break;
	}
}
A: 0 1 2 3 4 5 6 
   | | | |\
B: 0 1 2 3 4 5 6
aM: a[0] = 0, a[1] = 1, a[2] = 2, a[3] = 3
bM: b[0] = 0, b[1] = 1, b[2] = 2, b[3] = 3
aChosen = {t, t, t, t, t, t, t }
bChosen = {f, f, f, f, t, t, t }
요새끼들 중 연결 로미오와 줄리엣처럼 연결된 놈이 한놈 있다.
바로 a[3] 과 b[4] 다
이 쌍들은 adj상 서로 연걸되어 있으므로 최대 독립집합 구성을 방해해요 ~~
a[3]은 매치가 3을 가르키고 있다.(물론 b[4]는 매치되는 게 없는 상태다)
a[3]을 선택에서 제외시킨다.
b[3]을 선택에 추가한다.


// 기지의 지도
int H, W, id[MAX_SIZE][MAX_SIZE+1];
char map[MAX_SIZE][MAX_SIZE+1];	//null문자 저장하려고 + 1했음

void makeGraph() { //이진 그래프를 생성한다.
	const int dx[4] = { 1, -1, 0, 0 };
	const int dy[4] = { 0, 0, 1, -1 };
	memset(id, -1, sizeof(id));
	n = m = 0;
	for (int y = 0; y < H; ++y)
		for (int x = 0; x < W; ++x)
			if (map[y][x] == '.') {
				if ((y + x) % 2 == 0)
					id[y][x] = n++;
				else
					id[y][x] = m++;
			}	//홀수칸, 짝수칸에 번호를 매긴다.
	memset(adj, 0, sizeof(adj));
	for (int y1 = 0; y1 < H; ++y1)
		for (int x1 = 0; x1 < W; ++x1)
			//짝수점에 대해서로 기준잡음
			if ((y1 + x1) % 2 == 0 && map[y1][x1] == '.') {
				for (int k = 0; k < 4; ++k) {
					int y2 = y1 + dy[k];
					int x2 = x1 + dx[k];
					if (inRange(y2, x2) && map[y2][x2] == '.')
						adj[id[y1][x1]][id[y2][x2]] = 1;
				}
			}
}
void printTraps() {
	int C = 0;
	for (int y = 0; y < H; ++y)
		for (int x = 0; x < W; ++x)
			if (map[y][x] == '.')
				if (((y + x) % 2 == 0 && aChosen[id[y][x]]) ||
					((y + x) % 2 == 1 && bChosen[id[y][x]])) {
					map[y][x] = '^';
					++C;
				}
	cout << C << endl;
	for (int y = 0; y < H; ++y)
		cout << map[y] << endl;
}
int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		cin >> H >> W;
		for (int y = 0; y < H; ++y)
			cin >> map[y];	//char map[][]인 배열에다가 이렇게 cin 할 수 있구나 !!!!
		makeGraph();
		calcMaxIndependentSet();
		printTraps();
	}
}


http://amugelab.tistory.com/entry/%EC%9C%A0%EB%9F%89-%EA%B4%80%EB%A0%A8-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%A0%95%EB%A6%AC
유량 관련 알고리즘 정리
신고" class="updated" datetime="2015.07.24 17:27 신고"> 2015.07.24 17:27 신고  구사과  IT/Algorithm
[2015/07/24 MCMF 보강]

유량 관련 문제는 대부분 유량을 흘릴 수 있는 경로를 찾고 그 경로에 유량을 보내줌으로써 해결한다.
비슷비슷해서 난 별로 차이가 없는 줄 알았는데 얼마전 DFS로 maxflow의 증가경로를 찾으면 안된다는 
얘기를 듣고 멘붕함. 이 기회를 통해서 정리하려 한다.

[Maximum Flow]
* 가장 기본적인 형태로 증가 경로를 탐색 알고리즘을 통해 찾은 후 그 쪽으로 flow를 보내주는 방식으로 해결한다.

* 시간 복잡도는 "O(f * E)" 이다. f는 유량의 총 크기로 만약 크기가 확실치 않다면 다항시간에 풀 수 없는 것이나 마찬가지다.

* "하지만 BFS를 사용했을때는 증가 경로를 VE번 이상 찾지 않는다는 것이 증명되었다. (DFS는 해당되지 않는다)" 
따라서 Maximum Flow 문제는 무조건 BFS를 사용해야 하며 시간 복잡도는 "O(VE^2)"이다. 


* n개의 정점이 있는 완전 그래프라 하면 시간 복잡도가 O(n^5)이다 ^^; 
하지만 이게 아니면 대부분 절대 다항시간에 안풀리기 때문에 여전히 유용하다.

//* 여담으로, Dinic's Algorithm을 사용하면 O( (V^2)E )에 문제를 해결하는 최적화가 가능하다.

//* Dinic's Algorithm Practice http://poj.org/problem?id=2391



[Bipartite Matching]
 * Maximum Flow의 특수한 형태이다.

 * 두 정점을 매칭하는 방법을 찾는 문제로써, 적당히 이분 그래프를 만들어주면 Maximum Flow로써 해결할 수 있다.

 * 단지 차이점이라 하면, 얘는 f <= V라는 점. 때문에 "O(VE)"에 풀 수 있다.

 * BFS, DFS 모두 이분 매칭을 같은 시간 복잡도에 풀 수 있지만 DFS가 코드 사이즈나 실행속도면에서 약간 우수한 편이다. 

 * Hopcroft-Karp Algorithm을 사용하면 O(Sqrt(V) * E) 에 문제를 해결하는 최적화가 가능하다.

 * Hopcroft-Karp Practice http://poj.org/problem?id=3281

 * IOI 2015부터 O(VE) 이분 매칭이 syllabus에 들어갔다. 


https://www.acmicpc.net/problem/11375 // 열혈강호 문제
종만 이분매칭 800ms -> 디닉 200ms -> 홉크레프트 100ms 

[Min-Cost Max-Flow]

 * 유량 그래프에 cost가 붙은 상황에서 문제를 해결하는 전략이다.

 * 생각보다 해결 방법은 단순하다. 증가 경로를 최단 경로 알고리즘으로 탐색하면 된다.

 * 다만 그래프에 음수 코스트 간선이 있기 때문에 Dijkstra를 그냥 돌리면 큰일나고 
  음수 간선을 처리할 수 있는 Bellman-Ford Algorithm을 사용해야 한다. 벨만 포드의 시간복잡도는 O(VE)이다.

 * ... 사실 제일 좋은 방법은 "SPFA"라는 흑마법 (?) 을 사용하는 것이다. 
 시간 복잡도는 O(VE) 이지만 "실전에서 훨씬 빨리 돌아가는 알고리즘." 음수 간선에도 문제없이 돌아가기 때문에 MCMF랑 잘 맞는다. 
 https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm

 * 역변을 만드는 과정에서 음수 사이클이 생기는 것이 걱정될수 있으나, 
 "다행이도 초기 그래프에 음수 사이클이 없으면" 음수 사이클이 절대 생기지 않음을 증명할 수 있다고 한다. 
 (알려주신 hongjun7님 감사합니다.) https://www.acmicpc.net/board/view/1291

 * 일반적인 상황에서의 복잡도는 잘 모르겠다. 확실한건 O(f * VE) 이다. 
 하지만 이분 매칭의 상황이라면 f <= V이기 때문에 O((V^2) * E) 에 해결할 수 있다.

 * 음수 간선을 적절히 처리하는 방법이 있는데 "(Cycle Canceling)" 이를 사용하면 벨만 포드 대신 Dijkstra를 
 사용할 수 있고 시간 복잡도는 O(V^3).
 (대부분 완전그래프가 나오기에 V^2 다익스트라를 사용한다. 우선순위큐 다익스트라는 O(E * log(V))) 
 이 부분에 관심이 있다면 https://en.wikipedia.org/wiki/Johnson%27s_algorithm 를 참고.

 * 이 문제로 해결할 수 있는 대표적인 문제가 Assignment Problem(배정 문제) 이다. 
 Assignment Problem은 Hungarian Algorithm을 사용해서 해결하는 것이 가능한데, 
 MCMF가 Hungarian Algorithm의 일반화된 형태이기 때문에 충분히 이를 대체할 수 있다.

 * Assignment Problem은 이분 그래프에서의 MCMF로 변형시킬 수 있고 
 이 때 E = n^2, V = n이기 때문에 일반적으로 O(n^4)에 해결 가능하다. 
 하지만 Cycle Canceling을 사용해서 O(n^3)에도 해결할 수 있다. 
 (naive가 n^4이고 slacky등을 잡아서 n^3으로 최적화하는 Hungarian Algorithm과 유사하다.) 
 일반적으로 Hungarian Algorithm이 MCMF보다 빠르게 작동하지만, 코딩하기는 MCMF가 훨씬 편하다. 
 (헝가리안 알고리즘은 소스코드가 MCMF의 몇배는 되며 디버깅하기도 골치아프다)

https://jmk.pe.kr/read/mcmf
https://algospot.com/judge/problem/read/CLEANING


MCMF 모델링을 하자
		거울(y축)
			|
	1		|
			|
			|		3
			|
	2		|
			|
각 점의 좌표 { x, y }
1 = { -2, 1 }
2 = { -2, -1}
3 = { 2, 0 }

// 1번이 3번과 대칭이 되려면 3번을 y축 반사시킨 가상의 점으로 이동 시켜야 된다.
// 1번과 2번은 대칭을 이룰수 없으니 생략해도 된다.
// 1번이 아무점과 대칭을 이루지 않으려면 1번점을 y축으로 이동시켜야 한다.
(비용, 용량)
                           (2*2,1)
	      --------- 1 ----------------- 1 
         /            \              /    \
        /              \  -----------      \
       /(0,1)           \/  (1,1)           \ (0,1)
      /                 /\  (1,1)            \
     /                 /  -----------         \
    /   (0,1)         /    (2*2,1)   \    (0,1)\
src --------------- 3 ----------------- 3 ------ snk
    \                 \              /         /
     \                 \  -----------         /
      \(0,1)            \/ (1,1)             /
       \                /\ (1,1)            /(0,1)
        \              /  -----------      /
         \            /              \    /
          --------- 2 ----------------- 2 
                          (2*2,1)






// 시간초과 뜬다.
const int INF = 987654321;
const int MOD = 1000000007;
struct MCMF3 {
	int V, totalFlow; double totalCost;
	struct Edge {
		int target, cp, fl; double cost;
		Edge* dual;
		Edge(int trg, int cp, double cost) : target(trg), cp(cp), cost(cost), fl(0) {}
		inline int residual() const { if (fl < 0) return -fl; return cp - fl; }
		inline double getCost() const { if (fl < 0) return -dual->cost; return cost; }
		void push(int amt) { fl += amt; dual->fl -= amt; }
	};
	vector<vector<Edge*>> adj;
	MCMF3(int n) : V(n), totalFlow(0), totalCost(0), adj(n) {}
	~MCMF3() { rep(i, V) rep(j, adj[i].size()) delete adj[i][j]; }
	void setEdge(int u, int v, int uvCp, double uvCost, int vuCp = 0, double vuCost = 0) {
		Edge* uv = new Edge(v, uvCp, uvCost);
		Edge* vu = new Edge(u, vuCp, vuCost);
		uv->dual = vu; vu->dual = uv;
		adj[u].push_back(uv); adj[v].push_back(vu);
	}
	double improve(int s, int t) {
		vector<double> dist(V, INF);
		vector<int> prnt(V, -1), edgeNo(V, -1), capa(V, -1);
		prnt[s] = s; dist[s] = 0; capa[s] = INF;
		priority_queue<pair<double, int>> pq;
		pq.push(mp(-0, s));
		while (!pq.empty()) {
			double cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost) continue;
			for (int i = 0; i < adj[here].size(); ++i) {
				Edge* e = adj[here][i];
				if (e->residual() <= 0) continue;
				double thereCost = dist[here] + e->getCost();
				if (thereCost < dist[e->target]) {
					prnt[e->target] = here;
					edgeNo[e->target] = i;	// here->there로 가는 간선이 여러개 있을수 있어서
					capa[e->target] = min(capa[here], e->residual()); //보낼수 있는 유량
					dist[e->target] = thereCost;
					pq.push(mp(-thereCost, e->target));
				}
			}
		}
		if (dist[t] < INF) {
			int here = t, amt = capa[t];	// amt 는 flow 양중 가장 작은거
			while (here != s) {
				int there = prnt[here];
				adj[there][edgeNo[here]]->push(amt);
				here = there;
			}
			totalFlow += amt;
			totalCost += dist[t] * amt;
		}
		return dist[t];
	}
};
// 1 <= n <= 100
int main() {
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);	
	// vs에서는 정상 동작하나 타 컴파일러에선 이 구문이 활성화 된다면 scanf 쓰면 안되네!!!!(엉뚱하게 나옴)
	// cin 을 사용하라.. std::ios::sync_with_stdio(false); 는 scanf 쓸때 잘 동작을 안하네.. 
	// 버그임... freopen 없이 실시간 입력시에는 scanf 로도 잘 받음...
	// printf 는 써도 동작하더라, 웹 c++11 컴파일러에서 테스트함
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vpii arr; int a, b;
		rep(i, n) {
			scanf("%d%d", &a, &b);
			//cin >> a >> b;
			if (a != 0)
				arr.push_back(mp(a, b));
		}
		n = arr.size();
		MCMF3 mcmf(arr.size() * 2 + 2);
		rep(i, n) {
			rep(j, n) {
				int u = i;
				int v = j + n;
				// a -- b, b -- a 두번 계산된다, 나누기 2를 하자
				// 같은 경우 a -- a 한번만 계산된다만 두배가 되어 더해짐
				// 마지막 출력부분에서 2로 나눠주자~
				double dist = hypot(arr[i].first + arr[j].first, arr[i].second - arr[j].second);
				mcmf.setEdge(u, v, 1, dist);
			}
		}
		rep(i, n) mcmf.setEdge(n * 2, i, 1, 0);		// SRC --- 왼쪽 노드
		rep(i, n) mcmf.setEdge(i + n, n * 2 + 1, 1, 0);	// 오른쪽 노드 --- SNK

		while (true) {
			// 밀어넣기를 계속 하자
			double distT = mcmf.improve(arr.size() * 2, arr.size() * 2 + 1);
			if (distT >= INF)
				break;
		}
		double sol = mcmf.totalCost;
		printf("%.3lf\n", sol / 2);
	}
	return 0;
}



// 메모리 오바 떳음...
const int INF = 987654321;
const int MOD = 1000000007;
struct MCMF4 {
	int V, totalFlow; double totalCost;
	struct Edge {
		int target, capacity, flow;
		double cost;
		Edge* dual;

		Edge(int target, int capacity, double cost) :
			target(target), capacity(capacity), cost(cost), flow(0) {
		}

		inline int residual() const {
			if (flow < 0) return -flow;
			return capacity - flow;
		}

		inline double getCost() const {
			if (flow < 0) return -dual->cost;
			return cost;
		}

		void push(int amt) {
			flow += amt;
			dual->flow -= amt;
		}
	};
	vector<vector<Edge*> > adj;
	vector<double> pot;
	MCMF4(int n) : V(n), totalFlow(0), totalCost(0), adj(n), pot(n, 0) {
	}
	~MCMF4() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < adj[i].size(); j++)
				delete adj[i][j];
	}
	void setEdge(int u, int v, double uvCapacity, double uvCost, 
		double vuCapacity = 0, double vuCost = 0) {
		Edge* uv = new Edge(v, uvCapacity, uvCost);
		Edge* vu = new Edge(u, vuCapacity, vuCost);
		uv->dual = vu; vu->dual = uv;
		adj[u].push_back(uv); adj[v].push_back(vu);
	}
	double improve(int s, int t) {
		vector<int> parent(V, -1), edgeNo(V, -1), capa(V, -1);
		vector<double> distance(V, INF);
		parent[s] = s;
		distance[s] = 0;
		capa[s] = INF;
		priority_queue<pair<double, int> > pq;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			double cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (distance[here] < cost) continue;
			for (int i = 0; i < adj[here].size(); ++i) {
				Edge* e = adj[here][i];
				if (e->residual() <= 0) continue;
				double thereCost = distance[here] + e->getCost() + pot[here] - pot[e->target];
				if (thereCost < distance[e->target]) {
					parent[e->target] = here;
					edgeNo[e->target] = i;
					capa[e->target] = min(capa[here], e->residual());
					distance[e->target] = thereCost;
					pq.push(make_pair(-thereCost, e->target));
				}

			}
		}
		double cost = distance[t] + pot[t] - pot[s];
		for (int i = 0; i < V; i++)
			if (pot[i] < INF)
				pot[i] += distance[i];
		if (distance[t] == INF) return INF;
		int here = t, amt = capa[t];
		while (here != s) {
			int there = parent[here];
			adj[there][edgeNo[here]]->push(amt);
			here = there;
		}
		totalFlow += amt;
		totalCost += cost * amt;
		return cost;
	}
};
// 1 <= n <= 100
int main() {
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vpii arr; int a, b;
		rep(i, n) {
			scanf("%d%d", &a, &b);
			//cin >> a >> b;
			if (a != 0)
				arr.push_back(mp(a, b));
		}
		n = arr.size();
		MCMF4 mcmf(arr.size() * 2 + 2);
		rep(i, n) {
			rep(j, n) {
				int u = i;
				int v = j + n;
				// a -- b, b -- a 두번 계산된다, 나누기 2를 하자
				// 같은 경우 a -- a 한번만 계산된다만 두배가 되어 더해짐
				// 마지막 출력부분에서 2로 나눠주자~
				double dist = hypot(arr[i].first + arr[j].first, arr[i].second - arr[j].second);
				mcmf.setEdge(u, v, 1, dist);
			}
		}
		rep(i, n) mcmf.setEdge(n * 2, i, 1, 0);		// SRC --- 왼쪽 노드
		rep(i, n) mcmf.setEdge(i + n, n * 2 + 1, 1, 0);	// 오른쪽 노드 --- SNK

		while (true) {
			// 밀어넣기를 계속 하자
			double distT = mcmf.improve(arr.size() * 2, arr.size() * 2 + 1);
			if (distT == INF)
				break;
		}
		double sol = mcmf.totalCost;
		printf("%.3lf\n", sol / 2);
	}
	return 0;
}


// 이건 시간초과
struct MCMF1 {
	int V, totalFlow; 
	double totalCost;
	vector<vector<int> > cap, flow;
	vector<vector<double>> cost;
	MCMF1(int n) : V(n), totalFlow(0), totalCost(0) {
		cap = flow = vector<vector<int> >(n, vector<int>(n));
		cost = vector<vector<double>>(n, vector<double>(n));
	}
	void setEdge(int u, int v, int cap, double cost) {
		this->cap[u][v] = cap;
		this->cost[u][v] = cost;
	}
	double improve(int s, int t) {
		vector<double> distance(V, INF);
		vector<int> parent(V, -1);
		parent[s] = s;
		distance[s] = 0;
		bool changed = true;
		while (changed) {
			changed = false;
			for (int u = 0; u < V; u++)
				if (distance[u] < INF)
					for (int v = 0; v < V; v++) {
						double cand;
						if (flow[v][u] > 0)
							cand = distance[u] - cost[v][u];
						else if (cap[u][v] > flow[u][v])
							cand = distance[u] + cost[u][v];
						else
							continue;
						if (cand < distance[v]) {
							distance[v] = cand;
							parent[v] = u;
							changed = true;
						}
					}
		}
		if (distance[t] < INF) {
			int here = t;
			while (here != s) {
				int there = parent[here];
				flow[there][here]++;
				flow[here][there]--;
				here = there;
			}
			totalFlow++;
			totalCost += distance[t];
		}
		return distance[t];
	}
};
// 이것도 시간초과
struct MCMF2 {
	int V, totalFlow;
	double totalCost;
	vector<vector<int> > cap, flow;
	vector<vector<double>> cost;
	MCMF2(int n) : V(n), totalFlow(0), totalCost(0) {
		cap = flow = vector<vector<int> >(n, vector<int>(n));
		cost = vector<vector<double>>(n, vector<double>(n));
	}
	void setEdge(int u, int v, int cap, double cost) {
		this->cap[u][v] = cap;
		this->cost[u][v] = cost;
	}
	inline double getCost(int u, int v) {
		return flow[v][u] > 0 ? -cost[v][u] : cost[u][v];
	}
	double improve(int s, int t) {
		vector<double> distance(V, INF);
		vector<int> parent(V, -1);
		parent[s] = s;
		distance[s] = 0;
		priority_queue<pair<double, int> > pq;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			double cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (distance[here] < cost) continue;
			for (int there = 0; there < V; ++there) {
				if (cap[here][there] - flow[here][there] <= 0) continue;
				double thereCost = distance[here] + getCost(here, there);
				if (thereCost < distance[there]) {
					parent[there] = here;
					distance[there] = thereCost;
					pq.push(make_pair(-thereCost, there));
				}
			}
		}
		if (distance[t] < INF) {
			int here = t;
			while (here != s) {
				int there = parent[here];
				flow[there][here]++;
				flow[here][there]--;
				here = there;
			}
			totalFlow++;
			totalCost += distance[t];
		}
		return distance[t];
	}
};

// 이걸로 예시파일을 만들었는데
/*
	freopen("output.txt", "w", stdout);
	cout << 50 << endl;
	rep(i, 50) {
		cout << 100 << endl;
		int base = 1;
		rep(i, 50) {
			cout << base << " " << base << endl;
			base++;
		}
		rep(i, 50) {
			cout << -base << " " << base << endl;
			base++;
		}
	}
	*/
MCMF4 기준으로 예시파일 하나의 케이스도 통과 못함...
//큐사이즈가 계속 커지더라!!!! 확인한것만 1000만개 정도임.. 그 이상은 시간 낭비라 생략..

// http://ideone.com/7fIRdJ
이 소스로 돌려봤고 큐사이즈를 체크해봤는데
한 케이스에 대해
다익스트라가 100번 돌아갔고
최초 다익스트라에서 큐사이즈가 최대값이 되었다 (2628)
그뒤 다익스트라에서 최대 큐사이즈는
qMaxSZ: 2627
qMaxSZ: 2576
qMaxSZ: 2526
...
qMaxSZ: 1
이렇게 되고 // 점점 줄어드는 구나!!!!
cnt: 100
3246.821 출력함


"MCMF4 로 통과 했음요!!!!	
// qMaxSZ 가 미소한 크기로 증가하는 예외가 있지만 점진적으로 줄어듬을 확인할 수 있었다.
const int INF = 100000000;
const int MOD = 1000000007;

struct MCMF4 {
	int V, totalFlow; double totalCost;
	struct Edge {
		int target, capacity, flow;
		double cost;
		Edge* dual;

		Edge(int target, int capacity, double cost) :
			target(target), capacity(capacity), cost(cost), flow(0) {
		}

		inline int residual() const {
			if (flow < 0) return -flow;
			return capacity - flow;
		}

		inline double getCost() const {
			if (flow < 0) return -dual->cost;
			return cost;
		}

		void push(int amt) {
			flow += amt;
			dual->flow -= amt;
		}
	};
	vector<vector<Edge*> > adj;
	vector<double> pot;
	MCMF4(int n) : V(n), totalFlow(0), totalCost(0), adj(n), pot(n, 0) {
	}
	~MCMF4() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < adj[i].size(); j++)
				delete adj[i][j];
	}
	void setEdge(int u, int v, double uvCapacity, double uvCost,
		double vuCapacity = 0, double vuCost = 0) {
		Edge* uv = new Edge(v, uvCapacity, uvCost);
		Edge* vu = new Edge(u, vuCapacity, vuCost);
		uv->dual = vu; vu->dual = uv;
		adj[u].push_back(uv); adj[v].push_back(vu);
	}
	double improve(int s, int t) {
		vector<int> parent(V, -1), edgeNo(V, -1), capa(V, -1);
		vector<double> distance(V, INF);
		parent[s] = s;
		distance[s] = 0;
		capa[s] = INF;
		priority_queue<pair<double, int> > pq;
		pq.push(make_pair(0, s));
		int qMaxSZ = 0;
		while (!pq.empty()) {
			qMaxSZ = (qMaxSZ >= pq.size() ? qMaxSZ : pq.size());
			//printf("pq.size() = %d\n", pq.size());
			double cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (distance[here] < cost) continue;
			for (int i = 0; i < adj[here].size(); ++i) {
				Edge* e = adj[here][i];
				if (e->residual() <= 0) continue;
				double thereCost = distance[here] + e->getCost() + pot[here] - pot[e->target];
				// !!!! MCMF4 사용시 cost가 double 형일때 주의점:  epsilon 고려해야한다. 미소량 빼주는 코드가 없을시
				// pq사이즈가 무진장 커지는 불상사가 발생함요...ㅠㅠ
				if (thereCost < distance[e->target] - 0.000000000001) {	//!!!!!!!!!
					parent[e->target] = here;
					edgeNo[e->target] = i;
					capa[e->target] = min(capa[here], e->residual());
					distance[e->target] = thereCost;
					pq.push(make_pair(-thereCost, e->target));
				}
			}
		}
		//printf("qMaxSZ: %d\n", qMaxSZ);
		double cost = distance[t] + pot[t] - pot[s];
		for (int i = 0; i < V; i++)
			if (pot[i] < INF)
				pot[i] += distance[i];
		if (distance[t] == INF) return INF;
		int here = t, amt = capa[t];
		while (here != s) {
			int there = parent[here];
			adj[there][edgeNo[here]]->push(amt);
			here = there;
		}
		totalFlow += amt;
		totalCost += cost * amt;
		return cost;
	}
};
// 1 <= n <= 100
int main() {
	/*
	freopen("output.txt", "w", stdout);
	cout << 50 << endl;
	rep(i, 50) {
	cout << 100 << endl;
	int base = 1;
	rep(i, 50) {
	cout << base << " " << base << endl;
	base++;
	}
	rep(i, 50) {
	cout << -base << " " << base << endl;
	base++;
	}
	}
	*/
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vpii arr; int a, b;
		rep(i, n) {
			scanf("%d%d", &a, &b);
			//cin >> a >> b;
			if (a != 0)
				arr.push_back(mp(a, b));
		}
		n = arr.size();
		MCMF4 mcmf(arr.size() * 2 + 2);
		rep(i, n) {
			rep(j, n) {
				int u = i;
				int v = j + n;
				// a -- b, b -- a 두번 계산된다, 나누기 2를 하자
				// 같은 경우 a -- a 한번만 계산된다만 두배가 되어 더해짐
				// 마지막 출력부분에서 2로 나눠주자~
				double dist = hypot(arr[i].first + arr[j].first, arr[i].second - arr[j].second);
				if (i == j)
					mcmf.setEdge(u, v, 1, dist);
				else if (arr[i].first * arr[j].first < 0)	// 쓸모없는 간선은 추가하지 말자!!!!
					mcmf.setEdge(u, v, 1, dist);
			}
		}
		rep(i, n) mcmf.setEdge(n * 2, i, 1, 0);		// SRC --- 왼쪽 노드
		rep(i, n) mcmf.setEdge(i + n, n * 2 + 1, 1, 0);	// 오른쪽 노드 --- SNK
		int cnt = 0;
		while (true) {
			// 밀어넣기를 계속 하자
			double distT = mcmf.improve(n*2, n*2 + 1);
			if (distT == INF)
				break;
			cnt++;
		//	printf("cnt: %d\n", cnt);
		}
		double sol = mcmf.totalCost;
		printf("%.3lf\n", sol / 2);
	}
	return 0;
}
//결론: MCMF4 는 정점 100개짜리 완전 그래프는 간단하게 돌아간다
//윗코드로 통과 시간이 165ms 정도 된다.
//타임 오버가 났을시 예시를 만들어 본게 많은 도움이 되는구냥!!!!


// epsilon 처리후 MCMF3 돌아감요: 156ms 걸림.. 더 빨라져버리냐..
const int INF = 987654321;
const int MOD = 1000000007;
struct MCMF3 {
	int V, totalFlow; double totalCost;
	struct Edge {
		int target, cp, fl; double cost;
		Edge* dual;
		Edge(int trg, int cp, double cost) : target(trg), cp(cp), cost(cost), fl(0) {}
		inline int residual() const { if (fl < 0) return -fl; return cp - fl; }
		inline double getCost() const { if (fl < 0) return -dual->cost; return cost; }
		void push(int amt) { fl += amt; dual->fl -= amt; }
	};
	vector<vector<Edge*>> adj;
	MCMF3(int n) : V(n), totalFlow(0), totalCost(0), adj(n) {}
	~MCMF3() { rep(i, V) rep(j, adj[i].size()) delete adj[i][j]; }
	void setEdge(int u, int v, int uvCp, double uvCost, int vuCp = 0, double vuCost = 0) {
		Edge* uv = new Edge(v, uvCp, uvCost);
		Edge* vu = new Edge(u, vuCp, vuCost);
		uv->dual = vu; vu->dual = uv;
		adj[u].push_back(uv); adj[v].push_back(vu);
	}
	double improve(int s, int t) {
		vector<double> dist(V, INF);
		vector<int> prnt(V, -1), edgeNo(V, -1), capa(V, -1);
		prnt[s] = s; dist[s] = 0; capa[s] = INF;
		priority_queue<pair<double, int>> pq;
		pq.push(mp(-0, s));
		while (!pq.empty()) {
			double cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost) continue;
			for (int i = 0; i < adj[here].size(); ++i) {
				Edge* e = adj[here][i];
				if (e->residual() <= 0) continue;
				double thereCost = dist[here] + e->getCost();
				if (thereCost < dist[e->target] - 0.000000000001) {
					prnt[e->target] = here;
					edgeNo[e->target] = i;	// here->there로 가는 간선이 여러개 있을수 있어서
					capa[e->target] = min(capa[here], e->residual()); //보낼수 있는 유량
					dist[e->target] = thereCost;
					pq.push(mp(-thereCost, e->target));
				}
			}
		}
		if (dist[t] < INF) {
			int here = t, amt = capa[t];	// amt 는 flow 양중 가장 작은거
			while (here != s) {
				int there = prnt[here];
				adj[there][edgeNo[here]]->push(amt);
				here = there;
			}
			totalFlow += amt;
			totalCost += dist[t] * amt;
		}
		return dist[t];
	}
};
// 1 <= n <= 100
int main() {
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vpii arr; int a, b;
		rep(i, n) {
			scanf("%d%d", &a, &b);
			//cin >> a >> b;
			if (a != 0)
				arr.push_back(mp(a, b));
		}
		n = arr.size();
		MCMF3 mcmf(arr.size() * 2 + 2);
		rep(i, n) {
			rep(j, n) {
				int u = i;
				int v = j + n;
				// a -- b, b -- a 두번 계산된다, 나누기 2를 하자
				// 같은 경우 a -- a 한번만 계산된다만 두배가 되어 더해짐
				// 마지막 출력부분에서 2로 나눠주자~
				double dist = hypot(arr[i].first + arr[j].first, arr[i].second - arr[j].second);
				if (i == j)
					mcmf.setEdge(u, v, 1, dist);
				else if (arr[i].first * arr[j].first < 0)
					mcmf.setEdge(u, v, 1, dist);
			}
		}
		rep(i, n) mcmf.setEdge(n * 2, i, 1, 0);		// SRC --- 왼쪽 노드
		rep(i, n) mcmf.setEdge(i + n, n * 2 + 1, 1, 0);	// 오른쪽 노드 --- SNK

		while (true) {
			// 밀어넣기를 계속 하자
			double distT = mcmf.improve(arr.size() * 2, arr.size() * 2 + 1);
			if (distT >= INF)
				break;
		}
		double sol = mcmf.totalCost;
		printf("%.3lf\n", sol / 2);
	}
	return 0;
}


// epsilon 처리후 MCMF2 돌아감요: 219ms 걸림.. 완전 그래프에 가깝기에..엣지가 많아서 그런거 같다.
// MCMF3, 4 랑 별 차이 안나네.
const int INF = 987654321;
const int MOD = 1000000007;
struct MCMF2 {
	int V, totalFlow;
	double totalCost;
	vector<vector<int> > cap, flow;
	vector<vector<double>> cost;
	MCMF2(int n) : V(n), totalFlow(0), totalCost(0) {
		cap = flow = vector<vector<int> >(n, vector<int>(n));
		cost = vector<vector<double>>(n, vector<double>(n));
	}
	void setEdge(int u, int v, int cap, double cost) {
		this->cap[u][v] = cap;
		this->cost[u][v] = cost;
	}
	inline double getCost(int u, int v) {
		return flow[v][u] > 0 ? -cost[v][u] : cost[u][v];
	}
	double improve(int s, int t) {
		vector<double> distance(V, INF);
		vector<int> parent(V, -1);
		parent[s] = s;
		distance[s] = 0;
		priority_queue<pair<double, int> > pq;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			double cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (distance[here] < cost) continue;
			for (int there = 0; there < V; ++there) {
				if (cap[here][there] - flow[here][there] <= 0) continue;
				double thereCost = distance[here] + getCost(here, there);
				if (thereCost < distance[there] - 0.000000000001) {
					parent[there] = here;
					distance[there] = thereCost;
					pq.push(make_pair(-thereCost, there));
				}
			}
		}
		if (distance[t] < INF) {
			int here = t;
			while (here != s) {
				int there = parent[here];
				flow[there][here]++;
				flow[here][there]--;
				here = there;
			}
			totalFlow++;
			totalCost += distance[t];
		}
		return distance[t];
	}
};
// 1 <= n <= 100
int main() {
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vpii arr; int a, b;
		rep(i, n) {
			scanf("%d %d", &a, &b);
			//cin >> a >> b;
			if (a != 0)
				arr.push_back(mp(a, b));
		}
		n = arr.size();
		MCMF2 mcmf(arr.size() * 2 + 2);
		rep(i, n) {
			rep(j, n) {
				int u = i;
				int v = j + n;
				// a -- b, b -- a 두번 계산된다, 나누기 2를 하자
				// 같은 경우 a -- a 한번만 계산된다만 두배가 되어 더해짐
				// 마지막 출력부분에서 2로 나눠주자~
				double dist = hypot(arr[i].first + arr[j].first, arr[i].second - arr[j].second);
				if (i == j)
					mcmf.setEdge(u, v, 1, dist);
				else if (arr[i].first * arr[j].first < 0)
					mcmf.setEdge(u, v, 1, dist);
			}
		}
		rep(i, n) mcmf.setEdge(n * 2, i, 1, 0);		// SRC --- 왼쪽 노드
		rep(i, n) mcmf.setEdge(i + n, n * 2 + 1, 1, 0);	// 오른쪽 노드 --- SNK

		while (true) {
			// 밀어넣기를 계속 하자
			double distT = mcmf.improve(arr.size() * 2, arr.size() * 2 + 1);
			if (distT > INF - 1)
				break;
		}
		double sol = mcmf.totalCost;
		printf("%.3lf\n", sol / 2);
	}
	return 0;
}

// epsilon 처리후 통과요 800ms 정도 걸리네요. 이건 시간이 좀 걸립니다..
const int INF = 987654321;
const int MOD = 1000000007;
struct MCMF1 {
	int V, totalFlow;
	double totalCost;
	vector<vector<int> > cap, flow;
	vector<vector<double>> cost;
	MCMF1(int n) : V(n), totalFlow(0), totalCost(0) {
		cap = flow = vector<vector<int> >(n, vector<int>(n));
		cost = vector<vector<double>>(n, vector<double>(n));
	}
	void setEdge(int u, int v, int cap, double cost) {
		this->cap[u][v] = cap;
		this->cost[u][v] = cost;
	}
	double improve(int s, int t) {
		vector<double> distance(V, INF);
		vector<int> parent(V, -1);
		parent[s] = s;
		distance[s] = 0;
		bool changed = true;
		while (changed) {
			changed = false;
			for (int u = 0; u < V; u++)
				if (distance[u] < INF)
					for (int v = 0; v < V; v++) {
						double cand;
						if (flow[v][u] > 0)
							cand = distance[u] - cost[v][u];
						else if (cap[u][v] > flow[u][v])
							cand = distance[u] + cost[u][v];
						else
							continue;
						if (cand < distance[v] - 0.000000000001) {
							distance[v] = cand;
							parent[v] = u;
							changed = true;
						}
					}
		}
		if (distance[t] < INF) {
			int here = t;
			while (here != s) {
				int there = parent[here];
				flow[there][here]++;
				flow[here][there]--;
				here = there;
			}
			totalFlow++;
			totalCost += distance[t];
		}
		return distance[t];
	}
};
// 1 <= n <= 100
int main() {
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		vpii arr; int a, b;
		rep(i, n) {
			scanf("%d %d", &a, &b);
			//cin >> a >> b;
			if (a != 0)
				arr.push_back(mp(a, b));
		}
		n = arr.size();
		MCMF1 mcmf(arr.size() * 2 + 2);
		rep(i, n) {
			rep(j, n) {
				int u = i;
				int v = j + n;
				// a -- b, b -- a 두번 계산된다, 나누기 2를 하자
				// 같은 경우 a -- a 한번만 계산된다만 두배가 되어 더해짐
				// 마지막 출력부분에서 2로 나눠주자~
				double dist = hypot(arr[i].first + arr[j].first, arr[i].second - arr[j].second);
				if (i == j)
					mcmf.setEdge(u, v, 1, dist);
				else if (arr[i].first * arr[j].first < 0)
					mcmf.setEdge(u, v, 1, dist);
			}
		}
		rep(i, n) mcmf.setEdge(n * 2, i, 1, 0);		// SRC --- 왼쪽 노드
		rep(i, n) mcmf.setEdge(i + n, n * 2 + 1, 1, 0);	// 오른쪽 노드 --- SNK

		while (true) {
			// 밀어넣기를 계속 하자
			double distT = mcmf.improve(arr.size() * 2, arr.size() * 2 + 1);
			if (distT > INF - 1)
				break;
		}
		double sol = mcmf.totalCost;
		printf("%.3lf\n", sol / 2);
	}
	return 0;
}

https://algospot.com/judge/problem/read/KAKAONEWHIRE
" 종만이의 MCMF는 믿을수가 없다.
" MCMF4 종만이걸로 돌렸는데 계속 오답떴음요...(그것도 원본형태 그대로 한 버전가지고 말이지)
" 원본형태 그대로 였는데 그러면 epsilion 체크없이도 돌아가는 것이고
" 그렇다는 뜻은 epsilon 이외에도 오류가 있다는 뜻이다!!!!
// 종만이 MCMF4 를 가지고 8번이나 틀렀다.
// 소수점 문제있나 의심하고,  의심병이 생김
" 종만이 소스 통과합니다. 종만이 원본(정수 cost)소스를 의심하다니.. 확실히 의심병이 생겼구나.."

//아래 소스는 인터넷에서 글어온 namespace mcmf 코드를 이용해서 짰고 통과했다.
// 성과 이름이 중복인 케이스는 고려해야 한다!!!!
const int INF = 987654321;
const int MOD = 1000000007;
namespace MCMF {
	typedef double cap_t;
	typedef double cost_t;
	bool isZeroCap(cap_t cap) {
		return cap == 0;
		
	}
	const cap_t CAP_MAX = numeric_limits<cap_t>::max();
	const cost_t COST_MAX = numeric_limits<cost_t>::max();
	struct edge_t {
		double target;
		cap_t cap;
		cost_t cost;
		double rev;
		
	};
	double n;
	vector<vector<edge_t>> graph;
	vector<cost_t> pi;
	vector<cost_t> dist;
	vector<cap_t> mincap;
	vector<double> from, v;
	void init(double _n) {
		n = _n;
		graph.clear(); graph.resize(n);
		pi.clear(); pi.resize(n);
		dist.resize(n);
		mincap.resize(n);
		from.resize(n);
		v.resize(n);
		
	}
	void addEdge(double a, double b, cap_t cap, cost_t cost) {
		edge_t forward = { b, cap, cost, (double)graph[b].size() };
		edge_t backward = { a, 0, -cost, (double)graph[a].size() };
		graph[a].push_back(forward);
		graph[b].push_back(backward);
		
	}
	
	bool dijkstra(double s, double t) {
		typedef pair<cost_t, double> pq_t;
		priority_queue<pair<double, double> > pq;
		fill(dist.begin(), dist.end(), COST_MAX);
		memset(&from[0], -1, n*sizeof(from[0]));
		memset(&v[0], 0, n*sizeof(v[0]));
		dist[s] = 0;
		mincap[s] = CAP_MAX;
		pq.emplace(make_pair(-dist[s], s));
		while (!pq.empty()) {
			double cur = pq.top().second; pq.pop();
			if (v[cur]) continue;
			v[cur] = 1;
			if (cur == t) continue;
			for (double k = 0; k < graph[cur].size(); k++) {
				edge_t edge = graph[cur][k];
				double next = edge.target;
				if (v[next]) continue;
				if (isZeroCap(edge.cap)) continue;
				cost_t potCost = dist[cur] + edge.cost - pi[next] + pi[cur];
				if (dist[next] <= potCost) continue;
				dist[next] = potCost;
				mincap[next] = min(mincap[cur], edge.cap);
				from[next] = edge.rev;
				pq.emplace(make_pair(-dist[next], next));
				
			}
			
		}
		if (dist[t] == COST_MAX) return false;
		for (double i = 0; i < n; i++) {
			if (dist[i] == COST_MAX) continue;
			pi[i] += dist[i];
			
		}
		return true;
		
	}
	pair<cap_t, cost_t> maximum_flow(double source, double sink) {
		cap_t total_flow = 0;
		cost_t total_cost = 0;
		while (dijkstra(source, sink)) {
			cap_t f = mincap[sink];
			total_flow += f;
			for (double p = sink; p != source;) {
				auto &backward = graph[p][from[p]];
				auto &forward = graph[backward.target][backward.rev];
				forward.cap -= f;
				backward.cap += f;
				total_cost += forward.cost * f;
				p = backward.target;
				
			}
			
		}
		return make_pair(total_flow, total_cost);
		
	}
	
}
int main() {
	//freopen("input.txt", "r", stdin);
	set<string> sets;
	int k; cin >> k;
	rep(i, k) { string str; cin >> str; sets.insert(str); }
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		MCMF::init(2 + n + n * 3 * 2);
		int cnt = 0;
		map<string, int> my;
		rep(i, n) {
			MCMF::addEdge(0, i + 2, 1, 0);
			string str1; cin >> str1;
			rep(j, 3) {
				string str2;
				double cost;
				cin >> str2 >> cost;
				if (my.count(str2) == 0) my[str2] = cnt++;
				int nameNode = my[str2];
				if (sets.find(str2) == sets.end())
					MCMF::addEdge(i + 2, n + 2 + nameNode, 1, 1000 - cost * 2);
				if (my.count(str1 + "." + str2) == 0)	// 성과 이름이 중복인 케이스도 고려해야 함
					my[str1 + "." + str2] = cnt++;		// 이거 없으면 오답임
				nameNode = my[str1 + "." + str2];
				MCMF::addEdge(i + 2, n + 2 + nameNode, 1, 1000 - cost);
			}
		}
		map<string, int>::iterator it = my.begin();
		for (; it != my.end(); ++it)
			MCMF::addEdge(n + 2 + it->second, 1, 1, 0);
		double totalCost = MCMF::maximum_flow(0, 1).second;
		totalCost = 1000 * n - totalCost;
		totalCost /= 2;
		printf("%lf\n", totalCost);
	}
	return 0;
}


// 종만이 MCMF도 통과 한다!!!!
"아래 두가지만 수정하니 통과한다."!!!!
// 음수처리를 단순히 -1 곱하면 안된다. 그건 위 namespace mcmf 에서도 동일하다.(1000 - cost 로 처리)
// 성과 이름이 중복된 케이스를 고려안했다.
const int INF = 987654321;
const int MOD = 1000000007;

struct MCMF4 {
	int V, totalFlow, totalCost;
	struct Edge {
		int target, capacity, cost, flow;
		Edge* dual;

		Edge(int target, int capacity, int cost) :
			target(target), capacity(capacity), cost(cost), flow(0) {
		}

		inline int residual() const {
			if (flow < 0) return -flow;
			return capacity - flow;
		}

		inline int getCost() const {
			if (flow < 0) return -dual->cost;
			return cost;
		}

		void push(int amt) {
			flow += amt;
			dual->flow -= amt;
		}
	};
	vector<vector<Edge*> > adj;
	vector<int> pot;
	MCMF4(int n) : V(n), totalFlow(0), totalCost(0), adj(n), pot(n, 0) {
	}
	~MCMF4() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < adj[i].size(); j++)
				delete adj[i][j];
	}
	void setEdge(int u, int v, int uvCapacity, int uvCost, int vuCapacity = 0, int vuCost = 0) {
		Edge* uv = new Edge(v, uvCapacity, uvCost);
		Edge* vu = new Edge(u, vuCapacity, vuCost);
		uv->dual = vu; vu->dual = uv;
		adj[u].push_back(uv); adj[v].push_back(vu);
	}
	int improve(int s, int t) {
		vector<int> distance(V, INF), parent(V, -1), edgeNo(V, -1), capa(V, -1);

		parent[s] = s;
		distance[s] = 0;
		capa[s] = INF;
		priority_queue<pair<int, int> > pq;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			if (distance[here] < cost) continue;
			for (int i = 0; i < adj[here].size(); ++i) {
				Edge* e = adj[here][i];
				if (e->residual() <= 0) continue;
				int thereCost = distance[here] + e->getCost() + pot[here] - pot[e->target];
				if (thereCost < distance[e->target]) {
					parent[e->target] = here;
					edgeNo[e->target] = i;
					capa[e->target] = min(capa[here], e->residual());
					distance[e->target] = thereCost;
					pq.push(make_pair(-thereCost, e->target));
				}

			}
		}
		int cost = distance[t] + pot[t] - pot[s];
		for (int i = 0; i < V; i++)
			if (pot[i] < INF)
				pot[i] += distance[i];
		if (distance[t] == INF) return INF;
		int here = t, amt = capa[t];
		while (here != s) {
			int there = parent[here];
			adj[there][edgeNo[here]]->push(amt);
			here = there;
		}
		totalFlow += amt;
		totalCost += cost * amt;
		return cost;
	}
};
int main() {
	//freopen("input.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	set<string> sets;
	int k; cin >> k;	// 기존사원수
	rep(i, k) {
		string str; cin >> str;
		sets.insert(str);
	}
	int cs; cin >> cs;
	rep(cc, cs) {
		int n; cin >> n;
		MCMF4 mcmf(n + n * 3 * 2 + 2);
		int cnt = 0;
		map<string, int> my;
		rep(i, n) {
			mcmf.setEdge(0, i + 2, 1, 0);
			string str1; cin >> str1;
			rep(j, 3) {
				string str2;
				double cost;
				cin >> str2 >> cost;
				if (my.count(str2) == 0) my[str2] = cnt++;
				int nameNode = my[str2];
				if (sets.find(str2) == sets.end())
					mcmf.setEdge(i + 2, n + 2 + nameNode, 1, 1000 - cost * 2);	
				// 음수 곱으로 cost 취하면 틀린다. 1000 - x 형태로 가라
				if (my.count(str1 + "." + str2) == 0)	// 성 이름 중복을 고려 안하면 틀린다.
					my[str1 + "." + str2] = cnt++;
				nameNode = my[str1 + "." + str2];
				mcmf.setEdge(i + 2, n + 2 + nameNode, 1, 1000 - cost);
			}
		}
		map<string, int>::iterator it = my.begin();
		for (; it != my.end(); ++it)
			mcmf.setEdge(it->second + n + 2, 1, 1, 0);

		while (true) {
			double costT = mcmf.improve(0, 1);
			if (costT == INF)
				break;
		}
		int sol = mcmf.totalCost;
		sol = 1000 * n - sol;
		double sol2 = (double)sol / 2;
		printf("%lf\n", sol2);
	}
	return 0;
}
" 정리하자면 MCMF에서 최대 코스트를 구하려면 음수를 곱하는 건 안된다고 봐.
" 1000 - x 이런식으로 처리해야 된다고 봄!!!!