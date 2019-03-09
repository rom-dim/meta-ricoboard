#Taken from TI yocto BSP Layer Version 05-2014, original name:ti33xx.inc
SOC_FAMILY = "ti43x"
require conf/machine/include/soc-family.inc

DEFAULTTUNE ?= "armv7athf-neon"
require conf/machine/include/tune-cortexa9.inc

# List common SoC features
MACHINE_FEATURES = "kernel26 usbgadget usbhost ext4 screen ethernet"

# Sub-architecture support adapted fom fsl-arm
MACHINE_SOCARCH = "${TUNE_PKGARCH}-ti43x"
PACKAGE_EXTRA_ARCHS_append = " ${MACHINE_SOCARCH}"

PREFERRED_PROVIDER_virtual/bootloader = "u-boot-ti-staging"
PREFERRED_PROVIDER_u-boot = "u-boot-ti-staging"
UBOOT_ARCH = "arm"
UBOOT_ENTRYPOINT = "0x80008000"
UBOOT_LOADADDRESS = "0x80008000"

# Kernel 
PREFERRED_PROVIDER_virtual/kernel ?= "linux-ti-staging"
PREFERRED_VERSION_linux-ti-staging = "4.9%"
KERNEL_IMAGETYPE ?= "zImage"

# Install modules in initramfs and rootfs
PACKAGE_INSTALL_append = " kernel-modules"

SERIAL_CONSOLES ?= "115200;ttyS0"
# dont install kernelimage to rootfs
RDEPENDS_kernel-base = ""

# rootfs images
# Use the expected value of the ubifs filesystem's volume name in the kernel
UBI_VOLNAME = "root"
# The biggest NANDs on current modules are 1GB. With current partition layout,
# this sums up to 7943 LEBs available for the ubifs
MKUBIFS_ARGS = "-F -m 2048 -e 129024 -c 7943"
UBINIZE_ARGS = "-m 2048 -p 128KiB -s 512"

RDEPENDS_kernel-modules_ti43x = "\
    ${@bb.utils.contains('MACHINE_FEATURES', 'suspend', 'amx3-cm3', '', d)} \
    ${@bb.utils.contains('MACHINE_FEATURES', 'sgx', 'ti-sgx-ddk-km', '', d)} \
"

# OpenGLES support for AM335x SGX Core
PREFERRED_PROVIDER_virtual/libgles1 ?= "ti-sgx-ddk-um"
PREFERRED_PROVIDER_virtual/libgles2 ?= "ti-sgx-ddk-um"
PREFERRED_PROVIDER_virtual/egl ?= "ti-sgx-ddk-um"

QT_QPA_DEFAULT_PLATFORM ?= "${@bb.utils.contains('MACHINE_FEATURES', 'sgx', 'eglfs', 'linuxfb', d)}"
