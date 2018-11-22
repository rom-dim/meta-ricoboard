SUMMARY = "A console-only image that fully supports the target device \
hardware."

IMAGE_FEATURES += "splash"

LICENSE = "MIT"

inherit core-image
#inherit populate_sdk populate_sdk_qt5


IMAGE_INSTALL_append = "\
    gdbserver \
    openssh-scp \
    openssh-sshd \
    openssh-sftp-server \
    packagegroup-qt5-toolchain-target \
    tslib \
    fontconfig \
    libpcre2 \
    libinput \
    dbus eudev \
    i2c-tools \
    evtest \
    "
  
IMAGE_INSTALL_append = " \
    cinematicexperience \
    ttf-dejavu-sans-mono \
    "

IMAGE_INSTALL_append = " \
  hd44780 \
  "
    
TOOLCHAIN_TARGET_TASK_append = " \
    kernel-devsrc \
    i2c-tools-dev \
    "
    