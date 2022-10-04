#pragma once
#include <iostream>
#include <fstream>
#include "StaticQueue.h"

using namespace std;

class FileLoader {

private:
	StaticQueue files;

public:
	FileLoader() {	}

	int LoadFiles();

	List GetListToProcess();
};