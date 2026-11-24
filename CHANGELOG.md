### v0.1.1

#### Added
- Read-only Product Code lookup for every installed title through libctru `AM_GetTitleProductCode`.
- `productCode` and nonfatal `productCodeResult` fields in schema v4 JSON.

#### Notes
- Product-code lookup failures do not abort scanning or hide otherwise valid installed titles.
- Existing Title ID, parent-ID, SMDH, version and installed-size logic is unchanged.
- Validated on real Nintendo 3DS hardware: Product Codes were exported for the tested installed games and achieved 100% exact GameTDB mapping in GameVault.

# Changelog

## v0.1.0

### Added
- Read-only AM inventory of NAND, SD and optional Game Card titles.
- Installed size and version from `AM_GetTitleInfo`.
- CTR Game, Demo, Update, DLC, TWL/DSiWare and system-title classification.
- Parent Title ID and 24-bit Unique ID extraction.
- Localized installed SMDH metadata: title, long description, publisher and region.
- Atomic JSON export to SD.
- Homebrew Launcher 3DSX package.
- Installable HOME Menu CIA with custom SMDH/icon and banner.
- GitHub Actions builds for both distribution formats.

### Validation
- Tested on real Nintendo 3DS hardware.
- CIA and 3DSX exports verified byte-identical using MD5 checksums.
