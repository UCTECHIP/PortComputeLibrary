Compute Library编译

使用scons交叉编译：

在Compute Library目录下

```
scons Werror=1 debug=0 asserts=0 neon=1 opencl=0 os=linux arch=riscv64 examples=1 -j8
```

库很大，正常编译很慢，可加 -jX，X=4~16来提高编译速度,根据实际情况决定。

编译完文件放在build。



使用qemu+gdb进行调试

​	如调试neon_cartoon_effect，

​	1.先将build里面的.so文件放入工具链

```
cd build
cp *.so .../riscv-gnu-toolchains-with-rvv-intrinsics-v0.9.0/sysroot/lib
```

​	2.然后使用工具链的qemu

不使用GDB

```
./qemu-riscv64 -L ../sysroot/ -cpu rv64,x-v=true,vlen=128,elen=64,vext_spec=v1.0 ~/project/ComputeLibrary/build/examples/neon_cartoon_effect
```

使用GDB

```
./qemu-riscv64 -L ../sysroot/ -cpu rv64,x-v=true,vlen=128,elen=64,vext_spec=v1.0 -g 8888
~/project/ComputeLibrary/build/examples/neon_cartoon_effect
```

​	3.使用工具链的gdb

```
./riscv64-unknown-linux-gnu-gdb -se ~/project/ComputeLibrary/build/examples/neon_cartoon_effect -d ~/project/ComputeLibrary
```

​	4.在gdb上连接port

```
target extended-remote localhost:8888（host根据qemu设置的值）
```

连接上后可以开始调试

