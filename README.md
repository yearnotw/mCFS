Way to apply the 'mCFS.patch' into Linux kernel.

1. Download source codes file 'public_sources.tbz2' of Jetpack 4.1.1 from the following URL.
https://developer.nvidia.com/embedded/linux-tegra-r311

2. Decompress the file
  $> tar xvf public_sources.tbz2
  $> cd <base path>/public_sources
  $> tar xvf kernel_src.tbz2
  $> cd <base path>/public_sources/kernel
  
3. Download a 'mCFS.patch' file and locate the file into '<base path>/public_sources/kernel'

4. Apply this patch
  $> cd <base path>/public_sources/kernel/kernel-4.9
  $> patch -p1 < ../mCFS.patch
