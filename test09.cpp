#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	cv::Mat src, dst;
	src = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/qie.png");
	if (!src.data)
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	char input_title[] = "input image";
	char output_title[] = "median filter image";

	cv::namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	cv::namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	cv::imshow(input_title, src);

	cv::medianBlur(src, dst, 3);
	cv::imshow(output_title, dst);

	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/medianblur_image.png", dst);

	cv::Mat bilater;
	cv::bilateralFilter(src, bilater, 15, 150, 3);
	cv::imshow("bilateral filter image", bilater);

	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/bilateral_image.jpg", bilater);

	
	cv::waitKey(0);
	return 0;
}

