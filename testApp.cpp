#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	subject = 0;
	counter = 0;
	page2.setup();
	beg = false;
	adv = false;
	inter = false;
	mClicked = false;
	ansCorrect = false;
	delayCounter = 0;
	clickDone = false;   
	clickedOutside = false;
	ofLogToFile("myLogFile.txt", true);

	eng.setup();   //--------setup eng,mat,bio,geo,sci
	math.setup();
	bio.setup();
	geo.setup();
	sci.setup();


    a.loadFont("1.ttf", 30);
	a.setLineHeight(18.0f);
	a.setLetterSpacing(1.037);
	
	
	b.loadFont("1.ttf", 15);
	b.setLineHeight(18.0f);
	b.setLetterSpacing(1.037);
	
}

//----------------------------------------------------------------
void testApp::update(int px, int py, bool clicked){
	mClicked = clicked;
	if(mClicked){
		mClicked = false;
		laserClicked(px, py); // added for laser
		gameLogic();
	}
	
	if (!(!beg && !adv && !inter))
	{
		if(beg)
		{
			switch(subject)   //UPDATED THE RESPECTIVE SUBJECTS
			{
				case 0 : //english subject 
					eng.update(beg , inter, adv, counter, mClicked);
					break;

				case 1: //math subject
					math.update(beg , inter, adv, counter, mClicked);
			        break;

				case 2: //bio subject
					bio.update(beg , inter, adv, counter, mClicked);
					break;

				case 3://geo subject
					geo.update(beg , inter, adv, counter, mClicked);
					break;

				case 4://sci sub
					sci.update(beg , inter, adv, counter, mClicked);
					break;

				default:
					break;
			}
        }
		else if(inter)
		{
           switch(subject)   //UPDATED THE RESPECTIVE SUBJECTS
			{
				case 0 : //english subject 
					eng.update(beg , inter, adv, counter, mClicked);
					break;

				case 1: //math subject
					math.update(beg , inter, adv, counter, mClicked);
			        break;

				case 2: //bio subject
					bio.update(beg , inter, adv, counter, mClicked);
					break;

				case 3://geo subject
					geo.update(beg , inter, adv, counter, mClicked);
					break;

				case 4://sci sub
					sci.update(beg , inter, adv, counter, mClicked);
					break;

				default:
					break;
		       }
		}
		else if(adv)
		{
		switch(subject)   //UPDATED THE RESPECTIVE SUBJECTS
			{
				case 0 : //english subject 
					eng.update(beg , inter, adv, counter, mClicked);
					break;

				case 1: //math subject
					math.update(beg , inter, adv, counter, mClicked);
			        break;

				case 2: //bio subject
					bio.update(beg , inter, adv, counter, mClicked);
					break;

				case 3://geo subject
					geo.update(beg , inter, adv, counter, mClicked);
					break;

				case 4://sci sub
					sci.update(beg , inter, adv, counter, mClicked);
					break;

				default:
					break;
		       }
		}

//---------------------------------DELAY COUNTER----------------------------
		if(delayCounter>10){ //for delay between pages
			delayCounter = 0;
			if(counter<5)
			{
				counter++;
				clickDone = false;
			}
			else if(counter>=5)
			{
				subject++;
				counter=0;
				clickDone = false;
			}
		}else
			delayCounter++;
	}
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	if (!(!beg && !adv && !inter)){
		
		if(beg|| inter ||adv)
		{
			switch(subject)
			{
//----------------------------------ENGLISH-------------------
			case 0 : // english subject
				eng.draw();

				if(!clickedOutside){
					if(clickDone){
						if(ansCorrect)  
						{
							ofSetColor(0,255,0);
							a.drawString("Correct", 350, 495);
						}
						else{
							ofSetColor(255,0,0);
							a.drawString("Wrong", 345, 495);
						}
					}
				}else{
					ofSetColor(255,0,0);
					b.drawString("Please click inside the Options", 300, 725);
				}
				break;
//-----------------------------------------MATH-------------------------------
			case 1: //math subject
				   math.draw();
					if(!clickedOutside){
					if(clickDone){
						if(ansCorrect)  
						{
							ofSetColor(0,255,0);
							a.drawString("Correct", 475, 495);
						}
						else{
							ofSetColor(255,0,0);
							a.drawString("Wrong", 475, 495);
						}
					}
				}else{
					ofSetColor(255,0,0);
					b.drawString("Please click inside the Options", 300, 725);
				}
				break;
//------------------------------BIOLOGY-------------------------------------
			case 2: //biology subject
				   bio.draw();
					if(!clickedOutside){
					if(clickDone){
						if(ansCorrect)  
						{
							ofSetColor(0,255,0);
							a.drawString("Correct", 425, 305);
						}
						else{
							ofSetColor(255,0,0);
							a.drawString("Wrong", 425, 305);
						}
					}
				}else{
					ofSetColor(255,0,0);
					b.drawString("Please click inside the Options", 300, 725);
				}
				break;

//--------------------------------GEOGRAPHY----------------------------------
			case 3: //geography subject
				 geo.draw();
					if(!clickedOutside){
					if(clickDone){
						if(ansCorrect)  
						{
							ofSetColor(0,255,0);
							a.drawString("Correct", 425, 305);
						}
						else{
							ofSetColor(255,0,0);
							a.drawString("Wrong", 425, 305);
						}
					}
				}else{
					ofSetColor(255,0,0);
					b.drawString("Please click inside the Options", 300, 725);
				}
				break;
							
//---------------------------------SCIENCE----------------------------------
				case 4: //science subject
				 sci.draw();
					if(!clickedOutside){
					if(clickDone){
						if(ansCorrect)  
						{
							ofSetColor(0,255,0);
							a.drawString("Correct", 435, 305);
						}
						else{
							ofSetColor(255,0,0);
							a.drawString("Wrong", 435, 305);
						}
					}
				}else{
					ofSetColor(255,0,0);
					b.drawString("Please click inside the Options", 300,725);
				}
				break;

//----------------------------------endings--------------------------------
			default:
				break;
			}
        }
	}
	else{
		page2.draw();
	    }
	     
}


//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	xLoc = x;
	yLoc = y;
//-------------------from main menu to check beg,inter or adv----------
	if(!beg&&!adv&&!inter){
		if(x>700 && x<950 && y>145 && y<220){
				beg = true;
				adv = false;
				inter = false;
		
		}else if(x>700 && x<950 && y>295 && y<375){
				beg = false;
				inter = true;
				adv = false;
		
		}
		else if(x>700 && x<950 && y>445 && y<525){
				beg =false ;
				inter = false;
				adv = true;
		}
	}else{
		mClicked = true;
	}
	if(x>940 && x<1020 && y>7 && y<47)
	{
		ofExit();
	}

}

void testApp::laserClicked(int x, int y){ 
	xLoc = x;
	yLoc = y;
	//-------------------from main menu to check beg,inter or adv----------
	if(!beg&&!adv&&!inter){
		if(x>700 && x<950 && y>145 && y<220){
				beg = true;
				adv = false;
				inter = false;
		
		}else if(x>700 && x<950 && y>295 && y<375){
				beg = false;
				inter = true;
				adv = false;
		
		}
		else if(x>700 && x<950 && y>445 && y<525){
				beg =false ;
				inter = false;
				adv = true;
		}
	}
	if(x>940 && x<1020 && y>7 && y<47)
	{
		ofExit();
	}

}


void testApp::gameLogic(){
	clickDone = true;
	if (!(!beg && !adv && !inter))
	{
//------------------------------------BEGINNER--------------------------
//------------------------------------BEGINNER--------------------------
//------------------------------------BEGINNER--------------------------
		if(beg)
		{
			switch(subject)
			{
//------------------------------------Beginner ENGLISH-----------------
			case 0 : //for english
				ans=engLogic();
				switch (counter)
				{
				case 0: //question 1 of beg eng
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg eng
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg eng
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg eng
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg eng
					if (ans==1)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
					
				} //end counter switch
				break;
//-----------------------------Beginner MATH-------------------------------			
					 
				case 1:   //for math  
				ans=mathLogic();
				switch (counter)
				{
				case 0: //question 1 of beg math
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg math
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg math
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg math
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg math
					if (ans==2)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;
//-----------------------------Beginner BIOLOGY-------------------------------	
				case 2: //biology subject
				ans=bioLogic();
				switch (counter)
				{
				case 0: //question 1 of beg bio
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg bio
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg bio
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg bio
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg bio
					if (ans==2)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
					
				} //end counter switch

				break;

//-----------------------------Beginner GEO-------------------------------	
				case 3: 
					ans=geoLogic();
				switch (counter)
				{
				case 0: //question 1 of beg geo
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg geo
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg geo
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg geo
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg geo
					if (ans==3)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;
					

//-----------------------------Beginner SCIENCE-------------------------------	
				case 4: //science subject
				ans=sciLogic();
				switch (counter)
				{
				case 0: //question 1 of beg science 
					if (ans==4)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg science 
					if (ans==4)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg science 
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg science 
					if (ans==4)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg science 
					if (ans==1)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;	

//------------ENDINGS OF SUBJECT SWITCH-------------------------------			
				default: //default of subject switch
				break;
             }//end of subject switch
		}//end if if(beg)

//-----------------------------INTERMEDIATE------------------------------
//-----------------------------INTERMEDIATE------------------------------
//-----------------------------INTERMEDIATE------------------------------

		else if(inter){
			switch(subject)
			{
					case 0 : //for english
				ans=engLogic();
				switch (counter)
				{
				case 0: //question 1 of inter eng
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of inter eng
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of inter eng
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of inter eng
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of inter eng
					if (ans==2)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
					
				} //end counter switch
				break;
//-----------------------------Inter MATH-------------------------------			
					 
				case 1:   //for math  
				ans=mathLogic();
				switch (counter)
				{
				case 0: //question 1 of inter math
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg math
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg math
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg math
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg math
					if (ans==2)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;
//----------------------------Inter BIOLOGY-------------------------------	
				case 2: //biology subject
				ans=bioLogic();
				switch (counter)
				{
				case 0: //question 1 of beg bio
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg bio
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg bio
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg bio
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg bio
					if (ans==3)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
					
				} //end counter switch

				break;

//-----------------------------Inter GEO-------------------------------	
				case 3: 
					ans=geoLogic();
				switch (counter)
				{
				case 0: //question 1 of beg geo
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg geo
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg geo
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg geo
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg geo
					if (ans==2)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;
					

//-----------------------------Inter SCIENCE-------------------------------	
				case 4: //science subject
				ans=sciLogic();
				switch (counter)
				{
				case 0: //question 1 of beg science 
					if (ans==4)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg science 
					if (ans==4)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg science 
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg science 
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg science 
					if (ans==2)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;

//------------ENDINGS OF SUBJECT SWITCH-------------------------------			
				default: //default of subject switch
				break;
             }//end of subject switch
		}//end if if(beg)
//------------------------------ADVANCED------------------------------
//------------------------------ADVANCED------------------------------
//------------------------------ADVANCED------------------------------
		else if(adv)
		{
			switch(subject)
			{
//------------------------------------Adv ENGLISH-----------------
			case 0 : //for english
				ans=engLogic();
				switch (counter)
				{
				case 0: //question 1 of beg eng
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg eng
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg eng
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg eng
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg eng
					if (ans==3)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
					
				} //end counter switch
				break;
//-----------------------------ADV MATH-------------------------------			
					 
				case 1:   //for math  
				ans=mathLogic();
				switch (counter)
				{
				case 0: //question 1 of beg math
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg math
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg math
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg math
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg math
					if (ans==1)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;
//-----------------------------ADV BIOLOGY-------------------------------	
				case 2: //biology subject
				ans=bioLogic();
				switch (counter)
				{
				case 0: //question 1 of beg bio
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg bio
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg bio
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg bio
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg bio
					if (ans==1)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
					
				} //end counter switch

				break;

//----------------------------ADV GEO-------------------------------	
				case 3: 
					ans=geoLogic();
				switch (counter)
				{
				case 0: //question 1 of beg geo
					if (ans==1)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg geo
					if (ans==3)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg geo
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg geo
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg geo
					if (ans==1)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;
					

//----------------------------ADV SCIENCE-------------------------------	
				case 4: //science subject
				ans=sciLogic();
				switch (counter)
				{
				case 0: //question 1 of beg science 
					if (ans==4)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
						clickedOutside = false;
					}
					break;

				case 1: //question 2 of beg science 
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 2: //question 3 of beg science 
					if (ans==2)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 3: //question 4 of beg science 
					if (ans==4)
					{
						clickedOutside = false;
						ansCorrect = true;
					}else if(ans == 0){
						clickedOutside = true;
					}else{
						ansCorrect = false;
					}
					break;

				case 4: //question 5 of beg science 
					if (ans==1)
					{
						ansCorrect = true;
					}else{
						ansCorrect = false;
					}
					break;
				
				default: //default of counter switch
					ansCorrect = false;
					break;
				}
				break;	

//------------ENDINGS OF SUBJECT SWITCH-------------------------------			
				default: //default of subject switch
				break;
             }//end of subject switch
		}//end if if(beg)


//---------------------------------ending of game logic
}
}

//------------------------ENGLISH LOGIC-------------------------------------
int testApp::engLogic(){ 
	    
	    //coordinates of english boxes
		if(xLoc>525 && xLoc<775 && yLoc>300 && yLoc<380) 
			return 1;

		else if(xLoc>525 && xLoc<775 && yLoc>450 && yLoc<530)
			return 2;

		else if(xLoc>525 && xLoc<775 && yLoc>600 && yLoc<680)
			return 3;

		else
			return 0;

}

//--------------------------MATH LOGIC------------------------------------

int testApp::mathLogic(){
	 //coordinates of math boxes
		if(xLoc>150 && xLoc<400 && yLoc>300 && yLoc<380) 
			return 1;

		if(xLoc>150 && xLoc<400 && yLoc>450 && yLoc<530) 
			return 2;

		if(xLoc>150 && xLoc<400 && yLoc>600 && yLoc<680) 
			return 3;

		else
			return 0;


}

//--------------------------BIO LOGIC------------------------------------
int testApp::bioLogic(){
	//coordinate of bio boxes
		if(xLoc>75 && xLoc<325 && yLoc>375 && yLoc<725) 
			return 1;

		if(xLoc>380 && xLoc<630 && yLoc>375 && yLoc<725) 
			return 2;

		if(xLoc>680 && xLoc<930 && yLoc>375 && yLoc<725) 
			return 3;

		else
			return 0;

}


//--------------------------GEO LOGIC------------------------------------
int testApp::geoLogic(){
	//coodrdinates of geo boxes
			if(xLoc>75 && xLoc<325 && yLoc>375 && yLoc<725) 
			return 1;

		if(xLoc>380 && xLoc<630 && yLoc>375 && yLoc<725) 
			return 2;

		if(xLoc>680 && xLoc<930 && yLoc>375 && yLoc<725) 
			return 3;

		else
			return 0;

}

//--------------------------SCIENCE LOGIC------------------------------------
int testApp::sciLogic(){
	//coordinates of science boxes
		if(xLoc>65 && xLoc<265 && yLoc>475 && yLoc<555) 
			return 1;

		if(xLoc>375 && xLoc<575 && yLoc>475 && yLoc<555) 
			return 2;

		if(xLoc>65 && xLoc<265 && yLoc>600 && yLoc<680) 
			return 3;

		if(xLoc>375 && xLoc<575 && yLoc>600 && yLoc<680) 
			return 4;

		else
			return 0;
}


//----------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
