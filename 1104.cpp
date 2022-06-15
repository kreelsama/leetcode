class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int layer = 0, n;
        for(n = 1; n <= label; n *= 2)
            layer += 1;
        n /= 2;
        cout << n;
        vector<int> res(layer);
        int num = label, parent;

        for(; layer > 0; layer --){
            res[layer - 1] = num;
            num = n - (num / 2) + n / 2 - 1;
            n /= 2; 
        }
        return res;
    }
};