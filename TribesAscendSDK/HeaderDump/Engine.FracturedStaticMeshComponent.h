#pragma once
#include "Engine.FracturedBaseComponent.h"
#include "Engine.MaterialInterface.h"
#include "Core.Object.h"
#include "Engine.PhysicalMaterial.h"
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
	class FracturedStaticMeshComponent : public FracturedBaseComponent
	{
	public:
		class FragmentGroup
		{
		public:
			ADD_STRUCT(ScriptArray<int>, FragmentIndices, 0)
			ADD_BOOL(bGroupIsRooted, 12, 0x1)
		};
		ADD_STRUCT(ScriptArray<byte>, FragmentNeighborsVisible, 640)
		ADD_STRUCT(float, FragmentBoundsMinZ, 696)
		ADD_STRUCT(float, FragmentBoundsMaxZ, 692)
		ADD_OBJECT(MaterialInterface, LoseChunkOutsideMaterialOverride, 688)
		ADD_STRUCT(float, TopBottomFragmentDistThreshold, 684)
		ADD_BOOL(bBottomFragmentsRootNonDestroyable, 680, 0x8)
		ADD_BOOL(bTopFragmentsRootNonDestroyable, 680, 0x4)
		ADD_BOOL(bUseVisibleVertsForBounds, 680, 0x2)
		ADD_BOOL(bUseSkinnedRendering, 680, 0x1)
		ADD_STRUCT(Object::Box, VisibleBox, 652)
		void SetVisibleFragments(ScriptArray<byte> VisibilityFactors)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.SetVisibleFragments");
			byte params[12] = { NULL };
			*(ScriptArray<byte>*)&params[0] = VisibilityFactors;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsFragmentDestroyable(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.IsFragmentDestroyable");
			byte params[8] = { NULL };
			*(int*)&params[0] = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsRootFragment(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.IsRootFragment");
			byte params[8] = { NULL };
			*(int*)&params[0] = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsNoPhysFragment(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.IsNoPhysFragment");
			byte params[8] = { NULL };
			*(int*)&params[0] = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Object::Box GetFragmentBox(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFragmentBox");
			byte params[32] = { NULL };
			*(int*)&params[0] = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Box*)&params[4];
		}
		Object::Vector GetFragmentAverageExteriorNormal(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFragmentAverageExteriorNormal");
			byte params[16] = { NULL };
			*(int*)&params[0] = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		int GetCoreFragmentIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetCoreFragmentIndex");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptArray<FracturedStaticMeshComponent::FragmentGroup> GetFragmentGroups(ScriptArray<int> IgnoreFragments, float MinConnectionArea)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFragmentGroups");
			byte params[28] = { NULL };
			*(ScriptArray<int>*)&params[0] = IgnoreFragments;
			*(float*)&params[12] = MinConnectionArea;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<FracturedStaticMeshComponent::FragmentGroup>*)&params[16];
		}
		ScriptArray<int> GetBoundaryHiddenFragments(ScriptArray<int> AdditionalVisibleFragments)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetBoundaryHiddenFragments");
			byte params[24] = { NULL };
			*(ScriptArray<int>*)&params[0] = AdditionalVisibleFragments;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<int>*)&params[12];
		}
		void RecreatePhysState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.RecreatePhysState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PhysicalMaterial* GetFracturedMeshPhysMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFracturedMeshPhysMaterial");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicalMaterial**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
