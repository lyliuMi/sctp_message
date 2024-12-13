project('sctp_test', 'c')

cc = meson.get_compiler('c')
project_path = meson.source_root()

prefix = project_path + '/install/'
bindir = prefix + 'bin'
libdir = prefix + 'lib'


_sctp_inc = include_directories('.')

subdir('core')
subdir('proto')
subdir('crypt')
subdir('asn1c')
subdir('nas')
subdir('src')

executable(
    'sctp_test_client', 
    sources : 'main1.c',
    include_directories: [_sctp_inc],
    dependencies : [libsctp_message_dep],
    install : true,
    install_dir : bindir
)

message(
    'project_path = ' + project_path + '\n',
    'prefix = ' + prefix + '\n',
    'bindir = ' + bindir + '\n',
    'libdir = ' + libdir + '\n'
)