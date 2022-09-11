#include "Utility.hpp"

cv::Mat Image::crop_image(const cv::Rect roi)
{
    auto dst = m_img(roi);
    return dst;
}

void Image::display_processed_image(const cv::Mat img)
{
    cv::imshow("processed_image",img);
    WAIT;
    DESTROY;
}

cv::Mat Image::resize_image(const cv::Size size)
{
    cv::Mat dst;
    cv::resize(m_img,dst,size);
    return dst;
}

cv::Mat Image::flip_image(const int code)
{
    cv::Mat dst;
    cv::flip(m_img,dst,code);
    return dst;
}

cv::Mat Image::annotate_image(const cv::Point point1,const cv::Point point2)
{
    auto dst = m_img.clone();
    cv::line(dst,point1,point2,cv::Scalar(0,255,0));
    return dst;
}

cv::Mat Image::annotate_image(const cv::Point point,const int radius)
{
    auto dst = m_img.clone();
    cv::circle(dst,point,radius,cv::Scalar(255,0,0));

    return dst;

}

cv::Mat Image::annotate_image(const cv::Rect rect)
{
    auto dst = m_img.clone();
    cv::rectangle(dst,rect,cv::Scalar(0,0,255));
    return dst;
}