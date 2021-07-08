/* Add your name here */
    
#include <iostream>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
using namespace std;


int main()
{
    srand(time(0)); // initialize random seed generator to current time: 
					// needed to generate a different sequence of random numbers
					// each time you run your program

    // Add your code to play the dice game here
    int x;

    int roll();
    {
        int roll = rand()%6+1;
        return roll;
    }

    int game();
    {
        cout << "Do you want to play the dice game?" << endl;
        cin >> x;

        if (x == 'Y' || x == 'y')
        {
            int num_1 = roll();
            int num_2 = roll();
            int sum = num_1+num_2;

            if (sum == 7 || sum == 11)
            {
                
            }
        }

    }

}


