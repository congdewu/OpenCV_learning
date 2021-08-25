#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open( "C:/Users/RedwallBot/Desktop/1-ÐéÄâ·ÂÕæÈü.mp4");

	cv::Mat frame;
	for (;;)
	{
		cap >> frame;
		if (frame.empty())
			break;
		cv::imshow("example", frame);
		if (cv::waitKey(33) >= 0)
			break;
	}
	return 0;

}