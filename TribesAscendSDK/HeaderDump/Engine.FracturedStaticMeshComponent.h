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
		struct FragmentGroup
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16040);
			byte params[12] = { NULL };
			*(ScriptArray<byte>*)params = VisibilityFactors;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsFragmentDestroyable(int FragmentIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16043);
			byte params[8] = { NULL };
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsRootFragment(int FragmentIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16046);
			byte params[8] = { NULL };
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsNoPhysFragment(int FragmentIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16049);
			byte params[8] = { NULL };
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Object::Box GetFragmentBox(int FragmentIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16052);
			byte params[32] = { NULL };
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Box*)&params[4];
		}
		Vector GetFragmentAverageExteriorNormal(int FragmentIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16055);
			byte params[16] = { NULL };
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		int GetCoreFragmentIndex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16058);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptArray<FracturedStaticMeshComponent::FragmentGroup> GetFragmentGroups(ScriptArray<int> IgnoreFragments, float MinConnectionArea)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16060);
			byte params[28] = { NULL };
			*(ScriptArray<int>*)params = IgnoreFragments;
			*(float*)&params[12] = MinConnectionArea;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<FracturedStaticMeshComponent::FragmentGroup>*)&params[16];
		}
		ScriptArray<int> GetBoundaryHiddenFragments(ScriptArray<int> AdditionalVisibleFragments)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16066);
			byte params[24] = { NULL };
			*(ScriptArray<int>*)params = AdditionalVisibleFragments;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<int>*)&params[12];
		}
		void RecreatePhysState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16071);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PhysicalMaterial* GetFracturedMeshPhysMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16072);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicalMaterial**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
