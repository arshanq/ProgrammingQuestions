int f(int num)
{
    int a = 111;
    int length=3;
    
    while(1)
    {
        if(a%num == 0 ) return length;
        a = a*10 + 1;
        if(a>=num) a%=num;
        length++;
        
    }
}

string smallestMultiple(int a) {
    int len = f(a);
    string str = "";
    for(int i = 0; i< len;i++) {
        str += "1";
    }
    return str;
}


