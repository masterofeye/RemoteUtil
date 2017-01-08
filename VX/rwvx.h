#ifndef _RWVX_H_
#define _RWVX_H_

//----------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------

#include <VX/vx.h>
#include <VX/vxu.h>

//----------------------------------------------------------------------------
// Macros
//----------------------------------------------------------------------------

#ifdef RWVX_STATIC_DEFINE
#  define RWVX_EXPORT
#  define RWVX_NO_EXPORT
#else
#  ifndef RWVX_EXPORT
#    ifdef visionworks_EXPORTS
        /* We are building this library */
#      define RWVX_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define RWVX_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef RWVX_NO_EXPORT
#    define RWVX_NO_EXPORT 
#  endif
#endif


#ifndef RWVX_EXTERN_C
#   ifdef __cplusplus
#       define RWVX_EXTERN_C extern "C"
#   else
#       define RWVX_EXTERN_C
#   endif
#endif

#ifndef RWVX_C_API
    #define RWVX_C_API RWVX_EXTERN_C RWVX_EXPORT
#endif

#ifndef RWVX_CXX_API
    #define RWVX_CXX_API RWVX_EXPORT
#endif

/**
 * \enum
 * \ingroup rwvx_framework_basic_types
 * \brief Defines additional types.
 */
enum rwvx_type_e {
    RWVX_TYPE_CALLBACK = VX_TYPE_VENDOR_STRUCT_START,
    RWVX_TYPE_STRUCT_MAX,
    RWVX_TYPE_OBJECT_MAX = VX_TYPE_VENDOR_OBJECT_START,
};

#define RWVX_LIBRARY_SCHLEISSHEIMER (0x01)

/*!
 * \enum
 * \ingroup rwvx_framework_basic_types
 * \brief Defines a list of extended vision kernels.
 */
enum rwvw_kernel_e {
 RWVX_KERNEL_VIDEOGRAB = VX_KERNEL_BASE(VX_ID_DEFAULT, RWVX_LIBRARY_SCHLEISSHEIMER) 
}



#endif