# GameVault Nintendo 3DS Exporter v0.1.1

GameVault Nintendo 3DS Exporter v0.1.1 adds read-only Product Code export for reliable canonical-title resolution in GameVault while preserving the existing installed-title inventory behavior.

## Highlights

- Adds `productCode` for installed titles through libctru `AM_GetTitleProductCode`.
- Adds nonfatal `productCodeResult` diagnostics.
- Updates the JSON format to **schemaVersion 4**.
- Keeps Title ID, parent relationship, Unique ID, media type, SMDH metadata, region, installed version and installed size unchanged.
- Product Code lookup failures do not hide or remove otherwise valid installed titles.
- Remains read-only with respect to titles, tickets, CIAs, saves, NAND databases and installed content.

## GameVault integration

Valid CTR/KTR Product Codes can be normalized by GameVault to exact GameTDB identifiers before IGDB lookup. This substantially improves canonical naming without overwriting the title reported by the console.

## Hardware validation

Validated on real Nintendo 3DS hardware. The schema-4 export produced Product Codes for the tested installed games and the resulting Product Codes reached 100% exact GameTDB mapping in GameVault.

## Files

- `GameVault-Nintendo-3DS-Exporter_v0.1.1.zip` — copy-ready `/3ds/` Homebrew Launcher package.
- `GameVault-3DS-Exporter_v0.1.1.cia` — installable HOME Menu CIA.

## Upgrade notes

GameVault v1.6.0-dev16 or newer accepts both legacy schema 3 and schema 4 exports. Older GameVault versions that accept only schema 3 must be upgraded before using this exporter release.
