#!/usr/bin/bash

meson setup Build/
meson compile -C Build/
DESTDIR="$PWD/bin/" meson install -C Build/
