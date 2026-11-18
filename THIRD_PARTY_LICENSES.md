# Third-party software and references

GameVault Nintendo 3DS Exporter is MIT-licensed. Third-party projects retain their own licenses.

## libctru
- Project: devkitPro/libctru
- URL: https://github.com/devkitPro/libctru
- License: zlib-style permissive license
- Usage: 3DS runtime, filesystem/configuration APIs and AM service calls including installed-title enumeration.

## FBI
- Project: Steveice10/FBI
- URL: https://github.com/Steveice10/FBI
- License: MIT
- Usage: installed-title management and SMDH archive/language/region handling were used as an open-source reference. No FBI binary or proprietary asset is bundled.

## FBI-NH
- Project: nh-server/FBI-NH
- URL: https://github.com/nh-server/FBI-NH
- Usage: known-working CIA RSF/ExHeader packaging structure was used as a reference for service access, system calls, process settings and system-module dependencies.

## bannertool
- Project: Steveice10/bannertool; Linux release bundle maintained by Epicpkmn11/bannertool
- URL: https://github.com/Epicpkmn11/bannertool
- Usage: build-time generation of CIA SMDH/icon and banner metadata. Not bundled in the application binary.

## makerom / Project_CTR
- Project: 3DSGuy/Project_CTR
- URL: https://github.com/3DSGuy/Project_CTR
- Usage: build-time CIA packaging. Not bundled in the application binary.
