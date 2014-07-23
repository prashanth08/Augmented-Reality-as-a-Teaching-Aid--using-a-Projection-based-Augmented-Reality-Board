#include "page2.h"

//--------------------------------------------------------------
void testAppp2::setup(){
	ofBackground(255);
	myImage1.loadImage("images/ironmann.jpg");
	myImage1.resize(1024,768);

	


}

//--------------------------------------------------------------
void testAppp2::update(int x, int y, bool clicked){
	if(x>940 && x<1020 && y>7 && y<47)
		{
			if(clicked)
			ofExit();
		}
}

//--------------------------------------------------------------
void testAppp2::draw(){
  


	ofSetColor(255);
	myImage1.draw(0, 0);

	cooperBlack.loadFont("cooperBlack.ttf", 25);
	cooperBlack.setLineHeight(18.0f);
	cooperBlack.setLetterSpacing(1.037);

	cooperBlack1.loadFont("cooperBlack.ttf", 20);
	cooperBlack1.setLineHeight(18.0f);
	cooperBlack1.setLetterSpacing(1.037);

	cooperBlack2.loadFont("cooperBlack.ttf", 18);
	cooperBlack2.setLineHeight(18.0f);
	cooperBlack2.setLetterSpacing(1.037);
	
		
	bFirst  = true;

	ofEnableAlphaBlending();
	ofSetColor(255,255,0);
	cooperBlack.drawString("BEGINNER", 725, 200);
	cooperBlack1.drawString("INTERMEDIATE", 702, 350);
	cooperBlack.drawString("ADVANCED", 715, 500);
	cooperBlack.drawString("OPTIONS", 735, 650);
	ofDisableAlphaBlending();




	
	ofNoFill();
	ofRectRounded(700,145,250,80,5);

	ofNoFill();
	ofRectRounded(703,150,250,80,5);

	ofNoFill();
	ofRectRounded(700,295,250,80,5);

	ofNoFill();
	ofRectRounded(703,300,250,80,5);

	ofNoFill();
	ofRectRounded(700,445,250,80,5);

	ofNoFill();
	ofRectRounded(703,450,250,80,5);

	ofNoFill();
	ofRectRounded(700,595,250,80,5);

	//ofNoFill();
	ofRectRounded(703,600,250,80,5);

	ofNoFill(); //exit
	ofRectRounded(940,7,80,40,5);
	
	cooperBlack2.drawString("Exit",953,33);
	
    

}

//--------------------------------------------------------------
void testAppp2::keyPressed(int key){

}

//--------------------------------------------------------------
void testAppp2::keyReleased(int key){

}

//--------------------------------------------------------------
void testAppp2::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testAppp2::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testAppp2::mousePressed(int x, int y, int button){

	
		if(x>940 && x<1020 && y>7 && y<47)
		{
			ofExit();
		}

}

//--------------------------------------------------------------
void testAppp2::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testAppp2::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testAppp2::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testAppp2::dragEvent(ofDragInfo dragInfo){ 

}
