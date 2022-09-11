#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#define WAIT cv::waitKey(0)
#define DESTROY cv::destroyAllWindows()

class Image
{
    private:
        std::string m_name;
        cv::Mat m_img;
    public:
        Image(const std::string name): m_name(name)
        {
            m_img = cv::imread(m_name);
            if(!m_img.data)
            {
                throw std::runtime_error("Image reading failed, please check given path");
            }
        }


        cv::Mat crop_image(const cv::Rect roi);

        void display_processed_image(const cv::Mat img);

        cv::Mat resize_image(const cv::Size size);

        cv::Mat flip_image(const int code);

        cv::Mat annotate_image(const cv::Point point1,const cv::Point point2);

        cv::Mat annotate_image(const cv::Point point,const int radius);

        cv::Mat annotate_image(const cv::Rect rect);
};