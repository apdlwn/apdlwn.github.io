---
layout: post
title: "ShellSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---

## Shell Sort (셸 정렬)

셸 정렬은, 삽입 정렬의 장점은 살리고 단점은 보완하여 더 빠르게 정렬하는 알고리즘 입니다. 

  * 삽입 정렬 : 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 부분과 비교하며 자신의 위치를 찾아가는 알고리즘 입니다.

### 정렬 방법

[1] 배열의 값들을 그룹으로 나눕니다.

[2] 그룹별로 삽입 정렬을 수행합니다.

[3] 그 그룹들을 합치면서 정렬을 반복하여 값의 이동 횟수를 줄입니다.

[4] 그룹의 갯수가 1이 될 때 까지 2-3번을 반복합니다. 

### Shell Sort 소스 코드

```java
import java.util.*;

public class Shell_Sort {
	public static void shell_sort(int[] a) {
		int size=a.length;
		for(int h=size/2; h>0; h/=2) {
			for(int i=h; i<size; i++) {
				int j;
				int temp=a[i];
				
				for(j=i-h; j>=0 && a[j]>temp; j-=h)
					a[j+h]=temp;
				a[j+h]=temp;
			}
		}
	}
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int[] a=new int[32];
	//    Random random=new Random(); 
		int n=a.length;
		for(int i=0; i<n; i++) {  //int i=n-1; i>=0 i--역순으로 설정할때
	//		a[i]=random.nextInt(); 
			a[i]=i;
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		shell_sort(a);
		for(int i=0; i<n; i++) {
			System.out.print(a[i]+" ");
		}
		long end = System.currentTimeMillis();
		System.out.print("\n");
		System.out.println("실행시간 : " + (end - start)/1000.0);
	}
}
```

### 장점

 삽입 정렬에 비해 정렬해야 하는 횟수는 늘지만 전체적으로 값의 이동 횟수가 줄어들어 효율적입니다. 또한 연속적이지 않은 리스트들의 자료 교환이 일어나면 더 큰 거리를 이동하기 때문에 교환되는 요소들이 삽입 정렬보다 최종 위치에 있을 가능성이 높아집니다. 

### 시간 복잡도 

* 최선 : O(n) => 삽입 정렬과 동일합니다.

* 평균 : O(n^1.5)

* 최악 : 간격을 잘못 설정한다면 O(n^2)