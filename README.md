# GameVault Nintendo 3DS Exporter

Read-only Nintendo 3DS installed-title inventory exporter for GameVault.

## Features

- Enumerates installed titles through the Nintendo 3DS AM service; no `title.db` decryption is required.
- Scans NAND and SD, and reports Game Card presence when available.
- Exports 16-digit Title ID, parent Title ID, 24-bit Unique ID, media, installed version and installed size.
- Classifies CTR applications, demos, patches/updates, add-on content/DLC, TWL/DSiWare and system-title subtypes.
- Reads installed SMDH metadata read-only for localized name, long description, publisher and region.
- Writes atomically to `sd:/3ds/GameVault-3DS-Exporter/installed_titles.json`.
- Available as both Homebrew Launcher `.3dsx` and installable `.cia`.

## Installation

### Homebrew Launcher

Use the release ZIP and copy its `3ds` directory to the root of the SD card. Launch `GameVault-3DS-Exporter.3dsx` from Homebrew Launcher.

### CIA / HOME Menu

Install `GameVault-3DS-Exporter_v0.1.0.cia` with FBI, then start **GameVault 3DS Exporter** from the HOME Menu.

The CIA contains its own SMDH/icon and HOME Menu banner. The CIA and 3DSX use the same inventory engine.

## Hardware validation

v0.1.0 was validated on real 3DS hardware. The CIA and 3DSX builds produced byte-identical `installed_titles.json` output; equality was independently verified by MD5 comparison.

## Output

`sd:/3ds/GameVault-3DS-Exporter/installed_titles.json`

The v0.1.0 schema contains:

- `schemaVersion: 3`
- `exporterVersion: 0.1.0`
- AM media statistics for NAND, SD and Game Card
- SMDH success/missing counters
- per-title Title ID, parent ID, category, subtype, Unique ID, name, description, publisher, region, version and installed size

## Controls

- **A**: export again
- **START**: exit

## Safety

The exporter is read-only with respect to installed titles. It does not install, delete, alter or decrypt titles, tickets, CIAs, saves, NAND contents or `title.db`. The only file it writes is its JSON export on SD.

## Build

GitHub Actions uses the official `devkitpro/devkitarm:latest` image. It builds the common ELF/3DSX application, creates CIA SMDH/banner metadata with `bannertool`, and packages the CIA with `makerom`.

The stable tag workflow publishes:

- `GameVault-Nintendo-3DS-Exporter_v0.1.0.zip`
- `GameVault-3DS-Exporter_v0.1.0.cia`

## License

MIT. See `LICENSE`, `NOTICE`, and `THIRD_PARTY_LICENSES.md`.
