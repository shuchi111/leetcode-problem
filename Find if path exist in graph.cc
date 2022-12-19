class Solution {
public:
    bool findIfPathExistsInGraphDfs(const std::vector<std::vector<int>>& adjacencyList,
std::vector<bool>& isVisited,
    const int& source, const int& destination)
    {
        if (isVisited[source] == true)
        {
            return false;
        }

        isVisited[source] = true;
        bool returnVal = false;

        for (int i = 0; i < adjacencyList[source].size(); i++)
        {;
            if (adjacencyList[source][i] == destination)
            {
                returnVal = true;
                break;
            }
            else if (findIfPathExistsInGraphDfs(adjacencyList, isVisited, adjacencyList[source][i], destination))
            {
                returnVal = true;
                break;
            }
        }

        return returnVal;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(edges.size() == 0)
        {
            return true;
        }

        std::vector<std::vector<int>> adjacencyList(n);
        std::vector<bool> isVisited(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adjacencyList[edges[i][0]].emplace_back(edges[i][1]);
            adjacencyList[edges[i][1]].emplace_back(edges[i][0]);
        }

        for (int i = 0; i < adjacencyList.size(); i++)
        {
            if (findIfPathExistsInGraphDfs(adjacencyList, isVisited, source, destination))
            {
                return true;
            }
        }

        return false;
    }
};
