// SPDX-License-Identifier: MIT
#include <3ds.h>
#include <cstdio>
#include <string>
#include <vector>
#include "TitleScanner.hpp"
#include "JsonExporter.hpp"
int main(){gfxInitDefault();consoleInit(GFX_TOP,nullptr);printf("GameVault Nintendo 3DS Exporter v0.1.0-dev1\n\n");Result rc=amInit();if(R_FAILED(rc)){printf("AM init failed: 0x%08lX\n\nSTART: exit\n",(unsigned long)rc);while(aptMainLoop()){hidScanInput();if(hidKeysDown()&KEY_START)break;gspWaitForVBlank();}gfxExit();return 1;}bool done=false;while(aptMainLoop()){if(!done){printf("Scanning NAND / SD / Game Card...\n");std::vector<ExportTitle>titles;ScanSummary summary;ScanTitles(titles,summary);std::string error;if(ExportJson(titles,summary,error)){unsigned games=0,updates=0,dlc=0,system=0,other=0;for(auto&t:titles){if(t.kind=="GAME")++games;else if(t.kind=="UPDATE")++updates;else if(t.kind=="DLC")++dlc;else if(t.kind=="SYSTEM")++system;else ++other;}printf("\nExport complete\nGames: %u\nUpdates: %u\nDLC: %u\nSystem: %u\nOther/TWL: %u\nTotal: %u\n",games,updates,dlc,system,other,(unsigned)titles.size());printf("\nsd:/3ds/GameVault-3DS-Exporter/installed_titles.json\n");}else printf("\nExport failed: %s\n",error.c_str());printf("\nA: export again\nSTART: exit\n");done=true;}hidScanInput();u32 k=hidKeysDown();if(k&KEY_START)break;if(k&KEY_A){consoleClear();printf("GameVault Nintendo 3DS Exporter v0.1.0-dev1\n\n");done=false;}gspWaitForVBlank();}amExit();gfxExit();return 0;}
