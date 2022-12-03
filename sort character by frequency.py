class Solution:
    def frequencySort(self, s: str) -> str:
        arr = sorted([(val, key) for key, val in Counter(s).items()], reverse=True)
        return "".join([arr[i][1]*arr[i][0] for i in range(len(arr))])
