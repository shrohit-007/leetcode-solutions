class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if(ay1>=by2 or by1>=ay2 or bx1>=ax2 or ax1>=bx2)
        {
            return (ay2-ay1)*(ax2-ax1)+(bx2-bx1)*(by2-by1);
        }
        int area=(ay2-ay1)*(ax2-ax1)+(bx2-bx1)*(by2-by1);
        int x=min(by2,ay2)-max(ay1,by1);
        int y=min(ax2,bx2)-max(ax1,bx1);
        area-=x*y;
        return area;
        
    }
};
