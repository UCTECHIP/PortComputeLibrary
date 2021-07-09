#ifndef __GCC_VECTOR_TRANSPLANT_H__
#define __GCC_VECTOR_TRANSPLANT_H__  1

#include <stdio.h>
#include <riscv_vector.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>


typedef signed char __v8qi __attribute__ ((vector_size (8)));
typedef __v8qi int8x8_t;
typedef unsigned char __uv8qi __attribute__ ((vector_size (8)));
typedef __uv8qi uint8x8_t;

typedef short __v4hi __attribute__ ((vector_size (8)));
typedef __v4hi int16x4_t;
typedef unsigned short __uv4hi __attribute__ ((vector_size (8)));
typedef __uv4hi uint16x4_t;

typedef int __v2si __attribute__ ((vector_size (8)));
typedef __v2si int32x2_t;
typedef unsigned int __uv2si __attribute__ ((vector_size (8)));
typedef __uv2si uint32x2_t;

typedef long __v1di __attribute__ ((vector_size (8)));
typedef __v1di int64x1_t;
typedef unsigned long __uv1di __attribute__ ((vector_size (8)));
typedef __uv1di uint64x1_t;

typedef float __v2sf __attribute__ ((vector_size (8)));
typedef __v2sf float32x2_t;

typedef struct int8x8x2_t {
    int8x8_t val[2];
} int8x8x2_t;

typedef struct uint8x8x2_t {
    uint8x8_t val[2];
} uint8x8x2_t;

typedef struct int8x8x3_t {
    int8x8_t val[3];
} int8x8x3_t;

typedef struct int16x4x2_t {
    int16x4_t val[2];
} int16x4x2_t;

typedef struct int16x4x3_t {
    int16x4_t val[3];
} int16x4x3_t;

typedef struct uint8x8x3_t {
    uint8x8_t val[3];
} uint8x8x3_t;

typedef struct int8x8x4_t {
    int8x8_t val[4];
} int8x8x4_t;

typedef struct int16x4x4_t {
    int16x4_t val[4];
} int16x4x4_t;

typedef struct uint16x4x4_t {
    uint16x4_t val[4];
} uint16x4x4_t;

typedef struct uint8x8x4_t {
    uint8x8_t val[4];
} uint8x8x4_t;

typedef struct int32x2x2_t {
    int32x2_t val[2];
} int32x2x2_t;

typedef struct uint16x4x2_t {
    uint16x4_t val[2];
} uint16x4x2_t;

typedef struct uint32x2x2_t {
    uint32x2_t val[2];
} uint32x2x2_t;

typedef struct float32x2x2_t {
    float32x2_t val[2];
} float32x2x2_t;

typedef signed char __v16qi __attribute__ ((vector_size (16)));
typedef __v16qi int8x16_t;
typedef unsigned char __uv16qi __attribute__ ((vector_size (16)));
typedef __uv16qi uint8x16_t;

typedef short __v8hi __attribute__ ((vector_size (16)));
typedef __v8hi int16x8_t;
typedef unsigned short __uv8hi __attribute__ ((vector_size (16)));
typedef __uv8hi uint16x8_t;

typedef int __v4si __attribute__ ((vector_size (16)));
typedef __v4si int32x4_t;
typedef unsigned int __uv4si __attribute__ ((vector_size (16)));
typedef __uv4si uint32x4_t;

typedef long __v2di __attribute__ ((vector_size (16)));
typedef __v2di int64x2_t;
typedef unsigned long __uv2di __attribute__ ((vector_size (16)));
typedef __uv2di uint64x2_t;

typedef float __v4sf __attribute__ ((vector_size (16)));
typedef __v4sf float32x4_t;
typedef double __v2df __attribute__ ((vector_size (16)));
typedef __v2df float64x2_t;


typedef struct int8x16x2_t {
    int8x16_t val[2];
} int8x16x2_t;

typedef struct uint8x16x2_t {
    uint8x16_t val[2];
} uint8x16x2_t;

typedef struct uint8x16x3_t {
    uint8x16_t val[3];
} uint8x16x3_t;

typedef struct uint8x16x4_t {
    uint8x16_t val[4];
} uint8x16x4_t;

typedef struct int16x8x2_t {
    int16x8_t val[2];
} int16x8x2_t;

typedef struct int16x8x4_t {
    int16x8_t val[4];
} int16x8x4_t;

typedef struct uint16x8x2_t {
    uint16x8_t val[2];
} uint16x8x2_t;

typedef struct int32x4x2_t {
    int32x4_t val[2];
} int32x4x2_t;

typedef struct int32x4x3_t {
    int32x4_t val[3];
} int32x4x3_t;

typedef struct int32x4x4_t {
    int32x4_t val[4];
} int32x4x4_t;

typedef struct uint32x4x2_t {
    uint32x4_t val[2];
} uint32x4x2_t;

typedef struct uint32x4x4_t {
    uint32x4_t val[4];
} uint32x4x4_t;

typedef struct float32x4x2_t {
    float32x4_t val[2];
} float32x4x2_t;

typedef struct float32x4x3_t {
    float32x4_t val[3];
} float32x4x3_t;

typedef struct float32x4x4_t {
    float32x4_t val[4];
} float32x4x4_t;

typedef struct int64x2x2_t {
    int64x2_t val[2];
} int64x2x2_t;


__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vld1_s8 (const int8_t * __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t b = vle8_v_i8m1(&__a[0]);
  int8x8_t c = {0};
  vse8_v_i8m1(&c[0],b);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vld1_s16 (const int16_t * __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t b = vle16_v_i16m1(&__a[0]);
  int16x4_t c = {0};
  vse16_v_i16m1(&c[0],b);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vld1_s32 (const int32_t * __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t b = vle32_v_i32m1(&__a[0]);
  int32x2_t c = {0};
  vse32_v_i32m1(&c[0],b);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vld1_u8 (const uint8_t * __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t b = vle8_v_u8m1(&__a[0]);
  uint8x8_t c = {0};
  vse8_v_u8m1(&c[0],b);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vld1_u16 (const uint16_t * __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t b = vle16_v_u16m1(&__a[0]);
  uint16x4_t c = {0};
  vse16_v_u16m1(&c[0],b);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vld1_u32 (const uint32_t * __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t b = vle32_v_u32m1(&__a[0]);
  uint32x2_t c = {0};
  vse32_v_u32m1(&c[0],b);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vld1_f32 (const float32_t * __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t b = vle32_v_f32m1(&__a[0]);
  float32x2_t c = {0};
  vse32_v_f32m1(&c[0],b);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vld1q_s8 (const int8_t * __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t vb = vle8_v_i8m1(&__a[0]);
  int8x16_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vld1q_s16 (const int16_t * __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t vb = vle16_v_i16m1(&__a[0]);
  int16x8_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vld1q_s32 (const int32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t vb = vle32_v_i32m1(&__a[0]);
  int32x4_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vld1q_u8 (const uint8_t * __a) 
{
  int number = 16;
  vsetvl_e8m1 (number); 
  vuint8m1_t vb = vle8_v_u8m1(__a);
  uint8x16_t b;
  vse8_v_u8m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vld1q_u16 (const uint16_t * __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vb = vle16_v_u16m1(&__a[0]);
  uint16x8_t b;
  vse16_v_u16m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vld1q_u32 (const uint32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number); 
  vuint32m1_t vb = vle32_v_u32m1(&__a[0]);
  uint32x4_t b;
  vse32_v_u32m1(&b[0],vb);
  return b;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vld1q_f32 (const float32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t vb = vle32_v_f32m1(&__a[0]);
  float32x4_t b;
  vse32_v_f32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vld1_dup_u8 (const uint8_t * __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t b = vmv_v_x_u8m1(__a[0]);
  uint8x8_t c = {0};
  vse8_v_u8m1(&c[0],b);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vld1_dup_s8 (const int8_t * __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t b = vmv_v_x_i8m1(__a[0]);
  int8x8_t c = {0};
  vse8_v_i8m1(&c[0],b);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vld1_dup_s16 (const int16_t * __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t b = vmv_v_x_i16m1(__a[0]);
  int16x4_t c = {0};
  vse16_v_i16m1(&c[0],b);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vld1_dup_f32 (const float32_t * __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t b = vfmv_v_f_f32m1(__a[0]);
  float32x2_t c = {0};
  vse32_v_f32m1(&c[0],b);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vld1q_dup_s32 (const int32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t vb = vmv_v_x_i32m1(__a[0]);
  int32x4_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vld1q_dup_f32 (const float32_t * __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vfloat32m1_t vb = vfmv_v_f_f32m1(__a[0]);
  float32x4_t b;
  vse32_v_f32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vld1q_lane_s32 (const int32_t *__a, int32x4_t __b, const int __c)
{
  int number = 1;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  int32x4_t a;
  vse32_v_i32m1(&a[0],va);
  if (0 <= __c && __c <= 3)
    __b[__c] = a[0];
  return __b;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vld1q_lane_f32 (const float32_t * __a, float32x4_t __b, const int __c)
{
  int number = 1; 
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  float32x4_t a;
  vse32_v_f32m1(&a[0],va);
  if (0 <= __c && __c <= 3)
    __b[__c] = a[0];
  return __b;
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1_s8 (int8_t * __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vse8_v_i8m1(&__a[0],vb); 
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1_s16 (int16_t * __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vse16_v_i16m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1_s32 (int32_t * __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vse32_v_i32m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1_u8 (uint8_t * __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vse8_v_u8m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1_u16 (uint16_t * __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vse16_v_u16m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1_u32 (uint32_t * __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vse32_v_u32m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1_f32 (float32_t * __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vse32_v_f32m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_u8 (uint8_t * __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vse8_v_u8m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_u16 (uint16_t * __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vse16_v_u16m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_u32 (uint32_t * __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vse32_v_u32m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_s8 (int8_t * __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vse8_v_i8m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_s16 (int16_t * __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vse16_v_i16m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_s32 (int32_t * __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vse32_v_i32m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_f32 (float32_t * __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vse32_v_f32m1(&__a[0],vb);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_lane_s8 (int8_t *__a, int8x16_t __b, const int __lane)
{
  int number = 1;
  vsetvl_e8m1 (number);
  if (0 <= __lane && __lane <= 15){
    __b[0] = __b[__lane];
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
    vse8_v_i8m1(&__a[0],vb);
  }
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_lane_s32 (int32_t *__a, int32x4_t __b, const int __lane)
{
  int number = 1;
  vsetvl_e32m1 (number);
  if (0 <= __lane && __lane <= 3){
//    __b[0] = __b[__lane];
//  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
//    vse32_v_i32m1(&__a[0],vb);
// @yexc
   *__a = __b[__lane];
  }
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst1q_lane_f32 (float32_t * __a, float32x4_t __b, const int __c)
{
  int number = 1;
  vsetvl_e32m1 (number);
  if (0 <= __c && __c <= 3){
    __b[0] = __b[__c];
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
    vse32_v_f32m1(&__a[0],vb);
  }
}

__extension__ static __inline uint8x8x2_t __attribute__ ((__always_inline__))
vld2_u8 (const uint8_t * __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  //vuint8m1x2_t vb = vlseg2e8_v_u8m1x2(__a);
  //uint8x8x2_t b;
  //vse8_v_u8m1(&b.v.val[0][0],vget_u8m1x2(vb, 0));
  //vse8_v_u8m1(&b.v.val[1][0],vget_u8m1x2(vb, 1));
  vuint8m1_t va = vlse8_v_u8m1(&__a[0],2);
  vuint8m1_t vb = vlse8_v_u8m1(&__a[1],2);
  uint8x8x2_t b;
  vse8_v_u8m1(&b.val[0][0],va);
  vse8_v_u8m1(&b.val[1][0],vb);
  return b;
}

__extension__ static __inline uint8x16x2_t __attribute__ ((__always_inline__))
vld2q_u8 (const uint8_t * __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  //vuint8m1x2_t vb = vlseg2e8_v_u8m1x2(__a);
  //uint8x16x2_t b;
  //vse8_v_u8m1(&b.v.val[0][0],vget_u8m1x2(vb, 0));
  //vse8_v_u8m1(&b.v.val[1][0],vget_u8m1x2(vb, 1));
  vuint8m1_t va = vlse8_v_u8m1(&__a[0],2);
  vuint8m1_t vb = vlse8_v_u8m1(&__a[1],2);
  uint8x16x2_t b;
  vse8_v_u8m1(&b.val[0][0],va);
  vse8_v_u8m1(&b.val[1][0],vb);
  return b;
}

__extension__ static __inline int16x8x2_t __attribute__ ((__always_inline__))
vld2q_s16 (const int16_t * __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  //vint16m1x2_t vb = vlseg2e16_v_i16m1x2(__a);
  //int16x8x2_t b;
  //vse16_v_i16m1(&b.v.val[0][0],vget_i16m1x2(vb, 0));
  //vse16_v_i16m1(&b.v.val[1][0],vget_i16m1x2(vb, 1));
  vint16m1_t va = vlse16_v_i16m1(&__a[0],4);
  vint16m1_t vb = vlse16_v_i16m1(&__a[1],4);
  int16x8x2_t b;
  vse16_v_i16m1(&b.val[0][0],va);
  vse16_v_i16m1(&b.val[1][0],vb);
  return b;
}

__extension__ static __inline int32x4x2_t __attribute__ ((__always_inline__))
vld2q_s32 (const int32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  //vint32m1x2_t vb = vlseg2e32_v_i32m1x2(__a);
  //int32x4x2_t b;
  //vse32_v_i32m1(&b.v.val[0][0],vget_i32m1x2(vb, 0));
  //vse32_v_i32m1(&b.v.val[1][0],vget_i32m1x2(vb, 1));
  vint32m1_t va = vlse32_v_i32m1(&__a[0],8);
  vint32m1_t vb = vlse32_v_i32m1(&__a[1],8);
  int32x4x2_t b;
  vse32_v_i32m1(&b.val[0][0],va);
  vse32_v_i32m1(&b.val[1][0],vb);
  return b;
}

__extension__ static __inline float32x4x2_t __attribute__ ((__always_inline__))
vld2q_f32 (const float32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  //vfloat32m1x2_t vb = vlseg2e32_v_f32m1x2(__a);
  //float32x4x2_t b;
  //vse32_v_f32m1(&b.v.val[0][0],vget_f32m1x2(vb, 0));
  //vse32_v_f32m1(&b.v.val[1][0],vget_f32m1x2(vb, 1));
  vfloat32m1_t va = vlse32_v_f32m1(&__a[0],8);
  vfloat32m1_t vb = vlse32_v_f32m1(&__a[1],8);
  float32x4x2_t b;
  vse32_v_f32m1(&b.val[0][0],va);
  vse32_v_f32m1(&b.val[1][0],vb);
  return b;
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst2_u8 (uint8_t * __a, uint8x8x2_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  //vuint8m1x2_t b;
  //b = vset_u8m1x2(b, 0, vle8_v_u8m1(&__b.v.val[0][0]));
  //b = vset_u8m1x2(b, 1, vle8_v_u8m1(&__b.v.val[1][0]));
  vuint8m1x2_t b = vcreate_u8m1x2(vle8_v_u8m1(&__b.val[0][0]), vle8_v_u8m1(&__b.val[1][0]));
  vsseg2e8_v_u8m1x2(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst2_s8 (int8_t * __a, int8x8x2_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  //vint8m1x2_t b;
  //b = vset_i8m1x2(b, 0, vle8_v_i8m1(&__b.v.val[0][0]));
  //b = vset_i8m1x2(b, 1, vle8_v_i8m1(&__b.v.val[1][0]));
  vint8m1x2_t b = vcreate_i8m1x2(vle8_v_i8m1(&__b.val[0][0]), vle8_v_i8m1(&__b.val[1][0]));
  vsseg2e8_v_i8m1x2(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst2q_u8 (uint8_t * __a, uint8x16x2_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1x2_t b = vcreate_u8m1x2(vle8_v_u8m1(&__b.val[0][0]), vle8_v_u8m1(&__b.val[1][0]));
  vsseg2e8_v_u8m1x2(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst2q_s16 (int16_t * __a, int16x8x2_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1x2_t b = vcreate_i16m1x2(vle16_v_i16m1(&__b.val[0][0]), vle16_v_i16m1(&__b.val[1][0]));
  vsseg2e16_v_i16m1x2(__a,b);
}

__extension__ static __inline uint8x16x3_t __attribute__ ((__always_inline__))
vld3q_u8 (const uint8_t * __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  //vuint8m1x3_t vb = vlseg3e8_v_u8m1x3(__a);
  //uint8x16x3_t b;
  //vse8_v_u8m1(&b.v.val[0][0],vget_u8m1x3(vb, 0));
  //vse8_v_u8m1(&b.v.val[1][0],vget_u8m1x3(vb, 1));
  //vse8_v_u8m1(&b.v.val[2][0],vget_u8m1x3(vb, 2));
  vuint8m1_t va = vlse8_v_u8m1(&__a[0],3);
  vuint8m1_t vb = vlse8_v_u8m1(&__a[1],3);
  vuint8m1_t vc = vlse8_v_u8m1(&__a[2],3);
  uint8x16x3_t b;
  vse8_v_u8m1(&b.val[0][0],va);
  vse8_v_u8m1(&b.val[1][0],vb);
  vse8_v_u8m1(&b.val[2][0],vc);
  return b;
}

__extension__ static __inline float32x4x3_t __attribute__ ((__always_inline__))
vld3q_f32 (const float32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  //vfloat32m1x3_t vb = vlseg3e32_v_f32m1x3(__a); 
  //float32x4x3_t b;
  //vse32_v_f32m1(&b.v.val[0][0],vget_f32m1x3(vb, 0));
  //vse32_v_f32m1(&b.v.val[1][0],vget_f32m1x3(vb, 1));
  //vse32_v_f32m1(&b.v.val[2][0],vget_f32m1x3(vb, 2));
  vfloat32m1_t va = vlse32_v_f32m1(&__a[0],12);
  vfloat32m1_t vb = vlse32_v_f32m1(&__a[1],12);
  vfloat32m1_t vc = vlse32_v_f32m1(&__a[2],12);
  float32x4x3_t b;
  vse32_v_f32m1(&b.val[0][0],va);
  vse32_v_f32m1(&b.val[1][0],vb);
  vse32_v_f32m1(&b.val[2][0],vc);
  return b;
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst3_u8 (uint8_t * __a, uint8x8x3_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  //vuint8m1x3_t b;
  //b = vset_u8m1x3(b, 0, vle8_v_u8m1(&__b.v.val[0][0]));
  //b = vset_u8m1x3(b, 1, vle8_v_u8m1(&__b.v.val[1][0]));
  //b = vset_u8m1x3(b, 2, vle8_v_u8m1(&__b.v.val[2][0]));
  vuint8m1x3_t b = vcreate_u8m1x3(vle8_v_u8m1(&__b.val[0][0]), vle8_v_u8m1(&__b.val[1][0]), vle8_v_u8m1(&__b.val[2][0]));
  vsseg3e8_v_u8m1x3(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst3q_u8 (uint8_t * __a, uint8x16x3_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1x3_t b = vcreate_u8m1x3(vle8_v_u8m1(&__b.val[0][0]), vle8_v_u8m1(&__b.val[1][0]), vle8_v_u8m1(&__b.val[2][0]));
  vsseg3e8_v_u8m1x3(__a,b);
}

__extension__ static __inline uint8x8x4_t __attribute__ ((__always_inline__))
vld4_u8 (const uint8_t * __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  //vuint8m1x4_t vb = vlseg4e8_v_u8m1x4(__a);
  //uint8x8x4_t b = {0};
  //vse8_v_u8m1(&b.v.val[0][0],vget_u8m1x4(vb, 0));
  //vse8_v_u8m1(&b.v.val[1][0],vget_u8m1x4(vb, 1));
  //vse8_v_u8m1(&b.v.val[2][0],vget_u8m1x4(vb, 2));
  //vse8_v_u8m1(&b.v.val[3][0],vget_u8m1x4(vb, 3));
  vuint8m1_t va = vlse8_v_u8m1(&__a[0],4);
  vuint8m1_t vb = vlse8_v_u8m1(&__a[1],4);
  vuint8m1_t vc = vlse8_v_u8m1(&__a[2],4);
  vuint8m1_t vd = vlse8_v_u8m1(&__a[3],4);
  uint8x8x4_t b;
  vse8_v_u8m1(&b.val[0][0],va);
  vse8_v_u8m1(&b.val[1][0],vb);
  vse8_v_u8m1(&b.val[2][0],vc);
  vse8_v_u8m1(&b.val[3][0],vd);
  return b;
}

__extension__ static __inline uint8x16x4_t __attribute__ ((__always_inline__))
vld4q_u8 (const uint8_t * __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  //vuint8m1x4_t vb = vlseg4e8_v_u8m1x4(__a);
  //uint8x16x4_t b;
  //vse8_v_u8m1(&b.v.val[0][0],vget_u8m1x4(vb, 0));
  //vse8_v_u8m1(&b.v.val[1][0],vget_u8m1x4(vb, 1));
  //vse8_v_u8m1(&b.v.val[2][0],vget_u8m1x4(vb, 2));
  //vse8_v_u8m1(&b.v.val[3][0],vget_u8m1x4(vb, 3));
  vuint8m1_t va = vlse8_v_u8m1(&__a[0],4);
  vuint8m1_t vb = vlse8_v_u8m1(&__a[1],4);
  vuint8m1_t vc = vlse8_v_u8m1(&__a[2],4);
  vuint8m1_t vd = vlse8_v_u8m1(&__a[3],4);
  uint8x16x4_t b;
  vse8_v_u8m1(&b.val[0][0],va);
  vse8_v_u8m1(&b.val[1][0],vb);
  vse8_v_u8m1(&b.val[2][0],vc);
  vse8_v_u8m1(&b.val[3][0],vd);
  return b;
}

__extension__ static __inline float32x4x4_t __attribute__ ((__always_inline__))
vld4q_f32 (const float32_t * __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  //vfloat32m1x4_t vb = vlseg4e32_v_f32m1x4(__a);
  //float32x4x4_t b;
  //vse32_v_f32m1(&b.v.val[0][0],vget_f32m1x4(vb, 0));
  //vse32_v_f32m1(&b.v.val[1][0],vget_f32m1x4(vb, 1));
  //vse32_v_f32m1(&b.v.val[2][0],vget_f32m1x4(vb, 2));
  //vse32_v_f32m1(&b.v.val[3][0],vget_f32m1x4(vb, 3));
  vfloat32m1_t va = vlse32_v_f32m1(&__a[0],16);
  vfloat32m1_t vb = vlse32_v_f32m1(&__a[1],16);
  vfloat32m1_t vc = vlse32_v_f32m1(&__a[2],16);
  vfloat32m1_t vd = vlse32_v_f32m1(&__a[3],16);
  float32x4x4_t b;
  vse32_v_f32m1(&b.val[0][0],va);
  vse32_v_f32m1(&b.val[1][0],vb);
  vse32_v_f32m1(&b.val[2][0],vc);
  vse32_v_f32m1(&b.val[3][0],vd);
  return b;
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst3_lane_u8 (uint8_t * __a, uint8x8x3_t __b, const int __c)
{
  int number = 3;
  vsetvl_e8m1 (number);
  uint8_t b[3];
  if (0 <= __c && __c <= 7){
    for(int i = 0;i < number;i++)
      b[i] = __b.val[i][__c];
    vuint8m1_t vb = vle8_v_u8m1(&b[0]);
    vse8_v_u8m1(&__a[0],vb);
  }
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst4_u8 (uint8_t * __a, uint8x8x4_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  //vuint8m1x4_t b;
  //b = vset_u8m1x4(b, 0, vle8_v_u8m1(&__b.v.val[0][0]));
  //b = vset_u8m1x4(b, 1, vle8_v_u8m1(&__b.v.val[1][0]));
  //b = vset_u8m1x4(b, 2, vle8_v_u8m1(&__b.v.val[2][0]));
  //b = vset_u8m1x4(b, 3, vle8_v_u8m1(&__b.v.val[3][0]));
  vuint8m1x4_t b = vcreate_u8m1x4(vle8_v_u8m1(&__b.val[0][0]), vle8_v_u8m1(&__b.val[1][0]), vle8_v_u8m1(&__b.val[2][0]), vle8_v_u8m1(&__b.val[3][0]));
  vsseg4e8_v_u8m1x4(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst4_u16 (uint16_t * __a, uint16x4x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  //vuint16m1x4_t b;
  //b = vset_u16m1x4(b, 0, vle16_v_u16m1(&__b.v.val[0][0]));
  //b = vset_u16m1x4(b, 1, vle16_v_u16m1(&__b.v.val[1][0]));
  //b = vset_u16m1x4(b, 2, vle16_v_u16m1(&__b.v.val[2][0]));
  //b = vset_u16m1x4(b, 3, vle16_v_u16m1(&__b.v.val[3][0]));
  vuint16m1x4_t b = vcreate_u16m1x4(vle16_v_u16m1(&__b.val[0][0]), vle16_v_u16m1(&__b.val[1][0]), vle16_v_u16m1(&__b.val[2][0]), vle16_v_u16m1(&__b.val[3][0]));
  vsseg4e16_v_u16m1x4(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst4q_u8 (uint8_t * __a, uint8x16x4_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1x4_t b = vcreate_u8m1x4(vle8_v_u8m1(&__b.val[0][0]), vle8_v_u8m1(&__b.val[1][0]), vle8_v_u8m1(&__b.val[2][0]), vle8_v_u8m1(&__b.val[3][0]));
  vsseg4e8_v_u8m1x4(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst4q_u32 (uint32_t * __a, uint32x4x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1x4_t b = vcreate_u32m1x4(vle32_v_u32m1(&__b.val[0][0]), vle32_v_u32m1(&__b.val[1][0]), vle32_v_u32m1(&__b.val[2][0]), vle32_v_u32m1(&__b.val[3][0]));
  vsseg4e32_v_u32m1x4(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst4q_f32 (float32_t * __a, float32x4x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1x4_t b = vcreate_f32m1x4(vle32_v_f32m1(&__b.val[0][0]), vle32_v_f32m1(&__b.val[1][0]), vle32_v_f32m1(&__b.val[2][0]), vle32_v_f32m1(&__b.val[3][0]));
  vsseg4e32_v_f32m1x4(__a,b);
}

__extension__ static __inline void __attribute__ ((__always_inline__))
vst4_lane_u8 (uint8_t * __a, uint8x8x4_t __b, const int __c)
{
  int number = 4;
  vsetvl_e8m1 (number);
  uint8_t b[4];
  if (0 <= __c && __c <= 7){
    for(int i = 0;i < number;i++)
      b[i] = __b.val[i][__c];
    vuint8m1_t vb = vle8_v_u8m1(&b[0]);;
    vse8_v_u8m1(&__a[0],vb);
  }
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vqabs_s8 (int8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vd;
  va = vle8_v_i8m1(&__a[0]);
  vint8m1_t b = vxor_vx_i8m1(va,-1);
  vint8m1_t c = vsadd_vx_i8m1(b,1);
  vd = vmax_vv_i8m1(va,c);
  int8x8_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vqabs_s16 (int16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vd;
  va = vle16_v_i16m1(&__a[0]);
  vint16m1_t b = vxor_vx_i16m1(va,-1);
  vint16m1_t c = vsadd_vx_i16m1(b,1);
  vd = vmax_vv_i16m1(va,c);
  int16x4_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vqabs_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vd;
  va = vle32_v_i32m1(&__a[0]);
  vint32m1_t b = vxor_vx_i32m1(va,-1);
  vint32m1_t c = vsadd_vx_i32m1(b,1);
  vd = vmax_vv_i32m1(va,c);
  int32x2_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vqabsq_s8 (int8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t b = vxor_vx_i8m1(va,-1);
  vint8m1_t c = vsadd_vx_i8m1(b,1);
  vint8m1_t vd = vmax_vv_i8m1(va,c);
  int8x16_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vqabsq_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t b = vxor_vx_i16m1(va,-1);
  vint16m1_t c = vsadd_vx_i16m1(b,1);
  vint16m1_t vd = vmax_vv_i16m1(va,c);
  int16x8_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqabsq_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t b = vxor_vx_i32m1(va,-1);
  vint32m1_t c = vsadd_vx_i32m1(b,1);
  vint32m1_t vd = vmax_vv_i32m1(va,c);
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vabs_s8 (int8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vd;
  va = vle8_v_i8m1(&__a[0]);
  vint8m1_t b = vxor_vx_i8m1(va,-1);
  vint8m1_t c = vadd_vx_i8m1(b,1);
  vd = vmax_vv_i8m1(va,c);
  int8x8_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vabs_s16 (int16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vd;
  va = vle16_v_i16m1(&__a[0]);
  vint16m1_t b = vxor_vx_i16m1(va,-1);
  vint16m1_t c = vadd_vx_i16m1(b,1);
  vd = vmax_vv_i16m1(va,c);
  int16x4_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vabs_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vd;
  va = vle32_v_i32m1(&__a[0]);
  vint32m1_t b = vxor_vx_i32m1(va,-1);
  vint32m1_t c = vadd_vx_i32m1(b,1);
  vd = vmax_vv_i32m1(va,c);
  int32x2_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vabs_f32 (float32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,b,vc;
  va = vle32_v_f32m1(&__a[0]);
  b = vfsgnjn_vv_f32m1(va,va);
  vc = vfmax_vv_f32m1(va,b);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vabsq_s8 (int8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t b = vxor_vx_i8m1(va,-1);
  vint8m1_t c = vadd_vx_i8m1(b,1);
  vint8m1_t vd = vmax_vv_i8m1(va,c);
  int8x16_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vabsq_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t b = vxor_vx_i16m1(va,-1);
  vint16m1_t c = vadd_vx_i16m1(b,1);
  vint16m1_t vd = vmax_vv_i16m1(va,c);
  int16x8_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vabsq_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t b = vxor_vx_i32m1(va,-1);
  vint32m1_t c = vadd_vx_i32m1(b,1);
  vint32m1_t vd = vmax_vv_i32m1(va,c);
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vabsq_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t b = vfsgnjn_vv_f32m1(va,va);
  vfloat32m1_t vc = vfmax_vv_f32m1(va,b);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
} 

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vreinterpretq_u8_s8 (int8x16_t __a)
{
  return (uint8x16_t)__a;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vreinterpretq_s8_s16 (int16x8_t __a)
{
  return (int8x16_t)__a;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vreinterpretq_s8_s32 (int32x4_t __a)
{
  return (int8x16_t) __a;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vreinterpretq_s32_s8 (int8x16_t __a)
{
  return (int32x4_t) __a;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vreinterpretq_u8_u64 (uint64x2_t __a)
{
  return (uint8x16_t) __a;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vreinterpretq_s8_u64 (uint64x2_t __a)
{
  return (int8x16_t) __a;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vreinterpretq_u64_s8 (int8x16_t __a)
{
  return (uint64x2_t) __a;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vreinterpret_u8_u16 (uint16x4_t __a)
{
  return (uint8x8_t)__a;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vreinterpret_u16_u8 (uint8x8_t __a)
{
  return (uint16x4_t)__a;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vreinterpret_s16_u16 (uint16x4_t __a)
{
  return (int16x4_t)__a;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vreinterpret_u16_u32 (uint32x2_t __a)
{
  return (uint16x4_t)__a;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vreinterpret_u32_u16 (uint16x4_t __a)
{
  return (uint32x2_t)__a;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vreinterpret_u32_s32 (int32x2_t __a)
{
  return (uint32x2_t)__a;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vreinterpretq_s16_u16 (uint16x8_t __a)
{
  return (int16x8_t)__a;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vreinterpretq_s16_s32 (int32x4_t __a)
{
  return (int16x8_t)__a;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vreinterpretq_s32_u32 (uint32x4_t __a)
{
  return (int32x4_t)__a;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vreinterpretq_u32_s32 (int32x4_t __a)
{
  return (uint32x4_t)__a;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vreinterpretq_u16_s16 (int16x8_t __a)
{
  return (uint16x8_t)__a;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vreinterpret_u64_u8 (uint8x8_t __a)
{
  return (uint64x1_t)__a;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vreinterpretq_u64_u8 (uint8x16_t __a)
{
  return (uint64x2_t)__a;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vreinterpretq_f32_s32 (int32x4_t __a)
{
  return (float32x4_t)__a;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vreinterpretq_s32_f32 (float32x4_t __a)
{
  return (int32x4_t)__a;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vreinterpretq_u32_f32 (float32x4_t __a)
{
  return (uint32x4_t)__a;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vreinterpretq_f32_u32 (uint32x4_t __a)
{
  return (float32x4_t)__a;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vreinterpret_u32_f32 (float32x2_t __a)
{
  return (uint32x2_t)__a;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vreinterpret_f32_u32 (uint32x2_t __a)
{
  return (float32x2_t)__a;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vsub_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vsub_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vsub_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vsub_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vsub_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vsub_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x1_t __attribute__ ((__always_inline__))
vsub_s64 (int64x1_t __a, int64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vsub_vv_i64m1(va,vb);
  int64x1_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vsub_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vsub_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vsub_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vsub_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vsub_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vsub_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vsub_u64 (uint64x1_t __a, uint64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vsub_vv_u64m1(va,vb);
  uint64x1_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vsub_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vfsub_vv_f32m1(va,vb);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vsubq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vsub_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vsubq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vsub_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vsubq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vsub_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vsubq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vsub_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vsubq_s64 (int64x2_t __a, int64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vsub_vv_i64m1(va,vb);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vsubq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vsub_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vsubq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vsub_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vsubq_u64 (uint64x2_t __a, uint64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vsub_vv_u64m1(va,vb);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vsubq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vfsub_vv_f32m1(va,vb);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vqsub_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vssub_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vqsub_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vssub_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vqsub_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vssub_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x1_t __attribute__ ((__always_inline__))
vqsub_s64 (int64x1_t __a, int64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vssub_vv_i64m1(va,vb);
  int64x1_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vqsub_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vssubu_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vqsub_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vssubu_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vqsub_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vssubu_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vqsub_u64 (uint64x1_t __a, uint64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vssubu_vv_u64m1(va,vb);
  uint64x1_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vqsubq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vssub_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vqsubq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vssub_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqsubq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number); 
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vssub_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vqsubq_s64 (int64x2_t __a, int64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vssub_vv_i64m1(va,vb);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vqsubq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vssubu_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vqsubq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vssubu_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vqsubq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vssubu_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vqsubq_u64 (uint64x2_t __a, uint64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vssubu_vv_u64m1(va,vb);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vsubl_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint16m2_t vc = vwsubu_vv_u16m2(va,vb);
  uint16x8_t c;
  vse16_v_u16m2(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vmovl_s8 (int8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint16m2_t vb = vwadd_vx_i16m2(va,0);
  int16x8_t b;
  vse16_v_i16m2(&b[0],vb);
  return b;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmovl_s16 (int16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint32m2_t vb = vwadd_vx_i32m2(va,0);
  int32x4_t b;
  vse32_v_i32m2(&b[0],vb);
  return b;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vmovl_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint64m2_t vb = vwadd_vx_i64m2(va,0);
  int64x2_t b;
  vse64_v_i64m2(&b[0],vb);
  return b;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmovl_u8 (uint8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint16m2_t vb = vwaddu_vx_u16m2(va,0);
  uint16x8_t b;
  vse16_v_u16m2(&b[0],vb);
  return b;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vmovl_u16 (uint16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint32m2_t vb = vwaddu_vx_u32m2(va,0);
  uint32x4_t b;
  vse32_v_u32m2(&b[0],vb);
  return b;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vmovl_u32 (uint32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint64m2_t vb = vwaddu_vx_u64m2(va,0);
  uint64x2_t b;
  vse64_v_u64m2(&b[0],vb);
  return b;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vget_low_s8 (int8x16_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  int8x8_t b;
  vse8_v_i8m1(&b[0],va);
  return b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vget_low_s16 (int16x8_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  int16x4_t b;
  vse16_v_i16m1(&b[0],va);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vget_low_s32 (int32x4_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  int32x2_t b;
  vse32_v_i32m1(&b[0],va);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vget_low_u8 (uint8x16_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  uint8x8_t b ;
  vse8_v_u8m1(&b[0],va);
  return b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vget_low_u16 (uint16x8_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  uint16x4_t b;
  vse16_v_u16m1(&b[0],va);
  return b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vget_low_u32 (uint32x4_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  uint32x2_t b;
  vse32_v_u32m1(&b[0],va);
  return b;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vget_low_f32 (float32x4_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  float32x2_t b;
  vse32_v_f32m1(&b[0],va);
  return b;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vget_high_s8 (int8x16_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  int8x8_t b;
  vint8m1_t c = vle8_v_i8m1(&__a[8]);
  vse8_v_i8m1(&b[0],c);
  return b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vget_high_s16 (int16x8_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  int16x4_t b;
  vint16m1_t c = vle16_v_i16m1(&__a[4]);
  vse16_v_i16m1(&b[0],c);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vget_high_s32 (int32x4_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  int32x2_t b;
  vint32m1_t c = vle32_v_i32m1(&__a[2]);
  vse32_v_i32m1(&b[0],c);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vget_high_u8 (uint8x16_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  uint8x8_t b;
  vuint8m1_t c = vle8_v_u8m1(&__a[8]);
  vse8_v_u8m1(&b[0],c);
  return b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vget_high_u16 (uint16x8_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  uint16x4_t b ;
  vuint16m1_t c = vle16_v_u16m1(&__a[4]);
  vse16_v_u16m1(&b[0],c);
  return b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vget_high_u32 (uint32x4_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  uint32x2_t b;
  vuint32m1_t c = vle32_v_u32m1(&__a[2]);
  vse32_v_u32m1(&b[0],c);
  return b;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vget_high_f32 (float32x4_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  float32x2_t b;
  vfloat32m1_t c = vle32_v_f32m1(&__a[2]);
  vse32_v_f32m1(&b[0],c);
  return b;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vabdq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vsub_vv_u8m1(va,vb);
  vuint8m1_t vd = vxor_vx_u8m1(vc,-1);
  vd = vsaddu_vx_u8m1(vd,1);
  uint8x16_t c,d,g;
  vse8_v_u8m1(&c[0],vc);
  vse8_v_u8m1(&d[0],vd);
  for(int i = 0; i < ( number); i++)
  {
    if(__a[i] < __b[i])
      g[i] = d[i];
    else
      g[i] = c[i];
  }
  return g;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vdup_n_s8 (int8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t vb;
  vb = vmv_v_x_i8m1(__a);
  int8x8_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vdup_n_s16 (int16_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t vb;
  vb = vmv_v_x_i16m1(__a);
  int16x4_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vdup_n_s32 (int32_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t vb;
  vb = vmv_v_x_i32m1(__a);
  int32x2_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vdup_n_u8 (uint8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vb;
  vb = vmv_v_x_u8m1(__a);
  uint8x8_t b;
  vse8_v_u8m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vdup_n_u16 (uint16_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vb;
  vb = vmv_v_x_u16m1(__a);
  uint16x4_t b;
  vse16_v_u16m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vdup_n_u32 (uint32_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vb;
  vb = vmv_v_x_u32m1(__a);
  uint32x2_t b;
  vse32_v_u32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vdup_n_u64 (uint64_t __a)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vuint64m1_t vb;
  vb = vmv_v_x_u64m1(__a);
  uint64x1_t b;
  vse64_v_u64m1(&b[0],vb);
  return b;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vdup_n_f32 (float32_t __a)
{
  int number = 2;
  vsetvl_e32m1 (4);
  vfloat32m1_t vb;
  vb = vfmv_v_f_f32m1(__a);
  vsetvl_e32m1 (number);
  float32x2_t b;
  vse32_v_f32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vdupq_n_s8 (int8_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t vc = vmv_v_x_i8m1(__a);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vdupq_n_s16 (int16_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t vc = vmv_v_x_i16m1(__a);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vdupq_n_u8 (uint8_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vc = vmv_v_x_u8m1(__a);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vdupq_n_u16 (uint16_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vc = vmv_v_x_u16m1(__a);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vdupq_n_u32 (uint32_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vc = vmv_v_x_u32m1(__a);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vdupq_n_s32 (int32_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t vc = vmv_v_x_i32m1(__a);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vdupq_n_u64 (uint64_t __a)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t vc = vmv_v_x_u64m1(__a);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vdupq_n_f32 (float32_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t vc = vfmv_v_f_f32m1(__a);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vqadd_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vsadd_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vqadd_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vsadd_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vqadd_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vsadd_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x1_t __attribute__ ((__always_inline__))
vqadd_s64 (int64x1_t __a, int64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vint64m1_t va,vb,vc;
  va = vle64_v_i64m1(&__a[0]);
  vb = vle64_v_i64m1(&__b[0]);
  vc = vsadd_vv_i64m1(va,vb);
  int64x1_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vqadd_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vsaddu_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vqadd_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vsaddu_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vqadd_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vsaddu_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vqadd_u64 (uint64x1_t __a, uint64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vuint64m1_t va,vb,vc;
  va = vle64_v_u64m1(&__a[0]);
  vb = vle64_v_u64m1(&__b[0]);
  vc = vsaddu_vv_u64m1(va,vb);
  uint64x1_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vqaddq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vsadd_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vqaddq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vsadd_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqaddq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vsadd_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vqaddq_s64 (int64x2_t __a, int64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vsadd_vv_i64m1(va,vb);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vqaddq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vsaddu_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vqaddq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vsaddu_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vqaddq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vsaddu_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vqaddq_u64 (uint64x2_t __a, uint64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vsaddu_vv_u64m1(va,vb);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vcvt_f32_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t vb;
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vb = vfcvt_f_x_v_f32m1(va);
  float32x2_t b;
  vse32_v_f32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vcvt_s32_f32 (float32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  asm("fsrmi  zero, 1\n");
  vint32m1_t vb = vfcvt_x_f_v_i32m1(va);
  asm("fsrmi  zero, 0\n");
  int32x2_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vcvtq_s32_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  volatile int test[4]= {0};//In order to be the same as arm
  asm(
    "li a0, 4\n"
    "vsetvli    a0,a0,e32,m1\n"
    "vle32.v    v0,(%0)\n"
    "vse32.v    v0,(%1)\n"
    :    
    :"r"(&__a[0]), "r"(test)
    :"a0"
  );
  for(int i=0;i<4;i++){
    if(0x7fc00000 == (test[i] & 0x7fc00000))
      __a[i] = 0; 
  }

  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
asm("fsrmi   zero,1\n");
  vint32m1_t vc = vfcvt_x_f_v_i32m1(va);
asm("fsrmi   zero,0\n");
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vcvtq_f32_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
//asm("fsrmi   zero,2\n");
  vfloat32m1_t vc = vfcvt_f_x_v_f32m1(va);
//asm("fsrmi   zero,0\n");
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcvtq_u32_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  volatile uint32_t test[4]= {0};//In order to be the same as arm
  asm(
    "li a0, 4\n"
    "vsetvli    a0,a0,e32,m1\n"
    "vle32.v    v0,(%0)\n"
    "vse32.v    v0,(%1)\n"
    :
    :"r"(&__a[0]), "r"(test)
    :"a0"
  );
  for(int i=0;i<4;i++){
    if(0x7fc00000 == (test[i] & 0x7fc00000))
      __a[i] = 0;
  }

  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
asm("fsrmi   zero,1\n");
  vuint32m1_t vc = vfcvt_xu_f_v_u32m1(va);
asm("fsrmi   zero,0\n");
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vcvtq_f32_u32 (uint32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
//asm("fsrmi   zero,2\n");
  vfloat32m1_t vc = vfcvt_f_xu_v_f32m1(va);
//asm("fsrmi   zero,0\n");
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vcvtnq_s32_f32 (float32x4_t __a)                                                
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vint32m1_t vc = vfcvt_x_f_v_i32m1(va);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vrndnq_f32 (float32x4_t __a)                                                    
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vint32m1_t b = vfcvt_x_f_v_i32m1(va);
  vfloat32m1_t vc = vfcvt_f_x_v_f32m1(b);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vmin_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vmin_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vmin_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vmin_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vmin_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vmin_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vmin_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vminu_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vmin_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vminu_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vmin_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vminu_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vmin_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vc = vfmin_vv_f32m1(va,vb);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vminq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vmin_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vminq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vmin_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vminq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vmin_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vminq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vminu_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vminq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vminu_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vminq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vminu_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vminq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vfmin_vv_f32m1(va,vb);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vpmin_s8 (int8x8_t __a, int8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc,vd;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vse8_v_i8m1(&vc[gvl],va);
  vse8_v_i8m1(&vc[number],vb);
  vsetvl_e8m1 (number*2);
  vd = vmin_vv_i8m1(vc,vslide1down_vx_i8m1(vc,0));
  vsetvl_e8m1 (number);
  vint8m1_t ve = vlse8_v_i8m1(&vd[gvl],2);
  int8x8_t e;
  vse8_v_i8m1(&e[0],ve);
  return e;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vpmin_s16 (int16x4_t __a, int16x4_t __b)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc,vd; 
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vse16_v_i16m1(&vc[gvl],va);
  vse16_v_i16m1(&vc[number],vb);
  vsetvl_e16m1 (number*2);
  vd = vmin_vv_i16m1(vc,vslide1down_vx_i16m1(vc,0));
  vsetvl_e16m1 (number);
  vint16m1_t ve = vlse16_v_i16m1(&vd[gvl],4);
  int16x4_t e;
  vse16_v_i16m1(&e[0],ve);
  return e;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vpmin_s32 (int32x2_t __a, int32x2_t __b)
{
/*
 // int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc,vd;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  int32x4_t c;
  vse32_v_i32m1(&c[0],va);
  vse32_v_i32m1(&c[number],vb);
//  vse32_v_i32m1(&vc[gvl],va);
//  vse32_v_i32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vc = vle32_v_i32m1(&c[0]);//
  vd = vmin_vv_i32m1(vc,vslide1down_vx_i32m1(vc,0));
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  vsetvl_e32m1 (number);
//  vint32m1_t ve = vlse32_v_i32m1(&vd[gvl],8);
  vint32m1_t ve = vlse32_v_i32m1(&d[0],8);
  int32x2_t e;
  vse32_v_i32m1(&e[0],ve);
  return e;
*/
  int32x2_t c;
  c[0] = __a[0] < __a[1] ? __a[0] : __a[1];
  c[1] = __b[0] < __b[1] ? __b[0] : __b[1];
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vpmin_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc,vd;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vse8_v_u8m1(&vc[gvl],va);
  vse8_v_u8m1(&vc[number],vb);
  vsetvl_e8m1 (number*2);
  vd = vminu_vv_u8m1(vc,vslide1down_vx_u8m1(vc,0));
  vsetvl_e8m1 (number);
  vuint8m1_t ve = vlse8_v_u8m1(&vd[gvl],2);
  uint8x8_t e;
  vse8_v_u8m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vpmin_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc,vd;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vse16_v_u16m1(&vc[gvl],va);
  vse16_v_u16m1(&vc[number],vb);
  vsetvl_e16m1 (number*2);
  vd = vminu_vv_u16m1(vc,vslide1down_vx_u16m1(vc,0));
  vsetvl_e16m1 (number);
  vuint16m1_t ve = vlse16_v_u16m1(&vd[gvl],4);
  uint16x4_t e;
  vse16_v_u16m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vpmin_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc,vd;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vse32_v_u32m1(&vc[gvl],va);
  vse32_v_u32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vd = vminu_vv_u32m1(vc,vslide1down_vx_u32m1(vc,0));
  vsetvl_e32m1 (number);
  vuint32m1_t ve = vlse32_v_u32m1(&vd[gvl],8);
  uint32x2_t e;
  vse32_v_u32m1(&e[0],ve);
  return e;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vpmin_f32 (float32x2_t __a, float32x2_t __b)
{
/*
 // int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc,vd;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  float32x4_t c;
  vse32_v_f32m1(&c[0],va);
  vse32_v_f32m1(&c[number],vb);
//  vse32_v_f32m1(&vc[gvl],va);
//  vse32_v_f32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vc = vle32_v_f32m1(&c[0]);//
  vd = vfmin_vv_f32m1(vc,vfslide1down_vf_f32m1(vc,0));
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  vsetvl_e32m1 (number);
//  vfloat32m1_t ve = vlse32_v_f32m1(&vd[gvl],8);
  vfloat32m1_t ve = vlse32_v_f32m1(&d[0],8);
  float32x2_t e;
  vse32_v_f32m1(&e[0],ve);
  return e;
*/
  float32x2_t c;
  c[0] = __a[0] < __a[1] ? __a[0] : __a[1];
  c[1] = __b[0] < __b[1] ? __b[0] : __b[1];
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vshlq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  volatile vint16m1_t c,d;
  c = vmax_vx_i16m1(vb,0);
  d = vmin_vx_i16m1(vb,0);
  d = vxor_vx_i16m1(d,-1);
  d = vsadd_vx_i16m1(d,1);
  vint16m1_t e = vsll_vv_i16m1(va,(vuint16m1_t)c);
  vint16m1_t vf = vsra_vv_i16m1(e,(vuint16m1_t)d);
  int16x8_t f;
  vse16_v_i16m1(&f[0],vf);
  return f;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vshlq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  volatile vint32m1_t c,d;
  c = vmax_vx_i32m1(vb,0);
  d = vmin_vx_i32m1(vb,0);
  d = vxor_vx_i32m1(d,-1);
  d = vsadd_vx_i32m1(d,1);
  vint32m1_t e = vsll_vv_i32m1(va,(vuint32m1_t)c);
  vint32m1_t vf = vsra_vv_i32m1(e,(vuint32m1_t)d);
  int32x4_t f;
  vse32_v_i32m1(&f[0],vf);
  return f;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vshlq_u16 (uint16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  volatile vint16m1_t c,d;
  c = vmax_vx_i16m1(vb,0);
  d = vmin_vx_i16m1(vb,0);
  d = vxor_vx_i16m1(d,-1);
  d = vsadd_vx_i16m1(d,1);
  vuint16m1_t e = vsll_vv_u16m1(va,(vuint16m1_t)c);
  vuint16m1_t vf = vsrl_vv_u16m1(e,(vuint16m1_t)d);
  uint16x8_t f;
  vse16_v_u16m1(&f[0],vf);
  return f;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vshlq_u32 (uint32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  volatile vint32m1_t c,d;
  c = vmax_vx_i32m1(vb,0);
  d = vmin_vx_i32m1(vb,0);
  d = vxor_vx_i32m1(d,-1);
  d = vsadd_vx_i32m1(d,1);
  vuint32m1_t e = vsll_vv_u32m1(va,(vuint32m1_t)c);
  vuint32m1_t vf = vsrl_vv_u32m1(e,(vuint32m1_t)d);
  uint32x4_t f;
  vse32_v_u32m1(&f[0],vf);
  return f;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vqshlq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  volatile vint16m1_t c,d;
  c = vmax_vx_i16m1(vb,0);
  d = vmin_vx_i16m1(vb,0);
  d = vxor_vx_i16m1(d,-1);
  d = vsadd_vx_i16m1(d,1);
  vint32m2_t e = vwmul_vx_i32m2(va,1);
  vuint32m2_t c1 = vwmulu_vx_u32m2((vuint16m1_t)c,1);
  vint32m2_t f = vsll_vv_i32m2(e,c1);
  vwrite_csr(RVV_VXRM, 0x02);
  vint16m1_t vg = vnclip_wv_i16m1(f,(vuint16m1_t)d);
  vwrite_csr(RVV_VXRM, 0x0);
  int16x8_t g;
  vse16_v_i16m1(&g[0],vg);
  return g;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqshlq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  volatile vint32m1_t c,d;
  c = vmax_vx_i32m1(vb,0);
  d = vmin_vx_i32m1(vb,0);
  d = vxor_vx_i32m1(d,-1);
  d = vsadd_vx_i32m1(d,1);
  vint64m2_t e = vwmul_vx_i64m2(va,1);
  vuint64m2_t c1 = vwmulu_vx_u64m2((vuint32m1_t)c,1);
  vint64m2_t f = vsll_vv_i64m2(e,c1);
  vwrite_csr(RVV_VXRM, 0x02);
  vint32m1_t vg = vnclip_wv_i32m1(f,(vuint32m1_t)d);
  vwrite_csr(RVV_VXRM, 0x0);
  int32x4_t g;
  vse32_v_i32m1(&g[0],vg);
  return g;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vqshlq_u16 (uint16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  volatile vint16m1_t c,d;
  c = vmax_vx_i16m1(vb,0);
  d = vmin_vx_i16m1(vb,0);
  d = vxor_vx_i16m1(d,-1);
  d = vsadd_vx_i16m1(d,1);
  vuint32m2_t e = vwmulu_vx_u32m2(va,1);
  vuint32m2_t c1 = vwmulu_vx_u32m2((vuint16m1_t)c,1);
  vuint32m2_t f = vsll_vv_u32m2(e,c1);
  vwrite_csr(RVV_VXRM, 0x02);
  vuint16m1_t vg = vnclipu_wv_u16m1(f,(vuint16m1_t)d);
  vwrite_csr(RVV_VXRM, 0x0);
  uint16x8_t g;
  vse16_v_u16m1(&g[0],vg);
  return g;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqrshlq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  volatile vint32m1_t c,d;
  c = vmax_vx_i32m1(vb,0);
  d = vmin_vx_i32m1(vb,0);
  d = vxor_vx_i32m1(d,-1);
  d = vsadd_vx_i32m1(d,1);
  vint64m2_t e = vwmul_vx_i64m2(va,1);
  vuint64m2_t c1 = vwmulu_vx_u64m2((vuint32m1_t)c,1);
  vint64m2_t f = vsll_vv_i64m2(e,c1);
  vint32m1_t vg = vnclip_wv_i32m1(f,(vuint32m1_t)d);
  int32x4_t g;
  vse32_v_i32m1(&g[0],vg);
  return g;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqshlq_n_s32 (int32x4_t __a, const int __b)
{
  int number = 4;
  vsetvl_e64m2 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint64m2_t c = vwmul_vx_i64m2(va,1);
  vint64m2_t d = vsll_vx_i64m2(c,(unsigned long)__b);
  vwrite_csr(RVV_VXRM, 0x02);
  vint32m1_t ve = vnclip_wx_i32m1(d,0);
  vwrite_csr(RVV_VXRM, 0x00);
  int32x4_t e;
  vse32_v_i32m1(&e[0],ve);
  return e;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vrshl_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  volatile vint32m1_t c,d;
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  c = vmax_vx_i32m1(vb,0);
  d = vmin_vx_i32m1(vb,0);
  d = vxor_vx_i32m1(d,-1);
  d = vsadd_vx_i32m1(d,1);
  vint32m1_t e = vsll_vv_i32m1(va,(vuint32m1_t)c);
  vint32m1_t vf = vssra_vv_i32m1(e,(vuint32m1_t)d);
  int32x2_t f;
  vse32_v_i32m1(&f[0],vf);
  return f;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vrshlq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  volatile vint32m1_t c,d;
  c = vmax_vx_i32m1(vb,0);
  d = vmin_vx_i32m1(vb,0);
  d = vxor_vx_i32m1(d,-1);
  d = vsadd_vx_i32m1(d,1);
  vint32m1_t e = vsll_vv_i32m1(va,(vuint32m1_t)c);
  vint32m1_t vf = vssra_vv_i32m1(e,(vuint32m1_t)d);
  int32x4_t f;
  vse32_v_i32m1(&f[0],vf);
  return f;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vshl_n_u32 (uint32x2_t __a, const int __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vc = vsll_vx_u32m1(va,(unsigned int)__b);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vshlq_n_s32 (int32x4_t __a, const int __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vc = vsll_vx_i32m1(va,(unsigned int)__b);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vshlq_n_u32 (uint32x4_t __a, const int __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vc = vsll_vx_u32m1(va,(unsigned int)__b);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vshll_n_u8 (uint8x8_t __a, const int __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint16m2_t vc = vwmulu_vx_u16m2(va,1);
  vuint16m2_t vd = vsll_vx_u16m2(vc,(unsigned short)__b);
  uint16x8_t d;
  vse16_v_u16m2(&d[0],vd);
  return d;

}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vshll_n_u16 (uint16x4_t __a, const int __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint32m2_t vc = vwmulu_vx_u32m2(va,1);
  vuint32m2_t vd = vsll_vx_u32m2(vc,(unsigned int)__b);
  uint32x4_t d;
  vse32_v_u32m2(&d[0],vd);
  return d;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vshr_n_s32 (int32x2_t __a, const int __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vc = vsra_vx_i32m1(va,(unsigned int)__b);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vshrq_n_s32 (int32x4_t __a, const int __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vc = vsra_vx_i32m1(va,(unsigned int)__b);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vshrq_n_u32 (uint32x4_t __a, const int __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vc = vsrl_vx_u32m1(va,(unsigned int)__b);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vrshrq_n_s64 (int64x2_t __a, const int __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vc = vssra_vx_i64m1(va,(unsigned long)__b);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vqshrun_n_s16 (int16x8_t __a, const int __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m2_t va = vle16_v_i16m2(&__a[0]);
  vint16m2_t vb = vmax_vx_i16m2(va,0);
  vwrite_csr(RVV_VXRM, 0x02);
  vuint8m1_t vc = vnclipu_wx_u8m1((vuint16m2_t)vb,(unsigned char)__b);
  vwrite_csr(RVV_VXRM, 0x00);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vqshrn_n_u16 (uint16x8_t __a, const int __b)
{
  int number = 8;
  vsetvl_e16m2 (number);
  vuint16m2_t va = vle16_v_u16m2(&__a[0]);
  vwrite_csr(RVV_VXRM, 0x02);
  vuint8m1_t vc = vnclipu_wx_u8m1(va,(unsigned char)__b);
  vwrite_csr(RVV_VXRM, 0x00);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}


__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vmul_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vmul_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vmul_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vmul_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vmul_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vmul_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vmul_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vmul_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vmul_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vmul_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vmul_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vmul_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vmul_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vc = vfmul_vv_f32m1(va,vb);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vmulq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vmul_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vmulq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vmul_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmulq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vmul_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vmulq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vmul_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmulq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vmul_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vmulq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vmul_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmulq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vfmul_vv_f32m1(va,vb);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vmul_n_f32 (float32x2_t __a, float32_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vc = vfmul_vf_f32m1(va,__b);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vmulq_n_s16 (int16x8_t __a, int16_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vc = vmul_vx_i16m1(va,__b);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmulq_n_s32 (int32x4_t __a, int32_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vc = vmul_vx_i32m1(va,__b);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmulq_n_u16 (uint16x8_t __a, uint16_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vc = vmul_vx_u16m1(va,__b);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
  
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmulq_n_f32 (float32x4_t __a, float32_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vc = vfmul_vf_f32m1(va,__b);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmull_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb;
  vint32m2_t vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vwmul_vv_i32m2(va,vb);
  int32x4_t c;
  vse32_v_i32m2(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmull_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb;
  vuint16m2_t vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vwmulu_vv_u16m2(va,vb);
  uint16x8_t c;
  vse16_v_u16m2(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmull_n_s16 (int16x4_t __a, int16_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint32m2_t vb = vwmul_vx_i32m2(va,__b);
  int32x4_t b;
  vse32_v_i32m2(&b[0],vb);
  return b;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vmla_s8 (int8x8_t __a, int8x8_t __b, int8x8_t __c)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc,vd;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vle8_v_i8m1(&__c[0]);
  vd = vmacc_vv_i8m1(va,vc,vb);
  int8x8_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vmla_s16 (int16x4_t __a, int16x4_t __b, int16x4_t __c)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc,vd;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vle16_v_i16m1(&__c[0]);
  vd = vmacc_vv_i16m1(va,vc,vb);
  int16x4_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vmla_s32 (int32x2_t __a, int32x2_t __b, int32x2_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc,vd;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vle32_v_i32m1(&__c[0]);
  vd = vmacc_vv_i32m1(va,vc,vb);
  int32x2_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vmla_u8 (uint8x8_t __a, uint8x8_t __b, uint8x8_t __c)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc,vd;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vle8_v_u8m1(&__c[0]);
  vd = vmacc_vv_u8m1(va,vc,vb);
  uint8x8_t d;
  vse8_v_u8m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vmla_u16 (uint16x4_t __a, uint16x4_t __b, uint16x4_t __c)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc,vd;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vle16_v_u16m1(&__c[0]);
  vd = vmacc_vv_u16m1(va,vc,vb);
  uint16x4_t d;
  vse16_v_u16m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vmla_u32 (uint32x2_t __a, uint32x2_t __b, uint32x2_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc,vd;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vle32_v_u32m1(&__c[0]);
  vd = vmacc_vv_u32m1(va,vc,vb);
  uint32x2_t d;
  vse32_v_u32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vmla_f32 (float32x2_t __a, float32x2_t __b, float32x2_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc,vd;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vc = vle32_v_f32m1(&__c[0]);
  vd = vfmacc_vv_f32m1(va,vb,vc);
  float32x2_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vmlaq_s8 (int8x16_t __a, int8x16_t __b, int8x16_t __c)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vle8_v_i8m1(&__c[0]);
  vint8m1_t vd = vmacc_vv_i8m1(va,vc,vb);
  int8x16_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vmlaq_s16 (int16x8_t __a, int16x8_t __b, int16x8_t __c)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vle16_v_i16m1(&__c[0]);
  vint16m1_t vd = vmacc_vv_i16m1(va,vc,vb);
  int16x8_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmlaq_s32 (int32x4_t __a, int32x4_t __b, int32x4_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vle32_v_i32m1(&__c[0]);
  vint32m1_t vd = vmacc_vv_i32m1(va,vc,vb);
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vmlaq_u8 (uint8x16_t __a, uint8x16_t __b, uint8x16_t __c)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vle8_v_u8m1(&__c[0]);
  vuint8m1_t vd = vmacc_vv_u8m1(va,vc,vb);
  uint8x16_t d;
  vse8_v_u8m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmlaq_u16 (uint16x8_t __a, uint16x8_t __b, uint16x8_t __c)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vle16_v_u16m1(&__c[0]);
  vuint16m1_t vd = vmacc_vv_u16m1(va,vc,vb);
  uint16x8_t d;
  vse16_v_u16m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vmlaq_u32 (uint32x4_t __a, uint32x4_t __b, uint32x4_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vle32_v_u32m1(&__c[0]);
  vuint32m1_t vd = vmacc_vv_u32m1(va,vc,vb);
  uint32x4_t d;
  vse32_v_u32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmlaq_f32 (float32x4_t __a, float32x4_t __b, float32x4_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vle32_v_f32m1(&__c[0]);
  vfloat32m1_t vd = vfmacc_vv_f32m1(va,vc,vb);
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vmla_n_f32 (float32x2_t __a, float32x2_t __b, float32_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vd = vfmacc_vf_f32m1(va,__c,vb);
  float32x2_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmlaq_n_u16 (uint16x8_t __a, uint16x8_t __b, uint16_t __c)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vd = vmacc_vx_u16m1(va,__c,vb);
  uint16x8_t d;
  vse16_v_u16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vmlaq_n_s16 (int16x8_t __a, int16x8_t __b, int16_t __c)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vd = vmacc_vx_i16m1(va,__c,vb);
  int16x8_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmlaq_n_s32 (int32x4_t __a, int32x4_t __b, int32_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vd = vmacc_vx_i32m1(va,__c,vb);
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmlaq_n_f32 (float32x4_t __a, float32x4_t __b, float32_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vd = vfmacc_vf_f32m1(va,__c,vb);
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmlaq_lane_f32 (float32x4_t __a, float32x4_t __b, float32x2_t __c, const int __d)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vd = vfmacc_vf_f32m1(va,__c[__d],vb);
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmlal_s16 (int32x4_t __a, int16x4_t __b, int16x4_t __c)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t vb,vc;
  vint32m2_t va;
  va = vle32_v_i32m2(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vle16_v_i16m1(&__c[0]);
  vint32m2_t vd = vwmacc_vv_i32m2(va,vc,vb);
  int32x4_t d;
  vse32_v_i32m2(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmlal_n_s16 (int32x4_t __a, int16x4_t __b, int16_t __c)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint32m2_t va = vle32_v_i32m2(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint32m2_t vd = vwmacc_vx_i32m2(va,__c,vb);
  int32x4_t d;
  vse32_v_i32m2(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmlal_lane_s16 (int32x4_t __a, int16x4_t __b, int16x4_t __c, const int __d)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t vb;
  vint32m2_t va;
  va = vle32_v_i32m2(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vint32m2_t vd = vwmacc_vx_i32m2(va,__c[__d],vb);
  int32x4_t d;
  vse32_v_i32m2(&d[0],vd);
  return d;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vmlal_lane_u16 (uint32x4_t __a, uint16x4_t __b, uint16x4_t __c, const int __d)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vb;
  vuint32m2_t va;
  va = vle32_v_u32m2(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vuint32m2_t vd = vwmaccu_vx_u32m2(va,__c[__d],vb);
  uint32x4_t d;
  vse32_v_u32m2(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmlsq_f32 (float32x4_t __a, float32x4_t __b, float32x4_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vle32_v_f32m1(&__c[0]);
  vfloat32m1_t vd = vfnmsac_vv_f32m1(va,vb,vc);
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmlsq_n_f32 (float32x4_t __a, float32x4_t __b, float32_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vd = vfnmsac_vf_f32m1(va,__c,vb);
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vmls_n_f32 (float32x2_t __a, float32x2_t __b, float32_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vd = vfnmsac_vf_f32m1(va,__c,vb);
  float32x2_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcombine_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],va);
  vse16_v_u16m1(&c[4],vb);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcombine_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],va);
  vse8_v_u8m1(&c[8],vb);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcombine_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],va);
  vse32_v_u32m1(&c[2],vb);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vcombine_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  int8x16_t c ;
  vse8_v_i8m1(&c[0],va);
  vse8_v_i8m1(&c[8],vb);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vcombine_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  int16x8_t c;
  vse16_v_i16m1(&c[0],va);
  vse16_v_i16m1(&c[4],vb);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vcombine_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  int32x4_t c;
  vse32_v_i32m1(&c[0],va);
  vse32_v_i32m1(&c[2],vb);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vcombine_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  float32x4_t c;
  vse32_v_f32m1(&c[0],va);
  vse32_v_f32m1(&c[2],vb);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vmovn_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m2 (number);
  vint16m2_t va = vle16_v_i16m2(&__a[0]);
  vint8m1_t vb = vnsra_wx_i8m1(va,0);
  int8x8_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vmovn_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m2 (number);
  vint32m2_t va = vle32_v_i32m2(&__a[0]);
  vint16m1_t vb = vnsra_wx_i16m1(va,0);
  int16x4_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vmovn_s64 (int64x2_t __a)
{
  int number = 2;
  vsetvl_e64m2 (number);
  vint64m2_t va = vle64_v_i64m2(&__a[0]);
  vint32m1_t vb = vnsra_wx_i32m1(va,0);
  int32x2_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vmovn_u16 (uint16x8_t __a)
{
  int number = 8;
  vsetvl_e16m2 (number);
  vuint16m2_t va = vle16_v_u16m2(&__a[0]);
  vuint8m1_t vb = vnsrl_wx_u8m1(va,0);
  uint8x8_t b;
  vse8_v_u8m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vmovn_u32 (uint32x4_t __a)
{
  int number = 4;
  vsetvl_e32m2 (number);
  vuint32m2_t va = vle32_v_u32m2(&__a[0]);
  vuint16m1_t vb = vnsrl_wx_u16m1(va,0);
  uint16x4_t b;
  vse16_v_u16m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vmovn_u64 (uint64x2_t __a)
{
  int number = 2;
  vsetvl_e64m2 (number);
  vuint64m2_t va = vle64_v_u64m2(&__a[0]);
  vuint32m1_t vb = vnsrl_wx_u32m1(va,0);
  uint32x2_t b;
  vse32_v_u32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vqmovn_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m2 (number);
  vint16m2_t va = vle16_v_i16m2(&__a[0]);
  vwrite_csr(RVV_VXRM, 0x02);
  vint8m1_t vb = vnclip_wx_i8m1(va,0);
  vwrite_csr(RVV_VXRM, 0x00);
  int8x8_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vqmovn_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m2 (number);
  vint32m2_t va = vle32_v_i32m2(&__a[0]);
  vwrite_csr(RVV_VXRM, 0x02);
  vint16m1_t vb = vnclip_wx_i16m1(va,0);
  vwrite_csr(RVV_VXRM, 0x00);
  int16x4_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vqmovn_s64 (int64x2_t __a)
{
  int number = 2;
  vsetvl_e64m2 (number);
  vint64m2_t va = vle64_v_i64m2(&__a[0]);
  vwrite_csr(RVV_VXRM, 0x02);
  vint32m1_t vb = vnclip_wx_i32m1(va,0);
  vwrite_csr(RVV_VXRM, 0x00);
  int32x2_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vqmovn_u16 (uint16x8_t __a)
{
  int number = 8;
  vsetvl_e16m2 (number);
  vuint16m2_t va = vle16_v_u16m2(&__a[0]);
  vwrite_csr(RVV_VXRM, 0x02);
  vuint8m1_t vb = vnclipu_wx_u8m1(va,0);
  vwrite_csr(RVV_VXRM, 0x00);
  uint8x8_t b;
  vse8_v_u8m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vqmovn_u32 (uint32x4_t __a)
{
  int number = 4;
  vsetvl_e32m2 (number);
  vuint32m2_t va = vle32_v_u32m2(&__a[0]);
  vwrite_csr(RVV_VXRM, 0x02);
  vuint16m1_t vb = vnclipu_wx_u16m1(va,0);
  vwrite_csr(RVV_VXRM, 0x00);
  uint16x4_t b;
  vse16_v_u16m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vqmovn_u64 (uint64x2_t __a)
{
  int number = 2;
  vsetvl_e64m2 (number);
  vuint64m2_t va = vle64_v_u64m2(&__a[0]);
  vwrite_csr(RVV_VXRM, 0x02);
  vuint32m1_t vb = vnclipu_wx_u32m1(va,0);
  vwrite_csr(RVV_VXRM, 0x00);
  uint32x2_t b;
  vse32_v_u32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vqmovun_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m2 (number);
  vint16m2_t va = vle16_v_i16m2(&__a[0]);
  vint16m2_t vb = vmax_vx_i16m2(va,0);
  vuint8m1_t vc = vnclipu_wx_u8m1((vuint16m2_t)vb,0);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vqmovun_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m2 (number);
  vint32m2_t va = vle32_v_i32m2(&__a[0]);
  vint32m2_t vb = vmax_vx_i32m2(va,0);
  vuint16m1_t vc = vnclipu_wx_u16m1((vuint32m2_t)vb,0);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vqmovun_s64 (int64x2_t __a)
{
  int number = 2;
  vsetvl_e64m2 (number);
  vint64m2_t va  = vle64_v_i64m2(&__a[0]);
  vint64m2_t vb = vmax_vx_i64m2(va,0);
  vuint32m1_t vc = vnclipu_wx_u32m1((vuint64m2_t)vb,0);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vmax_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vmax_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vmax_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vmax_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vmax_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vmax_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vmax_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vmaxu_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vmax_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vmaxu_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vmax_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vmaxu_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vmax_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vc = vfmax_vv_f32m1(va,vb);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vmaxq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vmax_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vmaxq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vmax_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmaxq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vmax_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vmaxq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vmaxu_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmaxq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vmaxu_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vmaxq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vmaxu_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vmaxq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4; 
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vfmax_vv_f32m1(va,vb);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32_t __attribute__ ((__always_inline__))
vmaxvq_f32 (float32x4_t __a)                                                    
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  volatile vfloat32m1_t b = vzero_f32m1();
  b = vfmv_s_f_f32m1(b, -3.4E+38);
  volatile vfloat32m1_t vc = vzero_f32m1();
  vc = vfredmax_vs_f32m1_f32m1(vc,va,b);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vpmax_s8 (int8x8_t __a, int8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vse8_v_i8m1(&vc[gvl],va);
  vse8_v_i8m1(&vc[number],vb);
  vsetvl_e8m1 (number*2);
  vint8m1_t vd = vmax_vv_i8m1(vc,vslide1down_vx_i8m1(vc,0));
  vsetvl_e8m1 (number);
  vint8m1_t ve = vlse8_v_i8m1(&vd[gvl],2);
  int8x8_t e;
  vse8_v_i8m1(&e[0],ve);
  return e;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vpmax_s16 (int16x4_t __a, int16x4_t __b)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vse16_v_i16m1(&vc[gvl],va);
  vse16_v_i16m1(&vc[number],vb);
  vsetvl_e16m1 (number*2);
  vint16m1_t vd = vmax_vv_i16m1(vc,vslide1down_vx_i16m1(vc,0));
  vsetvl_e16m1 (number);
  vint16m1_t ve = vlse16_v_i16m1(&vd[gvl],4);
  int16x4_t e;
  vse16_v_i16m1(&e[0],ve);
  return e;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vpmax_s32 (int32x2_t __a, int32x2_t __b)
{
/*
  //int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  int32x4_t c;
  vse32_v_i32m1(&c[0],va);
  vse32_v_i32m1(&c[number],vb);
  //vse32_v_i32m1(&vc[gvl],va);
  //vse32_v_i32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vc = vle32_v_i32m1(&c[0]);//
  vint32m1_t vd = vmax_vv_i32m1(vc,vslide1down_vx_i32m1(vc,0));
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  vsetvl_e32m1 (number);
  //vint32m1_t ve = vlse32_v_i32m1(&vd[gvl],8);
  vint32m1_t ve = vlse32_v_i32m1(&d[0],8);
  int32x2_t e;
  vse32_v_i32m1(&e[0],ve);
  return e;
*/
  int32x2_t c;
  c[0] = __a[0] > __a[1] ? __a[0] : __a[1];
  c[1] = __b[0] > __b[1] ? __b[0] : __b[1];
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vpmax_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vse8_v_u8m1(&vc[gvl],va);
  vse8_v_u8m1(&vc[number],vb);
  vsetvl_e8m1 (number*2);
  vuint8m1_t vd = vmaxu_vv_u8m1(vc,vslide1down_vx_u8m1(vc,0));
  vsetvl_e8m1 (number);
  vuint8m1_t ve = vlse8_v_u8m1(&vd[gvl],2);
  uint8x8_t e;
  vse8_v_u8m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vpmax_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vse16_v_u16m1(&vc[gvl],va);
  vse16_v_u16m1(&vc[number],vb);
  vsetvl_e16m1 (number*2);
  vuint16m1_t vd = vmaxu_vv_u16m1(vc,vslide1down_vx_u16m1(vc,0));
  vsetvl_e16m1 (number);
  vuint16m1_t ve = vlse16_v_u16m1(&vd[gvl],4);
  uint16x4_t e;
  vse16_v_u16m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vpmax_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vse32_v_u32m1(&vc[gvl],va);
  vse32_v_u32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vuint32m1_t vd = vmaxu_vv_u32m1(vc,vslide1down_vx_u32m1(vc,0));
  vsetvl_e32m1 (number);
  vuint32m1_t ve = vlse32_v_u32m1(&vd[gvl],8);
  uint32x2_t e = {0, 0};
  vse32_v_u32m1(&e[0],ve);
  return e;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vpmax_f32 (float32x2_t __a, float32x2_t __b)
{/* 
  //int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  float32x4_t c;
  vse32_v_f32m1(&c[0],va);
  vse32_v_f32m1(&c[number],vb);
  //vse32_v_f32m1(&vc[gvl],va);
  //vse32_v_f32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vc = vle32_v_f32m1(&c[0]);//
  vfloat32m1_t vd = vfmax_vv_f32m1(vc,vfslide1down_vf_f32m1(vc,0));
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  vsetvl_e32m1 (number);
  //vfloat32m1_t ve = vlse32_v_f32m1(&vd[gvl],8);
  vfloat32m1_t ve = vlse32_v_f32m1(&d[0],8);
  float32x2_t e;
  vse32_v_f32m1(&e[0],ve);
  return e;
*/
  float32x2_t c;
  c[0] = __a[0] > __a[1] ? __a[0] : __a[1];
  c[1] = __b[0] > __b[1] ? __b[0] : __b[1];
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vqrdmulh_n_s32 (int32x2_t __a, int32_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  uint32_t n = 32;
  vint64m2_t vb = vwmul_vx_i64m2(va,__b);
  vint64m2_t ve = vmul_vx_i64m2(vb,2);
  vint32m1_t vc = vnclip_wx_i32m1(ve,n);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqrdmulhq_n_s32 (int32x4_t __a, int32_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  uint32_t n = 32;
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint64m2_t vc = vwmul_vx_i64m2(va,__b);
  vint64m2_t ve = vmul_vx_i64m2(vc,2);
  vint32m1_t vd = vnclip_wx_i32m1(ve,n);
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vqrdmulhq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  uint32_t n = 32;
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint64m2_t vc = vwmul_vv_i64m2(va,vb);
  vint64m2_t ve = vmul_vx_i64m2(vc,2);
  vint32m1_t vd = vnclip_wx_i32m1(ve,n);
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
} 

__extension__ static __inline int8_t __attribute__ ((__always_inline__))
vget_lane_s8 (int8x8_t __a, const int __b)
{
  if (__b < 8 && __b >= 0 )
         return __a[__b];
  else
  {
      printf("lane out of range");
      return 1;
  }
}

__extension__ static __inline int16_t __attribute__ ((__always_inline__))
vget_lane_s16 (int16x4_t __a, const int __b)
{
  if (__b < 4 && __b >= 0 )
         return __a[__b];
  else
  {
      printf("lane out of range");
      return 1;
  }
}

__extension__ static __inline int32_t __attribute__ ((__always_inline__))
vget_lane_s32 (int32x2_t __a, const int __b)
{
  if (__b < 2 && __b >= 0 )
         return __a[__b];
  else
  {
      printf("lane out of range");
      return 1;
  }
}

__extension__ static __inline uint8_t __attribute__ ((__always_inline__))
vget_lane_u8 (uint8x8_t __a, const int __b)
{
  if (__b < 8 && __b >= 0 )
         return __a[__b];
  else
  {
      printf("lane out of range");
      return 1;
  }
}

__extension__ static __inline uint16_t __attribute__ ((__always_inline__))
vget_lane_u16 (uint16x4_t __a, const int __b)
{
  if (__b < 4 && __b >= 0 )
         return __a[__b];
  else
  {
      printf("lane out of range");
      return 1;
  }
}

__extension__ static __inline uint32_t __attribute__ ((__always_inline__))
vget_lane_u32 (uint32x2_t __a, const int __b)
{
  if (__b < 2 && __b >= 0 )
         return __a[__b];
  else
  {
      printf("lane out of range");
      return 1;
  }
}

__extension__ static __inline uint64_t __attribute__ ((__always_inline__))
vget_lane_u64 (uint64x1_t __a, const int __b)
{
  if (__b < 1 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline float32_t __attribute__ ((__always_inline__))
vget_lane_f32 (float32x2_t __a, const int __b)
{
  if (__b < 2 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline int8_t __attribute__ ((__always_inline__))
vgetq_lane_s8 (int8x16_t __a, const int __b)
{
  if (__b < 16 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline int16_t __attribute__ ((__always_inline__))
vgetq_lane_s16 (int16x8_t __a, const int __b)
{
  if (__b < 8 && __b >= 0 )
    return __a[__b];
  else 
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline int32_t __attribute__ ((__always_inline__))
vgetq_lane_s32 (int32x4_t __a, const int __b)
{
  if (__b < 4 && __b >= 0 )
    return __a[__b];
  else 
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline int64_t __attribute__ ((__always_inline__))
vgetq_lane_s64 (int64x2_t __a, const int __b)
{
  if (__b < 2 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline uint8_t __attribute__ ((__always_inline__))
vgetq_lane_u8 (uint8x16_t __a, const int __b)
{
  if (__b < 16 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline uint16_t __attribute__ ((__always_inline__))
vgetq_lane_u16 (uint16x8_t __a, const int __b)
{
  if (__b < 8 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline uint32_t __attribute__ ((__always_inline__))
vgetq_lane_u32 (uint32x4_t __a, const int __b)
{
  if (__b < 4 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline uint64_t __attribute__ ((__always_inline__))
vgetq_lane_u64 (uint64x2_t __a, const int __b)
{
  if (__b < 2 && __b >= 0 )
    return __a[__b];
  else
  {
    printf("lane out of range");
    return 1;
  }
}

__extension__ static __inline float32_t __attribute__ ((__always_inline__))
vgetq_lane_f32 (float32x4_t __a, const int __b)
{
  if (__b < 4 && __b >= 0 )
    return __a[__b];
  else 
    return 1;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vset_lane_s8 (int8_t __a, int8x8_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vset_lane_s16 (int16_t __a, int16x4_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vset_lane_s32 (int32_t __a, int32x2_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vset_lane_u8 (uint8_t __a, uint8x8_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vset_lane_u16 (uint16_t __a, uint16x4_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vset_lane_u32 (uint32_t __a, uint32x2_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vset_lane_f32 (float32_t __a, float32x2_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vsetq_lane_s8 (int8_t __a, int8x16_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vsetq_lane_s16 (int16_t __a, int16x8_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}
__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vsetq_lane_s32 (int32_t __a, int32x4_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vsetq_lane_u8 (uint8_t __a, uint8x16_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vsetq_lane_u16 (uint16_t __a, uint16x8_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vsetq_lane_u32 (uint32_t __a, uint32x4_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vsetq_lane_u64 (uint64_t __a, uint64x2_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vsetq_lane_f32 (float32_t __a, float32x4_t __b, const int __c)
{
  __b[__c] = __a;
  return __b;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vtbl2_s8 (int8x8x2_t __a, int8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a.val[0][0]);
  vint8m1_t vb = vle8_v_i8m1(&__a.val[1][0]);
  vint8m1_t vc;
  vse8_v_i8m1(&vc[gvl],va);
  vse8_v_i8m1(&vc[number],vb);
  vint8m1_t vd = vle8_v_i8m1(&__b[0]);
  vsetvl_e8m1 (number*2);
  vint8m1_t ve = vrgather_vv_i8m1(vc,(vuint8m1_t)vd);
  vsetvl_e8m1 (number);
  int8x8_t c;
  vse8_v_i8m1(&c[0],ve);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vtbl2_u8 (uint8x8x2_t __a, uint8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a.val[0][0]);
  vuint8m1_t vb = vle8_v_u8m1(&__a.val[1][0]);
  vuint8m1_t vc;
  vse8_v_u8m1(&vc[gvl],va);
  vse8_v_u8m1(&vc[number],vb);
  vuint8m1_t vd = vle8_v_u8m1(&__b[0]);
  vsetvl_e8m1 (number*2);
  vuint8m1_t ve = vrgather_vv_u8m1(vc,vd);
  vsetvl_e8m1 (number);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],ve);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vtbl4_u8 (uint8x8x4_t __a, uint8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m2 (number);
  vuint8m1_t va1,va2,va3,va4;
  vuint8m2_t vb,vc,vd;
  va1 = vle8_v_u8m1(&__a.val[0][0]);
  va2 = vle8_v_u8m1(&__a.val[1][0]);
  va3 = vle8_v_u8m1(&__a.val[2][0]);
  va4 = vle8_v_u8m1(&__a.val[3][0]);
  vb = vle8_v_u8m2(&__b[0]);
  vse8_v_u8m1(&vc[gvl],va1);
  vse8_v_u8m1(&vc[number],va2);
  vse8_v_u8m1(&vc[number*2],va3);
  vse8_v_u8m1(&vc[number*3],va4);
  vsetvl_e8m2 (number*4);
  vd = vrgather_vv_u8m2(vc,vb);
  vsetvl_e8m1 (number);
  uint8x8_t c;
  vse8_v_u8m2(&c[0],vd);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vtbx2_u8 (uint8x8_t __a, uint8x8x2_t __b, uint8x8_t __c)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb1,vb2,vc,vd,ve,vg,vh;
  va = vle8_v_u8m1(&__a[0]);
  vb1 = vle8_v_u8m1(&__b.val[0][0]);
  vb2 = vle8_v_u8m1(&__b.val[1][0]);
  vc = vle8_v_u8m1(&__c[0]);
  vse8_v_u8m1(&vd[gvl],vb1);
  vse8_v_u8m1(&vd[number],vb2);
  vsetvl_e8m1 (number*2);
  ve = vrgather_vv_u8m1(vd,vc);
  vbool8_t vf = vmsne_vx_u8m1_b8(ve,0);
  vg = vzero_u8m1();
  vh = vadd_vv_u8m1_m(vf,va,vg,ve);
  vsetvl_e8m1 (number);
  uint8x8_t e;
  vse8_v_u8m1(&e[0],vh);
  return e;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vtbx3_u8 (uint8x8_t __a, uint8x8x3_t __b, uint8x8_t __c)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m2 (number);
  vuint8m2_t vb1,vb2,vb3,vc,vd,ve;
  vb1 = vle8_v_u8m2(&__b.val[0][0]);
  vb2 = vle8_v_u8m2(&__b.val[1][0]);
  vb3 = vle8_v_u8m2(&__b.val[2][0]);
  vc = vle8_v_u8m2(&__c[0]);
  vse8_v_u8m2(&vd[gvl],vb1);
  vse8_v_u8m2(&vd[number],vb2);
  vse8_v_u8m2(&vd[number*2],vb3);
  vsetvl_e8m2 (number*3);
  ve = vrgather_vv_u8m2(vd,vc);
  vsetvl_e8m1 (number);
  vuint8m1_t vaa = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vcc = vle8_v_u8m1(&__c[0]);
  vbool8_t vf = vmsltu_vx_u8m1_b8(vcc,24);
  vuint8m1_t vgg = vzero_u8m1();
  vuint8m1_t vee = vle8_v_u8m1(&ve[gvl]);
  vuint8m1_t vhh = vadd_vv_u8m1_m(vf,vaa,vgg,vee);
  uint8x8_t e;
  vse8_v_u8m1(&e[0],vhh);
  return e;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vrev64_s8 (int8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  unsigned char b0[8] = {7, 6, 5, 4, 3, 2, 1, 0};
  vuint8m1_t b = vle8_v_u8m1(&b0[0]);
  vint8m1_t va,vc;
  va = vle8_v_i8m1(&__a[0]);
  vc = vrgather_vv_i8m1(va,b);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vrev64_s16 (int16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  unsigned short b0[4] = {3, 2, 1, 0};
  vuint16m1_t b = vle16_v_u16m1(&b0[0]);
  vint16m1_t va,vc;
  va = vle16_v_i16m1(&__a[0]);
  vc = vrgather_vv_i16m1(va,b);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vrev64_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  unsigned int b0[2] = {1, 0};
  vuint32m1_t b = vle32_v_u32m1(&b0[0]);
  vint32m1_t va,vc;
  va = vle32_v_i32m1(&__a[0]);
  vc = vrgather_vv_i32m1(va,b);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vrev64_u8 (uint8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  unsigned char b0[8] = {7, 6, 5, 4, 3, 2, 1, 0};
  vuint8m1_t b = vle8_v_u8m1(&b0[0]);
  vuint8m1_t va,vc;
  va = vle8_v_u8m1(&__a[0]);
  vc = vrgather_vv_u8m1(va,b);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vrev64_u16 (uint16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  unsigned short b0[4] = {3, 2, 1, 0};
  vuint16m1_t b = vle16_v_u16m1(&b0[0]);
  vuint16m1_t va,vc;
  va = vle16_v_u16m1(&__a[0]);
  vc = vrgather_vv_u16m1(va,b);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vrev64_u32 (uint32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  unsigned int b0[2] = {1, 0};
  vuint32m1_t b = vle32_v_u32m1(&b0[0]);
  vuint32m1_t va,vc;
  va = vle32_v_u32m1(&__a[0]);
  vc = vrgather_vv_u32m1(va,b);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vrev64_f32 (float32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  unsigned int b0[2] = {1, 0};
  vuint32m1_t b = vle32_v_u32m1(&b0[0]);
  vfloat32m1_t va,vc;
  va = vle32_v_f32m1(&__a[0]);
  vc = vrgather_vv_f32m1(va,b);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vrev64q_s8 (int8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  unsigned char b0[16] = {7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8};
  vuint8m1_t b = vle8_v_u8m1(&b0[0]);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vc = vrgather_vv_i8m1(va,b);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vrev64q_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  unsigned short b0[8] = {3, 2, 1, 0, 7, 6, 5, 4};
  vuint16m1_t b = vle16_v_u16m1(&b0[0]);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vc = vrgather_vv_i16m1(va,b);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vrev64q_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  unsigned int b0[4] = {1, 0, 3, 2};
  vuint32m1_t b = vle32_v_u32m1(&b0[0]);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vc = vrgather_vv_i32m1(va,b);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vrev64q_u8 (uint8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  unsigned char b0[16] = {7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8};
  vuint8m1_t b = vle8_v_u8m1(&b0[0]);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vc = vrgather_vv_u8m1(va,b);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vrev64q_u16 (uint16x8_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  unsigned short b0[8] = {3, 2, 1, 0, 7, 6, 5, 4};
  vuint16m1_t b = vle16_v_u16m1(&b0[0]);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vc = vrgather_vv_u16m1(va,b);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vrev64q_u32 (uint32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  unsigned int b0[4] = {1, 0, 3, 2};
  vuint32m1_t b = vle32_v_u32m1(&b0[0]);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vc = vrgather_vv_u32m1(va,b);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vrev64q_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  unsigned int b0[4] = {1, 0, 3, 2};
  vuint32m1_t b = vle32_v_u32m1(&b0[0]);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vc = vrgather_vv_f32m1(va,b);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vorr_s8 (int8x8_t __a, int8x8_t __b)
{
  return __a | __b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vorr_s16 (int16x4_t __a, int16x4_t __b)
{
  return __a | __b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vorr_s32 (int32x2_t __a, int32x2_t __b)
{
  return __a | __b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vorr_u8 (uint8x8_t __a, uint8x8_t __b)
{
  return __a | __b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vorr_u16 (uint16x4_t __a, uint16x4_t __b)
{
  return __a | __b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vorr_u32 (uint32x2_t __a, uint32x2_t __b)
{
  return __a | __b;
}

__extension__ static __inline int64x1_t __attribute__ ((__always_inline__))
vorr_s64 (int64x1_t __a, int64x1_t __b)
{
  return __a | __b;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vorr_u64 (uint64x1_t __a, uint64x1_t __b)
{
  return __a | __b;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vorrq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vor_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vorrq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vor_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vorrq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vor_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vorrq_s64 (int64x2_t __a, int64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vor_vv_i64m1(va,vb);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vorrq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vor_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vorrq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vor_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vorrq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vor_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vorrq_u64 (uint64x2_t __a, uint64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vor_vv_u64m1(va,vb);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vmvn_s8 (int8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb;
  va = vle8_v_i8m1(&__a[0]);
  vb = vnot_v_i8m1(va);
  int8x8_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vmvn_s16 (int16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb;
  va = vle16_v_i16m1(&__a[0]);
  vb = vnot_v_i16m1(va);
  int16x4_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vmvn_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb;
  va = vle32_v_i32m1(&__a[0]);
  vb = vnot_v_i32m1(va);
  int32x2_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vmvn_u8 (uint8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb;
  va = vle8_v_u8m1(&__a[0]);
  vb = vnot_v_u8m1(va);
  uint8x8_t b;
  vse8_v_u8m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vmvn_u16 (uint16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb;
  va = vle16_v_u16m1(&__a[0]);
  vb = vnot_v_u16m1(va);
  uint16x4_t b;
  vse16_v_u16m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vmvn_u32 (uint32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb;
  va = vle32_v_u32m1(&__a[0]);
  vb = vnot_v_u32m1(va);
  uint32x2_t b;
  vse32_v_u32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vmvnq_s8 (int8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vnot_v_i8m1(va);
  int8x16_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vmvnq_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vnot_v_i16m1(va);
  int16x8_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vmvnq_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vnot_v_i32m1(va);
  int32x4_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vmvnq_u8 (uint8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vnot_v_u8m1(va);
  uint8x16_t b;
  vse8_v_u8m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vmvnq_u16 (uint16x8_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vnot_v_u16m1(va);
  uint16x8_t b;
  vse16_v_u16m1(&b[0],vb);
  return b;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vmvnq_u32 (uint32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vnot_v_u32m1(va);
  uint32x4_t b;
  vse32_v_u32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vneg_s8 (int8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb;
  va = vle8_v_i8m1(&__a[0]);
  vb = vadd_vx_i8m1(vnot_v_i8m1(va),1);
  int8x8_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vneg_s16 (int16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb;
  va = vle16_v_i16m1(&__a[0]);
  vb = vadd_vx_i16m1(vnot_v_i16m1(va),1);
  int16x4_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vneg_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb;
  va = vle32_v_i32m1(&__a[0]);
  vb = vadd_vx_i32m1(vnot_v_i32m1(va),1);
  int32x2_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vneg_f32 (float32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb;
  va = vle32_v_f32m1(&__a[0]);
  vb = vfsgnjn_vv_f32m1(va,va);
  float32x2_t b;
  vse32_v_f32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vnegq_s8 (int8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vadd_vx_i8m1(vnot_v_i8m1(va),1);
  int8x16_t b;
  vse8_v_i8m1(&b[0],vb);
  return b;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vnegq_s16 (int16x8_t __a)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vadd_vx_i16m1(vnot_v_i16m1(va),1);
  int16x8_t b;
  vse16_v_i16m1(&b[0],vb);
  return b;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vnegq_s32 (int32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vadd_vx_i32m1(vnot_v_i32m1(va),1);
  int32x4_t b;
  vse32_v_i32m1(&b[0],vb);
  return b;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vnegq_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vfsgnjn_vv_f32m1(va,va);
  float32x4_t b;
  vse32_v_f32m1(&b[0],vb);
  return b;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vext_s8 (int8x8_t __a, int8x8_t __b, const int __c)
{
  int number = 8;
  int8x8_t d;
  vsetvl_e8m1 (number - __c);
  vint8m1_t vd = vle8_v_i8m1(&__a[__c]);
  vse8_v_i8m1(&d[0],vd);
  vsetvl_e8m1 (__c);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vse8_v_i8m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vext_s16 (int16x4_t __a, int16x4_t __b, const int __c)
{
  int number = 4;
  int16x4_t d;
  vsetvl_e16m1 (number - __c);
  vint16m1_t vd = vle16_v_i16m1(&__a[__c]);
  vse16_v_i16m1(&d[0],vd);
  vsetvl_e16m1 (__c);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vse16_v_i16m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vext_u8 (uint8x8_t __a, uint8x8_t __b, const int __c)
{
  int number = 8;
  uint8x8_t d;
  vsetvl_e8m1 (number - __c);
  vuint8m1_t vd = vle8_v_u8m1(&__a[__c]);
  vse8_v_u8m1(&d[0],vd);
  vsetvl_e8m1 (__c);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vse8_v_u8m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vext_u16 (uint16x4_t __a, uint16x4_t __b, const int __c)
{
  int number = 4;
  uint16x4_t d;
  vsetvl_e16m1 (number - __c);
  vuint16m1_t vd = vle16_v_u16m1(&__a[__c]);
  vse16_v_u16m1(&d[0],vd);
  vsetvl_e16m1 (__c);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vse16_v_u16m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vextq_s8 (int8x16_t __a, int8x16_t __b, const int __c)
{
  int number = 16;
  int8x16_t d;
  vsetvl_e8m1 (number - __c);
  vint8m1_t vd = vle8_v_i8m1(&__a[__c]);
  vse8_v_i8m1(&d[0],vd);
  vsetvl_e8m1 (__c);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vse8_v_i8m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vextq_s16 (int16x8_t __a, int16x8_t __b, const int __c)
{
  int number = 8;
  int16x8_t d;
  vsetvl_e16m1 (number - __c);
  vint16m1_t vd = vle16_v_i16m1(&__a[__c]);
  vse16_v_i16m1(&d[0],vd);
  vsetvl_e16m1 (__c);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vse16_v_i16m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vextq_s32 (int32x4_t __a, int32x4_t __b, const int __c)
{
  int number = 4;
  int32x4_t d;
  vsetvl_e32m1 (number - __c);
  vint32m1_t vd = vle32_v_i32m1(&__a[__c]);
  vse32_v_i32m1(&d[0],vd);
  vsetvl_e32m1 (__c);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vse32_v_i32m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vextq_f32 (float32x4_t __a, float32x4_t __b, const int __c)
{
  int number = 4;
  float32x4_t d;
  vsetvl_e32m1 (number - __c);
  vfloat32m1_t vd = vle32_v_f32m1(&__a[__c]);
  vse32_v_f32m1(&d[0],vd);
  vsetvl_e32m1 (__c);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vse32_v_f32m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vextq_u8 (uint8x16_t __a, uint8x16_t __b, const int __c)
{
  int number = 16;
  uint8x16_t d;
  vsetvl_e8m1 (number - __c);
  vuint8m1_t vd = vle8_v_u8m1(&__a[__c]);
  vse8_v_u8m1(&d[0],vd);
  vsetvl_e8m1 (__c);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vse8_v_u8m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vextq_u16 (uint16x8_t __a, uint16x8_t __b, const int __c)
{
  int number = 8;
  uint16x8_t d;
  vsetvl_e16m1 (number - __c);
  vuint16m1_t vd = vle16_v_u16m1(&__a[__c]);
  vse16_v_u16m1(&d[0],vd);
  vsetvl_e16m1 (__c);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vse16_v_u16m1(&d[number - __c],vb);
  return d;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
veor_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vxor_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
veor_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vxor_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
veor_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vxor_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
veor_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vxor_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
veor_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vxor_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
veor_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vxor_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
veorq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vxor_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
veorq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vxor_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
veorq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vxor_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
veorq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vxor_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
veorq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vxor_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
veorq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vxor_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vclt_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vbool8_t mask = vmslt_vv_i8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vclt_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vbool16_t mask = vmslt_vv_i16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vclt_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vbool32_t mask = vmslt_vv_i32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vclt_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmsltu_vv_u8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vclt_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmsltu_vv_u16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vclt_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmsltu_vv_u32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vclt_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmflt_vv_f32m1_b32(va,vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcltq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vbool8_t mask = vmslt_vv_i8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcltq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vbool16_t mask = vmslt_vv_i16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcltq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vbool32_t mask = vmslt_vv_i32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcltq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmsltu_vv_u8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcltq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmsltu_vv_u16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcltq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmsltu_vv_u32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcltq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmflt_vv_f32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcltzq_s32 (int32x4_t __a)                                                      
{
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  uint32x4_t b;
  vse32_v_u32m1(&b[0],(vuint32m1_t) (va > 0));
  return b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vcgt_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vbool8_t mask = vmsle_vv_i8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vcgt_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vbool16_t mask = vmsle_vv_i16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vcgt_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vbool32_t mask = vmsle_vv_i32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vcgt_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmsleu_vv_u8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vcgt_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmsleu_vv_u16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vcgt_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmsleu_vv_u32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vcgt_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmfgt_vv_f32m1_b32(va,vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcgtq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vbool8_t mask = vmsle_vv_i8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcgtq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vbool16_t mask = vmsle_vv_i16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcgtq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vbool32_t mask = vmsle_vv_i32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcgtq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmsleu_vv_u8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcgtq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmsleu_vv_u16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcgtq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmsleu_vv_u32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcgtq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmfgt_vv_f32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vcge_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vbool8_t mask = vmslt_vv_i8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vcge_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vbool16_t mask = vmslt_vv_i16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vcge_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vbool32_t mask = vmslt_vv_i32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vcge_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmsltu_vv_u8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vcge_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmsltu_vv_u16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vcge_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmsltu_vv_u32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vcge_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmfge_vv_f32m1_b32(va,vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcgeq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vbool8_t mask = vmslt_vv_i8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcgeq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vbool16_t mask = vmslt_vv_i16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcgeq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vbool32_t mask = vmslt_vv_i32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcgeq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(-1);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmsltu_vv_u8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, 0);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcgeq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(-1);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmsltu_vv_u16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, 0);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcgeq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(-1);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmsltu_vv_u32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, 0);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcgeq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmfge_vv_f32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vcle_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmfle_vv_f32m1_b32(va,vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vcleq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmsleu_vv_u8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vcleq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmsleu_vv_u16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcleq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmsleu_vv_u32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vcleq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmfle_vv_f32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vceq_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vbool8_t mask = vmseq_vv_i8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vceq_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vbool16_t mask = vmseq_vv_i16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vceq_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vbool32_t mask = vmseq_vv_i32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vceq_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vbool8_t mask = vmseq_vv_u8m1_b8(va, vb);
  vuint8m1_t vec_ret = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x8_t ret;
  vse8_v_u8m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vceq_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vbool16_t mask = vmseq_vv_u16m1_b16(va, vb);
  vuint16m1_t vec_ret = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x4_t ret;
  vse16_v_u16m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vceq_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vbool32_t mask = vmseq_vv_u32m1_b32(va, vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vceq_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vbool32_t mask = vmfeq_vv_f32m1_b32(va,vb);
  vuint32m1_t vec_ret = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x2_t ret;
  vse32_v_u32m1(&ret[0],vec_ret);
  return ret;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vceqq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vbool8_t mask = vmseq_vv_i8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vceqq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vbool16_t mask = vmseq_vv_i16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vceqq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vbool32_t mask = vmseq_vv_i32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vceqq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vec_ref = vmv_v_x_u8m1(0);
  vbool8_t mask = vmseq_vv_u8m1_b8(va,vb);
  vuint8m1_t vc = vmerge_vxm_u8m1(mask, vec_ref, -1);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vceqq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vec_ref = vmv_v_x_u16m1(0);
  vbool16_t mask = vmseq_vv_u16m1_b16(va,vb);
  vuint16m1_t vc = vmerge_vxm_u16m1(mask, vec_ref, -1);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vceqq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vbool32_t mask = vmseq_vv_u32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vceqq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vbool32_t mask = vmfeq_vv_f32m1_b32(va,vb);
  vuint32m1_t vc = vmerge_vxm_u32m1(mask, vec_ref, -1);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vbsl_s8 (uint8x8_t __a, int8x8_t __b, int8x8_t __c)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va;
  volatile vint8m1_t vb,vc,vd;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vle8_v_i8m1(&__c[0]);
  vb = vand_vv_i8m1((vint8m1_t)va,vb);
  vc = vand_vv_i8m1(vnot_v_i8m1((vint8m1_t)va),vc);
  vd = vor_vv_i8m1(vb,vc);
  int8x8_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vbsl_s16 (uint16x4_t __a, int16x4_t __b, int16x4_t __c)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va;
  volatile vint16m1_t vb,vc,vd;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vle16_v_i16m1(&__c[0]);
  vb = vand_vv_i16m1((vint16m1_t)va,vb);
  vc = vand_vv_i16m1(vnot_v_i16m1((vint16m1_t)va),vc);
  vd = vor_vv_i16m1(vb,vc);
  int16x4_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vbsl_s32 (uint32x2_t __a, int32x2_t __b, int32x2_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va;
  volatile vint32m1_t vb,vc,vd;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vle32_v_i32m1(&__c[0]);
  vb = vand_vv_i32m1((vint32m1_t)va,vb);
  vc = vand_vv_i32m1(vnot_v_i32m1((vint32m1_t)va),vc);
  vd = vor_vv_i32m1(vb,vc);
  int32x2_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vbsl_u8 (uint8x8_t __a, uint8x8_t __b, uint8x8_t __c)
{
  int number = 8;
  vsetvl_e8m1 (number);
  volatile vuint8m1_t va,vb,vc,vd;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vle8_v_u8m1(&__c[0]);
  vb = vand_vv_u8m1(va,vb);
  vc = vand_vv_u8m1(vnot_v_u8m1(va),vc);
  vd = vor_vv_u8m1(vb,vc);
  uint8x8_t d;
  vse8_v_u8m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vbsl_u16 (uint16x4_t __a, uint16x4_t __b, uint16x4_t __c)
{
  int number = 4;
  vsetvl_e16m1 (number);
  volatile vuint16m1_t va,vb,vc,vd;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vle16_v_u16m1(&__c[0]);
  vb = vand_vv_u16m1(va,vb);
  vc = vand_vv_u16m1(vnot_v_u16m1(va),vc);
  vd = vor_vv_u16m1(vb,vc);
  uint16x4_t d;
  vse16_v_u16m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vbsl_u32 (uint32x2_t __a, uint32x2_t __b, uint32x2_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  volatile vuint32m1_t va,vb,vc,vd;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vle32_v_u32m1(&__c[0]);
  vb = vand_vv_u32m1(va,vb);
  vc = vand_vv_u32m1(vnot_v_u32m1(va),vc);
  vd = vor_vv_u32m1(vb,vc);
  uint32x2_t d;
  vse32_v_u32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vbsl_f32 (uint32x2_t __a, float32x2_t __b, float32x2_t __c)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vfloat32m1_t vb,vc;
  vuint32m1_t vbb,vcc,vdd;
  vb = vle32_v_f32m1(&__b[0]);
  vc = vle32_v_f32m1(&__c[0]);
  vbb = vand_vv_u32m1(va,(vuint32m1_t)vb);
  vcc = vand_vv_u32m1(vnot_v_u32m1(va),(vuint32m1_t)vc);
  vdd = vor_vv_u32m1(vbb,vcc);
  float32x2_t d;
  vse32_v_f32m1(&d[0],(vfloat32m1_t)vdd);
  return d;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vbslq_s8 (uint8x16_t __a, int8x16_t __b, int8x16_t __c)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  volatile vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  volatile vint8m1_t vc = vle8_v_i8m1(&__c[0]);
  vb = vand_vv_i8m1((vint8m1_t)va,vb);
  vc = vand_vv_i8m1(vnot_v_i8m1((vint8m1_t)va),vc);
  vint8m1_t vd = vor_vv_i8m1(vb,vc);
  int8x16_t d;
  vse8_v_i8m1(&d[0],vd);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vbslq_s16 (uint16x8_t __a, int16x8_t __b, int16x8_t __c)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  volatile vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  volatile vint16m1_t vc = vle16_v_i16m1(&__c[0]);
  vb = vand_vv_i16m1((vint16m1_t)va,vb);
  vc = vand_vv_i16m1(vnot_v_i16m1((vint16m1_t)va),vc);
  vint16m1_t vd = vor_vv_i16m1(vb,vc);
  int16x8_t d;
  vse16_v_i16m1(&d[0],vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vbslq_s32 (uint32x4_t __a, int32x4_t __b, int32x4_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  volatile vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  volatile vint32m1_t vc = vle32_v_i32m1(&__c[0]);
  vb = vand_vv_i32m1((vint32m1_t)va,vb);
  vc = vand_vv_i32m1(vnot_v_i32m1((vint32m1_t)va),vc);
  vint32m1_t vd = vor_vv_i32m1(vb,vc);
  int32x4_t d;
  vse32_v_i32m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vbslq_u8 (uint8x16_t __a, uint8x16_t __b, uint8x16_t __c)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  volatile vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  volatile vuint8m1_t vc = vle8_v_u8m1(&__c[0]);
  vb = vand_vv_u8m1(va,vb);
  vc = vand_vv_u8m1(vnot_v_u8m1(va),vc);
  vuint8m1_t vd = vor_vv_u8m1(vb,vc);
  uint8x16_t d;
  vse8_v_u8m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vbslq_u16 (uint16x8_t __a, uint16x8_t __b, uint16x8_t __c)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  volatile vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  volatile vuint16m1_t vc = vle16_v_u16m1(&__c[0]);
  vb = vand_vv_u16m1(va,vb);
  vc = vand_vv_u16m1(vnot_v_u16m1(va),vc);
  vuint16m1_t vd = vor_vv_u16m1(vb,vc);
  uint16x8_t d;
  vse16_v_u16m1(&d[0],vd);
  return d;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vbslq_u32 (uint32x4_t __a, uint32x4_t __b, uint32x4_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  volatile vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  volatile vuint32m1_t vc = vle32_v_u32m1(&__c[0]);
  vb = vand_vv_u32m1(va,vb);
  vc = vand_vv_u32m1(vnot_v_u32m1(va),vc);
  vuint32m1_t vd = vor_vv_u32m1(vb,vc);
  uint32x4_t d;
  vse32_v_u32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vbslq_f32 (uint32x4_t __a, float32x4_t __b, float32x4_t __c)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vle32_v_f32m1(&__c[0]);
  vuint32m1_t vd,ve,vf;
  vd = vand_vv_u32m1(va,(vuint32m1_t)vb);
  ve = vand_vv_u32m1(vnot_v_u32m1(va),(vuint32m1_t)vc);
  vf = vor_vv_u32m1(vd,ve);
  float32x4_t f;
  vse32_v_f32m1(&f[0],(vfloat32m1_t)vf);
  return f;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vand_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vand_vv_i8m1(va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vand_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vand_vv_i16m1(va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vand_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vand_vv_i32m1(va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x1_t __attribute__ ((__always_inline__))
vand_s64 (int64x1_t __a, int64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vint64m1_t va,vb,vc;
  va = vle64_v_i64m1(&__a[0]);
  vb = vle64_v_i64m1(&__b[0]);
  vc = vand_vv_i64m1(va,vb);
  int64x1_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vand_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vand_vv_u8m1(va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vand_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vand_vv_u16m1(va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vand_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vand_vv_u32m1(va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vand_u64 (uint64x1_t __a, uint64x1_t __b)
{
  int number = 1;
  vsetvl_e64m1 (number);
  vuint64m1_t va,vb,vc;
  va = vle64_v_u64m1(&__a[0]);
  vb = vle64_v_u64m1(&__b[0]);
  vc = vand_vv_u64m1(va,vb);
  uint64x1_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vandq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vand_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vandq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vand_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vandq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vand_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vandq_s64 (int64x2_t __a, int64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vand_vv_i64m1(va,vb);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vandq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vand_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vandq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vand_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vandq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vand_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vandq_u64 (uint64x2_t __a, uint64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vand_vv_u64m1(va,vb);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vpadd_s8 (int8x8_t __a, int8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb,vc,vd,ve;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vse8_v_i8m1(&vc[gvl],va);
  vse8_v_i8m1(&vc[number],vb);
  vsetvl_e8m1 (number*2);
  vd = vadd_vv_i8m1(vc,vslide1down_vx_i8m1(vc,0));
  vsetvl_e8m1 (number);
  ve = vlse8_v_i8m1(&vd[gvl],2);
  int8x8_t e;
  vse8_v_i8m1(&e[0],ve);
  return e;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vpadd_s16 (int16x4_t __a, int16x4_t __b)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb,vc,vd,ve;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vse16_v_i16m1(&vc[gvl],va);
  vse16_v_i16m1(&vc[number],vb);
  vsetvl_e16m1 (number*2);
  vd = vadd_vv_i16m1(vc,vslide1down_vx_i16m1(vc,0));
  vsetvl_e16m1 (number);
  ve = vlse16_v_i16m1(&vd[gvl],4);
  int16x4_t e;
  vse16_v_i16m1(&e[0],ve);
  return e;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vpadd_s32 (int32x2_t __a, int32x2_t __b)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb,vc,vd,ve;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vse32_v_i32m1(&vc[gvl],va);
  vse32_v_i32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vd = vadd_vv_i32m1(vc,vslide1down_vx_i32m1(vc,0));
  vsetvl_e32m1 (number);
  ve = vlse32_v_i32m1(&vd[gvl],8);
  int32x2_t e;
  vse32_v_i32m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vpadd_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc,vd,ve;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vse8_v_u8m1(&vc[gvl],va);
  vse8_v_u8m1(&vc[number],vb);
  vsetvl_e8m1 (number*2);
  vd = vadd_vv_u8m1(vc,vslide1down_vx_u8m1(vc,0));
  vsetvl_e8m1 (number);
  ve = vlse8_v_u8m1(&vd[gvl],2);
  uint8x8_t e;
  vse8_v_u8m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vpadd_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb,vc,vd,ve;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vse16_v_u16m1(&vc[gvl],va);
  vse16_v_u16m1(&vc[number],vb);
  vsetvl_e16m1 (number*2);
  vd = vadd_vv_u16m1(vc,vslide1down_vx_u16m1(vc,0));
  vsetvl_e16m1 (number);
  ve = vlse16_v_u16m1(&vd[gvl],4);
  uint16x4_t e;
  vse16_v_u16m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vpadd_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb,vc,vd,ve;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vse32_v_u32m1(&vc[gvl],va);
  vse32_v_u32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vd = vadd_vv_u32m1(vc,vslide1down_vx_u32m1(vc,0));
  vsetvl_e32m1 (number);
  ve = vlse32_v_u32m1(&vd[gvl],8);
  uint32x2_t e;
  vse32_v_u32m1(&e[0],ve);
  return e;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vpadd_f32 (float32x2_t __a, float32x2_t __b)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc,vd,ve;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vse32_v_f32m1(&vc[gvl],va);
  vse32_v_f32m1(&vc[number],vb);
  vsetvl_e32m1 (number*2);
  vd = vfadd_vv_f32m1(vc,vfslide1down_vf_f32m1(vc,0));
  vsetvl_e32m1 (number);
  ve = vlse32_v_f32m1(&vd[gvl],8);
  float32x2_t e;
  vse32_v_f32m1(&e[0],ve);
  return e;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vpaddq_s32 (int32x4_t __a, int32x4_t __b)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number*2);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vadd_vv_i32m1(va,vslide1down_vx_i32m1(va,0));
  vint32m1_t vd = vadd_vv_i32m1(vb,vslide1down_vx_i32m1(vb,0));
/*
  int32x4_t c,d,e;
  vse32_v_i32m1(&c[0],vc);
  vse32_v_i32m1(&d[0],vd);
  for (int i = 0;i < (number / 2);i++)
  {
    e[i] = c[2*i];
    e[i + (number / 2)] = d[2*i];
  }
  return e;
*/
  vsetvl_e32m1 (number);
  vint32m1_t c = vlse32_v_i32m1(&vc[gvl],8);
  vint32m1_t d = vlse32_v_i32m1(&vd[gvl],8);
  int32x4_t e;
  vse32_v_i32m1(&e[0],c);
  vse32_v_i32m1(&e[number],d);
  return e;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vpaddl_s8 (int8x8_t __a)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va;
  va = vle8_v_i8m1(&__a[0]);
  vint16m2_t vb = vwadd_vv_i16m2(va,vslide1down_vx_i8m1(va,0));
  vint16m1_t vc = vlse16_v_i16m1(&vb[gvl],4);
  int16x4_t d = {0, 0, 0, 0};
  vse16_v_i16m1(&d[0],vc);
  return d;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vpaddl_s16 (int16x4_t __a)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va;
  va = vle16_v_i16m1(&__a[0]);
  vint32m2_t vb = vwadd_vv_i32m2(va,vslide1down_vx_i16m1(va,0));
  vint32m1_t vc = vlse32_v_i32m1(&vb[gvl],8);
  int32x2_t d = {0, 0};
  vse32_v_i32m1(&d[0],vc);
  return d;
}

__extension__ static __inline int64x1_t __attribute__ ((__always_inline__))
vpaddl_s32 (int32x2_t __a)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va;
  va = vle32_v_i32m1(&__a[0]);
  vint64m2_t vb = vwadd_vv_i64m2(va,vslide1down_vx_i32m1(va,0));
  vint64m1_t vc = vlse64_v_i64m1(&vb[gvl],16);
  int64x1_t d = {0};
  vse64_v_i64m1(&d[0],vc);
  return d;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vpaddl_u8 (uint8x8_t __a)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va;
  va = vle8_v_u8m1(&__a[0]);
  vuint16m2_t vb = vwaddu_vv_u16m2(va,vslide1down_vx_u8m1(va,0));
  vuint16m1_t vc = vlse16_v_u16m1(&vb[gvl],4);
  uint16x4_t d = {0, 0, 0, 0};
  vse16_v_u16m1(&d[0],vc);
  return d;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vpaddl_u16 (uint16x4_t __a)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va;
  va = vle16_v_u16m1(&__a[0]);
  vuint32m2_t vb = vwaddu_vv_u32m2(va,vslide1down_vx_u16m1(va,0));
  vuint32m1_t vc = vlse32_v_u32m1(&vb[gvl],8);
  uint32x2_t d = {0, 0};
  vse32_v_u32m1(&d[0],vc);
  return d;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vpaddl_u32 (uint32x2_t __a)
{
  int gvl = 0;
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va;
  va = vle32_v_u32m1(&__a[0]);
  vuint64m2_t vb = vwaddu_vv_u64m2(va,vslide1down_vx_u32m1(va,0));
  vuint64m1_t vc = vlse64_v_u64m1(&vb[gvl],16);
  uint64x1_t d = {0};
  vse64_v_u64m1(&d[0],vc);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vpaddlq_s8 (int8x16_t __a)
{
  int gvl = 0;
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint16m2_t b = vwadd_vv_i16m2(va,vslide1down_vx_i8m1(va,0));
  vint16m2_t c = vlse16_v_i16m2(&b[gvl],4);
  int16x8_t d;
  vse16_v_i16m2(&d[0],c);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vpaddlq_s16 (int16x8_t __a)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint32m2_t b = vwadd_vv_i32m2(va,vslide1down_vx_i16m1(va,0));
  vint32m2_t c = vlse32_v_i32m2(&b[gvl],8);
  int32x4_t d;
  vse32_v_i32m2(&d[0],c);
  return d;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vpaddlq_s32 (int32x4_t __a)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint64m2_t b = vwadd_vv_i64m2(va,vslide1down_vx_i32m1(va,0));
  vint64m2_t c = vlse64_v_i64m2(&b[gvl],16);
  int64x2_t d;
  vse64_v_i64m2(&d[0],c);
  return d;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vpaddlq_u8 (uint8x16_t __a)
{
  int gvl = 0;
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint16m2_t b = vwaddu_vv_u16m2(va,vslide1down_vx_u8m1(va,0));
  vuint16m2_t c = vlse16_v_u16m2(&b[gvl],4);
  uint16x8_t d;
  vse16_v_u16m2(&d[0],c);
  return d;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vpaddlq_u16 (uint16x8_t __a)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint32m2_t b = vwaddu_vv_u32m2(va,vslide1down_vx_u16m1(va,0));
  vuint32m2_t c = vlse32_v_u32m2(&b[gvl],8);
  uint32x4_t d;
  vse32_v_u32m2(&d[0],c);
  return d;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vpaddlq_u32 (uint32x4_t __a)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint64m2_t b = vwaddu_vv_u64m2(va,vslide1down_vx_u32m1(va,0));
  vuint64m2_t c = vlse64_v_u64m2(&b[gvl],16);
  uint64x2_t d;
  vse64_v_u64m2(&d[0],c);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vaddl_s8 (int8x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va,vb;
  va = vle8_v_i8m1(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vint16m2_t vc = vwadd_vv_i16m2(va,vb);
  int16x8_t c;
  vse16_v_i16m2(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vaddl_s16 (int16x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va,vb;
  va = vle16_v_i16m1(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vint32m2_t vc = vwadd_vv_i32m2(va,vb);
  int32x4_t c;
  vse32_v_i32m2(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vaddl_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va,vb;
  va = vle32_v_i32m1(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vint64m2_t vc = vwadd_vv_i64m2(va,vb);
  int64x2_t c;
  vse64_v_i64m2(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vaddl_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vuint16m2_t vc = vwaddu_vv_u16m2(va,vb);
  uint16x8_t c;
  vse16_v_u16m2(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vaddl_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va,vb;
  va = vle16_v_u16m1(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vuint32m2_t vc = vwaddu_vv_u32m2(va,vb);
  uint32x4_t c;
  vse32_v_u32m2(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vaddl_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va,vb;
  va = vle32_v_u32m1(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vuint64m2_t vc = vwaddu_vv_u64m2(va,vb);
  uint64x2_t c;
  vse64_v_u64m2(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vaddl_high_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  int halfnumber = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint16m2_t vc = vwadd_vv_i16m2(va,vb);
  vsetvl_e16m1 (halfnumber);
  vint16m1_t vd = vle16_v_i16m1(&vc[halfnumber]);
  int16x8_t d;
  vse16_v_i16m1(&d[0], vd);
  return d;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vaddl_high_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  int halfnumber = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint32m2_t vc = vwadd_vv_i32m2(va,vb);
  vsetvl_e32m1 (halfnumber);
  vint32m1_t vd = vle32_v_i32m1(&vc[halfnumber]);
  int32x4_t d;
  vse32_v_i32m1(&d[0], vd);
  return d;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vaddl_high_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  int halfnumber = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint16m2_t vc = vwaddu_vv_u16m2(va,vb);
  vsetvl_e16m1 (halfnumber);
  vuint16m1_t vd = vle16_v_u16m1(&vc[halfnumber]);
  uint16x8_t d;
  vse16_v_u16m1(&d[0], vd);
  return d;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vaddw_s8 (int16x8_t __a, int8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t vb;
  vint16m2_t va,vc;
  va = vle16_v_i16m2(&__a[0]);
  vb = vle8_v_i8m1(&__b[0]);
  vc = vwadd_wv_i16m2(va,vb);
  int16x8_t c;
  vse16_v_i16m2(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vaddw_s16 (int32x4_t __a, int16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t vb;
  vint32m2_t va,vc;
  va = vle32_v_i32m2(&__a[0]);
  vb = vle16_v_i16m1(&__b[0]);
  vc = vwadd_wv_i32m2(va,vb);
  int32x4_t c;
  vse32_v_i32m2(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vaddw_s32 (int64x2_t __a, int32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t vb;
  vint64m2_t va,vc;
  va = vle64_v_i64m2(&__a[0]);
  vb = vle32_v_i32m1(&__b[0]);
  vc = vwadd_wv_i64m2(va,vb);
  int64x2_t c;
  vse64_v_i64m2(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vaddw_u8 (uint16x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t vb;
  vuint16m2_t va,vc;
  va = vle16_v_u16m2(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vwaddu_wv_u16m2(va,vb);
  uint16x8_t c;
  vse16_v_u16m2(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vaddw_u16 (uint32x4_t __a, uint16x4_t __b)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t vb;
  vuint32m2_t va,vc;
  va = vle32_v_u32m2(&__a[0]);
  vb = vle16_v_u16m1(&__b[0]);
  vc = vwaddu_wv_u32m2(va,vb);
  uint32x4_t c;
  vse32_v_u32m2(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vaddw_u32 (uint64x2_t __a, uint32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t vb;
  vuint64m2_t va,vc;
  va = vle64_v_u64m2(&__a[0]);
  vb = vle32_v_u32m1(&__b[0]);
  vc = vwaddu_wv_u64m2(va,vb);
  uint64x2_t c;
  vse64_v_u64m2(&c[0],vc);
  return c;
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
vadd_s8 (int8x8_t __a, int8x8_t __b)
{
  return __a + __b;
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
vadd_s16 (int16x4_t __a, int16x4_t __b)
{
  return __a + __b;
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
vadd_s32 (int32x2_t __a, int32x2_t __b)
{
  return __a + __b;
}

__extension__ static __inline int64x1_t __attribute__ ((__always_inline__))
vadd_s64 (int64x1_t __a, int64x1_t __b)
{
  return __a + __b;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vadd_u8 (uint8x8_t __a, uint8x8_t __b)
{
  return __a + __b;
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
vadd_u16 (uint16x4_t __a, uint16x4_t __b)
{
  return __a + __b;
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
vadd_u32 (uint32x2_t __a, uint32x2_t __b)
{
  return __a + __b;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vadd_u64 (uint64x1_t __a, uint64x1_t __b)
{
  return __a + __b;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vadd_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc;
  float32x2_t c;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vc = vfadd_vv_f32m1(va,vb);
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vaddq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint8m1_t vc = vadd_vv_i8m1(va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vaddq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint16m1_t vc = vadd_vv_i16m1(va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vaddq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t vc = vadd_vv_i32m1(va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int64x2_t __attribute__ ((__always_inline__))
vaddq_s64 (int64x2_t __a, int64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vle64_v_i64m1(&__b[0]);
  vint64m1_t vc = vadd_vv_i64m1(va,vb);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vaddq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vadd_vv_u8m1(va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vaddq_u16 (uint16x8_t __a, uint16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&__b[0]);
  vuint16m1_t vc = vadd_vv_u16m1(va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vaddq_u32 (uint32x4_t __a, uint32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1_t vc = vadd_vv_u32m1(va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint64x2_t __attribute__ ((__always_inline__))
vaddq_u64 (uint64x2_t __a, uint64x2_t __b)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vle64_v_u64m1(&__b[0]);
  vuint64m1_t vc = vadd_vv_u64m1(va,vb);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vaddq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1_t vc = vfadd_vv_f32m1(va,vb);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline int8_t __attribute__ ((__always_inline__))
vaddv_s8 (int8x8_t __a)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vzero_i8m1();
  volatile vint8m1_t vc = vzero_i8m1();
  vc = vredsum_vs_i8m1_i8m1(vc,va,vb);
  int8x8_t c;
  vse8_v_i8m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline int16_t __attribute__ ((__always_inline__))
vaddv_s16 (int16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vzero_i16m1();
  volatile vint16m1_t vc = vzero_i16m1();
  vc = vredsum_vs_i16m1_i16m1(vc,va,vb);
  int16x4_t c;
  vse16_v_i16m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline int32_t __attribute__ ((__always_inline__))
vaddv_s32 (int32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vzero_i32m1();
  volatile vint32m1_t vc = vzero_i32m1();
  vc = vredsum_vs_i32m1_i32m1(vc,va,vb);
  int32x2_t c;
  vse32_v_i32m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint8_t __attribute__ ((__always_inline__))
vaddv_u8 (uint8x8_t __a)                                                        
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vzero_u8m1();
  volatile vuint8m1_t vc = vzero_u8m1();
  vc = vredsum_vs_u8m1_u8m1(vc,va,vb);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint16_t __attribute__ ((__always_inline__))
vaddv_u16 (uint16x4_t __a)
{
  int number = 4;
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vzero_u16m1();
  volatile vuint16m1_t vc = vzero_u16m1();
  vc = vredsum_vs_u16m1_u16m1(vc,va,vb);
  uint16x4_t c;
  vse16_v_u16m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint32_t __attribute__ ((__always_inline__))
vaddv_u32 (uint32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vzero_u32m1();
  volatile vuint32m1_t vc = vzero_u32m1();
  vc = vredsum_vs_u32m1_u32m1(vc,va,vb);
  uint32x2_t c;
  vse32_v_u32m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline float32_t __attribute__ ((__always_inline__))
vaddv_f32 (float32x2_t __a)                                                     
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vzero_f32m1();
  volatile vfloat32m1_t vc = vzero_f32m1();
  vc = vfredsum_vs_f32m1_f32m1(vc,va,vb);
  float32x2_t c;
  vse32_v_f32m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline int8_t __attribute__ ((__always_inline__))
vaddvq_s8 (int8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vzero_i8m1();
  volatile vint8m1_t vc = vzero_i8m1();
  vc = vredsum_vs_i8m1_i8m1(vc,va,vb);
  int8x16_t c;
  vse8_v_i8m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline int16_t __attribute__ ((__always_inline__))
vaddvq_s16 (int16x8_t __a)
{
  int number = 8; 
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vzero_i16m1();
  volatile vint16m1_t vc = vzero_i16m1();
  vc = vredsum_vs_i16m1_i16m1(vc,va,vb);
  int16x8_t c;
  vse16_v_i16m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline int32_t __attribute__ ((__always_inline__))
vaddvq_s32 (int32x4_t __a)                                                      
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vzero_i32m1();
  volatile vint32m1_t vc = vzero_i32m1();
  vc = vredsum_vs_i32m1_i32m1(vc,va,vb);
  int32x4_t c;
  vse32_v_i32m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline int64_t __attribute__ ((__always_inline__))
vaddvq_s64 (int64x2_t __a)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vint64m1_t va = vle64_v_i64m1(&__a[0]);
  vint64m1_t vb = vzero_i64m1();
  volatile vint64m1_t vc = vzero_i64m1();
  vc = vredsum_vs_i64m1_i64m1(vc,va,vb);
  int64x2_t c;
  vse64_v_i64m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint8_t __attribute__ ((__always_inline__))
vaddvq_u8 (uint8x16_t __a)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vzero_u8m1();
  volatile vuint8m1_t vc = vzero_u8m1();
  vc = vredsum_vs_u8m1_u8m1(vc,va,vb);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint16_t __attribute__ ((__always_inline__))
vaddvq_u16 (uint16x8_t __a)
{
  int number = 8;  
  vsetvl_e16m1 (number);
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vzero_u16m1();
  volatile vuint16m1_t vc = vzero_u16m1();
  vc = vredsum_vs_u16m1_u16m1(vc,va,vb);
  uint16x8_t c;
  vse16_v_u16m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint32_t __attribute__ ((__always_inline__))
vaddvq_u32 (uint32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vzero_u32m1();
  volatile vuint32m1_t vc = vzero_u32m1();
  vc = vredsum_vs_u32m1_u32m1(vc,va,vb);
  uint32x4_t c;
  vse32_v_u32m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint64_t __attribute__ ((__always_inline__))
vaddvq_u64 (uint64x2_t __a)
{
  int number = 2;
  vsetvl_e64m1 (number);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint64m1_t vb = vzero_u64m1();
  volatile vuint64m1_t vc = vzero_u64m1();
  vc = vredsum_vs_u64m1_u64m1(vc,va,vb);
  uint64x2_t c;
  vse64_v_u64m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline float32_t __attribute__ ((__always_inline__))
vaddvq_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vzero_f32m1();
  volatile vfloat32m1_t vc = vzero_f32m1();
  vc = vfredsum_vs_f32m1_f32m1(vc,va,vb);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c[0];
}

__extension__ static __inline uint32x4_t __attribute__ ((__always_inline__))
vtstq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vuint32m1_t vec_ref = vmv_v_x_u32m1(0);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1_t c = vand_vv_i32m1(va,vb);
  vbool32_t vc = vmsne_vx_i32m1_b32(c,0);
  vuint32m1_t vd = vmerge_vxm_u32m1(vc, vec_ref, -1);
  uint32x4_t d;
  vse32_v_u32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vrecps_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc,vd;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vc = vfmul_vv_f32m1(va,vb);
  vd = vfrsub_vf_f32m1(vc,2);
  float32x2_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vrecpsq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  volatile vfloat32m1_t vc = vfmul_vv_f32m1(va,vb);
  vc = vfrsub_vf_f32m1(vc,2);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vrecpe_f32 (float32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc;
  float32x2_t c;
  va = vle32_v_f32m1(&__a[0]);
  vb = vfmv_v_f_f32m1(1);
  vc = vfdiv_vv_f32m1(vb,va);
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vrecpeq_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t c = vfmv_v_f_f32m1(1);
  vfloat32m1_t vd = vfdiv_vv_f32m1(c,va);
  float32x4_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vrsqrts_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2;
  vsetvl_e32m1 (number);
  volatile vfloat32m1_t va,vb,vc;
  float32x2_t c;
  va = vle32_v_f32m1(&__a[0]);
  vb = vle32_v_f32m1(&__b[0]);
  vc = vfmul_vv_f32m1(va,vb);
  vc = vfrsub_vf_f32m1(vc,3);
  vc = vfdiv_vf_f32m1(vc,2);
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vrsqrtsq_f32 (float32x4_t __a, float32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  volatile vfloat32m1_t vc = vfmul_vv_f32m1(va,vb);
  vc = vfrsub_vf_f32m1(vc,3);
  vc = vfdiv_vf_f32m1(vc,2);
  float32x4_t c;
  vse32_v_f32m1(&c[0],vc);
  return c;
}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vrsqrte_f32 (float32x2_t __a)
{
  int number = 2;
  vsetvl_e32m1 (number);
  vfloat32m1_t va,vb,vc,vd;
  va = vle32_v_f32m1(&__a[0]);
  vc = vfmv_v_f_f32m1(1);
  vb = vfsqrt_v_f32m1(va);
  vd = vfdiv_vv_f32m1(vc,vb);
  float32x2_t d;
  vse32_v_f32m1(&d[0],vd);
  return d;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vrsqrteq_f32 (float32x4_t __a)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t c = vfsqrt_v_f32m1(va);
  vfloat32m1_t ve = vfrdiv_vf_f32m1(c,1);
  float32x4_t e;
  vse32_v_f32m1(&e[0],ve);
  return e;
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
vhadd_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  vsetvl_e8m1 (number);
  vuint8m1_t va,vb,vc;
  va = vle8_v_u8m1(&__a[0]);
  vb = vle8_v_u8m1(&__b[0]);
  vc = vnsrl_wx_u8m1(vwaddu_vv_u16m2(va,vb),1);
  uint8x8_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vhaddq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vnsrl_wx_u8m1(vwaddu_vv_u16m2(va,vb),1);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x16_t __attribute__ ((__always_inline__))
vrhaddq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint8m1_t vc = vnclipu_wx_u8m1(vadd_vx_u16m2(vwaddu_vv_u16m2(va,vb),1),1);
  uint8x16_t c;
  vse8_v_u8m1(&c[0],vc);
  return c;
}

__extension__ static __inline uint8x8x2_t __attribute__ ((__always_inline__))
vtrn_u8 (uint8x8_t __a, uint8x8_t __b)
{
  int number = 8;
  int halfnumber = 4;
  //vsetvl_e8m1 (number);
  //vuint8m1x2_t ab1,ab2;
  //ab1 = vset_u8m1x2(ab1, 0, vlse8_v_u8m1(&__a[0],2));
  //ab1 = vset_u8m1x2(ab1, 1, vlse8_v_u8m1(&__b[0],2));
  //ab2 = vset_u8m1x2(ab2, 0, vlse8_v_u8m1(&__a[1],2));
  //ab2 = vset_u8m1x2(ab2, 1, vlse8_v_u8m1(&__b[1],2));
  //vuint8m1_t a = vget_u8m1x2(ab1, 0);
  //vuint8m1_t b = vget_u8m1x2(ab1, 1);
  //vse8_v_u8m1(&a[halfnumber],vget_u8m1x2(ab2, 0));
  //vse8_v_u8m1(&b[halfnumber],vget_u8m1x2(ab2, 1));

  vsetvl_e8m1 (halfnumber);
  vuint8m1_t va = vlse8_v_u8m1(&__a[0],2);
  vuint8m1_t vb = vlse8_v_u8m1(&__b[0],2);
  vuint8m1_t vc = vlse8_v_u8m1(&__a[1],2);
  vuint8m1_t vd = vlse8_v_u8m1(&__b[1],2);
  vse8_v_u8m1(&va[halfnumber],vc);
  vse8_v_u8m1(&vb[halfnumber],vd);
  vsetvl_e8m1 (number);
  vuint8m1x2_t ab = vcreate_u8m1x2(va, vb);
  uint8x8x2_t c;
  vsseg2e8_v_u8m1x2(&c.val[0][0],ab);
  return c;
}

__extension__ static __inline uint16x4x2_t __attribute__ ((__always_inline__))
vtrn_u16 (uint16x4_t __a, uint16x4_t __b)
{
  int number = 4;
  int halfnumber = 2;
  //vsetvl_e16m1 (number);
  //vuint16m1x2_t ab1,ab2;
  //ab1 = vset_u16m1x2(ab1, 0, vlse16_v_u16m1(&__a[0],4));
  //ab1 = vset_u16m1x2(ab1, 1, vlse16_v_u16m1(&__b[0],4));
  //ab2 = vset_u16m1x2(ab2, 0, vlse16_v_u16m1(&__a[1],4));
  //ab2 = vset_u16m1x2(ab2, 1, vlse16_v_u16m1(&__b[1],4));
  //vuint16m1_t a = vget_u16m1x2(ab1, 0);
  //vuint16m1_t b = vget_u16m1x2(ab1, 1);
  //vse16_v_u16m1(&a[halfnumber],vget_u16m1x2(ab2, 0));
  //vse16_v_u16m1(&b[halfnumber],vget_u16m1x2(ab2, 1));
  //uint16x4x2_t c;
  //vsseg2e16_v_u16m1x2(&c.val[0][0],ab1);
  //return c;

  vsetvl_e16m1 (halfnumber);
  vuint16m1_t va = vlse16_v_u16m1(&__a[0],4);
  vuint16m1_t vb = vlse16_v_u16m1(&__b[0],4);
  vuint16m1_t vc = vlse16_v_u16m1(&__a[1],4);
  vuint16m1_t vd = vlse16_v_u16m1(&__b[1],4);
  vse16_v_u16m1(&va[halfnumber],vc);
  vse16_v_u16m1(&vb[halfnumber],vd);
  vsetvl_e16m1 (number);
  vuint16m1x2_t ab = vcreate_u16m1x2(va, vb);
  uint16x4x2_t c;
  vsseg2e16_v_u16m1x2(&c.val[0][0],ab);
  return c;
}

__extension__ static __inline uint32x2x2_t __attribute__ ((__always_inline__))
vtrn_u32 (uint32x2_t __a, uint32x2_t __b)
{
  int number = 2;
  //vsetvl_e32m1 (number);
  //vuint32m1x2_t ab1;
  //ab1 = vset_u32m1x2(ab1, 0, vle32_v_u32m1(&__a[0]));
  //ab1 = vset_u32m1x2(ab1, 1, vle32_v_u32m1(&__b[0]));
  //uint32x2x2_t c;
  //vsseg2e32_v_u32m1x2(&c.val[0][0],ab1);
  //return c;

  vsetvl_e32m1 (number);
  vuint32m1_t va = vle32_v_u32m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  vuint32m1x2_t ab = vcreate_u32m1x2(va, vb);
  uint32x2x2_t c;
  vsseg2e32_v_u32m1x2(&c.val[0][0],ab);
  return c;
}

__extension__ static __inline int32x2x2_t __attribute__ ((__always_inline__))
vzip_s32 (int32x2_t __a, int32x2_t __b)
{
  int number = 2; 
  //vsetvl_e32m1 (number);
  //vint32m1x2_t ab1; 
  //ab1 = vset_i32m1x2(ab1, 0, vle32_v_i32m1(&__a[0]));
  //ab1 = vset_i32m1x2(ab1, 1, vle32_v_i32m1(&__b[0]));
  //int32x2x2_t c;
  //vsseg2e32_v_i32m1x2(&c.val[0][0],ab1);
  //return c;

  vsetvl_e32m1 (number);
  vint32m1_t va = vle32_v_i32m1(&__a[0]);
  vint32m1_t vb = vle32_v_i32m1(&__b[0]);
  vint32m1x2_t ab = vcreate_i32m1x2(va, vb);
  int32x2x2_t c;
  vsseg2e32_v_i32m1x2(&c.val[0][0],ab);
  return c;
}

__extension__ static __inline float32x2x2_t __attribute__ ((__always_inline__))
vzip_f32 (float32x2_t __a, float32x2_t __b)
{
  int number = 2; 
  vsetvl_e32m1 (number);
  vfloat32m1_t va = vle32_v_f32m1(&__a[0]);
  vfloat32m1_t vb = vle32_v_f32m1(&__b[0]);
  vfloat32m1x2_t ab = vcreate_f32m1x2(va, vb);
  float32x2x2_t c;
  vsseg2e32_v_f32m1x2(&c.val[0][0],ab);
  return c;
}

__extension__ static __inline int32x4x2_t __attribute__ ((__always_inline__))
vzipq_s32 (int32x4_t __a, int32x4_t __b)
{
  int number = 4;
  vsetvl_e32m1 (number);
  vint32m1x2_t ab1 = vcreate_i32m1x2(vle32_v_i32m1(&__a[0]), vle32_v_i32m1(&__b[0]));
  int32x4x2_t c;
  vsseg2e32_v_i32m1x2(&c.val[0][0],ab1);
  return c;
}

__extension__ static __inline int8x16x2_t __attribute__ ((__always_inline__))
vuzpq_s8 (int8x16_t __a, int8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vint8m1_t va = vle8_v_i8m1(&__a[0]);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  int8_t vc[32];
  vse8_v_i8m1(&vc[0],va);
  vse8_v_i8m1(&vc[16],vb);
  int8x16x2_t c;
  vse8_v_i8m1(&c.val[0][0], vlse8_v_i8m1(&vc[0],2));
  vse8_v_i8m1(&c.val[1][0], vlse8_v_i8m1(&vc[1],2));
  return c;
}

__extension__ static __inline int16x8x2_t __attribute__ ((__always_inline__))
vuzpq_s16 (int16x8_t __a, int16x8_t __b)
{
  int number = 8;
  vsetvl_e16m1 (number);
  vint16m1_t va = vle16_v_i16m1(&__a[0]);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  int16_t vc[16];
  vse16_v_i16m1(&vc[0],va);
  vse16_v_i16m1(&vc[8],vb);
  int16x8x2_t c;
  vse16_v_i16m1(&c.val[0][0], vlse16_v_i16m1(&vc[0],4));
  vse16_v_i16m1(&c.val[1][0], vlse16_v_i16m1(&vc[1],4));
  return c;
}

__extension__ static __inline uint8x16x2_t __attribute__ ((__always_inline__))
vuzpq_u8 (uint8x16_t __a, uint8x16_t __b)
{
  int number = 16;
  vsetvl_e8m1 (number);
  vuint8m1_t va = vle8_v_u8m1(&__a[0]);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  uint8_t vc[32];
  vse8_v_u8m1(&vc[0],va);
  vse8_v_u8m1(&vc[16],vb);
  uint8x16x2_t c;
  vse8_v_u8m1(&c.val[0][0], vlse8_v_u8m1(&vc[0],2));
  vse8_v_u8m1(&c.val[1][0], vlse8_v_u8m1(&vc[1],2));
  return c;
}

__extension__ static __inline int8x16_t __attribute__ ((__always_inline__))
vuzp1q_s8 (int8x16_t __a, int8x16_t __b)                                        
{
  int number = 16;
  vsetvl_e8m1 (number);
  int8x16_t c;
  int j = 0;
  for(int i = 0; i < (number);){
    c[j] = __a[i];
    c[j+(number/2)] = __b[i];
    i += 2;
    j ++;
  }
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vuzp1q_s16 (int16x8_t __a, int16x8_t __b)                                       
{
  int number = 8;
  vsetvl_e16m1 (number);
  int16x8_t c;
  int j = 0;
  for(int i = 0; i < (number);){
    c[j] = __a[i];
    c[j+(number/2)] = __b[i];
    i += 2;
    j ++;
  }
  return c;
}

__extension__ static __inline uint64x1_t __attribute__ ((__always_inline__))
vpadal_u32 (uint64x1_t __a, uint32x2_t __b)
{
  int number = 1;
  vsetvl_e32m1 (number*2);
  vuint64m1_t va = vle64_v_u64m1(&__a[0]);
  vuint32m1_t vb = vle32_v_u32m1(&__b[0]);
  volatile vuint64m1_t vc = vzero_u64m1();
  vc = vwredsumu_vs_u32m1_u64m1(vc,vb,va);
  vsetvl_e64m1 (number);
  uint64x1_t c;
  vse64_v_u64m1(&c[0],vc);
  return c;
}

__extension__ static __inline int16x8_t __attribute__ ((__always_inline__))
vpadalq_s8 (int16x8_t __a, int8x16_t __b)
{
  int gvl = 0;
  int number = 8;
  vsetvl_e8m1 (number*2);
  vint8m1_t vb = vle8_v_i8m1(&__b[0]);
  vint16m2_t vc = vwadd_vv_i16m2(vb, vslide1down_vx_i8m1(vb,0));
  vsetvl_e16m1 (number);
  vint16m2_t va = vle16_v_i16m2(&__a[0]);
  vint16m2_t vd = vlse16_v_i16m2(&vc[gvl],4);
  vint16m2_t ve = vadd_vv_i16m2(va,vd);
  int16x8_t e;
  vse16_v_i16m2(&e[0],ve);
  return e;
}

__extension__ static __inline int32x4_t __attribute__ ((__always_inline__))
vpadalq_s16 (int32x4_t __a, int16x8_t __b)
{
  int gvl = 0;
  int number = 4;
  vsetvl_e16m1 (number*2);
  vint16m1_t vb = vle16_v_i16m1(&__b[0]);
  vint32m2_t vc = vwadd_vv_i32m2(vb, vslide1down_vx_i16m1(vb,0));
  vsetvl_e32m1 (number);
  vint32m2_t va = vle32_v_i32m2(&__a[0]);
  vint32m2_t vd = vlse32_v_i32m2(&vc[gvl],8);
  vint32m2_t ve = vadd_vv_i32m2(va,vd);
  int32x4_t e;
  vse32_v_i32m2(&e[0],ve);
  return e;
}

__extension__ static __inline uint16x8_t __attribute__ ((__always_inline__))
vpadalq_u8 (uint16x8_t __a, uint8x16_t __b)
{
  int gvl = 0;
  int number = 8;
/*  vsetvl_e16m1 (number);
  uint16x8_t b;
  for(int i = 0; i < number;i++)
    b[i] = __b[2*i] + __b[2*i + 1];
  vuint16m1_t va = vle16_v_u16m1(&__a[0]);
  vuint16m1_t vb = vle16_v_u16m1(&b[0]);
  vuint16m1_t ve = vadd_vv_u16m1(va,vb);
  uint16x8_t e;
  vse16_v_u16m1(&e[0],ve);
  return e;*/
  vsetvl_e8m1 (number*2);
  vuint8m1_t vb = vle8_v_u8m1(&__b[0]);
  vuint16m2_t vc = vwaddu_vv_u16m2(vb, vslide1down_vx_u8m1(vb,0));
  vsetvl_e16m1 (number);
  vuint16m2_t va = vle16_v_u16m2(&__a[0]);
  vuint16m2_t vd = vlse16_v_u16m2(&vc[gvl],4);
  vuint16m2_t ve = vadd_vv_u16m2(va,vd);
  uint16x8_t e;
  vse16_v_u16m2(&e[0],ve);
  return e;

}

__extension__ static __inline float32x2_t __attribute__ ((__always_inline__))
vdiv_f32 (float32x2_t __a, float32x2_t __b)
{
  return __a / __b;
}

__extension__ static __inline float32x4_t __attribute__ ((__always_inline__))
vdivq_f32 (float32x4_t __a, float32x4_t __b)                                    
{
  return __a / __b;
}


#ifdef __cplusplus
}
#endif

#endif

