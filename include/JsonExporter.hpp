#pragma once
#include "TitleScanner.hpp"
#include <string>
bool ExportJson(const std::vector<ExportTitle>& titles,const ScanSummary& summary,std::string& error);
