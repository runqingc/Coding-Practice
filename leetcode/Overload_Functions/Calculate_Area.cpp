#include <iostream>
#include <cmath>
using namespace std;

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----

int find_area(int a);
double find_area(double a, double b);

int find_area(int a){
    return a*a;
}

double find_area(double a, double b){
    return a*b;
}






//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void area_calc() {
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    
    int square_area = find_area(2);
    double rectangle_area = find_area(4.5, 2.3);
    
    
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The area of the square is " << square_area << "\n" << "The area of the rectangle is " << rectangle_area;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----


int main(){
    area_calc();
    return 0;
}







