#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
#include<math.h>

int main(int argc, char** argv)
{
	cv::Mat src, gray_src;
	src = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	if (!src.data)
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	cv::namedWindow("input image", CV_WINDOW_AUTOSIZE);
	cv::imshow("input image", src);

	//cv::cvtColor(src, gray_src, cv::COLOR_BGR2GRAY);
	//cv::namedWindow("output image", CV_WINDOW_AUTOSIZE);
	//cv::imshow("output image", gray_src);

	//int height = gray_src.rows;
	//int width = gray_src.cols;

	////单通道
	//for (int row = 0; row < height; row++)
	//{
	//	for (int col = 0; col < width; col++)
	//	{
	//		int gray = gray_src.at<uchar>(row, col);
	//		gray_src.at<uchar>(row, col) = 255 - gray;
	//	}
	//}

	cv::Mat dst;
	dst.create(src.size(), src.type());
	int height1 = src.rows;
	int width1 = src.cols;
	int nc = src.channels();
	
	//单通道或多通道情况
	/*for (int row = 0; row < height1; row++)
	{
		for (int col = 0; col < width1; col++)
		{
			if (nc == 1) 
			{
				int gray = gray_src.at<uchar>(row, col);
				gray_src.at<uchar>(row, col) = 255 - gray;
			}
			else if (nc == 3)
			{
				int b = src.at<cv::Vec3b>(row, col)[0];
				int g = src.at<cv::Vec3b>(row, col)[1];
				int r = src.at<cv::Vec3b>(row, col)[2];
				dst.at<cv::Vec3b>(row, col)[0] = 255 - b;
				dst.at<cv::Vec3b>(row, col)[1] = 255 - g;
				dst.at<cv::Vec3b>(row, col)[2] = 255 - r;
			}
		}
	}*/

	//用位操作函数即可实现以上的像素值取反的操作
	cv::bitwise_not(src, dst);
	cv::namedWindow("output image", CV_WINDOW_AUTOSIZE);
	cv::imshow("output image", dst);
	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/pixel_image.jpg", dst);

	cv::waitKey(0);

	return 0;
}