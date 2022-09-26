#include "stacker.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
// stacker::stacker() {
//   magic_number = "P3";
//   width = 1;
//   height = 1;
//   max_color = 255;

//   pixels.push_back(height);
// }

void stacker::load_data(string filename, int index) {
  ifstream in;
  
  in.open(filename);
  // image header
  in >> magic_number
     >> width >> height
     >> max_color;
  // end of image header

  if(index == 1) {
    pixels.reserve(width * height);
  }  
  
  // image body
  for(int i = 0; i < (width * height); i++) {
    in >> pixels[i].red >> pixels[i].green >> pixels[i].blue;
  }
  // end of image body
  in.close();
}

void stacker::average(int denominator, int index, stacker& stack) {
  if(index == 1) { // First call
    magic_number = stack.magic_number;
    width = stack.width;
    height = stack.height;
    max_color = stack.max_color;

    for(int i = 0; i < (width * height); i++) {  // sets all elements to 0      
      p temp_pix;
      temp_pix.red = 0;
      temp_pix.green = 0;
      temp_pix.blue = 0;

      pixels.push_back(temp_pix);
    }
  }

  // sums values each time average() is called
  for(int i = 0; i < (width * height); i++) {
    pixels[i].red += stack.pixels[i].red;
    pixels[i].green += stack.pixels[i].green;
    pixels[i].blue += stack.pixels[i].blue;
  }

  if(index == denominator) { // Divides on last call
    for(int i = 0; i < (width * height); i++) {
      pixels[i].red = pixels[i].red / denominator;
      pixels[i].green = pixels[i].green / denominator;
      pixels[i].blue = pixels[i].blue / denominator;
    }
  }
}

void stacker::write_data(std::string filename) {
  ofstream out;
  string newFile = filename.append(".ppm");
  
  out.open(newFile);
  // image header
  out << magic_number << '\n'
      << width << ' ' << height << '\n'
      << max_color << '\n';
  // end of image header

  // image body
  for(int i = 0; i < (width * height); i++) {
    out << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << '\n';
  }
  // end of image body
  out.close();
}
