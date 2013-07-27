#pragma once
#include "Engine.Keypoint.h"
#include "Engine.Texture2D.h"
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
	class TargetPoint : public Keypoint
	{
	public:
		ADD_STRUCT(int, SpawnRefCount, 484)
		ADD_OBJECT(Texture2D, SpawnSpriteTexture, 480)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
