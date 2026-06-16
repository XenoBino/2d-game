project('2d-game', ['c', 'cpp'])

cstd   = 'c23'
cxxstd = 'c++26'

libsdl3 = dependency('sdl3', required: true)
libgl = dependency('gl', required: true)

cflags   = [ '-std=' + cstd ]
cxxflags = [ '-std=' + cxxstd ]
ldflags  = []

subdir('libs/')
subdir('engine/')
subdir('editor/')
