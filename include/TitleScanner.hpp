#pragma once
#include <3ds.h>
#include <cstdint>
#include <string>
#include <vector>
struct ExportTitle { uint64_t titleId=0; uint64_t size=0; uint16_t version=0; std::string mediaType; std::string kind; std::string parentTitleId; };
struct ScanSummary { uint32_t nandCount=0, sdCount=0, gameCardCount=0; std::vector<std::string> errors; };
bool ScanTitles(std::vector<ExportTitle>& titles, ScanSummary& summary);
