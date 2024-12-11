libnas_eps_sources = files('''
    types.c
    conv.c
    ies.c
    decoder.c
    encoder.c
'''.split())

libnas_eps_inc = include_directories('.')

libnas_eps = library('ogsnas-eps',
    sources : libnas_eps_sources,
    version : '1.0.0',
    c_args : '-DOGS_NAS_COMPILATION',
    include_directories : libnas_eps_inc,
    dependencies : libnas_common_dep,
    install : true,
    install_dir : libdir    
)

libnas_eps_dep = declare_dependency(
    link_with : libnas_eps,
    include_directories : [libnas_eps_inc],
    dependencies : libnas_common_dep)
