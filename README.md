# Dusklight Randomizer

The official randomizer mod for [Dusklight](https://github.com/TwilitRealm/dusklight).

## Xbox One S / UWP fork

This branch contains experimental Xbox build fixes. For Xbox, use the
[per-mod setup and compatibility guide](https://github.com/999sian/dusklight/blob/xbox-one-s-uwp-v2.0.3/docs/xbox-one-s-mod-compatibility.md#4-randomizer-source-fork-no-public-xbox-installer-yet).

**There is no public Xbox Randomizer installer here.** Initialization passed
in a previous private UWP app build, but gameplay and seed/save workflows are
not verified. The public Dusklight 2.0.3.54 package excludes Randomizer pending
bundled texture redistribution review.

The desktop build instructions below do not produce an installable Xbox mod.
Xbox needs a matching UWP rebuild bundled inside a signed Dusklight MSIX,
including the game's symbol manifest. Copying a downloaded `.dusk` or native
DLL into Xbox app data cannot load it through the current UWP loader. The
linked guide explains the developer integration requirements and the mods
that can be used with the public package now.

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
