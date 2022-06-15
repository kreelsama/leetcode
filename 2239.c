int findClosestNumber(int* nums, int numsSize){
    int len_dist = 1e5, minimum=-1e5;
    for(int i = 0; i < numsSize; ++i){
        int n = nums[i];
        if ( n > 0 && n <= len_dist){
            len_dist = minimum = n;
        }
        if ( n < 0 && -n < len_dist){
            minimum = n;
            len_dist = -n;
        }
        if ( n == 0 )
            return 0;
    }
    return minimum;
}