/**
 * @file stacker.cpp
 * @author Kyle Byassee
 * @date 2022-09-26
 * @brief File to implement the stacker class.
 * 
 * The stacker class methods are implemented here.
 */

#include "stacker.h"
#include <iostream>
#include <fstream>

using namespace std;

//  Constructor
stacker::stacker() {
  magic_number = "P3";
  width = 1;
  height = 1;
  max_color = 2;

  for(int i = 0; i < (width * height); i++) {
    pixel temp;
    
    temp.red = 0;
    temp.green = 0;
    temp.blue = 0;
    
    pixels.push_back(temp);
  }
}

void stacker::load_data(string filename, int index) {
  ifstream in;
  
  in.open(filename);
  // image header
  in >> magic_number
     >> width >> height
     >> max_color;
  // end of image header

  // Reserves the memory required store the pixel info
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
    // Sets the header
    magic_number = stack.magic_number;
    width = stack.width;
    height = stack.height;
    max_color = stack.max_color;

    // Sets all pixel values to 0 based on the area of the image
    for(int i = 0; i < (width * height); i++) {
      pixel temp;
      
      temp.red = 0;
      temp.green = 0;
      temp.blue = 0;
      
      pixels.push_back(temp);
    }
  }

  // Error checking
  if(magic_number != stack.magic_number) {
    if(width != stack.width) {
      if(height != stack.height) {
	if(max_color != stack.max_color) {
	  cout << "Error: ppm header info does not match. Continuing anyways..." << endl;
	}
      }
    }
  }

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
