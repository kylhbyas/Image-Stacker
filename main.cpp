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
  
  cout << endl;
  
  int num_images = 0;
  cout << "Please enter the number of images: ";
  cin >> num_images;  // 10
  
  while( (num_images > 10) || (num_images < 1) ) {
    cout << "Try again: ";
    cin >> img_name;
  }
  
  cout << endl
       << "Stacking images:" << endl;
  
  stacker one;
  int size = one.load_data(img_name);
  one.write_data(img_name, size);

  cout << "Stacking succeeded." << endl;
  //   << "Output written to: " << endl;
  // Stuff again..
  
  return 0;
}
