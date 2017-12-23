ifeq ($(CONFIG_OF),y)

dtb-$(CONFIG_SOC_AM43XX) += \
	am437x-myir-ricoboard-lcd.dtb \
	am437x-myir-ricoboard-hdmi.dtb
endif

dtstree		:= $(srctree)/$(src)
dtb-$(CONFIG_OF_ALL_DTBS) := $(patsubst $(dtstree)/%.dts,%.dtb, $(wildcard $(dtstree)/*.dts))

always		:= $(dtb-y)
clean-files	:= *.dtb
