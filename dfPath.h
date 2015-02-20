#ifndef DFPATH_H
#define DFPATH_H
#include <string>
using namespace std;
/*
*
* Functions defined here do the following: Create default directory for saving studys
*                                          Check if file alredy exists
*                                          Add more stuff,
* I am not shure if this will be an object or something different, but I will write couple of functions just to test stuff around
*
*/

string GetFileNameAndLocation();

string DefaultDirectory();

// Function: fileExists
/**
    Check if a file exists
@param[in] filename - the name of the file to check

@return    true if the file exists, else false

*/
bool fileExists(const std::string& filename);

#endif // DFPATH_H


