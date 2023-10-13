#include "image.h"
#include <iostream>
#include "mbrot.h"

double normalise(double min, double max, double value);
void update_image(Image image, const MandelbrotPointInfo info);
void output_image_to_pgm(Image image);