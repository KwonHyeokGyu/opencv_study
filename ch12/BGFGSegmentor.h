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
//	Mat gray;				// ���� �׷��̷��� ����
//	Mat background;			// ������ ���
//	Mat backImage;			// ���� ��� ����
//	Mat foreground;			// ���� ����
//
//	// ��� ���� ���� �н���
//	double learningRate;
//	int threshold;			// ���� ������ ���� ��谪
//
//public:
//	void setThreshold(int t) {
//
//		threshold = t;
//	}
//
//	// ó�� �޼ҵ�
//	void process(Mat& frame, Mat& output) {
//		// �׷��̷��� �������� ��ȯ
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//
//		// ù ��° ���������μ� ��� �ʱ�ȭ
//		if (background.empty())
//			gray.convertTo(background, CV_32F);
//
//		// ����� 8U�� ��ȯ
//		background.convertTo(backImage, CV_8U);
//
//		// ����� ��� ���� ���� ���
//		absdiff(backImage, gray, foreground);
//
//		// ���� ���� ��� �� ����
//		cv::threshold(foreground, output, threshold, 255, THRESH_BINARY_INV);
//
//		// ��� ����
//		// alpha*gray + (1-alpha)*background
//		accumulateWeighted(gray, background,
//							learningRate,		// alpha
//							output);			// ����ũ
//	}
//};