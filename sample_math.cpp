#include "mati1.h"

//--------------------------------------------------------------
void testApp21::setup(){
	ofBackground(255);
	math1bg.loadImage("images/mati1.jpg");
	math1bg.resize(1024,768);
	  ofSetFrameRate(30);
	   ansCorrect = false;
	   bFirst = false;
}

//--------------------------------------------------------------
void testApp21::update(){

}

//--------------------------------------------------------------
void testApp21::draw(){
	ofSetColor(200);
	math1bg.draw(0,0);

    a.loadFont("4.ttf", 30);
	a.setLineHeight(18.0f);
	a.setLetterSpacing(1.037);

	b.loadFont("4.ttf", 17);
	b.setLineHeight(18.0f);
	b.setLetterSpacing(1.037);
	
	
	ofSetColor(255,255,255);
	a.drawString("True or false? -4 is a natural ",125, 135);
	a.drawString("number",125,200);

	ofNoFill(); //question
	ofRectRounded(120,75,700,150,5);
	//opa.draw(80,380);

	
	ofNoFill();
	ofRectRounded(150,300,250,80,5);

	ofNoFill();
	ofRectRounded(150,450,250,80,5);

	ofNoFill();
	ofRectRounded(150,600,250,80,5);
	
	

	ofNoFill(); //mainmenu
	ofRectRounded(15,7,80,40,5);
	b.drawString("Menu",20,33);

	ofNoFill(); //exit
	ofRectRounded(940,7,80,40,5);
	b.drawString("Exit",955,33);


	ofNoFill(); //back
	ofRectRounded(15,700,80,40,5);
	b.drawString("Back",20,723);


	ofNoFill(); //next
	ofRectRounded(940,700,80,40,5);
	b.drawString("Next",945,725);


	
	ofEnableAlphaBlending();
	//ofSetColor(255,255,0);
	a.drawString("False", 240, 350);
	a.drawString("True", 245, 505);
	a.drawString("Can't Tell", 185, 655);
	ofDisableAlphaBlending();
	 

	//for mouse click event
	if(!ansCorrect){
	   ofSetColor(255);
	   ofSetColor(255,0,0);
	   if(bFirst)
			a.drawString("Wrong", 475, 495);
	}

	else{
		ofSetColor(0,255,0);
		a.drawString("Correct", 485, 495);
     	//ofExit();
		//ofRunApp(new testApp21());
	}

}

//--------------------------------------------------------------
void testApp21::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp21::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp21::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp21::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp21::mousePressed(int x, int y, int button){

		if(x>150 && x<400 && y>300 && y<380)
	{
		if(!bFirst)
			bFirst  = true;    
		ansCorrect = true;
	}
	else
	{
		if(!bFirst)
			bFirst  = true;
		ansCorrect = false;
	}
		if(x>940 && x<1020 && y>7 && y<47)
		{
			ofExit();
		}

}





//--------------------------------------------------------------
void testApp21::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp21::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp21::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp21::dragEvent(ofDragInfo dragInfo){ 

}
