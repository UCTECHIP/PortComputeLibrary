​	该库是基于riscv-v-spec-0.9移植的ComputeLibrary。

​	移植的内在函数放于vector_transplant.h，主要考虑了移植的方向，牺牲了一些性能。

​	gemm的内联汇编更改为riscv的，目前支持float和部分整型。

​	使用说明参考doc/build.md。

