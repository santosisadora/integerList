// Major Assignment 1 - 20%

//Student: Isadora Santos
//Student number: 200449748


//ALL WORK MUST BE YOUR OWN , IF FOUND COPYING CODE FROM OTHERS OR ONLINE YOU WILL RECEIVE 0% FOR YOUR GRADE
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    //declaring the int collection
    vector <int> number_list {}; 
    //declaring the variables
    char choice;
    int number_to_add;
    int sum {};
    int mean {};
    char chars;
    
    //using do-while loop. Run this loop while condition is true 
    do{
    //Asking for user's choice input
    cout << "\n P - Print numbers \n A - Add a number \n M - Display mean value of the list \n S - Display the smallest number \n L - Display the largest number \n Q - Quit \n";
    cout << "\n Please enter your choice: ";
    cin >> choice ;
    
    switch(choice){
        //In case user chooses P/p
        case 'P':
        case 'p': 
        if(!number_list.empty()){
        //Print numbers from the list
        cout << " Printing numbers..." <<endl;
        cout << " [";
        for(int i:number_list)
            cout << i << ' ';
        cout << "]" << endl;
        }else {
            cout << " This list is empty" << endl;
              }
        break;
        
        //In case user chooses A/a
        case 'A':
        case 'a':
        //Prompting user for a number to add
        cout << " Please enter the number to be added: ";
        cin >> number_to_add;
        //adding the number to the list
        number_list.push_back(number_to_add);
        //confirming that the number was added
        cout << " Number " <<number_to_add << " was added to the list." << endl;
        break;
        
        //In case the user chooses M/m
        case 'M':
        case 'm':
        if(!number_list.empty()){
        //Calculate the mean value of the list
        cout << " The mean value of the list is: ";
        for(int x:number_list)
            sum += x;
        mean = sum / number_list.size();
        cout << mean <<endl;
        }else{
         cout << " Unable to calculate the mean - no data" << endl;    
             }
        break;
        
        //In case the user chooses S/s
        case 'S':
        case 's':
        if(!number_list.empty()){
        //Display the smallest number in the list
        cout << " The smallest number in the list is: ";
        cout << *min_element(number_list.begin(), number_list.end()) << endl;
        }else{
            cout << " Unable to determine the smallest number - list is empty" << endl;    
             }
        break;
        
        //In case user chooses L/l
        case 'L':
        case 'l':
        if(!number_list.empty()){
        //Display the largest number in the list
        cout << " The largest number in the list is: ";
        cout << *max_element(number_list.begin(), number_list.end()) << endl;
        }else{
             cout << " Unable to determine the largest number - list is empty" << endl;
            }
        break;

    }
    //The loop runs while this condition is true(while the user doesn't choose to quit the program
    }while(choice != 'Q' && choice != 'q');
    
    //If they choose to quit the program
    if(choice == 'q' || choice == 'Q'){
        //Display goodbye message
        cout << " Goodbye! :)" << endl;    
    }
}

