engine_cflags = []
engine_cxxflags = []
engine_ldflags = []
engine_dep = []
engine_srcs = ['engine.cpp']
engine_incs_pub = ['include/']
engine_incs_pri = ['include/', '.']

# -v- Don't edit these
_engine_cflags = []
_engine_cxxflags = []
_engine_ldflags = []
# -^- Don't edit these

foreach flag : cflags
  _engine_cflags += flag
endforeach

foreach flag : cxxflags
  _engine_cxxflags += flag
endforeach

foreach flag : ldflags
  _engine_ldflags += flag
endforeach

foreach flag : engine_cflags
  _engine_cflags += flag
endforeach

foreach flag : engine_cxxflags
  _engine_cxxflags += flag
endforeach

foreach flag : engine_ldflags
  _engine_ldflags += flag
endforeach

engine_lib = static_library(
  'engine',
  engine_srcs,
  include_directories: engine_incs_pri,
  c_args: _engine_cflags,
  cpp_args: _engine_cxxflags,
  link_args: _engine_ldflags,
)
engine = declare_dependency(link_with: engine_lib, include_directories: engine_incs_pub)
