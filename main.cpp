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

using namespace std;

int main() {//int x) {
  string img_name;
  cout << "Please enter the image you wish to stack: ";
  cin >> img_name;

  cout << endl;
  
  int num_images;
  cout << "Please enter the number of images: ";
  cin >> num_images;

  cout << endl
       << "Stacking images:" << endl;

  // Stuff happens here...

  cout << "Stacking succeeded." << endl
       << "Output written to: " << endl;
  
  return 0;
}
