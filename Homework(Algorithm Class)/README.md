Algorithm Class 과제 (작성 중)

  - Chained_Matrix_Multi.cpp
    - 이 과제는 연속된 행렬 곱 계산 수행 시 최소 계산 횟수의 순서를 찾는 코드이다.
    
    - 추가된 라이브러리
      - "iostream", "fstream", "string", "vector"
    
    - define Min(X,Y) ((X) < (Y) ? (X) : (Y)) 
      - 3항 연산자를 이용한 Min 값 구하는 함수 define
    
    - void print_order(int i, int j)
      - vector outA에 담긴 행렬들을 순서대로 출력하는 함수이다.
      
    - 핵심 알고리즘
    
      for (diagonal = 1; diagonal < inM.size(); diagonal++) {
      
	    	for (i = 1; i < inM.size() - diagonal; i++) {
        
    			j = i + diagonal;
          
    			tmp = 100000;
          
    			for (k = i; k < j; k++) {
          
    				p = tmp;
            
     				tmp = Min(tmp, (M[i][k] + M[k+1][j] + (inM[i - 1] * inM[k] * inM[j])));
            
     				if (p > tmp) P[i][j] = k;
            
	    		}
          
	    		M[i][j] = tmp;
          
	    	}
        
    	}
      
      
