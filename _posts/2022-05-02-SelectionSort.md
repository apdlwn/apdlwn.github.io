---
layout: post
title: "SelectionSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---

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