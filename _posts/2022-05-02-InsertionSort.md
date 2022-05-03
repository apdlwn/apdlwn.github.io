---
layout: post
title: "InsertionSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---
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