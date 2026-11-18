# Changelog

## v0.1.0-dev3
- Adds explicit CTR/TWL/system subtypes, raw title category and 24-bit Unique ID.
- Improves on-device summary for Demo, TWL/DSiWare and System categories.
- Keeps the validated AM + localized SMDH path unchanged.

## v0.1.0-dev3
- Initial read-only AM inventory probe.
- NAND, SD and Game Card enumeration.
- Title ID, size, version and preliminary content-type export.
- Atomic JSON output to SD.
- GitHub Actions 3DSX build and copy-ready SD package.

### CIA packaging test
- GitHub Actions additionally emits an installable CIA using makerom 0.18.4.
- The normal copy-ready 3DSX artifact remains unchanged.
