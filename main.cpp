/**
 * @file main.cpp
 * @author Kyle Byassee & Darren Clark
 * @date 2022-09-26
 * @brief This program takes a number of noisy images and 
 * cleans them up to produce a final image that is noise free.
 * 
 * By getting all rgb values from images, from a file, this 
 * program will "stack" all rgb values. With a total value, 
 * the program will then calculate their average and write that 
 * to an output file which should produce a noise free image.
 */

#include "stacker.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
  
  // The magnitude of ppms that can be averaged in this program: 10^power
  int power = 3;
  
  int magnitude = 1;
  for(int i = 0; i < power; i++) {
    magnitude = magnitude * 10;
  }
  
  // Name of the folder containing all of the ppm's to be stacked.
  string img_name = "";
  cout << "Please enter the image you wish to stack: ";
  cin >> img_name;

  // Number of ppm files in the specified folder.
  int num_images = 0;
  cout << "Please enter the number of images: ";
  cin >> num_images;

  // For our purposes stacker handles up to 10^power ppm files.
  while( ( num_images > magnitude ) || (num_images < 1) ) {
    cout << "Try again: ";
    cin >> num_images;
  }

  stacker Single;
  stacker Average;
  
  stringstream nameStream;
  string nameOfFile = "";
  
  cout << "Stacking images:" << endl;
  
  // One based index to conform to ppm naming convention.
  for(int i = 1; i <= num_images; i++) {
    nameStream.str("");

    // Relative path to ppm files
    nameStream << "ppms" << '/' << img_name << '/';
    
    // File name: Limited to 10^power ppm files
    nameStream << img_name << '_' << setfill('0') << setw(power) << i << '.' << "ppm";
    
    nameOfFile = nameStream.str();

    //cout << '\t' << nameOfFile.substr(5) << endl;  // Doesn't match example
    cout << "     " << nameOfFile.substr(5) << endl;
    Single.load_data(nameOfFile, i);
    
    Average.average(num_images, i, Single);
  }
  cout << endl
       << "Stacking succeeded." << endl;
  
  Average.write_data(img_name);
  cout << "Output written to: " << img_name + ".ppm" << endl;
  
  return 0;
}
