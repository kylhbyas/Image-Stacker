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

void stacker::average(int denominator, int index, stacker& stack); //, vector<p> tally) {
  if(index == 1) {  // assignment operator overload?
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

    for(int i = 0; i < (width * height); i++) {  // sets all elements to 0      
      p place;
      place.red = 0;
      place.green = 0;
      place.blue = 0;
    
      //tally.push_back(place);
    }
  }
  
  for(int i = 0; i < (width * height); i++) { // sums values each time average() is called
    if(stack.pixels[i].red != 0 || index == 1) {
      pixels[i].red += stack.pixels[i].red;
      //tally[i].red++;
    }
    if(stack.pixels[i].green != 0 || index == 1) {
      pixels[i].green += stack.pixels[i].green;
      //tally[i].green++;
    }
    if(stack.pixels[i].blue != 0 || index == 1) {
      pixels[i].blue += stack.pixels[i].blue;
      //tally[i].blue++;
    }
  }

  if(index == denominator) { // Divides on last call
    for(int i = 0; i < (width * height); i++) {
      //cout << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << endl;
       cout << tally[i].red << endl;
      if(tally[i].red != 0) {
	//pixels[i].red = pixels[i].red / tally[i].red;
      }
      if(tally[i].green != 0) {
	//pixels[i].green = pixels[i].green / tally[i].green;
      }
      if(tally[i].blue != 0) {
	//pixels[i].blue = pixels[i].blue / tally[i].blue;
      }
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
