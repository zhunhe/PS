/*
 * µÎ ¿ë¾×
 * https://www.acmicpc.net/problem/2470
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
	int n;	std::cin >> n;
	std::vector<int> sol(n);
	for (auto &elem : sol) std::cin >> elem;
	sort(sol.begin(), sol.end());
	int ans = INT_MAX, left = 0, right = n - 1;
	int small = sol[left], big = sol[right];
	while (left < right) {
		int sum = sol[left] + sol[right];
		if (abs(sum) < abs(ans)) {
			small = sol[left], big = sol[right];
			ans = sum;
		}
		if (sum > 0) right--;
		else left++;
	}
	std::cout << small << ' ' << big;
}