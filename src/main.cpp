#include <cstddef>
#include <iostream>
#include <Magick++.h>
#include <vector>



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

    std::vector<std::vector<std::vector<int>>> pixelArray(
        w,
        std::vector<std::vector<int>>(h,
            std::vector<int>(3)
        )
    );

    for (std::size_t i{ 0 }; i < w; ++i) {
        for (std::size_t j { 0 }; j < h; ++j) {
            Magick::ColorRGB px = image.pixelColor(i, j);
            pixelArray[i][j][0] = px.red()*255;
            pixelArray[i][j][1] = px.green()*255;
            pixelArray[i][j][2] = px.blue()*255;
        }
    }

    std::cout << "Successfully contructed pixel matrix!" << std::endl;
    std::cout << "Pixel matrix size: " << w << " x " << h << std::endl; 
    std::cout << "Iterating through pixel contents: " << std::endl;
    std::cout << "Pointer here\n";
    for (std::size_t i{ 0 }; i < pixelArray.size(); ++i)
        for (std::size_t j{ 0 }; j < pixelArray[i].size(); ++j) {
            std::cout << "(" << pixelArray[i][j][0] << ", " << pixelArray[i][j][1] << ", " << pixelArray[i][j][2] << ")" << std::endl;
        }


    return 0;
}


