#ifndef __Task_HPP__
#define __Task_HPP__

#include <string>
#include <vector>


class Subtask: public Moment {
   private:

   public:
	Subtask():Moment(){ //default constructor, intializes a blank subtask
	   
	
	}

	Subtask(string titIn, string descIn, string catIn, double startIn, double endIn, double totIn, int priIn ):Moment(titIn,descIn, catIn, startIn, endIn, totIn, priIn ){


	}

	

};



#endif
