#include <iostream>

namespace std;


class Solution {
public:
    int helper(int end, int d, bool* used){
        
        if (end == d){
            return 1;
        }
        
        int first = 0;
        
        int sum = 0;
        
        if (d == 0){
            first = 1;
        }else{
            first = 0;
        }
        
        for (int i = first; i < 10; i++){
            
            if (!used[i]){
                
                used[i] = true;
                
                sum = sum + helper(end, d+1, used);
                
                used[i] = false;
            }
        }
        
        return sum;
        
    }
    
    
    int countNumbersWithUniqueDigits(int n) {
        
        bool used[10] = {false};
        
        int total = 1;
        
        for (int i = 1; i<= min(n,10); i++){
            
            total = total + helper(i,0,used);
        }
        
        return total;
        
    }
};

int main(){

    Solution a;

    cout << a.countNumbersWithUniqueDigits(2) << endl;
    cout << a.countNumbersWithUniqueDigits(3) << endl;
    cout << a.countNumbersWithUniqueDigits(4) << endl;
    cout << a.countNumbersWithUniqueDigits(5) << endl;
    cout << a.countNumbersWithUniqueDigits(6) << endl;
    cout << a.countNumbersWithUniqueDigits(7) << endl;
    
    return 0;

}
