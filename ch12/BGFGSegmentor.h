//#include <iostream>
//#include <iomanip>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include "VideoProcessor.h"
//
//using namespace cv;
//
//class BGFGSegmentor : public FrameProcessor {
//	Mat gray;				// 현재 그레이레벨 영상
//	Mat background;			// 축적된 배경
//	Mat backImage;			// 현재 배경 영상
//	Mat foreground;			// 전경 영상
//
//	// 배경 축적 시의 학습률
//	double learningRate;
//	int threshold;			// 전경 추출을 위한 경계값
//
//public:
//	void setThreshold(int t) {
//
//		threshold = t;
//	}
//
//	// 처리 메소드
//	void process(Mat& frame, Mat& output) {
//		// 그레이레벨 영상으로 변환
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//
//		// 첫 번째 프레임으로서 배경 초기화
//		if (background.empty())
//			gray.convertTo(background, CV_32F);
//
//		// 배경을 8U로 변환
//		background.convertTo(backImage, CV_8U);
//
//		// 영상과 배경 간의 차를 계산
//		absdiff(backImage, gray, foreground);
//
//		// 전경 영상에 경계 값 적용
//		cv::threshold(foreground, output, threshold, 255, THRESH_BINARY_INV);
//
//		// 배경 축적
//		// alpha*gray + (1-alpha)*background
//		accumulateWeighted(gray, background,
//							learningRate,		// alpha
//							output);			// 마스크
//	}
//};