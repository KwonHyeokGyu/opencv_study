//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//int main() {
//	//Mat image = imread("chess1410.jpg");
//	Mat image = imread("../../images/chessboards/chessboard01.jpg");
//	if (!image.data) {
//		cout << "�̹��� ����!" << endl;
//		return 0;
//	}
//
//	namedWindow("src");
//	imshow("src", image);
//
//	// ���� ���� ��� ����
//	vector<Point2f> imageCorners;
//
//	// ���󿡼��� ���� �ڳ� ����
//	Size boardSize(7, 5);
//
//	// ü���� �ڳ� ���
//	bool found = findChessboardCorners(image,						// ü���� ���� ����
//									  boardSize,					// ���� ũ��
//									  imageCorners);				// ������ �ڳ� ���
//
//	// �ڳ� �׸���
//	drawChessboardCorners(image, boardSize, imageCorners, found);	// ã�Ҵ� �ڳ�
//
//	namedWindow("Detected points");
//	imshow("Detected points", image);
//
//	waitKey();
//	return 0;
//}