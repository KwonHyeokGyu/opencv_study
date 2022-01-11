//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//#include "VideoProcessor.h"
//
//using namespace cv;
//
//class FeatureTracker : public FrameProcessor {
//	Mat gray;			// ���� �׷��̷��� ����
//	Mat gray_prev;		// ���� �׷��̷��� ����
//
//	// 0���� ������ ���̸� 1��
//	std::vector<Point2f> points[2];
//
//	// ������ ���� �ʱ� ��ġ
//	std::vector<Point2f> initial;
//	std::vector<Point2f> features;	// ������ Ư¡
//	int max_count;					// ������ ���� Ư¡�� �ִ� ����
//	double qlevel;					// Ư¡ ������ ���� ǰ�� ����
//	double minDist;					// �� �� ���� �ּ� �Ÿ�
//	std::vector<uchar> status;		// ������ ���� ����
//	std::vector<float> err;			// ���� ����
//
//public:
//	FeatureTracker() : max_count(500), qlevel(0.01), minDist(10.0) {}
//
//	void process(Mat& frame, Mat& output) {
//		// �׷��̷��� �������� ��ȯ
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		frame.copyTo(output);
//
//		// 1. ���ο� Ư¡���� �߰��ؾ� �Ѵٸ�
//		if (addNewPoints()) {
//			// Ư¡�� ����
//			detectFeaturePoints();
//
//			// ������ Ư¡���� ���� ������ Ư¡�� �߰�
//			// the currently tracked features
//			points[0].insert(points[0].end(), features.begin(), features.end());
//			initial.insert(initial.end(), features.begin(), features.end());
//		}
//
//		// �������� ù ��° ���� ����
//		if (gray_prev.empty())
//			gray.copyTo(gray_prev);
//
//		// 2. Ư¡ ����
//		calcOpticalFlowPyrLK(gray_prev, gray,	// 2���� ���� ����
//							 points[0],			// ù ��° ���󿡼� �Է� �� ��ġ
//							 points[1],			// �� ���� ���󿡼� ��� �� ��ġ
//							 status,			// ���� ����
//							 err);				// ���� ����
//
//		// 3. �Ϻ� Ư¡���� �����ϱ� ���� ������ Ư¡���� ��ȸ
//		int k = 0;
//		for (int i = 0; i < points[1].size(); i++) {
//			// �� Ư¡���� �����ϴ°�?
//			if (accepTrackedPoint(i)) {
//				// ���Ϳ� �� Ư¡���� ����
//				initial[k] = initial[i];
//				points[1][k++] = points[1][i];
//			}
//		}
//
//		// ������ Ư¡���� ����
//		points[1].resize(k);
//		initial.resize(k);
//
//		// 4. �޾Ƶ��� ������ �� ó��
//		handleTrackedPoints(frame, output);
//		
//		// 5. ���� ��ġ�� ������ ���� ��ġ�� ���� ������ ��
//		std::swap(points[1], points[0]);
//		swap(gray_prev, gray);
//	}
//
//	// Ư¡�� ����
//	void detectFeaturePoints() {
//		// Ư¡�� ����
//		goodFeaturesToTrack(gray,		// ����
//							features,	// ����� ����� Ư¡
//							max_count,	// Ư¡�� �ִ� ����
//							qlevel,		// ǰ�� ����
//							minDist);	// �� Ư¡�� ���� �ּ� �Ÿ�
//	}
//
//	// ���ο� Ư¡���� �߰����� ����
//	bool addNewPoints() {
//		//Ư¡���� �ʹ� ���ٸ�
//		return points[0].size() <= 10;
//	}
//
//	// ������ Ư¡���� �޾Ƶ����� ����
//	bool accepTrackedPoint(int i) {
//		return status[i] &&		// �� i�� ������ �� ���� ��� status[i]�� false��
//			// Ư¡���� �̵��ߴٸ�
//			(abs(points[0][i].x - points[1][i].x) 
//			+ (abs(points[0][i].y - points[1][i].y)) > 2);
//	}
//
//	// ���� ������ �� ó��
//	void handleTrackedPoints(Mat& frame, Mat& output) {
//		// ��� ������ ���� ����
//		for (int i = 0; i < points[1].size(); i++) {
//			// ���� �� �׸���
//			line(output,
//				initial[i],		// �ʱ� ��ġ
//				points[1][i],	// ���ο� ��ġ
//				Scalar(255, 255, 255));
//
//			circle(output, points[1][i], 3,	Scalar(255, 255, 255), -1);
//		}
//	}
//};