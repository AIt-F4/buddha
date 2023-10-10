#include "image.h"
#include <ostream>
#include "mbrot.h"

double normalize(double min, double max, double value);
void update_image(Image &image, const MandelbrotPointInfo &info);
void output_image_to_pgm(const Image &image, ostream &os);