// SPDX-License-Identifier: MIT
#include "JsonExporter.hpp"
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <sys/stat.h>
constexpr const char* OUT="sdmc:/3ds/GameVault-3DS-Exporter/installed_titles.json";
constexpr const char* TMP="sdmc:/3ds/GameVault-3DS-Exporter/installed_titles.json.tmp";
namespace {void S(FILE*f,const std::string&v){fputc('"',f);for(unsigned char c:v){if(c=='"')fputs("\\\"",f);else if(c=='\\')fputs("\\\\",f);else if(c=='\n')fputs("\\n",f);else if(c<0x20)fprintf(f,"\\u%04X",c);else fputc(c,f);}fputc('"',f);}std::string H(uint64_t id){char b[17];snprintf(b,sizeof(b),"%016llX",(unsigned long long)id);return b;}}
bool ExportJson(const std::vector<ExportTitle>&v,const ScanSummary&s,std::string&e){e.clear();mkdir("sdmc:/3ds/GameVault-3DS-Exporter",0777);FILE*f=fopen(TMP,"wb");if(!f){e=std::string("fopen: ")+strerror(errno);return false;}fputs("{\n  \"schemaVersion\": 1,\n  \"exporter\": \"GameVault Nintendo 3DS Exporter\",\n  \"exporterVersion\": \"0.1.0-dev1\",\n  \"platform\": \"NINTENDO_3DS\",\n",f);fprintf(f,"  \"titleCount\": %u,\n  \"mediaCounts\": {\"NAND\":%u,\"SD\":%u,\"GAME_CARD\":%u},\n  \"titles\": [\n",(unsigned)v.size(),s.nandCount,s.sdCount,s.gameCardCount);for(size_t i=0;i<v.size();++i){auto&t=v[i];fputs("    {\"titleId\":",f);S(f,H(t.titleId));fputs(",\"parentTitleId\":",f);S(f,t.parentTitleId);fputs(",\"mediaType\":",f);S(f,t.mediaType);fputs(",\"kind\":",f);S(f,t.kind);fprintf(f,",\"version\":%u,\"installedSizeBytes\":%llu}%s\n",t.version,(unsigned long long)t.size,i+1<v.size()?",":"");}fputs("  ],\n  \"errors\": [",f);for(size_t i=0;i<s.errors.size();++i){if(i)fputc(',',f);S(f,s.errors[i]);}fputs("]\n}\n",f);if(fflush(f)||ferror(f)){e="write failed";fclose(f);remove(TMP);return false;}if(fclose(f)){e="close failed";remove(TMP);return false;}remove(OUT);if(rename(TMP,OUT)){e=std::string("rename: ")+strerror(errno);remove(TMP);return false;}return true;}
