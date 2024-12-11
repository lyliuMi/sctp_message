sctp_message_inc = include_directories('.')

sctp_message_src = files(
    's1ap_msg_hdr.h',
    'context.c',
    'message.c',
    's1ap_build.c',
    'sctp.c',
    'socket.c',
    's1ap_path.c',
    'nas_build.c',
    'nas_security.c'
)

libsctp = cc.find_library('sctp', required:true)

libsctp_message = library('sctp_message',
    sources : sctp_message_src,
    version : '1.0.0',
    include_directories : [sctp_message_inc],
    dependencies : [libsctp, libasn1c_s1ap_dep, libasn1c_ngap_dep, libasn1c_util_dep, libnas_eps_dep],
    install : true,
    install_dir : libdir
)


# 外部依赖将会public 该include_directories
# 依赖该dep的 将自动将该该include_directories的目录给加入头文件搜索路径
# 而且是层层依赖
libsctp_message_dep = declare_dependency(
    link_with : libsctp_message,
    include_directories : [sctp_message_inc],
    dependencies : [libsctp, libasn1c_s1ap_dep, libasn1c_ngap_dep, libasn1c_util_dep, libnas_eps_dep]
)
