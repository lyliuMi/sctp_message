libsctp_message_core_src = files('''
    list.c
    pkbuf.c
    log.c
    conv.c
'''.split())

libsctp_message_core_inc = include_directories('.')

libsctp_message_core = library('sctp_message_core',
    sources : libsctp_message_core_src,
    version : '1.0.0',
    # c_args : libasn1c_common_cc_flags,
    include_directories : libsctp_message_core_inc,
    install : true,
    install_dir : libdir    
)

libsctp_message_core_dep = declare_dependency(
    link_with : libsctp_message_core,
    include_directories : [libsctp_message_core_inc]
)
