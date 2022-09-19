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
#include <string>

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

  stacker Stacky_McStackyface;
  
  cout << endl
       << "Stacking images:" << endl;
  
  Stacky_McStackyface.load_data(img_name);
  cout << "Stacking succeeded." << endl;

  Stacky_McStackyface.average(num_images);
  
  Stacky_McStackyface.write_data(img_name);
  //cout << "Output written to: " << img_name + ".ppm" << endl;
  
  return 0;
}
