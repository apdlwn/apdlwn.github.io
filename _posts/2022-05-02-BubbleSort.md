---
layout: post
title: "BubbleSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---
```java
import java.util.*;

public class Bubble_Sort {
	public static void bubble_sort(int[] a) {
		bubble_sort(a, a.length);
	}
	private static void bubble_sort(int a[], int size) {
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
		int[] a=new int[1048576];
		Random random=new Random(); 
		int n=a.length;
		for(int i=0; i<n; i++) {  //int i=n-1; i>=0 역순으로 설정할때
			a[i]=random.nextInt(); 
			//a[i]=i;
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		bubble_sort(a);
		for(int i=0; i<n; i++) {
			System.out.print(a[i]+" ");
		}
		long end = System.currentTimeMillis();
		System.out.print("\n");
		System.out.println("실행시간 : " + (end - start)/1000.0);
	}
}
```