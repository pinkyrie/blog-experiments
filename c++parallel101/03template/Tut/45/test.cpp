#include<iostream>
struct Data
{
    double data[200];
};
struct Junk
{
    int junk[100];
};
int main(){
    Data d = {2.5e33, 3.5e-19, 20.2e32};
    char * pch = (char *) (&d); // type cast #1 – convert to string
    char ch = char (&d); // type cast #2 - convert address to a char
    Junk * pj = (Junk *) (&d); // type cast #3 - convert to Junk pointer
}
