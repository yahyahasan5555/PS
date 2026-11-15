
class Solution {
public:
	int count_leq(int rows, int cols, int value) {	// O(rows)
		int count = 0;
		for (int r = 1; r <= rows; r++)
			count += min(value / r, cols);
		return count;
	}

	int findKthNumber(int m, int n, int k) {
		int start = 1, end = m * n, kth = -1;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (count_leq(m, n, mid) < k)	// not enough
				start = mid + 1;
			else
				end = mid - 1, kth = mid;
		}
		return kth;
	}
};
