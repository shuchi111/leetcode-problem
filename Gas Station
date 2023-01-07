class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),idx=0;
        
        for(int i=0;i<n;i++){
            cost[i]=gas[i]-cost[i];
            gas[i]=cost[i]+(i>0?gas[i-1]:0);
            
            if(gas[i]<gas[idx]){
                idx=i;
            }
        }
        
        int ans=-1;
        for(int i=0;i<n;i=(i+1)){
            if(cost[(i+idx)%n]>=0){
                ans=(i+idx)%n;
                break;
            }
        }
        
        if(ans==-1){
            return ans;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum<0){
                return -1;
            }
            else{
                sum+=cost[(i+ans)%n];
            }
        }
        if(sum<0){
                return -1;
        }
        return ans;
}
};
