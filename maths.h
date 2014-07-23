#pragma once

#include "ofMain.h"
//--beg--
#include "../apps/myApps/ARapp/src/beg/math/math1/math1.h"
#include "../apps/myApps/ARapp/src/beg/math/mat2/mat2.h"
#include "../apps/myApps/ARapp/src/beg/math/mat3/mat3.h"
#include "../apps/myApps/ARapp/src/beg/math/mat4/mat4.h"
#include "../apps/myApps/ARapp/src/beg/math/mat5/mat5.h"

//---inter
#include "../apps/myApps/ARapp/src/int/mathi/mati1/mati1.h"
#include "../apps/myApps/ARapp/src/int/mathi/mati2/mati2.h"
#include "../apps/myApps/ARapp/src/int/mathi/mati3/mati3.h"
#include "../apps/myApps/ARapp/src/int/mathi/mati4/mati4.h"
#include "../apps/myApps/ARapp/src/int/mathi/mati5/mati5.h"

//--adv
#include "../apps/myApps/ARapp/src/adv/matha/mata1/mata1.h"
#include "../apps/myApps/ARapp/src/adv/matha/mata2/mata2.h"
#include "../apps/myApps/ARapp/src/adv/matha/mata3/mata3.h"
#include "../apps/myApps/ARapp/src/adv/matha/mata4/mata4.h"
#include "../apps/myApps/ARapp/src/adv/matha/mata5/mata5.h"



class maths
{
	public:
		void setup();
		void update(bool, bool, bool, int, bool);
		void draw();
	

		testApp16 math1;
		testApp17 mat2;
		testApp18 mat3;
		testApp19 mat4;
		testApp20 mat5;

		testApp21 mati1;
		testApp22 mati2;
		testApp23 mati3;
		testApp24 mati4;
		testApp25 mati5;

		testApp26 mata1;
		testApp27 mata2;
		testApp28 mata3;
		testApp29 mata4;
		testApp30 mata5;
		
		
private:
	int Counter;
	bool beg, adv, intr;
};

