(문제번호) (문제이름).cpp 파일들은
Baejoon Online Judge 의 문제들을 풀이한 cpp파일들입니다.

README 작성중..

  - 17140 이차원 배열과 연산.cpp
  
  - 17143 낚시왕.cpp
  
  - 17144 미세먼지 안녕!.cpp
  
  - 17281 야구.cpp
  
  - 17472 다리 만들기2.cpp
  
    - DFS, Kruskal 알고리즘 사용
    
      1. DFS를 사용하여 주어진 입력들의 섬을 구분하고 섬들의 번호를 매긴다.

      2. Class Edge를 선언하고 Vector<Edge>에 연결되는 섬의 번호와 다리길이를 담는다.

      3. sort() 함수를 사용하여 다리길이가 오름차순이 되도록 정렬한다.
          (이를 위해 Edge 클래스에 operator < 를 선언해야함)

      4. Union, Find를 사용한 Kruskal 알고리즘으로 최소 신장트리를 만든다.

      5. 모든 섬이 연결되어있는지 확인한다.
