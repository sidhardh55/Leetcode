class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        // int digs = 0;
        // int temp = n;
        // while(temp>0){
        //     digs++;
        //     temp = temp/10;
        // }
        // int zeroes = digs/3;
        // cout<<zeroes<<" ";
        return n-1000+1;
    }
};