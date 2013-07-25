#pragma once
#include "Engine__Controller.h"
#include "Engine__NavigationPoint.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Pylon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Pylon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Pylon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Pylon : public NavigationPoint
	{
	public:
		ADD_VAR(::IntProperty, DebugEdgeCount, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ExpansionSphereCenter, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bForceObstacleMeshCollision, 0x400)
		ADD_VAR(::BoolProperty, bDisabled, 0x200)
		ADD_VAR(::BoolProperty, bBuildThisPylon, 0x100)
		ADD_VAR(::BoolProperty, bDrawObstacleSurface, 0x80)
		ADD_VAR(::BoolProperty, bDrawWalkableSurface, 0x40)
		ADD_VAR(::BoolProperty, bRenderInShowPaths, 0x20)
		ADD_VAR(::BoolProperty, bDrawPolyBounds, 0x10)
		ADD_VAR(::BoolProperty, bDrawEdgePolys, 0x8)
		ADD_VAR(::BoolProperty, bNeedsCostCheck, 0x4)
		ADD_VAR(::BoolProperty, bUseExpansionSphereOverride, 0x2)
		ADD_VAR(::BoolProperty, bImportedMesh, 0x1)
		ADD_VAR(::FloatProperty, MaxExpansionRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExpansionRadius, 0xFFFFFFFF)
		ADD_OBJECT(Pylon, NextPylon)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'OctreeIWasAddedTo'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.OctreeElementId' for the property named 'OctreeId'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'PathObjectsThatAffectThisPylon'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'WorkingSetPtr'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'DynamicObstacleMesh'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ObstacleMesh'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'NavMeshPtr'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IEditorLinkSelectionInterface'!
		// Here lies the not-yet-implemented method 'OnPylonStatusChange'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetEnabled'
		// Here lies the not-yet-implemented method 'IsEnabled'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'CanReachPylon'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
