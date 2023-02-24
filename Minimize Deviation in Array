class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        heap = [-n if not n%2 else -2*n for n in set(nums)]
        heapify(heap)
        minVal = -max(heap)
        ans = inf
        while not heap[0]%2:
            maxVal = -heappop(heap)
            heappush(heap, -maxVal//2)
            ans = min(ans, maxVal-minVal)
            minVal = min(minVal, maxVal//2)
        return min(-heap[0]-minVal, ans)
