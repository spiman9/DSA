// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.



// DO IT AGAIN - THIS IS STL approch do it by recursion approch

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        char ch = '1';
        for(int i =0 ;i < n;i++){
            s += ch;
            ch++;
        }
        reverse(s.begin() , s.end());

        int times = 1;
        do{
            next_permutation(s.begin() , s.end());
            times++;
        }while(times <= k);

        return s;
    }
};


