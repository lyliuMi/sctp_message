project('sctp_test', 'c')

prefix = '/work/lyl/sctp_message/install/'
bindir = prefix + 'bin'
libdir = prefix + 'lib'

cc = meson.get_compiler('c')

_sctp_inc = include_directories('.')

subdir('core')
subdir('asn1c')
subdir('proto')
subdir('crypt')
subdir('nas')
subdir('src')

executable(
    'sctp_test_server', 
    sources : 'main1.c',
    include_directories: [_sctp_inc],
    dependencies : [libsctp_message_dep],
    install : true,
    install_dir : bindir
)

