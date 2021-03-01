#ifndef __SUBTASK_HPP__
#define __SUBTASK_HPP__

#include <string>
#include <vector>

#include "../header/Moment.hpp"


class Subtask: public Moment {
   private:

   public:
	Subtask(std::string titIn, std::string descIn, std::string catIn, double startIn, double endIn, double totIn, int priIn ):Moment(titIn,descIn, catIn, startIn, endIn, totIn, priIn );

};



#endif
