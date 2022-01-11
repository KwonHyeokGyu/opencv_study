//#include <vector>
//#include <iostream>
//#include <opencv2/core.hpp>
//#include "opencv2/imgproc.hpp"
//#include "opencv2/calib3d.hpp"
//#include <opencv2/highgui.hpp>
//
//using namespace cv;
//using namespace std;
//
//class CameraCalibrator {
//
//    // 입력 점은 세게 좌표에 있음
//    vector<vector<Point3f> > objectPoints;
//
//    // 화소 단위인 점 위치
//    vector<vector<Point2f> > imagePoints;
//
//    // 결과 행렬
//    Mat cameraMatrix;
//    Mat distCoeffs;
//
//    // 보정 완료 여부를 지정하는 플래그
//    int flag;
//
//    // used in image undistortion 
//    Mat map1, map2;
//    bool mustInitUndistort;
//
//public:
//    CameraCalibrator() : flag(0), mustInitUndistort(true) {}
//
//    // Open the chessboard images and extract corner points
//    int addChessboardPoints(const vector<string>& filelist, 
//                            Size& boardSize, string windowName = "");
//
//    // Add scene points and corresponding image points
//    void addPoints(const vector<Point2f>& imageCorners, 
//                   const vector<Point3f>& objectCorners);
//
//    // Calibrate the camera
//    double calibrate(const Size imageSize);
//
//    // Set the calibration flag
//    void setCalibrationFlag(bool radial8CoeffEnabled = false, 
//                            bool tangentialParamEnabled = false);
//
//    // Remove distortion in an image (after calibration)
//    Mat remap(const Mat& image, Size& outputSize = Size(-1, -1));
//
//    // Getters
//    Mat getCameraMatrix() { return cameraMatrix; }
//    Mat getDistCoeffs() { return distCoeffs; }
//};