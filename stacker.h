#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

class stacker {
private:
  std::string magic_number = ""; // The P3 value
  int width = 0; // The image width: (600 rows) x (600 columns)
  int height = 0; // The image height
  int max_color = 0; // The maximum color depth of the image: < 255
  
  struct pixel { // A struct for three ints: red, green, blue
    int red = 0;
    int green = 0;
    int blue = 0;
  };
  //vector<struct> pixels; // A vector of pixel structs storing color information for the stacked image

 public:
  int load_data(std::string filename);
  // and potentially more stuff...

};
#endif //STACKER_H
