game_cflags = []
game_cxxflags = []
game_ldflags = []
game_dep = [libsdl3, libgl, libglad, engine]
game_srcs = ['game.cpp']
game_incs_pub = ['include/']
game_incs_pri = ['include/', '.']

# -v- Don't edit these
_game_cflags = []
_game_cxxflags = []
_game_ldflags = []
# -^- Don't edit these

foreach flag : cflags
  _game_cflags += flag
endforeach

foreach flag : cxxflags
  _game_cxxflags += flag
endforeach

foreach flag : ldflags
  _game_ldflags += flag
endforeach

foreach flag : game_cflags
  _game_cflags += flag
endforeach

foreach flag : game_cxxflags
  _game_cxxflags += flag
endforeach

foreach flag : game_ldflags
  _game_ldflags += flag
endforeach

game = executable(
  'game',
  game_srcs,
  dependencies: game_dep,
  c_args: _game_cflags,
  cpp_args: _game_cxxflags,
  link_args: _game_ldflags,
  install: true,
  install_dir: '/'
)
