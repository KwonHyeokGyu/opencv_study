//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/features2d.hpp>
//#include <opencv2/video/tracking.hpp>
//#include <opencv2/superres/optical_flow.hpp>
//#include "VideoProcessor.h"
//
//using namespace cv;
//
//// 영상 위에 옵티컬 플로우 그리기
//void drawOpticalFlow(const Mat& oflow,		// 옵티컬 플로우
//					 Mat& flowImage,		// 만든 영상
//					 int stride,			// 벡터를 표시하기 위한 스트라이드
//					 float scale,			// 벡터 곱셈 인자
//					 const Scalar& color)	// 벡터의 컬러
//{
//	// 필요하면 영상 생성
//	if (flowImage.size() != oflow.size()) {
//		flowImage.create(oflow.size(), CV_8UC3);
//		flowImage = Vec3i(255, 255, 255);
//	}
//
//	// 모든 벡터를 대상으로 스트라이드를 단계로 사용
//	for (int y = 0; y < oflow.rows; y += stride) {
//		for (int x = 0; x < oflow.cols; x += stride) {
//			// 벡터 얻기
//			Point2f vector = oflow.at<Point2f>(y, x);
//
//			// 선 그리기
//			line(flowImage, Point(x, y),
//				Point(static_cast<int>(x + scale * vector.x + 0.5),
//					  static_cast<int>(y + scale * vector.y + 0.5)),
//				color);
//
//			// 화살 표의 끝 그리기
//			circle(flowImage, Point(static_cast<int>(x + scale * vector.x + 0.5),
//									static_cast<int>(y + scale * vector.y + 0.5)), 
//									1, color, -1);
//		}
//	}
//}
//
//int main() {
//	// 영상 열기
//	Mat frame1 = imread("../../images/goose/goose230.bmp", 0);
//	Mat frame2 = imread("../../images/goose/goose237.bmp", 0);
//
//	// 두 영상 합치기
//	Mat combined(frame1.rows, frame1.cols + frame2.cols, CV_8U);
//	frame1.copyTo(combined.colRange(0, frame1.cols));
//	frame2.copyTo(combined.colRange(frame1.cols, frame1.cols + frame2.cols));
//	imshow("Frames", combined);
//
//	// 옵티컬 플로우 알고리즘 생성
//	Ptr<superres::DualTVL1OpticalFlow> tvl1 = cv::superres::createOptFlow_DualTVL1();
//
//	Mat oflow;	// 2D 옵티컬 플로우 벡터의 영상
//
//	// frame1과 frame2 간의 옵티컬 플로우 계산
//	tvl1->calc(frame1, frame2, oflow);
//
//	// 옵티컬 플로우 영상 그리기
//	Mat flowImage;
//
//	drawOpticalFlow(oflow,				// 입력 옵티컬 플로우 벡터
//					flowImage,			// 생성 영상
//					8,					// 8개의 화소마다 벡터 표시
//					2,					// 벡터의 크기와 2를 곱함
//					Scalar(0, 0, 0));	// 벡터의 컬러
//	
//	imshow("Optical flow", flowImage);
//
//	// 두 프레임 간의 더 부드러운 옵티컬 프로우를 계산한다.
//	tvl1->setLambda(0.02);
//	tvl1->calc(frame1, frame2, oflow);
//
//	Mat flowImage2;
//
//	drawOpticalFlow(oflow,				// 입력 옵티컬 플로우 벡터
//		flowImage2,			// 생성 영상
//		8,					// 8개의 화소마다 벡터 표시
//		2,					// 벡터의 크기와 2를 곱함
//		Scalar(0, 0, 0));	// 벡터의 컬러
//
//	imshow("Smoother Optical flow", flowImage2);
//
//	waitKey();
//	return 0;
//}