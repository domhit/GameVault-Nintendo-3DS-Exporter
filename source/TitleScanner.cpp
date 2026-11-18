// SPDX-License-Identifier: MIT
#include "TitleScanner.hpp"
#include <cstdio>
#include <vector>
namespace {
std::string Hex16(u64 id){char b[17];std::snprintf(b,sizeof(b),"%016llX",static_cast<unsigned long long>(id));return b;}
std::string Media(FS_MediaType m){return m==MEDIATYPE_NAND?"NAND":m==MEDIATYPE_SD?"SD":"GAME_CARD";}
std::string Kind(u64 id){u32 hi=static_cast<u32>(id>>32);if(hi==0x00040000)return"GAME";if(hi==0x0004000E)return"UPDATE";if(hi==0x0004008C)return"DLC";if((hi&0xFFFF0000)==0x00048000)return"DSIWARE_OR_TWL";if((hi&0xFFFF0000)==0x00040100)return"SYSTEM";return"OTHER";}
std::string Parent(u64 id,const std::string&kind){if(kind!="UPDATE"&&kind!="DLC")return Hex16(id);u64 low=id&0xFFFFFFFFULL;return Hex16((0x00040000ULL<<32)|low);}
bool ScanMedia(FS_MediaType media,std::vector<ExportTitle>&out,uint32_t&countOut,std::vector<std::string>&errors){u32 count=0;Result rc=AM_GetTitleCount(media,&count);if(R_FAILED(rc)){char b[96];std::snprintf(b,sizeof(b),"AM_GetTitleCount %s: 0x%08lX",Media(media).c_str(),static_cast<unsigned long>(rc));errors.emplace_back(b);return false;}countOut=count;if(!count)return true;std::vector<u64>ids(count);u32 read=0;rc=AM_GetTitleList(&read,media,count,ids.data());if(R_FAILED(rc)){char b[96];std::snprintf(b,sizeof(b),"AM_GetTitleList %s: 0x%08lX",Media(media).c_str(),static_cast<unsigned long>(rc));errors.emplace_back(b);return false;}ids.resize(read);std::vector<AM_TitleEntry> info(read);rc=AM_GetTitleInfo(media,read,ids.data(),info.data());if(R_FAILED(rc)){char b[96];std::snprintf(b,sizeof(b),"AM_GetTitleInfo %s: 0x%08lX",Media(media).c_str(),static_cast<unsigned long>(rc));errors.emplace_back(b);return false;}for(const auto&e:info){ExportTitle t;t.titleId=e.titleID;t.size=e.size;t.version=e.version;t.mediaType=Media(media);t.kind=Kind(t.titleId);t.parentTitleId=Parent(t.titleId,t.kind);out.push_back(std::move(t));}return true;}
}
bool ScanTitles(std::vector<ExportTitle>&titles,ScanSummary&s){titles.clear();s={};bool ok=true;ok=ScanMedia(MEDIATYPE_NAND,titles,s.nandCount,s.errors)&&ok;ok=ScanMedia(MEDIATYPE_SD,titles,s.sdCount,s.errors)&&ok;ok=ScanMedia(MEDIATYPE_GAME_CARD,titles,s.gameCardCount,s.errors)&&ok;return ok;}
