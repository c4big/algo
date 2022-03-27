회문찾기	// palindrom : O(n^2),  string 길이가 30000 이상이면 가장 긴 길이의 회문 찾으려면 manacher's algorithm 으로 검색해봐라. 백준에도 있다.
// 전체 회문의 갯수를 리턴한다.   https://leetcode.com/problems/palindromic-substrings/
int dp[1010][1010];
class Solution {
public:
int countSubstrings(string s) {
    memset(dp, 0, sizeof(dp));
	int ans = 0;
	
	// 한개짜리
	for (int i = 0; i < s.size(); ++i) {
		dp[i][i] = 1;
		ans++;
	}
	
	// 두개짜리
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
			ans++;
		}
	}
	
	// 세개 이상
	for (int sz = 3; sz <= s.size(); ++sz) {
		for (int i = 0; i < s.size(); ++i) {
			int begin = i;
			int end = i + sz - 1;
			if (end >= s.size()) continue;
			if (dp[begin + 1][end - 1] == 1 && (s[begin] == s[end])) {
				dp[begin][end] = 1;
				ans++;
			}
		}
	}
	return ans;
}
};

// 문제: 카카오 블라인드 6번 : 1000 by 1000 에 영역 덧셈, 뺄샘을 시작한 후 각 지점에서 0보다 큰 갯수 찾기 문제
// 업데이트는 
2차원 구간 업데이트 포인트 쿼리 처리 : 2d range update point query
// 해당 자료구조를 찾아봤지만 시간만 소비하고 찾기가 힘듬...
"근데 부분합으로 간단히 처리가 된다는 .. 으아아아" // 왜냐면 구간을 마지막에 계산하면 되기 때문이다.



https://leetcode.com/problems/unique-paths-iii/		// 모든사각형을 다 채우고 목적지까지 도달 가능한 경우의 수

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20		// bitset 으로 방문여부를 기록해야 하나
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.

// 모든 경로를 밝아야 하므로 bitset 으로 모든것을 방문했는지 체크안해도 된다. 방문한 square 갯수를 총 방문할 square 갯수랑 비교하면 되기 때문이다.
class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j, int s, int c) {
        // invalid indexes or position
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return 0;
        
        // we reached target, now compare if the number of steps matches the number of empty cells
        if(grid[i][j] == 2)
            return s == c ? 1 : 0;	// 방문한 square cnt == 방문할 square cnt 이면 1을 리턴한다.
        
        // mark as processed
        grid[i][j] = -1;
        
        // explore all the directions
        int path = dfs(grid, i + 1, j, s + 1, c) 
                 + dfs(grid, i - 1, j, s + 1, c) 
                 + dfs(grid, i, j + 1, s + 1, c) 
                 + dfs(grid, i, j - 1, s + 1, c);
        
        // backtrack and mark as available
        grid[i][j] = 0;
        
        return path;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // starti & startj hold the position of starting square
        // count holds the number of empty cells
        int starti = 0, startj = 0, count = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    starti = i;
                    startj = j;
                }
                
                if(grid[i][j] != -1)
                    count++;
            }
        }
        
        return dfs(grid, starti, startj, 1, count);
    }
};


https://leetcode.com/contest/weekly-contest-260/problems/grid-game/
문제설명: 
2 by 50000 크기를 가진 grid 가 있다. (행은 항상 2임)
이동방향은 아래 혹은 오른쪽이다. 그리고 맨 오른쪽 아랫단에 도달하면 종료한다.
첫번째 놈이 지나가면서 점수를 가져가면 grid 의 값들은 모두 0이 된다
이후 두번째 놈이 지나가면서 점수를 최대한 얻으려고 한다.

첫번째 놈은 두번째 놈이 얻는 점수를 최소화 하고 싶어 한다.

"나의 접근"
	// 첫번째가 최대한 많은 점수를 가져가면 두번째는 최저가 되겠지 하고 dp 로 풀어봤는데 --> 그게 틀렸다 !!
"다시 접근"	
	//각 지점에서 아래로 꺽인 경우 b는 위나 아래 둘중 하나만 의미있는 점수가 된다.
idx	0 1 2 3 4 5 6 7
	4 1 3 2 1 5 2 3
	9 7 3 2 7 8 9 1
	
첫번째가 idx 4에서 꺽인 경우	
idx	0 1 2 3 4 5 6 7
	0 0 0 0 0 5 2 3
	9 7 3 2 0 0 0 0
	// 이경우 두번째는 9+7+3+2 or 5+2+3 둘 중 하나를 얻게 된다. 이 계산은 부분합으로 처리하면 된다.
	
	
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> uPsum(grid[0].size());
        vector<long long> dPsum(grid[0].size());
        for (int i = 0; i < grid[0].size(); ++i) {
            if (i == 0) {
                uPsum[0] = grid[0][0];
                dPsum[0] = grid[1][0];
            }
            else {
                uPsum[i] = uPsum[i - 1] + grid[0][i];
                dPsum[i] = dPsum[i - 1] + grid[1][i];
            }
        }
        long long sol = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            if (i == 0)
                sol = uPsum[n - 1] - uPsum[0];
            else {
                long long cand1 = uPsum[n - 1] - uPsum[i];
                long long cand2 = dPsum[i - 1];
                long long cand = max(cand1, cand2);
                sol = min(sol, cand);
            }
        }
        return sol;
    }
};


https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/
낱말퍼즐

ex1)
"# #"
"  #"
"#c "
word = "abc"
return output = true
//"#a#"
//" b#"
//"#c "


ex2)
" #a"
" #c"
" #a"
word = "ac"
return output = false


ex3)
"# #"
"  #"
"# c"
word = "ca"
return output = true	// 오른쪽에서 왼쪽으로 단어가 채워져도 된다.
//"# #"
//"  #"
//"#ac"

제약사항:
1 <= m * n <= 2 * 10^5	// 흐미
1 <= word.length <= max(m, n)


// 다들 시간복잡도가 구질구질하다. 노가다로 풀어야 하나.. 싫다. 참신한 소스 나중에 나오면 참고하자.
	https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/discuss/?currentPage=1&orderBy=most_votes&query=easy%20understanding
	
// 시간복잡도 상으론 최대 400억이 될수 있는데 ... 이 코드를 돌리면 316 ms 밖에 안걸린다.	// 코드포스 레드 것
class Solution {
public:
    bool check(vector<vector<char>> a,string s){
        int n = a.size(), m = a[0].size(), l = s.size();
        for(int i=0;i<n;i++) for(int j=0;j+l-1<m;j++){
            if((j==0||a[i][j-1]=='#') && (j+l-1==m-1||a[i][j+l]=='#')){
                int ok = 1;
                for(int k=0;k<l;k++){
                    if(a[i][j+k]==' ') continue;
                    if(a[i][j+k]!=s[k]) ok = 0;
                }
                if(ok) return true;
            }
        }
        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> boardr = vector<vector<char>>(n,vector<char>(m));
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) boardr[j][i] = board[i][j];	// 대각선 대칭
        if(check(board,word)) return true;
        if(check(boardr,word)) return true;
        reverse(word.begin(),word.end());	// 찾는 문자열을 reverse
        if(check(board,word)) return true;
        if(check(boardr,word)) return true;
        return false;
    }
};

https://leetcode.com/contest/weekly-contest-277/problems/maximum-good-people-based-on-statements/
leetcode 연습문제 virtual 277 (weekly contest 4) 
// 문제 해석이 어려운 문제
N 이 최대 16 임
C++ Bitmask Subset Traversal O(2^N * N^2)	// 2^16 = 65536, 16^2 = (2^4)^2 = 2^8		// 약 400만
class Solution {
public:
	int maximumGood(vector<vector<int>& A) {
		int N = a.size(), ans = 0;
		auto valid = [&](int m) {
			for (int i = 0; i < N; ++i) {
				if (m >> i & 1) {	// person i is good
					for (int j = 0; j < N: ++j) {
						int good = m >> j & 1;
						if ((A[i][j] == 0 && good) || (A[i][j] == 1 && !good)) return false;
					}
				}
			}
			return true;
		};
		for (int m = 1; m < (1 << N); ++m) {
			if (valid(m)) ans = max(ans, __builtin_popcount(m));
		}
		return ans;
	}
};



https://leetcode.com/problems/minimum-time-to-finish-the-race/
https://leetcode.com/problems/minimum-time-to-finish-the-race/discuss/1802444/C%2B%2B-Linear-time-DP-with-explanation
// 타이어들이 있다. 자동차는 한 lap 을 돌고 나서 타이어를 교체할 수 있고 아니면 그냥 달릴수도 있다.
그냥 달리게 되면 vector<vector<int>> tires 
fi = tires[i][0]		// 초항
ri = tires[i][1]		// 공비
lap time = fi * ri^(횟수 - 1) 만큼 시간이 걸림
즉 
tires[3][0] // fi 가 2 이고
tires[3][1] // ri 가 5 라면
3번 타이어로 
첫번째 랩타임은 2 가 되고
두번째 랩타임은 2 * 5 가 되고
세번째 랩타임은 2 * 5^2 이 된다.

타이어를 교체하는데 걸리는 시간은 changeTime 이 된다.
교체는 3번 타이어에서 3번 타이어로도 가능하다. 뭐 changeTime 이 존재하지만 말이다.

제한조건
1 <= tires.size <= 10^5
tires[i].size == 2
1 <= fi, changeTime <= 10^5
2 <= ri <= 10^5
1 <= numLaps <= 1000

// 접근법
타이어를 교체 + 교체바퀴로 첫번째 도는 시간 = 10^5 + 10^5 를 넘길수 없다.
즉 타이어를 안바꾸는 케이스는 2^19 부터 262142 가 되어서 필요없다.
즉 2^18 까지만 고려하면 된다.

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        // to handle the cases where numLaps is small
		// without_change[i][j]: the total time to run j laps consecutively with tire i
		"타이어를 안 바꾸는 케이스(랩타임 19 이하)"
        vector<vector<int>> without_change(n, vector<int>(20, 2e9));
        for (int i = 0; i < n; i++) {
            without_change[i][1] = tires[i][0];
            for (int j = 2; j < 20; j++) {
                if ((long long)without_change[i][j-1] * tires[i][1] >= 2e9)
                    break;
                without_change[i][j] = without_change[i][j-1] * tires[i][1];
            }
            // since we define it as the total time, rather than just the time for the j-th lap
			// we have to make it prefix sum
			"누적 시간"
            for (int j = 2; j < 20; j++) {
                if ((long long)without_change[i][j-1] + without_change[i][j] >= 2e9)
                    break;
                without_change[i][j] += without_change[i][j-1];
            }
        }
		// dp[x]: the minimum time to finish x laps
        vector<int> dp(numLaps+1, 2e9);
        for (int i = 0; i < n; i++) {
            dp[1] = min(dp[1], tires[i][0]);
        }
        for (int x = 1; x <= numLaps; x++) {
            if (x < 20) {
				// x is small enough, so an optimal solution might never changes tires!
                for (int i = 0; i < n; i++) {
                    dp[x] = min(dp[x], without_change[i][x]);
                }
            }
            for (int j = x-1; j > 0 && j >= x-18; j--) {
                dp[x] = min(dp[x], dp[j] + changeTime + dp[x-j]);
            }
        }
        return dp[numLaps];
    }
};


// 이해하기 쉽게 기저2 로 따로 빼서 제출 통과
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
		"타이어를 안 바꾸는 케이스(랩타임 19 이하)"
        vector<vector<int>> without_change(n, vector<int>(20, 2e9));
        for (int i = 0; i < n; i++) {
            without_change[i][1] = tires[i][0];
            for (int j = 2; j < 20; j++) {
                if ((long long)without_change[i][j-1] * tires[i][1] >= 2e9)
                    break;
                without_change[i][j] = without_change[i][j-1] * tires[i][1];
            }
			"누적 시간"
            for (int j = 2; j < 20; j++) {
                if ((long long)without_change[i][j-1] + without_change[i][j] >= 2e9)
                    break;
                without_change[i][j] += without_change[i][j-1];
            }
        }
		// dp[x]: the minimum time to finish x laps
        vector<int> dp(numLaps+1, 2e9);
        
		// 기저1 : 초기값
		for (int i = 0; i < n; i++) 
            dp[1] = min(dp[1], tires[i][0]);
		
		// 기저2 : 타이어를 안바꾸고도 답이 되는것들 세팅
		for (int x = 1; x < 20; ++x) {
			if (x > numLaps) break;
			for (int i = 0; i < n; ++i)
				dp[x] = min(dp[x], without_change[i][x]);
		}
		
		// dp 계산
        for (int x = 1; x <= numLaps; x++) 
            for (int j = x-1; j > 0 && j >= x-18; j--) 
                dp[x] = min(dp[x], dp[j] + changeTime + dp[x-j]);
        
        return dp[numLaps];
    }
};





































