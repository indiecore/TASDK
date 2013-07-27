#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class FracturedBaseComponent : public StaticMeshComponent
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, VisibleFragments, 616)
		ADD_STRUCT(int, bResetStaticMesh, 636)
		ADD_STRUCT(int, NumResourceIndices, 632)
		ADD_BOOL(bUseDynamicIBWithHiddenFragments, 628, 0x10)
		ADD_BOOL(bUseDynamicIndexBuffer, 628, 0x8)
		ADD_BOOL(bInitialVisibilityValue, 628, 0x4)
		ADD_BOOL(bVisibilityReset, 628, 0x2)
		ADD_BOOL(bVisibilityHasChanged, 628, 0x1)
		ADD_STRUCT(Object::RenderCommandFence_Mirror, ReleaseResourcesFence, 612)
		ADD_STRUCT(Object::Pointer, ComponentBaseResources, 608)
		bool SetStaticMesh(class StaticMesh* NewMesh, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.SetStaticMesh");
			byte params[12] = { NULL };
			*(class StaticMesh**)&params[0] = NewMesh;
			*(bool*)&params[4] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptArray<byte> GetVisibleFragments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.GetVisibleFragments");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<byte>*)&params[0];
		}
		bool IsFragmentVisible(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.IsFragmentVisible");
			byte params[8] = { NULL };
			*(int*)&params[0] = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetNumFragments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.GetNumFragments");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetNumVisibleFragments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.GetNumVisibleFragments");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
