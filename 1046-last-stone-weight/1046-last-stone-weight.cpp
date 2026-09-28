class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int ans;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(true){
            if(pq.empty()){
                ans = 0;
                break;
            }
            if(pq.size()==1){
                ans = pq.top();
                break;
            }
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x<y){
                pq.push(y-x);
            }else if(x>y){
                pq.push(x-y);
            }
        }
        return ans;
    }
};