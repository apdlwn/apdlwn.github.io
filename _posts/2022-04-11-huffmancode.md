---
layout: post
title: "Huffman Code"
subtitle: "과제"
date: 2022-04-11 00:19:23 +0900
background: '/PATH_TO_IMAGE'
---
```java
import java.util.*;
import java.io.*;

class Node{
	char character;
	int freq;
	Node left, right;
}
class compareNode implements Comparator<Node>{
	public int compare(Node a, Node b) {
		int x=a.freq;
		int y=b.freq;
		return x-y;
	}
}
public class Huffman {
	//huffman code에 필요
	public static PriorityQueue<Node> queue;
	public static HashMap<Character, String> CharToCode=new HashMap<Character, String>();
	public static Node coding(int n) {
		for(int i=0; i<n-1; i++) {
			Node a=new Node();
			a.left=queue.poll();
			a.right=queue.poll();
			a.freq=a.left.freq+a.right.freq;
			queue.add(a);
		}
		return queue.poll();
	}
	public static void main(String[] args) {
		//텍스트파일 저장에 필요
		Scanner scanner = new Scanner(System.in);
		FileWriter fout = null;
		int c;
		try {
		fout = new FileWriter("c:\\Temp\\test2.txt");
		while(true) {
		String line = scanner.nextLine();
		if(line.length() == 0)
		break;
		fout.write(line, 0, line.length());
		fout.write("\r\n", 0, 2);
		}
		fout.close();
		} catch (IOException e) {
		System.out.println("입출력 오류");
		}
		scanner.close();
		//파일 내 문자 추출
		String text="";
		try {
			File file = new File("c:\\Temp\\test2.txt");
			FileReader file_reader=new FileReader(file);
			int cur=0;
			while((cur=file_reader.read())!=-1) {
				text=text+(char)cur;
				System.out.print((char)cur);
			}
			System.out.println(text);
			file_reader.close();
		}catch(FileNotFoundException e){
			e.getStackTrace();
		}catch(IOException e) {
			e.getStackTrace();
		}
		System.out.println();
		//huffman code에 필요
		HashMap<Character, Integer> checkFreq=new HashMap<Character, Integer>();
		queue=new PriorityQueue<Node>(new compareNode());
		int count=0;
		for(int i=0; i<text.length(); i++) {
			char temp=text.charAt(i);
			if(checkFreq.containsKey(temp)) {
				checkFreq.put(temp, checkFreq.get(temp)+1);
			}
			else {
				checkFreq.put(temp, 1);
			}
		}
		for(Character a : checkFreq.keySet()) {
			Node n=new Node();
			n.character=a;
			n.freq=checkFreq.get(a);
			queue.add(n);
			count++;
		}
		Node huffmancoding=coding(count);
		
		makeHuffmanCode(huffmancoding, new String());
		
		String result=new String();
		
		for(int i=0; i<text.length(); i++) {
			result=result+CharToCode.get(text.charAt(i));
		}
		System.out.println(result);
	}
	public static void makeHuffmanCode(Node n, String s) {
		if(n==null)
			return;
		makeHuffmanCode(n.left, s+"0");
		makeHuffmanCode(n.right, s+"1");
		if(n.character != '\0') {
			System.out.println("'"+n.character+"'"+"="+s);
			CharToCode.put(n.character, s);
		}
		
	}
}

```