# continue.md (rtg, master)

## Repos

| Repo | Commit | State |
|---|---|---|
| rtg | master, this file's commit | pushed |
| kazilib (`src/dep/kazilib`) | master `f2b4263` | pushed |

## Last work (2026-11-06)

- **Port:** the 2018 SFML 2 code onto SFML 3.1 and kazilib (`src/rtg/`: std names, log, `lib::scene::Manager` in place of its own scene manager, `struct`, `g_` globals, no plain getters), FASTBuild, Release x86.
- **Web:** `build_web.ps1`, deployed at https://kazin.dev/projects/rtg/ (`deploy_ubuntu.ps1`, static, Caddy snippet `kazin.dev.d/rtg.caddy`, `/opt/rtg/web`).
- **Bugs fixed:**
  1. A right click with nothing selected read `front()` of an empty list: now it does nothing.
  2. `Unit::_selected` was never initialized.
  3. A destination between pixels made units shake around it for ever: the last step is now what's left.
- **Changed on purpose:** a fixed 60 ticks a second (`App::Ticks`), so a browser on a 120 Hz display doesn't run the game twice as fast. At 60 Hz it plays as before.
- **Added:** console lines for the test, the controls hint under the game on the page, README with controls and screenshot.

## Tested

| Test | Result |
|---|---|
| `src\tests\web\run_web_test.ps1`, local build | passed |
| same, `-Url https://kazin.dev/projects/rtg/` | passed |
| `deploy\rtg.exe` Release x86 | builds; started and ran 3 s; not played by hand |

Known gaps: only headless Edge with software WebGL; see `to-resolve.md`.

## Next steps

- `to-resolve.md`: the manual checks and three questions (the yellow box, overlapping units, anti-aliasing in the browser).

## The user's prompts (this work)

1. "https://github.com/xkazinx/rtg deploy same"
2. "continue"
