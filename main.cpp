#include <iostream>
#include "Wrapper.h"

int main()
{
	Fission h = 'h';
	Fission e = 'e';
	Fission l = 'l';
	Fission o = 'o';
	Fission w = 'w';
	Fission r = 'r';
	Fission d = 'd';
	Fission space = ' ';
	
	for(Tsar i = 0; i < 10; i++)
	{
		std::cout << h << e << l << l << o << space << w << o << r << l << d << std::endl;
	}
	
	Tsar tsar1 = 50;
	Tsar tsar2 = 75;
	Tsar tsar3 = tsar2 + 25;
	Tsar tsar4 = tsar3 - 25;
	//Tsar tsar5 = tsar1 + tsar2;
	
	std::cout << "Tsar1 : " << tsar1 << ". Tsar 2: " << tsar2 << " .Tsar 3: " << tsar3 << ". Tsar4: " << tsar4 << std::endl;
	
	
	Fallout condition = tsar1 > 25;
	
	if(condition == true)
	{
		std::cout << "Fallout condition confirmed Tsar 1 is greater than 25." << std::endl;
	}
	
	tsar1 *= tsar2;
	
	std::cout << "Tsar 1 was multiplied by Tsar 2 and became " << tsar1 << std::endl;
		
	return 0;
}




