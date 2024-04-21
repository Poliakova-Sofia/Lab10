#include <iostream>
using namespace std;

// structure for the task 1
struct TDate {
    int day; 
    int month;
    int year;
};
void param60();
int DaysInMonth(const TDate& date);

// structure for the task 2
struct Square {
    float a, b, S, P;
};
void begin3();
void perim(Square *s);
void area(Square *s);

// structure for the task 3
struct Point {
    float x, y;
};
struct Rectangle {
    Point topLeft;
    Point bottomRight;
};
void boolean29();
bool isInsideRectangle(Point p, Rectangle r);

int main () { // menu
    cout << " " << endl;
    int task_num;  // diclaration
    do {
        cout << " Task number (0 - exit):  ";
        cin >> task_num;
        if (!cin) {
            cout << " Ups!" << endl; continue;
            // error notification
        }
        switch (task_num) {
            case 1 : param60(); break; // task 1
            case 2 : begin3(); break; // task 2
            case 3 : boolean29(); break; // task 3
            case 0 : cout << " The program is over!" << endl; break;
            default : cout << " Wrong task number!" << endl;
            // output for incorrect numbers
        }
    } while (task_num != 0); // end the program
    return 0;
}
// task 1
void param60() {
    cout << " ### param60 ### " << endl;
    // entered dates to count days
    TDate date1 = {31, 1, 2024}; // January 2024
    TDate date2 = {15, 2, 2023}; // February 2023
    TDate date3 = {21, 4, 2022}; // April 2022
    TDate date4 = {1, 12, 2021}; // December 2021
    TDate date5 = {28, 2, 2020}; // February 2020

    cout << " Days in January 2024: " << DaysInMonth(date1) << endl;
    cout << " Days in February 2023: " << DaysInMonth(date2) << endl;
    cout << " Days in April 2022: " << DaysInMonth(date3) << endl;
    cout << " Days in December 2021: " << DaysInMonth(date4) << endl;
    cout << " Days in February 2020: " << DaysInMonth(date5) << endl;

    return;
}
// function for determining the number of days in a month
int DaysInMonth(const TDate& date) {
    int daysInMonth; // diclaration
    switch (date.month) { 
        // for months with 31 days
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        // for months with 30 days
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        // for month with 29 or 28 days
        case 2:
        // check for leap year    
            if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
                daysInMonth = 29;
            else
                daysInMonth = 28;
            break;
        // if the introductions are in the wrong month
        default:
            daysInMonth = -1; 
            break;
    }

    return daysInMonth;
}
// task 2
void begin3() {
    cout << " ### begin3 ### " << endl;
    Square sq1;
    cout << " Enter value a : ";
    cin >> sq1.a; // input a
    cout << " Enter value b : ";
    cin >> sq1.b; // input b
    
    perim(&sq1); // perimeter calculation
    cout << " P = 2 * (a + b) =  " << sq1.P << endl;
    area(&sq1); // area calculation
    cout << " S = a * b =  " << sq1.S << endl;
}
// perimeter calculation
void perim(Square *s) {
    s->P = 2 * (s->a + s->b);
}
// area calculation
void area(Square *s) {
    s->S = s->a * s->b;
}
// task 3
void boolean29() {
    cout << " ### boolean29 ### " << endl;
    float x, y, x1, y1, x2, y2; // diclaration 

    cout << " Enter the coordinates of the point (x, y): ";
    cin >> x >> y; // input x and y

    cout << " Enter the coordinates of the top-left corner of the rectangle (x1, y1): ";
    cin >> x1 >> y1; // input x1 and y1

    cout << " Enter the coordinates of the bottom-right corner of the rectangle (x2, y2): ";
    cin >> x2 >> y2; // input x2 and y2
    
    Rectangle rect = {{x1, y1}, {x2, y2}}; // calculation

    if (isInsideRectangle({x, y}, rect)) {
        //if the point falls within the area
        cout << " The point is inside the rectangle: true" << endl;
    } else {
        // if the point is not falls into the area
        cout << " The point is outside the rectangle: false" << endl;
    }
    return;
}
// calculation
bool isInsideRectangle(Point p, Rectangle r) {
    return (p.x >= r.topLeft.x && p.x <= r.bottomRight.x &&
            p.y >= r.bottomRight.y && p.y <= r.topLeft.y);
}
