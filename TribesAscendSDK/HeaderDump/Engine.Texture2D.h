#pragma once
#include "Engine.Texture.h"
#include "Core.Object.Pointer.h"
#include "Engine.Texture2D.TextureLinkedListMirror.h"
#include "Core.Object.Guid.h"
#include "Core.Object.ThreadSafeCounter.h"
#include "Core.Object.IndirectArray_Mirror.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Texture2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Texture2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Texture2D : public Texture
	{
	public:
		ADD_VAR(::FloatProperty, Timer, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FirstResourceMemMip, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ResourceMem, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MipTailBaseIdx, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StreamingIndex, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureLinkedListMirror>, StreamableTexturesLink, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ThreadSafeCounter>, PendingMipChangeRequestStatus, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ResidentMips, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RequestedMips, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Guid>, TextureFileCacheGuid, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TextureFileCacheName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceMipLevelsToBeResidentTimestamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGlobalForceMipLevelsToBeResident, 0x10)
		ADD_VAR(::BoolProperty, bForceMiplevelsToBeResident, 0x8)
		ADD_VAR(::BoolProperty, bHasBeenLoadedFromPersistentArchive, 0x4)
		ADD_VAR(::BoolProperty, bHasCancelationPending, 0x2)
		ADD_VAR(::BoolProperty, bIsStreamable, 0x1)
		ADD_VAR(::ByteProperty, AddressY, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AddressX, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OriginalSizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OriginalSizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<IndirectArray_Mirror>, CachedPVRTCMips, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<IndirectArray_Mirror>, Mips, 0xFFFFFFFF)
		void SetForceMipLevelsToBeResident(float Seconds, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2D.SetForceMipLevelsToBeResident");
			byte* params = (byte*)malloc(8);
			*(float*)params = Seconds;
			*(int*)(params + 4) = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* Create(int InSizeX, int InSizeY, byte InFormat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2D.Create");
			byte* params = (byte*)malloc(13);
			*(int*)params = InSizeX;
			*(int*)(params + 4) = InSizeY;
			*(params + 8) = InFormat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
