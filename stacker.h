#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

class stacker {
private:
  std::string magic_number = ""; // The P3 value
  int width = 0; // The image width: (600 rows) x (600 columns)
  int height = 0; // The image height
  int max_color = 0; // The maximum color depth of the image: < 256
  
  struct p { // A struct containing three ints: red, green, and blue
    int red = 0;
    int green = 0;
    int blue = 0;
  };  
  std::vector<p> pixels; // A vector of pixel structs storing color information for the stacked image

 public:
  void load_data(std::string filename, int index);
  
  void average(int denominator, int index, stacker& stacked_pixels);
  
  void write_data(std::string filename);
};
#endif //STACKER_H
