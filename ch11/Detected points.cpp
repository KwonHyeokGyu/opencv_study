//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//int main() {
//	//Mat image = imread("chess1410.jpg");
//	Mat image = imread("../../images/chessboards/chessboard01.jpg");
//	if (!image.data) {
//		cout << "이미지 없음!" << endl;
//		return 0;
//	}
//
//	namedWindow("src");
//	imshow("src", image);
//
//	// 영상 점의 결과 벡터
//	vector<Point2f> imageCorners;
//
//	// 영상에서의 내부 코너 개수
//	Size boardSize(7, 5);
//
//	// 체스판 코너 얻기
//	bool found = findChessboardCorners(image,						// 체스판 패턴 영상
//									  boardSize,					// 패턴 크기
//									  imageCorners);				// 검출한 코너 목록
//
//	// 코너 그리기
//	drawChessboardCorners(image, boardSize, imageCorners, found);	// 찾았던 코너
//
//	namedWindow("Detected points");
//	imshow("Detected points", image);
//
//	waitKey();
//	return 0;
//}