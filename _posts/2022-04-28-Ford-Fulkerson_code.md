---
layout: post
title: "README2"
subtitle: "과제"
date: 2022-04-28 22:13:10 +0900
background: '/PATH_TO_IMAGE'
---

```java
import java.io.*;
import java.util.*;

public class FordFulkerson {
	public static int INF = 987654321;
	static int N=52;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        int E = sc.nextInt();
        int src = atoi(sc.next().charAt(0));
        int sink = atoi(sc.next().charAt(0));

        int[][] flow = new int[N][N];
        int[][] capacity = new int[N][N];
        boolean[][] adj = new boolean[N][N];
      
        for(int e = 0; e < E; ++e) {
        	 int a = atoi(sc.next().charAt(0));
             int b = atoi(sc.next().charAt(0));
             int c = sc.nextInt();
             capacity[a][b] = c;
            adj[a][b] = adj[b][a] = true;
        }

        Queue<Integer> q = new LinkedList<Integer>();
        int ans = 0;
        while(true) {
            int[] prev = new int[N];

            q.clear();
            q.add(src);
            prev[src] = src;

            while(!q.isEmpty()) {
                int cur = q.poll();

                for(int there = 0; there < N; ++there) {
                    if(!adj[cur][there]) 
                    	continue;
                    if(prev[there] != 0) 
                    	continue;

                    if(capacity[cur][there] - flow[cur][there] > 0) {
                        q.add(there);
                        prev[there] = cur;
                        if(there == sink) 
                        	break;
                    }
                }
            }

            if(prev[sink] == 0) 
            	break;


            int minFlow = INF;
            for(int v = sink; prev[v] != v; v = prev[v]) {
                minFlow = Math.min(minFlow, capacity[prev[v]][v] - flow[prev[v]][v]);
            }
            for(int v = sink; prev[v] != v; v = prev[v]) {
                flow[prev[v]][v] += minFlow;
                flow[v][prev[v]] -= minFlow;
            }

            ans += minFlow;
        }

        System.out.println(ans);
    }
    static int atoi(char c) {
		if('A' <= c && c <= 'Z') {
			return c-'A';
		}else if('a' <= c && c <= 'z'){
			return c-'A'-6;
		}
		return -1;
	}
}
```