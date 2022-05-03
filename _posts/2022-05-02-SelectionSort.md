---
layout: post
title: "SelectionSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---

## Selection Sort (선택 정렬)

선택 정렬이란, 제자리 정렬 알고리즘의 하나로서 해당 순서에 원소를 넣을 위치는 이미 정해져 있고, 그 위치에 어떤 원소를 넣을지 선택하는 알고리즘 입니다. 

여기서 제자리 정렬이란, 입력 배열 이외에 다른 추가 메모리를 요구하지 않는 정렬 방법을 말합니다. 

선택 정렬과 삽입 정렬이 비슷해보이는데, 삽입 정렬은 배열의 모든 값을 비교하여 자신의 위치를 찾아가는 것이고, 선택 정렬은 정해진 자리에 들어올 값을 찾는 것입니다. 

### 정렬 방법

첫번째 값을 두번째 값부터 마지막 값 까지 비교하여 가장 작은 값을 찾아 첫번째에 놓고, 두번째 값을 세번째 값부터 마지막 값 까지 비교하여 그 중 가장 작은 값을 찾아 두번째 위치에 놓는 것을 반복하여 정렬합니다. 

[1] 배열 중 최소값을 찾습니다. 

[2] 그 값을 맨 앞에 위치한 값과 교환합니다. 

[3] 맨 처음 값을 제외한 나머지 값들로 1-2번을 반복합니다.(n-1번 반복)

### Selection Sort 소스 코드

```java
import java.util.*;

public class Selection_Sort {
	public static void selection_sort(int[] a) {
		int size=a.length;
		for(int i=0; i<size-1; i++) {
			int min_index=i;
			for(int j=i+1; j<size; j++) {
				if(a[j]<a[min_index])
					min_index=j;
			}
			int temp=a[min_index];
			a[min_index]=a[i];
			a[i]=temp;
		}
	}
	public static void main(String[] args) {
		int[] a=new int[1048576];
	//	Random random=new Random(); 
		int n=a.length;
		for(int i=0; i<n; i++) {  //int i=n-1; i>=0 역순으로 설정할때
		//	a[i]=random.nextInt(); 
			a[i]=i;
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		long start = System.currentTimeMillis();
		selection_sort(a);
		long end = System.currentTimeMillis();
		for(int i=0; i<n; i++) {
		System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		System.out.println("실행시간 : " + (end - start)/1000.0);
	}
}
```

### 시간 복잡도

데이터 갯수가 n개라면 
첫번째 1-2번 반복 -> n-1 + 두번째 1-2번 반복 -> n-2 + ... = n(n-1)/2

그러므로 **시간 복잡도는 O(n^2)**