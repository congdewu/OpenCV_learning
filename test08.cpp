#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	cv::Mat src, dst;
	src = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	if (!src.data)
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	char input_title[] = "input image";
	char output_title[] = "blur image";
	
	cv::namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	cv::namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	cv::imshow(input_title, src);

	cv::blur(src, dst, cv::Size(5, 5), cv::Point(-1, -1));
	cv::imshow(output_title, dst);

	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/blur_image.jpg", dst);

	cv::Mat gblur;
	cv::GaussianBlur(src, gblur, cv::Size(5, 5), 11, 11);
	cv::imshow("gaussian blur", gblur);

	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/gaussianblur_image.jpg", gblur);

	cv::waitKey(0);
	return 0;
}

