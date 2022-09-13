#include "stacker.h"
#include <iostream>
#include <fstream>
#include <string>

// Constructor
//stacker::stacker(){
//}

int stacker::load_data(std::string filename) {
  std::ifstream in;
  int num_rows = 0;
  
  in.open(filename);
  // image header
  in >> magic_number;
  in >> width;
  in >> height;
  in >> max_color;
  // end of image header

  // image body
  while(in) {
    //in >> pixel.red;  // Fix me
    //in >> pixel.green;
    //in >> pixel.blue;

    num_rows++;
  }
  // end of image body
  in.close();

  return num_rows; // Should be 600 && equal to height
}
