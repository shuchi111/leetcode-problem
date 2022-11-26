class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        A = list(zip(startTime, endTime, profit))
        A.sort()
        max_profit = max_total_profit = 0
        chains = [] # // min heap having {endTime, profit}
        for start, end, profit in A:
            while chains and start >= chains[0][0]:
                max_profit = max(max_profit, chains[0][-1])
                heapq.heappop(chains)
            heapq.heappush(chains, (end, profit + max_profit))
        max_profit = 0
        for job in chains:
            max_profit = max(job[-1], max_profit)
        return max_profit
