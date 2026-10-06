class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_vol=0;
        int left=0;
        int right=heights.size()-1;
        while(left<right){
            int width=right-left;
            int height=min(heights[left],heights[right]);
            int vol=width*height;
            max_vol=max(max_vol,vol);
            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return max_vol;
        
    }
};
