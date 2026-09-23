class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int bots = numBottles;
        while(bots>=numExchange){
            ans+=(bots/numExchange);
            bots = bots%numExchange+(bots/numExchange);
        }
        return ans;
    }
};