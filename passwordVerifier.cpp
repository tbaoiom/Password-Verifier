#include <iostream>
#include <cstring>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Function to have invisible password

int pswd_getch( ) {

    struct termios savedTermIO, newTermIO;  //storing termio flags information
    int ch;

    //retrieving the current termio (terminal I/O) attributes of stdin (cin)
    tcgetattr(STDIN_FILENO, &savedTermIO );
    newTermIO = savedTermIO;

    // setting termio flags:
    // turn off input buffering (ICANON) and echoing to cout  (ECHO)
    newTermIO.c_lflag &= ~( ICANON | ECHO );  

    //settting the new termio (terminal I/O) attributes before reading a char
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermIO );
    ch = getchar();

    // read in a char, now reverting to the previously saved termio
    tcsetattr( STDIN_FILENO, TCSANOW, &savedTermIO );
    return ch;
  }

int main() {
  // Declaration of variables
  int upperCount;
  int invalidDigitCount;
  int punctCount;
  int digitCount;
  char password[12];
  char oldPassword[12];
  int i=0;
  int tries = 5;
  int j;

  // Let the user know the requirements of the password
  cout << "(Note: The password must be [8-12] characters long, have at least 1 uppercase " 
          "letter, contain a digit that is not [0,1,7], and must contain at least 1 special"   
          "character {!@#$%^&*()_+})" 
       << endl;
  
  while (tries > 0) {
    // Reestablish counts and resets array when password fails
    upperCount = 0;
    invalidDigitCount = 0;
    punctCount = 0;
    digitCount = 0;
    i = 0;
    password[0] = 0;
    
    // Ask user to input password and hide it while they type
    cout << "Enter a password: " << endl;
    
    while((password[i] = pswd_getch())!='\n'){
      cout<<"*";
      i++;
    }    
    
    // Makes sure it is properly null terminated
    password[i] = '\0';
    cout << endl;

    // Loops through password to check for requirements
    j=0;
    while (j<i) {
      if (isupper(password[j])) {
        upperCount++;
      }
      if (password[j] == 0 || password[j] == 1 || password[j] == 7) {
        invalidDigitCount++;
      }
      if (ispunct(password[j])) {
        punctCount++;
      }
      if (isdigit(password[j])) {
        digitCount++;
      }
      j++;
    }
    
    // Breaks out of loop if password is valid
    if (upperCount < 0) {
      tries--;
      cout << "Invalid password. You have " << tries << " tries left." << endl;
      }
    else if (i < 8 || i > 12) {
      tries--;
      cout << "Invalid password. You have " << tries << " tries left." << endl;
      }
    else if (invalidDigitCount > 0) {
      tries--;
      cout << "Invalid password. You have " << tries << " tries left." << endl;
      }
    else if (punctCount < 0) {
      tries--;
      cout << "Invalid password. You have " << tries << " tries left." << endl;
    }
    else if (digitCount < 0) {
      tries--;
      cout << "Invalid password. You have " << tries << " tries left." << endl;
    }
    else {
      break;
    }
  }

  // If tries reaches 0, display kick message, otherwise success message
  if (tries < 1) {
    cout << "Maximum number of tries exceeded, you have been kicked." << endl;
  }
  else {
    cout << "It worked! The password is: " << password << endl;
  }
}