// File name: read_button.cpp
// Made by joshua Gillespie 11/30/21
// this is a CGI application
// This application reads a pushbutton on GPIO1_14
//


#include <iostream> // for the input/output
#include <stdlib.h> // for the getenv call
#include <string>

#include <sys/sysinfo.h> // for the system uptime call
#include <cgicc/Cgicc.h> // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "GPIO.h"



using namespace exploringBB;
using namespace std;
using namespace cgicc;

int main()
{
	GPIO button(46);

	try{
		Cgicc cgi;

		// Send HTTP header
		cout << HTTPHTMLHeader() << endl;

		// Set up the HTML document
		cout << html() << endl;
		cout << head(title("Homework 10 problem 2")) << endl;
		cout << body() << endl;
		cout << h1("CPE 422/522 Reading a Pushbutton as Digital Input") << endl;
		cout << h1("Reading a Pushbutton on gpio46 via a Web Browser") << endl;

		cout << "<form action=\"/cgi-bin/read_button.cgi\" method=\"POST\">" << endl;
		cout << "<div> <input type = \"submit\" value =\"Read Button\"> </div>" << endl;
		cout << "</form>" << endl;
		cout << h1("Pushbutton State") << endl;


		//push button state
		if (button.getValue()==0)
			cout << "<h2>Button Pressed</h2>" << endl;
		else 
			cout << "<h3>Button Not Pressed</h3>" << endl;

		// Close the HTML document
		cout << body() << html();
	}
	catch(exception& e) {
		cout << "Error!";
		// handle any errors - omitted for brevity
	}
}
