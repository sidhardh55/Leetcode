class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        if(n<1000){
            return 0;
        }else if( n>=1000 && n<1000000 ){
            ans = n-1000+1;
        }else if(n>=1e6 && n<1e9){
            ans = 2*(n-1e6+1)+(1e6-1000);
        }else if(n>=1e9 && n<1e12){
            ans =3*(n-1e9+1)+2*(1e9-1e6)+(1e6-1000);
        }else if(n>=1e12 && n<1e15){
            ans = 4*(n-1e12+1)+3*(1e12-1e9)+2*(1e9-1e6)+(1e6-1000);
        }else{
            ans = 4*(n-1e12)+3*(1e12-1e9)+2*(1e9-1e6)+(1e6-1000)+5;
        }
        return ans;
    }
};