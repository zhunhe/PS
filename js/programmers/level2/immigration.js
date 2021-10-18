function solution(n, times) {
    let answer;
    // 최소 시간 1분
    let left = 1;
    // 최대 시간 === 가장 오래걸리는 사람이 모두 처리한 시간
    let right = Math.max(...times) * n;
    // 최소시간이 최대시간보다 같거나 작을 때까지 반복
    while (left <= right) {
        // 이분탐색을 위한 중간값 구해주고
        let mid = parseInt((left + right) / 2);
        // mid 시간 기준으로 입국가능한 사람 숫자 구하기
        let people = 0;
        for (let x of times) {
            people += parseInt(mid / x);
        }
        // 입국한 사람 숫자가 n보다 크거나 같은 경우 값 세팅
        if (n <= people) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}
