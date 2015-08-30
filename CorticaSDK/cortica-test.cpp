/*
* Author: Kiveisha Yevgeniy
* Copyright (c) 2015 Intel Corporation.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include "include\Cortica.h"

int
main(int argc, char ** argv) {
	Cortica* api = Cortica::GetApi(CORTICAPI_PROVIDER_CLOUD);
	api->initializeDB();

	RGBImage data;
	data.ImageURL = "http://media.cmgdigital.com/shared/img/photos/2012/08/13/7f/f8/slideshow_782633_carmarket0310c.JPG";
	vector<Tag> tags = api->matchingSync(&data);

	for (vector<Tag>::iterator item = tags.begin(); item != tags.end(); ++item) {
		std::cout << (*item).Name << std::endl;
	}

	std::cout << "Exit 'cortica-test'" << std::endl;
	return 0;
}