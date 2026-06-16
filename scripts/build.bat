@echo OFF

meson setup Build/
meson compile -C Build/
set DESTDIR=%cd%\bin
meson install -C Build/
