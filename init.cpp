#include "init.hpp"

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace cv;

bool init(const int &argc, const char** argv, CvCapture* capture, CascadeClassifier &faceCascade){
	capture= cvCaptureFromCAM(0);
	if(!initArgs(argc,argv,faceCascade))
		return -1;

	if(!initCapture(capture))
		return -1;

	return 0;
}

bool initArgs(const int &argc, const char** argv, CascadeClassifier &faceCascade){
	if(faceCascade.load(DEF_CLASSIFIER))
		return 0;
	else return -1;
}

bool initCapture(CvCapture* capture){
	if(capture=cvCaptureFromCAM(0))
		return 0;
	else return -1;
}