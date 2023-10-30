#include "bbrot.h"
#include <complex>
#include <vector>
#include <cmath>
#include <utility>
#include <fstream>
// Initialising the ranges of real and imaginary values for the complex number
const double x_min = -2.0;
const double x_max = 1.0;
const double y_min = -1.5;
const double y_max = 1.5;

// normalise a number in a range over 0-1
double normalise(double value, double min, double max)
{
    return (value - min)/(max - min);
}
// takes a vector of complex points and increments the pixel values of points in the vector
void update_image(Image  &myImage,MandelbrotPointInfo cPointInfo)
{
    vector<d_complex> points = cPointInfo.points_in_path;
    int image_size = myImage.getHeight();
    for(int i = 0; i < points.size(); i++)
    {
        d_complex c = points.at(i);
        if(-2.0 <= c.real() && c.real() <= 1.0 && -1.5 <= c.imag() && c.imag() <= 1.5)
        {
            double x = c.real();
            double y = c.imag();
            double norm_x = normalise(x, x_min, x_max);
            double norm_y = normalise(y, y_min, y_max);
            int coord_x = round(norm_x * (image_size-1));
            int coord_y = round(norm_y * (image_size-1));
            myImage.incValue(coord_x, coord_y);
            myImage.incValue(coord_x, (myImage.getHeight() - coord_y -1));

        }
    }
}
//outputs the image and its greyscale values to pgm file format
void output_image_to_pgm(Image myImage)
{
    vector<int> imageData = myImage.getData();
    vector<int>::iterator iter = imageData.begin();
    
    vector<int> pixelValues = {};
    int j = myImage.getHighestValue();

    for(iter; iter < imageData.end(); iter++)
    {
        //normalise the values for each pixel to the range 0 to 255 for greyscale image
        
        int greyscaleValue = round(normalise(*iter,0,j)*255);
        pixelValues.push_back(greyscaleValue);
    }
    std::cout << "greyscale values generated";
    std::ofstream file("image.pgm");
    file << "P2 " << myImage.getWidth() << " " << myImage.getHeight() << " 255\n";
    for(int i = 0; i < pixelValues.size(); i++)
    {
        if(i == 0)
        {
            file << pixelValues[i];
        }
        else
        {
        file << " " << pixelValues[i];
        }
    }
    

        
}


int main(int argc, char **argv)
{
    // if the wrong number of args are given throws error
    if(argc != 4)
    {
        std::cerr << "Error wrong number of arguments given";
        return 1;
    }
    int image_size = std::atoi(argv[1]);
    int number_of_points = std::atoi(argv[2]);
    int max_iters = std::atoi(argv[3]);
    Image myImage = Image(image_size,image_size);

    //generates a number of random complext numbers equal to the given arguement and plots their escape paths
    for(int i =0; i < number_of_points;i++)
    {
    complex<double> c = gen_complex(x_min, x_max, y_min, y_max);
    MandelbrotPointInfo cPointInfo = compute_mandelbrot(c,max_iters,true);
    if (cPointInfo.escaped == true)
    {
    update_image(myImage, cPointInfo);
    }
    if( i% 10000 == 0 && i != 0)
    {
        std::cout << i << " lines done" << std::endl;
    }
    }
    
    std::cout << "the highest value is " << myImage.getHighestValue();
    output_image_to_pgm(myImage);
    return 0;
}