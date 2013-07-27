#pragma once
#include "Engine.AnimNodeBlendList.h"
#include "Engine.Actor.h"
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
	class AnimNodeBlendByBase : public AnimNodeBlendList
	{
	public:
		enum EBaseBlendType : byte
		{
			BBT_ByActorTag = 0,
			BBT_ByActorClass = 1,
			BBT_MAX = 2,
		};
		ADD_OBJECT(Actor, CachedBase, 296)
		ADD_STRUCT(float, BlendTime, 292)
		ADD_OBJECT(ScriptClass, ActorClass, 288)
		ADD_STRUCT(ScriptName, ActorTag, 280)
		ADD_STRUCT(AnimNodeBlendByBase::EBaseBlendType, Type, 276)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
