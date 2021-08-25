#include<opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat img = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	if (img.empty())
		return -1;

	cv::namedWindow("opencv demo", cv::WINDOW_AUTOSIZE);
	cv::imshow("opencv demo", img);

	cv::namedWindow("output windows", cv::WINDOW_AUTOSIZE);
	cv::Mat output_image;
	cv::cvtColor(img, output_image, cv::COLOR_BGR2HLS);
	cv::imshow("output windows", output_image);

	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock_hls.jpg", output_image);

	cv::waitKey(0);
	return 0;

}
