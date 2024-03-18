#if 0
;
; Input signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; TEXCOORD                 0   xy          0     NONE   float   xy  
; TEXCOORD                 1   xyzw        1     NONE   float   xyzw
;
;
; Output signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; TEXCOORD                 0   xyzw        0     NONE   float   xyzw
; SV_Position              0   xyzw        1      POS   float   xyzw
;
; shader hash: f13b1cc9b87e560da744659dd5d39dcb
;
; Pipeline Runtime Information: 
;
; Vertex Shader
; OutputPositionPresent=1
;
;
; Input signature:
;
; Name                 Index             InterpMode DynIdx
; -------------------- ----- ---------------------- ------
; TEXCOORD                 0                              
; TEXCOORD                 1                              
;
; Output signature:
;
; Name                 Index             InterpMode DynIdx
; -------------------- ----- ---------------------- ------
; TEXCOORD                 0                 linear       
; SV_Position              0          noperspective       
;
; Buffer Definitions:
;
; cbuffer _18_20
; {
;
;   struct hostlayout._18_20
;   {
;
;       row_major float4x4 _20_m0;                    ; Offset:    0
;       float4 _20_m1;                                ; Offset:   64
;       float2 _20_m2;                                ; Offset:   80
;   
;   } _18_20;                                         ; Offset:    0 Size:    88
;
; }
;
;
; Resource Bindings:
;
; Name                                 Type  Format         Dim      ID      HLSL Bind  Count
; ------------------------------ ---------- ------- ----------- ------- -------------- ------
; _18_20                            cbuffer      NA          NA     CB0     cb0,space1     1
;
;
; ViewId state:
;
; Number of inputs: 8, outputs: 8
; Outputs dependent on ViewId: {  }
; Inputs contributing to computation of Outputs:
;   output 0 depends on inputs: { 4 }
;   output 1 depends on inputs: { 5 }
;   output 2 depends on inputs: { 6 }
;   output 3 depends on inputs: { 7 }
;   output 4 depends on inputs: { 0, 1 }
;   output 5 depends on inputs: { 0, 1 }
;   output 6 depends on inputs: { 0, 1 }
;   output 7 depends on inputs: { 0, 1 }
;
target datalayout = "e-m:e-p:32:32-i1:32-i8:32-i16:32-i32:32-i64:64-f16:32-f32:32-f64:64-n8:16:32:64"
target triple = "dxil-ms-dx"

%dx.types.Handle = type { i8* }
%dx.types.CBufRet.f32 = type { float, float, float, float }
%hostlayout._18_20 = type { [4 x <4 x float>], <4 x float>, <2 x float> }

define void @main() {
  %1 = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 2, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %2 = call float @dx.op.loadInput.f32(i32 4, i32 1, i32 0, i8 0, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %3 = call float @dx.op.loadInput.f32(i32 4, i32 1, i32 0, i8 1, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %4 = call float @dx.op.loadInput.f32(i32 4, i32 1, i32 0, i8 2, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %5 = call float @dx.op.loadInput.f32(i32 4, i32 1, i32 0, i8 3, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %6 = call float @dx.op.loadInput.f32(i32 4, i32 0, i32 0, i8 0, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %7 = call float @dx.op.loadInput.f32(i32 4, i32 0, i32 0, i8 1, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %8 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 0)  ; CBufferLoadLegacy(handle,regIndex)
  %9 = extractvalue %dx.types.CBufRet.f32 %8, 0
  %10 = extractvalue %dx.types.CBufRet.f32 %8, 1
  %11 = extractvalue %dx.types.CBufRet.f32 %8, 2
  %12 = extractvalue %dx.types.CBufRet.f32 %8, 3
  %13 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 1)  ; CBufferLoadLegacy(handle,regIndex)
  %14 = extractvalue %dx.types.CBufRet.f32 %13, 0
  %15 = extractvalue %dx.types.CBufRet.f32 %13, 1
  %16 = extractvalue %dx.types.CBufRet.f32 %13, 2
  %17 = extractvalue %dx.types.CBufRet.f32 %13, 3
  %18 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 3)  ; CBufferLoadLegacy(handle,regIndex)
  %19 = extractvalue %dx.types.CBufRet.f32 %18, 0
  %20 = extractvalue %dx.types.CBufRet.f32 %18, 1
  %21 = extractvalue %dx.types.CBufRet.f32 %18, 2
  %22 = extractvalue %dx.types.CBufRet.f32 %18, 3
  %23 = fmul fast float %9, %6
  %24 = call float @dx.op.tertiary.f32(i32 46, float %7, float %14, float %23)  ; FMad(a,b,c)
  %25 = fadd fast float %19, %24
  %26 = fmul fast float %10, %6
  %27 = call float @dx.op.tertiary.f32(i32 46, float %7, float %15, float %26)  ; FMad(a,b,c)
  %28 = fadd fast float %27, %20
  %29 = fmul fast float %11, %6
  %30 = call float @dx.op.tertiary.f32(i32 46, float %7, float %16, float %29)  ; FMad(a,b,c)
  %31 = fadd fast float %30, %21
  %32 = fmul fast float %12, %6
  %33 = call float @dx.op.tertiary.f32(i32 46, float %7, float %17, float %32)  ; FMad(a,b,c)
  %34 = fadd fast float %33, %22
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 0, float %2)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 1, float %3)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 2, float %4)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 3, float %5)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 1, i32 0, i8 0, float %25)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 1, i32 0, i8 1, float %28)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 1, i32 0, i8 2, float %31)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 1, i32 0, i8 3, float %34)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  ret void
}

; Function Attrs: nounwind readnone
declare float @dx.op.loadInput.f32(i32, i32, i32, i8, i32) #0

; Function Attrs: nounwind
declare void @dx.op.storeOutput.f32(i32, i32, i32, i8, float) #1

; Function Attrs: nounwind readonly
declare %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32, %dx.types.Handle, i32) #2

; Function Attrs: nounwind readnone
declare float @dx.op.tertiary.f32(i32, float, float, float) #0

; Function Attrs: nounwind readonly
declare %dx.types.Handle @dx.op.createHandle(i32, i8, i32, i32, i1) #2

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind }
attributes #2 = { nounwind readonly }

!llvm.ident = !{!0}
!dx.version = !{!1}
!dx.valver = !{!2}
!dx.shaderModel = !{!3}
!dx.resources = !{!4}
!dx.viewIdState = !{!7}
!dx.entryPoints = !{!8}

!0 = !{!"dxc(private) 1.8.0.4662 (416fab6b5)"}
!1 = !{i32 1, i32 0}
!2 = !{i32 1, i32 8}
!3 = !{!"vs", i32 6, i32 0}
!4 = !{null, null, !5, null}
!5 = !{!6}
!6 = !{i32 0, %hostlayout._18_20* undef, !"", i32 1, i32 0, i32 1, i32 88, null}
!7 = !{[10 x i32] [i32 8, i32 8, i32 240, i32 240, i32 0, i32 0, i32 1, i32 2, i32 4, i32 8]}
!8 = !{void ()* @main, !"main", !9, !4, null}
!9 = !{!10, !17, null}
!10 = !{!11, !14}
!11 = !{i32 0, !"TEXCOORD", i8 9, i8 0, !12, i8 0, i32 1, i8 2, i32 0, i8 0, !13}
!12 = !{i32 0}
!13 = !{i32 3, i32 3}
!14 = !{i32 1, !"TEXCOORD", i8 9, i8 0, !15, i8 0, i32 1, i8 4, i32 1, i8 0, !16}
!15 = !{i32 1}
!16 = !{i32 3, i32 15}
!17 = !{!18, !19}
!18 = !{i32 0, !"TEXCOORD", i8 9, i8 0, !12, i8 2, i32 1, i8 4, i32 0, i8 0, !16}
!19 = !{i32 1, !"SV_Position", i8 9, i8 3, !12, i8 4, i32 1, i8 4, i32 1, i8 0, !16}

#endif

const unsigned char tri_color_vert_sm60_dxil[] = {
  0x44, 0x58, 0x42, 0x43, 0xeb, 0x11, 0xa0, 0x76, 0xea, 0x69, 0xbc, 0x28,
  0xcd, 0xbc, 0x0c, 0xab, 0x14, 0x5d, 0xfa, 0x53, 0x01, 0x00, 0x00, 0x00,
  0x98, 0x0f, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00,
  0x08, 0x02, 0x00, 0x00, 0x70, 0x08, 0x00, 0x00, 0x8c, 0x08, 0x00, 0x00,
  0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x31, 0x54, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0x00, 0x00, 0x00,
  0x4f, 0x53, 0x47, 0x31, 0x60, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54, 0x45, 0x58, 0x43,
  0x4f, 0x4f, 0x52, 0x44, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x6f, 0x73, 0x69,
  0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x50, 0x53, 0x56, 0x30,
  0xf0, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00,
  0x02, 0x02, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00,
  0x00, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0x54, 0x45,
  0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4f,
  0x4f, 0x52, 0x44, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x42, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x44, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x44, 0x00,
  0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x01, 0x44, 0x03, 0x03, 0x04, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00,
  0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x53, 0x54, 0x41, 0x54, 0x60, 0x06, 0x00, 0x00,
  0x60, 0x00, 0x01, 0x00, 0x98, 0x01, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c,
  0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x48, 0x06, 0x00, 0x00,
  0x42, 0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00, 0x8f, 0x01, 0x00, 0x00,
  0x0b, 0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x07, 0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39,
  0x92, 0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62,
  0x80, 0x14, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42, 0xa4, 0x10, 0x32, 0x14,
  0x38, 0x08, 0x18, 0x4b, 0x0a, 0x32, 0x52, 0x88, 0x48, 0x90, 0x14, 0x20,
  0x43, 0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90,
  0x91, 0x22, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a,
  0x04, 0x29, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x1b, 0x8c, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d,
  0x84, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff,
  0xff, 0xff, 0xff, 0x1f, 0x00, 0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x13, 0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06,
  0x00, 0x00, 0x00, 0x00, 0x89, 0x20, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00,
  0x32, 0x22, 0x48, 0x09, 0x20, 0x64, 0x85, 0x04, 0x93, 0x22, 0xa4, 0x84,
  0x04, 0x93, 0x22, 0xe3, 0x84, 0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8a, 0x8c,
  0x0b, 0x84, 0xa4, 0x4c, 0x10, 0x6c, 0x23, 0x00, 0x25, 0x00, 0x14, 0x66,
  0x00, 0xe6, 0x08, 0xc0, 0x60, 0x8e, 0x00, 0x29, 0xc6, 0x20, 0x84, 0x14,
  0x42, 0xa6, 0x18, 0x80, 0x10, 0x52, 0x06, 0xa1, 0xa3, 0x86, 0xcb, 0x9f,
  0xb0, 0x87, 0x90, 0x7c, 0x6e, 0xa3, 0x8a, 0x95, 0x98, 0xfc, 0xe2, 0xb6,
  0x11, 0x31, 0xc6, 0x18, 0x54, 0xee, 0x19, 0x2e, 0x7f, 0xc2, 0x1e, 0x42,
  0xf2, 0x43, 0xa0, 0x19, 0x16, 0x02, 0x05, 0xab, 0x10, 0x8a, 0x30, 0x42,
  0xad, 0x14, 0x83, 0x8c, 0x31, 0xe8, 0xcd, 0x11, 0x04, 0xc5, 0x60, 0xa4,
  0x10, 0x12, 0x49, 0x0e, 0x04, 0x0c, 0x23, 0x10, 0x43, 0x12, 0xd4, 0x61,
  0x04, 0x61, 0xb8, 0xe8, 0x70, 0xa4, 0x69, 0x01, 0x30, 0x87, 0x9a, 0xfc,
  0xbf, 0xe6, 0x7f, 0x9b, 0x46, 0x83, 0xad, 0x97, 0x70, 0x2a, 0x10, 0x00,
  0x13, 0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79,
  0x68, 0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e,
  0x7a, 0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07,
  0x6d, 0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e,
  0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07,
  0x7a, 0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07,
  0x6d, 0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x43, 0x9e, 0x00, 0x08, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x3c, 0x06, 0x10, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x10, 0x20,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x34,
  0x40, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4,
  0x79, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
  0xc8, 0x23, 0x01, 0x01, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x16, 0x08, 0x00, 0x13, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14,
  0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x22,
  0x25, 0x30, 0x02, 0x50, 0x0c, 0x05, 0x1b, 0x50, 0x04, 0x85, 0x50, 0x06,
  0xe5, 0x50, 0x12, 0x05, 0x18, 0x50, 0x1a, 0x05, 0x1a, 0x50, 0x1e, 0x05,
  0x51, 0x56, 0x54, 0x4a, 0x62, 0x04, 0xa0, 0x08, 0x0a, 0xa1, 0x0c, 0x28,
  0xd6, 0x00, 0xe1, 0x19, 0x00, 0xca, 0x33, 0x00, 0xa4, 0xc7, 0x52, 0x10,
  0x04, 0x3e, 0xe0, 0x03, 0x00, 0x02, 0x81, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x79, 0x18, 0x00, 0x00, 0x8e, 0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90,
  0x46, 0x02, 0x13, 0xc4, 0x31, 0x20, 0xc3, 0x1b, 0x43, 0x81, 0x93, 0x4b,
  0xb3, 0x0b, 0xa3, 0x2b, 0x4b, 0x01, 0x89, 0x71, 0xc1, 0x71, 0x81, 0x71,
  0xa1, 0xb1, 0xb1, 0x91, 0x01, 0x41, 0xa1, 0x89, 0xb1, 0x31, 0x0b, 0x13,
  0xb3, 0x11, 0xab, 0x49, 0xd9, 0x10, 0x04, 0x13, 0x04, 0xc2, 0x98, 0x20,
  0x10, 0xc7, 0x06, 0x61, 0x20, 0x36, 0x08, 0x04, 0x41, 0xc1, 0x6e, 0x6e,
  0x82, 0x40, 0x20, 0x1b, 0x86, 0x03, 0x21, 0x26, 0x08, 0x19, 0x47, 0xe3,
  0x2b, 0x06, 0xe7, 0x4b, 0x06, 0x66, 0x82, 0x40, 0x24, 0x1b, 0x10, 0x42,
  0x59, 0x06, 0x62, 0x60, 0x80, 0x0d, 0x41, 0xb3, 0x81, 0x00, 0x00, 0x07,
  0x98, 0x20, 0x60, 0x1b, 0x8d, 0x2f, 0x19, 0x98, 0xaf, 0x36, 0x98, 0x09,
  0x02, 0xa1, 0x4c, 0x10, 0x88, 0x65, 0xc3, 0x30, 0x4d, 0xc3, 0x04, 0x81,
  0x60, 0x26, 0x08, 0x44, 0x33, 0x41, 0x20, 0x9c, 0x09, 0x42, 0xa4, 0x6d,
  0x50, 0x90, 0x48, 0xa2, 0x2a, 0xc2, 0xba, 0x2e, 0x8c, 0xc6, 0x97, 0x0c,
  0xcc, 0x57, 0x5b, 0xcc, 0x04, 0x81, 0x78, 0x26, 0x08, 0x04, 0xb4, 0x01,
  0x41, 0xb4, 0x6a, 0xb3, 0x2e, 0x6e, 0xa2, 0xf1, 0x25, 0x03, 0xf3, 0xd5,
  0x26, 0x33, 0x41, 0x20, 0xa2, 0x0d, 0x08, 0xe2, 0x55, 0x9f, 0x75, 0x71,
  0xd2, 0x06, 0x82, 0xc9, 0x3a, 0x30, 0xd8, 0x30, 0x10, 0x50, 0x18, 0x4c,
  0x10, 0x04, 0x60, 0x03, 0xb0, 0x61, 0x20, 0xc8, 0x80, 0x0c, 0x36, 0x04,
  0x65, 0xb0, 0x61, 0x18, 0xc6, 0xc0, 0x0c, 0x26, 0x08, 0x5a, 0xb7, 0x21,
  0x40, 0x03, 0x12, 0x6d, 0x61, 0x69, 0x6e, 0x44, 0xa8, 0x8a, 0xb0, 0x86,
  0x9e, 0x9e, 0xa4, 0x88, 0x26, 0x08, 0x45, 0x35, 0x41, 0x28, 0xac, 0x0d,
  0x01, 0x31, 0x41, 0x28, 0xae, 0x0d, 0x42, 0x55, 0x6d, 0x58, 0x88, 0x35,
  0x60, 0x83, 0x36, 0x70, 0x83, 0x36, 0x18, 0xde, 0x80, 0x68, 0x03, 0x38,
  0xd8, 0x10, 0x0c, 0x13, 0x84, 0x02, 0x9b, 0x20, 0x10, 0xd2, 0x06, 0xa1,
  0xa2, 0x83, 0x0d, 0xcb, 0xb0, 0x06, 0x6c, 0xd0, 0x06, 0x72, 0xd0, 0x06,
  0xc3, 0x1c, 0x0c, 0x6d, 0x50, 0x07, 0x1b, 0x84, 0x38, 0xb0, 0x83, 0x0d,
  0x0b, 0xb1, 0x06, 0x6c, 0xd0, 0x06, 0x6e, 0xf0, 0x06, 0xc3, 0x1c, 0x10,
  0x6d, 0x50, 0x07, 0x5c, 0xa6, 0xac, 0xbe, 0xa0, 0xde, 0xe6, 0xd2, 0xe8,
  0xd2, 0xde, 0xdc, 0x26, 0x08, 0x45, 0xb6, 0x61, 0x19, 0xf2, 0x80, 0x0d,
  0xf4, 0xc0, 0x0d, 0xe6, 0x60, 0x98, 0x83, 0xa1, 0x0d, 0xea, 0x60, 0x83,
  0x80, 0x07, 0x7b, 0xb0, 0x61, 0xb8, 0x03, 0x3e, 0x00, 0x36, 0x14, 0x63,
  0xa0, 0x06, 0x7d, 0xf0, 0x00, 0x34, 0xcc, 0xd8, 0xde, 0xc2, 0xe8, 0xe6,
  0x26, 0x08, 0xc4, 0xc4, 0x22, 0xcd, 0x6d, 0x8e, 0x6e, 0x6e, 0x82, 0x40,
  0x50, 0x34, 0xe6, 0xd2, 0xce, 0xbe, 0xd8, 0xc8, 0x68, 0xcc, 0xa5, 0x9d,
  0x7d, 0xcd, 0xd1, 0x6d, 0x40, 0xfe, 0x00, 0x14, 0x42, 0x41, 0x14, 0x46,
  0x01, 0x21, 0x05, 0x50, 0xa8, 0xc2, 0xc6, 0x66, 0xd7, 0xe6, 0x92, 0x46,
  0x56, 0xe6, 0x46, 0x37, 0x25, 0x08, 0xaa, 0x90, 0xe1, 0xb9, 0xd8, 0x95,
  0xc9, 0xcd, 0xa5, 0xbd, 0xb9, 0x4d, 0x09, 0x88, 0x26, 0x64, 0x78, 0x2e,
  0x76, 0x61, 0x6c, 0x76, 0x65, 0x72, 0x53, 0x82, 0xa2, 0x0e, 0x19, 0x9e,
  0xcb, 0x1c, 0x5a, 0x18, 0x59, 0x99, 0x5c, 0xd3, 0x1b, 0x59, 0x19, 0xdb,
  0x94, 0x00, 0x29, 0x43, 0x86, 0xe7, 0x22, 0x57, 0x36, 0xf7, 0x56, 0x27,
  0x37, 0x56, 0x36, 0x37, 0x25, 0x70, 0x2a, 0x91, 0xe1, 0xb9, 0xd0, 0xe5,
  0xc1, 0x95, 0x05, 0xb9, 0xb9, 0xbd, 0xd1, 0x85, 0xd1, 0xa5, 0xbd, 0xb9,
  0xcd, 0x4d, 0x11, 0xc2, 0xc0, 0x0c, 0xea, 0x90, 0xe1, 0xb9, 0xd8, 0xa5,
  0x95, 0xdd, 0x25, 0x91, 0x4d, 0xd1, 0x85, 0xd1, 0x95, 0x4d, 0x09, 0xd0,
  0xa0, 0x0e, 0x19, 0x9e, 0x4b, 0x99, 0x1b, 0x9d, 0x5c, 0x1e, 0xd4, 0x5b,
  0x9a, 0x1b, 0xdd, 0xdc, 0x94, 0xa0, 0x0f, 0xba, 0x90, 0xe1, 0xb9, 0x8c,
  0xbd, 0xd5, 0xb9, 0xd1, 0x95, 0xc9, 0xcd, 0x4d, 0x09, 0x48, 0x01, 0x00,
  0x79, 0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c,
  0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3,
  0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6,
  0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e,
  0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43,
  0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03,
  0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48,
  0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20,
  0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e,
  0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d,
  0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89,
  0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83,
  0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68,
  0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90,
  0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78,
  0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98,
  0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5,
  0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c,
  0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c,
  0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43,
  0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43,
  0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82,
  0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xc8, 0x21, 0x07, 0x7c, 0x70,
  0x03, 0x72, 0x10, 0x87, 0x73, 0x70, 0x03, 0x7b, 0x08, 0x07, 0x79, 0x60,
  0x87, 0x70, 0xc8, 0x87, 0x77, 0xa8, 0x07, 0x7a, 0x98, 0x81, 0x3c, 0xe4,
  0x80, 0x0f, 0x6e, 0x40, 0x0f, 0xe5, 0xd0, 0x0e, 0xf0, 0x00, 0x00, 0x00,
  0x71, 0x20, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x36, 0xb0, 0x0d, 0x97,
  0xef, 0x3c, 0xbe, 0x10, 0x50, 0x45, 0x41, 0x44, 0xa5, 0x03, 0x0c, 0x25,
  0x61, 0x00, 0x02, 0xe6, 0x17, 0xb7, 0x6d, 0x05, 0xd2, 0x70, 0xf9, 0xce,
  0xe3, 0x0b, 0x11, 0x01, 0x4c, 0x44, 0x08, 0x34, 0xc3, 0x42, 0x58, 0xc0,
  0x34, 0x5c, 0xbe, 0xf3, 0xf8, 0x8b, 0x03, 0x0c, 0x62, 0xf3, 0x50, 0x93,
  0x5f, 0xdc, 0xb6, 0x09, 0x54, 0xc3, 0xe5, 0x3b, 0x8f, 0x2f, 0x4d, 0x4e,
  0x44, 0xa0, 0xd4, 0xf4, 0x50, 0x93, 0x5f, 0xdc, 0xb6, 0x11, 0x48, 0xc3,
  0xe5, 0x3b, 0x8f, 0x3f, 0x11, 0xd1, 0x84, 0x00, 0x11, 0xe6, 0x17, 0xb7,
  0x6d, 0x00, 0x04, 0x03, 0x20, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x48, 0x41, 0x53, 0x48, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf1, 0x3b, 0x1c, 0xc9, 0xb8, 0x7e, 0x56, 0x0d, 0xa7, 0x44, 0x65, 0x9d,
  0xd5, 0xd3, 0x9d, 0xcb, 0x44, 0x58, 0x49, 0x4c, 0x04, 0x07, 0x00, 0x00,
  0x60, 0x00, 0x01, 0x00, 0xc1, 0x01, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c,
  0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xec, 0x06, 0x00, 0x00,
  0x42, 0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00, 0xb8, 0x01, 0x00, 0x00,
  0x0b, 0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x07, 0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39,
  0x92, 0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62,
  0x80, 0x14, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42, 0xa4, 0x10, 0x32, 0x14,
  0x38, 0x08, 0x18, 0x4b, 0x0a, 0x32, 0x52, 0x88, 0x48, 0x90, 0x14, 0x20,
  0x43, 0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90,
  0x91, 0x22, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a,
  0x04, 0x29, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x1b, 0x8c, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d,
  0x84, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff,
  0xff, 0xff, 0xff, 0x1f, 0x00, 0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x13, 0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06,
  0x00, 0x00, 0x00, 0x00, 0x89, 0x20, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00,
  0x32, 0x22, 0x48, 0x09, 0x20, 0x64, 0x85, 0x04, 0x93, 0x22, 0xa4, 0x84,
  0x04, 0x93, 0x22, 0xe3, 0x84, 0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8a, 0x8c,
  0x0b, 0x84, 0xa4, 0x4c, 0x10, 0x6c, 0x23, 0x00, 0x25, 0x00, 0x14, 0x66,
  0x00, 0xe6, 0x08, 0xc0, 0x60, 0x8e, 0x00, 0x29, 0xc6, 0x20, 0x84, 0x14,
  0x42, 0xa6, 0x18, 0x80, 0x10, 0x52, 0x06, 0xa1, 0xa3, 0x86, 0xcb, 0x9f,
  0xb0, 0x87, 0x90, 0x7c, 0x6e, 0xa3, 0x8a, 0x95, 0x98, 0xfc, 0xe2, 0xb6,
  0x11, 0x31, 0xc6, 0x18, 0x54, 0xee, 0x19, 0x2e, 0x7f, 0xc2, 0x1e, 0x42,
  0xf2, 0x43, 0xa0, 0x19, 0x16, 0x02, 0x05, 0xab, 0x10, 0x8a, 0x30, 0x42,
  0xad, 0x14, 0x83, 0x8c, 0x31, 0xe8, 0xcd, 0x11, 0x04, 0xc5, 0x60, 0xa4,
  0x10, 0x12, 0x49, 0x0e, 0x04, 0x0c, 0x23, 0x10, 0x43, 0x12, 0xd4, 0x61,
  0x04, 0x61, 0xb8, 0xe8, 0x70, 0xa4, 0x69, 0x01, 0x30, 0x87, 0x9a, 0xfc,
  0xbf, 0xe6, 0x7f, 0x9b, 0x46, 0x83, 0xad, 0x97, 0x70, 0x2a, 0x10, 0x00,
  0x13, 0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79,
  0x68, 0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e,
  0x7a, 0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07,
  0x6d, 0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e,
  0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07,
  0x7a, 0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07,
  0x6d, 0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x43, 0x9e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x3c, 0x06, 0x10, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x10, 0x20,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x34,
  0x40, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4,
  0x79, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
  0xc8, 0x23, 0x01, 0x01, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x16, 0x08, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14,
  0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x22,
  0x25, 0x30, 0x02, 0x50, 0x10, 0xc5, 0x50, 0xb0, 0x01, 0x65, 0x50, 0x1e,
  0x54, 0x4a, 0x62, 0x04, 0xa0, 0x08, 0x0a, 0xa1, 0x0c, 0x28, 0xcf, 0x00,
  0x90, 0x1e, 0x4b, 0x41, 0x10, 0xf8, 0x80, 0x0f, 0x00, 0x08, 0x04, 0x02,
  0x01, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x57, 0x00, 0x00, 0x00,
  0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4, 0x31, 0x20, 0xc3, 0x1b,
  0x43, 0x81, 0x93, 0x4b, 0xb3, 0x0b, 0xa3, 0x2b, 0x4b, 0x01, 0x89, 0x71,
  0xc1, 0x71, 0x81, 0x71, 0xa1, 0xb1, 0xb1, 0x91, 0x01, 0x41, 0xa1, 0x89,
  0xb1, 0x31, 0x0b, 0x13, 0xb3, 0x11, 0xab, 0x49, 0xd9, 0x10, 0x04, 0x13,
  0x04, 0xc2, 0x98, 0x20, 0x10, 0xc7, 0x06, 0x61, 0x20, 0x26, 0x08, 0x04,
  0xb2, 0x41, 0x18, 0x0c, 0x0a, 0x76, 0x73, 0x13, 0x04, 0x22, 0xd9, 0x30,
  0x20, 0x09, 0x31, 0x41, 0xc8, 0x24, 0x02, 0x13, 0x04, 0x42, 0xd9, 0x80,
  0x10, 0x0b, 0x33, 0x10, 0x43, 0x03, 0x6c, 0x08, 0x9c, 0x0d, 0x04, 0x00,
  0x3c, 0xc0, 0x04, 0x41, 0x9b, 0x36, 0x04, 0xd1, 0x04, 0x41, 0x00, 0x48,
  0xb4, 0x85, 0xa5, 0xb9, 0x11, 0xa1, 0x2a, 0xc2, 0x1a, 0x7a, 0x7a, 0x92,
  0x22, 0x9a, 0x20, 0x14, 0xcd, 0x04, 0xa1, 0x70, 0x36, 0x04, 0xc4, 0x04,
  0xa1, 0x78, 0x26, 0x08, 0xc4, 0xb2, 0x41, 0xd0, 0xb4, 0x0d, 0x0b, 0x51,
  0x59, 0x17, 0x76, 0x0d, 0x19, 0x71, 0x6d, 0x1b, 0x82, 0x61, 0x82, 0x50,
  0x40, 0x13, 0x04, 0x82, 0xd9, 0x20, 0x68, 0xdf, 0x86, 0x65, 0xa8, 0xac,
  0xab, 0xbb, 0x06, 0x6f, 0xb8, 0xc0, 0x60, 0x83, 0xc0, 0x85, 0xc1, 0x86,
  0x85, 0xa8, 0xac, 0x0b, 0xcb, 0x06, 0x8f, 0xb8, 0xc0, 0x80, 0xcb, 0x94,
  0xd5, 0x17, 0xd4, 0xdb, 0x5c, 0x1a, 0x5d, 0xda, 0x9b, 0xdb, 0x04, 0xa1,
  0x88, 0x36, 0x2c, 0x03, 0x19, 0x58, 0x65, 0x80, 0x79, 0x83, 0x37, 0x5c,
  0x60, 0xb0, 0x41, 0x18, 0x03, 0x33, 0xd8, 0x30, 0x88, 0xc1, 0x19, 0x00,
  0x1b, 0x8a, 0x89, 0x42, 0x03, 0x08, 0xa8, 0xc2, 0xc6, 0x66, 0xd7, 0xe6,
  0x92, 0x46, 0x56, 0xe6, 0x46, 0x37, 0x25, 0x08, 0xaa, 0x90, 0xe1, 0xb9,
  0xd8, 0x95, 0xc9, 0xcd, 0xa5, 0xbd, 0xb9, 0x4d, 0x09, 0x88, 0x26, 0x64,
  0x78, 0x2e, 0x76, 0x61, 0x6c, 0x76, 0x65, 0x72, 0x53, 0x02, 0xa3, 0x0e,
  0x19, 0x9e, 0xcb, 0x1c, 0x5a, 0x18, 0x59, 0x99, 0x5c, 0xd3, 0x1b, 0x59,
  0x19, 0xdb, 0x94, 0x20, 0x29, 0x43, 0x86, 0xe7, 0x22, 0x57, 0x36, 0xf7,
  0x56, 0x27, 0x37, 0x56, 0x36, 0x37, 0x25, 0x78, 0xea, 0x90, 0xe1, 0xb9,
  0xd8, 0xa5, 0x95, 0xdd, 0x25, 0x91, 0x4d, 0xd1, 0x85, 0xd1, 0x95, 0x4d,
  0x09, 0xa2, 0x3a, 0x64, 0x78, 0x2e, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50,
  0x6f, 0x69, 0x6e, 0x74, 0x73, 0x53, 0x02, 0x34, 0x00, 0x00, 0x00, 0x00,
  0x79, 0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c,
  0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3,
  0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6,
  0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e,
  0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43,
  0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03,
  0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48,
  0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20,
  0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e,
  0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d,
  0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89,
  0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83,
  0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68,
  0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90,
  0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78,
  0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98,
  0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5,
  0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c,
  0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c,
  0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43,
  0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43,
  0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82,
  0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xc8, 0x21, 0x07, 0x7c, 0x70,
  0x03, 0x72, 0x10, 0x87, 0x73, 0x70, 0x03, 0x7b, 0x08, 0x07, 0x79, 0x60,
  0x87, 0x70, 0xc8, 0x87, 0x77, 0xa8, 0x07, 0x7a, 0x98, 0x81, 0x3c, 0xe4,
  0x80, 0x0f, 0x6e, 0x40, 0x0f, 0xe5, 0xd0, 0x0e, 0xf0, 0x00, 0x00, 0x00,
  0x71, 0x20, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x36, 0xb0, 0x0d, 0x97,
  0xef, 0x3c, 0xbe, 0x10, 0x50, 0x45, 0x41, 0x44, 0xa5, 0x03, 0x0c, 0x25,
  0x61, 0x00, 0x02, 0xe6, 0x17, 0xb7, 0x6d, 0x05, 0xd2, 0x70, 0xf9, 0xce,
  0xe3, 0x0b, 0x11, 0x01, 0x4c, 0x44, 0x08, 0x34, 0xc3, 0x42, 0x58, 0xc0,
  0x34, 0x5c, 0xbe, 0xf3, 0xf8, 0x8b, 0x03, 0x0c, 0x62, 0xf3, 0x50, 0x93,
  0x5f, 0xdc, 0xb6, 0x09, 0x54, 0xc3, 0xe5, 0x3b, 0x8f, 0x2f, 0x4d, 0x4e,
  0x44, 0xa0, 0xd4, 0xf4, 0x50, 0x93, 0x5f, 0xdc, 0xb6, 0x11, 0x48, 0xc3,
  0xe5, 0x3b, 0x8f, 0x3f, 0x11, 0xd1, 0x84, 0x00, 0x11, 0xe6, 0x17, 0xb7,
  0x6d, 0x00, 0x04, 0x03, 0x20, 0x0d, 0x00, 0x00, 0x61, 0x20, 0x00, 0x00,
  0x63, 0x00, 0x00, 0x00, 0x13, 0x04, 0x41, 0x2c, 0x10, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x44, 0x4a, 0xa1, 0x10, 0x66, 0x00, 0x8a, 0xab,
  0xec, 0x4a, 0x8e, 0x4a, 0x09, 0x50, 0x1c, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x20, 0x5d, 0x43, 0x53, 0x55, 0xc1,
  0x88, 0x41, 0x02, 0x80, 0x20, 0x18, 0x18, 0x1c, 0x72, 0x59, 0xcf, 0x31,
  0x62, 0x90, 0x00, 0x20, 0x08, 0x06, 0x46, 0x97, 0x60, 0x17, 0x81, 0x8c,
  0x18, 0x24, 0x00, 0x08, 0x82, 0x81, 0xe1, 0x29, 0x19, 0x06, 0x25, 0x23,
  0x06, 0x09, 0x00, 0x82, 0x60, 0x60, 0x7c, 0x8b, 0x96, 0x3d, 0xca, 0x88,
  0x41, 0x02, 0x80, 0x20, 0x18, 0x18, 0x60, 0xc0, 0x68, 0xda, 0xb4, 0x8c,
  0x18, 0x24, 0x00, 0x08, 0x82, 0x81, 0x11, 0x06, 0xcd, 0xb6, 0x21, 0xcc,
  0x88, 0xc1, 0x01, 0x80, 0x20, 0x18, 0x34, 0x60, 0xb0, 0x1c, 0xdc, 0x68,
  0x42, 0x00, 0x8c, 0x26, 0x08, 0xc1, 0x68, 0xc2, 0x20, 0x8c, 0x26, 0x10,
  0xc3, 0x88, 0xc1, 0x01, 0x80, 0x20, 0x18, 0x34, 0x65, 0x00, 0x31, 0x62,
  0x30, 0x9a, 0x10, 0x00, 0xa3, 0x09, 0x42, 0x30, 0x9a, 0x30, 0x08, 0xa3,
  0x09, 0xc4, 0x30, 0x62, 0x70, 0x00, 0x20, 0x08, 0x06, 0x8d, 0x1a, 0x54,
  0x91, 0x18, 0x8c, 0x26, 0x04, 0xc0, 0x68, 0x82, 0x10, 0x8c, 0x26, 0x0c,
  0xc2, 0x68, 0x02, 0x31, 0x98, 0x13, 0xc9, 0x67, 0xc4, 0x00, 0x01, 0x40,
  0x10, 0x0c, 0x9e, 0x37, 0xe0, 0x22, 0x25, 0x30, 0x23, 0x80, 0x8e, 0x41,
  0x94, 0x7c, 0x46, 0x0c, 0x10, 0x00, 0x04, 0xc1, 0xe0, 0x91, 0x83, 0x8f,
  0x62, 0x02, 0x0b, 0x10, 0xe8, 0x98, 0x74, 0xc9, 0x67, 0xc4, 0x00, 0x01,
  0x40, 0x10, 0x0c, 0x9e, 0x3a, 0x10, 0x83, 0xcb, 0x09, 0x2c, 0x50, 0xa0,
  0x63, 0x94, 0x26, 0x9f, 0x11, 0x03, 0x04, 0x00, 0x41, 0x30, 0x78, 0xf0,
  0xa0, 0x0c, 0x34, 0x28, 0xb0, 0x80, 0x81, 0xce, 0x88, 0x41, 0x02, 0x80,
  0x20, 0x18, 0x20, 0x7c, 0xa0, 0x06, 0x77, 0x70, 0x07, 0x70, 0x10, 0x06,
  0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x80, 0xf0, 0x81, 0x1a, 0xdc, 0xc1,
  0x1d, 0x90, 0x01, 0x18, 0x8c, 0x18, 0x24, 0x00, 0x08, 0x82, 0x01, 0xc2,
  0x07, 0x6a, 0x70, 0x07, 0x77, 0xf0, 0x06, 0xdf, 0x88, 0x41, 0x02, 0x80,
  0x20, 0x18, 0x20, 0x7c, 0xa0, 0x06, 0x77, 0x70, 0x07, 0x6d, 0xe0, 0x8d,
  0x18, 0x24, 0x00, 0x08, 0x82, 0x01, 0xc2, 0x07, 0x6a, 0x80, 0x07, 0x77,
  0x00, 0x07, 0xca, 0x88, 0x41, 0x02, 0x80, 0x20, 0x18, 0x20, 0x7c, 0xa0,
  0x06, 0x78, 0x70, 0x07, 0x64, 0x70, 0x8c, 0x18, 0x24, 0x00, 0x08, 0x82,
  0x01, 0xc2, 0x07, 0x6a, 0x80, 0x07, 0x77, 0xf0, 0x06, 0xc4, 0x88, 0x41,
  0x02, 0x80, 0x20, 0x18, 0x20, 0x7c, 0xa0, 0x06, 0x78, 0x70, 0x07, 0x6d,
  0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
