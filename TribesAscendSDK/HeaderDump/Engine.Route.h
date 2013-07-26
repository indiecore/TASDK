#pragma once
#include "Engine.Pawn.h"
#include "Core.Object.Pointer.h"
#include "Engine.Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Route." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Route." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Route : public Info
	{
	public:
		ADD_VAR(::ByteProperty, RouteType, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IEditorLinkSelectionInterface, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RouteIndexOffset, 0xFFFFFFFF)
		int ResolveRouteIndex(int Idx, byte RouteDirection, byte& out_bComplete, byte& out_bReverse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Route.ResolveRouteIndex");
			byte* params = (byte*)malloc(11);
			*(int*)params = Idx;
			*(params + 4) = RouteDirection;
			*(params + 5) = out_bComplete;
			*(params + 6) = out_bReverse;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_bComplete = *(params + 5);
			out_bReverse = *(params + 6);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int MoveOntoRoutePath(class Pawn* P, byte RouteDirection, float DistFudgeFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Route.MoveOntoRoutePath");
			byte* params = (byte*)malloc(13);
			*(class Pawn**)params = P;
			*(params + 4) = RouteDirection;
			*(float*)(params + 8) = DistFudgeFactor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
