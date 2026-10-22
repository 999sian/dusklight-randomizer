# Dusklight Randomizer

The official randomizer mod for [Dusklight](https://github.com/TwilitRealm/dusklight).

## Xbox One S / UWP fork

**No public Xbox installer yet.** The public Dusklight package excludes
Randomizer pending bundled texture rights review. Gameplay is unverified.

This fork contains build fixes. Xbox needs Randomizer bundled in a signed
app package; copying a `.dusk` or DLL into app data will not work.
The build steps below are for desktop.

[Simple Xbox mod guide](https://github.com/999sian/dusklight/blob/xbox-one-s-uwp-v2.0.3/docs/xbox-one-s-mod-compatibility.md#randomizer)

## Building

```sh
git clone https://github.com/TwilitRealm/dusklight-randomizer/
cmake -B build
cmake --build build --parallel 
```

The compiled mod is `build/mods/randomizer.dusk`. Copy it into the game's mods folder to try it:

- Windows: `%APPDATA%\TwilitRealm\Dusklight\mods`
- Linux: `~/.local/share/TwilitRealm/Dusklight/mods`
- macOS: `~/Library/Application Support/TwilitRealm/Dusklight/mods`

## For Dusklight developers

Point the build at an existing checkout instead of fetching one:

```sh
cmake -B build -DDUSKLIGHT_DIR=~/path/to/dusklight
```
