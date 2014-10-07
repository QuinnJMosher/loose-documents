#include <cstdio>
#include <iostream>
#include <new>
#include <cstdlib>
#include <vector>

void* operator new ( size_t t, char* zFile, int nLine) {
	std::cout << zFile << " " << nLine << "\n";
	void *pAllocation = malloc(t);
	if (pAllocation) {
		//record_allocation(pAllocation, zFile, nLine);
	}
	return pAllocation;
}

void operator delete (void *p, char* zFile, int nLine) {
	//deallocate_from_list(p);
	free(p);
}

void operator delete (void *p) {
	//deallocate_from_list(p);
	free(p);
}

#ifdef _DEBUG
#define new new (__FILE__, __LINE__)
#endif

struct memLog {
	void *memLoc;
	char* fileLoc;
	int lineLoc;

	memLog(void *pAllocation, char* zFile, int nLine) {
		memLoc = pAllocation;
		fileLoc = zFile;
		lineLoc = nLine;
	}
};

struct memLogHandler {
	std::vector<memLog> memLogs;

	void record_allocation(void *pAllocation, char* zFile, int nLine) {
		memLogs.emplace_back(memLog(pAllocation, zFile, nLine));
	}
};

void main() {
	
}