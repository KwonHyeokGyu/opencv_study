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
//	// �Է� ���� ���� ��ǥ�� ����
//	vector<vector<Point3f>> objectPoints;
//
//	// ȭ�� ������ �� ��ġ
//	vector<vector<Point2f>> imagePoints;
//
//	// ��� ���
//	Mat cameraMatrix;
//	Mat distCoeffs;
//
//
//	// ���� �Ϸ� ���θ� �����ϴ� �÷���
//	int flag;
//
//	// ü���� ������ �� �Ŀ� �ڳ� �� ����
//	int CameraCalibrator::addChessboardPoints(
//		const vector<string>& filelist,	// ���ϸ� ���
//		Size& boardSize) {				// ü���� ũ�� ����
//
//		// ü���� ���� ��
//		vector<Point2f> imageCorners;
//		vector<Point3f> objectCorners;
//
//		// 3D ��� �� :
//		// ü���� ���� ���󿡼� ü���� �ڳ� �ʱ�ȭ
//		// �ڳ��� 3D ��ġ (X, Y, Z) = (i, j, 0)
//		for (int i = 0; i < boardSize.height; i++) {
//			for (int j = 0; j < boardSize.width; j++) {
//				objectCorners.push_back(Point3f(i, j, 0.0f));
//			}
//		}
//
//		// 2D ���� �� :
//		Mat image;	// ü���� ������ �����ϱ� ����
//		int successes = 0;
//
//		// ��� ��������
//		for (int i = 0; i < filelist.size(); i++) {
//			// ���� ����
//			image = imread(filelist[i], 0);
//
//			// ü���� �ڳ� ���
//			bool found = findChessboardCorners(image,				// ü���� ���� ����
//				boardSize,			// ���� ũ��
//				imageCorners);		// ������ �ڳ� ���
//
//// �ڳ� ���� ��ȭ�� ��Ȯ�� ���
//			if (found) {
//				cornerSubPix(image, imageCorners,
//					Size(5, 5),		// Ž�� �������� ����ũ��
//					Size(-1, -1),
//					TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 30,	// �ݺ� �ִ� ����
//						0.1)); // �ּ� ��Ȯ��
//
//			// ���� ü������ �ִٸ� �����Ϳ� �߰�
//				if (imageCorners.size() == boardSize.area()) {
//					// ����� �� ������ ��� �� �߰�
//					addPoints(imageCorners, objectCorners);
//					successes++;
//				}
//			}
//			return successes;
//		}
//
//		// ī�޶� ����
//		// ������ ���� ��ȯ
//		double CameraCalibrator::calibrate(Size & imageSize)
//		{
//			// ȸ���� �̵� ���
//			vector<Mat> rvecs, tvecs;
//
//			// ���� ����
//			return calibrateCamera(objectPoints,	// 3D ��
//				imagePoints,		// ���� ��
//				imageSize,			// ���� ũ��
//				cameraMatrix,		// ��� ī�޶� ���
//				distCoeffs,			// ��� �ְ� ���
//				rvecs, tvecs,		// Rs, Ts
//				flag);				// �ɼ� ����
//		}
//
//		// ���󿡼� �ְ� ���� (������ ��)
//		Mat CameraCalibrator::remap(const Mat & image) {
//			Mat undistorted;
//
//			if (mustInitUndistort) {	// ������ ������ ȣ��
//				initUndistortRectifyMap(
//					cameraMatrix,		// ���� ī�޶� ���
//					distCoeffs,			// �Ի�� �ְ� ���
//					Mat(),				// ���� ������ ����(�ƹ��͵� ����)
//					Mat(),				// �����ϱ� ���� ī�޶� ���
//					image.size(),		// ���� ũ��
//					CV_32FC1,			// ��� ���� Ÿ��
//					map1, map2);		// x�� y ���� �Լ�
//
//				mustInitUndistort = false;
//			}
//			// ���� �Լ� ����
//			remap(image, undistorted, map1, map2, INTER_LINEAR);	// ���� Ÿ��
//
//			return undistorted;
//		}
//	}
//};