---
layout: post
title: "ShellSort"
subtitle: "과제"
date: 2022-05-02 01:50:10 +0900
background: '/PATH_TO_IMAGE'
---
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