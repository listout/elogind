# SPDX-License-Identifier: LGPL-2.1-or-later

executables += [
        libexec_template + {
                'name' : 'elogind-userwork',
                'conditions' : ['ENABLE_USERDB'],
                'sources' : files('userwork.c'),
                'dependencies' : threads,
        },
        libexec_template + {
                'name' : 'elogind-userdbd',
                'conditions' : ['ENABLE_USERDB'],
                'sources' : files(
                        'userdbd-manager.c',
                        'userdbd.c',
                ),
                'dependencies' : threads,
        },
        executable_template + {
                'name' : 'userdbctl',
                'conditions' : ['ENABLE_USERDB'],
                'sources' : files('userdbctl.c'),
                'dependencies' : threads,
        },
]

if conf.get('ENABLE_SSH_USERDB_CONFIG') == 1
        custom_target(
                '20-elogind-userdb.conf',
                input : '20-elogind-userdb.conf.in',
                output : '20-elogind-userdb.conf',
                command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
                install : true,
                install_dir : sshdconfdir.startswith('/usr/') ? sshdconfdir : libexecdir / 'sshd_config.d')

        if conf.get('LINK_SSHD_USERDB_DROPIN') == 1
                install_emptydir(sshdconfdir)

                meson.add_install_script(sh, '-c',
                        ln_s.format(libexecdir / 'sshd_config.d' / '20-elogind-userdb.conf', sshdconfdir / '20-elogind-userdb.conf'))
        endif
endif
