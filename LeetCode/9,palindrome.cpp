class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        string aux = to_string(x);
        string reversed;
        for(int i = aux.length()-1;i>=0;i--){
            reversed += aux[i];
        }
        if(reversed == aux){
            return true;
        }else{
            return false;
        }

    }
};