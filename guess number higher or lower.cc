 /** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 

class Solution {
public:
int guessNumber(int n) {
    int left = 1, right = n, cur = left+(right-left)/2;

    while(true){
        switch(guess(cur)){
            case -1:
                right = cur-1;
                cur = left+(right-left)/2;
                break;
            case 1:
                left = cur+1;
                cur = left+(right-left)/2;
                break;
            case 0:
                return cur;
        }
    }
    return 0;
}
};
