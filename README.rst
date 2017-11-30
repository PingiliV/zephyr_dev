Zephyr Project
##############

.. raw:: html

   <a href="https://bestpractices.coreinfrastructure.org/projects/74"><img
   src="https://bestpractices.coreinfrastructure.org/projects/74/badge"></a>
   <img
   src="https://api.shippable.com/projects/58ffb2b8baa5e307002e1d79/badge?branch=master">


The Zephyr Project is a scalable real-time operating system (RTOS) supporting
multiple hardware architectures, optimized for resource constrained devices,
and built with security in mind.

The Zephyr OS is based on a small-footprint kernel designed for use on
resource-constrained systems: from simple embedded environmental sensors and
LED wearables to sophisticated smart watches and IoT wireless gateways.

The Zephyr kernel supports multiple architectures, including ARM Cortex-M,
Intel x86, ARC, NIOS II, Tensilica Xtensa, and RISC V, and a large number of
`supported boards`_.

.. below included in doc/introduction/introduction.rst

.. start_include_here

Setup environment variables
###########################

export ZEPHYR_BASE=<zephyr source base dir>
export ZEPHYR_GCC_VARIANT=zephyr
export ZEPHYR_SDK_INSTALL_DIR=/opt/zephyr-sdk


Compilation steps for latest Zephyr releases
############################################

cmake expects 3.8.2 version.
1) Download Latest or 3.8.2 or greater cmake source.
1a) unzip or untar cmake packages.
1b) ./configure <configure the package for compilation>.
1c) make.
1d) sudo make install.
2) In samples and corresponding app ex: zephyr/samples/hello_world.
2) create build/arduino_due <corresponding target> (mkdir -p build/arduino_due).
2a) cmake -DBOARD=arduino_due ../.. (as cmakelist exists in samples/hello_world).
2b) run make command to compile the platform and OS centric source files cmd: make.
2c) build/arduino_due/zephyr will have corresponding binaries ready to be flashed on the device.
