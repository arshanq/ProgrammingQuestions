int isIntegerPalindrome(int a) {
    int num, digit, rev=0;
    num = a;
    do {
        digit  = num%10;
        rev = (rev*10) + digit;
        num = num/10;
        
    }while(num!=0) ;
    if(a == rev) return 1;
return 0;

}


