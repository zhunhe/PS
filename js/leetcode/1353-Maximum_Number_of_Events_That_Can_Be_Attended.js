/*
[leetcode] 1353. Maximum Number of Events That Can Be Attended
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
*/
class minHeap {
    constructor() {
        this.heap = [];
        this.heap.push(Number.MIN_SAFE_INTEGER);
    }
    insert(val) {
        this.heap.push(val);
        this.upheap(this.heap.length - 1);
    }
    upheap(pos) {
        let tmp = this.heap[pos];
        while (tmp < this.heap[parseInt(pos/2)]) {
            this.heap[pos] = this.heap[parseInt(pos/2)];
            pos = parseInt(pos/2);
        }
        this.heap[pos] = tmp;
    }
    get() {
        if (this.heap.length < 2) {
            return false;
        }
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
            if (child < len && this.heap[child] > this.heap[child + 1]) {
                child++;
            }
            if (tmp <= this.heap[child]) {
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

var maxEvents = function(events) {
    let answer = 0;
    events.sort((a, b) => {
        if (a[0] === b[0])
            return a[1] - b[1];
        else
            return a[0] - b[0];
    });
    const maxDay = [...events].sort((a,b) => b[1] - a[1])[0][1];

    let minH = new minHeap();

    let i = 0;
    for (let day = 1; day <= maxDay; day++) {
        for (; i < events.length; i++) {
            if (events[i][0] > day) {
                break;
            }
            minH.insert(events[i][1]);
        }
        let tmp;
        while(minH.size() && (tmp = minH.get()) < day) {
            ;
        }
        if (tmp >= day)
            answer++;
        if (i === events.length && minH.size() === 0) {
            break;
        }
    }
    return answer;
};

input = [
    [[1,2],[2,3],[3,4]],
    [[1,2],[2,3],[3,4],[1,2]],
    [[1,4],[4,4],[2,2],[3,4],[1,1]],
    [[1,100000]],
    [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]],
    [[1,2],[1,2],[3,3],[1,5],[1,5]]
];
output = [
    3, 4, 4, 1, 7, 5
];

for (let i = 0; i < output.length; i++)
    console.log(output[i], maxEvents(input[i]));