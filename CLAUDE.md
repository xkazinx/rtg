# CLAUDE.md (rtg)

- **Build:** `powershell -ExecutionPolicy Bypass -File build.ps1` (`setup.ps1`: kazilib submodule, junction `src\dep\SFML-3.1.0` → `src\dep\kazilib\SFML-3.1.0`; then kazilib FASTBuild on `src\fastbuild.json`: kazilib, rtg). `build.ps1 rtg`, `-Regen`, `-Clean`, `-Local`; `-Configuration Debug` only if asked. Output `deploy\rtg.exe`. `setup.ps1`'s `submodule update` resets kazilib to the recorded pointer: stage a moved pointer first (`git add src/dep/kazilib`).
- **Web:** `build_web.ps1` (Emscripten `D:\code\tools\emsdk`, SFML web `D:\code\tools\kazilib-web`) → `src\build\web\rtg-build\`; `src\rtg\CMakeLists.txt` is the web build only. Code that differs: `#ifdef __EMSCRIPTEN__` in `app.cpp` (no resize frame, no frame limit, no anti-aliasing request, the controls hint on the page).
- **Deploy:** `deploy_ubuntu.ps1` → box `kazin-music`, `/opt/rtg/web`, Caddy `kazin.dev/projects/rtg` (`deploy\ubuntu\`); static, no service. Touch only rtg's files there.
- **Tests:** `src\tests\web\run_web_test.ps1` (local build; `-Url https://kazin.dev/projects/rtg/` live), 0 failed, outside the command sandbox; read the shots in `testerino\web\`.
- **Ticks:** the game runs at 60 ticks a second whatever the display (`App::Ticks`); units move a pixel per axis per tick.
- **Kazilib first:** scenes (`scene/manager.h`), log, std names from kazilib; reusable code goes there.
- **Console lines** (`Game ready`, `Selected`, `Moving`, `Units arrived`) are what the web test waits for: writer and steps change together.
- **README:** the 2018 original stays at its end (`## Original README`).
- **Names:** members `_name`, functions / types `PascalCase`, `struct`, `g_` globals (full rules: `D:\code\hb\hbmillennium\CLAUDE.md`).
