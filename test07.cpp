#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

cv::Mat bgImage;
const char* drawdemo_win = "draw shapes and text demo";
void MyLines();
void MyRectangle();
void MyEllipse();
void MyCircle();
void MyPolygon();
void RandomLineDemo();


int main(int argc, char** argv)
{
	bgImage = cv::imread("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/shiprock.jpg");
	if (!bgImage.data)
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	//MyLines();
	//MyRectangle();
	//MyEllipse();
	//MyCircle();
	//MyPolygon();

	//cv::putText(bgImage, "Hello OpenCV", cv::Point(300, 80), CV_FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(12, 255, 200), 2, 8);
	RandomLineDemo();

	//cv::namedWindow(drawdemo_win, CV_WINDOW_AUTOSIZE);
	//cv::imshow(drawdemo_win, bgImage);
	//cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/draw_image.jpg", bgImage);

	cv::waitKey(0);
	return 0;
}

void MyLines()
{
	cv::Point p1 = cv::Point(20, 30);
	cv::Point p2;
	p2.x = 300;
	p2.y = 300;
	cv::Scalar color = cv::Scalar(0, 0, 255);
	cv::line(bgImage, p1, p2, color, 2, cv::LINE_8);
}

void MyRectangle()
{
	cv::Rect rect = cv::Rect(110, 290, 280, 220);
	cv::Scalar color = cv::Scalar(255, 0, 255);
	cv::rectangle(bgImage, rect, color, 2, cv::LINE_8);
}

void MyEllipse()
{
	cv::Scalar color = cv::Scalar(0, 255, 255);
	cv::ellipse(bgImage, cv::Point(bgImage.cols / 2+50, bgImage.rows / 2), cv::Size(bgImage.cols / 4, bgImage.rows / 8), 60, 0, 360, color, 2, cv::LINE_8);
}

void MyCircle()
{
	cv::Scalar color = cv::Scalar(128, 0, 255);
	cv::Point center = cv::Point(bgImage.cols / 2 + 50, bgImage.rows / 2);
	cv::circle(bgImage, center, 120, color, 2, cv::LINE_8);
}

void MyPolygon()
{
	cv::Point pts[1][5];
	pts[0][0] = cv::Point(100, 100);
	pts[0][1] = cv::Point(100, 200);
	pts[0][2] = cv::Point(200, 200);
	pts[0][3] = cv::Point(200, 100);
	pts[0][4] = cv::Point(100, 100);

	const cv::Point* ppts[] = { pts[0] };
	int npt[5] = { 5 };
	cv::Scalar color = cv::Scalar(0, 255, 0);
	cv::fillPoly(bgImage, ppts, npt, 1, color, 8);
}

void RandomLineDemo()
{
	cv::Mat bg = cv::Mat::zeros(bgImage.size(), bgImage.type());
	cv::namedWindow("random line demo", cv::WINDOW_AUTOSIZE);

	cv::RNG rng(12345);
	cv::Point pt1;
	cv::Point pt2;

	for (int i = 0; i < 100000; i++)
	{
		pt1.x = rng.uniform(0, bgImage.cols);
		pt2.x = rng.uniform(0, bgImage.cols);
		pt1.y = rng.uniform(0, bgImage.rows);
		pt2.y = rng.uniform(0, bgImage.rows);

		cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

		if (cv::waitKey(50) > 0)
		{
			break;
		}
		cv::line(bg, pt1, pt2, color, 2, 8);
		cv::imshow("random line demo", bg);
	}
	cv::imwrite("C:/Users/RedwallBot/Desktop/Notes/OpenCV_learning/img/random_image.jpg", bg);
	
}