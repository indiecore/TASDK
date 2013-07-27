#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Engine.ParticleModuleOrientationAxisLock.h"
#include "Engine.StaticMesh.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleTypeDataMesh : public ParticleModuleTypeDataBase
	{
	public:
		enum EMeshCameraFacingOptions : byte
		{
			XAxisFacing_NoUp = 0,
			XAxisFacing_ZUp = 1,
			XAxisFacing_NegativeZUp = 2,
			XAxisFacing_YUp = 3,
			XAxisFacing_NegativeYUp = 4,
			LockedAxis_ZAxisFacing = 5,
			LockedAxis_NegativeZAxisFacing = 6,
			LockedAxis_YAxisFacing = 7,
			LockedAxis_NegativeYAxisFacing = 8,
			VelocityAligned_ZAxisFacing = 9,
			VelocityAligned_NegativeZAxisFacing = 10,
			VelocityAligned_YAxisFacing = 11,
			VelocityAligned_NegativeYAxisFacing = 12,
			EMeshCameraFacingOptions_MAX = 13,
		};
		enum EMeshCameraFacingUpAxis : byte
		{
			CameraFacing_NoneUP = 0,
			CameraFacing_ZUp = 1,
			CameraFacing_NegativeZUp = 2,
			CameraFacing_YUp = 3,
			CameraFacing_NegativeYUp = 4,
			CameraFacing_MAX = 5,
		};
		enum EMeshScreenAlignment : byte
		{
			PSMA_MeshFaceCameraWithRoll = 0,
			PSMA_MeshFaceCameraWithSpin = 1,
			PSMA_MeshFaceCameraWithLockedAxis = 2,
			PSMA_MAX = 3,
		};
		ADD_STRUCT(float, Yaw, 92)
		ADD_STRUCT(float, Roll, 88)
		ADD_STRUCT(float, Pitch, 84)
		ADD_STRUCT(ParticleModuleTypeDataMesh::EMeshCameraFacingOptions, CameraFacingOption, 83)
		ADD_STRUCT(ParticleModuleTypeDataMesh::EMeshCameraFacingUpAxis, CameraFacingUpAxisOption, 82)
		ADD_STRUCT(ParticleModuleOrientationAxisLock::EParticleAxisLock, AxisLockOption, 81)
		ADD_STRUCT(ParticleModuleTypeDataMesh::EMeshScreenAlignment, MeshAlignment, 80)
		ADD_OBJECT(StaticMesh, Mesh, 72)
		ADD_BOOL(bApplyParticleRotationAsSpin, 76, 0x20)
		ADD_BOOL(bCameraFacing, 76, 0x10)
		ADD_BOOL(bOverrideMaterial, 76, 0x8)
		ADD_BOOL(bAllowMotionBlur, 76, 0x4)
		ADD_BOOL(DoCollisions, 76, 0x2)
		ADD_BOOL(CastShadows, 76, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
