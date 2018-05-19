#include "includes.hpp"
#include "Cities.hpp"
#include "CVP.hpp"

int main()
{
	srand(time(NULL));
	CVP cvp;
	cvp.CreatePath(); 

	return 0;
}