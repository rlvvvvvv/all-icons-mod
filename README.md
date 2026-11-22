# All Icons (Geode mod)

Unlocks all icons, Color 1, Color 2 and glow in Geometry Dash.

## Before building
1. Open `mod.json` and change `id` (`yourname.allicons`) and `developer` to your own name.
2. Make sure the `geode` version in `mod.json` matches your installed Geode version.

## Option A: Build locally
1. Install the Geode SDK and CLI: https://docs.geode-sdk.org/getting-started/
2. Set the `GEODE_SDK` environment variable.
3. Run:
   ```
   geode build
   ```
4. Copy the resulting `.geode` file into your Geometry Dash `geode/mods` folder.

## Option B: Build online (no setup)
1. Create a GitHub repo and upload everything in this folder (keep `.github`).
2. Open the Actions tab, run "Build Binaries", and download the artifact.
3. Put the `.geode` file in `geode/mods`.

`logo.png` is the mod's icon/profile picture.
