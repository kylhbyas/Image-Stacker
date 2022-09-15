#include "stacker.h"
#include <iostream>
#include <fstream>
#include <string>

// Constructor
// stacker::stacker() {
//   magic_number = "P3";
//   width = 1;
//   height = 1;
//   max_color = 255;

//   pixel.red = 0;
//   pixel.green = 0;
//   pixel.blue = 0;
// }

int stacker::load_data(std::string filename) {
  std::ifstream in;
  int num_rows = 0;

  std::string nameOfFile = "ppms" + '/' + filename + '/' + filename + "_0" + "01" + ".ppm"; // needs revision
  std::cout << std::endl << std::endl << nameOfFile << std::endl;
  
  in.open(nameOfFile);
  // image header
  in >> magic_number;
  in >> width;
  in >> height;
  in >> max_color;
  // end of image header


  // image body
  in >> pixel.red;
  while(in) {
    in >> pixel.green;
    in >> pixel.blue; // Correct until after this line

    num_rows++;
    in >> pixel.red;
  }
  in.close();
  // end of image body

  return num_rows; // Should be 600 && equal to height
}

void stacker::write_data(std::string filename, int size) {
  std::ofstream out;
  std::string newFile = filename.append(".ppm");
  
  out.open(newFile);
  out << magic_number << '\n'
      << width << ' ' << height << '\n'
      << max_color << '\n';
  
  for(int i = 1; i <= size; i++) {
    out << pixel.red << ' ' << pixel.green << ' ' << pixel.blue << '\n';
  }
  out.close();
  std::cout << "Output written to: " << newFile << std::endl;
}
