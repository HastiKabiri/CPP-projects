#include <iostream>

using namespace std;

int main() {

    cout << " hello hasti "; // print 
    int age= 20;
    double height= 1.60;
    char grade= 'A';
    const double PI= 3.14; // constant variable
    // const variable means, uIcan not change the value of that variable, it is constant.


    cout << " age:  " << age << endl; 
    cout << " height:  " << height << endl;
    cout << " grade:  " << grade << endl;  
    cout << " PI: " << PI << endl;
    
    // obvi a comment

    /* multi- line 
    comment */

cout << "---------------Next Exercise -----------------------" << endl;

    // USER INPUT


    string Name;
    string Fname;

    cout << "Enter your precious name here :" ;
    cin >> Name; // take input from user and store it in variable name

    cout<< "Enter your big ass family name here baby:";
    cin >> Fname;

    cout << "Your full pretty name is: " << Name << " " << Fname << endl;


cout << "---------------Next Exercise -----------------------" << endl;

    int a= 10;
    int b = 6;

    double result = (double) a/b; 
    /* the (double) is a type cast, it converts the integer values to double before division.
    we know that int a and b were int , so we say, this one time u consider them as double.
    */
    cout<< result <<endl;

cout << "---------------Next Exercise -----------------------" << endl;

// MATH 


int n = 5;
n++;       // n = 6  (increment by 1)
n--;       // n = 5  (decrement by 1)
n += 3;    // n = 8  (same as n = n + 3)
n -= 2;    // n = 6  (same as n = n - 2)
n *= 2;    // n = 12 (same as n = n * 2)
n /= 4;    // n = 3  (same as n = n / 4)


cout << "---------------Next Exercise -----------------------" << endl;

// IF AND ELSE


int score;
cout<< "Enter your score:  ";
cin >> score;

if (score> 90){
    cout<< "Good job kiddo! u have got A+" << endl;
} else if (score> 80) {
    cout<<"nice work kid, u got A" << endl;
} else{
    cout<< "U need to work a bit harder kid, you have got this" << endl;
}


cout << "---------------Next Exercise -----------------------" << endl;

// SWITCH STATEMENT


int number;
cout<< "please enter a number from 1 to 4:  ";
cin >> number;

switch(number)  {
case 1:   cout << "first day" ; break;
case 2: cout << "second day"; break;
case 3: cout << "third day"; break;
case 4: cout << "fourth day"; break;
default: cout << "only enter a number from 1 to 4"; break;

// default case is included it to handle unexpected input.
}




cout << "---------------Next Exercise -----------------------" << endl;

// FOR LOOP

// for (init; condition; update)
// like  for(min, max, step)

for(int i= 1; i <11 ; i++) {
cout << "i = " << i << endl;
}


// Count down
for (int i = 5; i > 0; i--) {
    cout << i << " ";
}
cout << "NICE JOB!" << endl;



cout << "---------------Next Exercise -----------------------" << endl;

// WHILE LOOP

int count = 1;

while (count <= 5) {
    cout << "Count: " << count << endl;
    count++;    // Don't forget to update! (avoids infinite loop)
}


cout << "---------------Next Exercise -----------------------" << endl;

// DO-WHILE LOOP


int z;

do {
    cout << "Enter a number (1-10): ";
    cin  >> z;
} while (z < 1 || z > 10);    // Repeat if invalid input

// if u put number more than 10 or less than 1, it will ask u to enter again, until u enter a valid number between 1 and 10.

cout << "Valid input: " << z << endl;




cout << "---------------Next Exercise -----------------------" << endl;

// BREAK AND CONTINUE


for (int i = 0; i < 10; i++) {
    if (i == 3) continue;   // Skip 3
    if (i == 7) break;      // Stop at 7
    cout << i << " ";
}
// Output: 0 1 2 4 5 6




cout << "---------------Next Exercise -----------------------" << endl;

// FUNCTIONS

// void means the function does not return any value. It just performs an action.


/* void greet(string name) {
    cout << "Hello, " << name << "!" << endl;
}
*/

/* 
// Function with return value
int square(int l) {
    return l * l;
}


// we have return here so we cannot run the code here. for running it we need to
move it after the main function that has started from the beginning of the code

*/

// Function with default parameter
double power(double base, int exp = 2) {
    double result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}












return 0;
}