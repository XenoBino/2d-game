editor_cflags = []
editor_cxxflags = []
editor_ldflags = []
editor_dep = [libsdl3, libgl, libglad, engine]
editor_srcs = ['editor.cpp']
editor_incs_pub = ['include/']
editor_incs_pri = ['include/', '.']

# -v- Don't edit these
_editor_cflags = []
_editor_cxxflags = []
_editor_ldflags = []
# -^- Don't edit these

foreach flag : cflags
  _editor_cflags += flag
endforeach

foreach flag : cxxflags
  _editor_cxxflags += flag
endforeach

foreach flag : ldflags
  _editor_ldflags += flag
endforeach

foreach flag : editor_cflags
  _editor_cflags += flag
endforeach

foreach flag : editor_cxxflags
  _editor_cxxflags += flag
endforeach

foreach flag : editor_ldflags
  _editor_ldflags += flag
endforeach

editor = executable('editor', editor_srcs, dependencies: editor_dep, c_args: _editor_cflags, cpp_args: _editor_cxxflags, link_args: _editor_ldflags)
