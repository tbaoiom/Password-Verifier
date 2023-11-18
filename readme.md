                 Read Me


*******************************************************
*  Description of the program
*******************************************************
1. Asks the user to enter a password and hides the password as they type.
2. Checks to see if user password conforms to requirements.
3. If requirements not met, user is asked again.
4. Kicks user if 5 tries is passed.
5. Displays password to user.

*******************************************************
*  Source files
*******************************************************

Name:  passwordVerifier.cpp
   Main program.  This is the driver program asks for inputs and 
   gives an output.
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 6.1.x  It was 
   compiled, run, and tested on gcc csegrid server.

*******************************************************
*  Written Algorithm
*******************************************************
1. Use a function to hide user password.
2. Ask user for their password.
3. While loop to check the tries the user is on, breaks out if 5 is reached.
4. Create counters for requirements (length, special character, uppercase, not 0,1,7).
5. Asks user to try again and loop again if password doesn't meet requirements.
6. If requirements met, set break out.
7. If tries > 5, display message that user has been kicked.
8. Else, display success message and password.
   
*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [HW3]

   Now you should see a directory named homework with the files:
        passwordVerifier.cpp
        readme.md
        outputFile.txt
        inputFile.txt

3. Build the program.

    Change to the directory that contains the file by:
    % cd [HW3] 

    Compile the program by:
    % make

4. Run the program by:
   % ./[passwordVerifier]

5. Delete the obj files, executables, and core dump by
   %./make clean