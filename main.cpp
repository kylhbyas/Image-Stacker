//???REMOVE ME BEFORE FINAL PUSH
/*
Anywhere you see ??? it means I have a note/question I want you to be sure and review.
I believe control + s ??? will allow you to find all instances of ???.
*/

/**
 * @file main.cpp
 * @author Kyle Byassee
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
#include <sstream>

using namespace std;

//??? I don't think any comments are needed in main? Can maybe make a few comments on your logic being used?
int main() {
  string img_name = "";
  cout << "Please enter the image you wish to stack: ";
  cin >> img_name;
  
  int num_images = 0;
  cout << "Please enter the number of images: ";
  cin >> num_images;
  
  while( (num_images > 10) || (num_images < 1) ) {
    cout << "Try again: ";
    cin >> num_images;
  }

  cout << "Stacking images:" << endl;

  stringstream nameStream;

  stacker stack;
  stacker averaged_stack;
  
  for(int i = 1; i <= num_images; i++) {
    nameStream.str("");
    
    if(i < 10) {
      nameStream << "ppms/" << img_name << '/'
		 << img_name << '_' << "00" << i << ".ppm";
    } else {
      nameStream << "ppms/" << img_name << '/'
		 << img_name << '_' << '0' << i << ".ppm";
    }
    string nameOfFile = nameStream.str();

    cout << '\t' << nameOfFile << endl;
    
    stack.load_data(nameOfFile, i);
    averaged_stack.average(num_images, i, stack);
  }
  cout << endl
       << "Stacking succeeded." << endl;
  
  averaged_stack.write_data(img_name);
  cout << "Output written to: " << img_name + ".ppm" << endl;
  
  return 0;
}
