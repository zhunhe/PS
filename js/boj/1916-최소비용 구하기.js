/*
[boj] 최소비용 구하기
https://www.acmicpc.net/problem/1916
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/1916.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
let idx = 0;
const n = parseInt(input[idx++]);
const m = parseInt(input[idx++]);
const edges = [];
for (idx = 2; idx < 2 + m; idx++) {
	edges[idx - 2] = input[idx].split(" ").map(Number);
}
const [start, end] = input[idx].split(" ").map(Number);

class minHeap {
	constructor() {
		this.heap = [];
		this.heap.push(Number.MIN_SAFE_INTEGER);
	}
	insert([a, b]) {
		this.heap.push([a, b]);
		this.upheap(this.heap.length - 1);
	}
	upheap(pos) {
		let tmp = this.heap[pos];
		while (tmp[1] < this.heap[parseInt(pos / 2)][1]) {
			this.heap[pos] = this.heap[parseInt(pos / 2)];
			pos = parseInt(pos / 2);
		}
		this.heap[pos] = tmp;
	}
	get() {
		if (this.heap.length < 2) return false;
		if (this.heap.length === 2) return this.heap.pop();
		let res = this.heap[1];
		this.heap[1] = this.heap.pop();
		this.downheap(1, this.heap.length - 1);

		return res;
	}
	downheap(pos, len) {
		let tmp = this.heap[pos];
		while (pos <= parseInt(len / 2)) {
			let child = pos * 2;
			if (child < len && this.heap[child][1] > this.heap[child + 1][1]) {
				child++;
			}
			if (tmp[1] <= this.heap[child][1]) {
				break;
			}
			this.heap[pos] = this.heap[child];
			pos = child;
		}
		this.heap[pos] = tmp;
	}
	size() {
		return this.heap.length - 1;
	}
}

// dist에 들어있는 값보다 min heap에서 뺀 값보다 작은 경우 continue
function solution(start, n, edges, end) {
	let minH = new minHeap();
	let graph = [...Array(n + 1)].map((e) => Array([]));
	let dist = Array(n + 1).fill(Infinity);
	for (const [a, b, c] of edges) graph[a].push([b, c]);

	dist[start] = 0;
	minH.insert([start, 0]);
	while (minH.size() > 0) {
		let tmp = minH.get();
		let now = tmp[0];
		let nowCost = tmp[1];
		if (nowCost > dist[now]) continue;
		for (let [next, cost] of graph[now]) {
			if (nowCost + cost < dist[next]) {
				dist[next] = nowCost + cost;
				minH.insert([next, dist[next]]);
			}
		}
	}
	return dist[end];
}

console.log(solution(start, n, edges, end));
