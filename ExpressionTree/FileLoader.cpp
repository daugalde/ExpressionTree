#include "Node.h"
#include <iostream>
#include <fstream>
#include "FileLoader.h"
#include <string>

using namespace std;

int FileLoader::LoadFiles() {
	int countLoadedFiles = 0;

	PointerNode newList = NULL;
	for (int i=0; i < 5; i++) {
		string fileId = to_string(i + 1);
		std::string str;
		std::ifstream file(("Arch" + fileId + ".txt"));

		while (!file.eof()) {
			std::getline(file, str);
			if (newList == NULL)
			{
				newList = new Node(str);
			}
			else {
				PointerNode aux = newList;

				while (aux->NextNode != NULL) {
					aux = aux->NextNode;
				}
				aux->NextNode = new Node(str);
/*
				newList = new Node(str, newList);*/
			}
		}

		files.Push(newList);
		newList = NULL;
		countLoadedFiles = i;
	}
	
	return countLoadedFiles;
}

List FileLoader::GetListToProcess() {
	return List(files.Pop());
}