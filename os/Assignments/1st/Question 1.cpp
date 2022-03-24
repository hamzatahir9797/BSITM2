#include <iostream>
#include <string>
using namespace std;
bool hasNumberSign(string num) {
    for(int i=0; i<num.length(); i++) {
        if (num[i] == '#')
            return true;
    }
    return false;
}

void printAnswer(string num1, string num2, string signNumber, int pos = 4)
 {
    int a = stoi(num1);
    int b = stoi(num2);
        
    if (pos == 4) {
        cout<< num1 <<" + " << num2 <<" = "<< signNumber<<"\n";
    }
    else if (pos == 3) {
         cout<< num1 <<" + " << num2 <<" = "<< a+b <<"\n";
    }
    else {
        bool valid = true;
        string result = to_string(b - a);
        
        int resultLength = result.length();
        int signNumberLength = signNumber.length();
        int differenceInLength = resultLength - signNumberLength + 1;
        if (differenceInLength == 0) {
            valid = false;
        }
        
        for(int i=0, j=0; i<result.length() && valid; i++) {
            if (signNumber[j] == '#' && differenceInLength > 0) {
                differenceInLength--;
                if (differenceInLength == 0) {
                    j++;
                }
            }
            else if (result[i] != signNumber[j]) {
             valid = false;
            }
            else {
                j++;    
            }
        }
        
        if (valid) {
            if (pos == 1) {
                cout<< result <<" + " << num1 <<" = "<< num2<<"\n";
            }
            else {
                cout<< num1 <<" + " << result <<" = "<< num2<<"\n";
            }
        }
        else {
            cout << "-1" << "\n";
        }
        
    }
}

int main()
{
    string a,b,c;
    cout<<"Enter A: ";
    cin>>a;
    
    cout<<"Enter B: ";
    cin>>b;
    
    cout<<"Enter C: ";
    cin>>c;
    
    if(hasNumberSign(a)) {
        printAnswer(b, c, a, 1);
    }
    else if(hasNumberSign(b)) {
        printAnswer(a, c, b, 2);
    }
    else if (hasNumberSign(c)) {
        printAnswer(a, b, c, 3);
    }
    else {
        printAnswer(a,b,c);
    }
    
    return 0;
}






