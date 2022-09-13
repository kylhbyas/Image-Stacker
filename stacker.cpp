#include "stacker.h"
#include <iostream>

stacker::stacker(){
}


// Vector::Vector(const Vector &other) {
//   vec_capacity = other.vec_capacity;
//   vec_size = other.vec_size;
  
//   vec_ptr = new int[vec_capacity];
//   for(int i = 0; i < vec_size; i++) {
//     vec_ptr[i] = other.vec_ptr[i];
//   }
// }


// Vector::~Vector() {
//   delete[] vec_ptr;
//   vec_ptr = nullptr;
  
//   vec_size = 0;
//   vec_capacity = 0;
// }


// Vector& Vector::operator=(const Vector &other) {
//   if(this != &other) {
//     vec_capacity = other.vec_capacity;
//     vec_size = other.vec_size;

//     delete[] vec_ptr;
//     vec_ptr = new int[vec_capacity];
//     for(int i = 0; i < vec_size; i++) {
//       vec_ptr[i] = other.vec_ptr[i];
//     }
//   }

//   return *this;
// }


// int Vector::size() {
//   return vec_size;
// }


// int Vector::capacity() {
//   return vec_capacity;
// }


// void Vector::push_back(int element) {
//   if(vec_size == vec_capacity) {
//     reserve(vec_capacity + 1);
//   }
//   vec_ptr[vec_size] = element;
//   vec_size++;
// }


// void Vector::reserve(int n) {
//   if(n > vec_capacity) {
//     vec_capacity = n;

//     int* temp_vec_ptr = new int[vec_capacity];
    
//     for(int i = 0; i < vec_size; i++) {
//       temp_vec_ptr[i] = vec_ptr[i];
//     } 
    
//     delete[] vec_ptr;    
//     vec_ptr = temp_vec_ptr;
//     temp_vec_ptr = nullptr;
//   }
// }


// int& Vector::operator[](unsigned int index) {
//   return vec_ptr[index];
