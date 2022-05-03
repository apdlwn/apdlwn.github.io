---
layout: post
title: "InsertionSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---

## Insertion Sort (삽입 정렬)

삽입 정렬이란, 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 부분과 비교하며 자신의 위치를 찾아가는 알고리즘 입니다. 즉, 현재 비교하고자 하는 요소와 그 이전의 요소들의 비교하며 자리를 교환합니다. 

### 정렬 방법

두번째 값을 첫번째 값부터 비교 -> 두번째 값보다 큰 값을 찾으면 그 자리에 두번째 값을 삽입하고 한 칸 씩 뒤로 밀기 => n-1번 반복

**처음 값은 무조건 두번째 값부터 시작한다.**

### Insertion Sort 소스 코드 

```java
import java.util.*;

public class Insertion_Sort {
	public static void insertion_sort(int[] a, int size) {
		for(int i=1; i<size; i++) {
			int target=a[i];
			int j=i-1;
			while(j>=0 && target<a[j]) {
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=target;
		}
	}
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int[] a=new int[32];
	//	Random random=new Random(); 
		int n=a.length;
		for(int i=0; i<n; i++) {  //int i=n-1; i>=0 i--역순으로 설정할때
	//		a[i]=random.nextInt(); 
			a[i]=i;
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		insertion_sort(a, a.length);
		for(int i=0; i<n; i++) {
			System.out.print(a[i]+" ");
		}
		long end = System.currentTimeMillis();
		System.out.print("\n");
		System.out.println("실행시간 : " + (end - start)/1000.0);
	}
}
```

### 시간 복잡도 

* 최선의 경우 

  비교 횟수 = 1번을 n-1번 하므로 **시간 복잡도는 O(n)**

* 최악의 경우
  
  비교 횟수 = 매번 모든 값을 비교해야하기 때문에 (n-1)+(n-2)+...=n(n-1)/2 이므로 **시간 복잡도는 O(n^2)**

