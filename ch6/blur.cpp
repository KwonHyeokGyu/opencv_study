//#include <stdio.h>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//
//int main() {
//	cv::Mat image = cv::imread("C:/Users/lge/Desktop/OpenCV/images/boldt.jpg");
//
//	cv::namedWindow("Original Image");
//	cv::imshow("Original Image", image);
//
//	cv::Mat result;
//	
//	cv::blur(image, result, cv::Size(5, 5));
//
//	cv::namedWindow("Mean filtered Image");
//	cv::imshow("Mean filtered Image", result);
//
//	cv::waitKey();
//	return 0;
//}