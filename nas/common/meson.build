libnas_common_sources = files('''
    types.c
    conv.c
    security.c
'''.split())

libnas_common_inc = include_directories('.')

libnas_common = library('ogsnas-common',
    sources : libnas_common_sources,
    version : '1.0.0',
    c_args : '-DOGS_NAS_COMPILATION',
    include_directories : [libnas_common_inc],
    dependencies : libcrypt_dep,
    install : true,
    install_dir : libdir    
)

libnas_common_dep = declare_dependency(
    link_with : libnas_common,
    include_directories : [libnas_common_inc],
    dependencies : libcrypt_dep)
