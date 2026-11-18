# GameVault Nintendo 3DS Exporter

Read-only Nintendo 3DS installed-title inventory exporter for GameVault.

## v0.1.0-dev3

This second hardware build combines AM enumeration with local installed-title SMDH metadata:

- 16-digit Title ID
- media source: NAND, SD, or Game Card
- installed version
- installed size in bytes
- preliminary type classification (Game, Update, DLC, System, TWL/DSiWare, Other)
- canonical parent Title ID for Update/DLC candidates

It does **not** read/decrypt `title.db` and does not modify installed content.

Output: `sd:/3ds/GameVault-3DS-Exporter/installed_titles.json`

## Install / run

Download the GitHub Actions artifact and copy the contained `3ds` directory to the root of the SD card. Then start `GameVault-3DS-Exporter.3dsx` from Homebrew Launcher.

A later milestone can add a CIA build after the 3DSX probe is validated on real hardware.

## Build

GitHub Actions uses the official `devkitpro/devkitarm:latest` image with devkitARM/libctru and produces a copy-ready SD ZIP plus the raw `.3dsx`.

## License

MIT. See `LICENSE`, `NOTICE`, and `THIRD_PARTY_LICENSES.md`.

## SMDH metadata in dev2

For non-system CTR titles, dev2 opens the installed icon/SMDH from `ARCHIVE_SAVEDATA_AND_CONTENT` using the same read-only archive method used by FBI. It exports the localized short title, long description, publisher, region mask and readable region list. The system language is preferred, with a region-based/default-language fallback and then the first non-empty title slot.

The exporter remains read-only and does not include an FTP server. Use the maintained standalone 3DS `ftpd` application when transferring the JSON.
