// Problem: Circle and Rectangle Overlapping
// Difficulty: Medium
// Approach: check the distance btwn the center and closest point on the square
// Time: O(1)
// Space: O(1)

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int xclose = max(x1,min(xCenter,x2));
        int yclose = max(y1,min(yCenter,y2));

        int xc = xCenter-xclose;
        int yc = yCenter-yclose;
        
        return xc*xc + yc*yc <= radius*radius;
    }
};