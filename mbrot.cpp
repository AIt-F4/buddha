#include "mbrot.h"
#include <iostream>
#include <random>
// random number generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> real(-2,1); // real range
std::uniform_real_distribution<double> imaginary(-1.5,1.5); // imaginary range

MandelbrotPointInfo compute_mandelbrot(complex<double> c, int max_iters, bool collect_points) 
{
    MandelbrotPointInfo pointInfo = {};
    pointInfo.initial_point = c;
    pointInfo.points_in_path = {};
    pointInfo.max_iters = max_iters;

    std::complex<double> z = std::complex(0.0,0.0);
    for (int i = 1 ;i <= max_iters; i++)
    {
        z = pow(z,2) + c;
        pointInfo.points_in_path.push_back(z);
        if ((pow(z.real(),2) +pow(z.imag(),2)) > 4.0)
        {
            pointInfo.num_iters = i;
            pointInfo.escaped = true;
            return pointInfo;
        }
    }

    pointInfo.escaped = false;
    pointInfo.num_iters = max_iters;
    return pointInfo;
}

int main(){
    double c_real = real(gen);
    double c_imaginary = imaginary(gen); 

    std::complex c = std::complex(c_real ,c_imaginary);
    // std::cout << c << std::endl << std::pow(c,2) << std::endl;
    // std::cout << c.real();
    MandelbrotPointInfo cPointInfo = compute_mandelbrot(c,10,true);
    std::cout << cPointInfo.initial_point << std::endl << cPointInfo.escaped << std::endl << cPointInfo.num_iters << std::endl <<cPointInfo.max_iters << std::endl;
    for(int i=0; i < cPointInfo.points_in_path.size(); i++)
    {
    std::cout << cPointInfo.points_in_path.at(i) << std::endl;
    }

}
