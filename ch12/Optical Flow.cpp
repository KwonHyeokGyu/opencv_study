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
//// ���� ���� ��Ƽ�� �÷ο� �׸���
//void drawOpticalFlow(const Mat& oflow,		// ��Ƽ�� �÷ο�
//					 Mat& flowImage,		// ���� ����
//					 int stride,			// ���͸� ǥ���ϱ� ���� ��Ʈ���̵�
//					 float scale,			// ���� ���� ����
//					 const Scalar& color)	// ������ �÷�
//{
//	// �ʿ��ϸ� ���� ����
//	if (flowImage.size() != oflow.size()) {
//		flowImage.create(oflow.size(), CV_8UC3);
//		flowImage = Vec3i(255, 255, 255);
//	}
//
//	// ��� ���͸� ������� ��Ʈ���̵带 �ܰ�� ���
//	for (int y = 0; y < oflow.rows; y += stride) {
//		for (int x = 0; x < oflow.cols; x += stride) {
//			// ���� ���
//			Point2f vector = oflow.at<Point2f>(y, x);
//
//			// �� �׸���
//			line(flowImage, Point(x, y),
//				Point(static_cast<int>(x + scale * vector.x + 0.5),
//					  static_cast<int>(y + scale * vector.y + 0.5)),
//				color);
//
//			// ȭ�� ǥ�� �� �׸���
//			circle(flowImage, Point(static_cast<int>(x + scale * vector.x + 0.5),
//									static_cast<int>(y + scale * vector.y + 0.5)), 
//									1, color, -1);
//		}
//	}
//}
//
//int main() {
//	// ���� ����
//	Mat frame1 = imread("../../images/goose/goose230.bmp", 0);
//	Mat frame2 = imread("../../images/goose/goose237.bmp", 0);
//
//	// �� ���� ��ġ��
//	Mat combined(frame1.rows, frame1.cols + frame2.cols, CV_8U);
//	frame1.copyTo(combined.colRange(0, frame1.cols));
//	frame2.copyTo(combined.colRange(frame1.cols, frame1.cols + frame2.cols));
//	imshow("Frames", combined);
//
//	// ��Ƽ�� �÷ο� �˰��� ����
//	Ptr<superres::DualTVL1OpticalFlow> tvl1 = cv::superres::createOptFlow_DualTVL1();
//
//	Mat oflow;	// 2D ��Ƽ�� �÷ο� ������ ����
//
//	// frame1�� frame2 ���� ��Ƽ�� �÷ο� ���
//	tvl1->calc(frame1, frame2, oflow);
//
//	// ��Ƽ�� �÷ο� ���� �׸���
//	Mat flowImage;
//
//	drawOpticalFlow(oflow,				// �Է� ��Ƽ�� �÷ο� ����
//					flowImage,			// ���� ����
//					8,					// 8���� ȭ�Ҹ��� ���� ǥ��
//					2,					// ������ ũ��� 2�� ����
//					Scalar(0, 0, 0));	// ������ �÷�
//	
//	imshow("Optical flow", flowImage);
//
//	// �� ������ ���� �� �ε巯�� ��Ƽ�� ���ο츦 ����Ѵ�.
//	tvl1->setLambda(0.02);
//	tvl1->calc(frame1, frame2, oflow);
//
//	Mat flowImage2;
//
//	drawOpticalFlow(oflow,				// �Է� ��Ƽ�� �÷ο� ����
//		flowImage2,			// ���� ����
//		8,					// 8���� ȭ�Ҹ��� ���� ǥ��
//		2,					// ������ ũ��� 2�� ����
//		Scalar(0, 0, 0));	// ������ �÷�
//
//	imshow("Smoother Optical flow", flowImage2);
//
//	waitKey();
//	return 0;
//}