class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1;
        int left_max = height[0] , right_max = height[right];
        int water = 0;
        while(left < right){
            if(left_max < right_max){ //that means we will take water from left because smaller wall will be maximum it can store
                left++;
                left_max = max(left_max , height[left]); // which is the tall wall
                water += left_max - height[left]; // tall wall - curr wall = water
                //notes - if the both the walls are of same height = 0 water
            }else{
                right--;
                right_max = max(right_max , height[right]); // gives which is tall right one or curr one
                water += right_max - height[right]; // tall wall - curr wall
            }
        }
        return water;
    }
};