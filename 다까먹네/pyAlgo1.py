# 파이썬 알고리즘 인터뷰 리트코드 기출

"01 유효한 팰린드롬" : 대소문자 구분 없음, 영문자와 숫자만을 대상으로 한다.
input:
    "A man, a plan, a canal: Panama"
output:
    true
    
    
input:
    "race a car"
output:
    false

1. 리스트로 변활 풀이
def isPalindrome(self, s:str) -> bool:
    strs = []
    for char in s:
        if char.isalnum():
            strs.append(char.lower())   # 숫자는 그냥 들어가구나
    #판별
    while len(strs) > 1:
        if strs.pop(0) != strs.pop():   # 파이썬 list 는 vector 라 보면 됨 맨 앞 원소 제거에는 O(n) 이 듬 느림...
            return False
    return True

2. 데크 자료형 풀이
def isPalindrom(self, s: str) -> bool:
    #  자료형 데크로 선언
    strs: Deque = collections.deque()
    for char in s:
        if char.isalnum():
            strs.append(char.lower())   # 데크는 삭제가 양방향 O(1) 임
    while len(strs) > 1:
        if strs.popleft() != strs.pop():
            return False
    return True

3. 슬라이싱 사용
def isPalindrome(self, s: str) -> bool:
    s = s.lower()
    # 정규식으로 불필요한 문자 필터링
    s = re.sub('[^a-z0-9]', '', s)  # 걸러내기
    return s == s[::-1] # 슬라이싱: 속도가 c로 구현 되어서 매우 빠름
    

"02 문자열 뒤집기" 입력값은 문자 배여이며 리턴 없이 리스트 내부를 직접 조작하라
input:
    ["h", "e", "l", "l", "o"]
output:
    ["o", "l", "l", "e", "h"]
    
input
    ["H", "a", "n", "n", "a", "h"]
output:
    ["h", "a", "n", "n", "a", "H"]

1. 투포인터를 이용한 스왑
def reverseString(self, s: List[str]) -> None:
    left, right = 0, lens(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1
        
2. 파이썬다운 방식
def reverseString(self, s: List[str]) -> None:
    s.reverse()     # reverse 는 리스트에만 제공된다. 만약 입력값이 문자열이라면 앞서 살펴본 슬라이싱을 이용할 수 있다.
                    # s = s[::-1]
                
                
"03 로그파일 재정렬"
input: logs = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]
output: ["let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1", "dig2 3 6"]

for log in logs:
    tmp = log.split()   # "dig1 8 1 5 1" -> ["dig1", "8", "1", "5", "1"] 된다.
                        # "let1 art can" -> {"let1", "art", "can"] 이 된다.

letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))

def reorderLogFiles(self, logs: List[str]) -> List[str]:
    letters, digits = [], []
    for log in logs:
        if log.split()[1].isdigit():
            digits.append(log)
        else
            letters.append(log)
    # 2개의 키를 람다 표현식으로 정렬: 두번째 원소(문자열)부터 끝까지를 비교하고 두번째부터 끝까지가 같으면 첫번째 식별자를 가지고 정렬한다.
    letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        # 문자 로그가 다른 경우 로그비교로 순서를 정하고 문자 로그가 완전 일치하면 식별자 비교로 순서를 정한다.
    return letters + digits     # 문자로그는 앞쪽에 숫자로그는 뒷쪽에
    
--- 부연설명 --- // 두번째 놈을 우선순위를 두고 정렬
s = ['2 A', '1 B', '4 C', '1 A']
sorted(s)
---> ['1 A', '1 B', '2 A', '4 C']
s 자체가 바뀌는 건 아니다.
s
---> ['2 A', '1 B', '4 C', '1 A']

def func(x):
    return x.split()[1], x.split()[0]

s.sort(key=func)
s
---> ['1 A', '2 A', '1 B', '4 C']

# 람다 처리
s.sort(key=lambda x: (x.split()[1], x.split()[0]))
s
---> ['1 A', '2 A', '1 B', '4 C']
"람다 표현식은 코드가 길어지고 map 이나 filter 와 함께 섞어서 사용하기 시작하면 가독성이 매우 떨어질 수 있으므로 주의가 필요"


"04 가장 흔한 단어"
금지된 단어를 제외한 가장 흔하게 등장하는 단어를 출력하라. 대소문자 구분안함, 구두점(마침표, 쉼표 등) 또한 무시한다.
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
출력: "ball"

http://regexp.elex.pe.kr/regular-expression // 점화식 \w 의 의미: [A-Za-z0-9_]  "영문자와 숫자 그리고 밑줄 문자"

tmp = re.sub(r'[^\w]', ' ', paragraph)
"Bob hit a ball, the hit BALL flew far after it was hit."
'Bob hit a ball  the hit BALL flew far after it was hit '

tmp2 = tmp.lower().split()
['bob', 'hit', 'a', 'ball', 'the', 'hit', 'ball', 'flew', 'far', 'after', 'it', 'was', 'hit']

for word in tmp2
    print(word)
차례대로 출력됨
bob
hit
a
ball
the
...

리스트 컴프리헨션: 설명 잘되어 있는 곳: https://wikidocs.net/22805  # 문법이 생소한 거임. 익숙해지삼
>>> [ 2*x for x in range(1, 10+1) ]
[2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

>>>  [x for x in range(1, 10+1) if x % 2 == 0]
[2, 4, 6, 8, 10]

def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
    words = [word for word in re.sub(r'[^\w', ' ', paragraph)       # 공백만들고
        .lower().split()                                            # 소문자화 한 뒤 단어 단위로 분리하고
        if word not in banned]                                      # 금지어에 있는 경우엔 제외
    
    counts = collections.Counter(words)
    return counts.most_common(1)[0][0]
    
    
# 내가 원한 맵이네 아래는
counts = collections.defaultdict(int)
for word in words:
    counts[word] += 1
return max(counts, key=counts.get)  # value 가 가장 큰 값의 key 를 리턴한다.


counts = collections.defaultdict(int)
counts['abc'] += 1      # 쌍따옴표로 "abc" 넣으니 빌드 오류남.  나의 착각이다 {"abc"] += 1 이렇게 했더라 썅
counts['bmp'] += 1
counts['abc'] += 1
counts['bmp'] += 1
counts['eee'] += 1
emp = max(counts, key=counts.get)   # 두 후보가 있지만 emp 는 'abc' 가 되어있음: value 가 동일한땐 최초 삽입된 놈이 우선임
                                    # max 내의 key 는 오해하면 안됨 그건 max 로 인정될 조건일 뿐입 그 조건이 counts.get 하기에 value 가 됨
                                    # return 값은 counts 의 key 중 하나가 됨.

# 가장 흔하게 등장하는 단어의 첫번째 값을 most_common(1) 로 추출한다. 정답이 여러개 존재할 수 있음
# [('abc', 2), ('bmp', 2)] 따라서 접근을 [0][0] 으로 했다.
counts = collections.Counter(words)
return counts.most_common(1)[0][0]                                  

--------------------------------------------------
"05 그룹 애너그램"
문자열 배열을 받아 애너그램 단위로 그룹핑하라
입력: ["eat", "tea", "tan", "ate", "nat", "bat"]
출력
[
    ["ate", "eat", "tea"],
    ["nat", "tan"],
    ["bat"]
]

def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    anagrams = collections.defaultdict(list)
    
    for word in strs:
        # 정렬하여 딕셔너리에 추가
        anagrams[''.join(sorted(word))].append(word)
    return list(anagrams.values())
    
word = 'eat'
tmp = sorted(word)  # ['a', 'e', 't']   // 각 char 별로 list 화 되네..
tmp2 = ''.join(sorted(word)) # 'aet'


anagrams.values() 는 dict_values([['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]) 로 나온다.
그걸 list 로 다시 추출하자
list(anagrams.values()) 는 [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']] 이렇게 나온다.

# collections.defaultdict(list) 구문 없이 그냥 딕셔너리 쓰면 어찌 되는가?
car = {"name" : "BMW",  "price" : "7000" } 
car["series"] = 7 
print(car)      # {'name': 'BMW', 'price': '7000', 'series': 7}

car["name"] = "Santafe"     // 삽입은 된다.
print(car)      # {'name': 'Santafe', 'price': '7000', 'series': 7}

del car["nam"]  예외가 발생함
print(car)      # {'price': '7000', 'series': 7}

"허나 기존 값에 갱신이 어렵다?" 잘만 되는 뎁쇼... 굳이 defaultdict 는 명시적으로 보이게끔 아닌가 싶다.
car = {}
car["abc"] = ['7']
car["eee"] = ['3']
car["abc"].append('7')
car["ccc"] = []
car["ccc"].append('c')
# {'abc': ['7', '7'], 'ccc': ['c'], 'eee': ['3']}

"정렬 방법 정리"
sorted, sort() 차이
aSortedList = sorted(aList)
sList.sort()    None 을 리턴한다. sList 자체가 바뀐다. # 제자리 정렬 In-place Sort

key 옵션
c = ['ccc', 'aaaa', 'd', 'bb']
sorted(c, key=len)
---> ['d', 'bb', 'ccc', 'aaaa']

응용 # 첫문자를 먼저 보고 그뒤 마지막 문자를 보는 정렬
a = ['cde', 'cfc', 'abc']
def fn(s):
    return s[0], s[-1]
print(sorted(a, key=fn))
---> ['abc', 'cfc', 'cde']

응용 # 람다
a = ['cde', 'cfc', 'abc']
sorted(a, key=lambda s: (s[0], s[-1])) # s 가 오면 s[0], s[-1] 을 리턴하라
---> ['abc', 'cfc', 'cde']


--------------------------------------------------
"06 가장 긴 팰린드롬 부분 문자열" 가장 긴 회문찾기 manacher's algorithm 도 기회되면 보삼
# 시간복잡도가 높을거 같은데.. O(n^2) 으로 보임. tco4 에서 palindrom : O(n^2) 은 dp 였는데.. 아래가 더 간단하네

def longestPalindrom(self, s: str) -> str:
    # 팰린드롬 판별 및 투 포인터 확장
    def expand(left: int, right: int) -> str:
        while (left >= 0 and right <= lens(s) and s[left] == s[right - 1]:
            left -= 1
            right += 1
        return s[left + 1: right - 1]
    # 해당 사항이 없을 때 빠르게 리턴
    if len(s) < 2 or s == s[::-1]:
        return s
    
    result = ''
    # 슬라이딩 윈도우 우측으로 이동
    for i in range(len(s) - 1):
        result = max(result,
                        expand(i, i + 1),   # aba 에서 i 가 1이고 i+1 는 2로 해서 들어가고 3이 리턴됨
                        expand(i, i + 2),   # abba 에서 i가 1이고 i+2 는 3로 해서 들어가고 4가 리턴됨
                        key = len)
    return result
    
    
<<<7장 배열>>>
--------------------------------------------------    
"07 두 수의 합" 덧셈하여 타겟을 만들 수 있는 배열의 두 숫자 인덱스를 리턴하라 (nums 는 정렬되어 있지 않아요)
입력
    nums = [2, 7, 11, 15], target = 9
출력
    [0, 1]
    
풀이 1) 브루트포스 O(n^2): 5284ms
def twoSum(self, nums: List[int], target: int) -> List[int]:
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
                
풀이 2) in 을 이용한 탐색 O(n^2): 864ms
def twoSum(self, nums: List[int], target: int) -> List[int]:
    for i, n in enumerate(nums):
        complement = target - n     # 보수
        
        if complement in nums[i + 1:]:  # 파이썬의 내부 함수이며 파이썬 레벨에서 매번 값을 비교하는 것보다 훨씬 더 빨리 실행됨
            return nums.index(n), nums[i + 1:].index(complement) + (i + 1)
 
풀이 3) 시간복잡도 개선 O(n): 48ms
def twoSum(self, nums: List[int], target: int) -> List[int]:
    nums_map = {}
    # 키와 값을 바꿔서 딕셔너리로 저장
    for i, num in enumerate(nums):
        nums_map[num] = i
        
    # 타겟에서 첫 번째 수를 뺀 결과를 키로 조회
    for i, num in enumerate(nums):
        # 딕셔너리에 보수가 존재하고 그 놈이 자기자신이 아닌 경우
        if target - num in nums_map and i != nums_map[target - num]:
            return nums.index(num), nums_map[target - num]
            

--------------------------------------------------    
"08 빗물 트래핑" 높이를 입력받아 비 온 후 얼마나 물이 쌓일 수 있는지 계산하라
42. Trapping Rain Water
입력
    [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
          +1    +1 +2 +1
출력
    6
    
풀이 1) 투 포인터를 최대로 이동
def trap(self, height: List[int]) -> int:
    if not height:
        return 0
    volume = 0
    left, right = 0, len(height) - 1
    left_max, right_max = height[left], height[right]
    
    while left < right:
        left_max, right_max =   max(height[left], left_max), 
                                max(height[right], right_max)
        # 더 높은 쪽을 향해 투 포인터 이동
        if left_max <= right_max:
            volume += left_max - height[left]
            left += 1
        else:
            volume += right_max - height[right]
            right -= 1
            
    return volume
    
       *
   *   ** *
 * ** ******

                            ____                    3
            ____                ____    ____        2
    ____        ____    ____        ____    ____    1
____    ____        ____                            0

0   1   0   2   1   0   1   3   2   1   2   1          
0   1   2   3   4   5   6   7   8   9   10  11

left                                        right           lm  l   rm  r   vol
0                                           1               0   0   1   1   0
    1                                       1               1   1   1   1   0 
        0                                   1               1   0   1   1   0 -> 1      # add = lm - l = 1 - 0 = 1   
            2                               1               2   2   1   1   1    
            2                           2                   2   2   2   2   1
                1                       2                   2   1   2   2   1 -> 2      # add = lm - l = 2 - 1 = 1
                    0                   2                   2   0   2   2   2 -> 4      # add = lm - l = 2 - 0 = 2
                        1               2                   2   1   2   2   4 -> 5      # add = lm - L = 2 - 1 = 1
                            3           2                   3   3   2   2   5
                            3       1                       3   3   2   1   5 -> 6      # add = rm - r = 2 - 1 = 1
                            3   2                           3   3   2   2   6
                            33                              3   3   3   3   6

풀이 2) 스택 쌓기 O(n) :56ms
def trap(self, height: List[int]) -> int:
    stack = []
    volume = 0
    
    for i in range(len(height)):
        # stack 에 들어 있는 것은 정렬된 상태이며, back(가장 뒤)이 가장 작다.
        # 현재 높이가 stack 내 원소보다 큰것들은 back 에서 부터 제거한다.
        while stack and height[i] > height[stack[-1]]:
            # 스택에서 꺼낸다
            top = stack.pop()

            if not len(stack):
                break
            
            # 이전과의 차이만큼 물 높이 처리
            distance = i - stack[-1] - 1
            # 스택에 마지막 두개가 같은 높이인 경우 waters 높이가 0이 된다.
            waters = min(height[i], height[stack[-1]]) - height[top]    
            
            volume += distance * waters
        
        stack.append(i)
    return volume

                                        ____            5
        ____                    ____                    4
            ____            ____    ____                3
                ____                                    2
    ____            ________                            1
____                                                    0
        
0   1   4   3   2   1   1   3   4   3   5
0   1   2   3   4   5   6   7   8   9   10
        
        4   4   4   4   4   4   4   4   5       
            3   3   3   3   3   4   4
                2   2   2   3       3
                    1   1   
                        1
# 10번째 처리때 4 4 3 이 뒤에서부터 지워짐 4-3 = 1 에서 waters height 가 1, 그뒤엔 4-4 = 0


--------------------------------------------------    
"09 세 수의 합"
15. 3Sum
입력
    nums = [-1, 0, 1, 2, -1, -4]
출력
    [
        [-1, 0, 1],
        [-1, -1, 2]
    ]
풀이 1) 브루트 포스로 계산 O(n^3) : time out
def threeSum(self, nums: List[int]) -> List[List[int]]:
    results = []
    nums.sort()
    
    # 브루트 포스 n^3 반복
    for i in range(len(nums) - 2):
        # 중복된 값 건너뛰기
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        for j in range(i + 1, len(nums) - 1):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue
            
            for k in range(j + 1, len(nums)):
                if k > j + 1 and nums[k] == nums[k - 1]:
                    continue
                    
                if nums[i] + nums[j] + nums[k] == 0:
                    results.append([nums[i], nums[j], nums[k]])
    return results
    
풀이 2) 투 포인터로 합 계산 O(n^2) : 884ms    # 중복 처리하는 방법이 재밌네
def threeSum(self, nums: List[int]) -> List[List[int]]:
    results = []
    nums.sort()
    
    for i in range(len(nums) - 2):
        # 중복된 값 건너뛰기
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        # 간격을 좁혀가며 합 sum 계산
        left, right = i + 1, len(nums) - 1
        while left < right:
            sum = nums[i] + nums[left] + nums[right]
            if sum < 0:
                left += 1
            elif sum > 0:
                right -= 1
            else:
                # sum = 0 인 경우이므로 정답 및 스킵 처리
                results.append([nums[i], nums[left], nums[right]])
                
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                left += 1
                right -= 1
    return results

--------------------------------------------------
"10 배열 파티션I" 너무 쉬운거
n개의 페어를 이용한 min(a, b) 의 합으로 만들 수 있는 가장 큰 수를 출력하라 (숫자는 짝수 개)
입력
    [1, 4, 3, 2]
출력
    4
풀이 1) 332ms
def arrayPairSum(self, nums: List[int]) -> int:
    sum = 0
    pair = []
    nums.sort()
    
    for n in nums:
        # 앞에서부터 오름차순으로 페어를 만들어서 합 계산
        pair.append(n)
        if len(pair) == 2:
            sum += min(pair)
            pair = []   # 초기화
    return sum

풀이 2) 308ms
def arrayPairSum(self, nums: List[int]) -> int:
    sum = 0
    nums.sort()
    
    for i, n in enumerate(nums):
        # 짝수 번째 값의 합 계산
        if i % 2 == 0:
            sum += n
    return sum

풀이 3) 파이썬다운 방식 284ms
def arrayPairSum(self, nums: List[int]) -> int:
    return sum(sorted(nums)[::2])       # (시작인덱스: 끝인덱스: 점프간격)





<<<8장 연결리스트>>>
--------------------------------------------------
"13 팰린드롬 연결 리스트"
입력
    1->2
출력
    false
입력
    1->2->2->1
출력
    true
풀이 1) 연결리스트를 파이썬의 리스트로 변환해서 풀기 # 첫원소 삭제시 비용이 크다.
def isPalindrome(self, head: ListNode) -> bool:


풀이 2)
def isPalindrome(self, head: ListNode) -> bool:

풀이 4) 런너를 이용한 우아한 풀이 : 64ms
def isPalindrome(self, head: ListNode) -> bool:
    rev = None
    slow = fast = head
    # 런너를 이용해 역순 연결 리스트 구성
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, slow = slow, rev, slow.next
    if fast:
        slow = slow.next
    # 팰린드롬 여부 확인
    while rev and rev.val == slow.val:
        slow, rev = slow.next, rev.next
    return not rev

--------------------------------------------------
"14 두 정렬 리스트의 병합"
정렬되어 있는 두 연결 리스트를 합쳐라(정렬된 상태로)
입력
    1->2->4, 1->3->4
출력
    1->1->2->3->4->4
    
풀이1) 재귀 구조로 연결
def mergeTwoList(selfself, l1: ListNode, l2: ListNode) -> ListNode
    # 항상 선택되는 놈을 l1 으로 두자
    if (not l1) or (l2 and l1.val > l2.val)     # l1이 없거나, l2가 있고 l1보다 작은 경우 
        l1, l2 = l2, l1     # 임시 변수 없이 swap 할 수 있어 편하네!!
        
    if l1:
        l1.next = self.mergeTwoLists(l1.next, l2)
    return l1


--------------------------------------------------
"15 역순 연결 리스트"
연결 리스트를 뒤집어라
입력
    1->2->3->4->5->NULL
출력
    5->4->3->2->1->NULL

풀이1) 재귀 구조로 뒤집기 : 40ms
def reverseList(self, head: ListNode) -> ListNode:
    def reverse(node: ListNode, prev: ListNode = None):
        if not node:
            return prev
        next, node.next = node.next, prev
        
        return reverse(next, node)
    return reverse(head)

reverse(1, None)
    reverse(2, 1)   # 1->None
        reverse(3, 2)   # 2->1->None
            reverse(4, 3)   
                reverse(5, 4)
                    reverse(None, 5)
                        return 5
                        
풀이2) 반복 구조로 뒤집기
def reverseList(self, head: ListNode) -> ListNode:
    node, prev = head, None
    
    while node:
        next, node.next = node.next, prev
        prev, node = node, next
        
            
    return prev
                        

next, node.next = 2, None
prev, node = 1, 2

next, node.next = 3, 1
prev, node = 2, 3

--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




--------------------------------------------------




