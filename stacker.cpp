#include "stacker.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constructor
// stacker::stacker() {
//   magic_number = "P3";
//   width = 1;
//   height = 1;
//   max_color = 255;

//   pixels.push_back(height);
// }

int stacker::load_data(std::string filename) {
  ifstream in;

  string nameOfFile = "ppms/" + filename;
  
  // String stream here instead...
  //string nameOfFile = "ppms/" + filename + '/' + filename + "_0" + "01" + ".ppm"; // needs revision
  //cout << endl << nameOfFile << endl;
  
  in.open(nameOfFile);
  
  // image header
  in >> magic_number
     >> width >> height
     >> max_color;
  // end of image header
  
  // image body
  for(int i = 0; i < (width * height); i++) {
    cout << "hi from before extraction" << endl;
    in >> pixels[i].red >> pixels[i].green >> pixels[i].blue; // Seg fault on this line
    cout << "hi from after extraction" << endl;
  }
  // end of image body
  in.close();

  int num_pix = pixels.size();
  
  return num_pix; // Should be 600 && equal to height
}

void stacker::write_data(std::string filename, int size) {
  ofstream out;
  string newFile = filename.append(".ppm"); // used to get rid of unused warning
  newFile = "test.ppm";
  
  out.open(newFile);
  out << magic_number << '\n'
      << width << ' ' << height << '\n'
      << max_color << '\n';
  
  for(int i = 1; i <= size; i++) {
    out << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << '\n';
  }
  out.close();
  cout << "Output written to: " << newFile << endl;
}
