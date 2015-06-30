// auto generated by go tool dist

// +build !android

#define	get_tls(r)	MOVL TLS, r
#define	g(r)	0(r)(TLS*1)
#define const_Gidle 0
#define const_Grunnable 1
#define const_Grunning 2
#define const_Gsyscall 3
#define const_Gwaiting 4
#define const_Gmoribund_unused 5
#define const_Gdead 6
#define const_Genqueue 7
#define const_Gcopystack 8
#define const_Gscan 4096
#define const_Gscanrunnable 4097
#define const_Gscanrunning 4098
#define const_Gscansyscall 4099
#define const_Gscanwaiting 4100
#define const_Gscanenqueue 4103
#define const_Pidle 0
#define const_Prunning 1
#define const_Psyscall 2
#define const_Pgcstop 3
#define const_Pdead 4
#define const_true 1
#define const_false 0
#define const_PtrSize 4
#define const_sizeofMutex 4
#define const_sizeofNote 4
#define const_sizeofString 8
#define const_sizeofFuncVal 4
#define const_sizeofIface 8
#define const_sizeofEface 8
#define const_sizeofComplex64 8
#define const_sizeofComplex128 16
#define const_sizeofSlice 12
#define const_sizeofGobuf 24
#define gobuf_sp 0
#define gobuf_pc 4
#define gobuf_g 8
#define gobuf_ctxt 12
#define gobuf_ret 16
#define gobuf_lr 20
#define const_sizeofSudoG 36
#define const_sizeofGCStats 40
#define const_sizeofLibCall 24
#define libcall_fn 0
#define libcall_n 4
#define libcall_args 8
#define libcall_r1 12
#define libcall_r2 16
#define libcall_err 20
#define const_sizeofWinCallbackContext 16
#define cbctxt_gobody 0
#define cbctxt_argsize 4
#define cbctxt_restorestack 8
#define cbctxt_cleanstack 12
#define const_sizeofStack 8
#define stack_lo 0
#define stack_hi 4
#define const_sizeofG 148
#define g_stack 0
#define g_stackguard0 8
#define g_stackguard1 12
#define g_panic 16
#define g_defer 20
#define g_sched 24
#define g_syscallsp 48
#define g_syscallpc 52
#define g_param 56
#define g_atomicstatus 60
#define g_goid 64
#define g_waitsince 72
#define g_waitreason 80
#define g_schedlink 88
#define g_issystem 92
#define g_preempt 93
#define g_paniconfault 94
#define g_preemptscan 95
#define g_gcworkdone 96
#define g_throwsplit 97
#define g_raceignore 98
#define g_m 100
#define g_lockedm 104
#define g_sig 108
#define g_writebuf 112
#define g_sigcode0 124
#define g_sigcode1 128
#define g_sigpc 132
#define g_gopc 136
#define g_racectx 140
#define g_waiting 144
#define g_end 148
#define const_sizeofM 524
#define m_g0 0
#define m_morebuf 4
#define m_procid 28
#define m_gsignal 36
#define m_tls 40
#define m_mstartfn 56
#define m_curg 60
#define m_caughtsig 64
#define m_p 68
#define m_nextp 72
#define m_id 76
#define m_mallocing 80
#define m_throwing 84
#define m_gcing 88
#define m_locks 92
#define m_softfloat 96
#define m_dying 100
#define m_profilehz 104
#define m_helpgc 108
#define m_spinning 112
#define m_blocked 113
#define m_fastrand 116
#define m_ncgocall 120
#define m_ncgo 128
#define m_cgomal 132
#define m_park 136
#define m_alllink 140
#define m_schedlink 144
#define m_machport 148
#define m_mcache 152
#define m_lockedg 156
#define m_createstack 160
#define m_freglo 288
#define m_freghi 352
#define m_fflag 416
#define m_locked 420
#define m_nextwaitm 424
#define m_waitsema 428
#define m_waitsemacount 432
#define m_waitsemalock 436
#define m_gcstats 440
#define m_needextram 480
#define m_traceback 481
#define m_waitunlockf 484
#define m_waitlock 488
#define m_scalararg 492
#define m_ptrarg 508
#define m_end 524
#define const_sizeofP 1172
#define p_lock 0
#define p_id 4
#define p_status 8
#define p_link 12
#define p_schedtick 16
#define p_syscalltick 20
#define p_m 24
#define p_mcache 28
#define p_deferpool 32
#define p_goidcache 52
#define p_goidcacheend 60
#define p_runqhead 68
#define p_runqtail 72
#define p_runq 76
#define p_gfree 1100
#define p_gfreecnt 1104
#define p_pad 1108
#define const_MaxGomaxprocs 256
#define const_sizeofSchedT 100
#define const_LockExternal 1
#define const_LockInternal 2
#define const_sizeofSigTab 8
#define const_SigNotify 1
#define const_SigKill 2
#define const_SigThrow 4
#define const_SigPanic 8
#define const_SigDefault 16
#define const_SigHandling 32
#define const_SigIgnored 64
#define const_SigGoExit 128
#define const_sizeofFunc 36
#define const_sizeofItab 20
#define const_NaCl 0
#define const_Windows 0
#define const_Solaris 0
#define const_Plan9 0
#define const_sizeofLFNode 8
#define const_sizeofParFor 80
#define const_sizeofCgoMal 8
#define const_sizeofDebugVars 28
#define const_GCoff 0
#define const_GCquiesce 1
#define const_GCstw 2
#define const_GCmark 3
#define const_GCsweep 4
#define const_sizeofForceGCState 12
#define const_Structrnd 4
#define const_HashRandomBytes 32
#define const_sizeofDefer 28
#define const_sizeofPanic 20
#define panic_argp 0
#define panic_arg 4
#define panic_link 12
#define panic_recovered 16
#define panic_aborted 17
#define const_sizeofStkframe 40
#define const_TraceRuntimeFrames 1
#define const_TraceTrap 2
#define const_TracebackMaxFrames 100
#define const_UseSpanType 1
#define const_thechar 56
#define const_BigEndian 0
#define const_CacheLineSize 64
#define const_RuntimeGogoBytes 64
#define const_PhysPageSize 4096
#define const_PCQuantum 1
#define const_Int64Align 4
#define const_PageShift 13
#define const_PageSize 8192
#define const_PageMask 8191
#define const_NumSizeClasses 67
#define const_MaxSmallSize 32768
#define const_TinySize 16
#define const_TinySizeClass 2
#define const_FixAllocChunk 16384
#define const_MaxMHeapList 128
#define const_HeapAllocChunk 1048576
#define const_StackCacheSize 32768
#define const_NumStackOrders 3
#define const_MHeapMap_Bits 19
#define const_MaxGcproc 32
#define const_sizeofMLink 4
#define const_sizeofFixAlloc 32
#define const_sizeofMStatsBySize 20
#define const_sizeofMStats 5644
#define const_sizeofMCacheList 8
#define const_sizeofStackFreeList 8
#define const_sizeofMCache 600
#define const_KindSpecialFinalizer 1
#define const_KindSpecialProfile 2
#define const_sizeofSpecial 8
#define const_sizeofSpecialFinalizer 24
#define const_sizeofSpecialProfile 12
#define const_MSpanInUse 0
#define const_MSpanStack 1
#define const_MSpanFree 2
#define const_MSpanListHead 3
#define const_MSpanDead 4
#define const_sizeofMSpan 60
#define const_sizeofMCentral 128
#define const_sizeofMHeapCentral 192
#define const_sizeofMHeap 29088
#define const_FlagNoScan 1
#define const_FlagNoZero 2
#define const_sizeofFinalizer 20
#define const_sizeofFinBlock 36
#define const_sizeofBitVector 8
#define const_sizeofStackMap 8
#define const_StackSystem 0
#define const_StackMin 2048
#define const_FixedStack0 2048
#define const_FixedStack1 2047
#define const_FixedStack2 2047
#define const_FixedStack3 2047
#define const_FixedStack4 2047
#define const_FixedStack5 2047
#define const_FixedStack6 2047
#define const_FixedStack 2048
#define const_StackBig 4096
#define const_StackGuard 512
#define const_StackSmall 128
#define const_StackLimit 384
#define const_raceenabled 0
#define const_sizeofType 40
#define const_sizeofMethod 24
#define const_sizeofUncommonType 20
#define const_sizeofIMethod 12
#define const_sizeofInterfaceType 52
#define const_sizeofMapType 64
#define const_sizeofChanType 48
#define const_sizeofSliceType 44
#define const_sizeofFuncType 68
#define const_sizeofPtrType 44
#define const_gcBits 4
#define const_wordsPerBitmapByte 2
#define const_insData 1
#define const_insArray 2
#define const_insArrayEnd 3
#define const_insEnd 4
#define const_BitsPerPointer 2
#define const_BitsMask 3
#define const_PointersPerByte 4
#define const_BitsDead 0
#define const_BitsScalar 1
#define const_BitsPointer 2
#define const_BitsMultiWord 3
#define const_BitsIface 2
#define const_BitsEface 3
#define const_MaxGCMask 64
#define const_bitBoundary 1
#define const_bitMarked 2
#define const_bitMask 3
#define const_bitPtrMask 12
#define const_GoidCacheBatch 16
#define const_sizeofCgoThreadStart 12
#define const_sizeofProfState 8
#define const_sizeofPdesc 24
#define GOEXPERIMENT ""
