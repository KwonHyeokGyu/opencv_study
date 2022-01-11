//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/bgsegm.hpp>
//#include "BGFGSegmentor.h"
//
//int main() {
//	// ���� ���� ����
//	VideoCapture capture("../../images/bike.avi");
//
//	// ������ ���������� �������� Ȯ��
//	if (!capture.isOpened())
//		return 0;
//
//	// ���� ���� ������
//	Mat frame;
//
//	// ���� ���� ����
//	Mat foreground;
//	namedWindow("Extracted Foreground(MOG2)");
//
//	// ��� �⺻ �Ķ���͸� ����� ����þ� ȥ�� ��ü
//	Ptr<BackgroundSubtractor> pMOG2;
//	pMOG2 = createBackgroundSubtractorMOG2();
//	//BackgroundSubtractorMOG2 mog;
//	bool stop(false);
//
//	// ������ ��� �����Ӹ���
//	while (!stop) {
//		// ���� �������� �ִٸ� �б�
//		if (!capture.read(frame))
//			break;
//
//		// ����� ������ �� ���� ��ȯ
//		//mog(frame, foreground, 0.01);
//		pMOG2->apply(frame, foreground);
//
//		// �н���
//		// ���� ����
//		threshold(foreground, foreground, 128, 255, THRESH_BINARY_INV);
//
//		// ���� �����ֱ�
//		imshow("Extracted Foreground(MOG2)", foreground);
//
//		// ������ �����ϰų� �����ϱ� ���� Ű �Է�
//		if (waitKey(10) >= 0)
//			stop = true;
//	}
//
//
//
//	// ���� ó���� �ν��Ͻ� ����
//	VideoProcessor processor;
//
//	// ���/���� ���ұ� ����
//	BGFGSegmentor segmentor;
//	segmentor.setThreshold(25);
//
//	// ���� ���� ����
//	processor.setInput("../../images/bike.avi");
//
//	// ������ ó���� ����
//	processor.setFrameProcessor(&segmentor);
//
//	// ���� ǥ���ϴ� â ����
//	processor.displayOutput("Extracted Foreground");
//
//	// �� �����ӷ��� ���� ���
//	processor.setDelay(1000. / processor.getFrameRate());
//
//	// ó�� ����
//	processor.run();
//}