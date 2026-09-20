class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearx,neary;
        if((x1 <= xCenter) && (xCenter <= x2)){
            nearx = xCenter;
        }else if(xCenter > x2){
            nearx = x2;
        }else{
            nearx = x1;
        }

        if((y1 <= yCenter) && (yCenter <= y2)){
            neary = yCenter;
        }else if(yCenter > y2){
            neary = y2;
        }else{
            neary = y1;
        }

        int dist = sqrt(pow(nearx-xCenter,2)+pow(neary-yCenter,2));

        if(dist <= radius){
            return true;
        }
        return false;
    }
};