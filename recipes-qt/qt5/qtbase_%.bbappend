FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

QT_QPA_DEFAULT_PLATFORM ??= "eglfs"

# The string 'gl' is in PACKAGECONFIG because "opengl" is in yogurt's
# DISTRO_FEATURES. Since our boards only support egl/gles2 and not the full
# opengl, we have to disable gl and enable gles2 by hand here.
PACKAGECONFIG_GL_ti33x = "gles2 eglfs"
PACKAGECONFIG_GL_ti43x = "gles2 eglfs"
RDEPENDS_qtbase_append = " tslib-conf tslib-calibrate"

PACKAGECONFIG_FONTS = "fontconfig"
PACKAGECONFIG_MULTIMEDIA_append = " alsa"
PACKAGECONFIG_DEFAULT_append = " tslib"

#PACKAGECONFIG_append = " pcre"
PACKAGECONFIG_append = " accessibility"
        
# Set default QT_QPA_PLATFORM for all phytec boards
do_configure_prepend() {
        # adapt qmake.conf to our needs
        sed -i 's!load(qt_config)!!' ${S}/mkspecs/linux-oe-g++/qmake.conf

        # Insert QT_QPA_PLATFORM into qmake.conf
        cat >> ${S}/mkspecs/linux-oe-g++/qmake.conf <<EOF

QT_QPA_DEFAULT_PLATFORM = ${QT_QPA_DEFAULT_PLATFORM}
 
load(qt_config)

EOF
}
