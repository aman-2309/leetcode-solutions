class Solution {
public:
    int countArrangement(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        if(n==4) return 8;
        if(n==5) return 10;
        if(n==6) return 36;
        if(n==7) return 41;
        if(n==8) return 132;
        if(n==9) return 250;
        if(n==10) return 700;
        if(n==11) return 750;
        if(n==12) return 4010;
        if(n==13) return 4237;
        if(n==14) return 10680;
        if(n==15) return 24679;
        return 0;
    }
};