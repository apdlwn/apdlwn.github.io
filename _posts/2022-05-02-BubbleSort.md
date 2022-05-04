---
layout: post
title: "BubbleSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---


## Bubble Sort (버블 정렬)

버블 정렬이란, 

인접한 두 원소를 비교하여 정렬하는 알고리즘을 말합니다. 

### 정렬 방법

[1] 첫번째부터 현재 값과 다음 값의 크기를 비교합니다.

[2] 현재의 값보다 다음 값이 더 크면 값을 교환합니다.

[3] 다음 값으로 이동하여 그 값과 그 다음 값을 비교합니다.

[4] 1-3번을 n-1번 반복합니다. (n=배열에 있는 값의 갯수)
  
 **1-3번을 1번 수행하면 가장 큰 수가 맨 뒤로 가게 되므로, 2번째에서는 맨 뒤 값은 제외하고 1-3번을 수행합니다.**

 ### Bubble Sort 소스 코드

```java
import java.util.*;

public class Bubble_Sort {
	public static void bubble_sort(int a[], int size) {
		for(int i=1; i<size; i++) {
			for(int j=0; j<size-i; j++) {
				if(a[j]>a[j+1]) {
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int[] a=new int[32];
	//	Random random=new Random(); 
		int n=a.length;
		for(int i=0; i<n; i++) {  //int i=n-1; i>=0 역순으로 설정할때
	//		a[i]=random.nextInt(); 
			a[i]=i;
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		bubble_sort(a, a.length);
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

 * 비교 횟수 = n(n-1)/2 로 일정합니다.

 * 교환 횟수 = 입력이 역순으로 정렬되어 있다면 한 번 교환하기 위해 3번의 이동이(swap 함수) 필요하므로 (비교 횟수 * 3)  =>  최악의 경우

   최상의 경우(입력이 정렬되어 있다면) 교환이 발생하지 않습니다. 

  그러므로
**시간 복잡도 = O(n^2)**