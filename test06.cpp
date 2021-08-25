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
	
	char input_win[] = "input image";
	//cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
	cv::namedWindow(input_win, cv::WINDOW_AUTOSIZE);
	cv::imshow(input_win, src);

	//contrast and brightness changes
	int height = src.rows;
	int width = src.cols;
	dst = cv::Mat::zeros(src.size(), src.type());

	float alpha = 1.5;
	float beta = 10;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (src.channels() == 3)
			{
				float b = src.at<cv::Vec3b>(row, col)[0];
				float g = src.at<cv::Vec3b>(row, col)[1];
				float r = src.at<cv::Vec3b>(row, col)[2];

				dst.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(b * alpha + beta);
				dst.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(g * alpha + beta);
				dst.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(r * alpha + beta);
			}
			else if (src.channels() == 1)
			{
				float v = src.at<uchar>(row, col);
				dst.at<uchar>(row, col) = cv::saturate_cast<uchar>(v * alpha + beta);
			}
		}
	}

	char output_title[] = "contrast and brightness changes demo";
	cv::namedWindow(output_title, cv::WINDOW_AUTOSIZE);
	cv::imshow(output_title, dst);
	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/bright_image.jpg", dst);

	cv::waitKey(0);
	return 0;
}