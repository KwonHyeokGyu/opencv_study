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
//	// ���� ó���� �ν��Ͻ� ����
//	VideoProcessor processor;
//
//	// Ư¡ ������ �ν��Ͻ� ����
//	FeatureTracker tracker;
//
//	// ���� ���� ����
//	processor.setInput("../../images/bike.avi");
//
//	// ������ ó���� ����
//	processor.setFrameProcessor(&tracker);
//
//	// ������ ǥ���ϴ� â ����
//	processor.displayOutput("Tracked Features");
//
//	// �� �����ӷ��� ���� ���
//	processor.setDelay(1000./processor.getFrameRate());
//
//	// ó�� ����
//	processor.run();
//
//	waitKey();
//}