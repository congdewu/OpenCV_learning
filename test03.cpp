#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	cv::Mat src;
	src = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
	cv::imshow("input", src);

	//创建了一个和 shiprock.jpg 大小相同的，自定义颜色背景的图像
	/*
	cv::Mat dst;
	dst = cv::Mat(src.size(), src.type());
	dst = cv::Scalar(255, 0, 255);
	cv::namedWindow("output", cv::WINDOW_AUTOSIZE);
	cv::imshow("output", dst);
	*/

	//拷贝图像，两张拷贝方式
	// 第一种
	//cv::Mat dst = src.clone();
	
	// 第二种
	//cv::Mat dst;
	//src.copyTo(dst);
	//cv::namedWindow("output", cv::WINDOW_AUTOSIZE);
	//cv::imshow("output", dst);
	
	//查看图像通道数
	cv::Mat dst;
	cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);

	cv::namedWindow("output", cv::WINDOW_AUTOSIZE);
	cv::imshow("output", dst);
	
	cout << "input image channels : " << src.channels() << endl;
	cout << "output image channels : " << dst.channels() << endl;

	int cols = dst.cols;
	int rows = dst.rows;
	cout << "rows : " << rows << " cols : " << cols << endl;
	const uchar* firstRow = dst.ptr<uchar>(100);
	cout << "first pixel value : " << (int)*firstRow << endl;

	cv::waitKey(0);
	return 0;
}