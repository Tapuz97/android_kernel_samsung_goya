# SM-T110 Android13 v42 kernel source checkpoint

WIP bring-up source, not an official LineageOS release or Nougat qualification.
Base:3c50b450af74d42f8c5d360c692f71002b3bb0af.
The installed v42/BOOT48 uses the standard-reclaim kernel with the paired native
hardware modules. Its logging/memory defaults were verified; physical display
wake, UI responsiveness and remaining hardware functions are not fully working.

This branch preserves the accumulated ARM syscall, Binder, SELinux, USB,
capabilities, network, ION, shared display/touch-I2C and logging work. The tested
full configuration is arch/arm/configs/t110_android13_v42_defconfig. Compile with
the recorded Android ARM GCC4.6 toolchain and the original image layout; this
commit alone is not a flash package. Preserve recovery and original firmware.

Device/bootstrap source and numbered patches:
https://github.com/Tapuz97/android_device_samsung_goyawifi/tree/t110/android13-v42-checkpoint

Before a full Android7.1 product build, validate legacy HWC1/EGL/gralloc ABI,
real GPU app drawing and physical panel/touch/system suspend-resume separately.
Do not import every Android13 compatibility backport as a Nougat requirement.

Generated modules/objects, scratch .orig files and ZIP-converted symlink
placeholders are excluded. Their exact private originals remain in the owner
backup. Upstream symlinks retain their original Git representation here.
