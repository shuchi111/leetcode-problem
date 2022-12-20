class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> v(rooms.size());
        v[0] = 1;
        
        queue<int> q;
        q.push(0);

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            if(v[i] == 1)
            {
                for(int j = 0 ;  j < rooms[i].size() ;j++)
                {
                    int k = rooms[i][j];
                    if(v[k] == 1)
                    {
                        continue;
                    }
                    q.push(k);
                    v[k] = 1;
                }
            }
        }

        for(auto it: v)
        {
            if(it == 0)
            {
                return false;
            }
          
        }

        return true;

    }
};
