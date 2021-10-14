/*
[boj] N번째 큰 수(2075)
https://www.acmicpc.net/problem/2075
*/

// 배열로 맥스힙 구현
class maxHeap {
    constructor() {
        this.heap = [];
        this.heap.push(Number.MAX_SAFE_INTEGER);
    }
    insert(val) {
        this.heap.push(val);
        this.upheap(this.heap.length - 1);
    }
    upheap(pos) {
        let tmp = this.heap[pos];
        while (tmp > this.heap[parseInt(pos/2)]) {
            this.heap[pos] = this.heap[parseInt(pos/2)];
            pos = parseInt(pos/2);
        }
        this.heap[pos] = tmp;
    }
    get() {
        if (this.heap.length < 2) {
            return false;
        }
        // 계속 get할시 4가 남아있게 됨 어떻게 처리할지?
        let res;
        if (this.heap.length > 2) {
            res = this.heap[1];
            this.heap[1] = this.heap.pop();
            this.downheap(1, this.heap.length - 1);
        } else {
            res = this.heap.pop();
        }
        return res;
    }
    downheap(pos, len) {
        let tmp = this.heap[pos];
        while (pos <= parseInt(len/2)) {
            let child = pos * 2;
            if (child < len && this.heap[child] < this.heap[child + 1]) {
                child++;
            }
            if (tmp >= this.heap[child]) {
                break;
            }
            this.heap[pos] = this.heap[child];
            pos = child;
        }
        this.heap[pos] = tmp
    }
    size() {
        return this.heap.length - 1;
    }
}

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === 'linux' ? '/dev/stdin' : './testcase/2075.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);

// 값 세팅
let list = [];
for (let i = 1; i < n + 1; i++) {
    list[i - 1] = input[i].split(" ");
}

// 맥스힙에 값 세팅
let mH = new maxHeap();
for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
        mH.insert(parseInt(list[i][j]));
    }
}

let answer;
for (let i = 0; i < n; i++) {
    answer = mH.get();
}
console.log(answer);

// 메모리 초과