#include "bbrot.h"
#include <complex>
#include <vector>
#include <cmath>
#include <utility>

const double x_min = -2.0;
const double x_max = 1.0;
const double y_min = -1.5;
const double y_max = 1.5;

double normalise(double value, double min, double max)
{
    return (value - min)/(max - min);
}

std::pair<int,int> map_complex(complex<double> c, int image_size)
{
    double x = c.real();
    double y = c.imag();

    double norm_x = normalise(x, x_min, x_max);
    double norm_y = normalise(y, y_min, y_max);
    int coord_x = round(norm_x * image_size);
    int coord_y = round(norm_y * image_size);
    std::pair<int,int> coords(coord_x,coord_y);
    return coords;
}


int main(int argc, char **argv)
{
    // if(argc != 4)
    // {
    //     std::cerr << "Error wrong number of arguments given";
    //     return 1;
    // }
    // int image_size = std::atoi(argv[1]);
    // int number_of_points = std::atoi(argv[2]);
    // int max_iters = std::atoi(argv[3]);
    for(int i = 0; i < 10;i++)
    {
    complex<double> c = gen_complex(x_min, x_max, y_min, y_max);
    std::pair<int,int> coords = map_complex(c,600);
    int x = coords.first;
    int y = coords.second;
    std::cout << c << " ";
    std::cout << x << " "<< y << std::endl;
    }


    return 0;
}