#include "mbrot.h"
#include <iostream>
#include <random>
// random number generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> real(-2,1); // real range
std::uniform_real_distribution<double> imaginary(-1.5,1.5); // irrational range

//displays the complex number supplied
// void display(complex <double> c){
//    std::cout << "The complex number is: ";
//    std::cout << real(c) << '+' << imag(c) << 'i' << std::endl;
// }



int main(){
    double c_real = real(gen);
    double c_imaginary = imaginary(gen); 
    std::complex<double> c = c_real + c_imaginary;
    std::cout << c;
    // display(c);
}
