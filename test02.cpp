#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
#include<math.h>

int main(int argc, char** argv)
{
	cv::Mat src, dst;
	src = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	if (!src.data)
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	cv::namedWindow("input image", CV_WINDOW_AUTOSIZE);
	cv::imshow("input image", src);

	/*int cols = src.cols * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;
	dst = cv::Mat::zeros(src.size(), src.type());

	for (int row = 1; row < (rows - 1); row++)
	{
		const uchar* current = src.ptr<uchar>(row);
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++)
		{
			output[col] = cv::saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		}
	}*/

	//上面注释掉的代码功能可由以下的 filter2D 函数功能实现
	//仅需两行代码即可实现以上代码块功能

	double t = cv::getTickCount();

	cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cv::filter2D(src, dst, src.depth(), kernel);

	double timeconsume = (cv::getTickCount() - t) / cv::getTickFrequency();
	cout << "time consume " << timeconsume <<"s" << endl;

	cv::namedWindow("contrast image demo", cv::WINDOW_AUTOSIZE);
	cv::imshow("contrast image demo", dst);
	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/contrast_image.jpg", dst);


	cv::waitKey(0);

	return 0;
}