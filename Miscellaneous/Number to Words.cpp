//Code written by Shubham Agarwal

/*  INPUT
7
170
1234
219
1001
3014
2
142

  OUTPUT

one hundred and seventy
one thousand two hundred and thirty four
two hundred and nineteen
one thousand and one
three thousand and forteen
two
one hundred and forty two
*/

#include<bits/stdc++.h>
using namespace std;
void convert(int n){
    string ones[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string tens[9]={"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string cat[]={"eleven","twelve","thirteen","forteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    if(n<10){
        cout<<ones[n];
    }
    else if(n>10 and n<20){
        n=n%10;
        cout<<cat[n-1];
    }
    else if(n<100 and n%10==0){
        n = n/10;
        cout<<tens[n-1];
    }
    else if(n>10 and n<99){
        int x = n/10;
        int y = n%10;
        cout<<tens[x-1]<<" "<<ones[y];
    }
    else if(n%100==0 and n<1000){
        n=n/100;
        cout<< ones[n] <<" hundred";
    }
    else if(n>100 and n<1000){
            int hundplace = n/100;
            int x = n%100;
            int tensplace = x/10;
            int onesplace = x%10;
            if(x>10 and x<20)
                cout<< ones[hundplace] << " hundred and " << cat[onesplace-1];
            else if(tensplace==0)
                cout<< ones[hundplace] << " hundred and " << ones[onesplace];
            else if(onesplace==0)
                cout<<ones[hundplace]<< " hundred and "<<tens[tensplace-1];
            else
                cout<< ones[hundplace] << " hundred and " << tens[tensplace-1] <<" "<<ones[onesplace];
    }
    else if(n%1000==0 and n<10000){
        n=n/1000;
        cout<< ones[n] <<" thousand";
    }
    else if(n>1000 and n<10000){
        int tsndplace = n/1000; n=n%1000;
        int hundplace = n/100;
        int x = n%100;
        int tensplace = x/10;
        int onesplace = x%10; 
        if(hundplace==0 and tensplace==0)
            cout<< ones[tsndplace]<<" thousand and "<<ones[onesplace];            
        else if(hundplace==0)
            cout<<ones[tsndplace]<<" thousand and "<<cat[onesplace-1];
        else if(x%10==0)
            cout<<ones[tsndplace] << " thousand "<<ones[hundplace] << " hundred and "<<tens[tensplace-1];
        else if(x>10 and x<20)
            cout<<ones[tsndplace] << " thousand "<<ones[hundplace] << " hundred and "<<cat[onesplace-1];
        else
            cout<<ones[tsndplace] << " thousand "<<ones[hundplace] << " hundred and "<<tens[tensplace-1]<<" "<<ones[onesplace];
    }
    
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        convert(n);
        cout<<endl;
    }
	return 0;
}
