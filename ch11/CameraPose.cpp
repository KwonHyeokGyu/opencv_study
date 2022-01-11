//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//#include <opencv2/viz.hpp>
//#include <opencv2/calib3d.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main() {
//	Mat image = imread("../../images/bench2.jpg");
//
//	namedWindow("Original Image");
//	imshow("Original Image", image);
//
//	// 입력 객체 점
//	vector<Point3f> objectPoints;
//	objectPoints.push_back(Point3f(0, 45, 0));
//	objectPoints.push_back(Point3f(242.5, 45, 0));
//	objectPoints.push_back(Point3f(242.5, 21, 0));
//	objectPoints.push_back(Point3f(0, 21, 0));
//	objectPoints.push_back(Point3f(0, 9, -9));
//	objectPoints.push_back(Point3f(242.5, 9, -9));
//	objectPoints.push_back(Point3f(242.5, 9, 44.5));
//	objectPoints.push_back(Point3f(0, 9, 44.5));
//	
//
//	// 입력 영상 점
//	vector<Point2f> imagePoints;
//	imagePoints.push_back(Point2f(136, 113));
//	imagePoints.push_back(Point2f(379, 114));
//	imagePoints.push_back(Point2f(379, 150));
//	imagePoints.push_back(Point2f(138, 135));
//	imagePoints.push_back(Point2f(143, 146));
//	imagePoints.push_back(Point2f(381, 166));
//	imagePoints.push_back(Point2f(345, 194));
//	imagePoints.push_back(Point2f(103, 161));
//
//	// Draw image points
//	for (int i = 0; i < 8; i++) {
//		cv::circle(image, imagePoints[i], 3, cv::Scalar(0, 0, 0), 2);
//	}
//	imshow("An image of a bench", image);
//	viz::Viz3d visualizer("Viz window");
//
//
//	//// 2D/3D 점으로부터 카메라 포즈 얻기
//	//Mat rvec, tvec;
//	//solvePnP(objectPoints, imagePoints,			// 대응하는 2D/3D 점
//	//		 cameraMatrix, cameraDistCoeffs,	// 보정
//	//		 rvec, tvec);
//
//	//// 3D 회전 행렬로 변환
//	//Mat rotation;
//	//Rodrigues(rvec, rotation);
//
//	waitKey();
//	return 0;
//}
