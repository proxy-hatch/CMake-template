

#include <iostream>


extern "C"
{
#include "rs232.h"
#include <stdlib.h> // atoi() because somehow std::stoi() is not supported on ARM gcc
}


int main() {
	
	const int CPORT_NUM = 16;   // number for /dev/ttymxc2 in rs232.h
	
	// attempt to open por
	if (RS232_OpenComport(CPORT_NUM, 115200, "8N1")) {
		std::cerr << "Can not open comport\n";
		return 1;
	}
	
	unsigned char buf[4095];
	const char *constBuf = reinterpret_cast<const char *>(buf);
	while (1) {
		int n = RS232_PollComport(CPORT_NUM, buf, 4095);
		std::cout << "reading";
		if (n > 0) {
			buf[n] = '\0';   /* always put a "null" at the end of a string! */
			
			for (int i = 0; i < n; i++) {
				if (buf[i] < 32)  // replace unreadable control-codes by dots
				{
					buf[i] = '.';
				}
			}
			RS232_cputs(CPORT_NUM, constBuf);
			std::cout << "Echoed " << n << " bytes: " << buf << "\n";
		}
	}
	
	return 0;

}


//
//// just some function to have something that can be test
//#include <exception>
//
//	void TestFunc() {
//		throw std::string("InvalidOperation: Just kidding");
//	}