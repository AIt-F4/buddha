//#include <mbrot.h>
#include <iostream>
#include <random>
#include <vector>
#include <complex>

std::default_random_engine gen;
std::uniform_real_distribution<double> real(-2,1); // real range
std::uniform_real_distribution<double> imaginary(-1.5,1.5); // irrational range



int main(){
    double c_real = real(gen);
    double c_imaginary = imaginary(gen);    
    std::complex<double> c = c_real + c_imaginary;
    std::cout << c;
}
