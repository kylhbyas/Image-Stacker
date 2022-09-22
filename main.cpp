/**
 * @file main.cpp
 * @author Kyle Byassee
 * @date 2022-09-13
 * @brief Main
 * 
 * main
 */

#include "stacker.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {  // might need to take an argument
  string img_name = "";
  cout << "Please enter the image you wish to stack: ";
  cin >> img_name;
  
  int num_images = 0;
  cout << endl
       << "Please enter the number of images: ";
  cin >> num_images;
  
  while( (num_images > 10) || (num_images < 1) ) {
    cout << "Try again: ";
    cin >> num_images;
  }

  cout << endl
       << "Stacking images:" << endl;

  stringstream nameStream;

  stacker stack;
  stacker averaged_stack;

  //vector<p> tally;
  
  for(int i = 1; i <= num_images; i++) {
    if(i < 10) {
      nameStream << "ppms/" << img_name << '/'
		 << img_name << '_' << "00" << i << ".ppm";
    } else {
      nameStream << "ppms/" << img_name << '/'
		 << img_name << '_' << '0' << i << ".ppm";
    }
    string nameOfFile = nameStream.str();
    
    stack.load_data(nameOfFile);
    averaged_stack.average(num_images, i, stack); // , tally);
  }
  cout << "Stacking succeeded." << endl;
  
  averaged_stack.write_data(img_name);
  //stack.write_data(img_name); // used to verify load and write
  cout << "Output written to: " << img_name + ".ppm" << endl;
  
  return 0;
}
