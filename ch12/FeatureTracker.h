//#include <iostream>
//#include <vector>
//#include <opencv2/opencv.hpp>
//#include "VideoProcessor.h"
//
//using namespace cv;
//
//class FeatureTracker : public FrameProcessor {
//	Mat gray;			// 현재 그레이레벨 영상
//	Mat gray_prev;		// 이전 그레이레벨 영상
//
//	// 0에서 추적된 점이면 1로
//	std::vector<Point2f> points[2];
//
//	// 추적된 점의 초기 위치
//	std::vector<Point2f> initial;
//	std::vector<Point2f> features;	// 검출한 특징
//	int max_count;					// 검출을 위한 특징의 최대 개수
//	double qlevel;					// 특징 검출을 위한 품질 수준
//	double minDist;					// 두 점 간의 최소 거리
//	std::vector<uchar> status;		// 추적한 점의 상태
//	std::vector<float> err;			// 추적 오류
//
//public:
//	FeatureTracker() : max_count(500), qlevel(0.01), minDist(10.0) {}
//
//	void process(Mat& frame, Mat& output) {
//		// 그레이레벨 영상으로 변환
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		frame.copyTo(output);
//
//		// 1. 새로운 특징점을 추가해야 한다면
//		if (addNewPoints()) {
//			// 특징점 검출
//			detectFeaturePoints();
//
//			// 검출한 특징점을 현재 추적된 특징에 추가
//			// the currently tracked features
//			points[0].insert(points[0].end(), features.begin(), features.end());
//			initial.insert(initial.end(), features.begin(), features.end());
//		}
//
//		// 시퀀스의 첫 번째 영상에 대해
//		if (gray_prev.empty())
//			gray.copyTo(gray_prev);
//
//		// 2. 특징 추적
//		calcOpticalFlowPyrLK(gray_prev, gray,	// 2개의 연속 영상
//							 points[0],			// 첫 번째 영상에서 입력 점 위치
//							 points[1],			// 두 번재 영상에서 결과 점 위치
//							 status,			// 추적 성공
//							 err);				// 추적 오류
//
//		// 3. 일부 특징점을 제외하기 위해 추적한 특징점을 순회
//		int k = 0;
//		for (int i = 0; i < points[1].size(); i++) {
//			// 이 특징점을 유지하는가?
//			if (accepTrackedPoint(i)) {
//				// 벡터에 이 특징점을 유지
//				initial[k] = initial[i];
//				points[1][k++] = points[1][i];
//			}
//		}
//
//		// 실패한 특징점을 제거
//		points[1].resize(k);
//		initial.resize(k);
//
//		// 4. 받아들인 추적한 점 처리
//		handleTrackedPoints(frame, output);
//		
//		// 5. 현재 위치와 영상은 이전 위치와 이전 영상이 됨
//		std::swap(points[1], points[0]);
//		swap(gray_prev, gray);
//	}
//
//	// 특징점 검출
//	void detectFeaturePoints() {
//		// 특징점 검출
//		goodFeaturesToTrack(gray,		// 영상
//							features,	// 결과인 검출된 특징
//							max_count,	// 특징의 최대 개수
//							qlevel,		// 품질 수준
//							minDist);	// 두 특징점 간의 최소 거리
//	}
//
//	// 새로운 특징점을 추가할지 결정
//	bool addNewPoints() {
//		//특징점이 너무 적다면
//		return points[0].size() <= 10;
//	}
//
//	// 추적한 특징점을 받아들일지 결정
//	bool accepTrackedPoint(int i) {
//		return status[i] &&		// 점 i를 추적할 수 없을 경우 status[i]가 false임
//			// 특징점이 이동했다면
//			(abs(points[0][i].x - points[1][i].x) 
//			+ (abs(points[0][i].y - points[1][i].y)) > 2);
//	}
//
//	// 현재 추적한 점 처리
//	void handleTrackedPoints(Mat& frame, Mat& output) {
//		// 모든 추적한 점에 대해
//		for (int i = 0; i < points[1].size(); i++) {
//			// 선과 원 그리기
//			line(output,
//				initial[i],		// 초기 위치
//				points[1][i],	// 새로운 위치
//				Scalar(255, 255, 255));
//
//			circle(output, points[1][i], 3,	Scalar(255, 255, 255), -1);
//		}
//	}
//};