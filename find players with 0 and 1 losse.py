class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        play = {}
        for winner, loser in matches:
            if winner not in play: play[winner] = 0
            play[loser] = play.get(loser, 0) + 1

        answer = [[], []]
        for player, l in play.items():
            if play[player] == 0:
                answer[0].append(player)
            elif play[player] == 1:
                answer[1].append(player)
        
        answer[0].sort()
        answer[1].sort()
        return answer
