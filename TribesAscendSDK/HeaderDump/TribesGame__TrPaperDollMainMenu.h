#pragma once
#include "TribesGame__TrPaperDoll.h"
#include "TribesGame__TrMainMenuMeshInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPaperDollMainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPaperDollMainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrPaperDollMainMenu : public TrPaperDoll
	{
	public:
		ADD_VAR(::ByteProperty, m_OldContentDataType, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rZeroedRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fFullCharacterLightingContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasLastMeshSwapRequestMainMenuContentScene, 0x2)
		ADD_VAR(::BoolProperty, m_bEditorMode, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'GetDevicePaperDollInfo'
		// Here lies the not-yet-implemented method 'SetMainMesh'
		// Here lies the not-yet-implemented method 'OnCharacterMeshContentDataClassLoaded'
		// Here lies the not-yet-implemented method 'OnDeviceContentDataClassLoaded'
		// Here lies the not-yet-implemented method 'TryUpdatingPaperDoll'
		// Here lies the not-yet-implemented method 'SetWeaponOnlyMesh'
		// Here lies the not-yet-implemented method 'SetFamilyInfo'
		// Here lies the not-yet-implemented method 'SetMainMeshInfo'
		// Here lies the not-yet-implemented method 'CreateAndAttachParticleSystems'
		// Here lies the not-yet-implemented method 'DetachAndDestroyMeshAttachments'
		// Here lies the not-yet-implemented method 'SetSpinning'
		// Here lies the not-yet-implemented method 'EmptyChildrenMeshes'
		// Here lies the not-yet-implemented method 'AddChildrenMeshes'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
