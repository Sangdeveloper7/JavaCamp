class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> alpha;
        int flag_ten = 0;
        for(int i=size-1; i>=0; i--){
            int temp = 0;
            temp = digits[i];
            if(i == size-1 || flag_ten == 1){
               temp = temp + 1;
               flag_ten = 0;
            }
            if(temp >= 10){
                temp = temp % 10;
                flag_ten = 1;
            }
            alpha.insert(alpha.begin(), temp);
        }

        if(flag_ten == 1){
            alpha.insert(alpha.begin(), 1);

        }
        return alpha;
    }
};