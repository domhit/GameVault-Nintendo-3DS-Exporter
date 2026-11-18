# GameVault Nintendo 3DS Exporter v0.1.0

First stable release of the read-only Nintendo 3DS inventory exporter for GameVault.

## Highlights

- Enumerates installed NAND and SD content through the 3DS AM service.
- Exports exact 16-digit Title IDs, parent relationships, installed versions and sizes.
- Distinguishes Games, Demos, Updates, DLC, TWL/DSiWare and system-title types.
- Reads localized installed SMDH title, description, publisher and region metadata.
- Does not require or decrypt `title.db`.
- Ships both a Homebrew Launcher 3DSX package and an installable CIA.

## Hardware tested

Both distribution formats were tested on real hardware. The CIA and 3DSX builds produced byte-identical `installed_titles.json` files, verified by MD5 comparison.

## Files

- `GameVault-Nintendo-3DS-Exporter_v0.1.0.zip` — copy-ready `/3ds/` Homebrew Launcher package.
- `GameVault-3DS-Exporter_v0.1.0.cia` — install with FBI for HOME Menu use.

## Output

`sd:/3ds/GameVault-3DS-Exporter/installed_titles.json`

The exporter is read-only with respect to installed titles and system databases.
