#include "stacker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Constructor
// stacker::stacker() {
//   magic_number = "P3";
//   width = 1;
//   height = 1;
//   max_color = 255;

//   pixels.push_back(height);
// }

void stacker::load_data(std::string filename) {
  ifstream in;

  string nameOfFile = "ppms/" + filename;
  
  //stringstream nameOfFile << "ppms/" << filename << '/'
  //                        << filename << "_" << "001" << ".ppm"; // needs revision
  //cout << endl << nameOfFile << endl;
  
  in.open(nameOfFile);
  // image header
  in >> magic_number
     >> width >> height
     >> max_color;
  // end of image header
  
  pixels.reserve(width * height);
  
  // image body
  for(int i = 0; i < (width * height); i++) {
    in >> pixels[i].red >> pixels[i].green >> pixels[i].blue;
  }
  // end of image body
  in.close();  
}

// Averages the rgb values of each pixel stack
void stacker::average(int denominator) {

  int red_sum = 0;
  int green_sum = 0;
  int blue_sum = 0;

  for(int i = 0; i < denominator; i++) {
    red_sum += pixels[i].red;
    green_sum += pixels[i].green;
    blue_sum += pixels[i].blue;
  }

  

  
}

void stacker::write_data(std::string filename) {
  ofstream out;
  string newFile = filename.append(".ppm"); // used to get rid of unused warning
  newFile = "test.ppm";
  
  out.open(newFile);
  out << magic_number << '\n'
      << width << ' ' << height << '\n'
      << max_color << '\n';
  
  for(int i = 0; i < (width * height); i++) {
    //cout << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << '\n';
    out << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << '\n';
  }
  out.close();
  cout << "Output written to: " << newFile << endl;
}
