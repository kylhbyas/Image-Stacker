/**
 * @file stacker.h
 * @author Kyle Byassee
 * @date 2022-09-26
 * @brief Defines the class stacker, it's members and methods.
 * 
 * Header file to declare and initialize members and methods of the stacker class.
 */

#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

/**
 * The stacker class opens a user requested folder that contains several images in ppm format. 
 * Each pixel of each image has its own rgb values, which the program will read and then sum each corresponding pixel together. 
 * Next it will find their averages by dividing the totals by the number of images. It writes the results to an output ppm file, 
 * which when opened in an image viewing program, will display a noise free image.
 *
 * @class stacker stacker.h "Image-Stacker/stacker.h"
 * @brief A custom class to take data from a ppm file, compute it, and write the results to an output ppm file. With the goal of producing a more clear image
 *
 */
class stacker {
private:
  std::string magic_number = ""; // The P3 value
  int width = 0; // The image width: (rows) * (columns)
  int height = 0; // The image height
  int max_color = 0; // The maximum color depth of the image: < 256
  
  struct pixel { // A struct containing three ints: red, green, and blue
    int red = 0;
    int green = 0;
    int blue = 0;
  };  

  std::vector<pixel> pixels; // A vector of pixel structs storing color information for the stacked image

 public:
/**
 * A constructor for the stacker class.
 *
 * @post A properly constructed object.
 * 
 */
  stacker();

/**
 * Method to set the private data members of a stacker object from a ppm file.
 *
 * @param std::string filename String variable containing the name of the file to be opened.
 * @param int index The index of the loop.
 * @pre String filename and int index have been declared and initialized to appropriate values.
 * @post The private members of one object have been set. One object to one ppm.
 * 
 */
  void load_data(std::string filename, int index);
  
/**
 * Method to find the average value of all stacked pixel values.
 *
 * @param int denominator The number of ppms being averaged.
 * @param int index The index of the loop.
 * @param stacker& stacked_pixels The address of the stacker object to be included in the average.
 * @pre The referenced stacker object should be properly loaded.
 * @post The private data members are now the average value of the stacked pixels.
 * 
 */
  void average(int denominator, int index, stacker& stack);

/**
 * Writes the calculated values and data to a new file.
 *
 * @param std::string filename Holds the name of the file to be written.
 * @post The file is opened and the ppm contents are written into it.
 * 
 */
  void write_data(std::string filename);
};
#endif //STACKER_H
