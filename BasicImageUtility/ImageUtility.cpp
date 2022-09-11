#include "Utility.hpp"
#include <memory>



int main(int argc,char** argv)
{
    if(argc <= 1)
    {
        throw std::runtime_error("Image path needed in order to process image");
    }

    auto image = std::make_unique<Image>(argv[1]);

    auto cropped_image = image->crop_image(cv::Rect(3,3,100,100));

    image->display_processed_image(cropped_image);

    auto resized_image = image->resize_image(cv::Size(64,64));

    image->display_processed_image(resized_image);

    auto flipped_image = image->flip_image(0);
    
    image->display_processed_image(flipped_image);

}