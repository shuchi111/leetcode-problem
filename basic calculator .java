class Solution {
    public int calculate(String s) {
        //evaluate expression recursively
        return calculate(s.toCharArray(), 0)[0];
    }
    
    //evaluate an expression from the string, starting at idx
    //0th index is result from expression.
    //1st index is index after evaluting the expression.
    int[] calculate(char[] s, int idx) {
        int ret = 0;
        int sign = 1;
        //evaluate expression until end is found
        while(idx < s.length && s[idx] != ')') {
            //check to see if sign needs to be reversed.
            for(; idx < s.length && s[idx] == ' '; idx++);
            if(idx == s.length)
                break;
            if(s[idx] == '-') {
                sign *= -1;
                idx++;
            }
            
            for(; idx < s.length && s[idx] == ' '; idx++);
            if(s[idx] == '(') {
                //make recursive call to evaluate inner expression.
                //add to result and advance index.
                int[] tmp = calculate(s, idx+1);
                ret += sign*tmp[0];
                idx = tmp[1];
                //assign starting sign for next op.
                for(; idx < s.length && s[idx] == ' '; idx++);
                if(idx < s.length && s[idx] != ')')
                    sign = s[idx++]=='+'?1:-1;
            //read next number, and add it to the total.
            }else {
                //read next number and add it to the result.
                int curr = 0;
                while(idx < s.length && s[idx] >= '0' && s[idx] <= '9')
                    curr = curr*10 + s[idx++]-'0';
                ret += sign*curr;
                //assign starting sign for next op.
                for(; idx < s.length && s[idx] == ' '; idx++);
                if(idx < s.length && s[idx] != ')')
                    sign = s[idx++]=='+'?1:-1;
            }
        }
        return new int[] {ret, idx+1};
    }
}
