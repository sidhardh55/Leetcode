class Solution {
public:
    int smallestNumber(int n, int t) {
        int rem = 0;
        int p=n;
        int use = n;
        while(true){
            int prod = 1;
            use = p;
            while(use>0){
                rem = use%10;
                use = use/10;
                prod*=rem;
            }
            use = p;
            if(prod%t==0) break;
            p++;
        }
        return use;
    }
};