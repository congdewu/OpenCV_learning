#include<opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat img1, img2;
	cv::namedWindow("example1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("example2", cv::WINDOW_AUTOSIZE);

	img1 = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	cv::imshow("example1", img1);

	//使用cv::pyrDown() 创建一个新的图像，其宽高均为原始图像的一半
	cv::pyrDown(img1, img2);
	cv::imshow("example2", img2);

	cv::waitKey(0);
	return 0;
}