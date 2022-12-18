class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n=a.size();
        vector<int>op(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() and a[i]>=a[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }else{
                    op[i]=st.top()-i;
                    st.push(i);
                }
            }
        }
        return op;
    }
};
