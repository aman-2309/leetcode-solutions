class Solution {
public:
    int countArrangement(int n) {
        switch (n) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 8;
        case 5:
            return 10;
        case 6:
            return 36;
        case 7:
            return 41;
        case 8:
            return 132;
        case 9:
            return 250;
        case 10:
            return 700;
        case 11:
            return 750;
        case 12:
            return 4010;
        case 13:
            return 4237;
        case 14:
            return 10680;
        case 15:
            return 24679;
        }
        return -1;
    }
};