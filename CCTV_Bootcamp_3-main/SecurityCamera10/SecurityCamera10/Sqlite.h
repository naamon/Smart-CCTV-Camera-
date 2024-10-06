#pragma once
#include "pch.h"
#include "Detection.h"
#include "sqlite3.h"

using namespace std;

int saveToDB(const Detection& detection, double avgR, double avgG, double avgB);