project('2d-game', ['c', 'cpp'])

cstd   = 'c23'
cxxstd = 'c++26'

libsdl3 = dependency('sdl3', required: true)
libgl = dependency('gl', required: true)

cflags   = [ '-std=' + cstd ]
cxxflags = [ '-std=' + cxxstd ]
ldflags  = []

meson.add_install_script('scripts/meson/gitignore.sh')

subdir('libs/')
subdir('engine/')
subdir('editor/')
subdir('game/')
