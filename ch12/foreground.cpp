//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/bgsegm.hpp>
//#include "BGFGSegmentor.h"
//
//int main() {
//	// 비디오 파일 열기
//	VideoCapture capture("../../images/bike.avi");
//
//	// 비디오를 성공적으로 열었는지 확인
//	if (!capture.isOpened())
//		return 0;
//
//	// 현재 비디오 프레임
//	Mat frame;
//
//	// 전경 이진 영상
//	Mat foreground;
//	namedWindow("Extracted Foreground(MOG2)");
//
//	// 모든 기본 파라미터를 사용한 가우시안 혼합 객체
//	Ptr<BackgroundSubtractor> pMOG2;
//	pMOG2 = createBackgroundSubtractorMOG2();
//	//BackgroundSubtractorMOG2 mog;
//	bool stop(false);
//
//	// 비디오의 모든 프레임마다
//	while (!stop) {
//		// 다음 프레임이 있다면 읽기
//		if (!capture.read(frame))
//			break;
//
//		// 배경을 갱신한 후 전경 반환
//		//mog(frame, foreground, 0.01);
//		pMOG2->apply(frame, foreground);
//
//		// 학습률
//		// 영상 반전
//		threshold(foreground, foreground, 128, 255, THRESH_BINARY_INV);
//
//		// 전경 보여주기
//		imshow("Extracted Foreground(MOG2)", foreground);
//
//		// 지연을 도입하거나 중지하기 위해 키 입력
//		if (waitKey(10) >= 0)
//			stop = true;
//	}
//
//
//
//	// 비디오 처리기 인스턴스 생성
//	VideoProcessor processor;
//
//	// 배경/전경 분할기 생성
//	BGFGSegmentor segmentor;
//	segmentor.setThreshold(25);
//
//	// 비디오 파일 열기
//	processor.setInput("../../images/bike.avi");
//
//	// 프레임 처리기 설정
//	processor.setFrameProcessor(&segmentor);
//
//	// 비디오 표시하는 창 선언
//	processor.displayOutput("Extracted Foreground");
//
//	// 원 프레임률로 비디오 재생
//	processor.setDelay(1000. / processor.getFrameRate());
//
//	// 처리 시작
//	processor.run();
//}