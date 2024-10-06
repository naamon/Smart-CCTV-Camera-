#include "Logger.h"

std::shared_ptr<spdlog::logger> logger;

void initLogger() {
	logger = spdlog::stdout_color_mt("console_logger");
}
