//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/features2d.hpp>
//#include <opencv2/video/tracking.hpp>
//#include "FeatureTracker.h"
//
//using namespace cv;
//
//int main() {
//	// 비디오 처리기 인스턴스 생성
//	VideoProcessor processor;
//
//	// 특징 추적기 인스턴스 생성
//	FeatureTracker tracker;
//
//	// 비디오 파일 열기
//	processor.setInput("../../images/bike.avi");
//
//	// 프레임 처리기 설정
//	processor.setFrameProcessor(&tracker);
//
//	// 비디오를 표시하는 창 선언
//	processor.displayOutput("Tracked Features");
//
//	// 원 프레임률로 비디오 재생
//	processor.setDelay(1000./processor.getFrameRate());
//
//	// 처리 시작
//	processor.run();
//
//	waitKey();
//}