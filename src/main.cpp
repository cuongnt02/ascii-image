#include <iostream>
#include <Magick++.h>



int main(int argc, char** argv) {

    Magick::Image image;

    try {
        image.read("../img/ascii-pineapple.jpg");
    }
    catch (Magick::Exception &error_) {
        std::cout << "Caught exception: " << error_.what() << std::endl;
        return 1;
    }
    std::cout << "Successfully loaded image!\n";
    std::cout << "Image size: " << image.size().width() << " x " << image.size().height() << std::endl;

    int w = image.columns();
    int h = image.rows();

    image.modifyImage();


    for (int i = 0; i <= w; ++i) {
        for (int j = 0; j <= h; ++j) {
            Magick::ColorRGB px = image.pixelColor(i, j);
            std::cout << "Pixel at point (" << i << ", " << j << "): ";
            std::cout << "( " << px.red() * 255.0 
                << ", " << px.green() * 255.0 
                << ", " << px.blue() * 255.0 <<" )" << std::endl;
        }
    }


    return 0;
}


