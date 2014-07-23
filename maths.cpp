#include "maths.h"


//--------------------------------------------------------------
void maths::setup(){
	math1.setup();
	mat2.setup();
	mat3.setup();
	mat4.setup();
	mat5.setup();

	mati1.setup();
	mati2.setup();
	mati3.setup();
	mati4.setup();
	mati5.setup();

	mata1.setup();
	mata2.setup();
	mata3.setup();
	mata4.setup();
	mata5.setup();

}

//--------------------------------------------------------------
void maths::update(bool mbeg, bool mIntr, bool mAdv, int mCounter, bool clicked){
	beg = mbeg;
	intr = mIntr;
	adv = mAdv;
	Counter = mCounter;
	if (beg)
	{
		switch(Counter)
		{
			case 0 :
				math1.update();
				break;
			case 1:
				mat2.update();
				break;
			case 2 :
				mat3.update();
				break;
			case 3:
				mat4.update();
				break;
			case 4 :
				mat5.update();
				break;
		}
	}
	else if(intr){
				switch(Counter)
		{
			case 0 :
				mati1.update();
				break;
			case 1:
				mati2.update();
				break;
			case 2 :
				mati3.update();
				break;
			case 3:
				mati4.update();
				break;
			case 4 :
				mati5.update();
				break;
		}
	
	}else if(adv){
		
switch(Counter)
		{
			case 0 :
				mata1.update();
				break;
			case 1:
				mata2.update();
				break;
			case 2 :
				mata3.update();
				break;
			case 3:
				mata4.update();
				break;
			case 4 :
				mata5.update();
				break;
		}
	
	}
		
}

//--------------------------------------------------------------
void maths::draw(){
	if (beg){
		switch(Counter)
		{
			case 0 :
				math1.draw();
				
				break;
			case 1:
				mat2.draw();
				break;
			case 2 :
				mat3.draw();
				break;
			case 3 :
				mat4.draw();
				break;
			case 4 :
				mat5.draw();
				break;
			}
	}
	else if(intr)
	{
	switch(Counter)
		{
			case 0 :
				mati1.draw();
				
				break;
			case 1:
				mati2.draw();
				break;
			case 2 :
				mati3.draw();
				break;
			case 3 :
				mati4.draw();
				break;
			case 4 :
				mati5.draw();
				break;
			}
	}else if(adv)
	{
	switch(Counter)
		{
			case 0 :
				mata1.draw();
				
				break;
			case 1:
				mata2.draw();
				break;
			case 2 :
				mata3.draw();
				break;
			case 3 :
				mata4.draw();
				break;
			case 4 :
				mata5.draw();
				break;
			}
	
	}
}









