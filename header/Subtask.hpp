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

    Subtask(std::string titIn) {
        setTitle(titIn);
        setClass("null");
    }

	Subtask(std::string titIn, std::string descIn, std::string catIn, int month, int date, int startIn, int endIn, int priIn, int inID ):Moment(titIn,descIn, catIn, month, date, startIn, endIn, priIn, inID ){
    }



};



#endif // __SUBTASK_HPP__
