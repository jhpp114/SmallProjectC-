#include <iostream>

using namespace std;

/*
print the number as hexi decimal number
base is fixed to 16

*/

void printHexidecimal(int number){
    static string hexi = "0123456789abcdef"; //base 16
    int base = 16;
    if(number >= base){
        printHexidecimal(number/base);
    }
    cout << hexi[number%base] << " ";
} 


int main(){
    int number = 1234;
    printHexidecimal(number);
    cout << endl;
    cout << number/16 << endl;
    return 0;
}