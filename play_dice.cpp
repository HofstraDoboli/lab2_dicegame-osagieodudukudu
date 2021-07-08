//Osagie Odudukudu
    
#include <iostream>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
using namespace std;

void welcomescreen();
void losescreen();
void winscreen();
void gameoverscreen();
int roll();

int main()
{
    srand(time(0)); // initialize random seed generator to current time: 
					// needed to generate a different sequence of random numbers
					// each time you run your program

    // Add your code to play the dice game here
    // This is display welcome screen
    welcomescreen();

    //a bool variable to check player continuing game

    bool play_game = true;
    
    //While the game is going
    while (play_game == true)
    {
       //pick two random numbers between 1 to 6
       int num1 = 0;
       int num2 = 0;

       num1 = roll();
       num2 = roll(); 

       //output the sum
       int sum = 0;

       sum = num1 + num2;
       cout << "The dice values are " << num1 << " and " << num2 << endl;
       cout << "The sum is " << sum << endl;

       //if the sum is 7 or 11 then output win_screen and ask if they want to play again
       if (sum == 7 || sum == 11)
       {
           winscreen();
           cout << "Do you want to continue?" << endl;
            char yesorno;
            cin >> yesorno;

            if (yesorno == 'y' || yesorno =='Y')
            {
                //do nothing
            }
            else 
            {
                play_game = false;
            }
       }
       
       //else if the sum is 2 or 3 or 12 then output the lose_screen and ask if they want to play again
       else if (sum == 2 || sum == 3 || sum == 12)
       {
           losescreen();
           cout << "Do you want to continue?" << endl;
            char yesorno;
            cin >> yesorno;

            if (yesorno == 'y' || yesorno =='Y')
            {
                //do nothing
            }
            else 
            {
                play_game = false;
            }
       }

       //else make player_point = to the sum and ask player to roll again
       else
       {
           //else make player_point = to the sum and ask player to roll again
           int player_point = sum;

           //bool to check win or lose
           bool winorlose = false;

           //while win not lose
           while (winorlose == false)
           {
               //pick two random numbers between 1 to 6 
                int num3 = 0;
                int num4 = 0;

                num3 = roll();
                num4 = roll(); 

                //output the sum
                int sum2 = 0;

                sum2 = num3 + num4;
                cout << "The dice values are " << num3 << " and " << num4 << endl;
                cout << "The sum is " << sum2 << endl; 

                //if sum equals player_point then win_screen and ask to play again

                if (sum2 == player_point)            
                {
                    winorlose = true;
                    winscreen();

                    cout << "Do you want to continue?" << endl;
                    char yesorno;
                    cin >> yesorno;

                    if (yesorno == 'y' || yesorno =='Y')
                    {
                        //do nothing
                    }
                    else 
                    {
                        play_game = false;
                    }                                        
                }
                //else if sum equals 7 then output the lose_screen and ask if they want to play again
                else if (sum == 7)
                {
                    winorlose = true;
                    losescreen();

                    cout << "Do you want to continue?" << endl;
                    char yesorno;
                    cin >> yesorno;

                    if (yesorno == 'y' || yesorno =='Y')
                    {
                        //do nothing
                    }
                    else 
                    {
                        play_game = false;
                    }                    
                }
                //else keep playing
                else
                {
                    //do nothing
                }

           }
           
       }

    }


}

void welcomescreen()
{
    cout << "Welcome to the dice game!"<<endl;
}

void losescreen()
{
    cout << "Sorry. You lost."<<endl;
}

void gameoverscreen()
{
    cout << "Game Over"<<endl;
}

void winscreen()
{
    cout << "Congrats! You won."<<endl;
}

//give random number between 1 and 6
int roll()
{
    int number = 0;
    number = rand()%6 + 1;
    return number;
}




