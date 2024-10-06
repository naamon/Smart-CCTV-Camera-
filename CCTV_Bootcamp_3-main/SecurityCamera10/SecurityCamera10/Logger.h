#pragma once
#include "spdlog/spdlog.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

extern std::shared_ptr<spdlog::logger> logger;
void initLogger();
