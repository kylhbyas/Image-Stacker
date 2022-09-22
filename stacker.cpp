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

void stacker::load_data(string filename) { // Good see test.ppm
  ifstream in;
  
  in.open(filename);
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

void stacker::average(int denominator, int index, stacker stack) {
  if(index == 1) {  // assignment operator overload?
    magic_number = stack.magic_number;
    width = stack.width;
    height = stack.height;
    max_color = stack.max_color;

    pixels.reserve(width * height);

    for(int i = 0; i < (width * height); i++) {  // sets all elements to 0
      cout << "hi" << endl;
      //pixels.assign(1, 0); // assignment here
      pixels[i].red = 0;
      cout << "omg" << endl;
      pixels[i].green = 0;
      pixels[i].blue = 0;
      cout << pixels[i].red << pixels[i].green << pixels[i].blue << endl;
    }
  }
  
  for(int i = 0; i < (width * height); i++) { // sums values each time average() is called
    pixels[i].red += stack.pixels[i].red;
    pixels[i].green += stack.pixels[i].green;
    pixels[i].blue += stack.pixels[i].blue;
    cout << pixels[i].red << pixels[i].green << pixels[i].blue << endl;
  }

  if(index == denominator) {  // Averages on last call
    for(int i = 0; i < (width * height); i++) {
      pixels[i].red /= denominator;
      pixels[i].green /= denominator;
      pixels[i].blue /= denominator;
    }
  }
}

void stacker::write_data(std::string filename) { // Works good see test.ppm
  ofstream out;
  string newFile = filename.append(".ppm");
  
  out.open(newFile);
  out << magic_number << '\n'
      << width << ' ' << height << '\n'
      << max_color << '\n';
  
  for(int i = 0; i < (width * height); i++) {
    out << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << '\n';
  }
  out.close();
}
