/*
    Understanding input: cin, getline
*/

#include <iostream>
#include <vector>
#include <fstream> 
#include <climits>
using namespace std;

int main()
{

    ofstream output_file;           // output_file = is an output stream object that sends a stream of chars from the program into an output file
    output_file.open("out_lab2_2_answers"); // open an outpuf file where output_file will send data. 
    vector<string> array_values;    // declares an empty vector of strings
    array_values.push_back("10");   // add "10" 
    array_values.push_back("4.5");  // add "4.5"
    array_values.push_back("abc"); 
    array_values.push_back("a"); 

    int val;  // declare an integer variable int

    cout << "Code for Q1" << endl;
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
    
        cout << "\tEnter an int "; 
        cin >> val; 

        cout << "\n\tCheck fail flag in cin " <<  cin.fail() << endl;
        cout << "\tYou entered " << val << endl << endl;
    }
    
    // cin = is a stream object that takes characters from the keyboard and extracts data according 
    //       to the type of the variable in your program.
    //      = If it cannot extract the type specified in your program (in our case an integer), it might leave
    //      characters in the stream, which will conflict with future cin statements.
    
    // See whether the cin buffer is empty or not
    cin.clear();        // set all error flags to false
    string s;
    getline(cin, s);    // extracts characters from cin into the string object s
                        // getline = is a function defined in the <string> class
                        // check its definition at: http://www.cplusplus.com/reference/string/string/getline/ 
    cout << "Check what is left unread in the cin buffer: " << s << endl;
    cout << "Nr. characters left unred in cin buffer: " << s.length() << endl;
  

    output_file << "\nQ1: (cin only) What happens when you run the code above? Explain why" << endl;
    string answer = "When ran, as soon as I input 4.5 when I'm supposed to, the whole program skips ahead to the end. This is because the leftover .5 of 4.5 gets carried over to the next inputs and continues the loop without input from the user.  "; // enter your answer in between ""
    output_file << "Answer Q1: " << answer << endl;

    cout << "\nCode for Q2 and Q3" << endl;
    ///uncomment when you get to Q2 and Q3
    
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
        cout << "\tEnter an int "; 
        cin >> val;

        cout << "\n\tCheck fail flag in cin " <<  cin.fail()<< endl;

        string s; 
        getline(cin,s); 
        cout << "\tCheck what is left unread in the cin buffer: Length =" << s.length() 
             << "\tString " << s << endl;

        if (cin.fail())
        {
            cin.clear(); // clears the flags   
            cin.ignore(INT_MAX,'\n'); // ignore all characters from cin until new line '\n'
            cout << "\tERROR: The value you entered is not an integer. Try again." << endl;
        }
        
        cout << "\tYou entered " << val << endl << endl;
    }  
    
    output_file << "\nQ2: (cin + fail+ignore) What happens when you run the code above? Explain why." << endl;
    answer = "The same thing as the first code, but this time it allows the user to input for 'abc' and 'a'. This code was created to ignore the leftovers which is why The user is allowed to input for all of them. "; // enter your answer in between ""
    output_file << "Answer Q2: " << answer << endl;

    output_file << "\nQ3: Is the problem of reading an integer value solved? Explain your reasoning." << endl;
    answer = "It's not solve, it's just ignored. It turns the .5 from 4.5 into a string variable."; // enter your answer in between ""
    output_file << "Answer Q3: " << answer << endl;

    cout << "\nCode for Q4" << endl;
    // uncomment when you get to Q4
    
    // for (int i = 0; i < array_values.size(); i++)
    // {
    //     cout << "\tEnter the value " << array_values.at(i) << endl;
    //     cout << "\tEnter an int "; 
    //     string s;
    //     getline(cin,s);     // read a line of input from the cin buffer - 
    //                         // up to and including '\n'
    //     val = stoi(s);  // stoi = converts a string into an integer 
    //                         // read more at http://www.cplusplus.com/reference/string/stoi/?kw=stoi
    //     cout << "\tYou entered " << val << endl << endl;
    // }  
    
    output_file << "\nQ4: (getline only) What happens when you run the code above? Explain why." << endl;
    answer = "The loop runs until the user inputs 'abc' which terminates the loop. This is because 'abc' cannot be converted into an integer."; // enter your answer in between ""
    output_file << "Answer Q4: " << answer << endl;

    // Comment the for loop for Q4 above - leave the answer to Q4
    
    cout << "\nCode for Q5" << endl;
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
        cout << "\tEnter an int "; 
        string s;
        getline(cin,s); 
 
        try{   // read more about exceptions at https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
            val = stoi(s);
        }
        catch(const std::invalid_argument& ia)
        {
            cerr << "\tInvalid argument: " << ia.what() << '\n';
        }
        cout << "\tYou entered " << val << endl << endl;
    }
    
    output_file << "\nQ5: (getline+stoi) What happens when you run the code above? Explain why." << endl;
    answer = "It runs like the last one, but this time the termination doesn't happen. The exception is caught in the catch block. This is very useful to manage unexpected outputs that could crash the program."; // enter your answer in between ""
    output_file << "Answer Q5: " << answer << endl;

    //6. Q6 Add code to enter integer values from the keyboard correctly = accept only 10, not 4.5, abc or a
    cout << "\nCode for Q6" << endl;
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
        cout << "\tEnter an int ";
        cin >> val;


        // add your code - it should ask you to type the value you see at line 134. 
        // it should display "Correct 10 " when you enter 10; 
        // it should display "Incorrect ", followed by the value you entered, for the rest of of the values 
        // (4.5, abc or a) 
        // YOUR CODE NEEDS TO DETECT that 4.5 is not an integer
        
        string s;
        getline(cin,s);
        if (s.length() > 0 )
       {
           cout << "\tIncorrect " << val << s << endl;
        
       }
       else if (cin.fail())
       {
           cin.clear();
           cin.ignore(INT_MAX,'\n');
           cout << "\tIncorrect " << array_values.at(i) << endl;
       }
       else 
       {
           cout << "\tCorrect " << val << endl;
       } 

       cout << " " << endl;


    }
    output_file << "\nQ6: Explain your method to validate integer values entered" << endl;
    answer = " The first part analyzes whether the input was a string value. If it is not a string value then it checks to see if the input was a float. If it was a float then it outputs incorrect while ignoring and erasing the extra decimal point. Otherwise it outputs correct. It does that for every input. "; // enter your answer in between ""
    output_file << "Answer Q6: " << answer << endl;
    output_file.close();
}
