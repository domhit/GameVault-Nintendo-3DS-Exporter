#pragma once
#include <3ds.h>
#include <cstdint>
#include <string>
#include <vector>
struct ExportTitle {
 uint64_t titleId=0,size=0; uint16_t version=0; std::string mediaType,kind,subtype,parentTitleId;
 uint32_t titleCategory=0,uniqueId=0;
 bool smdhAvailable=false; std::string name,longDescription,publisher,region; uint32_t regionMask=0; int32_t smdhResult=0;
};
struct ScanSummary {
 uint32_t nandCount=0,sdCount=0,gameCardCount=0,smdhSuccess=0,smdhMissing=0;
 bool gameCardPresent=false; std::vector<std::string> errors;
};
bool ScanTitles(std::vector<ExportTitle>& titles,ScanSummary& summary);
