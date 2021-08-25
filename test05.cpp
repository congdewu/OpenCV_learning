#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	cv::Mat src1, src2, dst;
	src1 = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	src2 = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/rc.jpg");
	if (!src1.data)
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	if (!src2.data)
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	double alpha = 0.5;
	if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type())
	{
		cv::addWeighted(src1, alpha, src2, (1.0 - alpha), 0.0, dst);

		cv::imshow("shiprock", src1);
		cv::imshow("rc", src2);
		cv::namedWindow("blend demo", cv::WINDOW_AUTOSIZE);
		cv::imshow("blend demo", dst);
		cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/blend_image.jpg", dst);
	}
	else
	{
		cout << "could not blend images,the size of images is not same..." << endl;
		return -1;
	}

	
	cv::waitKey(0);
	return 0;
}