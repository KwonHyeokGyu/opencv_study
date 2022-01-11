//#include "CameraCalibrator.h"
//
//// 체스판 영상을 연 후에 코너 점 추출
//int CameraCalibrator::addChessboardPoints(
//	const vector<string>& filelist, // list of filenames containing board images
//	Size& boardSize,                     // size of the board
//	string windowName) {                 // name of window to display results
//											  // if null, no display shown
//	// 체스판 위의 점
//	vector<Point2f> imageCorners;
//	vector<Point3f> objectCorners;
//
//	// 3D 장면 점 :
//	// 체스판 참조 영상에서 체스판 코너 초기화
//	// 코너의 3D 위치(X,Y,Z)= (i,j,0)
//	for (int i = 0; i < boardSize.height; i++) {
//		for (int j = 0; j < boardSize.width; j++) {
//
//			objectCorners.push_back(Point3f(i, j, 0.0f));
//		}
//	}
//
//	// 2D 영상 점 :
//	Mat image; // 체스판 영상을 포함하기 위해
//	int successes = 0;
//
//	// 모든 시점마다.
//	for (int i = 0; i < filelist.size(); i++) {
//
//		// 영상 열기
//		image = imread(filelist[i], 0);
//
//		// 체스판 코너 얻기
//		bool found = findChessboardCorners(image,         // 체스판 패턴 영상
//										   boardSize,     // 패턴 크기
//										   imageCorners); // 검출한 코너 목록
//
//		// 코너 위의 부화소 정확도 얻기
//		if (found) {
//			cornerSubPix(image, imageCorners,
//				Size(5, 5), // 탐색 윈도우의 절반 크기
//				Size(-1, -1),
//				TermCriteria(TermCriteria::MAX_ITER +
//					TermCriteria::EPS, 30,		// 반복 최대 개수
//					0.1));  // 최소 정확도
//
//			// 좋은 체스판이 있다면 데이터에 추가
//			if (imageCorners.size() == boardSize.area()) {
//
//				// 영상과 한 시점의 장면 점 추가
//				addPoints(imageCorners, objectCorners);
//				successes++;
//			}
//		}
//
//		if (windowName.length() > 0 && imageCorners.size() == boardSize.area()) {
//
//			//Draw the corners
//			drawChessboardCorners(image, boardSize, imageCorners, found);
//			imshow(windowName, image);
//			waitKey(100);
//		}
//	}
//
//	return successes;
//}
//
//// Add scene points and corresponding image points
//void CameraCalibrator::addPoints(const vector<Point2f>& imageCorners, const vector<Point3f>& objectCorners) {
//
//	// 2D image points from one view
//	imagePoints.push_back(imageCorners);
//	// corresponding 3D scene points
//	objectPoints.push_back(objectCorners);
//}
//
//// 카메라 보정
//// 재투영 오차 반환
//double CameraCalibrator::calibrate(const Size imageSize)
//{
//	// undistorter must be reinitialized
//	mustInitUndistort = true;
//
//	// 회전 이동 결과
//	vector<Mat> rvecs, tvecs;
//
//	// 보정 시작
//	return
//		calibrateCamera(objectPoints, // 3D 점
//						imagePoints,  // 영상 점
//						imageSize,    // 영상 크기
//						cameraMatrix, // 결과 카메라 행렬
//						distCoeffs,   // 결과 왜곡 행렬
//						rvecs, tvecs, // Rs, Ts 
//						flag);        // 옵션 설정
////					,CV_CALIB_USE_INTRINSIC_GUESS);
//
//}
//
//// 영상에서 왜곡 제거(보정한 후)
//Mat CameraCalibrator::remap(const Mat& image, Size& outputSize) {
//
//	Mat undistorted;
//
//	if (outputSize.height == -1)
//		outputSize = image.size();
//
//	if (mustInitUndistort) { // 보정할 때마다 호출
//
//		initUndistortRectifyMap(
//			cameraMatrix,	// 계산된 카메라 행렬
//			distCoeffs,		// 계산된 왜곡 행렬
//			Mat(),			// 선택 사항인 수정(아무것도 없음)
//			Mat(),			// 보정하기 위한 카메라 행렬
//			outputSize,		// 보정 크기
//			CV_32FC1,		// 결과 맵의 타입
//			map1, map2);	// x과 y 매핑 함수
//
//		mustInitUndistort = false;
//	}
//
//	// 매핑함수 적용
//	remap(image, undistorted, map1, map2,
//		INTER_LINEAR); // 보간 타입
//
//	return undistorted;
//}
//
//
//// Set the calibration options
//// 8radialCoeffEnabled should be true if 8 radial coefficients are required (5 is default)
//// tangentialParamEnabled should be true if tangeantial distortion is present
//void CameraCalibrator::setCalibrationFlag(bool radial8CoeffEnabled, bool tangentialParamEnabled) {
//
//	// Set the flag used in calibrateCamera()
//	flag = 0;
//	if (!tangentialParamEnabled) flag += CV_CALIB_ZERO_TANGENT_DIST;
//	if (radial8CoeffEnabled) flag += CV_CALIB_RATIONAL_MODEL;
//}