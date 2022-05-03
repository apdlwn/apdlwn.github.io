---
layout: post
title: "QuickSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---

## QuickSort(퀵정렬)

퀵 정렬은 **분할 정복** 알고리즘 중 하나로, 평균적으로 매우 빠른 수행 속도를 가지고 있습니다. 배열을 *비균등*하게 분할하며, 다른 원소와의 비교 만으로 정렬을 수행하므로 다른 메모리 공간을 필요로 하지 않습니다. 

### 정렬 방법

[1] 피벗(pivot)이라는 임의의 값 한 개를 선택합니다. 

[2] 피벗을 기준으로 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로 옮겨지고, 피벗보다 큰 요소들은 모두 피벗의 오른쪽으로 옮겨집니다.
 * 길이를 n이라고 가정한다면, 시작점은 0, 도착점은 n-1로 설정합니다. 

[3] 시작점>도착점이 되면 새로운 시작점과 도착점을 설정합니다.

[4] 피벗을 제외한 왼쪽 부분과 오른쪽 부분을 각각 정렬합니다.

 * 순환 호출을 이용하여 왼쪽, 오른쪽에서 각각 피벗을 정한 후 분할하는 방식으로 정렬합니다. 

[5] 더 이상 분할이 불가능할 때 까지 반복합니다.

### Quick Sort 소스 코드

```java
import java.util.*;
public class Quick_Sort {
	public static void quickSort(int[] arr, int start, int end) {
		int part=partition(arr, start, end);
		if(start<part-1)
			quickSort(arr, start, part-1);
		if(end>part)
			quickSort(arr, part, end);
	}
	public static int partition(int[] arr, int start, int end) {
		int pivot=arr[(start+end)/2];
		while(start<=end) {
			while(arr[start]<pivot)
				start++;
			while(arr[end]>pivot)
				end--;
			if(start<=end) {
				swap(arr, start, end);
				start++;
				end--;
			}
		}
		return start;
	}
	public static void swap(int[] arr, int start, int end) {
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
	}
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int[] a=new int[32];
	//	Random random=new Random(); 랜덤으로 설정할 때
		int n=a.length;
		for(int i=0; i<n; i++) {  //int i=n-1; i>=0 i--역순으로 설정할때
	//		a[i]=random.nextInt(); 랜덤으로 설정할때
			a[i]=i;
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		quickSort(a, 0, n-1);
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

퀵 정렬의 시간 복잡도는 랜덤 배열에서 빠른 정렬 속도를 보입니다. 그리고 피벗을 선정하는 방법에 따라 달라지며, 이미 정렬되어 있는 경우나 역정렬 되어있는 경우에는 불균등 분할에 의해 시간이 더 오래 걸립니다. 

* 최선 : **O(log₂N)**

* 평균 : 나누는 횟수는 n회, 데이터 탐색 횟수는 매번 절반씩 줄기 때문에 logN 이므로 **O(Nlog₂N)**

* 최악 : 정렬/역정렬된 배열에서 피벗을 최솟값이나 최댓값으로 선택한 경우에 n-1개의 데이터 비교를 n번 하게 되므로 **O(n^2)**
