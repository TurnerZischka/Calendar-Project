#ifndef __SUBTASK_HPP__
#define __SUBTASK_HPP__

#include <string>
#include <vector>

#include "../header/Moment.hpp"


class Subtask: public Moment {
   private:

   public:

	Subtask():Moment(){ //default constructor, intializes a blank subtask
	}

	Subtask(std::string titIn, std::string descIn, std::string catIn, int startIn, int endIn, int totIn, int priIn ):Moment(titIn,descIn, catIn, startIn, endIn, totIn, priIn ){
    }



};



#endif // __SUBTASK_HPP__