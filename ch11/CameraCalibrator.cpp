//#include "CameraCalibrator.h"
//
//// ü���� ������ �� �Ŀ� �ڳ� �� ����
//int CameraCalibrator::addChessboardPoints(
//	const vector<string>& filelist, // list of filenames containing board images
//	Size& boardSize,                     // size of the board
//	string windowName) {                 // name of window to display results
//											  // if null, no display shown
//	// ü���� ���� ��
//	vector<Point2f> imageCorners;
//	vector<Point3f> objectCorners;
//
//	// 3D ��� �� :
//	// ü���� ���� ���󿡼� ü���� �ڳ� �ʱ�ȭ
//	// �ڳ��� 3D ��ġ(X,Y,Z)= (i,j,0)
//	for (int i = 0; i < boardSize.height; i++) {
//		for (int j = 0; j < boardSize.width; j++) {
//
//			objectCorners.push_back(Point3f(i, j, 0.0f));
//		}
//	}
//
//	// 2D ���� �� :
//	Mat image; // ü���� ������ �����ϱ� ����
//	int successes = 0;
//
//	// ��� ��������.
//	for (int i = 0; i < filelist.size(); i++) {
//
//		// ���� ����
//		image = imread(filelist[i], 0);
//
//		// ü���� �ڳ� ���
//		bool found = findChessboardCorners(image,         // ü���� ���� ����
//										   boardSize,     // ���� ũ��
//										   imageCorners); // ������ �ڳ� ���
//
//		// �ڳ� ���� ��ȭ�� ��Ȯ�� ���
//		if (found) {
//			cornerSubPix(image, imageCorners,
//				Size(5, 5), // Ž�� �������� ���� ũ��
//				Size(-1, -1),
//				TermCriteria(TermCriteria::MAX_ITER +
//					TermCriteria::EPS, 30,		// �ݺ� �ִ� ����
//					0.1));  // �ּ� ��Ȯ��
//
//			// ���� ü������ �ִٸ� �����Ϳ� �߰�
//			if (imageCorners.size() == boardSize.area()) {
//
//				// ����� �� ������ ��� �� �߰�
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
//// ī�޶� ����
//// ������ ���� ��ȯ
//double CameraCalibrator::calibrate(const Size imageSize)
//{
//	// undistorter must be reinitialized
//	mustInitUndistort = true;
//
//	// ȸ�� �̵� ���
//	vector<Mat> rvecs, tvecs;
//
//	// ���� ����
//	return
//		calibrateCamera(objectPoints, // 3D ��
//						imagePoints,  // ���� ��
//						imageSize,    // ���� ũ��
//						cameraMatrix, // ��� ī�޶� ���
//						distCoeffs,   // ��� �ְ� ���
//						rvecs, tvecs, // Rs, Ts 
//						flag);        // �ɼ� ����
////					,CV_CALIB_USE_INTRINSIC_GUESS);
//
//}
//
//// ���󿡼� �ְ� ����(������ ��)
//Mat CameraCalibrator::remap(const Mat& image, Size& outputSize) {
//
//	Mat undistorted;
//
//	if (outputSize.height == -1)
//		outputSize = image.size();
//
//	if (mustInitUndistort) { // ������ ������ ȣ��
//
//		initUndistortRectifyMap(
//			cameraMatrix,	// ���� ī�޶� ���
//			distCoeffs,		// ���� �ְ� ���
//			Mat(),			// ���� ������ ����(�ƹ��͵� ����)
//			Mat(),			// �����ϱ� ���� ī�޶� ���
//			outputSize,		// ���� ũ��
//			CV_32FC1,		// ��� ���� Ÿ��
//			map1, map2);	// x�� y ���� �Լ�
//
//		mustInitUndistort = false;
//	}
//
//	// �����Լ� ����
//	remap(image, undistorted, map1, map2,
//		INTER_LINEAR); // ���� Ÿ��
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