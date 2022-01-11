//#include <stdio.h>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//using namespace cv;
//
//int main() {
//	// 원본 영상
//	Mat image = imread("C:/Users/lge/Desktop/OpenCV/images/boldt.jpg");
//
//	namedWindow("Original Image");
//	imshow("Original Image", image);
//
//	// GaussianBlur 영상
//	Mat result;
//
//	GaussianBlur(image, result, Size(5, 5), 1.5);
//	
//	namedWindow("Gaussian filtered Image");
//	imshow("Gaussian filtered Image", result);
//	
//	// 원래크기를 4배로 축소한 영상 - 잘못된 예시
//	Mat image2 = imread("C:/Users/lge/Desktop/OpenCV/images/boldt.jpg", 0);
//	Mat reduced(image2.rows / 4, image2.cols / 4, CV_8U);
//	for (int i = 0; i < reduced.rows; i++) {
//		for (int j = 0; j < reduced.cols; j++) {
//			reduced.at<uchar>(i, j) = image2.at<uchar>(i * 4, j * 4);
//		}
//	}
//
//	// 정상크기
//	resize(reduced, reduced, Size(image.cols, image.rows));
//	
//	cv::namedWindow("Badly reduced Image");
//	cv::imshow("Badly reduced Image", reduced);
//
//	// 원래크기를 4배로 축소한 영상
//	// 고주파 성분 제거
//	GaussianBlur(image2, image2, cv::Size(11, 11), 2.0);
//	// 4화소마다 1화소만 유지
//	Mat reduced2(image2.rows / 4, image2.cols / 4, CV_8U);
//	for (int i = 0; i < reduced2.rows; i++) {
//		for (int j = 0; j < reduced2.cols; j++) {
//			reduced2.at<uchar>(i, j) = image2.at<uchar>(i * 4, j * 4);
//		}
//	}
//
//	resize(reduced2, reduced2, Size(image.cols, image.rows));
//
//	namedWindow("Reduced Image");
//	imshow("Reduced Image", reduced2);
//	
//	// pyrDown - 영상을 2배로 축소
//	Mat reducedImage;
//	pyrDown(image, reducedImage);
//	
//	namedWindow("pyrDown");
//	imshow("pyrDown", reducedImage);
//
//	// 영상 축소
//	Mat resizedImage;
//	resize(image, resizedImage, Size(image.cols / 4, image.rows / 4));
//
//	namedWindow("ResizedImage");
//	imshow("ResizedImage", resizedImage);
//
//	// 영상 축소
//	resize(image, resizedImage, Size(), 1.0 / 4.0, 1.0 / 4.0);
//
//	namedWindow("Resize Image");
//	imshow("Resize Image", resizedImage);
//
//	// 최근접 이웃 보간법
//	Mat newImage;
//	resize(reduced, newImage, Size(), 3, 3, INTER_NEAREST);
//
//	namedWindow("New Image");
//	imshow("New Image", newImage);
//
//	// 양선형 보간법
//	resize(reduced2, newImage, Size(), 3, 3, INTER_LINEAR);
//
//	namedWindow("Bilinear resizing");
//	imshow("Bilinear resizing", newImage);
//
//	// 중간 값 필터
//	medianBlur(image, result, 5);
//
//	namedWindow("Median filtered Image");
//	imshow("Median filtered Image", result);
//
//	// 중간 값 필터 - S&P noise
//	Mat image3 = imread("C:/Users/lge/Desktop/OpenCV/images/salted.bmp", 0);
//	medianBlur(image3, result, 5);
//
//	namedWindow("Median filtered S&P Image");
//	imshow("Median filtered S&P Image", result);
//
//	// 평균 값 필터 - S&P noise
//	blur(image3, result, Size(5, 5));
//
//	namedWindow("Mean filtered S&P Image");
//	imshow("Mean filtered S&P Image", result);
//	
//	cv::waitKey();
//	return 0;
//}