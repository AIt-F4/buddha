#include "bbrot.h"
#include <complex>
#include <vector>

const double x_min = -2.0;
const double x_max = 1.0;
const double y_min = -1.5;
const double y_max = 1.5;

double normalise(double min, double max, double value)
{
    return (value - min)/(max - min);
}