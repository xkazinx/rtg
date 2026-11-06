# to-resolve.md (rtg)

## Web version (2026-11-06)

Manual checks:

- **Firefox, Safari, a real GPU.** Why: only headless Edge with software WebGL was tested. Steps: open https://kazin.dev/projects/rtg/, drag over the units at the top left, right click elsewhere.
- **A phone.** Why: the game needs a drag and a right click, and a touch screen has no right button. It is expected not to be playable there.
- **The Windows build by hand.** Why: `deploy\rtg.exe` was only started and left running 3 seconds. Selecting and moving were tested in the browser, on the same code. Steps: run it, drag, right click, resize the window.

Open questions:

- **The yellow box stays on the map** after a group arrives. It looks like a debug aid (it was called `test` in 2018). Hide it on arrival, or remove it?
- **Units overlap.** They walk through each other and stack on the destination, as in 2018. Keep it as a prototype, or add spacing?
- **Round edges in the browser.** The circles have no anti-aliasing there: kazilib's web context is made before the window asks for it. Worth making it always on in kazilib's SFML patch?
