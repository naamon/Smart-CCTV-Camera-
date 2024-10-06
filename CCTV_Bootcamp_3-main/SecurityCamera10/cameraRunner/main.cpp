#include "../SecurityCamera10/Logger.h"
#include "../SecurityCamera10/Camera.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
	initLogger();

	logger->info("start project in camera process!", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);

	// camera process 
	readVideo();

	return 0;
}