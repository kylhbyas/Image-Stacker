//???REMOVE ME BEFORE FINAL PUSH
/*
Anywhere you see ??? it means I have a note/question I want you to be sure and review.
I believe control + s ??? will allow you to find all instances of ???.
*/

/**
 * @file stacker.h
 * @author Darren Clark
 * @date 2022-09-26
 * @brief Defines the class stacker, its members and methods.
 * 
 * Header file to declare and initialize members and methods of class Stacker.
 */

#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

//??? I think classes are typically spelled with a capital? so class Stacker {

/**
 * Class stacker opens a user requested file that contains several 
 * images. Each image has its own rgb values, which the program will 
 * read and sum all together. Next it will find their averages by
 * dividing the totals by the number of images. It writes the results
 * to an output file, which when opened in an image viewing program, will
 * display a noise free image.
 *
 * @class stacker stacker.h "Image-Stacker/stacker.h"
 * @brief A custom class to take data from a file, compute it, and 
 * write the results to an output file producing a cleaner image.

 */
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

/**
 * Method to open the user requested file.
 *
 * @param std::string filename String variable containing the name of the file to be opened.
 * @param int index ???
 * @pre String filename and int index have been declared and initialized to appropriate values.
 * @return void 
 * @post String filename has been assigned a value of a file to open and int index ???
 * 
 */
  void load_data(std::string filename, int index);
  

/**
 * Method to find the average value of all images rgb values.
 *
 * @param int denominator is the number of images being used.
 * @param int index ???
 * @param stacker& stacked_pixels Vector to contain the color values of the stacked image. ???
 * @pre int denominator has a value.
 * @return void 
 * @post ???
 * 
 */
  void average(int denominator, int index, stacker& stacked_pixels);
  

/**
 * Writes the calculated values and data to a new file.
 *
 * @param std::string filename holds the name of the file to be opened.
 * @pre filename has been given a value.
 * @return void 
 * @post the file is opened and contents are written into it. ???
 * 
 */
  void write_data(std::string filename);
};
#endif //STACKER_H
