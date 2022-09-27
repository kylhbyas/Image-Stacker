<!--
   - @file README.md
   - @author Kyle Byassee
   - @date 2022-09-26
   - @brief ReadMe file
   - 
   - Basic readme for Image stacker assignment
   -->
# Image Stacker by Six Appeal

Name: Kyle Byassee & Darren Clark

Date: 2022-09-13

This is a place for our files for the image noise reduction assignment.

* Makefile
  * Controls compilation and cleans temporary and extraneous files.

* stacker.h
  * Declares the stacker class.

* stacker.cpp
  * Contains the definitions of the methods for the stacker class.

* main.cpp
  * A numbered main.cpp that contains the main function and interacts with the user.

## Compilation Instructions
How do we compile your program?
* To compile type <make> into the terminal, which calls the Makefile.

## Program usage
How do we run your program?
* To run the program:
  * Compile the program
  * Type <./stacker> to run the executables.

Does the program expect any inputs?
* The name of the folder containing the ppm files.
* The number of images to be stacked.

## Notes
* What is working?
  * The program is working as intended.

* What are the limitations of the programs?
  * The path to the ppm files is rather specific.
  * The file names must follow a particular format.
  * The program can only handle up to 1000 ppm files without tinkering.

* What were some design decisions?
  * Consistency was the primary consideration.

