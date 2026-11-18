#pragma once
#include <3ds.h>
// SMDH binary layout. Titles occupy 0x2008 bytes total; settings begin at 0x2008.
struct GV_SmdhTitle {
    u16 shortDescription[0x40];
    u16 longDescription[0x80];
    u16 publisher[0x40];
};
struct GV_SmdhSettings {
    u8 ratings[0x10];
    u32 region;
    u32 matchmakerId;
    u64 matchmakerBitId;
    u32 flags;
    u16 eulaVersion;
    u16 reserved;
    float optimalBannerFrame;
    u32 streetpassId;
};
struct GV_Smdh {
    u32 magic;
    u16 version;
    u16 reserved;
    GV_SmdhTitle titles[16];
    GV_SmdhSettings settings;
    u8 reserved2[8];
    u8 smallIcon[0x480];
    u8 largeIcon[0x1200];
};
static_assert(sizeof(GV_SmdhTitle) == 0x200, "Unexpected SMDH title size");
static_assert(sizeof(GV_Smdh) == 0x36C0, "Unexpected SMDH size");
