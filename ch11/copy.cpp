//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/features2d.hpp>
//
//using namespace cv;
//using namespace std;
//
//class CameraCalibrator {
//	// 입력 점은 세계 좌표에 있음
//	vector<vector<Point3f>> objectPoints;
//
//	// 화소 단위인 점 위치
//	vector<vector<Point2f>> imagePoints;
//
//	// 결과 행렬
//	Mat cameraMatrix;
//	Mat distCoeffs;
//
//
//	// 보정 완료 여부를 지정하는 플래그
//	int flag;
//
//	// 체스판 영상을 연 후에 코너 점 추출
//	int CameraCalibrator::addChessboardPoints(
//		const vector<string>& filelist,	// 파일명 목록
//		Size& boardSize) {				// 체스판 크기 보정
//
//		// 체스판 위의 점
//		vector<Point2f> imageCorners;
//		vector<Point3f> objectCorners;
//
//		// 3D 장면 점 :
//		// 체스판 참조 영상에서 체스판 코너 초기화
//		// 코너의 3D 위치 (X, Y, Z) = (i, j, 0)
//		for (int i = 0; i < boardSize.height; i++) {
//			for (int j = 0; j < boardSize.width; j++) {
//				objectCorners.push_back(Point3f(i, j, 0.0f));
//			}
//		}
//
//		// 2D 영상 점 :
//		Mat image;	// 체스판 영상을 포함하기 위해
//		int successes = 0;
//
//		// 모든 시점마다
//		for (int i = 0; i < filelist.size(); i++) {
//			// 영상 열기
//			image = imread(filelist[i], 0);
//
//			// 체스판 코너 얻기
//			bool found = findChessboardCorners(image,				// 체스판 패턴 영상
//				boardSize,			// 패턴 크기
//				imageCorners);		// 검출한 코너 목록
//
//// 코너 위의 부화소 정확도 얻기
//			if (found) {
//				cornerSubPix(image, imageCorners,
//					Size(5, 5),		// 탐색 윈도우의 절반크기
//					Size(-1, -1),
//					TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 30,	// 반복 최대 개수
//						0.1)); // 최소 정확도
//
//			// 좋은 체스판이 있다면 데이터에 추가
//				if (imageCorners.size() == boardSize.area()) {
//					// 영상과 한 시점의 장면 점 추가
//					addPoints(imageCorners, objectCorners);
//					successes++;
//				}
//			}
//			return successes;
//		}
//
//		// 카메라 보정
//		// 재투영 오차 반환
//		double CameraCalibrator::calibrate(Size & imageSize)
//		{
//			// 회전과 이동 결과
//			vector<Mat> rvecs, tvecs;
//
//			// 보정 시작
//			return calibrateCamera(objectPoints,	// 3D 점
//				imagePoints,		// 영상 점
//				imageSize,			// 영상 크기
//				cameraMatrix,		// 결과 카메라 행렬
//				distCoeffs,			// 결과 왜곡 행렬
//				rvecs, tvecs,		// Rs, Ts
//				flag);				// 옵션 설정
//		}
//
//		// 영상에서 왜곡 제거 (보정한 후)
//		Mat CameraCalibrator::remap(const Mat & image) {
//			Mat undistorted;
//
//			if (mustInitUndistort) {	// 보정할 때마다 호출
//				initUndistortRectifyMap(
//					cameraMatrix,		// 계산된 카메라 행렬
//					distCoeffs,			// 게산된 왜곡 행렬
//					Mat(),				// 선택 사항인 수정(아무것도 없음)
//					Mat(),				// 보정하기 위한 카메라 행렬
//					image.size(),		// 보정 크기
//					CV_32FC1,			// 결과 맵의 타입
//					map1, map2);		// x과 y 매핑 함수
//
//				mustInitUndistort = false;
//			}
//			// 매핑 함수 적용
//			remap(image, undistorted, map1, map2, INTER_LINEAR);	// 보간 타입
//
//			return undistorted;
//		}
//	}
//};