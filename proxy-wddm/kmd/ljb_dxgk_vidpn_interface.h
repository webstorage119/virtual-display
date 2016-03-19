/*
 * ljb_dxgk_vidpn_interface.h
 *
 * Author: Lin Jiabang (lin.jiabang@gmail.com)
 *     Copyright (C) 2016  Lin Jiabang
 *
 *  This program is NOT free software. Any unlicensed usage is prohbited.
 */
#ifndef _LJB_DXGK_VIDPN_INTERFACE_H_
#define _LJB_DXGK_VIDPN_INTERFACE_H_

/*
 * LJB_VIDPN object wraps around the VidPn object managed by VidPn manager
 */
#define LJB_VINPN_MAGIC     _MAKE_POOLTAG('V', 'I', 'D', 'P')

typedef struct _LJB_VIDPN
{
    ULONG                           MagicBegin;
    LJB_ADAPTER *                   Adapter;
    D3DKMDT_HVIDPN                  hVidPn;
    DXGK_VIDPN_INTERFACE_VERSION    VidPnInterfaceVersion;
    DXGK_VIDPN_INTERFACE *          VidPnInterface;
}   LJB_VIDPN;

/*
 * C function declaration
 */
_C_BEGIN

NTSTATUS
LJB_VIDPN_GetTopology(
    __in CONST D3DKMDT_HVIDPN                   hVidPn,
    __out D3DKMDT_HVIDPNTOPOLOGY*               phVidPnTopology,
    __out CONST DXGK_VIDPNTOPOLOGY_INTERFACE**  ppVidPnTopologyInterface
    );
NTSTATUS
LJB_VIDPN_AcquireSourceModeSet(
    __in CONST D3DKMDT_HVIDPN                       hVidPn,
    __in CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID       VidPnSourceId,
    __out D3DKMDT_HVIDPNSOURCEMODESET*              phVidPnSourceModeSet,
    __out CONST DXGK_VIDPNSOURCEMODESET_INTERFACE** ppVidPnSourceModeSetInterface
    );
NTSTATUS
LJB_VIDPN_ReleaseSourceModeSet(
    __in CONST D3DKMDT_HVIDPN               hVidPn,
    __in CONST D3DKMDT_HVIDPNSOURCEMODESET  hVidPnSourceModeSet
    );
NTSTATUS
LJB_VIDPN_CreateNewSourceModeSet(
    __in CONST D3DKMDT_HVIDPN                       hVidPn,
    __in CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID       VidPnSourceId,
    __out D3DKMDT_HVIDPNSOURCEMODESET*              phNewVidPnSourceModeSet,
    __out CONST DXGK_VIDPNSOURCEMODESET_INTERFACE** ppVidPnSourceModeSetInterface
    );
NTSTATUS
LJB_VIDPN_AssignSourceModeSet(
    __in D3DKMDT_HVIDPN                         hVidPn,
    __in CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID   VidPnSourceId,
    __in CONST D3DKMDT_HVIDPNSOURCEMODESET      hVidPnSourceModeSet
    );
NTSTATUS
LJB_VIDPN_AssignMultiSampleSourceModeSet(
    __in D3DKMDT_HVIDPN                         hVidPn,
    __in CONST D3DDDI_VIDEO_PRESENT_SOURCE_ID   VidPnSourceId,
    __in CONST SIZE_T                           NumMethods,
    __in CONST D3DDDI_MULTISAMPLINGMETHOD*      pSupportedMethodSet
    );
NTSTATUS
LJB_VIDPN_AcquireTargetModeSet(
    __in CONST D3DKMDT_HVIDPN                       hVidPn,
    __in CONST D3DDDI_VIDEO_PRESENT_TARGET_ID       VidPnTargetId,
    __out D3DKMDT_HVIDPNTARGETMODESET*              phVidPnTargetModeSet,
    __out CONST DXGK_VIDPNTARGETMODESET_INTERFACE** ppVidPnTargetModeSetInterface
    );
NTSTATUS
LJB_VIDPN_ReleaseTargetModeSet(
    __in CONST D3DKMDT_HVIDPN               hVidPn,
    __in CONST D3DKMDT_HVIDPNTARGETMODESET  hVidPnTargetModeSet
    );
NTSTATUS
LJB_VIDPN_CreateNewTargetModeSet(
    __in CONST D3DKMDT_HVIDPN                       hVidPn,
    __in CONST D3DDDI_VIDEO_PRESENT_TARGET_ID       VidPnTargetId,
    __out D3DKMDT_HVIDPNTARGETMODESET*              phNewVidPnTargetModeSet,
    __out CONST DXGK_VIDPNTARGETMODESET_INTERFACE** ppVidPnTargetModeSetInterface
    );
NTSTATUS
LJB_VIDPN_AssignTargetModeSet(
    __in D3DKMDT_HVIDPN                         hVidPn,
    __in CONST D3DDDI_VIDEO_PRESENT_TARGET_ID   VidPnTargetId,
    __in CONST D3DKMDT_HVIDPNTARGETMODESET      hVidPnTargetModeSet
    );

_C_END

#endif