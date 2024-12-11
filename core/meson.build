libcoreources = files('''
    list.c
    pkbuf.c
    log.c
    conv.c
'''.split())

libcore_inc = include_directories('.')

libcore = library('core',
    sources : libcoreources,
    version : '1.0.0',
    # c_args : libasn1c_common_cc_flags,
    include_directories : libcore_inc,
    # dependencies : [libasn1c_common_dep, libsctp_message_dep],
    install : true,
    install_dir : libdir    
)

libcore_dep = declare_dependency(
    link_with : libcore,
    include_directories : [libcore_inc]
)
