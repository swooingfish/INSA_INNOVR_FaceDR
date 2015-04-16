#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

//Include here all headers needed
#include "init.hpp"
#include "detection.hpp"

using namespace std;
using namespace cv;

//main program, no code must be written here except function calls
//and variables
int main(int argc, char** argv)
{
	CvCapture* capture;
	CascadeClassifier faceCascade;
	vector<Mat> faces;
	Mat frame;
	faceCascade.load(DEF_CLASSIFIER);
	capture= cvCaptureFromCAM(0);

	if(init(argc,(const char**)argv,capture,faceCascade))
		return 3;

	while(1){
		detectFaces(capture,faceCascade,faces);
        for(int i=0;i<faces.size();i++) imshow("face "+i,faces[i]);
    }

	cout << "Succesfully exiting ..." << endl;
	return 0;
}
